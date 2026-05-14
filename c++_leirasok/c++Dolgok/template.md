Természetesen! Bocsi, hogy félbehagyta — folytatom a C++ template-ekről szóló részt.

------

#  C++ Template-ek – Teljes Bevezető

##  Mi az a template?

A template egy olyan mechanizmus, amellyel típusfüggetlen (ún. generikus) függvényeket és osztályokat lehet írni. Egy sablonból (template-ből) több konkrét változat is létrehozható különböző típusokkal.

Például egy `max(a,b)` függvényt akarunk írni, ami működik `int`, `double`, `float` stb. típusokra is — erre jó a template.

------

##  Mire használják?

1. Újrafelhasználhatóság: Egy kód több típussal is működjön.
2. Teljesítmény: Fordítási időben dől el, melyik verzió kerül generálásra → nincs futásidejű költség.
3. Type safety: Ellenőrzés fordítási időben.
4. Meta-programming: Komplex logikák implementálása fordítási időben.

------

##  Egyszerű Példa: Függvény Template

cpp

```
#include <iostream>

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(3, 7) << "\n";          // int
    std::cout << max(3.14, 2.71) << "\n";    // double
    std::cout << max('a', 'z') << "\n";      // char
}
#include <iostream>

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(3, 7) << "\n";          // int
    std::cout << max(3.14, 2.71) << "\n";    // double
    std::cout << max('a', 'z') << "\n";      // char
}
```

------

##  Osztály Template

cpp

```
template<typename T>
class Box {
private:
    T content;
public:
    Box(T value) : content(value) {}

    void setContent(T value) {
        content = value;
    }

    T getContent() const {
        return content;
    }
};

int main() {
    Box<int> intBox(42);
    Box<std::string> stringBox("Hello");

    std::cout << intBox.getContent() << "\n";
    std::cout << stringBox.getContent() << "\n";
}
template<typename T>
class Box {
private:
    T content;
public:
    Box(T value) : content(value) {}

    void setContent(T value) {
        content = value;
    }

    T getContent() const {
        return content;
    }
};

int main() {
    Box<int> intBox(42);
    Box<std::string> stringBox("Hello");

    std::cout << intBox.getContent() << "\n";
    std::cout << stringBox.getContent() << "\n";
}
```

------

##  Template Specializáció

Bizonyos típusokra máshogy viselkedhet a sablon:

cpp

```
template<typename T>
class Printer {
public:
    void print(const T& value) {
        std::cout << "Value: " << value << "\n";
    }
};

// Specializáció bool-ra
template<>
class Printer<bool> {
public:
    void print(const bool& value) {
        std::cout << "Boolean: " << (value ? "true" : "false") << "\n";
    }
};

int main() {
    Printer<int> iprinter;
    Printer<bool> bprinter;

    iprinter.print(42);     // Value: 42
    bprinter.print(true);   // Boolean: true
}
template<typename T>
class Printer {
public:
    void print(const T& value) {
        std::cout << "Value: " << value << "\n";
    }
};

// Specializáció bool-ra
template<>
class Printer<bool> {
public:
    void print(const bool& value) {
        std::cout << "Boolean: " << (value ? "true" : "false") << "\n";
    }
};

int main() {
    Printer<int> iprinter;
    Printer<bool> bprinter;

    iprinter.print(42);     // Value: 42
    bprinter.print(true);   // Boolean: true
}
```

------

##  Variadic Templates (Változó számú paraméter)

cpp

```
#include <iostream>

template<typename T>
void print(T&& t) {
    std::cout << t << "\n";
}

template<typename T, typename... Args>
void print(T&& t, Args&&... args) {
    std::cout << t << " ";
    print(args...);
}

int main() {
    print(1, 2.5, "hello", 'x');  // 1 2.5 hello x
}
#include <iostream>

template<typename T>
void print(T&& t) {
    std::cout << t << "\n";
}

template<typename T, typename... Args>
void print(T&& t, Args&&... args) {
    std::cout << t << " ";
    print(args...);
}

int main() {
    print(1, 2.5, "hello", 'x');  // 1 2.5 hello x
}
```

------

## Perfect Forwarding Template Function

cpp

