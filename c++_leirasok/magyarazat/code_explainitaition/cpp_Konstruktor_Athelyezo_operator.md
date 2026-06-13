### Áthelyező Operátor

-------------

```cpp
//Áthelyező operátor
//-PÉLDAPROGRAM
//Szemlélteti az áthelyező Operátort
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cstring>


class EnTarolom
{
public:
EnTarolom(int nS, const char* pS) : nMeret(nS)
{
    mSztring = new char[nMeret];
    //strcpy(cel, forras); azaz Másol
    strcpy(mSztring, pS);
}
//Desktruktor
~EnTarolom()
{
    delete[] mSztring;
    mSztring = nullptr;
}
//Másoló konstruktor
EnTarolom(const EnTarolom &s)
{
    masolas(*this, s);
}
EnTarolom& operator=(EnTarolom& s)
{
    delete[] mSztring;
    masolas(*this, s);
    return *this;
}
//áthelyező konstruktor
EnTarolom(EnTarolom&& s)
{
    athelyezes(*this, s);
}
EnTarolom& operator=(EnTarolom&& s)
{
    delete[] mSztring;
    athelyezes(*this, s);
    return *this;
}

protected:
    static void athelyezes(EnTarolom& cel, EnTarolom& forras)
    {
        std::cout<< forras.mSztring << " áthelyezése: " << '\n';
        cel.nMeret = forras.nMeret;
        cel.mSztring = forras.mSztring;

        forras.nMeret = 0;
        forras.mSztring = nullptr;
    }
    static void masolas(EnTarolom& cel,const EnTarolom& forras)
    {
        std::cout<< forras.mSztring << " másolása: " << '\n';
        delete[] cel.mSztring;
        cel.nMeret = forras.nMeret;
        cel.mSztring = forras.mSztring;

        cel.mSztring = new char[cel.nMeret];
        strncpy(cel.mSztring, forras.mSztring, cel.nMeret);
    }
    int nMeret;
    char* mSztring;
};
EnTarolom fv(int n, const char* mSztring)
{
    EnTarolom b(n, mSztring);
    return b;
}
int main(int argc, char** argv)
{
    //stack
    EnTarolom et(100, "Eredeti");
    et = fv(100, "Létrehozva az fv()-ben");
    //kilépünk
    std::cout<<"A folytatáshoz kérlek nyomd meg az ENTERT...... Kétszer"<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();
    return 0;
}

```

Jó kérdés! Nézzük meg pontosan:

## Mi hol jön létre?

```cpp
int main() {
    EnTarolom et(100, "Eredeti");  // ← ez a STACK-en van
```

Az `et` objektum **maga** (tehát az `nMeret` és a `mSztring` pointer) a **stack**-en van.

**DE!** A `mSztring` pointer által mutatott **szöveg tartalma** a **heap**-en van:

```cpp
mSztring = new char[nMeret];  // ← ez a new kulcsszó heap-re foglal!
```

------

## Vizuálisan:

```
STACK                    HEAP
──────────────────       ──────────────────
et.nMeret = 100          [O][r][i][g][i][n][á][l][i][s][\0]
et.mSztring ──────────────────────────────────────^
```

Tehát:

- Az **objektum váza** (a két változó) → **stack**
- A **tényleges szöveg** (`new` miatt) → **heap**

------

## Az `fv()` függvényben:

```cpp
EnTarolom fv(int n, const char* mSztring) {
    EnTarolom b(n, mSztring);  // b váza → stack, szöveg → heap
    return b;                   // visszaadáskor az áthelyező lép életbe
}
```

Az `fv()`-ben létrejövő `b` objektum váza is stack-en van, de amikor a függvény visszatér, a stack-en lévő `b` **megszűnik** – ezért kell az áthelyezés, hogy a heap-en lévő szöveget **megmentsük** és átadjuk `et`-nek!

------

## Röviden:

| Mit?                        | Hol?                                |
| --------------------------- | ----------------------------------- |
| `et` objektum váza          | Stack                               |
| `"Eredeti"` szöveg tartalma | Heap (`new` miatt)                  |
| `fv()`-ben `b` váza         | Stack (de megszűnik!)               |
| `"Létrehozva..."` szöveg    | Heap (ezt menti meg az áthelyezés!) |

# C++ Áthelyező Operátor – Részletes Magyarázat

## Mi ez a program?

Ez a program azt szemlélteti, hogy C++-ban hogyan lehet **hatékonyan** kezelni a memóriát, amikor objektumokat másolunk vagy "áthelyezünk".

------

## Az alapgondolat – miért kell ez?

Képzeld el, hogy van egy dobozod, amiben egy papír van. Ha **másolod** → csinálsz egy új dobozt és lemásolod a papírt. Ha **áthelyezed** → kiveszed a papírt az eredeti dobozból és beteszed az újba. Az eredeti doboz üres lesz. Az áthelyezés **gyorsabb**, mert nem kell másolni!

------

## A `&&` jel – az "RValue referencia"

```cpp
EnTarolom(EnTarolom&& s)   // && = "áthelyező"
EnTarolom(const EnTarolom& s)  // & = "másoló"
```

| Jel  | Neve              | Mit jelent?                                 |
| ---- | ----------------- | ------------------------------------------- |
| `&`  | LValue referencia | Egy **létező, névvel bíró** változóra mutat |
| `&&` | RValue referencia | Egy **ideiglenes, eldobható** dologra mutat |

### Példa érthetően:

```cpp
EnTarolom a(100, "Hello");   // 'a' létező változó → & (LValue)
fv(100, "Hello")             // fv() visszatérési értéke ideiglenes → && (RValue)
```

Amikor a függvény visszaad valamit, az egy **pillanatra létező, ideiglenes érték**. Ezt másolás helyett **át lehet venni** (lopni) – ez az áthelyezés lényege!

------

## Az osztály felépítése

```cpp
class EnTarolom {
    int nMeret;      // a szöveg mérete
    char* mSztring;  // pointer a memóriában lévő szövegre
```

A `char* mSztring` nem maga a szöveg, hanem egy **cím**, ami megmutatja, hol van a szöveg a memóriában (heap-en).

------

## A konstruktor és destruktor

```cpp
// KONSTRUKTOR – létrehozáskor fut le
EnTarolom(int nS, const char* pS) : nMeret(nS) {
    mSztring = new char[nMeret];  // memóriát foglal a heap-en
    strcpy(mSztring, pS);         // bemásolja a szöveget
}

// DESTRUKTOR – megsemmisítéskor fut le
~EnTarolom() {
    delete[] mSztring;    // felszabadítja a memóriát
    mSztring = nullptr;   // nullra állítja a pointert (biztonság)
}
```

------

## A másoló függvény (`masolas`)

```cpp
static void masolas(EnTarolom& cel, const EnTarolom& forras) {
    delete[] cel.mSztring;              // törli a cél régi tartalmát
    cel.nMeret = forras.nMeret;         // átmásolja a méretet
    cel.mSztring = new char[cel.nMeret]; // ÚJ memóriát foglal
    strncpy(cel.mSztring, forras.mSztring, cel.nMeret); // átmásolja a szöveget
}
```

**Eredmény:** Két külön memóriaterület, ugyanazzal a tartalommal.

```
forras: [memória A] → "Hello"
cel:    [memória B] → "Hello"   ← új, független másolat
```

------

## Az áthelyező függvény (`athelyezes`)

```cpp
static void athelyezes(EnTarolom& cel, EnTarolom& forras) {
    cel.nMeret = forras.nMeret;    // átmásolja a méretet
    cel.mSztring = forras.mSztring; // UGYANARRA a memóriára mutat!
    forras.nMeret = 0;
    forras.mSztring = nullptr;     // a forrás "lemond" a memóriáról
}
```

