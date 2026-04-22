#  Mi az előfeldolgozó (preprocessor)?

A C++ programot **fordítás előtt** egy előfeldolgozó dolgozza fel.
Ez **nem a fordító**, hanem az a lépés, ami:

1. **#include** direktívákat behelyettesít
2. **#define** makrókat cserél le
3. Feltételes fordítást (#ifdef, #ifndef, #if) kezel
4. Egyéb **előfeldolgozói utasításokat** végrehajt

------

##  Hogyan működik lépésről lépésre

Tegyük fel van egy kis programod:

```cpp
#include <iostream>
#define PI 3.14

int main() {
    std::cout << "PI = " << PI << std::endl;
    return 0;
}
```

### Mit csinál az előfeldolgozó?

1. Beilleszti a `<iostream>` tartalmát (ezek a C++ standard könyvtár definíciói)
2. Lecseréli a **makrókat**, pl. `PI` → `3.14`
3. Eltávolítja a kommenteket (`// …` és `/* … */`)

Az előfeldolgozás után a fordító kapja:

```cpp
int main() {
    std::cout << "PI = " << 3.14 << std::endl;
    return 0;
}
```

------

#  Tipikus előfeldolgozó direktívák

| Direktíva                      | Mit csinál                                            |
| ------------------------------ | ----------------------------------------------------- |
| `#include <file>`              | Beilleszti a fájl tartalmát                           |
| `#include "file"`              | Beilleszti a fájl tartalmát (helyi könyvtárból)       |
| `#define X 10`                 | Makró definiálás – minden X előfordulást 10-re cserél |
| `#undef X`                     | Makró törlése                                         |
| `#if / #elif / #else / #endif` | Feltételes fordítás                                   |
| `#ifdef / #ifndef`             | Makró létezésének ellenőrzése                         |
| `#error`                       | Hibát dob az előfeldolgozás során                     |
| `#pragma`                      | Speciális fordítóra vonatkozó utasítás                |

------

#  Példa feltételes fordításra

```cpp
#include <iostream>

#define DEBUG

int main() {
#ifdef DEBUG
    std::cout << "Debug mód aktív" << std::endl;
#endif

    std::cout << "Program indul..." << std::endl;
    return 0;
}
```

- Ha `DEBUG` definiálva van → kiírja a "Debug mód aktív" üzenetet
- Ha nincs → az a rész **kihagyásra kerül**

------

#  Miért fontos az előfeldolgozó?

- Segít **platformfüggetlen kódot** írni
- Lehetővé teszi **makrók** és **feltételes fordítás** használatát
- A **header fájlok (#include)** kezelését biztosítja
- Előfeldolgozó nélkül a **C++ fordító nem tudná értelmezni** a `#include`-okat és a makrókat

------

> `#include` -  a megadott fájl tartalmát **beilleszti**
>
> `#define` - **konstans vagy makró** definiálásal
>
> `#if` -  a kódrészletet **feltételesen** illeszti be, ha a feltétel igaz.