```
#include <utility>
#include <iostream>

class MyClass {
public:
    MyClass(int x) { std::cout << "Constructing with " << x << "\n"; }
    MyClass(const MyClass&) { std::cout << "Copy constructor\n"; }
    MyClass(MyClass&&) { std::cout << "Move constructor\n"; }
};

template<typename T>
void create_and_forward(T&& arg) {
    MyClass obj(std::forward<T>(arg)); // perfect forwarding
}

int main() {
    create_and_forward(42);           // rvalue
    int x = 42;
    create_and_forward(x);            // lvalue
}
#include <utility>
#include <iostream>

class MyClass {
public:
    MyClass(int x) { std::cout << "Constructing with " << x << "\n"; }
    MyClass(const MyClass&) { std::cout << "Copy constructor\n"; }
    MyClass(MyClass&&) { std::cout << "Move constructor\n"; }
};

template<typename T>
void create_and_forward(T&& arg) {
    MyClass obj(std::forward<T>(arg)); // perfect forwarding
}

int main() {
    create_and_forward(42);           // rvalue
    int x = 42;
    create_and_forward(x);            // lvalue
}
```

------

##  Template Metaprogramming Példa: Compile-Time Fibonacci

cpp

```
template<int N>
struct Fib {
    static constexpr int value = Fib<N-1>::value + Fib<N-2>::value;
};

template<>
struct Fib<0> {
    static constexpr int value = 0;
};

template<>
struct Fib<1> {
    static constexpr int value = 1;
};

int main() {
    std::cout << "Fibonacci(10): " << Fib<10>::value << "\n"; // 55
}
template<int N>
struct Fib {
    static constexpr int value = Fib<N-1>::value + Fib<N-2>::value;
};

template<>
struct Fib<0> {
    static constexpr int value = 0;
};

template<>
struct Fib<1> {
    static constexpr int value = 1;
};

int main() {
    std::cout << "Fibonacci(10): " << Fib<10>::value << "\n"; // 55
}
```

------

##  Mikor használjuk?

| Felhasználási terület  | Példa                                     |
| ---------------------- | ----------------------------------------- |
| Általános algoritmusok | `sort`, `find`, `max`, `min`              |
| Konténerek             | `vector<T>`, `map<K,V>`                   |
| Smart pointerek        | `unique_ptr<T>`, `shared_ptr<T>`          |
| Type traits            | `is_integral`, `enable_if`, `conditional` |

------

##  Gyakori hiba: Nem létező operátor/művelet

cpp

```
template<typename T>
void do_math(T a, T b) {
    std::cout << a + b << "\n"; // Hibás lehet, ha T nem támogatja a + operátort!
}
template<typename T>
void do_math(T a, T b) {
    std::cout << a + b << "\n"; // Hibás lehet, ha T nem támogatja a + operátort!
}
```

Megoldás: `static_assert`, `concept` (C++20), vagy SFINAE.

------

# 🚀 Haladó Template Példák – Mini Framework Építése

Készítünk egy teljes mini framework-et template-ek segítségével:

## 📦 Tartalomjegyzék

1. Saját `Vector` konténer
2. Saját `SmartPointer`
3. Reflection-szerű rendszer
4. Event system template-kkel
5. Type-safe factory pattern

------

## 1️⃣ Saját Vector Konténer

cpp

```
#include <memory>
#include <stdexcept>

template<typename T>
class MyVector {
private:
    std::unique_ptr<T[]> data;
    size_t size_;
    size_t capacity_;

    void resizeIfNeeded() {
        if (size_ >= capacity_) {
            capacity_ *= 2;
            auto newData = std::make_unique<T[]>(capacity_);
            for (size_t i = 0; i < size_; ++i) {
                newData[i] = std::move(data[i]);
            }
            data = std::move(newData);
        }
    }

public:
    MyVector() : size_(0), capacity_(1) {
        data = std::make_unique<T[]>(capacity_);
    }

    void push_back(const T& item) {
        resizeIfNeeded();
        data[size_++] = item;
    }

    void push_back(T&& item) {
        resizeIfNeeded();
        data[size_++] = std::move(item);
    }

    T& operator[](size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
};
#include <memory>
#include <stdexcept>

template<typename T>
class MyVector {
private:
    std::unique_ptr<T[]> data;
    size_t size_;
    size_t capacity_;

    void resizeIfNeeded() {
        if (size_ >= capacity_) {
            capacity_ *= 2;
            auto newData = std::make_unique<T[]>(capacity_);
            for (size_t i = 0; i < size_; ++i) {
                newData[i] = std::move(data[i]);
            }
            data = std::move(newData);
        }
    }

public:
    MyVector() : size_(0), capacity_(1) {
        data = std::make_unique<T[]>(capacity_);
    }

    void push_back(const T& item) {
        resizeIfNeeded();
        data[size_++] = item;
    }

    void push_back(T&& item) {
        resizeIfNeeded();
        data[size_++] = std::move(item);
    }

    T& operator[](size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
};
```

