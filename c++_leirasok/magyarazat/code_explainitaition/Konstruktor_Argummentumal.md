```c++
// KonstruktorArgumentummal
//Egy konstruktornak átadunk argumentumokat
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    Hallgato(const char* mNev)
    {
        std::cout <<"A következő hallgató fellépítése: " << mNev << '\n';
        nev = mNev;
        feleviOraSzam = 0;
        tanulmanyiAtlag = 0.0;
    }

protected:
    std::string nev;
    int feleviOraSzam;
    double tanulmanyiAtlag;
} ;

int main(int argc, char** argv)
{
    // létrehozunk kettő hallgatot a veremben
    // kettőt pedig a halomban
    //
    std::cout<<"Stack memory: "<<'\n';
    Hallgato h("[STACK]Prüntyi");
    Hallgato h2("[STACK]Pákító");
    std::cout <<'\n';

    std::cout<<"Heap memory: "<<'\n';
    Hallgato* mH2 = new Hallgato("[HEAP]Nova");
    Hallgato* mH1 = new Hallgato("[HEAP]Ati");

    //Töröljük a Heap-et
    delete mH2;
    delete mH1;

    std::cout <<"\nA Foltatáshoz kérlek nyomd meg kétszer az enter bilentyüt..."<<std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return EXIT_SUCCESS;
}

```

Ez már teljesen jó konstruktoros példa 
Jól használod:

- konstruktor argumentummal 
- stack objektum 
- heap objektum 
- `new/delete` 
- `const char*` átadás 

A konstruktorod:

```cpp
Hallgato(const char* mNev)
```

megkapja a nevet paraméterként, majd:

```cpp
nev = mNev;
```

átmásolja a `std::string` változóba.

------

#  Ami itt fontos történik

Ez:

```cpp
Hallgato h("[STACK]Prüntyi");
```

automatikusan meghívja:

```cpp
Hallgato(const char* mNev)
```

és:

```cpp
mNev = "[STACK]Prüntyi"
```

------

#  Modern C++ apró javítás

Mivel `nev` már `std::string`, modernebb így:

```cpp
Hallgato(const std::string& mNev)
```

így:

```cpp
Hallgato(const std::string& mNev)
{
    nev = mNev;
}
```

De a mostani verziód teljesen jó tanuláshoz.

------

#  Egy nagyon fontos dolog

A stack objektumok:

```cpp
Hallgato h(...);
Hallgato h2(...);
```

automatikusan törlődnek a `main` végén.

A heap objektumok:

```cpp
new Hallgato(...)
```

nem.

Ezért kell:

```cpp
delete mH2;
delete mH1;
```

------

#  Most már kb érted az alap OOP memória modellt

| Típus | Létrehozás  | Törlés      |
| ----- | ----------- | ----------- |
| stack | automatikus | automatikus |
| heap  | `new`       | `delete`    |

------

#  Egy apró szakmai megjegyzés

Ez:

```cpp
const char* mNev
```

itt biztonságos, mert:

```cpp
std::string nev;
```

másolatot készít.

Ha sima `char*`-ba mentenéd el, akkor már lehetne dangling pointer probléma.

------

Nagyon jó irányban haladsz, mert most már:

- konstruktor
- paraméter
- stack/heap
- pointer
- encapsulation

egyszerre kezd összeállni 

Ha `char` tömbbe akarod menteni a nevet, akkor már neked kell kezelni a karaktereket és a `'\0'` terminátort is.

Példa biztonságos klasszikus C-stílusban:

```cpp
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    Hallgato(const char* mNev)
    {
        std::cout << "A következő hallgató felépítése: "
                  << mNev << '\n';

        std::strcpy(nev, mNev);

        feleviOraSzam = 0;
        tanulmanyiAtlag = 0.0;
    }

    void kiir()
    {
        std::cout << "Név: " << nev << '\n';
    }

protected:
    char nev[64];
    int feleviOraSzam;
    double tanulmanyiAtlag;
};

int main()
{
    Hallgato h("Nova");
    h.kiir();

    return 0;
}
```

------

#  Mi történik itt?

Ez:

```cpp
char nev[64];
```

egy karaktertömb.

A konstruktorban:

```cpp
std::strcpy(nev, mNev);
```

átmásolja:

```cpp
"Nev"
```

karaktereit + a `'\0'` terminátort.

------

#  Fontos veszély

A `strcpy` nem ellenőrzi a méretet.

Ha:

```cpp
mNev
```

hosszabb mint 63 karakter:

 buffer overflow lehet.

------

#  Biztonságosabb verzió

```cpp
std::strncpy(nev, mNev, sizeof(nev) - 1);
nev[sizeof(nev) - 1] = '\0';
```

Ez már limitálja a másolást.

------

#  Modern C++ miért használ inkább std::string-et?

C++

Mert:

- automatikus memória kezelés
- nincs buffer overflow
- nincs kézi `'\0'`
- kényelmesebb

------

#  Fontos különbség

## Ez:

```cpp
char nev[64];
```

fix méretű.

## Ez:

```cpp
std::string nev;
```

dinamikusan nőhet.

------

#  Ha tényleg heap-es char* kell

akkor már jön:

- `new[]`
- `delete[]`
- kézi másolás

ami már a klasszikus C++ memória kezelés világa.

C-ben

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hallgato
{
    char nev[64];
    int feleviOraSzam;
    double tanulmanyiAtlag;
};

void hallgatoLetrehoz(struct Hallgato* h, const char* mNev)
{
    printf("A következő hallgató felépítése: %s\n", mNev);

    strcpy(h->nev, mNev);

    h->feleviOraSzam = 0;
    h->tanulmanyiAtlag = 0.0;
}

void hallgatoKiir(struct Hallgato* h)
{
    printf("Név: %s\n", h->nev);
    printf("Félévi óraszám: %d\n", h->feleviOraSzam);
    printf("Tanulmányi átlag: %.2f\n\n", h->tanulmanyiAtlag);
}

int main()
{
    // STACK memória
    printf("Stack memory:\n\n");

    struct Hallgato h1;
    struct Hallgato h2;

    hallgatoLetrehoz(&h1, "[STACK] Prüntyi");
    hallgatoLetrehoz(&h2, "[STACK] Pákító");

    printf("\n");

    hallgatoKiir(&h1);
    hallgatoKiir(&h2);

    // HEAP memória
    printf("Heap memory:\n\n");

    struct Hallgato* mH1 =
        (struct Hallgato*)malloc(sizeof(struct Hallgato));

    struct Hallgato* mH2 =
        (struct Hallgato*)malloc(sizeof(struct Hallgato));

    hallgatoLetrehoz(mH1, "[HEAP] Nova");
    hallgatoLetrehoz(mH2, "[HEAP] Ati");

    printf("\n");

    hallgatoKiir(mH1);
    hallgatoKiir(mH2);

    // Heap felszabadítás
    free(mH1);
    free(mH2);

    printf("A memória felszabadítva.\n");

    return 0;
}
```

Itt C-ben nincs:

- konstruktor
- class
- `std::string`
- `new/delete`

Hanem:

- `struct`
- függvények
- `char[]`
- `malloc/free`

A `->` operátor ugyanúgy működik pointer esetén C-ben is:

```
mH1->nev
```

és a stack / heap logika ugyanaz marad