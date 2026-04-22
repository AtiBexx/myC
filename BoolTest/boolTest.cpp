
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

// Helper function to get a valid integer input
int getValidInteger(const std::string& prompt) {
    std::string line;
    int value;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);

        if (line == "exit") {
            exit(0); // Exit the program
        }

        try {
            // Using stoi instead of stof since we're dealing with integers
            size_t pos;
            float fValue = std::stof(line, &pos);

            // Check if the entire string was consumed (no extra characters)
            if (pos != line.length()) {
                throw std::invalid_argument("Extra characters after number");
            }

            // Check if the value is actually an integer
            if (fValue != static_cast<int>(fValue)) {
                throw std::invalid_argument("Not a whole number");
            }

            value = static_cast<int>(fValue);
            break; // Valid integer received
        } catch (const std::exception &e) {
            std::cerr << "Rossz input.\nKérlek csak számot adj meg." << std::endl;
            std::cin.clear();
        }
    }

    return value;
}

bool result(bool bresult, int iValue1, int iValue2) {
  bresult = iValue1 == iValue2;
  std::cout << "A két érték összehasonlítása:\n"
            << iValue1 << " és a " << iValue2 << " értéke egyenlő-e?\n"
            << std::boolalpha << bresult << "\n\n";  // Using std::boolalpha here too
  return bresult;
}

int main(int argc, char *argv[]) {
  int iValue1, iValue2;
  bool bresult;

  // Handle command line arguments if provided
  if (argc == 3) {
      try {
          iValue1 = std::stoi(argv[1]);
          iValue2 = std::stoi(argv[2]);

          result(bresult, iValue1, iValue2);

          // Wait for user to press enter before exiting
          std::cout << "Nyomj entert a program leállításához!";
          std::cin.get();
          return 0;
      } catch (const std::exception &e) {
          std::cerr << "Hibás parancssori argumentumok.\n";
          std::cerr << "Használat: " << argv[0] << " <szam1> <szam2>\n";
          return 1;
      }
  }

  // Interactive mode
  std::cout.setf(std::cout.boolalpha);

  while (true) {
      // Get first value
      iValue1 = getValidInteger("Kérlek add meg az első értéket: ");

      // Get second value
      iValue2 = getValidInteger("Kérlek add meg a második értéket: ");

      // Compare and display result
      result(bresult, iValue1, iValue2);
  }

  return 0;
}