# std::string Alapok és Típusok

A `<string>` fejlécben definiált sablonosztály:

```cpp
template<
    class CharT,
    class Traits = std::char_traits<CharT>,
    class Allocator = std::allocator<CharT>
> class basic_string;
```

### pmr változat (C++17 óta)
A polimorf memóriafoglalót használó típusdefiníció:

```cpp
namespace pmr {
    template<
        class CharT,
        class Traits = std::char_traits<CharT>
    > using basic_string =
        std::basic_string<CharT, Traits, std::pmr::polymorphic_allocator<CharT>>;
}
```

---

Az `std::string` valójában egy sablonosztály specializációja: `std::basic_string<char>`.

## Általános leírás

Az `std::basic_string` karakter-szerű objektumok sorozatát tárolja és kezeli. Nem függ a karakter típusától, sem a rajtuk végzett műveletek természetétől (ezeket a `Traits` sablonparaméter határozza meg).

### Memóriatárolás (Contiguous Storage)
A string elemei **folytonosan** vannak tárolva a memóriában. Ez azt jelenti, hogy:
- A karakterekre mutató pointerekkel úgy dolgozhatunk, mint egy tömbbel.
- **C++11 óta:** Garantált, hogy a string végén van egy lezáró null-karakter (`\0`), így az elejére mutató pointer átadható olyan függvényeknek is, amik C-stílusú stringet várnak.

### Megfelelőség (Requirements)
A `basic_string` megfelel a következő konténer-követelményeknek:
- `AllocatorAwareContainer` (memóriafoglaló-tudatos)
- `SequenceContainer` (sorozat-konténer)
- `ContiguousContainer` (folytonos tárolású konténer – C++17 óta)

### Constexpr támogatás (C++20 óta)
Minden tagfüggvény `constexpr`, tehát használható fordítási idejű számításoknál.
**Fontos:** Egy `constexpr std::string` változó definiálása általában hibát okoz, mert a fordítási idejű dinamikus memóriafoglalást ugyanazon számítás során fel is kell szabadítani.

## Gyakori típusdefiníciók (Typedefs)

A standard könyvtár előre definiált neveket biztosít a leggyakoribb karaktertípusokhoz:

| Név | Definíció | Leírás |
| :--- | :--- | :--- |
| `std::string` | `basic_string<char>` | Standard 8-bites karakterek |
| `std::wstring` | `basic_string<wchar_t>` | Széles karakterek (platformfüggő) |
| `std::u8string` | `basic_string<char8_t>` | UTF-8 karakterek (C++20) |
| `std::u16string` | `basic_string<char16_t>` | UTF-16 karakterek (C++11) |
| `std::u32string` | `basic_string<char32_t>` | UTF-32 karakterek (C++11) |
| `std::pmr::string` | `pmr::basic_string<char>` | Polimorf memóriafoglalóval (C++17) |

## Template parameters (Sablon paraméterek)

- **CharT**: A karakter típusa (pl. `char`, `wchar_t`, `char16_t`).
- **Traits**: Meghatározza a karaktereken végzett alapműveleteket (pl. összehasonlítás, másolás). Alapértelmezett: `std::char_traits<CharT>`.
- **Allocator**: A memóriakezelésért felelős osztály. Alapértelmezett: `std::allocator<CharT>`.

## Nested types (Beágyazott típusok)

| Típus neve | Leírás |
| :--- | :--- |
| `traits_type` | A sablon Traits paramétere. |
| `value_type` | A karakter típusa (`CharT`). |
| `allocator_type` | A memóriafoglaló típusa. |
| `size_type` | Előjel nélküli egész típus a méretekhez (általában `size_t`). |
| `difference_type` | Előjeles egész típus távolságokhoz (általában `ptrdiff_t`). |
| `reference` | Referencia a karakterre (`value_type&`). |
| `const_reference` | Konstans referencia a karakterre. |
| `pointer` | Mutató a karakterre. |
| `const_pointer` | Konstans mutató a karakterre. |
| `iterator` | Véletlen elérésű iterátor a karakterekhez. |
| `const_iterator` | Konstans iterátor. |
| `reverse_iterator` | Fordított irányú iterátor. |
| `const_reverse_iterator` | Konstans fordított irányú iterátor. |

---

# std::string Member Functions (Tagfüggvények)

Ez az útmutató a C++ `std::string` osztályának legfontosabb metódusait mutatja be.

## Member functions (Alapvető tagfüggvények)

### (constructor)
Létrehoz egy string objektumot. Többféleképpen inicializálható (üresen, másolatként, karakterláncból stb.).
```cpp
std::string s1;           // Üres string
std::string s2("Szia");   // "Szia" tartalommal
std::string s3(s2);       // Másoló konstruktor
std::string s4(5, 'a');   // "aaaaa" (5 darab 'a' karakter)
```

### (destructor)
Megsemmisíti a stringet, és felszabadítja a lefoglalt memóriát. Automatikusan meghívódik, amikor a változó kikerül a hatóköréből (scope).

### operator=
Értéket ad a stringnek. Lehet egy másik string, egy karaktertömb vagy egy karakter.
```cpp
std::string s;
s = "Hello";        // C-stílusú string hozzárendelése
std::string s2 = s; // Másik std::string hozzárendelése
```

### assign
Új értéket rendel a stringhez, de rugalmasabb, mint az `operator=`. Megadható vele részlet is.
```cpp
std::string s;
s.assign("Hello World", 5); // Csak az első 5 karaktert adja hozzá: "Hello"
```

### assign_range (C++23)
Egy tartomány (range) elemeit rendeli a stringhez.
```cpp
std::vector<char> v = {'H', 'i'};
std::string s;
s.assign_range(v); // s értéke "Hi" lesz
```

### get_allocator
Visszaadja a stringhez tartozó memóriafoglalót (allocator). Ritkán használatos közvetlenül, alacsony szintű memóriakezeléshez kell.
```cpp
auto alloc = s.get_allocator();
```

## Element access (Elemelérés)

### at
Visszaadja a megadott indexen lévő karaktert. **Biztonságos**, mert ellenőrzi, hogy az index a határokon belül van-e (ha nem, `std::out_of_range` hibát dob).
```cpp
std::string s = "Példa";
char c = s.at(1); // 'é'
```

### operator[]
Visszaadja a megadott indexen lévő karaktert. **Gyorsabb**, mint az `at()`, mert nem ellenőrzi a határokat (ha rossz indexet adsz meg, a viselkedése nem meghatározott).
```cpp
std::string s = "Példa";
char c = s[0]; // 'P'
```

### front (C++11)
Visszaadja a string legelső karakterét.
```cpp
std::string s = "Szia";
char c = s.front(); // 'S'
```

### back (C++11)
Visszaadja a string utolsó karakterét.
```cpp
std::string s = "Szia";
char c = s.back(); // 'a'
```

### data
Visszaad egy mutatót a string első karakterére. C++11 óta garantáltan null-terminált karaktertömböt ad vissza.
```cpp
std::string s = "Adat";
const char* ptr = s.data();
```

### c_str
Visszaadja a string tartalmát egy standard C-stílusú karaktertömbként (`const char*`), ami le van zárva egy null-karakterrel (`\0`). Akkor kell, ha régi C-s függvényeknek akarsz átadni egy stringet.
```cpp
std::string s = "Teszt";
printf("%s", s.c_str());
```

### operator basic_string_view (C++17)
Lehetővé teszi a string automatikus átalakítását `std::string_view`-vá. Ez egy olvasásra optimalizált, memóriamásolás nélküli nézet.
```cpp
std::string s = "Nézet";
std::string_view sv = s; // Automatikus konverzió
```

## Iterators (Iterátorok)

Az iterátorok segítségével végigmehetünk a string karakterein (mint egy mutatónál). A `c` előtagú változatok (cbegin, cend) konstans iterátorokat adnak, amikkel nem lehet módosítani a tartalmat.

### begin / cbegin
Iterátor a string elejére.
```cpp
std::string s = "Szia";
auto it = s.begin(); // *it értéke 'S'
```

### end / cend
Iterátor a string végére (az utolsó karakter utáni elméleti pozícióra mutat).
```cpp
auto it_end = s.end();
```

### rbegin / crbegin
Reverz (visszafelé haladó) iterátor a string utolsó karakterére.
```cpp
std::string s = "Szia";
auto rit = s.rbegin(); // *rit értéke 'a'
```

### rend / crend
Reverz iterátor az első karakter előtti elméleti pozícióra.
```cpp
auto rit_end = s.rend();
```

## Capacity (Kapacitás)

### empty
Megvizsgálja, hogy a string üres-e. `true` értéket ad vissza, ha a mérete 0.
```cpp
std::string s = "";
if (s.empty()) { /* A string üres */ }
```

### size / length
Mindkettő ugyanazt csinálja: visszaadja a stringben tárolt karakterek számát.
```cpp
std::string s = "Hello";
size_t len = s.size();   // 5
size_t len2 = s.length(); // 5
```

### max_size
Visszaadja a string által tárolható karakterek elméleti maximumát. Ez egy nagyon nagy szám, amit a rendszer/implementáció korlátoz.
```cpp
std::string s;
std::cout << s.max_size();
```

### reserve
Előre lefoglal egy adott mennyiségű memóriát a stringnek. Ezzel elkerülhető a lassú, többszöri újrafoglalás, ha tudjuk, mekkora lesz a string.
```cpp
std::string s;
s.reserve(100); // 100 karakternek foglal helyet előre
```

### capacity
Visszaadja a jelenleg lefoglalt memória méretét karakterekben mérve. Ez mindig nagyobb vagy egyenlő, mint a `size()`.
```cpp
std::string s = "Szia";
std::cout << s.capacity(); 
```

### shrink_to_fit
Kéri a rendszert, hogy csökkentse a lefoglalt memóriát (capacity) a string aktuális méretére (size), így felszabadítva a felesleget.
```cpp
std::string s = "Nagyon hosszú string";
s.clear();
s.shrink_to_fit(); // Felszabadítja a felesleges memóriát
```

## Modifiers (Módosítók)

### clear
Törli a string teljes tartalmát. A mérete 0 lesz. Működése megegyezik az `erase(begin(), end())` hívással.
- **Kivételkezelés:** `noexcept` (C++11 óta).
- **Fordítási idő:** `constexpr` (C++20 óta).
- **Iterátorok:** Minden mutató, referencia és iterátor, ami a string elemeire mutatott, **érvénytelenné válik**.

**Fontos megjegyzés a memóriáról:**
A `clear()` hívás **nem szabadítja fel a lefoglalt memóriát** (a `capacity` változatlan marad). Ha a memóriát is fel akarod szabadítani, használd utána a `shrink_to_fit()` metódust.

```cpp
#include <cassert>

std::string s = "Példa";
size_t regi_kapacitas = s.capacity();

s.clear();

assert(s.empty());
assert(s.size() == 0);
assert(s.capacity() == regi_kapacitas); // A memória megmaradt
```

### insert
Karaktereket vagy egy másik stringet szúr be egy megadott pozícióba.
```cpp
std::string s = "Hella";
s.insert(4, "o"); // "Hello" (a 4. indexhez szúr be)
```

### insert_range (C++23)
Egy tartomány (pl. egy vektor elemeit) szúrja be a megadott pozícióba.
```cpp
std::vector<char> v = {'!', '?'};
std::string s = "Szia";
s.insert_range(s.end(), v); // "Szia!?"
```

### erase
Karaktereket töröl a stringből egy adott pozíciótól kezdve.
```cpp
std::string s = "Hello World";
s.erase(5, 6); // "Hello" (az 5. indextől töröl 6 karaktert)
```

### push_back
Egyetlen karaktert fűz a string végéhez.
```cpp
std::string s = "Szi";
s.push_back('a'); // "Szia"
```

### pop_back (C++11)
Eltávolítja az utolsó karaktert a stringből.
```cpp
std::string s = "Szia!";
s.pop_back(); // "Szia"
```

### append
Karakterláncot vagy karaktereket fűz a string végéhez. Rugalmasabb, mint a `+=`.
```cpp
std::string s = "Hello";
s.append(" World"); // "Hello World"
```

### append_range (C++23)
Egy tartomány elemeit fűzi a string végéhez.
```cpp
std::vector<char> v = {'1', '2'};
std::string s = "Számok: ";
s.append_range(v); // "Számok: 12"
```

### operator+=
A leggyakoribb módja a hozzáfűzésnek. Működik stringgel, karakterrel és karaktertömbbel is.
```cpp
std::string s = "C++";
s += ' ';
s += "Programozás"; // "C++ Programozás"
```

### replace
A string egy megadott részét kicseréli egy másik karakterláncra.
```cpp
std::string s = "Ez egy alma.";
s.replace(7, 4, "körte"); // "Ez egy körte."
```

### replace_with_range (C++23)
A string egy részét egy tartomány elemeire cseréli.
```cpp
std::string s = "Szia!";
std::vector<char> v = {'?', '?'};
s.replace_with_range(s.begin()+4, s.end(), v); // "Szia??"
```

### copy
Egy részletet másol át a stringből egy külső karaktertömbbe (`dest`). 
- **Fordítási idő:** `constexpr` (C++20 óta).
- **Lezárás:** A másolt karakterlánc **NEM lesz null-terminált** (`\0`), erről manuálisan kell gondoskodni!
- **Paraméterek:** 
  - `dest`: a cél tömb mutatója.
  - `count`: a másolandó karakterek száma.
  - `pos`: a kezdőpozíció (alapértelmezett: 0).

**Kivételkezelés:** `std::out_of_range` hibát dob, ha a kezdőpozíció (`pos`) nagyobb, mint a string hossza. Erős hiba-biztonsági garanciát ad: ha hiba történik, nem változik semmi.

```cpp
#include <iostream>

std::string foo("BOR");
char bar[4]{}; // A kapcsos zárójel kinullázza a tömböt (így lesz \0 a végén)

// Csak 3 karaktert másolunk, a 4. marad a 0 (lezáró karakter)
foo.copy(bar, 3);

std::cout << bar; // "BOR"
```

### resize
Megváltoztatja a string méretét. Ha nagyobb lesz, kitölti (alapértelmezetten nullákkal vagy megadott karakterrel), ha kisebb, levágja a végét.
```cpp
std::string s = "Hello";
s.resize(3);    // "Hel"
s.resize(5, '!'); // "Hel!!"
```

### resize_and_overwrite (C++23)
Hatékony átméretezés, ahol egy lambda függvényben közvetlenül írhatjuk meg a string tartalmát.
```cpp
std::string s;
s.resize_and_overwrite(5, [](char* buf, size_t n) {
    std::memcpy(buf, "Szia!", 5);
    return 5; // A ténylegesen beírt karakterek száma
});
```

### swap
Megcseréli két string tartalmát. Nagyon gyors, mert csak a belső mutatókat cseréli meg.
```cpp
std::string s1 = "A";
std::string s2 = "B";
s1.swap(s2); // s1: "B", s2: "A"
```

## Search (Keresés)

Ezek a függvények `std::string::npos` értéket adnak vissza, ha nem találják meg a keresett elemet.

