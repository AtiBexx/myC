# C++ Fordítási Segédlet: Manuális, Makefile és CMake

Ez az útmutató segít eligazodni a több fájlból álló projektek fordításában Windows, Linux és Termux (Android) rendszereken.

---

## 1. Manuális Fordítás (Clang++ / G++)

Amikor a projekt több `.cpp` és `.h` fájlból áll, a fordítónak látnia kell az összes részt.

### Alap parancs (több fájl)
```bash
clang++ main.cpp fuggvenyek.cpp -o programom
```

### Fontos kapcsolók (Flags)
- `-I./include` : Megadja, hol keresse a `.h` fájlokat (Header include path).
- `-Wall` : Minden figyelmeztetést kiír (Warning All).
- `-std=c++20` : A használni kívánt C++ szabvány.
- `-c` : Csak objektum fájlt készít (`.o`), nem linkeli össze kész programnak.

### Optimalizációs szintek
- `-O0` : Nincs optimalizálás (fejlesztéshez, hibakereséshez).
- `-O1`, `-O2` : Jó egyensúly a sebesség és a fájlméret között.
- `-O3` : Maximális sebességre törekszik.
- `-Ofast` : Mindent belead, még a matematikai szabványokat is lazíthatja a sebességért.
- **`-march=native`** : **A LEGFONTOSABB!** A fordító a TE géped processzorához (CPU) igazítja a kódot. Minden extra utasításkészletet (AVX, SSE) kihasznál. Csak ott fog futni, de ott a leggyorsabban.

---

## 2. A Makefile (A klasszikus automatizáció)

A `make` megjegyzi a parancsokat helyetted, és csak azt fordítja újra, ami változott.
**Fontos:** A parancsok előtt MINDIG **TAB** karakternek kell lennie, nem szóköznek!

### Univerzális Makefile sablon
```make
# Változók
CXX = clang++
CXXFLAGS = -Wall -O3 -march=native -std=c++17 -I./include
TARGET = programom

# Automatikus fájlkeresés
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Fő szabály: Összeillesztés (Linkelés)
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Szabály az objektumokhoz: Minden .cpp -> .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Takarítás
clean:
	rm -f *.o $(TARGET)
```
**Használat:** `make` a fordításhoz, `make clean` a takarításhoz.

---

## 3. CMake (A modern szabvány)

A CMake nem fordít, hanem "fordítási szabályokat" (pl. Makefile-t vagy Visual Studio projektet) generál. Ez a legprofibb megoldás ma.

### CMakeLists.txt alapfájl
```cmake
cmake_minimum_required(VERSION 3.10)
project(SajatProgram)

# C++ szabvány beállítása
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header fájlok helye
include_directories(include)

# Összes forrásfájl megkeresése
file(GLOB SOURCES "*.cpp")

# A futtatható program létrehozása
add_executable(programom ${SOURCES})

# Optimalizáció hozzáadása (ha nem debug mód)
if(NOT CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(programom PRIVATE -O3 -march=native)
endif()
```

### Fordítási folyamat CMake-el
```bash
pkg install cmake  # Termuxban
mkdir build
cd build
cmake ..
make
```

---

## 4. Nano: A terminálos szerkesztő trükkjei

A Nano nem csak egy buta jegyzettömb, ha jól használod.

### Hasznos kapcsolók
- `nano -l` : Sorszámok megjelenítése (életmentő hibaüzeneteknél).
- `nano -m` : Egér használatának engedélyezése (lehet vele kattintani és görgetni).

### Szintaxis kiemelés (Színes kód)
Hozz létre egy `.nanorc` fájlt a főkönyvtáradban:
```bash
nano ~/.nanorc
```
Másold bele:
```bash
include "/data/data/com.termux/files/usr/share/nano/*.nanorc"
```
*(Windows/Linux esetén az útvonal eltérő lehet, pl. `/usr/share/nano/*.nanorc`)*

### Workflow folyamat
1. `nano -l main.cpp` -> Szerkesztés.
2. `Ctrl+O`, `Enter` -> Mentés.
3. `Ctrl+X` -> Kilépés.
4. `make` -> Fordítás.
5. `./programom` -> Tesztelés.

---

## 6. Git: Az életmentő verziókezelő

Ha elrontasz valamit a kódban, a Git segítségével bármikor visszaléphetsz az időben.

### Alap parancsok
- `git init` : Új "időgép" (tárhely) létrehozása a mappában.
- `git add .` : Minden fájl kijelölése mentésre.
- `git commit -m "Üzenet"` : Egy "mentési pont" (snapshot) létrehozása.
- `git status` : Megnézi, mi változott a legutóbbi mentés óta.
- `git log` : Megnézi a korábbi mentési pontokat.
- `git checkout .` : **VISSZAÁLLÍTÁS:** Ha mindent elrontottál, ez visszaállítja a fájlokat az utolsó jó mentésre.

---

## 7. Összegzés: Melyiket válaszd?

| Eszköz | Mikor használd? | Erőssége |
| :--- | :--- | :--- |
| **Manuális Clang++** | Tanuláshoz, 1-2 fájlhoz | Gyors, nem kell beállítani semmit. |
| **Makefile** | Közepes projektekhez, Termuxhoz | Egyszerű, villámgyors újrafordítás. |
| **CMake** | Nagy, profi projektekhez | Platformfüggetlen, minden IDE támogatja. |

**Gemmi tippje:** Kezdd a Makefile-al, mert az segít megérteni, mi történik a háttérben. Ha már több tíz fájlod van, válts CMake-re! 🚀💻
