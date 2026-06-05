#### STAIKUS TAG MEGHÍVÁSA

----------

```cpp
//Statikus tagok meghívása
//két módszer egy statikus függvény meghívására
//
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    Hallgato(const char *mN ="névtelen") : szNev(mN)
    {
        hallgatokSzama++;
    }
    //destruktor
    ~Hallgato()
    {
        hallgatokSzama--;
    }
    const std::string &nev(){ return szNev; }
    static int szam() { return hallgatokSzama; }
//========================
protected:
    static int hallgatokSzama;
    std::string szNev;
};
//inicilaizáljuk a hallgatok számát
int Hallgato::hallgatokSzama = 0;

int main(int argc, char** argv)
{
    //Létrehozzunk két hallgató objektumot
    Hallgato h1("[stack]_PrünytiMüntyi");
    Hallgato *h2 = new Hallgato("[Heap]_Pákító");
    std::cout << h1.nev()  <<" és "<<'\n'<< h2->nev()
    << "Létrehozva..." <<'\n';
    std::cout <<"A Hallgatok száma: " << h1.szam() <<'\n';

    //Most töröljük a heapet és kérdezük meg újra a hallgatók számát
    std::cout <<"A Heap tőrlése -- "<< h2->nev() << "-- hallgató -- törölve...."<<'\n';
    delete h2;
    std::cout <<"A Hallgatók száma: " << Hallgato::szam() <<'\n';
    std::cout << "vége" <<'\n';

    //==========KILÉPÜNK===========================
    std::cout << "A folytatáshoz kérlek kétszer nyomd meg az ENTERT...." <<std::endl;

    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return 0;
}

```

Ebben a példában **két különböző dolog van**, amiket érdemes szétválasztani:

### 1. `const char* mN`

A konstruktorodban ez van:

```cpp
Hallgato(const char *mN ="névtelen") : szNev(mN)
```

A `const char*` jelentése:

```cpp
const char* mN
```

- `mN` egy karakterláncra mutató pointer.
- A `const` a karakterekre vonatkozik.

Tehát:

```cpp
const char* szoveg = "Hello";
```

Ezt NEM teheted:

```cpp
szoveg[0] = 'J'; // HIBA
```

mert a karakterek konstansak.

Viszont a pointer maga átállítható:

```cpp
szoveg = "Világ"; // OK
```

Ezért szokták úgy olvasni:

> "pointer konstans karakterekre"

------

### 2. Mi lenne a `char*`?

```cpp
char* szoveg;
```

Itt a karakterek módosíthatók:

```cpp
char tomb[] = "Hello";
char* szoveg = tomb;

szoveg[0] = 'J'; // OK
```

------

### 3. Mi lenne a `char* const`?

```cpp
char* const szoveg = tomb;
```

Itt:

- a karakterek módosíthatók
- a pointer nem mozgatható

```cpp
szoveg[0] = 'J'; // OK

szoveg = masik;  // HIBA
```

------

### 4. Mi lenne a `const char* const`?

```cpp
const char* const szoveg = "Hello";
```

Sem a karakterek, sem a pointer nem változhat.

------

## A `static` mit jelent itt?

Ebben:

```cpp
static int hallgatokSzama;
```

a `static` azt jelenti, hogy

**nem minden objektumnak van saját példánya belőle.**

Normál tag:

```cpp
std::string szNev;
```

minden objektumnak külön van:

```cpp
h1.szNev
h2.szNev
```

külön memóriában.

------

Viszont:

```cpp
static int hallgatokSzama;
```

csak **egyszer létezik az egész programban**.

Például:

```cpp
Hallgato h1("Ati");
Hallgato h2("Nova");
Hallgato h3("Pista");
```

Memóriában:

```text
h1.szNev -> "Ati"
h2.szNev -> "Nova"
h3.szNev -> "Pista"

hallgatokSzama -> 3
```

Egyetlen darab `hallgatokSzama` van.

Ezért tudod növelni a konstruktorban:

```cpp
hallgatokSzama++;
```

és csökkenteni a destruktorban:

```cpp
hallgatokSzama--;
```

------

### A statikus függvény

```cpp
static int szam()
{
    return hallgatokSzama;
}
```

szintén nem objektumhoz tartozik.

Ezért hívható így:

```cpp
Hallgato::szam();
```

objektum nélkül.

Vagy így is:

```cpp
h1.szam();
```

de valójában ugyanazt az egyetlen statikus függvényt hívod.

------

Röviden:

```cpp
const char* p;
```

→ a szöveg nem módosítható, a pointer igen

```cpp
static int hallgatokSzama;
```

→ egyetlen közös változó az összes Hallgato objektum számára

```cpp
static int szam();
```

→ objektum nélkül is meghívható függvény

```cpp
const std::string& nev();
```

→ a nevet csak olvasásra adja vissza, nem másolja le a stringet.

--------

**Miért kell a Növelés és csökkenés?**( POSTFIX++ )

> [( ++PREFIX --- az ellentéte )]

Amikor létrejön egy új objektum:

```cpp
Hallgato h1("Ati");
```

lefut a konstruktor:

```cpp
Hallgato(const char *mN ="névtelen")
{
    hallgatokSzama++;
}
```

