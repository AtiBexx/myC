# Namespace

## Miért kell itt a `namespace`?

A **namespace** arra  is való, hogy **azonos nevű függvényeket vagy változókat elkülöníts**, hogy ne ütközzenek.

A te példádban **két log függvény van**:

```cpp
namespace Math 
{
    double log(double x)
}

namespace systemLog
{
    int log(double x)
}
```

Ha **nem lenne namespace**, akkor ez lenne:

```cpp
double log(double x);
int log(double x);   // HIBA
```

Ez hibát adna, mert:

- ugyanaz a név (`log`)
- ugyanaz a paraméter (`double`)
- csak a return type más → ez C++-ban **nem elég különbség**

## Namespace megoldja:

Így már külön "terekben" vannak:

```cpp
Math::log(x);        // matematikai log
systemLog::log(x);   // system log
```

Tehát a `::` operátorral mondod meg melyiket akarod.

## Egyszerű hasonlat:

Képzeld el:

**Budapest János**
**Debrecen János**

Mindkettő János, de a "namespace" a város:

```
Budapest::Janos
Debrecen::Janos
```

## Miért hasznos ez valós projektekben?

Például:

- saját `log()` függvény
- `std::log()` (cmath)

Namespace nélkül összeakadnának.

Ezért van a standard library is:

```cpp
std::cout
std::log
std::vector
```

Az `std` is namespace.

## A te kódod célja valószínűleg ez volt:

Demonstrálni hogy:

```cpp
Math::log(x);
systemLog::log(x);
```

ugyanaz a név lehet.

## Extra profi megjegyzés:

A `systemLog::log` rossz return type:

```cpp
int log(double x)
```

mert `std::log` double-t ad vissza.

Inkább:

```cpp
double log(double x)
{
    return std::log(x);
}
```

```
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

namespace Math 
{
    double log (double x) 
    {
        //TODO 
        //return std::log(x);
    }
}

namespace systemLog
{
    int log (double x) 
    {
        // TODO 
        //return std::log(x);
    }
}

int main(int argc, char* argv[]) 
{
    double x = 0.0;
    double dl = Math::log(x);
    systemLog::log(dl);

    //exiting
    std::cout <<"A folytatáshoz kérlek nyomd meg az enter-t! " << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}
```

#### kód teljes

```
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

namespace Math 
{
    double log (double x) 
    { 
        return std::log(x);
    }
}

namespace systemLog
{
    void log (double x) 
    {
        std::cout << "Log value: " << x << std::endl;
    }
}

int main(int argc, char* argv[]) 
{
    double x = 0.0;
    double dl = Math::log(x);
    systemLog::log(dl);

    //exiting
    std::cout <<"A folytatáshoz kérlek nyomd meg az enter-t! " << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}
```

**output**

```
Log value: -inf
A folytatáshoz kérlek nyomd meg az enter-t!
```

-inf == **infinity** azaz végtelen

#### másik kód

```c++
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

namespace Math 
{
    double log (double x) 
    { 
        return std::log(x);
    }
}

namespace systemLog
{
    void log (double x) 
    {
        std::cout << "Log value: " << x << std::endl;
    }
}
void test (double x)
{
    double dl = Math::log(x);
    systemLog::log(dl);
}

//prótotípus deklaráció
void test (double x);


int main(int argc, char* argv[]) 
{
    test(10);
    test(1);
    test(0.5);
    test(0.1);

    //exiting
    std::cout <<"A folytatáshoz kérlek nyomd meg az enter-t! " << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}
```

**output**

```c++
Log value: 2.30259
Log value: 0
Log value: -0.693147
Log value: -2.30259
A folytatáshoz kérlek nyomd meg az enter-t!
```

Az `std::log()` az **e** számot használja alapként, ahol `e ≈ 2.718...`

Miért pont ez a furcsa szám? Mert az e-nek van egy különleges tulajdonsága — ez az egyetlen szám amelynek növekedési üteme pontosan önmaga. Ez természetesen jelenik meg a természetben (kamatos kamat, bomlás, stb.), ezért hívják **természetes** logaritmusnak.

## A te eredményeid magyarázva



```
test(10)  → 2.30259    mert   e^2.30259 ≈ 10
test(1)   → 0          mert   e^0 = 1  (bármely szám 0. hatványa = 1)
test(0.5) → -0.693     mert   e^(-0.693) ≈ 0.5
test(0.1) → -2.302     mert   e^(-2.302) ≈ 0.1
```

A negatív eredmény logikus: ha 1-nél kisebb számot akarsz kapni, **negatív kitevő** kell.

 Azért megy prototípus nélkül is, mert a `test()` függvény **a `main()` előtt van definiálva** a fájlban. A fordító fentről lefelé olvassa a kódot, tehát mire a `main()`-hez ér, már ismeri a `test()`-et.

pl:

```cpp
int main() {
    test(10);  // ← fordító még nem látta a test()-et!
}

void test(double x) { ... }  // ← csak itt van definiálva
```

