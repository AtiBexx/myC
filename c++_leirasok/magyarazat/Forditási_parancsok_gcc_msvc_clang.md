# Fordítás parancssorban

## PLATFORM-SPECIFIKUS KÜLÖNBSÉGEK

| Platform                   | Alapértelmezett kimenet | Statikus könyvtár | Dinamikus könyvtár | Futtatható fájl    |
| -------------------------- | ----------------------- | ----------------- | ------------------ | ------------------ |
| Windows (MinGW-w64/Cygwin) | a.exe                   | .lib vagy .a      | .dll               | .exe               |
| Linux                      | a.out                   | .a                | .so                | Nincs kiterjesztés |
| macOS                      | a.out                   | .a                | .dylib             | Nincs kiterjesztés |



# fordítási parancsok az összes fájl megtalálásához Gcc

1. **Wildcard használata**

```
g++ *.cpp -o program
```

Ez csak az **aktuális mappában** működik megkeresi az összes .`cpp` fájlt és header fájlt<b>

de az almappákra nem müködik....

2. **Minden fájl-ra (az almappákra is)**

**Linux/macOS/Git Bash:**

```
g++ $(find . -name "*.cpp") -o program
```

**Windows-on:**

**{PowerShell}:**

```
g++ $(Get-ChildItem -Recurse -Filter *.cpp | % { $_.FullName }) -o program
```

vagy

```
g++ (Get-ChildItem -Recurse -Filter *.cpp | ForEach-Object { $_.FullName }) -o program
```



ha vannak szöközök az útvonalakban

```
g++ @(gci -Recurse -Filter *.cpp | % { "`"$($_.FullName)`"" }) -o program
```



**CMD-ben bash-el**

```
@echo off
setlocal enabledelayedexpansion

REM összegyűjtjük az összes .cpp fájl elérési útját
set SOURCES=
for /R %%f in (*.cpp) do (
    set SOURCES=!SOURCES! "%%f"
)

REM fordítás g++-szal
g++ !SOURCES! -o program.exe
```

**bash-nélkül**

```
set SOURCES= & for /R %f in (*.cpp) do set SOURCES=%SOURCES% "%f" & g++ %SOURCES% -o program.exe
```

### Clang esetén:

```
@echo off
setlocal enabledelayedexpansion

REM összegyűjtjük az összes .cpp fájl elérési útját
set SOURCES=
for /R %%f in (*.cpp) do (
    set SOURCES=!SOURCES! "%%f"
)

REM fordítás g++-szal vagy clang++-szal
g++ !SOURCES! -o program.exe
REM vagy
clang++ !SOURCES! -o program.exe
```
**bash-nélkül**

```
set SOURCES= & for /R %f in (*.cpp) do set SOURCES=%SOURCES% "%f" & g++ %SOURCES% -o program.exe
```

### **MSVC-esetén:**

```
@echo off
setlocal enabledelayedexpansion

set SOURCES=
set OBJS=
for /R %%f in (*.cpp) do (
    set SOURCES=!SOURCES! "%%f"
    set OBJ=%%~nf.obj
    set OBJS=!OBJS! !OBJ!
    cl /nologo /EHsc /c "%%f" /Fo!OBJ!
)

REM Linkelés
link /NOLOGO /OUT:program.exe !OBJS!
```

vagy 

ha a `main.cpp` a **gyökérben van**, a többi fájl más mappákban. Akkor CMD-ben egyszerűen **meg kell adni teljes elérési utat mindenhez**<br>

```
g++ main.cpp src\foo.cpp src\bar.cpp -Iinclude -o program.exe
```

project/
├─ main.cpp
├─ src/
│  ├─ foo.cpp
│  └─ bar.cpp
└─ include/
   └─ foo.h

**vagy a MakeFile használata:** 

```
# a fordító és a kapcsolók
CXX = g++
CXXFLAGS = -Wall -g -Iinclude

# a végső program neve
TARGET = program.exe

# a forrásfájlok
SRCS = main.cpp src/foo.cpp

