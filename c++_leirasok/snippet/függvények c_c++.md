##  C és C++: visszatérési típus

```
<visszateresi típus> függvényNeve(a függvény argumentumai)
void magyarazatMegjelenitese(void)
double osszeAdd(double d)
int kivon(int n) vagy(int a, int b)
```

------

##  Általános szintaxis

```
<visszatérési típus> függvényNeve(<paraméterek listája>)
```

- `<visszatérési típus>`: `void`, `int`, `double`, stb.
- `<paraméterek listája>`: a függvény bemeneti változói (pl. `int a`, `double d`)
- `void` → **nem ad vissza értéket**
- `int`, `double` → **visszatérési érték típusa**

------

##  Példák

###  `void` – nincs visszatérési érték

```c
void magyarazatMegjelenitese(void) {
    printf("Ez a függvény csak kiír valamit, de nem ad vissza értéket.\n");
}
```

- `void` → nincs return érték
- `void` paraméterlistában → **nincsenek bemeneti paraméterek** (C/C++ stílus)

------

###  `double` – lebegőpontos szám visszaadása

```c
double osszeAdd(double d) {
    return d + 10.0; // pl. hozzáad 10-et és visszaadja
}
```

- `double` → visszatérési érték típusa
- `double d` → bemeneti paraméter
- `return` → a függvény értéket ad vissza

------

###  `int` – egész szám visszaadása

```c
int kivon(int n) {
    return n - 5; // kivon 5-öt és visszaadja
}

// több paraméterrel
int osszeadKetSzamot(int a, int b) {
    return a + b;
}
```

- `int` → egész szám visszatérési típus
- `int n` vagy `int a, int b` → bemenet
- `return` → a függvény értéket ad vissza

------

###  Összefoglaló

| Függvény                             | Paraméter | Visszatérés | Megjegyzés                |
| ------------------------------------ | --------- | ----------- | ------------------------- |
| `void magyarazatMegjelenitese(void)` | nincs     | semmi       | csak végrehajt valamit    |
| `double osszeAdd(double d)`          | 1 double  | double      | visszaadja a szám + 10-et |
| `int kivon(int n)`                   | 1 int     | int         | visszaadja n-5-öt         |
| `int osszeadKetSzamot(int a, int b)` | 2 int     | int         | visszaadja a+b összeget   |

------

##  Kotlin

```kotlin
fun magyarazatMegjelenitese(): Unit {  // Unit = void
    println("Ez a függvény csak kiír valamit, de nem ad vissza értéket.")
}

fun osszeAdd(d: Double): Double {
    return d + 10.0
}

fun kivon(n: Int): Int {
    return n - 5
}

fun osszeadKetSzamot(a: Int, b: Int): Int {
    return a + b
}

fun main() {
    magyarazatMegjelenitese()           // Unit, semmit nem ad vissza
    println(osszeAdd(3.5))               // 13.5
    println(kivon(10))                    // 5
    println(osszeadKetSzamot(2, 3))      // 5
}
```

- `Unit` = nincs visszatérési érték (`void` C/C++/Java)
- `Int`, `Double` = visszatérési típus
- Paraméterek típussal vannak megadva (`a: Int`)

------

##  Java

```java
public class Main {

    static void magyarazatMegjelenitese() { // void = semmit nem ad vissza
        System.out.println("Ez a függvény csak kiír valamit.");
    }

    static double osszeAdd(double d) {
        return d + 10.0;
    }

    static int kivon(int n) {
        return n - 5;
    }

    static int osszeadKetSzamot(int a, int b) {
        return a + b;
    }

    public static void main(String[] args) {
        magyarazatMegjelenitese();
        System.out.println(osszeAdd(3.5));       // 13.5
        System.out.println(kivon(10));           // 5
        System.out.println(osszeadKetSzamot(2, 3)); // 5
    }
}
```

- `void` → semmit nem ad vissza
- `int` és `double` → visszatérési típusok

------

##  Python

```python
def magyarazatMegjelenitese():   # nincs visszatérés, implicit None
    print("Ez a függvény csak kiír valamit, de nem ad vissza értéket.")

def osszeAdd(d):
    return d + 10.0

def kivon(n):
    return n - 5

def osszeadKetSzamot(a, b):
    return a + b

# használat
magyarazatMegjelenitese()   # None
print(osszeAdd(3.5))         # 13.5
print(kivon(10))              # 5
print(osszeadKetSzamot(2, 3)) # 5
```

- Pythonban **nem kell típus** a paraméterhez vagy visszatéréshez
- `None` = semmi visszatérés (void)

------