Ilyenkor a fordító panaszkodna, hogy nem ismeri a `test()`-et. A prototípus előre "bemutatja" a függvényt.

## Miért?

Mert a törtkitevős hatványhoz egy végtelen összeadás kell (ezt hívják Taylor-sornak):



```
e^x = 1 + x + x²/2! + x³/3! + x⁴/4! + ...
```

Ez kb. azt jelenti: örökké összeadsz egyre kisebb számokat, és közelítesz a végeredményhez.

------

## De megmutatom az egész kitevőst, azt lehet! 



```
e^2 = 2.718 × 2.718 = 7.389
```

Ezt kézzel meg tudod csinálni. A `2.30259`-es kitevőt viszont már a számológép/számítógép csinálja.

------

## A lényeg amit érdemes megjegyezni

Neked programozóként **nem kell kézzel kiszámolni.** Elég érteni hogy:



```
log(10) = 2.30259
```

azt jelenti: **"e-t ennyiszer kell önmagával szorozni hogy 10-et kapj"**

A pontos számítást a `std::log()` elvégzi helyetted. 🙂

Nem feltétlenül! A számológépen általában **két gomb** van:

------

## A két logaritmus gomb

```
log(x)   →  ez 10-es alapú   (log₁₀)
ln(x)    →  ez e-s alapú     (természetes, ez a 2.718)
```

------

## A te példád

Ha **ln(10)**-et nyomod:

```
ln(10) = 2.30259  ✓  ← ez ugyanaz amit a C++ ad
```

Ha **log(10)**-et nyomod:

```
log(10) = 1  ✓  ← mert 10^1 = 10
```

------

## Próbáld ki!

Nyomd meg a számológépen:

```
ln(10)   → 2.30259 kell kapj
ln(1)    → 0
ln(0.5)  → -0.693
```

Ezek pontosan egyeznek a C++ programod kimenetével! 🙂

Nagyon jó kérdés, ez az egyik legszebb sztori a matematikában! 😊

------

## Kezdjük egy valós példával: a bank

Tegyük fel van **1 forintod** és a bank **100% kamatot** ad évente.

```
1 év végén = 2 forint
```

De mi van ha **félévente** fizetik a kamatot? (50% kétszer)

```
1.5 × 1.5 = 2.25 forint
```

Mi van ha **havonta**? (12-szer kis kamat)

```
(1 + 1/12)^12 = 2.613 forint
```

Mi van ha **naponta**?

```
(1 + 1/365)^365 = 2.714 forint
```

Mi van ha **másodpercenként**?

```
(1 + 1/végtelen)^végtelen = 2.71828...
```

------

#### Ez az e szám!

```
e = (1 + 1/n)^n   ahol n → végtelen
e = 2.71828182845...
```

**Minél sűrűbben fizeted a kamatot, annál inkább közelít e-hez — de soha nem lépi túl!**

------

#### Miért "természetes"?

Mert ez a **folyamatos növekedés** alapja. Nem csak bankban, hanem:

```
népességnövekedés
radioaktív bomlás
vírus terjedése
```

#### A Windows számológép

------

#### Így kapcsold át tudományosra

```
Számológép megnyitása
→ bal felső sarok: három vízszintes csík (☰)
→ "Tudományos" választása
```

------

#### Amit keresni fogsz

```
ln       → természetes logaritmus (e alapú)
log      → 10-es alapú logaritmus
x^y      → ez a hatványozás gomb  (ez a te ^ jeled!)
e^x      → e hatványai
```

------

#### Próbáld ki!

```
1.) írj be 2.71828
2.) nyomd meg x^y
3.) írj be 2.30259
4.) Enter
→ kb 10-et kell kapj  ✓
```

Ez pontosan azt ellenőrzi amit tanultunk:

```
e^2.30259 = 10
```

------

#### Miért 1?(ha log 10)

Mert ez a gomb **10-es alapú** logaritmus:

```
log(10) = 1
```

mert:

```
10^1 = 10  ✓
```

------

#### Az e-s logaritmushoz az LN gomb kell

Keresd meg az **LN** feliratú gombot, és nyomd:

```
LN ( 10 ) = ?  → 2.30259 kell kapj
```

------

#### A hatványozáshoz

A Casio számológépeken általában ez a gomb:

```
x^y   vagy   y^x   vagy   ^
```

Próbáld meg:

```
2.718  →  y^x  →  2.30259  →  =
→ kb 10-et kell kapj  ✓
```

### Logaritmus log

```
ln(10) megkérdezi:  "2.718-at milyen kitevőre kell emelni hogy 10-et kapjak?"
a válasz:           2.30259
tehát:              2.718^2.30259 = 10
```

A logaritmus értéke **mindig a kitevő** — nem az alap! 🙂

Próbáld ki számológépen:

```
2.718  →  y^x  →  2.30259  →  =
→ kb 10-et kell kapj  ✓
```

Az **ln** ugyanaz mint amit eddig tanultunk! 😊

------

## Egyszerűen

```
ln  =  e alapú logaritmus
e   =  2.718...
```

Csak rövidítés:

