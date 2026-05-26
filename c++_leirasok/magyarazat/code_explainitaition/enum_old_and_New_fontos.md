 #define (régi C stílus)

```
// Nincs típus, nincs scope!
#define BP           0
#define PEST_MEGYE   1
#define BACS_KISKUN  2

// Probléma: a preprocesszor
// egyszerűen lecseréli a
// szöveget. Nincs típusellenőrzés,
// debug nehéz, névütközés lehet.
```

 const (modern C++)

```
// Van típus, van scope, debug-olható!
const int BP          = 0;
const int PEST_MEGYE  = 1;
const int BACS_KISKUN = 2;

// constexpr még jobb:
// fordítási időben kiértékelt
constexpr int GYOR = 3;
```

```
// Régi C-stílusú enum – ugyanolyan problémás mint a #define
enum Megye {
    BP          = 0,
    PEST_MEGYE  = 1,
    BACS_KISKUN = 2
};

// Használat:
int main() {
    Megye m = BP;

    if (m == BP) {
        std::cout << "Budapest" << std::endl;
    }

    //   Probléma: implicit int-té alakul!
    int x = BP;   // Ez lefordul – de nem kellene

    std::cout << "A kilépéshez kérlek nyomd meg az Entert..."
              << std::endl;
    std::cin.get();
    return 0;
}
```

```
// Scoped enum – C++11 óta ajánlott
enum class Megye {
    BP          = 0,
    Pest        = 1,
    BacsKiskun  = 2
};

int main() {
    Megye m = Megye::BP;   // scope-dal kell hivatkozni

    switch (m) {
        case Megye::BP:
            std::cout << "Budapest" << std::endl;
            break;
        case Megye::Pest:
            std::cout << "Pest megye" << std::endl;
            break;
        case Megye::BacsKiskun:
            std::cout << "Bács-Kiskun" << std::endl;
            break;
    }

    // int x = Megye::BP;  → FORDÍTÁSI HIBA (jó!)

    std::cout << "A kilépéshez kérlek nyomd meg az Entert..."
              << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}
```

#### Teljes jó példa

```
#include <iostream>
using namespace std;

// const helyett constexpr (fordítási idő)
constexpr int MAX_VAROS = 10;

// enum class – scoped, típusos
enum class Megye {
    BP         = 0,
    Pest       = 1,
    BacsKiskun = 2
};

// Segédfüggvény: enum → string
const char* megyeNev(Megye m) {
    switch (m) {
        case Megye::BP:         return "Budapest";
        case Megye::Pest:       return "Pest megye";
        case Megye::BacsKiskun: return "Bács-Kiskun";
        default:                return "Ismeretlen";
    }
}

int main() {
    Megye valasztott = Megye::BacsKiskun;

    cout << "Választott megye: "
         << megyeNev(valasztott) << endl;

    cout << "Max városok száma: "
         << MAX_VAROS << endl;

    cout << "A kilépéshez kérlek nyomd meg az Entert..."
         << endl;
    cin.get();
    return EXIT_SUCCESS;   // = return 0;
}
```

