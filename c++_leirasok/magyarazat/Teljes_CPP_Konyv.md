# Teljes C++ Könyv
## Tanuld meg a C++ programozási nyelvet nulláról haladó szintig!

---

**Szerző:** AI Asszisztens  
**Verzió:** 1.0  
**Nyelv:** Magyar

---

# Tartalomjegyzék

1. [Bevezetés a C++-ba](#1-fejezet-bevezetés-a-c-ba)
2. [Alapvető adatszerkezetek](#2-fejezet-alapvető-adatszerkezetek)
3. [Vezérlési szerkezetek](#3-fejezet-vezérlési-szerkezetek)
4. [Függvények](#4-fejezet-függvények)
5. [Tömbök és stringek](#5-fejezet-tömbök-és-stringek)
6. [Mutatók és referenciák](#6-fejezet-mutatók-és-referenciák)
7. [Struktúrák és osztályok](#7-fejezet-struktúrák-és-osztályok)
8. [Objektumorientált programozás](#8-fejezet-objektumorientált-programozás)
9. [Sablonok (Templates)](#9-fejezet-sablonok-templates)
10. [STL - Standard Template Library](#10-fejezet-stl-standard-template-library)
11. [Kivételkezelés](#11-fejezet-kivételkezelés)
12. [Fájlkezelés](#12-fejezet-fájlkezelés)
13. [Haladó témák](#13-fejezet-haladó-témák)
14. [Header fájlok és többfájlos projektek](#14-fejezet-header-fájlok-és-többfájlos-projektek)
15. [Windows GDI és natív ablakprogramozás](#15-fejezet-windows-gdi-és-natív-ablakprogramozás)
16. [Linux ablakprogramozás (X11 és GTK)](#16-fejezet-linux-ablakprogramozás-x11-és-gtk)
17. [Matematikai képletek C++-ban](#17-fejezet-matematikai-képletek-c-ban)
18. [DSP - Digitális Jelfeldolgozás](#18-fejezet-dsp-digitális-jelfeldolgozás)
19. [CLI programozás és multi-language támogatás](#19-fejezet-cli-programozás-és-multi-language-támogatás)
20. [Hálózati programozás C++-ban](#20-fejezet-hálózati-programozás-c-ban)
21. [Kódelemzés és reverse engineering](#21-fejezet-kódelemzés-és-reverse-engineering)
22. [Rekurzív gondolkozásmód](#22-fejezet-rekurzív-gondolkozásmód)
23. [Hibakezelés CLI és GUI alkalmazásokban](#23-fejezet-hibakezelés-cli-és-gui-alkalmazásokban)
24. [String kezelés és több bájtos karakterek](#24-fejezet-string-kezelés-és-több-bájtos-karakterek)
25. [Fájlkezelés és másoló függvények](#25-fejezet-fájlkezelés-és-másoló-függvények)
26. [Konstruktorok és speciális metódusok](#26-fejezet-konstruktorok-és-speciális-metódusok)
27. [AI fejlesztés C++-ban](#27-fejezet-ai-fejlesztés-c-ban)
28. [Fontos kiegészítő témák](#28-fejezet-fontos-kiegészítő-témák)

---

# 1. fejezet: Bevezetés a C++-ba

## 1.1 Mi az a C++?

A **C++** egy általános célú, objektumorientált programozási nyelv, amelyet Bjarne Stroustrup fejlesztett ki 1979-ben a Bell Labs-nál. A nyelv a C nyelvből származik, és kiterjeszti azt objektumorientált funkciókkal.

### Miért tanulj C++-t?

- **Gyors és hatékony**: Közvetlen hozzáférés a hardverhez
- **Univerzális**: Operációs rendszerek, játékok, beágyazott rendszerek
- **Népszerű**: Egyik leggyakrabban használt nyelv világszerte
- **Alapozó**: Megérted a számítógép működését

## 1.2 Az első program: Hello World

Minden programozó első programja a "Hello World". Íme C++-ban:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

### A program részeinek magyarázata:

| Rész | Jelentés |
|------|----------|
| `#include <iostream>` | Beilleszti a be-/kimeneti könyvtárat |
| `int main()` | A program belépési pontja |
| `std::cout` | Kimeneti stream (konzolra írás) |
| `<<` | Kiírási operátor |
| `std::endl` | Új sor karakter |
| `return 0` | A program sikeres lefutását jelzi |

## 1.3 Fordítás és futtatás

### Windows (MinGW vagy MSVC):

```bash
# Fordítás
g++ -o program.exe program.cpp

# Futtatás
program.exe
```

### Linux/Mac:

```bash
# Fordítás
g++ -o program program.cpp

# Futtatás
./program
```

## 1.4 A C++ program szerkezete

Minden C++ program a következő részekből áll:

```cpp
// 1. Preprocesszor direktívák
#include <iostream>
#include <string>

// 2. Névtér használata (opcionális)
using namespace std;

// 3. Globális változók (opcionális)
int globalisValtozo = 0;

// 4. Függvények és osztályok deklarálása
void fuggvenyNeve();

// 5. A main függvény - a program belépési pontja
int main() {
    // Program kód
    return 0;
}

// 6. Függvények definíciója
void fuggvenyNeve() {
    // Kód
}
```

## 1.5 Megjegyzések (Commentek)

A megjegyzések nem kerülnek lefordításra, csak a kód olvashatóságát segítik:

```cpp
// Ez egy egy soros megjegyzés

/*
    Ez egy
    több soros
    megjegyzés
*/

/**
 * Dokumentációs megjegyzés (Doxygen stílus)
 * @param x A paraméter leírása
 * @return A visszatérési érték leírása
 */
```

---

# 2. fejezet: Alapvető adatszerkezetek

## 2.1 Változók és adattípusok

### Alapvető adattípusok:

```cpp
// Egész számok
int szam = 42;              // Általános egész (általában 32 bit)
short rovid = 100;          // Rövid egész (16 bit)
long hosszu = 1000000L;     // Hosszú egész (32 vagy 64 bit)
long long nagyonHosszu = 9223372036854775807LL;  // 64 bit

// Lebegőpontos számok
float tizedes = 3.14f;      // Egyszerű pontosság (32 bit)
double duplapontossagu = 3.14159265359;  // Dupla pontosság (64 bit)

// Karakterek
char betu = 'A';            // Egy karakter (8 bit)
wchar_t unicode = L'Á';     // Széles karakter

// Logikai értékek
bool igaz = true;
bool hamis = false;

// Automatikus típuskikövetkeztetés
auto valtozo = 42;          // int lesz
auto szoveg = "Hello";      // const char* lesz
```

### Típusméretek lekérdezése:

```cpp
#include <iostream>

int main() {
    std::cout << "int méret: " << sizeof(int) << " bájt" << std::endl;
    std::cout << "double méret: " << sizeof(double) << " bájt" << std::endl;
    std::cout << "char méret: " << sizeof(char) << " bájt" << std::endl;
    return 0;
}
```

## 2.2 Változók deklarálása és inicializálása

```cpp
// Deklarálás (változó létrehozása)
int szam;

// Inicializálás (értékadás)
szam = 42;

// Deklarálás és inicializálás együtt
int szam2 = 42;

// Modern C++ inicializálás (C++11-től)
int szam3{42};
auto szam4 = 100;

// Konstans változók
const int PI = 3.14159;
constexpr int MAX_MERET = 100;  // Fordítási időben kiértékelt konstans
```

## 2.3 Operátorok

### Aritmetikai operátorok:

```cpp
int a = 10, b = 3;

int osszeg = a + b;      // 13
int kulonbseg = a - b;   // 7
int szorzat = a * b;     // 30
int hanyados = a / b;    // 3 (egész osztás!)
int maradek = a % b;     // 1 (maradékos osztás)

// Lebegőpontos osztás
double pontos = 10.0 / 3.0;  // 3.333...

// Növelés/csökkentés
int x = 5;
x++;      // x = 6 (poszt-inkrement)
++x;      // x = 7 (pre-inkrement)
x--;      // x = 6 (poszt-dekrement)
--x;      // x = 5 (pre-dekrement)

// Különbség:
int y = 5;
int z = y++;  // z = 5, y = 6 (először használja, majd növeli)
int w = ++y;  // w = 7, y = 7 (először növeli, majd használja)
```

### Összetett értékadó operátorok:

```cpp
int a = 10;

a += 5;   // a = a + 5  → 15
a -= 3;   // a = a - 3  → 12
a *= 2;   // a = a * 2  → 24
a /= 4;   // a = a / 4  → 6
a %= 4;   // a = a % 4  → 2
```

### Összehasonlító operátorok:

```cpp
int a = 10, b = 5;

bool egyenlo = (a == b);        // false
bool nemEgyenlo = (a != b);     // true
bool nagyobb = (a > b);        // true
bool kisebb = (a < b);        // false
bool nagyobbEgyenlo = (a >= b); // true
bool kisebbEgyenlo = (a <= b); // false
```

### Logikai operátorok:

```cpp
bool a = true, b = false;

bool es = (a && b);    // false (ÉS művelet)
bool vagy = (a || b);  // true (VAGY művelet)
bool nem = (!a);       // false (NEM művelet)

// Gyakorlati példa
int kor = 25;
bool vanJogositvany = true;

if (kor >= 18 && vanJogositvany) {
    std::cout << "Vezethet autót!" << std::endl;
}
```

### Bitműveleti operátorok:

```cpp
unsigned char a = 0b01010101;  // 85
unsigned char b = 0b00111100;  // 60

unsigned char es = a & b;      // 0b00010100 (20) - BITWISE AND
unsigned char vagy = a | b;    // 0b01111101 (125) - BITWISE OR
unsigned char kizaroVagy = a ^ b; // 0b01101001 (105) - XOR
unsigned char nem = ~a;        // 0b10101010 (170) - NOT
unsigned char balra = a << 1;  // 0b10101010 (170) - balra shift
unsigned char jobbra = a >> 1; // 0b00101010 (42) - jobbra shift
```

## 2.4 Típuskonverziók

```cpp
// Implicit konverzió (automatikus)
int egesz = 42;
double tizedes = egesz;  // 42.0 (automatikusan átalakul)

// Explicit konverzió (type casting)
double d = 3.99;
int i = (int)d;          // C-stílusú cast → 3
int j = static_cast<int>(d);  // C++ stílusú cast → 3

// Konstans cast
const int* ptr = new int(10);
int* nemKonstans = const_cast<int*>(ptr);

// Reinterpret cast (veszélyes!)
int szam = 42;
char* charPtr = reinterpret_cast<char*>(&szam);
```

---

# 3. fejezet: Vezérlési szerkezetek

## 3.1 Feltételes utasítások

### if-else utasítás:

```cpp
#include <iostream>
using namespace std;

int main() {
    int kor;
    cout << "Hány éves vagy? ";
    cin >> kor;
    
    if (kor < 0) {
        cout << "Hibás életkor!" << endl;
    } else if (kor < 18) {
        cout << "Kiskorú vagy." << endl;
    } else if (kor < 65) {
        cout << "Felnőtt vagy." << endl;
    } else {
        cout << "Nyugdíjas vagy." << endl;
    }
    
    return 0;
}
```

### Ternáris operátor:

```cpp
int szam = 10;

// Hosszú forma
string eredmeny;
if (szam % 2 == 0) {
    eredmeny = "páros";
} else {
    eredmeny = "páratlan";
}

// Rövid forma (ternáris operátor)
string eredmeny2 = (szam % 2 == 0) ? "páros" : "páratlan";
```

### switch-case utasítás:

```cpp
#include <iostream>
using namespace std;

int main() {
    int nap;
    cout << "Adj meg egy napot (1-7): ";
    cin >> nap;
    
    switch (nap) {
        case 1:
            cout << "Hétfő" << endl;
            break;
        case 2:
            cout << "Kedd" << endl;
            break;
        case 3:
            cout << "Szerda" << endl;
            break;
        case 4:
            cout << "Csütörtök" << endl;
            break;
        case 5:
            cout << "Péntek" << endl;
            break;
        case 6:
            cout << "Szombat" << endl;
            break;
        case 7:
            cout << "Vasárnap" << endl;
            break;
        default:
            cout << "Hibás nap!" << endl;
    }
    
    return 0;
}
```

### Modern switch (C++17-től):

```cpp
int erv = 2;

switch (erv) {
    [[fallthrough]]  // Szándékos "átesés" a következő case-be
    case 1:
        cout << "Egy vagy kettő" << endl;
        break;
    case 2:
        cout << "Kettő" << endl;
        break;
}
```

## 3.2 Ciklusok

### for ciklus:

```cpp
// Klasszikus for ciklus
for (int i = 0; i < 5; i++) {
    cout << "i = " << i << endl;
}
// Kimenet: 0, 1, 2, 3, 4

// Több változó
for (int i = 0, j = 10; i < j; i++, j--) {
    cout << "i = " << i << ", j = " << j << endl;
}

// Range-based for (C++11-től) - tömbökön/vektorokon
int szamok[] = {1, 2, 3, 4, 5};
for (int szam : szamok) {
    cout << szam << " ";
}
// Kimenet: 1 2 3 4 5

// Referenciával (módosítható)
for (int& szam : szamok) {
    szam *= 2;  // Eredeti tömb elemeit módosítja
}
```

### while ciklus:

```cpp
// while ciklus
int szamlalo = 0;
while (szamlalo < 5) {
    cout << "Szamlalo: " << szamlalo << endl;
    szamlalo++;
}

// Végtelen ciklus (break-kel kilépve)
while (true) {
    cout << "Adj meg egy számot (0 a kilépéshez): ";
    int szam;
    cin >> szam;
    if (szam == 0) break;
    cout << "A szám négyzete: " << szam * szam << endl;
}
```

### do-while ciklus:

```cpp
// do-while: legalább egyszer végrehajtódik
int valasz;
do {
    cout << "1. Menüpont" << endl;
    cout << "2. Menüpont" << endl;
    cout << "0. Kilépés" << endl;
    cout << "Válassz: ";
    cin >> valasz;
} while (valasz != 0);
```

### break és continue:

```cpp
// break - kilép a ciklusból
for (int i = 0; i < 100; i++) {
    if (i == 10) {
        break;  // Kilép a ciklusból i=10-nél
    }
    cout << i << " ";
}
// Kimenet: 0 1 2 3 4 5 6 7 8 9

// continue - kihagyja az aktuális iterációt
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
        continue;  // Kihagyja a páros számokat
    }
    cout << i << " ";
}
// Kimenet: 1 3 5 7 9
```

### Beágyazott ciklusok:

```cpp
// Szorzótábla
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        cout << i * j << "\t";
    }
    cout << endl;
}

// Háromszög rajzolása
int magassag = 5;
for (int i = 1; i <= magassag; i++) {
    for (int j = 0; j < i; j++) {
        cout << "*";
    }
    cout << endl;
}
/*
Kimenet:
*
**
***
****
*****
*/
```

---

# 4. fejezet: Függvények

## 4.1 Függvények alapjai

### Függvény definíciója:

```cpp
// Függvény deklaráció (prototípus)
int osszead(int a, int b);

// Függvény definíció
int osszead(int a, int b) {
    return a + b;
}

// Függvény hívása
int main() {
    int eredmeny = osszead(5, 3);  // 8
    cout << "Eredmény: " << eredmeny << endl;
    return 0;
}
```

### Függvény részei:

```cpp
// visszatérési_típus függvény_név(paraméterek) { törzs }
//       ↑              ↑            ↑         ↑
//   visszatérési   függvény     paraméterek   kód
//      típus         neve
```

## 4.2 Paraméterek és visszatérési értékek

### Különböző paraméter típusok:

```cpp
// Nincs paraméter, nincs visszatérési érték
void udvozol() {
    cout << "Szia!" << endl;
}

// Egy paraméter, nincs visszatérési érték
void udvozolNevvel(string nev) {
    cout << "Szia " << nev << "!" << endl;
}

// Több paraméter, van visszatérési érték
int szoroz(int a, int b) {
    return a * b;
}

// Ugyanolyan típusú paraméterek
int osszeg(int a, int b, int c, int d) {
    return a + b + c + d;
}
```

### Alapértelmezett paraméterek:

```cpp
void koszon(string nev = "Vendég", int alkalom = 1) {
    for (int i = 0; i < alkalom; i++) {
        cout << "Üdvözöllek, " << nev << "!" << endl;
    }
}

// Hívások:
koszon();                    // "Üdvözöllek, Vendég!"
koszon("János");            // "Üdvözöllek, János!"
koszon("Éva", 3);           // 3-szor írja ki
```

### Referencia szerinti paraméterátadás:

```cpp
// Érték szerinti átadás (nem módosítja az eredetit)
void megnovel(int szam) {
    szam++;
}

// Referencia szerinti átadás (módosítja az eredetit)
void megnovelReferenciaval(int& szam) {
    szam++;
}

int main() {
    int a = 5;
    megnovel(a);
    cout << a;  // 5 (nem változott)
    
    int b = 5;
    megnovelReferenciaval(b);
    cout << b;  // 6 (megváltozott)
    
    return 0;
}
```

### Konstans referencia (hatékony és biztonságos):

```cpp
// Nagy objektumek esetén hatékony
void kiir(const string& szoveg) {
    // Nem módosítható, de nem másolódik
    cout << szoveg << endl;
}
```

## 4.3 Függvény-túlterhelés (Overloading)

```cpp
// Ugyanaz a függvénynév, különböző paraméterekkel
int osszead(int a, int b) {
    return a + b;
}

double osszead(double a, double b) {
    return a + b;
}

int osszead(int a, int b, int c) {
    return a + b + c;
}

string osszead(string a, string b) {
    return a + b;
}

// A fordító a paraméterek alapján választja ki a megfelelőt
osszead(2, 3);           // int verzió
osszead(2.5, 3.7);       // double verzió
osszead(1, 2, 3);        // 3 paraméteres verzió
osszead("Hello", "World"); // string verzió
```

## 4.4 Rekurzív függvények

```cpp
// Faktoriális számítása
int faktorialis(int n) {
    if (n <= 1) return 1;
    return n * faktorialis(n - 1);
}

// Fibonacci sorozat
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Hatványozás
int hatvany(int alap, int kitevo) {
    if (kitevo == 0) return 1;
    return alap * hatvany(alap, kitevo - 1);
}
```

## 4.5 Inline függvények

```cpp
// A fordító beilleszti a kódot (gyorsabb, de nagyobb)
inline int negyzet(int x) {
    return x * x;
}

// Rövid függvényeknél érdemes használni
inline int max(int a, int b) {
    return (a > b) ? a : b;
}
```

## 4.6 Függvény pointerek

```cpp
// Függvény pointer deklaráció
int osszead(int a, int b) { return a + b; }
int kivon(int a, int b) { return a - b; }

int main() {
    // Függvény pointer
    int (*muvelet)(int, int);
    
    muvelet = osszead;
    cout << muvelet(5, 3);  // 8
    
    muvelet = kivon;
    cout << muvelet(5, 3);  // 2
    
    return 0;
}
```

---

# 5. fejezet: Tömbök és stringek

## 5.1 Egydimenziós tömbök

```cpp
// Tömb deklarálása
int szamok[5];  // 5 elemű egész tömb

// Inicializálás
int szamok2[5] = {1, 2, 3, 4, 5};
int szamok3[] = {1, 2, 3, 4, 5};  // Méret automatikus
int szamok4[5] = {0};  // Minden elem 0

// Elemek elérése
szamok[0] = 10;  // Első elem
szamok[4] = 50;  // Utolsó elem

// Tömb bejárása
for (int i = 0; i < 5; i++) {
    cout << szamok[i] << " ";
}

// Range-based for
for (int szam : szamok) {
    cout << szam << " ";
}

// Tömb mérete
int meret = sizeof(szamok) / sizeof(szamok[0]);
```

## 5.2 Többdimenziós tömbök

```cpp
// 2D tömb (mátrix)
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Elemek elérése
matrix[0][0] = 10;  // Első sor, első oszlop
matrix[1][2] = 60;  // Második sor, harmadik oszlop

// Bejárás
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}

// 3D tömb
int kocka[3][3][3];
```

## 5.3 C-stílusú stringek

```cpp
// Karaktertömb (C-stílusú string)
char nev[] = "János";
char vezeteknev[20] = "Kovács";

// Beolvasás (csak szóköz nélkül)
cin >> nev;

// Beolvasás szóközzel
cin.getline(nev, 20);

// String függvények (cstring könyvtár)
#include <cstring>

int hossz = strlen(nev);           // Hossz
strcpy(vezeteknev, "Nagy");        // Másolás
strcat(nev, " ");                  // Összefűzés
strcat(nev, vezeteknev);
int eredmeny = strcmp(nev, "Kovács");  // Összehasonlítás
```

## 5.4 std::string (modern C++)

```cpp
#include <string>
using namespace std;

// String létrehozása
string s1 = "Hello";
string s2("World");
string s3(5, 'A');  // "AAAAA"
string s4;          // Üres string

// String műveletek
string nev = "János";
string vezetek = "Kovács";

string teljes = nev + " " + vezetek;  // Összefűzés
nev += " " + vezetek;                  // Hozzáfűzés

// Hossz
int hossz = nev.length();
int meret = nev.size();

// Részstring
string resz = teljes.substr(0, 5);  // Első 5 karakter

// Karakter elérése
char c = nev[0];
char c2 = nev.at(0);  // Biztonságos (kivételt dob)

// Keresés
size_t pozicio = nev.find("ános");  // 1
size_t nincs = nev.find("X");       // string::npos

// Csere
nev.replace(0, 1, "V");  // "Vános"

// Konverzió
string szam = "123";
int ertek = stoi(szam);     // string → int
double d = stod("3.14");    // string → double

string szam2 = to_string(456);  // int → string
```

### String bejárása:

```cpp
string szoveg = "Hello World";

// Indexeléssel
for (size_t i = 0; i < szoveg.length(); i++) {
    cout << szoveg[i];
}

// Range-based for
for (char c : szoveg) {
    cout << c;
}

// Iterátorral
for (auto it = szoveg.begin(); it != szoveg.end(); it++) {
    cout << *it;
}
```

---

# 6. fejezet: Mutatók és referenciák

## 6.1 Mutatók alapjai

```cpp
// Mutató deklaráció
int szam = 42;
int* ptr = &szam;  // ptr a szam címét tárolja

// Érték elérése (dereferálás)
cout << szam;      // 42 (közvetlen)
cout << *ptr;      // 42 (mutatón keresztül)
cout << &szam;     // Cím
cout << ptr;       // Ugyanaz a cím

// Mutató módosítása
*ptr = 100;        // szam értéke 100 lesz

// nullptr (üres mutató)
int* ures = nullptr;
if (ures == nullptr) {
    cout << "Üres mutató" << endl;
}
```

### Mutatók és tömbök:

```cpp
int tomb[5] = {1, 2, 3, 4, 5};
int* ptr = tomb;  // Tömb neve = első elem címe

cout << *ptr;      // 1 (első elem)
cout << *(ptr+1);  // 2 (második elem)
cout << ptr[2];    // 3 (harmadik elem)

// Tömb bejárása mutatón
for (int i = 0; i < 5; i++) {
    cout << *(ptr + i) << " ";
}
```

## 6.2 Referenciák

```cpp
int szam = 42;

// Referencia deklaráció
int& ref = szam;  // ref a szam aliasa

cout << szam;  // 42
cout << ref;   // 42

ref = 100;     // szam is 100 lesz

// Referencia vs mutató
int a = 10;
int& r = a;    // Referencia - KÖTELEZŐ inicializálni
int* p = &a;   // Mutató - lehet nullptr

// Referencia használata függvényekben
void csere(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int x = 5, y = 10;
csere(x, y);  // x=10, y=5
```

## 6.3 Dinamikus memóriakezelés

```cpp
// new operátor (memóriafoglalás)
int* ptr = new int;      // Egy int
*ptr = 42;

int* tomb = new int[10]; // 10 elemű tömb
for (int i = 0; i < 10; i++) {
    tomb[i] = i;
}

// delete operátor (memóriafelszabadítás)
delete ptr;      // Egy elem
delete[] tomb;   // Tömb

// Fontos: mindig szabadítsuk fel!
// Memóriaszivárgás elkerülése:
int* p = new int(5);
// ... használat ...
delete p;
p = nullptr;  // Dangling pointer elkerülése
```

### Dinamikus 2D tömb:

```cpp
int sorok = 3, oszlopok = 4;

// Lefoglalás
int** matrix = new int*[sorok];
for (int i = 0; i < sorok; i++) {
    matrix[i] = new int[oszlopok];
}

// Használat
matrix[0][0] = 1;

// Felszabadítás
for (int i = 0; i < sorok; i++) {
    delete[] matrix[i];
}
delete[] matrix;
```

## 6.4 Smart pointerek (C++11)

```cpp
#include <memory>

// unique_ptr (egyedüli tulajdonos)
unique_ptr<int> ptr1 = make_unique<int>(42);
unique_ptr<int[]> tomb = make_unique<int[]>(10);
// Automatikus felszabadítás, nem kell delete

// shared_ptr (több tulajdonos)
shared_ptr<int> ptr2 = make_shared<int>(42);
shared_ptr<int> ptr3 = ptr2;  // Megosztott tulajdon
// Ref counting, automatikus felszabadítás

// weak_ptr (nem tulajdonló referencia)
weak_ptr<int> gyenge = ptr2;
// Nem növeli a referenciaszámlálót
```

---

# 7. fejezet: Struktúrák és osztályok

## 7.1 Struktúrák (struct)

```cpp
struct Szemely {
    string nev;
    int kor;
    double magassag;
};

// Használat
Szemely szemely1;
szemely1.nev = "János";
szemely1.kor = 25;
szemely1.magassag = 180.5;

// Inicializálás
Szemely szemely2 = {"Éva", 30, 165.0};

// Tömb
Szemely szemelyek[3];

// Mutató
Szemely* ptr = new Szemely;
ptr->nev = "Péter";  // Nyíl operátor mutatónál
delete ptr;
```

### Struktúra függvényekkel:

```cpp
struct Szemely {
    string nev;
    int kor;
    
    void bemutatkozas() {
        cout << "Szia, " << nev << " vagyok, " << kor << " éves." << endl;
    }
    
    int szuletesiEv() {
        return 2026 - kor;
    }
};

Szemely s = {"János", 25};
s.bemutatkozas();  // "Szia, János vagyok, 25 éves."
```

## 7.2 Osztályok (class)

```cpp
class Szemely {
private:
    string nev;
    int kor;
    
public:
    // Setterek
    void setNev(string n) { nev = n; }
    void setKor(int k) { kor = k; }
    
    // Getterek
    string getNev() { return nev; }
    int getKor() { return kor; }
    
    // Metódus
    void bemutatkozas() {
        cout << "Szia, " << nev << " vagyok!" << endl;
    }
};

// Használat
Szemely szemely;
szemely.setNev("János");
szemely.setKor(25);
szemely.bemutatkozas();
```

### Hozzáférési módosítók:

| Módosító | Osztályon belül | Örökölt osztály | Kívül |
|----------|-----------------|-----------------|-------|
| `public` | ✓ | ✓ | ✓ |
| `protected` | ✓ | ✓ | ✗ |
| `private` | ✓ | ✗ | ✗ |

## 7.3 Konstruktorok és destruktorok

```cpp
class Szemely {
private:
    string nev;
    int kor;
    
public:
    // Alapértelmezett konstruktor
    Szemely() {
        nev = "Ismeretlen";
        kor = 0;
    }
    
    // Paraméteres konstruktor
    Szemely(string n, int k) {
        nev = n;
        kor = k;
    }
    
    // Inicializáló lista (hatékonyabb)
    Szemely(string n, int k) : nev(n), kor(k) {}
    
    // Destruktor
    ~Szemely() {
        cout << nev << " törlődik..." << endl;
    }
};

// Használat
Szemely s1;              // Alapértelmezett konstruktor
Szemely s2("János", 25); // Paraméteres konstruktor
```

### Másoló konstruktor:

```cpp
class Szemely {
private:
    string nev;
    int* kor;
    
public:
    // Másoló konstruktor
    Szemely(const Szemely& masik) {
        nev = masik.nev;
        kor = new int(*masik.kor);  // Mély másolás
    }
};
```

## 7.4 Getterek és setterek

```cpp
class Termek {
private:
    string nev;
    double ar;
    int keszlet;
    
public:
    // Getterek (const - nem módosítják az objektumot)
    string getNev() const { return nev; }
    double getAr() const { return ar; }
    int getKeszlet() const { return keszlet; }
    
    // Setterek
    void setNev(string n) { nev = n; }
    void setAr(double a) { 
        if (a > 0) ar = a; 
    }
    void setKeszlet(int k) {
        if (k >= 0) keszlet = k;
    }
};
```

---

# 8. fejezet: Objektumorientált programozás

## 8.1 Öröklődés

```cpp
// Alaposztály
class Allat {
protected:
    string nev;
    int kor;
    
public:
    Allat(string n, int k) : nev(n), kor(k) {}
    
    void eszik() {
        cout << nev << " eszik." << endl;
    }
    
    virtual void hangotAd() {
        cout << "Valamilyen hang" << endl;
    }
};

// Származtatott osztály
class Kutya : public Allat {
private:
    string fajta;
    
public:
    Kutya(string n, int k, string f) : Allat(n, k), fajta(f) {}
    
    // Felüldefiniálás (override)
    void hangotAd() override {
        cout << nev << " ugat: Vau-vau!" << endl;
    }
    
    void fut() {
        cout << nev << " fut." << endl;
    }
};

// Használat
Kutya kutya("Bodri", 3, "Puli");
kutya.eszik();      // Örökölt metódus
kutya.hangotAd();   // Felüldefiniált metódus
kutya.fut();        // Saját metódus
```

### Öröklődési típusok:

```cpp
class Nyilvanos : public Alap { };    // public öröklés
class Vedett : protected Alap { };    // protected öröklés
class Privat : private Alap { };      // private öröklés
```

## 8.2 Polimorfizmus

```cpp
class Alakzat {
public:
    virtual double terulet() = 0;  // Tiszta virtuális függvény
    virtual ~Alakzat() {}
};

class Kor : public Alakzat {
private:
    double sugar;
    
public:
    Kor(double r) : sugar(r) {}
    
    double terulet() override {
        return sugar * sugar * 3.14159;
    }
};

class Negyzet : public Alakzat {
private:
    double oldal;
    
public:
    Negyzet(double o) : oldal(o) {}
    
    double terulet() override {
        return oldal * oldal;
    }
};

// Polimorf használat
int main() {
    Alakzat* alakzatok[2];
    alakzatok[0] = new Kor(5);
    alakzatok[1] = new Negyzet(4);
    
    for (int i = 0; i < 2; i++) {
        cout << "Terület: " << alakzatok[i]->terulet() << endl;
    }
    
    // Felszabadítás
    for (int i = 0; i < 2; i++) {
        delete alakzatok[i];
    }
    
    return 0;
}
```

## 8.3 Absztrakt osztályok

```cpp
// Absztrakt osztály (nem példányosítható)
class Jarmu {
protected:
    string tipus;
    
public:
    Jarmu(string t) : tipus(t) {}
    
    // Tiszta virtuális függvény - absztrakt metódus
    virtual void indit() = 0;
    virtual void allit() = 0;
    
    // Virtuális destruktor
    virtual ~Jarmu() {}
    
    // Nem virtuális metódus
    void informacio() {
        cout << "Jármű típusa: " << tipus << endl;
    }
};

// Konkrét osztály
class Auto : public Jarmu {
private:
    int ajtokSzama;
    
public:
    Auto(string t, int a) : Jarmu(t), ajtokSzama(a) {}
    
    void indit() override {
        cout << tipus << " elindul." << endl;
    }
    
    void allit() override {
        cout << tipus << " megáll." << endl;
    }
};
```

## 8.4 Többes öröklődés

```cpp
class A {
public:
    void fuggvenyA() { cout << "A" << endl; }
};

class B {
public:
    void fuggvenyB() { cout << "B" << endl; }
};

// Többes öröklődés
class C : public A, public B {
public:
    void fuggvenyC() { cout << "C" << endl; }
};

C c;
c.fuggvenyA();  // A-ból örökölt
c.fuggvenyB();  // B-ből örökölt
c.fuggvenyC();  // Saját
```

## 8.5 Friend (barát) függvények és osztályok

```cpp
class Osztaly {
private:
    int titkosAdat;
    
    // Barát függvény - hozzáfér a private tagokhoz
    friend void kiir(const Osztaly& o);
    
    // Barát osztály - minden tagfüggvénye hozzáfér
    friend class Baratosztaly;
};

void kiir(const Osztaly& o) {
    cout << o.titkosAdat;  // Hozzáfér a private-hoz
}

class Baratosztaly {
public:
    void fuggveny(Osztaly& o) {
        o.titkosAdat = 42;  // Hozzáfér a private-hoz
    }
};
```

---

# 9. fejezet: Sablonok (Templates)

## 9.1 Függvénysablonok

```cpp
// Általános sablon
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Használat
cout << max(3, 7);           // int
cout << max(3.14, 2.71);     // double
cout << max('a', 'z');       // char

// Több típusparaméter
template <typename T1, typename T2>
auto osszead(T1 a, T2 b) {
    return a + b;
}

osszead(5, 3.14);  // double eredmény
```

### Sablon specializáció:

```cpp
// Általános sablon
template <typename T>
string tipusNeve(T t) {
    return "Ismeretlen";
}

// Specializációk
template <>
string tipusNeve(int t) {
    return "int";
}

template <>
string tipusNeve(double t) {
    return "double";
}

template <>
string tipusNeve(char t) {
    return "char";
}
```

## 9.2 Osztálysablonok

```cpp
template <typename T>
class Tombok {
private:
    T* adatok;
    int meret;
    
public:
    Tombok(int m) : meret(m) {
        adatok = new T[meret];
    }
    
    ~Tombok() {
        delete[] adatok;
    }
    
    void set(int index, T ertek) {
        if (index >= 0 && index < meret) {
            adatok[index] = ertek;
        }
    }
    
    T get(int index) {
        return adatok[index];
    }
    
    int getMeret() {
        return meret;
    }
};

// Használat
Tombok<int> intTomb(5);
intTomb.set(0, 10);
cout << intTomb.get(0);

Tombok<string> stringTomb(3);
stringTomb.set(0, "Hello");
```

## 9.3 Variadikus sablonok (C++11)

```cpp
// Rekurzív sablon
template <typename T>
T osszeg(T ertek) {
    return ertek;
}

template <typename T, typename... Args>
T osszeg(T elso, Args... rest) {
    return elso + osszeg(rest...);
}

// Használat
cout << osszeg(1, 2, 3, 4, 5);  // 15
cout << osszeg(1.1, 2.2, 3.3);  // 6.6
```

---

# 10. fejezet: STL - Standard Template Library

## 10.1 Vector (dinamikus tömb)

```cpp
#include <vector>

// Deklaráció
vector<int> v1;              // Üres vector
vector<int> v2(5);           // 5 elemű (0-val inicializálva)
vector<int> v3(5, 10);       // 5 elemű, minden elem 10
vector<int> v4 = {1, 2, 3};  // Inicializáló lista

// Elemek hozzáadása
v1.push_back(1);
v1.push_back(2);
v1.push_back(3);

// Elemek elérése
cout << v1[0];        // 1
cout << v1.at(0);     // 1 (biztonságos)
cout << v1.front();   // Első elem
cout << v1.back();    // Utolsó elem

// Méret és kapacitás
cout << v1.size();     // Elemek száma
cout << v1.capacity(); // Lefoglalt hely
v1.reserve(100);       // Kapacitás növelése

// Beszúrás és törlés
v1.insert(v1.begin() + 1, 99);  // Beszúrás
v1.erase(v1.begin());           // Törlés
v1.pop_back();                  // Utolsó törlése

// Bejárás
for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << " ";
}

for (int elem : v1) {
    cout << elem << " ";
}

for (auto it = v1.begin(); it != v1.end(); it++) {
    cout << *it << " ";
}
```

## 10.2 List (kétirányú láncolt lista)

```cpp
#include <list>

list<int> lista;

// Hozzáadás
lista.push_back(1);
lista.push_back(2);
lista.push_front(0);  // Elejére

// Törlés
lista.pop_back();
lista.pop_front();

// Beszúrás
auto it = lista.begin();
advance(it, 1);
lista.insert(it, 99);

// List specifikus műveletek
lista.sort();         // Rendezés
lista.reverse();      // Megfordítás
lista.unique();       // Duplikációk törlése
lista.merge(masik);   // Összefésülés
```

## 10.3 Map és Set

```cpp
#include <map>
#include <set>

// Map (kulcs-érték tároló)
map<string, int> eletkorok;
eletkorok["János"] = 25;
eletkorok["Éva"] = 30;

// Hozzáférés
cout << eletkorok["János"];  // 25
cout << eletkorok.at("Éva"); // 30

// Bejárás
for (auto const& [kulcs, ertek] : eletkorok) {
    cout << kulcs << ": " << ertek << endl;
}

// Keresés
auto it = eletkorok.find("János");
if (it != eletkorok.end()) {
    cout << "Megtalálva: " << it->second;
}

// Set (egyedi elemek)
set<int> szamok;
szamok.insert(1);
szamok.insert(2);
szamok.insert(2);  // Nem kerül be (duplikált)

for (int szam : szamok) {
    cout << szam << " ";  // 1 2
}
```

## 10.4 STL algoritmusok

```cpp
#include <algorithm>
#include <vector>

vector<int> szamok = {5, 2, 8, 1, 9, 3};

// Rendezés
sort(szamok.begin(), szamok.end());  // 1 2 3 5 8 9

// Keresés
auto it = find(szamok.begin(), szamok.end(), 8);

// Számlálás
int db = count(szamok.begin(), szamok.end(), 3);

// Minimum/Maximum
int min = *min_element(szamok.begin(), szamok.end());
int max = *max_element(szamok.begin(), szamok.end());

// Összegzés (accumulate)
#include <numeric>
int osszeg = accumulate(szamok.begin(), szamok.end(), 0);

// Transzformáció
vector<int> negyzetek;
transform(szamok.begin(), szamok.end(), back_inserter(negyzetek),
          [](int x) { return x * x; });

// Rendezés saját feltétellel
sort(szamok.begin(), szamok.end(), greater<int>());  // Csökkenő
```

---

# 11. fejezet: Kivételkezelés

## 11.1 Try-catch blokk

```cpp
#include <iostream>
#include <exception>

int main() {
    try {
        int a = 10, b = 0;
        
        if (b == 0) {
            throw "Osztás nullával!";
        }
        
        int eredmeny = a / b;
        cout << "Eredmény: " << eredmeny << endl;
        
    } catch (const char* hiba) {
        cout << "Hiba történt: " << hiba << endl;
    }
    
    return 0;
}
```

## 11.2 Több catch blokk

```cpp
try {
    int* tomb = new int[1000000000];
    throw 42;
    
} catch (bad_alloc& e) {
    cout << "Memóriahiba: " << e.what() << endl;
    
} catch (int szam) {
    cout << "Int hiba: " << szam << endl;
    
} catch (const exception& e) {
    cout << "Általános hiba: " << e.what() << endl;
    
} catch (...) {
    cout << "Ismeretlen hiba!" << endl;
}
```

## 11.3 Saját kivétel osztály

```cpp
class Sajathiba : public exception {
private:
    string uzenet;
    
public:
    Sajathiba(string u) : uzenet(u) {}
    
    const char* what() const noexcept override {
        return uzenet.c_str();
    }
};

// Használat
try {
    throw Sajathiba("Ez egy saját hiba!");
    
} catch (const Sajathiba& e) {
    cout << "Hiba: " << e.what() << endl;
}
```

## 11.4 Kivétel biztonság (RAII)

```cpp
class File {
private:
    FILE* file;
    
public:
    File(const char* nev) {
        file = fopen(nev, "r");
        if (!file) {
            throw runtime_error("Fájl nem nyitható meg");
        }
    }
    
    ~File() {
        if (file) fclose(file);  // Automatikus bezárás
    }
    
    // Másolás letiltása
    File(const File&) = delete;
    File& operator=(const File&) = delete;
};

// Használat - automatikus erőforrás kezelés
try {
    File f("adat.txt");
    // ... használat ...
} catch (...) {
    // File destruktor automatikusan lefut
}
```

---

# 12. fejezet: Fájlkezelés

## 12.1 Fájlok írása

```cpp
#include <fstream>
#include <iostream>

int main() {
    // Írás fájlba
    ofstream ki("szoveg.txt");
    
    if (ki.is_open()) {
        ki << "Első sor" << endl;
        ki << "Második sor" << endl;
        ki << "Szám: " << 42 << endl;
        ki.close();
    }
    
    return 0;
}
```

## 12.2 Fájlok olvasása

```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
    ifstream be("szoveg.txt");
    string sor;
    
    if (be.is_open()) {
        // Soronkénti olvasás
        while (getline(be, sor)) {
            cout << sor << endl;
        }
        be.close();
    }
    
    return 0;
}
```

### Egyéb olvasási módok:

```cpp
ifstream be("adat.txt");

// Szó szerinti olvasás
string szo;
while (be >> szo) {
    cout << szo << endl;
}

// Karakterenkénti olvasás
char c;
while (be.get(c)) {
    cout << c;
}

// Teljes fájl beolvasása
string tartalom((istreambuf_iterator<char>(be)),
                istreambuf_iterator<char>());
```

## 12.3 Bináris fájlok

```cpp
// Írás
struct Adat {
    int id;
    double ertek;
};

Adat adat = {1, 3.14};

ofstream bin("adat.bin", ios::binary);
bin.write(reinterpret_cast<char*>(&adat), sizeof(Adat));
bin.close();

// Olvasás
Adat beolvasott;
ifstream be("adat.bin", ios::binary);
be.read(reinterpret_cast<char*>(&beolvasott), sizeof(Adat));
be.close();

cout << "ID: " << beolvasott.id << endl;
cout << "Érték: " << beolvasott.ertek << endl;
```

## 12.4 Fájl módok

```cpp
// Megnyitási módok kombinálása
ofstream f1("fajl.txt");                    // Írás (felülír)
ofstream f2("fajl.txt", ios::app);          // Hozzáfűzés
ofstream f3("fajl.txt", ios::ate);          // Végére ugrik
ofstream f4("fajl.txt", ios::binary);       // Bináris
ofstream f5("fajl.txt", ios::trunc);        // Ürít
ofstream f6("fajl.txt", ios::out);          // Írás
ifstream f7("fajl.txt", ios::in);           // Olvasás
fstream f8("fajl.txt", ios::in | ios::out); // Olvasás/írás
```

---

# 13. fejezet: Haladó témák

## 13.1 Lambda kifejezések (C++11)

```cpp
// Egyszerű lambda
auto negyzet = [](int x) { return x * x; };
cout << negyzet(5);  // 25

// Lambda paraméterekkel
auto osszead = [](int a, int b) { return a + b; };

// Capture (környezet használata)
int szorzo = 3;
auto szoroz = [szorzo](int x) { return x * szorzo; };

// Referencia capture
int osszeg = 0;
auto novel = [&osszeg](int ertek) { osszeg += ertek; };

// Általános lambda (C++14)
auto general = [](auto a, auto b) { return a + b; };

// Lambda STL-ben
vector<int> szamok = {1, 2, 3, 4, 5};
sort(szamok.begin(), szamok.end(), [](int a, int b) {
    return a > b;  // Csökkenő rendezés
});
```

## 13.2 Smart pointerek részletesen

```cpp
#include <memory>

// unique_ptr - egyedüli tulajdonos
unique_ptr<int> ptr1 = make_unique<int>(42);
unique_ptr<int> ptr2 = move(ptr1);  // Tulajdon átruházás
// ptr1 most nullptr

// unique_ptr tömbhöz
unique_ptr<int[]> tomb = make_unique<int[]>(10);

// shared_ptr - megosztott tulajdon
shared_ptr<int> s1 = make_shared<int>(42);
shared_ptr<int> s2 = s1;  // Referenciaszámláló növelése
cout << s1.use_count();   // 2

// weak_ptr - nem tulajdonló referencia
weak_ptr<int> w = s1;
if (shared_ptr<int> lock = w.lock()) {
    cout << *lock;  // Biztonságos hozzáférés
}

// custom deleter
auto deleter = [](int* p) {
    cout << "Törlés: " << *p << endl;
    delete p;
};
unique_ptr<int, decltype(deleter)> ptr(new int(5), deleter);
```

## 13.3 Move semantics (C++11)

```cpp
// Lvalue és rvalue
int a = 5;      // lvalue (névvel rendelkezik)
int b = a + 5;  // rvalue (átmeneti érték)

// Move constructor
class String {
    char* adat;
    size_t hossz;
    
public:
    // Move constructor
    String(String&& masik) noexcept 
        : adat(masik.adat), hossz(masik.hossz) {
        masik.adat = nullptr;  // Forrás "kimerítése"
        masik.hossz = 0;
    }
    
    // Move assignment
    String& operator=(String&& masik) noexcept {
        if (this != &masik) {
            delete[] adat;
            adat = masik.adat;
            hossz = masik.hossz;
            masik.adat = nullptr;
            masik.hossz = 0;
        }
        return *this;
    }
};

// std::move használata
String s1 = "Hello";
String s2 = move(s1);  // s1 tartalma átkerül s2-be
```

## 13.4 Auto és decltype

```cpp
// auto - típuskikövetkeztetés
auto x = 42;           // int
auto y = 3.14;         // double
auto z = "Hello";      // const char*
auto v = vector<int>(); // vector<int>

// decltype - típus lekérdezése
int a = 5;
decltype(a) b = 10;    // b típusa int

// Auto függvényekben (C++14)
auto osszead(auto a, auto b) {
    return a + b;
}

// Auto lambda paraméterek
auto lambda = [](auto x) { return x * 2; };
```

## 13.5 Constexpr (fordítási idő)

```cpp
// Constexpr függvény
constexpr int negyzet(int x) {
    return x * x;
}

constexpr int eredmeny = negyzet(5);  // Fordítási időben kiértékelt

// Constexpr változók
constexpr double PI = 3.14159265359;

// Constexpr feltételek
constexpr int max(int a, int b) {
    return (a > b) ? a : b;
}

// C++17: if constexpr
template <typename T>
void fuggveny(T t) {
    if constexpr (is_integral_v<T>) {
        cout << "Egész szám";
    } else if constexpr (is_floating_point_v<T>) {
        cout << "Lebegőpontos szám";
    }
}
```

## 13.6 Modern C++ legjobb gyakorlatok

```cpp
// 1. Használj smart pointereket
unique_ptr<int> ptr = make_unique<int>(5);

// 2. Kerüld a nyers new/delete-t
vector<int> v(100);  // new int[100] helyett

// 3. Használj auto-t hosszú típusneveknél
auto it = myMap.begin();

// 4. Preferáld a const-ot
void fuggveny(const string& s) { }

// 5. Használj nullptr-t NULL helyett
int* ptr = nullptr;

// 6. Használj range-based for-t
for (const auto& elem : container) { }

// 7. Használj initializer_list-et
vector<int> v = {1, 2, 3};

// 8. Használj override kulcsszót
void fuggveny() override { }

// 9. Használj enum class-t
enum class Szin { Piros, Zold, Kek };

// 10. Használj noexcept-t ha biztos vagy benne
void fuggveny() noexcept { }
```

---

# Függelék

## A. Gyakori hibák és megoldások

### 1. Memóriaszivárgás
```cpp
// HIBÁS
int* ptr = new int[100];
// elfelejtett delete[]

// JAVÍTOTT
unique_ptr<int[]> ptr = make_unique<int[]>(100);
```

### 2. Dangling pointer
```cpp
// HIBÁS
int* ptr = new int(5);
delete ptr;
*ptr = 10;  // Hiba!

// JAVÍTOTT
delete ptr;
ptr = nullptr;
```

### 3. Tömb határok túllépése
```cpp
// HIBÁS
int tomb[5];
tomb[5] = 10;  // Hiba! 0-4 érvényes

// JAVÍTOTT
vector<int> v(5);
v.at(4) = 10;  // Kivételt dob ha hibás
```

## B. Hasznos könyvtárak

| Könyvtár | Leírás |
|----------|--------|
| `<iostream>` | Be-/kimenet |
| `<string>` | String kezelés |
| `<vector>` | Dinamikus tömb |
| `<algorithm>` | Algoritmusok |
| `<memory>` | Smart pointerek |
| `<fstream>` | Fájlkezelés |
| `<map>` | Map container |
| `<set>` | Set container |
| `<cmath>` | Matematikai függvények |
| `<chrono>` | Időmérés |

## C. További források

- [cppreference.com](https://en.cppreference.com/)
- [LearnCpp.com](https://www.learncpp.com/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

---

# 14. fejezet: Header fájlok és többfájlos projektek

## 14.1 Header fájlok (.h) létrehozása

A header fájlok (.h vagy .hpp) függvények, osztályok és változók deklarációit tartalmazzák. Lehetővé teszik a kód újrafelhasználását és szervezését.

### Egyszerű header fájl létrehozása:

**fuggvenyek.h**
```cpp
#ifndef FUGGVENYEK_H
#define FUGGVENYEK_H

// Függvény deklarációk
int osszead(int a, int b);
int szoroz(int a, int b);
void udvozol(const char* nev);

#endif // FUGGVENYEK_H
```

### Header guard (include guard) magyarázata:

```cpp
#ifndef FUGGVENYEK_H    // Ha FUGGVENYEK_H még nincs definiálva
#define FUGGVENYEK_H    // Definiáld most

// ... kód ...

#endif // FUGGVENYEK_H    // Zárd le
```

Ez megakadályozza, hogy ugyanaz a header fájl többször legyen beillesztve, ami fordítási hibát okozna.

### Modern alternatíva: `#pragma once`

```cpp
#pragma once  // Egyszerűbb, compiler-specifikus megoldás

// Függvény deklarációk
int osszead(int a, int b);
int szoroz(int a, int b);
```

## 14.2 Implementációs fájlok (.cpp)

A header fájlban deklarált függvények implementációja külön .cpp fájlba kerül.

**fuggvenyek.cpp**
```cpp
#include "fuggvenyek.h"
#include <iostream>
using namespace std;

// Függvény definíciók
int osszead(int a, int b) {
    return a + b;
}

int szoroz(int a, int b) {
    return a * b;
}

void udvozol(const char* nev) {
    cout << "Üdvözöllek, " << nev << "!" << endl;
}
```

## 14.3 Főprogram használata

**main.cpp**
```cpp
#include <iostream>
#include "fuggvenyek.h"  // Saját header fájl
using namespace std;

int main() {
    int a = 5, b = 3;
    
    cout << "Összeg: " << osszead(a, b) << endl;
    cout << "Szorzat: " << szoroz(a, b) << endl;
    
    udvozol("János");
    
    return 0;
}
```

## 14.4 Fordítás többfájlos projektnél

### Parancssori fordítás (g++):

```bash
# Egy lépésben
g++ -o program.exe main.cpp fuggvenyek.cpp

# Külön-külön objektum fájlok, majd linkelés
g++ -c main.cpp -o main.o
g++ -c fuggvenyek.cpp -o fuggvenyek.o
g++ -o program.exe main.o fuggvenyek.o
```

### Makefile példa:

```makefile
CC = g++
CFLAGS = -Wall -std=c++17
TARGET = program.exe
SRCS = main.cpp fuggvenyek.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
```

### CMakeLists.txt (CMake):

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(program.exe
    main.cpp
    fuggvenyek.cpp
)
```

## 14.5 Osztályok header fájlokban

**szemely.h**
```cpp
#ifndef SZEMELY_H
#define SZEMELY_H

#include <string>

class Szemely {
private:
    std::string nev;
    int kor;
    
public:
    // Konstruktorok
    Szemely();
    Szemely(std::string n, int k);
    
    // Getterek
    std::string getNev() const;
    int getKor() const;
    
    // Setterek
    void setNev(std::string n);
    void setKor(int k);
    
    // Egyéb metódusok
    void bemutatkozas() const;
    int szuletesiEv() const;
    
    // Destruktor
    ~Szemely();
};

#endif // SZEMELY_H
```

**szemely.cpp**
```cpp
#include "szemely.h"
#include <iostream>

// Konstruktorok
Szemely::Szemely() : nev("Ismeretlen"), kor(0) {}

Szemely::Szemely(std::string n, int k) : nev(n), kor(k) {}

// Getterek
std::string Szemely::getNev() const {
    return nev;
}

int Szemely::getKor() const {
    return kor;
}

// Setterek
void Szemely::setNev(std::string n) {
    nev = n;
}

void Szemely::setKor(int k) {
    if (k > 0) kor = k;
}

// Metódusok
void Szemely::bemutatkozas() const {
    std::cout << "Szia, " << nev << " vagyok, " << kor << " éves." << std::endl;
}

int Szemely::szuletesiEv() const {
    return 2026 - kor;
}

// Destruktor
Szemely::~Szemely() {
    std::cout << "Szemely objektum törlődik: " << nev << std::endl;
}
```

**main.cpp**
```cpp
#include "szemely.h"

int main() {
    Szemely s1;  // Alapértelmezett konstruktor
    Szemely s2("János", 25);  // Paraméteres konstruktor
    
    s1.bemutatkozas();
    s2.bemutatkozas();
    
    std::cout << "János születési éve: " << s2.szuletesiEv() << std::endl;
    
    return 0;
}
```

## 14.6 Több mappa szerkezete

### Projekt struktúra:

```
projekt/
├── include/
│   ├── fuggvenyek.h
│   └── szemely.h
├── src/
│   ├── main.cpp
│   ├── fuggvenyek.cpp
│   └── szemely.cpp
├── CMakeLists.txt
└── Makefile
```

### Fordítás include útvonallal:

```bash
# g++ -I kapcsolóval
g++ -I./include -o program.exe src/main.cpp src/fuggvenyek.cpp src/szemely.cpp
```

## 14.7 Statikus és extern változók

**globalis.h**
```cpp
#ifndef GLOBALIS_H
#define GLOBALIS_H

// Extern deklaráció (nem foglal le memóriát)
extern int globalisSzamlalo;
extern const double PI;

// Inline változó (C++17)
inline int inlineValtozo = 42;

#endif // GLOBALIS_H
```

**globalis.cpp**
```cpp
#include "globalis.h"

// Definíció (memóriafoglalás)
int globalisSzamlalo = 0;
const double PI = 3.14159265359;
```

## 14.8 Template header fájlok

A sablonokat teljes egészében a header fájlban kell definiálni:

**sablonok.h**
```cpp
#ifndef SABLONOK_H
#define SABLONOK_H

// Függvénysablon - teljes definíció a headerben
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Osztálysablon - teljes definíció a headerben
template <typename T>
class Tarolo {
private:
    T adat;
    
public:
    Tarolo(T a) : adat(a) {}
    
    T getAdat() const {
        return adat;
    }
    
    void setAdat(T a) {
        adat = a;
    }
};

#endif // SABLONOK_H
```

## 14.9 Gyakori hibák

### 1. Függvény definíció headerben (hiba!)

```cpp
// HIBÁS - többszörös definíció hiba
// fuggvenyek.h
int osszead(int a, int b) {
    return a + b;
}
```

```cpp
// JAVÍTOTT - csak deklaráció a headerben
// fuggvenyek.h
int osszead(int a, int b);  // Deklaráció

// fuggvenyek.cpp
int osszead(int a, int b) {  // Definíció
    return a + b;
}
```

### 2. Körkörös hivatkozás

```cpp
// HIBÁS - körkörös include
// a.h
#include "b.h"
class A { B* b; };

// b.h
#include "a.h"
class B { A* a; };

// JAVÍTOTT - előreközölt deklaráció
// a.h
class B;  // Előreközölt deklaráció
class A { B* b; };

// b.h
class A;  // Előreközölt deklaráció
class B { A* a; };
```

---

# 15. fejezet: Windows GDI és natív ablakprogramozás

## 15.1 Bevezetés a Windows API-ba

A Windows API (Win32 API) lehetővé teszi natív Windows alkalmazások készítését. A GDI (Graphics Device Interface) a grafikus műveletekért felel.

### Első Windows ablak program:

```cpp
#include <windows.h>
#include <tchar.h>

// Ablakosztály neve
const TCHAR CLASS_NAME[] = TEXT("SajatAblakOsztaly");

// Ablakeljárás (Window Procedure)
LRESULT CALLBACK AblakEljaras(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
            
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Rajzolás
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
            TextOut(hdc, 50, 50, TEXT("Helló Windows!"), 14);
            
            EndPaint(hwnd, &ps);
            break;
        }
        
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// Belépési pont
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    
    // Ablakosztály regisztrálása
    WNDCLASS wc = {};
    wc.lpfnWndProc = AblakEljaras;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    RegisterClass(&wc);
    
    // Ablak létrehozása
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        TEXT("Saját Windows Alkalmazás"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    
    if (hwnd == NULL) {
        return 0;
    }
    
    // Ablak megjelenítése
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    // Üzenet hurok (Message Loop)
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}
```

### Fordítás:

```bash
# MinGW
g++ -o program.exe main.cpp -lgdi32 -luser32

# MSVC
cl /EHsc main.cpp user32.lib gdi32.lib
```

## 15.2 GDI alapok - Grafikus műveletek

### Színek és ecsetek:

```cpp
case WM_PAINT: {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    
    // Színek létrehozása
    COLORREF piros = RGB(255, 0, 0);
    COLORREF zold = RGB(0, 255, 0);
    COLORREF kek = RGB(0, 0, 255);
    
    // Ecset létrehozása
    HBRUSH pirosEcset = CreateSolidBrush(piros);
    HBRUSH zoldEcset = CreateSolidBrush(zold);
    
    // Téglalap rajzolása
    RECT rect = {100, 100, 300, 200};
    FillRect(hdc, &rect, pirosEcset);
    
    // Ellipszis rajzolása
    SelectObject(hdc, zoldEcset);
    Ellipse(hdc, 400, 100, 600, 300);
    
    // Erőforrások felszabadítása
    DeleteObject(pirosEcset);
    DeleteObject(zoldEcset);
    
    EndPaint(hwnd, &ps);
    break;
}
```

### Vonalak rajzolása:

```cpp
case WM_PAINT: {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    
    // Toll létrehozása
    HPEN toll1 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    HPEN toll2 = CreatePen(PS_DASH, 3, RGB(0, 0, 255));
    
    // Toll kiválasztása
    SelectObject(hdc, toll1);
    
    // Vonal rajzolása
    MoveToEx(hdc, 50, 50, NULL);
    LineTo(hdc, 200, 200);
    
    // Téglalap keret
    SelectObject(hdc, toll2);
    Rectangle(hdc, 250, 50, 450, 250);
    
    // Felszabadítás
    DeleteObject(toll1);
    DeleteObject(toll2);
    
    EndPaint(hwnd, &ps);
    break;
}
```

### Szöveg rajzolása:

```cpp
case WM_PAINT: {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    
    // Háttér mód
    SetBkMode(hdc, TRANSPARENT);
    
    // Szöveg színe
    SetTextColor(hdc, RGB(0, 0, 255));
    
    // Egyszerű szöveg
    TextOut(hdc, 50, 50, TEXT("Helló Windows!"), 14);
    
    // Formázott szöveg
    RECT rect = {50, 100, 400, 200};
    DrawText(hdc, TEXT("Ez egy hosszabb szöveg,\namely több sorban is megjelenhet."),
             -1, &rect, DT_LEFT | DT_WORDBREAK);
    
    EndPaint(hwnd, &ps);
    break;
}
```

## 15.3 Eseménykezelés

### Egér események:

```cpp
LRESULT CALLBACK AblakEljaras(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static int egérX = 0, egérY = 0;
    static bool egérGombNyomva = false;
    
    switch (msg) {
        case WM_LBUTTONDOWN:
            egérGombNyomva = true;
            egérX = LOWORD(lParam);
            egérY = HIWORD(lParam);
            InvalidateRect(hwnd, NULL, TRUE);  // Újrarajzolás
            break;
            
        case WM_LBUTTONUP:
            egérGombNyomva = false;
            break;
            
        case WM_MOUSEMOVE:
            if (egérGombNyomva) {
                egérX = LOWORD(lParam);
                egérY = HIWORD(lParam);
                InvalidateRect(hwnd, NULL, TRUE);
            }
            break;
            
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            TCHAR buffer[100];
            wsprintf(buffer, TEXT("Egér pozíció: %d, %d"), egérX, egérY);
            TextOut(hdc, 10, 10, buffer, lstrlen(buffer));
            
            if (egérGombNyomva) {
                Ellipse(hdc, egérX - 20, egérY - 20, egérX + 20, egérY + 20);
            }
            
            EndPaint(hwnd, &ps);
            break;
        }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
```

### Billentyűzet események:

```cpp
case WM_KEYDOWN:
    switch (wParam) {
        case VK_UP:
            // Felfelé nyíl
            break;
        case VK_DOWN:
            // Lefelé nyíl
            break;
        case VK_LEFT:
            // Balra nyíl
            break;
        case VK_RIGHT:
            // Jobbra nyíl
            break;
        case VK_ESCAPE:
            DestroyWindow(hwnd);
            break;
    }
    break;
```

## 15.4 Vezérlők (Controls)

### Gomb, lista, szövegmező:

```cpp
// Globális változók
HWND gombHwnd;
HWND listaHwnd;
HWND szovegHwnd;

// Ablak létrehozásakor
gombHwnd = CreateWindow(
    TEXT("BUTTON"),
    TEXT("Kattints ide!"),
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
    10, 10, 150, 40,
    hwnd,
    (HMENU)1,  // Gomb azonosító
    hInstance,
    NULL
);

listaHwnd = CreateWindow(
    TEXT("LISTBOX"),
    NULL,
    WS_CHILD | WS_VISIBLE | LBS_STANDARD,
    10, 60, 200, 200,
    hwnd,
    (HMENU)2,
    hInstance,
    NULL
);

// Lista elemek hozzáadása
SendMessage(listaHwnd, LB_ADDSTRING, 0, (LPARAM)TEXT("Első elem"));
SendMessage(listaHwnd, LB_ADDSTRING, 0, (LPARAM)TEXT("Második elem"));

// Üzenetkezelés
case WM_COMMAND:
    if (LOWORD(wParam) == 1) {  // Gomb
        SendMessage(listaHwnd, LB_ADDSTRING, 0, (LPARAM)TEXT("Új elem"));
    }
    break;
```

## 15.5 Teljes példa - Rajzoló alkalmazás

```cpp
#include <windows.h>
#include <vector>

using namespace std;

const TCHAR CLASS_NAME[] = TEXT("RajzoloAblak");

struct Pont {
    int x, y;
};

vector<Pont> pontok;
bool rajzolas = false;

LRESULT CALLBACK AblakEljaras(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_LBUTTONDOWN:
            rajzolas = true;
            pontok.clear();
            pontok.push_back({LOWORD(lParam), HIWORD(lParam)});
            break;
            
        case WM_LBUTTONUP:
            rajzolas = false;
            break;
            
        case WM_MOUSEMOVE:
            if (rajzolas) {
                pontok.push_back({LOWORD(lParam), HIWORD(lParam)});
                InvalidateRect(hwnd, NULL, FALSE);
            }
            break;
            
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Háttér törlése
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
            
            // Vonalak rajzolása
            if (pontok.size() > 1) {
                HPEN toll = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
                SelectObject(hdc, toll);
                
                for (size_t i = 1; i < pontok.size(); i++) {
                    MoveToEx(hdc, pontok[i-1].x, pontok[i-1].y, NULL);
                    LineTo(hdc, pontok[i].x, pontok[i].y);
                }
                
                DeleteObject(toll);
            }
            
            EndPaint(hwnd, &ps);
            break;
        }
        
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
            
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    
    WNDCLASS wc = {};
    wc.lpfnWndProc = AblakEljaras;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    RegisterClass(&wc);
    
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        TEXT("Egyszerű Rajzoló"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}
```

## 15.6 Menük létrehozása

```cpp
// Menü létrehozása
HMENU hMenu = CreateMenu();
HMENU hMenuFile = CreatePopupMenu();

AppendMenu(hMenuFile, MF_STRING, 1001, TEXT("Új"));
AppendMenu(hMenuFile, MF_STRING, 1002, TEXT("Megnyitás"));
AppendMenu(hMenuFile, MF_SEPARATOR, 0, NULL);
AppendMenu(hMenuFile, MF_STRING, 1003, TEXT("Kilépés"));

AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hMenuFile, TEXT("Fájl"));

SetMenu(hwnd, hMenu);

// Menü kezelés
case WM_COMMAND:
    switch (LOWORD(wParam)) {
        case 1001:
            // Új
            break;
        case 1002:
            // Megnyitás
            break;
        case 1003:
            DestroyWindow(hwnd);
            break;
    }
    break;
```

## 15.7 Párbeszédablakok (Dialog Boxes)

### Üzenetdobozok:

```cpp
// Információs üzenet
MessageBox(hwnd, TEXT("Sikeres művelet!"), TEXT("Információ"), MB_OK | MB_ICONINFORMATION);

// Hibaüzenet
MessageBox(hwnd, TEXT("Hiba történt!"), TEXT("Hiba"), MB_OK | MB_ICONERROR);

// Megerősítés
int eredmeny = MessageBox(hwnd, TEXT("Biztosan kilép?"), 
                          TEXT("Megerősítés"), MB_YESNO | MB_ICONQUESTION);

if (eredmeny == IDYES) {
    // Igen válasz
}
```

### Fájl megnyitás dialógus:

```cpp
#include <commdlg.h>

OPENFILENAME ofn = {};
TCHAR szFile[260] = TEXT("");

ofn.lStructSize = sizeof(ofn);
ofn.hwndOwner = hwnd;
ofn.lpstrFile = szFile;
ofn.nMaxFile = sizeof(szFile);
ofn.lpstrFilter = TEXT("Fájlok (*.*)\0*.*\0Képek (*.bmp;*.jpg)\0*.bmp;*.jpg\0");
ofn.nFilterIndex = 1;
ofn.lpstrFileTitle = NULL;
ofn.nMaxFileTitle = 0;
ofn.lpstrInitialDir = NULL;
ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

if (GetOpenFileName(&ofn)) {
    // Fájl kiválasztva
    MessageBox(hwnd, szFile, TEXT("Kiválasztott fájl"), MB_OK);
}
```

---

# 16. fejezet: Linux ablakprogramozás (X11 és GTK)

## 16.1 X11 alapok

Az X11 (X Window System) a Linux és Unix rendszerek grafikus felülete.

### Egyszerű X11 ablak:

```cpp
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Display* display = XOpenDisplay(NULL);
    
    if (display == NULL) {
        fprintf(stderr, "Nem sikerült megnyitni a display-t!\n");
        return 1;
    }
    
    Window rootWindow = DefaultRootWindow(display);
    
    // Ablak attribútumok
    XSetWindowAttributes attrs;
    attrs.event_mask = ExposureMask | KeyPressMask | ButtonPressMask;
    
    // Ablak létrehozása
    Window ablak = XCreateWindow(
        display,
        rootWindow,
        100, 100,           // Pozíció
        640, 480,           // Méret
        0,                  // Keret szélesség
        CopyFromParent,     // Színmélység
        InputOutput,
        CopyFromParent,
        CWEventMask,
        &attrs
    );
    
    // Ablak cím beállítása
    XStoreName(display, ablak, "X11 Alkalmazás");
    
    // Ablak megjelenítése
    XMapWindow(display, ablak);
    
    // Esemény hurok
    XEvent event;
    while (1) {
        XNextEvent(display, &event);
        
        switch (event.type) {
            case Expose:
                // Rajzolás
                XDrawString(display, ablak, DefaultGC(display, 0),
                           50, 50, "Helló X11!", 10);
                break;
                
            case KeyPress:
                // Kilépés Escape-re
                if (event.xkey.keycode == 9) {  // Escape keycode
                    XDestroyWindow(display, ablak);
                    XCloseDisplay(display);
                    return 0;
                }
                break;
                
            case ButtonPress:
                printf("Egér kattintás: %d, %d\n", 
                       event.xbutton.x, event.xbutton.y);
                break;
        }
    }
    
    return 0;
}
```

### Fordítás X11-hez:

```bash
g++ -o program program.cpp -lX11
```

## 16.2 X11 grafikus műveletek

```cpp
#include <X11/Xlib.h>
#include <X11/Xutil.h>

void rajzolas(Display* display, Window ablak) {
    GC gc = DefaultGC(display, 0);
    
    // Színek
    unsigned long feher = WhitePixel(display, 0);
    unsigned long fekete = BlackPixel(display, 0);
    unsigned long piros = XAllocColor(display, DefaultColormap(display, 0), 
                                       &(XColor{.red = 65535, .green = 0, .blue = 0})) 
                          ? 0xFF0000 : fekete;
    
    // Vonal rajzolása
    XDrawLine(display, ablak, gc, 50, 50, 200, 200);
    
    // Téglalap
    XDrawRectangle(display, ablak, gc, 100, 100, 150, 100);
    
    // Kitöltött téglalap
    XSetForeground(display, gc, piros);
    XFillRectangle(display, ablak, gc, 300, 100, 100, 100);
    
    // Szöveg
    XSetForeground(display, gc, fekete);
    XDrawString(display, ablak, gc, 50, 300, "X11 Grafika", 11);
    
    // Kör (ív)
    XDrawArc(display, ablak, gc, 50, 350, 100, 100, 0, 360 * 64);
}
```

## 16.3 GTK+ 3 bevezetés

A GTK (GIMP Toolkit) egy modern, objektumorientált GUI toolkit.

### Egyszerű GTK ablak:

```cpp
#include <gtk/gtk.h>

// Callback függvény a gombhoz
static void gomb_nyomva(GtkWidget* widget, gpointer data) {
    g_print("Gomb megnyomva: %s\n", (char*)data);
}

// Kilépés callback
static void kilépés(GtkWidget* widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char* argv[]) {
    // GTK inicializálás
    gtk_init(&argc, &argv);
    
    // Főablak létrehozása
    GtkWidget* ablak = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ablak), "GTK Alkalmazás");
    gtk_window_set_default_size(GTK_WINDOW(ablak), 400, 300);
    gtk_container_set_border_width(GTK_CONTAINER(ablak), 10);
    
    // Gomb létrehozása
    GtkWidget* gomb = gtk_button_new_with_label("Kattints ide!");
    
    // Eseménykezelők csatlakoztatása
    g_signal_connect(gomb, "clicked", G_CALLBACK(gomb_nyomva), (gpointer)"Üdvözlet!");
    g_signal_connect(ablak, "destroy", G_CALLBACK(kilépés), NULL);
    
    // Gomb hozzáadása az ablakhoz
    gtk_container_add(GTK_CONTAINER(ablak), gomb);
    
    // Widgetek megjelenítése
    gtk_widget_show_all(ablak);
    
    // Fő ciklus
    gtk_main();
    
    return 0;
}
```

### Fordítás GTK-hoz:

```bash
g++ -o program program.cpp $(pkg-config --cflags --libs gtk+-3.0)
```

## 16.4 GTK layout és vezérlők

### Több vezérlő elhelyezése:

```cpp
#include <gtk/gtk.h>

static void szamitas(GtkWidget* widget, gpointer data) {
    GtkWidget* label = GTK_WIDGET(data);
    gtk_label_set_text(GTK_LABEL(label), "Számítás elvégezve!");
}

int main(int argc, char* argv[]) {
    gtk_init(&argc, &argv);
    
    GtkWidget* ablak = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ablak), "GTK Példa");
    gtk_container_set_border_width(GTK_CONTAINER(ablak), 10);
    
    // Függőleges doboz elrendezés
    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    
    // Label
    GtkWidget* label = gtk_label_new("Üdvözöllek a GTK-ban!");
    
    // Entry (szövegmező)
    GtkWidget* entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry), "Írj ide valamit...");
    
    // Gomb
    GtkWidget* gomb = gtk_button_new_with_label("Számítás");
    g_signal_connect(gomb, "clicked", G_CALLBACK(szamitas), label);
    
    // Checkbutton
    GtkWidget* check = gtk_check_button_new_with_label("Opció bekapcsolása");
    
    // Hozzáadás a dobozhoz
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), gomb, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), check, FALSE, FALSE, 0);
    
    gtk_container_add(GTK_CONTAINER(ablak), vbox);
    
    g_signal_connect(ablak, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_widget_show_all(ablak);
    gtk_main();
    
    return 0;
}
```

## 16.5 GTK haladó elemek

### Lista (TreeView):

```cpp
GtkWidget* lista_letrehozasa() {
    // Lista modell
    GtkListStore* store;
    GtkTreeIter iter;
    
    store = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_INT);
    
    // Adatok hozzáadása
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "Első elem", 1, 100, -1);
    
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "Második elem", 1, 200, -1);
    
    // TreeView létrehozása
    GtkWidget* view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
    
    // Oszlopok
    GtkCellRenderer* renderer;
    GtkTreeViewColumn* column;
    
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Név", renderer, "text", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
    
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Érték", renderer, "text", 1, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
    
    g_object_unref(store);
    
    return view;
}
```

### Fájl választó dialógus:

```cpp
void fajl_megnyitasa(GtkWidget* widget, gpointer data) {
    GtkWidget* dialog = gtk_file_chooser_dialog_new(
        "Fájl megnyitása",
        GTK_WINDOW(data),
        GTK_FILE_CHOOSER_ACTION_OPEN,
        "_Mégse", GTK_RESPONSE_CANCEL,
        "_Megnyitás", GTK_RESPONSE_ACCEPT,
        NULL
    );
    
    GtkFileFilter* filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "Képek");
    gtk_file_filter_add_pattern(filter, "*.png");
    gtk_file_filter_add_pattern(filter, "*.jpg");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);
    
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char* filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        g_print("Kiválasztott fájl: %s\n", filename);
        g_free(filename);
    }
    
    gtk_widget_destroy(dialog);
}
```

## 16.6 GTK CSS stílusozás

```css
/* style.css */
window {
    background-color: #f0f0f0;
}

button {
    background-color: #4CAF50;
    color: white;
    padding: 10px 20px;
    border-radius: 5px;
}

button:hover {
    background-color: #45a049;
}

label {
    font-size: 16px;
    font-weight: bold;
}
```

```cpp
// CSS betöltése
GtkCssProvider* provider = gtk_css_provider_new();
gtk_css_provider_load_from_path(provider, "style.css", NULL);
gtk_style_context_add_provider_for_screen(
    gdk_screen_get_default(),
    GTK_STYLE_PROVIDER(provider),
    GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
);
```

## 16.7 Teljes GTK példa - Szövegszerkesztő

```cpp
#include <gtk/gtk.h>

GtkWidget* create_text_view() {
    GtkWidget* scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled),
                                    GTK_POLICY_AUTOMATIC,
                                    GTK_POLICY_AUTOMATIC);
    
    GtkWidget* textview = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textview), GTK_WRAP_WORD);
    
    gtk_container_add(GTK_CONTAINER(scrolled), textview);
    
    return scrolled;
}

void mentes(GtkWidget* widget, gpointer data) {
    GtkWidget* dialog = gtk_file_chooser_dialog_new(
        "Mentés másként",
        GTK_WINDOW(data),
        GTK_FILE_CHOOSER_ACTION_SAVE,
        "_Mégse", GTK_RESPONSE_CANCEL,
        "_Mentés", GTK_RESPONSE_ACCEPT,
        NULL
    );
    
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char* filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        g_print("Mentés ide: %s\n", filename);
        g_free(filename);
    }
    
    gtk_widget_destroy(dialog);
}

int main(int argc, char* argv[]) {
    gtk_init(&argc, &argv);
    
    GtkWidget* ablak = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ablak), "Egyszerű Szövegszerkesztő");
    gtk_window_set_default_size(GTK_WINDOW(ablak), 800, 600);
    
    // Függőleges doboz
    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    
    // Menüsáv
    GtkWidget* menubar = gtk_menu_bar_new();
    
    // Fájl menü
    GtkWidget* fajl_menu = gtk_menu_new();
    GtkWidget* fajl_item = gtk_menu_item_new_with_label("Fájl");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fajl_item), fajl_menu);
    
    GtkWidget* mentes_item = gtk_menu_item_new_with_label("Mentés");
    g_signal_connect(mentes_item, "activate", G_CALLBACK(mentes), ablak);
    
    GtkWidget* kilep_item = gtk_menu_item_new_with_label("Kilépés");
    g_signal_connect(kilep_item, "activate", G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_menu_shell_append(GTK_MENU_SHELL(fajl_menu), mentes_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(fajl_menu), kilep_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fajl_item);
    
    // Szövegnézet
    GtkWidget* textview = create_text_view();
    
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), textview, TRUE, TRUE, 0);
    
    gtk_container_add(GTK_CONTAINER(ablak), vbox);
    
    g_signal_connect(ablak, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_widget_show_all(ablak);
    gtk_main();
    
    return 0;
}
```

## 16.8 Qt keretrendszer (alternatíva GTK-hoz)

A Qt egy másik népszerű cross-platform GUI keretrendszer C++-hoz.

### Egyszerű Qt ablak:

```cpp
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    QWidget ablak;
    ablak.setWindowTitle("Qt Alkalmazás");
    ablak.resize(400, 300);
    
    // Elrendezés
    QVBoxLayout* layout = new QVBoxLayout;
    
    QLabel* label = new QLabel("Üdvözöllek a Qt-ban!");
    QPushButton* gomb = new QPushButton("Kattints ide!");
    
    layout->addWidget(label);
    layout->addWidget(gomb);
    
    ablak.setLayout(layout);
    
    // Eseménykezelés
    QObject::connect(gomb, &QPushButton::clicked, []() {
        qDebug() << "Gomb megnyomva!";
    });
    
    ablak.show();
    
    return app.exec();
}
```

### Fordítás Qt-hoz:

```bash
qmake projekt.pro
make

# vagy
cmake -DCMAKE_PREFIX_PATH=/path/to/qt ..
make
```

---

# 17. fejezet: Matematikai képletek C++-ban

## 17.1 Matematikai könyvtárak

### `<cmath>` - Alap matematikai függvények:

```cpp
#include <iostream>
#include <cmath>

int main() {
    double x = 4.0;
    
    // Hatvány, gyök
    std::cout << "Négyzet: " << pow(x, 2) << std::endl;      // 16
    std::cout << "Négyzetgyök: " << sqrt(x) << std::endl;    // 2
    std::cout << "Köbgyök: " << cbrt(x) << std::endl;        // 1.587
    
    // Exponenciális, logaritmus
    std::cout << "e^x: " << exp(x) << std::endl;             // 54.598
    std::cout << "ln(x): " << log(x) << std::endl;           // 1.386
    std::cout << "log10(x): " << log10(x) << std::endl;      // 0.602
    
    // Trigonometria
    double szog = M_PI / 4;  // 45 fok radiánban
    std::cout << "sin: " << sin(szog) << std::endl;          // 0.707
    std::cout << "cos: " << cos(szog) << std::endl;          // 0.707
    std::cout << "tan: " << tan(szog) << std::endl;          // 1.0
    
    // Inverz trigonometria
    std::cout << "asin: " << asin(0.707) << std::endl;
    std::cout << "acos: " << acos(0.707) << std::endl;
    std::cout << "atan: " << atan(1.0) << std::endl;         // 0.785 (45°)
    
    // Kerekítés
    std::cout << "floor: " << floor(3.7) << std::endl;       // 3
    std::cout << "ceil: " << ceil(3.2) << std::endl;         // 4
    std::cout << "round: " << round(3.5) << std::endl;       // 4
    
    // Abszolút érték
    std::cout << "abs: " << abs(-5) << std::endl;            // 5
    std::cout << "fabs: " << fabs(-5.5) << std::endl;        // 5.5
    
    // Konstantok
    std::cout << "PI: " << M_PI << std::endl;                // 3.14159
    std::cout << "e: " << M_E << std::endl;                  // 2.71828
    
    return 0;
}
```

## 17.2 Matematikai képletek átírása C++-ra

### Másodfokú egyenlet megoldása:

**Matematikai formula:**
$$x_{1,2} = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$$

**C++ implementáció:**

```cpp
#include <iostream>
#include <cmath>

struct MasodfokuEredmeny {
    bool vanMegoldas;
    double x1, x2;
};

MasodfokuEredmeny masodfokuMegold(double a, double b, double c) {
    MasodfokuEredmeny eredmeny;
    
    if (a == 0) {
        // Nem másodfokú
        eredmeny.vanMegoldas = false;
        return eredmeny;
    }
    
    double diszkriminans = b * b - 4 * a * c;
    
    if (diszkriminans > 0) {
        // Két valós megoldás
        eredmeny.x1 = (-b + sqrt(diszkriminans)) / (2 * a);
        eredmeny.x2 = (-b - sqrt(diszkriminans)) / (2 * a);
        eredmeny.vanMegoldas = true;
    } else if (diszkriminans == 0) {
        // Egy valós megoldás
        eredmeny.x1 = eredmeny.x2 = -b / (2 * a);
        eredmeny.vanMegoldas = true;
    } else {
        // Nincs valós megoldás
        eredmeny.vanMegoldas = false;
    }
    
    return eredmeny;
}

int main() {
    auto eredmeny = masodfokuMegold(1, -5, 6);
    
    if (eredmeny.vanMegoldas) {
        std::cout << "x1 = " << eredmeny.x1 << std::endl;
        std::cout << "x2 = " << eredmeny.x2 << std::endl;
    } else {
        std::cout << "Nincs valós megoldás" << std::endl;
    }
    
    return 0;
}
```

### Derékszögű háromszög átfogója:

**Pitagorasz-tétel:** $c = \sqrt{a^2 + b^2}$

```cpp
#include <cmath>

double atfogo(double a, double b) {
    return sqrt(a * a + b * b);
    // vagy: return hypot(a, b);  // hypot() biztonságosabb (túlcsordulás ellen)
}
```

### Szögfüggvények használata:

```cpp
#include <cmath>

// Fok radiánba
double fokRad(double fok) {
    return fok * M_PI / 180.0;
}

// Radián fokba
double radFok(double rad) {
    return rad * 180.0 / M_PI;
}

// Példa: Ferde hajítás
struct HajitasEredmeny {
    double tavolsag;
    double maxMagassag;
    repulesiIdo;
};

HajitasEredmeny ferdeHajitas(double v0, double szogFok, double g = 9.81) {
    HajitasEredmeny eredmeny;
    double szogRad = fokRad(szogFok);
    
    // Hatótávolság: d = (v₀² × sin(2θ)) / g
    eredmeny.tavolsag = (v0 * v0 * sin(2 * szogRad)) / g;
    
    // Maximális magasság: h = (v₀² × sin²(θ)) / (2g)
    eredmeny.maxMagassag = (v0 * v0 * sin(szogRad) * sin(szogRad)) / (2 * g);
    
    // Repülési idő: t = (2 × v₀ × sin(θ)) / g
    eredmeny.repulesiIdo = (2 * v0 * sin(szogRad)) / g;
    
    return eredmeny;
}
```

## 17.3 Összetett számok

```cpp
#include <iostream>
#include <complex>

int main() {
    using namespace std::complex_literals;
    
    // Komplex számok létrehozása
    std::complex<double> z1(3.0, 4.0);  // 3 + 4i
    std::complex<double> z2 = 1.0 + 2.0i;
    
    // Műveletek
    std::complex<double> osszeg = z1 + z2;
    std::complex<double> szorzat = z1 * z2;
    
    // Valós és képzetes rész
    std::cout << "Valós rész: " << z1.real() << std::endl;
    std::cout << "Képzetes rész: " << z1.imag() << std::endl;
    
    // Abszolút érték (modulus)
    std::cout << "Abszolút érték: " << std::abs(z1) << std::endl;
    
    // Fázisszög (argument)
    std::cout << "Fázisszög: " << std::arg(z1) << " rad" << std::endl;
    
    // Konjugált
    std::cout << "Konjugált: " << std::conj(z1) << std::endl;
    
    // Hatványozás
    std::cout << "z1^2: " << std::pow(z1, 2) << std::endl;
    
    // Exponenciális
    std::cout << "e^(i*π) = " << std::exp(std::complex<double>(0, M_PI)) << std::endl;
    // Euler-azonosság: e^(iπ) + 1 = 0
    
    return 0;
}
```

## 17.4 Vektor és mátrix műveletek

### 3D vektor osztály:

```cpp
#include <cmath>
#include <iostream>

class Vector3 {
public:
    double x, y, z;
    
    Vector3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    
    // Összeadás
    Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }
    
    // Kivonás
    Vector3 operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }
    
    // Skalárral való szorzás
    Vector3 operator*(double scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }
    
    // Skaláris szorzat
    double dot(const Vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
    
    // Vektoriális szorzat
    Vector3 cross(const Vector3& other) const {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }
    
    // Hossz (norma)
    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }
    
    // Normalizálás
    Vector3 normalize() const {
        double len = length();
        if (len > 0) {
            return *this * (1.0 / len);
        }
        return Vector3();
    }
    
    // Kiírás
    void print() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

int main() {
    Vector3 a(1, 2, 3);
    Vector3 b(4, 5, 6);
    
    Vector3 osszeg = a + b;
    osszeg.print();  // (5, 7, 9)
    
    double skalaris = a.dot(b);
    std::cout << "Skaláris szorzat: " << skalaris << std::endl;  // 32
    
    Vector3 vektoriális = a.cross(b);
    vektoriális.print();  // (-3, 6, -3)
    
    std::cout << "Hossz: " << a.length() << std::endl;  // 3.74
    
    return 0;
}
```

### Mátrix osztály (3x3):

```cpp
#include <array>
#include <cmath>

class Matrix3x3 {
private:
    std::array<std::array<double, 3>, 3> adat;
    
public:
    Matrix3x3() {
        // Nullmátrix
        for (auto& sor : adat)
            for (auto& elem : sor)
                elem = 0.0;
    }
    
    // Identitásmátrix
    static Matrix3x3 identity() {
        Matrix3x3 m;
        m.adat[0][0] = 1.0;
        m.adat[1][1] = 1.0;
        m.adat[2][2] = 1.0;
        return m;
    }
    
    // Elem elérés
    double& at(int sor, int oszlop) {
        return adat[sor][oszlop];
    }
    
    // Mátrix szorzás
    Matrix3x3 operator*(const Matrix3x3& other) const {
        Matrix3x3 eredmeny;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    eredmeny.adat[i][j] += adat[i][k] * other.adat[k][j];
                }
            }
        }
        return eredmeny;
    }
    
    // Vektor transzformálás
    Vector3 transform(const Vector3& v) const {
        return Vector3(
            adat[0][0] * v.x + adat[0][1] * v.y + adat[0][2] * v.z,
            adat[1][0] * v.x + adat[1][1] * v.y + adat[1][2] * v.z,
            adat[2][0] * v.x + adat[2][1] * v.y + adat[2][2] * v.z
        );
    }
    
    // Forgatás Z tengely körül
    static Matrix3x3 rotateZ(double szogRad) {
        Matrix3x3 m;
        m.adat[0][0] = std::cos(szogRad);
        m.adat[0][1] = -std::sin(szogRad);
        m.adat[1][0] = std::sin(szogRad);
        m.adat[1][1] = std::cos(szogRad);
        m.adat[2][2] = 1.0;
        return m;
    }
};
```

## 17.5 Numerikus módszerek

### Numerikus integrálás (trapéz módszer):

```cpp
#include <functional>
#include <cmath>

// Numerikus integrálás trapéz módszerrel
double integralTrapez(std::function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;
    double osszeg = (f(a) + f(b)) / 2.0;
    
    for (int i = 1; i < n; i++) {
        osszeg += f(a + i * h);
    }
    
    return osszeg * h;
}

// Példa: ∫x² dx from 0 to 1 = 1/3
double negyzet(double x) {
    return x * x;
}

int main() {
    double eredmeny = integralTrapez(negyzet, 0.0, 1.0, 1000);
    std::cout << "∫x² dx = " << eredmeny << std::endl;  // ~0.333
    return 0;
}
```

### Deriválás numerikusan:

```cpp
// Numerikus deriválás
double derivalt(std::function<double(double)> f, double x, double h = 1e-7) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

// Példa: d/dx(x²) = 2x
int main() {
    double derivaltErtek = derivalt(negyzet, 3.0);
    std::cout << "d/dx(x²) at x=3: " << derivaltErtek << std::endl;  // ~6.0
    return 0;
}
```

### Newton-Raphson módszer (gyökkeresés):

```cpp
// Newton-Raphson módszer
double newtonRaphson(std::function<double(double)> f, 
                     std::function<double(double)> df,
                     double x0, double epsilon = 1e-7, int maxIter = 100) {
    double x = x0;
    
    for (int i = 0; i < maxIter; i++) {
        double fx = f(x);
        
        if (std::abs(fx) < epsilon) {
            return x;  // Megtaláltuk a gyököt
        }
        
        double dfx = df(x);
        if (dfx == 0) break;  // Nem lehet osztani nullával
        
        x = x - fx / dfx;
    }
    
    return x;  // Közelítés
}

// Példa: x² - 2 = 0 gyöke (√2)
int main() {
    auto f = [](double x) { return x * x - 2; };
    auto df = [](double x) { return 2 * x; };
    
    double gyok = newtonRaphson(f, df, 1.0);
    std::cout << "√2 ≈ " << gyok << std::endl;  // 1.414...
    
    return 0;
}
```

---

# 18. fejezet: DSP - Digitális Jelfeldolgozás

## 18.1 Bevezetés a DSP-be

A Digitális Jelfeldolgozás (DSP) analóg jelek digitális formában történő feldolgozása. Alkalmazások: audio, kép-, radar-, orvosi jelfeldolgozás.

### Alap fogalmak:

- **Mintavételezés**: Analóg jel → digitális sorozat
- **Kvantálás**: Értékek diszkrét szintekre kerekítése
- **FFT**: Gyors Fourier Transzformáció

## 18.2 Jel reprezentáció C++-ban

```cpp
#include <vector>
#include <complex>
#include <cmath>

// Diszkrét jel (minták sorozata)
using JelMinta = double;
using Jel = std::vector<JelMinta>;

// Komplex jel (FFT-hez)
using KomplexJel = std::vector<std::complex<double>>;

// Szinusz jel generálása
Jel szinuszJelGeneralo(double frekvencia, double mintavetelezes, double ido, double amplitudo = 1.0) {
    Jel jel;
    int mintakSzama = static_cast<int>(ido * mintavetelezes);
    
    for (int i = 0; i < mintakSzama; i++) {
        double t = i / mintavetelezes;
        jel.push_back(amplitudo * std::sin(2 * M_PI * frekvencia * t));
    }
    
    return jel;
}

// Négyzetjel generálása
Jel negyzetJelGeneralo(double frekvencia, double mintavetelezes, double ido, double amplitudo = 1.0) {
    Jel jel;
    int mintakSzama = static_cast<int>(ido * mintavetelezes);
    double periodus = 1.0 / frekvencia;
    
    for (int i = 0; i < mintakSzama; i++) {
        double t = i / mintavetelezes;
        double fázis = std::fmod(t, periodus) / periodus;
        jel.push_back(fázis < 0.5 ? amplitudo : -amplitudo);
    }
    
    return jel;
}

// Fűrészjel generálása
Jel fureszJelGeneralo(double frekvencia, double mintavetelezes, double ido, double amplitudo = 1.0) {
    Jel jel;
    int mintakSzama = static_cast<int>(ido * mintavetelezes);
    double periodus = 1.0 / frekvencia;
    
    for (int i = 0; i < mintakSzama; i++) {
        double t = i / mintavetelezes;
        double fázis = std::fmod(t, periodus) / periodus;
        jel.push_back(amplitudo * (2 * fázis - 1));
    }
    
    return jel;
}
```

## 18.3 Diszkrét Fourier Transzformáció (DFT)

```cpp
#include <complex>
#include <vector>
#include <cmath>

// Diszkrét Fourier Transzformáció
KomplexJel DFT(const Jel& jel) {
    int N = jel.size();
    KomplexJel spektrum(N);
    
    for (int k = 0; k < N; k++) {
        std::complex<double> osszeg(0, 0);
        
        for (int n = 0; n < N; n++) {
            double szog = -2.0 * M_PI * k * n / N;
            osszeg += jel[n] * std::complex<double>(std::cos(szog), std::sin(szog));
        }
        
        spektrum[k] = osszeg;
    }
    
    return spektrum;
}

// Inverz DFT
Jel IDFT(const KomplexJel& spektrum) {
    int N = spektrum.size();
    Jel jel(N);
    
    for (int n = 0; n < N; n++) {
        double osszeg = 0;
        
        for (int k = 0; k < N; k++) {
            double szog = 2.0 * M_PI * k * n / N;
            osszeg += spektrum[k].real() * std::cos(szog) 
                    - spektrum[k].imag() * std::sin(szog);
        }
        
        jel[n] = osszeg / N;
    }
    
    return jel;
}

// Amplitúdó spektrum kinyerése
std::vector<double> amplitudoSpektrum(const KomplexJel& spektrum) {
    std::vector<double> amplitudo(spektrum.size());
    
    for (size_t i = 0; i < spektrum.size(); i++) {
        amplitudo[i] = std::abs(spektrum[i]) / spektrum.size();
    }
    
    return amplitudo;
}

// Fázis spektrum kinyerése
std::vector<double> fazisSpektrum(const KomplexJel& spektrum) {
    std::vector<double> fazis(spektrum.size());
    
    for (size_t i = 0; i < spektrum.size(); i++) {
        fazis[i] = std::arg(spektrum[i]);
    }
    
    return fazis;
}
```

## 18.4 Gyors Fourier Transzformáció (FFT)

```cpp
// Cooley-Tukey FFT algoritmus (radix-2)
void FFT(KomplexJel& jel) {
    int N = jel.size();
    
    if (N <= 1) return;
    
    // Bit-reverzál permutáció
    for (int i = 1, j = 0; i < N; i++) {
        int bit = N >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            std::swap(jel[i], jel[j]);
    }
    
    // FFT számítás
    for (int len = 2; len <= N; len *= 2) {
        double szog = -2 * M_PI / len;
        std::complex<double> wn(std::cos(szog), std::sin(szog));
        
        for (int i = 0; i < N; i += len) {
            std::complex<double> w(1, 0);
            
            for (int j = 0; j < len / 2; j++) {
                std::complex<double> u = jel[i + j];
                std::complex<double> t = w * jel[i + j + len / 2];
                
                jel[i + j] = u + t;
                jel[i + j + len / 2] = u - t;
                
                w *= wn;
            }
        }
    }
}

// Inverz FFT
void IFFT(KomplexJel& jel) {
    int N = jel.size();
    
    // Konjugálás
    for (int i = 0; i < N; i++) {
        jel[i] = std::conj(jel[i]);
    }
    
    // FFT
    FFT(jel);
    
    // Konjugálás és normalizálás
    for (int i = 0; i < N; i++) {
        jel[i] = std::conj(jel[i]) / N;
    }
}

// Példa használat
int main() {
    // Jel létrehozása
    Jel jel = szinuszJelGeneralo(440.0, 44100.0, 0.1);  // 440 Hz, 0.1 mp
    
    // Komplex jellé alakítás
    KomplexJel komplexJel(jel.begin(), jel.end());
    
    // FFT számítás
    FFT(komplexJel);
    
    // Amplitúdó spektrum
    auto amplitudo = amplitudoSpektrum(komplexJel);
    
    // Frekvencia tengely
    double mintavetelezes = 44100.0;
    for (int i = 0; i < amplitudo.size() / 2; i++) {
        double frekvencia = i * mintavetelezes / amplitudo.size();
        std::cout << frekvencia << " Hz: " << amplitudo[i] << std::endl;
    }
    
    return 0;
}
```

## 18.5 Digitális szűrők

### Mozgóátlag szűrő (Low-pass):

```cpp
class MozgoatlagSzuro {
private:
    int ablakMeret;
    std::vector<double> puffter;
    int index;
    double osszeg;
    bool tele;
    
public:
    MozgoatlagSzuro(int meret) : ablakMeret(meret), index(0), osszeg(0), tele(false) {
        puffter.resize(meret, 0);
    }
    
    double szur(double bemenet) {
        // Régi érték kivonása
        if (tele) {
            osszeg -= puffter[index];
        }
        
        // Új érték hozzáadása
        puffter[index] = bemenet;
        osszeg += bemenet;
        
        // Index frissítése
        index = (index + 1) % ablakMeret;
        
        if (!tele && index == 0) {
            tele = true;
        }
        
        // Átlag visszaadása
        return osszeg / (tele ? ablakMeret : index);
    }
    
    void reset() {
        std::fill(puffter.begin(), puffter.end(), 0);
        index = 0;
        osszeg = 0;
        tele = false;
    }
};
```

### Exponenciális mozgóátlag (EMA):

```cpp
class EMASzuro {
private:
    double alpha;  // Súlyozó tényező (0 < alpha <= 1)
    double ertek;
    bool inicializalt;
    
public:
    EMASzuro(double alpha) : alpha(alpha), ertek(0), inicializalt(false) {}
    
    double szur(double bemenet) {
        if (!inicializalt) {
            ertek = bemenet;
            inicializalt = true;
        } else {
            ertek = alpha * bemenet + (1 - alpha) * ertek;
        }
        return ertek;
    }
    
    void reset(double kezdeti = 0) {
        ertek = kezdeti;
        inicializalt = true;
    }
};
```

### IIR szűrő (egyszerűsített):

```cpp
class IIRSzuro {
private:
    // Szűrő együtthatók
    double b0, b1, b2;  // Numerátor
    double a1, a2;      // Nevező (a0 = 1)
    
    // Korábbi értékek
    double x1, x2;  // Korábbi bemenetek
    double y1, y2;  // Korábbi kimenetek
    
public:
    IIRSzuro(double b0, double b1, double b2, double a1, double a2)
        : b0(b0), b1(b1), b2(b2), a1(a1), a2(a2),
          x1(0), x2(0), y1(0), y2(0) {}
    
    // y[n] = b0*x[n] + b1*x[n-1] + b2*x[n-2] - a1*y[n-1] - a2*y[n-2]
    double szur(double x) {
        double y = b0 * x + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;
        
        // Eltolás
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
        
        return y;
    }
    
    void reset() {
        x1 = x2 = y1 = y2 = 0;
    }
};

// Aluláteresztő szűrő tervezése
IIRSzuro alulateresztoSzuro(double cutoffFreq, double sampleRate) {
    double RC = 1.0 / (2 * M_PI * cutoffFreq);
    double dt = 1.0 / sampleRate;
    double alpha = dt / (RC + dt);
    
    // Egyszerűsített együtthatók
    return IIRSzuro(alpha, 0, 0, alpha - 1, 0);
}
```

### FIR szűrő:

```cpp
class FIRSzuro {
private:
    std::vector<double> egyutthatok;
    std::vector<double> puffter;
    int index;
    
public:
    FIRSzuro(const std::vector<double>& egyutthatok)
        : egyutthatok(egyutthatok), index(0) {
        puffter.resize(egyutthatok.size(), 0);
    }
    
    double szur(double bemenet) {
        puffter[index] = bemenet;
        
        double kimenet = 0;
        for (size_t i = 0; i < egyutthatok.size(); i++) {
            int puffIndex = (index - i + egyutthatok.size()) % egyutthatok.size();
            kimenet += egyutthatok[i] * puffter[puffIndex];
        }
        
        index = (index + 1) % egyutthatok.size();
        return kimenet;
    }
};

// Ablakozott sinc szűrő tervezése
std::vector<double> sincSzuro(double cutoffFreq, double sampleRate, int meret) {
    std::vector<double> egyutthatok(meret);
    double fc = cutoffFreq / sampleRate;
    int kozep = meret / 2;
    
    // Hamming ablak
    for (int i = 0; i < meret; i++) {
        double n = i - kozep;
        
        if (n == 0) {
            egyutthatok[i] = 2 * fc;
        } else {
            egyutthatok[i] = std::sin(2 * M_PI * fc * n) / (M_PI * n);
        }
        
        // Hamming ablak alkalmazása
        egyutthatok[i] *= 0.54 - 0.46 * std::cos(2 * M_PI * i / (meret - 1));
    }
    
    // Normalizálás
    double osszeg = 0;
    for (double c : egyutthatok) osszeg += c;
    for (double& c : egyutthatok) c /= osszeg;
    
    return egyutthatok;
}
```

## 18.6 Konvolúció és korreláció

```cpp
// Diszkrét konvolúció
Jel konvolucio(const Jel& jel, const std::vector<double>& kernel) {
    int jelMeret = jel.size();
    int kernelMeret = kernel.size();
    int kimenetMeret = jelMeret + kernelMeret - 1;
    
    Jel kimenet(kimenetMeret, 0);
    
    for (int n = 0; n < kimenetMeret; n++) {
        for (int k = 0; k < kernelMeret; k++) {
            int jelIndex = n - k;
            if (jelIndex >= 0 && jelIndex < jelMeret) {
                kimenet[n] += jel[jelIndex] * kernel[k];
            }
        }
    }
    
    return kimenet;
}

// Korreláció (hasonlóság mérés)
double korrelacio(const Jel& jel1, const Jel& jel2) {
    int meret = std::min(jel1.size(), jel2.size());
    double osszeg1 = 0, osszeg2 = 0, szorzatOsszeg = 0;
    
    for (int i = 0; i < meret; i++) {
        osszeg1 += jel1[i];
        osszeg2 += jel2[i];
        szorzatOsszeg += jel1[i] * jel2[i];
    }
    
    double atlag1 = osszeg1 / meret;
    double atlag2 = osszeg2 / meret;
    
    double szoronas1 = 0, szoronas2 = 0, kovariancia = 0;
    for (int i = 0; i < meret; i++) {
        kovariancia += (jel1[i] - atlag1) * (jel2[i] - atlag2);
        szoronas1 += std::pow(jel1[i] - atlag1, 2);
        szoronas2 += std::pow(jel2[i] - atlag2, 2);
    }
    
    return kovariancia / std::sqrt(szoronas1 * szoronas2);
}
```

## 18.7 Hangfeldolgozás

### WAV fájl olvasás/írás (egyszerűsített):

```cpp
#include <fstream>
#include <cstdint>

#pragma pack(push, 1)
struct WAVHeader {
    char riff[4] = "RIFF";
    uint32_t fileSize;
    char wave[4] = "WAVE";
    char fmt[4] = "fmt ";
    uint32_t fmtSize = 16;
    uint16_t audioFormat = 1;  // PCM
    uint16_t numChannels = 1;
    uint32_t sampleRate = 44100;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample = 16;
    char data[4] = "data";
    uint32_t dataSize;
};
#pragma pack(pop)

class WavFajl {
public:
    static Jel olvasWAV(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        WAVHeader header;
        
        file.read(reinterpret_cast<char*>(&header), sizeof(header));
        
        Jel jel;
        int16_t minta;
        
        while (file.read(reinterpret_cast<char*>(&minta), sizeof(minta))) {
            jel.push_back(minta / 32768.0);  // Normalizálás -1..1 tartományba
        }
        
        return jel;
    }
    
    static void irWAV(const std::string& filename, const Jel& jel, int sampleRate = 44100) {
        std::ofstream file(filename, std::ios::binary);
        
        WAVHeader header;
        header.numChannels = 1;
        header.sampleRate = sampleRate;
        header.bitsPerSample = 16;
        header.blockAlign = header.numChannels * header.bitsPerSample / 8;
        header.byteRate = header.sampleRate * header.blockAlign;
        header.dataSize = jel.size() * header.blockAlign;
        header.fileSize = header.dataSize + sizeof(WAVHeader) - 8;
        
        file.write(reinterpret_cast<char*>(&header), sizeof(header));
        
        for (double minta : jel) {
            int16_t normalizalt = static_cast<int16_t>(minta * 32767);
            file.write(reinterpret_cast<char*>(&normalizalt), sizeof(normalizalt));
        }
    }
};
```

### Hangerő szabályozás:

```cpp
Jel hangeroSzabalyozas(const Jel& jel, double gain) {
    Jel kimenet;
    kimenet.reserve(jel.size());
    
    for (double minta : jel) {
        // Klippelés elkerülése
        double ertek = minta * gain;
        ertek = std::max(-1.0, std::min(1.0, ertek));
        kimenet.push_back(ertek);
    }
    
    return kimenet;
}
```

### Normalizálás:

```cpp
Jel normalizalas(const Jel& jel) {
    // Maximum abszolút érték keresése
    double maxErtek = 0;
    for (double minta : jel) {
        maxErtek = std::max(maxErtek, std::abs(minta));
    }
    
    if (maxErtek == 0) return jel;
    
    // Normalizálás 0.95-re (headroom)
    double gain = 0.95 / maxErtek;
    return hangeroSzabalyozas(jel, gain);
}
```

---

# 19. fejezet: CLI programozás és multi-language támogatás

## 19.1 CLI (Command Line Interface) alapok

### Egyszerű CLI program:

```cpp
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::cout << "Program neve: " << argv[0] << std::endl;
    std::cout << "Paraméterek száma: " << argc - 1 << std::endl;
    
    for (int i = 1; i < argc; i++) {
        std::cout << "Paraméter " << i << ": " << argv[i] << std::endl;
    }
    
    return 0;
}
```

## 19.2 Argumentumok feldolgozása

### Manuális argumentum parsing:

```cpp
#include <iostream>
#include <string>
#include <cstring>