```
ln(10)        =  2.30259
log_e(10)     =  2.30259   ← ugyanaz!
```

------

## A három logaritmus gomb a számológépen

```
log      →  10-es alap    →  log(10)  = 1
ln       →  2.718 alap    →  ln(10)   = 2.30259
y^x      →  hatványozás   →  ellenőrzésre
```

------

## Tehát a C++ std::log() is ln!

~~~cpp
std::log(10) = 2.30259  // ez ln, nem log!
```

Azért hívják "természetes logaritmusnak" mert az **e** a természetes alap — ahogy a banknál mutattuk! 

Próbáld most számológépen:
```
ln → 10 → =
→ 2.30259 kell kapj  ✓
~~~

A **ln(10) értéke = 2.30259**

A **2.718^2.30259 értéke = 10**

------

## Tehát

```
ln(10)        = 2.30259   ✓
2.718^2.30259 = 10        ✓
```

A sima **log** alapja **10**! 😊

------

## A kettő különbsége

```
ln(10)  = 2.30259   ← alap: 2.718 (e)
log(10) = 1         ← alap: 10
```

------

## Miért 1 a log(10)?

Mert:

```
10^1 = 10  ✓
```

A kérdés: **"10-et milyen kitevőre kell emelni hogy 10-et kapjak?"**

A válasz: **1** — hiszen 10^1 = 10

------

## Még egy példa

```
log(100) = 2    mert   10^2 = 100
log(1000) = 3   mert   10^3 = 1000
log(10) = 1     mert   10^1 = 10
log(1) = 0      mert   10^0 = 1
```

Látod a mintát? Szépen egész számok jönnek ki ha 10-es hatványokat írsz be! 😊

------

## Összefoglalva

```
log  →  alap 10   →  "10-es logaritmus"
ln   →  alap e    →  "természetes logaritmus"
```

### tegyük fel vírus terjedése vagy természetes banki növekedést vagy népességfogyást/növekedést akarok számolni ...........

## A képlet

```
A = A₀ × e^(r×t)
```

```
A₀  =  kezdeti érték (pl. 100 ember)
r   =  növekedési ráta (pl. 0.05 = 5%)
t   =  idő (pl. évek)
A   =  végeredmény
```

------

## Példák

**Vírus terjedése** - 100 fertőzött, 20% naponta, 10 nap múlva:

```
A = 100 × e^(0.20 × 10)
A = 100 × e^2
A = 100 × 7.389
A = 738 fertőzött
```

**Népességnövekedés** - 1 millió ember, 3% évente, 50 év múlva:

```
A = 1000000 × e^(0.03 × 50)
A = 1000000 × e^1.5
A = 1000000 × 4.48
A = 4 480 000 ember
```

**Radioaktív bomlás** - csökkenésnél r negatív!:

```
A = 1000 × e^(-0.1 × 10)
A = 1000 × e^(-1)
A = 1000 × 0.368
A = 368 maradt
```

------

## C++-ban ez így nézne ki

cpp

```cpp
#include <cmath>

double novekedes(double kezdeti, double rata, double idő)
{
    return kezdeti * std::exp(rata * idő);
}
```

Rendben, egyszerűen és részletesen! 😊

------

## A képlet

```
A = A₀ × e^(r × t)
```

------

## Minden betű jelentése

**A₀ = kiindulás**

```
hány fertőzöttel kezdtük?
példánkban: 100 fertőzött
```

**r = sebesség**

```
milyen gyorsan terjed naponta?
példánkban: 20% naponta
```

**t = idő**

```
hány napig terjed?
példánkban: 10 nap
```

**e = 2.718...**

```
ez a természetes növekedés alapszáma
mindig ugyanannyi, nem változik
```

**A = végeredmény**

```
hány fertőzött lesz a végén?
ezt akarjuk kiszámolni
```

------

## Konkrétan a példánkban

```
A₀ = 100     (ennyi fertőzöttel indulunk)
r  = 0.20    (20% naponta)
t  = 10      (10 nap)
e  = 2.718
```

Behelyettesítve:

```
A = 100 × 2.718^(0.20 × 10)
A = 100 × 2.718^2
A = 100 × 7.389
A = 738 fertőzött
```

------

Rendben, így néz ki konkrétan! 😊

------

## A képlet kitöltve

```
A = A₀ × e^(r × t)
```

Behelyettesítve:

```
A = 100 × e^(0.20 × 10)
```

------

## Lépésről lépésre

**1. lépés - zárójelben lévő szorzás:**

```
0.20 × 10 = 2
```

**2. lépés - e hatványozása:**

```
e^2 = 2.718 × 2.718 = 7.389
```

**3. lépés - végső szorzás:**

```
100 × 7.389 = 738
```

------

## Eredmény

```
100 fertőzöttből
20% napi terjedéssel
10 nap alatt
738 fertőzött lesz
```

------

## Számológépen

```
1.)  0.20 × 10 =        → 2
2.)  SHIFT + ln → 2 =   → 7.389
3.)  100 × 7.389 =      → 738
```

