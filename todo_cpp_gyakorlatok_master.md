# C++ Master / Expert Szintű Gyakorlatok

---

## BLOKK 1 – FORDÍTÓIDEJŰ PROGRAMOZÁS (Compile-time)

### 1.1 constexpr mélyen
**Feladat:** Írj egy `constexpr` faktoriális függvényt.
A lényeg: az eredmény fordítás közben kiszámolódik, nem futáskor!
```cpp
constexpr int fakto(int n) {
    // ... te töltöd ki
}
static_assert(fakto(5) == 120, "Rossz eredmény!");  // fordítóidejű ellenőrzés!
```

### 1.2 Template metaprogramozás (TMP)
**Feladat:** Számold ki fordítóidőben a Fibonacci sorozatot template-tel.
Ez az alapja az összes modern C++ könyvtárnak!
```cpp
template<int N>
struct Fib {
    static const int ertek = Fib<N-1>::ertek + Fib<N-2>::ertek;
};
// specializations for 0 and 1...
```

### 1.3 if constexpr (C++17)
**Feladat:** Írj egy `kiir<T>` template függvényt ami:
- ha T numerikus → kiírja a négyzetét
- ha T string → kiírja nagybetűsen
- mindezt fordítóidőben dönti el, nem if-else-szel futáskor!

---

## BLOKK 2 – MOVE SZEMANTIKA MÉLYEN

### 2.1 Perfect forwarding
**Feladat:** Írj egy `gyart<T>` factory függvényt ami bármilyen
konstruktor argumentumot tökéletesen továbbít – se felesleges másolás,
se felesleges move. Ez az `std::make_unique` belső működése!
```cpp
template<typename T, typename... Args>
std::unique_ptr<T> gyart(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
```

### 2.2 Saját move-aware konténer
**Feladat:** Írj egy egyszerű `Vektor<T>` osztályt (mint az std::vector)
ami támogatja a move szemantikát, automatikusan növeli a kapacitását,
és helyesen kezeli a Rule of Five-ot.

### 2.3 Copy elision / RVO megértése
**Feladat:** Teszteld a godbolt.org-on hogy mikor történik RVO
(Return Value Optimization) és mikor nem.
Írj 3 függvényt: egynél RVO történik, egynél move, egynél copy.
Figyeld meg az assembly output különbségét!

---

## BLOKK 3 – HALADÓ TEMPLATES

### 3.1 Variadic templates
**Feladat:** Írj egy `osszead` függvényt ami tetszőleges számú
argumentumot összead – bármilyen típust ami támogatja a `+` operátort!
```cpp
template<typename T>
T osszead(T ertek) { return ertek; }

template<typename T, typename... Args>
T osszead(T elso, Args... tobbi) {
    return elso + osszead(tobbi...);
}
// osszead(1, 2, 3, 4, 5) == 15
// osszead("Hello"s, " "s, "World"s) == "Hello World"
```

### 3.2 SFINAE (Substitution Failure Is Not An Error)
**Feladat:** Írj egy template függvényt ami csak akkor fordul le
ha a típusnak van `size()` metódusa (pl. string, vector – de nem int).
```cpp
template<typename T>
auto meret(const T& t) -> decltype(t.size()) {
    return t.size();
}
```

### 3.3 Concepts (C++20)
**Feladat:** Írj egy `Szamolhato` concept-et ami megköveteli
hogy a típuson működjön `+`, `-`, `*`. Használd template constraintként!
```cpp
template<typename T>
concept Szamolhato = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
    { a - b } -> std::convertible_to<T>;
    { a * b } -> std::convertible_to<T>;
};
```

---

## BLOKK 4 – MEMÓRIA MÉLYEN

### 4.1 Custom allocator
**Feladat:** Írj egy saját allocator-t ami egy előre lefoglalt
memória poolból oszt ki – ez az alapja a játékmotorok
memóriakezelésének (nincs `new`/`delete` futáskor!)
```cpp
template<typename T>
class PoolAllocator {
    // saját memória pool
    // allocate() és deallocate() metódusok
};
std::vector<int, PoolAllocator<int>> v;
```

### 4.2 Placement new
**Feladat:** Hozz létre objektumot egy előre lefoglalt memóriaterületen
`placement new`-val. Mikor kell ez? (embedded, game dev, teljesítmény)
```cpp
char buffer[sizeof(MyClass)];
MyClass* obj = new (buffer) MyClass();  // placement new
obj->~MyClass();  // manuálisan kell destruktort hívni!
```

### 4.3 Memory alignment
**Feladat:** Mérj meg különböző struct elrendezéseket –
melyik foglal kevesebb memóriát és miért? (padding probléma)
```cpp
struct Rossz  { char a; int b; char c; };   // mennyi? miért?
struct Jo     { int b; char a; char c; };   // mennyi? miért?
```

