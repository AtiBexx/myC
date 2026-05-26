# Char karakterKiIras

```
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
```

vagy

```
#include <cstdio>
#include <cstdlib>
#include <iostream>

void charNamePrinting(char charBlock[], int charBlockSize);

int main(int argc, char* argv[]) {
    char charName[] = {'A', 'T', 'I', '\n' };
    charNamePrinting(charName, 4); 
    std::cout<< std::endl;

    std::cout << "A Kilépéshez nyomd meg az ENTERT...." << std::endl;
  //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
  return 0;
}

void charNamePrinting(char charBlock[], int charBlockSize) {
    for (int i = 0; i < charBlockSize; i++)
    {
        std::cout << charBlock[i];
    }
}
```

Null terminatoral

```
#include <cstdio>
#include <cstdlib>
#include <iostream>

void charNamePrinting(char charBlock[]);

int main(int argc, char* argv[]) {
    char charName[] = {'A', 'T', 'I', '\0' };
    charNamePrinting(charName); 
    std::cout<< std::endl;

    std::cout << "A Kilépéshez nyomd meg az ENTERT...." << std::endl;
  //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
  return 0;
}

void charNamePrinting(char charBlock[]) {
    for (int i = 0;  charBlock[i] != '\0'; i++)
    {
        std::cout << charBlock[i];
    }
}
```