**Eredmény:** Nem másolunk semmit, csak "átadjuk" a memória címét!

```
forras: [nullptr]  ← kiürült
cel:    [memória A] → "Hello"  ← átvette a tulajdonjogot
```

Ez sokkal gyorsabb, főleg nagy adatoknál!

------

## A négy speciális függvény összehasonlítva

```cpp
// 1. Másoló konstruktor – amikor létrehozáskor másolunk
EnTarolom b = a;               // meghívódik: EnTarolom(const EnTarolom& s)

// 2. Másoló értékadó operátor – amikor már létező objektumba másolunk
b = a;                         // meghívódik: operator=(EnTarolom& s)

// 3. Áthelyező konstruktor – létrehozáskor ideiglenest veszünk át
EnTarolom b = fv(100, "Hi");   // meghívódik: EnTarolom(EnTarolom&& s)

// 4. Áthelyező értékadó operátor – már létező objektumba helyezünk át
b = fv(100, "Hi");             // meghívódik: operator=(EnTarolom&& s)
```

------

## A `main` – lépésről lépésre

```cpp
EnTarolom et(100, "Eredeti");
```

1. Lefoglal 100 byte-ot a heap-en
2. Bemásolja: `"Eredeti"`

```cpp
et = fv(100, "Létrehozva az fv()-ben");
```

1. `fv()` létrehoz egy **ideiglenes** `EnTarolom` objektumot `"Létrehozva az fv()-ben"` tartalommal
2. Visszaadja → ez egy **RValue** (`&&`)
3. Meghívódik az **áthelyező** `operator=`
4. `et` átveszi az ideiglenes memóriáját
5. Az ideiglenes objektum `nullptr`-re áll, majd megsemmisül

------

## Összefoglalás egy mondatban

> A `&&` (move szemantika) lényege: ha egy **ideiglenes, eldobandó** objektum memóriájára van szükségünk, ne másoljuk le – **vegyük el** tőle, hiszen úgyis megszűnik!

Igen, Ati, a

```cpp
EnTarolom(EnTarolom&& s)
```

és

```cpp
EnTarolom& operator=(EnTarolom&& s)
```

részben a `&&` jelenti, hogy **rvalue referencia**, és ezt használja a C++ az **áthelyezéshez (move)**.

Egyszerűen:

```cpp
EnTarolom a(100, "Hello");
EnTarolom b(std::move(a));
```

Itt a `b` nem lemásolja `a` tartalmát, hanem átveszi a memóriát. Ez az áthelyező konstruktor tipikus esete.

------

A kódod most már sokkal jobb, de még lenne néhány javítás.

### 1. A konstruktorban érdemes +1 helyet foglalni

Most:

```cpp
mSztring = new char[nMeret];
```

Mivel a C-string végén van egy `'\0'`, általában:

```cpp
mSztring = new char[nMeret + 1];
```

biztonságosabb.

------

### 2. A másoló függvényben ez a sor felesleges

Most:

```cpp
cel.mSztring = forras.mSztring;
```

Utána rögtön ezt csinálod:

```cpp
cel.mSztring = new char[cel.nMeret];
```

Tehát az első értékadás elveszik. Ezt nyugodtan törölheted.

------

### 3. A másoló operátor legyen const-os

Most:

```cpp
EnTarolom& operator=(EnTarolom& s)
```

Jobb:

```cpp
EnTarolom& operator=(const EnTarolom& s)
```

Mert a másolás nem módosítja a forrást.

------

### 4. Önhozzárendelés ellenőrzése

Például:

```cpp
if (this == &s)
    return *this;
```

Ez megakadályozza az olyan problémákat, mint:

```cpp
et = et;
```

------

### 5. A move operátorban is hasznos

```cpp
if (this == &s)
    return *this;
```

bár ritkábban fordul elő.

------

Összességében:

- A `&&` valóban az áthelyező (move) konstruktor és move operátor alapja.
- A legnagyobb hibát (a `masolas` helyett `athelyezes`) már kijavítottad.
- A kód oktatási példának már egész jól mutatja a copy és move közti különbséget.
- Production kódban ma inkább `std::string`-et használnánk nyers `char*` helyett, de tanulásra ez a példa hasznos.

## Az `operator=` – az értékadó operátor

Alapból a C++-ban az `=` jel egy beépített operátor. De ha az osztályodban **saját memóriát kezelsz** (mint itt a `new`), felül kell írnod, mert különben baj lesz!

------

## Mi történne felülírás nélkül?

```cpp
EnTarolom et(100, "Eredeti");
EnTarolom b(100, "Másik");
et = b;  // ← az alapértelmezett = csak a pointert másolja!
et.mSztring ──────────────► "Másik"  ← mindkettő ugyanoda mutat!
b.mSztring  ──────────────►
                            "Eredeti" ← ez elveszett, memóriaszivárgás!
```

Ez a **shallow copy** probléma – csak a cím másolódik, nem a tartalom!

------

## Ezért írjuk felül:

```cpp
EnTarolom& operator=(EnTarolom& s)  // másoló verzió (& = létező változó)
{
    delete[] mSztring;   // ← törli a RÉGI tartalmat (hogy ne szivárogjon!)
    masolas(*this, s);   // ← deep copy, új memóriát foglal
    return *this;        // ← visszaadja saját magát (hogy a = láncolható legyen)
}

EnTarolom& operator=(EnTarolom&& s)  // áthelyező verzió (&& = ideiglenes)
{
    delete[] mSztring;    // ← törli a régi tartalmat
    athelyezes(*this, s); // ← átveszi a memória tulajdonjogát
    return *this;
}
```

------

## A `return *this` miért kell?

Hogy ez működjön:

```cpp
a = b = c;  // láncolás
```

Ha nem adnád vissza `*this`-t, az `a =` résznek nem lenne mit értékül adni.

------

## Összefoglalva:

| Helyzet        | Melyik hívódik meg?          |
| -------------- | ---------------------------- |
| `et = b`       | másoló `operator=` (`&`)     |
| `et = fv(...)` | áthelyező `operator=` (`&&`) |

Az `operator=` lényege: **te mondod meg a C++-nak, mit jelentsen az `=` jel a saját osztályodnál!**

Igen, jó megfigyelés! De pontosítsuk egy kicsit:

------

## Procedurális vs OOP memóriakezelés

A procedurális programozásban **mindkettőt használják**, de valóban a `&` referencia **egyszerűbb és biztonságosabb**:

```cpp
// PROCEDURÁLIS stílus – inkább így:
void megvaltoztat(int& szam) {  // & referencia
    szam = 10;
}

// Ritkábban így (pointer):
void megvaltoztat(int* szam) {  // * pointer
    *szam = 10;
}
```

------

## Mi a különbség?

|                          | Referencia `&` | Pointer `*` |
| ------------------------ | -------------- | ----------- |
| Lehet `nullptr`?         | ❌ Nem          | ✅ Igen      |
| Kell `*` a használathoz? | ❌ Nem          | ✅ Igen      |
| Átirányítható másra?     | ❌ Nem          | ✅ Igen      |
| Biztonságosabb?          | ✅ Igen         | ❌ Kevésbé   |

------

## Akkor miért kell mégis pointer az OOP-ban?

Mert a **heap-en** csak pointerrel tudsz foglalni memóriát:

```cpp
// Ezt csak pointerrel lehet:
mSztring = new char[100];  // heap foglalás → pointer kell!

// Referenciával NEM lehet heap-et foglalni:
char& valami = new char[100];  // ← ez NEM működik!
```

------

## Röviden:

- **Procedurális** → inkább `&` referencia, egyszerűbb, biztonságosabb
- **OOP + dinamikus memória** → pointer kell, mert `new`/`delete` csak pointerrel működik

