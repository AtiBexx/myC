# C++ Nyelvi Kezelés, Fájlkezelés és String Referencia

Ez a dokumentum a legteljesebb útmutató a többnyelvűséghez, a konfigurációkhoz, a fájlok beolvasásához és a stringek kezeléséhez.

---

## 1. Nyelvi Kezelés (Struct & Enum)
*Lásd a korábbi fejezeteket a részletekért: `Language` enum, `VocabMenu` struct és `std::vector` alapú tárolás.*

---

## 2. Konfiguráció és Külső Nyelvek (CFG & INI)
*Lásd a korábbi fejezeteket: `AppConfig` struct mentése/betöltése és `std::map<string, string>` használata a `lang.ini`-hez.*

---

## 3. MINDEN Fájlbeolvasási Funkció és Mód

A C++-ban az `std::ifstream` (beolvasás) és `std::ofstream` (írás) az alap.

### A) Megnyitási módok (`std::ios`)
Amikor megnyitsz egy fájlt, megadhatod a módot:
- `std::ios::in` : Olvasás (alapértelmezett ifstream-nél).
- `std::ios::out` : Írás (alapértelmezett ofstream-nél).
- `std::ios::app` : Hozzáfűzés a végéhez (Append).
- `std::ios::ate` : Megnyitás után a végére ugrik (At the end).
- `std::ios::trunc` : Ha létezik, törli a tartalmát (Truncate).
- `std::ios::binary` : Bináris mód (nem kezeli le az újsorokat speciálisan).

### B) Fájl állapot ellenőrzése
```cpp
file.is_open(); // Igaz, ha sikerült megnyitni
file.good();    // Minden rendben van
file.eof();     // Elértük a fájl végét (End of File)
file.fail();    // Logikai hiba (pl. rossz formátum)
file.bad();     // Súlyos hiba (pl. hardver hiba)
```

### C) Beolvasási függvények
- `file >> adat;` : Beolvasás szóközig.
- `std::getline(file, string);` : Beolvasás sor végéig.
- `file.get(char);` : Egyetlen karakter beolvasása.
- `file.read(buffer, n);` : Beolvas pontosan `n` bájtot (bináris).
- `file.peek();` : Megnézi a következő karaktert, de nem veszi ki.
- `file.unget();` : Visszateszi az utoljára kiolvasott karaktert.

### D) Pozicionálás (Keresés a fájlban)
- `file.tellg();` : Visszaadja a jelenlegi pozíciót (hol tartunk a beolvasásban).
- `file.seekg(pozicio);` : Egy adott bájtra ugrik.
- `file.seekg(offset, irany);` : Elmozdulás valahonnan.
  - Irányok: `std::ios::beg` (elejétől), `std::ios::cur` (mostani helytől), `std::ios::end` (végétől).

### E) Fájlrendszer műveletek (`std::filesystem`) - A TELJES LISTA
```cpp
#include <filesystem>
namespace fs = std::filesystem;
```

#### 1. Az `fs::path` osztály (Az útvonalak királya)
A `path` nem csak egy string, hanem okos: automatikusan kezeli a `/` és `\` jeleket operációs rendszertől függően.
- `path p = "C:/adatok/szavak.txt";`
- `p.filename()` : "szavak.txt"
- `p.extension()` : ".txt"
- `p.stem()` : "szavak" (kiterjesztés nélkül)
- `p.parent_path()` : "C:/adatok"
- `p.is_absolute()` / `p.is_relative()` : Logikai ellenőrzés.
- `p.replace_extension(".dat")` : Lecseréli a kiterjesztést.
- `p1 / p2` : Az `/` operátor összefűzi az útvonalakat (pl. "mappa" / "file.txt" -> "mappa/file.txt").

#### 2. Fájl és Mappa műveletek
- `fs::exists(p)` : Létezik-e a fájl/mappa?
- `fs::create_directory(p)` : Mappa létrehozása.
- `fs::create_directories(p)` : Teljes mappaszerkezet létrehozása (mint a `mkdir -p`).
- `fs::copy(honnan, hova)` : Másolás (fájl vagy mappa).
- `fs::copy_file(honnan, hova)` : Csak fájl másolása.
- `fs::rename(regi, uj)` : Átnevezés vagy mozgatás.
- `fs::remove(p)` : Törlés.
- `fs::remove_all(p)` : Mappa törlése minden tartalmával együtt.
- `fs::current_path()` : Aktuális munkakönyvtár lekérése/beállítása.
- `fs::temp_directory_path()` : A rendszer ideiglenes mappájának elérése.

#### 3. Lekérdezések (Információgyűjtés)
- `fs::file_size(p)` : Méret bájtban.
- `fs::is_directory(p)` : Mappa-e?
- `fs::is_regular_file(p)` : Sima fájl-e?
- `fs::last_write_time(p)` : Utolsó módosítás ideje.
- `fs::space(p)` : Lemezterület infó (`capacity`, `free`, `available` bájtok).
- `fs::hard_link_count(p)` : Hány hivatkozás van a fájlra.

#### 4. Jogosultságok
- `fs::permissions(p, fs::perms::owner_read | fs::perms::group_read)` : Jogok beállítása.

#### 5. Bejárás (Iterátorok) - Mappa tartalmának listázása
```cpp
// Csak az adott mappában:
for (const auto& entry : fs::directory_iterator("mappa")) {
    std::cout << entry.path() << std::endl;
}

