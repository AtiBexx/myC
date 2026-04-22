/**
Ez a program tömbökbe menti el a beírt eredményeket majd
kiírja a tömbök számát/értékét és megjeleníti azokat
*/
#include <iostream>
#include <string>
#include <vector>
// ProtoType declaration
void explorationOfprogram(void);
int blocksReading(std::vector<int>& blocks);
int totalBlocks(const std::vector<int>& blocks);
void blockOutWriting(const std::vector<int>& blocks);
void exiting(void);

std::string line;
int main(int argc, char *argv[]) {
     std::vector<int> blocks;
  if (argc == 1) {
    explorationOfprogram();
    blocksReading(blocks);
    exiting();
    return 0;
  } else {
    for (int i = 1; i < argc; i++) {
      blocks.push_back(std::stoi(argv[i]));
    }
    std::cout << "A tömbök száma: " << blocks.size() << std::endl;
    std::cout << "Elemek:\n";
    blockOutWriting(blocks);
    std::cout << "Összeg: " << totalBlocks(blocks) << std::endl;
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

int blocksReading(std::vector<int>& blocks) {
  int valueNumber = 0;
  for (;;) {
    int value = 0; // nem kötelező a 0 de szebb
    std::cout << "Kérlek add meg a számokat(exit-> kilépés, cls->képernyő "
                 "törlés, final-> összegzés): ";
    std::getline(std::cin, line);

    if (line == "exit") {
      if (!blocks.empty())
      {
      std::cout << "A tömbök száma: " << blocks.size() << std::endl;
      std::cout << "Elemek:\n";
      blockOutWriting(blocks);
      std::cout << "A teljes bevitt összeg: "
                << totalBlocks(blocks) << std::endl;
      return valueNumber;
      }else {
        return valueNumber;
      }
     // exiting ending 
    } else if (line == "cls") {
      std::cout << "\x1B[2J\x1B[H"; // natív képernyő törlés
    } else if (line == "final") {
      std::cout << "A tömbök száma: " << blocks.size() << std::endl;
      std::cout << "Elemek:\n";
      blockOutWriting(blocks);
      std::cout << "A teljes bevitt összeg: "
                << totalBlocks(blocks) << std::endl;
      // lenullázuk a tömböket és az értékeiket
      blocks.clear();
      //valueNumber = 0;
      // value = 0; nem kell lenulázni mert a ciklus végén ujraíndul
    } else {
      try {
        value = std::stoi(line);
        blocks.push_back(value);
        valueNumber++;
      } catch (const std::exception &) {
        std::cerr << "Rossz input.\nKérlek csak számot adj meg." << std::endl;
      }
    }
  }
}

int totalBlocks(const std::vector<int>& blocks) {
  int total = 0;

  for (int i = 0; i < blocks.size(); i++) {
    total += blocks[i];
  }
  return total;
}
void blockOutWriting(const std::vector<int>& blocks) {
  for (int i = 0; i < blocks.size(); i++) {
    std::cout << "[" << i << "] = " << blocks[i] << std::endl;
  }
}

void exiting() {
  std::cout << "A kilépéshez kérlek nyomd meg az entert." << std::endl;
  std::cin.get();
  // return 0 ;
}
