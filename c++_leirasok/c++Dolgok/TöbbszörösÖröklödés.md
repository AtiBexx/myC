### Többszörös_Öröklődés

```cpp
// Többszörös_öröklődés
// egy osztály több alaposztálytól is örökölhet
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Agy
{
public:
    Agy() {}
    void alvas()
    {
        std::cout << "Alvás" << '\n';
    }
    int suly;
};
class Kanape
{
public:
    Kanape() {}
    void TVnezes()
    {
        std::cout << "TV_Nézés" << '\n';
    }
    int suly;
};

//Kihuzhato kanapé ágy is egyben
class KihuzhatoKanape : public Agy, public Kanape
{
public:
    KihuzhatoKanape(){}
    void kihuzas()
    {
        std::cout << "Kihúzás" << '\n';
    }
};

int main(int argc, char** argv)
{
    KihuzhatoKanape kk;

    //tv nezes
    kk.TVnezes();
    //kihuzas
    kk.kihuzas();
    //alvás
    kk.alvas();

    std::cout <<'\n' <<'\n';
    std::cout << "on Heap" <<'\n';

    KihuzhatoKanape * k2 = new KihuzhatoKanape();
    k2->TVnezes();
    k2->alvas();
    k2->kihuzas();

    delete k2;
    k2 = nullptr;

    std::cout <<"A kilépéshez kérlek nyomd meg 2-szer az entert" << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return 0;
}

```

Szia! A heap-pel alapvetően nincs baj, a hiba itt van:

```cpp
k2->Agy();
```



### Ha az Agy objektumra akarsz hivatkozni

Többszörös öröklődésnél a `KihuzhatoKanape` tartalmaz egy `Agy` és egy `Kanape` részt is. Készíthetsz rá mutatót:

```cpp
Agy* a = k2;
a->alvas();
```

vagy referencia:

```cpp
Agy& a = *k2;
a.alvas();
```

### Másik potenciális probléma

Mind az `Agy`, mind a `Kanape` tartalmaz egy `suly` adattagot:

```cpp
class Agy
{
    int suly;
};

class Kanape
{
    int suly;
};
```

Ez két különböző `suly` lesz a `KihuzhatoKanape` objektumban. Ha ezt írod:

```cpp
kk.suly = 10;
```

akkor fordítási hibát kapsz, mert nem egyértelmű, hogy melyik `suly`-ra gondolsz.

Ilyenkor:

```cpp
kk.Agy::suly = 10;
kk.Kanape::suly = 20;
```

