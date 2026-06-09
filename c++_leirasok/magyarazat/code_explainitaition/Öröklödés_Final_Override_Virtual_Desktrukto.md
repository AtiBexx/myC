### Öröklödés_Final_Override_Virtual_Desktruktor

-------

```cpp
class Hallgato
{
    public:
    virtual void kurzusHozzaAdasa(double osztalyzat);
};
class VegzosHallgato : public Hallgato
{
    public:
    virtual void kurzusosztalyzatHozzaAdasa(float osztalyzat)
        ovverride;
}
```

Oké, nézzük teljesen tisztán.

------

####  Mit csinál az `override`?

Az `override` C++-ban azt jelenti:

> „Ez a függvény egy ősosztályból származó virtual függvényt akar felülírni.”

------

####  A te példád:

```cpp
class Hallgato
{
public:
    virtual void kurzusHozzaAdasa(double osztalyzat);
};
```

Ez azt mondja:
 van egy függvény, amit a gyerekosztályok felülírhatnak

------

####  Gyerekosztály:

```cpp
class VegzosHallgato : public Hallgato
{
public:
    virtual void kurzusosztalyzatHozzaAdasa(float osztalyzat)
        override;
};
```

------

####  Itt a lényeg: NÁLAD HIBA VAN

#### 1. A függvénynév nem egyezik

Ős:

```cpp
kurzusHozzaAdasa
```

Gyerek:

```cpp
kurzusosztalyzatHozzaAdasa 
```

 EZ NEM override, ez egy teljesen új függvény

------

#### 2. A paraméter sem egyezik

Ős:

```cpp
double
```

Gyerek:

```cpp
float
```

 ez sem egyezik → nem override

------

####  Akkor mit csinál az `override` itt?

 A fordító ezt ellenőrzi:

- „tényleg felülírsz egy létező virtual függvényt?”

------

## Ha NEM egyezik:

 fordítási hiba lesz

------

####  Példa a TE hibádra

Ez:

```cpp
virtual void kurzusosztalyzatHozzaAdasa(float) override;
```

 a fordító ezt mondja:

> nincs ilyen függvény az ősben → HIBA

------

####  Ha JÓL csinálod:

```cpp
class VegzosHallgato : public Hallgato
{
public:
    void kurzusHozzaAdasa(double osztalyzat) override;
};
```

------

####  Mit nyersz az `override`-dal?

#### 1. Hibavédelem

Ha elgépeled:

```cpp
kurzusHozzaAdsa
```

 fordító azonnal szól

------

#### 2. Biztonság

Nem lesz „véletlen új függvény”

------

####  Egyszerű gondolat

- virtual = „lehet felülírni”
- override = „tényleg felülírom”
- ha nem stimmel → hiba

------

####  Egy mondat:

> az override biztosítja, hogy valóban az ős virtual függvényét írod felül, nem egy új függvényt hozol létre

------

####  Mi történik, ha elrontod `override`-dal?

####  Példa (hibás név vagy paraméter):

```
class VegzosHallgato : public Hallgato
{
public:
    void kurzusosztalyzatHozzaAdasa(float osztalyzat) override;
};
```

------

####  Mit csinál a fordító?

 AZONNAL hibát ad fordításkor:

> error: ‘kurzusosztalyzatHozzaAdasa’ marked ‘override’, but does not override

------

####  Miért?

Mert a szabály:

> `override` = “ennek pontosan egy létező virtual függvényt kell felülírnia”

Ha nem egyezik:

- név 
- paraméter 
- const 
- return típus  (ritkán)

 akkor NEM override

------

####  Mi történik `override` NÉLKÜL?

Ha ezt írod:

```
void kurzusosztalyzatHozzaAdasa(float osztalyzat);
```

 akkor:

 **lefordul**
  **de NEM override lesz**
 **hanem egy teljesen új függvény**

------

####  Ez a veszély (nagyon fontos)

```
Hallgato* h = new VegzosHallgato();
h->kurzusHozzaAdasa(90.0);
```

 ha elrontottad a nevet:

