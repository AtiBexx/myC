```
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

bool result(bool bresult, int iValue1, int iValue2) {
  bresult = iValue1 == iValue2;
  std::cout << "A két érték összehasonlítása:\n"
            << iValue1 << " és a " << iValue2 << " értéke egyenlő-e?\n"
            << bresult << "\n\n";
  return bresult;
}

// függvényDeklaráció
bool result(bool bresult, int iValue1, int iValue2);

int main(int argc, char *argv[]) {

  std::string line;
  int iValue1, iValue2;
  bool bresult;
  // bool változó kimeneti formátumának beállítása true és false értékre
  std::cout.setf(std::cout.boolalpha);

  for (;;) {
    end: // Visszaadás a program leállításához
    if (line == "exit") {
      break;
    } else {

      for (;;) {

        // két érték megadása
        std::cout << "Kérlek add meg az első értéket: ";
        std::getline(std::cin, line);
        if (line == "exit")
          goto end; //ugrás az end labelhez

        // Kezeljük a hibákat
        try {
          iValue1 = std::stof(line);
          break;
        } catch (const std::exception &e) {
          std::cerr << "Rossz input.\nKérlek csak számot adj meg." << std::endl;
          std::cin.clear();
        }
      }

      for (;;) {
        // két érték megadása
        std::cout << "Kérlek add meg a második értéket: ";
        std::getline(std::cin, line);
        if (line == "exit")
          break;

        // Kezeljük a hibákat
        try {
          iValue2 = std::stof(line);
          break;
        } catch (const std::exception &e) {
          std::cerr << "Rossz input.\nKérlek csak számot adj meg." << std::endl;
          std::cin.clear();
        }
      }

      // függvényhívás
      if (line != "exit") {
        result(bresult, iValue1, iValue2);
      } else {
        break;
      }
    }
  }

  // Várakozás a program leállításával
  std::cout << "Nyomj entert a program leállításához!";
  // std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  std::cin.get();

  return 0;
}
```

```
#include <cstdlib>
#include <iostream>
#include <string>

bool result(int iValue1, int iValue2) {
  bool bresult = iValue1 == iValue2;
  std::cout << "A két érték összehasonlítása:\n"
            << iValue1 << " és a " << iValue2 << " értéke egyenlő-e?\n"
            << std::boolalpha << bresult << "\n\n";
  return bresult;
}

int getValidInput(const std::string &prompt) {
  std::string line;
  int value;
  std::cout << prompt; 

  while (true) {
    std::getline(std::cin, line);

    if (line == "exit") { // Ha egyből ki akarunk lépni
      exit(0);
    } 
    try {
      value = std::stoi(line);
      break;
    } catch (const std::invalid_argument &) {
      std::cerr << "Rossz input.\nKérlek csak számot adj meg." << std::endl;
    } catch (const std::out_of_range &) {
      std::cerr << "A szám túl nagy vagy túl kicsi." << std::endl;
    }
  }

  return value;
}

int main(int argc, char *argv[]) {
  int iValue1, iValue2;

  // Ha van 3 argumentum (programnév + 2 szám), akkor azokat használjuk
  if (argc == 3) {
    try {
      iValue1 = std::stoi(argv[1]);
      iValue2 = std::stoi(argv[2]);
      result(iValue1, iValue2);
      return 0;
    } catch (const std::exception &) {
      std::cerr << "Érvénytelen argumentumok." << std::endl;
      return 1;
    }
  } else {
    for (;;) {
      // Különben kérjük be a felhasználótól
      iValue1 = getValidInput("Kérlek add meg az első értéket: ");
      iValue2 = getValidInput("Kérlek add meg a második értéket: ");
    std::cout << "\n";
      // Összehasonlítás eredményének kiírása
      result(iValue1, iValue2);
    }
  }

  if (argc == 1) {

    // Várakozás a program leállításával
    std::cout << "Nyomj entert a program leállításához!";
    std::cin.get();

    return 0;
  }
}
```

```
#include <cstdlib>
#include <iostream>
#include <string>

bool result(int iValue1, int iValue2) {
  bool bresult = iValue1 == iValue2;
  std::cout << "A két érték összehasonlítása:\n"
            << iValue1 << " és a " << iValue2 << " értéke egyenlő-e?\n"
            << std::boolalpha << bresult << "\n\n";
  return bresult;
}

int getValidInput(const std::string &prompt) {
  std::string line;
  int value;
  std::cout << prompt; 

  while (true) {
    std::getline(std::cin, line);

    if (line == "exit") { // Ha egyből ki akarunk lépni
       return -999999; // Speciális érték a kilépéshez
    } 
    try {
      value = std::stoi(line);
      break;
    } catch (const std::invalid_argument &) {
      std::cerr << "Rossz input.\nKérlek csak számot adj meg." << std::endl;
    } catch (const std::out_of_range &) {
      std::cerr << "A szám túl nagy vagy túl kicsi." << std::endl;
    }
  }

  return value;
}

int main(int argc, char *argv[]) {
  int iValue1, iValue2;
   bool exitRequested = false;

  // Ha van 3 argumentum (programnév + 2 szám), akkor azokat használjuk
  if (argc == 3) {
    try {
      iValue1 = std::stoi(argv[1]);
      iValue2 = std::stoi(argv[2]);
      result(iValue1, iValue2);
      return 0;
    } catch (const std::exception &) {
      std::cerr << "Érvénytelen argumentumok." << std::endl;
      return 1;
    }
  } else {
    for (;;) {
      // Különben kérjük be a felhasználótól
      
      iValue1 = getValidInput("Kérlek add meg az első értéket: ");
      if (iValue1 == -999999) break; // Kilépés, ha exit-et írt a felhasználó
      iValue2 = getValidInput("Kérlek add meg a második értéket: ");
      if (iValue1 == -999999) break; // Kilépés, ha exit-et írt a felhasználó
      
    std::cout << "\n";
      // Összehasonlítás eredményének kiírása
      result(iValue1, iValue2);
    }
  }

  if (argc == 1) {

    // Várakozás a program leállításával
    std::cout << "Nyomj entert a program leállításához!";
    std::cin.get();

    return 0;
  }
}
```

