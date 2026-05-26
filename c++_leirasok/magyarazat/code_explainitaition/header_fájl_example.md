## Header fájl példa

**owndata.cpp**

```
#include "owndata.h"
#include <cmath>

double own_sin (double x)
{
    return std::sin(x);
}

double own_cosin (double x)
{
    return std::cos(x);
}

double own_tan (double x)
{
    return std::tan(x);
}

/*
Mi a kapszulázás?
Egyszerűen:
Adatok + működés egy "dobozba" zárása, és elrejtése a külvilág elől.
Vagy még egyszerűbben:
Csak azt látod amit kell, a többi rejtve van.

private == Csak az osztály saját tagjai férhetnek hozzá.
protected == Olyan, mint a private, de a leszármazott osztályok is hozzáférhetnek. Külső kód nem látja, csak az öröklődő osztály.
public == Mindenki hozzáférhet az adott változóhoz/funkcióhoz bárhonnan.

Interface == MIT tudsz hívni
Encapsulation == MIT nem láthatsz
*/
```

**main.cpp**/ vagy preprocessor.cpp

```
#include "owndata.h"
#include <iostream>
#include <cstdlib>
#include<cstdio>
/*Ha az #includet"" időzöjelekben adod meg a saját mappájában fogja kereni a header fájl
C++ -nál nem szükséges.h kiterjesztés kell, de a C-ben szükséges(és müködik .h-val is)
ha pedig <> csúcsós zárojelek között adod meg akkor a saját könyvtáraiban kezdi keresni a header fájlt
tehát amiket te csinálsz mindig "" idézőjelek között add meg.
a Header fájl csak deklarációk, a megvalósiításokat a .cpp fájlban kell megvalósiítani
"*/
/*
A header azért kell, hogy több fájl tudja használni ugyanazt a kódot anélkül hogy lemásolnád....
*/
int main(int argc, char* argv[])
{
    std::cout << "A .5 szinusza: " << own_sin(0.5) << std::endl;
    std::cout << "nyomd meg az Entert a kilépéshez" << std::endl;
    std::cin.get();
    return 0;
}
```

**owndata.h**

```
#ifndef OWNDATA_H
#define OWNDATA_H
//vagy c++17-óta pragma once 
double own_sin (double x);
double own_cosin (double x);
double own_tan (double x);

#endif // OWNDATA_H
/*
Interface == A program azon része amit más kód használhat.
Interfész = amit egy kód kifelé mutat magából.
Nem az hogyan működik,
hanem hogyan lehet használni.
*/

/*
#ifndef
Jelentése: “if not defined”, azaz „ha nincs definiálva”.
Azt ellenőrzi, hogy egy makró már létezik-e.
Ha még nincs definiálva, akkor a következő kódot engedi be.
header guard-ként használják, hogy egyszer csak legyen 
beolvasva a header fájl, még ha többször is includelnék.
*/

/*
#define
Jelentése: definiál egy makrót.
Itt azt mondjuk: „most már definiáltam az OWNDATA_H-t”.
így ha később valahol újra include-oljuk ezt a header-t, 
az #ifndef OWNDATA_H hamis lesz, és a kód nem kerül újra beolvasásra.
Ez megakadályozza a többszörös definíció miatti hibákat.
*/

/*
#endif az if/else-szerű direktívák “lezáró kulcsa” a C++ preprocessorban.
Minden #ifndef, #ifdef vagy #if blokkot le kell zárni #endif-tel.
Jelezze a fordítónak: „itt ér véget az ellenőrzés, mostantól újra normál kód következik”.
*/

/*
A #pragma once a C++-ban egy modern, egyszerűsített alternatívája a header guard-nek 
(#ifndef … #define … #endif)

#pragma once   // elég egyszer írni a fájl elejére

double own_sin(double x);
double own_cosin(double x);
double own_tan(double x);
*/
```

fordítás: `g++ preprocessor.cpp owndata.cpp -o preprocessor`

vagy

Külön fordítás**C++ fordítási modellje**, ezt hívják **separate compilation**-nek....

### Hogyan néz ki?

Tegyük fel, van két fájlod:

- `owndata.cpp` – itt van a `own_sin`, `own_cosin`, `own_tan` implementációja
- `preprocessor.cpp` – itt használod ezeket a függvényeket `#include "owndata.h"`-dal

------

#### Lépés 1: Külön fordítás

```bash
g++ -c owndata.cpp -o owndata.o
g++ -c preprocessor.cpp -o preprocessor.o
```

- A `-c` **csak fordítja** a fájlokat, **nem linkeli**.
- Az `.o` fájlok **objektum fájlok**, tartalmazzák a gépi kódot, de még nem a végrehajthatót.

------

#### Lépés 2: Linkelés

```bash
g++ owndata.o preprocessor.o -o preprocessor
```

- Ez összekapcsolja a két objektum fájlt és létrehozza a futtatható `preprocessor` programot.
- A linker összerakja a hívásokat (`own_sin`) a megfelelő objektum kódhoz.

------

### Miért jó?

- **Gyorsabb fordítás**: ha csak a `preprocessor.cpp` változik, nem kell újrafordítani az `owndata.cpp`-t.
- **Tisztább moduláris kód**: minden cpp a saját felelősségi körét tartalmazza.
- **Nagy projektnél kötelező**: így több száz fájl esetén is kezelhető a fordítás.

------