// Rekurzívan (minden almappában is):
for (const auto& entry : fs::recursive_directory_iterator("mappa")) {
    std::cout << entry.path() << std::endl;
}
```

---

## 4. MINDEN String Függvény és Tulajdonság

A `std::string` egy dinamikus tömb, rengeteg beépített képességgel.

### Iterátorok (Bejáráshoz)
- `s.begin()`, `s.end()` : Eleje és vége.
- `s.rbegin()`, `s.rend()` : Fordított irányú bejáráshoz.

### Kapacitás és Méret
- `s.size()` vagy `s.length()` : Karakterek száma.
- `s.max_size()` : Maximális elméleti méret.
- `s.capacity()` : Lefoglalt memória mérete (több lehet, mint a size).
- `s.resize(n)` : Átméretezi a stringet.
- `s.reserve(n)` : Előre lefoglal memóriát (gyorsítás).
- `s.shrink_to_fit()` : Felszabadítja a feleslegesen lefoglalt memóriát.
- `s.clear()` : Kiüríti a tartalmát.
- `s.empty()` : Igaz, ha a méret 0.

### Elemek elérése
- `s[i]` : Elérés (gyors, de nem ellenőriz).
- `s.at(i)` : Elérés (biztonságos, hibát dob, ha rossz az index).
- `s.front()` : Első karakter.
- `s.back()` : Utolsó karakter.
- `s.data()` vagy `s.c_str()` : C-stílusú mutatót ad (`const char*`).

### Módosítások
- `s += "..."` vagy `s.append("...")` : Hozzáfűzés.
- `s.push_back('c')` : Egy karakter a végére.
- `s.pop_back()` : Utolsó karakter törlése.
- `s.assign("új")` : Új értéket ad neki.
- `s.insert(poz, "szöveg")` : Beszúrás adott helyre.
- `s.erase(poz, hossz)` : Törlés adott helyről.
- `s.replace(poz, hossz, "mire")` : Csere.
- `s.swap(s2)` : Felcseréli két string tartalmát.

### Keresés (Minden variáció)
- `s.find("mit")` : Első előfordulás.
- `s.rfind("mit")` : Utolsó előfordulás.
- `s.find_first_of("abc")` : Az első karakter, ami az "abc" közül bármelyik.
- `s.find_last_of("abc")` : Az utolsó karakter, ami az "abc" közül bármelyik.
- `s.find_first_not_of("abc")` : Az első, ami NEM az "abc" része.
- `s.find_last_not_of("abc")` : Az utolsó, ami NEM az "abc" része.

### Műveletek
- `s.substr(poz, hossz)` : Részstring kivágása.
- `s.compare(s2)` : Összehasonlítás (0 ha egyenlő).

---

## 5. Globális String Segédfüggvények
Ezek nem a string osztály részei, de vele dolgoznak:
- `std::getline(std::cin, s)` : Teljes sor beolvasása billentyűzetről.
- `std::to_string(ertek)` : Szám -> String.
- `std::stoi(s)`, `std::stod(s)`, `std::stol(s)` : String -> Int, Double, Long.

**Megjegyzés:** A stringek indexelése mindig 0-tól kezdődik! Ha egy keresés nem talál semmit, az eredmény mindig `std::string::npos`.

---

## 6. Hálózatkezelés C++-ban (WinSock / Sockets)

A C++ alapból nem tud hálózatot kezelni, ezért Windows-on a `WinSock2` könyvtárat kell használnunk.

### Alapvető beállítások
```cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib") // A könyvtár linkelése
```

---

## 17. Hasznos Segédfüggvények (Utility functions)

Ezek a függvények segítenek a felhasználói felület és az adatok tisztításában.

### A) Puffer kezelés és Várakozás
Ha `cin >> x` után `getline`-t használsz, a pufferben maradt újsor karakter (`\n`) bekavarhat. Ezt így oldjuk meg:

```cpp
#include <limits>

