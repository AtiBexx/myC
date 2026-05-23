KonzulensPfV()
    ↓

KonzulensPar konzulensPar
    ↓
    (KonzulensPar konstruktor indul)

KonzulensPar tagobjektumokat épít:
    ↓

Hallgato hallgato
    ↓
Hallgato()

Oktato oktato
    ↓
Oktato()

Oktato konstruktorban:
    ↓

mK = new Kurzus
    ↓
Kurzus()

Végül:
    ↓

KonzulensPar()



```
// Tagmegsemmisítése - ez a program fellépít majd meg is semmisit néhány adatlapot
// amihez ~Destruktort használunk
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Kurzus
{
public:
    Kurzus() { std::cout << "A kurzus fellépítése"<< "\n"; }
    // A destruktor jele ~
    // Mos töröljük/megsemmisítjük
    ~Kurzus() { std::cout <<"A Kurzus megsemmisítése"<< "\n"; }
};

class Hallgato
{
public:
    Hallgato() {std::cout <<"A Hallgató fellépítése" << "\n"; }
    ~Hallgato() {std::cout <<"A Hallgató megsemmísétése" << "\n";}
};

class Oktato
{
public:
    Oktato()
    {
    std::cout << "Az Oktató fellépítése" << "\n\n";
    //uj Kurzus létrehozása
    mK = new Kurzus;
    }
~Oktato()
{
    std::cout << "Az Oktató megsemmítése" << "\n\n";
    delete mK;
}
protected:
    Kurzus* mK;
};

class KonzulensPar
{
public:
    KonzulensPar() { std::cout << "A KonzulensPár fellépítése\n";}
    ~KonzulensPar() { std::cout << "A KonzulensPár megsemmisítése\n";}
protected:
    //Itt hívjuk meg a Hallgató és az Oktató objektumot
    Hallgato hallgato; //másodjára  ez megy végbe
    Oktato oktato; //harmadjára ez
};

KonzulensPar* KonzulensPfV() // Az eredeti fv()
{
    std::cout << "A KonzulensPar Objektum létrehozása a KonzulensPfV() függvényben " <<"\n\n"; // ->elsőnek ez megy végbe
    KonzulensPar konzulensPar; //az eredeti kp

    std::cout <<"A KonzulensPar lefoglalása a halomMermóriából" <<"\n";

    KonzulensPar* tagKonzulensPar = new KonzulensPar; //az eredeti tagKonzulensPar helyett mKP
    //mKP = memeber Konzulens Pár
    std::cout <<"Visszatérés a KonzulensPfV -ből\n";
    return tagKonzulensPar;
}

int main(int argc, char** argv)
{
    //
    //
    KonzulensPar* tagKonzulensParVisszaHelyezett = KonzulensPfV();
    std::cout << "VisszaTesszük a halom memóriából a KonzulensPfV() " << std::endl;

    delete tagKonzulensParVisszaHelyezett;

    //kilépünk
    std::cout <<"\nA foltatáshoz kérlek nyomd meg az ENTER billentyüt..." << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();
    return 0;
}
```
A stack és heap is a RAM-ban van, nem a processzorban.
A CPU csak használja őket.


```text
CPU
 ↓
RAM
 ├── STACK
 └── HEAP
```

A stack általában gyorsabb mert:

* lineáris memória
* automatikus kezelés
* nincs memória keresgélés
* csak a stack pointer mozog

A heap lassabb mert:

* dinamikus memóriafoglalás
* keresni kell szabad blokkot
* fragmentáció lehet
* `new/delete` kezelő fut

---

# A PROGRAM ÁTÍRVA RÉSZLETES KOMMENTEKKEL