https://github.com/AtiBexx/learningLanguagesCLI/blob/main/src/CreateVocab/createVocab.cpp

Beengedett! Lássuk a kódodat elemezve:

------

## A te kódod – mit csinálsz és hogyan

### Referencia használat a te kódodban

```cpp
void listFlat(const std::string& root)
//                               ^ const referencia – nem másolja a stringet
FileCreationAction handleFileCreationInput(const std::string& input)
int handleInput(const std::string& input, std::ofstream& file, bool allowEmpty)
//                                                             ^ sima referencia
//                                                               mert írni kell bele!
```

Szépen csinálod – `const &` ha csak olvasol, sima `&` ha módosítasz (pl. `outFile`-ba írsz).

------

### A fájlkezelés

```cpp
std::ofstream outFile(fullPath, mode);  // fájl megnyitás
outFile << trim(...) << " -> " << ...;  // írás bele
outFile.close();                         // bezárás
```

Ez tiszta stack alapú – **nincs `new`**, az `ofstream` destruktora automatikusan lezárja a fájlt ha elfelejtened `.close()`-t hívni.

------

### A struktúrák

```cpp
WordPair currentWords;
currentWords.targetLangMeaning = ...;
currentWords.motherLangMeaning = ...;
```

Egyszerű stack-en lévő struktúra, pointer nélkül – teljesen helyes modern C++ stílus.

------

### Amit jól csinálsz

| Dolog                                     | Miért jó                    |
| ----------------------------------------- | --------------------------- |
| `const std::string&` paraméterek          | Hatékony, nem másol         |
| `std::ofstream` stack-en                  | Automatikus cleanup         |
| `std::string` és `std::vector`            | Belül kezelik a memóriát    |
| Nincs `new`/`delete`                      | Nem kell, a std lib elég    |
| `trim()`, `toLowerCase()` segédfüggvények | Tiszta, újrahasználható kód |

Összességében **modern, tiszta C++ kód** – pontosan úgy használod a referenciákat ahogy kell, és helyesen kerülöd a szükségtelen pointert!

A fa struktúrát nem enged be, de a blob linkeket igen – soroljuk fel amit az előző olvasásból láttam, és próbálom meg egyenként a fájlokat!A keresés nem hozta fel a te repód fájljait. Próbálom direktben a többi ismert fájlt:A trükk az, hogy a `/blob/main/` URL-eket beengedi! Próbálom a többi fájlt így. Az első `.cpp`-ből látom, hogy az include-ok alapján ezek a fájlok léteznek – próbálom egyenként:Nagyon jó, a `code_explanation.md` tartalmazza a fő fájlokat! Most már átfogó képem van az egész projektről. Összefoglalom:

------

## Az egész projekt áttekintése

### Architektúra – hogyan épül fel

```
main.cpp
  └─► mainMenu()
        ├─► listAndSelectFile() → programQuiz()   (kvíz)
        ├─► mistakeExercise()                      (hibás szavak gyakorlása)
        ├─► createVocab()                          (új szólista készítés)
        ├─► settings()                             (beállítások)
        └─► openFileInEditor()                     (szerkesztő)
```

------

### Amit jól csinálsz

**Globális állapot kezelés** – szépen elkülönítve:

```cpp
Language programUiLanguage = Language::HUNGARIAN;
Language motherLanguage    = Language::HUNGARIAN;
Language targetLanguage    = Language::ENGLISH;
```

**Cross-platform kezelés** mindenhol következetesen:

```cpp
#ifdef _WIN32
    std::system("mkdir ...");
#else
    std::system("mkdir -p ...");
#endif
```

**Fordítási rendszer** – `getTranslation()` alapú, nem hard-coded szövegek – ez nagyon profi megközelítés.

**Hibanaplózás** – `logError()` és `logMistakeWriteFile()` külön fájlba ment, időbélyeggel.

**String normalizálás** – `cleanString()` hármas lépésben: trim → kisbetű → írásjel → ékezet eltávolítás, opcionálisan.

