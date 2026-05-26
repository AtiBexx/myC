# PointerObjects

```
# include <cstdio>
# include <cstdlib>
# include <iostream>
using namespace std;

class Tanulo 
{
    public:
    int feleviOraszam = 0;
    double tanulmanyiAtlag = 0;

    //Metódos/taggfüggvény
    double kurzusHozzadasa(int oraSzam, double osztalyzat)
    {return 0.0;}
};

void egyFv() 
{
// Deklarálunk egy 10 tanulóbol álló tömböt
    Tanulo t[10];
    //Az 5. hallgatóhoz 5 -ös tanulmányi átlagot rendelünk hozzá
    t[4].tanulmanyiAtlag = 5;
    t[4].feleviOraszam = 32;

    //Hozzáadunk még egy kurzust az 5. hallgatóhoz ami nem sikerült neki 
    t[4].kurzusHozzadasa(3, 0.0);
}

int main(int argc, char* argv[])
{
//TODO --- akár de ez most kihagyjuk
//TODO jelentése majd megcsinálni

    return EXIT_SUCCESS;
}
```

```c++
# include <cstdio>
# include <cstdlib>
# include <iostream>
using namespace std;

class Tanulo 
{
    public:
    int feleviOraszam = 0;
    double tanulmanyiAtlag = 0;

    //Metódos/taggfüggvény
    double kurzusHozzadasa(int oraSzam, double osztalyzat)
    {return 0.0;}
};

void egyFv() 
{
// Deklarálunk egy 10 tanulóbol álló tömböt
    Tanulo t[10];
    //Az 5. hallgatóhoz 5 -ös tanulmányi átlagot rendelünk hozzá
    t[4].tanulmanyiAtlag = 5;  // (5 * 32 + 0)
    t[4].feleviOraszam = 32;

    //Hozzáadunk még egy kurzust az 5. hallgatóhoz ami nem sikerült neki 
    t[4].kurzusHozzadasa(3, 0.0); // (32 + 3)
    //uj tanulmanyi atlag kiszamitasa
    t[4].tanulmanyiAtlag = (t[4].tanulmanyiAtlag * t[4].feleviOraszam + t[4].kurzusHozzadasa(3, 0.0)) / (t[4].feleviOraszam + 3);
    // (5 * 32 + 0) / (32 + 3) = 160 / 35 ≈ 4.571
    cout << "A 5. hallgató tanulmanyi átlaga: " << t[4].tanulmanyiAtlag << endl;
}

int main(int argc, char* argv[])
{
    egyFv(); // meghivjuk a függvényünket
    cout << "A folytatáshoz nyomd meg az Entert..." << endl;
    cin.get();
    return EXIT_SUCCESS;
}
```

## Deklaráljuk az Objektumok mutatóit

