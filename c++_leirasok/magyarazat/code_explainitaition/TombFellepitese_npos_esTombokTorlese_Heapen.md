#### TömbFellépítése npos és TÖMBÖK Tőrlése Heapen stbstb

```cpp
//
// TömbFelépítése
//Egy objektumTömb felépítése
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <iterator>

class Hallgato
{
public:
    Hallgato()
    {
        std::cout <<"Névtelen hallgató felépítése"<<'\n';
        nev = "nevtelen";
        feleviOraSzam = 0;
        tanulmanyiAtlag = 0.0;
    }

    Hallgato(const char* mNev)
    {
        std::cout <<"A következő hallgató fellépítése: "
        << mNev <<'\n';

        nev=mNev;
        feleviOraSzam = 0;
        tanulmanyiAtlag = 0;
    }
    Hallgato(const char* mNev, int atadottOraszam, float atadottAtlag)
    : nev(mNev),feleviOraSzam(atadottOraszam), tanulmanyiAtlag(atadottAtlag)
    {
        std::cout<< "A következő hallgató fellépítése: "
        << mNev << atadottOraszam << atadottAtlag <<'\n';
    }
    ~Hallgato(){std::cout<<"Hallgató objektumok megsemmísétése : "<< nev <<'\n';}
protected:
    std::string nev;
    int feleviOraSzam;
    float tanulmanyiAtlag;
};

int main(int argc, char** argv)
{
    //stack (VEREM)
    Hallgato h[]{"Prüntyi", "Pákító"};
    Hallgato hh[] {{"Gemi",5,4.5},{"Claude",5, 4.5},{"NOVA",5,5.0}};
    Hallgato h2("Ati");
    //Heap
    Hallgato* hN = new Hallgato("Anonymus");
    //Heap Tömb
    Hallgato* nNTomb[] ={
    new Hallgato("AnonimeGril"),
    new Hallgato("HeapMaster")
    };


    std::cout<<"A FOLYTATÁSHOZ KÉRLEK NYOMD MEG KÉTSZER AZ ENTERT..."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();
    // az Enter megnyomása után kell törölni
    //tőrlés
    delete hN;
    /*delete nNTomb[0];
    delete nNTomb[1];*/

    // vagy
    /*for(int i = 0; i < std::size(nNTomb); i ++)
    {
        delete nNTomb[i];
    }*/

    //vagy
    /*for(auto p: nNTomb)
    {
        delete p;
    }*/
    //vagy
    int nNTombSize = sizeof(nNTomb) / sizeof(nNTomb[0]);
    for(int i = 0; i < nNTombSize; i++)
    {
        delete nNTomb[i];
    }

    return EXIT_SUCCESS;
}

```





A `mNev` nem fog működni, mert az csak a konstruktor paramétere volt:

```cpp
Hallgato(const char* mNev)
```

A destruktorban ez a változó már nem létezik.

A nevet az adattagban tárolod:

```cpp
std::string nev;
```

Ezért így kell:

```cpp
~Hallgato()
{
    std::cout << "Hallgató objektum megsemmisítése: "
              << nev << '\n';
}
```

vagy egy sorban:

```cpp
~Hallgato(){ std::cout << "Hallgató objektum megsemmisítése: " << nev << '\n'; }
```

Ha most lefuttatod, valami ilyesmit fogsz látni a program végén:

```text
Hallgató objektum megsemmisítése: Ati
Hallgató objektum megsemmisítése: NOVA
Hallgató objektum megsemmisítése: Claude
Hallgató objektum megsemmisítése: Gemi
Hallgató objektum megsemmisítése: Pákító
Hallgató objektum megsemmisítése: Prüntyi
```

Ez szépen megmutatja, hogy a stacken lévő objektumok fordított sorrendben semmisülnek meg.

Mellékesen: ha egy adattagot és egy paramétert ugyanúgy nevezel el, akkor a konstruktorban a `this` kulcsszóval tudod megkülönböztetni őket:

```cpp
class Hallgato
{
    std::string nev;

public:
    Hallgato(const char* nev)
    {
        this->nev = nev;
    }
};
```

A te kódodban viszont a paraméter neve `mNev`, az adattagé `nev`, ezért nincs szükség `this->` használatára.

Nem kell 3 külön destruktor. Egy osztálynak **egy destruktora lehet**.

Tehát a `Hallgato` osztályba elég egy:

```cpp
~Hallgato()
{
    std::cout << nev << " megsemmisítése\n";
}
```

Például:

```cpp
class Hallgato
{
public:
    // konstruktorok ...

    ~Hallgato()
    {
        std::cout << nev << " megsemmisítése\n";
    }

protected:
    std::string nev;
    int feleviOraSzam;
    float tanulmanyiAtlag;
};
```

------

Ha lefuttatod a programodat, a konstruktorok valami ilyesmi sorrendben futnak:

```text
Prüntyi
Pákító
Gemi
Claude
NOVA
Ati
```

