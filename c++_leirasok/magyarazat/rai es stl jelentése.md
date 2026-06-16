

------

#  1. Mit jelent az, hogy **RAII-barát**?

##  RAII = *Resource Acquisition Is Initialization*

Magyarul kb.:

> “az erőforrás megszerzése a konstruktorban, felszabadítása a destruktorban”

------

##  Egyszerűen:

Egy RAII-barát objektum:

- létrejön → lefoglal valamit
- megszűnik → automatikusan felszabadít mindent

------

##  Példa C++-ban:

###  RAII (jó):

```cpp
std::vector<int> v;
```

 amikor kilépsz a scope-ból:

- memória automatikusan felszabadul

------

###  fájl stream is RAII:

```cpp
std::ifstream f("file.txt");
```

 amikor vége a blokknak:

- fájl automatikusan bezáródik

------

##  Nem RAII-barát (régi stílus):

```cpp
char* p = new char[100];
```

 itt neked kell:

```cpp
delete[] p;
```

ha elfelejted → memória leak

------

##  A strstream miért nem RAII-barát?

Mert:

- kézzel kezelt buffer
- nem mindig egyértelmű ki töröl
- “ownership” zavaros

 ezért veszélyes volt

------

#  2. Mit jelent az, hogy **nem STL-kompatibilis**?

##  STL = Standard Template Library

Ez a modern C++ alapja:

- `std::vector`
- `std::string`
- `std::algorithm`
- iterátorok

------

##  STL-kompatibilis = jól együttműködik ezzel:

###  példa:

```cpp
std::vector<int> v = {1,2,3};

std::sort(v.begin(), v.end());
```

 működik, mert:

- van iterátor
- van standard interfész

------

##  nem STL-kompatibilis = régi cucc

pl. `strstream`

- nincs normális iterátor
- nem működik STL algoritmusokkal
- saját, “külön világ”

------

#  Egyszerű kép

## STL-kompatibilis:

```text
lego kockák → minden illik mindenhez
```

## nem STL-kompatibilis:

```text
régi egyedi alkatrész → nem passzol semmihez
```

------

#  Összefoglalás

| fogalom              | jelentés                                         |
| -------------------- | ------------------------------------------------ |
| RAII-barát           | automatikusan kezeli az erőforrást (biztonságos) |
| nem RAII-barát       | kézzel kell takarítani (veszélyes)               |
| STL-kompatibilis     | illeszkedik a modern C++ szabvány eszközeihez    |
| nem STL-kompatibilis | régi, izolált API, nehéz használni               |

------

#  Egy mondatban:

> RAII-barát = nem tudsz “elfelejteni takarítani”, STL-kompatibilis = könnyen illeszkedik a modern C++ eszközökbe.

------