```
// Definiáljukn mutatókat
// és használjuk a Tanuló mutatóját

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Tanulo {
public:
  int felevioraszam = 0;
  double tanulmanyiAtlag = 0;
  // ha a double helyett voidot használsz nem tudsz értéket visszadni a
  // fuggvenyben doublet add vissza és oraSzamra int-et osztalyzatra doublet var
  double kurzusHozzadasa(int oraSzam, double osztalyzat);
};

int main(int argc, char *argv[]) {
  // létrehozuk a tanulo objektumot
  Tanulo t;

  t.tanulmanyiAtlag = 3.0;

  //Most létrehozunk egy mH pointert(mutatót) ami egy tanuló objektumra mutat
  Tanulo *mH; //átadjuk a tanuló objektumnak az mH pointert
  //Most beállítjuk a mH pointert a mi t (tanulo) objektumra
  mH = &t; //az mh pointert a t (tanulo) objektumr memóriacímére és értékére mutat azaz nem másolunk 

/*
mH egy mutató a Tanulo típusra.
&t = a t objektum memóriacíme.
*/

  //Most kiíratjuk az eredményt
  cout << "t.tanulmanyiAtlag: " << t.tanulmanyiAtlag <<"\n";
  cout << "mH->tanulmanyiAtlag: " << mH->tanulmanyiAtlag << endl;

  cout << "A folytatáshoz kérlek nyomd meg az Entert..." << endl;
  cin.get();//várunk az enterre
  return EXIT_SUCCESS;
}

/*
Tanulo *mH;
mH = &t;
* nem az értékátadást jelenti, hanem azt, hogy mH mutató, azaz memóriacímet tárol.
Ha mH-t használod (mH->tanulmanyiAtlag), akkor az eredeti objektumot éred el, nem másolatot.
Tehát a * mutató deklarálására szolgál, a -> pedig a mutatott objektum tagjainak elérésére.

& – cím operátor
mH = &t;
Az & itt nem “értékátadás”, hanem azt jelenti: “vegyük a t változó memóriacímét”.
Így a mH mutató a t objektumra fog mutatni, nem készít másolatot.
*/

/*
C nyelv – mutató

C-ben is:

#include <stdio.h>

void f(int *p) {
    *p = 10; // a mutatóval a hívó változót módosítjuk
}

int main() {
    int x = 5;
    f(&x);
    printf("%d\n", x); // 10
    return 0;
}
*p → a mutató által mutatott érték
&x → az x memóriacíme
Így a függvény a valódi változót módosítja, nem másolatot.

Tehát mutatóval tudunk “eredményt kiírni” vagy módosítani, de a függvény visszatérési értéke nélkül, közvetlenül a memóriát változtatjuk.
*/
/*
Érték szerint átadás
void f(int x) {
    x = 10; // csak a másolatot módosítjuk
}

int main() {
    int a = 5;
    f(a);
    printf("%d\n", a); // 5 marad
}
Itt nem látjuk a függvényen belüli változtatást, mert x csak másolat.
*/

/*
Mutató (*) és érték kiíratása
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int *p = &x;

    cout << p << endl;   // ez **a címét** írja ki
    cout << *p << endl;  // ez **az értékét** írja ki
}
p → mutató, a x címe van benne
*p → a mutató által mutatott érték
Tehát a pointerrel is ki tudsz íratni értéket, nem csak &-vel.
2️ .  & – cím operátor
cout << &x << endl;  // x memóriacíme
&x → x címe, nem az érték
Ha *p-vel dolgozol, nem kell &-t használni az érték kiíratásához, csak a címhez.
*/

/*
A pointerrel értéket tudsz "visszaadni" egy függvényből úgy, hogy közvetlenül a memóriát 
módosítod. Ezt hívjuk cím szerinti paraméterátadásnak.

A Tanulo osztályodban a kurzusHozzadasa függvényt deklaráltad, de nem írtad meg a törzsét. 
Ha pointerrel szeretnéd módosítani az átlagot egy függvényen belül, az így nézne ki:

C++
// Függvény, ami pointert kap, hogy módosítsa az eredeti objektumot
void atlagModositas(Tanulo *tMutato, double ujAtlag) {
    if (tMutato != nullptr) {
        tMutato->tanulmanyiAtlag = ujAtlag; // Közvetlenül az eredeti t-t módosítjuk
    }
}

// Használat a main-ben:
atlagModositas(&t, 4.5); 
Összegezve: Az & (címképző) operátorra csak akkor van szükséged, amikor egy
"hétköznapi" változó (mint az int x vagy Tanulo t) helyét akarod megtudni. 
Amint ez a cím már benne van egy pointerben, onnantól a pointerrel szabadon 
"dobálózhatsz" anélkül, hogy az &-et újra ki kellene tenned a változó elé.


*/

```

#### Most új eredményt adunk neki

```
//Most feloldjuk az új eredményt azaz új értéket adunk neki
  (*mH).tanulmanyiAtlag = 4.5;

  cout << "t.tanulmanyiAtlag: " << t.tanulmanyiAtlag <<"\n"; //itt is az új eredmény lesz
  cout << "mH->tanulmanyiAtlag: " << mH->tanulmanyiAtlag << endl; //itt is az új eredmény lesz
```

vagy így.....

```
 mH->tanulmanyiAtlag = 5.0;
```





azaz full kód:

