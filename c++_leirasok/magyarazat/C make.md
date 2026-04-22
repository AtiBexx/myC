## C_Make

Mi az a Cmake ?

A CMake egy multiplatformos build rendszer, amely lehetővé teszi a szoftverprojektek fordításának
  automatizálását különböző operációs rendszereken és különböző fordítókkal. A CMake nem maga a fordító, hanem egy build rendszer generátor, amely leíró fájlok alapján hozza létre a tényleges fordításhoz szükséges konfigurációkat.

Főbb jellemzők:

   - Platformfüggetlen: Ugyanazt a CMakeLists.txt fájlt használhatod Windows, Linux és macOS rendszereken is
   - Fordítófüggetlen: Támogatja a GCC, Clang, MSVC és más fordítókat
   - Build rendszer generátor: Létrehozza a platformnak megfelelő build fájlokat (pl. Makefile, Visual Studio
     Solution, Xcode Project)

  Hogyan működik?
   1. **Létrehozol egy CMakeLists.txt fájlt, amely leírja:**
      - Milyen fájlokat kell lefordítani
      - Milyen könyvtárakat kell linkelni
      - Milyen fordítási opciókat kell használni
   2. **A CMake feldolgozza ezt a fájlt, és létrehozza a platformnak megfelelő build konfigurációt**
   3. **A generált konfiguráció alapján lefuttatod a tényleges fordítást (pl. make Linuxon vagy msbuild Windowson)**

  **Példa**:
  Ha egy egyszerű C++ programod van, a CMakeLists.txt fájl lehet:

 

```
 1 cmake_minimum_required(VERSION 3.10)
   2 project(MyApp)
   3
   4 add_executable(myapp main.cpp)
```

  Ezután a következő parancsokkal fordíthatod:

```
   1 cmake .
   2 make
```



```
cmake_minimum_required(VERSION 3.15)

project(
    MegaProject
    LANGUAGES C CXX ASM
)

# ============================
# Nyelvi standardok
# ============================
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# ============================
# Include
# ============================
include_directories(include)

# ============================
# C
# ============================
file(GLOB C_SOURCES src/c/*.c)
add_executable(c_app ${C_SOURCES})

# ============================
# C++
# ============================
file(GLOB CPP_SOURCES src/cpp/*.cpp)
add_executable(cpp_app ${CPP_SOURCES})

# ============================
# Shared library (DLL / SO)
# ============================
file(GLOB LIB_SOURCES src/lib/*.c)
add_library(mylib SHARED ${LIB_SOURCES})

target_link_libraries(cpp_app mylib)
target_link_libraries(c_app mylib)

# ============================
# Assembly (NASM)
# ============================
enable_language(ASM_NASM)
file(GLOB ASM_SOURCES src/asm/*.asm)

add_executable(asm_app ${ASM_SOURCES})
set_target_properties(asm_app PROPERTIES
    LINKER_LANGUAGE C
)

# ============================
# Python
# ============================
add_custom_target(python_app
    COMMAND python3 ${CMAKE_SOURCE_DIR}/src/python/script.py
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# ============================
# Java
# ============================
add_custom_target(java_app
    COMMAND javac ${CMAKE_SOURCE_DIR}/src/java/Main.java
    COMMAND java -cp ${CMAKE_SOURCE_DIR}/src/java Main
)

# ============================
# Kotlin (JVM)
# ============================
add_custom_target(kotlin_app
    COMMAND kotlinc ${CMAKE_SOURCE_DIR}/src/kotlin/Main.kt
            -include-runtime
            -d kotlin_app.jar
    COMMAND java -jar kotlin_app.jar
)

# ============================
# C# (.NET)
# ============================
add_custom_target(csharp_app
    COMMAND dotnet build ${CMAKE_SOURCE_DIR}/src/csharp/App.csproj
)

# ============================
# Install (DLL / SO)
# ============================
install(TARGETS mylib
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)


```

project/
│ CMakeLists.txt
│
├─include/
│
├─src/
│  ├─c/
│  │   main.c
│  ├─cpp/
│  │   main.cpp
│  ├─lib/
│  │   dll_example.c
│  ├─asm/
│  │   hello.asm
│  ├─python/
│  │   script.py
│  ├─java/
│  │   Main.java
│  ├─kotlin/
│  │   Main.kt
│  └─csharp/
│      App.csproj

**Build (minden OS-en)**

```
mkdir build
cd build
cmake ..
cmake --build .
```

Extra targetek:

```
cmake --build . --target python_app
cmake --build . --target java_app
cmake --build . --target kotlin_app
cmake --build . --target csharp_app
```

**Fordito megadása**

**CMakePresets.json**

```
{
  "version": 3,
  "configurePresets": [
    {
      "name": "gcc",
      "displayName": "GCC (MinGW / Linux)",
      "generator": "Ninja",
      "binaryDir": "build/gcc",
      "cacheVariables": {
        "CMAKE_C_COMPILER": "gcc",
        "CMAKE_CXX_COMPILER": "g++"
      }
    },
    {
      "name": "clang",
      "displayName": "Clang",
      "generator": "Ninja",
      "binaryDir": "build/clang",
      "cacheVariables": {
        "CMAKE_C_COMPILER": "clang",
        "CMAKE_CXX_COMPILER": "clang++"
      }
    },
    {
      "name": "msvc",
      "displayName": "MSVC",
      "generator": "Visual Studio 17 2022",
      "binaryDir": "build/msvc"
    }
  ]
}
```