- az ős függvénye fut
- nem a gyereké

 ez nagyon alattomos bug

------

####  override szerepe egyszerűen:

> “fordító, ellenőrizd hogy tényleg override-olok-e valamit”

************************************************

//***********************************************************************************************//

#### final

---------

```cpp
class VegzosHallgato : public Hallgato
{
    public:
    virtual void kurzusOsztalyzatHozzaAdasa(double osztalyzat) final;  
};
class PHDHallgato : public VegzosHallgato
{
    public:
    virtual voidkurzusOsztalyzatHozzaAdasa(double osztalyzat);
}
```

A `final` C++-ban azt jelenti: **“innen tovább nem lehet felülírni / örökölni”**.

------

####  1. `final` függvénynél

```cpp
class Hallgato {
public:
    virtual void kurzusHozzaAdasa(double osztalyzat) final;
};
```

####  Mit jelent?

 Ez a függvény:

- felülírható az első gyerekosztályban (ha nem final az osztály)
- de **többé már SENKI nem override-olhatja tovább**

------

####  Példa:

```cpp
class A {
public:
    virtual void f() {}
};

class B : public A {
public:
    void f() final {}   // OK
};

class C : public B {
public:
    void f() {} //  HIBA: nem override-olhatod, mert final
};
```

------

####  2. `final` osztálynál

```cpp
class VegzosHallgato final : public Hallgato {
};
```

##  Mit jelent?

 ebből az osztályból:

- nem lehet örökölni

```cpp
class PHD : public VegzosHallgato {}; // ❌ HIBA
```

------

####  Mikor használjuk?

####  függvénynél:

- ha nem akarod, hogy tovább módosítsák a viselkedést

 pl. biztonsági / core logika

------

####  osztálynál:

- ha “lezárod” a típust

 pl:

- string
- utility class
- security class

------

####  Egyszerű különbség

| kulcsszó         | mit csinál                      |
| ---------------- | ------------------------------- |
| override         | felülírom                       |
| final (függvény) | itt a vége, nincs több override |
| final (class)    | nem lehet örökölni              |

------

####  Egy mondat:

> a `final` lezárja az öröklési láncot vagy a felülírást

------

//

A **virtual destruktor** akkor kell, amikor az osztályodat **polimorf módon (base pointerrel) használod**, és van esély arra, hogy a gyerekosztályban **dinamikus erőforrások** vannak.

------

####  Alapszabály

> Ha egy osztályban van **bármilyen virtual függvény**, akkor a destruktor legyen **virtual**.

------

####  Mi történik, ha NINCS virtual destruktor?

```cpp
class Hallgato {
public:
    ~Hallgato() {
        std::cout << "Hallgato destruktor\n";
    }
};

class VegzosHallgato : public Hallgato {
public:
    ~VegzosHallgato() {
        std::cout << "Vegzos destruktor\n";
    }
};
Hallgato* h = new VegzosHallgato();
delete h;
```

 Eredmény:

- csak `Hallgato` destruktor fut
- `VegzosHallgato` NEM
- memory leak / erőforrás leak

------

#  Megoldás: virtual destruktor

```cpp
class Hallgato {
public:
    virtual ~Hallgato() {
        std::cout << "Hallgato destruktor\n";
    }
};
```

------

##  Most mi történik?

```cpp
Hallgato* h = new VegzosHallgato();
delete h;
```

 helyes sorrend:

1. `VegzosHallgato` destruktor
2. `Hallgato` destruktor

------

#  Miért?

Mert virtual destruktor esetén:

> a delete is késői kötést használ (vtable)

------

#  Mikor KELL virtual destruktor?

##  mindig ha:

- van virtual függvény az osztályban
- polimorf módon használod (`Base* ptr = new Derived`)

------

##  nem kell ha:

- soha nem örökítesz belőle
- nem használsz pointeren keresztüli törlést
- “final / utility class”

------

#  Tipikus szabály (nagyon fontos):

> Ha az osztályod polymorphic (virtual van benne), akkor destruktor = virtual

------

# Egyszerű gondolat:

- virtual függvény → runtime viselkedés
- delete is runtime kell legyen
- ezért kell virtual destruktor

