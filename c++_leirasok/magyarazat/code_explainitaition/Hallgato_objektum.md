```
// ObjektumMutató
//ObjMut - definiáljuk és használjuk a hallgató objektum mutatóját

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>

class Hallgato
{
public:
    int felevioraszam;
    double tanulmanyAtlag;

    double kurzusHozzaAdasa(int oraSzam, double osztalyzat);
};

int main(int argc, char** argv)
{
    //létrehozuk a hallgató objektumot
    Hallgato h;
    //beállítjuk a tanulmanyi átlagot
    h.tanulmanyAtlag = 3.0;
    //most létrehozzuk a mutatót ami a hallgató objektumra mutat
    Hallgato* mH;
    //Beállítjuk az Mh hogy a mi Hallgató objektumunkra mutasson
    //azaz átadjuk neki a mi h (hallgato) értékünket
    // pontosan átadjuk neki a h objektum memóriacímét ezáltal az értéket is.
    //ilyenkor nem adatot másolunk hanem a memóriacímünkre hivatkozunk
    mH = &h;

    // Most kiírjuk az értékeket
    std::cout <<"h.tanulmanyiAtlag: " <<h.tanulmanyAtlag <<"\n\n";

    // most kiírjuk mutatóval
    std::cout <<"mH* azaz mH->tanulmanyiAtlag: " <<mH->tanulmanyAtlag <<"\n\n";
    std::cout <<"Most létrehozzuk nem stacken hanem heapen ugyanezt"<<"\n";
    Hallgato* hH = new Hallgato;
    hH->tanulmanyAtlag = 3.3;

    std::cout <<"Heapen a tanulmányi átlag: "<< hH->tanulmanyAtlag <<"\n";
    delete hH;
    std::cout <<"És a végén töröljük delete hH;" << "\n\n";

    std::cout<<"Most pedig kiírjuk smart pointerel itt nem kell a new delete\n";
    auto hh = std::make_unique<Hallgato>();
    hh->tanulmanyAtlag = 3.4;
    std::cout<<"Smart pointerrel: " << hh->tanulmanyAtlag <<"\n";

    //kilépünk
    std::cout << "A folytatáshoz kérlek nyomd meg az Enter bilenytüt 2-szer..." << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}
```



c-ben

 C-ben is létezik a `->` operátor.

Ott is pointeren keresztül éred el a struktúra tagjait.

Viszont C-ben nincs `class` és nincs `new`.

Ott `struct` van és általában `malloc()`.

Példa C-ben:

```c
#include <stdio.h>
#include <stdlib.h>

struct Hallgato
{
    int felevioraszam;
    double tanulmanyAtlag;
};

int main()
{
    struct Hallgato* hH =
        malloc(sizeof(struct Hallgato));

    hH->tanulmanyAtlag = 3.3;

    printf("Atlag: %.1f\n",
           hH->tanulmanyAtlag);

    free(hH);

    return 0;
}
```

A `->` ugyanazt jelenti C-ben is:

```text
pointer -> tag
```

ugyanaz mint:

```c
(*pointer).tag
```

Tehát:

```c
hH->tanulmanyAtlag
```

ugyanaz mint:

```c
(*hH).tanulmanyAtlag
```

A `->` csak kényelmesebb rövidítés.

A különbség inkább ez:

C++:

```cpp
Hallgato* hH = new Hallgato;
delete hH;
```

C:

```c
struct Hallgato* hH =
    malloc(sizeof(struct Hallgato));

free(hH);
```

Tehát:

- `->` van mindkettőben
- pointer logika ugyanaz
- memóriafoglalás módja más 

Nem  Java-ban a `->` teljesen másra is használható: ott a lambda kifejezéseknél jelent meg.

C/C++:

```cpp
pointer->tag
```

Java:

```java
(x) -> x * 2
```

Ez lambda.

Példa Java-ban:

