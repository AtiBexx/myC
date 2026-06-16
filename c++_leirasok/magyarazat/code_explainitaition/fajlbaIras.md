#  Mini fájlíró program

```cpp
#include <iostream>
#include <fstream>

int main()
{
    std::ofstream fajl("adat.txt");

    if (!fajl.is_open())
    {
        std::cout << "Nem sikerult megnyitni a fajlt" << std::endl;
        return 1;
    }

    std::cout << "Fajl megnyitva, iras indul..." << std::endl;

    fajl << "Ez egy teszt sor" << std::endl;
    fajl << "Masodik sor" << std::endl;
    fajl << "Harmadik sor" << std::endl;

    std::cout << "Kesz, kiirtam a fajlba" << std::endl;

    fajl.close();

    return 0;
}
```

------

#  Fontos dolgok

## 1) Nem muszáj `.txt`

Írhatsz ilyet is:

```cpp
std::ofstream fajl("adat");
```

vagy:

```cpp
std::ofstream fajl("valami.dat");
```

 a kiterjesztés csak név, nem kötelező

------

## 2) Mit csinál ez?

- `std::ofstream` → fájl írás
- `fajl <<` → fájlba írás (mint cout)
- `std::cout` → képernyőre írás

------

## 3) Mi történik futás után?

Ha futtatod:

- képernyőn látod:

```
Fajl megnyitva, iras indul...
Kesz, kiirtam a fajlba
```

- fájlban lesz:

```
Ez egy teszt sor
Masodik sor
Harmadik sor
```

------

#  Egymondatos lényeg

 a `cout` a monitor, az `ofstream` pedig ugyanaz, csak fájlba ír

------

Ha akarod, a következő lépés lehet:
 hogyan kérsz be felhasználótól szöveget és azt írod fájlba (valódi program logika).