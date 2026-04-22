## Float_es_Double_AtlagSzamitas

```
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <limits>

int main(int argc, char *argv[])
{

    // Értékek inicializálása
    float fValue1, fValue2, fValue3;

    for (;;)
    {
        // megadunk 3 számot
        std::cout << " Ez a program 3 számot\n"
                  << " lebegőpontos (float) értékre átlagol\n\n";
        std::cout << "Kérlek adj meg 3 számot:\n";

        std::cout << "Első szám: ";
        std::cin >> fValue1;

        std::cout << "Második szám: ";
        std::cin >> fValue2;

        std::cout << "Harmadik szám: ";
        std::cin >> fValue3;

        if (!std::cin.fail())
        {
            break;
        }
        else
        {
            std::cout << "Nem számot adtál meg!\n"
                      << "Kérlek csak számot adj meg!\n";
            std::cin.clear();                                                   // Hibajelzés tőrlése
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ürítjuk a puffert
        }
    }

    // elöször a 3 szám tört összege
    std::cout << "n1/3 + n2/3 + n3/3 = ";
    std::cout << fValue1/3 + fValue2/3 + fValue3/3 << "\n";

    // most a 3 szám összegének a törtrésze
    std::cout << "(n1 + n2 + n3)/3 = ";
    std::cout << (fValue1 + fValue2 + fValue3)/3 << "\n";

    // kilépünk
    std::cout << "A kilépéshez nyomd meg az Entert";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
```

Ez a program átlagot számol de még mindig nem tizedesen pontossan..<br>

Adjuk hozzá az **`exit`** parancsot is ....<br>

A hibát már kezeltük itt.

```
 if (!std::cin.fail())
        {
            break;
        }
        else
        {
            std::cout << "Nem számot adtál meg!\n"
                      << "Kérlek csak számot adj meg!\n";
            std::cin.clear();                                                   // Hibajelzés tőrlése
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ürítjuk a puffert
        }
    }
```



**3.Módszer**

## 3 helyes megoldás

**1. stringstream (C++-os, tanulható)**

```
std::stringstream ss(line);
if (!(ss >> fValue1)) {
    std::cout << "Nem szám!\n";
}
```

------

**2. std::stof (egyszerű)**

```
try {
    fValue1 = std::stof(line);
} catch (...) {
    std::cout << "Nem szám!\n";
}
```

------

 **3. strtof + endptr (low-level, profi)**

```
char* end;
fValue1 = std::strtof(line.c_str(), &end);
if (end == line.c_str() || *end != '\0') {
    std::cout << "Nem szám!\n";
}
```

**Exit_Parancsal**

1. **Megoldás**

```
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <sstream>
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
        std::cout << fValue1 / 3 + fValue2 / 3 + fValue3 / 3 << "\n";

        // most a 3 szám összegének a törtrésze
        std::cout << "\n";
        std::cout << "(n1 + n2 + n3)/3 = ";
        std::cout << (fValue1 + fValue2 + fValue3) / 3 << "\n";
        std::cout << "\n";
    }

    // kilépünk
    std::cout << "A kilépéshez nyomd meg az Entert";
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
```



```
//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
```

Nem kell puffert üríteni 

`std::getline` **egész sort olvas** (`\n`-ig).

A sor végén a `\n` **automatikusan eldobódik** → nincs maradék a bufferben.

Ezért **nincs szükség `std::cin.ignore()`-ra** minden szám után.



2. **Megoldás**

```
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
```

Az  `std::stof` a `std::string`-et (`line`) **float értékké alakítja**.

**!!!! kivételkezelés kell, mert lehet hibás input .**

```
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
```

`#include <iomanip>`<br>

```
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
```



```
std::cout << std::fixed << std::setprecision(10);
```

Pedig 10 számjegyig irja ki az eredményt.....

kimenet pl:

```
n1/3 + n2/3 + n3/3 = 1.0000000000

(n1 + n2 + n3)/3 = 1.0000000000
```

3. **Megoldás**

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

Ebben a verzióban függvényeket is írtunk hogy ne keljen állandóan bemásolni ugyanazt 

```
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
```

- **Void** --ez nem add vissza értéket semmit sem
- **Double** -- Double értéket add vissza
- **Int** -- A return 1 int értéket add vissza...

```
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
        }    
```

Itt kérjük be az argumentumot ....