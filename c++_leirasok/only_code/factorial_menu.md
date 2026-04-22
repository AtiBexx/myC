### Helyes minta, régi stílusban

```
int szam;
string order;

cout << "Adj meg egy számot vagy parancsot: ";
if (cin >> szam) {
    cout << "Beolvasott szám: " << szam << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // buffer törlése
} 
else {
    cin.clear(); // hibajelzés törlése
    cin >> order;
    cout << "Beolvasott parancs: " << order << endl;
}
```

**Magyarázat:**

1. `cin >> szam` → próbál számot beolvasni
2. Ha nem sikerül (pl. `"exit"`), a `cin` hibajelzést ad → `else` ág fut
3. `cin.clear()` → törli a hibát, így lehet újra olvasni a bufferből
4. `cin >> order` → a bufferből olvas, szóközig

```c++
#include<cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
    using namespace std;

    // PrototypeDeclaration
    void explanation(void); void exiting(int); void menu(void);
    unsigned long long factorial(unsigned long long);
    void factorialOutput(unsigned long long);

    int main(int argc, char *argv[]) {
      if (argc == 1) {
        menu();
      } else if(argc == 2) {
        unsigned long long n;
        stringstream ss(argv[1]);
        if (!(ss >> n)) {
            cout << "Hiba: nem ervenyes szamot adtal meg!" << endl;
            return 1;
        } else {
            cout << n << "! = " << factorial(n) << endl;
            return 0;
        }
      } else
      {
        cout << "Tul sok parameter!" << endl;
        cout << "Tul sok számot adtál meg csak egy számot adj meg!" << endl;
      }
    }

    void explanation(void) {
      cout << "Ez a program kiszámítja egy pozitív egész szám faktoriálisát."
           << endl;
      cout << "A kilépéshez használd az 'Exit' parancsot." << endl;
      cout << "A képernyő törléséhez pedig használd a 'cls' parancsot.\n"
           << endl;

      cout << "A menübe való visszalépéshez nyomd meg az ENTER-t." << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();
    } void exiting(int) {
      cout << "A Kilépeshez kérlek nyomd meg az enter-t......" << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();
      exit(0);
    } void factorialOutput() {
      for (;;) {
        string input;
        unsigned long long n;
        cout << "A kilépéshez használd az 'Exit' parancsot." << endl;
        cout << "A képernyő törléséhez pedig használd a 'cls' parancsot."
             << endl;
        cout << "Adj meg egy pozitiv egész számot: ";
        getline(cin, input);

        if (input == "exit" || input == "EXIT" || input == "Exit") {
          menu();
          return;
        } else if (input == "cls") {
          cout << "\x1B[2J\x1B[H";
          continue;
        }
        // ha nem szám
        long long temp;
        stringstream ss(input);
        if (!(ss >> temp) || temp < 0) {
          cout << "Nem számot adtál meg" << endl;
          cout << "Vagy ha igen akkor negatívat" << endl;
          cout << "Kérlek csak spozitiv egész számot adj meg !!!\n" << endl;
          continue; // újra a ciklus eleje
        } else {
          unsigned long long n = temp;
          cout << "A megadott szám kaktoriális értéke:" << endl;
          cout << n << "! = " << factorial(n) << endl;
        }
      }
    } unsigned long long factorial(unsigned long long n) {
      if (n > 20)
      {
        cerr << "Túlcsordulás 20-nál ne írj nagyobbat" << endl;
        cout << "Maximum 20-at adhatsz meg1!" << endl;
        //return 1;
        return EXIT_FAILURE;
      }  
      unsigned long long fact = 1;
      for (int i = 1; i <= n; i++) {
        fact *= i;
      }
      return fact;
    } void menu(void) {
      while (true) {
        int value;
        cout << "===== MENU =====" << endl;
        cout << "1 - Faktorialis szamitas" << endl;
        cout << "2 - Magyarazat" << endl;
        cout << "3 - Kilepes" << endl;

        cout << "választás: ";
        cin >> value;
        if (cin.fail())
        /*if (!(cin >> value))*/
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Nem számot adtál meg!" << endl;
          cout << "Kérlek add meg újra a megadott szamot 1-3-ig....." << endl;
          continue; // vissza a menübe
        }

        switch (value) {

        case 1:
          factorialOutput();
          break;

        case 2:
          explanation();
          break;

        case 3:
          exiting(0);
          break;

        default:
          if (value > 3 || value < 1) {
            cout << "A megadott szam nem megfelelo" << endl;
            cout << "Kérlek add meg újra a megadott szamot 1-3-ig....." << endl;
            continue; // újra a ciklus eleje
          }
        }
      }
    }
```