---

## BLOKK 5 – KONKURENCIA MÉLYEN

### 5.1 Lock-free programozás
**Feladat:** Írj egy thread-safe számlálót `std::atomic`-kal,
mutex NÉLKÜL. Mérj sebességet mutex vs atomic között!
```cpp
std::atomic<int> szamlalo{0};
szamlalo.fetch_add(1, std::memory_order_relaxed);
```

### 5.2 Thread pool
**Feladat:** Írj egy egyszerű thread pool-t ami N szálat tart életben
és feladatokat oszt ki nekik `std::queue` és `std::mutex` segítségével.
Ez az alapja minden szerver alkalmazásnak!

### 5.3 Promise és Future
**Feladat:** Számold ki aszinkron módon egy nagy szám prímtényezőit
`std::promise`/`std::future` segítségével, a főszál közben csináljon
mást, majd kérje le az eredményt.

---

## BLOKK 6 – HALADÓ OOP MINTÁK

### 6.1 CRTP (Curiously Recurring Template Pattern)
**Feladat:** Valósíts meg statikus polimorfizmust CRTP-vel –
virtuális függvények NÉLKÜL, fordítóidőben dől el a típus!
```cpp
template<typename Leszarmazott>
class Alap {
public:
    void muvelet() {
        static_cast<Leszarmazott*>(this)->muvelet_impl();
    }
};
```

### 6.2 Type erasure
**Feladat:** Írj egy `Barmilyen` osztályt (mint az `std::any`)
ami bármilyen típust tárolhat template és virtual kombinációjával.

### 6.3 Policy-based design
**Feladat:** Írj egy `Naplo` osztályt ahol a naplózási stratégia
(fájlba, konzolra, hálózatra) template paraméterként cserélhető,
nem öröklődéssel!
```cpp
template<typename NaplozasiPolicy>
class Naplo : private NaplozasiPolicy {
    // ...
};
Naplo<FajlbaIr> fajlNaplo;
Naplo<Konzolra> konzolNaplo;
```

---

## BLOKK 7 – TELJESÍTMÉNY OPTIMALIZÁLÁS

### 7.1 Cache locality
**Feladat:** Mérj sebességet két mátrix bejárási módszer között:
sor-sor vs oszlop-sor. Miért tér el drasztikusan a sebesség?
(CPU cache line = 64 byte – ezt kell érteni!)

### 7.2 Branch prediction
**Feladat:** Mérj sebességet rendezett vs rendezetlen tömbön
egy feltételes összegzésnél. A CPU előre jelzi az elágazást!

### 7.3 SIMD alapok (opcionális, game dev-hez fontos)
**Feladat:** Ismerd meg az `__m128` típust és az SSE intrinsics-eket.
Adj össze 4 float-ot egyszerre egy CPU utasítással!

---

## BLOKK 8 – VALÓS RENDSZER FELADATOK

### 8.1 Saját string osztály
**Feladat:** Írj egy `SajatString` osztályt a semmiből:
- SSO (Small String Optimization) – rövid stringek stack-en
- COW (Copy-on-Write) opcionálisan
- Minden operator: `+`, `==`, `[]`, `<<`
- Rule of Five teljesen

### 8.2 Saját shared_ptr
**Feladat:** Írj egy `SajatSharedPtr<T>` osztályt ami:
- referencia számlálást végez
- thread-safe (`atomic` számlálóval)
- támogatja a `weak_ptr` megfelelőjét

### 8.3 Event system (Observer pattern production szinten)
**Feladat:** Írj egy típusbiztos event rendszert template-ekkel
ahol az esemény típusa fordítóidőben ellenőrzött:
```cpp
EventBus bus;
bus.subscribe<KattintasEsemeny>([](const KattintasEsemeny& e) {
    // kezeli az eseményt
});
bus.publish(KattintasEsemeny{100, 200});
```

---

## A Master szint jele ha:

- [ ] Godbolt-on el tudod olvasni az assembly outputot
- [ ] Meg tudod mondani melyik kód gyorsabb és MIÉRT
- [ ] Tudsz írni template library-t amit mások használnak
- [ ] Értesz lock-free adatstruktúrához
- [ ] Meg tudod valósítani az STL konténereket sajátként
- [ ] Ismered a C++ memory modelt (`memory_order_*`)
- [ ] Tudod mi az ABI és miért számít

---

## Ajánlott könyvek ha a jelenlegi könyv végére érsz:

| Könyv | Miért fontos |
|-------|-------------|
| **Effective Modern C++ – Scott Meyers** | A legjobb C++11/14 könyv |
| **C++ Templates: The Complete Guide** | Template master szint |
| **C++ Concurrency in Action – Anthony Williams** | Threading biblia |
| **The Art of Writing Efficient Programs** | Teljesítmény optimalizálás |
