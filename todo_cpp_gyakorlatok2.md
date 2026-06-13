# C++ Haladó Gyakorlatok – Master / Állásinterjú szint

---

## BLOKK 1 – MEMÓRIAKEZELÉS (Alap az alapon)

### 1.1 Stack vs Heap tudatosan
**Feladat:** Írj egy programot ami megmutatja a különbséget:
- hozz létre egy nagy tömböt stack-en → figyeld a stack overflow-t
- ugyanazt heap-en → működik
- mérd meg a sebességkülönbséget (`std::chrono`-val)

### 1.2 Memory leak detektálás
**Feladat:** Az alábbi kódban találd meg az összes memory leak-et és javítsd ki:
```cpp
void rossz() {
    int* p = new int[100];
    if (hiba) return;      // <- szivárog!
    delete[] p;
}
```
Szabály: minden `new`-hoz legyen `delete`, kivétel esetén is!

### 1.3 RAII elv
**Feladat:** Írj egy `AutoTomb` osztályt ami RAII-t valósít meg –
a konstruktorban foglal, a destruktorban felszabadít automatikusan.
Ez az alap elve a modern C++-nak és a smart pointereknek!
```cpp
// Így kell működnie:
{
    AutoTomb t(100);
    // használod...
}  // <- itt automatikusan felszabadul, nem kell delete!
```

---

## BLOKK 2 – SMART POINTEREK (Modern C++ kötelező!)

### 2.1 unique_ptr
**Feladat:** Írj egy `Allat` osztályt, hozz létre `unique_ptr<Allat>`-ot.
Próbáld meg másolni – mi történik? Miért? Mozgasd át `std::move`-val!
```cpp
std::unique_ptr<Allat> a = std::make_unique<Allat>("Kutya");
// std::unique_ptr<Allat> b = a;  // <- ez mit csinál?
std::unique_ptr<Allat> b = std::move(a); // <- ez?
```

### 2.2 shared_ptr és a referencia számlálás
**Feladat:** Hozz létre egy objektumot `shared_ptr`-rel, add át 3 helyre,
írd ki minden lépésnél a `use_count()`-ot. Figyeld mikor szabadul fel!

### 2.3 weak_ptr – körkörös referencia probléma
**Feladat:** Hozz létre két osztályt (`A` és `B`) amik `shared_ptr`-rel
mutatnak egymásra – ez memory leak! Javítsd ki `weak_ptr`-rel.
```cpp
struct A { std::shared_ptr<B> b_ptr; };
struct B { std::shared_ptr<A> a_ptr; };  // <- körköros, szivárog!
```

---

## BLOKK 3 – OOP MÉLYEN (Interjún mindig kérdezik)

### 3.1 Virtuális függvények és vtable
**Feladat:** Írj egy `Alak` alaposztályt `virtual terulet()` függvénnyel,
leszármaztass `Kor`, `Teglalapot`. Tárold őket `Alak*` tömbben,
hívd meg a `terulet()`-et – polimorfizmus!
```cpp
Alak* alakok[3] = { new Kor(5), new Teglalap(3,4), new Kor(2) };
for (auto* a : alakok) std::cout << a->terulet() << "\n";
```

### 3.2 Pure virtual / absztrakt osztály
**Feladat:** Az előző `Alak` legyen absztrakt (pure virtual).
Mi történik ha példányosítani próbálod? Miért hasznos ez?

### 3.3 Virtual destruktor – miért kötelező?
**Feladat:** Csináld meg az előző példát virtual destruktor NÉLKÜL,
figyeld meg a memory leak-et. Aztán add hozzá és figyeld meg a különbséget.
```cpp
// Rossz:
class Alak { ~Alak() {} };
// Jó:
class Alak { virtual ~Alak() {} };
```

### 3.4 Override és final kulcsszavak
**Feladat:** Bővítsd az előző példát `override` és `final` kulcsszavakkal.
Mi a különbség? Mit véd meg a fordítóidő hibáktól?

---

## BLOKK 4 – TEMPLATES (Generikus programozás)

### 4.1 Függvény template
**Feladat:** Írj egy `maxErtek<T>` template függvényt ami bármilyen
típusra működik (int, double, string). Teszteld mindhárommal!
```cpp
template<typename T>
T maxErtek(T a, T b) {
    // ... te töltöd ki
}
```

### 4.2 Osztály template
**Feladat:** Írj egy `Par<T, U>` template osztályt ami két különböző
típusú értéket tárol (mint az `std::pair`). Valósítsd meg getterekkel.

### 4.3 Template specializáció
**Feladat:** Az előző `maxErtek` template-et specializáld `const char*`-ra
mert az alapértelmezett pointer összehasonlítás nem működik stringekre!

---

## BLOKK 5 – STL KONTÉNEREK (Napi szintű tudás)

