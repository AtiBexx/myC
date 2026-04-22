# Typedef

A `typdef` kulcszsóval röviditett változóNeveket hozhatunk létre pl:

```
typedef int* IntMut;
typedef const IntMut IntKonstMut;
int i;
int *const mut1 = &i;
IntKontMut mut2= mut1;
```

A kód részletei:

```c
typedef int* IntMut;                 // IntMut = int pointer
typedef const IntMut IntKonstMut;    // IntKonstMut = const int* pointer ??? <- itt fontos megérteni
int i;
int *const mut1 = &i;                // mut1 = konstans pointer int-re (pointer maga konstans, nem az int)
IntKonstMut mut2 = mut1;             // mut2 = ??? 
```

###  `typedef int* IntMut;`

- `IntMut` egy **int pointer** típust jelent.
- Tehát bárhol, ahol `IntMut`-ot írsz, az olyan, mintha `int*`-ot írnál.
- Például:

```c
IntMut p = &i;   // ugyanaz, mintha int* p = &i;
```

###  `typedef const IntMut IntKonstMut;`

- Itt jön a csavar. Mit jelent ez pontosan?
- **`IntMut` = `int\*`**, tehát `const IntMut` = `int* const`.
- Miért? Mert a `const` előtti typedef a teljes típust érinti, nem a mutatott értéket. Tehát:

```c
typedef const IntMut IntKonstMut;
// megfelel
typedef int* const IntKonstMut;  // pointer maga konstans
```

- **Fontos**: Ez NEM azt jelenti, hogy az int, amire mutatsz, const, hanem hogy maga a pointer konstans (nem lehet másik címre állítani).

###  `int *const mut1 = &i;`

- `mut1` egy **konstans pointer**, ami egy `int`-re mutat.
- Tehát:
  - A pointer **nem változtatható**: `mut1 = &j;` → **hibás**
  - A mutatott érték **módosítható**: `*mut1 = 5;` → OK

###  `IntKonstMut mut2 = mut1;`

- `IntKonstMut` = `int* const`
- `mut1` is `int* const`
- Tehát itt **konstans pointert adunk konstans pointernek**, rendben van.
- Ami történik: `mut2` most **ugyanarra az int-re mutató konstans pointer**, mint `mut1`.
- Ez azt jelenti, hogy:

```c
mut2 = &j;   //  nem lehet, a pointer konstans
*mut2 = 7;   //  lehet, mert a mutatott int módosítható
```

###  Összegzés:

- `IntMut` → sima `int*`
- `IntKonstMut` → konstans pointer `int* const`
- `mut1` és `mut2` → **konstans pointerek**, amik az `i` változóra mutatnak.
- Pointer címét **nem változtathatod**, de az int értékét módosíthatod.

Ha akarod, rajzolhatok egy kis ábrát, ami vizuálisan mutatja, hogy mi konstans és mi nem – nagyon sokat segít a typedef+const kombinációknál.

Akarod, hogy csináljak egy ilyet?

#### A lényeg

 **Alapjában a `typedef` csak egy típusnak ad új nevet**. Nem változó, nem memória, nem új típus (C-ben), csak egy **alias (becenév)**.

Egyszerű példa:

```
typedef int Szam;

Szam a = 5;   // ugyanaz mint: int a = 5;
```

Tehát:

- `Szam` → csak egy másik név az `int`-re
- Semmi extra nem történik a háttérben

### Pointer példával:

```
typedef int* IntPtr;

IntPtr p;   // ugyanaz mint: int* p;
```

### Miért hasznos?

3 fő oka van:

### 1️⃣ Olvashatóbb kód

```
typedef unsigned long long U64;

U64 number;
```

Jobban olvasható mint:

```
unsigned long long number;
```

### 2️⃣ Bonyolult típusok egyszerűsítése

Például function pointer:

```
typedef int (*FuncPtr)(int,int);

FuncPtr f;
```

Enélkül:

```
int (*f)(int,int);
```

### 3️⃣ Absztrakció (profi kódokban)

Pl:

```
typedef int FileHandle;
```

Később megváltoztathatod:

```
typedef void* FileHandle;
```

És a kód többi része nem változik.

### ⚠️ Amit sokan elrontanak (a te példád is ilyen)

Ez:

```
typedef int* IntMut;
```

nem ezt jelenti:

```
const int*   // NEM!
```

hanem ezt:

