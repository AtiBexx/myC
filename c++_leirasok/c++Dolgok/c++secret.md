A "nagyon secret" C++ módszerek és kódok igazából nem mások, mint olyan technikák, amelyeket ritkán használnak, vagy csak haladó szintű programozók ismernek. Ezek között vannak például:

1. Template metaprogramming
2. SFINAE (Substitution Failure Is Not An Error)
3. Constexpr és compile-time execution
4. Perfect forwarding
5. CRTP (Curiously Recurring Template Pattern)
6. Operator overloading trükkök
7. Type traits és type manipulation
8. Memory layout hackery / pointer magic
9. Inline assembly in C++
10. Custom allocators

### Példa: Saját Constexpr String Hashelés (compile time hash)

```
#include <iostream>

// Compile time string hash
constexpr unsigned int hash(const char* str, int h = 0) {
    return !str[h] ? 0x811C9DC5 : (hash(str, h+1) * 0x01000193) ^ str[h];
}

int main() {
    switch (hash("secret")) {
        case hash("secret"):
            std::cout << "Access granted to the secret vault.\n";
            break;
        default:
            std::cout << "Intruder detected!\n";
    }
}
```

Ez a `hash` függvény már fordítási időben kiszámolja az eredményt – tehát teljesen "láthatatlan" futásidőben. 

Természetesen! Itt van egy-egy példa mindegyik említett "titkos" C++ technikára. Ezek mind haladó C++ jellemzők, amiket nem mindenki használ nap mint nap – de nagyon hatékonyak lehetnek bizonyos helyzetekben.

------

## 1. Template Metaprogramming

Fordítási időn belüli számítások.

cpp

```
template<int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static constexpr int value = 1;
};

int main() {
    std::cout << "Factorial of 5 is: " << Factorial<5>::value << "\n"; // 120
}
template<int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static constexpr int value = 1;
};

int main() {
    std::cout << "Factorial of 5 is: " << Factorial<5>::value << "\n"; // 120
}
```

------

##  2. SFINAE (Substitution Failure Is Not An Error)

Függvény túlterhelés típus alapján.

cpp

```
#include <type_traits>
#include <iostream>

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print(T t) {
    std::cout << "Integer: " << t << "\n";
}

template<typename T>
typename std::enable_if<!std::is_integral<T>::value, void>::type
print(T t) {
    std::cout << "Non-integer: " << t << "\n";
}

int main() {
    print(42);       // Integer
    print(3.14);     // Non-integer
}
#include <type_traits>
#include <iostream>

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print(T t) {
    std::cout << "Integer: " << t << "\n";
}

template<typename T>
typename std::enable_if<!std::is_integral<T>::value, void>::type
print(T t) {
    std::cout << "Non-integer: " << t << "\n";
}

int main() {
    print(42);       // Integer
    print(3.14);     // Non-integer
}
```

------

##  3. Constexpr és Compile-Time Execution

cpp

```
constexpr int square(int n) {
    return n * n;
}

int main() {
    constexpr int x = square(10);
    static_assert(x == 100, "Math broken!");
    std::cout << "Compile-time squared: " << x << "\n";
}
constexpr int square(int n) {
    return n * n;
}

int main() {
    constexpr int x = square(10);
    static_assert(x == 100, "Math broken!");
    std::cout << "Compile-time squared: " << x << "\n";
}
```

------

##  4. Perfect Forwarding

cpp

```
#include <utility>
#include <iostream>

void func(int& x) { std::cout << "Lvalue\n"; }
void func(int&& x) { std::cout << "Rvalue\n"; }

template<typename T>
void wrapper(T&& arg) {
    func(std::forward<T>(arg)); // Perfect forwarding
}

int main() {
    int x = 42;
    wrapper(x);         // Lvalue
    wrapper(1337);      // Rvalue
}
#include <utility>
#include <iostream>

void func(int& x) { std::cout << "Lvalue\n"; }
void func(int&& x) { std::cout << "Rvalue\n"; }

template<typename T>
void wrapper(T&& arg) {
    func(std::forward<T>(arg)); // Perfect forwarding
}

int main() {
    int x = 42;
    wrapper(x);         // Lvalue
    wrapper(1337);      // Rvalue
}
```