// Puffer törlése (hogy ne ugorjon át a bevitelen)
void pufferDelete() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Várakozás Enterre
void waitToEnter() {
    std::cout << "Nyomj Entert a folytatáshoz...";
    // Ha előtte cin >> volt, kell a pufferDelete()!
    std::cin.get(); 
}
```

### B) Képernyő törlése (Screen Wipe)
A leggyorsabb és legmodernebb módja a képernyő letakarításának ANSI kódokkal (Windows 10+ és Linux is támogatja):

```cpp
void screenWipe() {
    // \x1B[2J = Képernyő törlése, \x1B[H = Kurzort haza (bal felső sarok)
    std::cout << "\x1B[2J\x1B[H\x1B[3J" << std::flush;
}
```

---

## 18. Rendszerszintű trükkök (Unicode, Vágólap, Billentyűzet)

### A) Unicode és Ékezetek Windows-on
Windows-on a konzol alapból nem szereti az UTF-8-at. Ahhoz, hogy lásd az ékezeteket, ezt be kell állítani:

```cpp
#ifdef _WIN32
#include <windows.h>
void setupUnicode() {
    SetConsoleOutputCP(CP_UTF8); // Kimenet UTF-8-ra
    SetConsoleCP(CP_UTF8);       // Bemenet UTF-8-ra
}
#endif
```

### B) UTF-16 -> UTF-8 átalakítás
A Windows belsőleg UTF-16-ot (`wstring`) használ, de mi a kódban jobban szeretjük a sima UTF-8 `string`-et. Ez a függvény a "híd":

```cpp
std::string Utf16ToUtf8(const std::wstring& utf16) {
    if (utf16.empty()) return "";
    // 1. Megkérdezzük mekkora hely kell
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &utf16[0], (int)utf16.size(), NULL, 0, NULL, NULL);
    std::string strTo(size_needed, 0);
    // 2. Tényleges átalakítás
    WideCharToMultiByte(CP_UTF8, 0, &utf16[0], (int)utf16.size(), &strTo[0], size_needed, NULL, NULL);
    return strTo;
}
```

---

## 20. Valós idejű billentyűzetfigyelés (Smart Getline)

A sima `std::getline` megvárja az Entert. Ha te **azonnal** akarsz reagálni egy gombnyomásra (pl. súgó gomb), akkor karakterenként kell olvasnod a billentyűzetet.

---

## 21. Szálkezelés (Multithreading)

---

## 22. Okos Adattárolók (STL Containers)

| Konténer | Mikor használd? | Erőssége |
| :--- | :--- | :--- |
| `std::vector` | Sima lista | Gyors elérés index alapján. |
| `std::map` | Szótár (Kulcs-Érték) | Rendezett, jó keresés (pl. ékezetes térkép). |
| `std::unordered_map` | Gyors szótár | **Villámgyors** keresés (pl. kulcsszavak az IDE-be). |
| `std::set` | Halmaz | Csak egyedi elemeket tárol, automatikusan rendez. |

---

## 23. Generikus típusok (Sablonok / Templates)

A generikus programozás lényege: írj egy kódot egyszer, ami **bármilyen adattípussal** működik. C++-ban ezt a `template` kulcsszóval érjük el.

---

## 24. Profi Programozási Technikák és Kulcsszavak

### A) `const` és `static` - Mi a különbség?
- **`const`**: Változhatatlan érték. A fordító figyelmeztet, ha meg akarod változtatni. Használd mindenhol, ahol az érték fix!
- **`static`**: Megmaradó memória. 

### B) `std::string::npos` - A "Nincs találat" jelzése
Amikor a `find()` függvénnyel keresel egy stringben, és az nem talál semmit, akkor a visszatérési érték `npos`.

### C) `using` vs `using namespace std`
A `using namespace std;` kerülendő nagy projekteknél, mert névütközéseket okozhat. 

---

## 25. Bonyolult bemenetek feldolgozása (Parsing)
Ha a felhasználó parancsokat ír be (pl. `del mappa`), így szedhetjük szét:

```cpp
size_t spacePos = input.find(' ');
if (spacePos != std::string::npos) {
    string cmd = input.substr(0, spacePos); // A szóköz előtti rész
    string path = input.substr(spacePos + 1); // A szóköz utáni rész
}
```

---

## 27. Memóriakezelés: A régi és az új út

### A) A régi út: Pointerek (Nyers mutatók)
A pointer egy változó, ami egy **memóriacímet** tárol.

### B) C-stílusú foglalás (`malloc` / `free`) - KERÜLD!
Ez a régi C nyelv módszere. Csak bájtokat foglal, nem hívja meg a konstruktorokat, és nehézkes a használata.

```cpp
// Foglalás: (típus*)malloc(darabszám * sizeof(típus))
int* tomb = (int*)malloc(2000000 * sizeof(int));

