# C++ -- static, const, static const, constexpr, statikus függvények és osztályok

---

## 1. const

Egy érték vagy pointer nem változtatható meg a program futása során.

```cpp
const int MAX = 50;         // MAX nem változhat
MAX = 100;                  // FORDÍTÁSI HIBA

const int* p = &MAX;        // a mutatott érték nem változhat
*p = 10;                    // FORDÍTÁSI HIBA
p = &masik;                 // ez viszont szabad, a pointer maga változhat

int* const p2 = &ertek;     // a pointer maga nem változhat
*p2 = 10;                   // ez szabad, az érték változhat
p2 = &masik;                // FORDÍTÁSI HIBA
```

### const char* nNev vs char* const nNev

Ez az egyik legzavaróbb rész -- a csillag helye számít.

```cpp
const char* nNev = "Kiss Peter";   // a mutatott szöveg nem változhat
nNev = "Nagy Anna";                // ez szabad -- a pointer maga változhat
nNev[0] = 'X';                     // FORDÍTÁSI HIBA -- a tartalom nem változhat

char* const nNev2 = nev;           // a pointer nem változhat
nNev2 = masikNev;                  // FORDÍTÁSI HIBA -- a pointer nem változhat
nNev2[0] = 'X';                    // ez szabad -- a tartalom változhat

const char* const nNev3 = "Teszt"; // sem a pointer, sem a tartalom nem változhat
```

Olvasási trick: jobbrol balra olvasd.
- "const char* nNev" --> nNev egy pointer, ami char-ra mutat, ami const
- "char* const nNev" --> nNev egy const pointer, ami char-ra mutat

### const tagfüggvény

Az osztályon belül a const tagfüggvény nem módosíthatja az osztály adattagjait.

```cpp
class Hallgato {
public:
    void kiir() const {        // const tagfüggvény
        std::cout << nev;      // olvasás -- szabad
        nev[0] = 'X';          // FORDÍTÁSI HIBA -- módosítás tiltott
    }
private:
    char nev[50];
};
```

---

## 2. static

A static kulcsszónak több jelentése van attól függően hol használod.

### Globális vagy fájl szintű static

A változó vagy függvény csak az adott fordítási egységben (cpp fájlban) látható.

```cpp
static int szamlalo = 0;   // más cpp fájlból nem érhető el
static void segéd() { }    // más cpp fájlból nem érhető el
```

### Lokális static (függvényen belül)

A változó csak egyszer jön létre és megőrzi értékét a függvényhívások között.

```cpp
void szamol() {
    static int db = 0;    // csak egyszer inicializálódik
    db++;
    std::cout << db;
}

szamol();   // kiír: 1
szamol();   // kiír: 2
szamol();   // kiír: 3
```

### static adattag osztályban

Nem az objektumhoz tartozik, hanem az osztályhoz -- minden objektum ugyanazt a példányt látja.

```cpp
class Hallgato {
public:
    static int hallgatokSzama;   // deklaráció az osztályban
};

int Hallgato::hallgatokSzama = 0;   // definíció és inicializálás a cpp fájlban

Hallgato h1, h2, h3;
Hallgato::hallgatokSzama = 10;      // az osztályon keresztül éred el
```

### static tagfüggvény osztályban

Nincs this pointere -- nem fér hozzá a példány adattagjaihoz, csak a static adattagokhoz.

```cpp
class Hallgato {
public:
    static int getSzam() {
        return hallgatokSzama;    // static adattagot elér -- szabad
        return nev;               // FORDÍTÁSI HIBA -- példány adattag, nincs this
    }
    static int elemekANevben() {
        return sizeof(nev);       // szabad -- sizeof fordítási idejű, nem kell this
    }
private:
    static int hallgatokSzama;
    char nev[50];
};

// Hívás objektum nélkül:
Hallgato::getSzam();

// Hívás objektumon keresztül is működik, de nem ajánlott stílus:
Hallgato h;
h.getSzam();
```

---

## 3. static const

Osztályban olyan konstans amely az osztályhoz tartozik, nem a példányhoz, és nem változhat.

```cpp
class Hallgato {
public:
    static const int MAX_NEV = 50;    // C++11-től közvetlenül inicializálható
    char nev[MAX_NEV];                // felhasználható tömb méretként
};

// Régebbi módszer (C++11 előtt) -- cpp fájlban kell definiálni:
const int Hallgato::MAX_NEV = 50;
```

A static const int az egyetlen eset ahol az osztályon belül közvetlenül adhatsz értéket -- más típusoknál ez nem működik C++11 előtt.

---

## 4. constexpr

Fordítási idejű konstans -- az értéke már fordításkor ismert, nem csak futáskor.

```cpp
constexpr int MAX = 50;             // fordítási idejű konstans
constexpr int DUPLA = MAX * 2;      // fordítási idejű számítás -- szabad

char tomb[MAX];                     // szabad -- fordítási idejű érték kell a tömbmérethez
```

