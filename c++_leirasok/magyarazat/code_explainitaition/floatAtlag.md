```
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>


//függvényprototípus/függvényDeklaráció
int error();
void error2();
void value(float fValue1, float fValue2, float fValue3);

//'int' csinál valamit, hogy visszaadja a hibakód értékét
int error() {
    std::cout << "Nem számot adtál meg!\nKérlek csak számot adj meg!" << std::endl;
    return 1;
}
//'void' nem csinál semmit, csak visszaadja a függvényt
void error2() {
    std::cout << "Kérlek csak számot adj meg\n"
    << " vagy az 'exit' parancsot használd a kilépéshez\n";
}

void value(float fValue1, float fValue2, float fValue3) {
    // elöször a 3 szám tört összege
        std::cout << "\n";
        std::cout << "n1/3 + n2/3 + n3/3 = ";
        std::cout << fValue1 / 3 + fValue2 / 3 + fValue3 / 3 << "\n";

        // most a 3 szám összegének a törtrésze
        std::cout << "\n";
        std::cout << "(n1 + n2 + n3)/3 = ";
        std::cout << (fValue1 + fValue2 + fValue3) / 3 << "\n";
        std::cout << "\n";
}


int main(int argc, char *argv[])
{

    // Értékek inicializálása
    float fValue1, fValue2, fValue3;
    std::string line;
    // megadunk 3 számot
    std::cout << "Ez a program 3 számot\n"
              << "lebegőpontos (float) értékre átlagol.\n";

    // Bekérjük az Argumentumot
    // if (argc != 4)
    if (argc == 4)
    {
        char *endptr;
       fValue1 = std::strtof(argv[1], &endptr);
                if (*endptr != '\0') return error(); //ellenőrizük hogy szám-e
        fValue2 = std::strtof(argv[2], &endptr);
                if (*endptr != '\0') return error(); 
        fValue3 = std::strtof(argv[3], &endptr);
                if (*endptr != '\0') return error(); 
        value(fValue1, fValue2, fValue3);
        
        

    } else {
        // Interaktiv mód
    for (;;)
    {
        std::cout << "Kérlek adj meg 3 számot:\n";
        std::cout << "A kilépéshaez használd az 'exit' parancsot\n";

        std::cout << "Első szám: ";
        std::getline(std::cin, line);
        if (line == "exit")
            break;
        char* endptr;
        fValue1 = std::strtof(line.c_str(), &endptr);
        if (endptr == line.c_str() || *endptr != '\0') {
        error2();
        continue; // vissza a ciklus elejére
    }

        std::cout << "Második szám: ";
        std::getline(std::cin, line);
        if (line == "exit")
            break;
        fValue2 = std::strtof(line.c_str(), &endptr);
        if (endptr == line.c_str() || *endptr != '\0') {
        error2();
        continue; // vissza a ciklus elejére
    }

        std::cout << "harmadik szám: ";
        std::getline(std::cin, line);
        if (line == "exit")
            break;
        fValue3 = std::strtof(line.c_str(), &endptr);
        if (endptr == line.c_str() || *endptr != '\0') {
        error2();
        continue; // vissza a ciklus elejére
    }
        //Meghívjuk a függvényünket ami számol
        value(fValue1, fValue2, fValue3);
    }
}
    if (argc <= 3)
    {
    // kilépünk
    std::cout << "A kilépéshez nyomd meg az Entert";
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
    }
}
```

