# C++ CheatSheet

## Alapvető I/O műveletek

| Kód                                                          | Funkció                                                      | Fejléc                   |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------ |
| `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');` | **Puffer törlése** - Törli a bemenetet addig, amíg el nem éri a sor végét | `<limits>`               |
| `std::cin.ignore(10,'\n');`                                  | **Puffer törlése** - Maximálisan 10 karaktert dob el, amint talál egy '\n'-t (új sort), akkor abbahagyja és az '\n'-t is eldobja | `<iostream>`             |
| `std::cin.fail();`                                           | Megvizsgálja, hogy a cin-ben (**a bemenetben**) van-e hiba. **true**, ha a bemeneti művelet hibába ütközött | `<iostream>`             |
| `!std::cin.fail();`                                          | Ha ciklusban használod (**pl if**) akkor lép be egy ciklusba ha **false**, azaz nem ütközött hibába. ! negálás az eredeti ellentéte | `<iostream>`             |
| `std::cin.clear();`                                          | Törli a hibajelzést, a hibajelző flag-eket (**failbit, badbit, eofbit**) | `<iostream>`             |
| `std::cout << "";`                                           | Kiír valamit a képernyőre **(standard output)** - Stringet, számot vagy a változó értékét | `<iostream>`             |
| `<<`                                                         | A kiírás operátora - `<<"hello"` → **String/szám** kiírása, `<<valtozoErteke<<` → Kiírja **a változó értékét** | `<iostream>`             |
| `>>`                                                         | A beolvasás operátora (`std::cin >>`)                        | `<iostream>`             |
| `std::cin >> valtozoNeve;`                                   | **Beolvas** egy számot vagy egy sztringet és egy változóba menti az értéket | `<iostream>`             |
| `std::cin.get();`                                            | **Beolvas** egy karaktert                                    | `<iostream>`             |
| `std::getline();`                                            | **Beolvas** egy egész sort                                   | `<iostream>`, `<string>` |
| `char c;`<br>`std::cin.get(c);`                              | **Beolvas** egy karaktert / **elmenti** egy változóba        | `<iostream>`             |
| ``std::string input;` <br>`std::getline(std::cin, input);`   | Létrehoz egy **sztring változót** `input` névvel.<br>Beolvas egy **teljes sort** a konzolról (beleértve a szóközöket is).<br>A beolvasott sort elmenti az `input` változóba | `<iostream>`, `<string>` |
| system("cls");                                               | Képernyő rőrlése **only windows**                            |                          |
| std::cout << "\x1B[2J\x1B[H";                                | natív képernyő törlés mindehol müködik                       |                          |
| std::cin.clear();                                            | Hibakód törlése (geltline-nal nem kell)                      |                          |
| std::cerr <<"Hiba.......";                                   | Hibajelzés jelzése                                           |                          |
| std::getline(std::cin, line1);                               |                                                              |                          |
| std::cin.getline(cCell, 256);                                |                                                              |                          |

------

## ** `std::getline(std::cin, line)` – STL változat**

- **Típus:** `std::string`
- **Fejléc:** `<string>` + `<iostream>`
- **Használat:**

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    cout << "Írj be valamit: ";
    getline(cin, line); // teljes sort beolvas a \n-ig
    cout << "Beolvasott: " << line << endl;
    return 0;
}
```

- **Jellemzők:**
  - **Beolvasás típusa:** `std::string`
  - **Megáll:** sorvég (`\n`) előtt
  - **Útvonal:** `std::getline` automatikusan kezeli a buffer hosszát, nem kell előre méretet adni
  - **Előny:** dinamikusan növekvő string, Unicode karaktereket is képes kezelni (UTF-8)

------

## ** `std::cin.getline(char\* buffer, size)` – C-style változat**

- **Típus:** karaktertömb (`char[]`)
- **Fejléc:** `<iostream>`
- **Használat:**