```
#include <stdio.h>

void magyarazatMegjelenitese(void) {
    printf("Ez a függvény csak kiír valamit, de nem ad vissza értéket.\n");
}

double osszeAdd(double d) {
    return d + 10.0;
}

int kivon(int n) {
    return n - 5;
}

int osszeadKetSzamot(int a, int b) {
    return a + b;
}

int main() {
    magyarazatMegjelenitese();       // void
    printf("double: %.2f\n", osszeAdd(3.5)); // 13.5
    printf("int: %d\n", kivon(10));         // 5
    printf("int: %d\n", osszeadKetSzamot(2,3)); // 5
    return 0;
}
```

###  Összehasonlító táblázat

| Nyelv  | void/Unit/None  | int/Int     | double/Double | Megjegyzés                                         |
| ------ | --------------- | ----------- | ------------- | -------------------------------------------------- |
| C      | void            | int         | double        | kötelező típusok                                   |
| C++    | void            | int         | double        | ugyanaz, mint C                                    |
| Kotlin | Unit            | Int         | Double        | Unit = void                                        |
| Java   | void            | int         | double        | statikus függvények                                |
| Python | None (implicit) | nincs típus | nincs típus   | dinamikus típus, nincs kötelező visszatérési típus |

#### JavaScript

```
// void: nem ad vissza értéket
function magyarazatMegjelenitese() {
    console.log("Ez a függvény csak kiír valamit, de nem ad vissza értéket.");
}

// double / lebegőpontos szám visszaadása
function osszeAdd(d) {
    return d + 10.0;
}

// int / egész szám visszaadása
function kivon(n) {
    return n - 5;
}

// több paraméter
function osszeadKetSzamot(a, b) {
    return a + b;
}

// használat
magyarazatMegjelenitese();         // void, semmi visszatér
console.log(osszeAdd(3.5));         // 13.5
console.log(kivon(10));             // 5
console.log(osszeadKetSzamot(2,3)); // 5
```

### Alap típusok

- `void` → **nem ad vissza értéket**
- `int` → egész szám
- `double` → lebegőpontos szám

###  Példák

```c
#include <stdio.h>

// void: nem ad vissza értéket
void koszones() {
    printf("Szia!\n");
}

// int: egész számot ad vissza
int osszead(int a, int b) {
    return a + b;
}

// double: lebegőpontos számot ad vissza
double felez(double x) {
    return x / 2.0;
}

int main() {
    koszones(); // void, csak lefut
    int e = osszead(3, 4); // 7
    double d = felez(5.0); // 2.5

    printf("int: %d, double: %.2f\n", e, d);
    return 0;
}
```

 Megjegyzés:

- C-ben és C++-ban **a `void` ugyanúgy működik**
- `int` és `double` értéket ad vissza → kell `return`

------

##  Kotlin

- Kotlinban **minden függvénynek van visszatérési típusa**
- Ha nem ad vissza értéket → `Unit` (ez C++/C `void` megfelelője)

```kotlin
fun koszones(): Unit {
    println("Szia!")
}

fun osszead(a: Int, b: Int): Int {
    return a + b
}

fun felez(x: Double): Double {
    return x / 2.0
}

fun main() {
    koszones()                 // Unit, semmit nem ad vissza
    val e = osszead(3, 4)      // 7
    val d = felez(5.0)         // 2.5
    println("int: $e, double: $d")
}
```

------

##  Java

- Java-ban `void` → nem ad vissza értéket
- `int`, `double` ugyanúgy, mint C/C++

```java
public class Main {
    static void koszones() {
        System.out.println("Szia!");
    }

    static int osszead(int a, int b) {
        return a + b;
    }

    static double felez(double x) {
        return x / 2.0;
    }

    public static void main(String[] args) {
        koszones(); // void
        int e = osszead(3, 4); // 7
        double d = felez(5.0); // 2.5
        System.out.println("int: " + e + ", double: " + d);
    }
}
```

------

##  Python

- Pythonban **nem kell típus**, de a logika ugyanaz:
- `None` → `void` megfelelője

```python
def koszones():
    print("Szia!")

def osszead(a, b):
    return a + b

def felez(x):
    return x / 2.0

koszones()         # semmit nem ad vissza
e = osszead(3, 4)  # 7
d = felez(5.0)     # 2.5
print(f"int: {e}, double: {d}")
```

------

###  Összefoglalás

| Nyelv  | “void” | int         | double              |
| ------ | ------ | ----------- | ------------------- |
| C      | void   | int         | double              |
| C++    | void   | int         | double              |
| Kotlin | Unit   | Int         | Double              |
| Java   | void   | int         | double              |
| Python | None   | nincs típus | nincs típus (float) |

- **C és C++**: a típusokat **mindig meg kell adni** (`void`, `int`, `double`)
- **Pythonban**: nincs kötelező típus, visszatérési érték lehet bármilyen

------

