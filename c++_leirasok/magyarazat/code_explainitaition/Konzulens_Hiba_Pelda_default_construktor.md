#### Ha a Konzulens elöbb épülne fel mint a Hallgató az gond lenne itt

```cpp
//Lefordul 
    //Akkor lenne gond ha a Konzulens elöbb lenne azaz alöbb épülne fel mint a Hallgato pici
    Hallgato pici(1234);
    Konzulens k(pici);
```

-> tovább full kód:

```cpp
//
// TömbFelépítése
//Egy objektumTömb felépítése
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <iterator>

class Hallgato
{
public:
    Hallgato() : hallgatoiAzonosito(0)
    {
        std::cout <<"Névtelen hallgató felépítése"<<'\n';
        nev = "nevtelen";
        feleviOraSzam = 0;
        tanulmanyiAtlag = 0.0;
    }

    Hallgato(const char* mNev) :hallgatoiAzonosito(0)
    {
        std::cout <<"A következő hallgató fellépítése: "
        << mNev <<'\n';

        nev=mNev;
        feleviOraSzam = 0;
        tanulmanyiAtlag = 0;
    }
    //értéket adunk a hAzonositonak gy nem kötelező megadni az értéket az objektum hívásakor
    Hallgato(const char* mNev, int atadottOraszam, float atadottAtlag, int hAzonosito = 0)
    : nev(mNev),feleviOraSzam(atadottOraszam), tanulmanyiAtlag(atadottAtlag), hallgatoiAzonosito(hAzonosito)
    {
        std::cout<< "A következő hallgató fellépítése: "
        << mNev << atadottOraszam << atadottAtlag <<'\n';
    }

    Hallgato(int azonosito) :hallgatoiAzonosito(azonosito)
    {
        std::cout<<"Hallgatoi azonosító: "<< azonosito <<'\n';
    }
    int getAzonosito() const
    {
        return hallgatoiAzonosito;
    }

    ~Hallgato(){std::cout<<"Hallgató objektumok megsemmísétése : "<< nev <<'\n';}
protected:
    std::string nev;
    int feleviOraSzam;
    float tanulmanyiAtlag;
    const int hallgatoiAzonosito;
};

class Konzulens
{
public:
    Konzulens(Hallgato& h) : konzulensAzonosito(h.getAzonosito())
    {

    }
    ~Konzulens() {std::cout<<"A konzulens_Destruktora"<<'\n';}
protected:
    int konzulensAzonosito;
};

int main(int argc, char** argv)
{
    //stack (VEREM)
    Hallgato h[]{"Prüntyi", "Pákító"};
    Hallgato hh[] {{"Gemi",5,4.5},{"Claude",5, 4.5},{"NOVA",5,5.0}};
    Hallgato h2("Ati");
    //Heap
    Hallgato* hN = new Hallgato("Anonymus");
    //Heap Tömb
    Hallgato* nNTomb[] ={
    new Hallgato("AnonimeGril"),
    new Hallgato("HeapMaster")
    };

    //Lefordul 
    //Akkor lenne gond ha a Konzulens elöbb lenne azaz alöbb épülne fel mint a Hallgato pici
    Hallgato pici(1234);
    Konzulens k(pici);

    std::cout<<"A FOLYTATÁSHOZ KÉRLEK NYOMD MEG KÉTSZER AZ ENTERT..."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();
    // az Enter megnyomása után kell törölni
    //tőrlés
    delete hN;
    /*delete nNTomb[0];
    delete nNTomb[1];*/

    // vagy
    /*for(int i = 0; i < std::size(nNTomb); i ++)
    {
        delete nNTomb[i];
    }*/

    //vagy
    /*for(auto p: nNTomb)
    {
        delete p;
    }*/
    //vagy
    int nNTombSize = sizeof(nNTomb) / sizeof(nNTomb[0]);
    for(int i = 0; i < nNTombSize; i++)
    {
        delete nNTomb[i];
    }

    return EXIT_SUCCESS;
}


```

**OUTPUT:**

```cpp
A következő hallgató fellépítése: Prüntyi
A következő hallgató fellépítése: Pákító
A következő hallgató fellépítése: Gemi54.5
A következő hallgató fellépítése: Claude54.5
A következő hallgató fellépítése: NOVA55
A következő hallgató fellépítése: Ati
A következő hallgató fellépítése: Anonymus
A következő hallgató fellépítése: AnonimeGril
A következő hallgató fellépítése: HeapMaster
Hallgatoi azonosító: 1234
A FOLYTATÁSHOZ KÉRLEK NYOMD MEG KÉTSZER AZ ENTERT...


Hallgató objektumok megsemmísétése : Anonymus
Hallgató objektumok megsemmísétése : AnonimeGril
Hallgató objektumok megsemmísétése : HeapMaster
A konzulens_Destruktora
Hallgató objektumok megsemmísétése : 
Hallgató objektumok megsemmísétése : Ati
Hallgató objektumok megsemmísétése : NOVA
Hallgató objektumok megsemmísétése : Claude
Hallgató objektumok megsemmísétése : Gemi
Hallgató objektumok megsemmísétése : Pákító
Hallgató objektumok megsemmísétése : Prüntyi

Process returned 0 (0x0)   execution time : 1.509 s
Press ENTER to continue.


```