# az objektum fájlok (fordítás intermediate)
OBJS = $(SRCS:.cpp=.o)

# alapértelmezett cél
all: $(TARGET)

# ha van dll fájlod és lib fájlod
LIBS = pr.lib  # vagy libpr.a

# a végső program készítése
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# objektumok fordítása
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# takarítás (felesleges fájlok törlése)
clean:
	del $(OBJS) $(TARGET)

```

Ha csak a DLL van, nincs `.lib`

- Akkor **runtime-on kell a program mellé másolni** a DLL-t.

-----------------

`-Iinclude` → ide adod a header fájlok mappáját.

`src/foo.cpp` → a forrásfájl mappáját is meg kell adni.

A Makefile neve **egyszerűen `Makefile`**, pontosan így, nagy “M”-mel, és **nincs kiterjesztése**.

- Ha `make` parancsot futtatsz ugyanabban a mappában, ahol a `Makefile` van, **automatikusan felismeri**.
- Alternatívaként lehet **kis “m”**: `makefile`, az is működik, de a **nagy “M” a szokásos és a leggyakoribb**.

de ha más a fájlod neve akkor kell a `make -f FájlNeve` és ilyenkor a parancs:

```
make -f MyBuildFile
```

ha Makefile a neve ellég a

```
make
```

parancs.

### Clang-al

```
CXX = clang++
CXXFLAGS = -Wall -g -Iinclude

TARGET = program.exe
SRCS = main.cpp src/foo.cpp
OBJS = $(SRCS:.cpp=.o)
LIBS = pr.lib   # vagy libpr.a

all: $(TARGET) copydll

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

copydll:
	copy pr.dll .

clean:
	del $(OBJS) $(TARGET) pr.dll

```

### MSVC-vel

```
# fordító és opciók
CXX = cl
CXXFLAGS = /nologo /W3 /EHsc /Iinclude

TARGET = program.exe
SRCS = main.cpp src\foo.cpp
OBJS = $(SRCS:.cpp=.obj)
LIBS = pr.lib

all: $(TARGET) copydll

$(TARGET): $(OBJS)
	link /NOLOGO /OUT:$(TARGET) $(OBJS) $(LIBS)

%.obj: %.cpp
	$(CXX) $(CXXFLAGS) /c $< /Fo$@

copydll:
	copy pr.dll .

clean:
	del $(OBJS) $(TARGET) pr.dll

```

Ha a projekted **C++, Python, Java, assembly** fájlokat is tartalmaz, egy Makefile lehet így:

```
all: cpp prog java python asm

cpp: main.cpp foo.cpp
	g++ main.cpp foo.cpp -o program.exe

java: HelloWorld.java
	javac HelloWorld.java

python: myscript.py
	@echo "Python script, nincs build, csak futtatható"
	@python myscript.py

asm: code.asm
	nasm -f win32 code.asm -o code.obj
	g++ code.obj -o asmprogram.exe
```

**Teljes futatható makefile példa:**

```
# ========================
# MSVC – C / C++
# ========================
CXX = cl
CC  = cl
CXXFLAGS = /nologo /W3 /EHsc /Iinclude
CFLAGS   = /nologo /W3 /Iinclude

TARGET = program.exe
CSRCS = cmain.c
CPPSRCS = main.cpp src\foo.cpp

COBJS = $(CSRCS:.c=.obj)
CPPOBJS = $(CPPSRCS:.cpp=.obj)

LIBS = pr.lib

# ========================
# Alapértelmezett target
# ========================
all: cpp java python asm kotlin copydll

# ========================
# C++
# ========================
cpp: $(CPPOBJS)
	link /NOLOGO /OUT:$(TARGET) $(CPPOBJS) $(LIBS)

%.obj: %.cpp
	$(CXX) $(CXXFLAGS) /c $< /Fo$@

# ========================
# C
# ========================
c: $(COBJS)
	link /NOLOGO /OUT:c_program.exe $(COBJS)

%.obj: %.c
	$(CC) $(CFLAGS) /c $< /Fo$@