```cpp
#include <iostream>
using namespace std;

int main() {
    char line[100];
    cout << "Írj be valamit: ";
    cin.getline(line, 100); // max 100 karakter beolvasása
    cout << "Beolvasott: " << line << endl;
    return 0;
}
```

- **Jellemzők:**
  - **Beolvasás típusa:** `char[]` (C-style string)
  - **Megáll:** sorvég (`\n`) előtt vagy ha elérjük a **max méretet**
  - **Buffer kezelés:** előre kell adni a tömb méretét, különben overflow lehet
  - **Előny:** régi kódokban használatos, kompatibilis C-vel

------

## **Összehasonlítás**

| Tulajdonság       | `std::getline(cin, std::string)` | `cin.getline(char*, n)`   |
| ----------------- | -------------------------------- | ------------------------- |
| Típus             | `std::string`                    | `char[]`                  |
| Max hossz         | dinamikus                        | előre definiált (`n-1`)   |
| Buffer kezelés    | automatikus                      | kézzel kell méretet adni  |
| Unicode támogatás | jó (UTF-8)                       | csak 1 byte per char      |
| Példa             | `std::getline(cin, line);`       | `cin.getline(line, 100);` |

------

 **`std::cin.getline(cCell, 256);`**

------

###  Mi történik itt**

```cpp
char cCell[256];
std::cin.getline(cCell, 256);
```

- `cCell` → egy **256 karakter hosszú karaktertömb** (C-style string).
- `std::cin.getline(cCell, 256)` → **beolvassa a felhasználó által beírt sort** a standard inputból (a `\n` karakterig vagy max 255 karakterig).
- **Null terminátor** (`\0`) automatikusan kerül a string végére.
- Ha a felhasználó több mint 255 karaktert ír be, **a maradék a bemeneti bufferben marad**, és a `failbit` beállítódik a `cin`-en.

------

### ** Példa**

```cpp
#include <iostream>
using namespace std;

int main() {
    char cCell[256];
    cout << "Írj be valamit (max 255 karakter): ";
    cin.getline(cCell, 256);

    cout << "Beolvasott szöveg: " << cCell << endl;
    return 0;
}
```

**Működés:**

- Felhasználó beír: `Hello, Nova! 🌍`
- `cCell` tartalma: `"Hello, Nova! 🌍"` (null terminátorral a végén)
- `cout` kiírja ugyanazt a sort.

------

### ** Összehasonlítás a `std::getline(cin, std::string)`-hez**

| Tulajdonság     | `cin.getline(cCell, 256)`       | `std::getline(cin, std::string)` |
| --------------- | ------------------------------- | -------------------------------- |
| Típus           | `char[]`                        | `std::string`                    |
| Max hossz       | fix, előre definiált (255 char) | dinamikus, bővíthető             |
| Unicode kezelés | csak 1 byte / char              | UTF-8 / Unicode kompatibilis     |
| Buffer overflow | ha több karakter, failbit       | automatikusan kezeli             |
| Példa           | `cin.getline(cCell, 256);`      | `getline(cin, line);`            |

------

 **Tipikus használat:**

- Ha régi C-stílus kódot írsz → `cin.getline(cCell, 256);`
- Ha modern C++ → `std::getline(cin, line);` sokkal biztonságosabb és kényelmesebb.

----------

## Ciklusok

| Ciklus       | Definíció                                          |
| ------------ | -------------------------------------------------- |
| `for (;;){}` | **Végtelen for ciklus** - a `break;`-kel lépünk ki |

## Parancssori argumentumok

| Argumentumok olvasására              | Definíció                                                    |
| ------------------------------------ | ------------------------------------------------------------ |
| `int main(int argc, char *argv[]){}` | **argc** - argumentumok számállítására<br>**argv** - argumentumok olvasására |
| `if (argc > 1)`                      |                                                              |

### Példa: Parancssori argumentumok feldolgozása

