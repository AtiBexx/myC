### Absztrakt osztály

--------

**Az Absztrakt osztály  egy olyan osztály amely egy vagy több tisztán virtuális függvényt tartalmaz.**

> A tisztán virtuális függvény olyan függvény amelynél jelölve van hogy, nincs megvalósítva.
>
> jele = 0;
>
> Egy hagyományos egyszerű nem tisztán virtuális függvényt **,,konkrét függvénynek" **nevezünk.

A tisztán virtuális függvény Snippet:

```cpp
//Számla - ez egy absztrakt osztály

class Szamla
{
    public:
    Szamla(unsigned szlaSzam, double kezdoEgyenleg =0.0);
    //lekérdező függvények
    unsigned int szlaSzam( );
    static int szamlakSzama( );
    //tranzakciós függvények
    void befizetes(double osszeg);
    //a következő egy tisztán virtuális függvény
    virtual void penzfelvetel(double osszeg) = 0;
    protected:
    //A számlákat egy láncolt listában tároljuk így nincs korlátja
    // a számlák számának.
    static int szam; // a számlák száma
    Unsigned szamlaSzam;
    Double egyenleg;
};
```

-------------

```cpp
// ADJUNK ÁT ABSZTRAKT OSZTÁLYOKAT
void fv(Szamla *mSzamla);
void masikFv()
{
	MegtakaritasiSzamla m;
	FolyoSzamla f;
	fv(&m);
	fv(&f)
}
```

Rövideben és jobban:

Persze Ati. Az absztrakt osztály elsőre bonyolultnak tűnik, de valójában egy nagyon egyszerű ötlet.

------

#### Mi az absztrakt osztály?

Egy absztrakt osztály olyan osztály:

- **amiből nem lehet objektumot létrehozni**
- **csak örökölni lehet belőle**
- **legalább egy tisztán virtuális (`= 0`) függvényt tartalmaz**

------

#### Egyszerű példa

Képzeld el, hogy vannak állatok.

Minden állat tud hangot adni, de nem tudod előre milyen hangot.

Ezért az ősosztályban csak előírod:

```cpp
class Allat
{
public:
    virtual void hangotAd() = 0;
};
```

A `= 0` azt jelenti:

> "Minden leszármazott köteles megvalósítani ezt a függvényt."

------

#### Nem lehet példányosítani

Ez hibás:

```cpp
Allat a;
```

Fordítási hiba.

Miért?

Mert az `Allat` osztály nem tudja milyen hangot kell kiadnia.

------

#### A leszármazottak megvalósítják

```cpp
#include <iostream>

class Allat
{
public:
    virtual void hangotAd() = 0;
};

class Kutya : public Allat
{
public:
    void hangotAd() override
    {
        std::cout << "Vau vau\n";
    }
};

class Macska : public Allat
{
public:
    void hangotAd() override
    {
        std::cout << "Miau\n";
    }
};
```

------

#### Most már lehet objektum

```cpp
Kutya k;
Macska m;
```

Mert a tisztán virtuális függvény meg lett valósítva.

------

#### Miért hasznos?

Írhatunk egy általános függvényt:

```cpp
void megszolaltat(Allat* a)
{
    a->hangotAd();
}
```

------

#### Használat

```cpp
int main()
{
    Kutya k;
    Macska m;

    megszolaltat(&k);
    megszolaltat(&m);

    return 0;
}
```

Kimenet:

```text
Vau vau
Miau
```

------

#### Mi történik itt?

A függvény:

```cpp
void megszolaltat(Allat* a)
```

nem tudja, hogy kutyát vagy macskát kap.

Csak annyit tud:

> "ez valamilyen Allat"

A `virtual` miatt futáskor derül ki:

- Kutya → Vau vau
- Macska → Miau

------

#### A Szamla példa ugyanez

Az ősosztály:

```cpp
class Szamla
{
public:
    virtual void penzfelvetel(double osszeg) = 0;
};
```

Azt mondja:

> Minden számláról lehet pénzt felvenni, de a módját nem tudom.

------

Például:

```cpp
class FolyoSzamla : public Szamla
{
public:
    void penzfelvetel(double osszeg) override
    {
        std::cout << "FolyoSzamla penzfelvetel\n";
    }
};

class MegtakaritasiSzamla : public Szamla
{
public:
    void penzfelvetel(double osszeg) override
    {
        std::cout << "MegtakaritasiSzamla penzfelvetel\n";
    }
};
```

------

#### Miért adunk át `Szamla*`-t?

```cpp
void fv(Szamla* sz)
{
    sz->penzfelvetel(1000);
}
```

Mert így ugyanaz a függvény működik:

```cpp
FolyoSzamla f;
MegtakaritasiSzamla m;

fv(&f);
fv(&m);
```

------

#### Rövid összefoglaló

- `virtual void f() = 0;` → tisztán virtuális függvény
- Ha van legalább egy ilyen függvény → az osztály absztrakt
- Absztrakt osztályból nem lehet objektumot létrehozni
- A leszármazott köteles megvalósítani a függvényt
- Az absztrakt osztály célja egy közös interfész biztosítása
- Az objektumokat általában pointerrel vagy referenciával kezeljük:

```cpp
Allat* a;
Szamla* sz;
```

Az absztrakt osztályt sokan úgy fogalmazzák meg egyszerűen:

> "Sablon vagy szerződés a leszármazottak számára: megmondja, mit kell tudniuk, de nem mondja meg, hogyan valósítsák meg."

--------------------

Az absztrakt osztályt sok könyv rögtön olyan példákkal kezdi el magyarázni, mint:

- bankszámla
- alkalmazott
- geometriai alakzat
- több szintű öröklődés

és közben tele van új fogalmakkal:

- virtual
- pure virtual
- abstract class
- polymorphism
- override
- pointer
- referencia

Így nehéz meglátni az alapötletet.

Pedig az absztrakt osztály lényege tényleg csak ennyi:

```cpp
class Allat
{
public:
    virtual void hangotAd() = 0;
};
```

Az `Allat` azt mondja:

> "Minden állatnak tudnia kell hangot adni, de én nem tudom, milyen hangot ad."

A `Kutya` és a `Macska` pedig kitöltik a hiányzó részt.

Ezért szokták az absztrakt osztályt úgy is nevezni, hogy **interfész-szerű alaposztály** vagy **szerződés**:

> Ha ebből örökölsz, ezt a függvényt kötelező megírnod.

- korai kötés
- késői kötés
- virtual
- override
- final
- absztrakt osztály
- tisztán virtuális függvény
- virtual destruktor

És ezek együtt adják a C++ klasszikus OOP alapjainak nagy részét.

A következő logikus lépés általában az, hogy megérted a különbséget a:

```cpp
Hallgato h;
Hallgato* h;
Hallgato& h;
```

között, mert a polimorfizmus a gyakorlatban szinte mindig pointerrel vagy referenciával jelenik meg. Ez az a pont, ahol sok korábbi `virtual`-lal kapcsolatos kérdés hirtelen teljesen értelmet nyer.