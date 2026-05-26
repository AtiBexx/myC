# Macro

inkább inline vagy constexpr -t használj...

```
#include <cstdio>
#include<cstdlib>
#include<iostream>

//Beágyazott függvény
// kommenteld ki az első makrót a második aktiválásához;

#define SQUARE(x) x * x
#ifndef SQUARE
#define SQUARE(x) ((x) * (x))
#ifndef SQUARE
    inline int SQUARE(int x) {return x * x;}
#endif
#endif

int main (int argc , char *argv[]) {
    int nSQUARE = SQUARE(2);
    std::cout <<"A négyzet eredménye: " << nSQUARE << std::endl;
    
    //itt van egy hiba ami megoldható ha zárójelet használsz
    std::cout << "A következő rossz eredmény'SQUARE(1 + 2)': " << SQUARE(1 + 2) << std::endl;

    //itt van egy olyan hiba ami nem oldható meg
    int i = 3;
    std::cout << "i = " << i << std::endl;
    nSQUARE = SQUARE(i++);
    std::cout << "A négyzet eredménye( 'SQUARE(i++)' ): " << nSQUARE << std::endl;
    std::cout <<"Most az i eredménye: " << i << std::endl;

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg az enter-t! " << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}
```

**output**

```
A négyzet eredménye: 4
A következő rossz eredmény'SQUARE(1 + 2)': 5
i = 3
A négyzet eredménye( 'SQUARE(i++)' ): 12
Most az i eredménye: 5
A folytatáshoz kérlek nyomd meg az enter-t!
```

tt **klasszikus macro hiba** van, és nagyon jó példát találtál. Ez pontosan az a probléma amiért a `#define` macrokat óvatosan kell használni. 

## A fő hiba:

Ez a macro:

```
#define SQUARE(x) x * x
```

nem tesz zárójeleket, ezért az expression **nem úgy értékelődik ki**, ahogy várnád.

------

##  Miért lett 5 a `SQUARE(1 + 2)` ?

A macro behelyettesítés:

```
SQUARE(1 + 2)
```

preprocessor után:

```
1 + 2 * 1 + 2
```

nem:

```
(1+2)*(1+2)
```

Hanem a precedence miatt:

```
1 + (2*1) + 2 = 5
```

Ezért lett **5**.

------

## Javítás:

```
#define SQUARE(x) ((x) * (x))
```

akkor:

```
((1+2)*(1+2)) = 9
```

------

##  Miért lett 12 a `SQUARE(i++)` ?

Ez még veszélyesebb.

Macro:

```
SQUARE(i++)
```

helyettesítés:

```
i++ * i++
```

Mi történik:

i = 3

első i++ → 3 (i=4 lesz)
 második i++ → 4 (i=5 lesz)

szorzás:

```
3 * 4 = 12
```

Ezért:

- eredmény = 12
- i = 5

Ez **undefined behavior közeli veszélyes macro használat**.

------

## Ezért mondják:

**NE használj macrokat matematikai függvényekhez.**

Hanem:

```
inline int square(int x) {
    return x * x;
}
```

Ez:

```
square(i++)
```

csak egyszer növeli:

i = 3

```
square(3)
```

eredmény:

```
9
```

i utána:

```
4
```

------

## Van még egy bug a kódodban:

Ez hibás nesting:

```
#ifndef SQUARE
#define SQUARE(x) ((x) * (x))
#ifndef SQUARE
inline int SQUARE(int x) {return x * x;}
#endif
#endif
```

A második `#ifndef` sose fut.

Helyes:

```
#ifndef SQUARE
#define SQUARE(x) ((x) * (x))
#endif
```

vagy:

```
inline int square(int x){
    return x*x;
}
```

------

## Profi C++ szabály:

Modern C++:

**NE macro**
 **HASZNÁLJ inline függvényt**

Macro = C korszak
 Inline = modern C++

```
#include <cstdio>
#include<cstdlib>
#include<iostream>

//Beágyazott függvény
// kommenteld ki az első makrót a második aktiválásához;

//#define SQUARE(x) x * x
#ifndef SQUARE
#define SQUARE(x) ((x) * (x))
#ifndef SQUARE
    inline int SQUARE(int x) {return x * x;}
#endif
#endif

int main (int argc , char *argv[]) {
    int nSQUARE = SQUARE(2);
    std::cout <<"A négyzet eredménye: " << nSQUARE << std::endl;
    
    //itt van egy hiba ami megoldható ha zárójelet használsz
    std::cout << "A következő rossz eredmény'SQUARE(1 + 2)': " << SQUARE(1 + 2) << std::endl;

    //itt van egy olyan hiba ami nem oldható meg
    int i = 3;
    std::cout << "i = " << i << std::endl;
    nSQUARE = SQUARE(i++);
    std::cout << "A négyzet eredménye( 'SQUARE(i++)' ): " << nSQUARE << std::endl;
    std::cout <<"Most az i eredménye: " << i << std::endl;

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg az enter-t! " << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}
```

**output**

```
A négyzet eredménye: 4
A következő rossz eredmény'SQUARE(1 + 2)': 9
i = 3
A négyzet eredménye( 'SQUARE(i++)' ): 12
Most az i eredménye: 5
A folytatáshoz kérlek nyomd meg az enter-t!
```