------

### Egy-két dolog amit érdemes megjegyezni

**A `static` map az `removeAccents()`-ben** – okos megoldás:

```cpp
static const std::map<std::string, std::string> accentMap = { ... };
```

A `static` itt azt jelenti, hogy csak egyszer épül fel, nem minden híváskor – ez hatékony!

**Az `error.log ` fájlnévben van egy szóköz!**

```cpp
std::ofstream logFile("error.log ", std::ios::app);  // ← "error.log " – szóköz van a végén!
```

Ez valószínűleg véletlen, és Windows-on furcsa nevű fájlt hoz létre.

------

### Összefoglalva

Ez egy jól strukturált, moduláris C++ projekt. Helyesen használod a referenciákat, nincs felesleges pointer, a cross-platform támogatás tudatos, és a fordítási rendszer is komoly. Örülök hogy beengedett!

Pontosan! Jól látod a lényeget.

A nyelvi fájlok tartalma `std::string`-ekben és `std::vector`-okban él, amik **maguk kezelik a heap-et** a háttérben – te nem látod, nem kell vele foglalkoznod.

```cpp
// Ez mind stack-en van "látszólag"...
Language programUiLanguage = Language::HUNGARIAN;  // egy enum = egyetlen int
std::string translation = getTranslation("menu.start");  // belül heap, de te nem látod
```

------

## Mikor kellene mégis pointer ebben a projektben?

Csak akkor, ha valami ilyesmi kellene:

**1. Nagyon nagy adatmennyiség**, amit futás közben dinamikusan kell bővíteni – de a `std::vector` ezt már megoldja pointer nélkül.

**2. Polimorfizmus** – ha például különböző kvíztípusokból egy közös alaposztályból akarnál létrehozni objektumokat futás közben:

```cpp
Quiz* q = new MultipleChoiceQuiz();  // ekkor kellene pointer
```

**3. Opcionális objektum** – ha valaminek vagy van értéke vagy nincs. De erre ma már van `std::optional<T>` pointer helyett.

------

## Röviden a te projektedre:

A te programod **tökéletesen megvan pointer nélkül**, mert:

- Az adatok mérete előre nagyjából ismert
- Nincs öröklési hierarchia ahol polimorfizmus kellene
- A `std::string` és `std::vector` elvégzik a nehéz munkát

Ez egyébként **modern C++ szemlélet** – csak akkor használj pointert, ha tényleg muszáj!

### Vissza a példára:

------------

```cpp
//Áthelyező operátor
//-PÉLDAPROGRAM
//Szemlélteti az áthelyező Operátort
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cstring>


class EnTarolom
{
public:
EnTarolom(int nS, const char* pS) : nMeret(nS)
{
    mSztring = new char[nMeret];
    //strcpy(cel, forras); azaz Másol
    strcpy(mSztring, pS);
}
//Desktruktor
~EnTarolom()
{
    delete[] mSztring;
    mSztring = nullptr;
}
//Másoló konstruktor
EnTarolom(const EnTarolom &s)
{
    masolas(*this, s);
}
EnTarolom& operator=(EnTarolom& s)
{
    //önEllenőrzés
    if(this==&s) return *this;

    delete[] mSztring;
    masolas(*this, s);

    return *this;
}
//áthelyező konstruktor
EnTarolom(EnTarolom&& s)
{
    athelyezes(*this, s);
}
EnTarolom& operator=(EnTarolom&& s)
{
    //önEllenőrzés
    if(this==&s) return *this;

    delete[] mSztring;
    athelyezes(*this, s);

    return *this;
}

protected:
    static void athelyezes(EnTarolom& cel, EnTarolom& forras)
    {
        std::cout<< forras.mSztring << " áthelyezése: " << '\n';
        cel.nMeret = forras.nMeret;
        cel.mSztring = forras.mSztring;

        forras.nMeret = 0;
        forras.mSztring = nullptr;
    }
    static void masolas(EnTarolom& cel,const EnTarolom& forras)
    {
        std::cout<< forras.mSztring << " másolása: " << '\n';
        delete[] cel.mSztring;
        cel.nMeret = forras.nMeret;
        cel.mSztring = forras.mSztring;

        cel.mSztring = new char[cel.nMeret];
        strncpy(cel.mSztring, forras.mSztring, cel.nMeret);
    }
    int nMeret;
    char* mSztring;
};
EnTarolom fv(int n, const char* mSztring)
{
    EnTarolom b(n, mSztring);
    return b;
}
int main(int argc, char** argv)
{
    //stack
    
    EnTarolom et(100, "Eredeti");
    et = fv(100, "Létrehozva az fv()-ben");
    //kilépünk
    std::cout<<"A folytatáshoz kérlek nyomd meg az ENTERT...... Kétszer"<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();
    return 0;
}

```