használat:

```
cmake --preset gcc
cmake --build build/gcc

cmake --preset clang
cmake --build build/clang

cmake --preset msvc
```



**feltételes fordító kezelés**

```
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "GCC detected")
    add_compile_options(-Wall -Wextra)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Clang detected")
    add_compile_options(-Wall -Weverything)
elseif (MSVC)
    message(STATUS "MSVC detected")
    add_compile_options(/W4)
endif()
```

Különbségek:
   - Telepítés: Windowson a CMake-et telepíteni kell külön telepítővel, Linuxon csomagkezelőből szerezhető
   - Fordítók:
     - Windowson: MSVC, MinGW-w64, Clang
     - Linuxon: GCC, Clang
   - Generátorok:
     - Windowson: Visual Studio generátorokat használhat (pl. "Visual Studio 16 2019")
     - Linuxon: Unix Makefiles vagy Ninja a tipikus
   - Elérési utak:
     - Windowson \ elválasztó karaktert használ
     - Linuxon / elválasztó karaktert használ

------



 Linux / MinGW / Ninja (single-config)

 GCC – Debug

```bash
cmake -S . -B build/gcc-debug \
  -G Ninja \
  -DCMAKE_C_COMPILER=gcc \
  -DCMAKE_CXX_COMPILER=g++ \
  -DCMAKE_BUILD_TYPE=Debug

cmake --build build/gcc-debug
```

------

 GCC – Release

```bash
cmake -S . -B build/gcc-release \
  -G Ninja \
  -DCMAKE_C_COMPILER=gcc \
  -DCMAKE_CXX_COMPILER=g++ \
  -DCMAKE_BUILD_TYPE=Release

cmake --build build/gcc-release
```

------

 Clang – Debug

```bash
cmake -S . -B build/clang-debug \
  -G Ninja \
  -DCMAKE_C_COMPILER=clang \
  -DCMAKE_CXX_COMPILER=clang++ \
  -DCMAKE_BUILD_TYPE=Debug

cmake --build build/clang-debug
```

------

Clang – Release

```bash
cmake -S . -B build/clang-release \
  -G Ninja \
  -DCMAKE_C_COMPILER=clang \
  -DCMAKE_CXX_COMPILER=clang++ \
  -DCMAKE_BUILD_TYPE=Release

cmake --build build/clang-release
```

------

 Windows – MSVC (multi-config)

 **Developer Command Prompt for VS**-ben futtasd!

 MSVC – Debug

```cmd
cmake -S . -B build/msvc -G "Visual Studio 17 2022" -A x64
cmake --build build/msvc --config Debug
```

------

 MSVC – Release

```cmd
cmake -S . -B build/msvc -G "Visual Studio 17 2022" -A x64
cmake --build build/msvc --config Release
```

*(configure elég egyszer, build többször mehet)*

------

#  Windows – MinGW (gcc)

Debug

```cmd
cmake -S . -B build/mingw-debug \
  -G "MinGW Makefiles" \
  -DCMAKE_C_COMPILER=gcc \
  -DCMAKE_CXX_COMPILER=g++ \
  -DCMAKE_BUILD_TYPE=Debug

cmake --build build/mingw-debug
```

------

Release

```cmd
cmake -S . -B build/mingw-release \
  -G "MinGW Makefiles" \
  -DCMAKE_C_COMPILER=gcc \
  -DCMAKE_CXX_COMPILER=g++ \
  -DCMAKE_BUILD_TYPE=Release

cmake --build build/mingw-release
```

------

 Gyors puskázó

| Fordító | Debug/Release hol?       |
| ------- | ------------------------ |
| GCC     | `CMAKE_BUILD_TYPE`       |
| Clang   | `CMAKE_BUILD_TYPE`       |
| MinGW   | `CMAKE_BUILD_TYPE`       |
| MSVC    | `--config Debug/Release` |

------

„Make-érzésű” 1 soros verzió

```bash
cmake -S . -B build && cmake --build build
```

(ha már configure-álva van)

------

#### Cmake fordíto  beállítása

A CMake-ben a fordító **beállítása CMakeLists-ben** így nézhet ki:

```
# CSAK a configure pillanatában hat
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
```

**Példa MegaProject-ben**

```
cmake_minimum_required(VERSION 3.15)
project(MegaProject LANGUAGES C CXX ASM)

# -------------------
# Fordító explicit
# -------------------
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

# Debug / Release alapértelmezett
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# -------------------
# Include
# -------------------
include_directories(include)

# -------------------
# C
# -------------------
file(GLOB C_SOURCES src/c/*.c)
add_executable(c_app ${C_SOURCES})

# -------------------
# C++
# -------------------
file(GLOB CPP_SOURCES src/cpp/*.cpp)
add_executable(cpp_app ${CPP_SOURCES})
target_link_libraries(c_app mylib)
target_link_libraries(cpp_app mylib)

# -------------------
# DLL / SO
# -------------------
file(GLOB LIB_SOURCES src/lib/*.c)
add_library(mylib SHARED ${LIB_SOURCES})
```

vagy  cmake txt-ben

```
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "GCC detected")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Clang detected")
elseif(MSVC)
    message(STATUS "MSVC detected")
endif()
```