A számláló 0-ról 1-re nő.

Ha létrehozol még egyet:

```cpp
Hallgato h2("Nova");
```

akkor 1-ről 2-re nő.

------

Ha egy objektum megszűnik, akkor már nem létezik, ezért csökkenteni kell a számlálót:

```cpp
~Hallgato()
{
    hallgatokSzama--;
}
```

Például:

```cpp
Hallgato* h2 = new Hallgato("Nova");
```

Létrejön:

```text
hallgatokSzama = 2
```

Majd:

```cpp
delete h2;
```

lefut a destruktor:

```cpp
hallgatokSzama--;
```

és:

```text
hallgatokSzama = 1
```

lesz.

------

Ha **nem csökkentenéd** a destruktorban, akkor hibás értéket kapnál:

```cpp
Hallgato h1("Ati");   // 1
Hallgato h2("Nova");  // 2
```

Majd `h2` törlődik, de a számláló maradna 2.

Pedig valójában már csak egy objektum létezik.

------

Ez egy gyakori minta:

```cpp
static int objektumokSzama;
```

amivel nyomon lehet követni, hogy az adott osztályból hány példány él jelenleg a memóriában.

A te programodban a futás így néz ki:

```text
Induláskor:          0

h1 létrejön:         1

h2 létrejön:         2

delete h2:           1

main vége:
h1 destruktora:      0
```

A program végén tehát ismét 0 lesz, mert már egyetlen `Hallgato` objektum sem létezik.

--------------

#### STATIKUS METÓDUS HIVATKOZHAT EGY NEM STATIKUS TAGRA

“Bizonyos esetekben, amikor a tag mérete fordításkor ismert (pl. char array), a static függvény használhatja a sizeof-ot.”

```cpp
class Hallgato
{
    public:
      static int elemekANevben()
      {
          int tombMerete = sizeof(nev);
          return tombMerete/sizeof(char);
      }
    protected:
    char nev[MAX_NEV_MERET];
    //sizeof(nev) == MAX_NEV_MERET
}
```

```cpp
#define MAX_NEV_MERET 50

class Hallgato
{
public:
    static int elemekANevben()
    {
        return MAX_NEV_MERET;
    }

protected:
    char nev[MAX_NEV_MERET];
};
```

- `static` → nincs objektum, nincs `this`, csak “osztály-szint”
- `this` → csak objektumhoz kötött függvényben létezik
- `sizeof(array)` → fix méret, fordításkor ismert (ha tényleg tömb)
- `MAX_NEV_MERET` → ilyen esetben sokszor jobb, mint bármit számolgatni

 **Rövid válasz:**
**igen, ez a kód bizonyos környezetben (C++11-től) működik, de nem jó “tanulós” példának, mert félrevezet.**

------

## MIÉRT FORDUL LE?

```cpp
static int elemekANevben()
{
    int tombMeret = sizeof(nev);
    return tombMeret / sizeof(char);
}
```

Ez azért működik, mert:

### nev` egy fix méretű tömb:

```cpp
char nev[MAX_NEV_MERET];
```

A fordító ezt már fordításkor tudja:

```text
sizeof(nev) == MAX_NEV_MERET
```

És mivel:

```cpp
sizeof(char) == 1
```

 a függvény gyakorlatilag ezt adja vissza:

```cpp
return MAX_NEV_MERET;
```

------

##  DE A FONTOS RÉSZ

Ez **NEM azt jelenti**, hogy:

> static függvény eléri a nem-static tagot

 EZ TÉVES következtetés lenne

------

##  VALÓS MAGYARÁZAT

A `sizeof(nev)` itt:

 **nem objektumhoz kötött hozzáférés**
 hanem **típus-információ**

A fordító nem ezt csinálja:

```cpp
h1.nev
```

hanem ezt:

```cpp
sizeof(char[50])
```

------

## MIKOR MENNE EL TÖNKRE?

Ha ezt átírod:

```cpp
std::string nev;
```

akkor:

```cpp
sizeof(nev); //  HIBA static függvényben
```

------

##  Helyes gondolkodás

### Ez a kód:

 működik
 de csak mert fix tömb + compile-time sizeof

------

##  TANULÁSHOZ HELYES VÁLTOZAT

Ha azt akarod, hogy “szép C++” legyen:

```cpp
class Hallgato
{
public:
    static constexpr int elemekANevben()
    {
        return MAX_NEV_MERET;
    }

protected:
    char nev[MAX_NEV_MERET];
};
```

------

##  ÖSSZEFOGLALÁS

| Állítás                                  | Igaz?             |
| ---------------------------------------- | ----------------- |
| static függvény eléri a nem-static tagot | ❌ nem általánosan |
| ez a konkrét kód működik                 | ✔️ igen            |
| mert objektumot használ                  | ❌ nem             |
| mert sizeof compile-time                 | ✔️ igen            |

------

##  Egymondatos lényeg

 A kód nem azért jó, mert static látja a tagot, hanem mert a `sizeof` miatt a fordító nem is objektumot használ.

------

Ha akarod, megmutatom ugyanennek a “csapdás verzióját”, ami elsőre működik, aztán std::string-re váltva teljesen szétesik – ez nagyon jó vizsgakérdés szokott lenni.