------

#  Egy mondat:

> a virtual destruktor biztosítja, hogy base pointeren keresztül törölve is a teljes objektum helyesen megsemmisüljön

------

Ha akarod, megmutatom:
 hogyan néz ki ez vtable szinten (ez az egyik legjobb “aha” C++ pillanat)

Nagyon jó észrevétel, itt van a lényeg, ahol sokan félreértik.

------

####  A te példádban tényleg nincs `virtual`

```cpp
class Hallgato {
public:
    ~Hallgato() {
        std::cout << "Hallgato destruktor\n";
    }
};
```

 Itt a destruktor **nem virtual**

------

####  Mi történik ekkor?

```cpp
Hallgato* h = new VegzosHallgato();
delete h;
```

 EZ PROBLÉMA

------

####  Miért?

Mert:

- a pointer típusa: `Hallgato*`
- nincs virtual destruktor
- ezért a fordító ezt csinálja:

> “statikus típus alapján törlök”

------

####  Eredmény:

Csak ez fut:

```
Hallgato destruktor
```

 `VegzosHallgato` destruktor NEM fut

------

####  A kulcs: nem kell virtual függvény ahhoz, hogy baj legyen

 A probléma NEM az, hogy van-e virtual függvény
 A probléma az, hogy:

> base pointeren keresztül törölsz

------

####  Fontos igazság:

####  Tévhít:

> “csak akkor kell virtual destruktor, ha van virtual függvény”

####  VALÓS szabály:

> ha törlöd base pointeren keresztül → destruktor legyen virtual

------

####  Javított verzió:

```cpp
class Hallgato {
public:
    virtual ~Hallgato() {
        std::cout << "Hallgato destruktor\n";
    }
};

class VegzosHallgato : public Hallgato {
public:
    ~VegzosHallgato() {
        std::cout << "Vegzos destruktor\n";
    }
};
```

------

####  Most mi történik?

```cpp
Hallgato* h = new VegzosHallgato();
delete h;
```

 helyes sorrend:

```
Vegzos destruktor
Hallgato destruktor
```

------

#### Miért működik így?

Mert a `virtual ~Hallgato()`:

 bekerül a vtable-be
 delete már runtime dönt
 “valódi típus” alapján töröl

------

####  Egy mondat:

> nem a virtual függvények száma számít, hanem az, hogy base pointeren keresztül törölsz-e

------

 **ha van bármilyen `virtual` függvényed, akkor szinte mindig kell `virtual destruktor` is**.

Most adok egy **teljes, korrekt, futtatható C++ példát**, hogy lásd együtt az egészet.

------

####  FULL példa (virtual függvény + virtual destruktor)

```cpp
#include <iostream>

class Hallgato {
public:
    // virtual függvény -> polimorfizmus
    virtual void kurzusHozzaAdasa(double osztalyzat) {
        std::cout << "Hallgato kurzusHozzaAdasa\n";
    }

    // virtual destruktor -> kötelező ilyen esetben
    virtual ~Hallgato() {
        std::cout << "Hallgato destruktor\n";
    }
};

class VegzosHallgato : public Hallgato {
public:
    void kurzusHozzaAdasa(double osztalyzat) override {
        std::cout << "VegzosHallgato kurzusHozzaAdasa\n";
    }

    ~VegzosHallgato() {
        std::cout << "VegzosHallgato destruktor\n";
    }
};

void fv(Hallgato* h)
{
    h->kurzusHozzaAdasa(5.0);
}

int main()
{
    Hallgato* h1 = new Hallgato();
    Hallgato* h2 = new VegzosHallgato();

    fv(h1);
    fv(h2);

    delete h1;
    delete h2;

    return 0;
}
```

------

####  Mit kell látni ebből?

####  1. virtual függvény

```cpp
virtual void kurzusHozzaAdasa(double);
```

 ez adja a polimorfizmust

------

####  2. override

```cpp
void kurzusHozzaAdasa(double) override;
```

 biztosítja, hogy tényleg felülírod

------

####  3. virtual destruktor

