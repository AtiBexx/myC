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