### constexpr vs const különbség

```cpp
const int a = 50;           // lehet fordítási idejű, de nem garantált
constexpr int b = 50;       // garantáltan fordítási idejű

const int c = fuggveny();   // futási idejű is lehet -- szabad
constexpr int d = fuggveny(); // HIBA ha fuggveny() nem constexpr
```

### constexpr függvény

Fordítási időben is kiértékelhető, ha konstans paramétereket kap.

```cpp
constexpr int negyzet(int x) {
    return x * x;
}

constexpr int eredmeny = negyzet(5);   // fordítási időben: 25
int valtozo = 3;
int masik = negyzet(valtozo);          // futási időben is működik
```

---

## 5. Statikus konstruktor -- nincs ilyen C++-ban

C++-ban nincs statikus konstruktor mint pl. C#-ban vagy Java-ban. De ugyanezt el lehet érni:

### 1. megoldás -- static lokális változó függvényben (Singleton minta)

```cpp
class Adatbazis {
public:
    static Adatbazis& getInstance() {
        static Adatbazis peldany;    // csak egyszer jön létre, első hívásnál
        return peldany;
    }
private:
    Adatbazis() {
        std::cout << "Adatbazis letrehozva" << std::endl;
    }
};

// Használat:
Adatbazis& db = Adatbazis::getInstance();
```

### 2. megoldás -- static adattag inicializálása cpp fájlban

```cpp
// hallgato.h
class Hallgato {
    static int hallgatokSzama;
    static std::string iskola;
};

// hallgato.cpp -- ez fut le a program indulásakor, main() előtt
int Hallgato::hallgatokSzama = 0;
std::string Hallgato::iskola = "BME";
```

---

## 6. Statikus osztály -- nincs ilyen C++-ban

C++-ban nincs static class kulcsszó. De ugyanezt el lehet érni úgy hogy minden tag static.

```cpp
class MathHelper {
public:
    static int osszeg(int a, int b) {
        return a + b;
    }
    static int szorzat(int a, int b) {
        return a * b;
    }
    static constexpr double PI = 3.14159265;

private:
    MathHelper() = delete;   // megakadályozza hogy példányt hozzanak létre
};

// Használat -- objektum nélkül:
int s = MathHelper::osszeg(3, 5);
double pi = MathHelper::PI;
```

---

## 7. Összefoglaló táblázat

| Kulcsszó | Hol | Mire való |
|---|---|---|
| const | mindenhol | érték nem változhat |
| const tagfüggvény | osztályban | nem módosítja az objektumot |
| const char* | pointer | mutatott tartalom nem változhat |
| char* const | pointer | maga a pointer nem változhat |
| static (lokális) | függvényben | megőrzi értékét hívások között |
| static (fájl szinten) | globálisan | csak az adott cpp fájlban látható |
| static adattag | osztályban | osztályhoz tartozik, nem objektumhoz |
| static tagfüggvény | osztályban | nincs this pointer, objektum nélkül hívható |
| static const | osztályban | osztályszintű konstans |
| constexpr | mindenhol | fordítási idejű konstans vagy függvény |

---

## 8. Teljes példakód

```cpp
#include <iostream>
#include <cstring>

class Hallgato {
public:
    static const int MAX_NEV = 50;           // osztályszintű konstans
    static constexpr double ATLAG_KOR = 21.5; // fordítási idejű konstans

    Hallgato(const char* ujNev) {
        strncpy(nev, ujNev, MAX_NEV - 1);
        nev[MAX_NEV - 1] = '\0';
        hallgatokSzama++;
    }

    ~Hallgato() {
        hallgatokSzama--;
    }

    static int getSzam() {                   // static tagfüggvény
        return hallgatokSzama;
    }

    static int elemekANevben() {             // static -- sizeof fordítási idejű
        return sizeof(nev) / sizeof(char);
    }

    void kiir() const {                      // const tagfüggvény
        std::cout << "Nev: " << nev << std::endl;
    }

private:
    char nev[MAX_NEV];
    static int hallgatokSzama;               // static adattag
};

int Hallgato::hallgatokSzama = 0;            // inicializálás cpp fájlban

int main() {
    std::cout << "Hallgatok szama: " << Hallgato::getSzam() << std::endl;  // 0

    Hallgato h1("Kiss Peter");
    Hallgato h2("Nagy Anna");

    std::cout << "Hallgatok szama: " << Hallgato::getSzam() << std::endl;  // 2
    std::cout << "Nev tomb merete: " << Hallgato::elemekANevben() << std::endl; // 50
    std::cout << "Atlag kor: " << Hallgato::ATLAG_KOR << std::endl;

    h1.kiir();
    h2.kiir();

    return 0;
}
```

**Kimenet:**
```
Hallgatok szama: 0
Hallgatok szama: 2
Nev tomb merete: 50
Atlag kor: 21.5
Nev: Kiss Peter
Nev: Nagy Anna
```
