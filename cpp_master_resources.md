# C++ Master Erőforrások – Oldalak, Könyvek, SIMD

---

## NAPI GYAKORLÓ OLDALAK

### Kötelező napi rutin:
| Oldal | Mire jó | Link |
|-------|---------|------|
| **cppquiz.org** | Csak C++ kvíz – interjúra tökéletes, 5-10 perc reggel | cppquiz.org |
| **leetcode.com** | Algoritmusok, minden tech interjún ezek jönnek | leetcode.com |
| **codewars.com** | Kata rendszer, fokozatos nehézség, közösség | codewars.com |
| **hackerrank.com** | C++ certifikáció is van, strukturált feladatok | hackerrank.com |

### Referencia / Eszközök:
| Oldal | Mire jó | Link |
|-------|---------|------|
| **cppreference.com** | A C++ biblia – minden függvény, szabály, példa | cppreference.com |
| **godbolt.org** | Compiler Explorer – látod mit csinál a fordító assembly-ben | godbolt.org |
| **quick-bench.com** | Kód sebesség mérés online, benchmark | quick-bench.com |
| **cppinsights.io** | Megmutatja mit csinál a fordító a kódoddal (template, lambda) | cppinsights.io |
| **stackoverflow.com** | Ismert, de inkább cppreference-t nézz először | stackoverflow.com |

---

## KÖNYVEK – SORRENDBEN HALADJ

### 1. Jelenlegi szint után (ha a könyved kész):
| Könyv | Szerző | Miért fontos |
|-------|--------|-------------|
| **Effective Modern C++** | Scott Meyers | A legjobb C++11/14/17 könyv, 42 konkrét tanács – kötelező! |
| **Effective C++** | Scott Meyers | Az előző elődje, klasszikus szabályok |
| **A Tour of C++** | Bjarne Stroustrup | Maga a nyelv alkotója írta, rövid és tömör |

### 2. Haladó szint:
| Könyv | Szerző | Miért fontos |
|-------|--------|-------------|
| **C++ Templates: The Complete Guide** | Vandevoorde, Josuttis | Template master szint, teljes útmutató |
| **C++ Concurrency in Action** | Anthony Williams | Threading és konkurencia biblia |
| **The C++ Programming Language** | Bjarne Stroustrup | A teljes referencia, vastag de teljes |

### 3. Teljesítmény / Game dev / Embedded:
| Könyv | Szerző | Miért fontos |
|-------|--------|-------------|
| **The Art of Writing Efficient Programs** | Fedor Pikus | Cache, SIMD, optimalizálás mélyen |
| **Computer Systems: A Programmer's Perspective** | Bryant, O'Hallaron | CPU, memória, assembly – alap minden low-level munkához |
| **Game Engine Architecture** | Jason Gregory | Game dev C++ a gyakorlatban, Naughty Dog engineer írta |
| **Real-Time C++** | Christopher Kormanyos | Embedded C++ master szint |

### SIMD specifikus könyvek:
| Könyv | Szerző | Miért fontos |
|-------|--------|-------------|
| **Intel Intrinsics Guide** | Intel (online) | A SIMD biblia – ingyenes, online: intel.com/content/www/us/en/docs/intrinsics-guide |
| **Harnessing the Power of SSE** | Online cikkek | Keress rá: "SSE SIMD C++ tutorial" |
| **SIMD for C++ Developers** | Const.me (online) | Ingyenes PDF, gyakorlati SIMD útmutató |

---

## SIMD – Mi ez és miért fontos?

### Az alap gondolat:
Normál kód:
```
4 float összeadása = 4 CPU utasítás
```
SIMD kód:
```
4 float összeadása = 1 CPU utasítás  ← 4x gyorsabb!
```
SIMD = **S**ingle **I**nstruction **M**ultiple **D**ata
Egy utasítással több adaton dolgozol egyszerre.

### SIMD generációk C++-ban:
| Generáció | Regiszter méret | Mennyi float egyszerre | Mikor jelent meg |
|-----------|----------------|----------------------|-----------------|
| SSE | 128 bit | 4 float | 1999 |
| SSE2 | 128 bit | 2 double | 2001 |
| AVX | 256 bit | 8 float | 2011 |
| AVX-512 | 512 bit | 16 float | 2016 |

---

## SIMD PÉLDAKÓD – lépésről lépésre

### 0. Szükséges include:
```cpp
#include <immintrin.h>  // SSE, AVX minden
#include <iostream>
```

