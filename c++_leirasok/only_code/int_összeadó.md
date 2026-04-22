# Számok összeadása

```

#include <exception>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string line1;

  int gyujto = 0;
  int nValue = 0;

  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      try {
        nValue = std::stoi(argv[i]);
        gyujto += nValue; // hozzáadjuk az osszeghez a változóhoz
      } catch (const std::exception &) {
        std::cerr << "Rossz input.\nKérlek csak számot adj meg." << std::endl;
        return 1;
      }
    }
    std::cout << "Ennek a sorozatnak az összege:" << gyujto << "\n";
    return 0;
  }

  std::cout << "Ez a program összeadja a számok sorozatát\n"
            << "És összegzi a számokat\n"
            << "A sorozat befejezéséhez használd a 'final' szöveget\n"
            << "A kilépéshez pedig írd be az 'exit' szöveget\n"
            << "A képrenyő törléséhes használ a 'cls' szövet\n";

  for (;;) {
    std::cout << "Add meg a következö számot: ";
    std::getline(std::cin, line1);
    if (line1 == "final") {
      std::cout << "Ennek a sorozatnak az összege:" << gyujto << "\n";
      gyujto = 0;
    } else if (line1 == "exit") {
      break;
    } else if (line1 == "cls") {
      // system("cls"); //rendszerhívás
      std::cout << "\x1B[2J\x1B[H"; // natív képernyő törlés
    } else {
      try {
        nValue = std::stoi(line1);
        gyujto += nValue; // hozzáadjuk az osszeghez a változóhoz
      } catch (const std::exception &e) {
        std::cerr << "Rossz input.\nKérlek csak számot adj meg." << std::endl;
        //std::cin.clear();
        // a getline() használatakor nem kell használni a clear()-t
      }
    }
  }
  if (argc == 1) {
    std::cout << "A kilépés folytatásához nyomd meg az 'ENTERT'..."
              << std::endl;
    std::cin.get();
    return 0;
  }
}
```



Ha **tört számokkal** (pl. `3.14`, `2.5`) akarsz dolgozni:

1. A `gyujto` és `nValue` **ne `int` legyen**, hanem `double` vagy `float`.
2. A `std::stoi` helyett **`std::stod`**-ot használj (`string → double`).

------

### Példa módosítás:

```cpp
double gyujto = 0.0;
double nValue = 0.0;

// konzol input feldolgozása
try {
    nValue = std::stod(line1);  // double-ot olvasunk
    gyujto += nValue;
} catch (const std::exception &e) {
    std::cerr << "Rossz input. Kérlek csak számot adj meg.\n";
}
```

- Parancssori számoknál is ugyanígy:

```cpp
nValue = std::stod(argv[i]);
gyujto += nValue;
```

- A `cout` automatikusan kiírja a tizedeseket:

```cpp
std::cout << "Összeg: " << gyujto << "\n";
```

------

Tipp:

- Ha mindig **2 tizedesjegy pontosságot** akarsz, használhatod:

```cpp
#include <iomanip>
std::cout << std::fixed << std::setprecision(2);
std::cout << "Összeg: " << gyujto << "\n";
```

- Így a `3 + 2.5` = `5.50` lesz kiírva.