# ========================
# Java
# ========================
java:
	javac java\Main.java
	java -cp java Main

# ========================
# Python
# ========================
python:
	python python\script.py

# ========================
# Assembly (NASM)
# ========================
asm:
	nasm -f win64 asm\hello.asm -o hello.obj
	link /NOLOGO /OUT:asm_program.exe hello.obj

# ========================
# Kotlin (JVM)
# ========================
kotlin:
	kotlinc kotlin\Main.kt -include-runtime -d kotlin_program.jar
	java -jar kotlin_program.jar

# ========================
# DLL másolás
# ========================
copydll:
	copy pr.dll .

# ========================
# Takarítás
# ========================
clean:
	del /Q *.obj *.exe *.jar 2>NUL
```

Futatás:

`make`            :: mindent
`make cpp `       :: C++ (MSVC)
`make c`          :: C (MSVC)
`make java`       :: Java
`make python`     :: Python
`make asm`        :: Assembly
`make kotlin`     :: Kotlin
`make clean`      :: takarítás

**{Linuxon}**

```
# ========================
# C / C++
# ========================
CXX = g++
CC  = gcc
CXXFLAGS = -Wall -Wextra -g -Iinclude
CFLAGS   = -Wall -Wextra -g -Iinclude

TARGET = program
CSRCS = cmain.c
CPPSRCS = main.cpp src/foo.cpp

COBJS = $(CSRCS:.c=.o)
CPPOBJS = $(CPPSRCS:.cpp=.o)

LIBS = -lpr   # libpr.so

# ========================
# Default
# ========================
all: cpp java python asm kotlin

