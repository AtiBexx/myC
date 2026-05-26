```
// ObjektumHivÁtadás azaz egy objektum tartalmának módosítása
// egy függvényben, egy hivatkozás használatával....
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    int feleviOraSzam = 0;
    double tanulmanyiAtlag = 0.0;
};

//Hivatkozas
void egyFv(Hallgato& hivH)
{
    hivH.feleviOraSzam = 10;
    hivH.tanulmanyiAtlag = 3,0;

}

int main(int argc, char** argv)
{
    Hallgato h;
    h.tanulmanyiAtlag = 0.0;

    std::cout <<"A h.tanulmanyiAtlag értéke: " << h.tanulmanyiAtlag <<"\n";
    //átadjuk a meglévő objektum címét
    std::cout <<"Az egyFv(Hallgato*) meghívása" <<'\n';
    egyFv(h);
    std::cout <<"Visszatérés az egyFv(Hallgato*)  függvényből" <<"\n";
    // a h.tanulmanyiAtlag értéke most 3.0
    std::cout << "A h.tanulmanyiAtlag értéke = " << h.tanulmanyiAtlag << std::endl;

    //kilépünk
     std::cout << "A folytatáshoz kérlek nyomd meg az Entert..." << std::endl;
     std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
     std::cin.get();
     return 0;
}

```



---------------------

```
//Az Objektum Értékének az átadása
//
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

class Hallgato
{
public:
    int feleviOraSzam;
    double tanulmanyiAtlag;
};

void egyFv(Hallgato masolatH)
{
    masolatH.feleviOraSzam = 10;
    masolatH.tanulmanyiAtlag = 3.0;

    cout << "A masolatH. tanulmanyiAtlag értéke = "<< masolatH.tanulmanyiAtlag<<"\n";
}

int main(int argc, char** argv)
{
    //Létrehozuk a hallgato objektumot
    Hallgato h;
    //Megváltoztatjuk a tanulmanyi átlag értékét
    h.tanulmanyiAtlag =0.0;
    //Ki írjuk a tanulmanyi átlag értékét mielött meghívjuk az egíFv()
    cout << "A h.tanulmanyiAtlag értéke: " << h.tanulmanyiAtlag << "\n";
    //átadjuk a meglévő objektum címét
    cout <<"Az egyFv(Hallgato) meghívása" <<"\n";
    egyFv(h);
    cout << "Visszatérés az egyFv(Hallgato) függvényből" << endl;
    // A h.tanulmanyiAtlag értéke 0 marad
    cout << "A h.tanulmanyiAtlag értéke = " << h.tanulmanyiAtlag << endl;

    //kilépünk
    cout << "A folytatáshoz nyomd meg az Entert..." << endl;
    cin.ignore((numeric_limits<streamsize>::max)(),'\n');
    cin.get();
    return 0;
}
```

Ez az egyik legfontosabb C++ kérdés. A pointer és a hivatkozás hasonlítanak, mert mindkettővel „egy másik objektumot érünk el”, de nem ugyanaz.

## Hivatkozás (`&`)

A hivatkozás egy **másik név ugyanarra a változóra**.

```cpp
int a = 5;
int& ref = a;

ref = 10;

std::cout << a;
```

Kimenet:

```text
10
```

Mi történt?

- `ref` nem új változó
- `ref` ugyanazt az `a`-t jelenti
- ha `ref` változik → `a` is

Kép:

```text
a = 5

ref ----+
         |
a -------+
```

------

## Pointer (`*`)

A pointer **memóriacímet tárol**.

```cpp
int a = 5;
int* ptr = &a;

*ptr = 10;

std::cout << a;
```

Kimenet:

```text
10
```

Itt:

```cpp
ptr
```

nem az értéket tárolja, hanem:

```text
ptr = 0x61FF20
```

(egy memóriacímet)

Kép:

```text
a = 5

ptr ----> [a]
```

A `*ptr` azt jelenti:

> „menj arra a címre, és használd az ott lévő értéket”

------

## Fő különbségek

| Hivatkozás                             | Pointer                 |
| -------------------------------------- | ----------------------- |
| Másik név                              | Memóriacím              |
| Kötelező inicializálni                 | Lehet üres (`nullptr`)  |
| Nem lehet átirányítani másik változóra | Átállítható             |
| Nem kell `*` használni                 | Ki kell dereferálni `*` |
| Nem lehet `null`                       | Lehet `nullptr`         |

Példa:

### Hivatkozás

```cpp
int a=5;
int b=8;

int& ref=a;

ref=b;
```

Sokan azt hiszik:

```text
ref -> b
```

de nem.

Valójában:

```text
a = b;
```

`ref` továbbra is `a` marad.

------

### Pointer

```cpp
int a=5;
int b=8;

int* ptr=&a;

ptr=&b;
```

Most tényleg átállt:

```text
előtte: ptr -> a
utána:  ptr -> b
```

------

Ezért a hivatkozás merevebb és biztonságosabb:

```cpp
void kiir(const Hallgato& h)
```

Pointer akkor kell, ha:

- lehet „nincs objektum” (`nullptr`)
- dinamikus memória van
- több objektum között váltogatni kell

A kezdőknek jó szabály:

**Ha nem kell pointer, használj hivatkozást.**

Igen, pontosan — **C-ben nincs C++-os hivatkozás (`&` referencia)**.

C-ben csak:

- sima változók
- pointerek (`*`)

vannak.

Ami C++-ban hivatkozás:

```cpp
int a = 5;
int& ref = a;

ref = 10;
```

az C-ben **nem létezik**.

C-ben ugyanezt pointerrel oldod meg:

```c
int a = 5;
int* ptr = &a;

*ptr = 10;
```

Itt:

- `&a` → `a` címe
- `ptr` → eltárolja a címet
- `*ptr` → a címen lévő érték

Ezért C-ben, ha egy függvényből módosítani akarsz egy változót, címet adsz át:

```c
void novel(int* x)
{
    (*x)++;
}

int main()
{
    int a = 5;

    novel(&a);

    printf("%d", a);
}
```

Kimenet:

```text
6
```

C++-ban ugyanez kényelmesebb:

```cpp
void novel(int& x)
{
    x++;
}
```

hívás:

```cpp
novel(a);
```

Nem kell:

- `*`
- `&`
- dereferálás

Ezért a C++ referencia lényegében egy kényelmesebb és biztonságosabb eszköz sok pointeres feladatra.

Viszont figyelj: a `&` jel **C-ben is létezik**, csak más jelentéssel:

```c
int a=5;
int* p=&a;
```

Itt a `&` **címet kér le** ("address of"), nem hivatkozást hoz létre. C++-ban ugyanaz a jel két külön szerepben is előfordulhat:

```cpp
int* p = &a;   // cím lekérése
int& r = a;    // referencia
```

A jelentés a környezettől függ.