### find
Megkeresi egy megadott karakterlánc vagy karakter első előfordulását. Visszaadja az első karakter indexét.
```cpp
std::string s = "Hello Világ";
size_t pos = s.find("Világ"); // 6
```

### rfind
Megkeresi az utolsó előfordulást (hátulról kezd keresni).
```cpp
std::string s = "alma fa alma";
size_t pos = s.rfind("alma"); // 8
```

### find_first_of
Megkeresi az első olyan karaktert, amelyik szerepel a megadott listában.
```cpp
std::string s = "Hello 123";
size_t pos = s.find_first_of("0123456789"); // 6 (az első számjegy)
```

### find_first_not_of
Megkeresi az első olyan karaktert, amelyik **nem** szerepel a megadott listában.
```cpp
std::string s = "aaaBaaa";
size_t pos = s.find_first_not_of("a"); // 3 (a 'B' karakter)
```

### find_last_of
Megkeresi az utolsó olyan karaktert, amelyik szerepel a megadott listában.
```cpp
std::string s = "123 Hello 456";
size_t pos = s.find_last_of("0123456789"); // 12 (a '6'-os)
```

### find_last_not_of
Megkeresi az utolsó olyan karaktert, amelyik **nem** szerepel a megadott listában.
```cpp
std::string s = "Teszt...";
size_t pos = s.find_last_not_of("."); // 4 (a 't' karakter)
```

## Operations (Műveletek)

### compare
Összehasonlít két stringet. 0-t ad vissza, ha egyenlőek, negatívat, ha az első kisebb, pozitívat, ha nagyobb (lexikografikusan).
```cpp
std::string s1 = "alma";
std::string s2 = "körte";
if (s1.compare(s2) < 0) { /* s1 előrébb van az ábécében */ }
```

### starts_with (C++20)
Megvizsgálja, hogy a string a megadott előtaggal (prefix) kezdődik-e.
```cpp
std::string s = "Kezdet";
bool b = s.starts_with("Kez"); // true
```

### ends_with (C++20)
Megvizsgálja, hogy a string a megadott utótaggal (suffix) végződik-e.
```cpp
std::string s = "Vége";
bool b = s.ends_with("ge"); // true
```

### contains (C++23)
Egyszerűen ellenőrzi, hogy a string tartalmazza-e a megadott részt vagy karaktert.
```cpp
std::string s = "C++ programozás";
bool b = s.contains("pro"); // true
```

### substr
Kivág és visszaad egy részletet a stringből a megadott pozíciótól, adott hosszúságban.
```cpp
std::string s = "Hello World";
std::string sub = s.substr(6, 5); // "World"
```

## Non-member functions (Külső segédfüggvények)

### operator+
Két stringet, vagy egy stringet és egy karaktert/karaktertömböt fűz össze egy új stringgé.
```cpp
std::string s1 = "Szia ";
std::string s2 = "Világ";
std::string s3 = s1 + s2; // "Szia Világ"
```

### Összehasonlító operátorok (==, !=, <, >, <=, >=, <=>)
Lexikografikusan (ábécérendben) hasonlítanak össze két stringet. C++20 óta a `<=>` (űrhajó operátor) váltja ki a legtöbb régit.
```cpp
std::string s1 = "alma";
std::string s2 = "körte";
if (s1 == s2) { /* Egyenlőek */ }
if (s1 < s2)  { /* s1 előrébb van */ }
```

### std::swap
Kicseréli két string tartalmát. Ez a globális `std::swap` speciális változata stringekre.
```cpp
std::string a = "egy", b = "kettő";
std::swap(a, b);
```

### erase, erase_if (C++20)
Törli a stringből azokat az elemeket, amik megfelelnek egy feltételnek (globális függvények).
```cpp
std::string s = "Hello123";
std::erase(s, 'l'); // "Heo123" (minden 'l'-t töröl)
std::erase_if(s, [](char c) { return std::isdigit(c); }); // "Heo" (minden számjegyet töröl)
```

## Input/output (Be- és kimenet)

### operator<< / operator>>
Lehetővé teszi a string használatát a standard folyamokkal (pl. `cin`, `cout`). Megjegyzés: a `>>` csak az első szóközig olvas.
```cpp
std::string s;
std::cin >> s;      // Beolvasás (szóközig)
std::cout << s;     // Kiírás
```

### getline
Beolvas egy egész sort (szóközzel együtt) egy bemeneti folyamból.
```cpp
std::string line;
std::getline(std::cin, line); // Egy egész sort beolvas
```

## Numeric conversions (Számkonverziók)

### stoi, stol, stoll (C++11)
Stringet konvertál egész számmá (int, long, long long).
```cpp
std::string s = "123";
int i = std::stoi(s); // 123
```

### stoul, stoull (C++11)
Stringet konvertál előjel nélküli egész számmá (unsigned long, unsigned long long).
```cpp
std::string s = "456";
unsigned long ul = std::stoul(s);
```

### stof, stod, stold (C++11)
Stringet konvertál lebegőpontos számmá (float, double, long double).
```cpp
std::string s = "3.14";
double d = std::stod(s); // 3.14
```

### to_string (C++11)
Bármilyen numerikus értéket (int, double stb.) stringgé alakít.
```cpp
int i = 42;
std::string s = std::to_string(i); // "42"
```

### to_wstring (C++11)
Számot konvertál széles karakterű stringgé (`std::wstring`).
```cpp
double d = 1.5;
std::wstring ws = std::to_wstring(d);
```

## Literals (Literálok)

A literálok segítségével közvetlenül a kódba írt szövegeket jelölhetjük meg `std::string` típusként (nem pedig `const char*`-ként). Ehhez a `std::literals::string_literals` névtér használata szükséges.

### operator""s (C++14)
Egy szöveges literált automatikusan `std::string` objektummá alakít.
```cpp
using namespace std::string_literals;

auto s = "Hello"s; // Ez már std::string típusú, nem const char*
```

## Helper classes (Segédosztályok)

### std::hash<std::string> (C++11)
Támogatást nyújt a stringek hash-eléséhez. Ez teszi lehetővé, hogy a stringeket kulcsként használhassuk olyan tárolókban, mint az `std::unordered_map` vagy `std::unordered_set`.
```cpp
std::string s = "Kulcs";
std::hash<std::string> string_hasher;
size_t h = string_hasher(s); // Legenerálja a string hash értékét
```

## Iterátorok érvénytelenítése (Iterator invalidation)

Nagyon fontos szabály: a string elemeire mutató referenciák, mutatók és iterátorok **érvénytelenné válhatnak** (vagyis nem biztonságos a használatuk), ha a stringet módosítjuk.

**Mikor válhatnak érvénytelenné?**
- Bármilyen nem-konstans (módosító) művelet után (pl. `append`, `insert`, `push_back`, `clear`, `operator+=`).
- Olyan globális függvények után, amik nem-konstans referenciát kapnak (pl. `std::getline`, `std::swap`, `operator>>`).

**Kivételek (amik NEM érvénytelenítik az iterátorokat):**
- Alapvető elérés: `operator[]`, `at`, `front`, `back`, `data`.
- Iterátor lekérés: `begin`, `rbegin`, `end`, `rend`.

## Megjegyzések (Notes)

- **C++20 Constexpr:** C++20 óta az `std::string` legtöbb függvénye használható `constexpr` kontextusban (fordítási időben végrehajtható műveletek).
- **Memóriakezelés:** Bár a C++23-ig voltak elméleti finomítások a konstruktoroknál, a gyakorlatban minden fordító a standard, hatékony memóriakezelést használta eddig is.

## Verzió-követési makrók (Feature-test macros)

Ha biztosra akarsz menni, hogy a fordítód támogatja-e az új funkciókat, ezeket a makrókat ellenőrizheted:

| Makró neve | Szabvány | Funkció |
| :--- | :--- | :--- |
| `__cpp_lib_string_udls` | C++14 | String literálok (`"..."s`) |
| `__cpp_lib_starts_ends_with` | C++20 | `starts_with`, `ends_with` |
| `__cpp_lib_erase_if` | C++20 | Globális `erase`, `erase_if` |
| `__cpp_lib_string_contains` | C++23 | `contains` metódus |
| `__cpp_lib_string_resize_and_overwrite` | C++23 | `resize_and_overwrite` |
| `__cpp_lib_containers_ranges` | C++23 | Range alapú konstruktorok és módosítók |

## Data members (Adattagok)

### npos [static]
Egy speciális konstans érték (gyakorlatilag -1, de `size_t` típusként a lehető legnagyobb szám), ami azt jelzi, hogy "nem található" vagy "a string végéig".
```cpp
std::string s = "Példa";
if (s.find("x") == std::string::npos) {
// "x" nincs benne a stringben
}
```

## Preprocessor (Előfeldolgozó direktívák)

Ezek a parancsok a fordítás tényleges megkezdése előtt futnak le. Mindig `#` jellel kezdődnek.

### #if, #ifdef, #ifndef, #elif, #else, #endif
Feltételes fordítást tesznek lehetővé. Csak azok a részek kerülnek a fordítóhoz, amikre a feltétel igaz.
```cpp
#define DEBUG_LEVEL 2

#if DEBUG_LEVEL > 1
// Ez a rész csak akkor fordul le, ha a DEBUG_LEVEL > 1
#elif DEBUG_LEVEL == 1
// Ez pedig ha pontosan 1
#else
// Minden más esetben
#endif

#ifdef MY_MACRO
// Ha a MY_MACRO definiálva van
#endif

#ifndef HEADER_H
#define HEADER_H
// Tipikus "include guard" szerkezet
#endif
```

### #elifdef, #elifndef (C++23)
A C++23-as szabvány tette lehetővé az `ifdef` és `ifndef` tömörített változatát az `elif` ágakban.
```cpp
#ifdef VERSION_A
// ...
#elifdef VERSION_B  // C++23: "Else if defined"
// ...
#endif
```

### #define, #, ##
Makrók definiálására és szöveghelyettesítésre szolgálnak.
- `#`: "Stringizing" – idézőjelek közé teszi a paramétert.
- `##`: "Token pasting" – összefűz két szövegrészletet.
```cpp
#define PI 3.14
#define STR(x) #x          // STR(teszt) -> "teszt"
#define CONCAT(a, b) a##b  // CONCAT(var, 1) -> var1
```

### #include
Beilleszti egy másik fájl tartalmát.
- `< >`: Rendszerkönyvtárakhoz (standard library).
- `" "`: Saját, projektbeli fájlokhoz.
```cpp
#include <iostream>
#include "my_header.h"
```

### #pragma
Fordító-specifikus utasítások. A leggyakoribb a `once`, ami kiváltja a régi bonyolult include guardokat.
```cpp
#pragma once // Megakadályozza a fájl többszöri beillesztését
```

### #line, #error
A `#line` a hibajelentések sorszámozását írja felül, a `#error` pedig leállítja a fordítást egy hibaüzenettel.
```cpp
#ifndef IMPORTANT_LIB
#error "Ez a könyvtár kötelező!"
#endif
```

### #warning (C++23)
C++23 óta szabványosított figyelmeztetés, ami nem állítja le a fordítást, de üzenetet küld a fejlesztőnek.
```cpp
#warning "Ez a kód elavult, használd az újat!"
```

## ASCII Táblázat és Használata

Az ASCII (American Standard Code for Information Interchange) egy karakterkódolási szabvány, amely 128 karaktert rendel számokhoz (0-127).

### Gyakorlati példák C++-ban

#### 1. Betűméret váltása (Matematikai úton)
Mivel a kis- és nagybetűk között fix 32 a különbség:
```cpp
char nagy = 'A';
char kicsi = nagy + 32; // 'a'
```

#### 2. Karakter ellenőrzése (Intervallummal)
```cpp
char c = '5';
if (c >= 48 && c <= 57) {
    // Ez egy számjegy, mert az ASCII értéke 48 és 57 közé esik
}
// Ugyanez olvashatóbban:
if (c >= '0' && c <= '9') { ... }
```

#### 3. Speciális vezérlőkarakterek
| Kód | Név | C++ jelölés | Leírás |
| :--- | :--- | :--- | :--- |
| 0 | NUL | `\0` | String vége jelző |
| 7 | BEL | `\a` | Rendszerhang (csipogás) |
| 8 | BS | `\b` | Backspace (visszatörlés) |
| 9 | HT | `\t` | Tabulátor |
| 10 | LF | `\n` | Új sor |
| 13 | CR | `\r` | Kocsi-vissza (sor elejére ugrik) |

### Az ASCII Tábla (Rövidített változat a legfontosabbakkal)

| Dec | Hex | Karakter | Leírás |
| :--- | :--- | :--- | :--- |
| 0 | 00 | NUL | Null karakter |
| 32 | 20 | (space) | Szóköz |
| 33 | 21 | ! | Felkiáltójel |
| 48-57 | 30-39 | 0-9 | Számjegyek |
| 65-90 | 41-5A | A-Z | Angol nagybetűk |
| 97-122 | 61-7A | a-z | Angol kisbetűk |
| 126 | 7E | ~ | Tilde |
| 127 | 7F | DEL | Törlés |

## Írásjelek és Operátorok (Punctuation & Operators)

A C++ írásjelei határozzák meg a kód szerkezetét és a műveletek elvégzését.

### Preprocessing Operátorok
| Jel | Leírás | Példa |
| :--- | :--- | :--- |
| `#` | Stringgé alakítás (Stringification) | `#define STR(x) #x` |
| `##` | Összefűzés (Token pasting) | `a##b` -> `ab` |

### Határolójelek és Zárójelek
| Jel | Leírás | Használat |
| :--- | :--- | :--- |
| `{ }` | Blokk kezdete és vége | Függvények, osztályok, ciklusok törzse. |
| `[ ]` | Indexelés / Lambda capture | `tomb[5]`, `[capture](params){...}` |
| `( )` | Csoportosítás / Függvényhívás | `(a + b) * c`, `fuggveny(param)` |
| `;` | Utasítás lezárása | Minden utasítás végére kötelező. |
| `,` | Elválasztójel | Paraméterlistákban, inicializáláskor. |

### Szögletes és Sima Zárójelek Részletesen

A zárójelek a C++ leggyakrabban használt, de legsokoldalúbb írásjelei.

#### 1. Szögletes zárójel `[ ]` (Brackets)
*Alternatív írásmód: `<:` és `:>`*

- **Indexelés:** Tömbök vagy konténerek elemeinek elérése (`tomb[i]`).
- **Tömb deklaráció:** Tömb méretének megadása (`int tomb[10]`).
- **Dinamikus foglalás:** `new[]` és `delete[]` operátoroknál a tömb jelzése.
- **Lambda Capture:** Lambdáknál a kívülről elért változók listája (`[=](int x){...}`).
- **Attribútumok (C++11):** Speciális fordítói utasítások jelölése (`[[nodiscard]]`, `[[maybe_unused]]`).
- **Structured Binding (C++17):** Összetett típusok (pl. struct, pair) elemeinek kicsomagolása (`auto [x, y] = pont;`).
- **Pack Indexing (C++26):** Paraméter-csomagok elemeinek indexelése.

#### 2. Sima zárójel `( )` (Parentheses)