# ========================
# C++
# ========================
cpp: $(CPPOBJS)
	$(CXX) -o $(TARGET) $(CPPOBJS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ========================
# C
# ========================
c: $(COBJS)
	$(CC) -o c_program $(COBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ========================
# Java
# ========================
java:
	javac java/Main.java
	java -cp java Main

# ========================
# Python
# ========================
python:
	python3 python/script.py

# ========================
# Assembly (NASM)
# ========================
asm:
	nasm -f elf64 asm/hello.asm -o hello.o
	$(CXX) hello.o -o asm_program

# ========================
# Kotlin
# ========================
kotlin:
	kotlinc kotlin/Main.kt -include-runtime -d kotlin_program.jar
	java -jar kotlin_program.jar

# ========================
# Clean
# ========================
clean:
	rm -f *.o program c_program asm_program *.jar
```

2 verzio

```
make -f Makefile.win
make -f Makefile.linux
```

vagy

OS beállítás

```
ifeq ($(OS),Windows_NT)
  RM = del
  EXE = .exe
else
  RM = rm -f
  EXE =
endif
```

# További fordítási parancsok

## MSVC FORDÍTÁSI PARANCSOK

### Egy fájl fordítása

```bash
cl.exe cppFajlodNeve.cpp
```

- Létrehozza a `cppFajlodNeve.exe` fájlt.
- A `.exe` kiterjesztést automatikusan hozzáadja.

### Több fájl fordítása egyszerre

```bash
cl.exe FájlodNeve.cpp másikFájlodNeve.cpp HarmadikFájlodNeve.cpp
```

- A header fájlokat nem kell külön megadni, mert a `#include` utasításokat a preprocesszor feldolgozza.
- Csak a `.cpp` fájlokat kell megadni.

### Header fájlok más mappában

```bash
cl.exe aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve
```

- Az `-I` opcióval adható meg a keresési útvonal a header fájlokhoz.
- A `/I` is működik (MSVC elfogadja mindkettőt).
- Például: `-I./include` (ahol a `.h` header fájl található).

### A program nevének megadása

```bash
cl.exe aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve /Fe:MyProgram.exe
```

- Az `/Fe:` opcióval lehet megadni a kimeneti fájl nevét.
- A `/Fe:MyProgram.exe` azt jelenti, hogy a kimenet `MyProgram.exe` legyen.

### Statikus könyvtárak linkelése (Release mód)

```bash
cl.exe main.cpp mydll_static.lib mydll2_static.lib /MT
```

- Az `/MT` opcióval a program statikusan linkeli a CRT (C Runtime) könyvtárat.
- Így nem kell telepíteni a Visual C++ Redistributables csomagot.
- A `.lib` fájlokat közvetlenül meg lehet adni a parancsban.

### Statikus könyvtárak linkelése (Debug mód)

```bash
cl.exe main.cpp mydll_static.lib mydll2_static.lib /MTd
```

- Az `/MTd` opcióval a program statikusan linkeli a CRT Debug verzióját.
- Debug módban mindig `/MTd`-t használj `/MT` helyett.

### Dinamikus könyvtárak (DLL) linkelése

```bash
cl.exe main.cpp mydll.lib mydll2.lib
```

- A DLL-ek használatához a hozzájuk tartozó `.lib` fájlt kell megadni a fordítás során.
- A `.dll` fájlt magát a program futtatásához kell elérhetővé tenni (pl. a PATH-ban vagy a program mappájában).

## GCC FORDÍTÁSI PARANCSOK (Windows MinGW-w64/Cygwin)

### Egy fájl fordítása

```bash
g++ cppFajlodNeve.cpp
```

- Létrehozza az `a.exe` fájlt (Windows MinGW alapértelmezett név).
- Az `.exe` kiterjesztést automatikusan hozzáadja Windows-on.

### Több fájl fordítása egyszerre

```bash
g++ FájlodNeve.cpp másikFájlodNeve.cpp HarmadikFájlodNeve.cpp
```

- A header fájlokat nem kell külön megadni, mert a `#include` utasításokat a preprocesszor feldolgozza.
- Csak a `.cpp` fájlokat kell megadni.

### Header fájlok más mappában

```bash
g++ aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve
```

- Az `-I` opcióval adható meg a keresési útvonal a header fájlokhoz.
- Például: `-I./include` (ahol a `.h` header fájl található).

### A program nevének megadása

```bash
g++ aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve -o MyProgram.exe
```

- Az `-o` opcióval lehet megadni a kimeneti fájl nevét.
- Windows-on: `-o MyProgram.exe`
- A `.exe` kiterjesztést meg kell adni.

### Statikus könyvtárak linkelése

```bash
g++ main.cpp -L./lib_mappa -lmydll_static -lmydll2_static -static
```

- Az `-L` opcióval megadható a könyvtár mappája.
- Az `-l` opcióval megadható a könyvtár neve (lib előtag és `.a` kiterjesztés nélkül).
- A `-static` opcióval minden könyvtár statikusan lesz linkelve.
- Például: `libmydll_static.a` → `-lmydll_static`

### Dinamikus könyvtárak linkelése

```bash
g++ main.cpp -L./lib_mappa -lmydll -lmydll2
```

- Windows-on a `.dll` fájlt a program mellé vagy a PATH-ba kell tenni.
- Például: `libmydll.dll` → `-lmydll`

## GCC FORDÍTÁSI PARANCSOK (Linux)

### Egy fájl fordítása

```bash
g++ cppFajlodNeve.cpp
```

- Létrehozza az `a.out` fájlt (Linux alapértelmezett név).
- Nincs `.exe` kiterjesztés.

### Több fájl fordítása egyszerre

```bash
g++ FájlodNeve.cpp másikFájlodNeve.cpp HarmadikFájlodNeve.cpp
```

- A header fájlokat nem kell külön megadni.
- Csak a `.cpp` fájlokat kell megadni.

### Header fájlok más mappában

```bash
g++ aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve
```

- Az `-I` opcióval adható meg a keresési útvonal a header fájlokhoz.

### A program nevének megadása

```bash
g++ aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve -o MyProgram
```

- Az `-o` opcióval lehet megadni a kimeneti fájl nevét.
- Linux-en: `-o MyProgram` (nincs `.exe` kiterjesztés).

### Statikus könyvtárak linkelése

```bash
g++ main.cpp -L./lib_mappa -lmydll_static -lmydll2_static -static
```

- Az `-L` opcióval megadható a könyvtár mappája.
- Az `-l` opcióval megadható a könyvtár neve.
- A `-static` opcióval minden könyvtár statikusan lesz linkelve.
- Például: `libmydll_static.a` → `-lmydll_static`

### Dinamikus könyvtárak linkelése

```bash
g++ main.cpp -L./lib_mappa -lmydll -lmydll2
```

- A `.so` fájlt a program mellé vagy az `LD_LIBRARY_PATH`-ba kell tenni.
- Például: `libmydll.so` → `-lmydll`

## GCC FORDÍTÁSI PARANCSOK (macOS)

### Egy fájl fordítása

```bash
g++ cppFajlodNeve.cpp
```

- Létrehozza az `a.out` fájlt (macOS alapértelmezett név).
- Nincs `.exe` kiterjesztés.

### Több fájl fordítása egyszerre

```bash
g++ FájlodNeve.cpp másikFájlodNeve.cpp HarmadikFájlodNeve.cpp
```

- A header fájlokat nem kell külön megadni.
- Csak a `.cpp` fájlokat kell megadni.

### Header fájlok más mappában

```bash
g++ aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve
```

- Az `-I` opcióval adható meg a keresési útvonal a header fájlokhoz.

### A program nevének megadása

```bash
g++ aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve -o MyProgram
```

- Az `-o` opcióval lehet megadni a kimeneti fájl nevét.
- macOS-en: `-o MyProgram` (nincs `.exe` kiterjesztés).

### Statikus könyvtárak linkelése

```bash
g++ main.cpp -L./lib_mappa -lmydll_static -lmydll2_static -static
```

- Az `-L` opcióval megadható a könyvtár mappája.
- Az `-l` opcióval megadható a könyvtár neve.
- A `-static` opcióval minden könyvtár statikusan lesz linkelve.
- Például: `libmydll_static.a` → `-lmydll_static`

### Dinamikus könyvtárak linkelése

```bash
g++ main.cpp -L./lib_mappa -lmydll -lmydll2
```

- A `.dylib` fájlt a program mellé vagy a `DYLIB_LIBRARY_PATH`-ba kell tenni.
- Például: `libmydll.dylib` → `-lmydll`

## CLANG FORDÍTÁSI PARANCSOK (Windows)

### Egy fájl fordítása

```bash
clang++ cppFajlodNeve.cpp
```

- Létrehozza az `a.exe` fájlt (Windows alapértelmezett név).
- Az `.exe` kiterjesztést automatikusan hozzáadja Windows-on.

### Több fájl fordítása egyszerre

```bash
clang++ FájlodNeve.cpp másikFájlodNeve.cpp HarmadikFájlodNeve.cpp
```

- A header fájlokat nem kell külön megadni, mert a `#include` utasításokat a preprocesszor feldolgozza.
- Csak a `.cpp` fájlokat kell megadni.

### Header fájlok más mappában

```bash
clang++ aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve
```

- Az `-I` opcióval adható meg a keresési útvonal a header fájlokhoz.
- Például: `-I./include` (ahol a `.h` header fájl található).

### A program nevének megadása

```bash
clang++ aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve -o MyProgram.exe
```

- Az `-o` opcióval lehet megadni a kimeneti fájl nevét.
- Windows-on: `-o MyProgram.exe`
- A `.exe` kiterjesztést meg kell adni.

### Statikus könyvtárak linkelése

```bash
clang++ main.cpp -L./lib_mappa -lmydll_static -lmydll2_static -static
```

- Az `-L` opcióval megadható a könyvtár mappája.
- Az `-l` opcióval megadható a könyvtár neve (lib előtag és `.a` vagy `.lib` kiterjesztés nélkül).
- A `-static` opcióval minden könyvtár statikusan lesz linkelve.
- Például: `libmydll_static.a` vagy `mydll_static.lib` → `-lmydll_static`

### Dinamikus könyvtárak linkelése

```bash
clang++ main.cpp -L./lib_mappa -lmydll -lmydll2
```

- Windows-on a `.dll` fájlt a program mellé vagy a PATH-ba kell tenni.
- Például: `mydll.dll` → `-lmydll`

## CLANG FORDÍTÁSI PARANCSOK (Linux)

### Egy fájl fordítása

```bash
clang++ cppFajlodNeve.cpp
```

- Létrehozza az `a.out` fájlt (Linux alapértelmezett név).
- Nincs `.exe` kiterjesztés.

### Több fájl fordítása egyszerre

```bash
clang++ FájlodNeve.cpp másikFájlodNeve.cpp HarmadikFájlodNeve.cpp
```

- A header fájlokat nem kell külön megadni.
- Csak a `.cpp` fájlokat kell megadni.

### Header fájlok más mappában

```bash
clang++ aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve
```

- Az `-I` opcióval adható meg a keresési útvonal a header fájlokhoz.

### A program nevének megadása

```bash
clang++ aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve -o MyProgram
```

- Az `-o` opcióval lehet megadni a kimeneti fájl nevét.
- Linux-en: `-o MyProgram` (nincs `.exe` kiterjesztés).

### Statikus könyvtárak linkelése

```bash
clang++ main.cpp -L./lib_mappa -lmydll_static -lmydll2_static -static
```

- Az `-L` opcióval megadható a könyvtár mappája.
- Az `-l` opcióval megadható a könyvtár neve.
- A `-static` opcióval minden könyvtár statikusan lesz linkelve.
- Például: `libmydll_static.a` → `-lmydll_static`

### Dinamikus könyvtárak linkelése

```bash
clang++ main.cpp -L./lib_mappa -lmydll -lmydll2
```

- A `.so` fájlt a program mellé vagy az `LD_LIBRARY_PATH`-ba kell tenni.
- Például: `libmydll.so` → `-lmydll`

## CLANG FORDÍTÁSI PARANCSOK (macOS)

### Egy fájl fordítása

```bash
clang++ cppFajlodNeve.cpp
```

- Létrehozza az `a.out` fájlt (macOS alapértelmezett név).
- Nincs `.exe` kiterjesztés.

### Több fájl fordítása egyszerre

```bash
clang++ FájlodNeve.cpp másikFájlodNeve.cpp HarmadikFájlodNeve.cpp
```

- A header fájlokat nem kell külön megadni.
- Csak a `.cpp` fájlokat kell megadni.

### Header fájlok más mappában

```bash
clang++ aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve
```

- Az `-I` opcióval adható meg a keresési útvonal a header fájlokhoz.

### A program nevének megadása

```bash
clang++ aFájlodNeve.cpp másikFájlodNeve.cpp -I./MappádNeve -o MyProgram
```

- Az `-o` opcióval lehet megadni a kimeneti fájl nevét.
- macOS-en: `-o MyProgram` (nincs `.exe` kiterjesztés).

### Statikus könyvtárak linkelése

```bash
clang++ main.cpp -L./lib_mappa -lmydll_static -lmydll2_static -static
```

- Az `-L` opcióval megadható a könyvtár mappája.
- Az `-l` opcióval megadható a könyvtár neve.
- A `-static` opcióval minden könyvtár statikusan lesz linkelve.
- Például: `libmydll_static.a` → `-lmydll_static`

### Dinamikus könyvtárak linkelése

```bash
clang++ main.cpp -L./lib_mappa -lmydll -lmydll2
```

- A `.dylib` fájlt a program mellé vagy a `DYLD_LIBRARY_PATH`-ba kell tenni.
- Például: `libmydll.dylib` → `-lmydll`

## Megjegyzések

- A Clang parancsai nagyon hasonlóak a GCC parancsaihoz, mivel mindkettő ugyanazokat a GNU parancssori opciókakat használja.
- A `clang++` a C++ fordító, míg a `clang` a C fordító.
- A Clang általában jobb hibaüzeneteket ad, mint a GCC.
- macOS-en a `clang++` az alapértelmezett C++ fordító (a `g++` gyakran csak egy alias a `clang++`-ra).