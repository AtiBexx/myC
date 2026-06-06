# VST Plugin SIMD & Fordítási Flag Optimalizáció

## Tartalom
1. [Inline ASM vs SIMD intrinsics](#1-inline-asm-vs-simd-intrinsics)
2. [EQ Plugin – FabFilter Pro-Q stílus](#2-eq-plugin--fabfilter-pro-q-stílus)
3. [Szintetizátor – Sylenth1 stílus](#3-szintetizátor--sylenth1-stílus)
4. [Fordítási flag-ek és kompatibilitás](#4-fordítási-flag-ek-és-kompatibilitás)
5. [Apple Silicon (M1/M2/M3)](#5-apple-silicon-m1m2m3)
6. [Ajánlott stack](#6-ajánlott-stack)

---

## 1. Inline ASM vs SIMD intrinsics

### Mikor lehet jobb az inline ASM?

- **Register allocation control** – kézzel döntöd el, hogy `ymm0`–`ymm7` mit tartalmaz, elkerülve a felesleges `vmovaps` utasításokat
- **Loop unrolling + prefetch kézi hangolás** – wavetable interpoláció vagy filter state update loopban pontosan előre töltheted a cache-t `prefetchnta`-val
- **Latency-critical code paths** – ha egy VCF ladder filter feedback loopja 1-2 ciklussal rövidebb ASM-ben, az 44.1kHz/128 sample buffernél érezhető lehet

### Miért NEM éri meg általában?

- A modern fordítók (`-O3 -march=native`) az intrinsic kódból szinte azonos assembly-t generálnak
- `_mm256_fmadd_ps`, `_mm256_loadu_ps` stb. → 1:1 AVX utasításokra fordulnak
- Inline ASM-et minden platformra (Windows/macOS/Linux, x86/ARM) újra kell írni
- JUCE / iPlug2 audio callback és buffer kezelés már SIMD-barát

### Összehasonlítás komponensenként

| Komponens | Intrinsics elég? | ASM kellhet? |
|---|---|---|
| Biquad filterbank | ✅ igen | ❌ nem |
| FFT (pffft) | ✅ már optimalizált | ❌ nem |
| Oszcillátor bank | ✅ igen | ❌ nem |
| Ladder filter | ✅ igen | ⚠️ csak profilozás után |
| tanh/sin approximáció | ✅ Chebyshev/minmax poly | ❌ nem |
| Envelope/LFO | ❌ SIMD sem kell | ❌ nem |

---

## 2. EQ Plugin – FabFilter Pro-Q stílus

### Biquad filter bank – SoA layout AVX-szal

```cpp
// ROSSZ - skalár, soros feldolgozás
for (int band = 0; band < numBands; band++) {
    output = b0*input + b1*x1 + b2*x2 - a1*y1 - a2*y2;
}

// JÓ - 8 band párhuzamosan AVX-szal (SoA layout)
__m256 b0  = _mm256_load_ps(coeff.b0);
__m256 b1  = _mm256_load_ps(coeff.b1);
__m256 x   = _mm256_set1_ps(inputSample);
__m256 out = _mm256_fmadd_ps(b0, x,
             _mm256_fmadd_ps(b1, state.x1, ...));
```

### Linear phase mód – FFT

Ne írj saját FFT-t! Ajánlott könyvtárak:

| Könyvtár | Licensz | Megjegyzés |
|---|---|---|
| `pffft` | MIT | Kifejezetten audio-ra, SIMD-aware |
| `FFTW` | GPL/fizetős | Gyors, nehézkes licensz |
| Intel IPP | Fizetős | Legjobb teljesítmény |

### Spectrum analyzer
Külön szálon fusson, ring buffer-rel. SIMD itt kevésbé számít.

---

## 3. Szintetizátor – Sylenth1 stílus

### Architektúra: hangok párhuzamosítása

A Sylenth1 megközelítése: **4 unisonos oszcillátor × 8 hang = 32 hang párhuzamosan**

```
AoS (ROSSZ):            SoA (JÓ - SIMD-barát):
Voice[0]: phase, freq   phases[0..7]  → __m256
Voice[1]: phase, freq   freqs[0..7]   → __m256
Voice[2]: phase, freq   outputs[0..7] → __m256
```

### Oszcillátor bank AVX-szal (8 hang egyszerre)

```cpp
struct OscBank {
    alignas(32) float phase[8];
    alignas(32) float phaseInc[8];  // freq / sampleRate
    alignas(32) float output[8];
};

void processBlock(OscBank& osc, float* out, int numSamples) {
    __m256 phases   = _mm256_load_ps(osc.phase);
    __m256 phaseInc = _mm256_load_ps(osc.phaseInc);
    __m256 twoPi    = _mm256_set1_ps(2.0f * M_PI);

    for (int i = 0; i < numSamples; i++) {
        __m256 wave = fast_sin_avx(phases);
        _mm256_store_ps(osc.output, wave);

        phases = _mm256_add_ps(phases, phaseInc);
        // Wrap [0, 2π]
        phases = _mm256_sub_ps(phases,
            _mm256_and_ps(twoPi,
                _mm256_cmp_ps(phases, twoPi, _CMP_GE_OS)));
    }
    _mm256_store_ps(osc.phase, phases);
}
```

### Ladder filter (Moog típus) – a legnehezebb SIMD-esíteni

> **Probléma:** az IIR filternek adatfüggősége van (feedback)  
> **Megoldás:** hangokat párhuzamosítani, NEM sample-öket!

```cpp
struct LadderBank {
    __m256 s1, s2, s3, s4;  // 4 stage state, 8 hangra
    __m256 k;                // resonance
    __m256 cutoff;
};

// Egy sample, 8 hang párhuzamosan
__m256 processLadder(LadderBank& f, __m256 input) {
    __m256 u = _mm256_sub_ps(input,
                   _mm256_mul_ps(f.k, f.s4));
    u = tanh_avx(u);  // tanh approximáció - fontos a karakterhez!
    // ... 4 stage cascading
}
```

### Fontossági sorrend (teljesítmény szempontból)

```
1. SoA adatszerkezet          → 60-70% gyorsulás
2. Memória alignment           → alignas(32), _mm_malloc
3. Fordítási flag-ek           → -O3 -march=haswell -ffast-math
4. AVX2 intrinsics hot path-on → __m256 műveletek
5. Cache-barát access pattern  → összefüggő memória
─────────────────────────────────────────────────
   Eddig: ~95%+ teljesítmény
6. Inline ASM                  → csak mért bottleneck esetén
```

---

## 4. Fordítási flag-ek és kompatibilitás

### A `-march=native` problémája

```
-march=native = "optimalizálj ERRE a konkrét CPU-ra"
```

**Másik gépen = crash vagy "Illegal Instruction" hiba**, ha az a CPU
nem támogatja a beégett utasításkészletet.

```
Te: Ryzen 9 + AVX2 → plugin.dll / plugin.vst3
Felhasználó: régi i5 (2013) → betölti DAW-ban → 💥 CRASH
```

### Biztonságos célzott minimum

```bash
# 2015 utáni gépek ~95%-a – ajánlott
-march=haswell        # AVX2 + FMA (Intel 2013+, AMD 2015+)

# Konzervatívabb, szélesebb kompatibilitás
-march=sandybridge    # AVX1 csak (Intel 2011+)

# Legbiztonságosabb (de lassabb)
-march=x86-64-v2      # SSE4.2, minden 2010+ gép
```

### Runtime CPU dispatch (profi megoldás)

```cpp
#include <cpuid.h>

struct CPUFeatures {
    bool hasAVX2   = false;
    bool hasAVX512 = false;
    bool hasFMA    = false;
};

CPUFeatures detectCPU() {
    CPUFeatures f;
    unsigned int eax, ebx, ecx, edx;

    __cpuid_count(7, 0, eax, ebx, ecx, edx);
    f.hasAVX2   = (ebx >> 5)  & 1;
    f.hasAVX512 = (ebx >> 16) & 1;

    __cpuid(1, eax, ebx, ecx, edx);
    f.hasFMA    = (ecx >> 12) & 1;

    return f;
}

// A processBlock-ban:
void processAudio(float* buffer, int numSamples) {
    static CPUFeatures cpu = detectCPU();

    if (cpu.hasAVX2)
        processAVX2(buffer, numSamples);   // gyors út
    else
        processSSE2(buffer, numSamples);   // fallback
}
```

### `-ffast-math` kockázatai VST-nél

| Mit csinál | Következmény |
|---|---|
| NaN/Inf ellenőrzést kikapcsolja | Hallható glitch ha denormal szám keletkezik |
| Asszociativitást feltételez | Minimális hangbeli különbség |
| flush-to-zero nem garantált | Denormal CPU spike-ok! |

### Denormal flush – mindig add hozzá!

```cpp
// DAW callback elején hívd meg – kötelező!
#include <xmmintrin.h>
#include <pmmintrin.h>

void enableFlushToZero() {
    _MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
    _MM_SET_DENORMALS_ZERO_MODE(_MM_DENORMALS_ZERO_ON);
}
// E nélkül egy csendben lévő filter 100x több CPU-t ehet!
```

### `-ffast-math` helyett biztonságos alternatíva

```bash
-fno-math-errno        # nincs errno – biztonságos
-fno-signed-zeros      # biztonságos audio-nál
-ffp-contract=fast     # FMA engedélyezés – biztonságos
# -ffinite-math-only   # ⚠️ NaN/Inf nincs – csak ha biztos vagy benne
```

### Ajánlott flag-ek összefoglalva

```bash
# FEJLESZTÉS (saját gép):
-O3 -march=native -ffast-math

# RELEASE BUILD (terjesztéshez):
-O3 -march=haswell -fno-math-errno -fno-signed-zeros -ffp-contract=fast

# + mindig:
-fvisibility=hidden    # VST3-hoz szükséges
-DNDEBUG
```

---

## 5. Apple Silicon (M1/M2/M3)

```
x86 SIMD intrinsics → ARM Neon intrinsics (teljesen más API!)
```

- **`sse2neon.h`** header automatikusan fordítja az SSE intrinsics-et NEON-ra
- AVX2-t **nem** támogatja – ott kézzel kell ARM-specifikus kódot írni
- macOS terjesztéshez **Universal Binary** kell: x86 + ARM külön build, egy fájlba csomagolva (`lipo`)

---

## 6. Ajánlott stack

| Komponens | Ajánlás |
|---|---|
| **Framework** | JUCE (GPL ingyenes / fizetős commercial) |
| **FFT** | pffft (MIT licensz, tökéletes VST-hez) |
| **Math** | Saját Chebyshev polinomok sin/tanh-hoz |
| **Profiler** | Intel VTune vagy Tracy |
| **CPU dispatch** | Runtime CPUID detekció |
| **Denormal védelem** | `_MM_SET_FLUSH_ZERO_MODE` minden callback-ben |