#### egy másik verzió getline nélkül

```
#include <iostream>
#include <cstdlib>
using namespace std;

// Prototípusok
void explanation();
void exiting();
unsigned long long factorial(unsigned long long);
void factorialOutput();

int main() {
    while (true) {
        int choice;
        cout << "===== MENU =====" << endl;
        cout << "1 - Faktoriális számítás" << endl;
        cout << "2 - Magyarázat" << endl;
        cout << "3 - Kilépés" << endl;
        cout << "Választás: ";

        if (!(cin >> choice)) { // ha nem számot adtak meg
            cin.clear(); // hibajelzés törlése
            string dummy;
            cin >> dummy; // buffer ürítése
            cout << "Nem számot adtál meg! Próbáld újra." << endl;
            continue; // vissza a menübe
        }

        switch (choice) {
            case 1:
                factorialOutput();
                break;
            case 2:
                explanation();
                break;
            case 3:
                exiting();
                break;
            default:
                cout << "Hibás választás! Adj meg 1-3 közötti számot." << endl;
        }
    }
}

void explanation() {
    cout << "\nEz a program kiszámítja egy pozitív egész szám faktoriálisát." << endl;
    cout << "A kilépéshez írd be az 'exit' parancsot." << endl;
    cout << "A képernyő törléséhez írd be a 'cls' parancsot.\n" << endl;
}

void exiting() {
    cout << "Kilépés... Enter a befejezéshez." << endl;
    cin.ignore(); // buffer törlése
    cin.get();
    exit(0);
}

void factorialOutput() {
    while (true) {
        cout << "\nAdj meg egy pozitív egész számot, vagy írd be a parancsot (exit / cls): ";

        int num;
        string command;

        if (cin >> num) { // sikerült számot olvasni
            if (num < 0) {
                cout << "Csak pozitív számot adhatsz meg!" << endl;
                continue;
            }
            cout << num << "! = " << factorial(num) << endl;
        } else { // nem szám, próbáljuk parancsként olvasni
            cin.clear(); // hibajelzés törlése
            cin >> command; // buffer ürítése
            if (command == "exit" || command == "EXIT") {
                return; // vissza a menübe
            } else if (command == "cls") {
                cout << "\x1B[2J\x1B[H"; // képernyő törlés
            } else {
                cout << "Ismeretlen parancs! Adj meg számot vagy 'exit'/'cls'-t." << endl;
            }
        }
    }
}

unsigned long long factorial(unsigned long long n) {
    unsigned long long fact = 1;
    for (unsigned long long i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
```

Pontosan, Ati — ha szeretnéd a programot több nyelvre “localizable”-ra csinálni, akkor a **szövegeket célszerű változókba vagy konstansokba rakni**, ne hardkódold őket a `cout`-ba. Így később könnyen át lehet írni a nyelvet, anélkül, hogy minden egyes `cout`-ot át kellene alakítani.

Például:

```cpp
// Nyelvi szövegek
string MSG_MENU_TITLE       = "===== MENU =====";
string MSG_OPTION_1         = "1 - Faktoriális számítás";
string MSG_OPTION_2         = "2 - Magyarázat";
string MSG_OPTION_3         = "3 - Kilépés";
string MSG_CHOOSE           = "választás: ";
string MSG_NOT_NUMBER       = "Nem számot adtál meg!";
string MSG_INVALID_OPTION   = "A megadott szám nem megfelelő";
string MSG_ENTER_NUMBER     = "Adj meg egy pozitív egész számot: ";
string MSG_NEGATIVE_NUMBER  = "NEGATÍV számot ne!";
string MSG_FACTORIAL_RESULT = "A megadott szám faktoriális értéke:";
string MSG_EXIT_INSTR       = "A kilépéshez használd az 'Exit' parancsot.";
string MSG_CLEAR_SCREEN     = "A képernyő törléséhez használd a 'cls' parancsot.";
```

