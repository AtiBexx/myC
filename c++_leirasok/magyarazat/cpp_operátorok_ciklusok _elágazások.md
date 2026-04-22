# C++ Operátorok és Vezérlési Struktúrák Teljes Útmutató

## Tartalomjegyzék
1. [Operátorok típusai](#operátorok-típusai)
2. [Operátor precedencia (műveletek sorrendje)](#operátor-precedencia-műveletek-sorrendje)
3. [Értékadó operátorok](#értékadó-operátorok)
4. [Bitenkénti operátorok](#bitenkénti-operátorok)
5. [Logikai operátorok](#logikai-operátorok)
6. [Ciklusok](#ciklusok)
7. [Elágazások](#elágazások)
8. [Switch-case szerkezet](#switch-case-szerkezet)
9. [Ugró utasítások](#ugró-utasítások)
10. [Példák és kódrészletek](#példák-és-kódrészletek)

## Operátorok típusai

### Egyoperandusú (unáris) operátorok
Az egyoperandusú operátorok egy operandust igényelnek.

| Operátor | Leírás | Példa | Prefix/Postfix |
|----------|--------|-------|----------------|
| `+` | Pozitív előjel | `+x` | Prefix |
| `-` | Negatív előjel | `-x` | Prefix |
| `++` | Inkrementálás | `++x`, `x++` | Mindkettő |
| `--` | Dekrementálás | `--x`, `x--` | Mindkettő |
| `!` | Logikai negáció | `!x` | Prefix |
| `~` | Bitenkénti negáció | `~x` | Prefix |
| `*` | Dereferencia | `*ptr` | Prefix |
| `&` | Címoperátor | `&var` | Prefix |
| `sizeof` | Méret operátor | `sizeof(var)` | Prefix |
| `(type)` | Cast operátor | `(int)x` | Prefix |

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int* ptr = &x;  // Címoperátor
    
    cout << "x értéke: " << x << endl;           // 5
    cout << "x címe: " << ptr << endl;           // x címe
    cout << "dereferált érték: " << *ptr << endl; // 5
    
    cout << "++x: " << ++x << endl;              // 6 (prefix: előbb növel, aztán használ)
    cout << "x++: " << x++ << endl;              // 6 (postfix: előbb használ, aztán növel)
    cout << "x értéke: " << x << endl;           // 7
    
    bool flag = true;
    cout << "!flag: " << !flag << endl;          // false logikai negáció
    
    return 0;
}
```

### Kétoperandusú (bináris) operátorok
A kétoperandusú operátorok két operandust igényelnek.

| Operátor | Leírás | Példa |
|----------|--------|-------|
| `+` | Összeadás | `a + b` |
| `-` | Kivonás | `a - b` |
| `*` | Szorzás | `a * b` |
| `/` | Osztás | `a / b` |
| `%` | Maradékos osztás | `a % b` |
| `<` | Kisebb | `a < b` |
| `>` | Nagyobb | `a > b` |
| `<=` | Kisebb vagy egyenlő | `a <= b` |
| `>=` | Nagyobb vagy egyenlő | `a >= b` |
| `==` | Egyenlőség | `a == b` |
| `!=` | Nem egyenlő | `a != b` |
| `&&` | Logikai ÉS | `a && b` |
| `||` | Logikai VAGY | `a || b` |
| `=` | Értékadás | `a = b` |
| `+=` | Összeadás és értékadás | `a += b` |
| `-=` | Kivonás és értékadás | `a -= b` |
| `*=` | Szorzás és értékadás | `a *= b` |
| `/=` | Osztás és értékadás | `a /= b` |
| `%=` | Maradékos osztás és értékadás | `a %= b` |
| `&` | Bitenkénti ÉS | `a & b` |
| `|` | Bitenkénti VAGY | `a | b` |
| `^` | Bitenkénti XOR | `a ^ b` |
| `<<` | Balra dịchés | `a << b` |
| `>>` | Jobbra dịchés | `a >> b` |

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;
    
    cout << "a + b = " << a + b << endl;    // 13
    cout << "a - b = " << a - b << endl;    // 7
    cout << "a * b = " << a * b << endl;    // 30
    cout << "a / b = " << a / b << endl;    // 3
    cout << "a % b = " << a % b << endl;    // 1
    
    bool x = true, y = false;
    cout << "x && y = " << (x && y) << endl; // 0 (false)
    cout << "x || y = " << (x || y) << endl; // 1 (true)
    
    a += b;  // a = a + b
    cout << "a += b után: " << a << endl;    // 13
    
    return 0;
}
```

## Operátor precedencia (műveletek sorrendje)

Az operátor precedencia meghatározza, hogy milyen sorrendben hajtódnak végre az operátorok egy kifejezésben. Az alábbi táblázat csökkenő prioritás szerint sorolja fel az operátorokat:

| Prioritás | Operátor | Leírás | Asszociativitás |
|-----------|----------|--------|-----------------|
| 1 | `::` | Hatókör feloldás | balról jobbra |
| 2 | `++`, `--`, `()`, `[]`, `.`, `->`, `typeid`, `const_cast`, `dynamic_cast`, `reinterpret_cast`, `static_cast` | Postfix inkrementálás/dekrementálás, függvényhívás, indexelés, tagelérés | balról jobbra |
| 3 | `++`, `--`, `+`, `-`, `!`, `~`, `(type)`, `*`, `&`, `sizeof`, `new`, `delete` | Prefix inkrementálás/dekrementálás, egyoperandusú műveletek | jobbról balra |
| 4 | `.*`, `->*` | Tag pointer | balról jobbra |
| 5 | `*`, `/`, `%` | Szorzás, osztás, maradékos osztás | balról jobbra |
| 6 | `+`, `-` | Összeadás, kivonás | balról jobbra |
| 7 | `<<`, `>>` | Biteltolás | balról jobbra |
| 8 | `<`, `<=`, `>`, `>=`, `typeid` | Relációs operátorok | balról jobbra |
| 9 | `==`, `!=` | Egyenlőségvizsgálat | balról jobbra |
| 10 | `&` | Bitenkénti ÉS | balról jobbra |
| 11 | `^` | Bitenkénti XOR | balról jobbra |
| 12 | `|` | Bitenkénti VAGY | balról jobbra |
| 13 | `&&` | Logikai ÉS | balról jobbra |
| 14 | `||` | Logikai VAGY | balról jobbra |
| 15 | `?:`, `throw` | Ternáris operátor | jobbról balra |
| 16 | `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `^=`, `|=`, `<<=`, `>>=` | Értékadó operátorok | jobbról balra |
| 17 | `,` | Vessző operátor | balról jobbra |

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 3, c = 2;
    
    // Precedencia szerint: * előbb mint +, + előbb mint <<
    cout << a + b * c << endl;        // 11 (a + (b * c))
    cout << (a + b) * c << endl;      // 16 ((a + b) * c)
    
    // Relációs operátorok precedenciája magasabb mint logikai VAGY
    cout << (a > b || b < c) << endl; // 1 (true)
    
    // Értékadás jobbról asszociatív
    int x, y, z;
    x = y = z = 10;                   // z = 10, y = 10, x = 10
    
    return 0;
}
```

## Értékadó operátorok

Az értékadó operátorok értéket rendelnek egy változóhoz.

| Operátor | Leírás | Ekvivalens kifejezés |
|----------|--------|----------------------|
| `=` | Sima értékadás | `x = y` |
| `+=` | Összeadás és értékadás | `x = x + y` |
| `-=` | Kivonás és értékadás | `x = x - y` |
| `*=` | Szorzás és értékadás | `x = x * y` |
| `/=` | Osztás és értékadás | `x = x / y` |
| `%=` | Maradékos osztás és értékadás | `x = x % y` |
| `&=` | Bitenkénti ÉS és értékadás | `x = x & y` |
| `|=` | Bitenkénti VAGY és értékadás | `x = x | y` |
| `^=` | Bitenkénti XOR és értékadás | `x = x ^ y` |
| `<<=` | Balra dịchés és értékadás | `x = x << y` |
| `>>=` | Jobbra dịchés és értékadás | `x = x >> y` |

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    
    x += 5;    // x = x + 5; x = 15
    cout << "x += 5: " << x << endl;
    
    x -= 3;    // x = x - 3; x = 12
    cout << "x -= 3: " << x << endl;
    
    x *= 2;    // x = x * 2; x = 24
    cout << "x *= 2: " << x << endl;
    
    x /= 4;    // x = x / 4; x = 6
    cout << "x /= 4: " << x << endl;
    
    x %= 5;    // x = x % 5; x = 1
    cout << "x %= 5: " << x << endl;
    
    return 0;
}
```

## Bitenkénti operátorok

A bitek szintjén végzett műveletek.

| Operátor | Leírás | Példa |
|----------|--------|-------|
| `&` | Bitenkénti ÉS | `a & b` |
| `|` | Bitenkénti VAGY | `a | b` |
| `^` | Bitenkénti XOR (kizáró VAGY) | `a ^ b` |
| `~` | Bitenkénti NEGÁCIÓ (komplementer) | `~a` |
| `<<` | Balra dịchés | `a << b` |
| `>>` | Jobbra dịchés | `a >> b` |

```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned char a = 5;   // Binárisan: 00000101
    unsigned char b = 3;   // Binárisan: 00000011
    
    cout << "a & b = " << (a & b) << endl;   // 1 (00000001)
    cout << "a | b = " << (a | b) << endl;   // 7 (00000111)
    cout << "a ^ b = " << (a ^ b) << endl;   // 6 (00000110)
    cout << "~a = " << (~a) << endl;         // 250 (11111010 - unsigned char esetén)
    
    cout << "a << 1 = " << (a << 1) << endl; // 10 (00001010)
    cout << "a >> 1 = " << (a >> 1) << endl; // 2 (00000010)
    
    return 0;
}
```

## Logikai operátorok

A logikai műveletek igaz/hamis értékekkel dolgoznak.

| Operátor | Leírás | Példa |
|----------|--------|-------|
| `!` | Logikai NEGÁCIÓ | `!a` |
| `&&` | Logikai ÉS | `a && b` |
| `||` | Logikai VAGY | `a || b` |

```cpp
#include <iostream>
using namespace std;

int main() {
    bool a = true;
    bool b = false;
    
    cout << "a && b = " << (a && b) << endl;  // false (0)
    cout << "a || b = " << (a || b) << endl;  // true (1)
    cout << "!a = " << (!a) << endl;          // false (0)
    
    // Rövidzáras kiértékelés
    int x = 5;
    if (x > 0 && ++x > 5) {  // x > 0 igaz, ezért ++x > 5 is kiértékelődik
        cout << "x értéke: " << x << endl;    // 6
    }
    
    return 0;
}
```

## Ciklusok

A ciklusok lehetővé teszik egy utasítás vagy utasításcsoport többszöri végrehajtását.

### for ciklus

A `for` ciklus ismert számú ismétlést végez.

```cpp
// Szintaxis: for(inicializálás; feltétel; léptetés)
for (int i = 0; i < 5; i++) {
    cout << i << " ";
}
// Kimenet: 0 1 2 3 4
```

### while ciklus

A `while` ciklus addig fut, amíg a feltétel igaz.

```cpp
int i = 0;
while (i < 5) {
    cout << i << " ";
    i++;
}
// Kimenet: 0 1 2 3 4
```

### do-while ciklus

A `do-while` ciklus legalább egyszer végrehajtja a ciklustörzset, majd ellenőrzi a feltételt.

```cpp
int i = 0;
do {
    cout << i << " ";
    i++;
} while (i < 5);
// Kimenet: 0 1 2 3 4
```

### Végtelen ciklusok

```cpp
// for (;;) végtelen ciklus
for (;;) {
    // Végtelenül fut, amíg nem történik kilépés
    if (condition) break; // break-el kilépünk
}

// while(true) végtelen ciklus
while (true) {
    // Végtelenül fut, amíg nem történik kilépés
    if (condition) break; // break-el kilépünk
}
```

Teljes példa ciklusokra:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "for ciklus: ";
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    cout << "while ciklus: ";
    int j = 0;
    while (j < 5) {
        cout << j << " ";
        j++;
    }
    cout << endl;
    
    cout << "do-while ciklus: ";
    int k = 0;
    do {
        cout << k << " ";
        k++;
    } while (k < 5);
    cout << endl;
    
    // Végtelen ciklus példa (megszakítással)
    int counter = 0;
    while (true) {
        cout << "Végtelen ciklus iteráció: " << counter << endl;
        counter++;
        if (counter >= 3) break;  // Kilépés a ciklusból
    }
    
    return 0;
}
```

## Elágazások

Az elágazások lehetővé teszik, hogy különböző utasításokat hajtsunk végre különböző feltételek alapján.

### if-else szerkezet

```cpp
int score = 85;

if (score >= 90) {
    cout << "Ötös" << endl;
} else if (score >= 80) {
    cout << "Négyes" << endl;
} else if (score >= 70) {
    cout << "Harmas" << endl;
} else if (score >= 60) {
    cout << "Kettes" << endl;
} else {
    cout << "Egyes" << endl;
}
```

### Ternáris operátor

A ternáris operátor (`?:`) egy rövidített if-else szerkezet.

```cpp
int age = 20;
string status = (age >= 18) ? "Felnőtt" : "Gyermek";
cout << status << endl;  // "Felnőtt"

// Több soros verzió:
if (age >= 18) {
    status = "Felnőtt";
} else {
    status = "Gyermek";
}
```

## Switch-case szerkezet

A `switch` utasítás több lehetőség közül választ egyet az érték alapján.

```cpp
#include <iostream>
using namespace std;

int main() {
    int day = 3;
    
    switch (day) {
        case 1:
            cout << "Hétfő" << endl;
            break;
        case 2:
            cout << "Kedd" << endl;
            break;
        case 3:
            cout << "Szerda" << endl;
            break;
        case 4:
            cout << "Csütörtök" << endl;
            break;
        case 5:
            cout << "Péntek" << endl;
            break;
        case 6:
        case 7:
            cout << "Hétvége" << endl;
            break;
        default:
            cout << "Érvénytelen nap" << endl;
            break;
    }
    
    return 0;
}
```

## Ugró utasítások

### break

A `break` utasítás kilép a legbelső switch, for, while vagy do-while ciklusból.

```cpp
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break;  // Kilép a ciklusból, ha i = 5
    }
    cout << i << " ";
}
// Kimenet: 0 1 2 3 4
```

### continue

A `continue` utasítás kihagyja a jelenlegi iteráció hátralevő részét, és folytatja a következő iterációval.

```cpp
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
        continue;  // Kihagyja a páros számokat
    }
    cout << i << " ";
}
// Kimenet: 1 3 5 7 9
```

### goto

A `goto` utasítás egy megadott címkéhez ugrik a programban. Általában kerülendő, mivel nehezíti a kód olvashatóságát.

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    
    start:  // Címke
    cout << i << " ";
    i++;
    
    if (i < 5) {
        goto start;  // Ugrás a 'start' címkéhez
    }
    
    cout << endl << "Ciklus vége" << endl;
    
    return 0;
}
```

## Példák és kódrészletek

### Teljes példaprogram az összes fogalomra

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "=== C++ Operátorok és Vezérlési Struktúrák ===" << endl;
    
    // Unáris operátorok
    int x = 5;
    cout << "Unáris operátorok:" << endl;
    cout << "x = " << x << ", ++x = " << ++x << ", x++ = " << x++ << ", x = " << x << endl;
    
    // Bináris operátorok
    int a = 10, b = 3;
    cout << "\nBináris operátorok:" << endl;
    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;
    cout << a << " / " << b << " = " << (a / b) << endl;
    cout << a << " % " << b << " = " << (a % b) << endl;
    
    // Bitenkénti operátorok
    cout << "\nBitenkénti operátorok:" << endl;
    cout << a << " & " << b << " = " << (a & b) << endl;
    cout << a << " | " << b << " = " << (a | b) << endl;
    cout << a << " ^ " << b << " = " << (a ^ b) << endl;
    cout << a << " << 1 = " << (a << 1) << endl;
    cout << a << " >> 1 = " << (a >> 1) << endl;
    
    // Logikai operátorok
    bool p = true, q = false;
    cout << "\nLogikai operátorok:" << endl;
    cout << p << " && " << q << " = " << (p && q) << endl;
    cout << p << " || " << q << " = " << (p || q) << endl;
    cout << "!" << p << " = " << (!p) << endl;
    
    // Értékadó operátorok
    cout << "\nÉrtékadó operátorok:" << endl;
    int c = 10;
    cout << "c = " << c << endl;
    c += 5; cout << "c += 5: " << c << endl;
    c -= 3; cout << "c -= 3: " << c << endl;
    c *= 2; cout << "c *= 2: " << c << endl;
    
    // Ciklusok
    cout << "\nCiklusok:" << endl;
    cout << "for ciklus: ";
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    cout << "while ciklus: ";
    int i = 0;
    while (i < 5) {
        cout << i << " ";
        i++;
    }
    cout << endl;
    
    cout << "do-while ciklus: ";
    int j = 0;
    do {
        cout << j << " ";
        j++;
    } while (j < 5);
    cout << endl;
    
    // Elágazások
    cout << "\nElágazások:" << endl;
    int score = 85;
    if (score >= 90) {
        cout << "Jegy: 5" << endl;
    } else if (score >= 80) {
        cout << "Jegy: 4" << endl;
    } else if (score >= 70) {
        cout << "Jegy: 3" << endl;
    } else if (score >= 60) {
        cout << "Jegy: 2" << endl;
    } else {
        cout << "Jegy: 1" << endl;
    }
    
    // Ternáris operátor
    string result = (score >= 60) ? "Sikeres" : "Sikertelen";
    cout << "Eredmény: " << result << endl;
    
    // Switch-case
    cout << "\nSwitch-case példa:" << endl;
    int month = 2;
    switch (month) {
        case 12:
        case 1:
        case 2:
            cout << "Tél" << endl;
            break;
        case 3:
        case 4:
        case 5:
            cout << "Tavasz" << endl;
            break;
        case 6:
        case 7:
        case 8:
            cout << "Nyár" << endl;
            break;
        case 9:
        case 10:
        case 11:
            cout << "Ősz" << endl;
            break;
        default:
            cout << "Érvénytelen hónap" << endl;
            break;
    }
    
    // Ugró utasítások
    cout << "\nUgró utasítások:" << endl;
    cout << "break példa (páratlan számok 0-10 között): ";
    for (int k = 0; k <= 10; k++) {
        if (k % 2 == 0) continue;  // Páros számokat kihagyja
        cout << k << " ";
    }
    cout << endl;
    
    cout << "goto példa (számláló 0-3-ig): ";
    int count = 0;
    loop_label:
    if (count < 4) {
        cout << count << " ";
        count++;
        goto loop_label;
    }
    cout << endl;
    
    return 0;
}
```

### Összetett példa: Számok osztályozása

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {15, 22, 7, 38, 41, 5, 92, 4, 67, 13};
    
    cout << "Számok osztályozása:" << endl;
    
    for (size_t i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        
        cout << num << ": ";
        
        // Páros/páratlan ellenőrzés bitekkel
        if ((num & 1) == 0) {
            cout << "páros, ";
        } else {
            cout << "páratlan, ";
        }
        
        // Prímszám ellenőrzés
        bool isPrime = true;
        if (num <= 1) {
            isPrime = false;
        } else {
            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        
        cout << (isPrime ? "prím, " : "nem prím, ");
        
        // Számjegyek száma
        int temp = num;
        int digitCount = 0;
        while (temp > 0) {
            temp /= 10;
            digitCount++;
        }
        cout << digitCount << " számjegyű";
        
        cout << endl;
    }
    
    return 0;
}
```