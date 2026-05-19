#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <limits>


bool isAllDigits(const std::string &str) {
    if (str.empty()) {
        return false; // Üres string nem szám
    }
    for (char c : str ) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            return false; // Nem szám karakter található
        }
    }
    return true;
}

bool constantDigits(const std::string &str) {
    for (char c : str) {
        if (std::isdigit(static_cast<unsigned char>(c))) {
            return true;
        }
    }
    return false;
}
/*
bool isAllDigits(const std::string &s) {
    return !s.empty() &&
           std::all_of(s.begin(), s.end(), [](char c) {
               return c >= '0' && c <= '9';
           });
}
*/



//Névhalmaz egy személy nevét tárolja ezekben az objektumokban
class NameDataSet
{
    public:
        std::string personName;
        // A lista következő bejegyzésének a hivatkozása
        NameDataSet *setNameNext;
};

// A lista első bejegyzésének a mutatója
NameDataSet *nameHead = nullptr;

// Új tag hozzáadása a láncolt listához
void addName(NameDataSet *newName)
{
    // Az aktuális bejegyzésban a lista elejére mutatunk
    newName->setNameNext = nameHead;
    // Az aktuális bejegyzésre mutatunk
    nameHead = newName;
}
// Adatok beolvasása Név taj stb stb
// Null-t add vissza ha nincs mit beolvasni
NameDataSet *readName()
{
    // Beolvassuk az első nevet
    std::string name = "";
    std::cout << "Add meg a neved kérlek: ";
    std::cin >> name;

    // Ha az érték 'Stop' akkor kilépünk
    if (name == "Stop" || name == "stop" || name == "STOP")
    {
        return nullptr;
    }
    if (name.empty()) {
        std::cout <<"A név nem lehet üres. Kérem adjon meg egy nevet." << std::endl;
        //continue;
    }
    if (isAllDigits(name)) {
        std::cout << "A név nem lehet csak szám kérlek adj meg egy nevet." << std::endl;
        return readName();
    }
    if (constantDigits(name)) {
        std::cout << "A név nem tartalmazhat számot  kérlek adj meg egy nevet." << std::endl;
        return readName();
    }

    /*try
    {
        size_t pos;
        std::stoi(name, &pos);
        if (pos == name.size()) {
            std::cout << "2.A név nem lehet csak szám kérlek adj meg egy nevet." << std::endl;
            //continue;
        }
        
    }
    catch (...) {}*/
    NameDataSet *newName = new NameDataSet;
    newName->personName = name;
    return newName;
    }

    int  main(int argc,  char* argv[]) {
    //    int main(int argc, char** argv) -> ugyanaz mint a fenti
    //    int main(int argc, const char** argv) -> HA NEM MÓDOSÍTUNK A MÚTATÓN
    //    int main(int argc, const char* argv[]) -> HA NEM MÓDOSÍTUNK A MÚTATÓN
       std::cout << "A Hallgatók nevének a beolvasása\n";
       std::cout << "A kilépéshez írd be hogy 'Stop'" << std::endl;
       
       NameDataSet *newName;
       while (newName = readName()) {
           addName(newName);
       }
    
    // Az objektumok megjelenítéséhez végig Iterálunk 
    std::cout << "A beolvasott nevek listája: " << std::endl;

    for (NameDataSet *current = nameHead; current != nullptr; current = current->setNameNext) {
        std::cout << current->personName << std::endl;
    }

    //kilépünk a programból
    std::cout << "A folytatáshoz kérlek nyomd meg az Enter-t" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ez a sor biztosítja, hogy az előző bemenet után ne maradjon semmi a bemeneti pufferben
    std::cin.get();
    return 0;
    }

    