------

##  Saját SmartPointer

cpp

```
template<typename T>
class MySmartPointer {
private:
    T* ptr;
    size_t* ref_count;

    void cleanup() {
        if (ref_count && --(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }

public:
    explicit MySmartPointer(T* p = nullptr) : ptr(p), ref_count(new size_t(1)) {}

    MySmartPointer(const MySmartPointer& other) : ptr(other.ptr), ref_count(other.ref_count) {
        ++(*ref_count);
    }

    MySmartPointer& operator=(const MySmartPointer& other) {
        if (this != &other) {
            cleanup();
            ptr = other.ptr;
            ref_count = other.ref_count;
            ++(*ref_count);
        }
        return *this;
    }

    ~MySmartPointer() {
        cleanup();
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }
};
template<typename T>
class MySmartPointer {
private:
    T* ptr;
    size_t* ref_count;

    void cleanup() {
        if (ref_count && --(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }

public:
    explicit MySmartPointer(T* p = nullptr) : ptr(p), ref_count(new size_t(1)) {}

    MySmartPointer(const MySmartPointer& other) : ptr(other.ptr), ref_count(other.ref_count) {
        ++(*ref_count);
    }

    MySmartPointer& operator=(const MySmartPointer& other) {
        if (this != &other) {
            cleanup();
            ptr = other.ptr;
            ref_count = other.ref_count;
            ++(*ref_count);
        }
        return *this;
    }

    ~MySmartPointer() {
        cleanup();
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }
};
```

------

##  Reflection-Szerű Rendszer

cpp

```
#include <string>
#include <unordered_map>
#include <functional>
#include <any>

class Reflectable {
private:
    std::unordered_map<std::string, std::any> properties;

public:
    template<typename T>
    void setProperty(const std::string& name, T&& value) {
        properties[name] = std::forward<T>(value);
    }

    template<typename T>
    T getProperty(const std::string& name) const {
        auto it = properties.find(name);
        if (it != properties.end()) {
            return std::any_cast<T>(it->second);
        }
        throw std::runtime_error("Property not found: " + name);
    }

    bool hasProperty(const std::string& name) const {
        return properties.find(name) != properties.end();
    }
};

// Használat:
class Person : public Reflectable {
public:
    Person(const std::string& name, int age) {
        setProperty("name", name);
        setProperty("age", age);
    }
};
#include <string>
#include <unordered_map>
#include <functional>
#include <any>

class Reflectable {
private:
    std::unordered_map<std::string, std::any> properties;

public:
    template<typename T>
    void setProperty(const std::string& name, T&& value) {
        properties[name] = std::forward<T>(value);
    }

    template<typename T>
    T getProperty(const std::string& name) const {
        auto it = properties.find(name);
        if (it != properties.end()) {
            return std::any_cast<T>(it->second);
        }
        throw std::runtime_error("Property not found: " + name);
    }

    bool hasProperty(const std::string& name) const {
        return properties.find(name) != properties.end();
    }
};

// Használat:
class Person : public Reflectable {
public:
    Person(const std::string& name, int age) {
        setProperty("name", name);
        setProperty("age", age);
    }
};
```

------

## Event System Template-Kel

cpp