```cpp
#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::string input = argv[1];
        char* endptr;
        // Próbáljuk számmá alakítani
        long double num = std::strtold(input.c_str(), &endptr);
        // Ellenőrizzük, hogy az egész karakterlánc szám volt-e
        if (*endptr == '\0') {
            std::cout << "Sikeresen számot adtál meg: " << num << std::endl;
        } else {
            std::cout << "Nem számot adtál meg, hanem szöveget: " << input << std::endl;
        }
    } else {
        std::cout << "Használat: ./program <szám_vagy_szöveg>" << std::endl;
    }
    return 0;
}
```

## strto függvények (`<cstdlib>`)

| Függvény   | Definíció                                              | Típus              |
| ---------- | ------------------------------------------------------ | ------------------ |
| `strtol`   | Szöveget long típusú egész számmá alakít               | long               |
| `strtoll`  | Szöveget long long típusú egész számmá alakít          | long long          |
| `strtoul`  | Szöveget előjel nélküli long számmá alakít             | unsigned long      |
| `strtoull` | Szöveget előjel nélküli long long számmá alakít        | unsigned long long |
| `strtof`   | Szöveget float típusú lebegőpontos számmá alakít       | float              |
| `strtod`   | Szöveget double típusú lebegőpontos számmá alakít      | double             |
| `strtold`  | Szöveget long double típusú lebegőpontos számmá alakít | long double        |

| C függvény                                    | C++ alternatíva                                              |
| --------------------------------------------- | ------------------------------------------------------------ |
| `strtol` / `strtoll` / `strtoul` / `strtoull` | `std::stoi` / `std::stol` / `std::stoll` / `std::stoul` / `std::stoull` |
| `strtof`                                      | `std::stof`                                                  |
| `strtod`                                      | `std::stod`                                                  |
| `strtold`                                     | `std::stold`                                                 |

```
#include <iostream>
#include <string>

int main() {
    std::string s = "123.45";

    try {
        double d = std::stod(s);  // C++-os std::string -> double
        std::cout << d << "\n";
    } catch (const std::exception& e) {
        std::cout << "Hibás input\n";
    }

    return 0;
}
```

### `<inttypes.h>` fejléc függvényei

| Függvény    | Definíció                                     | Típus     |
| ----------- | --------------------------------------------- | --------- |
| `strtoimax` | Szöveget intmax_t típusú egész számmá alakít  | intmax_t  |
| `strtoumax` | Szöveget uintmax_t típusú egész számmá alakít | uintmax_t |

### Használat példa:

```cpp
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    const char* str = "123.45";
    
    // long double konvertálása
    char* endptr;
    long double ld = std::strtold(str, &endptr);
    
    if (*endptr == '\0') {
        std::cout << "Sikeres konverzió: " << ld << std::endl;
    } else {
        std::cout << "Hiba: nem szám!" << std::endl;
    }
    
    return 0;
}
```

**A program után írod az értéket cmd-nél, például: `program.exe 2`**

Példák a használatra:

- Szám megadása: `./program 42.5` → Kimenet: `Sikeresen számot adtál meg: 42.5`
- Szöveg megadása: `./program hello` → Kimenet: `Nem számot adtál meg, hanem szöveget: hello`
- Részben szám, részben szöveg: `./program 123abc` → Kimenet: `Nem számot adtál meg, hanem szöveget: 123abc`

## Bitenkénti Operátorok

