# KülönAzonosító fellépítése

```cpp
//
//KülönAzonFelépítés
// Egy sikertelen kísérlet egy adattag inicializálására
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

int kovHallgatoiAzonosito = 1000;

class HallgatoiAzonosito
{
public:
// az alapértelmezett konstruktor egymást követő azonosítókat oszt ki
    HallgatoiAzonosito()
    {
        ertek = kovHallgatoiAzonosito++;
                std::cout << "A kapott hallgatói azonosító: "
                << ertek << '\n';
    }
// az int konstruktorral a felhasználó oszthat ki azonosítót
    HallgatoiAzonosito(int azonosito)
    {
        ertek = azonosito;
        std::cout << "A következő hallgatói azonosító hozzárendelése: "<<'\n';
    }
//Destruktor
    ~HallgatoiAzonosito()
    {
        std::cout<< ertek <<" megsemmisítése" <<'\n'<<'\n';
    }
protected:
    int ertek;
};

class Hallgato
{
public:
    Hallgato(const char* mNev, int khAzonosito)
    {
        std::cout << "A következő hallgató fellépítése: " << mNev <<'\n';
        nev = mNev;
        // Ez nem úgy fog müködni
        HallgatoiAzonosito azonosito(khAzonosito);// felépítünk egy hallgatói azonosítót
    }
protected:
    std::string nev;
    HallgatoiAzonosito azonosito;
};

int main(int argc, char** argv)
{
 Hallgato h1("Example", 1234);
 std::cout << "Egy üzenet a main függvényből" << '\n';

    //kilépünk
    std::cout <<"A kilépéshez kérlek nyomj meg kétszer az Entert..." << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS ;
}

```

**output:**

```cpp
A kapott hallgatói azonosító: 1000
A következő hallgató fellépítése: Example
A következő hallgatói azonosító hozzárendelése: 
1234 megsemmisítése

Egy üzenet a main függvényből
A kilépéshez kérlek nyomj meg kétszer az Entert...

```

Azért “nem működik”, mert a konstruktorban **nem az adattagot inicializálod**, hanem létrehozol egy **lokális változót**, ami rögtön meg is semmisül.

Ez a sor a probléma:

```cpp
HallgatoiAzonosito azonosito(khAzonosito);
```

Itt NEM a `Hallgato::azonosito` adattagot állítod be, hanem csinálsz egy új lokális objektumot ugyanazzal a névvel (`shadowing`).

Ezért történik ez:

1. A `Hallgato` objektum létrejön
2. Az adattagok ELŐBB felépülnek
3. A `azonosito` adattag meghívja az alapértelmezett konstruktort
4. Utána a konstruktor törzsében létrejön egy másik lokális `azonosito`
5. Az rögtön megsemmisül a konstruktor végén

Tehát két objektumod van.

A helyes megoldás: **initializer list**.

Így kell:

```cpp
class Hallgato
{
public:
    Hallgato(const char* mNev, int khAzonosito)
        : nev(mNev), azonosito(khAzonosito)
    {
        std::cout << "A következő hallgató felépítése: "
                  << mNev << '\n';
    }

protected:
    std::string nev;
    HallgatoiAzonosito azonosito;
};
```

Ez valóban az adattagot inicializálja.

A C++-ban az adattagokat NEM érdemes a konstruktor törzsében “felépíteni”, mert addigra már léteznek.

A te verziód kb. ezt csinálja logikailag:

```cpp
// adattag létrejön automatikusan
this->azonosito = HallgatoiAzonosito();

// aztán csinálsz egy teljesen külön objektumot
HallgatoiAzonosito azonosito(khAzonosito);
```

Ez egy nagyon tipikus kezdő C++ hiba.

```cpp
//
//KülönAzonFelépítés
// Egy sikertelen kísérlet egy adattag inicializálására
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

int kovHallgatoiAzonosito = 1000;

class HallgatoiAzonosito
{
public:
// az alapértelmezett konstruktor egymást követő azonosítókat oszt ki
    HallgatoiAzonosito()
    {
        ertek = kovHallgatoiAzonosito++;
                std::cout << "A kapott hallgatói azonosító: "
                << ertek << '\n';
    }
// az int konstruktorral a felhasználó oszthat ki azonosítót
    HallgatoiAzonosito(int azonosito)
    {
        ertek = azonosito;
        std::cout << "A következő hallgatói azonosító hozzárendelése: "<<'\n';
    }
//Destruktor
    ~HallgatoiAzonosito()
    {
        std::cout<< ertek <<" megsemmisítése" <<'\n'<<'\n';
    }
protected:
    int ertek;
};

class Hallgato
{
public:
    //Hallgato(const char* mNev, int khAzonosito)
    Hallgato(const char* mNev, int khAzonosito): nev(mNev),azonosito(khAzonosito)// így müködni fog
    {
        std::cout << "A következő hallgató fellépítése: " << mNev <<'\n';
        nev = mNev;
        // Ez nem úgy fog müködni
        //HallgatoiAzonosito azonosito(khAzonosito);// felépítünk egy hallgatói azonosítót
    }
protected:
    std::string nev;
    HallgatoiAzonosito azonosito;
};

int main(int argc, char** argv)
{
 Hallgato h1("Example", 1234);
 std::cout << "Egy üzenet a main függvényből" << '\n';

    //kilépünk
    std::cout <<"A kilépéshez kérlek nyomj meg kétszer az Entert..." << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS ;
}

```