```
// Definiáljukn mutatókat
// és használjuk a Tanuló mutatóját

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Tanulo {
public:
  int felevioraszam = 0;
  double tanulmanyiAtlag = 0;
  // ha a double helyett voidot használsz nem tudsz értéket visszadni a
  // fuggvenyben doublet add vissza és oraSzamra int-et osztalyzatra doublet var
  double kurzusHozzadasa(int oraSzam, double osztalyzat);
};

int main(int argc, char *argv[]) {
  // létrehozuk a tanulo objektumot
  Tanulo t;

  t.tanulmanyiAtlag = 3.0;

  //Most létrehozunk egy mH pointert(mutatót) ami egy tanuló objektumra mutat
  Tanulo *mH; //átadjuk a tanuló objektumnak az mH pointert
  //Most beállítjuk a mH pointert a mi t (tanulo) objektumra
  mH = &t; //az mh pointert a t (tanulo) objektumr memóriacímére és értékére mutat azaz nem másolunk 

/*
mH egy mutató a Tanulo típusra.
&t = a t objektum memóriacíme.
*/

  //Most kiíratjuk az eredményt
  cout << "t.tanulmanyiAtlag: " << t.tanulmanyiAtlag <<"\n";
  cout << "mH->tanulmanyiAtlag: " << mH->tanulmanyiAtlag << endl;
  
  //Most feloldjuk az új eredményt azaz új értéket adunk neki
  (*mH).tanulmanyiAtlag = 4.5;

  cout << "Az új t.tanulmanyiAtlag: " << t.tanulmanyiAtlag <<"\n"; //itt is az új eredmény lesz
  cout << "Az újmH->tanulmanyiAtlag: " << mH->tanulmanyiAtlag << endl; //itt is az új eredmény lesz
    //vagy igy is lehet 
  mH->tanulmanyiAtlag = 5.0;// A nyíl operátort csak azért használjuk mert olvashatóbb

  cout << "Az újabb t.tanulmanyiAtlag: " << t.tanulmanyiAtlag <<"\n"; //itt is az új eredmény lesz
  cout << "Az újabb mH->tanulmanyiAtlag: " << mH->tanulmanyiAtlag << endl; //itt is az új eredmény lesz

  cout << "A folytatáshoz kérlek nyomd meg az Entert..." << endl;
  cin.get();//várunk az enterre
  return EXIT_SUCCESS;
}

/*
Tanulo *mH;
mH = &t;
* nem az értékátadást jelenti, hanem azt, hogy mH mutató, azaz memóriacímet tárol.
Ha mH-t használod (mH->tanulmanyiAtlag), akkor az eredeti objektumot éred el, nem másolatot.
Tehát a * mutató deklarálására szolgál, a -> pedig a mutatott objektum tagjainak elérésére.

& – cím operátor
mH = &t;
Az & itt nem “értékátadás”, hanem azt jelenti: “vegyük a t változó memóriacímét”.
Így a mH mutató a t objektumra fog mutatni, nem készít másolatot.
*/

/*
C nyelv – mutató

C-ben is:

#include <stdio.h>

void f(int *p) {
    *p = 10; // a mutatóval a hívó változót módosítjuk
}

int main() {
    int x = 5;
    f(&x);
    printf("%d\n", x); // 10
    return 0;
}
*p → a mutató által mutatott érték
&x → az x memóriacíme
Így a függvény a valódi változót módosítja, nem másolatot.

Tehát mutatóval tudunk “eredményt kiírni” vagy módosítani, de a függvény visszatérési értéke nélkül, közvetlenül a memóriát változtatjuk.
*/
/*
Érték szerint átadás
void f(int x) {
    x = 10; // csak a másolatot módosítjuk
}

int main() {
    int a = 5;
    f(a);
    printf("%d\n", a); // 5 marad
}
Itt nem látjuk a függvényen belüli változtatást, mert x csak másolat.
*/

/*
Mutató (*) és érték kiíratása
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int *p = &x;

    cout << p << endl;   // ez **a címét** írja ki
    cout << *p << endl;  // ez **az értékét** írja ki
}
p → mutató, a x címe van benne
*p → a mutató által mutatott érték
Tehát a pointerrel is ki tudsz íratni értéket, nem csak &-vel.
2️ .  & – cím operátor
cout << &x << endl;  // x memóriacíme
&x → x címe, nem az érték
Ha *p-vel dolgozol, nem kell &-t használni az érték kiíratásához, csak a címhez.
*/

/*
A pointerrel értéket tudsz "visszaadni" egy függvényből úgy, hogy közvetlenül a memóriát 
módosítod. Ezt hívjuk cím szerinti paraméterátadásnak.

A Tanulo osztályodban a kurzusHozzadasa függvényt deklaráltad, de nem írtad meg a törzsét. 
Ha pointerrel szeretnéd módosítani az átlagot egy függvényen belül, az így nézne ki:

C++
// Függvény, ami pointert kap, hogy módosítsa az eredeti objektumot
void atlagModositas(Tanulo *tMutato, double ujAtlag) {
    if (tMutato != nullptr) {
        tMutato->tanulmanyiAtlag = ujAtlag; // Közvetlenül az eredeti t-t módosítjuk
    }
}

// Használat a main-ben:
atlagModositas(&t, 4.5); 
Összegezve: Az & (címképző) operátorra csak akkor van szükséged, amikor egy
"hétköznapi" változó (mint az int x vagy Tanulo t) helyét akarod megtudni. 
Amint ez a cím már benne van egy pointerben, onnantól a pointerrel szabadon 
"dobálózhatsz" anélkül, hogy az &-et újra ki kellene tenned a változó elé.


*/

```