------

##  5. CRTP (Curiously Recurring Template Pattern)

cpp

```
template<typename Derived>
class Animal {
public:
    void speak() {
        static_cast<Derived*>(this)->make_sound();
    }
};

class Dog : public Animal<Dog> {
public:
    void make_sound() { std::cout << "Woof!\n"; }
};

int main() {
    Dog dog;
    dog.speak(); // Woof!
}
template<typename Derived>
class Animal {
public:
    void speak() {
        static_cast<Derived*>(this)->make_sound();
    }
};

class Dog : public Animal<Dog> {
public:
    void make_sound() { std::cout << "Woof!\n"; }
};

int main() {
    Dog dog;
    dog.speak(); // Woof!
}
```

------

##  6. Operator Overloading Trükkök

cpp

```
#include <iostream>

struct SecretVault {
    bool operator==(const SecretVault&) const {
        return true; // Mindig titkos 
    }
};

std::ostream& operator<<(std::ostream& os, const SecretVault&) {
    return os << "[SECRET DATA ENCRYPTED]";
}

int main() {
    SecretVault vault;
    std::cout << vault << "\n"; // [SECRET DATA ENCRYPTED]
}
#include <iostream>

struct SecretVault {
    bool operator==(const SecretVault&) const {
        return true; // Mindig titkos 
    }
};

std::ostream& operator<<(std::ostream& os, const SecretVault&) {
    return os << "[SECRET DATA ENCRYPTED]";
}

int main() {
    SecretVault vault;
    std::cout << vault << "\n"; // [SECRET DATA ENCRYPTED]
}
```

------

##  7. Type Traits és Type Manipulation

cpp

```
#include <type_traits>
#include <iostream>

template<typename T>
void inspect_type() {
    if constexpr (std::is_same_v<T, int>) {
        std::cout << "It's an int!\n";
    } else if constexpr (std::is_pointer_v<T>) {
        std::cout << "It's a pointer!\n";
    } else {
        std::cout << "Unknown type.\n";
    }
}

int main() {
    inspect_type<int>();        // It's an int!
    inspect_type<double*>();    // It's a pointer!
}
#include <type_traits>
#include <iostream>

template<typename T>
void inspect_type() {
    if constexpr (std::is_same_v<T, int>) {
        std::cout << "It's an int!\n";
    } else if constexpr (std::is_pointer_v<T>) {
        std::cout << "It's a pointer!\n";
    } else {
        std::cout << "Unknown type.\n";
    }
}

int main() {
    inspect_type<int>();        // It's an int!
    inspect_type<double*>();    // It's a pointer!
}
```

------

## 8. Memory Layout Hackery / Pointer Magic

 Ez veszélyes, de néha hasznos low-level dolgokhoz:

cpp

```
#include <iostream>

struct Data {
    int a;
    double b;
};

int main() {
    Data d{42, 3.14};
    void* ptr = &d;

    // Ugly but shows memory access tricks
    int* p_a = reinterpret_cast<int*>(ptr);
    double* p_b = reinterpret_cast<double*>(p_a + 1);

    std::cout << "a = " << *p_a << ", b = " << *p_b << "\n";
}
#include <iostream>

struct Data {
    int a;
    double b;
};

int main() {
    Data d{42, 3.14};
    void* ptr = &d;

    // Ugly but shows memory access tricks
    int* p_a = reinterpret_cast<int*>(ptr);
    double* p_b = reinterpret_cast<double*>(p_a + 1);

    std::cout << "a = " << *p_a << ", b = " << *p_b << "\n";
}
```

------

##  9. Inline Assembly in C++

