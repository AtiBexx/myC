## Függvény_Objektiv_Értékel

```
//OBJEKT ÉRTÉK ÁTADÁS

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Tanulo{
    public:
    int feleviOraszam = 0;
    double tanulmanyiAtlag = 0;

};

void egyFv(Tanulo masolatH) 
{
    masolatH.feleviOraszam = 10;
    masolatH.tanulmanyiAtlag = 5;
    cout << "A masolatH.tanulmanyiAtlagÉrtéke: " << masolatH.tanulmanyiAtlag << endl;
}

int main(int argc, char* argv[]) {
    Tanulo t;
    t.tanulmanyiAtlag = 0.0;
    
cout << "t.tanulmanyiAtlag értéke: " << t.tanulmanyiAtlag << endl;

    //meghivjuk a függvényünket
    cout << "Az egy Fv() értéke: " << endl;
    egyFv(t);
    cout << "Visszatérés az egy fv tanulo függvényböl " << endl;
    // a t. tanulmanyi értéke mindig 0 marad

    cout << "t.tanulmanyiAtlag értéke: " << t.tanulmanyiAtlag << endl;


    //kilépünk
    cout << "A folytatáshoz nyomd meg az Entert..." << endl;
    cin.get();
    return EXIT_SUCCESS;
}
```

```
//output
ok_pointerek_tulterheles\"FunctionWithObjectValue
t.tanulmanyiAtlag értéke: 0
Az egy Fv() értéke:
A masolatH.tanulmanyiAtlagÉrtéke: 5
Visszatérés az egy fv tanulo függvényböl
t.tanulmanyiAtlag értéke: 0
A folytatáshoz nyomd meg az Entert...
```

## hívjuk meg a függvényt egy Objektiv mutatóval

```
//OBJEKTIV --MUTATÓ ÁTADÁS

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Tanulo {
    public:
    int feleviOraszam = 0;
    double tanulmanyiAtlag = 0;
};

void egyFv (Tanulo *mH) {

    mH-> feleviOraszam = 10;
    mH->tanulmanyiAtlag = 3.0;
    cout << "A mH->tanulmanyiAtlagÉrtéke: " << mH->tanulmanyiAtlag << endl;
}

int main(int argc, char* argv[]) {
    Tanulo t;
    t.tanulmanyiAtlag = 0.0;

    //kiírjuk a t.tanulmanyiAtlag értékét mielött meghívjuk a egy Fv() függvényt
    cout << "t.tanulmanyiAtlag értéke: " << t.tanulmanyiAtlag << endl;

    // átadjuk a meglévő objektum címét
    cout << "Az egy Fv(Tanulo*) -- értéke.....egyFv(&t); : " << endl;
    egyFv(&t);
    cout << "Visszatérés az egy fv tanulo függvényböl " << endl;

    //a t.tanulmanyiAtlag értéke 3.0 most már
    cout << "t.tanulmanyiAtlag értéke: " << t.tanulmanyiAtlag << endl;

    //kilépünk
    cout << "A folytatáshoz kérlek nyomd meg az Entert..." << endl;
    cin.get();
    return EXIT_SUCCESS;
}

/*
Ez a program szemlélteti hogy valojában a t tanulo címét adjuk át 
nem pedig az értéket adjuk át.

*/
```

```
//output

t.tanulmanyiAtlag értéke: 0
Az egy Fv(Tanulo*) -- értéke.....egyFv(&t); :
A mH->tanulmanyiAtlagÉrtéke: 3
Visszatérés az egy fv tanulo függvényböl
t.tanulmanyiAtlag értéke: 3
A folytatáshoz kérlek nyomd meg az Entert...
```

#### Hivjuk meg a függvényt hivatkozási operátoral &

