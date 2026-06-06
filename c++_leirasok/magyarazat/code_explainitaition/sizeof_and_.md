Erre van egy beépített megoldás C++11-től — a `std::extent`:

```cpp
#include <type_traits>

char nev[50];
std::extent<decltype(nev)>::value; // visszaadja: 50
```

De a legjobb és legolvashatóbb megoldás egy **template függvény**:

```cpp
template<typename T, size_t N>
constexpr size_t elemSzam(T (&)[N]) {
    return N;
}

// Használat:
char nev[50];
int szamok[100];
double arak[25];

elemSzam(nev);    // → 50
elemSzam(szamok); // → 100
elemSzam(arak);   // → 25
```

**Miért jobb ez mint a sizeof/sizeof?**

```cpp
// Ez elbukik pointernél:
void fuggveny(char nev[]) {
    sizeof(nev)/sizeof(char); // ❌ pointer méretét adja vissza (8), nem a tömb méretét!
}

// A template fordítási hibát ad pointer esetén:
elemSzam(nev); // ✅ biztonságos, csak valódi tömbön működik
```

**C++17-től** még egyszerűbb — beépített:

```cpp
#include <iterator>

char nev[50];
std::size(nev); // → 50, működik tömbön és STL konténereken is
```

------

**Összefoglalva melyiket használd:**

| Megoldás                 | C++ verzió | Biztonságos          |
| ------------------------ | ---------- | -------------------- |
| `sizeof(t)/sizeof(t[0])` | mindenhol  | ❌ pointernél elbukik |
| template `elemSzam()`    | C++11      | ✅                    |
| `std::size()`            | C++17      | ✅                    |

Ha modern C++-t írsz, a `std::size()` a legtisztább megoldás.

Ha mindenképpen `sizeof`-al szeretnéd, akkor ez a makró a klasszikus megoldás ami **mindenhol** működik:

```cpp
#define TOMB_MERET(t) (sizeof(t) / sizeof((t)[0]))

// Használat:
char nev[50];
int szamok[100];
double arak[25];

TOMB_MERET(nev);     // → 50
TOMB_MERET(szamok);  // → 100
TOMB_MERET(arak);    // → 25
```

**Miért `(t)[0]` és nem `t[0]`?**

A zárójel biztonság miatt — ha valami összetettebb kifejezést adsz át, nem törik el.

------

**De a pointer probléma sajnos megmarad:**

```cpp
void fuggveny(char tomb[]) {
    TOMB_MERET(tomb); // ❌ még mindig rossz — pointer, nem tömb
}

char nev[50];
TOMB_MERET(nev); // ✅ itt jó, mert valódi tömb
```

------

Szóval `sizeof`-al csak akkor működik **biztosan helyesen**, ha:

- Közvetlenül a tömb deklarációja után használod
- Nem adod át függvénynek paraméterként

```cpp
#include <iostream>
#define TOMB_MERET(t) (sizeof(t) / sizeof((t)[0]))

const int MAX_NEV_MERET = 50;

class Hallgato {
public:
    // sizeof-os makróval — csak itt biztonságos mert valódi tömb
    static int elemekANevben() {
        return TOMB_MERET(nev);
    }

    // C++11 template megoldás — mindenhol biztonságos
    template<typename T, size_t N>
    static constexpr size_t elemSzam(T (&)[N]) {
        return N;
    }

    void setNev(const char* ujNev) {
        strncpy(nev, ujNev, MAX_NEV_MERET - 1);
        nev[MAX_NEV_MERET - 1] = '\0'; // biztonságos lezárás
    }

    void kiir() {
        std::cout << "Nev: " << nev << std::endl;
        std::cout << "Tomb merete (sizeof makro): " 
                  << elemekANevben() << std::endl;
        std::cout << "Tomb merete (template): " 
                  << elemSzam(nev) << std::endl;
    }

protected:
    char nev[MAX_NEV_MERET];
};

int main() {
    Hallgato h;
    h.setNev("Kiss Peter");
    h.kiir();

    // Közvetlen makró használat
    char masikTomb[100];
    int szamok[25];
    std::cout << "masikTomb merete: " << TOMB_MERET(masikTomb) << std::endl;
    std::cout << "szamok merete: "    << TOMB_MERET(szamok)    << std::endl;

    return 0;
}
```

**Kimenet:**

```
Nev: Kiss Peter
Tomb merete (sizeof makro): 50
Tomb merete (template): 50
masikTomb merete: 100
szamok merete: 25
```

**Mi van benne:**

- `TOMB_MERET` makró — `sizeof`-os megoldás
- `elemSzam` template — biztonságos verzió összehasonlításképp
- `strncpy` — biztonságos másolás hogy ne lógjon túl a tömb határán
- Mindkét megoldás ugyanazt adja vissza — látható hogy azonos eredmény

C-ben nincs class, nincs template, nincs `strncpy` biztonságosan beépítve — de a makró ugyanaz marad:

```c
#include <stdio.h>
#include <string.h>

#define TOMB_MERET(t) (sizeof(t) / sizeof((t)[0]))

#define MAX_NEV_MERET 50  // C-ben #define, nem const int

typedef struct {
    char nev[MAX_NEV_MERET];
} Hallgato;

void setNev(Hallgato* h, const char* ujNev) {
    strncpy(h->nev, ujNev, MAX_NEV_MERET - 1);
    h->nev[MAX_NEV_MERET - 1] = '\0';
}

void kiir(Hallgato* h) {
    printf("Nev: %s\n", h->nev);
    printf("Tomb merete: %zu\n", TOMB_MERET(h->nev));
}

int main() {
    Hallgato h;
    setNev(&h, "Kiss Peter");
    kiir(&h);

    // Közvetlen makró használat
    char masikTomb[100];
    int szamok[25];
    printf("masikTomb merete: %zu\n", TOMB_MERET(masikTomb));
    printf("szamok merete: %zu\n",    TOMB_MERET(szamok));

    return 0;
}
```

**Kimenet:**

```
Nev: Kiss Peter
Tomb merete: 50
masikTomb merete: 100
szamok merete: 25
```

------

**A főbb különbségek C vs C++:**

| C++                  | C                                   |
| -------------------- | ----------------------------------- |
| `class`              | `struct`                            |
| `const int MAX = 50` | `#define MAX 50`                    |
| `h.setNev()`         | `setNev(&h)` — pointert kell átadni |
| `h.nev`              | `h->nev` — pointeren keresztül      |
| `std::cout`          | `printf`                            |
| template             | nincs, csak makró                   |

C-ben minden "metódus" sima függvény, és mindig kézzel kell átadni a struktúra pointerét — ezt váltja ki C++-ban a `this` pointer automatikusan.