| Operátor   | Jelentés és Funkció                                          |
| ---------- | ------------------------------------------------------------ |
| `~`        | **Nem** - az egyes bitek átállítása 1-ről 0-ra és 0-ról 1-re |
| `^`        | Bitwise XOR - `1 ^ 1 = 0` , `1 ^ 0 = 1` ,  `0 ^ 1 = 1`,  `0 ^ 0 = 0` |
| `!`        | Logikai NOT HA 1 akkor Nulla ha 0 akkor 1                    |
| `&`        | Bitwise ÉS(AND) - `1 & 1 = 1`, `1 & 0 = 0` , `0 & 1 = 0` , `0 & 0 = 0` |
| `|`        | Bitwise VAGY(OR) - `1 | 1 = 1` , `1 | 0 = 1` ,`0 | 1 = 1` , `0 | 0 = 0` |
| `<<`, `>>` | Bit Shift -- `<<`: Balra shift (szorzás 2-vel) , `>>`: Jobbra shift (osztás 2-vel). |
| **NOR **OR | `A NOR B = NOT (A OR B),` `1 NOR 1 = 0`, `1 NOR 0 = 0`, `0 NOR 1 = 0` ,`0 NOR 0 = 1` |

## Tipikus Kilépés (CLI)

```
std:: cout << "A kilpéshez nyomd meg az Entert...." << std::endl; 
std:: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   
std:: cin.get(); 
return 0;
```

## Bekérés

## 1. `cin >> int`

- Csak **egész számot** olvas be.
- Ha betűt írsz, a `failbit` beáll, a `cin` hibás állapotba kerül.

```cpp
int x;
std::cin >> x;  // csak számot fogad
```

- Hibás input esetén:

```cpp
if (std::cin.fail()) {
    std::cout << "Ez nem szám!\n";
    std::cin.clear(); // hibajelzés törlése
    std::cin.ignore(1000, '\n'); // a hibás karakterek eltávolítása a pufferből
}
```

------

## 2. `cin >> char`

- Egyetlen karaktert olvas be:

```cpp
char c;
std::cin >> c;
```

- Betű, szám, bármi → **egy karakter** lesz.

Hibakezelés 

```
char c;
std::cin >> c;
if (std::cin.fail()) {
    std::cout << "Hiba történt!\n";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}
```

De **betű/szám különbség ellenőrzéshez** magadnak kell tesztelni:

```
if (!isalpha(c)) {
    std::cout << "Ez nem betű!\n";
}
```

## `getline(cin, line)` + `char`-ra konvertálás

Ha `getline`-et használsz, és a stringből akarsz **egyetlen karaktert**:

```
std::string line;
std::getline(std::cin, line);

if (line.length() != 1) {
    std::cout << "Adj meg pontosan egy karaktert!\n";
} else {
    char c = line[0];  // ez a karakter
    std::cout << "Beolvasott karakter: " << c << "\n";
}
```

------

## 3. `getline(cin, string)`

- Egész sort olvas be szövegként:

```cpp
std::string s;
std::getline(std::cin, s);
```

- Ez **tetszőleges karakterláncot** enged: szám, betű, szóköz, speciális karakterek.
- Ha utána számmá akarod konvertálni, kell `stoi` / `stod`.

Hibás input esetén.

```
#include <iostream>
#include <string>

int main() {
    std::string line;
    int szam = 0;

    while (true) {
        std::cout << "Adj meg egy számot: ";
        std::getline(std::cin, line);  // bármilyen karakterláncot beolvas

        if (line == "exit") break; // kilépés

        try {
            szam = std::stoi(line);  // próbáljuk számra konvertálni
            std::cout << "Beolvasott szám: " << szam << "\n";
        } catch (const std::exception &e) {
            std::cout << "Hibás input! Kérlek csak számot adj meg.\n";
            // Nincs szükség cin.clear() vagy ignore()-ra, mert getline mindig tiszta
        }
    }
}
```

vagy ha double akkor 

```
std::stod(line1);  // double-ot olvasunk
```

Ha mindig **2 tizedesjegy pontosságot** akarsz, használhatod:

```
#include <iomanip>
std::cout << std::fixed << std::setprecision(2);
std::cout << "Összeg: " << gyujto << "\n";
```

------

### 🔹 Összegzés

| Típus / függvény           | Mit enged be?                        |
| -------------------------- | ------------------------------------ |
| `int x; cin >> x;`         | Csak egész szám                      |
| `double x; cin >> x;`      | Csak valós szám (tört)               |
| `char c; cin >> c;`        | Egyetlen karakter                    |
| `string s; getline(cin,s)` | Teljes sor tetszőleges karakterekkel |

