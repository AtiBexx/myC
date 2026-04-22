# C++ Változótípusok Teljes Útmutató

## Tartalomjegyzék
1. [Alapvető típusok](#alapvető-típusok)
2. [Integer típusok](#integer-típusok)
3. [Lebegőpontos típusok](#lebegőpontos-típusok)
4. [Karakter típusok](#karakter-típusok)
5. [Logikai típus](#logikai-típus)
6. [Speciális karakterek és escape sorozatok](#speciális-karakterek-és-escape-sorozatok)
7. [Előjel nélküli típusok](#előjel-nélküli-típusok)
8. [Konstans típusok](#konstans-típusok)
9. [Automatikus típuskifejezés (auto)](#automatikus-típuskifejezés-auto)
10. [Névadási konvenciók](#névadási-konvenciók)
11. [Példák és kódrészletek](#példák-és-kódrészletek)

## Alapvető típusok

| Típus | Méret | Értéktartomány | Leírás |
|-------|-------|----------------|--------|
| `bool` | 1 byte | `true` vagy `false` | Logikai érték |
| `char` | 1 byte | -128 to 127 vagy 0 to 255 | Karakter vagy egész szám |
| `int` | 2 vagy 4 byte | -32,768 to 32,767 vagy -2,147,483,648 to 2,147,483,647 | Egész szám |
| `float` | 4 byte | ±3.4e +/- 38 (~7 számjegy) | Lebegőpontos szám |
| `double` | 8 byte | ±1.7e +/- 308 (~15 számjegy) | Kétszeres pontosságú lebegőpontos szám |
| `wchar_t` | 2 vagy 4 byte | L wide karakter |
| `void` | - | - | Nincs érték |
| `enum` | - | - | Felsorolási típus |

## Integer típusok

### Előjeles egészek
| Típus | Méret | Értéktartomány | Rövidítés |
|-------|-------|----------------|-----------|
| `short` vagy `short int` | 2 byte | -32,768 to 32,767 | `n` (pl. `nValue`) |
| `int` | 4 byte | -2,147,483,648 to 2,147,483,647 | `n` (pl. `nCount`) |
| `long` vagy `long int` | 4 byte | -2,147,483,648 to 2,147,483,647 | `l` (pl. `lSize`) |
| `long long` vagy `long long int` | 8 byte | -(2^63) to (2^63)-1 | `ll` (pl. `llBigNumber`) |

### Előjel nélküli egészek
| Típus | Méret | Értéktartomány | Rövidítés |
|-------|-------|----------------|-----------|
| `unsigned short` vagy `unsigned short int` | 2 byte | 0 to 65,535 | `us` (pl. `usPort`) |
| `unsigned int` | 4 byte | 0 to 4,294,967,295 | `u` vagy `ui` (pl. `uIndex`) |
| `unsigned long` vagy `unsigned long int` | 4 byte | 0 to 4,294,967,295 | `ul` (pl. `ulAddress`) |
| `unsigned long long` vagy `unsigned long long int` | 8 byte | 0 to 18,446,744,073,709,551,615 | `ull` (pl. `ullLargeValue`) |

## Lebegőpontos típusok

| Típus | Méret | Értéktartomány | Pontosság | Suffix |
|-------|-------|----------------|-----------|---------|
| `float` | 4 byte | ±3.4e +/- 38 | ~7 számjegy | `f` (pl. `3.14f`) |
| `double` | 8 byte | ±1.7e +/- 308 | ~15 számjegy | `d` (pl. `3.14d`) vagy alapértelmezett |
| `long double` | 8 vagy 10 vagy 16 byte | - | - | `L` (pl. `3.14L`) |

## Karakter típusok

| Típus | Méret | Leírás | Példa |
|-------|-------|--------|-------|
| `char` | 1 byte | Szabványos karakter | `'A'`, `'\n'` |
| `wchar_t` | 2 vagy 4 byte | Széles karakter | `L'A'`, `L"Hello"` |
| `char16_t` | 2 byte | UTF-16 karakter | `u'A'`, `u"Hello"` |
| `char32_t` | 4 byte | UTF-32 karakter | `U'A'`, `U"Hello"` |
| `std::string` | - | Karakterlánc osztály | `"Hello World"` |
| `std::wstring` | - | Széles karakterlánc | `L"Hello World"` |

## Logikai típus

| Típus | Méret | Értéktartomány | Rövidítés |
|-------|-------|----------------|-----------|
| `bool` | 1 byte | `true` vagy `false` | `b` (pl. `bFlag`) |

## Speciális karakterek és escape sorozatok

| Escape sorozat | Leírás | ASCII érték | Hex érték |
|----------------|--------|-------------|-----------|
| `\n` | Új sor | 10 | 0x0A |
| `\t` | Tabulátor | 9 | 0x09 |
| `\r` | Carriage return | 13 | 0x0D |
| `\b` | Backspace | 8 | 0x08 |
| `\f` | Form feed | 12 | 0x0C |
| `\a` | Alert (csengő) | 7 | 0x07 |
| `\\` | Fordított perjel | 92 | 0x5C |
| `\'` | Aposztróf | 39 | 0x27 |
| `\"` | Idézőjel | 34 | 0x22 |
| `\?` | Kérdőjel | 63 | 0x3F |
| `\0` | Null karakter | 0 | 0x00 |
| `\040` | Oktális érték (szóköz) | 32 | 0x20 |
| `\x20` | Hexadecimális érték (szóköz) | 32 | 0x20 |

## Előjel nélküli típusok

Minden egész típus rendelkezhet `unsigned` kulcsszóval, ami csak pozitív értékeket engedélyez:

```cpp
unsigned char uc = 255;        // 0 to 255
unsigned short us = 65535;     // 0 to 65,535
unsigned int ui = 4294967295;  // 0 to 4,294,967,295
unsigned long ul = 4294967295; // 0 to 4,294,967,295
```

## Konstans típusok

| Módosító | Leírás | Példa |
|----------|--------|-------|
| `const` | Változatlan értékű változó | `const int MAX = 100;` |
| `constexpr` | Fordítási idejű konstans | `constexpr double PI = 3.14159;` |
| `volatile` | Megakadályozza az optimalizálást | `volatile int* port = 0x1234;` |
| `mutable` | Tagváltozó módosíthatósága | `mutable int cache;` |

## Automatikus típuskifejezés (auto)

A `auto` kulcsszóval a fordító automatikusan meghatározza a változó típusát:

```cpp
auto i = 42;          // int
auto f = 3.14f;       // float
auto d = 3.14;        // double
auto c = 'A';         // char
auto b = true;        // bool
auto s = "Hello";     // const char*
auto str = std::string("World"); // std::string
```

## Névadási konvenciók

### Magyarországi gyakorlat (Hungarian notation)
| Prefix | Típus | Példa |
|--------|-------|-------|
| `n` | int | `nCount` |
| `l` | long | `lSize` |
| `f` | float | `fValue` |
| `d` | double | `dResult` |
| `b` | bool | `bFlag` |
| `c` | char | `cLetter` |
| `s` | string | `sName` |
| `p` | pointer | `pBuffer` |
| `arr` | array | `arrNumbers` |
| `fn` | function | `fnCallback` |

### Modern C++ gyakorlat
| Stílus | Példa |
|--------|-------|
| camelCase | `studentAge`, `firstName` |
| PascalCase | `StudentRecord`, `MainWindow` |
| snake_case | `student_age`, `first_name` |
| SCREAMING_SNAKE_CASE | `MAX_SIZE`, `PI_VALUE` |

## Példák és kódrészletek

### Egyszerű változódeklarációk
```cpp
// Integer típusok
int nAge = 25;
short sSmall = 100;
long lBig = 100000L;
long long llHuge = 123456789012345LL;

// Unsigned típusok
unsigned int uCount = 100U;
unsigned long ulAddress = 0xDEADBEEFUL;
unsigned long long ullLarge = 18446744073709551615ULL;

// Lebegőpontos típusok
float fPi = 3.14159f;
double dPi = 3.141592653589793;
long double ldPi = 3.141592653589793238L;

// Karakter típusok
char cGrade = 'A';
wchar_t wcChar = L'Ω';
char16_t c16Char = u'€';
char32_t c32Char = U'𝄞';

// Logikai típus
bool bValid = true;

// String típusok
std::string sText = "Hello World";
std::wstring wsWide = L"Wide String";
```

### Konstans példák
```cpp
const int MAX_SIZE = 100;
constexpr double PI = 3.14159265358979323846;
const char* pszMessage = "Constant C-string";
```

### Auto példák
```cpp
auto x = 42;                    // int
auto y = 3.14;                  // double
auto z = 42LL;                  // long long
auto ch = 'x';                  // char
auto flag = true;               // bool
auto str = std::string("text"); // std::string
auto ptr = &x;                  // int*
```

### Speciális karakterek használata
```cpp
std::cout << "Sor1\nSor2\tTabulátor\n";  // Új sor és tabulátor
std::cout << "Idézet: \"Hello\"\n";      // Idézőjel
std::cout << "Backslash: \\\n";          // Fordított perjel
std::cout << "Oktális: \040\n";          // Szóköz oktálisan
std::cout << "Hexa: \x20\n";             // Szóköz hexában
```

### Széles karakterek és Unicode
```cpp
wchar_t wide_char = L'α';
char16_t utf16_char = u'β';
char32_t utf32_char = U'γ';

std::wstring wide_string = L"Széles karakterlánc";
std::u16string utf16_string = u"UTF-16 karakterlánc";
std::u32string utf32_string = U"UTF-32 karakterlánc";
```