```
//Egy objektum tartalmának a módosítása 
//Egy függvényben  egy hivatkozás használatával

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Tanulo 
{
    public:
        double tanulmanyiAtlag = 0.0;
        int feleviOraszam = 0; 
};

void egyFv(Tanulo& hivH) {
    hivH.feleviOraszam = 10;
    hivH.tanulmanyiAtlag = 3.0;
    //kiirjuk az eredményt
    cout << "A hivH.atlag értéke: " << hivH.tanulmanyiAtlag << endl;
}

int main(int argc, char* argv[]) {
    Tanulo t;
    t.tanulmanyiAtlag = 0.0;

    //kiirjuk a t.tanulmanyiAtlag értékét mielött meghívjuk a egy Fv() függvényt
    cout << "t.tanulmanyiAtlag értéke: " << t.tanulmanyiAtlag << endl;

    //átadjuk a meglévő objektum címét
    cout << "Az egy Fv(Tanulo&) -- értéke.....egyFv(t); : " << endl;
    egyFv(t);
    cout << "Visszatérés az egy fv tanulo függvényböl " << endl;

    //a t.tanulmanyiAtlag értéke 3.0 most már
    cout << "t.tanulmanyiAtlag értéke: " << t.tanulmanyiAtlag << endl;

    //kilépünk
    cout << "A folytatáshoz kérlek nyomd meg az Entert..." << endl;
    cin.get();
    return EXIT_SUCCESS; //vagy return 0;
}
```

#### csináljunk egy másik függvényt pointerrel

```
//Egy objektum tartalmának a módosítása 
//Egy függvényben  egy hivatkozás használatával

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
class myClass
{
    public:
    int value = 0;
};
class Tanulo 
{
    public:
        double tanulmanyiAtlag = 0.0;
        int feleviOraszam = 0; 
};

void egyFv(Tanulo& hivH) {
    hivH.feleviOraszam = 10;
    hivH.tanulmanyiAtlag = 3.0;
    //kiirjuk az eredményt
    cout << "A hivH.atlag értéke: " << hivH.tanulmanyiAtlag << endl;
}

void masFv(){
    myClass *myClassPtr = new myClass[10];
    for (int i = 0; i < 10; i++)
    {
        myClassPtr[i].value = i;
        cout <<"Index:" << i << ", value: " << myClassPtr[i].value << endl;
    }
    //visszateszük a memóriát a halomba
    delete[] myClassPtr;
    myClassPtr = nullptr;
};

int main(int argc, char* argv[]) {
    Tanulo t;
    t.tanulmanyiAtlag = 0.0;

    //kiirjuk a t.tanulmanyiAtlag értékét mielött meghívjuk a egy Fv() függvényt
    cout << "t.tanulmanyiAtlag értéke: " << t.tanulmanyiAtlag << endl;

    //átadjuk a meglévő objektum címét
    cout << "Az egy Fv(Tanulo&) -- értéke.....egyFv(t); : " << endl;
    egyFv(t);
    cout << "Visszatérés az egy fv tanulo függvényböl " << endl;

    //a t.tanulmanyiAtlag értéke 3.0 most már
    cout << "t.tanulmanyiAtlag értéke: " << t.tanulmanyiAtlag << endl;

    cout <<"Meghivjuk a masFv() függvényt" << endl;
    masFv();
    cout <<"Itt visszaraktok a memóriát a halomba" << endl;

    //kilépünk
    cout << "A folytatáshoz kérlek nyomd meg az Entert..." << endl;
    cin.get();
    return EXIT_SUCCESS; //vagy return 0;
}

/*
Egy nagyon fontos modern C++ megjegyzés (pro tipp)

A new / delete manuális használata ma már nem ajánlott.

Jobb:

C++11:

#include <vector>

vector<myClass> myClassPtr(10);

for(int i=0;i<5;i++)
{
    myClassPtr[i].value = i;
}

Miért jobb?

✔ nincs memory leak
✔ nincs delete
✔ exception safe
✔ egyszerűbb

Ez az úgynevezett RAII gondolkodás.
*/

/*
3 helyes megoldás C++11-ben:
1. Külön változóban tárolod (klasszikus C/C++ módszer)

Ez a leggyakoribb:

int size = 10;

myClass *myClassPtr = new myClass[size];

for(int i = 0; i < size; i++)
{
    myClassPtr[i].value = i;
}

Ez a klasszikus low level megoldás.

2. const méret (még jobb)
const int SIZE = 10;

myClass *myClassPtr = new myClass[SIZE];

for(int i = 0; i < SIZE; i++)
{
    myClassPtr[i].value = i;
}

Ez biztonságosabb.

3. Modern C++11 (ajánlott)

vector:

#include <vector>

vector<myClass> myClassPtr(10);

for(size_t i = 0; i < myClassPtr.size(); i++)
{
    myClassPtr[i].value = i;
}

Ez tudja a méretét:

myClassPtr.size()

Ezért sokkal biztonságosabb.
*/
```

