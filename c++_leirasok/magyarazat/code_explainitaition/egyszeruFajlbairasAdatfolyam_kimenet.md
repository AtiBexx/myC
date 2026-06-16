#### egyszeruFajlbairasAdatfolyam_kimenet

----------

```cpp
//AdatfolyamKimenet
//egyszerű írás egy fájlba
//
#include <fstream>

int main(int agrc, char** argv)
{
    std::ofstream nevem("nevem.txt");
    nevem << "Atti_c" <<'\n'
    << "test" << std::endl;


    return 0;
}
/*
#include <fstream>

int main(int argc, char** argv)
{
    std::ofstream nevem("nevem.txt");

    nevem << "Atti_c" << '\n';
    nevem << "test" << std::endl;

    return 0;
}
*/

```

Igen, és ez teljesen normális.

------

#  Miért működik `<iostream>` nélkül is?

A te kódod:

```cpp
#include <fstream>
```

és mégis használod:

```cpp
std::endl
```

 mert az `<fstream>` **magában húzza az `<ostream>`-et**

------

#  Lánc logika (nagyon fontos)

```text
fstream
   ↓
iostream (közvetetten)
   ↓
ostream
   ↓
std::endl
```

------

#  Ezért működik:

- `std::ofstream` az `<fstream>`-ben van
- `<fstream>` már tartalmazza az alap stream rendszert
- ezért `std::endl` elérhető

------

#  FONTOS különbség

## Ez is működik:

```cpp
#include <fstream>
```

## Ez is működik:

```cpp
#include <iostream>
```

## Ez NEM jó hosszú távon:

csak `fstream` + `cout` keverés nélkül gondolkodás

------

#  Amit érdemes tudni

- fordító **nem mindig ugyanúgy optimalizálja a include láncot**
- de standard szerint `<fstream>`-ben benne van az `ostream` funkciók többsége

------

#  Egyszerű szabály

 ha fájlba írsz → elég `fstream`
 ha képernyőre is → kell `iostream`
 de `endl` mindig működni fog, ha van stream rendszered

------



------

