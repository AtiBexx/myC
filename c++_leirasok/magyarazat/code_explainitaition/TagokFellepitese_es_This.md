```cpp
// TagokFellépítése
// Egy osztály átadhat argumentumokat a tagok konstruktorainak
//
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string> // némelyik fordító hibát dob ha nincs includolva az std::string-hez

int kovHallgatoiAzon = 1000;// az elsö szabályos hallgatói azonosító

class HallgatoiAzon
{
public:
    // az alapértelmezett konstruktor egymást követő azonosítokat oszt ki
    HallgatoiAzon()
    {
        ertek = kovHallgatoiAzon++;
        std::cout << "A kapott következő hallgatói azonosító: " << ertek <<'\n';
    }
    HallgatoiAzon(int azon)
    {
        ertek = azon;
        std::cout <<"A következő hallgatói azonosító hozzárendelése: " << ertek <<'\n';
    }
protected:
    int ertek;
};

class Hallgato
{
public:
    Hallgato(const char* mNev,int mFeleviOraSzam,double mTanulmanyiAtlag)
    {
        std::cout << "A következő Hallgató fellépítése: " << mNev << '\n';
        std::cout << "FÉLÉVI ÓRASZÁM: " << mFeleviOraSzam << '\n';
        std::cout << "tanulmanyi átlag: " << mTanulmanyiAtlag << '\n';
        std::cout <<'\n';
        nev = mNev;
        feleviOraSzam = mFeleviOraSzam;
        tanulmanyiAtlag = mTanulmanyiAtlag;
    }

    Hallgato(const char* mNev,int feleviOraSzam, double tanulmanyiAtlag, int azonositoSzam) :azon(azonositoSzam)
        //Hallgato() = default;
    {
        std::cout << "A következő Hallgató fellépítése: " << mNev << '\n';
        std::cout << "FÉLÉVI ÓRASZÁM: " << feleviOraSzam << '\n';
        std::cout << "tanulmanyi átlag: " << tanulmanyiAtlag << '\n';
        std::cout <<'\n';
        nev = mNev;
        this->feleviOraSzam = feleviOraSzam;
        this->tanulmanyiAtlag = tanulmanyiAtlag;
    }
protected:
    std::string nev;
    int feleviOraSzam;
    double tanulmanyiAtlag;
    HallgatoiAzon azon;
};

int main(int argc, char** argv)
{
    //Stack
    Hallgato h1("Ati", 10, 5.0);
    Hallgato h2("Prüntyi", 10, 5.0);
    Hallgato h3("Pákító", 10, 5.0);
    //Heap
    Hallgato* Hbest = new Hallgato("Nova_Gemi_Claude", 5, 5.0,1);
    delete Hbest;
    Hallgato* H2 = new Hallgato("Anonymus" , 5 ,4.5,2);
    delete H2;

    //kilépünk
    std::cout <<"A kilépéshez kérlek kétszer nyomd meg az entert..."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}

```



A `this` az aktuális objektumra mutató pointer.

Ebben az esetben azért kell, mert ugyanaz a neve a paraméternek és a tagváltozónak:

```cpp
int feleviOraSzam
```

és:

```cpp
int feleviOraSzam;
```

------

##  Mi történik `this` nélkül?

Ha ezt írod:

```cpp
feleviOraSzam = feleviOraSzam;
```

akkor a fordító így érti:

```cpp
paraméter = paraméter;
```

vagyis semmi nem történik.

A tagváltozó nem változik.

------

#  A `this->`

Azt mondja:

> “az aktuális objektum tagváltozója”

Tehát:

```cpp
this->feleviOraSzam
```

jelenti:

```text
ennek az objektumnak a feleviOraSzam tagja
```

------

## Így:

```cpp
this->feleviOraSzam = feleviOraSzam;
```

jelentése:

```text
objektum_tag = paraméter
```

------

#  A háttérben

A `this` valójában pointer:

```cpp
Hallgato* this
```

Ezért van `->`.

------

#  Példa

```cpp
class Test
{
    int x;

public:

    Test(int x)
    {
        this->x = x;
    }
};
```

Bal oldal:

```cpp
this->x
```

→ tagváltozó

Jobb oldal:

```cpp
x
```

→ paraméter

------

#  Az első konstruktorodban miért nem kell?

Mert ott más neveket adtál:

```cpp
mFeleviOraSzam
```

és:

```cpp
feleviOraSzam
```

nincs névütközés.

Ezért:

```cpp
feleviOraSzam = mFeleviOraSzam;
```

egyértelmű.

