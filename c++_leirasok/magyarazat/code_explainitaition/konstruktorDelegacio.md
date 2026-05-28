### Konstruktor Delegálás

```cpp
// Egymást hívo konstruktorok
//Ezzel a funkcióval az egyik
//Konstruktor meghívhatja a másikat
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    Hallgato(const char* mNev,
             int atadottOraSzam,
             double atadottAtlag)
    {
        std::cout << "A következő Hallgató fellépítése" << mNev <<'\n';
        std::cout << "Óraszám: " << atadottOraSzam << '\n';
        std::cout << "Átlag: " << atadottAtlag << '\n';
        nev = mNev;
        feleviOraSzam = atadottOraSzam;
        tanulmanyiAtlag = atadottAtlag;
    }
    //itt hívja az egyik konstruktor a másikat
    Hallgato() : Hallgato("Névtelen",0,0.0) {}
    Hallgato(const char* mNev): Hallgato(mNev,0,0.0){}
protected:
    std::string nev;
    int feleviOraSzam;
    double tanulmanyiAtlag;
};

int main(int argc, char** argv)
{
    Hallgato nevtelen;
    Hallgato elsoeves("[Stack]Prüntyi&Pákító");
    Hallgato cserediak("[Stack]Ati", 5, 5.0);

    Hallgato* best = new Hallgato("[Heap]Nova,Gemi,Claude", 1 , 5.0);
    delete best;

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomj kétszer egy ENTERT..." << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}

```

Ez már nagyon jó C++ 
Most éppen a **delegáló konstruktorokat** használod (constructor delegation).

Ez a rész:

```cpp
Hallgato() : Hallgato("Névtelen",0,0.0) {}
```

azt jelenti:

> a paraméter nélküli konstruktor meghívja a fő konstruktort.

Ugyanez itt:

```cpp
Hallgato(const char* mNev): Hallgato(mNev,0,0.0){}
```

Tehát:

- nincs kódismétlés,
- minden inicializálás egy helyen történik,
- modern C++ megoldás.

Ez már sokkal jobb design, mint a korábbi 3 külön konstruktor ugyanazzal a kóddal.

A programod gyakorlatilag helyes.

Csak apróságok:

### 1. Szebb formázás

```cpp
Hallgato(const char* mNev)
    : Hallgato(mNev, 0, 0.0)
{}
```

olvashatóbb.

------

### 2. „fellépítése” → „felépítése”

Elírás 🙂

```cpp
A következő Hallgató felépítése
```

------

### 3. Még modernebb verzió

Később majd ezt fogod látni:

```cpp
Hallgato(std::string mNev,
         int ora,
         double atlag)
```

vagy:

```cpp
Hallgato(const std::string& mNev,
         int ora,
         double atlag)
```

De tanulási szempontból a `const char*` teljesen jó most.

------

Amit most használsz, az konkrétan:

- konstruktor túlterhelés,
- delegáló konstruktor,
- stack vs heap,
- `new/delete`,
- `const char*`,
- `std::string`

Angolul:

```text
delegating constructor
```

vagy többes számban:

```text
delegating constructors
```

Ez a hivatalos C++ kifejezés arra, amikor egy konstruktor meghív egy másik konstruktort ugyanabban az osztályban.

Például:

```cpp
Hallgato() : Hallgato("Névtelen",0,0.0) {}
```

→ default constructor delegál a fő konstruktorhoz.

Ez a `:` nem operátor, hanem a **member initializer list** (taginicializáló lista) része C++-ban.

Ebben:

```cpp
Hallgato() : Hallgato("Névtelen",0,0.0) {}
```

a `:` azt jelenti:

> a konstruktor törzse előtt inicializálj valamit.

Normál használat:

```cpp
Hallgato() : feleviOraSzam(0), tanulmanyiAtlag(0.0)
{}
```

Itt a tagváltozókat inicializálja.

A te példádban viszont:

```cpp
Hallgato() : Hallgato("Névtelen",0,0.0)
{}
```

nem mezőt inicializál,
hanem egy MÁSik konstruktort hív meg.

Ez a delegating constructor syntax.

------

Tehát a `:` után lehet:

- tagváltozó inicializálás
- bázisosztály inicializálás
- másik konstruktor hívása

Példa:

```cpp
class Pelda
{
    int x;

public:
    Pelda() : x(5)
    {}
};
```

Itt:

- `x(5)` inicializálja az `x` mezőt.

Nem ugyanaz mint:

```cpp
x = 5;
```

mert az már assignment lenne a konstruktor törzsében.