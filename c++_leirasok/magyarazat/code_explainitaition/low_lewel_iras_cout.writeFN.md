```cpp
#include <iostream>
int main()
{
    // HELYES - függvényhívás:
    std::cout.write("Hello World", 11);  // 11 = "Hello World" hossza
    return 0;
}
```

------

#  A példád

```cpp
std::cout.write("Hello World", 11);
```

## Mit csinál?

 ez **nem formázott kiírás**, hanem nyers írás

- `"Hello World"` = char tömb
- `11` = hány byte-ot írjon ki

------

#  Mi a különbség `<<` és `write` között?

##  1. `<<` (stream operator)

```cpp
std::cout << "Hello World";
```

 formázott kimenet

- kezeli a formázást
- boolalpha, hex, width stb.

------

##  2. `write` (nyers adat)

```cpp
std::cout.write("Hello World", 11);
```

 byte pontos kiírás

- nem formáz
- nem állít semmit
- gyorsabb / low-level

------

#  Fontos különbség

| tulajdonság     | <<          | write    |
| --------------- | ----------- | -------- |
| formázás        | igen        | nem      |
| gyors           | normál      | gyorsabb |
| string kezelés  | igen        | nem      |
| null terminátor | automatikus | NEM      |

------

#  kritikus dolog

```cpp
std::cout.write("Hello", 11);
```

 ez **undefined behavior lehet**, mert:

- `"Hello"` csak 6 byte (5 betű + `\0`)
- te 11-et kérsz

------

#  helyesebb verzió

```cpp
std::string s = "Hello World";
std::cout.write(s.c_str(), s.size());
```

------

#  Amit a GCC / Clang header-ekben látsz

Amikor nézed:

- `<iostream>`
- `<ostream>`
- `<bits/...>`

 ezekben valójában:

- template-ek
- overloadok
- buffer kezelés
- low-level write/read

------

#  Amit most tanulsz (fontos)

Te már nem csak C++-t látsz, hanem:

 **stream buffer rendszert (std::streambuf)**

Ez az egész mögötte:

```
cout -> ostream -> streambuf -> OS write()
```

------

#  Extra (érdekesség)

A `write()` gyakran ezt hívja:

```cpp
sputn()
```

ami a buffer szintű „nyers írás”.

------

### A `<<` operátor mit csinál belül:

cpp

```cpp
std::cout << "Hello World";
```

Ez valójában:

cpp

```cpp
// 1. Megnézi milyen típus (string? int? float?)
// 2. Formázási beállításokat ellenőriz (width, fill, flags)
// 3. Locale-t ellenőriz (milyen ország formátuma?)
// 4. AZTÁN hívja a write()-ot
```

------

### A `write()` mit csinál:

cpp

```cpp
std::cout.write("Hello World", 11);
// 1. Egyből a pufferbe írja
// ← kész, semmi más!
```

------

### Vizuálisan:

```
<< operátor:
[adat] → típusellenőrzés → formázás → locale → puffer → képernyő

write():
[adat] → puffer → képernyő
```

------

### De a valóságban:

Stringeknél a különbség **elhanyagolható** – mindkettő nagyon gyors. A `write()` igazán akkor számít:

cpp

```cpp
// Nagy bináris adat kiírása:
char kepAdat[1920 * 1080 * 3];  // egy HD kép
std::cout.write(kepAdat, sizeof(kepAdat));  // egy hívás, azonnal!

// << -el nem is tudnád így kiírni bináris adatot!
```

------

### Röviden:

|               | `<<`       | `write()`       |
| ------------- | ---------- | --------------- |
| Kényelmes?    | -          | kell a méret    |
| Gyors?        | elég gyors | kicsit gyorsabb |
| Bináris adat? |            | -               |
| Formázás?     | -          |                 |

Szóval nem azt jelenti hogy "alacsonyabb szintű = mindig ezt használd" – azt jelenti hogy **kevesebbet csinál**, és ezért kicsit gyorsabb, de cserébe te csinálsz meg mindent kézzel!