```cpp
virtual ~Hallgato();
```

 ez biztosítja, hogy:

```cpp
delete h2;
```

Vegzos destruktor is lefusson
 ne legyen memória/erőforrás leak

------

####  Mi történik futáskor?

#### `fv(h2)`:

 VegzosHallgato verzió fut

## `delete h2`:

 helyes sorrend:

```
VegzosHallgato destruktor
Hallgato destruktor
```

------

####  Fontos szabály (nagyon lényeges)

> Ha egy osztályban van legalább 1 virtual függvény → destruktor legyen virtual

------

####  Egyszerű gondolat

- virtual függvény → runtime viselkedés
- destructor is runtime kell legyen
- ezért kell virtual destructor

------

####  Egy mondat:

> a virtual függvények miatt az objektum már polimorf, ezért a destrukciónak is polimorfnak kell lennie

------

Rendben, nézzük a **lehető legegyszerűbb példát**, semmi extra.

------

####  1. NINCS `virtual`

```cpp
#include <iostream>

class A {
public:
    void f() {
        std::cout << "A f()" << std::endl;
    }
};

class B : public A {
public:
    void f() {
        std::cout << "B f()" << std::endl;
    }
};

int main() {
    A* obj = new B();
    obj->f();

    delete obj;
}
```

####  Eredmény:

```
A f()
```

 Miért?

- a pointer típusa `A*`
- nincs virtual → **fordításkor eldől**

------

####  2. VAN `virtual`

```cpp
#include <iostream>

class A {
public:
    virtual void f() {
        std::cout << "A f()" << std::endl;
    }
};

class B : public A {
public:
    void f() override {
        std::cout << "B f()" << std::endl;
    }
};

int main() {
    A* obj = new B();
    obj->f();

    delete obj;
}
```

####  Eredmény:

```
B f()
```

------

####  Mi a különbség?

#### virtual nélkül:

- mindig az **A verzió fut**
- mert A* a típus

####  virtual-lal:

- a **valódi objektum számít**
- B verzió fut

------

####  1 mondatos különbség

- **nincs virtual:** “mit mond a pointer típusa?”
- **van virtual:** “mi az igazi objektum?”

------

####  Nagyon egyszerű analógia

####  virtual nélkül:

> “mindegy kit hívsz, mindig A válaszol”

####  virtual-lal:

> “akit tényleg hívsz (B), az válaszol”

------

A `virtual`-t **csak az ősosztályban kell megadni**, nem kell mindenhol újraírni.

------

####  Alapelv

> Ha az A osztályban egy függvény `virtual`, akkor **minden leszármazottban automatikusan virtual marad**, még ha nem is írod ki.

------

####  Példa láncolt öröklésre

```cpp
class A {
public:
    virtual void f() {
        std::cout << "A\n";
    }
};

class B : public A {
public:
    void f() override {
        std::cout << "B\n";
    }
};

class C : public B {
public:
    void f() override {
        std::cout << "C\n";
    }
};
```

------

####  Mit kell látni?

####  A-ban:

```cpp
virtual void f()
```

 innentől kezdve:

- B-ben NEM kell újra `virtual`
- C-ben NEM kell újra `virtual`

------

####  Működés:

```cpp
A* obj = new C();
obj->f();
```

 eredmény:

```
C
```

------

####  Fontos szabály

####  nem kell ezt írni:

```cpp
class B {
public:
    virtual void f(); // felesleges
};
```

####  elég:

```cpp
class B {
public:
    void f() override;
};
```

------

####  Mit jelent ez valójában?

- `virtual` = “ez a függvény polimorf”
- ez **öröklődik automatikusan**
- csak egyszer kell deklarálni (ősben)

------

####  Extra fontos szabály

 ha az ősben `virtual`, akkor:

| osztály | kell virtual?              |
| ------- | -------------------------- |
| A       | IGEN                       |
| B       | NEM (de lehet, nem muszáj) |
| C       | NEM                        |

------

####  Egy mondat:

> a virtual csak az ősosztályban kell, onnantól minden leszármazott automatikusan polimorf lesz

------

