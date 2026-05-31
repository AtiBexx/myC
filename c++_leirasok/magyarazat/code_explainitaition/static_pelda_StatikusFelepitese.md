```cpp
/*
A statikus változók olyan változók
amely egy függvény változói
de megőrzik az értéküket a függvény hívásai között.

A globális változók a függvényem kívül deklarált változók.
*/
//------------------------------------------------------
/*
A statikus Objektumok hasonlóak a helyi változókhoz
azt leszámítva hogy,, csak egyetlen egyszer épülnek fel.
*/
//======================================
// StatikusFelépítése
// Szemlélteti hogy a statikus objektum csak egyszer épül fel
//======================================
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class NemCsinalSemmit
{
public:
    NemCsinalSemmit(int kezdeti):nErtek(kezdeti)
    {
        std::cout <<"Nem csinálunk semmit érték(Stacken csak egyszer fut le):"<< kezdeti <<'\n';
    }
    //Destruktor ~ megsemmísítés
    ~NemCsinalSemmit()
    {
        std::cout <<"A Konstruktor megsemmisítése" <<'\n';
    }
protected:
    int nErtek;
};
void fv(int i)
{
    std::cout <<"Az fv() Függvénynek átadott érték: " << i <<'\n';
    static NemCsinalSemmit fv (i);
}

int main(int argc,char** argv)
{
    //stack
    fv(10);
    fv(20);
    fv(40);
    fv(50);
    std::cout<<'\n';
    std::cout <<"Heap->"<<'\n';
    //Heap *
    NemCsinalSemmit* fv1 = new NemCsinalSemmit(40);
    NemCsinalSemmit* fv2 = new NemCsinalSemmit(50);

    delete fv1;
    delete fv2;

    //kilépünk
    std::cout <<"Kérlek a folytatáshoz nyomd meg kétszer az ENTERT...."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return EXIT_SUCCESS;
}

```

Pontosan. A te példádban a heapen létrehozott objektumok **nem statikusak**.

Nézd ezt:

```cpp
NemCsinalSemmit* fv1 = new NemCsinalSemmit(40);
NemCsinalSemmit* fv2 = new NemCsinalSemmit(50);
```

Itt minden `new`:

1. lefoglal memóriát a heapen,
2. meghívja a konstruktort,
3. létrehoz egy új objektumot.

Ezért a konstruktor kétszer fut le:

```text
Nem csinálunk semmit érték(Stacken csak egyszer fut le):40
Nem csinálunk semmit érték(Stacken csak egyszer fut le):50
```

------

A statikus objektum itt van:

```cpp
void fv(int i)
{
    static NemCsinalSemmit fv(i);
}
```

Ez nem a stacken van a klasszikus értelemben.

A `static` lokális változó:

- nem a heapen van,
- nem a normál veremen (stacken) van,
- a program statikus adattároló területén van (static storage).

Élettartama:

```text
program indul
      ↓
létrejön első híváskor
      ↓
megmarad
      ↓
megmarad
      ↓
megmarad
      ↓
program vége
      ↓
destruktor
```

------

Összefoglalva:

| Típus            | Hol van?       | Mikor jön létre?  | Mikor szűnik meg? |
| ---------------- | -------------- | ----------------- | ----------------- |
| Lokális változó  | Stack          | Belépéskor        | Kilépéskor        |
| `static` lokális | Static storage | Első használatkor | Program végén     |
| `new` objektum   | Heap           | `new`-kor         | `delete`-kor      |

A programban:

```cpp
static NemCsinalSemmit fv(i);
```

→ statikus tárolóterület

```cpp
NemCsinalSemmit* fv1 = new NemCsinalSemmit(40);
```

→ heap

```cpp
NemCsinalSemmit obj(10);
```

→ stack

Ez a három különböző élettartam-modell C++-ban. A "statikus" nem azt jelenti, hogy heapen van, hanem azt, hogy az objektum élettartama az egész programra (vagy a program végéig) kiterjed.

Nagyon jó kérdés. A **static storage** egy külön memóriaterület, ami sem nem stack, sem nem heap.

Egy tipikus program memóriája leegyszerűsítve így néz ki:

```text
Magas címek
+------------------+
|      Stack       |
|  lokális változók|
+------------------+

|                  |
|  szabad memória  |
|                  |

+------------------+
|       Heap       |
|   new / delete   |
+------------------+

|      BSS         |
| statikus, globális
| nullázott adatok |
+------------------+

|      Data        |
| statikus, globális
| inicializált     |
+------------------+

|      Text        |
| programkód       |
+------------------+
Alacsony címek
```

------

## Példa

```cpp
int globalis = 5;
```

Ez a **Data** szegmensbe kerül.

------

```cpp
int globalis2;
```

Ez a **BSS** szegmensbe kerül.

------

```cpp
void fv()
{
    static int x = 10;
}
```