```cpp
// =====================================================
// STACK vs HEAP bemutatása destruktorokkal
// =====================================================

#include <iostream>
#include <limits>

// =====================================================
// KURZUS OSZTÁLY
// =====================================================
class Kurzus
{
public:

    // Konstruktor
    // Akkor fut le amikor létrejön egy Kurzus objektum
    Kurzus()
    {
        std::cout << "[KONSTRUKTOR] Kurzus letrejott\n";
    }

    // Destruktor
    // Akkor fut le amikor a Kurzus objektum megsemmisul
    ~Kurzus()
    {
        std::cout << "[DESTRUKTOR] Kurzus torolve\n";
    }
};

// =====================================================
// HALLGATO OSZTÁLY
// =====================================================
class Hallgato
{
public:

    // Stack tagobjektum konstruktor
    Hallgato()
    {
        std::cout << "[KONSTRUKTOR] Hallgato letrejott\n";
    }

    // Automatikus destruktor
    ~Hallgato()
    {
        std::cout << "[DESTRUKTOR] Hallgato torolve\n";
    }
};

// =====================================================
// OKTATO OSZTÁLY
// =====================================================
class Oktato
{
public:

    // Konstruktor
    Oktato()
    {
        std::cout << "[KONSTRUKTOR] Oktato letrejott\n";

        // ============================================
        // HEAP memória foglalás
        // ============================================
        //
        // A new:
        //
        // 1. memóriát foglal a HEAP-en
        // 2. meghívja a konstruktor
        //
        // mK egy POINTER
        //
        // STACK:
        //   mK pointer
        //
        // HEAP:
        //   Kurzus objektum
        //
        // mK -----> [Kurzus objektum]
        //
        // ============================================

        mK = new Kurzus;
    }

    // Destruktor
    ~Oktato()
    {
        std::cout << "[DESTRUKTOR] Oktato torolve\n";

        // ============================================
        // FONTOS
        // ============================================
        //
        // A delete:
        //
        // 1. meghívja a Kurzus destruktort
        // 2. felszabadítja a heap memóriát
        //
        // Ha ez nincs:
        //
        // MEMORY LEAK
        //
        // ============================================

        delete mK;
    }

protected:

    // POINTER a heap objektumra
    Kurzus* mK;
};

// =====================================================
// KONZULENSPAR OSZTÁLY
// =====================================================
class KonzulensPar
{
public:

    // Konstruktor
    KonzulensPar()
    {
        std::cout << "[KONSTRUKTOR] KonzulensPar letrejott\n";
    }

    // Destruktor
    ~KonzulensPar()
    {
        std::cout << "[DESTRUKTOR] KonzulensPar torolve\n";
    }

protected:

    // ============================================
    // STACK TAGOBJEKTUMOK
    // ============================================
    //
    // Ezek NEM pointerek.
    //
    // Ezek közvetlen objektumok.
    //
    // A KonzulensPar részei.
    //
    // Konstrukció sorrend:
    //
    // 1. Hallgato
    // 2. Oktato
    // 3. KonzulensPar
    //
    // Destrukció FORDÍTVA:
    //
    // 1. KonzulensPar
    // 2. Oktato
    // 3. Hallgato
    //
    // ============================================

    Hallgato hallgato;
    Oktato oktato;
};

// =====================================================
// FÜGGVÉNY
// =====================================================
KonzulensPar* KonzulensPfV()
{
    std::cout << "\n========== FUGGVENY START ==========\n\n";

    // ============================================
    // STACK objektum
    // ============================================
    //
    // Ez AUTOMATIKUS objektum.
    //
    // A függvény végén AUTOMATIKUSAN törlődik.
    //
    // Nem kell delete.
    //
    // STACK:
    //
    // [konzulensPar]
    //
    // ============================================

    KonzulensPar konzulensPar;

    std::cout << "\n[INFO] Heap objektum letrehozasa\n\n";

    // ============================================
    // HEAP objektum
    // ============================================
    //
    // A new:
    //
    // 1. memóriát foglal HEAP-en
    // 2. meghívja a konstruktort
    //
    // STACK:
    //   tagKonzulensPar pointer
    //
    // HEAP:
    //   KonzulensPar objektum
    //
    // tagKonzulensPar -----> [KonzulensPar]
    //
    // ============================================

    KonzulensPar* tagKonzulensPar =
        new KonzulensPar;

    std::cout << "\n[INFO] return elott\n";

    // ============================================
    // FONTOS
    // ============================================
    //
    // A return előtt:
    //
    // a STACK objektum megszűnik:
    //
    // konzulensPar
    //
    // ezért AUTOMATIKUSAN:
    //
    // ~KonzulensPar()
    //
    // lefut.
    //
    // A HEAP objektum NEM szűnik meg.
    //
    // ============================================

    return tagKonzulensPar;
}

// =====================================================
// MAIN
// =====================================================
int main()
{
    std::cout << "\n========== MAIN START ==========\n\n";

    // ============================================
    // A pointer STACK-en van
    // Az objektum HEAP-en van
    // ============================================

    KonzulensPar* tagKonzulensParVisszaHelyezett =
        KonzulensPfV();

    std::cout << "\n[INFO] Vissza a main-be\n\n";

    // ============================================
    // DELETE
    // ============================================
    //
    // A delete:
    //
    // 1. meghívja:
    //
    //    ~KonzulensPar()
    //
    // 2. felszabadítja a heap memóriát
    //
    // ============================================

    delete tagKonzulensParVisszaHelyezett;

    std::cout << "\n========== PROGRAM VEGE ==========\n";

    std::cin.ignore(
        (std::numeric_limits<std::streamsize>::max)(),
        '\n'
    );

    std::cin.get();

    return 0;
}
```