### 1. Legegyszerűbb példa – 4 float összeadása SSE-vel:
```cpp
#include <immintrin.h>
#include <iostream>

int main() {
    // 4 float normál módon
    float a[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    float b[4] = {5.0f, 6.0f, 7.0f, 8.0f};
    float eredmeny[4];

    // SIMD módszer:
    __m128 va = _mm_loadu_ps(a);        // betölti a[0..3]-at egy 128 bites regiszterbe
    __m128 vb = _mm_loadu_ps(b);        // betölti b[0..3]-at
    __m128 vered = _mm_add_ps(va, vb);  // EGYSZERRE adja össze mind a 4 párt!
    _mm_storeu_ps(eredmeny, vered);     // visszamenti a memóriába

    // Kiírás:
    for (int i = 0; i < 4; i++) {
        std::cout << a[i] << " + " << b[i] << " = " << eredmeny[i] << "\n";
    }
    return 0;
}
```
**Output:**
```
1 + 5 = 6
2 + 6 = 8
3 + 7 = 10
4 + 8 = 12
```

---

### 2. Normál vs SIMD sebesség összehasonlítás:
```cpp
#include <immintrin.h>
#include <chrono>
#include <iostream>
#include <vector>

const int MERET = 1000000;  // 1 millió elem

// Normál módszer
void normalis_osszead(const float* a, const float* b, float* c, int n) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

// SIMD módszer (SSE - 4 floatot egyszerre)
void simd_osszead(const float* a, const float* b, float* c, int n) {
    int i = 0;
    // 4-esével dolgozunk
    for (; i <= n - 4; i += 4) {
        __m128 va = _mm_loadu_ps(a + i);
        __m128 vb = _mm_loadu_ps(b + i);
        __m128 vc = _mm_add_ps(va, vb);
        _mm_storeu_ps(c + i, vc);
    }
    // Maradék elemek (ha n nem osztható 4-gyel)
    for (; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

int main() {
    std::vector<float> a(MERET, 1.5f);
    std::vector<float> b(MERET, 2.5f);
    std::vector<float> c(MERET);

    // Normál mérés
    auto start = std::chrono::high_resolution_clock::now();
    normalis_osszead(a.data(), b.data(), c.data(), MERET);
    auto vege = std::chrono::high_resolution_clock::now();
    auto normalis_ido = std::chrono::duration_cast<std::chrono::microseconds>(vege - start).count();

    // SIMD mérés
    start = std::chrono::high_resolution_clock::now();
    simd_osszead(a.data(), b.data(), c.data(), MERET);
    vege = std::chrono::high_resolution_clock::now();
    auto simd_ido = std::chrono::duration_cast<std::chrono::microseconds>(vege - start).count();

    std::cout << "Normális idő: " << normalis_ido << " mikrosec\n";
    std::cout << "SIMD idő:     " << simd_ido << " mikrosec\n";
    std::cout << "Gyorsulás:    " << (float)normalis_ido / simd_ido << "x\n";

    return 0;
}
```

---

### 3. SIMD típusok és függvények – gyors referencia:
```
__m128   = 4 x float  (128 bit SSE)
__m128d  = 2 x double (128 bit SSE2)
__m128i  = egész számok (128 bit)
__m256   = 8 x float  (256 bit AVX)
__m256d  = 4 x double (256 bit AVX)
```

```
Betöltés:
_mm_loadu_ps()   = float betöltés (nem igazított memória)
_mm_load_ps()    = float betöltés (16-byte igazított memória, gyorsabb)

Mentés:
_mm_storeu_ps()  = float mentés
_mm_store_ps()   = float mentés (igazított)

Aritmetika (float):
_mm_add_ps()     = összeadás
_mm_sub_ps()     = kivonás
_mm_mul_ps()     = szorzás
_mm_div_ps()     = osztás
_mm_sqrt_ps()    = négyzetgyök (mind a 4 elemre egyszerre!)
_mm_max_ps()     = maximum
_mm_min_ps()     = minimum
```

---

### 4. Mikor NEM érdemes SIMD-et használni:
- Ha az adat nem folyamatos a memóriában (random access)
- Ha sok az elágazás (if/else) az adaton belül
- Ha az adat kis méretű (overhead > nyereség)
- Ha a fordító úgyis auto-vektorizál (ellenőrizd godbolt-on!)

---

### 5. Fordítási flag-ek SIMD-hez:
```bash
# SSE2 (szinte minden x86 CPU támogatja):
g++ -msse2 -O2 main.cpp

# AVX (2011 utáni CPU-k):
g++ -mavx -O2 main.cpp

# AVX2:
g++ -mavx2 -O2 main.cpp

# Mindent ami a CPU tud (nem hordozható de leggyorsabb):
g++ -march=native -O2 main.cpp
```

---

## ÖSSZEFOGLALÓ – Mit tanulj milyen sorrendben

```
1. Jelenlegi könyv vége
        ↓
2. Effective Modern C++ (Scott Meyers) + napi leetcode + cppquiz
        ↓
3. C++ Concurrency in Action + quick-bench + godbolt
        ↓
4. Templates: The Complete Guide + cppinsights
        ↓
5. SIMD / teljesítmény (The Art of Writing Efficient Programs)
        ↓
6. Specializáció: Game dev / Embedded / Szerver
```