itt még mindig növelte az i++ -2szer és 5 lett hiba 

helyes verzió

```
#include <cstdio>
#include<cstdlib>
#include<iostream>

//Beágyazott függvény
// kommenteld ki az első makrót a második aktiválásához;

//#define SQUARE(x) x * x
//#ifndef SQUARE
//#define SQUARE(x) ((x) * (x))
#ifndef SQUARE
    inline int SQUARE(int x) {return x * x;}
#endif
//#endif

int main (int argc , char *argv[]) {
    int nSQUARE = SQUARE(2);
    std::cout <<"A négyzet eredménye: " << nSQUARE << std::endl;
    
    //itt van egy hiba ami megoldható ha zárójelet használsz
    std::cout << "A következő rossz eredmény'SQUARE(1 + 2)': " << SQUARE(1 + 2) << std::endl;

    //itt van egy olyan hiba ami nem oldható meg
    int i = 3;
    std::cout << "i = " << i << std::endl;
    nSQUARE = SQUARE(i++);
    std::cout << "A négyzet eredménye( 'SQUARE(i++)' ): " << nSQUARE << std::endl;
    std::cout <<"Most az i eredménye: " << i << std::endl;

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg az enter-t! " << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}
```

**output**

```
A négyzet eredménye: 4
A következő rossz eredmény'SQUARE(1 + 2)': 9
i = 3
A négyzet eredménye( 'SQUARE(i++)' ): 9
Most az i eredménye: 4
A folytatáshoz kérlek nyomd meg az enter-t!
```

na most a jó az i++ csak egyszer növelte

## Nagyon fontos szabály C++-ban:

**Macro argumentumot soha ne adj meg side effect-tel.**

Side effect:

- i++
- ++i
- function()
- assignment

------

## Profi szabály:

Ha ezt látod:

```
#define SQUARE(x)
```

- -> red flag 

Modern C++:

```
inline int square(int x)
```

vagy még jobb:

```
constexpr int square(int x){
    return x*x;
}
```

Ez compile time is működik.

## Amit most csináltál az már **helyes modern megoldás**.

Ha még profibb akarsz lenni:

```
constexpr int square(const int x) noexcept {
    return x * x;
}
```

Ez:

- constexpr → compile time
- const → nem módosul
- noexcept → nem dob exception
- inline implicit

Ez már production style.

#### c ben a megoldás

## Biztonságos macro (klasszikus C megoldás)

Így:

```
#define SQUARE(x) ((x) * (x))
```

De így **sem szabad**:

```
SQUARE(i++)
```

C szabály:
 → macro paraméter legyen **pure expression**

Jó:

```
SQUARE(i)
SQUARE(a+1)
```

Rossz:

```
SQUARE(i++)
SQUARE(f())
```

------

##  Static inline függvény (modern C megoldás)

C99 óta:

```
static inline int square(int x){
    return x * x;
}
```

Ez már ugyanaz mint C++ inline.

Ez a **legjobb C megoldás**.

Miért static:

- linker konfliktus elkerülése
- headerben használható

Ez production C kód.

------

##  Macro + temp variable (profi C hack)

GNU extension:

```
#define SQUARE(x) ({ \
    int _tmp = (x); \
    _tmp * _tmp; \
})
```

Ez megoldja a dupla kiértékelést.

De:

- nem standard C
- csak GCC/Clang

Linux kernel ezt használja sok helyen.

## Hogyan csinálják a profik C-ben?

Általában:

```
static inline int square(int x){
    return x*x;
}
```

## Probléma:

C-ben nincs ilyen:

```
template<typename T>
T square(T x){
    return x*x;
}
```

Ez C++ only.

------

## C megoldás: macro generál függvényt

Példa:

```
#define DEFINE_SQUARE(type) \
type square_##type(type x){ \
    return x*x; \
}
```

Használat:

```
DEFINE_SQUARE(int)
DEFINE_SQUARE(float)
DEFINE_SQUARE(double)
```

Ez generál:

```
int square_int(int x){
    return x*x;
}

float square_float(float x){
    return x*x;
}

double square_double(double x){
    return x*x;
}
```

Ez **C template hack**.

------

## Még durvább verzió (generic call):

```
#define square(x) _Generic((x), \
    int: square_int, \
    float: square_float, \
    double: square_double \
)(x)
```

Ez C11 feature.

Most:

```
square(5)      // int version
square(5.5f)   // float version
square(5.5)    // double version
```

Ez már majdnem C++ template.

------

## Linux kernel style macro (nagyon durva):

```
#define max(a,b) ({ \
    typeof(a) _a = (a); \
    typeof(b) _b = (b); \
    _a > _b ? _a : _b; \
})
```

Ez:

- csak egyszer értékel
- típus safe
- macro gyors

Ez **profi C wizardry**.

------

## Miért érdekes ez?

Mert C++ template ezt **automatán csinálja**.

C++:

```
template<typename T>
T max(T a, T b){
    return a>b?a:b;
}
```

C-ben:
 macro + typeof + generic.

------

## 