```cpp
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    //const char* mNev mivel ne modosítsa az std::string nev által átadot változót
    Hallgato(const char* mNev) { nev = mNev; std::cout << "Név: " << mNev <<'\n';}

    Hallgato() = default;
    std::string nev;
    //std::cout << "Név: " << mNev <<'\n';
    // csak a konstruktor függvényébe szabad írni
    //ez már nem a függvény része

};

int main(int argc, char** argv)
{
    Hallgato nevtelen;//nincs név tehát üres

    Hallgato* enjoy = new Hallgato("Mr Dance:D");

    delete enjoy;

    std::cout <<"A kilépéshez kérlek 2-szer nyomd meg az entert..." <<'\n';
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return 0;

}

```

Ebben a programban KÉT objektum jön létre:

## 1. Stacken létrejövő objektum

```cpp
Hallgato nevtelen;
```

Itt:

- `nevtelen` az objektum ne`ve
- stack memóriában jön létre
- automatikusan törlődik a `main()` végén

------

## 2. Heapen létrejövő objektum

```cpp
Hallgato* enjoy = new Hallgato("Mr Dance:D");
```

Itt:

- a valódi objektum a heapen jön létre
- `"Mr Dance:D"` névvel

Az `enjoy` NEM maga az objektum,
hanem POINTER az objektumra.

Kb. így:

```text
enjoy ---> Hallgato objektum ("Mr Dance:D")
```

Ezért kell:

```cpp
delete enjoy;
```

mert a heapes objektumot kézzel kell felszabadítani.

------

Tehát:

| Kód                  | Mi ez?   | Hol van? |
| -------------------- | -------- | -------- |
| `Hallgato nevtelen;` | objektum | stack    |
| `Hallgato* enjoy`    | pointer  | stack    |
| `new Hallgato(...)`  | objektum | heap     |

Nagyon fontos különbség 

A

```cpp
Hallgato() = delete;
```

azt jelenti:

> TILOS paraméter nélküli objektumot létrehozni.

Tehát ez hibás lesz:

```cpp
Hallgato nevtelen;
```

mert nincs megadva név.

------

Mikor hasznos?

Amikor az objektumnak KÖTELEZŐ adat kell.

Például egy hallgatónak mindig legyen neve:

```cpp
class Hallgato
{
public:
    Hallgato() = delete;

    Hallgato(const char* mNev)
    {
        nev = mNev;
    }

private:
    std::string nev;
};
```

Most ez engedélyezett:

```cpp
Hallgato h("Ati");
```

De ez már nem:

```cpp
Hallgato h;
```

------

Miért jó?

Mert megakadályozza az „érvénytelen” objektumokat.

Példa:

- egy `Hallgato` név nélkül értelmetlen
- egy `BankAccount` számlaszám nélkül hibás
- egy `File` fájlnév nélkül használhatatlan

------

Régen ezt bonyolultabban csinálták.
Modern C++-ban:

```cpp
= delete
```

a hivatalos módszer.

------

Hasonló:

```cpp
Hallgato(const Hallgato&) = delete;
```

→ tiltja a másolást.

Ezt például:

- mutexek,
- fájlkezelők,
- socketek

használják gyakran.

### Delete 

######  függvény() = Delete;

```cpp
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    //const char* mNev mivel ne modosítsa az std::string nev által átadot változót
    Hallgato(const char* mNev) { nev = mNev; std::cout << "Név: " << mNev <<'\n';}

    //Hallgato() = default;
    //Most megtiltjuk az érték nélküli objektum átadást
    // a delete kulcsszóval
    Hallgato() = delete;
    std::string nev;
    //std::cout << "Név: " << mNev <<'\n';
    // csak a konstruktor függvényébe szabad írni
    //ez már nem a függvény része

};

int main(int argc, char** argv)
{
    //Hallgato nevtelen;//nincs név tehát üres
    // a fentitnek most muszály nevet adni
    // a Hallgato() = delete; nem engedi
    // hogy a név érték nélkül legyen
    Hallgato nevtelen("No name");

    Hallgato* enjoy = new Hallgato("Mr Dance:D");

    delete enjoy;

    std::cout <<"A kilépéshez kérlek 2-szer nyomd meg az entert..." <<'\n';
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return 0;

}
```

