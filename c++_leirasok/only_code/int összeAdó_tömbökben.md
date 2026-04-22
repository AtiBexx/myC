# Int Összeadó_Tömbökben_

#### Statikus tömb verzió(előre lefoglalt tömbMéret)

```
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
int blocksReading(int blocks[1000], int maxSize);
int totalBlocks(int blocks[1000], int maxSize);
void blockOutWriting(int blocks[1000], int maxSize);
void exiting(void);

std::string line;
int main(int argc, char *argv[]) {
  int blocks[1000] = {0};
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

```

#### Dinamikus Tömb(Mérete a **futásidőben** dönthető el)(dynamic array / heap array)

- A **heap-en** van lefoglalva.
- Neked kell **felszabadítani** (`delete[]`) a memóriát, különben memória szivárgás lesz.

```
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
```

- `int* blocks = new int[maxSize]{0};` létrehoz egy **heapen lévő fix 1000 elemű tömböt**, minden elem inicializálva 0-ra.
- A **foglalás fix**: mindig 1000 elemnyi memória van lefoglalva, **függetlenül attól, hogy mennyi számot írtál bele**.
- Ha beírsz 3 számot, akkor azok felülírják a tömb első 3 elemét, a többi elem 0 marad.
- Ha a `final` után lenullázod a `valueNumber`-t, és mondjuk a tömb első 3 elemét újra 0-ra állítod (vagy nem), **a teljes tömb továbbra is 1000 elemnyi memória foglalatot jelent**, azaz újra használhatod mind a 1000 helyet.
- A memória **nem csökken** lenullázáskor, a 997 vs 1000 félreértés abból jön, hogy a `valueNumber` változik, de a tömb mérete nem.

Tehát: **a lenullázás csak a tartalmat állítja vissza “üres” állapotba**, a memória mindig 1000 elemnyi marad.

#### **vectoros verziót**, ami teljesen dinamikus:

- Nem kell előre meghatározni a tömb méretét.

- A `std::vector` automatikusan kezeli a memóriát a heap-en.

- Amikor új elemet adsz hozzá, a vector automatikusan növeli a kapacitását.

- Ha lenullázod a vector-t, akkor a mérete 0 lesz, de a memóriát a vector automatikusan kezeli, nem kell `delete[]`.

```c++
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
```

A **for-each** ciklus a `vector`-okon (és más konténereken) így működik:

```cpp
for (int elem : blocks) {
    std::cout << elem << std::endl;
}
```

- Itt `elem` **minden egyes elemet tartalmaz sorrendben** a `blocks` vectorból.
- Nem kell indexelni (`blocks[i]`), mert a ciklus **automatikusan végigmegy minden elemen**.
- Ha módosítani akarod az elemeket, akkor így kell írni:

```cpp
for (int& elem : blocks) {
    elem *= 2;  // pl. minden elemet duplázunk
}
```

- Az `&` referencia miatt **valódi elemet módosítunk**, nem másolatot.
- Ha nincs `&`, akkor csak egy másolatot kapsz, és az eredeti vector **nem változik**.

------