- **Kifejezések csoportosítása:** Műveleti sorrend módosítása (`(a + b) * c`).
- **Függvényhívás:** Függvények meghívása és argumentumok átadása (`fuggveny(arg1)`).
- **Típuskonverzió (C-style cast):** `(int)3.14` vagy `int(3.14)`.
- **Névvel ellátott cast-ok:** `static_cast<int>(x)`, `dynamic_cast<T*>(obj)`.
- **Operandusok körülzárása:** Kötelező a következő operátoroknál:
  - `sizeof(tipus)`
  - `typeid(objektum)`
  - `noexcept(kifejezes)`
  - `alignof(tipus)`
  - `decltype(kifejezes)`
- **Vezérlési szerkezetek:** `if`, `switch`, `while`, `for` feltételeinek és fejlécének elhatárolása.
- **Paraméterlista:** Függvények deklarációjánál a paraméterek felsorolása.

### Tagság és Hatókör elérése
| Jel | Leírás | Példa |
| :--- | :--- | :--- |
| `::` | Hatókör feloldása (Scope resolution) | `std::string`, `Osztaly::Metodus` |
| `.` | Közvetlen tagnév elérés | `objektum.adat` |
| `->` | Közvetett tagnév elérés (mutatónál) | `mutato->adat` |

### Összetett (Compound) Értékadó Operátorok
Rövidített formák, amik elvégzik a műveletet és az eredményt el is tárolják:
`+=`, `-=`, `*=`, `/=`, `%=`, `^=`, `&=`, `|=`, `<<=`, `>>=`
```cpp
int x = 10;
x += 5; // x = x + 5; (eredmény: 15)
```

### Logikai és Összehasonlító Operátorok
| Jel | Leírás | Alternatív név |
| :--- | :--- | :--- |
| `&&` | Logikai ÉS | `and` |
| `||` | Logikai VAGY | `or` |
| `!` | Logikai NEM | `not` |
| `==` | Egyenlőség vizsgálat | - |
| `!=` | Egyenlőtlenső vizsgálat | `not_eq` |
| `<=>` | Háromirányú összehasonlítás (C++20) | "Spaceship" operátor |

### Matematikai és Bitműveleti Operátorok

Ezek a jelek végzik az alapvető számításokat és az alacsony szintű bitműveleteket.

| Jel | Név / Leírás | Alternatív név | Példa |
| :--- | :--- | :--- | :--- |
| `/` | Osztás | - | `10 / 2` -> `5` |
| `%` | Moduló (Osztási maradék) | - | `10 % 3` -> `1` |
| `^` | Bitműveleti XOR (Kizáró VAGY) | `xor` | `a ^ b` |
| `&` | Bitműveleti ÉS | `bitand` | `a & b` |
| `|` | Bitműveleti VAGY | `bitor` | `a | b` |

#### Az `&` jel sokszínűsége C++-ban:
1. **Címképzés:** Lekéri egy változó memóriacímét. (`&x`)
2. **Bitműveleti ÉS:** Összehasonlítja két szám bitjeit. (`a & b`)
3. **Lvalue-referencia:** Típusként jelzi, hogy egy változó egy másikra hivatkozik. (`int& ref = x;`)
4. **Lambda referencia capture:** Jelzi, hogy a lambda kívülről referenciaként kapja meg a változót. (`[&x]{...}`)
5. **Ref-qualifier:** Tagfüggvényeknél jelzi, hogy a függvény csak balérték (lvalue) objektumon hívható meg.

### Egyéb fontos jelek
- `*` : Dereferencia (mutató értéke) vagy szorzás.
- `&` : Címképzés vagy referencia típus.
- `~` : Bitműveleti NEM vagy destruktor jele.
- `? :` : Ternáris operátor (egysoros feltétel).
- `...` : Variadikus sablonok (pack expansion) vagy elkapó ág (`catch(...)`).
- `++` / `--` : Inkrementálás / Dekrementálás (növelés/csökkentés eggyel).

### Különleges operátor-kulcsszavak

Vannak olyan operátorok, amik nem jelekből, hanem szavakból állnak:

#### 1. sizeof
Visszaadja egy típus vagy változó méretét **bájtokban**. Fordítási időben dől el.
```cpp
int x = 10;
size_t s1 = sizeof(x);    // int mérete (általában 4 bájt)
size_t s2 = sizeof(double); // double mérete (általában 8 bájt)
```

#### 2. sizeof... (C++11)
Variadikus sablonoknál (template pack) megadja a csomagban lévő elemek számát.
```cpp
template<typename... Args>
void f(Args... args) {
    size_t db = sizeof...(args); // Megszámolja, hány paramétert kaptunk
}
```

#### 3. typeid
Lekérdezi egy objektum típusinformációját futási időben.
```cpp
#include <typeinfo>
std::cout << typeid(x).name(); // Kiírja a típus nevét
```

#### 4. alignof (C++11)
Visszaadja a megadott típus igazítási (alignment) követelményét bájtokban.
```cpp
size_t a = alignof(int); // Megmutatja, hány bájtra kell igazítani az int-et
```

#### 5. decltype (C++11)
Lekérdezi egy kifejezés típusát (fordítási időben), így típusneveket "gyárthatunk" vele.
```cpp
int x = 5;
decltype(x) y = 10; // y típusa int lesz, mert x is az
```

### Specifikátorok és Statikus ellenőrzések

Ezek a kulcsszavak speciális nyelvi funkciókat látnak el, és zárójeleket `()` használnak a megadott értékek (operandusok) elkülönítésére.

#### 1. static_assert (C++11)
**Fordítási idejű ellenőrzés.** Ha a zárójelek között megadott feltétel hamis, a fordítás hibaüzenettel leáll. Segít megelőzni a hibás konfigurációkat.
```cpp
static_assert(sizeof(int) >= 4, "Az int mérete legalább 4 bájt kell legyen!");
```

#### 2. noexcept (C++11)
Két szerepe is van:
- **Specifikátorként:** Jelzi, hogy egy függvény dobhat-e kivételt.
- **Operátorként:** A zárójelek közötti kifejezésről eldönti (fordítási időben), hogy dobhat-e kivételt.
```cpp
void biztonsagos() noexcept; // A függvény nem fog kivételt dobni
bool b = noexcept(1 + 1);    // true
```

#### 3. alignas (C++11)
Megadja egy változó vagy típus **memória-igazítási** (alignment) követelményét a zárójelek között.
```cpp
alignas(16) float tomb[4]; // A tömb 16-bájtos határhoz lesz igazítva a memóriában
```

#### 4. decltype (C++11)
Lekérdezi a zárójelek közé írt kifejezés típusát fordítási időben.
```cpp
int x = 10;
decltype(x) y = 20; // y típusa int lesz, mert x típusa is az
```

## Vezérlési szerkezetek (Control Structures)

Ezek a szerkezetek határozzák meg, hogy a kód mely részei és hányszor fussanak le.

### Feltételes elágazások

#### 1. if / else
Alapvető feltételvizsgálat.
```cpp
if (x > 0) {
    // Ha igaz
} else {
    // Ha hamis
}
```

#### 2. consteval if (C++23)
Lehetővé teszi, hogy a kód egy része csak akkor fusson le, ha a függvényt **fordítási időben** (constant evaluation) hívták meg.
```cpp
if consteval {
    // Csak fordítási időben fut le
} else {
    // Futási időben fut le
}
```

#### 3. switch
Többirányú elágazás fix értékek alapján.
```cpp
switch (nap) {
    case 1: std::cout << "Hétfő"; break;
    case 2: std::cout << "Kedd"; break;
    default: std::cout << "Egyéb nap";
}
```

### Ciklusok (Loops)

#### 1. while
Elöltesztelő ciklus: addig fut, amíg a feltétel igaz. Lehet, hogy egyszer sem fut le.
```cpp
while (x < 10) {
    x++;
}
```

#### 2. do-while
Hátultesztelő ciklus: **legalább egyszer mindenképpen lefut**, mert a vizsgálat a végén van.
```cpp
do {
    // Egyszer biztosan lefut
} while (feltetel);
```

#### 3. for
Hagyományos számlálós ciklus.
```cpp
for (int i = 0; i < 5; i++) {
    // 0-tól 4-ig fut
}
```

#### 4. Range-based for (C++11)
A legegyszerűbb módja egy konténer (pl. string vagy vector) összes elemén való végighaladásnak.
```cpp
std::string s = "Szia";
for (char c : s) {
    std::cout << c << " ";
}
```

## Lambda kifejezések (Lambdas)

A lambdák névtelen függvények, amiket közvetlenül a felhasználás helyén definiálhatunk. Rendkívül hasznosak algoritmusoknál (pl. `std::sort`).

### Szintaxis felépítése
`[ elkapás ] <sablon> ( paraméterek ) módosítók -> visszatérési_típus { törzs }`

#### 1. Captures (Elkapási lista) `[ ]`
Meghatározza, hogy a lambda mely külső változókat érheti el.
- `[x]`: `x`-et érték szerint kapja meg (másolat).
- `[&x]`: `x`-et referenciaként kapja meg.
- `[=]`: Minden külső változót érték szerint kap meg.
- `[&]`: Minden külső változót referenciaként kap meg.
- `[this]`: Az aktuális osztálypéldány elérése.

#### 2. Template parameters (C++20) `< >`
Generikus lambdákhoz használható, ahol megadhatunk konkrét típusparamétereket.
```cpp
auto l = []<typename T>(std::vector<T> v) { return v.size(); };
```

#### 3. Specifikátorok (Specifiers)
- **mutable**: Alapértelmezés szerint az érték szerint elkapott változók nem módosíthatók a lambdán belül. A `mutable` kulcsszóval ez engedélyezhető.
- **constexpr (C++17)**: Jelzi, hogy a lambda lefuthat fordítási időben.
- **consteval (C++20)**: Garantálja, hogy a lambda *csak* fordítási időben futhat le.
- **static (C++23)**: A lambdát statikus függvényként kezeli, ami gyorsabb hívást tesz lehetővé (de nem kaphat el változókat).

#### 4. Explicit object parameter (C++23)
Lehetővé teszi a "deduced this" használatát, így a lambda hivatkozhat saját magára (pl. rekurzióhoz).

#### 5. Visszatérési típus (Trailing return type) `->`
Opcionális, a fordító általában kitalálja, de bonyolult esetekben kézzel is megadható.
```cpp
auto l = [](int x) -> double { return x * 1.5; };
```

#### 6. Requirements (C++20) `requires`
Megkötéseket (concepts) szabhatunk a lambda típusparamétereire.
```cpp
auto l = []<typename T>(T x) requires std::integral<T> { return x + 1; };
```

#### 7. Contracts (C++26)
Lehetővé teszi elő- és utófeltételek megadását a lambda törzsében.
```cpp
auto l = [](int x) [[pre: x > 0]] { return 100 / x; };
```

### Utasítások és Ciklusvezérlés (Statements)

Ezek az utasítások finomhangolják a ciklusok futását és a függvényekből való visszatérést.

#### 1. continue és break
- **break**: Azonnal kilép a legbelső ciklusból vagy `switch`-ből.
- **continue**: Kihagyja a ciklus törzsének hátralévő részét, és a következő iterációval folytatja.
```cpp
for (int i = 0; i < 10; i++) {
    if (i == 3) continue; // Kihagyja a 3-ast
    if (i == 7) break;    // Megáll 7-nél
    std::cout << i;
}
```

#### 2. goto és return
- **return**: Kilép a függvényből, és opcionálisan visszaad egy értéket.
- **goto**: Egy címkére (label) ugrik a kódon belül. **Használata kerülendő**, mert nehezen olvashatóvá teszi a kódot (úgynevezett "spagetti kód").
```cpp
if (hiba) goto error_handler;
// ...
error_handler:
    std::cout << "Hiba történt!";
```

#### 3. contract_assert (C++26)
A C++26 szabvány része, amely lehetővé teszi a "szerződés alapú" programozást. Futási időben ellenőrzi a feltételeket, hasonlóan a `static_assert`-hez, de ez futás közben él.
```cpp
void feldolgoz(int n) {
    contract_assert(n > 0); // Garantálja, hogy n pozitív
}
```

#### 4. Szinkronizációs utasítások (synchronized / atomic)
- **synchronized** (TM TS): Olyan kódblokkot jelöl, amely biztosítja, hogy egyszerre csak egy szál futtassa (szálbiztos elérés).
- **atomic**: Olyan műveleteket vagy blokkokat jelöl, amelyek megszakíthatatlanok és láthatóak más szálak számára.
```cpp
synchronized {
    // Ez a blokk szálbiztos (ha a fordító támogatja a kísérleti funkciót)
}
```

## Azonosítók (Identifiers)

Az azonosító egy tetszőleges hosszúságú karaktersorozat, amellyel entitásokat (változókat, függvényeket, típusokat stb.) nevezünk meg.

### Elnevezési szabályok
- **Kezdő karakter:** Csak angol ábécé betűje (A-Z, a-z) vagy alulvonás (`_`) lehet. Számjeggyel nem kezdődhet!
- **További karakterek:** Betűk, számjegyek (0-9) és alulvonás.
- **Kis- és nagybetű érzékenység:** Az `adat`, `Adat` és `ADAT` három különböző azonosító.
- **Unicode:** A modern C++ támogatja a Unicode karaktereket is az azonosítókban (bár a gyakorlatban ritkábban használják a hordozhatóság miatt).

### Foglalt (Reserved) azonosítók
Bizonyos neveket tilos használni, mert a fordító vagy a standard könyvtár számára vannak fenntartva:
1. **Kulcsszavak:** Pl. `int`, `class`, `if`, `while` nem lehet változónév.
2. **Alulvonással kezdődő nevek:**
   - A globális névtérben az alulvonással kezdődő nevek foglaltak.
   - Bárhol foglaltak a dupla alulvonást (`__`) tartalmazó, vagy alulvonással és nagybetűvel kezdődő nevek (pl. `_Adat`).
3. **Speciális jelentésű szavak (C++20):** Az `import`, `module`, `override`, `final` bizonyos környezetben speciális jelentéssel bírnak.

### Minősítetlen és Minősített azonosítók

#### Minősítetlen (Unqualified)
Egyszerű nevek, hatókör-feloldó operátor nélkül.
```cpp
int x = 5;      // x egyszerű azonosító
operator+;      // operátor függvény neve
~SajatOsztaly;  // destruktor neve
```

#### Minősített (Qualified)
A hatókör-feloldó operátort (`::`) használják egy konkrét névtér vagy osztály tagjának eléréséhez.
```cpp
std::string s;       // a string az std névtérből
std::string::npos;   // az npos a string osztály statikus tagja
::tolower('A');      // a globális névtérbeli tolower hívása
```

### Implicit `this->` átalakítás
Osztályokon belül, ha egy nem-statikus adattagra hivatkozol, a fordító azt automatikusan `this->név` formára alakítja át (kivéve sablonoknál bizonyos esetekben).
```cpp
struct Adat {
    int x;
    void f() {
        x = 10; // A háttérben: this->x = 10;
    }
};
```

### Nevek (Names)
A "név" fogalma tágabb az azonosítónál. Névnek számít:
- Maga az azonosító.
- Túlterhelt operátor függvény jelölése (`operator+`).
- Felhasználó által definiált literál operátor (`operator ""_km`).
- Sablonnév az argumentumaival együtt (`Lista<int>`).

