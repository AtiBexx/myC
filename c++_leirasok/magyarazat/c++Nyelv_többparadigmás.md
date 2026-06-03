# Programozási paradigmák röviden

## Mi az a paradigma?

A paradigma egy programozási szemlélet vagy módszer, amely megmondja, hogyan érdemes felépíteni a programot.

Egy nyelv támogathat egy vagy több paradigmát.

------

# Procedurális programozás

A procedurális programozás a programot eljárásokra (függvényekre) bontja.

A hangsúly azon van, hogy milyen lépések hajtódnak végre egymás után.

Példa:

```cpp
#include <iostream>

void koszones()
{
    std::cout << "Hello";
}

int main()
{
    koszones();
}
```

Jellemzők:

- függvényközpontú
- egyszerű felépítés
- a C nyelv fő paradigmája
- kisebb programoknál nagyon hatékony

------

# Objektumorientált programozás (OOP)

Az OOP a programot objektumokból építi fel.

Az objektum adatokat és műveleteket tartalmaz egy egységben.

Példa:

```cpp
class Hallgato
{
private:
    std::string nev;

public:
    void kiir()
    {
        std::cout << nev;
    }
};
```

Alapfogalmak:

- osztály (class)
- objektum
- konstruktor
- destruktor
- öröklődés
- polimorfizmus
- adatrejtés (encapsulation)

Előnye:

- nagy programok könnyebben kezelhetők
- a kód jobban újrahasznosítható

------

# Generikus programozás

A generikus programozás célja, hogy ugyanaz a kód több adattípussal is működjön.

A C++ ezt főleg template-ekkel valósítja meg.

Példa:

```cpp
template<typename T>
T maximum(T a, T b)
{
    return a > b ? a : b;
}
```

Használat:

```cpp
maximum(5, 7);
maximum(3.2, 8.1);
```

Ugyanaz a függvény működik int, double és más típusokkal is.

A C++ Standard Library nagy része generikus programozásra épül.

Példák:

```cpp
std::vector
std::sort
std::map
std::find
```

------

# Funkcionális programozás

A funkcionális programozás a matematikai függvények szemléletéből indul ki.

A hangsúly az adatok átalakításán van, nem az állapot módosításán.

C++-ban ezt főleg lambda függvényekkel használjuk.

Példa:

```cpp
auto osszeg = [](int a, int b)
{
    return a + b;
};

std::cout << osszeg(3, 4);
```

További példák:

```cpp
std::for_each(...)
std::transform(...)
std::ranges
```

Jellemzők:

- kevés vagy nincs globális állapot
- sok kis függvény
- adatok átalakítása függvényekkel

A C++ nem tisztán funkcionális nyelv, de támogat funkcionális elemeket.

------

# Többparadigmás nyelv

A többparadigmás nyelv egyszerre több programozási stílust támogat.

A C++ ilyen nyelv.

Egyetlen programban lehet:

Procedurális:

```cpp
void kiir()
{
}
```

Objektumorientált:

```cpp
class Hallgato
{
};
```

Generikus:

```cpp
template<typename T>
```

Funkcionális:

```cpp
auto lambda = [](){};
```

Mindegyik használható ugyanabban a projektben.

------

# A C++ fő paradigmái

1. Procedurális programozás
   - függvények és algoritmusok
2. Objektumorientált programozás
   - osztályok és objektumok
3. Generikus programozás
   - template-ek
4. Funkcionális programozás
   - lambda függvények, algoritmusok, ranges

Ezért mondjuk azt, hogy a C++ többparadigmás programozási nyelv.

Ez teljesen normális, mert a funkcionális programozás elsőre sokkal elvontabbnak tűnik, mint a procedurális vagy az OOP.

Kezdjük azzal, hogy mit csinálsz procedurálisan:

```cpp
int szamok[] = {1, 2, 3, 4, 5};

for(int i = 0; i < 5; i++)
{
    szamok[i] *= 2;
}
```

Itt lépésről lépésre megmondod:

- menj végig a tömbön
- vedd ki az elemet
- szorozd meg kettővel
- írd vissza

Ez procedurális gondolkodás: **hogyan** történjen a művelet.

------

A funkcionális szemlélet inkább azt mondja:

> Van egy művelet, ami egy számot megdupláz. Alkalmazd ezt minden elemre.

Például:

```cpp
auto duplaz = [](int x)
{
    return x * 2;
};
```

A `[](){}` szerkezetet lambda függvénynek hívják.

Ez gyakorlatilag egy névtelen függvény:

```cpp
int duplaz(int x)
{
    return x * 2;
}
```

csak rövidebben írva.

------

A modern C++ gyakran így használja:

```cpp
std::vector<int> v = {1,2,3,4,5};

std::transform(
    v.begin(),
    v.end(),
    v.begin(),
    [](int x)
    {
        return x * 2;
    }
);
```

Itt nem te írod a ciklust.

Csak megmondod:

> minden elemre alkalmazd ezt a függvényt

A ciklust a `std::transform` intézi.

------

Még egy egyszerű példa.

Procedurális:

```cpp
int a = 5;
int b = 7;

int c = a + b;
```

Funkcionális szemlélet:

```cpp
auto osszead = [](int a, int b)
{
    return a + b;
};

int c = osszead(5, 7);
```

A műveletet függvényként kezeled.

------

A funkcionális programozás egyik fontos gondolata:

A függvény legyen olyan, mint a matematikában.

Például:

```cpp
int negyzet(int x)
{
    return x * x;
}
```

Ha:

```cpp
negyzet(5)
```

akkor mindig 25 lesz.

Nem módosít globális változókat, nem ír fájlba, nem változtatja meg a program állapotát.

Csak:

```text
bemenet -> feldolgozás -> kimenet
```

------

Ha C++-os szemmel nézzük, a funkcionális elemek, amelyekkel a legtöbbször találkozol:

```cpp
lambda függvények

[](int x)
{
    return x * 2;
}
std::for_each
std::transform
std::find_if
std::ranges
```

------

A gyakorlatban a legtöbb C++ fejlesztő főleg:

- procedurális kódot ír,
- OOP-t használ,
- template-eket használ (generikus programozás),

és emellett időnként funkcionális elemeket (lambda, algoritmusok).

Tehát nem kell úgy elképzelni, hogy a funkcionális programozás egy teljesen külön világ a C++-ban. Sokszor csak annyit jelent, hogy ciklusok helyett algoritmusokat és lambda függvényeket használsz. Ezért találkozol olyan kóddal, mint:

```cpp
std::sort(v.begin(), v.end(),
    [](int a, int b)
    {
        return a < b;
    });
```

ami már egy kis funkcionális szemléletet használ, miközben a program többi része lehet teljesen OOP vagy procedurális.