struct CLIArgs {
    std::string inputFile;
    std::string outputFile;
    bool verbose = false;
    bool help = false;
    int threads = 1;
};

CLIArgs parseArgs(int argc, char* argv[]) {
    CLIArgs args;
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "-h" || arg == "--help") {
            args.help = true;
        }
        else if (arg == "-v" || arg == "--verbose") {
            args.verbose = true;
        }
        else if (arg == "-i" || arg == "--input") {
            if (i + 1 < argc) {
                args.inputFile = argv[++i];
            }
        }
        else if (arg == "-o" || arg == "--output") {
            if (i + 1 < argc) {
                args.outputFile = argv[++i];
            }
        }
        else if (arg == "-t" || arg == "--threads") {
            if (i + 1 < argc) {
                args.threads = std::stoi(argv[++i]);
            }
        }
    }
    
    return args;
}

void printHelp(const char* programName) {
    std::cout << "Használat: " << programName << " [opciók]\n"
              << "\nOpciók:\n"
              << "  -h, --help           Súgó megjelenítése\n"
              << "  -v, --verbose        Részletes kimenet\n"
              << "  -i, --input <fájl>   Bemeneti fájl\n"
              << "  -o, --output <fájl>  Kimeneti fájl\n"
              << "  -t, --threads <n>    Szálak száma (alap: 1)\n";
}