------

Tipp:

Ha mindig számot akarsz, **`getline` + `stoi` / `stod`** biztonságosabb, mert a felhasználótól jövő hibás inputot könnyebb kezelni try/catch blokkban.

------

#### SztringKezelő függvények

| Név                              | Müvelet                                                      |
| -------------------------------- | ------------------------------------------------------------ |
| int strleng(string)              | Egy string karaktereinek a számát adja vissza                |
| char* strcat(cél, forrás)        | A forrás Stringet a véltömbe másolja                         |
| char*strncpy(cél, forrás, n)     | Egy stringet egy céltömbe másol az n karakterig a forrásStringből. |
| char* strncat(cél, forrás,n)     | Hozzáfüzi a célString végéhez a forrásStringet vagy az n karaktert amelyik hamarabb bekövetkezik. |
| char* strstr(string, minta)      | Egy minta első előfordulásának a helyét adja vissza ha a minta nem található null értéket add vissza. |
| int strcmp(forrás1, forrás2)     | Összehasonlít 2 stringet. Ha a forrás 1 a forrás 2 előtt szerepel a szótárban -1-et és ha utána , akkor 1 -et add vissza .0-ad vissza ha a két sztring pontosan megegyezik. |
| int strncmp(forrás1, forrás2, n) | Két String első n karakterét hasonlítja össze.               |
|                                  |                                                              |

 **C++** példák

------

###  `strlen` – string hossza

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char* s = "Hello Nova";
    cout << "A string hossza: " << strlen(s) << endl;
    return 0;
}
```

------

###  `strcat` – összefűzés

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s1[50] = "Hello ";
    const char* s2 = "Nova";
    strcat(s1, s2);
    cout << s1 << endl; // Hello Nova
    return 0;
}
```

------

### `strncpy` – másolás n karakterig

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s1[20];
    const char* s2 = "HelloNova";
    strncpy(s1, s2, 5);
    s1[5] = '\0'; // mindig zárjuk le '\0'-val
    cout << s1 << endl; // Hello
    return 0;
}
```

------

### `strncat` – hozzáfűzés n karakterig

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s1[20] = "Hello ";
    const char* s2 = "NovaLand";
    strncat(s1, s2, 4); // csak az első 4 karaktert fűzi hozzá
    cout << s1 << endl; // Hello Nova
    return 0;
}
```

------

###  `strstr` – minta keresés

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char* s = "Hello Nova";
    const char* minta = "Nova";
    char* talalat = strstr((char*)s, minta);
    if (talalat)
        cout << "Találtuk a mintát: " << talalat << endl;
    else
        cout << "Nincs találat" << endl;
    return 0;
}
```

------

###  `strcmp` – összehasonlítás

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char* s1 = "Apple";
    const char* s2 = "Banana";

    int eredmeny = strcmp(s1, s2);
    if (eredmeny < 0) cout << "s1 előrébb van" << endl;
    else if (eredmeny > 0) cout << "s1 később van" << endl;
    else cout << "egyeznek" << endl;

    return 0;
}
```

------