A `std::unique_ptr` nagyon sok helyen kiváltja a `new/delete` használatát, DE nem mindenhol.

A modern C++ célja:

```cpp
new/delete -> ritka
```

de vannak helyzetek ahol még kell vagy praktikusabb.

------

# 1. Régi C API-k

Példa:

```cpp
FILE* f = fopen("test.txt", "r");
```

Itt nem `unique_ptr`-t kapsz.

Vagy:

```cpp
SDL_Window* window;
```

régi C libraryknél gyakori.

------

# 2. Manuális memória kezelés

Game engine
OS kernel
embedded
allocatorok

pl:

```cpp
void* memory = operator new(1024);
```

Itt nagyon kontrollálni akarják:

- alignment
- cache
- memória pool
- custom allocator

------

# 3. Placement new

Ez nagyon haladó C++.

```cpp
char buffer[sizeof(Kurzus)];

Kurzus* k = new(buffer) Kurzus;
```

Itt NEM foglal memóriát.

Csak meglévő memóriába épít objektumot.

Ilyet használnak:

- game engine
- Unreal Engine
- custom containers

------

# 4. Saját memória pool

Példa:

```cpp
Enemy* e = enemyPool.allocate();
```

A háttérben lehet `new/delete`, de speciálisan kezelik.

Gyorsabb lehet mint a normál heap.

------

# 5. shared_ptr ciklikus referencia

Néha direkt nem akarnak smart pointert.

------

# 6. Nagyon egyszerű ideiglenes példák

Néha tutorialban:

```cpp
new/delete
```

mert tanítani akarják a memóriakezelést.

------

# 7. Interfész kompatibilitás

Van API ami:

```cpp
MyObject* CreateObject();
```

visszaad pointert.

Neked kell:

```cpp
delete
```

------

# 8. Tömbök

Régen:

```cpp
int* arr = new int[100];
delete[] arr;
```

Ma inkább:

```cpp
std::vector<int>
```

------

# FONTOS

A `unique_ptr` NEM helyettesíti:

## Stack objektumokat

Ez:

```cpp
Kurzus k;
```

még mindig jobb ha lehet.

Mert:

- gyorsabb
- egyszerűbb
- nincs heap
- nincs pointer

------

# Modern C++ gondolkodás

## Első választás:

```cpp
Kurzus k;
```

(stack)

------

## Ha dinamikus kell:

```cpp
std::unique_ptr<Kurzus>
```

------

## Csak végső eset:

```cpp
new/delete
```

------

# Modern guideline

Kb így:

```text
Stack objektum
    ↓
unique_ptr
    ↓
shared_ptr
    ↓
raw new/delete
```

------

# A te példád ideálisan:

```cpp
class Oktato
{
private:
    Kurzus mK;
};
```

ÉS ENNYI 

Nincs:

- pointer
- new
- delete
- unique_ptr

mert ha nincs szükség dinamikus memóriára, a stack/tagobjektum a legjobb.

Mert a programodban KÉT külön `KonzulensPar` objektum jön létre 🙂
Ez a kulcs.

------

# 1. ELSŐ objektum (STACK)

Ez:

```cpp
KonzulensPar konzulensPar;
```

lokális objektum a függvényben.

------

# 2. MÁSODIK objektum (HEAP)

Ez:

```cpp
KonzulensPar* tagKonzulensPar = new KonzulensPar;
```

egy teljesen MÁS objektum.

------

# Ezért látod kétszer:

```text
Hallgato()
Oktato()
Kurzus()
KonzulensPar()
```