A `x` is a statikus tárolóterületen van (Data/BSS).

Nem a stacken.

------

## Miért nem a stacken?

Normál lokális változó:

```cpp
void fv()
{
    int x = 10;
}
```

Minden függvényhíváskor:

```text
belépés -> x létrejön
kilépés -> x eltűnik
```

------

Statikus lokális:

```cpp
void fv()
{
    static int x = 10;
}
```

Első hívás:

```text
x létrejön
```

Második hívás:

```text
ugyanaz az x
```

Harmadik hívás:

```text
ugyanaz az x
```

Program vége:

```text
x megsemmisül
```

Ezért nem lehet a stacken, mert a stack tartalma eltűnik a függvény végén.

------

## A te példádban

```cpp
static NemCsinalSemmit fv(i);
```

A `NemCsinalSemmit` objektum valahol a statikus adattároló területen lakik.

Az első híváskor:

```cpp
fv(10);
```

létrejön.

A későbbi hívások:

```cpp
fv(20);
fv(40);
fv(50);
```

ugyanazt az objektumot használják.

------

## Egy klasszikus példa

```cpp
void szamlalo()
{
    static int db = 0;
    db++;

    std::cout << db << '\n';
}
```

Hívások:

```cpp
szamlalo();
szamlalo();
szamlalo();
```

Kimenet:

```text
1
2
3
```

Ha nem lenne `static`:

```text
1
1
1
```

lenne.

------

Ezért szokták azt mondani:

> A `static` lokális változó **úgy néz ki, mint egy lokális változó, de úgy él, mint egy globális változó.**

Láthatósága csak a függvényen belüli, de az élettartama a teljes programra kiterjed.

Igen, pontosan. A `static` és a globális változók általában a **Data** vagy a **BSS** szegmensbe kerülnek.

A különbség:

## Data szegmens

Azok a globális vagy statikus változók, amelyeknek van kezdőértékük.

```cpp
int x = 10;
static int y = 20;
```

Ezek a Data szegmensben vannak.

A program futása előtt az operációs rendszer betölti őket a megadott értékekkel.

------

## BSS szegmens

A BSS (Block Started by Symbol) azokat a globális és statikus változókat tartalmazza, amelyek nincsenek explicit inicializálva.

```cpp
int x;
static int y;
```

A C++ garantálja, hogy ezek induláskor nullázva lesznek:

```cpp
x == 0
y == 0
```

Ezért nem kell a futtatható fájlban tárolni a sok nullát. Az OS egyszerűen lefoglalja a memóriát és lenullázza.

------

Példa:

```cpp
int a = 5;      // Data
int b;          // BSS

static int c=7; // Data
static int d;   // BSS
```

------

A te objektumod:

```cpp
static NemCsinalSemmit obj(10);
```

kicsit speciális.

Mivel van konstruktora, az objektum memóriája statikus tárolóterületen van, de a konstruktor futtatása programinduláskor vagy első használatkor történik. A fordító és a linker intézi, hogy ehhez szükséges információk a megfelelő szegmensekben legyenek.

------

Egyszerűen:

```text
Text    -> gépi kód
Data    -> inicializált static/global
BSS     -> inicializálatlan static/global
Heap    -> new/delete
Stack   -> lokális változók, függvényhívások
```

Például:

```cpp
int g = 42;          // Data
int h;               // BSS

int main()
{
    int x = 1;       // Stack

    int* p = new int(5); // Heap
}
```

Ez az alap memóriafelosztás, amit szinte minden C/C++ programnál érdemes fejben tartani.

-------------------

Ha az `index.h`-ban ezt írod:

```cpp
int value;
```

és ezt a headert több `.cpp` fájl is include-olja, akkor **linkelési hibát kapsz**.

Mert minden `.cpp` létrehoz egy saját definíciót:

```cpp
// a.cpp
int value;

// b.cpp
int value;
```

A linker ilyenkor azt mondja:

```text
multiple definition of 'value'
```

------

A helyes megoldás:

### index.h

```cpp
extern int value;
```

### index.cpp

```cpp
int value = 0;
```

Most már az egész programban egyetlen `value` létezik.

------

Ha aztán:

```cpp
// main.cpp
value = 10;
```

és

```cpp
// masik.cpp
value = 20;
```

akkor ugyanazt a változót módosítod.

A végső érték attól függ, melyik kód futott le utoljára.

------

## Mi van, ha static?

Headerben:

```cpp
static int value;
```

Ez teljesen más.

Minden `.cpp` kap egy saját példányt:

```cpp
// main.cpp
static int value;

// masik.cpp
static int value;
```

Valójában:

```text
main.cpp -> value
masik.cpp -> value
```

két külön változó.

------

Példa:

```cpp
// main.cpp
value = 10;
// masik.cpp
value = 20;
```

Akkor:

```text
main.cpp saját value = 10
masik.cpp saját value = 20
```

