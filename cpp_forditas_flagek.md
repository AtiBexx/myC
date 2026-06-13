# C++ Fordítási Flagek – GCC, Clang, CMake

---

## OPTIMALIZÁLÁSI SZINTEK

| Flag | Mit jelent | Mikor használd |
|------|-----------|----------------|
| `-O0` | Nincs optimalizálás | Debug, töréspontok |
| `-O1` | Alap optimalizálás | Ritkán kell |
| `-O2` | Biztonságos optimalizálások | Production standard |
| `-O3` | Agresszív – de nem mindig gyorsabb! | Mérj utána! |
| `-Os` | Méret optimalizálás | Embedded, kis ROM |
| `-Ofast` | O3 + matematikai szabályokat sérti | Ha pontosság nem számít |

### Miért nem mindig gyorsabb a -O3?
```
-O3 bekapcsol:
- loop unrolling      → nagy kód → cache miss → lassabb lehet!
- function inlining   → szintén nagy kód méret
- auto-vectorization  → néha rosszul vektorizál
```
Mindig mérd meg! quick-bench.com vagy saját chrono mérés.

---

## GCC PARANCSOK

```bash
# Alap debug build:
g++ -O0 -g main.cpp -o program

# Production (leggyakoribb):
g++ -O2 -march=native main.cpp -o program

# Teljesítmény teszt O3-mal:
g++ -O3 -march=native main.cpp -o program

# Legagresszívabb (lebegőpontos pontosság sérülhet!):
g++ -Ofast -march=native main.cpp -o program

# Embedded / kis méret:
g++ -Os -march=native main.cpp -o program

# Teljes production build ajánlott flagekkel:
g++ -O2 -march=native -Wall -Wextra -std=c++17 main.cpp -o program

# SIMD explicit engedélyezés (ha nem march=native):
g++ -O2 -msse2 main.cpp -o program       # SSE2
g++ -O2 -mavx main.cpp -o program        # AVX
g++ -O2 -mavx2 main.cpp -o program       # AVX2
g++ -O2 -mavx512f main.cpp -o program    # AVX-512
```

### Hasznos extra GCC flagek:
```bash
-Wall              # minden fontos figyelmeztetés
-Wextra            # még több figyelmeztetés
-Wpedantic         # szigorú C++ szabvány betartás
-std=c++17         # C++ verzió (c++11, c++14, c++17, c++20)
-g                 # debug info (gdb-hez)
-pg                # profiling (gprof-hoz)
-fno-omit-frame-pointer  # profiling + stack trace-hez
```

---

## CLANG PARANCSOK

A Clang flagek **szinte teljesen azonosak** a GCC-vel!

```bash
# Alap debug build:
clang++ -O0 -g main.cpp -o program

# Production:
clang++ -O2 -march=native main.cpp -o program

# Teljesítmény teszt:
clang++ -O3 -march=native main.cpp -o program

# Legagresszívabb:
clang++ -Ofast -march=native main.cpp -o program

# Teljes production build:
clang++ -O2 -march=native -Wall -Wextra -std=c++17 main.cpp -o program

# SIMD ugyanúgy mint GCC-nél:
clang++ -O2 -mavx2 -march=native main.cpp -o program
```

### Clang specifikus extra flagek:
```bash
-fsanitize=address      # AddressSanitizer – memory hibák detektálása
-fsanitize=thread       # ThreadSanitizer – race condition detektálás
-fsanitize=undefined    # UBSanitizer – undefined behavior detektálás
--analyze               # statikus analízis
-ftime-report           # fordítási idő részletezése
```

### GCC vs Clang mikor melyiket?
| | GCC | Clang |
|--|-----|-------|
| Sebesség | Hasonló | Hasonló |
| Hibaüzenetek | Régebben gyengébb | **Jobb, érthetőbb** |
| Sanitizerek | Van | **Jobb implementáció** |
| Build idő | Kicsit lassabb | **Gyorsabb** |
| Embedded | Szélesebb támogatás | Kevesebb target |
| LLVM/Clang toolchain | Nem | Igen |