mert:

```text
ELSŐ objektum felépül
MÁSODIK objektum felépül
```

------

# Memóriában:

```text
STACK:

konzulensPar
 ├── Hallgato
 └── Oktato
      └── Kurzus (heap)

tagKonzulensPar pointer
        │
        ▼

HEAP:

KonzulensPar objektum
 ├── Hallgato
 └── Oktato
      └── Kurzus (heap)
```

------

# Tehát VALÓJÁBAN:

## 2 db KonzulensPar

## 2 db Hallgato

## 2 db Oktato

## 2 db Kurzus

jön létre.

------

# Miért fut le kétszer a destruktor?

Mert KÉT objektum szűnik meg külön időben.

------

# ELSŐ destrukció

Ez:

```cpp
KonzulensPar konzulensPar;
```

a függvény végén automatikusan megszűnik.

Amikor:

```cpp
return tagKonzulensPar;
```

lefut.

------

# Ezért az első:

```text
~KonzulensPar()
~Oktato()
~Kurzus()
~Hallgato()
```

MÁR A FÜGGVÉNYBEN lefut.

------

# MÁSODIK destrukció

A heap objektum MÉG él.

Mert:

```cpp
new KonzulensPar
```

nem törlődik automatikusan.

------

# Csak itt:

```cpp
delete tagKonzulensParVisszaHelyezett;
```

------

# Ezért fut le MÁSODSZOR is:

```text
~KonzulensPar()
~Oktato()
~Kurzus()
~Hallgato()
```

------

# Röviden

## Első példány:

```cpp
KonzulensPar konzulensPar;
```

→ stack
→ automatikus destruktor

------

## Második példány:

```cpp
new KonzulensPar;
```

→ heap
→ kézi `delete`

------

# Ez volt a példa lényege

Megmutatni a különbséget:

| Stack objektum        | Heap objektum       |
| --------------------- | ------------------- |
| automatikus törlés    | kézi delete         |
| scope végén megszűnik | addig él míg delete |
| gyors                 | lassabb             |
| nem kell delete       | kell delete         |

Nagyon egyszerű szabály Ati 🙂

# STACK

Ha simán létrehozod az objektumot:

```cpp
Kurzus k;
```

vagy:

```cpp
KonzulensPar kp;
```

akkor STACK.

------

# HEAP

Ha `new`-t használsz:

```cpp
Kurzus* k = new Kurzus;
```

vagy:

```cpp
KonzulensPar* kp = new KonzulensPar;
```

akkor HEAP.

------

# A legfontosabb szabály

## `new` → heap

## nincs `new` → stack

------

# A te programodban

## STACK:

```cpp
KonzulensPar konzulensPar;
Hallgato hallgato;
Oktato oktato;
```

------

# HEAP:

```cpp
new KonzulensPar
new Kurzus
```

------

# FONTOS

A pointer NEM jelenti automatikusan hogy heap.

Ez:

```cpp
Kurzus* k;
```

MÉG nem heap.

Ez csak egy pointer változó.

------

# A heap itt kezdődik:

```cpp
k = new Kurzus;
```

------

# Egyszerű memória kép

# STACK

```text
main()
 └── kp
      ├── hallgato
      └── oktato
```

Automatikusan törlődik.

------

# HEAP

```text
kp pointer
    │
    ▼
[KonzulensPar objektum]
```

Kézzel kell:

```cpp
delete kp;
```

------

# Mikor használunk stack-et?

A legtöbbször 🙂

```cpp
std::string s;
std::vector<int> v;
Kurzus k;
```

------

# Mikor heap-et?

Ha:

- dinamikus életciklus kell
- nagy objektum
- sok objektum
- vissza akarod adni
- meg akarod osztani
- runtime méret

------

# Modern C++:

## Stack:

```cpp
Kurzus k;
```

------

## Heap modernül:

```cpp
auto k = std::make_unique<Kurzus>();
```

nem:

```cpp
new/delete
```

------

# Rövid szabály

```text
new      -> heap
nincs new -> stack
```

Igen 🙂
Ez teljesen valós dolog, és ezért létezik a heap.

De fontos látni, hogy a stack overflow általában nem „normál” kis objektumoktól jön, hanem:

- túl nagy lokális tömbök
- végtelen rekurzió
- nagyon sok stack adat