int main(int argc, char* argv[]) {
    CLIArgs args = parseArgs(argc, argv);
    
    if (args.help) {
        printHelp(argv[0]);
        return 0;
    }
    
    if (args.verbose) {
        std::cout << "Bemenet: " << args.inputFile << std::endl;
        std::cout << "Kimenet: " << args.outputFile << std::endl;
        std::cout << "Szálak: " << args.threads << std::endl;
    }
    
    return 0;
}
```

## 19.3 CLI könyvtárak használata

### CLI11 könyvtár (népszerű modern CLI library):

```cpp
// CLI11 használata (https://github.com/CLIUtils/CLI11)
#include <CLI/CLI.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    CLI::App app("CLI Példa Program");
    
    // Opciók
    std::string inputFile;
    app.add_option("-i,--input", inputFile, "Bemeneti fájl")->required();
    
    std::string outputFile = "output.txt";
    app.add_option("-o,--output", outputFile, "Kimeneti fájl");
    
    bool verbose = false;
    app.add_flag("-v,--verbose", verbose, "Részletes kimenet");
    
    int threads = 1;
    app.add_option("-t,--threads", threads, "Szálak száma")
       ->check(CLI::Range(1, 32));
    
    // Parancsok (subcommands)
    auto* convert = app.add_subcommand("convert", "Fájl konvertálás");
    std::string format;
    convert->add_option("-f,--format", format, "Cél formátum");
    
    auto* process = app.add_subcommand("process", "Adat feldolgozás");
    bool fast = false;
    process->add_flag("--fast", fast, "Gyors mód");
    
    CLI11_PARSE(app, argc, argv);
    
    if (convert->parsed()) {
        std::cout << "Konvertálás: " << inputFile << " -> " << outputFile << std::endl;
        std::cout << "Formátum: " << format << std::endl;
    }
    
    if (process->parsed()) {
        std::cout << "Feldolgozás..." << std::endl;
        std::cout << "Gyors mód: " << (fast ? "BE" : "KI") << std::endl;
    }
    
    return 0;
}
```

## 19.4 Színes konzol kimenet

### ANSI escape kódok:

```cpp
#include <iostream>
#include <string>