Jó kérdések, de néhányat pontosítsunk!

------

## 1. Stack vs Heap – hogyan kerül oda?

```cpp
EnTarolom et(100, "Eredeti");
STACK                    HEAP
─────────────────        ──────────────────
et.nMeret = 100          [E][r][e][d][e][t][i][\0]
et.mSztring ─────────────────────────────────^
```

Az **objektum váza** (nMeret + mSztring pointer) → **stack** A **tényleges adat** (`new char[100]`) → **heap**

Tehát nem "a heap-re kerül majd a stackre" – a kettő **egyszerre, párhuzamosan** él. A stack tárolja a pointert, a heap tárolja amit a pointer mutat.

------

## 2. A `protected` és a konstruktor

Nem a névről van szó! A `protected` azt jelenti:

```cpp
protected:
    static void athelyezes(...) { }  // ← csak az osztály és leszármazottai látják
    static void masolas(...) { }
    int nMeret;
    char* mSztring;
```

A konstruktorból azért hívhatjuk, mert a konstruktor **az osztályon belül van**, tehát látja a `protected` tagokat:

```cpp
EnTarolom(const EnTarolom &s)  // ← ez az osztályon belül van
{
    masolas(*this, s);  // ← ezért eléri a protected masolas()-t
}
```

Nem "más névre felülírás" történik – egyszerűen belülről hívja saját védett függvényét.

------

## 3. A `#include <cstring>` és `strncpy`

Az `strncpy` **nem összefűzés** – az összefűzés `strcat` lenne! Az `strncpy` **másol**:

```cpp
strncpy(cel.mSztring, forras.mSztring, cel.nMeret);
// strncpy(hova,        honnan,          max hány bájt)
```

| Függvény  | Mit csinál                                    |
| --------- | --------------------------------------------- |
| `strcpy`  | másol, de nem ellenőrzi a méretet → veszélyes |
| `strncpy` | másol, de max N karaktert → biztonságosabb    |
| `strcat`  | összefűz                                      |
| `strlen`  | hosszt mér                                    |

------

## 4. A `const EnTarolom` – egyszer lefut?

```cpp
static void masolas(EnTarolom& cel, const EnTarolom& forras)
//                                  ^^^^^
```

A `const` itt nem azt jelenti hogy "egyszer fut le" – azt jelenti hogy a `forras` objektumot **nem fogja módosítani** a függvény. Tehát olvasás-only. Többször is meghívható, csak mindig csak olvashat a forrásból.

Az áthelyezőnél nincs `const`, mert ott **módosítja** a forrást (nullázza):

```cpp
static void athelyezes(EnTarolom& cel, EnTarolom& forras)
//                                     ^ nincs const, mert forras.mSztring = nullptr lesz!
```



# FONTOS

### : **"Rule of Three / Five"** – amikor saját memóriát kezelsz, fel kell írni:

- Destruktor
- Másoló konstruktor
- Másoló `operator=`
- *(+ move konstruktor és move operator= → ez a Rule of Five)*