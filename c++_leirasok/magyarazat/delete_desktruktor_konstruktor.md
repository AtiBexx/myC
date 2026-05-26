A **destruktor nem egy függvényhez kell**, hanem **egy osztályhoz (classhoz)**. A `delete` pedig **nem kötelezően a `main`-ben van** — ott hívod, ahol már nincs szükség az objektumra.

Példa:

```cpp
class Tomb
{
    int* adat;

public:
    Tomb()
    {
        adat = new int[100];
    }

    ~Tomb()
    {
        delete[] adat;
        std::cout << "Felszabadítva\n";
    }
};
```

Most:

```cpp
int main()
{
    Tomb* t = new Tomb();

    delete t;
}
```

Mi történik a `delete t;` során?

1. Lefut:

```cpp
t->~Tomb();
```

1. Felszabadul a heap memória.

Tehát:

```text
delete
 ├─ destruktor meghívása
 └─ memória felszabadítása
```

A destruktor **a class része**, a `delete` **a használat helyén van**.

------

Stackes objektumnál még `delete` sem kell:

```cpp
int main()
{
    Tomb t;
}
```

Kilépéskor a destruktor **automatikusan** lefut:

```text
main vége
↓
~Tomb()
```

Nem kell:

```cpp
delete t;
```

sőt ez hibás lenne.

------

Összefoglalva:

- `~Tomb()` → osztályban definiálod
- `delete p` → ott írod, ahol vége a használatnak
- stack objektumnál nincs `delete`
- heap (`new`) → általában kell `delete`
- `delete` automatikusan meghívja a destruktort

Ezért szokták mondani:

> ```
> new` ↔ `delete
> ```
>
> konstruktor ↔ destruktor

párokban gondolkodj.

----------------------------------------

C_ben

Igen, most már nagyon közel vagy. Egy pontosítás:

A konstruktor:

```cpp
Tomb()
```

a destruktor:

```cpp
~Tomb()
```

és **igen**, ide tetted a:

```cpp
delete[] adat;
```

mert a `Tomb` objektum **birtokolja** azt a memóriát, amit `new`-val lefoglalt.

Ez a C++-os gondolkodás: *aki lefoglalta és birtokolja, az takarítja el.*

------

C-ben nincs:

- konstruktor
- destruktor
- `new`
- `delete`
- osztály

Ezért kézzel kell megoldani.

Kb. így nézne ki:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* adat;
} Tomb;
```

"Konstruktor" helyett csinálsz egy függvényt:

```c
void Tomb_init(Tomb* t)
{
    t->adat = malloc(100 * sizeof(int));
}
```

"Destruktor" helyett:

```c
void Tomb_destroy(Tomb* t)
{
    free(t->adat);

    printf("Felszabadítva\n");
}
```

Használat:

```c
int main()
{
    Tomb t;

    Tomb_init(&t);

    // használat

    Tomb_destroy(&t);

    return 0;
}
```

C-ben neked kell fejben tartani:

```text
malloc → free
init → destroy
```

Míg C++:

```text
new → delete
konstruktor → destruktor
```

A C++ ezért kényelmesebb:

```cpp
{
    Tomb t;
}
```

kilépéskor automatikusan:

```cpp
~Tomb()
```

C-ben ha elfelejted:

```c
Tomb_destroy(&t);
```

akkor memóriaszivárgás lesz.

Ezért a C++ egyik nagy előnye pont az automatikus erőforrás-kezelés.