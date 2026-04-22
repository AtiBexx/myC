#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>

int main(int argc, char *argv[])
{

    // Értékek inicializálása
    float fValue1, fValue2, fValue3;
    std:: string  line;
    
    for (;;)
    {
        // megadunk 3 számot
        std::cout << " Ez a program 3 számot\n"
                  << " lebegőpontos (float) értékre átlagol\n\n";
        std::cout << "Kérlek adj meg 3 számot (vagy írd be: exit):\n";

        std::cout << "Első szám: ";
        std::cin >> line;
        if (line == "exit") break;

        try {
            fValue1 = std::stof(line);
        } catch (...) {
            std::cout << "Nem számot adtál meg!\nKérlek csak számot adj meg!\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Második szám: ";
        if (!(std::cin >> fValue2)) {
            std::cout << "Nem számot adtál meg!\nKérlek csak számot adj meg!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Harmadik szám: ";
        if (!(std::cin >> fValue3)) {
            std::cout << "Nem számot adtál meg!\nKérlek csak számot adj meg!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        // elöször a 3 szám tört összege
    std::cout << "n1/3 + n2/3 + n3/3 = ";
    std::cout << fValue1/3 + fValue2/3 + fValue3/3 << "\n";

    // most a 3 szám összegének a törtrésze
    std::cout << "(n1 + n2 + n3)/3 = ";
    std::cout << (fValue1 + fValue2 + fValue3)/3 << "\n";
        
    }

    // kilépünk
    std::cout << "A kilépéshez nyomd meg az Entert";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}