##### Egy osztály tagjai abban a sorrendben épülnek fel amelyben deklarálva vannak

pl: itt az nAzonosito épül fel elsőnek dAtlag az utolsó

```cpp
class Hallgato
{
    public:
    Hallgato(int azonosito, int kor) : nKor(kor), nAzonosito(azonosito){}
    protected:
    const int nAzonosito;
    const int nKor;
    double dAtlag =0.0;
};
```

##### Egy osztály tagjai abban a sorrendben épülnek fel amelyben deklarálva vannak

pl: itt az nAzonosito épül fel elsőnek dAtlag az utolsó

Igen. 🙂

Ha ezt írod:

```cpp
Hallgato h[5];
```

akkor **5 darab `Hallgato` objektum jön létre** a tömbben.

Viszont ehhez kell, hogy legyen **paraméter nélküli (default) konstruktor**, mert a fordító így hozza létre az elemeket:

```cpp
h[0]
h[1]
h[2]
h[3]
h[4]
```

és mindegyiknél meghívja a default konstruktort.

Például:

```cpp
class Hallgato
{
public:
    Hallgato()
    {
        std::cout << "Hallgato letrejott\n";
    }
};
Hallgato h[5];
```

Kimenet:

```text
Hallgato letrejott
Hallgato letrejott
Hallgato letrejott
Hallgato letrejott
Hallgato letrejott
```

------

A te utolsó példádban viszont:

```cpp
class Hallgato
{
public:
    Hallgato(int azonosito, int kor)
        : nAzonosito(azonosito), nKor(kor)
    {}
};
```

**nincs default konstruktor**, ezért:

```cpp
Hallgato h[5];
```

fordítási hibát adna.

Ilyenkor vagy készítesz default konstruktort:

```cpp
Hallgato()
    : nAzonosito(0), nKor(0)
{}
```

vagy minden elemhez megadod az adatokat:

```cpp
Hallgato h[] =
{
    {1, 20},
    {2, 21},
    {3, 22},
    {4, 23},
    {5, 24}
};
```

------

A memóriában egy ilyen tömb így néz ki:

```text
h[0] h[1] h[2] h[3] h[4]
```

5 egymás után elhelyezkedő `Hallgato` objektum, nem 5 mutató, hanem valódi objektum. A program végén pedig a destruktoruk automatikusan meghívódik fordított sorrendben:

```text
h[4]
h[3]
h[2]
h[1]
h[0]
```

ha van destruktor az osztályban.

Majdnem, de nem egészen. 🙂

Ha **alapértelmezett konstruktort** szeretnél, akkor több lehetőséged van.

### 1. Saját default konstruktor

```cpp
class Hallgato
{
public:
    Hallgato()
        : nAzonosito(0), nKor(0)
    {
    }

    Hallgato(int azonosito, int kor)
        : nAzonosito(azonosito), nKor(kor)
    {
    }

protected:
    const int nAzonosito;
    const int nKor;
};
```

------

### 2. `= default`

Ez csak akkor működik, ha a fordító képes automatikusan létrehozni a default konstruktort.

A szintaxis:

```cpp
Hallgato() = default;
```

**Nem ez:**

```cpp
default = Hallgato();   // ❌ hibás
```

és nem is:

```cpp
Hallgato() = Hallgato(); // ❌ hibás
```

------

### 3. A te esetedben viszont van egy csavar

Nálad:

```cpp
const int nAzonosito;
const int nKor;
```

Ezek `const` tagok.

Ha ezt írod:

```cpp
Hallgato() = default;
```

a fordító nem tudja, milyen értéket adjon a két `const int` tagnak, ezért a default konstruktor törlődik (deleted lesz).

Példa:

```cpp
class Hallgato
{
public:
    Hallgato() = default; // ❌

protected:
    const int nAzonosito;
    const int nKor;
};
```

Fordítási hiba.

------

### 4. Ha ragaszkodsz a `= default`-hoz

Adj alapértéket a tagoknak:

```cpp
class Hallgato
{
public:
    Hallgato() = default;

    Hallgato(int azonosito, int kor)
        : nAzonosito(azonosito), nKor(kor)
    {
    }

protected:
    const int nAzonosito = 0;
    const int nKor = 0;
    double dAtlag = 0.0;
};
```

Ekkor már működik:

```cpp
Hallgato h[5];
```

mert a fordító tudja, hogy a `const` tagok értéke alapból `0`.

### Röviden

❌ Hibás:

```cpp
default = Hallgato();
```

✔️ Helyes:

```cpp
Hallgato() = default;
```

De a te osztályodnál ez csak akkor működik, ha a `const` adattagoknak adsz alapértéket, vagy írsz saját default konstruktort, amely inicializálja őket.