```
int* const   // mert a typedef egy egység
```

Ezért sok C programozó inkább ezt írja:

```
typedef int Int;
typedef Int* IntPtr;
```

mert kevésbé félrevezető.

### Röviden:

**typedef = típus becenév**

Mint:

```
typedef int Age;
typedef float Temperature;
typedef int* Pointer;
```

### Egy mondatban:

A `typedef` nem változót nevez át, hanem **egy típust nevez át**, hogy könnyebb legyen használni.

# struct egyszerűsítése (leggyakoribb)

Normálisan:

```
struct Person {
    int age;
};

struct Person p1;
```

typedef-fel:

```
typedef struct {
    int age;
} Person;

Person p1;
```

Mi történt?

- Nem kell mindig kiírni hogy `struct`
- Szebb lett a kód

Ez nagyon gyakori C-ben.

------

#  Pointer típus egyszerűsítés

Normálisan:

```
int *p1;
int *p2;
```

typedef-fel:

```
typedef int* IntPtr;

IntPtr p1;
IntPtr p2;
```

Viszont itt van egy **fontos csapda**:

Ez:

```
IntPtr p1, p2;
```

nem:

```
int *p1, *p2;
```

hanem:

```
int* p1;
int* p2;
```

Tehát typedef itt tényleg új típusnevet ad.

------

#  Function pointer (itt lesz igazán hasznos)

Ez typedef nélkül brutális:

```
int (*func)(int,int);
```

typedef-fel:

```
typedef int (*Func)(int,int);

Func func;
```

Ez sokkal olvashatóbb.

Példa használat:

```
int add(int a,int b)
{
    return a+b;
}

Func f = add;

printf("%d",f(2,3));
```

------

# Ezért használják igazán:

Nagy projekteknél:

```
typedef unsigned char byte;
typedef unsigned int uint;
typedef float f32;
typedef double f64;
```

Game engine-ekben pl:

```
typedef float f32;
typedef int i32;
typedef unsigned int u32;
```

------

#  Profi gondolkodás:

A typedef olyan mint:

```
typedef int Health;
typedef int Score;
```

Mindkettő int, de a név elmondja mire használod.

------

# Extra fontos amit kevesen értenek:

Ez NEM új típus C-ben:

```
typedef int Age;
typedef int Weight;
```

Ez működik:

```
Age a = 10;
Weight w = a;   // OK
```

C++-ban `using` már jobb erre.

------

# Brutál egyszerű definíció:

**typedef = típus rövidítés + olvashatóság**

------

# Ha igazán meg akarod érteni:

Ez a 4 typedef a 90%:

```
typedef struct {} StructName;
typedef int* Ptr;
typedef int (*Func)(int);
typedef unsigned int uint;
```

# Modern C++ (C++11 óta) → inkább `using`

Ugyanez modernebb formában:

```
using Number = int;

Number a = 10;
```

Ez ugyanaz mint a typedef, csak:

- olvashatóbb
- template-ekkel jobb
- modern C++ style

------

# Példa pointerrel:

typedef:

```
typedef int* IntPtr;

IntPtr p;
```

using:

```
using IntPtr = int*;

IntPtr p;
```

------

# Function pointer (itt látszik a különbség):

typedef:

```
typedef int (*Func)(int,int);
```

using:

```
using Func = int (*)(int,int);
```

------

# Ahol **using sokkal jobb** (template):

typedef:

```
typedef std::vector<int> IntVector;
```

using:

```
using IntVector = std::vector<int>;
```

------

# Template typedef (amit typedef nem tud jól):

Ez typedef-fel nehéz vagy lehetetlen:

```
template<typename T>
using Vec = std::vector<T>;

Vec<int> numbers;
Vec<float> floats;
```

Ezért modern C++-ban inkább `using`.

------

# Mikor melyik?

| Régi C style   | Modern C++ |
| -------------- | ---------- |
| typedef        | using      |
| működik        | működik    |
| régebbi kód    | új kód     |
| C kompatibilis | C++ style  |

------

# Valóság:

C++ kódokban mindkettőt látod mert:

- régi projektek → typedef
- modern projektek → using

------

# Egyszerű szabály:

Ha C++-t tanulsz:

**használj `using`-ot.**

Ha C vagy régi kód:

**typedef.**

------

# Brutál egyszerűen:

```
typedef int Age;   // régi
using Age = int;   // modern
```