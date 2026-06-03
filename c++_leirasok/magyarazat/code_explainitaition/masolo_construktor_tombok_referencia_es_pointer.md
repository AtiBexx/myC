#### Másolo_kondtruktor és tömbök_Referencia_és_mutató_Pointer

### Referencia (`&`)

```cpp
void fv(const Hallgato& h)
```

Itt a `h` **referencia**. Nem másolat készül, hanem a függvény ugyanarra az objektumra hivatkozik.

```cpp
Hallgato Nova("Nova", 1234);
fv(Nova);
```

A másoló konstruktor **nem hívódik meg**.

A referencia a háttérben gyakran címként van megvalósítva, de C++ szinten nem mutató, hanem egy alternatív név ugyanarra az objektumra.

------

### Mutató (`*`)

```cpp
void fv(const Hallgato* h)
```

Hívás:

```cpp
fv(&Nova);
```

Itt ténylegesen a memóriacímet adod át.

Használat:

```cpp
std::cout << h->getNev();
```

vagy

```cpp
std::cout << (*h).getNev();
```

------

### Mi a különbség?

Referencia:

```cpp
void fv(const Hallgato& h);
fv(Nova);
```

Mutató:

```cpp
void fv(const Hallgato* h);
fv(&Nova);
```

Mindkettőnél **nincs másolás**.

------

### Mikor hívódik meg a másoló konstruktor?

Csak amikor új objektumot kell létrehozni egy meglévőből:

```cpp
Hallgato h2(h1);        // másoló konstruktor
Hallgato h3 = h1;       // másoló konstruktor
```

vagy

```cpp
void fv(Hallgato h);    // érték szerinti paraméter
fv(h1);                 // másoló konstruktor
```

------

### Mit érdemes használni?

Ha a függvény csak olvassa az objektumot:

```cpp
void fv(const Hallgato& h)
```

Ez a leggyakoribb és legkényelmesebb megoldás.

Ha lehet, ne írj ilyet:

```cpp
void fv(Hallgato h)
```

mert minden híváskor másolat készül.

A `const Hallgato* h` akkor hasznos, ha a paraméter lehet `nullptr` is:

```cpp
void fv(const Hallgato* h)
{
    if(h)
        ...
}
```

Egy normál objektum átadására viszont a `const Hallgato&` a legelterjedtebb C++-os megoldás.

```cpp
/*
A konstruktor egy különleges függvény, amit a c++
automatikusan meghív az objektumok létrehozásakor
hogy, inicializálni tudják magukat.
*/
//Másoló konstruktor
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <iterator>

class Hallgato
{
public:
    //Hagyományos konstruktor
    Hallgato(const char* mNev = "névtelen", int khAzonosito = 0)
    : nev(mNev), azon(khAzonosito)
    {
        std::cout << nev <<"felépítve[hagyományos_konstruktor]" << '\n';
    }
    //másoló konstruktor
    Hallgato(const Hallgato &h)
    : nev(h.nev + " másolata"),azon(h.azon)
    {
        std::cout << nev << "felépítve" <<'\n';
    }
    //destruktor
    ~Hallgato() {std::cout <<"A hallgato megsemmisítése"<< '\n';}
protected:
    std::string nev;
    int azon;
};
// fv érték szerint kapja az argumentumát
void fv(Hallgato masolat)
{
    std::cout << "Az fv() függvényben" << '\n';
}
int main(int argc, char** argv)
{
    //stack
    Hallgato Nova("Nova", 1234);
    fv(Nova);

    //Heap
    Hallgato* hTomb[] ={
    new Hallgato("Ati", 1234),
    new Hallgato("Pruntyi&Pakito", 5678)
    };

    std::cout << "újra a main függvényben" << '\n';
    //kilépünk
    std::cout <<"A kilépéshez kérlek nyomd meg 2-szer az ENTERT...."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    //Tőrlünk
    for(int i = 0; i < std::size(hTomb); i++)
    {
        delete hTomb[i];
    }

    return EXIT_SUCCESS;
}

```

#### Tömbös verziók

## 1. Objektumtömb (`new Hallgato[2]`)

```cpp
Hallgato* hallgato = new Hallgato[2];

hallgato[0] = Hallgato("Ati", 1234);
hallgato[1] = Hallgato("Pruntyi&Pakito", 5678);
```

Itt **egyben** foglaltál le egy 2 elemű tömböt.

Törlés:

```cpp
delete[] hallgato;
```

❌ Nem szabad:

```cpp
delete hallgato[0];
delete hallgato[1];
```

mert `hallgato[0]` és `hallgato[1]` nem mutatók, hanem objektumok.

------

## 2. Mutatótömb (`Hallgato* hTomb[]`)

A jelenlegi kódod:

```cpp
Hallgato* hTomb[] =
{
    new Hallgato("Ati", 1234),
    new Hallgato("Pruntyi&Pakito", 5678)
};
```

Itt:

- `hTomb[0]` → egy `Hallgato*`
- `hTomb[1]` → egy `Hallgato*`

Mindkét objektum külön `new`-val lett létrehozva.

Ezért kell:

```cpp
for (int i = 0; i < std::size(hTomb); i++)
{
    delete hTomb[i];
}
```

Ez nálad teljesen helyes.

------

## Képzeld el így

### Objektumtömb

```cpp
Hallgato* tomb = new Hallgato[2];
```

Memória:

```text
[Hallgato][Hallgato]
 ^
 tomb
```

Egyetlen blokk → `delete[] tomb`

------

### Mutatótömb

```cpp
Hallgato* tomb[] =
{
    new Hallgato("Ati",1234),
    new Hallgato("Paki",5678)
};
```

Memória:

```text
tomb[0] ---> [Hallgato]
tomb[1] ---> [Hallgato]
```

Két külön foglalás → mindkettőt külön kell törölni:

```cpp
delete tomb[0];
delete tomb[1];
```

vagy ciklussal.

------

Modern C++-ban viszont általában nem használnánk sem `new`-t, sem `delete`-et erre. Inkább:

```cpp
#include <vector>

std::vector<Hallgato> hallgatok =
{
    Hallgato("Ati",1234),
    Hallgato("Pruntyi&Pakito",5678)
};
```

Ekkor a memória kezelése automatikus, és nem kell kézzel törölni semmit.