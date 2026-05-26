 nagyon röviden:

- `void fuggveny(void)` → **nem kap semmit, nem ad vissza semmit**
- `int fuggveny(void)` → **nem kap semmit, visszaad egy int-et**
- `int fuggveny(int l, double d)` → **kap int-et és double-t, visszaad int-et**
- `void fuggveny(int l, double d)` → **kap int-et és double-t, nem ad vissza semmit** 



## 1. **`void fuggveny(void)`**

```c
void fuggveny(void);
```

- `void` a **visszatérési típus** → **nem ad vissza semmit**
- `(void)` a **paraméterlista** → **nem vár semmilyen bemenetet**
- Tehát: **nem kapsz be semmit, és nem ad vissza semmit**.

Példa:

```c
#include <stdio.h>

void koszones(void) {
    printf("Szia!\n");
}

int main() {
    koszones(); // Kiírja: Szia!
    return 0;
}
```

------

## 2. **`int fuggveny(void)`**

```c
int fuggveny(void);
```

- `int` → **egész számot ad vissza**
- `(void)` → **nem vár semmilyen bemenetet**
- Tehát: **nem adsz neki semmit, de kapsz vissza egy int-et**

Példa:

```c
#include <stdio.h>

int negyzet(void) {
    return 4*4; // visszaadja 16-ot
}

int main() {
    int eredmeny = negyzet();
    printf("%d\n", eredmeny); // Kiírja: 16
    return 0;
}
```

------

## 3. **`int fuggveny(int l, double d)`**

```c
int fuggveny(int l, double d);
```

- `int` → visszatérési érték: **egész szám**
- `(int l, double d)` → **két bemenetet vár**: egy egész `l` és egy valós szám `d`
- Tehát: **adunk neki két számot, és visszaad egy int-et**

Példa:

```c
#include <stdio.h>

int osszead(int a, double b) {
    return a + (int)b; // konvertálja double-t int-re
}

int main() {
    int eredmeny = osszead(3, 4.7);
    printf("%d\n", eredmeny); // Kiírja: 7
    return 0;
}
```

------

## 4. **`void fuggveny(int l , double d)`**

```c
void fuggveny(int l, double d);
```

- `void` → **nem ad vissza semmit**
- `(int l, double d)` → **két bemenetet vár**
- Tehát: **adunk neki két számot, de nem kapunk vissza semmit**

Példa:

```c
#include <stdio.h>

void kiir(int a, double b) {
    printf("Számok: %d és %.2f\n", a, b);
}

int main() {
    kiir(5, 3.14); // Kiírja: Számok: 5 és 3.14
    return 0;
}
```

------

### Összefoglaló logika

| Függvény                         | Mit ad vissza? | Mit kap?    |
| -------------------------------- | -------------- | ----------- |
| `void fuggveny(void)`            | semmit         | semmit      |
| `int fuggveny(void)`             | int            | semmit      |
| `int fuggveny(int l, double d)`  | int            | int, double |
| `void fuggveny(int l, double d)` | semmit         | int, double |

------