---

## CMAKE

### Alap CMakeLists.txt:
```cmake
cmake_minimum_required(VERSION 3.15)
project(MyCppProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(program main.cpp)
```

### Debug és Release build típusok:
```cmake
cmake_minimum_required(VERSION 3.15)
project(MyCppProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ha nem adtad meg, alapból Debug legyen:
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(program main.cpp)

# Flagek build típus szerint:
target_compile_options(program PRIVATE
    $<$<CONFIG:Debug>:   -O0 -g -Wall -Wextra>
    $<$<CONFIG:Release>: -O2 -march=native -Wall>
)
```

### CMake build parancsok:
```bash
# Könyvtár létrehozása és konfiguráció:
mkdir build && cd build

# Debug build:
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .

# Release build:
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .

# Clang használata GCC helyett:
cmake .. -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release
cmake --build .

# Párhuzamos fordítás (gyorsabb):
cmake --build . --parallel 8   # 8 maggal fordít
cmake --build . -j8            # ugyanaz rövidebben
```

### SIMD CMake-ben:
```cmake
cmake_minimum_required(VERSION 3.15)
project(SimdProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(program main.cpp)

# SIMD flagek hozzáadása:
target_compile_options(program PRIVATE
    $<$<CONFIG:Release>: -O2 -march=native>
)

# Vagy explicit SIMD szint:
target_compile_options(program PRIVATE -mavx2)

# CPU feature detektálás CMake-ben (cmake 3.10+):
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-mavx2" COMPILER_SUPPORTS_AVX2)
if(COMPILER_SUPPORTS_AVX2)
    target_compile_options(program PRIVATE -mavx2)
    message(STATUS "AVX2 támogatott!")
else()
    message(STATUS "AVX2 nem támogatott, SSE2-t használunk")
    target_compile_options(program PRIVATE -msse2)
endif()
```

### Több forrásfájl CMake-ben (mint a te projekted):
```cmake
cmake_minimum_required(VERSION 3.15)
project(LearningLanguagesCLI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Forrásfájlok listája:
set(SOURCES
    src/main.cpp
    src/CreateVocab/createVocab.cpp
    src/generalFunctions/generalFunctions.cpp
)

add_executable(program ${SOURCES})

# Include könyvtárak:
target_include_directories(program PRIVATE
    src/
    src/CreateVocab/
    src/generalFunctions/
)

# Build típus szerinti flagek:
target_compile_options(program PRIVATE
    $<$<CONFIG:Debug>:   -O0 -g -Wall -Wextra>
    $<$<CONFIG:Release>: -O2 -march=native -Wall>
)
```

---

## ÖSSZEFOGLALÁS – Mikor mit használj

```
Fejlesztés közben:
  g++/clang++ -O0 -g -Wall -Wextra -std=c++17

Tesztelés / hibakeresés:
  clang++ -O0 -g -fsanitize=address,undefined

Production:
  g++/clang++ -O2 -march=native -std=c++17

Teljesítmény mérés:
  Próbáld -O2 és -O3 mindkettővel → mérd meg → amelyik gyorsabb!

CMake projektben:
  -DCMAKE_BUILD_TYPE=Debug    → fejlesztéshez
  -DCMAKE_BUILD_TYPE=Release  → kiadáshoz
```

gy extra tipp amit sokan nem tudnak – a **sanitizerek** a leghasznosabb debug eszközök:



bash

```bash
# Memory hibák (felejtetted delete, out of bounds):
clang++ -O0 -g -fsanitize=address main.cpp

# Race condition (threading hibák):
clang++ -O0 -g -fsanitize=thread main.cpp

# Undefined behavior (signed overflow, null deref):
clang++ -O0 -g -fsanitize=undefined main.cpp
```

Ezeket a te projekteknél is érdemes futtatni – sokszor olyan hibákat fog meg amit a normál fordítás nem jelez!