// ANSI színek
namespace Colors {
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
    const std::string WHITE = "\033[37m";
    
    const std::string BOLD = "\033[1m";
    const std::string DIM = "\033[2m";
    const std::string UNDERLINE = "\033[4m";
    
    // Háttérszínek
    const std::string BG_RED = "\033[41m";
    const std::string BG_GREEN = "\033[42m";
    const std::string BG_BLUE = "\033[44m";
}

void szinesKiiras() {
    std::cout << Colors::RED << "Piros szöveg" << Colors::RESET << std::endl;
    std::cout << Colors::GREEN << "Zöld szöveg" << Colors::RESET << std::endl;
    std::cout << Colors::BLUE << "Kék szöveg" << Colors::RESET << std::endl;
    std::cout << Colors::BOLD << "Félkövér szöveg" << Colors::RESET << std::endl;
    std::cout << Colors::YELLOW << Colors::BG_BLUE << "Sárga szöveg kék háttérrel" 
              << Colors::RESET << std::endl;
}

// Windows konzol színek (Windows 10+)
#ifdef _WIN32
#include <windows.h>

void WindowsSzinekEngedelyezese() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
#endif
```

### Haladó konzol formázás:

```cpp
#include <iomanip>
#include <iostream>

void formazottKiiras() {
    // Oszlopok
    std::cout << std::left << std::setw(15) << "Név"
              << std::right << std::setw(10) << "Életkor"
              << std::right << std::setw(15) << "Város" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    
    std::cout << std::left << std::setw(15) << "János"
              << std::right << std::setw(10) << 25
              << std::right << std::setw(15) << "Budapest" << std::endl;
    
    std::cout << std::left << std::setw(15) << "Éva"
              << std::right << std::setw(10) << 30
              << std::right << std::setw(15) << "Debrecen" << std::endl;
    
    // Tizedesjegyek
    double pi = 3.14159265359;
    std::cout << std::fixed << std::setprecision(4) << "PI: " << pi << std::endl;
    
    // Hexadecimális
    int szam = 255;
    std::cout << "Hex: " << std::hex << szam << std::endl;
    std::cout << "Dec: " << std::dec << szam << std::endl;
}
```

## 19.5 Haladásjelző (Progress Bar)

```cpp
#include <iostream>
#include <thread>
#include <chrono>

class Progressbar {
private:
    int szlessseg;
    
public:
    Progressbar(int szlesseg = 50) : szlessseg(szlesseg) {}
    
    void update(double percent) {
        int kitoltott = static_cast<int>(percent * szlessseg);
        
        std::cout << "\r[";
        
        for (int i = 0; i < szlessseg; i++) {
            if (i < kitoltott) {
                std::cout << "=";
            } else {
                std::cout << " ";
            }
        }
        
        std::cout << "] " << std::fixed << std::setprecision(1) 
                  << (percent * 100) << "%";
        std::cout.flush();
        
        if (percent >= 1.0) {
            std::cout << std::endl;
        }
    }
};

// Példa használat
void haladasPelda() {
    Progressbar pb(50);
    
    for (int i = 0; i <= 100; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        pb.update(i / 100.0);
    }
}
```

## 19.6 Multi-language (többnyelvű) támogatás

### gettext alapú internacionalizáció:

```cpp
// main.cpp
#include <iostream>
#include <libintl.h>
#include <locale.h>
#include <string>

#define _(String) gettext(String)

int main(int argc, char* argv[]) {
    // Locale beállítása
    setlocale(LC_ALL, "");
    bindtextdomain("myapp", "./locale");
    textdomain("myapp");
    
    // Nyelv beállítása környezeti változóból vagy paraméterből
    std::string lang = "en";
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg.find("--lang=") == 0) {
            lang = arg.substr(7);
        }
    }
    
    setlocale(LC_ALL, lang.c_str());
    
    // Használat
    std::cout << _("Üdvözöllek!") << std::endl;
    std::cout << _("Ez egy többnyelvű alkalmazás.") << std::endl;
    
    return 0;
}
```

### PO fájlok (fordítások):

```po
# locale/hu_HU/LC_MESSAGES/myapp.po
msgid ""
msgstr ""
"Project-Id-Version: MyApp 1.0\n"
"Language: hu_HU\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=UTF-8\n"

msgid "Üdvözöllek!"
msgstr "Welcome!"

msgid "Ez egy többnyelvű alkalmazás."
msgstr "This is a multilingual application."

msgid "Hiba történt."
msgstr "An error occurred."
```

### Saját többnyelvű rendszer:

```cpp
// i18n.h
#ifndef I18N_H
#define I18N_H

#include <string>
#include <map>
#include <fstream>
#include <sstream>

class I18n {
private:
    static I18n* instance;
    std::map<std::string, std::string> forditasok;
    std::string jelenlegiNyelv;
    
    I18n() {}
    
public:
    static I18n* getInstance() {
        if (!instance) {
            instance = new I18n();
        }
        return instance;
    }
    
    void betoltes(const std::string& nyelv, const std::string& fajlnev) {
        jelenlegiNyelv = nyelv;
        forditasok.clear();
        
        std::ifstream file(fajlnev);
        std::string sor;
        
        while (std::getline(file, sor)) {
            if (sor.empty() || sor[0] == '#') continue;
            
            size_t egyenlo = sor.find('=');
            if (egyenlo != std::string::npos) {
                std::string kulcs = sor.substr(0, egyenlo);
                std::string ertek = sor.substr(egyenlo + 1);
                forditasok[kulcs] = ertek;
            }
        }
    }
    
    std::string tr(const std::string& kulcs) {
        auto it = forditasok.find(kulcs);
        if (it != forditasok.end()) {
            return it->second;
        }
        return kulcs;  // Ha nincs fordítás, visszaadjuk a kulcsot
    }
    
    std::string operator()(const std::string& kulcs) {
        return tr(kulcs);
    }
};

I18n* I18n::instance = nullptr;

// Makró a kényelmes használathoz
#define TR(key) I18n::getInstance()->tr(key)

#endif // I18N_H
```

### Nyelvi fájlok:

```ini
# lang/hu.ini
greeting=Üdvözöllek!
welcome=Üdvözöljük az alkalmazásban
error=Hiba történt
success=Sikeres művelet
exit=Kilépés
help=Súgó
input_file=Bemeneti fájl
output_file=Kimeneti fájl
processing=Feldolgozás...
done=Kész!
```

```ini
# lang/en.ini
greeting=Welcome!
welcome=Welcome to the application
error=An error occurred
success=Operation successful
exit=Exit
help=Help
input_file=Input file
output_file=Output file
processing=Processing...
done=Done!
```

```ini
# lang/de.ini
greeting=Willkommen!
welcome=Willkommen in der Anwendung
error=Ein Fehler ist aufgetreten
success=Erfolgreich
exit=Beenden
help=Hilfe
input_file=Eingabedatei
output_file=Ausgabedatei
processing=Verarbeitung...
done=Fertig!
```

### Használat:

```cpp
// main.cpp
#include "i18n.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // Nyelv meghatározása
    std::string nyelv = "hu";
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--lang=en") nyelv = "en";
        else if (arg == "--lang=de") nyelv = "de";
    }
    
    // Nyelvi fájl betöltése
    I18n::getInstance()->betoltes(nyelv, "lang/" + nyelv + ".ini");
    
    // Fordított szövegek használata
    std::cout << TR("greeting") << std::endl;
    std::cout << TR("welcome") << std::endl;
    
    return 0;
}
```

## 19.7 CLI best practices más nyelvekből

### Rust-stílusú CLI (clap könyvtár mintára):

```cpp
// Modern, típusbiztonságos CLI
#include <string>
#include <optional>
#include <variant>

enum class LogLevel {
    Debug,
    Info,
    Warning,
    Error
};

struct Config {
    std::string inputFile;
    std::optional<std::string> outputFile;
    LogLevel logLevel = LogLevel::Info;
    int threads = 1;
    bool dryRun = false;
};

class CLI {
private:
    Config config;
    
public:
    Config parse(int argc, char* argv[]) {
        // Típusbiztonságos parsing
        // ... implementáció ...
        return config;
    }
};
```

### Python-stílusú CLI (argparse mintára):

```cpp
// Python argparse stílusú CLI
#include <iostream>
#include <vector>

class ArgumentParser {
private:
    std::string programName;
    std::string description;
    std::vector<std::string> arguments;
    
public:
    ArgumentParser(const std::string& name, const std::string& desc)
        : programName(name), description(desc) {}
    
    void addArgument(const std::string& name, const std::string& help) {
        arguments.push_back(name);
    }
    
    void printHelp() {
        std::cout << "usage: " << programName << " [options]\n\n";
        std::cout << description << "\n\n";
        std::cout << "Arguments:\n";
        for (const auto& arg : arguments) {
            std::cout << "  " << arg << "\n";
        }
    }
};
```

### Node.js-stílusú CLI (commander mintára):

```cpp
// Commander.js stílusú CLI
#include <functional>
#include <map>

class Commander {
private:
    std::map<std::string, std::function<void()>> parancsok;
    
public:
    Commander& command(const std::string& name, std::function<void()> callback) {
        parancsok[name] = callback;
        return *this;
    }
    
    void parse(int argc, char* argv[]) {
        if (argc > 1) {
            std::string parancs = argv[1];
            auto it = parancsok.find(parancs);
            if (it != parancsok.end()) {
                it->second();
            }
        }
    }
};

// Használat
int main(int argc, char* argv[]) {
    Commander cli;
    
    cli.command("start", []() {
        std::cout << "Indítás..." << std::endl;
    })
    .command("stop", []() {
        std::cout << "Leállítás..." << std::endl;
    })
    .command("status", []() {
        std::cout << "Állapot lekérdezése..." << std::endl;
    });
    
    cli.parse(argc, argv);
    
    return 0;
}
```

## 19.8 Teljes CLI alkalmazás példa

```cpp
// Teljes CLI alkalmazás minden funkcióval
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "i18n.h"
#include "colors.h"

class CLIAlkalmazas {
private:
    std::map<std::string, bool> flagok;
    std::map<std::string, std::string> opcioK;
    std::vector<std::string> poziciosArgok;
    
public:
    void parse(int argc, char* argv[]) {
        for (int i = 1; i < argc; i++) {
            std::string arg = argv[i];
            
            if (arg[0] == '-') {
                if (arg[1] == '-') {
                    // Hosszú opció
                    size_t egyenlo = arg.find('=');
                    if (egyenlo != std::string::npos) {
                        opcioK[arg.substr(2, egyenlo - 2)] = arg.substr(egyenlo + 1);
                    } else {
                        flagok[arg.substr(2)] = true;
                    }
                } else {
                    // Rövid opció
                    flagok[arg.substr(1)] = true;
                }
            } else {
                poziciosArgok.push_back(arg);
            }
        }
    }
    
    bool hasFlag(const std::string& name) {
        return flagok.count(name) > 0;
    }
    
    std::string getOption(const std::string& name, const std::string& defaultVal = "") {
        auto it = opcioK.find(name);
        return (it != opcioK.end()) ? it->second : defaultVal;
    }
    
    void futtat() {
        // Nyelv beállítása
        std::string lang = getOption("lang", "hu");
        I18n::getInstance()->betoltes(lang, "lang/" + lang + ".ini");
        
        // Súgó
        if (hasFlag("help") || hasFlag("h")) {
            std::cout << Colors::BOLD << TR("greeting") << Colors::RESET << std::endl;
            std::cout << "Használat: program [opciók] [fájlok...]\n\n";
            std::cout << "Opciók:\n";
            std::cout << "  -h, --help        Súgó megjelenítése\n";
            std::cout << "  -v, --verbose     Részletes kimenet\n";
            std::cout << "  --lang=<nyelv>    Nyelv beállítása (hu/en/de)\n";
            std::cout << "  -o, --output=<fájl>  Kimeneti fájl\n";
            return;
        }
        
        // Verzió
        if (hasFlag("version")) {
            std::cout << "CLI Alkalmazás v1.0.0\n";
            return;
        }
        
        // Fő funkció
        if (hasFlag("verbose")) {
            std::cout << Colors::CYAN << "[DEBUG] " << Colors::RESET;
            std::cout << "Verbose mód bekapcsolva\n";
        }
        
        std::cout << TR("processing") << std::endl;
        
        // Progress bar
        Progressbar pb(40);
        for (int i = 0; i <= 100; i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            pb.update(i / 100.0);
        }
        
        std::cout << Colors::GREEN << TR("done") << Colors::RESET << std::endl;
    }
};

int main(int argc, char* argv[]) {
    CLIAlkalmazas cli;
    cli.parse(argc, argv);
    cli.futtat();
    
    return 0;
}
```

---

# 20. fejezet: Hálózati programozás C++-ban

## 20.1 Bevezetés a hálózati programozásba

A hálózati programozás lehetővé teszi számítógépek közötti kommunikációt. Két fő típusa:
- **Kliens-szerver architektúra**
- **Peer-to-peer (P2P)**

### Hálózati protokollok:

| Protokoll | Leírás |
|-----------|--------|
| TCP | Megbízható, kapcsolatorientált |
| UDP | Gyors, kapcsolat nélküli |
| HTTP/HTTPS | Web kommunikáció |
| WebSocket | Kétirányú kommunikáció |

## 20.2 Socket programozás alapok

### TCP Szerver (POSIX - Linux/Mac):

```cpp
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>