if (tomb != NULL) {
    tomb[0] = 100;
    free(tomb); // Felszabadítás
}
```

### C) Hagyományos C++ foglalás (`new` / `delete`)
Ez a C++ saját módszere. Okosabb, mint a `malloc`, mert hív konstruktort és tudja a típust.

**Szabályok:**
1. Ha egyetlen objektumot foglalsz: `new` -> `delete`
2. Ha tömböt foglalsz: `new[]` -> `delete[]` (A szögletes zárójel kötelező!)

```cpp
// PÉLDA DINAMIKUS TÖMBRE:
int* tomb = new int[2000000]; // 8 MB a Heap-en
tomb[0] = 10;
delete[] tomb; // Mindig szabadítsd fel!
```

---

## 28. Az `&` és `*` operátorok szerepe és haszna

Gyakori kérdés: *"Nem lehetne csak a & operátort használni foglalás helyett?"*

1. **A `&` (Címképző / Referencia):**
   - Mint operátor: Megadja egy már létező változó címét. (`int* p = &x;`)
   - Mint típus: Egy "becenév" (alias) egy változóhoz. (`int& ref = x;`)
2. **A `new` vagy `malloc`:** Ezek **kérnek** új területet a Heap-en.
3. **A `*` (Dereferálás / Pointer):**
   - Mint operátor: Belenéz a cím által mutatott dobozba. (`std::cout << *p;`)
   - Mint típus: Egy változó, ami címet tárol. (`int* p;`)

### Mire használjuk ezeket a gyakorlatban?

**A Pointer (`double* numb`) - A "Helyfoglaló":**
- **Dinamikus memória (Heap):** Csak pointerrel érjük el a `new` által lefoglalt helyet.
- **Opcionális adat:** Lehet `nullptr` (azaz "nincs itt semmi").
- **Tömbök:** Pointerrel tudunk végigmenni egy adatsoron (`p++`).

### C) Pointer és Referencia Átjárhatóság (A "Híd")

Gyakori kérdés: *"Hogyan csináljak referenciát egy pointerből?"*

#### 1. A leggyakoribb hiba
```cpp
int* t = 5; // ❌ HIBA! A pointer címet vár, az 5-ös pedig egy sima szám.
```
**Helyesen:**
```cpp
int x = 5;
int* t = &x; // ✅ Így már az x címét tárolja.
```

#### 2. Átváltás: Pointer -> Referencia
Ha van egy pointered (`t`), de egy olyan függvényt akarsz meghívni, ami referenciát vár, használd a `*` operátort:

```cpp
void f(int& r) { r = 10; } // Referenciát vár

