#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>
int main(int argc, char *argv[])
{

    // Értékek inicializálása
    float fValue1, fValue2, fValue3;
    std::string line;
    
    // megadunk 3 számot
        std::cout << "Ez a program 3 számot\n"
                  << "lebegőpontos (float) értékre átlagol.\n";

    for (;;)
    {
        std::cout << "Kérlek adj meg 3 számot:\n";
        std::cout << "A kilépéshaez használd az 'exit' parancsot\n";

        std::cout << "Első szám: ";
        std::getline(std::cin, line);
        if (line == "exit")
            break;
        std::stringstream ss1(line);
        if (!(ss1 >> fValue1))
        {
            std::cout << "Kérlek csak számot adj meg\n"
                      << "vagy az 'exit' parancsot használd a kilépéshez\n";
            continue;
        }

        std::cout << "Második szám: ";
        std::getline(std::cin, line);
        std::stringstream ss2(line);
        if (line == "exit")
            break;
        if (!(ss2 >> fValue2))
        {
            std::cout << "Kérlek csak számot adj meg\n"
                      << " vagy az 'exit' parancsot használd a kilépéshez\n";
            continue;
        }

        std::cout << "harmadik szám: ";
        std::getline(std::cin, line);
        if (line == "exit")
            break;
        std::stringstream ss3(line);
        if (!(ss3 >> fValue3))
        {
            std::cout << "Kérlek csak számot adj meg\n"
                      << " vagy az 'exit' parancsot használd a kilépéshez\n";
            continue;
        }

        // elöször a 3 szám tört összege
        std::cout << "\n";
        std::cout << "n1/3 + n2/3 + n3/3 = ";
        std::cout << std::fixed << std::setprecision(10);
        std::cout << fValue1 / 3 + fValue2 / 3 + fValue3 / 3 << "\n";

        // most a 3 szám összegének a törtrésze
        std::cout << "\n";
        std::cout << "(n1 + n2 + n3)/3 = ";
        std::cout << std::fixed << std::setprecision(10);
        std::cout << (fValue1 + fValue2 + fValue3) / 3 << "\n";
        std::cout << "\n";
    }

    // kilépünk
    std::cout << "A kilépéshez nyomd meg az Entert";
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}