A destruktorok pedig **fordított sorrendben**:

```text
Ati megsemmisítése
NOVA megsemmisítése
Claude megsemmisítése
Gemi megsemmisítése
Pákító megsemmisítése
Prüntyi megsemmisítése
```

Ez azért van, mert a stacken lévő objektumok **LIFO** (Last In, First Out) sorrendben semmisülnek meg.

------

Még egy apró stílusbeli javítás:

```cpp
std::cout<< "A következő hallgató fellépítése: "
          << mNev << atadottOraszam << atadottAtlag << '\n';
```

jelenleg ilyesmit ír ki:

```text
A következő hallgató fellépítése: Gemi54.5
```

Olvashatóbb lenne:

```cpp
std::cout << "A következő hallgató fellépítése: "
          << mNev
          << ", óraszám: " << atadottOraszam
          << ", átlag: " << atadottAtlag
          << '\n';
```

így:

```text
A következő hallgató fellépítése: Gemi, óraszám: 5, átlag: 4.5
```

Sokkal könnyebb követni, melyik konstruktor milyen adatokat kapott.

Igen, de két különböző dolgot lehet érteni alatta.

## 1. Pointerek tömbje

Van több külön heapen létrehozott objektumod:

```cpp
Hallgato* h1 = new Hallgato();
Hallgato* h2 = new Hallgato();
Hallgato* h3 = new Hallgato();
```

Ezeket egy pointertömbbe rakhatod:

```cpp
Hallgato* tomb[] = {
    new Hallgato(),
    new Hallgato("Ati"),
    new Hallgato("Gemi")
};
```

Használat:

```cpp
tomb[0]->...
tomb[1]->...
```

Törölni kell őket:

```cpp
for (int i = 0; i < 3; i++)
{
    delete tomb[i];
}
```

------

## 2. Objektumtömb a heapen

Egyszerre több objektumot kérsz a heapről:

```cpp
Hallgato* tomb = new Hallgato[5];
```

Ez 5 darab `Hallgato` objektumot hoz létre.

Ehhez kell az alapértelmezett konstruktor:

```cpp
Hallgato()
{
    ...
}
```

Használat:

```cpp
tomb[0];
tomb[1];
tomb[2];
```

Törlés:

```cpp
delete[] tomb;
```

Figyelj a `[]`-re!

------

### Mi a különbség?

#### Pointertömb

```cpp
Hallgato* tomb[] = {
    new Hallgato("Ati"),
    new Hallgato("Gemi")
};
```

Memória:

```text
Stack:
tomb[0] ---> Heap: Hallgato("Ati")
tomb[1] ---> Heap: Hallgato("Gemi")
```

------

#### Heapen lévő objektumtömb

```cpp
Hallgato* tomb = new Hallgato[2];
```

Memória:

```text
Heap:
+-----------+
| Hallgato  |
+-----------+
| Hallgato  |
+-----------+
```

Egybefüggő memóriaterület.

------

Modern C++-ban inkább ezt használják:

```cpp
std::vector<Hallgato> hallgatok;
```

vagy

```cpp
std::vector<std::unique_ptr<Hallgato>>
```

mert nem kell kézzel `new` és `delete`-tel foglalkozni. De tanulási célból nagyon hasznos megérteni a fenti két megoldást.

Itt a probléma az, hogy a `nNTomb` **nem heapen lévő objektumtömb**, hanem **pointerek tömbje**.

Ez:

```cpp
Hallgato* nNTomb[] ={
    new Hallgato("AnonimeGril"),
    new Hallgato("HeapMaster")
};
```

valójában:

```text
nNTomb[0] ---> Hallgato("AnonimeGril")
nNTomb[1] ---> Hallgato("HeapMaster")
```

A `nNTomb` maga egy normál tömb (a stacken), ezért erre nem lehet:

```cpp
delete[] nNTomb; // HIBA!
```

használni.

------

Helyesen:

```cpp
delete nNTomb[0];
delete nNTomb[1];
```

vagy ciklussal:

```cpp
for (int i = 0; i < 2; i++)
{
    delete nNTomb[i];
}
```

------

A `delete[]` csak akkor kell, ha így foglaltál:

```cpp
Hallgato* tomb = new Hallgato[2];
```

Ilyenkor:

```cpp
delete[] tomb;
```

mert egyetlen `new[]` hívással jött létre egy objektumtömb.

------

Összefoglalva:

### Egy objektum

```cpp
Hallgato* p = new Hallgato();
delete p;
```

------

### Objektumtömb

```cpp
Hallgato* p = new Hallgato[10];
delete[] p;
```

------

### Pointerek tömbje

```cpp
Hallgato* p[] = {
    new Hallgato(),
    new Hallgato()
};

delete p[0];
delete p[1];
```

Nincs:

```cpp
delete[] p;
```

mert a `p` tömböt nem `new[]` hozta létre. A te `nNTomb` változód ebbe a harmadik kategóriába tartozik.

