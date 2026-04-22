/**
Ez a program minden egyes összeget negyzetre emel.
Kilépéshez az 'exit'-parancsot kell beírni.
A feladat befejezéséhez meg a 'final' parancsot
de a folyamat akkor újraindul.
*/
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

// Négyzetre emelés függvénye
double square(double change) { return change * change; }

// Program leírásának a függvénye
void explanationOfProgram(void) {
  std::cout << "Ez a program több szám sorozatát negyzetre emel.\n";
  std::cout << "majd összegzi az eredményt ha abbahagyjuk a feladatot.\n";
  std::cout << "A feladat befejezéséhez meg a 'final' parancsot\n";
  std::cout << "de a folyamat akkor újraindul.\n";
  std::cout << "Kilépéshez az 'exit'-parancsot kell beírni.\n";
  std::cout << "a kéápernyő törléséhez a 'cls'-parancsot kell beírni.\n";
}

// Az Összegző függvénye
double totalValue(void) {

  double collector = 0; // 0-ról indul a gyüjtő értéke
  for (;;) {
    std::string line;
    std::cout << "Kérlek add meg a következő számot a gyüjtöhöz:\n";
    std::getline(std::cin, line);
    if (line == "final") {
      std::cout << "Ennek a sorozatnak az összege:" << collector << "\n";
      collector = 0; // lenullázuk a gyüjtő értékét
    } else if (line == "exit") {
      if (collector > 0)
      {
        std::cout << "Ennek a sorozatnak az összege:" << collector << "\n";
      }  
      return collector;
      //break; 
    } else if (line == "cls") {
      std::cout << "\x1B[2J\x1B[H"; // natív képernyő törlés
    } else {
      try {
        double dValue = std::stod(line);
        collector += square(
            dValue); // hozzáadjuk a nyégyzetre emelt összeget a változóhoz
      } catch (const std::exception &e) {
        std::cerr << "Rossz input.\nKérlek csak számot adj meg." << std::endl;
        // std::cin.clear();
        //  a getline() használatakor nem kell használni a clear()-t
      }
    }
  }
}
double totalValueFromArgs(int argc, char *argv[]) {
    double collector = 0; // 0-ról indul a gyüjtő értéke
    for (int i = 1; i < argc; i++) {
      try {
        double dValue = std::stod(argv[i]);
        collector += square(
            dValue); // hozzáadjuk a nyégyzetre emelt összeget a változóhoz
        //std::cout << "A gyüjtő értéke:" << collector << "\n";
      } catch (const std::exception &e) {
        std::cerr << "Rossz input.\nKérlek csak számot adj meg." << std::endl;
        return 1; // ilyenkor hibakódal kilépünk
        // std::cin.clear();
        //  a getline() használatakor nem kell használni a clear()-t
      }
    }
    std::cout << "A gyüjtő értéke:" << collector << "\n";
    return 0; // hibakód kilépünk argumentumnál
}


// A függvények Deklarációi
void explanationOfProgram(void);
double square(double change);
double totalValue(void);
double totalValueFromArgs(int argc, char *argv[]);

// A main függvény(fő belépésí pont)
int main(int argc, char *argv[]) {

  if (argc > 1) {
    totalValueFromArgs(argc, argv);
    
  } else {

    explanationOfProgram();
    totalValue();
  }
  if (argc == 1) {
    std::cout << "A kilépés folytatásához nyomd meg az 'ENTERT'..."
              << std::endl;
    std::cin.get();
    return 0;
  }
}
