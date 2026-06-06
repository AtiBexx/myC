#### LáncoltListaOsztály osztálymetódusokkal

-----------------

```cpp
//LáncoltListaOsztály osztálymetódusokkal
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

class NevAdathalmaz
{
    public:
    NevAdathalmaz(string &hivNev)
    :szNev(hivNev),mKovetkezo(nullptr) {}
    // önmaga hozzáadása a lista elejéhez
    void hozzaAdas()
    {
        this->mKovetkezo = mFej;
        mFej = this;
    }
    // lekérdező metódusok
    static NevAdathalmaz *elso() { return mFej; }
    NevAdathalmaz * kovetekezo() { return mKovetkezo; }
    const string &nev() { return szNev; }

    protected:
        string szNev;
        //A lista első és következő tagjának a hivatkozása
        static NevAdathalmaz *mFej;
        NevAdathalmaz *mKovetkezo;
};

//tárhelylefoglalása a fejmutatónak
NevAdathalmaz *NevAdathalmaz::mFej = nullptr;


NevAdathalmaz *adatokBeolvasasa()
{
    string nev;
    cout <<"Add meg a nevet:";
    cin >> nev;
    //
    if (nev == "stop")
    {
        return 0;
    }
    return new NevAdathalmaz(nev);
}

int main(int argc, char** argv)
{
    cout <<"A hallgatók nevének a beolvasása: " <<'\n';
    cout <<"A kilépéshez írd be hogy 'stop'...." <<'\n';

    //létrehozunk még egy NevAdathalmaz objektumot
    NevAdathalmaz* mNA;
    while(mNA = adatokBeolvasasa())
    {
        // hozzáadjuk a NevAdathalmaz objektumot a listához
        mNA->hozzaAdas();
    }

    // Az objektum megjelenitesehez vegogIteralunk
    // akkor állunk le a listával ha NULL
    cout << "\nBejegyzesek: " <<endl;
    for(NevAdathalmaz* mIter = NevAdathalmaz::elso();
    mIter;
    mIter = mIter->kovetekezo()
    )
    {
        //kiÍrjuk az aktuális bejegyzés nevét
        cout << mIter->nev() <<endl;
    }

    //kilépünk
    cout <<"A folytatáshoz kérlek nyomd meg kétszer az entert...."<< endl;

    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}

```

Ati, ebben a programban gyakorlatilag egy **egyszerű láncolt listát (linked list)** építettél fel kézzel, ahol minden objektum saját magát fűzi be a listába.

## 🧠 Mi a fő ötlet?

Az osztály:

```cpp
class NevAdathalmaz
```

egy listaelem.

Minden objektum tárol:

```cpp
string szNev;
```

egy nevet,

és:

```cpp
NevAdathalmaz *mKovetkezo;
```

egy mutatót a következő elemre.

------

## A lista feje

```cpp
static NevAdathalmaz *mFej;
```

Ez egy **statikus tag**.

Ezért:

```text
mFej
 ↓
első elem
```

csak egyetlen példány van belőle az egész programban.

------

## A hozzaAdas() metódus

Ez a legérdekesebb rész:

```cpp
void hozzaAdas()
{
    this->mKovetkezo = mFej;
    mFej = this;
}
```

Tegyük fel, hogy a lista üres:

```text
mFej -> nullptr
```

------

### Első név: Ati

Létrejön:

```text
[Ati]
```

Majd:

```cpp
this->mKovetkezo = mFej;
```

azaz:

```text
Ati -> nullptr
```

utána:

```cpp
mFej = this;
mFej
 ↓
[Ati]
```

------

### Második név: Nova

```text
[Nova]
```

hozzaAdas():

```cpp
Nova->mKovetkezo = mFej;
```

jelenleg:

```text
mFej -> Ati
```

tehát:

```text
Nova -> Ati
```

majd:

```cpp
mFej = Nova;
```

eredmény:

```text
mFej
 ↓
[Nova] -> [Ati] -> nullptr
```

------

### Harmadik név: Béla

Ugyanez:

```text
mFej
 ↓
[Béla] -> [Nova] -> [Ati] -> nullptr
```

------

## Mi történik a while ciklusban?

```cpp
while(mNA = adatokBeolvasasa())
```

Ez nem összehasonlítás.

Ez értékadás.

------

Például:

```cpp
mNA = adatokBeolvasasa();
```

ha nem null:

```text
0x123456
```

akkor igaz.

Ha:

```cpp
return 0;
```

akkor hamis.

------

Ezért működik:

```cpp
while(mNA = adatokBeolvasasa())
```

------

## Az iterálás

```cpp
for(
    NevAdathalmaz* mIter = NevAdathalmaz::elso();
    mIter;
    mIter = mIter->kovetekezo()
)
```

Először:

```text
mIter = mFej
```

------

Például:

```text
[Béla] -> [Nova] -> [Ati]
```

Kiírja:

```text
Béla
Nova
Ati
```

------

## Miért statikus az elso()?

```cpp
static NevAdathalmaz *elso()
{
    return mFej;
}
```

Mert:

```cpp
mFej
```

szintén statikus.

Nincs szükség objektumra:

```cpp
NevAdathalmaz::elso();
```

------

## Amit még nem csinál a program

Van egy memória-szivárgás:

```cpp
new NevAdathalmaz(...)
```

de sehol sincs:

```cpp
delete
```

Tehát a program végén az operációs rendszer takarít el mindent.

Egy tanulóprogramnál ez nem tragédia, de egy valódi programban végig kellene menni a listán és felszabadítani az elemeket.

------

## Röviden

Ebben a programban:

- létrehoztál egy saját láncolt listát,
- minden `NevAdathalmaz` objektum egy listaelem,
- a `static mFej` tárolja az első elemet,
- a `mKovetkezo` mutat a következő elemre,
- a `hozzaAdas()` a lista elejére szúr be,
- a `for` ciklus végigjárja és kiírja a neveket.

Ez már egy klasszikus OOP + pointeres adatstruktúra példa, amit régen nagyon sok C++ könyvben használtak a láncolt listák bemutatására.