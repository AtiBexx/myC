##  Függvény-túlterhelés (Function Overloading) jelentése

**Függvény-túlterhelés** azt jelenti, hogy **ugyanazzal a névvel több függvényt hozunk létre**, de **különböző paraméterlistával**.

- A fordító a **paraméterek típusa és száma** alapján dönt, melyik függvényt hívja meg.
- A visszatérési típus **nem számít**, csak a paraméterlista!

------

###  Példa C++-ban

```cpp
#include <iostream>
using namespace std;

// int paraméterrel
int osszead(int a, int b) {
    return a + b;
}

// double paraméterrel
double osszead(double a, double b) {
    return a + b;
}

int main() {
    cout << osszead(2, 3) << endl;       // int verzió fut → 5
    cout << osszead(2.5, 3.7) << endl;   // double verzió fut → 6.2
}
```

- Ugyanaz a név: `osszead`
- Különböző paraméterek → **túlterhelt függvények**

------

###  Python

Pythonban **nincs hagyományos függvény-túlterhelés**, mert a **utolsó definíció felülírja a régit**.

- Viszont **default értékekkel vagy \*args, **kwargs**-szal** lehet hasonló hatást elérni:

```python
def osszead(a, b=0):
    return a + b

print(osszead(2,3))   # 5
print(osszead(2))     # 2 (b=0 alapértelmezett)
```

------

###  Java

Java-ban is működik:

```java
class Main {
    static int osszead(int a, int b) {
        return a + b;
    }

    static double osszead(double a, double b) {
        return a + b;
    }

    public static void main(String[] args) {
        System.out.println(osszead(2, 3));       // int verzió
        System.out.println(osszead(2.5, 3.7));   // double verzió
    }
}
```

------

### Összefoglalás

| Nyelv  | Lehetőség túlterhelésre? | Megjegyzés                                   |
| ------ | ------------------------ | -------------------------------------------- |
| C++    | igen                     | Típussal és paraméter számmal                |
| Java   | igen                     | Ugyanaz, mint C++                            |
| Python | nincs klasszikus         | Default paraméterekkel vagy *args-szal lehet |

------

#### valós egyszerű_példa_

```
#include <iostream>
using namespace std;

// Egész számok összeadása
int osszead(int a, int b) {
    return a + b;
}

// Lebegőpontos számok összeadása
double osszead(double a, double b) {
    return a + b;
}

// Több szám összeadása (variadic)
int osszead(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << osszead(2, 3) << endl;       // int -> 5
    cout << osszead(2.5, 3.7) << endl;   // double -> 6.2
    cout << osszead(1, 2, 3) << endl;    // 3 paraméter -> 6
}
```

## C – nincs túlterhelés, workaround

C-ben **nem lehet ugyanazt a függvénynevet többször használni**, ezért **más névvel vagy paraméterekre bontva** oldjuk meg:

```
#include <stdio.h>

// int paraméterek
int osszead_int(int a, int b) {
    return a + b;
}

// double paraméterek
double osszead_double(double a, double b) {
    return a + b;
}

int main() {
    printf("%d\n", osszead_int(2, 3));       // 5
    printf("%.2f\n", osszead_double(2.5, 3.7)); // 6.20
}
```

#### kotlin

```
fun osszead(a: Int, b: Int): Int = a + b
fun osszead(a: Double, b: Double): Double = a + b
fun osszead(a: Int, b: Int, c: Int): Int = a + b + c

fun main() {
    println(osszead(2, 3))       // 5
    println(osszead(2.5, 3.7))   // 6.2
    println(osszead(1, 2, 3))    // 6
}
```