GCC/Clang specifikus példa:

cpp

```
int main() {
    int a = 5, b = 10, result;
    asm ("add %1, %2\n\t"
         "mov %2, %0"
         : "=r"(result)
         : "r"(a), "r"(b));
    std::cout << "Result: " << result << "\n"; // 15
}
int main() {
    int a = 5, b = 10, result;
    asm ("add %1, %2\n\t"
         "mov %2, %0"
         : "=r"(result)
         : "r"(a), "r"(b));
    std::cout << "Result: " << result << "\n"; // 15
}
```

------

##  10. Custom Allocators

cpp

```
#include <memory>
#include <iostream>

template<typename T>
class SecretAllocator {
public:
    using value_type = T;

    T* allocate(size_t n) {
        std::cout << "[ALLOCATING SECRETLY]\n";
        return static_cast<T*>(std::malloc(n * sizeof(T)));
    }

    void deallocate(T* p, size_t) {
        std::cout << "[DEALLOCATING SECRETLY]\n";
        std::free(p);
    }
};

int main() {
    std::vector<int, SecretAllocator<int>> secretVec;
    secretVec.push_back(42);
}
#include <memory>
#include <iostream>

template<typename T>
class SecretAllocator {
public:
    using value_type = T;

    T* allocate(size_t n) {
        std::cout << "[ALLOCATING SECRETLY]\n";
        return static_cast<T*>(std::malloc(n * sizeof(T)));
    }

    void deallocate(T* p, size_t) {
        std::cout << "[DEALLOCATING SECRETLY]\n";
        std::free(p);
    }
};

int main() {
    std::vector<int, SecretAllocator<int>> secretVec;
    secretVec.push_back(42);
}
```

------

Ha szeretnéd, csinálhatunk egy komplett projektet is ezen technikák felhasználásával – pl. egy "titkos adatbázist", ami csak bizonyos kulcsszóra nyílik ki… 

Szólj, ha érdekel! 

Rendben! Készítünk egy "Titkos Adatbázis" alkalmazást C++-ban, amely csak akkor enged hozzáférést, ha helyes kulcsot adsz meg. Használunk benne néhány korábban bemutatott "titkos" technikát:

------

## 🔐 Titkos Adatbázis Projekt (SecretDB)

### 🧠 Használt technikák:

- Compile-time string hashelés (`constexpr`)
- Template metaprogramming
- Custom allocator
- Perfect forwarding
- SFINAE

------

### 📁 Fájl: `SecretDB.hpp`

cpp