**output:**

```cpp
A következő hallgatói azonosító hozzárendelése: 
A következő hallgató fellépítése: Example
Egy üzenet a main függvényből
A kilépéshez kérlek nyomj meg kétszer az Entert...
```

Persze. A kulcs az, hogy C++-ban az **adattagok a konstruktor törzse ELŐTT jönnek létre**.

Nézzük végig lépésenként.

Van ez:

```cpp
class Hallgato
{
public:
    Hallgato(const char* mNev, int khAzonosito)
    {
        nev = mNev;

        HallgatoiAzonosito azonosito(khAzonosito);
    }

protected:
    std::string nev;
    HallgatoiAzonosito azonosito;
};
```

Amikor ez lefut:

```cpp
Hallgato h1("Example", 1234);
```

a C++ ezt csinálja a háttérben:

------

# 1. lépés — memória foglalás

Létrejön a `Hallgato` objektum memóriája:

```text
Hallgato objektum:
-------------------
nev
azonosito
```

------

# 2. lépés — adattagok automatikus felépítése

Mielőtt a konstruktor törzse lefutna:

```cpp
{
    nev = mNev;

    HallgatoiAzonosito azonosito(khAzonosito);
}
```

a C++ AUTOMATIKUSAN létrehozza az adattagokat.

Tehát ez történik:

```cpp
// implicit
azonosito.HallgatoiAzonosito();
```

vagyis az alapértelmezett konstruktor fut le.

Ezért kapsz automatikus ID-t.

------

# 3. lépés — belép a konstruktor törzsébe

Most fut ez:

```cpp
HallgatoiAzonosito azonosito(khAzonosito);
```

És EZ A FONTOS:

Itt nem az adattagot használod.

Hanem létrehozol egy ÚJ lokális változót.

Kb. mintha ezt írnád:

```cpp
int x = 5;
```

Csak itt objektum:

```cpp
HallgatoiAzonosito lokalisObjektum(1234);
```

Ez a lokális objektum:

- csak a konstruktorban él
- elfedi (`shadowing`) az adattagot
- a konstruktor végén megsemmisül

------

# 4. lépés — destruktor

A lokális objektum eltűnik:

```text
1234 megsemmisítése
```

de az adattag még mindig az eredeti automatikus ID-val létezik.

------

# Miért jó az initializer list?

Ez:

```cpp
Hallgato(const char* mNev, int khAzonosito)
    : nev(mNev), azonosito(khAzonosito)
{
}
```

NEM assignment.

Hanem azt mondja:

> “amikor létrehozod az adattagot,
> rögtön ezzel a konstruktorral építsd fel”

Tehát most ez történik:

```cpp
azonosito.HallgatoiAzonosito(khAzonosito);
```

ÉS NINCS fölösleges lokális objektum.

------

# Egyszerű analógia

A te verziód:

```text
1. építs egy széket automatikusan
2. csinálj még egy széket külön
3. dobd ki a második széket
```

Initializer list:

```text
1. rögtön a megfelelő széket építsd meg
```

------

# Nagyon fontos C++ szabály

A konstruktor törzse előtt:

- minden adattag már létezik

Ezért:

- primitív típusnál lehet assignment
- objektumnál jobb initializer listet használni

Különösen kötelező:

- `const` adattagoknál
- referencia adattagoknál
- sok STL objektumnál
- inheritance esetén.

amikor kilépünk az enterrel akkor semmisülnek meg az adattagok

```cpp
A következő hallgatói azonosító hozzárendelése: 
A következő hallgató fellépítése: Example
Egy üzenet a main függvényből
A kilépéshez kérlek nyomj meg kétszer az Entert...


1234 megsemmisítése


Process returned 0 (0x0)   execution time : 347.975 s
Press ENTER to continue.

```

Most már működik jól. 👍

Azért más a kimenet, mert most az initializer listtel tényleg az adattagot inicializálod.

Korábban ez történt:

```cpp
HallgatoiAzonosito azonosito(khAzonosito);
```

→ létrejött egy ideiglenes lokális objektum
→ ezért láttad rögtön a destruktort is.

Most viszont:

```cpp
Hallgato(const char* mNev, int khAzonosito)
    : azonosito(khAzonosito)
{
}
```

Ez közvetlenül a `Hallgato` adattagját építi fel.

------

Ezért most a program menete:

# 1.

```text
A következő hallgatói azonosító hozzárendelése:
```

Lefut:

```cpp
HallgatoiAzonosito(int azonosito)
```

Tehát az adattag felépül 1234-gyel.

------

# 2.

```text
A következő hallgató fellépítése: Example
```

Most fut le a `Hallgato` konstruktor törzse.

------

# 3.

```text
Egy üzenet a main függvényből
```

Main tovább fut.

------

# 4.

A program vár az Enterre.

------

# 5.

Amikor kilépsz a programból:

akkor fogod látni:

```text
1234 megsemmisítése
```

Mert az adattag destruktora a `main` végén fut le.

------

A legfontosabb tanulság:

## Régi verzió

```cpp
HallgatoiAzonosito azonosito(khAzonosito);
```

= új lokális objektum

------

## Új verzió

```cpp
: azonosito(khAzonosito)
```

= a valódi adattag inicializálása

------

Ez a C++ egyik legfontosabb OOP/alap objektuméletciklus szabálya:

- konstrukció
- initializer list
- destrukció
- scope
- temporális objektumok

mind erre épül.