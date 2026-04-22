# C++ Terminológia és Fogalmak Teljes Útmutató

## Tartalomjegyzék
1. [Deklaráció vs Inicializálás vs Típusmegadás](#deklaráció-vs-inicializálás-vs-típusmegadás)
2. [Kevert típusú kifejezések](#kevert-típusú-kifejezések)
3. [Túlcsordulás (Overflow) és Alulcsordulás (Underflow)](#túlcsordulás-overflow-és-alulcsordulás-underflow)
4. [Egyéb fontos fogalmak](#egyéb-fontos-fogalmak)
5. [Példák és kódrészletek](#példák-és-kódrészletek)

## Deklaráció vs Inicializálás vs Típusmegadás

### Deklaráció (Declaration)
A deklaráció egy változó nevét és típusát határozza meg, de nem feltétlenül foglal memóriát vagy ad értéket neki.

```cpp
int x;           // Deklaráció
extern int y;    // Külső deklaráció
void func();     // Függvény deklaráció
```

### Definíció (Definition)
A definíció valójában létrehozza a változót, memóriát foglal neki, és lehetővé teszi az értékadást.

```cpp
int x;           // Definíció (és deklaráció)
int x = 10;      // Definíció és inicializálás
```

### Inicializálás (Initialization)
Az inicializálás egy változó létrehozásakor történő első értékadás.

```cpp
int x = 5;              // Copy-initialization
int y(10);              // Direct-initialization
int z{15};              // Brace-initialization (C++11)
int arr[]{1, 2, 3};     // Aggregate initialization
```

### Típusmegadás (Type Specification)
A típusmegadás meghatározza, hogy milyen típusú adatot tárol egy változó.

```cpp
int count;              // int típus
double price = 19.99;   // double típus
char grade = 'A';       // char típus
bool isValid = true;    // bool típus
```

## Kevert típusú kifejezések

A kevert típusú kifejezések (mixed-type expressions) olyan kifejezések, amelyek különböző típusú operandusokat tartalmaznak.

### Implicit típuskonverzió (Type Promotion)
A C++ automatikusan konvertálja a kisebb típusokat nagyobb típusokká a műveletek során.

```cpp
int i = 5;
double d = 2.5;
double result = i + d;  // i automatikusan double típusúvá konvertálódik
// result = 7.5
```

### Típuskonverziós szabályok
- `bool` → `char` → `short int` → `int` → `long` → `long long`
- `int` → `float` → `double` → `long double`

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 10;
    float f = 3.14f;
    double d = 2.5;
    
    // Kevert típusú kifejezés
    auto result = i + f * d;  // int + float * double = double
    
    cout << "Eredmény: " << result << endl;  // 10 + 3.14 * 2.5 = 17.85
    return 0;
}
```

### Explicit típuskonverzió (Casting)
```cpp
int i = 10;
double d = static_cast<double>(i);  // Explicit konverzió

float f = 3.14f;
int truncated = static_cast<int>(f);  // 3 lesz

// Más típusú cast-ok
int x = (int)f;           // C-style cast
int y = int(f);          // Function-style cast
```

## Túlcsordulás (Overflow) és Alulcsordulás (Underflow)

### Túlcsordulás (Overflow)
A túlcsordulás akkor történik, amikor egy érték meghaladja a típus maximális értékét.

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    // Unsigned int túlcsordulás
    unsigned int max_uint = numeric_limits<unsigned int>::max();
    cout << "Max unsigned int: " << max_uint << endl;
    
    unsigned int overflow = max_uint + 1;
    cout << "Túlcsordulás után: " << overflow << endl;  // 0 lesz
    
    // Signed int túlcsordulás
    int max_int = numeric_limits<int>::max();
    cout << "Max int: " << max_int << endl;
    
    int signed_overflow = max_int + 1;
    cout << "Signed túlcsordulás: " << signed_overflow << endl;  // Negatív szám
    
    return 0;
}
```

### Alulcsordulás (Underflow)
Az alulcsordulás akkor történik, amikor egy érték az adott típus minimális értéke alá csökken.

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    // Unsigned int alulcsordulás
    unsigned int zero = 0;
    unsigned int underflow = zero - 1;
    cout << "Alulcsordulás: " << underflow << endl;  // Max érték lesz
    
    // Signed int alulcsordulás
    int min_int = numeric_limits<int>::min();
    cout << "Min int: " << min_int << endl;
    
    int signed_underflow = min_int - 1;
    cout << "Signed alulcsordulás: " << signed_underflow << endl;  // Pozitív szám
    
    return 0;
}
```

### Lebegőpontos túlcsordulás és alulcsordulás
```cpp
#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int main() {
    // Lebegőpontos túlcsordulás
    double large = numeric_limits<double>::max();
    double overflow = large * 2.0;
    cout << "Lebegőpontos túlcsordulás: " << overflow << endl;  // inf
    
    // Lebegőpontos alulcsordulás
    double small = numeric_limits<double>::min();
    double underflow = small / pow(10.0, 308);
    cout << "Lebegőpontos alulcsordulás: " << underflow << endl;  // 0 vagy denormal
    
    return 0;
}
```

## Egyéb fontos fogalmak

### Scope (Láthatósági tartomány)
A scope meghatározza, hogy egy változó hol látható és elérhető a programban.

```cpp
#include <iostream>
using namespace std;

int global_var = 10;  // Globális scope

int main() {
    int local_var = 20;  // Lokális scope
    
    {
        int block_var = 30;  // Blokk scope
        cout << global_var << ", " << local_var << ", " << block_var << endl;
    }
    // block_var itt már nem elérhető
    
    return 0;
}
```

### Lifetime (Élettartam)
A változó élettartama azt határozza meg, meddig létezik a program futása során.

```cpp
#include <iostream>
using namespace std;

void func() {
    static int static_var = 0;  // Statikus élettartam - csak egyszer inicializálódik
    int local_var = 0;          // Automatikus élettartam - minden hívásnál újra létrejön
    
    static_var++;
    local_var++;
    
    cout << "Static: " << static_var << ", Local: " << local_var << endl;
}

int main() {
    func();  // Static: 1, Local: 1
    func();  // Static: 2, Local: 1
    func();  // Static: 3, Local: 1
    return 0;
}
```

### Storage Class Specifiers (Tárolási osztály megadók)
- `auto`: Automatikus tárolás (alapértelmezett)
- `register`: Regiszter tárolás (javaslat a fordítónak)
- `static`: Statikus tárolás
- `extern`: Külső definíció
- `mutable`: Módosítható tagváltozó

```cpp
void example() {
    auto int a = 5;      // auto (implicit minden lokális változónál)
    register int b = 10; // regiszter változó
    static int c = 0;    // statikus változó
    extern int d;        // külső változó
}
```

### Const Correctness (Const helyesség)
A const kulcsszó segítségével megakadályozható a nem kívánt módosítás.

```cpp
const int x = 10;           // konstans érték
const int* ptr1 = &x;       // mutató konstans értékre
int* const ptr2 = &x;       // konstans mutató
const int* const ptr3 = &x; // konstans mutató konstans értékre

// Függvény paraméterek
void func(const int& param) {  // referencia nem módosítható
    // param nem módosítható itt
}
```

### Reference (Referencia)
A referencia egy alias egy meglévő változóra.

```cpp
int x = 10;
int& ref = x;  // ref az x aliasa

ref = 20;      // x értéke most 20
x = 30;        // ref értéke most 30

// Referencia paraméterek
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

### Pointer (Mutató)
A pointer egy memóriacímet tárol.

```cpp
int x = 10;
int* ptr = &x;    // ptr az x címét tárolja

int value = *ptr; // érték elérése a címről
*ptr = 20;        // érték módosítása a címen keresztül

// Pointer aritmetika
int arr[] = {1, 2, 3, 4, 5};
int* p = arr;     // pointer az első elemre
*(p + 2);         // a harmadik elem (3)
```

### Literal (Literál)
A literál egy fix értéket reprezentál a forráskódban.

```cpp
int decimal = 42;           // decimális literál
int octal = 052;            // oktális literál
int hex = 0x2A;             // hexadecimális literál
int binary = 0b101010;      // bináris literál (C++14)

float f = 3.14f;            // float literál
double d = 3.14;            // double literál
long double ld = 3.14L;     // long double literál

char c = 'A';               // karakter literál
const char* s = "Hello";    // string literál

bool b = true;              // bool literál
nullptr_t null_ptr = nullptr; // null pointer literál
```

## Példák és kódrészletek

### Teljes példaprogram a legfontosabb fogalmakkal
```cpp
#include <iostream>
#include <limits>
#include <typeinfo>
using namespace std;

// Globális változó
int global_counter = 0;

// Függvény prototípus (deklaráció)
void demonstrate_concepts();

int main() {
    cout << "=== C++ Terminológia Példák ===" << endl;
    
    // Inicializálás különböző formákban
    int copy_init = 42;           // Copy initialization
    int direct_init(42);          // Direct initialization  
    int brace_init{42};           // Brace initialization
    
    // Kevert típusú kifejezés
    int i = 10;
    double d = 3.5;
    auto mixed_result = i * d;    // double típusú lesz
    
    cout << "Kevert típusú kifejezés eredménye: " << mixed_result << endl;
    
    // Túlcsordulás demonstráció
    unsigned char max_byte = 255;
    unsigned char overflow_byte = max_byte + 1;
    cout << "Byte túlcsordulás: " << (int)overflow_byte << endl;  // 0
    
    // Const használata
    const int MAX_SIZE = 100;
    const double PI = 3.14159;
    
    // Referencia használata
    int original = 100;
    int& ref_to_original = original;
    ref_to_original = 200;  // original értéke is 200 lesz
    
    cout << "Referencia általi módosítás után: " << original << endl;
    
    // Pointer használata
    int* ptr_to_original = &original;
    *ptr_to_original = 300;  // original értéke is 300 lesz
    
    cout << "Pointer általi módosítás után: " << original << endl;
    
    // Függvényhívás
    demonstrate_concepts();
    
    return 0;
}

void demonstrate_concepts() {
    // Statikus változó - csak egyszer inicializálódik
    static int call_count = 0;
    call_count++;
    
    cout << "Ez a függvény " << call_count << ". alkalommal hívódik" << endl;
    
    // Blokk scope
    {
        int block_scoped = 42;
        cout << "Blokkon belüli változó: " << block_scoped << endl;
    }
    // block_scoped itt már nem elérhető
}
```

### További hasznos fogalmak

#### Type Inference (Típuskikövetkeztetés)
```cpp
auto x = 42;              // int
auto y = 3.14;            // double  
auto z = 42LL;            // long long
auto ch = 'x';            // char
auto flag = true;         // bool
auto str = std::string{}; // std::string
```

#### decltype
```cpp
int x = 42;
decltype(x) y = x;        // y típusa is int lesz

const int& rx = x;
decltype(rx) ry = x;      // ry típusa const int&
```

#### R-value és L-value
```cpp
int x = 42;               // x egy lvalue
int& lr = x;              // lvalue referenciája
// int& lr = 42;          // HIBA! nem lehet lvalue-ra referenciát hivatkozni rvalue-ről
int&& rr = 42;            // rvalue referenciája
```

#### Enumerations (Felsorolások)
```cpp
enum Color { RED, GREEN, BLUE };           // Régi stílus
enum class Direction { NORTH, SOUTH };     // Scoped enum (C++11)

Color c = RED;                             // Használat
Direction d = Direction::NORTH;           // Használat scoped enum-mal
```