Nem látják egymást.

------

## Data vagy BSS?

Attól függ, van-e inicializálás.

```cpp
int value;
```

→ BSS

```cpp
int value = 0;
```

Sok rendszeren szintén BSS-be optimalizálható.

```cpp
int value = 10;
```

→ Data

------

Tehát:

```cpp
static int value;
```

→ minden fordítási egységben külön változó, általában BSS.

```cpp
static int value = 20;
```

→ minden fordítási egységben külön változó, általában Data.

------

A legfontosabb szabály:

- `extern` → egy közös globális változó az egész programban
- `static` globális → minden `.cpp` saját példányt kap
- inicializált → Data
- inicializálatlan → BSS (vagy nullázott statikus terület)

A **BSS** rövidítés történelmileg:

**Block Started by Symbol**

Ez még régi assembleres időkből származik.

A gyakorlatban ma úgy érdemes megjegyezni:

```cpp
BSS = inicializálatlan globális/statikus változók
```

Példák:

```
int a;          // BSS
static int b;   // BSS
```

Induláskor mindkettő 0 lesz.

------

Ezzel szemben:

```
int a = 5;          // Data
static int b = 7;   // Data
```

ezek a **Data** szegmensbe kerülnek.

-----

**Globális később inicializált változóknál:**

Például:

**index.h**

```cpp
extern int value;
```

**index.cpp**

```cpp
int value;
```

Itt a `value` definíciója:

```cpp
int value;
```

nincs inicializálva, ezért **BSS**.

Most legyen:

**main.cpp**

```cpp
value = 10;
```

**running.cpp**

```cpp
value = 20;
```

Mindkettő ugyanazt az egyetlen `value` változót módosítja.

A `value` továbbra is **BSS-ben van**, mert így lett definiálva:

```cpp
int value;
```

A futásidejű értékadások (`value = 10;`, `value = 20;`) nem helyezik át a változót a Data szegmensbe.

------

Másik eset:

**index.cpp**

```cpp
int value = 123;
```

Itt a definíció inicializált, ezért **Data**.

Ezután teljesen mindegy, hogy később:

```cpp
value = 10;
```

vagy

```cpp
value = 20;
```

a változó továbbra is **Data** szegmensbeli változó marad.

------

Összefoglalva:

| Definíció        | Hol van?                                                     |
| ---------------- | ------------------------------------------------------------ |
| `int value;`     | BSS                                                          |
| `int value = 0;` | általában BSS vagy nullázott adat szegmens (implementációfüggő) |
| `int value = 5;` | Data                                                         |

A következők:

```cpp
value = 10;
value = 20;
```

**nem befolyásolják**, hogy Data vagy BSS. Ezek csak futásidejű módosítások.

Tehát a te példádban:

```cpp
extern int value;   // csak deklaráció
```

és

```cpp
int value;          // definíció
```

→ **BSS**

akkor is, ha tíz különböző `.cpp` fájlban később ezt csinálod:

```cpp
value = 10;
value = 20;
value = 999;
```

A változó attól még BSS-ből indult. A headerben lévő `extern` pedig nem Data és nem BSS; az csak egy deklaráció, nem foglal tárhelyet.

Gyakorlatilag **egyik sem gyorsabb a másiknál** futás közben.

Ha van:

```cpp
int a = 10;   // Data
```

és

```cpp
int b;        // BSS
```

akkor a program futása után mindkettő normál memóriában van, és az elérésük sebessége ugyanaz.

```cpp
a++;
b++;
```

között nincs érdemi teljesítménykülönbség.

------

A különbség inkább programindításkor van.

### Data

```cpp
int a = 10;
```

A futtatható fájlban tárolni kell a `10` értéket.

------

### BSS

```cpp
int b;
```

A futtatható fájlban nem kell tárolni egy csomó nullát.

Az operációs rendszer egyszerűen:

```text
foglalj 4 byte-ot
nullázd le
```

Ezért a BSS gyakran kisebb executable-t eredményez.

Példa:

```cpp
char buffer[10000000];
```

Ha ez BSS:

```cpp
char buffer[10000000];
```

a programfájl mérete alig nő.

Ha viszont:

```cpp
char buffer[10000000] = {1};
```

akkor a Data szegmensbe kerül, és a futtatható fájl jelentősen nagyobb lehet.

------

Tehát:

| Tulajdonság         | Data           | BSS             |
| ------------------- | -------------- | --------------- |
| Futásidejű sebesség | ugyanaz        | ugyanaz         |
| Programméret        | nagyobb lehet  | kisebb          |
| Inicializálás       | van kezdőérték | automatikusan 0 |

A CPU szempontjából nincs olyan, hogy:

> "a BSS gyorsabb"

vagy

> "a Data gyorsabb"

A processzor csak egy memóriacímet lát. Mire a program fut, a változó már memóriában van mindkét esetben.