------

# Stack méret

A stack általában korlátozott.

Kb:

```text
1 MB
2 MB
8 MB
16 MB
```

OS-től függően.

------

# Heap

A heap sokkal nagyobb lehet:

```text
száz MB
GB-ok
```

------

# EZ OKÉS stacken

```cpp
Kurzus k;
Hallgato h;
Oktato o;
```

Ezek pici objektumok.

------

# EZ MÁR VESZÉLYES

```cpp
int tomb[10000000];
```

Ez kb:

```text
40 MB
```

stack overflow lehet.

------

# Rekurzió is veszélyes

```cpp
void f()
{
    f();
}
```

Minden hívás új stack frame.

Végül:

```text
STACK OVERFLOW
```

------

# Modern C++ szabály

## Kis objektum:

STACK 👍

```cpp
std::string
std::vector
kis classok
```

------

# Nagy adatok:

HEAP 👍

```cpp
std::vector<int> nagyAdat;
```

A vector maga stacken van, de az adat heapen.

------

# FONTOS

Ez:

```cpp
std::vector<int> v(10000000);
```

NEM stack overflow.

Mert:

```text
vector objektum -> stack
adatok -> heap
```

------

# Ezért jók az STL konténerek

- vector
- string
- map
- unordered_map

mert belül heap-et használnak.

------

# Régi C stílus veszélyesebb

```cpp
char buffer[10000000];
```

stack overflow lehet.

------

# A te példád teljesen biztonságos stacken

Mert a `KonzulensPar` kicsi.

Kb:

```text
Hallgato
Oktato
pointer
```

Ez pár byte.

------

# Nagyon fontos modern guideline

## Preferáld a stack-et.

Mert:

- gyors
- automatikus
- cache friendly
- nincs memory leak

DE:

## nagy/dinamikus adat → heap.

------

# Modern C++ gondolkodás

```text
Kis objektum:
    stack

Nagy adatok:
    vector/string (heap belül)

Komplex ownership:
    unique_ptr/shared_ptr
```

------

# Valóságban

A legtöbb modern C++ program:

- sok stack objektumot használ
- de az STL belül heap-et használ

Példa:

```cpp
std::string s = "Hello";
```

A `string` stack objektum, de a karakterek gyakran heapen vannak.

 a **data segment is RAM-ban van**, ugyanabban a fő memóriában, mint a stack és a heap.

------

# Hol van a data segment?

A program futásakor a RAM így néz ki egyszerűsítve:

```text
RAM
 ├── TEXT (kód)
 ├── DATA (global / static változók)
 ├── HEAP (dinamikus memória)
 └── STACK (függvények, lokális változók)
```

 Tehát a **data segment = RAM része**

------

# Lassú-e?

##  Nem lassabb alapból

A data segment:

- **ugyanolyan gyorsan elérhető**, mint a stack
- CPU cache-be ugyanúgy bekerül
- nincs „keresgélés”, mint a heapnél

------

# Gyors összehasonlítás

| terület              | sebesség     | miért                    |
| -------------------- | ------------ | ------------------------ |
| STACK                | nagyon gyors | pointer mozgatás         |
| DATA (global/static) | gyors        | fix cím                  |
| HEAP                 | lassabb      | allokáció + fragmentáció |

------

# Miért érzik sokan lassabbnak?

Nem maga a data segment lassú, hanem:

## 1. Global state miatt

- nehezebb optimalizálni
- cache locality rosszabb lehet

## 2. Több thread esetén

- lock kellhet
- versenyhelyzet

## 3. Indirekt hozzáférés

pl.:

```cpp
extern int choice;
```

nem inline, mint stack változó

------

# Fontos különbség

## STACK

```cpp
int x = 5;
```

- gyors
- lokális
- CPU register közel

------

## DATA segment

```cpp
int x = 5; // global
```

- fix memória cím
- program teljes idejéig él

------

## HEAP

```cpp
int* x = new int(5);
```

- leglassabb
- dinamikus
- allocator kell

------

# Egymondatos lényeg

 A data segment is RAM-ban van, és nem lassú, inkább a heap a lassabb, nem a global memória.

------

Ha akarod, megmutatom egy nagyon tiszta ábrán, hogyan fér bele egy teljes C++ program (code + stack + heap + data) futás közben, ez sokat szokott segíteni.