### 5.1 vector vs list – mikor melyik?
**Feladat:** Mérj sebességet (`chrono`-val):
- 100.000 elem BESZÚRÁSA az elejére: `vector` vs `list`
- 100.000 elem ELÉRÉSE random indexszel: `vector` vs `list`
Írd le a tanulságot kommentben!

### 5.2 map és unordered_map
**Feladat:** Írj egy szószámláló programot ami megszámolja egy szövegben
hányszor szerepel minden szó. Csináld meg `map`-pel és `unordered_map`-pel.
Mi a különbség a kettő között (rendezés, sebesség)?

### 5.3 STL algoritmusok
**Feladat:** Egy `vector<int>`-en csináld meg kizárólag STL algoritmusokkal:
- rendezés (`sort`)
- keresés (`find`, `binary_search`)
- szűrés (`copy_if`)
- transzformáció (`transform`)
- összegzés (`accumulate`)

---

## BLOKK 6 – LAMBDÁK ÉS MODERN C++ (C++11/14/17)

### 6.1 Lambda alapok
**Feladat:** Rendezz egy `vector<string>`-et lambdával hossz szerint,
majd abc szerint, majd fordított abc szerint – mindhárom külön lambda!

### 6.2 Lambda capture
**Feladat:** Írj egy számlálót lambdával ami minden hívásnál eggyel nő.
Mit jelent a `[=]`, `[&]`, `[x]`, `[&x]` capture?
```cpp
int szamlalo = 0;
auto novel = [&szamlalo]() { szamlalo++; };
```

### 6.3 std::function
**Feladat:** Írj egy `alkalmaz` függvényt ami `std::function<int(int)>`-t
kap és alkalmazza egy vektorra. Teszteld lambdával, sima függvénnyel is!

---

## BLOKK 7 – HIBAKEZELÉS

### 7.1 Exception alapok
**Feladat:** Írj egy osztályt ami kivételt dob ha érvénytelen értéket kap.
Kezeld `try/catch`-csel. Dobj saját exception osztályt!
```cpp
class SajatHiba : public std::exception {
    // ... te töltöd ki
};
```

### 7.2 Exception és RAII kapcsolata
**Feladat:** Mutasd meg hogy RAII-val automatikusan megtörténik a cleanup
kivétel esetén is – ellentétben a nyers pointer + delete megoldással.

---

## BLOKK 8 – KONKURENCIA (Haladó, de interjún kérdezik)

### 8.1 std::thread alapok
**Feladat:** Indíts el 3 szálat amik egyszerre számlálnak 1-1000-ig,
írd ki az eredményt. Mi a probléma? (race condition)

### 8.2 Mutex
**Feladat:** Javítsd az előző példát `std::mutex`-szel.
Mi a különbség `lock()/unlock()` és `std::lock_guard` között?

---

## BLOKK 9 – TERVEZÉSI MINTÁK (Design Patterns)

### 9.1 Singleton
**Feladat:** Írj egy `Naplo` singleton osztályt ami az egyetlen naplózó
a programban. Miért veszélyes a singleton multithreading esetén?

### 9.2 Factory
**Feladat:** Írj egy `AlakGyar` osztályt ami string alapján (`"kor"`, `"teglalap"`)
létrehozza a megfelelő `Alak` leszármazottat és visszaad egy `unique_ptr`-t.

### 9.3 Observer
**Feladat:** Írj egy eseményrendszert: egy `Gomb` osztály értesít
több `Figyelo`-t ha megnyomják. Ez az alap minden GUI framework mögött!

---

## BLOKK 10 – VALÓS INTERJÚ KÉRDÉSEK (Magyarázd el szóban is!)

Ezeket nem kódolni kell hanem érteni és elmagyarázni:

1. Mi a különbség `struct` és `class` között C++-ban?
2. Mi az a vtable és mikor jön létre?
3. Mi a különbség `new` és `malloc` között?
4. Mit jelent az ODR (One Definition Rule)?
5. Mi az undefined behavior? Adj 3 példát!
6. Mi a különbség `++i` és `i++` között, melyik gyorsabb és miért?
7. Mi az a copy elision / RVO (Return Value Optimization)?
8. Mikor használj `unique_ptr`-t és mikor `shared_ptr`-t?
9. Mi a különbség `std::array` és `std::vector` között?
10. Mit jelent a `constexpr` és mire jó?

---

## Fontossági sorrend ha időhiány van:

| Prioritás | Témák |
|-----------|-------|
| 🔴 Kötelező | Smart pointerek, virtuális függvények, templates alapok, STL |
| 🟡 Fontos | Lambdák, exception kezelés, RAII, design patterns |
| 🟢 Haladó | Konkurencia, template specializáció, move semantics mélyen |
