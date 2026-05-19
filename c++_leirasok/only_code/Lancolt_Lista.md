```
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

    try
    {
        size_t pos;
        int value =std::stoi(name, &pos);
        if (pos == name.size()) {
            std::cout << "2.A név nem lehet csak szám kérlek adj meg egy nevet." << std::endl;
            return readName();
        }
        
    }
    catch (...) {}
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
       while ((newName = readName())) {
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
/*
singly linked list = egyszeresen láncolt lista
doubly linked list = kétszeresen láncolt lista
circular linked list = körkörös láncolt lista*/
    

```

#### stoi

Itt nem szükséges de a gyakorlás céljából benne hagytam

Oké, végigmegyek rajta tisztán, hogy mi mit csinál, sallang nélkül.

------

# Header-ek

```cpp
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <limits>
```

- `<iostream>`: `cout`, `cin` (képernyő + billentyűzet)
- `<string>`: `std::string` típus
- `<cctype>`: karakter függvények (`isdigit`)
- `<limits>`: `numeric_limits` (input tisztítás)
- `<cstdio>`, `<cstdlib>`: itt most gyakorlatilag nem használod → elhagyható

------

# isAllDigits

```cpp
bool isAllDigits(const std::string &str)
```

Mit csinál:

- megnézi, hogy a string **csak számokból áll-e**

Lépések:

- ha üres → false
- végigmegy minden karakteren
- ha talál nem számot → false
- ha minden szám → true

Példa:

- `"123"` → true
- `"12a"` → false
- `"a2"` → false

------

# constantDigits

```cpp
bool constantDigits(const std::string &str)
```

Mit csinál:

- megnézi, hogy **van-e benne legalább 1 szám**

Lépések:

- végigmegy a stringen
- ha talál számot → true

Példa:

- `"Ati"` → false
- `"a2"` → true
- `"123"` → true

------

# class NameDataSet

```cpp
class NameDataSet
```

Ez egy objektum (egy “doboz” adatnak)

Tartalma:

```cpp
std::string personName;
NameDataSet *setNameNext;
```

- `personName`: a név
- `setNameNext`: pointer a következő elemre

Ez csinálja a láncolt listát.

------

# nameHead

```cpp
NameDataSet *nameHead = nullptr;
```

- ez a lista **első eleme**
- kezdetben nincs semmi → `nullptr`

------

# addName

```cpp
void addName(NameDataSet *newName)
```

Mit csinál:

- új elemet berak a lista elejére

Lépések:

1. az új elem következője = régi head
2. head = új elem

Ezért fordított sorrend lesz a kiírásnál.

------

# readName

```cpp
NameDataSet *readName()
```

Ez a program lelke.

## 1. bekérés

```cpp
std::cin >> name;
```

------

## 2. stop feltétel

```cpp
if (name == "Stop" || ...)
```

- ha Stop → kilép (nullptr)

------

## 3. validálás

### üres string

```cpp
if (name.empty())
```

- hiba, de nem állítja le (ez egy kis hiba a logikában)

------

### csak szám

```cpp
if (isAllDigits(name))
```

- pl: "123"
- újra bekéri (rekurzió)

------

### van benne szám

```cpp
if (constantDigits(name))
```

- pl: "a2"
- újra bekéri

------

## 4. stoi rész

```cpp
int value = std::stoi(name, &pos);
```

Mit csinál:

- megpróbálja számként értelmezni a stringet
- `pos` megmondja meddig volt szám

```cpp
if (pos == name.size())
```

- ha teljesen szám volt → hibás név → újra kér

------

Fontos:

- ezt most redundánsan csinálod, mert a fenti 2 check már lefedi

------

## 5. visszatérés

```cpp
NameDataSet *newName = new NameDataSet;
newName->personName = name;
return newName;
```

- létrehoz egy új elemet
- eltárolja a nevet
- visszaadja pointerként

------

# main

## 1. kezdés

Kiírja a szöveget

------

## 2. beolvasás ciklus

```cpp
while ((newName = readName()))
```

Mit jelent:

- hívja readName-et
- ha nullptr → stop
- ha van adat → beteszi listába

------

## 3. kiírás

```cpp
for (NameDataSet *current = nameHead;
     current != nullptr;
     current = current->setNameNext)
```

Mit csinál:

- végigmegy a láncolt listán
- kiírja a neveket

------

## 4. várakozás

```cpp
cin.ignore(...)
cin.get();
```

- hogy ne záródjon be azonnal a konzol

------

# összefoglalás (egyszerűen)

Ez a program:

1. bekér neveket
2. kiszűri a számokat
3. eltárolja láncolt listában
4. visszafelé sorrendben kiírja

------------------

- pointer = “következő elem címe”
- linked list = egymásra mutató elemek
- head = első elem
- új elem mindig az elejére kerül



