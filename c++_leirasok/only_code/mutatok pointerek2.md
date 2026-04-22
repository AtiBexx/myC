```
#include<cstdio>
#include<cstdlib>
#include<iostream>

int main(int argc, char* argv[]) {

    int x;
    int* ptr = &x;
    *ptr = 10;
    std:: cout << *ptr << std::endl;
    return 0;
}
```

**vagy**

```
#include<cstdio>
#include<cstdlib>
#include<iostream>

int main(int argc, char* argv[]) {

    //int x;
    //int* ptr = &x;
    int* ptr = new int;
    *ptr = 10;
    std:: cout << *ptr << std::endl;
    delete ptr; // töröljük a memóriából a pointert
    ptr = nullptr;// vagy ptr = 0;

    return 0;
}
```



------

## Mi a helyzet ma?

###  Raw pointerek

```cpp
int* ptr = new int;
*ptr = 10;
delete ptr;
```

- működik
- de **veszélyes**
- könnyű hibázni

------

###  Modern C++ megoldások

A `raw pointer` helyett **smart pointereket** használnak:

#### std::unique_ptr

```cpp
#include <memory>

std::unique_ptr<int> ptr = std::make_unique<int>(10);
std::cout << *ptr << std::endl;
// Nem kell delete, automatikusan felszabadul
```

#### std::shared_ptr

```cpp
#include <memory>

std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
std::shared_ptr<int> ptr2 = ptr1; // több tulajdonos
```

------

###  Stack pointerek

A klasszikus mutató, ami **stack változóra mutat**, még mindig nagyon gyakori:

```cpp
int x = 10;
int* ptr = &x;
*ptr = 20;
```

- **nem kell `delete`**
- **biztonságosabb**, mert a változó a stacken van

------

 Összefoglalva:

- **Raw `new/delete` pointert** a modern C++-ban **próbálják kerülni**
- **Smart pointer** a menő, automatikusan kezeli a memóriát
- **Stack pointer** még mindig gyakori, biztonságos és gyors

------

##  Stack pointerek (pl. `int* ptr = &x;`)

- Futásidőben **szinte azonnal elérhető**, mert a változó a **stacken van**, CPU regiszterekhez nagyon közel.
- Nem kell `new/delete`, nincs extra overhead.
- Nagyon gyors, szinte **semmi különbség nincs a sima változóhoz képest**.

------

##  Raw heap pointerek (`new/delete`)

```cpp
int* ptr = new int;
*ptr = 10;
delete ptr;
```

- Itt **memória a heap-en** foglalódik → futásidőben a rendszerhívás miatt **lassabb**, mint a stack.
- Ha sok `new/delete` van ciklusban → látványos overhead.
- Viszont **dinamikus méretű memória kezelésére kell**, stack túl kicsi lenne.

------

##  Smart pointerek (`unique_ptr`, `shared_ptr`)

- `unique_ptr` → szinte **ugyanolyan gyors**, mint a raw pointer (mert csak destruktorkor hív `delete`-et).
- `shared_ptr` → **lassabb**, mert futásidőben referenciát számol (atomic counter).
- De cserébe **biztonságos** → nincs memória szivárgás, nincs dangling pointer.

------

## Összefoglalva futásidőben

| Pointer típus    | Futásidőbeli gyorsaság | Megjegyzés                     |
| ---------------- | ---------------------- | ------------------------------ |
| Stack pointer    | ⚡ nagyon gyors         | Nem kell delete                |
| Raw heap pointer | 🐢 lassabb              | Heap overhead, delete kell     |
| `unique_ptr`     | ⚡ majdnem olyan gyors  | Automatikusan delete           |
| `shared_ptr`     | 🐌 lassabb              | Referenciaszámláló futásidőben |

------

##  DOS / régi rendszerek

Igen, régebben DOS-os programokban és régi C/C++ kódokban **ma is sok raw pointer van**, mert:

- Nem volt smart pointer
- Memória mindig limitált volt → minden bájt számított
- Stack vs. heap kezelés manuális volt

De **modern, nagy rendszerekben már inkább smart pointer + stack pointer kombinációt használnak**.