```java
Runnable r = () -> {
    System.out.println("Hello");
};
```

vagy:

```java
(a, b) -> a + b
```

Itt a `->` azt jelenti kb:

```text
bemenet -> művelet
```

Tehát:

- bal oldal = paraméterek
- jobb oldal = végrehajtandó kód

C++-ban a `->` pointer operátor.
Java-ban a `->` lambda operátor.

Viszont érdekesség:
C++11-től C++-ban is vannak lambdák 

Példa:

```cpp
auto f = [](int x) {
    return x * 2;
};
```

de ott nem `->` indítja a lambdát, hanem `[]`.

C++-ban a `->` lambda esetén csak opcionális visszatérési típusnál jelenhet meg:

```cpp
auto f = [](int x) -> int {
    return x * 2;
};
```

itt a `-> int` azt jelenti:

- a lambda `int` típust ad vissza

Szóval ugyanaz a jel több nyelvben mást jelent 

Ma a modern C++ fejlesztők nagy része inkább a C++ smart pointereit használja (`std::unique_ptr`, `std::shared_ptr`) a nyers `new/delete` helyett — és pont a nagyon tapasztalt fejlesztők között ez különösen gyakori.

Régebben viszont:

- C stílus
- régi C++98
- játékmotorok
- embedded rendszerek

esetén tényleg sok kézi `new/delete` volt.

A probléma a kézi memóriakezeléssel:

```cpp
Hallgato* h = new Hallgato;
```

ha valahol:

- exception történik
- korai `return`
- elfelejted a `delete`-et

akkor memóriaszivárgás lesz.

Ezért modern C++-ban inkább:

```cpp
#include <memory>

auto h = std::make_unique<Hallgato>();

h->tanulmanyAtlag = 3.5;
```

Itt:

- nincs kézi `delete`
- automatikusan felszabadul
- exception-safe
- sokkal biztonságosabb

A modern C++ szemlélet kb:

```text
"Ha lehet, ne használj közvetlen new/delete-et."
```

Viszont nagyon fontos:
attól még meg kell érteni a nyers pointereket és a `new/delete` működését.

Mert:

- smart pointerek is pointerekre épülnek
- régi kódbázisok tele vannak velük
- engine-ekben, low-level kódban még ma is előfordul
- interjúkon is kérdezik

 (`new/delete`, `*`, `&`, `->`) az nagyon fontos alap 

----------------------

- stack objektum
- raw pointer
- heap + `new/delete`
- smart pointer

egymás mellett nagyon jól látható.

 vannak területek, ahol nem vagy ritkábban használnak smart pointereket.

Például:

- kernel driverek
- operációs rendszer kernel
- embedded rendszerek
- nagyon low-level engine kód
- hardverközeli C API-k
- realtime rendszerek

Itt sokszor:

- nincs teljes STL
- nincs exception
- nincs RTTI
- speciális allocator van
- szigorú memória kontroll kell
- vagy egyszerűen coding standard tiltja

Például Linux kernelben nagyrészt sima C van:

- `malloc` helyett `kmalloc`
- kézi felszabadítás
- manuális életciklus kezelés

Sok játékmotorban is:

- custom memory pool
- saját allocator
- saját smart pointer rendszer

van.

Viszont modern általános C++ alkalmazásoknál:

- desktop app
- backend
- toolok
- GUI
- üzleti szoftver

ott nagyon gyakori a `unique_ptr`.

Ami fontos:
a smart pointer NEM "varázslat".

A `unique_ptr` belül kb ezt csinálja:

```cpp
class UniquePtr
{
    T* ptr;

    ~UniquePtr()
    {
        delete ptr;
    }
};
```

tehát a végén ugyanúgy `delete` történik, csak automatikusan.
mielőtt valaki smart pointert használ, értenie kell:

- heap
- stack
- pointer
- dereferencia
- ownership
- `new/delete`

különben nem fogja érteni, mi történik a háttérben 