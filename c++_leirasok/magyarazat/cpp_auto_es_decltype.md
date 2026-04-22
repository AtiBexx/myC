# C++ decltype() és auto Kulcsszó Teljes Útmutató

## Tartalomjegyzék
1. [Az auto kulcsszó](#az-auto-kulcsszó)
2. [A decltype() függvény](#a-decltype-függvény)
3. [auto és decltype() kombinálása](#auto-és-decltype-kombinálása)
4. [Gyakorlati alkalmazások](#gyakorlati-alkalmazások)
5. [Példák és kódrészletek](#példák-és-kódrészletek)

## Az auto kulcsszó

Az `auto` kulcsszóval a fordító automatikusan meghatározza a változó típusát az értékadás alapján. Ez a C++11-ben vezették be, és jelentősen megkönnyíti a kódolást, különösen összetett típusok esetén.

### Alapvető használat

```cpp
auto x = 42;              // x típusa: int
auto y = 3.14;            // y típusa: double
auto z = 42LL;            // z típusa: long long
auto c = 'A';             // c típusa: char
auto b = true;            // b típusa: bool
auto str = "Hello";       // str típusa: const char*
auto s = std::string("World"); // s típusa: std::string
```

### Összetett típusok egyszerűsítése

```cpp
#include <vector>
#include <map>
#include <string>

// Komplex típusok kezelése auto-val
std::vector<std::string> vec = {"apple", "banana", "cherry"};

// Hosszadalmas írás:
std::vector<std::string>::iterator it = vec.begin();

// auto használata:
auto it2 = vec.begin();

// Lambda kifejezések esetén:
auto lambda = [](int x, int y) { return x + y; };

// Map példa:
std::map<std::string, std::vector<int>> myMap;
// Hosszadalmas:
std::map<std::string, std::vector<int>>::iterator mapIt = myMap.begin();
// auto-val:
auto mapIt2 = myMap.begin();
```

### auto és konstansság

```cpp
int x = 42;
const int& rx = x;

auto a = rx;        // a típusa: int (a referencia eltávolítva)
auto& b = rx;       // b típusa: const int& (a referencia megmarad)
const auto c = rx;  // c típusa: const int
const auto& d = rx; // d típusa: const int&
```

### auto és pointerek

```cpp
int x = 42;
int* px = &x;

auto ptr1 = px;        // ptr1 típusa: int*
auto* ptr2 = px;       // ptr2 típusa: int*
auto ptr3 = *px;       // ptr3 típusa: int (érték, nem pointer)
```

## A decltype() függvény

A `decltype()` egy fordítási idejű operátor, amely visszaadja egy kifejezés típusát. A név az "declared type" rövidítése.

```c++
int nValtozo1;
decltype(nValtozo1) nValtozo2; //a valtozo2  típusmegadása a valtozo 1 megegyező típusával

```



### Alapvető használat

```cpp
int x = 42;
const int& rx = x;
int arr[10];

decltype(x) a = 10;        // a típusa: int
decltype(rx) b = x;        // b típusa: const int&
decltype(arr) c = {};      // c típusa: int[10] (nem működik közvetlenül, csak példaként)
decltype(x + 1) d = 43;    // d típusa: int
```

### decltype() viselkedése különböző kifejezések esetén

```cpp
struct Point {
    int x = 10;
};

Point p;
int arr[5] = {1, 2, 3, 4, 5};

// Változók esetén
decltype(p) p2;            // Point típusú változó
decltype(p.x) member = 5;  // int típusú változó

// Tömbök esetén
decltype(arr) arr2;        // int[5] típusú tömb

// Kifejezések esetén
int& func();               // függvény deklaráció
decltype(func()) ref = func();  // int& típusú referencia
```

### decltype(auto) - C++14

A `decltype(auto)` kombinálja az `auto` típuskikövetkeztetést a `decltype` szemantikájával.

```cpp
int x = 42;
int& getRef() { return x; }

// auto mindig értéket vesz fel
auto a = getRef();           // a típusa: int

// decltype(auto) megtartja a pontos típust
decltype(auto) b = getRef(); // b típusa: int&
decltype(auto) c = x;        // c típusa: int
decltype(auto) d = (x);      // d típusa: int& (zárójel fontos!)
```

## auto és decltype() kombinálása

A két eszköz gyakran együtt használható, különösen sablonokban és haladó típuskikövetkeztetési esetekben.

### decltype() és auto együttműködése

```cpp
template<typename Container>
void example(Container& c) {
    // decltype(c[0]) meghatározza a konténer elemeinek típusát
    decltype(c[0]) element = c[0];  // például int& vagy const int&
    
    // auto-val egyszerűbb:
    auto element2 = c[0];           // érték szerinti másolat
    decltype(auto) element3 = c[0]; // pontos típus (lehet referencia is)
}

// Függvény visszatérési típusának kikövetkeztetése
template<typename T, typename U>
auto multiply(T t, U u) -> decltype(t * u) {
    return t * u;
}
```

### Trailing return type (utólagos visszatérési típus)

```cpp
template<typename T, typename U>
auto add(T& t, U& u) -> decltype(t + u) {
    return t + u;
}

// C++14-ben egyszerűbbé vált:
template<typename T, typename U>
decltype(auto) getValue(T& container, size_t index) {
    return container[index];
}
```

## Gyakorlati alkalmazások

### Sablonprogramozásban

```cpp
#include <vector>
#include <iostream>

template<typename Container>
void printFirstElement(Container& c) {
    if (!c.empty()) {
        // decltype megőrzi a pontos típust (pl. const int& ha a konténer const)
        decltype(auto) first = c[0];
        std::cout << "Első elem: " << first << std::endl;
    }
}

// auto használata iterátoroknál
template<typename Container>
void iterateContainer(const Container& c) {
    for (auto it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
```

### Lambda kifejezésekben

```cpp
#include <functional>

// auto használata lambda tárolására
auto lambda = [](int x) { return x * 2; };

// decltype használata visszatérési típus meghatározására
template<typename F, typename T>
auto apply(F&& f, T&& t) -> decltype(f(t)) {
    return f(std::forward<T>(t));
}
```

### Összetett típusok kezelése

```cpp
#include <map>
#include <string>
#include <utility>

// decltype használata pair típusok kikövetkeztetésére
std::map<std::string, int> myMap = {{"one", 1}, {"two", 2}};

// decltype meghatározza a pontos típust
for (const decltype(myMap)::value_type& pair : myMap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
}

// auto használata ugyanezen célra (egyszerűbb)
for (const auto& pair : myMap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
}
```

## Példák és kódrészletek

### Teljes példaprogram

```cpp
#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>

// Segédfüggvény típus kiírásához (fordítási időben)
template<typename T>
void printType(const std::string& varName) {
    std::cout << varName << " típusa: " << typeid(T).name() << std::endl;
}

int main() {
    std::cout << "=== auto és decltype() példák ===" << std::endl;
    
    // auto példák
    auto x = 42;
    auto y = 3.14f;
    auto z = 3.14;
    auto s = std::string("Hello");
    
    std::cout << "auto példák:" << std::endl;
    printType<decltype(x)>("x");
    printType<decltype(y)>("y");
    printType<decltype(z)>("z");
    printType<decltype(s)>("s");
    
    // decltype példák
    int a = 10;
    const int& b = a;
    int arr[5] = {1, 2, 3, 4, 5};
    
    decltype(a) c = 20;        // int
    decltype(b) d = a;         // const int&
    decltype(a + b) e = a + 1; // int
    
    std::cout << "\ndecltype példák:" << std::endl;
    printType<decltype(c)>("c");
    printType<decltype(d)>("d");
    printType<decltype(e)>("e");
    
    // decltype(auto) példák (C++14)
    auto getValue = []() -> int& {
        static int value = 42;
        return value;
    };
    
    decltype(auto) ref = getValue();  // int&
    std::cout << "\ndecltype(auto) példa:" << std::endl;
    printType<decltype(ref)>("ref");
    
    // auto és decltype kombinációja sablonban
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin();
    
    std::cout << "\nIterator példa:" << std::endl;
    printType<decltype(it)>("it");
    
    // Konténer elemeinek típusának kikövetkeztetése
    decltype(vec)::value_type element = 10;  // int típus
    printType<decltype(element)>("element");
    
    return 0;
}
```

### Haladó példák

```cpp
#include <iostream>
#include <type_traits>

// decltype használata sablon metaprogramozásban
template<typename T>
struct TypeInfo {
    using type = T;
    using reference = T&;
    using pointer = T*;
    using const_reference = const T&;
};

// auto és decltype kombinációja függvény visszatérési típusának meghatározására
template<typename Container>
auto getElement(Container& c, size_t idx) -> typename TypeInfo<decltype(c[idx])>::reference {
    return c[idx];
}

// decltype(auto) használata referencia visszaadásra
template<typename T>
decltype(auto) getReference(T&& t) {
    return std::forward<T>(t);
}

int main() {
    int x = 42;
    int& ref = x;
    
    // decltype(auto) megtartja a referencia tulajdonságot
    decltype(auto) result = getReference(ref);
    
    std::cout << "Eredmény típusa: " << typeid(result).name() << std::endl;
    std::cout << "Érték: " << result << std::endl;
    
    result = 100;  // Módosítja az eredeti x értékét
    std::cout << "x új értéke: " << x << std::endl;
    
    return 0;
}
```

### Fordítási idejű típusellenőrzés

```cpp
#include <type_traits>
#include <iostream>

// Statikus ellenőrzés decltype és auto használatával
template<typename T, typename U>
void checkTypes(T&& t, U&& u) {
    // Fordítási idejű ellenőrzés
    static_assert(std::is_same_v<decltype(t + u), int>, "Várt típus: int");
    
    // Használat
    auto result = t + u;
    std::cout << "Eredmény: " << result << std::endl;
}

int main() {
    checkTypes(5, 10);  // Működik, mert int + int = int
    return 0;
}
```