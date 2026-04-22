# BoolTest

```
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

int main(int argc, char* argv[]) {
    
    //bool változó kimeneti formátumának beállítása true és false értékre
    std::cout.setf(std::cout.boolalpha);
    //két érték megadása
    std::cout <<"Kérlek add meg az első értéket: ";
    int value1;
    std::cin >> value1;
    std::cout <<"Kérlek add meg a második értéket: ";
    int value2;
    std::cin >> value2;

    // a két változó összehasonlítása
    bool bresult;
    bresult = value1 == value2;
    std::cout << "A két érték összehasonlítása:\n"
              << value1 << " egyenlő " << value2 << " értéke egyenlő-e?\n" << bresult << "\n";

    //Várakozás a program leállításával
    std::cout << "Nyomj entert a program leállításához!";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.get();
              
    return 0;
}
```

Kezeljük a hibát 

```
if (!(std::cin >> value1)) {
    std::cerr << "Hibás bemenet!\n";
    return 1;
}
```

**Teljes kód:**

```
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

int main(int argc, char* argv[]) {
    
    int value1 , value2;
    
    for(;;){
    //bool változó kimeneti formátumának beállítása true és false értékre
    std::cout.setf(std::cout.boolalpha);
    //két érték megadása
    std::cout <<"Kérlek add meg az első értéket: ";
    std::cin >> value1;
    //Kezeljük a hibákat
    if (std::cin.fail()) {
        std::cerr << "Rossz input.\n Kérlek csak számot adj meg.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //continue;
    }else {
        break;
    } 
}

    for(;;){
    //két érték megadása
    std::cout <<"Kérlek add meg a második értéket: ";
    std::cin >> value2;
    //Kezeljük a hibákat
    if (std::cin.fail()) {
        std::cerr << "Rossz input.\n Kérlek csak számot adj meg." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //continue;
    }else {
        break;
    } 
}

    // a két változó összehasonlítása
    bool bresult;
    bresult = value1 == value2;
    std::cout << "A két érték összehasonlítása:\n"
              << value1 << " és a " << value2 << " értéke egyenlő-e?\n" << bresult << "\n";

    //Várakozás a program leállításával
    std::cout << "Nyomj entert a program leállításához!";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.get();
              
    return 0;
}
```

Külön `for(;;)` Ciklusban kell kezelni a hibákat mert elveszik a value 1 értéke ha a value2 nél hibás bemenetet adunk meg.

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

Ez kevésbé Pragmatikus de működik nagyon is szóval jó.

Ez már pragmatikusabb..

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

Ez jobb de itt rögtön kilép.... 

Argumentumal is müködik most megírom úgy hogy , a ciklusból lépjen ki....

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

Nyilván lehet jobb kódott is írni de ez már ellég pragmatikos goto val is meg lehetne oldani amúgy.

A goto használata azért nem célszerű mert az úgynevezet spagetti kód lesz a végén belőle és átláthatatlan lesz az egész inkább ciklusokkal oldjuk meg ha lehet.