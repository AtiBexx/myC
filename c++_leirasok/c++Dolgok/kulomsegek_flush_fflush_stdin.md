A különbség főleg az, hogy **C++ stream** vagy **C FILE*** rendszert használsz, és hogy **kimenetet** vagy **bemenetet** akarsz flusholni.

# 1. `std::flush`

Ez **C++ stream manipulátor**.

Példa:

```cpp
#include <iostream>

int main() {
    std::cout << "Betöltés..." << std::flush;

    // hosszú művelet

    return 0;
}
```

Mit csinál?

* Kiüríti a `std::cout` buffert.
* Azonnal kiírja a képernyőre a még bufferben lévő adatot.
* Nem tesz új sort.

Ez ugyanaz mint:

```cpp
std::cout.flush();
```

---

## Mikor hasznos?

Pl loading szöveg:

```cpp
std::cout << "Várj..." << std::flush;
Sleep(3000);
```

különben lehet hogy csak 3 mp múlva jelenik meg.

---

# 2. `std::fflush()`

Ez már **C nyelvi függvény** a `<cstdio>`-ből.

`FILE*` streamet flushol.

Példa:

```cpp
#include <cstdio>

int main() {
    printf("Hello");
    fflush(stdout);

    return 0;
}
```

Mit flushol?

* `stdout`
* fájl
* más `FILE*`

---

## Különbség röviden

| C++          | C                |
| ------------ | ---------------- |
| `std::cout`  | `printf`         |
| `std::flush` | `fflush(stdout)` |

---

# 3. `fflush(stdin)`

Na ez a problémás rész.

```cpp
fflush(stdin);
```

## Ez NEM standard C/C++

A szabvány szerint:

* `fflush()` csak output streamre garantált.
* `stdin` input stream.

Tehát:

```cpp
fflush(stdin);
```

➡️ **undefined behavior**.

---

# Miért használják mégis sokan?

Régi Windows/MSVC környezetben működött arra, hogy:

* törölje a billentyűbuffer maradékát.

Pl:

```cpp
scanf("%d", &x);
fflush(stdin);
```

De:

* GCC alatt lehet nem működik
* Linuxon hibás
* nem hordozható

---

# Modern C++ megoldás input törlésre

Használj:

```cpp
#include <limits>

std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
```

Példa:

```cpp
int x;

std::cin >> x;

std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
```

Ez:

* kidobja a maradék entert és karaktereket
* szabványos
* működik mindenhol

---

# Rövid összefoglaló

| Dolog            | Mire való                | Jó?            |
| ---------------- | ------------------------ | -------------- |
| `std::flush`     | C++ output buffer ürítés | ✅              |
| `fflush(stdout)` | C output buffer ürítés   | ✅              |
| `fflush(stdin)`  | input buffer "törlés"    | ❌ nem standard |

---

# Extra fontos

`std::endl` is flushol:

```cpp
std::cout << "Hello" << std::endl;
```

Ez:

1. új sort ír
2. flushol is

Míg:

```cpp
std::cout << '\n';
```

csak új sort ír, flush nélkül.

Ezért a `'\n'` gyorsabb nagy ciklusokban.