A sima C tömbnek nincs `.size()` metódusa.

Ezért ez nem jó:

```cpp
for(int i; i < i.size(); i++)
```

mert:

- `i` egy `int`
- az `int`-nek nincs `size()` függvénye

És ez sem:

```cpp
nNTomb.size()
```

mert a `nNTomb` egy C-stílusú tömb:

```cpp
Hallgato* nNTomb[] = {
    new Hallgato("AnonimeGril"),
    new Hallgato("HeapMaster")
};
```

------

### Modern C++ (ajánlott)

Használd a `std::size`-ot:

```cpp
#include <iterator>

for (size_t i = 0; i < std::size(nNTomb); i++)
{
    delete nNTomb[i];
}
```

vagy:

```cpp
for (auto p : nNTomb)
{
    delete p;
}
```

Ez a legegyszerűbb.

------

### Régi módszer

```cpp
int meret = sizeof(nNTomb) / sizeof(nNTomb[0]);

for (int i = 0; i < meret; i++)
{
    delete nNTomb[i];
}
```

Itt:

```cpp
sizeof(nNTomb)
```

a teljes tömb mérete byte-ban.

```cpp
sizeof(nNTomb[0])
```

egy elem mérete.

A kettő hányadosa az elemszám.

------

A te példádnál én ezt írnám:

```cpp
for (auto p : nNTomb)
{
    delete p;
}
```

Mert:

- rövid
- nem kell méretet számolni
- nem lehet elrontani az indexelést

Még egy apróság: ha indexes ciklust írsz, mindig inicializáld az `i`-t:

```cpp
for (int i = 0; i < ...; i++)
```

A te verziódban:

```cpp
for(int i; ...)
```

az `i` szemétértékkel indulna, ami hiba.

Igen, a `npos` itt nem használható.

A `npos` nem általános C++ tömbméret vagy indexfogalom, hanem főleg a C++ Standard Library stringes osztályainak speciális konstansa.

Például:

```cpp
std::string s = "Hello";

if (s.find("x") == std::string::npos)
{
    std::cout << "Nincs benne";
}
```

Itt a `npos` azt jelenti:

```text
"nem található pozíció"
```

Gyakorlatilag egy nagyon nagy szám (`size_t(-1)`).

------

Ezért:

```cpp
nNTomb.npos
```

nem létezik, mert:

```cpp
Hallgato* nNTomb[]
```

egy sima C-stílusú tömb.

Nincs:

- `.size()`
- `.npos`
- `.begin()`
- `.end()`

------

Ha ezt írnád:

```cpp
std::array<Hallgato*, 2> nNTomb;
```

akkor lenne:

```cpp
nNTomb.size()
```

------

Ha pedig:

```cpp
std::vector<Hallgato*> nNTomb;
```

akkor is lenne:

```cpp
nNTomb.size()
```

------

A te kódodban a legjobb megoldás:

```cpp
for (auto p : nNTomb)
{
    delete p;
}
```

vagy:

```cpp
for (size_t i = 0; i < std::size(nNTomb); i++)
{
    delete nNTomb[i];
}
```

A `npos`-t inkább úgy jegyezd meg, hogy:

> **string kereséseknél használatos "nem található" érték**, nem tömbméret és nem ciklusokhoz való.

Igen, ott gyakran találkozol vele, de valójában akkor is **stringművelethez** kapcsolódik, nem magához a fájlhoz.

Például fájlnévnél:

```cpp
std::string fajlnev = "dokumentum.txt";

size_t pont = fajlnev.find('.');
```

Ha nincs pont a névben:

```cpp
if (pont == std::string::npos)
{
    std::cout << "Nincs kiterjesztés";
}
```

Itt a `npos` azt jelenti, hogy a `find()` nem találta meg a keresett karaktert.

Ugyanez működik:

```cpp
std::string utvonal = "C:\\temp\\file.txt";

if (utvonal.find(".txt") != std::string::npos)
{
    std::cout << "TXT fájl";
}
```

De figyeld meg, hogy még itt sem a fájlrendszer használja az `npos`-t, hanem a `std::string::find()`.

------

Másik példa:

```cpp
std::string szoveg = "Hello World";

auto pos = szoveg.find("World");

if (pos != std::string::npos)
{
    std::cout << "Megtalálva";
}
```

------

Szóval:

```text
std::string::npos
```

jelentése:

```text
érvénytelen pozíció
nem található index
```

és tipikusan ezeknél látod:

- `find()`
- `rfind()`
- `find_first_of()`
- `find_last_of()`
- fájlnevek stringes feldolgozása
- útvonalak stringes feldolgozása

de nem:

- C-stílusú tömböknél
- pointertömböknél
- `new[]` tömböknél
- ciklusok elemszámának meghatározásánál

Ezekhez inkább `std::size()`, `sizeof(...)`, `std::array::size()`, vagy `std::vector::size()` való.