int x = 5;
int* t = &x;

f(*t); // ✅ A *t "feloldja" a címet, és magát az x-et adja át referenciaként.

// Vagy létrehozhatsz egy új alias-t is:
int& newT = *t; // newT mostantól az x egy másik neve.
```

#### 3. Gyors Szótár
| Kifejezés | Jelentése | Példa |
| :--- | :--- | :--- |
| `t` | **Cím:** Hol lakik az adat? | `0x7ffd...` |
| `*t` | **Érték:** Mi van a címen? | `5` |
| `&x` | **Címképzés:** Mi az x lakcíme? | `0x7ffd...` |
| `int& r = x` | **Alias:** x-nek van egy új neve (r). | `r = x` |
| `int& r = *t` | **Alias címről:** r a t által mutatott adat neve. | `r = *t` |

#### 4. A legfontosabb különbség (Biztonság)
- **Pointer:** Lehet üres (`int* t = nullptr;`).
- **Referencia:** **KÖTELEZŐ** azonnal inicializálni, sosem lehet üres! (`int& r;` ❌ ERROR).

---

## 29. Hatékonyság: Mikor másoljunk és mikor ne?

A C++-ban a sebesség titka a felesleges másolások elkerülése.

### 1. Érték szerinti átadás (Lassú nagy adatoknál)
Ha egy függvénynek így adsz át egy vektort: `void feldolgoz(std::vector<string> v)`, a C++ **lemásolja a teljes tartalmat**.

### 2. Referencia szerinti átadás (Villámgyors)
Ha így adod át: `void feldolgoz(std::vector<string>& v)`, akkor **0 bájt tényleges adat-másolás** történik. A függvény csak egy 8 bájtos címet kap az eredeti adathoz.

### 3. Mi történik a Stack-en? (A 8 bájtos szabály)
A modern 64 bites rendszereken egy memóriacím pontosan **8 bájt**.

- **Kicsi adatoknál** (pl. `double`, `int`, `bool`): 
  Egy `double` is 8 bájt. Ha referenciát használsz, a fordító gyakran **optimalizálja** a kódot, és a referencia **0 bájt** extra helyet foglal (mert csak egy álnév). Ebben az esetben a másolás és a referencia között nincs érdemi különbség.

- **Nagy adatoknál** (pl. `std::vector`, `std::string`, `struct`): 
  Itt jön a hatalmas spórolás! Míg a másolás millió bájtokat mozgatna, a referencia logikailag továbbra is csak egy álnév, fizikai megvalósításban pedig legfeljebb egy 8 bájtos cím.

**Konklúzió:** A referencia (`&`) a legmodernebb eszköz, mert logikailag "ingyen" van (0 bájt), és a fordítóra bízza, hogy a leggyorsabb módon (akár címátadással, akár az álnév behelyettesítésével) oldja meg a feladatot.

---

## 30. Speciális bemeneti trükkök


### A) Csak Enterre való várakozás
Ha azt akarod, hogy a programod tényleg csak az Enter leütése után menjen tovább:

```cpp
void waitOnlyForEnter() {
    std::cout << "Nyomj Entert a folytatashoz...";
    while (std::cin.get() != '\n'); // Addig olvas, amíg újsort nem talál
}
```

---

## 31. Tiszta Kód: Hatókör (Scope) és Globális Változók

---

## 32. A Teljes Memória-térkép (Hová kerül a változóm?)

Amikor elindul a programod, az operációs rendszer négy fő részre osztja a neki adott memóriát:

| Szegmens | Mi lakik itt? | Élettartam | Méret |
| :--- | :--- | :--- | :--- |
| **Code (Text)** | A lefordított gépi kód (utasítások). | Végig | Fix |
| **Static (Data)** | **Globális változók**, `static` változók. | Végig | Fix |
| **Stack (Verem)** | Helyi változók, függvényhívások. | Függvény végéig | Kicsi (1-8 MB) |
| **Heap (Halom)** | `new`, `malloc` által foglalt adatok. | Amíg fel nem szabadítod | Hatalmas (GB-ok) |

---

## 33. Hardveres Háttér: Stack vs. Heap

### A) Stack (Verem) - A gyorsító sáv
- **Mi ez?** Egy kicsi, extrém gyors memóriaterület a RAM-on belül.
- **Mérete:** Operációs rendszertől függ (Windows: 1 MB, Linux: 8 MB).
- **VESZÉLY (A nagy tömbök csapdája):** 
  Ha egy függvényen belül írod: `int tomb[2000000];`, az kb. 8 MB. Ez Windows-on **Stack Overflow** hibát okoz, mert a fordító NEM rakja át magától a Heap-re!
- **Szabály:** Ha kb. 100 KB-nál nagyobb adatod van, soha ne használd a sima fix tömböt, használd az `std::vector`-t!

### B) Heap (Halom) - A raktár
- **Mi ez?** A gép teljes szabad **RAM** memóriája. NEM azonos a HDD-vel!

---

## 34. CPU Cache: A láthatatlan segítő

---

## 35. Memória (RAM) vs. Háttértár (HDD/SSD)

---

## 36. Az RAII Elv: A Modern C++ Szíve

---

## 38. Nyelvi Kezelés C-ben (Pointerekkel)

Ha tiszta C-ben (nem C++!) akarnád megírni ugyanezt a fordítórendszert, az jóval "fapadosabb", de nagyon gyors lenne. Itt jönnek be képbe a **pointerek**.

### A) A Struktúra és Enum C-ben
C-ben nincs `std::string`, helyette `const char*`-ot használunk (mutató egy karaktersorra).

```c
// C-ben érdemes typedef-et használni, hogy ne kelljen mindig kiírni a 'struct' szót
typedef struct {
    const char* toBeRenamed;
    const char* newName;
} RenameFilesAndFolders;

