#### Mutatok és pointerek

```
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

void fv (int* mvaltozo);
void fv2 (int* mvaltozo);
void fvKilometer(const int* kmValtozo);
void stack(double* stackVar);
void fv4 (double* dvalt);
void fv (int* mvaltozo) {
     *mvaltozo = 5;
}
void fv2 (int* mvaltozo) {
    *mvaltozo += 10;
}
void fvKilometer(const int* kmValtozo) {
    std::cout << "Érték: " << *kmValtozo << std::endl;
}
void stack(double* stackVar) {
    *stackVar = 3.14;
}
void fv4 (double &dvalt) {
     dvalt = 6.28;
}

int main (int argc, char* argv[]) {
    int nvaltozo = 1;
    fv(&nvaltozo);
    std::cout << nvaltozo << std::endl;
    fv2(&nvaltozo);
    std::cout << nvaltozo << std::endl;
    nvaltozo -= 5;
    std::cout << nvaltozo << std::endl;

    int kilometerTotal = 100;
    fvKilometer(&kilometerTotal);
    std::cout << std::flush;

    //halommemória
    double* ptr = new double;
    stack(ptr);
    std::cout <<"A pointer edménye:"<< *ptr << std::endl;
    delete ptr; //törölkjuk a pointeredményt
    ptr = 0; //pointer nullázása
    //ez után soha nem szabad a törölt memóriát ujraolvasni
    //ptr = nullptr; //pointer nullázása
    // std::cout <<"A pointer edménye újra: "<< *ptr << std::endl;
    double n2valtozo = 1;
    fv4(n2valtozo);
    std::cout <<"n2valtozo eredménye: " << n2valtozo << std::endl;
    //klépünk 
    std::cout << "Kérlek nyomj egy ENTERT a befejezéshez!" << std::endl;
    //std:: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}
```



------

##  Java verzió**

```java
public class Main {

    // Függvények
    static void fv(IntWrapper n) {
        n.value = 5;
    }

    static void fv2(IntWrapper n) {
        n.value += 10;
    }

    static void fvKilometer(IntWrapper km) {
        System.out.println("Érték: " + km.value);
    }

    static void stack(DoubleWrapper d) {
        d.value = 3.14;
    }

    static void fv4(DoubleWrapper d) {
        d.value = 6.28;
    }

    public static void main(String[] args) throws java.io.IOException {

        IntWrapper nvaltozo = new IntWrapper(1);
        fv(nvaltozo);
        System.out.println(nvaltozo.value);
        fv2(nvaltozo);
        System.out.println(nvaltozo.value);
        nvaltozo.value -= 5;
        System.out.println(nvaltozo.value);

        IntWrapper kilometerTotal = new IntWrapper(100);
        fvKilometer(kilometerTotal);

        DoubleWrapper ptr = new DoubleWrapper(0);
        stack(ptr);
        System.out.println("A pointer edménye: " + ptr.value);
        ptr = null; // Java garbage collector kezeli a memóriát

        DoubleWrapper n2valtozo = new DoubleWrapper(1);
        fv4(n2valtozo);
        System.out.println("n2valtozo eredménye: " + n2valtozo.value);

        System.out.println("Kérlek nyomj egy ENTERT a befejezéshez!");
        System.in.read();
    }
}

// Wrapper osztályok primitívekhez, hogy referencia szerint menjen át
class IntWrapper {
    public int value;
    IntWrapper(int v) { value = v; }
}

class DoubleWrapper {
    public double value;
    DoubleWrapper(double v) { value = v; }
}
```

- Java-ban **primitív típusok érték szerint mennek át**, ezért wrapper osztályokat használunk.

------

## ** Kotlin verzió**

```kotlin
fun fv(n: IntWrapper) { n.value = 5 }
fun fv2(n: IntWrapper) { n.value += 10 }
fun fvKilometer(km: IntWrapper) { println("Érték: ${km.value}") }
fun stack(d: DoubleWrapper) { d.value = 3.14 }
fun fv4(d: DoubleWrapper) { d.value = 6.28 }

fun main() {
    val nvaltozo = IntWrapper(1)
    fv(nvaltozo)
    println(nvaltozo.value)
    fv2(nvaltozo)
    println(nvaltozo.value)
    nvaltozo.value -= 5
    println(nvaltozo.value)

    val kilometerTotal = IntWrapper(100)
    fvKilometer(kilometerTotal)

    val ptr = DoubleWrapper(0.0)
    stack(ptr)
    println("A pointer edménye: ${ptr.value}")
    // Kotlin garbage collector kezeli

    val n2valtozo = DoubleWrapper(1.0)
    fv4(n2valtozo)
    println("n2valtozo eredménye: ${n2valtozo.value}")

    println("Kérlek nyomj egy ENTERT a befejezéshez!")
    readLine()
}

class IntWrapper(var value: Int)
class DoubleWrapper(var value: Double)
```

- Kotlinban is **garbage collector van**, nincs szükség `delete`-re.
- `var value`-val tudjuk változtatni az objektum belső értékét.

------

## ** Python verzió**

Pythonban a primitívek **immutábilisak**, ezért itt szintén wrapper osztályt használunk:

```python
class IntWrapper:
    def __init__(self, value):
        self.value = value

class DoubleWrapper:
    def __init__(self, value):
        self.value = value

def fv(n): n.value = 5
def fv2(n): n.value += 10
def fvKilometer(km): print(f"Érték: {km.value}")
def stack(d): d.value = 3.14
def fv4(d): d.value = 6.28

def main():
    nvaltozo = IntWrapper(1)
    fv(nvaltozo)
    print(nvaltozo.value)
    fv2(nvaltozo)
    print(nvaltozo.value)
    nvaltozo.value -= 5
    print(nvaltozo.value)

    kilometerTotal = IntWrapper(100)
    fvKilometer(kilometerTotal)

    ptr = DoubleWrapper(0)
    stack(ptr)
    print(f"A pointer edménye: {ptr.value}")

    n2valtozo = DoubleWrapper(1)
    fv4(n2valtozo)
    print(f"n2valtozo eredménye: {n2valtozo.value}")

    input("Kérlek nyomj egy ENTERT a befejezéshez!")

if __name__ == "__main__":
    main()
```

- Pythonban **nem kell memória felszabadítás** (`delete`), a **garbage collector** mindenről gondoskodik.
- Objektum referenciákat adunk át, így a függvény tudja módosítani az értéket.

------

 **Összefoglalás minden nyelvre**:

- **C++** → pointer / referencia + `new/delete`
- **Java/Kotlin/Python** → objektum referenciák + garbage collector
- Primitíveket csak wrapperrel tudunk “referencia szerint” átadni

------