## Típus-azonosítók (Type-id)

A `type-id` egy olyan elnevezés, amely pontosan meghatároz egy típust. Használjuk castolásnál (`static_cast`), operátoroknál (`sizeof`, `new`) vagy sablonparamétereknél.

### Példák típus-azonosítókra

#### 1. Egyszerű típusok és mutatók
```cpp
int* p;               // "int*" a típus-azonosító
static_cast<int*>(p); // Itt is "int*" szerepel
```

#### 2. Tömbök
```cpp
int a[3];             // "int[3]" a típus-azonosító
new int[3];           // Dinamikus foglalásnál is "int[3]"
```

#### 3. Függvénytípusok (std::function-höz)
```cpp
void f(int); 
std::function<void(int)> x = f;          // A type-id: "void(int)"
std::function<auto(int) -> void> y = f;  // Ugyanaz trailing return típussal
```

#### 4. Összetett, bonyolult típusok
Deklarációkban és `new` operátornál a zárójelezés rendkívül fontos:
```cpp
// 2 darab mutatót tartalmazó tömb, amik olyan függvényekre mutatnak, 
// amik 3 elemű int tömbre mutató pointert adnak vissza:
int (*(*x[2])())[3];
new (int (*(*[2])())[3]); // A zárójelezés kötelező a type-id körül!
```

### Gyakori hibák és korlátozások

- **Típusdefiniálás tilalma:** Nem hozhatsz létre új típust egy `sizeof` kifejezésen belül.
```cpp
sizeof(struct { int x; }); // HIBA: nem definiálható új típus itt
```

- **Tárolási osztályok:** A `static`, `extern`, `thread_local` kulcsszavak nem részei a típusnak, így nem szerepelhetnek type-id-ban.
```cpp
sizeof(static int); // HIBA: a static nem típus-specifikátor
```

- **Függvény-specifikátorok:** Az `inline` vagy `virtual` szavak szintén nem részei a típusnak.
```cpp
std::function<inline void(int)> f; // HIBA: az inline nem lehet a típus része
```

## Statikus és Dinamikus típusok

A C++-ban fontos különbséget tenni a változó fordítási idejű és futási idejű típusa között.

### 1. Statikus típus (Static type)
Ez az a típus, amit a fordító a kód elemzésekor (fordítási időben) rendel egy kifejezéshez. Ez a típus **soha nem változik** a program futása során.

### 2. Dinamikus típus (Dynamic type)
Polimorf objektumok esetén (ahol van legalább egy virtuális függvény) egy mutató vagy referencia a tényleges, legszármaztatottabb objektumra mutathat. Ez a típus futás közben derül ki.

```cpp
struct B { virtual ~B() {} }; // Polimorf bázisosztály
struct D : B {};              // Származtatott osztály

D d;
B* ptr = &d;

// (*ptr) statikus típusa: B
// (*ptr) dinamikus típusa: D (mivel valójában egy D objektumra mutat)
```

## Nem teljes típusok (Incomplete types)

Egy típus akkor számít "nem teljesnek", ha a fordító tud a létezéséről, de még nem ismeri a pontos méretét vagy belső felépítését.

### Mik számítanak nem teljes típusnak?
- A `void` típus.
- Olyan osztályok/struktúrák, amiket csak deklaráltunk, de nem definiáltunk (`class X;`).
- Ismeretlen méretű tömbök (`extern int tomb[];`).
- Olyan tömbök, amiknek az elemei nem teljes típusúak.
- Olyan `enum`-ok, amiknek még nem dőlt el az alapértelmezett típusa.

### Mikor KÖTELEZŐ a teljes típus (Complete type)?
Általánosságban minden olyan esetben, amikor a fordítónak ismernie kell a típus **méretét** vagy **memóriaképét**:
- Objektum létrehozása (`X x;`).
- Függvényhívás, ha a típus visszatérési érték vagy paraméter.
- `sizeof`, `typeid` vagy `alignof` operátor használata.
- Osztályöröklődés (a bázisosztálynak teljesnek kell lennie).
- Tagműveletek elérése (`obj.adat`).
- Mutató-aritmetika (`ptr++`), mert tudni kell, hány bájtot ugorjon.

### Példa: Típus kiegészítése
```cpp
struct X;            // Előzetes deklaráció (X most nem teljes)
extern X* xp;        // OK: mutatónál nem kell tudni a méretet

void hiba() {
    xp++;            // HIBA: X nem teljes, nem tudjuk mekkora egy elem
}

struct X { int i; }; // Definíció (X most már TELJES)

void ok() {
    xp++;            // OK: Most már ismerjük a méretét
}
```

### Ismeretlen méretű tömbök
```cpp
extern int arr[];   // Nem teljes típus
typedef int UNKA[]; // Szintén nem teljes

UNKA* arrp;         // Mutató egy nem teljes típusra

void teszt() {
    arrp++;         // HIBA: a méret ismeretlen
}

int arr[10];        // A típus most már teljes (10 elemű int tömb)
```

## Kifejtett típus-specifikátor (Elaborated type specifier)

Ez a technika lehetővé teszi egy osztály (`class`, `struct`, `union`) vagy `enum` elérését akkor is, ha a nevét "eltakarta" egy másik deklaráció (például egy ugyanilyen nevű változó vagy függvény).

```cpp
struct Adat { int x; };
int Adat = 10; // Az 'Adat' név most már egy int változót takar, elrejtve a struktúrát

// Adat a;      // HIBA: a fordító int-nek nézi
struct Adat a;  // OK: a 'struct' kulcsszóval jelezzük, hogy a típusra gondolunk
```

## Alapvető típusok (Fundamental types)

A C++ beépített, alapvető típusai, amelyekből minden más típus felépül.

### 1. void
Olyan típus, amelynek nincs értékkészlete.
- **Nem teljes típus:** nem hozható létre `void` típusú objektum vagy tömb.
- **Használata:** Függvények visszatérési értékeként (ha nincs visszatérés) vagy általános mutatóként (`void*`).
```cpp
void fuggveny(); // Nincs visszatérési érték
void* ptr;       // Általános mutató bármilyen típusra
```

### 2. std::nullptr_t (C++11)
A null pointer literál (`nullptr`) saját típusa.
- Segít megkülönböztetni a nullát (0) a valódi null mutatótól.
- Mérete megegyezik egy sima mutatóéval (`void*`).
```cpp
#include <cstddef>
std::nullptr_t null_ertek = nullptr;
```

### 3. std::meta::info (C++26)
A reflexiós értékek típusa. A fordítási idejű kódvizsgálathoz és kódgeneráláshoz használatos.
```cpp
#include <meta>
// C++26 kísérleti funkció a nyelvi elemek leírására
```

### 4. Egész típusok (Integral types)

#### Alaptípus: int
Az alapvető egész szám típus. Minimális mérete 16 bit, de modern rendszereken (32/64 bit) szinte mindig legalább 32 bites.

#### Módosítók (Modifiers)
Az `int` típus tulajdonságait változtathatjuk meg velük. Bármilyen sorrendben írhatók.

**Előjel (Signedness):**
- **signed**: Előjeles szám (alapértelmezett, ha elhagyjuk).
- **unsigned**: Csak pozitív számok (és a nulla) tárolására.

**Méret (Size):**
- **short**: Legalább 16 bit, helytakarékos megoldás.
- **long**: Legalább 32 bit.
- **long long** (C++11): Legalább 64 bit.

```cpp
unsigned long long ul = 500ULL;
```

### 4. Egész típusok (Integral types) - Részletesen

A C++ garantálja az egyes típusok minimális bitméretét, de a pontos méret platformfüggő.

| Típus | Minimális méret | Leírás |
| :--- | :--- | :--- |
| `signed char` | 8 bit | Előjeles karakter/szám. |
| `unsigned char` | 8 bit | Előjel nélküli karakter/szám. Nyers memóriavizsgálathoz is használt. |
| `short` | 16 bit | Rövid egész szám. |
| `int` | 16 bit | Alapértelmezett egész (modern gépeken 32 bit). |
| `long` | 32 bit | Hosszú egész szám. |
| `long long` (C++11)| 64 bit | Nagyon hosszú egész szám. |

**std::size_t:** Egy speciális, előjel nélküli egész típus. Ezt adják vissza a `sizeof`, `sizeof...` és `alignof` operátorok.

### 5. Logikai típus (Boolean type)

- **bool**: Két értéket vehet fel: `true` (igaz) vagy `false` (hamis).
- **Mérete:** Implementációfüggő, gyakran 1 bájt, de nem garantált.

### 6. Karakter típusok (Character types)

- **char**: A rendszer számára leghatékonyabb karakter típus. Lehet előjeles vagy előjel nélküli (platformfüggő).
- **wchar_t**: Széles karakterek tárolására. Windows-on általában 16 bites (UTF-16), Linuxon 32 bites (UTF-32).
- **char8_t** (C++20): Kifejezetten UTF-8 karakterekhez (8 bit).
- **char16_t** (C++11): UTF-16 karakterekhez (16 bit).
- **char32_t** (C++11): UTF-32 karakterekhez (32 bit).

### Méret garanciák (Size guarantees)

A C++ szabvány garantálja a következő sorrendet (méretben):
`1 == sizeof(char) ≤ sizeof(short) ≤ sizeof(int) ≤ sizeof(long) ≤ sizeof(long long)`

Ez azt jelenti, hogy egy `int` sosem lehet kisebb, mint egy `short`, de lehetnek egyforma méretűek is.

### 7. Lebegőpontos típusok (Floating-point types)

Tizedes törtek tárolására szolgáló típusokat. A legtöbb modern rendszeren az IEEE-754 szabványt követik.

| Típus | Leírás | Jellemző formátum |
| :--- | :--- | :--- |
| `float` | Egyszeres pontosságú lebegőpontos szám. | 32-bit (binary32) |
| `double` | Kétszeres pontosságú lebegőpontos szám. | 64-bit (binary64) |
| `long double` | Kiterjesztett pontosságú szám. | Platformfüggő (80 vagy 128 bit) |

#### Speciális értékek
A lebegőpontos típusok képesek különleges állapotok tárolására is:
- **Végtelen (Infinity):** Pozitív és negatív irányban is (pl. nullával való osztáskor).
- **Negatív nulla (`-0.0`):** Matematikailag egyenlő a sima nullával, de bizonyos műveleteknél (pl. komplex számoknál) számít az iránya.
- **Nem szám (NaN - Not-a-Number):** Érvénytelen műveletek eredménye (pl. `0.0 / 0.0`). Nem egyenlő semmivel, még saját magával sem!

#### Megjegyzések a pontosságról
- A lebegőpontos számításoknál kerekítési hibák léphetnek fel. Soha ne hasonlíts össze két lebegőpontos számot közvetlen egyenlőséggel (`==`)! Ehelyett nézd meg, hogy a különbségük kisebb-e egy nagyon kicsi számnál (epszilon).
- A C++23 bevezette a fix szélességű lebegőpontos típusokat is (opcionális támogatás a fordítótól).

### 8. Értéktartományok (Range of values)