```
#include <functional>
#include <vector>
#include <unordered_map>

template<typename... Args>
class EventEmitter {
private:
    std::unordered_map<std::string, std::vector<std::function<void(Args...)>>> listeners;

public:
    void on(const std::string& event, std::function<void(Args...)> callback) {
        listeners[event].push_back(callback);
    }

    void emit(const std::string& event, Args... args) {
        auto it = listeners.find(event);
        if (it != listeners.end()) {
            for (auto& callback : it->second) {
                callback(args...);
            }
        }
    }
};

// Használat:
EventEmitter<int, std::string> eventSystem;

void onUserLogin(int userId, const std::string& username) {
    std::cout << "User " << username << " (ID: " << userId << ") logged in\n";
}

int main() {
    eventSystem.on("user_login", onUserLogin);
    eventSystem.emit("user_login", 123, "Alice");
}
#include <functional>
#include <vector>
#include <unordered_map>

template<typename... Args>
class EventEmitter {
private:
    std::unordered_map<std::string, std::vector<std::function<void(Args...)>>> listeners;

public:
    void on(const std::string& event, std::function<void(Args...)> callback) {
        listeners[event].push_back(callback);
    }

    void emit(const std::string& event, Args... args) {
        auto it = listeners.find(event);
        if (it != listeners.end()) {
            for (auto& callback : it->second) {
                callback(args...);
            }
        }
    }
};

// Használat:
EventEmitter<int, std::string> eventSystem;

void onUserLogin(int userId, const std::string& username) {
    std::cout << "User " << username << " (ID: " << userId << ") logged in\n";
}

int main() {
    eventSystem.on("user_login", onUserLogin);
    eventSystem.emit("user_login", 123, "Alice");
}
```

------

## Type-Safe Factory Pattern

cpp

```
#include <memory>
#include <unordered_map>
#include <functional>

class BaseObject {
public:
    virtual ~BaseObject() = default;
    virtual void identify() const = 0;
};

template<typename T>
class RegisteredObject : public BaseObject {
public:
    void identify() const override {
        std::cout << "I am a " << typeid(T).name() << "\n";
    }
};

class ObjectFactory {
private:
    template<typename T>
    using Creator = std::function<std::unique_ptr<BaseObject>()>;

    std::unordered_map<std::string, Creator<BaseObject>> creators;

public:
    template<typename T>
    void registerType(const std::string& name) {
        creators[name] = []() -> std::unique_ptr<BaseObject> {
            return std::make_unique<T>();
        };
    }

    std::unique_ptr<BaseObject> create(const std::string& name) {
        auto it = creators.find(name);
        if (it != creators.end()) {
            return it->second();
        }
        return nullptr;
    }
};

// Használat:
class Player : public RegisteredObject<Player> {};
class Enemy : public RegisteredObject<Enemy> {};

int main() {
    ObjectFactory factory;
    factory.registerType<Player>("player");
    factory.registerType<Enemy>("enemy");

    auto player = factory.create("player");
    if (player) player->identify(); // I am a Player
}
#include <memory>
#include <unordered_map>
#include <functional>

class BaseObject {
public:
    virtual ~BaseObject() = default;
    virtual void identify() const = 0;
};

template<typename T>
class RegisteredObject : public BaseObject {
public:
    void identify() const override {
        std::cout << "I am a " << typeid(T).name() << "\n";
    }
};

class ObjectFactory {
private:
    template<typename T>
    using Creator = std::function<std::unique_ptr<BaseObject>()>;

    std::unordered_map<std::string, Creator<BaseObject>> creators;

public:
    template<typename T>
    void registerType(const std::string& name) {
        creators[name] = []() -> std::unique_ptr<BaseObject> {
            return std::make_unique<T>();
        };
    }

    std::unique_ptr<BaseObject> create(const std::string& name) {
        auto it = creators.find(name);
        if (it != creators.end()) {
            return it->second();
        }
        return nullptr;
    }
};

// Használat:
class Player : public RegisteredObject<Player> {};
class Enemy : public RegisteredObject<Enemy> {};

int main() {
    ObjectFactory factory;
    factory.registerType<Player>("player");
    factory.registerType<Enemy>("enemy");

    auto player = factory.create("player");
    if (player) player->identify(); // I am a Player
}
```

------

## Összefoglalás

Ezek a példák demonstrálják, hogyan lehet:

- Memória kezelést implementálni (`MyVector`, `MySmartPointer`)
- Dinamikus tulajdonságkezelést (`Reflectable`)
- Observer pattern-t (`EventEmitter`)
- Plugin architektúrát (`ObjectFactory`)

Mindez template-ek segítségével, típusbiztosan és újrafelhasználhatóan!

Szeretnél mélyebbre menni valamelyik témában? Pl.:

- Template specializáció mélyebben
- Concepts (C++20)
- Template metaprogramming trükkök
- Variadic template gyakorlati alkalmazásai

Csak szólj! 