```
#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

// === 1. Compile-time hash ===
constexpr unsigned long long hash(const char* str, int h = 0) {
    return !str[h] ? 0x811C9DC5 : (hash(str, h+1) * 0x01000193) ^ str[h];
}

// === 2. Custom Allocator ===
template<typename T>
class SecretAllocator {
public:
    using value_type = T;

    T* allocate(size_t n) {
        std::cout << "[ ALLOCATING SECRET MEMORY]\n";
        return static_cast<T*>(std::malloc(n * sizeof(T)));
    }

    void deallocate(T* p, size_t) {
        std::cout << "[ DEALLOCATING SECRET MEMORY]\n";
        std::free(p);
    }

    template<typename U>
    bool operator==(const SecretAllocator<U>&) const { return true; }

    template<typename U>
    bool operator!=(const SecretAllocator<U>&) const { return false; }
};

// === 3. Titkos Adatbázis Osztály ===
class SecretDatabase {
private:
    std::unordered_map<std::string, std::string, std::hash<std::string>, std::equal_to<>, SecretAllocator<std::pair<const std::string, std::string>>> db;

public:
    template<typename... Args>
    void add_entry(Args&&... args) {
        db.emplace(std::forward<Args>(args)...);
    }

    void access_with_key(const std::string& key) const {
        switch(hash(key.c_str())) {
            case hash("secret123"):
                std::cout << " ACCESS GRANTED:\n";
                for (const auto& pair : db) {
                    std::cout << "User: " << pair.first << " -> Pass: " << pair.second << "\n";
                }
                break;
            default:
                std::cout << " INTRUDER DETECTED!\n";
        }
    }
};
#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

// === 1. Compile-time hash ===
constexpr unsigned long long hash(const char* str, int h = 0) {
    return !str[h] ? 0x811C9DC5 : (hash(str, h+1) * 0x01000193) ^ str[h];
}

// === 2. Custom Allocator ===
template<typename T>
class SecretAllocator {
public:
    using value_type = T;

    T* allocate(size_t n) {
        std::cout << "[ ALLOCATING SECRET MEMORY]\n";
        return static_cast<T*>(std::malloc(n * sizeof(T)));
    }

    void deallocate(T* p, size_t) {
        std::cout << "[ DEALLOCATING SECRET MEMORY]\n";
        std::free(p);
    }

    template<typename U>
    bool operator==(const SecretAllocator<U>&) const { return true; }

    template<typename U>
    bool operator!=(const SecretAllocator<U>&) const { return false; }
};

// === 3. Titkos Adatbázis Osztály ===
class SecretDatabase {
private:
    std::unordered_map<std::string, std::string, std::hash<std::string>, std::equal_to<>, SecretAllocator<std::pair<const std::string, std::string>>> db;

public:
    template<typename... Args>
    void add_entry(Args&&... args) {
        db.emplace(std::forward<Args>(args)...);
    }

    void access_with_key(const std::string& key) const {
        switch(hash(key.c_str())) {
            case hash("secret123"):
                std::cout << " ACCESS GRANTED:\n";
                for (const auto& pair : db) {
                    std::cout << "User: " << pair.first << " -> Pass: " << pair.second << "\n";
                }
                break;
            default:
                std::cout << " INTRUDER DETECTED!\n";
        }
    }
};
```

------

### 📄 `main.cpp`

cpp

```
#include "SecretDB.hpp"

int main() {
    SecretDatabase db;

    // Perfect forwarding használata az adatok beszúrásához
    db.add_entry("Alice", "rosebud");
    db.add_entry("Bob", "qwerty123");

    std::cout << "Trying wrong password...\n";
    db.access_with_key("wrongpass");

    std::cout << "\nTrying correct password...\n";
    db.access_with_key("secret123");

    return 0;
}
#include "SecretDB.hpp"

int main() {
    SecretDatabase db;

    // Perfect forwarding használata az adatok beszúrásához
    db.add_entry("Alice", "rosebud");
    db.add_entry("Bob", "qwerty123");

    std::cout << "Trying wrong password...\n";
    db.access_with_key("wrongpass");

    std::cout << "\nTrying correct password...\n";
    db.access_with_key("secret123");

    return 0;
}
```

------

###  Kimenet:

```
[ ALLOCATING SECRET MEMORY]
[ ALLOCATING SECRET MEMORY]
Trying wrong password...
 INTRUDER DETECTED!

Trying correct password...
 ACCESS GRANTED:
User: Alice -> Pass: rosebud
User: Bob -> Pass: qwerty123
[ DEALLOCATING SECRET MEMORY]
[ DEALLOCATING SECRET MEMORY]
[ ALLOCATING SECRET MEMORY]
[ ALLOCATING SECRET MEMORY]
Trying wrong password...
 INTRUDER DETECTED!

Trying correct password...
 ACCESS GRANTED:
User: Alice -> Pass: rosebud
User: Bob -> Pass: qwerty123
[DEALLOCATING SECRET MEMORY]
[DEALLOCATING SECRET MEMORY]
```

------

###  Miért titkos?

- A kulcs sosem tárolódik simán, csak hashelve van.
- A memória allokáció üzenetet ír ki – mintha titkosítva lenne.
- A teljes logika egy elegáns `switch-case`-en múlik a `constexpr` hash alapján.

------