- **Egész számok:** C++20 óta kötelező a **kettes komplemens** (two's complement) ábrázolás. Egy N-bites előjeles egész tartománya: $-2^{N-1}$-től $+2^{N-1}-1$-ig terjed (pl. 8 biten: -128-tól 127-ig).
- **Lebegőpontos számok:** A tartományuk a legkisebb ábrázolható véges negatív számtól a legnagyobb véges pozitív számig terjed, de a végtelen (infinity) támogatásával minden valós számot lefednek elméletben.

### 9. Típusok mérete és tartománya (Összefoglaló táblázat)

| Típus csoport | Méret (bit) | Formátum | Értéktartomány (Hozzávetőleges) |
| :--- | :--- | :--- | :--- |
| **Karakter** | 8 | signed | -128 ... 127 |
| | 8 | unsigned | 0 ... 255 |
| | 16 | UTF-16 | 0 ... 65,535 |
| | 32 | UTF-32 | 0 ... 1,114,111 |
| **Egész** | 16 | signed | ± 3.27 · 10⁴ |
| | 16 | unsigned | 0 ... 6.55 · 10⁴ |
| | 32 | signed | ± 2.14 · 10⁹ |
| | 32 | unsigned | 0 ... 4.29 · 10⁹ |
| | 64 | signed | ± 9.22 · 10¹⁸ |
| | 64 | unsigned | 0 ... 1.84 · 10¹⁹ |
| **Lebegőpontos** | 32 | IEEE-754 | ± 1.17 · 10⁻³⁸ ... ± 3.40 · 10³⁸ |
| | 64 | IEEE-754 | ± 2.22 · 10⁻³⁰⁸ ... ± 1.79 · 10³⁰⁸ |
| | 80 | x86 ext. | ± 3.36 · 10⁻⁴⁹³² ... ± 1.18 · 10⁴⁹³² |
| | 128 | IEEE-754 | ± 3.36 · 10⁻⁴⁹³² ... ± 1.18 · 10⁴⁹³² |

### 10. Adatmodellek (Data models)

A fordítók és operációs rendszerek választása a típusok méretére vonatkozóan.

#### 32-bites rendszerek:
- **LP32 (Win16):** `int` 16-bit, `long` és mutató 32-bit.
- **ILP32 (Win32, Linux, macOS):** `int`, `long` és mutató is 32-bites.

#### 64-bites rendszerek:
- **LLP64 (64-bit Windows):** `int` és `long` marad 32-bites, de a mutató már 64-bites.
- **LP64 (64-bit Linux, macOS):** `int` 32-bit, de a `long` és a mutató már 64-bites.

### 11. Verzió-követési makrók és Kulcsszavak

| Makró | Szabvány | Funkció |
| :--- | :--- | :--- |
| `__cpp_unicode_characters` | C++11 | `char16_t` és `char32_t` típusok |
| `__cpp_char8_t` | C++20 | `char8_t` típus támogatása |

**Alapvető típus-kulcsszavak:**
`void`, `bool`, `true`, `false`, `char`, `char8_t`, `char16_t`, `char32_t`, `wchar_t`, `int`, `short`, `long`, `signed`, `unsigned`, `float`, `double`

## Objektumok (Objects)

A C++ programok objektumokat hoznak létre, semmisítenek meg és módosítanak. Az objektum több, mint egy egyszerű változó.

### Az objektum tulajdonságai
Minden objektumnak van:
- **Mérete:** lekérdezhető a `sizeof` operátorral.
- **Igazítási követelménye (Alignment):** lekérdezhető az `alignof` operátorral.
- **Tárolási időtartama (Storage duration):** automatikus, statikus, dinamikus vagy szál-lokális.
- **Élettartama (Lifetime):** az az időszak, amíg az objektum érvényesen létezik.
- **Típusa:** meghatározza a tárolható adatokat és műveleteket.
- **Értéke:** a tárolt adat (lehet határozatlan is inicializálás nélkül).
- **Neve:** opcionális (vannak névtelen objektumok is).

**Mi NEM objektum?** Az értékek (values), referenciák, függvények, típusnevek, névterek, sablonok és a `this` mutató.

### Változó (Variable)
A változó egy olyan objektum vagy referencia, amelyet egy deklaráció vezet be (kivéve a nem-statikus osztálytagokat).

### Objektumok létrehozása

#### 1. Explicit létrehozás
Amikor közvetlenül utasítjuk a gépet az objektum létrehozására:
- Definícióval: `int x;`
- `new` kifejezéssel: `new MyClass()`
- Ideiglenes objektumokkal: `std::string("példa")`

#### 2. Implicit létrehozás (C++11/17/23)
Bizonyos alacsony szintű műveletek (pl. `malloc`, `memcpy`) "implicit-élettartamú" típusok esetén automatikusan létrehozzák az objektumot a memóriában, anélkül, hogy konstruktort hívnánk.

```cpp
#include <cstdlib>

struct Pont { int x, y; };

Pont* Letrehoz() {
    // A malloc lefoglalja a helyet, és implicit módon 
    // "létrehozza" ott a Pont objektumot.
    Pont* p = static_cast<Pont*>(std::malloc(sizeof(Pont)));
    p->x = 10;
    p->y = 20;
    return p;
}
```

**C++23 újdonság:** A `std::start_lifetime_as` függvény segítségével explicit módon megmondhatjuk a fordítónak, hogy egy adott memóriaterületen egy bizonyos típusú objektum kezdje meg az életét.
```cpp
auto* p = std::start_lifetime_as<Pont>(buffer);
```

### Objektum- és értékábrázolás

A C++ különbséget tesz aközött, ahogy egy objektum a memóriában megjelenik, és aközött, amit az értéke jelent.

- **Objektum-ábrázolás (Object representation):** Az a bájtsorozat (`unsigned char`), amit az objektum elfoglal. Ennek mérete a `sizeof(T)`.
- **Érték-ábrázolás (Value representation):** Azon bitek halmaza az objektum-ábrázoláson belül, amelyek ténylegesen meghatározzák az objektum értékét.
- **Padding bits (Kitöltő bitek):** Azok a bitek az objektum-ábrázolásban, amelyek nem vesznek részt az érték meghatározásában. Ezek általában az **igazítás (alignment)** miatt kerülnek be a memóriába.

#### Példa a kitöltő bájtokra (Padding)
```cpp
struct Pelda {
    char c;    // 1 bájt érték
               // 3 bájt padding (ha a float 4 bájtra igazodik)
    float f;   // 4 bájt érték
};
// sizeof(Pelda) == 8 bájt lesz a padding miatt!
```

**Fontos szabályok:**
- **TriviallyCopyable** típusoknál (pl. egyszerű struct-ok) az objektum-ábrázolás bájtról-bájtra történő másolása (`memcpy`) garantáltan lemásolja az értéket is.
- **Trap representation:** Olyan bitminták, amelyek nem érvényes értékek, és a használatuk hardveres hibát (exception) válthat ki.
- **Karakterek:** A sima `char` típusnál minden bit részt vesz az érték ábrázolásában, nincsenek benne kitöltő bitek.

### Al-objektumok (Subobjects)

Egy objektum állhat más, kisebb objektumokból is.

**Típusai:**
1. **Adattagok (Member objects):** Az osztályon belül definiált változók.
2. **Bázisosztály al-objektumok:** Amikor egy osztály örököl egy másikból.
3. **Tömbelemek:** A tömbben tárolt egyes elemek.

#### Fogalmak:
- **Teljes objektum (Complete object):** Olyan objektum, amely nem al-objektuma semmi másnak.
- **Legszármaztatottabb objektum (Most derived object):** A teljes objektum vagy az al-objektum tényleges, végső típusa (pl. öröklődési lánc végén).

```cpp
struct Alap { int a; };
struct Szarmaztatott : Alap { int b; };

Szarmaztatott obj; 
// obj: Teljes objektum (Complete object)
// obj.a: Az Alap bázisosztály al-objektumának tagja
```

### Objektumok mérete (Size)

Minden objektumnak van mérete, de léteznek speciális esetek, ahol ez a méret "elméletileg" nulla lehet.

- **Átfedő al-objektumok:** Egy bázisosztály al-objektuma vagy egy `[[no_unique_address]]` attribútummal jelölt adattag (C++20) átfedheti más objektumok területét.
- **Nulla méret (Zero size):** Egy objektum mérete csak akkor lehet nulla, ha:
  - Al-objektumként szerepel (pl. bázisosztály).
  - Nincs virtuális függvénye vagy bázisa.
  - Nincsenek saját, nem-nulla méretű adattagjai.
- **Empty Base Optimization (EBO):** Ha egy osztály üres (nincsenek adattagjai), bázisosztályként használva nem foglal plusz helyet a származtatott osztályban.

```cpp
struct Ures {}; 
struct Adat : Ures { int x; }; 

// sizeof(Adat) valószínűleg 4 bájt lesz, mert az Ures 0 bájtot foglal (EBO).
```

### Objektumok címe (Address)

Az objektum címe az első bájtjának címe a memóriában.

- **Beágyazás (Nesting):** Egy objektum tartalmazhat más objektumokat (al-objektumok vagy tárolóként funkcionálás).
- **Azonos címek:** Általában két különböző objektumnak különböző címe van. Azonban azonos lehet a címük, ha:
  - Az egyik a másikba van ágyazva (pl. az osztály és az első adattagja).
  - Az egyik egy nulla méretű al-objektum.
  - **Potenciálisan nem egyedi objektumok:** Ilyenek például a string literálok, amiket a fordító optimalizálásként összevonhat egyetlen memóriaterületre.

#### Példa a címek egyezésére:
```cpp
const char* s1 = "x";
const char* s2 = "x";

// s1 == s2 eredménye fordítófüggő (unspecified), 
// de gyakran igaz, mert a fordító egy helyen tárolja az azonos literálokat.

struct Pont { int x, y; };
Pont p;
// &p címe megegyezik &p.x címével.
```

### Polimorf objektumok (Polymorphic objects)

Polimorf objektumnak nevezzük azokat az osztálypéldányokat, amelyeknek van legalább egy **virtuális** (`virtual`) függvényük.

- **Belső működés:** Minden ilyen objektum tárol egy plusz információt (általában egy mutatót a virtuális metódustáblára - vtable), ami lehetővé teszi a futás közbeni típusazonosítást.
- **RTTI (Run-Time Type Information):** Emiatt működik rajtuk a `dynamic_cast` és a `typeid` futás közben is.
- **Nem polimorf objektumok:** Azok, amiknek nincs virtuális függvényük. Ezeknél a fordító már fordítási időben eldönti a típust, és nem tárolnak extra mutatót (kisebb a méretük).

#### Példa polimorfizmusra:
```cpp
struct Alap { virtual ~Alap() {} }; // Polimorf
struct Szarmaztatott : Alap {};

Szarmaztatott obj;
Alap& ref = obj;

std::cout << typeid(ref).name(); // Futás közben kiírja: "Szarmaztatott"
```

### Strict aliasing

A C++ szabályai szerint tilos egy objektumot a memóriában más típusúnak tettetni, mint amilyen típussal létrehoztuk. Ha ezt megszegjük (pl. egy `int` területét `float*`-ként kezeljük), az **meghatározatlan viselkedéshez (Undefined Behavior)** vezet. Vannak kivételek (pl. `char*` vagy `std::byte*`), de általánosságban kerülni kell.

### Igazítás (Alignment)

Minden típusnak van egy **igazítási követelménye** (`alignment requirement`). Ez azt a bájtszámot jelenti, aminek a többszörösén az objektum memóriacíme kell, hogy kezdődjön.

- **alignof:** Lekérdezhetjük vele egy típus igazítási igényét (mindig 2 valamelyik hatványa).
- **alignas:** Kérhetünk a fordítótól szigorúbb igazítást (pl. cache-optimalizáláshoz).
- **Padding:** A fordító üres bájtokat szúr be az adattagok közé, hogy mindegyik a neki megfelelő igazítású címre kerüljön.

#### Példa az igazításra:
```cpp
struct S {
    char a; // méret: 1, igazítás: 1
    char b; // méret: 1, igazítás: 1
}; // sizeof(S) == 2, alignof(S) == 1

struct X {
    int n;  // méret: 4, igazítás: 4
    char c; // méret: 1, igazítás: 1
    // Itt 3 bájt kitöltés (padding) jön!
}; // sizeof(X) == 8, alignof(X) == 4
```

### Memóriahelyszín (Memory location)

A memóriahelyszín az a tárterület, amelyet egy **skalár típusú** (nem bitmező) objektum, vagy a **bitmezők** leghosszabb folytonos sorozata foglal el.

- **Skalár típusok:** `char`, `int`, mutatók stb. Minden ilyen (nem bitmező) változó külön memóriahelyszín.
- **Bitmezők (Bit-fields):** Az egymás utáni bitmezők egyetlen memóriahelyszínnek számítanak, amíg nincs közöttük egy nulla hosszúságú bitmező vagy egy nem-bitmező tag.

#### Miért fontos ez?
A szálbiztosság (thread safety) miatt: két különböző szál biztonságosan módosíthat két **különböző** memóriahelyszínt szinkronizáció nélkül. Ha azonban két szál ugyanazt a memóriahelyszínt (pl. két szomszédos bitmezőt) próbálja egyszerre írni, az **adatversenyhez (data race)** és hibához vezet.

#### Példa a memóriahelyszínekre:
```cpp
struct S {
    char a;     // 1. memóriahelyszín
    int b : 5;  // 2. memóriahelyszín
    int c : 11, // 2. memóriahelyszín (folytatás)
          : 0,  // Nulla hosszúságú bitmező: kényszerített elvágás!
        d : 8;  // 3. memóriahelyszín
    struct {
        int ee : 8; // 4. memóriahelyszín
    } e;
} obj;
// Az 'obj' objektum összesen 4 különálló memóriahelyszínből áll.
```


## Hatókörök (Scopes)

A hatókör határozza meg, hogy egy név (változó, függvény, típus) a kód mely részén érvényes és használható.

### 1. Blokk hatókör (Block scope)
A kapcsos zárójelek `{ }` közötti rész. Az itt definiált nevek csak a blokkon belül látszanak.
- **Shadowing (Elfedés):** Egy belső blokkban definiált azonos nevű változó elrejti a külsőt.
- **Ciklusok:** A `for` ciklus fejlécében definiált változó a ciklus blokkjához tartozik.

```cpp
int i = 42;
for (int i = 0; i < 10; i++) {
    // Ez az "i" a belső blokkhoz tartozik (0-9-ig fut)
}
int j = i; // j értéke 42 lesz, mert a belső "i" megszűnt
```

**Fontos szabály:** Nem definiálhatsz újra egy változót ugyanabban a blokkban vagy közvetlen al-utasításában.
```cpp
if (int x = f()) {
    int x; // HIBA: az 'x' már definiálva van a feltételben
}
```

### 2. Függvényparaméter hatókör (Function parameter scope)
A függvény paraméterei a függvény fejlécétől a függvény törzsének (`{ }`) végéig élnek.
```cpp
void f(int n) { // 'n' hatóköre elkezdődik
    // ...
} // 'n' hatóköre véget ér
```

### 3. Lambda hatókör (Lambda scope)
A lambdák saját hatókört vezetnek be, ami az elkapási lista `[ ]` után kezdődik és a törzs végéig tart. A C++14 óta használt elkapási inicializálók is ide tartoznak.
```cpp
auto l = [x = 1]() {
    // 'x' csak a lambdán belül létezik
};
```

### 4. Névtér hatókör (Namespace scope)
Egy névtérben definiált nevek a névtér minden definíciójában látszanak. A **globális hatókör** is egy névtér hatókör (a legkülső).
```cpp
namespace V {
    void f(); // 'f' a V névtér tagja
}

void V::f() {
    void h(); // Ez valójában V::h-t deklarálja
}
```

### 5. Osztály hatókör (Class scope)
Az osztályon belül definiált nevek (adattagok, metódusok) az egész osztályban látszanak, függetlenül a sorrendtől.
```cpp
class C {
    void f() { g(); } // 'g' használható, pedig később van deklarálva
    void g() {}
};
```

### 6. Enumeráció hatókör (Enumeration scope)
Az `enum class` elemei az enumeráció saját hatókörébe tartoznak.
```cpp
enum class Szin { Piros, Kek };
Szin s = Szin::Piros; // 'Piros' csak a 'Szin' minősítéssel érhető el
```

### 7. Sablonparaméter hatókör (Template parameter scope)
A sablonparaméterek (`typename T`) hatóköre a sablon deklarációjától a sablon végéig tart.
```cpp
template <typename T> // 'T' hatóköre elkezdődik
class Lista {
    T adat;
}; // 'T' hatóköre véget ér

### 8. Szerződés-ellenőrzési hatókör (Contract-assertion scope, C++26)
A C++26-ban bevezetett szerződések (`pre`, `post` feltételek) saját hatókört hoznak létre. Egy utófeltétel (`post`) azonosítója nem ütközhet a függvény paramétereivel vagy a közeli lambda hatóköreivel.

## Deklaráció pontja (Point of declaration / Locus)

A deklaráció pontja az a hely a kódban, ahonnan kezdve egy név láthatóvá válik. Ez gyakran a változó neve után, de még az értékadása előtt van!

### 1. Egyszerű változók
A név azonnal a deklarátor után látszik, még az inicializáló rész előtt.
```cpp
int x = 32; 
{
    int x = x; // HIBA: a belső x-et önmagával inicializálod (határozatlan érték)!
               // A külső x-et már eltakarta a belső név.
}
```
**Kivétel:** Rekurzív lambdáknál ez hasznos:
```cpp
std::function<int(int)> f = [&](int n) {
    return n > 1 ? n * f(n - 1) : n; // 'f' már látszik, elkapható referenciával
};
```

### 2. Osztályok és Enumok
- **Osztály:** A név az osztályfej (`struct S`) után azonnal látszik, így a bázisosztályok listájában már hivatkozhatunk rá.
- **Enum:** Az alapul fekvő típus megadása után már látszik.
```cpp
struct S : std::enable_shared_from_this<S> {}; // 'S' már látszik a kettőspontnál
enum E : int { A = sizeof(E) };               // 'E' már látszik
```

### 3. Típus-álnév (Type alias)
A név csak a pontosvessző (`;`) után válik láthatóvá.
```cpp
using T = int;
{
    using T = T*; // Itt a belső T jelentése 'int*', mert a T még az int-re utal
}
```

### 4. Injected-class-name
Egy osztály neve az osztály törzsén ( `{` ) belül "beágyazott névként" is látszik.
```cpp
template<typename T>
struct Lista {
    Lista* kovetkezo; // A 'Lista' itt hivatkozhat a Lista<T>-re rövidítésként
};
```

### 5. Range-for ciklus
A ciklusváltozó csak a bejárt konténer megadása után válik láthatóvá.
```cpp
std::vector<int> x;
for (auto x : x) { // A kettőspont utáni 'x' még a vektort jelenti,
                   // a ciklusban az 'x' már az aktuális elemet.
}
```

### 6. Speciális változók
- **`__func__`**: Automatikusan létrejön minden függvényben, közvetlenül a nyitó kapcsos zárójel előtt.
- **Strukturált kötés (C++17):** A nevek a listájuk (`[a, b]`) után látszanak, de nem hivatkozhatnak önmagukra az inicializáláskor.
```cpp
auto [a, b] = f(); // 'a' és 'b' a pontosvessző után használható
```

## Minősített névkeresés (Qualified name lookup)

A minősített név olyan név, amely a hatókör-feloldó operátor (`::`) jobb oldalán áll. Segítségével pontosan megmondhatjuk, melyik osztály vagy névtér tagjára gondolunk.

### 1. Globális hatókör (`::név`)
Ha a `::` bal oldalán nincs semmi, a fordító csak a legkülső, globális névtérben keres. Ez hasznos, ha egy helyi változó elrejti a globálisat.
```cpp
int adat = 10; // Globális

void f() {
    int adat = 5; // Helyi, elrejti a globálisat
    std::cout << adat;   // 5
    std::cout << ::adat; // 10 (a globális adat)
}
```

### 2. Osztálytagok elérése
Ha a bal oldalon egy osztálynév áll, a fordító az adott osztályban (és annak bázisaiban) keres.

#### Virtuális hívás kikerülése
A minősített névvel meghívott tagfüggvények **soha nem virtuálisak**. Ezzel kényszeríthetjük egy konkrét bázisosztály metódusának futtatását.
```cpp
struct Alap { virtual void f() { std::cout << "Alap"; } };
struct Szarmaztatott : Alap { void f() override { std::cout << "Szarmaz"; } };

void teszt() {
    Szarmaztatott obj;
    Alap& ref = obj;
    
    ref.f();       // "Szarmaz" (virtuális hívás)
    ref.Alap::f(); // "Alap" (statikus, minősített hívás)
}
```

### 3. Névtér tagok elérése
A fordító először az adott névtérben keres, majd az ott található `inline` névterekben és a `using` direktívákkal beemelt névterekben.

```cpp
namespace A { int x = 1; }
namespace B { int x = 2; }

namespace Osszes {
    using namespace A;
    using namespace B;
}

// Osszes::x++; // HIBA: kétértelmű, mert A-ban és B-ben is van x
```

### 4. Destruktorok keresése
A `~` jel utáni nevet ugyanabban a hatókörben keresi a fordító, mint a `::` előtti nevet.
```cpp
struct C { typedef int I; };
C::I* p;
p->C::I::~I(); // Az I-t a C osztályon belül találja meg
```

### Fontos szabályok:
- **Típus-függőség:** A `::` bal oldalán álló névnek osztálynak, névtérnek vagy enumerációnak kell lennie.
- **Sablon argumentumok:** A sablonok paramétereit (pl. `N::Sablon<X>`) mindig az aktuális környezetben keresi a fordító, nem pedig a bal oldali névtérben (`N`).
```cpp
namespace N { struct X {}; template<typename T> struct S {}; }
struct X {}; // Globális X

N::S<X> obj; // Itt az X a globális X lesz, nem az N::X!
```

## Main függvény (A program belépési pontja)

Minden futtatható C++ programnak tartalmaznia kell egy globális `main` függvényt, amely a program indulásakor hívódik meg.

### Szabványos formái
1. **Paraméterek nélkül:** `int main() { ... }`
2. **Parancssori argumentumokkal:** `int main(int argc, char* argv[]) { ... }`

#### Paraméterek magyarázata:
- **argc (Argument Count):** A programnak átadott argumentumok száma (nem-negatív).
- **argv (Argument Vector):** Mutatók tömbje, amely a null-terminált karakterláncokra (stringekre) mutat. 
  - `argv[0]` a program neve (vagy üres string).
  - `argv[1]` ... `argv[argc-1]` a tényleges argumentumok.
  - `argv[argc]` garantáltan `nullptr`.

### Speciális tulajdonságok
- **Implicit return:** A `main` az egyetlen függvény, ahol nem kötelező a `return` utasítás. Ha eléri a végét, automatikusan `return 0;`-t hajt végre (sikeres futás).
- **Kilépés:** A `return` hívása a `main`-ben egyenértékű az automatikus objektumok megsemmisítésével, majd a `std::exit()` meghívásával.
- **Statikus objektumok:** A `main` elindulása előtt a globális/statikus objektumok már inicializálva vannak.

### Szigorú megkötések (TILOS műveletek)
A program hibás lesz, ha megszegjük ezeket a szabályokat:
1. **Nem hívható meg:** A `main` nem hívható meg rekurzívan.
2. **Nem kérhető le a címe:** Nem készíthetünk mutatót a `main` függvényre.
3. **Nem terhelhető túl (No Overloading):** Csak egyetlen `main` létezhet a globális névtérben.
4. **Nem lehet:** `constexpr`, `consteval`, `inline` vagy `static`.
5. **Visszatérési típusa fix:** Csak `int` lehet (nem használható az `auto main()` típuslevezetés).
6. **Nem lehet korutin (coroutine).**

### Példa: Argumentumok feldolgozása
```cpp
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Argumentumok szama: " << argc << "\n";
    
    for (int i = 0; i < argc; ++i) {
        std::cout << i << ". argumentum: " << argv[i] << "\n";
    }
    
    return 0; // Sikeres befejezés
}
```

```

## Élettartam (Lifetime)

Az élettartam az az időszak, amíg egy objektum érvényesen létezik a memóriában. Ez nem azonos a memória foglalási idejével!

- **Mikor kezdődik?** Amikor a konstruktora lefutott, vagy ha nincs konstruktora (trivial type), akkor a memóriafoglalás után azonnal.
- **Mikor ér véget?** Amikor a destruktora elkezd futni, vagy amikor a memóriát felszabadítják/másra használják.

### Élettartamon kívüli elérés (Undefined Behavior)
Ha egy objektumhoz az élettartamán kívül próbálsz hozzáférni (pl. már lefutott a destruktora), az **meghatározatlan viselkedéshez** vezet.
**TILOS élettartamon kívül:**
- Nem-statikus adattag elérése vagy metódus hívása.
- Referencia kötése bázisosztályhoz.
- `dynamic_cast` vagy `typeid` használata.

---

## Memória újrahasználata (Storage reuse)

A C++ lehetővé teszi, hogy egy már lefoglalt memóriaterületen (ahol korábban egy másik objektum volt) egy új objektumot hozzunk létre. Erre leggyakrabban a **placement new** operátort használjuk.

### 1. Placement new alapok
```cpp
#include <new> // Szükséges a placement new-hoz

struct Adat { int x; ~Adat(){} };

void pelda() {
    alignas(Adat) char buffer[sizeof(Adat)]; // Memória lefoglalása
    
    // Új objektum létrehozása a már meglévő bufferben:
    Adat* p = new (buffer) Adat{10}; 
    
    p->~Adat(); // Manuálisan kell hívni a destruktort!
}
```

### 2. Átlátható helyettesítés (Transparently replaceable)
Ha egy meglévő objektum helyére (ugyanarra a címre) egy **azonos típusú** objektumot hozunk létre, a régi mutatók és nevek automatikusan az új objektumra fognak mutatni.
**Feltételek:**
- A típusok pontosan megegyeznek.
- Az eredeti objektum nem volt `const`.
- Nem bázisosztály al-objektumáról van szó.

### 3. std::launder (C++17)
Ha a helyettesítés **nem** átlátható (pl. a típusban `const` vagy referencia tag van), a fordító optimalizációja miatt a régi mutató használata hibás lehet. Ilyenkor kell a `std::launder`.

```cpp
#include <new>

struct X { const int n; };

void test() {
    X* p = new X{1};
    int regi_n = p->n;
    
    p->~X();
    new (p) X{2}; // Új objektum ugyanott, de const taggal!
    
    // int uj_n = p->n; // Lehet, hogy a fordító még az 1-et látja itt (optimalizáció)!
    int uj_n = std::launder(p)->n; // OK: Kényszerítjük a friss beolvasást
}
```

### 4. Buffer biztosítása (Providing storage)
Egy `unsigned char` vagy `std::byte` tömb képes "helyet adni" bármilyen más objektumnak anélkül, hogy a tömb élettartama véget érne.
```cpp
unsigned char buffer[1024];
int* pInt = new (buffer) int(42);       // Az int elfoglalja a buffer elejét
char* pChar = new (buffer + 4) char('A'); // A következő bájtra is tehetünk mást
```

### Fontos figyelmeztetések:
- **Triviális destruktor:** Ha az objektumnak nincs fontos dolga a destruktorban (pl. egy `int`), nem kötelező hívni a destruktort újrahasználat előtt.
- **Konstans objektumok:** Statikus vagy automatikus `const` objektumok helyét **tilos** újrahasználni, mert azok gyakran csak olvasható (read-only) memóriában vannak!
```cpp
const Adat a;
// a.~Adat();
// new (&a) Adat; // HIBA! Meghatározatlan viselkedés.
```

## Modulok (Modules - C++20 óta)

A modulok a `#include` modern, gyorsabb és biztonságosabb alternatívái. Segítségével pontosan szabályozhatjuk, hogy mi legyen látható más fájlok számára.

### Alapvető felépítés

Egy modul általában két részből áll: egy **interfészből** (amit mások importálnak) és opcionálisan egy **implementációból**.

#### 1. Modul Interfész (`export module`)
```cpp
// hello.cppm (vagy .cpp)
export module köszönés; // Modul deklarálása

import <iostream>;      // Más modulok beemelése

export void szia() {    // Az 'export' kulcsszóval tesszük láthatóvá
    std::cout << "Szia, C++20 Modul Világ!\n";
}

void titkos() {         // Ez nem exportált, csak ebben a fájlban látszik
}
```

#### 2. Modul használata (`import`)
```cpp
// main.cpp
import köszönés; // Nincs többé #include!

int main() {
    szia();      // Működik
    // titkos(); // HIBA: nem lett exportálva
}
```

### Fontos fogalmak

- **`export`**: Megjelöli azokat a függvényeket, osztályokat vagy névtereket, amiket a modult használók elérhetnek.
- **`import <header>`**: Fejléc-egységként (header unit) importálja a standard könyvtárat. Gyorsabb, mint a `#include`.
- **Global Module Fragment**: Ha mégis szükség van régi `#include`-okra (pl. makrók miatt), azt a modul deklarációja előtt, a `module;` kulcsszó után kell megtenni.
- **Private Module Fragment (`module : private`)**: Lehetővé teszi, hogy az interfész és az implementáció egy fájlban legyen, de a felhasználók ne lássák az implementációs részleteket.

### Modul Partíciók (`module : név`)
Nagyobb modulokat részekre (partíciókra) bonthatunk, amik kifelé egyetlen modulként látszanak.
```cpp
export module A:Resz1; // Partíció deklarálása
```

### Miért jobb, mint a `#include`?
1. **Sebesség:** A modult csak egyszer kell lefordítani, nem minden fájlban újra és újra.
2. **Izoláció:** A modulban definiált makrók nem "szivárognak" ki és nem rontják el más fájlok kódját.
3. **Logikus felépítés:** Végre van egy valódi komponens-rendszer a nyelvben, nem csak szöveges bemásolás.

## Szerződések (Contracts - C++26 óta)

A szerződések lehetővé teszik a program elvárt állapotának rögzítését a kódban. Három fő típusa van: az előfeltétel, az utófeltétel és a menet közbeni ellenőrzés.

### Szerződés típusok

1. **Előfeltétel (`pre`):** A függvény meghívása előtt kell teljesülnie.
2. **Utófeltétel (`post`):** A függvény lefutása után garantált állapot.
3. **`contract_assert`:** A kód bármely pontján elhelyezhető ellenőrzés.

```cpp
// Példa: elő- és utófeltétel használata
int osztas(int a, int b) 
    pre(b != 0)          // Előfeltétel: b nem lehet nulla
    post(r: r * b <= a)   // Utófeltétel: az eredmény (r) helyességének ellenőrzése
{
    return a / b;
}

void feldolgoz(int n) {
    contract_assert(n > 0); // Menet közbeni ellenőrzés
}
```

### Kiértékelési módok (Semantics)

A fordító beállításaitól függően a szerződések különböző módon viselkedhetnek:
- **ignore:** Az ellenőrzések teljesen kimaradnak a kódból (nincs lassulás).
- **observe:** Az ellenőrzés lefut, de ha hamis, a program megy tovább (pl. csak logolás történik).
- **enforce:** Ha a feltétel hamis, a program azonnal leáll (biztonságos mód).
- **quick-enforce:** Mint az enforce, de a fordító feltételezheti, hogy a feltétel igaz, és eszerint optimalizálhat.

### Szerződésszegés kezelése (Violation Handler)

Ha egy szerződés nem teljesül (és nem `ignore` módban vagyunk), a rendszer meghívja a globális hibakezelőt:
```cpp
void handle_contract_violation(std::contracts::contract_violation violation);
```
Ezt a függvényt a fejlesztő definiálhatja felül, hogy saját logolást vagy speciális leállítást valósítson meg.

### Fontos figyelmeztetés (Mellékhatások)
Soha ne tegyél olyan műveletet a szerződés feltételébe, aminek meg kell történnie a program futásához (pl. `num++`), mert a fordító dönthet úgy, hogy **nem futtatja le** a feltételt (pl. `ignore` módban), és akkor a változó nem fog növekedni!
```cpp
void f() pre(num++, false); // Rossz gyakorlat: num++ lehet, hogy sosem fut le!
```

---

# C++ Input/output könyvtár (I/O Library)

A C++ a következő bemeneti/kimeneti könyvtárakat tartalmazza:
- Egy **OOP-stílusú folyamalapú (stream-based)** I/O könyvtár.
- **Print-alapú** függvénycsalád (C++23 óta).
- A standard **C-stílusú I/O** függvények.

## Folyamalapú I/O (Stream-based I/O)

A folyamalapú bemeneti/kimeneti könyvtár absztrakt bemeneti/kimeneti eszközök köré szerveződik. Ezek az absztrakt eszközök lehetővé teszik, hogy ugyanaz a kód kezelje a fájlokba, memóriafolyamokba vagy egyedi adaptereszközökbe (pl. tömörítés) történő írást/olvasást menet közben.

A legtöbb osztály sablon alapú (templated), így bármilyen alapvető karaktertípushoz hozzáigazítható. Külön típusdefiníciók (typedefs) állnak rendelkezésre a leggyakoribb karaktertípusokhoz (`char` és `wchar_t`).

### Absztrakció és hierarchia

Az osztályok a következő hierarchiába rendeződnek:

| Osztály | Leírás | Fejléc |
| :--- | :--- | :--- |
| **ios_base** | Kezeli a formázási jelzőket (flags) és az I/O kivételeket. | `<ios>` |
| **basic_ios** | Egy tetszőleges folyam-puffert (stream buffer) kezel. | `<ios>` |
| **basic_streambuf** | Absztrakt módon kezeli a nyers eszközt. | `<streambuf>` |
| **basic_ostream** | Egy absztrakt eszközt (`std::basic_streambuf`) csomagol be, és magas szintű kimeneti felületet biztosít. | `<ostream>` |
| **basic_istream** | Egy absztrakt eszközt (`std::basic_streambuf`) csomagol be, és magas szintű bemeneti felületet biztosít. | `<istream>` |
| **basic_iostream** | Magas szintű bemeneti és kimeneti felületet is biztosít egyszerre. | `<istream>` |

### Gyakorlati példa (Stream használata)

```cpp
#include <iostream>  // std::cout, std::cin
#include <fstream>   // std::ofstream, std::ifstream (fájlkezelés)
#include <sstream>   // std::stringstream (memória folyam)

int main() {
    // 1. Standard kimenet (ostream)
    std::cout << "Kimenet a konzolra." << std::endl;

    // 2. Fájlba írás (ofstream - kimeneti fájl folyam)
    std::ofstream ki_fajl("adatok.txt");
    if (ki_fajl.is_open()) {
        ki_fajl << "Szia fájl! " << 2026 << "\n";
        ki_fajl.close();
    }

    // 3. String folyam (stringstream) - Formázás memóriában
    std::stringstream ss;
    ss << "Sebesség: " << 120 << " km/h";
    std::string eredmeny = ss.str();
    
    // 4. Bemenet (istream)
    int szam;
    // std::cin >> szam; // Konzolos beolvasás
    
    return 0;
}
```

## Fájl I/O megvalósítás (File I/O)

A `<fstream>` fejlécben definiált osztályok fájlok olvasására és írására szolgálnak.

| Osztály | Leírás |
| :--- | :--- |
| **basic_filebuf** | Megvalósítja a nyers fájl-eszközt (pufferelést). |
| **basic_ifstream** | Magas szintű fájlbeviteli műveleteket végez. |
| **basic_ofstream** | Magas szintű fájlkiviteli műveleteket végez. |
| **basic_fstream** | Magas szintű fájl be- és kimeneti műveleteket végez. |

## String I/O megvalósítás (String I/O)

A `<sstream>` fejlécben definiált osztályok lehetővé teszik a stringek folyamként (stream) való kezelését.

| Osztály | Leírás |
| :--- | :--- |
| **basic_stringbuf** | Megvalósítja a nyers string-eszközt. |
| **basic_istringstream** | Magas szintű string-bemeneti műveleteket végez. |
| **basic_ostringstream** | Magas szintű string-kimeneti műveleteket végez. |
| **basic_stringstream** | Magas szintű string be- és kimeneti műveleteket végez. |

### Példa: Adatok kinyerése stringből (istringstream)

```cpp
#include <sstream>
#include <string>
#include <iostream>

int main() {
    std::string adat = "100 3.14 Alma";
    std::istringstream iss(adat);

    int i;
    double d;
    std::string s;

    // A folyam automatikusan elvégzi a típuskonverziót
    iss >> i >> d >> s;

    std::cout << "Egész: " << i << "\n";   // 100
    std::cout << "Lebegő: " << d << "\n"; // 3.14
    std::cout << "Szöveg: " << s << "\n";  // Alma

    return 0;
}
```

## Gyakori típusdefiníciók (Typedefs)

A standard könyvtár előre definiált rövidítéseket (typedefs) biztosít a leggyakoribb karaktertípusokhoz (`char` és `wchar_t`).

| Fejléc | Típus (`char`) | Típus (`wchar_t`) | Alaposztály |
| :--- | :--- | :--- | :--- |
| `<ios>` | **std::ios** | **std::wios** | `basic_ios` |
| `<streambuf>` | **std::streambuf** | **std::wstreambuf** | `basic_streambuf` |
| `<istream>` | **std::istream** | **std::wistream** | `basic_istream` |
| | **std::iostream** | **std::wiostream** | `basic_iostream` |
| `<ostream>` | **std::ostream** | **std::wostream** | `basic_ostream` |
| `<fstream>` | **std::filebuf** | **std::wfilebuf** | `basic_filebuf` |
| | **std::ifstream** | **std::wifstream** | `basic_ifstream` |
| | **std::ofstream** | **std::wofstream** | `basic_ofstream` |
| | **std::fstream** | **std::wfstream** | `basic_fstream` |
| `<sstream>` | **std::stringbuf** | **std::wstringbuf** | `basic_stringbuf` |
| | **std::istringstream** | **std::wistringstream** | `basic_istringstream` |
| | **std::ostringstream** | **std::wostringstream** | `basic_ostringstream` |
| | **std::stringstream** | **std::wstringstream** | `basic_stringstream` |
| `<spanstream>` | **std::spanbuf** (23) | **std::wspanbuf** (23) | `basic_spanbuf` |
| | **std::ispanstream** (23) | **std::wispanstream** (23) | `basic_ispanstream` |
| | **std::ospanstream** (23) | **std::wospanstream** (23) | `basic_ospanstream` |
| | **std::spanstream** (23) | **std::wspanstream** (23) | `basic_spanstream` |
| `<syncstream>` | **std::syncbuf** (20) | **std::wsyncbuf** (20) | `basic_syncbuf` |
| | **std::osyncstream** (20) | **std::wosyncstream** (20) | `basic_osyncstream` |

## Előre definiált standard folyam objektumok

A `<iostream>` fejléc globális objektumokat biztosít a standard be- és kimenetek kezeléséhez.

| Objektum (`char`) | Objektum (`wchar_t`) | Leírás |
| :--- | :--- | :--- |
| **std::cin** | **std::wcin** | A standard C bemeneti folyamról (`stdin`) olvas. |
| **std::cout** | **std::wcout** | A standard C kimeneti folyamra (`stdout`) ír. |
| **std::cerr** | **std::wcerr** | A standard C hiba-folyamra (`stderr`) ír, **pufferelés nélkül**. |
| **std::clog** | **std::wclog** | A standard C hiba-folyamra (`stderr`) ír (pufferelt). |

## I/O Manipulátorok (I/O Manipulators)

A folyamalapú I/O könyvtár manipulátorokat használ (pl. `std::boolalpha`, `std::hex`, `std::setw`) a folyamok viselkedésének és a formázásnak a szabályozására. Ezeket közvetlenül a `<<` vagy `>>` operátorokkal használjuk.

## Segédtípusok (Auxiliary Types)

A folyamok pozicionálásához és méretkezeléséhez a következő típusok állnak rendelkezésre:

| Típus | Leírás | Fejléc |
| :--- | :--- | :--- |
| **streamoff** | Relatív pozíciót képvisel (eltolás). Bármekkora fájlméret ábrázolására alkalmas. | `<ios>` |
| **streamsize** | Átvitt karakterek számát vagy a puffer méretét jelöli. | `<ios>` |
| **fpos** | Abszolút pozíciót képvisel egy folyamban vagy fájlban. | `<ios>` |

### Speciális pozíció típusok (Typedefs)

| Név | Definíció | Szabvány |
| :--- | :--- | :--- |
| **std::streampos** | `fpos<char_traits<char>::state_type>` | - |
| **std::wstreampos** | `fpos<char_traits<wchar_t>::state_type>` | - |
| **std::u8streampos** | `fpos<char_traits<char8_t>::state_type>` | C++20 |
| **std::u16streampos** | `fpos<char_traits<char16_t>::state_type>` | C++11 |
| **std::u32streampos** | `fpos<char_traits<char32_t>::state_type>` | C++11 |

## Hibakezelési felület (C++11 óta)

A `<ios>` fejlécben található eszközök a folyamok hibaállapotainak kezelésére szolgálnak.

| Osztály/Függvény | Leírás |
| :--- | :--- |
| **io_errc** | Az I/O folyamok hibakódjait tartalmazó enumeráció. |
| **iostream_category** | Az iostream hiba-kategóriát azonosító függvény. |

## Print függvények (C++23 óta)

A C++23 bevezette a Unicode-tudatos `print` függvénycsaládot. Ezek a `std::format` teljesítménybeli előnyeit kínálják: gyorsabbak, alapértelmezetten nyelvfüggetlenek (locale-independent), csökkentik a globális állapotot, és elkerülik az ideiglenes string objektumok foglalását.

| Függvény | Fejléc | Leírás |
| :--- | :--- | :--- |
| **print** | `<print>` | Formázott kimenet a standard kimenetre (`stdout`) vagy fájlba. |
| **println** | `<print>` | Ugyanaz, mint a `print`, de automatikusan új sort (`\n`) fűz a végére. |
| **vprint_unicode** | `<print>` | Típus-törölt (type-erased) Unicode kimenet. |
| **vprint_nonunicode**| `<print>` | Típus-törölt nem-Unicode kimenet. |
| **print(ostream)** | `<ostream>` | Formázott kimenet egy adott `std::ostream`-re. |
| **println(ostream)**| `<ostream>` | Formázott kimenet `std::ostream`-re, új sorral a végén. |

### Példa: Modern kiírás (C++23)

```cpp
#include <print>
#include <fstream>

int main() {
    // Kiírás a konzolra új sorral
    std::println("Szia, {}! Az évszám: {}", "Világ", 2026);

    // Kiírás fájlba
    std::ofstream fajl("teszt.txt");
    if (fajl) {
        std::println(fajl, "Ez a sor a fájlba kerül.");
    }
    
    return 0;
}
```

## C-stílusú I/O

A C++ továbbra is támogatja a hagyományos C bemeneti/kimeneti függvényeket, amik a `<cstdio>` (C-ben `stdio.h`) fejlécben találhatók.

- Példák: `std::fopen`, `std::fprintf`, `std::scanf`, `std::getc`, `std::puts`.
- **Használatuk:** Bár néha gyorsabbak lehetnek bizonyos esetekben, nem típusbiztosak és nem támogatják az objektumorientált megközelítést.

---

# Fájlrendszer könyvtár (Filesystem Library - C++17)

A Filesystem könyvtár (elérhető a `<filesystem>` fejlécben) eszközöket biztosít a fájlrendszereken és azok összetevőin (útvonalak, fájlok, könyvtárak) végzett műveletekhez. Eredetileg a `boost.filesystem` részeként fejlesztették ki, majd a C++17 szabvány részévé vált.

### Fordítási és szerkesztési tudnivalók
A könyvtár használatához bizonyos fordítóknál extra kapcsolókra lehet szükség:
- **GNU (GCC) 9.1 előtti verziók:** Szükséges a `-lstdc++fs` kapcsoló a linkerhez.
- **LLVM (Clang) 9.0 előtti verziók:** Szükséges a `-lc++fs` kapcsoló a linkerhez.

### Kísérleti változat (std::experimental)
A C++17 szabványosítás előtt a funkciók a `std::experimental::filesystem` névtérben voltak elérhetőek (ISO/IEC TS 18822:2015). 
- **Eredete:** Közvetlenül a `boost.filesystem` könyvtáron alapul.
- **Mai állapota:** Elavult (deprecated). Új kódokban már a standard `std::filesystem` használandó, de régi kódbázisokban még találkozhatsz vele.

| Verziókövetési makró | Érték | Szabvány |
| :--- | :--- | :--- |
| **`__cpp_lib_filesystem`** | `201703L` | C++17 |

**Fontos megjegyzések:**
- **Elérhetőség:** Bizonyos funkciók nem érhetők el, ha az alatta lévő fájlrendszer nem támogatja azokat (pl. a FAT rendszerben nincsenek szimbolikus linkek).
- **Adatverseny (Race condition):** A viselkedés nem meghatározott, ha több szál vagy folyamat egyszerre próbálja módosítani ugyanazt a fájlrendszer-objektumot.

## Alapfogalmak

- **Fájl (File):** Adatokat tároló objektum, amely olvasható, írható vagy mindkettő. Nevük és attribútumaik (pl. típus) vannak.
- **Könyvtár (Directory):** Olyan fájl, amely bejegyzések konténereként működik. Ezek a bejegyzések más fájlokra vagy alkönyvtárakra mutatnak. A szülőkönyvtárra a `..` relatív útvonallal hivatkozhatunk.
- **Szabályos fájl (Regular file):** Olyan bejegyzés, amely egy nevet rendel egy létező fájlhoz (hard link).
- **Szimbolikus link (Symbolic link):** Egy nevet társít egy elérési úthoz (ami nem feltétlenül létezik).
- **Speciális fájltípusok:** blokk eszköz, karakter eszköz, FIFO, socket.

## Elérési utak (Paths)

- **Fájlnév (File name):** Karakterek sorozata, amely azonosít egy fájlt. A megengedett karakterek és a név hossza operációs rendszer függő. A `.` (aktuális mappa) és `..` (szülő mappa) speciális jelentéssel bír.
- **Elérési út (Path):** Elemek sorozata, amely azonosít egy fájlt. Tartalmazhat gyökérnevet (pl. `C:`), gyökérkönyvtárat (pl. `/`) és fájlnevek sorozatát.
- **Abszolút út (Absolute path):** Egyértelműen azonosítja a fájl helyét a gyökértől kezdve.
- **Kanonikus út (Canonical path):** Olyan abszolút út, amely nem tartalmaz szimbolikus linkeket, `.` vagy `..` elemeket.
- **Relatív út (Relative path):** Egy adott helyhez képest határozza meg a fájl helyét.

## Osztályok és típusok

A `<filesystem>` fejléc a következő osztályokat és típusokat tartalmazza a `std::filesystem` névtérben:

| Osztály / Típus | Leírás |
| :--- | :--- |
| **path** | Egy elérési utat (útvonalat) képvisel. |
| **filesystem_error** | Fájlrendszer-hibák esetén dobott kivétel osztály. |
| **directory_entry** | Egy konkrét könyvtárbejegyzést (fájlt vagy mappát) képvisel. |
| **directory_iterator** | Iterátor egy könyvtár tartalmának bejárásához. |
| **recursive_directory_iterator** | Iterátor egy könyvtár és összes alkönyvtárának bejárásához. |
| **file_status** | A fájl típusát és jogosultságait tárolja. |
| **space_info** | Információ a fájlrendszer szabad és elérhető helyéről. |
| **file_type** (enum) | A fájl típusát határozza meg (pl. mappa, szabályos fájl). |
| **perms** (enum) | Fájlrendszer jogosultságok azonosítása. |
| **perm_options** (enum) | Jogosultsági műveletek viselkedésének szabályozása. |
| **copy_options** (enum) | Másolási műveletek viselkedésének szabályozása. |
| **directory_options** (enum) | Könyvtár-iterálás beállításai. |
| **file_time_type** | Fájlok időbélyegzőit képviselő típus. |

## Nem-tagfüggvények (Non-member functions)

Ezek a függvények végzik a tényleges műveleteket a fájlrendszeren.

| Függvény | Leírás |
| :--- | :--- |
| **absolute** | Abszolút útvonalat készít egy megadott útból. |
| **system_complete** | Abszolút útvonallá alakítja az utat az OS-specifikus viselkedést másolva (Experimental). |
| **canonical** / **weakly_canonical** | Kanonikus (tisztított, szimbolikus linkektől mentes) útvonalat hoz létre. |
| **relative** / **proximate** | Relatív útvonalat készít. |
| **copy** | Fájlok vagy könyvtárak másolása. |
| **copy_file** | Egy fájl tartalmának másolása. |
| **copy_symlink** | Szimbolikus link másolása. |
| **create_directory** / **create_directories** | Új könyvtár(ak) létrehozása. |
| **create_hard_link** | Hard link (közvetlen hivatkozás) létrehozása. |
| **create_symlink** / **create_directory_symlink** | Szimbolikus link létrehozása fájlhoz vagy könyvtárhoz. |
| **current_path** | Lekérdezi vagy beállítja az aktuális munkakönyvtárat. |
| **exists** | Ellenőrzi, hogy az adott útvonal létezik-e. |
| **equivalent** | Megnézi, hogy két útvonal ugyanarra a fájlrendszer-objektumra mutat-e. |
| **file_size** | Visszaadja a fájl méretét bájtban. |
| **hard_link_count** | Visszaadja az adott fájlra mutató hard linkek számát. |
| **last_write_time** | Lekérdezi vagy beállítja az utolsó módosítás idejét. |
| **permissions** | Módosítja a fájl-hozzáférési jogosultságokat. |
| **read_symlink** | Lekérdezi, hova mutat egy szimbolikus link. |
| **remove** / **remove_all** | Fájl vagy könyvtár törlése (a `remove_all` rekurzívan töröl). |
| **rename** | Fájl vagy könyvtár áthelyezése vagy átnevezése. |
| **resize_file** | Megváltoztatja a fájl méretét (levágás vagy kiegészítés). |
| **space** | Lekérdezi a szabad helyet a fájlrendszeren. |
| **status** / **symlink_status** | Lekérdezi a fájl attribútumait (típus, jogosultságok). |
| **temp_directory_path** | Visszaadja az ideiglenes fájlok számára fenntartott mappát. |

## Fájltípus ellenőrző függvények (File types)

Ezek a függvények segítenek megállapítani, hogy egy adott útvonal milyen típusú objektumra mutat.

| Függvény | Leírás |
| :--- | :--- |
| **is_directory** | Ellenőrzi, hogy az útvonal könyvtárra mutat-e. |
| **is_regular_file** | Ellenőrzi, hogy az útvonal szabályos (normál) fájlra mutat-e. |
| **is_symlink** | Ellenőrzi, hogy az útvonal szimbolikus link-e. |
| **is_empty** | Megnézi, hogy a fájl vagy könyvtár üres-e. |
| **is_block_file** | Blokk-eszközre mutat-e az út. |
| **is_character_file** | Karakter-eszközre mutat-e az út. |
| **is_fifo** | Nevesített csővezetékre (FIFO) mutat-e az út. |
| **is_socket** | IPC socketre mutat-e az út. |
| **is_other** | Egyéb típusú fájl-e (pl. eszközfájl, de nem blokk/karakter). |
| **status_known** | Ellenőrzi, hogy a fájl állapota lekérdezhető-e. |

### Gyakorlati példa

```cpp
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path p = "adatok/teszt.txt";

    std::cout << "Fájlnév: " << p.filename() << "\n";
    std::cout << "Kiterjesztés: " << p.extension() << "\n";
    std::cout << "Szülő mappa: " << p.parent_path() << "\n";

    // Létezés ellenőrzése
    if (fs::exists(p)) {
        std::cout << "A fájl létezik, mérete: " << fs::file_size(p) << " bájt\n";
    }

    // Könyvtár tartalmának kilistázása
    fs::path dir = ".";
    for (const auto& entry : fs::directory_iterator(dir)) {
        std::cout << (entry.is_directory() ? "[D] " : "[F] ") 
                  << entry.path().filename() << "\n";
    }

    return 0;
}
```





Ezek a könyvtárak lehetővé teszik a fix méretű memóriaterületek (karaktertömbök) folyamként való kezelését.

### Span-alapú folyamok (C++23)
A `<spanstream>` fejléc rögzített méretű karakter-puffereken végzett műveleteket tesz lehetővé, memóriafoglalás nélkül.

| Osztály | Leírás |
| :--- | :--- |
| **basic_spanbuf** | Rögzített karakter-puffer eszközt valósít meg. |
| **basic_ispanstream** | Bemeneti műveletek rögzített pufferen. |
| **basic_ospanstream** | Kimeneti műveletek rögzített pufferen. |
| **basic_spanstream** | Be- és kimeneti műveletek rögzített pufferen. |

### Karaktertömb folyamok (Elavult)
A `<strstream>` fejléc elemei elavultak (deprecated), használatuk nem javasolt, mert a C++26-ban eltávolításra kerülnek. Helyettük a `<sstream>` vagy `<spanstream>` használandó.

| Osztály | Állapot | Leírás |
| :--- | :--- | :--- |
| **strstreambuf** | Elavult (C++98) | Nyers karaktertömb eszköz. |
| **istrstream** | Elavult (C++98) | Bemeneti műveletek karaktertömbön. |
| **ostrstream** | Elavult (C++98) | Kimeneti műveletek karaktertömbön. |
| **strstream** | Elavult (C++98) | Be- és kimenet karaktertömbön. |

## Szinkronizált kimenet (C++20)

A `<syncstream>` fejléc segít elkerülni, hogy a párhuzamosan futó szálak kimenetei (pl. `cout` hívások) összekeveredjenek a konzolon.

| Osztály | Leírás |
| :--- | :--- |
| **basic_syncbuf** | Szinkronizált kimeneti eszköz burkoló (wrapper). |
| **basic_osyncstream** | Szinkronizált kimeneti folyam burkoló. |

### Példa: Szálbiztos kiírás (osyncstream)

```cpp
#include <syncstream>
#include <iostream>
#include <thread>

void munkas(int id) {
    // osyncstream használatával az egész blokk egyszerre íródik ki
    std::osyncstream(std::cout) << "Szál " << id << " üzeni: Kész vagyok!\n";
}

int main() {
    std::thread t1(munkas, 1), t2(munkas, 2);
    t1.join();
    t2.join();
    return 0;
    }
    ```

    ---

    # Dátum és Idő könyvtár (Date and Time Library)

    A C++ kétféle módszert biztosít az idő kezelésére:
    1. **Chrono könyvtár (C++11 óta):** Rugalmas, típusbiztos eszközrendszer az idő mérésére különböző pontossággal.
    2. **C-stílusú dátum és idő:** Hagyományos függvények (pl. `std::time`), amik a `<ctime>` fejlécben találhatók.

    ## Chrono könyvtár (C++11 óta)

    A `<chrono>` fejlécben definiált könyvtár több alapvető típust és segédfüggvényt tartalmaz:
    - **Órák (Clocks):** Meghatározzák a kezdőpontot (epoch) és az ütemet (tick rate).
    - **Időpontok (Time points):** Egy konkrét pillanat az időben.
    - **Időtartamok (Durations):** Két időpont közötti különbség.
    - **Naptári dátumok és Időzónák (C++20 óta):** Komplexebb dátumkezelés és zóna-átalakítások.

    ### Órák (Clocks)

    Minden óra egy kezdőpontból (epoch) és egy mérési sebességből áll.

    | Óra típus | Leírás | Szabvány |
    | :--- | :--- | :--- |
    | **system_clock** | A rendszer valós idejű órája (falióra). Alkalmas naptári időhöz. | C++11 |
    | **steady_clock** | Monoton óra, amely soha nem ugrik vissza. Időtartamok mérésére kiváló. | C++11 |
    | **high_resolution_clock** | A rendszerben elérhető legkisebb ütemű (legpontosabb) óra. | C++11 |
    | **utc_clock** | Összehangolt világidő (UTC) óra. Kezeli a szökőmásodperceket. | C++20 |
    | **tai_clock** | Nemzetközi atomidő (TAI) óra. | C++20 |
    | **gps_clock** | GPS idő óra. | C++20 |
    | **file_clock** | Fájlok időbélyegzőihez használt óra. | C++20 |
    | **local_t** | Helyi időt reprezentáló pszeudo-óra. | C++20 |
    | **is_clock** / **is_clock_v** | Segédeszköz annak eldöntésére, hogy egy típus óra-e. | C++20 |

    ## Időpontok (Time points)

    Az időpont egy időtartamot képvisel, amely egy adott óra kezdőpontja (epoch) óta telt el.

    | Osztály / Függvény | Leírás | Szabvány |
    | :--- | :--- | :--- |
    | **time_point** | Egy konkrét pillanat az időben. | C++11 |
    | **clock_cast** | Időpont konvertálása egyik óráról a másikra (pl. rendszeridőről UTC-re). | C++20 |
    | **clock_time_conversion** | Trait osztály, amely meghatározza az órák közötti átváltás módját. | C++20 |

    ## Időtartamok (Durations)

    Az időtartam egy időintervallumot képvisel, amelyet az egységnyi idő (tick) száma határoz meg. Például a "42 másodperc" 42 darab 1 másodperces egységből áll.

    | Osztály | Leírás | Szabvány |
    | :--- | :--- | :--- |
    | **duration** | Egy időintervallum tárolása és kezelése. | C++11 |

    ## Napszak kezelés (Time of day - C++20 óta)

    A `hh_mm_ss` osztály segít felosztani egy időtartamot (pl. az éjfél óta eltelt időt) órákra, percekre és másodpercekre. Ez elsősorban formázási segédeszköz.

    | Osztály / Függvény | Leírás | Szabvány |
    | :--- | :--- | :--- |
    | **hh_mm_ss** | Egy napszakot (óra, perc, másodperc, törtrész) képvisel. | C++20 |
    | **is_am** / **is_pm** | Eldönti, hogy délelőtt (AM) vagy délután (PM) van-e. | C++20 |
    | **make12** / **make24** | Átváltás 12 és 24 órás időformátumok között. | C++20 |

    ## Naptár (Calendar - C++20 óta)

    A C++20 naptári típusai lehetővé teszik a dátumok (év, hónap, nap) kényelmes és típusbiztos kezelését a Gergely-naptár szerint.

    | Osztály | Leírás |
    | :--- | :--- |
    | **day** | A hónap egy napját képviseli (1-31). |
    | **month** | Az év egy hónapját képviseli (Jan-Dec). |
    | **year** | Egy évet képvisel. |
    | **weekday** | A hét egy napját képviseli (Hétfő-Vasárnap). |
    | **weekday_indexed** | Egy hónap n-edik adott hétköznapját képviseli (pl. a hónap 2. keddje). |
    | **weekday_last** | Egy hónap utolsó adott hétköznapját képviseli. |
    | **last_spec** | Jelölő osztály a hónap utolsó napjának vagy hétköznapjának megjelöléséhez. |
    | **month_day** | Egy adott hónap adott napját képviseli. |
    | **month_day_last** | Egy adott hónap utolsó napját képviseli. |
    | **month_weekday** | Egy adott hónap n-edik hétköznapját képviseli. |
    | **month_weekday_last** | Egy adott hónap utolsó hétköznapját képviseli. |
    | **year_month** | Egy adott év adott hónapját képviseli. |
    | **year_month_day** | Egy konkrét évet, hónapot és napot képvisel. |
    | **year_month_day_last** | Egy adott év és hónap utolsó napját képviseli. |
    | **year_month_weekday** | Egy adott év és hónap n-edik hétköznapját képviseli. |
    | **year_month_weekday_last** | Egy adott év és hónap utolsó hétköznapját képviseli. |
    | **operator/** | Kényelmes szintaxis a dátumok létrehozásához (pl. `2026y/April/27d`). |

    ### Gyakorlati példa

    ```cpp
    #include <iostream>
    #include <chrono>
    #include <thread>

    int main() {
    using namespace std::chrono;

    // Kezdő időpont
    auto start = steady_clock::now();

    // Szimulált munka (várakozás)
    std::this_thread::sleep_for(milliseconds(500));

    // Vége időpont
    auto end = steady_clock::now();

    // Időtartam kiszámítása
    duration<double, std::milli> eltel = end - start;

    std::cout << "Eltelt idő: " << eltel.count() << " ms\n";

    return 0;
    }
    ```

## Időzónák (Time zones - C++20 óta)

A C++20 bevezette az IANA időzóna-adatbázis támogatását, lehetővé téve a pontos időzóna-átalakításokat.

| Osztály / Függvény | Leírás |
| :--- | :--- |
| **tzdb** | Az IANA időzóna-adatbázis egy másolatát reprezentálja. |
| **tzdb_list** | A rendelkezésre álló `tzdb` objektumok láncolt listája. |
| **get_tzdb** / **get_tzdb_list** | Hozzáférés a globális időzóna-adatbázishoz. |
| **locate_zone** | Megkeres egy időzónát a neve alapján (pl. "Europe/Budapest"). |
| **current_zone** | Visszaadja a rendszer aktuális időzónáját. |
| **time_zone** | Egy konkrét időzónát reprezentál. |
| **sys_info** | Információt ad egy időzónáról egy adott időpontban (pl. eltolás, nyári időszámítás). |
| **local_info** | Információt ad a helyi idő és a UNIX idő közötti átalakításról. |
| **choose** (enum) | Kiválasztja, hogyan oldjuk fel a kétértelmű helyi időt. |
| **zoned_time** | Egy időzónát és egy időpontot kapcsol össze. |
| **zoned_traits** | Trait osztály az időzóna-mutatókhoz. |
| **leap_second** | Információ egy szökőmásodperc beiktatásáról. |
| **leap_second_info** | Szökőmásodperc beiktatási adatok. |
| **get_leap_second_info**| Szökőmásodperc információ lekérése UTC időpontból. |
| **time_zone_link** | Egy időzóna alternatív nevét reprezentálja. |
| **nonexistent_local_time**| Kivétel: nem létező helyi idő (pl. óraátállítás miatt kimaradó óra). |
| **ambiguous_local_time** | Kivétel: kétértelmű helyi idő (pl. óraátállítás miatt ismétlődő óra). |
| **reload_tzdb** | Frissíti az időzóna-adatbázist. |
| **remote_version** | Lekéri az adatbázis legfrissebb elérhető verzióját. |

## Literálok (Literals - C++14/20 óta)

A literálok segítségével olvashatóbb módon adhatunk meg időtartamokat és dátumokat. Használatukhoz a `using namespace std::chrono_literals;` szükséges.

| Literál | Leírás | Szabvány |
| :--- | :--- | :--- |
| **operator""h** | Óra (`std::chrono::hours`) | C++14 |
| **operator""min** | Perc (`std::chrono::minutes`) | C++14 |
| **operator""s** | Másodperc (`std::chrono::seconds`) | C++14 |
| **operator""ms** | Milliszekundum (`std::chrono::milliseconds`) | C++14 |
| **operator""us** | Mikroszekundum (`std::chrono::microseconds`) | C++14 |
| **operator""ns** | Nanoszekundum (`std::chrono::nanoseconds`) | C++14 |
| **operator""y** | Év (`std::chrono::year`) | C++20 |
| **operator""d** | Nap (`std::chrono::day`) | C++20 |

### Gyakorlati példa (Literálok használata)

```cpp
#include <chrono>
#include <iostream>

int main() {
    using namespace std::chrono_literals;

    auto fel_ora = 30min;
    auto egy_nap = 24h;
    auto ev = 2026y;
    auto nap = 27d;

    std::cout << "30 perc az " << fel_ora.count() << " perc.\n";
    
    return 0;
}
```

### Gyakorlati példa (Időzóna lekérdezése)

```cpp
#include <iostream>
#include <chrono>

int main() {
    try {
        auto zóna = std::chrono::current_zone();
        std::cout << "Aktuális időzóna: " << zóna->name() << "\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Hiba: " << e.what() << "\n";
    }
    return 0;
}
```