const int PORT = 8080;
const int BUFFER_SIZE = 1024;

class TCPSzerver {
private:
    int serverFd;
    struct sockaddr_in address;
    
public:
    TCPSzerver() : serverFd(-1) {}
    
    bool indit(int port = PORT) {
        // Socket létrehozása
        serverFd = socket(AF_INET, SOCK_STREAM, 0);
        if (serverFd < 0) {
            perror("Socket hiba");
            return false;
        }
        
        // Socket opciók (újrahasznosítás)
        int opt = 1;
        setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
        
        // Cím beállítása
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port);
        
        // Bind
        if (bind(serverFd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            perror("Bind hiba");
            return false;
        }
        
        // Listen
        if (listen(serverFd, 3) < 0) {
            perror("Listen hiba");
            return false;
        }
        
        std::cout << "Szerver indítva a " << port << " porton..." << std::endl;
        return true;
    }
    
    void futtat() {
        struct sockaddr_in clientAddr;
        socklen_t clientLen = sizeof(clientAddr);
        
        while (true) {
            // Kliens fogadása
            int clientFd = accept(serverFd, (struct sockaddr*)&clientAddr, &clientLen);
            if (clientFd < 0) {
                perror("Accept hiba");
                continue;
            }
            
            char buffer[BUFFER_SIZE] = {0};
            read(clientFd, buffer, BUFFER_SIZE);
            std::cout << "Üzenet érkezett: " << buffer << std::endl;
            
            // Válasz küldése
            std::string valasz = "Köszönöm az üzenetet!";
            send(clientFd, valasz.c_str(), valasz.length(), 0);
            
            close(clientFd);
        }
    }
    
    ~TCPSzerver() {
        if (serverFd >= 0) {
            close(serverFd);
        }
    }
};

int main() {
    TCPSzerver szerver;
    if (szerver.indit()) {
        szerver.futtat();
    }
    return 0;
}
```

### TCP Kliens (POSIX):

```cpp
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>

const int PORT = 8080;
const char* IP = "127.0.0.1";

class TCPKliens {
private:
    int clientFd;
    struct sockaddr_in serverAddr;
    
public:
    TCPKliens() : clientFd(-1) {}
    
    bool csatlakozas(const char* ip = IP, int port = PORT) {
        // Socket létrehozása
        clientFd = socket(AF_INET, SOCK_STREAM, 0);
        if (clientFd < 0) {
            perror("Socket hiba");
            return false;
        }
        
        // Szerver cím beállítása
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        
        if (inet_pton(AF_INET, ip, &serverAddr.sin_addr) <= 0) {
            perror("Cím konverzió hiba");
            return false;
        }
        
        // Csatlakozás
        if (connect(clientFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
            perror("Connect hiba");
            return false;
        }
        
        std::cout << "Csatlakozva a szerverhez!" << std::endl;
        return true;
    }
    
    bool kuldes(const std::string& uzenet) {
        return send(clientFd, uzenet.c_str(), uzenet.length(), 0) >= 0;
    }
    
    std::string fogadas() {
        char buffer[1024] = {0};
        int bytes = read(clientFd, buffer, sizeof(buffer) - 1);
        if (bytes > 0) {
            return std::string(buffer, bytes);
        }
        return "";
    }
    
    void bezaras() {
        if (clientFd >= 0) {
            close(clientFd);
        }
    }
    
    ~TCPKliens() {
        bezaras();
    }
};

int main() {
    TCPKliens kliens;
    
    if (kliens.csatlakozas()) {
        kliens.kuldes("Szia Szerver!");
        std::string valasz = kliens.fogadas();
        std::cout << "Válasz: " << valasz << std::endl;
    }
    
    return 0;
}
```

## 20.3 Windows Socket (Winsock)

```cpp
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

const int PORT = 8080;

class WinsockSzerver {
private:
    SOCKET serverSocket;
    WSADATA wsaData;
    
public:
    WinsockSzerver() : serverSocket(INVALID_SOCKET) {}
    
    bool indit() {
        // Winsock inicializálás
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            std::cerr << "WSAStartup hiba!" << std::endl;
            return false;
        }
        
        // Socket létrehozása
        serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (serverSocket == INVALID_SOCKET) {
            std::cerr << "Socket hiba: " << WSAGetLastError() << std::endl;
            return false;
        }
        
        // Cím beállítása
        sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(PORT);
        
        // Bind
        if (bind(serverSocket, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
            std::cerr << "Bind hiba: " << WSAGetLastError() << std::endl;
            return false;
        }
        
        // Listen
        if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
            std::cerr << "Listen hiba: " << WSAGetLastError() << std::endl;
            return false;
        }
        
        std::cout << "Szerver indítva a " << PORT << " porton..." << std::endl;
        return true;
    }
    
    void futtat() {
        sockaddr_in clientAddr;
        int clientAddrLen = sizeof(clientAddr);
        
        while (true) {
            SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddrLen);
            if (clientSocket == INVALID_SOCKET) {
                std::cerr << "Accept hiba: " << WSAGetLastError() << std::endl;
                continue;
            }
            
            char buffer[1024] = {0};
            recv(clientSocket, buffer, sizeof(buffer), 0);
            std::cout << "Üzenet: " << buffer << std::endl;
            
            const char* valasz = "Köszönöm!";
            send(clientSocket, valasz, strlen(valasz), 0);
            
            closesocket(clientSocket);
        }
    }
    
    ~WinsockSzerver() {
        if (serverSocket != INVALID_SOCKET) {
            closesocket(serverSocket);
        }
        WSACleanup();
    }
};
```

## 20.4 UDP kommunikáció

### UDP Szerver:

```cpp
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

class UDPSzerver {
private:
    int socketFd;
    struct sockaddr_in addr;
    
public:
    UDPSzerver(int port = 9090) {
        socketFd = socket(AF_INET, SOCK_DGRAM, 0);
        
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(port);
        
        bind(socketFd, (struct sockaddr*)&addr, sizeof(addr));
    }
    
    void fogad() {
        char buffer[1024];
        struct sockaddr_in clientAddr;
        socklen_t clientLen = sizeof(clientAddr);
        
        int bytes = recvfrom(socketFd, buffer, sizeof(buffer), 0,
                            (struct sockaddr*)&clientAddr, &clientLen);
        
        if (bytes > 0) {
            buffer[bytes] = '\0';
            std::cout << "Üzenet: " << buffer << std::endl;
            
            // Válasz küldése
            const char* valasz = "Vettem!";
            sendto(socketFd, valasz, strlen(valasz), 0,
                  (struct sockaddr*)&clientAddr, clientLen);
        }
    }
    
    ~UDPSzerver() {
        close(socketFd);
    }
};
```

### UDP Kliens:

```cpp
class UDPKliens {
private:
    int socketFd;
    struct sockaddr_in serverAddr;
    
public:
    UDPKliens(const char* ip, int port) {
        socketFd = socket(AF_INET, SOCK_DGRAM, 0);
        
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        inet_pton(AF_INET, ip, &serverAddr.sin_addr);
    }
    
    void kuldes(const std::string& uzenet) {
        sendto(socketFd, uzenet.c_str(), uzenet.length(), 0,
              (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    }
    
    std::string fogadas() {
        char buffer[1024];
        int bytes = recv(socketFd, buffer, sizeof(buffer), 0);
        if (bytes > 0) {
            return std::string(buffer, bytes);
        }
        return "";
    }
};
```

## 20.5 HTTP Kliens egyszerű implementáció

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <arpa/inet.h>

class HTTPKliens {
private:
    int socketFd;
    
public:
    bool csatlakozas(const std::string& host, int port = 80) {
        socketFd = socket(AF_INET, SOCK_STREAM, 0);
        
        struct hostent* server = gethostbyname(host.c_str());
        if (!server) {
            std::cerr << "Host nem található: " << host << std::endl;
            return false;
        }
        
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        memcpy(&addr.sin_addr, server->h_addr, server->h_length);
        
        return connect(socketFd, (struct sockaddr*)&addr, sizeof(addr)) >= 0;
    }
    
    std::string GET(const std::string& path) {
        std::stringstream request;
        request << "GET " << path << " HTTP/1.1\r\n";
        request << "Host: localhost\r\n";
        request << "Connection: close\r\n\r\n";
        
        send(socketFd, request.str().c_str(), request.str().length(), 0);
        
        std::string valasz;
        char buffer[1024];
        int bytes;
        
        while ((bytes = read(socketFd, buffer, sizeof(buffer))) > 0) {
            valasz.append(buffer, bytes);
        }
        
        close(socketFd);
        return valasz;
    }
};

// Használat
int main() {
    HTTPKliens http;
    if (http.csatlakozas("example.com", 80)) {
        std::string valasz = http.GET("/");
        std::cout << valasz << std::endl;
    }
    return 0;
}
```

## 20.6 Többklienses szerver (szálkezeléssel)

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>
#include <arpa/inet.h>

void kezeloKliens(int clientSocket) {
    char buffer[1024];
    
    while (true) {
        int bytes = read(clientSocket, buffer, sizeof(buffer));
        if (bytes <= 0) break;
        
        buffer[bytes] = '\0';
        std::cout << "Klienstől: " << buffer << std::endl;
        
        // Üzenet visszaküldése mindenkinek (broadcast)
        // ... implementáció ...
    }
    
    close(clientSocket);
}

class TobbkliensesSzerver {
private:
    int serverSocket;
    std::vector<std::thread> kliensek;
    
public:
    void indit(int port = 8080) {
        // ... socket létrehozás, bind, listen ...
        
        while (true) {
            int clientSocket = accept(serverSocket, NULL, NULL);
            
            // Új szál indítása a kliens kezelésére
            kliensek.emplace_back(kezeloKliens, clientSocket);
        }
    }
};
```

## 20.7 Modern C++ hálózati könyvtárak

### Boost.Asio (keresztplatform):

```cpp
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

void szerverFuttatas() {
    boost::asio::io_context io_context;
    
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8080));
    
    while (true) {
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        
        // Kezelés
        char buffer[1024];
        socket.read_some(boost::asio::buffer(buffer));
        socket.write_some(boost::asio::buffer("OK", 2));
    }
}

// Async szerver
class AsyncSzerver {
private:
    tcp::acceptor acceptor;
    tcp::socket socket;
    
public:
    AsyncSzerver(boost::asio::io_context& io, short port)
        : acceptor(io, tcp::endpoint(tcp::v4(), port))
        , socket(io) {
        fogadas();
    }
    
