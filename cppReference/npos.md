# std::string::npos mi az?

```
std::string::npos
```

## Jelentése:

> “nem található pozíció”

------

### Példa:

```
std::string s = "hello";
size_t pos = s.find("x");
```

Ha nincs benne:

```
pos == std::string::npos
```

------

## Miért kell?

Mert `find()` egy számot ad vissza:

- ha megtalálja → index (0,1,2,...)
- ha nem → kell egy speciális érték

ezt jelöli: `npos`

------

## Mi az a npos?

Valójában:

```
(size_t)-1
```

azaz a legnagyobb lehetséges szám

```
#include <iostream>
#include <string>

int main()
{
    std::string s = "hello";
    size_t pos = s.find("x");

    if (pos == std::string::npos)
    {
        std::cout << "The letter is not found";
    }
}
```

- `s` egy string
- `npos` egy konstans
- köztük nincs operátor

A helyes logika mindig a `find()` eredményével dolgozik.

```
if (s.find("x") == std::string::npos)
{
    std::cout << "Not found";
}
```

# `find()` és `(size_t)-1`

Nem azt jelenti, hogy “-1-et ad vissza”, hanem ezt:

```
(size_t)-1
```

 ez valójában a **legnagyobb lehetséges unsigned szám**

Mert:

- `size_t` = unsigned (nem lehet negatív)
- ezért a `-1` “átfordul” nagyon nagy számra

Tehát nem:

```
-1
```

hanem pl:

```
18446744073709551615 (64-bit rendszeren)
```

 és ezt nevezzük: `std::string::npos`