### `strncmp` – első n karakter összehasonlítása

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char* s1 = "HelloWorld";
    const char* s2 = "HelloNova";

    int eredmeny = strncmp(s1, s2, 5); // csak az első 5 karaktert hasonlítja
    if (eredmeny == 0) cout << "Az első 5 karakter egyezik" << endl;
    else cout << "Az első 5 karakter nem egyezik" << endl;

    return 0;
}
```

------

# TÖBB BÁJTOS SZTRINGKEZELŐ FÜGGVÉNYEK

| Név                                    | Művelet                                                      |
| -------------------------------------- | ------------------------------------------------------------ |
| int wcslen(string)                     | Egy string több bájtós karaktereinek a számát adja vissza, a záró null nélkül. |
| wchar_t* wcscpy(cél, forrás)           | A több bájtós forrásStringet a céltömbe másolja.             |
| wchar_t* wcscat(cél, forrás)           | A több bájtos forrásStringet hozzáfűzi a több bájtos célSztring végéhez. |
| wchar_t* wcsncpy(cél, forrás, n)       | Egy több bájtos sztringet n karakterig egy céltömbe másol a forrásSztringből. |
| wchar_t* wcsncat(cél, forrás, n)       | Hozzáfűzi a célSztring végéhez a forrásStringet vagy az n karakter amelyik hamarabb bekővetkezik. |
| wchar_t* wcsstr(string, minta)         | Megkeresi egy minta első előfordulásának a helyét a sztringben.Ha a minta nem található Null értéket add vissza. |
| wchar_t* wcscmp(forrás1, forrás2)      | Összehasonlít két több-bájtos sztringet.Ha a forrás1 a forrás2 előtt szerepel a szótárban, -1-et és ha utána akkor 1-et ad vissza.0-ad vissza ha a két sztring pontosan megegyezik. |
| wchar_t* wcsncmp(forrás1 , forrás2, n) | Két több bájtos Sztring első n több-bájtos karakterét hasonlítja össze. |

Oké Ati! 😎 Akkor csinálok rövid, működő **C++ példákat** mind a több-bájtos (wide) string függvényekre, **`wchar_t`** típus használatával. Ezek a függvények főleg **Unicode karakterekhez** jók.

------

##  `wcslen` – több-bájtos string hossza**

```cpp
#include <iostream>
#include <cwchar> // wide char függvények
using namespace std;

int main() {
    wchar_t sz[] = L"Hello 🌍"; // L prefix wide string
    wcout << L"A string hossza: " << wcslen(sz) << endl; // záró null nélkül
    return 0;
}
```

------

##  `wcscpy` – másolás**

```cpp
#include <iostream>
#include <cwchar>
using namespace std;

int main() {
    wchar_t cél[50];
    wchar_t forrás[] = L"Hello 🌍";
    wcscpy(cél, forrás);
    wcout << L"A másolt string: " << cél << endl;
    return 0;
}
```

------

##  `wcsncpy` – másolás n karakterig**

```cpp
#include <iostream>
#include <cwchar>
using namespace std;

int main() {
    wchar_t cél[50];
    wchar_t forrás[] = L"Hello 🌍";
    wcsncpy(cél, forrás, 5); // csak az első 5 wide karakter
    cél[5] = L'\0'; // mindig zárjuk le
    wcout << L"Részstring: " << cél << endl;
    return 0;
}
```

------

##  `wcsat` – összefűzés**

```cpp
#include <iostream>
#include <cwchar>
using namespace std;

int main() {
    wchar_t s1[50] = L"Hello ";
    wchar_t s2[] = L"🌍!";
    wcscat(s1, s2);
    wcout << L"Összefűzve: " << s1 << endl;
    return 0;
}
```

------

##  `wcsncat` – összefűzés n karakterig**

```cpp
#include <iostream>
#include <cwchar>
using namespace std;

int main() {
    wchar_t s1[50] = L"Hello ";
    wchar_t s2[] = L"🌍!!!";
    wcsncat(s1, s2, 2); // csak az első 2 wide karaktert fűzi hozzá
    wcout << L"Részösszefűzés: " << s1 << endl;
    return 0;
}
```

------

## ** `wcsstr` – minta keresés**

```cpp
#include <iostream>
#include <cwchar>
using namespace std;

int main() {
    wchar_t sz[] = L"Hello 🌍, welcome!";
    wchar_t minta[] = L"🌍";
    wchar_t* talalat = wcsstr(sz, minta);
    if (talalat)
        wcout << L"Talált minta: " << talalat << endl;
    else
        wcout << L"Nincs találat" << endl;
    return 0;
}
```

------

##  `wcscmp` – összehasonlítás**

```cpp
#include <iostream>
#include <cwchar>
using namespace std;

