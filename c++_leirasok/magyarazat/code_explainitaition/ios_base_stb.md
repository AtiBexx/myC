Oké, adok mindegyikre **mini példát + rövid magyarázatot**, tisztán.

------

# 1) ios_base::app (hozzáfűzés fájl végéhez)

## Mire jó?

Fájl végére ír, nem törli a régi tartalmat.

## Példa:

```cpp
#include <fstream>

int main()
{
    std::ofstream f("adat.txt", std::ios_base::app);

    f << "uj sor\n";
}
```

 mindig a végére ír

------

# 2) ios_base::trunc (törlés megnyitáskor)

## Mire jó?

Megnyitáskor törli a fájlt.

## Példa:

```cpp
std::ofstream f("adat.txt", std::ios_base::trunc);
f << "csak ez marad\n";
```

 minden régi adat eltűnik

------

# 3) ios_base::in / ios_base::out

## Mire jó?

- in = olvasás
- out = írás

## Példa:

```cpp
std::fstream f("adat.txt", std::ios_base::in | std::ios_base::out);
```

 egyszerre olvasol és írsz

------

# 4) binary (bináris mód)

## Mire jó?

Nem szövegként, hanem nyers byte-okként kezeli a fájlt.

## Példa:

```cpp
std::ofstream f("adat.bin", std::ios_base::binary);

int x = 10;
f.write(reinterpret_cast<char*>(&x), sizeof(x));
```

 nem “10” karakter, hanem nyers memória

------

# 5) gcount()

## Mire jó?

Megmondja, hány byte-ot olvastál utoljára.

## Példa:

```cpp
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream f("adat.txt");

    char buffer[100];

    f.read(buffer, 100);

    std::cout << f.gcount() << std::endl;
}
```

 kiírja mennyit olvasott ténylegesen

------

# 6) fill()

## Mire jó?

Kimenet kitöltő karaktere (pl. 0 padding).

## Példa:

```cpp
#include <iostream>

int main()
{
    std::cout.fill('*');

    std::cout.width(10);
    std::cout << 42 << std::endl;
}
```

 eredmény: `********42`

------

# 7) ios_base::beg / cur / end (seek pozíciók)

## Mire jó?

Fájl pozíció mozgatása.

------

## beg (elejétől)

```cpp
f.seekg(5, std::ios_base::beg);
```

5. byte-ra ugrik a fájl elejétől

------

## cur (aktuális pozíciótól)

```cpp
f.seekg(3, std::ios_base::cur);
```

 3 byte-tal előrébb lép

------

## end (fájl végétől)

```cpp
f.seekg(-5, std::ios_base::end);
```

 5 byte-tal a vége előttre ugrik

------

#  ÖSSZEFOGLALÁS

| dolog       | mire jó               |
| ----------- | --------------------- |
| app         | hozzáfűzés            |
| trunc       | törlés                |
| in/out      | olvasás/írás          |
| binary      | nyers adat            |
| gcount      | mennyit olvasott      |
| fill        | kitöltés karakter     |
| beg/cur/end | fájl pozíció mozgatás |

------

