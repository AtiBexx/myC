#include <iostream>
//#include <limits>



void printChar(char charBlock[], int charBlockSize) {
    for (int i = 0; i < charBlockSize; i++) {
        std::cout << charBlock[i] ;
    }
}

// protótípusDeklaráció
void printChar(char charBlock[], int charBlockSize);

int main(int argc, char* argv[]) {

  char charName[] = {'A', 'T', 'I' };
  printChar(charName, 3);
  //std::cout << std::flush;
  //std::cout << "\n";
  std::cout << std::endl;


  std::cout << "A Kilépéshez nyomd meg az ENTERT...." << std::endl;
  //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
  return 0;
}