És a `cout`-ok helyett:

```cpp
cout << MSG_MENU_TITLE << endl;
cout << MSG_OPTION_1 << endl;
cout << MSG_OPTION_2 << endl;
cout << MSG_OPTION_3 << endl;
cout << MSG_CHOOSE;
```

Ugyanígy a `factorialOutput()`-ban:

```cpp
cout << MSG_EXIT_INSTR << endl;
cout << MSG_CLEAR_SCREEN << endl;
cout << MSG_ENTER_NUMBER;
```

------

### Ha több nyelvet szeretnél:

- Készíthetsz **tömböt vagy map-et** nyelvek szerint, pl. `map<string, string>`-et, vagy `struct`-ot:

```cpp
struct Language {
    string MENU_TITLE;
    string OPTION_1;
    string OPTION_2;
    string OPTION_3;
    string CHOOSE;
    string NOT_NUMBER;
    // ... stb
};

Language hu = { "===== MENU =====", "1 - Faktoriális számítás", "2 - Magyarázat", "3 - Kilépés", "választás: ", "Nem számot adtál meg!" };
Language en = { "===== MENU =====", "1 - Factorial Calculation", "2 - Explanation", "3 - Exit", "choose: ", "Not a number!" };

Language currentLang = hu;
```

És a programban csak `currentLang.MENU_TITLE` stb. használni.

------

Oké Ati, akkor csináljunk egy **kétnyelvű verziót** a factorial menüdhöz, ahol egyszerűen lehet váltani **magyar (HU)** és **angol (EN)** között. A lényege: a szövegeket `struct`-ba rakjuk, és egy `currentLang` változóval választjuk ki a nyelvet. Így a program többi része nem változik, csak a szövegek.

Itt egy példa, hogyan nézhet ki:

```cpp
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
using namespace std;

// Nyelvi struktúra
struct Language {
    string MENU_TITLE;
    string OPTION_1;
    string OPTION_2;
    string OPTION_3;
    string CHOOSE;
    string NOT_NUMBER;
    string INVALID_OPTION;
    string ENTER_NUMBER;
    string NEGATIVE_NUMBER;
    string FACTORIAL_RESULT;
    string EXIT_INSTR;
    string CLEAR_SCREEN;
};

// Magyar szövegek
Language hu = {
    "===== MENÜ =====",
    "1 - Faktoriális számítás",
    "2 - Magyarázat",
    "3 - Kilépés",
    "választás: ",
    "Nem számot adtál meg!",
    "A megadott szám nem megfelelő",
    "Adj meg egy pozitív egész számot: ",
    "NEGATÍV számot ne!",
    "A megadott szám faktoriális értéke:",
    "A kilépéshez használd az 'Exit' parancsot.",
    "A képernyő törléséhez használd a 'cls' parancsot."
};

// Angol szövegek
Language en = {
    "===== MENU =====",
    "1 - Factorial calculation",
    "2 - Explanation",
    "3 - Exit",
    "choose: ",
    "Not a number!",
    "Invalid option",
    "Enter a positive integer: ",
    "Don't enter a negative number!",
    "Factorial of the number is:",
    "Use 'Exit' command to quit.",
    "Use 'cls' command to clear screen."
};

// Aktuális nyelv
Language currentLang = hu; // alapértelmezett magyar

// Prototípusok
void explanation();
void exiting(int);
void menu();
unsigned long long factorial(unsigned long long);
void factorialOutput();

int main() {
    // Példa: ha akarsz angolra váltani
    // currentLang = en;
    menu();
}

void explanation() {
    cout << currentLang.EXIT_INSTR << endl;
    cout << currentLang.CLEAR_SCREEN << "\n" << endl;
    cout << "Press ENTER to return to menu..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void exiting(int) {
    cout << "Press ENTER to exit..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    exit(0);
}

void factorialOutput() {
    for (;;) {
        string input;
        long long temp;
        cout << currentLang.EXIT_INSTR << endl;
        cout << currentLang.CLEAR_SCREEN << endl;
        cout << currentLang.ENTER_NUMBER;
        getline(cin, input);

        if (input == "exit" || input == "EXIT" || input == "Exit") {
            menu();
            return;
        } else if (input == "cls") {
            cout << "\x1B[2J\x1B[H";
            continue;
        }

        stringstream ss(input);
        if (!(ss >> temp) || temp < 0) {
            cout << currentLang.NOT_NUMBER << endl;
            cout << currentLang.NEGATIVE_NUMBER << "\n" << endl;
            continue;
        } else {
            unsigned long long n = temp;
            cout << currentLang.FACTORIAL_RESULT << endl;
            cout << n << "! = " << factorial(n) << endl;
        }
    }
}

unsigned long long factorial(unsigned long long n) {
    unsigned long long fact = 1;
    for (unsigned long long i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

void menu() {
    while (true) {
        int value;
        cout << currentLang.MENU_TITLE << endl;
        cout << currentLang.OPTION_1 << endl;
        cout << currentLang.OPTION_2 << endl;
        cout << currentLang.OPTION_3 << endl;
        cout << currentLang.CHOOSE;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << currentLang.NOT_NUMBER << endl;
            continue;
        }

        switch (value) {
            case 1: factorialOutput(); break;
            case 2: explanation(); break;
            case 3: exiting(0); break;
            default:
                cout << currentLang.INVALID_OPTION << endl;
                continue;
        }
    }
}
```

