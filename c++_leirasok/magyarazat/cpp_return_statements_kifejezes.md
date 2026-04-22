# C++ Return Utasítások Teljes Útmutató

## Tartalomjegyzék
1. [Void függvények és return](#void-függvények-és-return)
2. [Return értékkel](#return-értékkel)
3. [Korai return-ek](#korai-return-ek)
4. [Return kifejezésekkel](#return-kifejezésekkel)
5. [Rekurzív függvényekben a return](#rekurzív-függvényekben-a-return)
6. [Különböző visszatérési típusok](#különböző-visszatérési-típusok)
7. [Gyakorlati alkalmazások](#gyakorlati-alkalmazások)
8. [Példák és kódrészletek](#példák-és-kódrészletek)

## Void függvények és return

A `void` függvények nem térnek vissza semmilyen értékkel. A `return` utasítás ebben az esetben csak kilép a függvényből, nem ad vissza értéket.

```cpp
#include <iostream>
using namespace std;

void printMessage() {
    cout << "Ez egy üzenet a függvényből." << endl;
    return;  // Nem kötelező, de explicit kilépést jelez
}

void printConditional(bool condition) {
    if (condition) {
        cout << "Feltétel teljesült." << endl;
        return;  // Korai kilépés, ha a feltétel igaz
    }
    
    cout << "Feltétel nem teljesült." << endl;
    // Nincs return, a függvény itt is befejeződik
}

int main() {
    printMessage();
    printConditional(true);   // Csak az első üzenet jelenik meg
    printConditional(false);  // Csak a második üzenet jelenik meg
    
    return 0;
}
```

## Return értékkel

A nem `void` függvényeknek vissza kell térniük egy értékkel, amely megfelel a deklarált visszatérési típusnak.

```cpp
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;  // Visszatér az a+b értékkel
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Hiba: nullával való osztás!" << endl;
        return 0.0;  // Hiba esetén 0.0 értékkel tér vissza
    }
    return a / b;
}

bool isEven(int number) {
    return (number % 2 == 0);  // Logikai értékkel tér vissza
}

int main() {
    cout << "5 + 3 = " << add(5, 3) << endl;
    cout << "10 / 2 = " << divide(10, 2) << endl;
    cout << "4 páros? " << isEven(4) << endl;
    
    return 0;
}
```

## Korai return-ek

A korai return-ek lehetővé teszik a függvény korai kilépését bizonyos feltételek teljesülésekor, ami segíthet elkerülni a mélyebb beágyazást.

```cpp
#include <iostream>
#include <string>
using namespace std;

// Rossz példa - mély beágyazás
int processBad(string input) {
    if (!input.empty()) {
        if (input.length() > 5) {
            if (input[0] != 'A') {
                return input.length() * 2;
            } else {
                return -1;
            }
        } else {
            return 0;
        }
    } else {
        return -1;
    }
}

// Jó példa - korai return-ek
int processGood(string input) {
    if (input.empty()) {
        return -1;  // Korai kilépés üres input esetén
    }
    
    if (input.length() <= 5) {
        return 0;   // Korai kilépés rövid string esetén
    }
    
    if (input[0] == 'A') {
        return -1;  // Korai kilépés, ha 'A'-val kezdődik
    }
    
    return input.length() * 2;  // Fő logika
}

int main() {
    cout << "processGood(\"Hello\"): " << processGood("Hello") << endl;      // 0
    cout << "processGood(\"World\"): " << processGood("World") << endl;      // 10
    cout << "processGood(\"Apple\"): " << processGood("Apple") << endl;      // -1
    cout << "processGood(\"\"): " << processGood("") << endl;                // -1
    
    return 0;
}
```

## Return kifejezésekkel

A return utasítások visszatérési értéke lehet egyszerű érték, változó, vagy komplex kifejezés.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Egyszerű érték visszaadása
int getFixedValue() {
    return 42;
}

// Kifejezés kiértékelése és visszaadása
int calculateSquare(int x) {
    return x * x;
}

// Feltételes kifejezés visszaadása
int absoluteValue(int x) {
    return (x >= 0) ? x : -x;
}

// Függvényhívás eredményének visszaadása
int getMax(vector<int>& nums) {
    if (nums.empty()) return 0;
    return *max_element(nums.begin(), nums.end());
}

// Komplex kifejezés visszaadása
bool isInRange(int value, int min, int max) {
    return (value >= min && value <= max);
}

int main() {
    cout << "Fix érték: " << getFixedValue() << endl;
    cout << "5 négyzete: " << calculateSquare(5) << endl;
    cout << "Abszolút érték (-7): " << absoluteValue(-7) << endl;
    
    vector<int> numbers = {3, 7, 2, 9, 1};
    cout << "Maximum: " << getMax(numbers) << endl;
    cout << "5 benne van-e 1 és 10 között? " << isInRange(5, 1, 10) << endl;
    
    return 0;
}
```

## Rekurzív függvényekben a return

A rekurzív függvényekben a return utasítások fontos szerepet játszanak a rekurzió végrehajtásában.

```cpp
#include <iostream>
using namespace std;

// Faktoriális kiszámítása rekurzívan
int factorial(int n) {
    if (n <= 1) {
        return 1;  // Alapeset - rekurzió leállítása
    }
    return n * factorial(n - 1);  // Rekurzív hívás
}

// Fibonacci szám kiszámítása rekurzívan
int fibonacci(int n) {
    if (n <= 1) {
        return n;  // Alapesetek: fib(0)=0, fib(1)=1
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  // Rekurzív hívások
}

// Számok összege 1-től n-ig rekurzívan
int sumToN(int n) {
    if (n <= 0) {
        return 0;  // Alapeset
    }
    return n + sumToN(n - 1);  // Rekurzív hívás
}

int main() {
    cout << "5 faktoriális: " << factorial(5) << endl;
    cout << "fibonacci(6): " << fibonacci(6) << endl;
    cout << "1-től 5-ig az összeg: " << sumToN(5) << endl;
    
    return 0;
}
```

## Különböző visszatérési típusok

A C++ különböző típusokkal is visszatérhet: primitív típusok, objektumok, pointerek, referenciák stb.

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Primitív típusokkal való visszatérés
int getInt() { return 42; }
double getDouble() { return 3.14159; }
char getChar() { return 'X'; }
bool getBool() { return true; }

// String visszaadása
string getGreeting() {
    return "Hello, világ!";
}

// Vektor visszaadása
vector<int> getVector() {
    return {1, 2, 3, 4, 5};
}

// Pointer visszaadása (óvatosan használandó!)
int* getIntPtr() {
    static int value = 100;  // Statikus változó, nem kerül a stack-re
    return &value;
}

// Referencia visszaadása (óvatosan használandó!)
int& getReference(int& x) {
    return x;  // Visszaadja az x változó referenciáját
}

// Konstans referencia visszaadása
const string& getConstReference(const string& s) {
    return s;  // Visszaadja a string konstans referenciáját
}

int main() {
    cout << "Int: " << getInt() << endl;
    cout << "Double: " << getDouble() << endl;
    cout << "Char: " << getChar() << endl;
    cout << "Bool: " << getBool() << endl;
    cout << "String: " << getGreeting() << endl;
    
    vector<int> vec = getVector();
    cout << "Vektor: ";
    for (int n : vec) {
        cout << n << " ";
    }
    cout << endl;
    
    int* ptr = getIntPtr();
    cout << "Pointer értéke: " << *ptr << endl;
    
    int x = 42;
    int& ref = getReference(x);
    cout << "Referencia értéke: " << ref << endl;
    ref = 100;  // Módosítja az eredeti x értékét
    cout << "x új értéke: " << x << endl;
    
    string text = "Példa szöveg";
    const string& constRef = getConstReference(text);
    cout << "Konstans referencia: " << constRef << endl;
    
    return 0;
}
```

## Gyakorlati alkalmazások

A return utasítások különböző gyakorlati alkalmazásai:

```cpp
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Hibaellenőrzés és visszatérés
int divideSafe(int dividend, int divisor) {
    if (divisor == 0) {
        cout << "Hiba: nullával való osztás!" << endl;
        return -1;  // Hiba esetén speciális érték
    }
    return dividend / divisor;
}

// Függvény visszatérési értékének használata feltételekben
bool isValidAge(int age) {
    return (age >= 0 && age <= 150);
}

// Több érték visszaadása struct segítségével
struct Result {
    bool success;
    int value;
    string message;
};

Result processData(int input) {
    if (input < 0) {
        return {false, 0, "Negatív érték nem elfogadható"};
    }
    
    if (input > 100) {
        return {false, 0, "Túl nagy érték"};
    }
    
    return {true, input * 2, "Sikeres feldolgozás"};
}

// Lambda kifejezések visszatérési értéke
auto createMultiplier(int factor) {
    return [factor](int x) { return x * factor; };
}

int main() {
    // Hibaellenőrzés
    int result = divideSafe(10, 2);
    if (result != -1) {
        cout << "Osztás eredménye: " << result << endl;
    }
    
    // Feltételekben való használat
    if (isValidAge(25)) {
        cout << "Érvényes életkor: 25" << endl;
    }
    
    // Struktúra visszaadása
    Result res = processData(50);
    if (res.success) {
        cout << res.message << ", érték: " << res.value << endl;
    } else {
        cout << "Hiba: " << res.message << endl;
    }
    
    // Lambda visszatérési érték használata
    auto doubler = createMultiplier(2);
    cout << "5 kétszerese: " << doubler(5) << endl;
    
    return 0;
}
```

## Példák és kódrészletek

### Teljes példaprogram a return utasítások minden típusára

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// 1. Void függvények
void printHeader() {
    cout << "=== Return Utasítás Példák ===" << endl;
}

// 2. Érték visszaadása
int addNumbers(int a, int b) {
    return a + b;
}

// 3. Korai return
string evaluateScore(int score) {
    if (score < 0 || score > 100) {
        return "Érvénytelen pontszám";
    }
    if (score >= 90) {
        return "Kiváló";
    } else if (score >= 80) {
        return "Jó";
    } else if (score >= 70) {
        return "Közepes";
    } else if (score >= 60) {
        return "Elégséges";
    } else {
        return "Elégtelen";
    }
}

// 4. Kifejezés visszaadása
bool isPositive(int num) {
    return num > 0;
}

// 5. Objektum visszaadása
vector<int> createSequence(int start, int count) {
    vector<int> sequence;
    for (int i = 0; i < count; i++) {
        sequence.push_back(start + i);
    }
    return sequence;
}

// 6. Rekurzív függvény
int factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}

// 7. Pointer visszaadása (statikus változóra)
int* getStaticCounter() {
    static int counter = 0;
    counter++;
    return &counter;
}

// 8. Referencia visszaadása
int& incrementAndGet(int& value) {
    value++;
    return value;
}

int main() {
    printHeader();
    
    // Érték visszaadás
    cout << "5 + 3 = " << addNumbers(5, 3) << endl;
    
    // Korai return
    cout << "85 pont: " << evaluateScore(85) << endl;
    cout << "105 pont: " << evaluateScore(105) << endl;
    
    // Kifejezés visszaadása
    cout << "10 pozitív? " << isPositive(10) << endl;
    cout << "-5 pozitív? " << isPositive(-5) << endl;
    
    // Objektum visszaadása
    vector<int> seq = createSequence(1, 5);
    cout << "Sorozat: ";
    for (int n : seq) {
        cout << n << " ";
    }
    cout << endl;
    
    // Rekurzív függvény
    cout << "5 faktoriális: " << factorialRecursive(5) << endl;
    
    // Statikus változó pointerének visszaadása
    int* counter1 = getStaticCounter();
    int* counter2 = getStaticCounter();
    cout << "Counter1: " << *counter1 << endl;
    cout << "Counter2: " << *counter2 << endl;
    
    // Referencia visszaadása
    int value = 10;
    int& ref = incrementAndGet(value);
    cout << "Érték: " << value << ", Referencia: " << ref << endl;
    
    return 0;
}
```

### Haladó példák - auto és decltype használata

```cpp
#include <iostream>
#include <type_traits>
using namespace std;

// auto visszatérési típus (C++14)
auto multiply(int a, double b) {
    return a * b;  // A visszatérési típust a fordító kikövetkezteti
}

// decltype(auto) visszatérési típus
template<typename T, typename U>
decltype(auto) getReferenceOrValue(T& t, U u, bool returnRef) {
    if (returnRef) {
        return t;  // int& típussal tér vissza
    } else {
        return u;  // U típussal tér vissza
    }
}

// Trailing return type (C++11)
template<typename T, typename U>
auto divideTemplate(T t, U u) -> decltype(t / u) {
    return t / u;
}

int main() {
    auto result1 = multiply(5, 2.5);
    cout << "multiply(5, 2.5) = " << result1 << endl;
    
    int x = 42;
    auto result2 = getReferenceOrValue(x, 3.14, true);
    result2 = 100;  // Módosítja az x értékét
    cout << "x értéke: " << x << endl;
    
    auto result3 = divideTemplate(10, 3);
    cout << "divideTemplate(10, 3) = " << result3 << endl;
    
    return 0;
}
```