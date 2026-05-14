# C++ Dokumentációs Útmutató: Doxygen és Profi Kommentelés

Ez a segédlet bemutatja, hogyan dokumentáld a kódodat úgy, hogy az megfeleljen az iparági sztenderdeknek.

---

## 1. Mi az a Doxygen?
A Doxygen egy olyan eszköz, ami a speciális formátumú kommentekből automatikusan képes weboldalt (HTML) vagy PDF dokumentációt generálni a kódodhoz.

### Speciális karakterek
- `/**` : Ezzel kezdődik a Doxygen blokk.
- `@` vagy `\` : Ezzel kezdődnek a parancsok (pl. `@brief`).

---

## 2. Fájl fejléc (File Header)
Minden fájl elejére kötelező tenni egy összefoglalót.

```cpp
/**
 * @file MyLogic.cpp
 * @author AtiBexx2
 * @date 2026-04-23
 * @version 1.0
 * @brief Ez a modul felelős a fájlok beolvasásáért és a szavak tisztításáért.
 * 
 * @details A modul támogatja az UTF-8 karaktereket, kezeli a Windows és Linux 
 * útvonalak közötti különbséget, és hibanaplót készít hiba esetén.
 */
```

---

## 3. Függvények dokumentálása
Ez a legfontosabb rész. Leírjuk, mit vár a függvény, és mit ad vissza.

```cpp
/**
 * @brief Megkeresi és lecseréli az ékezetes karaktereket sima megfelelőjükre.
 * 
 * @param s A bemeneti szöveg, amit tisztítani kell (pl. "árvíztűrő").
 * @param upper Ha igaz, a kimenet nagybetűs lesz. Alapértelmezett: false.
 * @return std::string A megtisztított, ékezetmentes szöveg (pl. "arvizturo").
 * 
 * @note A függvény UTF-8 kódolást vár.
 * @warning Ha a bemeneti string hibás byte-okat tartalmaz, a program leállhat!
 */
std::string cleanText(const std::string& s, bool upper = false);
```

---

## 4. Struktúrák és Enumok
Ne csak a nevet írd le, hanem azt is, hogy az egyes értékek mire jók.

```cpp
/**
 * @brief A fájlműveletek lehetséges kimenetei.
 */
enum class FileStatus {
    SUCCESS,  /**< A művelet hiba nélkül lefutott. */
    NOT_FOUND, /**< A megadott fájl nem létezik az útvonalon. */
    LOCKED    /**< A fájlt egy másik folyamat használja. */
};
```

---

## 5. Profi "Belső" kommentek (Inline)
A kód belsejében ne azt írd le, *mit* csinál a kód (azt látjuk a parancsból), hanem azt, hogy *miért*.

**Rossz példa:**
```cpp
i++; // Növeljük i értékét eggyel. (Felesleges információ)
```

**Jó példa:**
```cpp
i++; // Átugorjuk a fejlécet, mert az nem tartalmaz adatot.
```

---

## 6. Munkafolyamat jelölők (TODO, FIXME)
A modern IDE-k (mint a VS Code) összegyűjtik ezeket neked egy listába.

- **`// TODO:`** : Valami, amit még meg kell csinálni, de most nincs rá idő.
- **`// FIXME:`** : Ismert hiba a kódban, amit sürgősen javítani kellene.
- **`// BUG:`** : Egy konkrét hiba leírása.
- **`// NOTE:`** : Fontos megjegyzés a kód működésével kapcsolatban.
- **`// HACK:`** : "Csúnya" megoldás, ami működik, de később szebben kell megírni.

### Példa:
```cpp
void loadConfig() {
    // TODO: Implementálni a JSON alapú beolvasást is, most csak .cfg megy.
    // FIXME: Ez a rész összeomlik, ha a fájl üres!
    // NOTE: Az alapértelmezett port a 8080.
}
```

---

## 7. Doxygen Parancsok Gyorslistája

| Parancs | Jelentése |
| :--- | :--- |
| `@brief` | Rövid, egysoros leírás. |
| `@details` | Részletes magyarázat (több soros is lehet). |
| `@param` | Függvény paramétere (`@param név Leírás`). |
| `@return` | A visszatérési érték leírása. |
| `@see` | Hivatkozás egy másik függvényre vagy fájlra. |
| `@author` | A kód szerzője. |
| `@deprecated` | Jelzi, hogy a függvény régi, ne használd már. |

---

## 8. Haladó Doxygen Technikák

### A) Sablonok (Templates) dokumentálása
Mivel C++-ban sokat használunk template-eket, fontos leírni, mi az a `T`.

```cpp
/**
 * @brief Általános függvény két érték felcserélésére.
 * @tparam T Bármilyen típus, aminek van másoló konstruktora.
 * @param a Az első érték.
 * @param b A második érték.
 */
template <typename T>
void swapValues(T& a, T& b) { ... }
```

### B) Logikai feltételek (Pre/Post conditions)
Leírhatod, hogy minek kell teljesülnie a függvény előtt és után.

- **`@pre`** (Precondition): Előfeltétel (pl. a mutató nem lehet NULL).
- **`@post`** (Postcondition): Utófeltétel (pl. a lista mérete eggyel nő).

```cpp
/**
 * @brief Elem hozzáadása a listához.
 * @pre A lista már inicializálva kell, hogy legyen.
 * @post A lista nem lesz üres a hívás után.
 */
```

### C) Kódpéldák beszúrása
Ha meg akarod mutatni, hogyan kell használni a függvényedet a dokumentáción belül.

```cpp
/**
 * @brief Adatbázis kapcsolódás.
 * @code
 *    DB conn;
 *    if (conn.connect("localhost")) {
 *        std::cout << "Siker!";
 *    }
 * @endcode
 */
```

### D) Verziókövetés és Hivatkozások
- **`@since`** : Mikortól érhető el ez a funkció (pl. `@since v1.2`).
- **`@ref`** : Hivatkozás egy másik osztályra vagy függvényre (kattintható lesz a doksiban).
- **`@bug`** : Egy ismert hiba leírása, amit még nem sikerült kijavítani.
- **`@todo`** : (Említettük, de Doxygenben külön listát készít belőle a generált oldalon).

---

## 9. Végső Tanács Gemmitől
A Doxygen parancsokat mindig a **deklaráció** (a `.h` fájlban lévő rész) fölé írd, ne a megvalósítás (`.cpp`) fölé. Így ha valaki csak a headert nézi meg, rögtön látja az összes instrukciót!

**Gemmi tippje:** Ha konzolos programot írsz, a Doxygen segítségével egyetlen paranccsal készíthetsz egy profi PDF-et a projektedről, amit bárkinek megmutathatsz! 🚀💻🏆