**Mit csinál ez a változtatás?**

- A program most már **nyelvfüggetlen**: csak át kell állítani `currentLang = en;` a `main()` elején, és minden szöveg angol lesz.
- Minden `cout` szöveget a `currentLang` ad.
- Egyszerű a karbantartás: ha új nyelvet akarsz, csak létrehozol egy új `Language` structot.

------

### Régi DOS-os módszer

Régen (amikor még nem volt `struct`) így csinálták:

```
int lang = 0; // 0 = HU, 1 = EN

if(lang == 0)
    cout << "1 - Faktoriális számítás" << endl;
else
    cout << "1 - Factorial calculation" << endl;

if(lang == 0)
    cout << "2 - Magyarázat" << endl;
else
    cout << "2 - Explanation" << endl;
```

Azaz **minden egyes kiírásnál if**, ami rengeteg kódot jelentett, főleg nagy programoknál. Ezért a `struct` és a változókba szervezés sokkal karbantarthatóbb.

Pontosan! 😎 Ez a **leggyakoribb modern megoldás**: a szövegeket külön fájlban tartod, pl. `.txt` vagy `.ini` formátumban, és a program induláskor beolvassa.

### Előnyök:

1. Nem kell újra fordítani, ha szöveget változtatsz.
2. Könnyen bővíthető új nyelvekkel.
3. Könnyen kezelhető fordítók vagy nem programozók számára is.

### Példa `.ini` fájlra:

```ini
[HU]
MENU_TITLE====== MENÜ =====
OPTION_1=1 - Faktoriális számítás
OPTION_2=2 - Magyarázat
OPTION_3=3 - Kilépés
PROMPT_NUMBER=Adj meg egy pozitív egész számot:
EXIT_MSG=A kilépéshez használd az 'Exit' parancsot.

[EN]
MENU_TITLE===== MENU =====
OPTION_1=1 - Factorial calculation
OPTION_2=2 - Explanation
OPTION_3=3 - Exit
PROMPT_NUMBER=Enter a positive integer:
EXIT_MSG=Use 'Exit' to quit.
```

### C++ beolvasás alapötlete:

```cpp
#include <fstream>
#include <map>
#include <string>
using namespace std;

map<string, string> langTexts;

void loadLanguage(string filename, string lang) {
    ifstream file(filename);
    string line;
    bool activeLang = false;

    while(getline(file, line)) {
        if(line.empty() || line[0] == ';') continue; // üres sor vagy komment
        if(line[0] == '[') {
            activeLang = (line == "[" + lang + "]");
            continue;
        }
        if(activeLang) {
            size_t eq = line.find('=');
            if(eq != string::npos) {
                string key = line.substr(0, eq);
                string value = line.substr(eq + 1);
                langTexts[key] = value;
            }
        }
    }
}

// Használat
// loadLanguage("lang.ini", "EN");
// cout << langTexts["MENU_TITLE"] << endl;
```

- Innen már **csak `langTexts["OPTION_1"]`** kell minden szöveghez.
- Ha új nyelvet akarsz, csak hozzáadsz új `[FR]`, `[DE]` szekciót a fájlhoz, nem kell a kódot módosítani.