typedef enum {
    LANG_HU = 0,
    LANG_EN = 1,
    LANG_ZH = 2
    // ...
} Language;
```

### B) Az Adatok Tárolása (Tömb)
Vektor helyett sima C tömböt használunk. A stringek a **Static (Read-only)** szegmensbe kerülnek.

```c
const RenameFilesAndFolders renameTranslations[] = {
    { "Átnevezendő: ", "\nUj nev: " }, // Index 0 (HU)
    { "Rename: ", "\nNew name: " }     // Index 1 (EN)
};
```

### C) Használat Pointerekkel
C-ben nincsenek referenciák (`&`), ezért a tömbelemre egy **pointerrel** mutatunk rá. A tagokat a `->` (nyíl) operátorral érjük el.

```c
void printRenameMenu(Language currentLang, const char* srcPath) {
    // Pointer a megfelelő nyelvi struct-ra
    const RenameFilesAndFolders* rfaf = &renameTranslations[currentLang];

    // C-ben printf van std::cout helyett
    printf("%s %s %s", rfaf->toBeRenamed, srcPath, rfaf->newName);
    
    // Bemenet fogadása:
    char inputName[256];
    fgets(inputName, sizeof(inputName), stdin);
}
```

### Mi a különbség? (C++ vs C)

| Jellemző | C++ (Amit most csinálsz) | C (A régi/nyers út) |
| :--- | :--- | :--- |
| **Szöveg** | `std::string` (biztonságos) | `const char*` (csak egy cím) |
| **Lista** | `std::vector` (dinamikus) | `Array[]` (fix méretű) |
| **Elérés** | Referencia (`&`) és `.` pont | Pointer (`*`) és `->` nyíl |
| **Kiírás** | `std::cout <<` | `printf("%s", ...)` |

**Gemmi megjegyzése:** A te C++ kódodban a `const RenameFilesAndFolders &RFAF` egy modern, biztonságos változata a C-s pointernek. A háttérben a gép majdnem ugyanazt csinálja, de a C++ megvéd attól, hogy véletlenül "félreugorj" a memóriában.

---

## 39. Végső Tanács Gemmitől
Mindig hasznást az **RAII** elvet és törekedj a **tiszta kódra**. Ne akarj "okosabb" lenni a fordítónál és a processzornál. Használj helyi változókar, mert a CPU Cache és a modern optimalizáció ezekre van kihegyezve.

Sok sikert a programozáshoz, Ati! Most már nálad van a teljes C++ tudástár! 😊🚀💻 <3

