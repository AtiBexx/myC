#### Részleges másolat Pointer

```cpp
//Részleges Másolat
//Bájtonként részleges másolatot készít
//helytelen ha az osztály erőforrásokat tartalmaz

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Szemely
{
public:
    Szemely(const char *mN)
    {
        std::cout <<"Felépítés: " <<mN <<'\n';
        mNev= new std::string(mN);
    }
    //desktruktor
    ~Szemely()
    {
        std::cout<<"Megsemmisítés: " << mNev
        << " (" << *mNev << ")" <<'\n';
        *mNev = "Már megsemisített memória";
        //összeomlik ha törlünk memóriát
        //mert mind a 2 egy memóriacímre mutat
        //delete mNev;
    }
protected:
    std::string *mNev;
};
void fv()
{
    //létrehozunk egy uj objektumot
    Szemely sz1("LONG_NAME");
    //átmásoljuk a tartalmát az sz2-be
    Szemely sz2(sz1);
}
int main(int argc, char** argv)
{
    std::cout<<"Az fv() meghívása" <<'\n';
    fv();
    std::cout<<"vége újra a main függvényben"<<'\n';
    //kilépünk
    std::cout <<"A Kilépéshez kérlek nyomd meg kétszer az entert" << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return 0;
}

```

**OUTPUT:**

```cpp
Az fv() meghívása
Felépítés: LONG_NAME
Megsemmisítés: 0x5620c69506c0 (LONG_NAME)
Megsemmisítés: 0x5620c69506c0 (Már megsemisített memória)
vége újra a main függvényben
A Kilépéshez kérlek nyomd meg kétszer az entert
```

Igen, **normál esetben kellene a `delete mNev;`**, hiszen a konstruktorban ezt csinálod:

```cpp
mNev = new std::string(mN);
```

Amihez tartozik egy:

```cpp
delete mNev;
```

a destruktorban.

Viszont a példa  azt akarja bemutatni, hogy miért veszélyes az alapértelmezett (bájtonkénti) másolás.

Amikor ezt írod:

```cpp
Szemely sz1("LONG_NAME");
Szemely sz2(sz1);
```

mivel nincs saját másoló konstruktorod, a fordító generál egyet, ami lényegében ezt csinálja:

```cpp
sz2.mNev = sz1.mNev;
```

Tehát:

```text
sz1.mNev ----+
             |
             v
        "LONG_NAME"
             ^
             |
sz2.mNev ----+
```

Mindkét objektum ugyanarra a `std::string`-re mutat.

Ha a destruktorban lenne:

```cpp
delete mNev;
```

akkor:

1. `sz2` megsemmisül → `delete mNev`
2. a string felszabadul
3. `sz1` megsemmisül → ismét `delete mNev`
4. ugyanazt a memóriát próbálja felszabadítani másodszor

Ez az úgynevezett **double delete**, ami nem definiált működés (tipikusan összeomlás).

Ezért van most kikommentezve:

```cpp
// delete mNev;
```

hogy a program demonstrálhassa a problémát anélkül, hogy azonnal elszállna.

A helyes megoldás ilyenkor egy saját másoló konstruktor:

```cpp
Szemely(const Szemely& masik)
{
    mNev = new std::string(*masik.mNev);
}
```

Ekkor:

```text
sz1.mNev --> "LONG_NAME"

sz2.mNev --> "LONG_NAME"
```

két külön `std::string` objektum jön létre, így már biztonságosan lehet:

```cpp
~Szemely()
{
    delete mNev;
}
```

Ez az egyik klasszikus példa arra, hogy miért van szükség saját másoló konstruktorra, ha az osztály dinamikusan foglalt erőforrást (például `new`-val lefoglalt memóriát) kezel. Ezt szokták a C++-ban a "Rule of Three" témakörében tanítani.

Igen, ez egy jó megjegyzés. Kicsit pontosabban így fogalmaznám:

```cpp
// Összeomolhat, ha delete mNev-et hívunk,
// mert a részleges (sekély) másolás miatt
// sz1.mNev és sz2.mNev ugyanarra a memóriaterületre mutat.
// Az első delete felszabadítja a memóriát,
// a második delete ugyanazt a memóriát próbálja felszabadítani
// (double delete).
```

Vagy rövidebben:

```cpp
// Double delete veszély:
// sz1 és sz2 ugyanarra a dinamikusan foglalt stringre mutat.
```

Például:

```text
sz1.mNev ----+
             |
             v
        "LONG_NAME"
             ^
             |
sz2.mNev ----+
```

Az első destruktor:

```cpp
delete mNev;
```

felszabadítja a stringet.

A második destruktor már egy érvénytelen (dangling) pointeren próbál `delete`-et végrehajtani, ami nem definiált működés. Ez gyakran programösszeomlást okoz, de akár látszólag működhet is — ettől még hibás marad a program.

Ez pontosan a **sekély másolás (shallow copy)** problémája. A megoldás a **mély másolás (deep copy)**, amikor a másoló konstruktor új `std::string` objektumot foglal és annak tartalmát másolja át.

#### MEGOLDÁS:

```cpp
//Teljes Másolat

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Szemely
{
public:
    Szemely(const char *mN)
    {
        std::cout <<"Felépítés: " <<mN <<'\n';
        mNev= new std::string(mN);
    }
    //Másoló konstruktor referencia átadással
    Szemely(const Szemely &szemely)
    {
        std::cout <<"Másolunk: "<< *(szemely.mNev) <<'\n';
        mNev = new std::string(*szemely.mNev);
    }

    //desktruktora
    ~Szemely()
    {
        std::cout<<"Megsemmisítés: " << mNev
        << " (" << *mNev << ")" <<'\n';
        //itt már nem omlik össze
        // mrt másolunk más címre mutat
        //lefut a destruktor
        delete mNev;
        mNev= nullptr;
    }
protected:
    std::string *mNev;
};
void fv()
{
    //létrehozunk egy uj objektumot
    Szemely sz1("LONG_NAME");
    //átmásoljuk a tartalmát az sz2-be
    Szemely sz2(sz1);
}
int main(int argc, char** argv)
{
    std::cout<<"Az fv() meghívása" <<'\n';
    fv();
    std::cout<<"vége újra a main függvényben"<<'\n';
    //kilépünk
    std::cout <<"A Kilépéshez kérlek nyomd meg kétszer az entert" << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return 0;
}

```

**OUTPUT:**

```cpp
Az fv() meghívása
Felépítés: LONG_NAME
Másolunk: LONG_NAME
Megsemmisítés: 0x55bcdcbcf6f0 (LONG_NAME)
Megsemmisítés: 0x55bcdcbcf6c0 (LONG_NAME)
vége újra a main függvényben
A Kilépéshez kérlek nyomd meg kétszer az entert



Process returned 0 (0x0)   execution time : 5.182 s
Press ENTER to continue.

```