int main() {
    wchar_t s1[] = L"Apple";
    wchar_t s2[] = L"Banana";

    int eredmeny = wcscmp(s1, s2);
    if (eredmeny < 0) wcout << L"s1 előrébb van" << endl;
    else if (eredmeny > 0) wcout << L"s1 később van" << endl;
    else wcout << L"egyeznek" << endl;

    return 0;
}
```

------

##  `wcsncmp` – első n karakter összehasonlítása**

```cpp
#include <iostream>
#include <cwchar>
using namespace std;

int main() {
    wchar_t s1[] = L"HelloWorld";
    wchar_t s2[] = L"HelloNova";

    int eredmeny = wcsncmp(s1, s2, 5); // csak az első 5 wide karaktert hasonlítja
    if (eredmeny == 0) wcout << L"Az első 5 karakter egyezik" << endl;
    else wcout << L"Az első 5 karakter nem egyezik" << endl;

    return 0;
}
```

------

## **Sima (narrow) stringek**

- **Típus:** `char`
- **Kódolás:** 1 bájt karakterenként (ASCII kompatibilis, vagy kódoldás: UTF-8)
- **Méret:** minden karakter pontosan 1 byte (de UTF-8 esetén 1–4 byte is lehet, de `char` tömb mindig 1 byte-onként számol)
- **Függvények:** `strlen`, `strcpy`, `strcat`, `strncmp` stb.
- **Példa:**

```cpp
char s[] = "Hello";
std::cout << "Hossz: " << strlen(s) << std::endl;
```

- **Előny:** egyszerű, gyors, sok régi kód használja.
- **Hátrány:** Unicode karakterekhez (pl. 🌍, ékezetes betűk) nem mindig elég, mert 1 char = 1 byte, de sok Unicode karakter 2–4 byte.

------

## ** Több-bájtos (wide) stringek**

- **Típus:** `wchar_t`
- **Kódolás:** platformtól függően 2 vagy 4 bájt karakterenként (Windows: 2 byte, Linux/macOS: 4 byte)
- **Méret:** minden karakter **egy wchar_t**, így könnyen kezel Unicode karaktereket.
- **Függvények:** `wcslen`, `wcscpy`, `wcsncpy`, `wcscat`, `wcsncmp` stb.
- **Példa:**

```cpp
wchar_t s[] = L"Hello 🌍";
std::wcout << L"Hossz: " << wcslen(s) << std::endl;
```

- **Előny:** Unicode kompatibilis, nem kell aggódni a több-bájtos karakterek miatt.
- **Hátrány:** nagyobb memóriaigény, több függvény, kevesebb régi kód támogatja.

------

### ** Összefoglaló táblázat**

| Tulajdonság       | Sima (`char`)       | Több-bájtos (`wchar_t`)        |
| ----------------- | ------------------- | ------------------------------ |
| Karakter mérete   | 1 byte              | 2–4 byte (platformtól függ)    |
| Unicode támogatás | Korlátozott / UTF-8 | Teljes (Unicode)               |
| Függvények        | strlen, strcpy…     | wcslen, wcscpy…                |
| Példa karakterek  | 'A', 'a', '0'       | 'A', 'é', '🌍'                  |
| Memóriaigény      | Kis                 | Nagyobb                        |
| Használat         | Régi kód, ASCII     | Unicode, nemzetközi karakterek |

------

## Cím és mutató operátorok

| Operátor          | Jelentés                                        |
| ----------------- | ----------------------------------------------- |
| & (egyoperandusú) | kifejezésnél -a következő címe                  |
| & (egyoperandusú) | Deklarációban - a következő hivatkozása         |
| * (egyoperandusú) | kifejezésnél - a következő által mutatott dolog |
| * (egyoperandusú) | Deklarációban - a következő mutatója            |

