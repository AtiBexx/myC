/**
Ez a program tömbökbe menti el a beírt eredményeket majd
kiírja a tömbök számát/értékét és megjeleníti azokat
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

// ProtoType declaration
void explorationOfprogram(void);
int blocksReading(int blocks[], int maxSize);
int totalBlocks(int blocks[], int maxSize);
void blockOutWriting(int blocks[], int maxSize);
void exiting(void);

std::string line;
int main(int argc, char *argv[]) {
    int maxSize = 1000;
   int* blocks = new int[maxSize]{0};  // dinamikus tömb inicializálva nullával
  if (argc == 1) {
    explorationOfprogram();
    blocksReading(blocks, 1000);
    exiting();
    return 0;
  } else {
    int valueNumber = 0;
    for (int i = 1; i < argc; i++) {
      blocks[valueNumber++] = std::stoi(argv[i]);
    }
    std::cout << "A tömbök száma: " << valueNumber << std::endl;
    std::cout << "Elemek:\n";
    blockOutWriting(blocks, valueNumber);
    std::cout << "Összeg: " << totalBlocks(blocks, valueNumber) << std::endl;
    delete[] blocks;  // dinamikus tömb felszabadítása
    return 0;
  }
}

void explorationOfprogram() {
  std::cout << "Ez a program tömbökbe menti el a beírt eredményeket majd \n"
            << "kiírja a tömbök számát/erdeményet és megjeleníti azokat\n"
            << "A teljes kilépéahez használd az 'exit' parancsot\n"
            << "A képernyő tőrléséhez használd a 'cls' parancsot\n"
            << "A tömbök összegzéséhez pedig használd a 'final' parancsot\n"
            << std::endl;
}

int blocksReading(int blocks[], int maxSize) {
  int valueNumber = 0;
  for (;;) {
    int value = 0; // nem kötelező a 0 de szebb
    std::cout << "Kérlek add meg a számokat(exit-> kilépés, cls->képernyő "
                 "törlés, final-> összegzés): ";
    std::getline(std::cin, line);

    if (line == "exit") {
      if (valueNumber > 0)
      {
      std::cout << "A tömbök száma: " << valueNumber << std::endl;
      std::cout << "Elemek:\n";
      blockOutWriting(blocks, valueNumber);
      std::cout << "A teljes bevitt összeg: "
                << totalBlocks(blocks, valueNumber) << std::endl;
      return valueNumber;
      }else {
        return valueNumber;
      }
     // exiting ending 
    } else if (line == "cls") {
      std::cout << "\x1B[2J\x1B[H"; // natív képernyő törlés
    } else if (line == "final") {
      std::cout << "A tömbök száma: " << valueNumber << std::endl;
      std::cout << "Elemek:\n";
      blockOutWriting(blocks, valueNumber);
      std::cout << "A teljes bevitt összeg: "
                << totalBlocks(blocks, valueNumber) << std::endl;
      // lenullázuk a tömböket és az értékeiket
      valueNumber = 0;
      // value = 0; nem kell lenulázni mert a ciklus végén ujraíndul
    } else {
      try {
        value = std::stoi(line);
        blocks[valueNumber] = value;
        valueNumber++;
      } catch (const std::exception &) {
        std::cerr << "Rossz input.\nKérlek csak számot adj meg." << std::endl;
      }
    }
  }
}

int totalBlocks(int blocks[], int maxSize) {
  int total = 0;

  for (int i = 0; i < maxSize; i++) {
    total += blocks[i];
  }
  return total;
}
void blockOutWriting(int blocks[], int maxSize) {
  for (int i = 0; i < maxSize; i++) {
    std::cout << "[" << i << "] = " << blocks[i] << std::endl;
  }
}

void exiting() {
  std::cout << "A kilépéshez kérlek nyomd meg az entert." << std::endl;
  std::cin.get();
  // return 0 ;
}