    void fogadas() {
        acceptor.async_accept(socket,
            [this](boost::system::error_code ec) {
                if (!ec) {
                    // Kezelés...
                }
                fogadas();  // Következő kliens fogadása
            });
    }
};
```

---

# 21. fejezet: Kódelemzés és reverse engineering

## 21.1 Ismeretlen kód elemzése

Gyakori helyzet: van egy kód, amit nem te írtál, és nem érted mit csinál.

### Lépések a kódelemzéshez:

1. **Futtasd a programot** - nézd meg mit csinál
2. **Olvasd át a fő függvényt** (main)
3. **Keresd a kulcsfontosságú változókat**
4. **Kövesd az adatfolyamot**
5. **Írj kiírásokat (debug print)**

## 21.2 Változónevek jelentésének kitalálása

### Példa: Rosszul elnevezett változók

```cpp
// MIT CSINÁL EZ A KÓD?
int f(int x, int y) {
    int z = 0;
    while (y > 0) {
        if (y & 1) {
            z += x;
        }
        x <<= 1;
        y >>= 1;
    }
    return z;
}
```

**Elemzés lépésről lépésre:**

1. `y & 1` - bitenkénti ÉS → utolsó bit ellenőrzése
2. `x <<= 1` - balra shift → szorzás 2-vel
3. `y >>= 1` - jobbra shift → osztás 2-vel
4. `z += x` - összegzés

**Következtetés:** Ez egy **szorzás bitműveletekkel**!

```cpp
// ÁTNEVEZVE - érthető verzió
int szorzasBitmuveletekkel(int szorzando, int szorzo) {
    int eredmeny = 0;
    
    while (szorzo > 0) {
        // Ha a szorzo utolsó bitje 1
        if (szorzo & 1) {
            eredmeny += szorzando;
        }
        
        szorzando *= 2;  // Balra shift
        szorzo /= 2;     // Jobbra shift
    }
    
    return eredmeny;
}
```

### Gyakori változó nevek és jelentéseik:

| Rövidítés | Jelentés | Példa |
|-----------|----------|-------|
| `ptr` | pointer | `int* ptr` |
| `buf` | buffer | `char buf[256]` |
| `tmp` | temporary (ideiglenes) | `int tmp` |
| `cnt` / `cnt` | count (számláló) | `int cnt` |
| `idx` | index | `int idx` |
| `len` | length (hossz) | `int len` |
| `sz` | size (méret) | `size_t sz` |
| `ret` | return value | `int ret` |
| `fd` | file descriptor | `int fd` |
| `sock` | socket | `int sock` |

## 21.3 Funkciók kitalálása kódrészlet alapján

### Példa 1:

```cpp
void mystery(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

**Elemzés:**
- Két beágyazott ciklus
- Szomszédos elemek összehasonlítása
- Csere ha szükséges
- `n - i - 1` → minden iterációban kevesebb

**Következtetés:** Ez egy **Bubble Sort** (buborék rendezés)!

```cpp
void bubbleSort(int* tomb, int meret) {
    for (int i = 0; i < meret - 1; i++) {
        for (int j = 0; j < meret - i - 1; j++) {
            if (tomb[j] > tomb[j + 1]) {
                // Csere
                int temp = tomb[j];
                tomb[j] = tomb[j + 1];
                tomb[j + 1] = temp;
            }
        }
    }
}
```

### Példa 2:

```cpp
int rejtelyes(const char* s) {
    int cnt = 0;
    while (*s) {
        if (*s >= '0' && *s <= '9') {
            cnt++;
        }
        s++;
    }
    return cnt;
}
```

**Elemzés:**
- String bejárása (`while (*s)`)
- `'0'` és `'9'` közötti karakterek számolása
- `cnt` növelése

**Következtetés:** **Számjegyek számolása stringben**!

```cpp
int szamjegyekSzama(const char* szoveg) {
    int szamlalo = 0;
    while (*szoveg) {
        if (*szoveg >= '0' && *szoveg <= '9') {
            szamlalo++;
        }
        szoveg++;
    }
    return szamlalo;
}
```

## 21.4 Debug technikák ismeretlen kódnál

### Print debug:

```cpp
void ismeretlenFuggveny(int* adat, int meret) {
    std::cout << "[DEBUG] Belépés: meret = " << meret << std::endl;
    
    for (int i = 0; i < meret; i++) {
        std::cout << "[DEBUG] i=" << i << ", adat[i]=" << adat[i] << std::endl;
        
        // ... kód ...
        
        std::cout << "[DEBUG] Módosítás után: " << adat[i] << std::endl;
    }
    
    std::cout << "[DEBUG] Kilépés" << std::endl;
}
```

### Debugger használata (GDB):

```bash
# Fordítás debug szimbólumokkal
g++ -g program.cpp -o program

# GDB indítása
gdb ./program

# GDB parancsok:
(gdb) break main          # Töréspont a main-nél
(gdb) run                 # Program indítása
(gdb) next                # Következő sor
(gdb) step                # Belépés függvénybe
(gdb) print valtozo       # Változó kiírása
(gdb) backtrace           # Call stack megjelenítése
(gdb) continue            # Futtatás tovább
(gdb) quit                # Kilépés
```

## 21.5 Call graph és adatfolyam elemzés

### Kézi call graph készítés:

```
main()
├── inicializalas()
│   └── konfiguracioBetoltes()
├── adatFeldolgozas()
│   ├── adatOlvasas()
│   ├── transzformacio()
│   └── eredmenyMentes()
└── takaritas()
```

### Adatfolyam diagram:

```
Bemenet → [Olvasás] → [Validálás] → [Transzformáció] → [Mentés] → Kimenet
              ↓              ↓              ↓
           [Hiba]       [Hiba]        [Naplozás]
```

## 21.6 Reverse engineering eszközök

### Oszd meg és uralkodj stratégia:

```cpp
// Nagy függvény szétbontása
void eredetiNagyFuggveny() {
    // 200 sor kód...
}

// Szétbontva:
void reszA() { /* ... */ }
void reszB() { /* ... */ }
void reszC() { /* ... */ }

void ujFuggveny() {
    reszA();
    reszB();
    reszC();
}
```

### Kód dokumentálása menet közben:

```cpp
// EREDETI KÓD MEGÉRTÉSE UTÁN:

/**
 * Hitelesíti a felhasználót a megadott adatokkal.
 * 
 * @param username Felhasználónév
 * @param password Jelszó (hashelt)
 * @return true ha sikeres, false ha hibás
 * 
 * Működés:
 * 1. Felhasználó keresése az adatbázisban
 * 2. Jelszó hash összehasonlítása
 * 3. Session létrehozása sikeres esetben
 */
bool authenticateUser(const std::string& username, 
                      const std::string& password) {
    // ... implementáció ...
}
```

---

# 22. fejezet: Rekurzív gondolkozásmód

## 22.1 Mi a rekurzió?

A rekurzió olyan technika, amikor egy függvény **önmagát hívja meg**. Minden rekurzív függvénynek két része van:

1. **Alapeset (base case)** - amikor nem hívja tovább önmagát
2. **Rekurzív eset** - amikor hívja önmagát kisebb paraméterrel

## 22.1 Rekurzív gondolkozásmód fejlesztése

### A rekurzív gondolkodás lépései:

1. **Képzeld el a problémát kisebb verzióként**
2. **Keresd meg az alapesetet** (legegyszerűbb eset)
3. **Gondold át hogyan csökken a probléma**
4. **Hidd el hogy a rekurzív hívás működik**

### Példa: Faktoriális

**Matematikai definíció:**
- 0! = 1 (alapeset)
- n! = n × (n-1)! (rekurzív eset)

```cpp
int faktorialis(int n) {
    // 1. Alapeset
    if (n == 0) {
        return 1;
    }
    
    // 2. Rekurzív eset
    // Hidd el hogy faktorialis(n-1) működik!
    return n * faktorialis(n - 1);
}

// Call stack:
// faktorialis(4)
// = 4 * faktorialis(3)
// = 4 * 3 * faktorialis(2)
// = 4 * 3 * 2 * faktorialis(1)
// = 4 * 3 * 2 * 1 * faktorialis(0)
// = 4 * 3 * 2 * 1 * 1
// = 24
```

## 22.2 Rekurzív problémák típusai

### 1. Matematikai sorozatok:

```cpp
// Fibonacci
int fibonacci(int n) {
    if (n <= 1) return n;           // Alapeset
    return fibonacci(n-1) + fibonacci(n-2);  // Rekurzív
}

// Hatványozás
int hatvany(int alap, int kitevo) {
    if (kitevo == 0) return 1;      // Alapeset
    return alap * hatvany(alap, kitevo - 1);
}

// Optimalizált hatványozás (gyors hatványozás)
int gyorsHatvany(int alap, int kitevo) {
    if (kitevo == 0) return 1;
    
    if (kitevo % 2 == 0) {
        int fel = gyorsHatvany(alap, kitevo / 2);
        return fel * fel;
    } else {
        return alap * gyorsHatvany(alap, kitevo - 1);
    }
}
```

### 2. Rekurzív adatszerkezetek bejárása:

```cpp
// Linkelt lista rekurzív bejárása
struct ListaElem {
    int adat;
    ListaElem* kovetkezo;
};

void listaKiir(ListaElem* fej) {
    if (fej == nullptr) return;  // Alapeset
    
    std::cout << fej->adat << " ";
    listaKiir(fej->kovetkezo);   // Rekurzív hívás
}

// Fa bejárása
struct FaCsucs {
    int adat;
    FaCsucs* bal;
    FaCsucs* jobb;
};

// In-order bejárás
void inOrder(FaCsucs* csucs) {
    if (csucs == nullptr) return;
    
    inOrder(csucs->bal);
    std::cout << csucs->adat << " ";
    inOrder(csucs->jobb);
}
```

### 3. Oszd meg és uralkodj algoritmusok:

```cpp
// Binary Search (bináris keresés)
int binarisKereses(const std::vector<int>& tomb, int keresett, 
                   int bal, int jobb) {
    if (bal > jobb) return -1;  // Nem található
    
    int kozep = bal + (jobb - bal) / 2;
    
    if (tomb[kozep] == keresett) {
        return kozep;
    } else if (tomb[kozep] > keresett) {
        return binarisKereses(tomb, keresett, bal, kozep - 1);
    } else {
        return binarisKereses(tomb, keresett, kozep + 1, jobb);
    }
}

// Merge Sort
void mergeSort(std::vector<int>& tomb, int bal, int jobb) {
    if (bal >= jobb) return;  // Alapeset: 1 elemű
    
    int kozep = bal + (jobb - bal) / 2;
    
    // Rekurzív osztás
    mergeSort(tomb, bal, kozep);
    mergeSort(tomb, kozep + 1, jobb);
    
    // Egyesítés (merge)
    // ... merge implementáció ...
}
```

### 4. Visszalépéses (backtracking) algoritmusok:

```cpp
// N-Queens probléma
bool nQueens(std::vector<std::vector<bool>>& tabla, int sor) {
    if (sor == tabla.size()) {
        return true;  // Minden királynő elhelyezve
    }
    
    for (int oszlop = 0; oszlop < tabla.size(); oszlop++) {
        if (biztonsagos(tabla, sor, oszlop)) {
            tabla[sor][oszlop] = true;  // Elhelyezés
            
            if (nQueens(tabla, sor + 1)) {  // Rekurzív hívás
                return true;
            }
            
            tabla[sor][oszlop] = false;  // Visszalépés
        }
    }
    
    return false;
}

// Sudoku megoldás
bool sudokuMegold(std::vector<std::vector<int>>& tabla) {
    // Üres hely keresése
    for (int sor = 0; sor < 9; sor++) {
        for (int oszlop = 0; oszlop < 9; oszlop++) {
            if (tabla[sor][oszlop] == 0) {
                // Szám kipróbálása 1-9
                for (int szam = 1; szam <= 9; szam++) {
                    if (ervenyos(tabla, sor, oszlop, szam)) {
                        tabla[sor][oszlop] = szam;
                        
                        if (sudokuMegold(tabla)) {
                            return true;
                        }
                        
                        tabla[sor][oszlop] = 0;  // Visszalépés
                    }
                }
                return false;
            }
        }
    }
    return true;  // Megoldva
}
```

## 22.3 Rekurzív problémák megoldásának technikái

### 1. Rekurzió fa rajzolása:

```
faktoriális(4)
    │
    ├─ 4 * faktoriális(3)
    │      │
    │      ├─ 3 * faktoriális(2)
    │      │      │
    │      │      ├─ 2 * faktoriális(1)
    │      │      │      │
    │      │      │      └─ 1 * faktoriális(0)
    │      │      │             │
    │      │      │             └─ 1
    │      │      │
    │      │      └─ 2 * 1 = 2
    │      │
    │      └─ 3 * 2 = 6
    │
    └─ 4 * 6 = 24
```

### 2. Állapot követése:

```cpp
// Rekurzív függvény naplózással
int faktorialisNaplóval(int n, int melyseg = 0) {
    std::string behúzás(melyseg * 2, ' ');
    
    std::cout << behúzás << "faktorialis(" << n << ")" << std::endl;
    
    if (n == 0) {
        std::cout << behúzás << "→ 1 (alapeset)" << std::endl;
        return 1;
    }
    
    int eredmeny = n * faktorialisNaplóval(n - 1, melyseg + 1);
    
    std::cout << behúzás << "→ " << eredmeny << std::endl;
    return eredmeny;
}
```

### 3. Farok-rekurzió (tail recursion):

```cpp
// Normál rekurzió
int osszeg(const std::vector<int>& lista) {
    if (lista.empty()) return 0;
    return lista[0] + osszeg(lista.slice(1));
}

// Farok-rekurzió (optimalizálható)
int osszegFarok(const std::vector<int>& lista, int akkumulator = 0) {
    if (lista.empty()) return akkumulator;
    return osszegFarok(lista.slice(1), akkumulator + lista[0]);
}

// Iteratív változat (ugyanaz)
int osszegIterativ(const std::vector<int>& lista) {
    int osszeg = 0;
    for (int szam : lista) {
        osszeg += szam;
    }
    return osszeg;
}
```

## 22.4 Rekurzív gyakorlatok

### 1. Hanoi tornyai:

```cpp
void hanoi(int n, char honnan, char seged, char hova) {
    if (n == 1) {
        std::cout << honnan << " → " << hova << std::endl;
        return;
    }
    
    hanoi(n - 1, honnan, hova, seged);
    std::cout << honnan << " → " << hova << std::endl;
    hanoi(n - 1, seged, honnan, hova);
}

// Használat: hanoi(3, 'A', 'B', 'C');
```

### 2. Permutációk generálása:

```cpp
void permutaciok(std::string s, int index = 0) {
    if (index == s.length()) {
        std::cout << s << std::endl;
        return;
    }
    
    for (int i = index; i < s.length(); i++) {
        std::swap(s[index], s[i]);
        permutaciok(s, index + 1);
        std::swap(s[index], s[i]);  // Visszaállítás
    }
}
```

### 3. Részhalmazok generálása:

```cpp
void reszhalmazok(const std::vector<int>& halmaz, 
                  std::vector<int>& aktualis, 
                  int index = 0) {
    if (index == halmaz.size()) {
        // Kiírás
        for (int elem : aktualis) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
        return;
    }
    
    // Nem választjuk az aktuális elemet
    reszhalmazok(halmaz, aktualis, index + 1);
    
    // Választjuk az aktuális elemet
    aktualis.push_back(halmaz[index]);
    reszhalmazok(halmaz, aktualis, index + 1);
    aktualis.pop_back();
}
```

## 22.5 Rekurzió vs iteráció

| Szempont | Rekurzió | Iteráció |
|----------|----------|----------|
| Olvashatóság | Elegáns, tömör | Hosszabb, explicit |
| Teljesítmény | Stack overhead | Gyorsabb |
| Memória | Stack használat | Minimális |
| Alkalmazás | Fa, gráf, backtracking | Egyszerű ciklusok |

### Mikor használj rekurziót?

✅ Fa/gráf bejárás  
✅ Osztályozó algoritmusok  
✅ Backtracking problémák  
✅ Matematikai sorozatok  

❌ Egyszerű ciklusok helyett  
❌ Ha stack overflow veszélye áll fenn  
❌ Ha iteratív megoldás egyszerűbb  

---

# 23. fejezet: Hibakezelés CLI és GUI alkalmazásokban

## 23.1 Hibakezelés alapok

### Hibák típusai:

1. **Fordítási hibák** - szintaktikai hibák
2. **Futási hibák** - nullával osztás, memóriahiba
3. **Logikai hibák** - a program működik, de rosszat csinál
4. **Bemeneti hibák** - rossz felhasználói bemenet

## 23.2 Hibakezelés CLI alkalmazásokban

### Hibakódok használata:

```cpp
#include <iostream>

enum class HibaKod {
    SIKERES = 0,
    BEMENETI_HIBA = 1,
    FAJL_HIBA = 2,
    MEMORIA_HIBA = 3,
    ISMERETLEN_HIBA = 4
};

HibaKod fajlFeldolgozas(const std::string& fajlnev) {
    // Ellenőrzések
    if (fajlnev.empty()) {
        std::cerr << "Hiba: Üres fájlnév!" << std::endl;
        return HibaKod::BEMENETI_HIBA;
    }
    
    std::ifstream file(fajlnev);
    if (!file.is_open()) {
        std::cerr << "Hiba: Nem nyitható meg a fájl: " << fajlnev << std::endl;
        return HibaKod::FAJL_HIBA;
    }
    
    // ... feldolgozás ...
    
    return HibaKod::SIKERES;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Használat: " << argv[0] << " <fajlnev>" << std::endl;
        return static_cast<int>(HibaKod::BEMENETI_HIBA);
    }
    
    HibaKod eredmeny = fajlFeldolgozas(argv[1]);
    
    if (eredmeny != HibaKod::SIKERES) {
        std::cerr << "Program hiba miatt leállt!" << std::endl;
    }
    
    return static_cast<int>(eredmeny);
}
```

### Kivételkezelés CLI-ben:

```cpp
#include <stdexcept>
#include <iostream>

class FajlKezelo {
public:
    enum class Hiba {
        NEM_NYITHATO,
        OLVASASI_HIBA,
        FORMAZASI_HIBA
    };
    
    static void fajlBeolvasas(const std::string& nev) {
        std::ifstream file(nev);
        
        if (!file.is_open()) {
            throw std::runtime_error("Fájl nem nyitható meg: " + nev);
        }
        
        // ... olvasás ...
        
        if (file.bad()) {
            throw std::ios_base::failure("Olvasási hiba");
        }
    }
};

int main() {
    try {
        FajlKezelo::fajlBeolvasas("adatok.txt");
        std::cout << "Sikeres betöltés!" << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Futási hiba: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Általános hiba: " << e.what() << std::endl;
        return 2;
    }
    catch (...) {
        std::cerr << "Ismeretlen hiba!" << std::endl;
        return 3;
    }
    
    return 0;
}
```

### Részletes hibajelentés:

```cpp
#include <sstream>
#include <chrono>
#include <fstream>

class HibaJelentes {
private:
    std::string uzenet;
    std::string fajl;
    int sor;
    std::string ido;
    
public:
    HibaJelentes(const std::string& msg, const std::string& file, int line)
        : uzenet(msg), fajl(file), sor(line) {
        
        auto most = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(most);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
        ido = ss.str();
    }
    
    void naplozas() {
        std::ofstream naplo("hiba_naplo.txt", std::ios::app);
        naplo << "[" << ido << "] "
              << "HIBA a " << fajl << ":" << sor << ". sorban: "
              << uzenet << std::endl;
    }
    
    void kiiras() {
        std::cerr << "╔════════════════════════════════════════╗" << std::endl;
        std::cerr << "║           H I B A J E L E N T É S      ║" << std::endl;
        std::cerr << "╠════════════════════════════════════════╣" << std::endl;
        std::cerr << "║ Idő: " << ido << std::endl;
        std::cerr << "║ Hely: " << fajl << ":" << sor << std::endl;
        std::cerr << "║ Üzenet: " << uzenet << std::endl;
        std::cerr << "╚════════════════════════════════════════╝" << std::endl;
    }
};

// Makró a könnyű használathoz
#define DOB_HIBA(uzenet) throw HibaJelentes(uzenet, __FILE__, __LINE__)

// Használat
void fuggveny() {
    if (valamiHiba) {
        DOB_HIBA("Valami nem működött!");
    }
}
```

## 23.3 Hibakezelés GUI alkalmazásokban

### Windows GUI hibakezelés:

```cpp
#include <windows.h>
#include <commdlg.h>

void HibaUzenet(HWND hwnd, const wchar_t* uzenet) {
    MessageBoxW(hwnd, uzenet, L"Hiba", MB_OK | MB_ICONERROR);
}

void Figyelmeztetes(HWND hwnd, const wchar_t* uzenet) {
    MessageBoxW(hwnd, uzenet, L"Figyelmeztetés", MB_OK | MB_ICONWARNING);
}

bool Megerosites(HWND hwnd, const wchar_t* uzenet) {
    int eredmeny = MessageBoxW(hwnd, uzenet, L"Megerősítés", 
                               MB_YESNO | MB_ICONQUESTION);
    return (eredmeny == IDYES);
}

// Példa használat
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_COMMAND:
            if (LOWORD(wParam) == ID_FILE_OPEN) {
                OPENFILENAMEW ofn = {};
                wchar_t szFile[260] = L"";
                
                ofn.lStructSize = sizeof(ofn);
                ofn.hwndOwner = hwnd;
                ofn.lpstrFile = szFile;
                ofn.nMaxFile = sizeof(szFile);
                ofn.lpstrFilter = L"Fájlok (*.*)\0*.*\0";
                
                if (!GetOpenFileNameW(&ofn)) {
                    DWORD hiba = CommDlgExtendedError();
                    if (hiba != 0) {
                        HibaUzenet(hwnd, L"Fájl megnyitás hiba!");
                    }
                    // Cancel nem hiba
                    break;
                }
                
                // Fájl betöltése...
            }
            break;
            
        case WM_CLOSE:
            if (Megerosites(hwnd, L"Biztosan ki akarsz lépni?")) {
                DestroyWindow(hwnd);
            }
            break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
```

### GTK hibakezelés:

```cpp
#include <gtk/gtk.h>

void hibaUzenet(GtkWidget* szulo, const gchar* uzenet) {
    GtkWidget* dialog = gtk_message_dialog_new(
        GTK_WINDOW(szulo),
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_ERROR,
        GTK_BUTTONS_OK,
        "%s", uzenet
    );
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void figyelmeztetes(GtkWidget* szulo, const gchar* uzenet) {
    GtkWidget* dialog = gtk_message_dialog_new(
        GTK_WINDOW(szulo),
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_WARNING,
        GTK_BUTTONS_OK,
        "%s", uzenet
    );
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

gboolean megerosites(GtkWidget* szulo, const gchar* uzenet) {
    GtkWidget* dialog = gtk_message_dialog_new(
        GTK_WINDOW(szulo),
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_QUESTION,
        GTK_BUTTONS_YES_NO,
        "%s", uzenet
    );
    gint valasz = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    return (valasz == GTK_RESPONSE_YES);
}

// Példa használat
void fajlMegnyitas(GtkWidget* widget, gpointer data) {
    GtkWidget* dialog = gtk_file_chooser_dialog_new(
        "Fájl megnyitása",
        GTK_WINDOW(data),
        GTK_FILE_CHOOSER_ACTION_OPEN,
        "_Mégse", GTK_RESPONSE_CANCEL,
        "_Megnyitás", GTK_RESPONSE_ACCEPT,
        NULL
    );
    
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char* filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        
        GError* error = NULL;
        gchar* tartalom;
        
        if (!g_file_get_contents(filename, &tartalom, NULL, &error)) {
            hibaUzenet(GTK_WIDGET(data), error->message);
            g_error_free(error);
        } else {
            // Sikeres betöltés...
            g_free(tartalom);
        }
        
        g_free(filename);
    }
    
    gtk_widget_destroy(dialog);
}
```

## 23.4 Hibakezelési minták

### RAII (Resource Acquisition Is Initialization):

```cpp
class File {
private:
    FILE* file;
    
public:
    File(const std::string& nev, const char* mode) {
        file = fopen(nev.c_str(), mode);
        if (!file) {
            throw std::runtime_error("Fájl nem nyitható: " + nev);
        }
    }
    
    ~File() {
        if (file) {
            fclose(file);
        }
    }
    
    // Másolás letiltása
    File(const File&) = delete;
    File& operator=(const File&) = delete;
    
    FILE* get() { return file; }
};

// Használat - automatikus erőforrás kezelés
void adatokMentes(const std::string& nev) {
    File file(nev, "w");  // Automatikus bezárás
    fprintf(file.get(), "Adatok...\n");
    // Nincs szükség explicit fclose-re!
}
```

### Error Result pattern:

```cpp
#include <variant>
#include <string>

template<typename T, typename E = std::string>
class Result {
private:
    std::variant<T, E> adat;
    bool sikeres;
    
public:
    Result(T ertek) : adat(ertek), sikeres(true) {}
    Result(E hiba) : adat(hiba), sikeres(false) {}
    
    bool isOk() const { return sikeres; }
    
    T value() const {
        if (!sikeres) throw std::runtime_error("Hibás Result!");
        return std::get<T>(adat);
    }
    
    E error() const {
        if (sikeres) throw std::runtime_error("Nincs hiba!");
        return std::get<E>(adat);
    }
};

// Használat
Result<int, std::string> osztas(int a, int b) {
    if (b == 0) {
        return Result<int, std::string>("Osztás nullával!");
    }
    return Result<int, std::string>(a / b);
}

void fuggveny() {
    auto eredmeny = osztas(10, 0);
    
    if (eredmeny.isOk()) {
        std::cout << "Eredmény: " << eredmeny.value() << std::endl;
    } else {
        std::cerr << "Hiba: " << eredmeny.error() << std::endl;
    }
}
```

## 23.5 Hibakezelés hálózati alkalmazásokban

```cpp
class NetworkHiba : public std::exception {
private:
    std::string uzenet;
    int errorCode;
    
public:
    NetworkHiba(const std::string& msg, int code) 
        : uzenet(msg), errorCode(code) {}
    
    const char* what() const noexcept override {
        return uzenet.c_str();
    }
    
    int getCode() const { return errorCode; }
};

class BiztonsagosSocket {
private:
    int socket;
    
public:
    BiztonsagosSocket(int domain, int type, int protocol) {
        socket = ::socket(domain, type, protocol);
        if (socket < 0) {
            throw NetworkHiba("Socket létrehozás hiba", errno);
        }
    }
    
    void connect(const std::string& host, int port) {
        // ... connect implementáció ...
        if (eredmeny < 0) {
            throw NetworkHiba("Csatlakozás hiba", errno);
        }
    }
    
    int send(const std::string& adat) {
        int bytes = ::send(socket, adat.c_str(), adat.length(), 0);
        if (bytes < 0) {
            throw NetworkHiba("Küldés hiba", errno);
        }
        return bytes;
    }
    
    ~BiztonsagosSocket() {
        if (socket >= 0) {
            close(socket);
        }
    }
};

// Használat
void halozatiPelda() {
    try {
        BiztonsagosSocket sock(AF_INET, SOCK_STREAM, 0);
        sock.connect("127.0.0.1", 8080);
        sock.send("Üzenet");
    }
    catch (const NetworkHiba& e) {
        std::cerr << "Hálózati hiba (" << e.getCode() << "): " 
                  << e.what() << std::endl;
    }
}
```

## 23.6 Naplózás (Logging)

```cpp
#include <fstream>
#include <mutex>
#include <chrono>

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class Logger {
private:
    static Logger* instance;
    std::ofstream logFile;
    std::mutex mutex;
    LogLevel minLevel;
    
    Logger() : minLevel(LogLevel::DEBUG) {
        logFile.open("alkalmazas.log", std::ios::app);
    }
    
public:
    static Logger* getInstance() {
        if (!instance) {
            instance = new Logger();
        }
        return instance;
    }
    
    void log(LogLevel level, const std::string& uzenet) {
        if (level < minLevel) return;
        
        std::lock_guard<std::mutex> lock(mutex);
        
        // Időbélyeg
        auto most = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(most);
        
        const char* levelStr;
        switch (level) {
            case LogLevel::DEBUG: levelStr = "DEBUG"; break;
            case LogLevel::INFO: levelStr = "INFO"; break;
            case LogLevel::WARNING: levelStr = "WARNING"; break;
            case LogLevel::ERROR: levelStr = "ERROR"; break;
            case LogLevel::CRITICAL: levelStr = "CRITICAL"; break;
        }
        
        logFile << "[" << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S")
                << "] [" << levelStr << "] " << uzenet << std::endl;
        logFile.flush();
    }
    
    void setMinLevel(LogLevel level) { minLevel = level; }
};

Logger* Logger::instance = nullptr;

// Makrók a könnyű használathoz
#define LOG_DEBUG(msg) Logger::getInstance()->log(LogLevel::DEBUG, msg)
#define LOG_INFO(msg) Logger::getInstance()->log(LogLevel::INFO, msg)
#define LOG_WARNING(msg) Logger::getInstance()->log(LogLevel::WARNING, msg)
#define LOG_ERROR(msg) Logger::getInstance()->log(LogLevel::ERROR, msg)
#define LOG_CRITICAL(msg) Logger::getInstance()->log(LogLevel::CRITICAL, msg)

// Használat
void fuggveny() {
    LOG_INFO("Függvény indítása");
    
    try {
        // ... kód ...
    }
    catch (const std::exception& e) {
        LOG_ERROR(std::string("Kivétel: ") + e.what());
        throw;
    }
    
    LOG_DEBUG("Függvény befejezve");
}
```

---

# 24. fejezet: String kezelés és több bájtos karakterek

## 24.1 Alap string függvények

### std::string alap műveletek:

```cpp
#include <string>
#include <iostream>

int main() {
    std::string s1 = "Hello";
    std::string s2 = "Világ";
    
    // Összefűzés
    std::string s3 = s1 + " " + s2;
    std::cout << s3 << std::endl;  // "Hello Világ"
    
    // Hossz
    std::cout << "Hossz: " << s3.length() << std::endl;  // 11
    std::cout << "Méret: " << s3.size() << std::endl;    // 11
    
    // Részstring
    std::string resz = s3.substr(0, 5);  // "Hello"
    
    // Keresés
    size_t poz = s3.find("Világ");  // 6
    if (poz != std::string::npos) {
        std::cout << "Megtalálva: " << poz << std::endl;
    }
    
    // Csere
    s3.replace(6, 5, "Föld");  // "Hello Föld"
    
    // Beszúrás
    s3.insert(5, ",");  // "Hello, Föld"
    
    // Törlés
    s3.erase(5, 1);  // "Hello Föld"
    
    return 0;
}
```

## 24.2 Több bájtos karakterek (UTF-8)

### UTF-8 kódolás alapok:

```cpp
#include <string>
#include <vector>
#include <cstdint>

// UTF-8 karakter típusok
enum class UTF8Tipus {
    ASCII,      // 0xxxxxxx (1 bájt)
    CONTINUATION, // 10xxxxxx (folytató bájt)
    START2,     // 110xxxxx (2 bájtos karakter kezdete)
    START3,     // 1110xxxx (3 bájtos karakter kezdete)
    START4      // 11110xxx (4 bájtos karakter kezdete)
};

UTF8Tipus getUTF8Tipus(uint8_t byte) {
    if ((byte & 0x80) == 0) return UTF8Tipus::ASCII;
    if ((byte & 0xC0) == 0x80) return UTF8Tipus::CONTINUATION;
    if ((byte & 0xE0) == 0xC0) return UTF8Tipus::START2;
    if ((byte & 0xF0) == 0xE0) return UTF8Tipus::START3;
    if ((byte & 0xF8) == 0xF0) return UTF8Tipus::START4;
    return UTF8Tipus::CONTINUATION;  // Hibás
}

// UTF-8 karakterek számolása
int utf8KarakterekSzama(const std::string& str) {
    int db = 0;
    for (char c : str) {
        if ((c & 0xC0) != 0x80) {  // Nem folytató bájt
            db++;
        }
    }
    return db;
}

// UTF-8 karakterek konvertálása Unicode kódpontra
std::vector<uint32_t> utf8ToUnicode(const std::string& utf8) {
    std::vector<uint32_t> kodpontok;
    
    for (size_t i = 0; i < utf8.length(); ) {
        uint8_t byte = utf8[i];
        uint32_t kodpont;
        int bajtok;
        
        if ((byte & 0x80) == 0) {
            kodpont = byte;
            bajtok = 1;
        } else if ((byte & 0xE0) == 0xC0) {
            kodpont = byte & 0x1F;
            bajtok = 2;
        } else if ((byte & 0xF0) == 0xE0) {
            kodpont = byte & 0x0F;
            bajtok = 3;
        } else if ((byte & 0xF8) == 0xF0) {
            kodpont = byte & 0x07;
            bajtok = 4;
        } else {
            i++;  // Hibás bájt, kihagyás
            continue;
        }
        
        // Folytató bájtok hozzáadása
        for (int j = 1; j < bajtok && i + j < utf8.length(); j++) {
            kodpont = (kodpont << 6) | (utf8[i + j] & 0x3F);
        }
        
        kodpontok.push_back(kodpont);
        i += bajtok;
    }
    
    return kodpontok;
}

// Unicode kódpontról konvertálás UTF-8-ra
std::string unicodeToUtf8(uint32_t kodpont) {
    std::string eredmeny;
    
    if (kodpont < 0x80) {
        eredmeny += static_cast<char>(kodpont);
    } else if (kodpont < 0x800) {
        eredmeny += static_cast<char>(0xC0 | (kodpont >> 6));
        eredmeny += static_cast<char>(0x80 | (kodpont & 0x3F));
    } else if (kodpont < 0x10000) {
        eredmeny += static_cast<char>(0xE0 | (kodpont >> 12));
        eredmeny += static_cast<char>(0x80 | ((kodpont >> 6) & 0x3F));
        eredmeny += static_cast<char>(0x80 | (kodpont & 0x3F));
    } else {
        eredmeny += static_cast<char>(0xF0 | (kodpont >> 18));
        eredmeny += static_cast<char>(0x80 | ((kodpont >> 12) & 0x3F));
        eredmeny += static_cast<char>(0x80 | ((kodpont >> 6) & 0x3F));
        eredmeny += static_cast<char>(0x80 | (kodpont & 0x3F));
    }
    
    return eredmeny;
}

// Használat
int main() {
    std::string magyar = "Árvíztűrő tükörfúrógép";
    
    std::cout << "Bájtok száma: " << magyar.length() << std::endl;
    std::cout << "Karakterek száma: " << utf8KarakterekSzama(magyar) << std::endl;
    
    // Konvertálás Unicode-ra
    auto kodpontok = utf8ToUnicode(magyar);
    for (uint32_t kp : kodpontok) {
        std::cout << "U+" << std::hex << kp << " ";
    }
    std::cout << std::endl;
    
    // Egyedi karakter létrehozása
    std::string ekezetesA = unicodeToUtf8(0x00C1);  // 'Á'
    std::cout << ekezetesA << std::endl;
    
    return 0;
}
```

## 24.3 Széles karakterek (wchar_t)

```cpp
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

int main() {
    // Széles karakter string
    std::wstring wstr = L"Széles karakteres szöveg ÁÉŰŐÓÜÖŰ";
    
    // Kiírás
    std::wcout << wstr << std::endl;
    
    // Hossz
    std::wcout << L"Hossz: " << wstr.length() << std::endl;
    
    // Konvertálás std::string <-> std::wstring
    std::wstring_convert<std::codecvt_utf8<wchar_t>> konverter;
    
    std::string utf8 = konverter.to_bytes(wstr);
    std::wstring vissza = konverter.from_bytes(utf8);
    
    return 0;
}
```

## 24.4 String manipulációs függvények

```cpp
#include <string>
#include <algorithm>
#include <cctype>

// String kisbetűsítése
std::string toLower(const std::string& str) {
    std::string eredmeny = str;
    std::transform(eredmeny.begin(), eredmeny.end(), eredmeny.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return eredmeny;
}

// String nagybetűsítése
std::string toUpper(const std::string& str) {
    std::string eredmeny = str;
    std::transform(eredmeny.begin(), eredmeny.end(), eredmeny.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return eredmeny;
}

// Trim (szóközök levágása)
std::string trim(const std::string& str) {
    size_t elso = str.find_first_not_of(" \t\n\r");
    if (std::string::npos == elso) return "";
    
    size_t utolso = str.find_last_not_of(" \t\n\r");
    return str.substr(elso, utolso - elso + 1);
}

// String fordítva
std::string reverse(const std::string& str) {
    std::string eredmeny = str;
    std::reverse(eredmeny.begin(), eredmeny.end());
    return eredmeny;
}

// Szóközök eltávolítása
std::string removeSpaces(const std::string& str) {
    std::string eredmeny;
    for (char c : str) {
        if (!std::isspace(c)) {
            eredmeny += c;
        }
    }
    return eredmeny;
}

// Ismétlődő karakterek eltávolítása
std::string removeDuplicates(const std::string& str) {
    std::string eredmeny;
    for (char c : str) {
        if (eredmeny.find(c) == std::string::npos) {
            eredmeny += c;
        }
    }
    return eredmeny;
}

// Használat
int main() {
    std::string s = "  Hello World  ";
    
    std::cout << "Eredeti: '" << s << "'" << std::endl;
    std::cout << "Trim: '" << trim(s) << "'" << std::endl;
    std::cout << "Lower: '" << toLower(trim(s)) << "'" << std::endl;
    std::cout << "Upper: '" << toUpper(trim(s)) << "'" << std::endl;
    std::cout << "Reverse: '" << reverse(trim(s)) << "'" << std::endl;
    
    return 0;
}
```

## 24.5 Tokenizáció (szöveg feldarabolása)

### Elmélet:
A **tokenizáció** a szöveg kisebb egységekre (tokenekre) bontása. Használata:
- Szövegfeldolgozás
- Fordítóprogramok
- AI/NLP alkalmazások
- Parancsértelmezők

### Manuális tokenizáció:

```cpp
#include <string>
#include <vector>
#include <sstream>

// Egyszerű tokenizáció elválasztó karakter alapján
std::vector<std::string> tokenize(const std::string& szoveg, char elvalaszto) {
    std::vector<std::string> tokenek;
    std::string token;
    
    for (char c : szoveg) {
        if (c == elvalaszto) {
            if (!token.empty()) {
                tokenek.push_back(token);
                token.clear();
            }
        } else {
            token += c;
        }
    }
    
    if (!token.empty()) {
        tokenek.push_back(token);
    }
    
    return tokenek;
}

// Tokenizáció stringstream-mel
std::vector<std::string> tokenizeStream(const std::string& szoveg) {
    std::vector<std::string> tokenek;
    std::stringstream ss(szoveg);
    std::string token;
    
    while (ss >> token) {
        tokenek.push_back(token);
    }
    
    return tokenek;
}

// Használat
int main() {
    std::string mondat = "Az,alma,és,a,körte,gyümölcs";
    
    auto tokenek = tokenize(mondat, ',');
    
    std::cout << "Tokenek:" << std::endl;
    for (const auto& t : tokenek) {
        std::cout << "  - " << t << std::endl;
    }
    
    // Szóköz szerinti tokenizáció
    std::string szoveg = "Ez egy példa mondat";
    auto szavak = tokenizeStream(szoveg);
    
    std::cout << "\nSzavak:" << std::endl;
    for (const auto& szo : szavak) {
        std::cout << "  - " << szo << std::endl;
    }
    
    return 0;
}
```

### Haladó tokenizáció (több elválasztó):

```cpp
#include <set>

std::vector<std::string> tokenizeTobbElvalaszto(
    const std::string& szoveg, 
    const std::set<char>& elvalasztok) {
    
    std::vector<std::string> tokenek;
    std::string token;
    
    for (char c : szoveg) {
        if (elvalasztok.count(c)) {
            if (!token.empty()) {
                tokenek.push_back(token);
                token.clear();
            }
        } else {
            token += c;
        }
    }
    
    if (!token.empty()) {
        tokenek.push_back(token);
    }
    
    return tokenek;
}

// Használat
int main() {
    std::string szoveg = "alma,körte;szőlő:barack";
    std::set<char> elvalasztok = {',', ';', ':'};
    
    auto gyumolcsok = tokenizeTobbElvalaszto(szoveg, elvalasztok);
    
    for (const auto& g : gyumolcsok) {
        std::cout << g << std::endl;
    }
    // alma, körte, szőlő, barack
    
    return 0;
}
```

### Regex alapú tokenizáció (C++11):

```cpp
#include <regex>

std::vector<std::string> tokenizeRegex(const std::string& szoveg, 
                                        const std::string& minta) {
    std::vector<std::string> tokenek;
    std::regex re(minta);
    std::sregex_token_iterator iter(szoveg.begin(), szoveg.end(), re, -1);
    std::sregex_token_iterator end;
    
    while (iter != end) {
        std::string token = *iter++;
        if (!token.empty()) {
            tokenek.push_back(token);
        }
    }
    
    return tokenek;
}

// Használat
int main() {
    std::string szoveg = "alma123körte456szőlő789";
    
    // Számok szerinti vágás
    auto tokenek = tokenizeRegex(szoveg, "\\d+");
    
    for (const auto& t : tokenek) {
        std::cout << t << std::endl;  // alma, körte, szőlő
    }
    
    return 0;
}
```

---

# 25. fejezet: Fájlkezelés és másoló függvények

## 25.1 Alap fájlkezelés

### Szöveges fájlok kezelése:

```cpp
#include <fstream>
#include <iostream>
#include <string>

// Írás fájlba
void irasFajlba(const std::string& fajlnev, const std::string& tartalom) {
    std::ofstream ki(fajlnev);
    
    if (ki.is_open()) {
        ki << tartalom;
        ki.close();
        std::cout << "Sikeres írás!" << std::endl;
    } else {
        std::cerr << "Nem nyitható meg a fájl!" << std::endl;
    }
}

// Olvasás fájlból
std::string olvasasFajlbol(const std::string& fajlnev) {
    std::ifstream be(fajlnev);
    std::string tartalom;
    std::string sor;
    
    if (be.is_open()) {
        while (std::getline(be, sor)) {
            tartalom += sor + "\n";
        }
        be.close();
    }
    
    return tartalom;
}

// Soronkénti olvasás
void soronkentiOlvadas(const std::string& fajlnev) {
    std::ifstream be(fajlnev);
    std::string sor;
    int sorszam = 1;
    
    if (be.is_open()) {
        while (std::getline(be, sor)) {
            std::cout << sorszam << ": " << sor << std::endl;
            sorszam++;
        }
        be.close();
    }
}
```

## 25.2 Bináris fájlok kezelése

```cpp
#include <fstream>
#include <vector>
#include <cstdint>

#pragma pack(push, 1)
struct AdatRekord {
    uint32_t id;
    double ertek;
    char nev[32];
};
#pragma pack(pop)

// Bináris írás
void binarisIras(const std::string& fajlnev) {
    std::ofstream ki(fajlnev, std::ios::binary);
    
    if (ki.is_open()) {
        AdatRekord rekord1 = {1, 3.14, "Első"};
        AdatRekord rekord2 = {2, 2.71, "Második"};
        
        ki.write(reinterpret_cast<const char*>(&rekord1), sizeof(AdatRekord));
        ki.write(reinterpret_cast<const char*>(&rekord2), sizeof(AdatRekord));
        
        ki.close();
    }
}

// Bináris olvasás
std::vector<AdatRekord> binarisOlvadas(const std::string& fajlnev) {
    std::vector<AdatRekord> adatok;
    std::ifstream be(fajlnev, std::ios::binary);
    
    if (be.is_open()) {
        AdatRekord rekord;
        while (be.read(reinterpret_cast<char*>(&rekord), sizeof(AdatRekord))) {
            adatok.push_back(rekord);
        }
        be.close();
    }
    
    return adatok;
}
```

## 25.3 Másoló függvények

### Memória másolás:

```cpp
#include <cstring>
#include <iostream>

// C-stílusú másolás (veszélyes!)
void veszelyesMasolas() {
    char forras[] = "Hello Világ!";
    char cel[10];  // Túl kicsi!
    
    // HIBA: Túlcsordulás!
    // strcpy(cel, forras);
}

// Biztonságos másolás
void biztonsagosMasolas() {
    char forras[] = "Hello Világ!";
    char cel[20];
    
    // Méret ellenőrzés
    if (strlen(forras) < sizeof(cel)) {
        strcpy(cel, forras);
    }
    
    // VAGY strncpy használata
    strncpy(cel, forras, sizeof(cel) - 1);
    cel[sizeof(cel) - 1] = '\0';  // Null byte biztosítása
}

// Modern C++ másolás
void modernMasolas() {
    std::string forras = "Hello Világ!";
    std::string cel = forras;  // Egyszerű másolás
    
    // VAGY
    std::string cel2(forras);
    
    // Részleges másolás
    std::string cel3 = forras.substr(0, 5);  // "Hello"
}
```

### Fájl másolás:

```cpp
#include <fstream>

// Egyszerű fájl másolás
bool masolFajl(const std::string& forras, const std::string& cel) {
    std::ifstream be(forras, std::ios::binary);
    std::ofstream ki(cel, std::ios::binary);
    
    if (!be.is_open() || !ki.is_open()) {
        return false;
    }
    
    // Teljes fájl betöltése memóriába
    std::string tartalom((std::istreambuf_iterator<char>(be)),
                          std::istreambuf_iterator<char>());
    
    ki << tartalom;
    
    return true;
}

// Nagy fájlok másolása (chunkolva)
bool masolNagyFajl(const std::string& forras, const std::string& cel) {
    std::ifstream be(forras, std::ios::binary);
    std::ofstream ki(cel, std::ios::binary);
    
    if (!be.is_open() || !ki.is_open()) {
        return false;
    }
    
    const size_t BUFFER_MERET = 8192;  // 8 KB
    char buffer[BUFFER_MERET];
    
    while (be.read(buffer, BUFFER_MERET)) {
        ki.write(buffer, be.gcount());
    }
    
    // Maradék bájtok írása
    if (be.gcount() > 0) {
        ki.write(buffer, be.gcount());
    }
    
    return true;
}

// Haladó másolás progresszel
bool masolFajlProgresszel(const std::string& forras, 
                          const std::string& cel,
                          std::function<void(double)> progressCallback) {
    std::ifstream be(forras, std::ios::binary | std::ios::ate);
    std::ofstream ki(cel, std::ios::binary);
    
    if (!be.is_open() || !ki.is_open()) {
        return false;
    }
    
    // Fájlméret lekérése
    std::streamsize meret = be.tellg();
    be.seekg(0, std::ios::beg);
    
    const size_t BUFFER_MERET = 65536;  // 64 KB
    char buffer[BUFFER_MERET];
    std::streamsize masolt = 0;
    
    while (be.read(buffer, BUFFER_MERET)) {
        ki.write(buffer, be.gcount());
        masolt += be.gcount();
        
        if (progressCallback) {
            progressCallback(static_cast<double>(masolt) / meret);
        }
    }
    
    if (be.gcount() > 0) {
        ki.write(buffer, be.gcount());
        masolt += be.gcount();
        
        if (progressCallback) {
            progressCallback(1.0);
        }
    }
    
    return true;
}

// Használat
int main() {
    masolFajlProgresszel("nagyfajl.bin", "masolat.bin", 
        [](double progress) {
            std::cout << "\rMásolás: " << (progress * 100) << "%";
            std::cout.flush();
        });
    
    return 0;
}
```

## 25.4 Fájlműveletek

```cpp
#include <filesystem>
namespace fs = std::filesystem;

// Fájl létezik ellenőrzés
bool fajlLetezik(const std::string& ut) {
    return fs::exists(ut);
}

// Könyvtár létrehozása
bool konyvtarLetrehozasa(const std::string& ut) {
    return fs::create_directories(ut);
}

// Fájlnév kinyerése
std::string fajlNev(const std::string& ut) {
    return fs::path(ut).filename().string();
}

// Kiterjesztés kinyerése
std::string kiterjesztes(const std::string& ut) {
    return fs::path(ut).extension().string();
}

// Fájlméret
uintmax_t fajlMeret(const std::string& ut) {
    return fs::file_size(ut);
}

// Összes fájl listázása könyvtárban
std::vector<std::string> fajlokListazasa(const std::string& konyvtar) {
    std::vector<std::string> fajlok;
    
    for (const auto& entry : fs::directory_iterator(konyvtar)) {
        if (entry.is_regular_file()) {
            fajlok.push_back(entry.path().string());
        }
    }
    
    return fajlok;
}

// Rekurzív fájlok listázása
std::vector<std::string> fajlokRekurziv(const std::string& konyvtar) {
    std::vector<std::string> fajlok;
    
    for (const auto& entry : fs::recursive_directory_iterator(konyvtar)) {
        if (entry.is_regular_file()) {
            fajlok.push_back(entry.path().string());
        }
    }
    
    return fajlok;
}

// Fájl törlése
bool fajlTorlese(const std::string& ut) {
    return fs::remove(ut);
}

// Fájl átnevezése
bool fajlAtnevezese(const std::string& regi, const std::string& uj) {
    try {
        fs::rename(regi, uj);
        return true;
    } catch (...) {
        return false;
    }
}

// Használat
int main() {
    std::cout << "Fájl létezik: " << fajlLetezik("test.txt") << std::endl;
    std::cout << "Fájlnév: " << fajlNev("/home/user/test.txt") << std::endl;
    std::cout << "Kiterjesztés: " << kiterjesztes("/home/user/test.txt") << std::endl;
    std::cout << "Méret: " << fajlMeret("test.txt") << " bájt" << std::endl;
    
    auto fajlok = fajlokListazasa(".");
    for (const auto& f : fajlok) {
        std::cout << "  - " << f << std::endl;
    }
    
    return 0;
}
```

---

# 26. fejezet: Konstruktorok és speciális metódusok

## 26.1 Konstruktorok típusai

### Alap konstruktorok:

```cpp
class Szemely {
private:
    std::string nev;
    int kor;
    double magassag;
    
public:
    // 1. Alapértelmezett konstruktor
    Szemely() : nev("Ismeretlen"), kor(0), magassag(0.0) {
        std::cout << "Alapértelmezett konstruktor" << std::endl;
    }
    
    // 2. Paraméteres konstruktor
    Szemely(std::string n, int k, double m) 
        : nev(n), kor(k), magassag(m) {
        std::cout << "Paraméteres konstruktor" << std::endl;
    }
    
    // 3. Másoló konstruktor
    Szemely(const Szemely& masik) 
        : nev(masik.nev), kor(masik.kor), magassag(masik.magassag) {
        std::cout << "Másoló konstruktor" << std::endl;
    }
    
    // 4. Mozgató (move) konstruktor (C++11)
    Szemely(Szemely&& masik) noexcept
        : nev(std::move(masik.nev)), 
          kor(masik.kor), 
          magassag(masik.magassag) {
        masik.kor = 0;
        masik.magassag = 0.0;
        std::cout << "Mozgató konstruktor" << std::endl;
    }
    
    // 5. Delegáló konstruktor (C++11)
    Szemely(std::string n) : Szemely(n, 0, 0.0) {
        std::cout << "Delegáló konstruktor" << std::endl;
    }
    
    // Destruktor
    ~Szemely() {
        std::cout << "Destruktor: " << nev << std::endl;
    }
    
    // Getterek
    std::string getNev() const { return nev; }
    int getKor() const { return kor; }
    double getMagassag() const { return magassag; }
};

// Használat
int main() {
    Szemely s1;                          // Alapértelmezett
    Szemely s2("János", 25, 180.0);     // Paraméteres
    Szemely s3(s2);                      // Másoló
    Szemely s4 = s2;                     // Másoló (egyforma)
    Szemely s5("Éva");                   // Delegáló
    
    // Mozgató
    Szemely s6 = std::move(s5);          // Move constructor
    
    return 0;
}
```

## 26.2 Inicializáló lista

```cpp
class Termek {
private:
    std::string nev;      // Referencia vagy const tag
    const int id;         // const tag
    double& arRef;        // Referencia tag
    double ar;
    
public:
    // Inicializáló lista KÖTELEZŐ referencia és const tagokhoz
    Termek(std::string n, int i, double& a) 
        : nev(n),         // Itt inicializáljuk
          id(i),          // const tag
          arRef(a),       // referencia tag
          ar(a) {         // normál tag
        // A törzsben már csak赋值 lehetséges
    }
    
    // HIBA: Ez nem működne!
    /*
    TermekHibas(std::string n, int i) {
        id = i;  // HIBA! const tag nem赋值ható
    }
    */
};
```

## 26.3 Konverziós konstruktorok

```cpp
class Távolság {
private:
    double meter;
    
public:
    // Konverziós konstruktor
    Távolság(double m) : meter(m) {}
    
    // Explicit konverziós konstruktor (C++11)
    explicit Távolság(int km) : meter(km * 1000.0) {}
    
    double getMeter() const { return meter; }
    double getKilometer() const { return meter / 1000.0; }
};

// Használat
int main() {
    Távolság t1 = 5.5;        // Implicit konverzió
    Távolság t2(3);           // Explicit (int -> km -> meter)
    Távolság t3 = Távolság(2); // Explicit kulcsszóval
    
    // Explicit nélkül:
    // Távolság t4 = 2;  // HIBA! explicit miatt
    
    return 0;
}
```

## 26.4 Operátor túlterhelés

```cpp
class Komplex {
private:
    double valos;
    double kepzetes;
    
public:
    // Konstruktorok
    Komplex(double v = 0, double k = 0) : valos(v), kepzetes(k) {}
    
    // Összeadás
    Komplex operator+(const Komplex& other) const {
        return Komplex(valos + other.valos, kepzetes + other.kepzetes);
    }
    
    // Kivonás
    Komplex operator-(const Komplex& other) const {
        return Komplex(valos - other.valos, kepzetes - other.kepzetes);
    }
    
    // Szorzás
    Komplex operator*(const Komplex& other) const {
        return Komplex(
            valos * other.valos - kepzetes * other.kepzetes,
            valos * other.kepzetes + kepzetes * other.valos
        );
    }
    
    // Egyenlőség
    bool operator==(const Komplex& other) const {
        return valos == other.valos && kepzetes == other.kepzetes;
    }
    
    // Kiírás
    friend std::ostream& operator<<(std::ostream& os, const Komplex& k) {
        os << k.valos;
        if (k.kepzetes >= 0) os << "+";
        os << k.kepzetes << "i";
        return os;
    }
    
    // Előtagos negálás
    Komplex operator-() const {
        return Komplex(-valos, -kepzetes);
    }
    
    // Értékadó operátor
    Komplex& operator=(const Komplex& other) {
        if (this != &other) {
            valos = other.valos;
            kepzetes = other.kepzetes;
        }
        return *this;
    }
};

// Használat
int main() {
    Komplex a(3, 4);
    Komplex b(1, -2);
    
    Komplex c = a + b;
    std::cout << "a + b = " << c << std::endl;
    
    Komplex d = a * b;
    std::cout << "a * b = " << d << std::endl;
    
    if (a == b) {
        std::cout << "Egyenlő" << std::endl;
    }
    
    return 0;
}
```

## 26.5 Speciális metódusok (Rule of Five)

```cpp
class Buffer {
private:
    int* adat;
    size_t meret;
    
public:
    // 1. Konstruktor
    explicit Buffer(size_t m) : meret(m) {
        adat = new int[meret];
    }
    
    // 2. Destruktor
    ~Buffer() {
        delete[] adat;
    }
    
    // 3. Másoló konstruktor
    Buffer(const Buffer& other) : meret(other.meret) {
        adat = new int[meret];
        std::copy(other.adat, other.adat + meret, adat);
    }
    
    // 4. Másoló értékadó operátor
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] adat;
            meret = other.meret;
            adat = new int[meret];
            std::copy(other.adat, other.adat + meret, adat);
        }
        return *this;
    }
    
    // 5. Mozgató konstruktor
    Buffer(Buffer&& other) noexcept 
        : adat(other.adat), meret(other.meret) {
        other.adat = nullptr;
        other.meret = 0;
    }
    
    // 6. Mozgató értékadó operátor
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] adat;
            adat = other.adat;
            meret = other.meret;
            other.adat = nullptr;
            other.meret = 0;
        }
        return *this;
    }
    
    // Elem elérés
    int& at(size_t index) { return adat[index]; }
    const int& at(size_t index) const { return adat[index]; }
    size_t size() const { return meret; }
};

// Használat
int main() {
    Buffer b1(10);
    b1.at(0) = 42;
    
    Buffer b2 = b1;           // Másoló konstruktor
    Buffer b3(std::move(b1)); // Mozgató konstruktor
    
    return 0;
}
```

---

# 27. fejezet: AI fejlesztés C++-ban

## 27.1 Bevezetés az AI programozásba

C++ előnyei AI fejlesztéshez:
- **Gyorsaság**: Kritikus számításokhoz ideális
- **Memória kontroll**: Közvetlen hardver hozzáférés
- **Könyvtárak**: TensorFlow, PyTorch C++ API

## 27.2 Egyszerű neurális hálózat implementáció

```cpp
#include <vector>
#include <cmath>
#include <random>
#include <functional>

// Aktivációs függvények
double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

double sigmoidDerivalt(double x) {
    double s = sigmoid(x);
    return s * (1 - s);
}

double relu(double x) {
    return std::max(0.0, x);
}

// Neurális hálózat réteg
class Reteg {
private:
    std::vector<std::vector<double>> sulyok;  // Súlymátrix
    std::vector<double> biasok;
    std::vector<double> kimenetek;
    
public:
    Reteg(int bemenetMeret, int kimenetMeret) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-0.5, 0.5);
        
        // Súlyok inicializálása
        sulyok.resize(kimenetMeret, std::vector<double>(bemenetMeret));
        for (auto& sor : sulyok) {
            for (auto& elem : sor) {
                elem = dis(gen);
            }
        }
        
        // Biasok inicializálása
        biasok.resize(kimenetMeret);
        for (auto& b : biasok) {
            b = dis(gen);
        }
        
        kimenetek.resize(kimenetMeret);
    }
    
    // Előrefuttatás
    std::vector<double> forward(const std::vector<double>& bemenet) {
        for (size_t i = 0; i < kimenetek.size(); i++) {
            double osszeg = biasok[i];
            
            for (size_t j = 0; j < bemenet.size(); j++) {
                osszeg += bemenet[j] * sulyok[i][j];
            }
            
            kimenetek[i] = sigmoid(osszeg);
        }
        
        return kimenetek;
    }
    
    // Súlyok frissítése (egyszerűsített)
    void frissitSulyok(const std::vector<double>& bemenet,
                       const std::vector<double>& hibak,
                       double tanulasiRata) {
        for (size_t i = 0; i < hibak.size(); i++) {
            for (size_t j = 0; j < bemenet.size(); j++) {
                sulyok[i][j] += tanulasiRata * hibak[i] * bemenet[j];
            }
            biasok[i] += tanulasiRata * hibak[i];
        }
    }
    
    const std::vector<double>& getKimenetek() const { return kimenetek; }
    const std::vector<std::vector<double>>& getSulyok() const { return sulyok; }
};

// Teljes neurális hálózat
class NeuralisHalozat {
private:
    std::vector<Reteg> retegek;
    
public:
    NeuralisHalozat(const std::vector<int>& retegezes) {
        for (size_t i = 1; i < retegezes.size(); i++) {
            retegek.emplace_back(retegezes[i-1], retegezes[i]);
        }
    }
    
    // Előrefuttatás
    std::vector<double> predict(const std::vector<double>& bemenet) {
        std::vector<double> aktualis = bemenet;
        
        for (auto& reteg : retegek) {
            aktualis = reteg.forward(aktualis);
        }
        
        return aktualis;
    }
    
    // Tanítás (egyszerűsített backpropagation)
    void tanit(const std::vector<std::vector<double>>& bemenetek,
               const std::vector<std::vector<double>>& kimenetek,
               int epohak,
               double tanulasiRata) {
        
        for (int epoha = 0; epoha < epohak; epoha++) {
            double osszHiba = 0;
            
            for (size_t i = 0; i < bemenetek.size(); i++) {
                // Előrefuttatás
                auto predikcio = predict(bemenetek[i]);
                
                // Hiba számítása
                std::vector<double> hibak;
                for (size_t j = 0; j < kimenetek[i].size(); j++) {
                    double hiba = kimenetek[i][j] - predikcio[j];
                    hibak.push_back(hiba);
                    osszHiba += hiba * hiba;
                }
                
                // Visszafelé terjesztés (egyszerűsített)
                retegek.back().frissitSulyok(
                    retegek.size() > 1 
                        ? retegek[retegek.size()-2].getKimenetek()
                        : bemenetek[i],
                    hibak,
                    tanulasiRata
                );
            }
            
            if (epoha % 100 == 0) {
                std::cout << "Epoha " << epoha << ", Hiba: " 
                          << osszHiba / bemenetek.size() << std::endl;
            }
        }
    }
};

// Használat - XOR probléma
int main() {
    // Bemenetek és kimenetek (XOR kapu)
    std::vector<std::vector<double>> bemenetek = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    
    std::vector<std::vector<double>> kimenetek = {
        {0},
        {1},
        {1},
        {0}
    };
    
    // Hálózat létrehozása: 2 bemenet, 4 rejtett, 1 kimenet
    NeuralisHalozat halozat({2, 4, 1});
    
    // Tanítás
    halozat.tanit(bemenetek, kimenetek, 10000, 0.1);
    
    // Tesztelés
    std::cout << "\nTesztelés:" << std::endl;
    for (size_t i = 0; i < bemenetek.size(); i++) {
        auto eredmeny = halozat.predict(bemenetek[i]);
        std::cout << bemenetek[i][0] << " XOR " << bemenetek[i][1] 
                  << " = " << eredmeny[0] << std::endl;
    }
    
    return 0;
}
```

## 27.3 Egyszerű döntési fa

```cpp
#include <vector>
#include <memory>
#include <algorithm>

struct AdatMinta {
    std::vector<double> jellemzok;
    int cimke;
};

class DontesiFaCsomopont {
public:
    int jellemzoIndex;
    double kuszobErtek;
    int cimke;  // Lev csomópont esetén
    std::shared_ptr<DontesiFaCsomopont> bal;
    std::shared_ptr<DontesiFaCsomopont> jobb;
    bool lev;
    
    DontesiFaCsomopont() : jellemzoIndex(-1), kuszobErtek(0), 
                           cimke(0), lev(false) {}
};

class DontesiFa {
private:
    std::shared_ptr<DontesiFaCsomopont> gyoker;
    
    // Gini impurity számítása
    double gini(const std::vector<AdatMinta>& mintak) {
        if (mintak.empty()) return 0;
        
        std::map<int, int> cimkeSzamlalo;
        for (const auto& minta : mintak) {
            cimkeSzamlalo[minta.cimke]++;
        }
        
        double giniErtek = 1.0;
        for (const auto& [cimke, szamlalo] : cimkeSzamlalo) {
            double p = static_cast<double>(szamlalo) / mintak.size();
            giniErtek -= p * p;
        }
        
        return giniErtek;
    }
    
    // Legjobb osztás keresése
    void keresOsztast(const std::vector<AdatMinta>& mintak,
                      int& legjobbJellemzo,
                      double& legjobbKuszob,
                      double& legjobbGini) {
        
        legjobbGini = 1.0;
        int jellemzoSzam = mintak[0].jellemzok.size();
        
        for (int j = 0; j < jellemzoSzam; j++) {
            // Értékek gyűjtése
            std::set<double> ertekek;
            for (const auto& m : mintak) {
                ertekek.insert(m.jellemzok[j]);
            }
            
            // Küszöbértékek kipróbálása
            for (double kuszob : ertekek) {
                std::vector<AdatMinta> bal, jobb;
                
                for (const auto& m : mintak) {
                    if (m.jellemzok[j] <= kuszob) {
                        bal.push_back(m);
                    } else {
                        jobb.push_back(m);
                    }
                }
                
                if (bal.empty() || jobb.empty()) continue;
                
                // Súlyozott Gini
                double giniBal = gini(bal);
                double giniJobb = gini(jobb);
                double sulyozottGini = 
                    (bal.size() * giniBal + jobb.size() * giniJobb) / mintak.size();
                
                if (sulyozottGini < legjobbGini) {
                    legjobbGini = sulyozottGini;
                    legjobbJellemzo = j;
                    legjobbKuszob = kuszob;
                }
            }
        }
    }
    
    // Fa építése rekurzívan
    std::shared_ptr<DontesiFaCsomopont> epitFa(
        std::vector<AdatMinta> mintak, 
        int melyseg,
        int maxMelyseg) {
        
        auto csomopont = std::make_shared<DontesiFaCsomopont>();
        
        // Lev csomópont feltételei
        if (melyseg >= maxMelyseg || mintak.size() < 2) {
            csomopont->lev = true;
            // Leggyakoribb címke
            std::map<int, int> szamlalo;
            for (const auto& m : mintak) {
                szamlalo[m.cimke]++;
            }
            csomopont->cimke = std::max_element(
                szamlalo.begin(), szamlalo.end(),
                [](const auto& a, const auto& b) { return a.second < b.second; }
            )->first;
            return csomopont;
        }
        
        // Osztás keresése
        int legjobbJellemzo;
        double legjobbKuszob, legjobbGini;
        keresOsztast(mintak, legjobbJellemzo, legjobbKuszob, legjobbGini);
        
        if (legjobbJellemzo == -1) {
            // Nem találtunk jó osztást
            csomopont->lev = true;
            std::map<int, int> szamlalo;
            for (const auto& m : mintak) {
                szamlalo[m.cimke]++;
            }
            csomopont->cimke = szamlalo.begin()->first;
            return csomopont;
        }
        
        // Csomópont beállítása
        csomopont->jellemzoIndex = legjobbJellemzo;
        csomopont->kuszobErtek = legjobbKuszob;
        
        // Adatok szétválogatása
        std::vector<AdatMinta> bal, jobb;
        for (const auto& m : mintak) {
            if (m.jellemzok[legjobbJellemzo] <= legjobbKuszob) {
                bal.push_back(m);
            } else {
                jobb.push_back(m);
            }
        }
        
        // Rekurzív építés
        csomopont->bal = epitFa(bal, melyseg + 1, maxMelyseg);
        csomopont->jobb = epitFa(jobb, melyseg + 1, maxMelyseg);
        
        return csomopont;
    }
    
    // Predikció egy csomóponton
    int predikal(const std::shared_ptr<DontesiFaCsomopont>& csomopont,
                 const std::vector<double>& jellemzok) const {
        
        if (csomopont->lev) {
            return csomopont->cimke;
        }
        
        if (jellemzok[csomopont->jellemzoIndex] <= csomopont->kuszobErtek) {
            return predikal(csomopont->bal, jellemzok);
        } else {
            return predikal(csomopont->jobb, jellemzok);
        }
    }
    
public:
    void tanit(const std::vector<AdatMinta>& mintak, int maxMelyseg = 5) {
        gyoker = epitFa(mintak, 0, maxMelyseg);
    }
    
    int predikal(const std::vector<double>& jellemzok) const {
        return predikal(gyoker, jellemzok);
    }
};

// Használat
int main() {
    // Tanító adatok (AND kapu szimuláció)
    std::vector<AdatMinta> mintak = {
        {{0, 0}, 0},
        {{0, 1}, 0},
        {{1, 0}, 0},
        {{1, 1}, 1}
    };
    
    DontesiFa fa;
    fa.tanit(mintak);
    
    // Tesztelés
    std::cout << "0 AND 0 = " << fa.predikal({0, 0}) << std::endl;
    std::cout << "0 AND 1 = " << fa.predikal({0, 1}) << std::endl;
    std::cout << "1 AND 0 = " << fa.predikal({1, 0}) << std::endl;
    std::cout << "1 AND 1 = " << fa.predikal({1, 1}) << std::endl;
    
    return 0;
}
```

## 27.4 K-means klaszterezés

```cpp
#include <vector>
#include <cmath>
#include <random>
#include <limits>

struct Pont {
    double x, y;
    int klaszter = -1;
};

double tavolsag(const Pont& a, const Pont& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

class KMeans {
private:
    int k;
    std::vector<Pont> kozpontok;
    
public:
    KMeans(int klaszterekSzama) : k(klaszterekSzama) {}
    
    void tanit(std::vector<Pont>& pontok, int maxIteracio = 100) {
        // Kezdeti központok véletlenszerűen
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, pontok.size() - 1);
        
        kozpontok.clear();
        for (int i = 0; i < k; i++) {
            kozpontok.push_back(pontok[dis(gen)]);
        }
        
        for (int iter = 0; iter < maxIteracio; iter++) {
            bool valtozas = false;
            
            // 1. lépés: Pontok hozzárendelése legközelebbi központhoz
            for (auto& pont : pontok) {
                int legjobbKlaszter = 0;
                double legkisebbTav = std::numeric_limits<double>::max();
                
                for (int i = 0; i < k; i++) {
                    double tav = tavolsag(pont, kozpontok[i]);
                    if (tav < legkisebbTav) {
                        legkisebbTav = tav;
                        legjobbKlaszter = i;
                    }
                }
                
                if (pont.klaszter != legjobbKlaszter) {
                    pont.klaszter = legjobbKlaszter;
                    valtozas = true;
                }
            }
            
            // Ha nincs változás, kész vagyunk
            if (!valtozas) break;
            
            // 2. lépés: Központok frissítése
            for (int i = 0; i < k; i++) {
                double osszX = 0, osszY = 0;
                int db = 0;
                
                for (const auto& pont : pontok) {
                    if (pont.klaszter == i) {
                        osszX += pont.x;
                        osszY += pont.y;
                        db++;
                    }
                }
                
                if (db > 0) {
                    kozpontok[i].x = osszX / db;
                    kozpontok[i].y = osszY / db;
                }
            }
        }
    }
    
    void kiirEredmeny(const std::vector<Pont>& pontok) {
        for (int i = 0; i < k; i++) {
            std::cout << "Klaszter " << i << " központja: ("
                      << kozpontok[i].x << ", " << kozpontok[i].y << ")" << std::endl;
        }
        
        std::cout << "\nPontok hozzárendelése:" << std::endl;
        for (const auto& pont : pontok) {
            std::cout << "(" << pont.x << ", " << pont.y 
                      << ") -> Klaszter " << pont.klaszter << std::endl;
        }
    }
};

// Használat
int main() {
    std::vector<Pont> pontok = {
        {1, 2}, {1.5, 1.8}, {5, 8}, {8, 8}, {1, 0.6}, {9, 11}
    };
    
    KMeans kmeans(2);
    kmeans.tanit(pontok);
    kmeans.kiirEredmeny(pontok);
    
    return 0;
}
```

---

# 28. fejezet: Fontos kiegészítő témák

## 28.1 Időmérés és időzítés

```cpp
#include <chrono>
#include <iostream>
#include <thread>

// Függvény futási idejének mérése
template<typename Func>
double meresiIdo(Func f) {
    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> diff = end - start;
    return diff.count();  // Másodpercben
}

// Használat
int main() {
    // Függvény futási ideje
    double ido = meresiIdo([]() {
        // Mérendő kód
        for (int i = 0; i < 1000000; i++) {
            volatile int x = i * i;
        }
    });
    
    std::cout << "Futási idő: " << ido << " mp" << std::endl;
    std::cout << "Futási idő: " << ido * 1000 << " ms" << std::endl;
    
    // Késleltetés
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    // Időzítő (timer)
    auto start = std::chrono::steady_clock::now();
    
    // ... kód ...
    
    auto most = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(most - start);
    std::cout << "Eltelt idő: " << elapsed.count() << " ms" << std::endl;
    
    return 0;
}
```

## 28.2 Random számok generálása

```cpp
#include <random>
#include <iostream>

int main() {
    // Random eszköz
    std::random_device rd;
    std::mt19937 gen(rd());  // Mersenne Twister
    
    // Egyenletes eloszlás
    std::uniform_int_distribution<> disInt(1, 100);
    std::uniform_real_distribution<> disReal(0.0, 1.0);
    
    std::cout << "Véletlen egész (1-100): " << disInt(gen) << std::endl;
    std::cout << "Véletlen valós (0-1): " << disReal(gen) << std::endl;
    
    // Normál eloszlás
    std::normal_distribution<> disNorm(10.0, 2.0);  // átlag=10, szórás=2
    std::cout << "Normál eloszlás: " << disNorm(gen) << std::endl;
    
    // Fix seed (reprodukálható)
    std::mt19937 genFix(42);
    std::cout << "Fix seed: " << disInt(genFix) << std::endl;
    
    return 0;
}
```

## 28.3 Lambda kifejezések haladóan

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> szamok = {5, 2, 8, 1, 9, 3};
    
    // Egyszerű lambda
    std::sort(szamok.begin(), szamok.end(), 
              [](int a, int b) { return a > b; });  // Csökkenő
    
    // Capture by value
    int szorzo = 3;
    auto szoroz = [szorzo](int x) { return x * szorzo; };
    std::cout << szoroz(5) << std::endl;  // 15
    
    // Capture by reference
    int osszeg = 0;
    std::for_each(szamok.begin(), szamok.end(),
                  [&osszeg](int x) { osszeg += x; });
    std::cout << "Összeg: " << osszeg << std::endl;
    
    // Mutable lambda
    int szamlalo = 0;
    auto novel = [szamlalo]() mutable {
        szamlalo++;
        return szamlalo;
    };
    
    // Általános lambda (C++14)
    auto osszead = [](auto a, auto b) { return a + b; };
    std::cout << osszead(2, 3.5) << std::endl;  // 5.5
    
    // Lambda visszatérési típussal
    auto negyzet = [](double x) -> double {
        return x * x;
    };
    
    return 0;
}
```

## 28.4 Smart pointerek részletesen

```cpp
#include <memory>
#include <iostream>
#include <vector>