#### Amit profik csinálnak C++-ban (pointer helyett):

Referencia:

```
void ujAtlag(Tanulo &t, double jegy){
    t.tanulmanyiAtlag = 5.0;
}
```

Használat:

```
ujAtlag(t,5.0);
```

Ez:

- gyors mint pointer
- tisztább
- nem kell `*` meg `->`

Ezért modern C++-ban sokszor **reference > pointer**.

​	

#### Amit profik használnak ha pointerel módosítanak:

Szinte mindig:

```
mH->tanulmanyiAtlag
```

mert:

- rövidebb
- olvashatóbb
- standard C/C++ stílus

De van **3 valódi oka**:

##  Nem másol (gyorsabb lehet)

Értékátadás:

```
void f(Tanulo t)   // másolat készül
{
    t.tanulmanyiAtlag = 5;
}
```

Pointer:

```
void f(Tanulo *t)   // nincs másolat
{
    t->tanulmanyiAtlag = 5;
}
```

Ha a class nagy:

```
class Tanulo{
    char nev[1000];
    double jegyek[500];
};
```

akkor a másolás **lassú** lehet.

------

## Az eredetit módosítod

Value:

```
void f(int x){
    x = 10;
}

int a = 5;
f(a);

// a még mindig 5
```

Pointer:

```
void f(int *x){
    *x = 10;
}

int a = 5;
f(&a);

// a most 10
```

------

##  Több dolgot tudsz visszaadni

C-ben ezért használják sokat:

```
void calc(int a,int b,int *osszeg,int *szorzat){
    *osszeg = a+b;
    *szorzat = a*b;
}
```

------

## DE fontos:

Modern C++-ban inkább **reference (&)**:

```
void f(Tanulo &t){
    t.tanulmanyiAtlag = 5;
}
```

Ez:

- nem másol
- tisztább
- biztonságosabb

------

## Profi sorrend C++-ban:

```
reference (&)   ← leggyakoribb
pointer (*)     ← ha kell null vagy realloc
value           ← kis típusoknál
```

------

## Egy nagyon fontos igazság:

**Nem azért jobb mert pointer.**

Hanem:

**mert nem másol.**

Referencia ugyanilyen gyors.

------

## Egyszerű fejben tartó szabály:

```
int, double → value ok
class, struct → reference vagy pointer
```

### Reference (ez a leggyakoribb)

Ez hasonlít a C++ reference-re:

```
fn main() {
    let x = 5;
    let r = &x;

    println!("{}", r);
}
```

Ez:

- biztonságos
- nem lehet null
- nem lehet invalid

------

###  Mutable reference

Mint C++ reference:

```
fn main() {
    let mut x = 5;

    let r = &mut x;

    *r = 10;

    println!("{}", x);
}
```

------

##  Raw pointer (ez a C/C++ pointer megfelelője)

```
let x = 5;

let p = &x as *const i32;
```

vagy:

```
let mut x = 5;

let p = &mut x as *mut i32;
```

De használni csak **unsafe blockban lehet**:

```
unsafe {
    println!("{}", *p);
}
```

------

## Miért?

Mert Rust filozófia:

**Biztonság default → veszély explicit**

C++:

```
veszély default
biztonság extra munka
```

Rust:

```
biztonság default
veszély explicit unsafe
```

------

## Nagyon fontos különbség:

C++:

```
int *p = nullptr;   // ok
```

Rust safe reference:

```
let r: &i32;   // ❌ nincs inicializálva → hiba
```

Rust nem engedi:

- dangling pointer
- use after free
- double free
- null dereference (safe codeban)

------

## Rust pointer filozófia:

| C++        | Rust        |
| ---------- | ----------- |
| pointer    | raw pointer |
| reference  | reference   |
| unique_ptr | Box         |
| shared_ptr | Rc / Arc    |

------

## Röviden:

Igen van pointer, de:

```
C++ → pointer first
Rust → reference first
```

Rustban a pointer inkább **low level esetekre van**:

- OS
- driver
- game engine
- allocator
- FFI