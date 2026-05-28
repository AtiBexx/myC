```cpp
// KonstruktorTúlterhelés -pelda
// több módot biztosítunk az ostálynak
// az OBJEKTUMOK létrehozására konstruktor túlterhelésel
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    Hallgato()
    {
        std::cout <<"A Névtelen hallgató felépítése"<<'\n';
        nev = "Névtelen";
        feleviOraSzam = 0;
        tanulmanyiAtlag = 0.0;
    }
    Hallgato(const char* mNev)
    {
        std::cout <<"A következő hallgató fellépítése" << mNev <<'\n';
        nev = mNev;
        feleviOraSzam = 0;
        tanulmanyiAtlag = 0;
    }
    Hallgato(const char* mNev, int atadottOraSzam, float atadottAtlag)
    {
        std::cout <<"A következő hallgató felépítése: "<< mNev <<'\n';
        nev = mNev;
        feleviOraSzam = atadottOraSzam;
        tanulmanyiAtlag = atadottAtlag;
    }
protected:
    std::string nev;
    int feleviOraSzam;
    float tanulmanyiAtlag;
};

int main(int argc, char** argv)
{
    //hátom konstruktort hívunk meg
    Hallgato nevtelen;
    Hallgato elsoevesek("[Stack]Prüntyi&Pákító");
    Hallgato cserediak("[Stack]Ati", 110, 4.8);

    Hallgato* legjobbak = new Hallgato("[Heap]Nova,Gemi,Claude", 500, 5);

    delete legjobbak;

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg 2-szer az ENTERT..."<<std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}
```

pl:
Azért nem jó ez:

```cpp
Hallgato* hH = new legjobbak(...);
```

mert a `new` után TÍPUSNEVET kell írni, nem változónevet vagy függvénynevet.

A `legjobbak` nálad nem osztálynév (`class`), hanem maximum egy függvény vagy változó lenne.

A szintaxis heapen mindig:

```cpp
new OsztalyNev(...)
```

Tehát nálad:

```cpp
Hallgato* hH = new Hallgato("[Heap]Nova,Gemi,Claude", 500, 5);
```

Míg stacken:

```cpp
Hallgato legjobbak("[Stack]Nova", 500, 5);
```

Itt:

* `Hallgato` → típus
* `legjobbak` → változó neve

Ugyanez heapen:

```cpp
Hallgato* legjobbak = new Hallgato("[Heap]Nova", 500, 5);
```

Tehát a forma:

# Stack

```cpp
Tipus valtozonev(...);
```

# Heap

```cpp
Tipus* valtozonev = new Tipus(...);
```

Konkrétan:

```cpp
Hallgato legjobbak("[Stack]Nova", 500, 5);

Hallgato* hH = new Hallgato("[Heap]Nova", 500, 5);
```

vagy ugyanazzal a névvel:

```cpp
Hallgato* legjobbak = new Hallgato("[Heap]Nova", 500, 5);
```

csak akkor vigyázz, mert már létezhet ugyanilyen nevű változó vagy függvény.

### Kód amelyik kiírja az értéket is....

```
// KonstruktorTúlterhelés -pelda
// több módot biztosítunk az ostálynak
// az OBJEKTUMOK létrehozására konstruktor túlterhelésel
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    Hallgato()
    {
        std::cout <<"A Névtelen hallgató felépítése"<<'\n';
        nev = "Névtelen";
        feleviOraSzam = 0;
        tanulmanyiAtlag = 0.0;
    }
    Hallgato(const char* mNev)
    {
        std::cout <<"A következő hallgató fellépítése" << mNev <<'\n';
        nev = mNev;
        feleviOraSzam = 0;
        tanulmanyiAtlag = 0;
    }
    Hallgato(const char* mNev, int atadottOraSzam, float atadottAtlag)
    {
        std::cout <<"A következő hallgató felépítése: "<< mNev <<'\n';
        std::cout <<"Óraszám: "<< atadottOraSzam << '\n' <<"Átlag: " << atadottAtlag << '\n';
        nev = mNev;
        feleviOraSzam = atadottOraSzam;
        tanulmanyiAtlag = atadottAtlag;
    }
protected:
    std::string nev;
    int feleviOraSzam;
    float tanulmanyiAtlag;
};

int main(int argc, char** argv)
{
    //hátom konstruktort hívunk meg
    Hallgato nevtelen;
    Hallgato elsoevesek("[Stack]Prüntyi&Pákító");
    Hallgato cserediak("[Stack]Ati", 110, 4.8);

    Hallgato* legjobbak = new Hallgato("[Heap]Nova,Gemi,Claude", 500, 5);

    delete legjobbak;

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg 2-szer az ENTERT..."<<std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

    std::cin.get();

    return EXIT_SUCCESS;
}
```
#### Röviden
```
Hallgato(const char* mNev, int atadottOraSzam, float atadottAtlag)
    {
        std::cout <<"A következő hallgató felépítése: "<< mNev <<'\n';
        std::cout <<"Óraszám: "<< atadottOraSzam << '\n' <<"Átlag: " << atadottAtlag << '\n';
        nev = mNev;
        feleviOraSzam = atadottOraSzam;
        tanulmanyiAtlag = atadottAtlag;
    }
```