// unique_ptr - egyedüli tulajdonos
void uniquePtrPelda() {
    std::unique_ptr<int> ptr1 = std::make_unique<int>(42);
    std::unique_ptr<int> ptr2 = std::move(ptr1);  // Tulajdon átruházás
    
    // ptr1 most nullptr!
    if (!ptr1) {
        std::cout << "ptr1 nullptr" << std::endl;
    }
    
    std::cout << *ptr2 << std::endl;  // 42
    
    // unique_ptr tömbhöz
    auto tomb = std::make_unique<int[]>(10);
    tomb[0] = 100;
}

// shared_ptr - megosztott tulajdon
void sharedPtrPelda() {
    auto s1 = std::make_shared<int>(42);
    auto s2 = s1;  // Megosztott tulajdon
    
    std::cout << "Referenciaszámláló: " << s1.use_count() << std::endl;  // 2
    
    auto s3 = s2;
    std::cout << "Referenciaszámláló: " << s1.use_count() << std::endl;  // 3
    
    // weak_ptr - nem tulajdonló referencia
    std::weak_ptr<int> gyenge = s1;
    std::cout << "Weak count: " << gyenge.use_count() << std::endl;
    
    // Biztonságos hozzáférés
    if (auto lock = gyenge.lock()) {
        std::cout << "Érték: " << *lock << std::endl;
    }
}

// Custom deleter
void customDeleter() {
    auto deleter = [](int* p) {
        std::cout << "Egyedi törlő: " << *p << std::endl;
        delete p;
    };
    
    std::unique_ptr<int, decltype(deleter)> ptr(new int(5), deleter);
}

// Körkörös hivatkozás elkerülése
struct B;

struct A {
    std::shared_ptr<B> b;
    ~A() { std::cout << "A törölve" << std::endl; }
};

struct B {
    std::weak_ptr<A> a;  // weak_ptr a körkörös hivatkozás elkerülésére!
    ~B() { std::cout << "B törölve" << std::endl; }
};

void kormentosPelda() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    
    a->b = b;
    b->a = a;  // weak_ptr, nem növeli a referenciaszámlálót
}

int main() {
    uniquePtrPelda();
    sharedPtrPelda();
    customDeleter();
    kormentosPelda();
    
    return 0;
}
```

## 28.5 Constexpr és compile-time számítások

```cpp
#include <iostream>
#include <array>

// Constexpr függvények
constexpr int faktorialis(int n) {
    return (n <= 1) ? 1 : n * faktorialis(n - 1);
}

constexpr int fibonacci(int n) {
    return (n <= 2) ? 1 : fibonacci(n-1) + fibonacci(n-2);
}

// Constexpr osztály
class constexprPont {
public:
    double x, y;
    
    constexpr constexprPont(double xVal, double yVal) 
        : x(xVal), y(yVal) {}
    
    constexpr double tavolsagOrigotol() const {
        return std::sqrt(x * x + y * y);
    }
};

// Constexpr tömb
constexpr auto szamok = std::array{1, 2, 3, 4, 5};

int main() {
    // Fordítási időben kiértékelt értékek
    constexpr int fakt5 = faktorialis(5);  // 120
    constexpr int fib10 = fibonacci(10);   // 55
    
    constexpr Pont p(3.0, 4.0);
    constexpr double tav = p.tavolsagOrigotol();  // 5.0
    
    std::cout << "5! = " << fakt5 << std::endl;
    std::cout << "Fib(10) = " << fib10 << std::endl;
    std::cout << "Távolság: " << tav << std::endl;
    
    return 0;
}
```

## 28.6 Variadikus template-ek

```cpp
#include <iostream>

// Variadikus függvény sablon
template<typename T>
T osszeg(T ertek) {
    return ertek;
}

template<typename T, typename... Args>
T osszeg(T elso, Args... rest) {
    return elso + osszeg(rest...);
}

// Kiírás több argumentummal
void kiir() {
    std::cout << std::endl;
}

template<typename T, typename... Args>
void kiir(T elso, Args... rest) {
    std::cout << elso << " ";
    kiir(rest...);
}

// Használat
int main() {
    std::cout << "Összeg: " << osszeg(1, 2, 3, 4, 5) << std::endl;  // 15
    std::cout << "Összeg: " << osszeg(1.5, 2.5, 3.0) << std::endl;  // 7.0
    
    std::cout << "Értékek: ";
    kiir(1, 2.5, "Hello", 'A', 42);
    
    return 0;
}
```

## 28.7 Type traits és SFINAE

```cpp
#include <type_traits>
#include <iostream>
#include <string>

// Type traits használata
template<typename T>
void vizsgal(T t) {
    std::cout << "Típus vizsgálata:" << std::endl;
    std::cout << "  Egész: " << std::is_integral<T>::value << std::endl;
    std::cout << "  Lebegőpontos: " << std::is_floating_point<T>::value << std::endl;
    std::cout << "  Pointer: " << std::is_pointer<T>::value << std::endl;
    std::cout << "  Referencia: " << std::is_reference<T>::value << std::endl;
    std::cout << "  Konstans: " << std::is_const<T>::value << std::endl;
}

// enable_if használata
template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
dupla(T ertek) {
    return ertek * 2;
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
dupla(T ertek) {
    return ertek * 2.0;
}

// C++17 if constexpr
template<typename T>
void feldolgoz(T ertek) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Egész szám: " << ertek << std::endl;
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Lebegőpontos: " << ertek << std::endl;
    } else if constexpr (std::is_pointer_v<T>) {
        std::cout << "Pointer" << std::endl;
    }
}

int main() {
    vizsgal(42);
    vizsgal(3.14);
    vizsgal("Hello");
    
    std::cout << "dupla(5) = " << dupla(5) << std::endl;
    std::cout << "dupla(3.14) = " << dupla(3.14) << std::endl;
    
    feldolgoz(42);
    feldolgoz(3.14);
    feldolgoz(&vizsgal);
    
    return 0;
}
```

## 28.8 Async programozás

```cpp
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// Hosszú számítás szimulációja
int hosszuSzamitas(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return n * n;
}

int main() {
    // async hívás
    std::future<int> eredmeny = std::async(std::launch::async, hosszuSzamitas, 5);
    
    // Más munka végzése...
    std::cout << "Várakozás..." << std::endl;
    
    // Eredmény lekérése (blokkol)
    int ertek = eredmeny.get();
    std::cout << "Eredmény: " << ertek << std::endl;
    
    // packaged_task
    std::packaged_task<int(int)> task(hosszuSzamitas);
    std::future<int> f = task.get_future();
    
    std::thread t(std::move(task), 7);
    t.detach();
    
    std::cout << "packaged_task eredmény: " << f.get() << std::endl;
    
    // promise
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    
    std::thread([&prom]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        prom.set_value(100);
    }).detach();
    
    std::cout << "promise eredmény: " << fut.get() << std::endl;
    
    return 0;
}
```

## 28.9 Best practices és kódolási szokások

### 1. Kövesd a RAII elvet:

```cpp
// ROSSZ
void rosszPelda() {
    int* ptr = new int[100];
    // ... kód ...
    if (hiba) return;  // Memóriaszivárgás!
    // ... kód ...
    delete[] ptr;
}

