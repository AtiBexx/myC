

## 1. EXIT PARANCS PÉLDÁK (CLI programok)

### Alapvető exit példa (mint a tiéd):

```cpp
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line;
    
    for (;;) {
        std::cout << "Parancs (vagy 'exit' kilépéshez): ";
        std::getline(std::cin, line);
        
        if (line == "exit" || line == "quit") {
            std::cout << "Viszlát!\n";
            break;
        }
        
        std::cout << "Beírtad: " << line << "\n";
    }
    
    return 0;
}
```

### Számológép exit paranccsal:

```cpp
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line;
    
    std::cout << "Egyszerű számológép (írj 'exit' a kilépéshez)\n";
    
    for (;;) {
        std::cout << "\nMűvelet (pl: 5 + 3): ";
        std::getline(std::cin, line);
        
        if (line == "exit") break;
        
        std::stringstream ss(line);
        double a, b;
        char op;
        
        if (ss >> a >> op >> b) {
            switch(op) {
                case '+': std::cout << "= " << a + b << "\n"; break;
                case '-': std::cout << "= " << a - b << "\n"; break;
                case '*': std::cout << "= " << a * b << "\n"; break;
                case '/': 
                    if (b != 0) std::cout << "= " << a / b << "\n";
                    else std::cout << "Hiba: 0-val osztás!\n";
                    break;
                default: std::cout << "Érvénytelen művelet!\n";
            }
        } else {
            std::cout << "Hibás formátum!\n";
        }
    }
    
    return 0;
}
```

### Menü rendszer exit-tel:

```cpp
#include <iostream>
#include <string>

void menu() {
    std::cout << "\n--- MENÜ ---\n";
    std::cout << "1. Funkció 1\n";
    std::cout << "2. Funkció 2\n";
    std::cout << "3. Funkció 3\n";
    std::cout << "exit - Kilépés\n";
    std::cout << "Választás: ";
}

int main() {
    std::string valasztas;
    
    for (;;) {
        menu();
        std::getline(std::cin, valasztas);
        
        if (valasztas == "exit" || valasztas == "q") {
            std::cout << "Kilépés...\n";
            break;
        }
        
        if (valasztas == "1") {
            std::cout << "Funkció 1 fut...\n";
        } else if (valasztas == "2") {
            std::cout << "Funkció 2 fut...\n";
        } else if (valasztas == "3") {
            std::cout << "Funkció 3 fut...\n";
        } else {
            std::cout << "Ismeretlen parancs!\n";
        }
    }
    
    return 0;
}
```

### Parancs alapú rendszer (több paranccsal):

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string line;
    std::vector<std::string> torzsadat;
    
    std::cout << "Egyszerű TODO lista\n";
    std::cout << "Parancsok: add <szöveg>, list, clear, exit\n\n";
    
    for (;;) {
        std::cout << "> ";
        std::getline(std::cin, line);
        
        std::stringstream ss(line);
        std::string parancs;
        ss >> parancs;
        
        if (parancs == "exit" || parancs == "quit") {
            break;
        }
        else if (parancs == "add") {
            std::string maradek;
            std::getline(ss, maradek);
            if (!maradek.empty()) {
                torzsadat.push_back(maradek.substr(1)); // első space levágása
                std::cout << "Hozzáadva!\n";
            }
        }
        else if (parancs == "list") {
            if (torzsadat.empty()) {
                std::cout << "A lista üres.\n";
            } else {
                for (size_t i = 0; i < torzsadat.size(); i++) {
                    std::cout << i+1 << ". " << torzsadat[i] << "\n";
                }
            }
        }
        else if (parancs == "clear") {
            torzsadat.clear();
            std::cout << "Lista törölve.\n";
        }
        else if (parancs == "help") {
            std::cout << "Parancsok:\n";
            std::cout << "  add <szöveg> - Elem hozzáadása\n";
            std::cout << "  list - Elemek listázása\n";
            std::cout << "  clear - Lista törlése\n";
            std::cout << "  exit - Kilépés\n";
        }
        else {
            std::cout << "Ismeretlen parancs: " << parancs << "\n";
        }
    }
    
    return 0;
}
```

------

## 2. HOGYAN OLVASS C++ KÖNYVTÁRI DOKUMENTÁCIÓT?

### A) cppreference.com használata

**1. Menj a cppreference.com-ra**

**2. Keress rá az adott dologra**, pl. `std::getline`

**3. Amit ott látsz:**

```
Defined in header <string>

(1) std::istream& getline(std::istream& input, std::string& str, char delim);
(2) std::istream& getline(std::istream& input, std::string& str);
```

**Mit jelent:**

- `Defined in header <string>` → **#include <string>** kell!
- `std::istream& input` → **ahonnan olvasol** (pl. `std::cin`)
- `std::string& str` → **ide megy** az eredmény
- `char delim` → **elválasztó karakter** (alapértelmezett: `\n`)

**4. Nézd meg a példákat lent:**

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Név: ";
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "!\n";
}
```

------

### B) Dokumentáció olvasása lépésről lépésre

**Példa: `std::stringstream`**

**1. Keresd meg:** https://cppreference.com → search: "stringstream"

**2. Nézd meg:**

```
Defined in header <sstream>

class stringstream : public std::iostream
```

→ Ez azt jelenti: **#include <sstream>** kell!

**3. Scrollozz le a "Member functions"-höz**

Látod:

- `operator>>` - beolvasás
- `operator<<` - kiírás
- `str()` - string lekérése/beállítása

**4. Nézd a példát:**

```cpp
#include <sstream>
#include <iostream>

int main() {
    std::stringstream ss;
    ss << "123 456";  // Írás
    
    int a, b;
    ss >> a >> b;     // Olvasás
    
    std::cout << a << " " << b << "\n";  // 123 456
}
```

------

### C) Gyakorlati tippek dokumentáció olvasáshoz:

**1. NE OLVASD EL AZ EGÉSZET!**

- Ugorj a példákhoz
- Nézd meg a "See also" részt
- Keresd a "Example" szekciót

**2. PRÓBÁLD KI RÖGTÖN**

```cpp
#include <iostream>
#include <sstream>

int main() {
    // Kipróbálom amit olvastam
    std::stringstream ss("42");
    int szam;
    ss >> szam;
    std::cout << szam << "\n";
}
```

**3. HA NEM ÉRTED:**

- YouTube: "C++ stringstream tutorial"
- Stack Overflow: keress rá
- Kérdezz chatben (mint most!)

------

### D) Példa: Ismeretlen függvény megértése

**Találsz egy kódban:** `std::cin.ignore()`

**1. Keresd rá:** cppreference.com → "cin ignore"

**2. Látsz:**

```
std::istream& ignore(std::streamsize count = 1, int delim = EOF);
```

**3. Olvasd el:** "Extracts and discards characters from the input stream"

**4. Nézd a példát:**

```cpp
std::cin.ignore(1000, '\n');  // Töröl 1000 karaktert VAGY \n-ig
```

**5. Használd:**

```cpp
int szam;
std::cin >> szam;
std::cin.ignore(1000, '\n');  // Töröljük a maradék sort
std::string sor;
std::getline(std::cin, sor);  // Most már működik!
```

------

##  ÖSSZEFOGLALVA:

**Dokumentáció olvasáshoz:**

1. Menj cppreference.com-ra
2. Keresd meg a függvényt/osztályt
3. **Nézd meg a példákat ELŐSZÖR**
4. Próbáld ki saját kódban
5. Ha nem megy → YouTube, Stack Overflow

**Exit parancs példákhoz:**

- Használd a fenti kódokat
- Kombinálj belőlük
- Építs rájuk