```cpp
// TagokFellépítése
// Egy osztály átadhat argumentumokat a tagok konstruktorainak
//
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string> // némelyik fordító hibát dob ha nincs includolva az std::string-hez

int kovHallgatoiAzon = 1000;// az elsö szabályos hallgatói azonosító

class HallgatoiAzon
{
public:
    // az alapértelmezett konstruktor egymást követő azonosítokat oszt ki
    HallgatoiAzon()
    {
        ertek = kovHallgatoiAzon++;
        std::cout << "A kapott következő hallgatói azonosító: " << ertek <<'\n';
    }
    HallgatoiAzon(int azon)
    {
        ertek = azon;
        std::cout <<"A következő hallgatói azonosító hozzárendelése: " << ertek <<'\n';
    }
protected:
    int ertek;
};

class Hallgato
{
public:
    Hallgato(const char* mNev,int mFeleviOraSzam = 0,double mTanulmanyiAtlag = 0.0)
    {
        std::cout << "A következő Hallgató fellépítése: " << mNev << '\n';
        std::cout << "FÉLÉVI ÓRASZÁM: " << mFeleviOraSzam << '\n';
        std::cout << "tanulmanyi átlag: " << mTanulmanyiAtlag << '\n';
        std::cout <<'\n';
        nev = mNev;
        feleviOraSzam = mFeleviOraSzam;
        tanulmanyiAtlag = mTanulmanyiAtlag;
    }

    Hallgato(const char* mNev,int feleviOraSzam, double tanulmanyiAtlag , int azonositoSzam ) :azon(azonositoSzam)
        //Hallgato() = default;
    {
        std::cout << "A következő Hallgató fellépítése: " << mNev << '\n';
        std::cout << "FÉLÉVI ÓRASZÁM: " << feleviOraSzam << '\n';
        std::cout << "tanulmanyi átlag: " << tanulmanyiAtlag << '\n';
        std::cout <<'\n';
        nev = mNev;
        this->feleviOraSzam = feleviOraSzam;
        this->tanulmanyiAtlag = tanulmanyiAtlag;
    }
protected:
    std::string nev;
    int feleviOraSzam;
    double tanulmanyiAtlag;
    HallgatoiAzon azon;
};

int main(int argc, char** argv)
{
    //Stack
    Hallgato h1("Ati", 10, 5.0);
    Hallgato h2("Prüntyi", 10, 5.0);
    Hallgato h3("Pákító", 10, 5.0);
    Hallgato h4("NotInitialize");
    //Heap
    Hallgato* Hbest = new Hallgato("Nova_Gemi_Claude", 5, 5.0,1);
    delete Hbest;
    Hallgato* H2 = new Hallgato("Anonymus" , 5 ,4.5,2);
    delete H2;

    //kilépünk
    std::cout <<"A kilépéshez kérlek kétszer nyomd meg az entert..."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}

```

#### kimenet

```cpp

A kapott következő hallgatói azonosító: 1001
A következő Hallgató fellépítése: Prüntyi
FÉLÉVI ÓRASZÁM: 10
tanulmanyi átlag: 5

A kapott következő hallgatói azonosító: 1002
A következő Hallgató fellépítése: Pákító
FÉLÉVI ÓRASZÁM: 10
tanulmanyi átlag: 5

A kapott következő hallgatói azonosító: 1003
A következő Hallgató fellépítése: NotInitialize
FÉLÉVI ÓRASZÁM: 0
tanulmanyi átlag: 0

A következő hallgatói azonosító hozzárendelése: 1
A következő Hallgató fellépítése: Nova_Gemi_Claude
FÉLÉVI ÓRASZÁM: 5
tanulmanyi átlag: 5

A következő hallgatói azonosító hozzárendelése: 2
A következő Hallgató fellépítése: Anonymus
FÉLÉVI ÓRASZÁM: 5
tanulmanyi átlag: 4.5

A kilépéshez kérlek kétszer nyomd meg az entert...


```

vagy 

**KonstruktorTúlterhelésel**

```cpp
Hallgato(const char* mNev)
{
    nev = mNev;

    feleviOraSzam = 0;
    tanulmanyiAtlag = 0.0;
}
```

azaz írunk egy új konstruktort....

| Kód                     | Mire jó                    |
| ----------------------- | -------------------------- |
| `Hallgato() = default;` | paraméter nélküli objektum |
| `Hallgato(const char*)` | csak név                   |
| default paraméterek     | opcionális argumentumok    |

---------

**Hallgato**() **= Default;**

Ez egy nagyon híres C++ csapda 😄

Ez:

```cpp
Hallgato h5();
```

NEM objektum létrehozás.

Hanem egy függvény deklaráció.

------

## A fordító ezt érti:

```cpp
Hallgato h5();
```

=

```text
egy h5 nevű függvény,
ami nem kap paramétert,
és Hallgato-t ad vissza
```

Ez az úgynevezett:

> “most vexing parse”

klasszikus C++ probléma.

------

# Valódi objektum létrehozás

Így:

```cpp
Hallgato h5;
```

vagy:

```cpp
Hallgato h5{};
```

------

# Ezért nem számít a:

```cpp
Hallgato() = default;
```

mert a `h5()` nem konstruktort hívott.

------

# Teszteld

Írd ezt:

```cpp
Hallgato h5;
```

Ha kiszeded:

```cpp
Hallgato() = default;
```

akkor már tényleg fordítási hibát kapsz.

------

# Röviden

| Kód              | Mit jelent            |
| ---------------- | --------------------- |
| `Hallgato h5();` | függvény deklaráció ❌ |
| `Hallgato h5;`   | objektum ✅            |
| `Hallgato h5{};` | objektum ✅            |

Ez az egyik legismertebb C++ szintaktikai furcsaság.

```cpp
// TagokFellépítése
// Egy osztály átadhat argumentumokat a tagok konstruktorainak
//
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string> // némelyik fordító hibát dob ha nincs includolva az std::string-hez

int kovHallgatoiAzon = 1000;// az elsö szabályos hallgatói azonosító

class HallgatoiAzon
{
public:
    // az alapértelmezett konstruktor egymást követő azonosítokat oszt ki
    HallgatoiAzon()
    {
        ertek = kovHallgatoiAzon++;
        std::cout << "A kapott következő hallgatói azonosító: " << ertek <<'\n';
    }
    HallgatoiAzon(int azon)
    {
        ertek = azon;
        std::cout <<"A következő hallgatói azonosító hozzárendelése: " << ertek <<'\n';
    }
protected:
    int ertek;
};

class Hallgato
{
public:
    Hallgato() = default;
    Hallgato(const char* mNev,int mFeleviOraSzam = 0,double mTanulmanyiAtlag = 0.0)
    {
        std::cout << "A következő Hallgató fellépítése: " << mNev << '\n';
        std::cout << "FÉLÉVI ÓRASZÁM: " << mFeleviOraSzam << '\n';
        std::cout << "tanulmanyi átlag: " << mTanulmanyiAtlag << '\n';
        std::cout <<'\n';
        nev = mNev;
        feleviOraSzam = mFeleviOraSzam;
        tanulmanyiAtlag = mTanulmanyiAtlag;
    }

    Hallgato(const char* mNev,int feleviOraSzam, double tanulmanyiAtlag , int azonositoSzam ) :azon(azonositoSzam)
        //
    {
        std::cout << "A következő Hallgató fellépítése: " << mNev << '\n';
        std::cout << "FÉLÉVI ÓRASZÁM: " << feleviOraSzam << '\n';
        std::cout << "tanulmanyi átlag: " << tanulmanyiAtlag << '\n';
        std::cout <<'\n';
        nev = mNev;
        this->feleviOraSzam = feleviOraSzam;
        this->tanulmanyiAtlag = tanulmanyiAtlag;
    }
protected:
    std::string nev;
    int feleviOraSzam;
    double tanulmanyiAtlag;
    HallgatoiAzon azon;
};

int main(int argc, char** argv)
{
    //Stack
    Hallgato h1("Ati", 10, 5.0);
    Hallgato h2("Prüntyi", 10, 5.0);
    Hallgato h3("Pákító", 10, 5.0);
    Hallgato h4("NotInitialize");
    Hallgato h5;
    //Heap
    Hallgato* Hbest = new Hallgato("Nova_Gemi_Claude", 5, 5.0,1);
    delete Hbest;
    Hallgato* H2 = new Hallgato("Anonymus" , 5 ,4.5,2);
    delete H2;

    //kilépünk
    std::cout <<"A kilépéshez kérlek kétszer nyomd meg az entert..."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}

```

Akkor megtiltod a paraméter nélküli konstruktor használatát. 👍

Tehát:

```cpp
Hallgato() = delete;
```

jelentése:

> “nem lehet `Hallgato` objektumot létrehozni argumentum nélkül”

------

# Példa

```cpp
class Hallgato
{
public:
    Hallgato() = delete;

    Hallgato(const char* nev)
    {
    }
};
```

------

# Ekkor EZ hibás:

```cpp
Hallgato h;
```

és:

```cpp
Hallgato h{};
```

is hibát dob:

```text
use of deleted function
```

------

# De ez működik:

```cpp
Hallgato h("Ati");
```

------

# És a fontos rész

Ez továbbra is:

```cpp
Hallgato h5();
```

függvény deklaráció marad 😄

A `= delete` nem befolyásolja, mert ott nem objektum készül.

------

# Mire jó a `= delete`?

Nagyon hasznos szabályozásra.

Például:

## Megtiltani másolást

```cpp
Hallgato(const Hallgato&) = delete;
```

------

## Megtiltani default konstruktort

```cpp
Hallgato() = delete;
```

------

# Röviden

| Kód         | Jelentés               |
| ----------- | ---------------------- |
| `= default` | generáld automatikusan |
| `= delete`  | tiltsd le              |

Ez modern C++-ban nagyon gyakori technika.