// JÓ
void joPelda() {
    std::vector<int> vec(100);
    // ... kód ...
    if (hiba) return;  // Automatikus felszabadítás
    // ... kód ...
}
```

### 2. Használj const-ot ahol lehet:

```cpp
// ROSSZ
void fuggveny(string& s) {
    // Nem módosítja, de nem const referencia
    cout << s.length();
}

// JÓ
void fuggveny(const string& s) {
    cout << s.length();
}
```

### 3. Kerüld a nyers pointereket:

```cpp
// ROSSZ
void rossz(int* ptr) {
    delete ptr;  // Ki felelős a törlésért?
}

// JÓ
void jo(std::unique_ptr<int> ptr) {
    // Automatikus törlés
}
```

### 4. Használj nullptr-t NULL helyett:

```cpp
// ROSSZ (régi stílus)
int* ptr = NULL;

// JÓ (modern C++)
int* ptr = nullptr;
```

### 5. Preferáld az auto-t hosszú típusneveknél:

```cpp
// ROSSZ (nehezen olvasható)
std::map<std::string, std::vector<std::pair<int, double>>>::iterator it;

// JÓ (olvashatóbb)
auto it = myMap.begin();
```

### 6. Használj range-based for-t:

```cpp
// ROSSZ
for (size_t i = 0; i < vec.size(); i++) {
    cout << vec[i];
}

// JÓ
for (const auto& elem : vec) {
    cout << elem;
}
```

### 7. Initializer list használata:

```cpp
// ROSSZ
std::vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);

// JÓ
std::vector<int> v = {1, 2, 3};
```

### 8. Override kulcsszó:

```cpp
// ROSSZ
class Derivalt : public Alap {
    void fuggveny() { /* ... */ }  // Lehet hogy elgépelés?
};

// JÓ
class Derivalt : public Alap {
    void fuggveny() override { /* ... */ }  // Fordító ellenőrzi
};
```

---

**Gratulálok!** 🎉

Elkészültél a **TELJES C++ KÖNYVVEL**! Most már rendelkezel:

- ✅ C++ alapokkal és haladó ismeretekkel
- ✅ Többfájlos projektek kezelésével
- ✅ Windows GDI és natív ablakprogramozással
- ✅ Linux X11 és GTK programozással
- ✅ Matematikai képletek C++ implementációjával
- ✅ DSP (Digitális Jelfeldolgozás) ismeretekkel
- ✅ CLI programozással és multi-language támogatással
- ✅ Hálózati programozással (TCP/UDP, socket)
- ✅ Kódelemzési és reverse engineering technikákkal
- ✅ Rekurzív gondolkozásmód fejlesztésével
- ✅ Prof hibakezeléssel CLI és GUI alkalmazásokban
- ✅ **String kezeléssel és tokenizációval**
- ✅ **Fájlkezeléssel és másoló függvényekkel**
- ✅ **Konstruktorok és speciális metódusokkal**
- ✅ **AI fejlesztéssel C++-ban (neurális háló, döntési fa, K-means)**
- ✅ **Fontos kiegészítő témákkal (időmérés, random, smart pointer, constexpr, async)**

A legjobb tanulási mód a **gyakorlás** - írj minél több programot, kísérletezz a kódokkal, és oldj meg problémákat!

**Jó kódolást!** 🚀

---

# 29. fejezet: Multi-language (többnyelvű) alkalmazások készítése

## 29.1 Bevezetés a többnyelvű alkalmazásokba

A modern alkalmazások gyakran támogatnak több nyelvet. Ez a fejezet bemutatja, hogyan készíthetsz olyan CLI és GUI alkalmazásokat, amelyek dinamikusan váltanak nyelveket.

### A többnyelvűség típusai:

1. **Statikus fordítás** - Fordítási időben rögzített nyelvek
2. **Dinamikus fordítás** - Futási időben betöltött nyelvi fájlok
3. **Hibrid megoldás** - Alapnyelv statikus, további nyelvek dinamikusan

## 29.2 CLI alkalmazások többnyelvűsége

### Alap struktúra - Globális változók és nyelv kezelő:

```cpp
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

// ============ GLOBÁLIS VÁLTOZÓK ============
int selectedLanguageIndex = 1;  // 1=English, 2=Magyar, 3=Deutsch
bool saveToFile = false;
bool singleLineOutput = false;

// Nyelvi szótár
std::map<std::string, std::string> lang;

// ============ NYELV KEZELŐ OSZTÁLY ============
class LanguageManager {
private:
    std::map<int, std::string> languages;
    
public:
    LanguageManager() {
        languages[1] = "English";
        languages[2] = "Magyar";
        languages[3] = "Deutsch";
        languages[4] = "Français";
        languages[5] = "Español";
    }
    
    bool loadLanguage(int index) {
        auto it = languages.find(index);
        if (it == languages.end()) return false;
        
        std::string filename = "lang/" + it->second + ".ini";
        std::ifstream file(filename);
        
        if (!file.is_open()) {
            std::cerr << "Nem tölthető be: " << filename << std::endl;
            return false;
        }
        
        lang.clear();
        std::string line;
        
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '#' || line[0] == ';') continue;
            
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = trim(line.substr(0, pos));
                std::string value = trim(line.substr(pos + 1));
                lang[key] = value;
            }
        }
        
        selectedLanguageIndex = index;
        saveSettings();
        return true;
    }
    
    std::string get(const std::string& key, const std::string& def = "") {
        auto it = lang.find(key);
        return (it != lang.end()) ? it->second : def;
    }
    
private:
    std::string trim(const std::string& s) {
        size_t start = s.find_first_not_of(" \t\n\r");
        if (start == std::string::npos) return "";
        size_t end = s.find_last_not_of(" \t\n\r");
        return s.substr(start, end - start + 1);
    }
};

LanguageManager langMgr;

// Segédfüggvény a fordításhoz
#define TR(key) langMgr.get(key, key)
```

### Nyelvi fájlok példák:

**lang/English.ini:**
```ini
# English translations
app_title=Translator Application
welcome=Welcome to the Translator!
menu_title=--- MAIN MENU ---
menu_translate=1. Start Translation
menu_settings=2. Settings
menu_exit=3. Exit
prompt_choice=Your choice: 
error_invalid=Invalid choice!
settings_title=--- SETTINGS ---
settings_save=Save to file: 
settings_singleline=Single line output: 
settings_language=3. Language Settings
settings_back=4. Back to Main Menu
lang_select_title=--- LANGUAGE SETTINGS ---
lang_current=Current: 
lang_english=English -> Hungarian
lang_hungarian=Hungarian -> English
lang_back=3. Back
translation_input=Enter text to translate:
translation_result=Translation:
goodbye=Goodbye!
on=ON
off=OFF
```

**lang/Magyar.ini:**
```ini
# Magyar fordítások
app_title=Fordító Alkalmazás
welcome=Üdvözöllek a Fordítóban!
menu_title=--- FŐMENÜ ---
menu_translate=1. Fordítás indítása
menu_settings=2. Beállítások
menu_exit=3. Kilépés
prompt_choice=Választás: 
error_invalid=Érvénytelen választás!
settings_title=--- BEÁLLÍTÁSOK ---
settings_save=Fájlba mentés: 
settings_singleline=Egy soros kiírás: 
settings_language=3. Nyelv beállítás
settings_back=4. Vissza a főmenübe
lang_select_title=--- NYELV BEÁLLÍTÁS ---
lang_current=Jelenlegi: 
lang_english=Angol -> Magyar
lang_hungarian=Magyar -> Angol
lang_back=3. Vissza
translation_input=Írd be a fordítandó szöveget:
translation_result=Fordítás:
goodbye=Viszlát!
on=BE
off=KI
```

**lang/Deutsch.ini:**
```ini
# Deutsche Übersetzungen
app_title=Übersetzer Anwendung
welcome=Willkommen beim Übersetzer!
menu_title=--- HAUPTMENÜ ---
menu_translate=1. Übersetzung starten
menu_settings=2. Einstellungen
menu_exit=3. Beenden
prompt_choice=Ihre Wahl: 
error_invalid=Ungültige Wahl!
settings_title=--- EINSTELLUNGEN ---
settings_save=In Datei speichern: 
settings_singleline=Einzeilige Ausgabe: 
settings_language=3. Spracheinstellungen
settings_back=4. Zurück zum Hauptmenü
lang_select_title=--- SPRACHEINSTELLUNGEN ---
lang_current=Aktuell: 
lang_english=Englisch -> Ungarisch
lang_hungarian=Ungarisch -> Englisch
lang_back=3. Zurück
translation_input=Text zur Übersetzung eingeben:
translation_result=Übersetzung:
goodbye=Auf Wiedersehen!
on=EIN
off=AUS
```

### Teljes CLI példa többnyelvűséggel:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN system("cls")
#else
    #define CLEAR_SCREEN system("clear")
#endif

// ============ GLOBÁLIS VÁLTOZÓK ============
int selectedLanguageIndex = 1;
bool saveToFile = false;
bool singleLineOutput = false;

// Nyelvi szótár
std::map<std::string, std::string> lang;

// ============ NYELV KEZELŐ OSZTÁLY ============
class LanguageManager {
private:
    std::map<int, std::string> languages;
    
public:
    LanguageManager() {
        languages[1] = "English";
        languages[2] = "Magyar";
        languages[3] = "Deutsch";
        languages[4] = "Français";
    }
    
    bool loadLanguage(int index) {
        auto it = languages.find(index);
        if (it == languages.end()) return false;
        
        std::string filename = "lang/" + it->second + ".ini";
        std::ifstream file(filename);
        
        if (!file.is_open()) {
            std::cerr << "Nem tölthető be: " << filename << std::endl;
            return false;
        }
        
        lang.clear();
        std::string line;
        
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '#' || line[0] == ';') continue;
            
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = trim(line.substr(0, pos));
                std::string value = trim(line.substr(pos + 1));
                lang[key] = value;
            }
        }
        
        selectedLanguageIndex = index;
        saveSettings();
        return true;
    }
    
    std::string get(const std::string& key, const std::string& def = "") {
        auto it = lang.find(key);
        return (it != lang.end()) ? it->second : def;
    }
    
    void showLanguageMenu() {
        CLEAR_SCREEN;
        std::cout << "\n=== LANGUAGE SETTINGS ===\n";
        std::cout << "Current: " << languages[selectedLanguageIndex] << "\n\n";
        
        for (const auto& [idx, name] : languages) {
            std::cout << "  " << idx << ". " << name << "\n";
        }
        std::cout << "  " << languages.size() + 1 << ". Back\n";
        std::cout << "\nChoice: ";
        
        std::string choice;
        std::getline(std::cin, choice);
        
        int idx = std::stoi(choice);
        if (idx > 0 && idx <= (int)languages.size()) {
            loadLanguage(idx);
        }
    }
    
private:
    std::string trim(const std::string& s) {
        size_t start = s.find_first_not_of(" \t\n\r");
        if (start == std::string::npos) return "";
        size_t end = s.find_last_not_of(" \t\n\r");
        return s.substr(start, end - start + 1);
    }
};

LanguageManager langMgr;

// ============ SEGÉDFÜGGVÉNYEK ============
std::string TR(const std::string& key) {
    return langMgr.get(key, key);
}

void saveSettings() {
    std::ofstream f("config.sav");
    if (f.is_open()) {
        f << "language=" << selectedLanguageIndex << "\n";
        f << "saveToFile=" << (saveToFile ? '1' : '0') << "\n";
        f << "singleLineOutput=" << (singleLineOutput ? '1' : '0') << "\n";
        f.close();
    }
}

void loadSettings() {
    std::ifstream f("config.sav");
    if (f.is_open()) {
        std::string line;
        while (std::getline(f, line)) {
            if (line.find("language=") != std::string::npos) {
                selectedLanguageIndex = std::stoi(line.substr(9));
            } else if (line.find("saveToFile=") != std::string::npos) {
                saveToFile = (line[11] == '1');
            } else if (line.find("singleLineOutput=") != std::string::npos) {
                singleLineOutput = (line[17] == '1');
            }
        }
        f.close();
    }
    langMgr.loadLanguage(selectedLanguageIndex);
}

// ============ MENÜK ============
void languageMenu() {
    while (true) {
        CLEAR_SCREEN;
        std::cout << "\n--- " << TR("lang_select_title") << " ---\n";
        std::cout << TR("lang_current") << " " 
                  << (selectedLanguageIndex == 1 ? "English" : 
                      selectedLanguageIndex == 2 ? "Magyar" : "Deutsch") 
                  << "\n\n";
        
        std::cout << "1. English -> Magyar\n";
        std::cout << "2. Magyar -> English\n";
        std::cout << "3. Deutsch\n";
        std::cout << "4. Français\n";
        std::cout << "5. Back\n";
        std::cout << TR("prompt_choice");
        
        std::string choice;
        std::getline(std::cin, choice);
        
        if (choice == "1") {
            selectedLanguageIndex = 1;
            langMgr.loadLanguage(1);
        } else if (choice == "2") {
            selectedLanguageIndex = 2;
            langMgr.loadLanguage(2);
        } else if (choice == "3") {
            selectedLanguageIndex = 3;
            langMgr.loadLanguage(3);
        } else if (choice == "4") {
            selectedLanguageIndex = 4;
            langMgr.loadLanguage(4);
        } else if (choice == "5") {
            break;
        }
    }
}

void settingsMenu() {
    while (true) {
        CLEAR_SCREEN;
        std::cout << "\n--- " << TR("settings_title") << " ---\n";
        std::cout << "1. " << TR("settings_save") << " " 
                  << (saveToFile ? TR("on") : TR("off")) << "\n";
        std::cout << "2. " << TR("settings_singleline") << " " 
                  << (singleLineOutput ? TR("on") : TR("off")) << "\n";
        std::cout << "3. " << TR("settings_language") << "\n";
        std::cout << "4. " << TR("settings_back") << "\n";
        std::cout << TR("prompt_choice");
        
        std::string choice;
        std::getline(std::cin, choice);
        
        if (choice == "1") {
            saveToFile = !saveToFile;
            saveSettings();
        } else if (choice == "2") {
            singleLineOutput = !singleLineOutput;
            saveSettings();
        } else if (choice == "3") {
            languageMenu();
        } else if (choice == "4") {
            break;
        }
    }
}

void translationMenu() {
    CLEAR_SCREEN;
    std::cout << "\n--- " << TR("translation_input") << " ---\n";
    std::cout << "> ";
    
    std::string input;
    std::getline(std::cin, input);
    
    std::string result = "[TRANSLATED: " + input + "]";
    
    std::cout << "\n" << TR("translation_result") << " " << result << "\n";
    
    if (saveToFile) {
        std::ofstream out("translation_output.txt");
        out << "Input: " << input << "\n";
        out << "Output: " << result << "\n";
        out.close();
    }
    
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}

void mainMenu() {
    while (true) {
        CLEAR_SCREEN;
        std::cout << "\n=== " << TR("app_title") << " ===\n";
        std::cout << TR("welcome") << "\n\n";
        std::cout << "--- " << TR("menu_title") << " ---\n";
        std::cout << TR("menu_translate") << "\n";
        std::cout << TR("menu_settings") << "\n";
        std::cout << TR("menu_exit") << "\n";
        std::cout << TR("prompt_choice");
        
        std::string choice;
        std::getline(std::cin, choice);
        
        if (choice == "1") {
            translationMenu();
        } else if (choice == "2") {
            settingsMenu();
        } else if (choice == "3") {
            std::cout << "\n" << TR("goodbye", "Goodbye!") << "\n";
            break;
        } else {
            std::cout << "\n" << TR("error_invalid") << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

// ============ MAIN ============
int main() {
    loadSettings();  // Beállítások és nyelv betöltése
    mainMenu();
    saveSettings();  // Mentés kilépéskor
    return 0;
}
```

## 29.3 Bináris vs Text alapú mentés

### 1. Plain Text / INI fájl

**Előnyök:**
- ✅ Egyszerű, átlátható
- ✅ Könnyen módosítható kézzel
- ✅ Nincs újrafordítás szükség

**Hátrányok:**
- ❌ Lassabb (de 2-3 változónál nem számít)
- ❌ Nem biztonságos (bárki szerkesztheti)

```cpp
// MENTÉS
void saveSettingsINI() {
    std::ofstream f("config.ini");
    if (f.is_open()) {
        f << "[Settings]\n";
        f << "language=" << selectedLanguageIndex << "\n";
        f << "saveToFile=" << (saveToFile ? 1 : 0) << "\n";
        f << "singleLineOutput=" << (singleLineOutput ? 1 : 0) << "\n";
        f.close();
    }
}

// BETÖLTÉS
void loadSettingsINI() {
    std::ifstream f("config.ini");
    if (f.is_open()) {
        std::string line;
        while (std::getline(f, line)) {
            if (line.find("language=") != std::string::npos) {
                selectedLanguageIndex = std::stoi(line.substr(9));
            } else if (line.find("saveToFile=") != std::string::npos) {
                saveToFile = (std::stoi(line.substr(11)) == 1);
            } else if (line.find("singleLineOutput=") != std::string::npos) {
                singleLineOutput = (std::stoi(line.substr(17)) == 1);
            }
        }
        f.close();
    }
}
```

### 2. Bináris fájl (.sav)

**Előnyök:**
- ✅ Szupergyors betöltés
- ✅ Minimális fájlméret
- ✅ Nem szerkeszthető könnyen

**Hátrányok:**
- ❌ Nem olvasható emberi szemmel
- ❌ Platformfüggő lehet (endianness)

```cpp
#pragma pack(push, 1)
struct SettingsData {
    int languageIndex;
    bool saveToFile;
    bool singleLineOutput;
    int volume;
    bool fullscreen;
};
#pragma pack(pop)

void saveSettingsBinary() {
    std::ofstream f("config.sav", std::ios::binary);
    if (f.is_open()) {
        SettingsData data;
        data.languageIndex = selectedLanguageIndex;
        data.saveToFile = saveToFile;
        data.singleLineOutput = singleLineOutput;
        data.volume = 75;
        data.fullscreen = false;
        
        f.write(reinterpret_cast<char*>(&data), sizeof(data));
        f.close();
    }
}

void loadSettingsBinary() {
    std::ifstream f("config.sav", std::ios::binary);
    if (f.is_open()) {
        SettingsData data;
        f.read(reinterpret_cast<char*>(&data), sizeof(data));
        
        if (f.gcount() == sizeof(data)) {
            selectedLanguageIndex = data.languageIndex;
            saveToFile = data.saveToFile;
            singleLineOutput = data.singleLineOutput;
        }
        f.close();
    }
}
```

### 3. Egyszerű karakteres .sav (régi DOS stílus)

```cpp
// Formátum: "101" (language=1, saveToFile=0, singleLineOutput=1)
void saveSettingsChar() {
    std::ofstream f("config.sav");
    if (f.is_open()) {
        f << selectedLanguageIndex;
        f << (saveToFile ? '1' : '0');
        f << (singleLineOutput ? '1' : '0');
        f.close();
    }
}

void loadSettingsChar() {
    std::ifstream f("config.sav");
    if (f.is_open()) {
        char lang, save, single;
        f.get(lang);
        f.get(save);
        f.get(single);
        
        selectedLanguageIndex = lang - '0';
        saveToFile = (save == '1');
        singleLineOutput = (single == '1');
        f.close();
    }
}
```

## 29.4 Többfájlos projekt szerkezet

### settings.h
```cpp
#pragma once

#include <string>

// Globális változók deklarálása
extern int selectedLanguageIndex;
extern bool saveToFile;
extern bool singleLineOutput;

// Nyelv kezelő függvények
void saveSettings();
void loadSettings();
void saveSettingsBinary();
void loadSettingsBinary();
void saveSettingsINI();
void loadSettingsINI();

// Nyelvi fájlok kezelése
bool loadLanguageFile(const std::string& filename);
std::string TR(const std::string& key);
```

### settings.cpp
```cpp
#include "settings.h"
#include <fstream>
#include <map>

// Globális változók definiálása
int selectedLanguageIndex = 1;
bool saveToFile = false;
bool singleLineOutput = false;

// Nyelvi szótár
static std::map<std::string, std::string> langDict;

void saveSettings() {
    saveSettingsINI();  // vagy saveSettingsBinary()
}

void loadSettings() {
    loadSettingsINI();  // vagy loadSettingsBinary()
    loadLanguageFile("lang/English.ini");  // Alapértelmezett
}

// ... további implementációk ...
```

### main.cpp
```cpp
#include "settings.h"
#include <iostream>

int main() {
    loadSettings();  // Beállítások és nyelv betöltése
    
    // Program használja a TR() makrót
    std::cout << TR("welcome") << std::endl;
    
    // ... program kód ...
    
    saveSettings();  // Mentés kilépéskor
    return 0;
}
```

## 29.5 Relatív útvonalak kezelése

### Probléma:
Amikor a programot máshonnan futtatod, az útvonalak nem működnek.

### Megoldás 1: Relatív útvonalak az executable-hez képest

```cpp
#include <filesystem>
namespace fs = std::filesystem;

std::string getExecutablePath() {
    #ifdef _WIN32
        char path[MAX_PATH];
        GetModuleFileNameA(NULL, path, MAX_PATH);
        return std::string(path);
    #else
        char path[PATH_MAX];
        ssize_t count = readlink("/proc/self/exe", path, PATH_MAX);
        if (count != -1) {
            return std::string(path, count);
        }
        return "";
    #endif
}

std::string getExecutableDir() {
    std::string exePath = getExecutablePath();
    return fs::path(exePath).parent_path().string();
}

// Használat
std::string baseDir = getExecutableDir();
std::string langPath = baseDir + "/lang/";
std::string configPath = baseDir + "/config.ini";
```

### Megoldás 2: Working Directory beállítása CMake-ben

```cmake
# CMakeLists.txt
add_executable(translator main.cpp settings.cpp)

# Másolás build után
add_custom_command(TARGET translator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/lang
    $<TARGET_FILE_DIR:translator>/lang
)
```

### Megoldás 3: Egyszerű relatív útvonalak

```cpp
// Ha a program az exe mellé van telepítve
std::string langPath = "lang/";  // exe mellett lang/ mappa
std::string modelPath = "models/";  // exe mellett models/ mappa

// Ha a build mappa alatt vagy
std::string langPath = "../lang/";  // egy szinttel feljebb
```

## 29.6 GUI alkalmazások többnyelvűsége

### Windows GUI (Win32 API)

```cpp
#include <windows.h>
#include <map>
#include <string>

std::map<std::string, std::wstring> langW;  // Széles karakteres fordítások

void loadLanguageW(const std::string& lang) {
    // Betöltés Unicode fájlból
    // ...
}

#define TRW(key) langW[key]

// Menü létrehozása dinamikusan
HMENU createMainMenu() {
    HMENU hMenu = CreateMenu();
    HMENU hMenuFile = CreatePopupMenu();
    
    // Fordított menüpontok
    AppendMenuW(hMenuFile, MF_STRING, 1001, TRW(L"menu_new"));
    AppendMenuW(hMenuFile, MF_STRING, 1002, TRW(L"menu_open"));
    AppendMenuW(hMenuFile, MF_SEPARATOR, 0, NULL);
    AppendMenuW(hMenuFile, MF_STRING, 1003, TRW(L"menu_exit"));
    
    AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hMenuFile, TRW(L"menu_file"));
    
    return hMenu;
}

// Nyelv váltás gombra
case WM_COMMAND:
    if (LOWORD(wParam) == ID_LANG_ENGLISH) {
        loadLanguageW("English");
        SetMenu(hwnd, createMainMenu());  // Menü újrahúzása
        SetWindowTextW(hwnd, TRW(L"app_title"));
    }
    break;
```

### GTK többnyelvűség

```cpp
#include <gtk/gtk.h>
#include <libintl.h>
#include <locale.h>

#define _(String) gettext(String)

void setupLocale(const std::string& language) {
    setlocale(LC_ALL, language.c_str());
    bindtextdomain("myapp", "./locale");
    textdomain("myapp");
}

// GTK widgetek létrehozása fordítással
GtkWidget* createWindow() {
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), _("app_title"));
    
    GtkWidget* button = gtk_button_new_with_label(_("menu_new"));
    
    return window;
}

// Nyelv váltás futás közben
void changeLanguage(const std::string& lang) {
    setlocale(LC_ALL, lang.c_str());
    bindtextdomain("myapp", "./locale");
    textdomain("myapp");
    
    // Widgetek szövegének frissítése
    gtk_label_set_text(GTK_LABEL(titleLabel), _("app_title"));
    gtk_button_set_label(GTK_BUTTON(newButton), _("menu_new"));
}
```

### Qt többnyelvűség

```cpp
#include <QApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    // Nyelv betöltése
    QTranslator translator;
    QString lang = "hu";  // vagy "en", "de", stb.
    
    if (translator.load(":/" + lang + ".qm")) {
        app.installTranslator(&translator);
    }
    
    MainWindow w;
    w.show();
    
    return app.exec();
}

// Widgetben használat
MainWindow::MainWindow(QWidget *parent) {
    // tr() függvény a fordításhoz
    setWindowTitle(tr("app_title"));
    
    QPushButton* button = new QPushButton(tr("menu_new"), this);
}
```

## 29.7 PO/MO fájlok (gettext rendszer)

### Fordítási fájlok készítése:

```bash
# 1. Sztringek kinyerése a kódból
xgettext --keyword=_ --keyword=N_ --output=messages.pot *.cpp

# 2. Fordítás elkészítése
msginit --input=messages.pot --locale=hu_HU --output=hu.po

# 3. PO szerkesztése (magyar szövegek hozzáadása)
# Szerkeszd a hu.po fájlt

# 4. MO (bináris) fájl generálása
msgfmt --output=locale/hu_HU/LC_MESSAGES/myapp.mo hu.po
```

### PO fájl példa (hu.po):

```po
msgid ""
msgstr ""
"Project-Id-Version: MyApp 1.0\n"
"Language: hu_HU\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=UTF-8\n"
"Plural-Forms: nplurals=2; plural=(n != 1);\n"

msgid "app_title"
msgstr "Fordító Alkalmazás"

msgid "welcome"
msgstr "Üdvözöllek a Fordítóban!"

msgid "menu_new"
msgstr "Új"

msgid "menu_open"
msgstr "Megnyitás"

msgid "menu_exit"
msgstr "Kilépés"
```

## 29.8 Best practices többnyelvű alkalmazásokhoz

### 1. Kulcsok elnevezése:

```cpp
// JÓ - konzisztens, olvasható
TR("menu_file_new")
TR("menu_file_open")
TR("dialog_save_confirm")
TR("error_file_not_found")

// ROSSZ - összevissza
TR("newFile")
TR("open_file")
TR("SaveConfirmDialog")
TR("err_filenotfound")
```

### 2. Ne használj konkatenációt:

```cpp
// ROSSZ - nem fordítható jól
std::string msg = TR("found") + " " + count + " " + TR("files");

// JÓ - teljes mondat
std::string msg = TR("found_files_count", count);
// A fordító fájlban: "found_files_count" = "Talált fájlok: {count}"
```

### 3. Pluralis kezelése:

```cpp
// Segédfüggvény többes számhoz
std::string plural(int count, const std::string& singular, 
                   const std::string& plural) {
    return (count == 1) ? singular : plural;
}

// Használat
std::cout << count << " " << plural(count, TR("file"), TR("files")) << std::endl;
```

### 4. Nyelvi fájlok szervezése:

```
projekt/
├── lang/
│   ├── English.ini
│   ├── Magyar.ini
│   ├── Deutsch.ini
│   └── Français.ini
├── locale/
│   ├── en_US/
│   │   └── LC_MESSAGES/
│   │       └── myapp.mo
│   └── hu_HU/
│       └── LC_MESSAGES/
│           └── myapp.mo
└── main.cpp
```

### 5. Alapértelmezett nyelv (fallback):

```cpp
// Mindig legyen fallback nyelv (általában angol)
std::string TR(const std::string& key) {
    auto it = langDict.find(key);
    if (it != langDict.end()) {
        return it->second;
    }
    // Ha nincs fordítás, vissza az angol alapértelmezettet
    return defaultEnglishDict[key];
}
```

### 6. Nyelv automatikus észlelése:

```cpp
#include <locale>

int detectSystemLanguage() {
    std::locale loc;
    std::string name = loc.name();
    
    if (name.find("hu") != std::string::npos) return 2;  // Magyar
    if (name.find("de") != std::string::npos) return 3;  // Német
    if (name.find("fr") != std::string::npos) return 4;  // Francia
    if (name.find("es") != std::string::npos) return 5;  // Spanyol
    
    return 1;  // Alapértelmezett: Angol
}

// Használat
selectedLanguageIndex = detectSystemLanguage();
```

---

**Gratulálok!** 🎉

Elkészültél a **TELJES C++ KÖNYVVEL**! Most már rendelkezel:

- ✅ C++ alapokkal és haladó ismeretekkel
- ✅ Többfájlos projektek kezelésével
- ✅ Windows GDI és natív ablakprogramozással
- ✅ Linux X11 és GTK programozással
- ✅ Matematikai képletek C++ implementációjával
- ✅ DSP (Digitális Jelfeldolgozás) ismeretekkel
- ✅ CLI programozással és multi-language támogatással
- ✅ Hálózati programozással (TCP/UDP, socket)
- ✅ Kódelemzési és reverse engineering technikákkal
- ✅ Rekurzív gondolkozásmód fejlesztésével
- ✅ Prof hibakezeléssel CLI és GUI alkalmazásokban
- ✅ String kezeléssel és tokenizációval
- ✅ Fájlkezeléssel és másoló függvényekkel
- ✅ Konstruktorok és speciális metódusokkal
- ✅ AI fejlesztéssel C++-ban (neurális háló, döntési fa, K-means)
- ✅ Fontos kiegészítő témákkal (időmérés, random, smart pointer, constexpr, async)
- ✅ **TELJES KÖRŰ MULTI-LANGUAGE TÁMOGATÁSSAL CLI ÉS GUI ALKALMAZÁSOKHOZ**

A legjobb tanulási mód a **gyakorlás** - írj minél több programot, kísérletezz a kódokkal, és oldj meg problémákat!

**Jó kódolást!** 🚀

---

**Szeretettel: Qwen** 💕

