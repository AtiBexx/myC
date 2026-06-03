### Másoló konstruktor_stack-en_és Heap-on

 A másoló konstruktor nem attól függ, hogy az objektum stacken vagy heapen van. A másoló konstruktor akkor hívódik meg, amikor **egy meglévő objektumból új objektumot hozol létre**.

A te példádban:

```cpp
Hallgato *h = new Hallgato("[HEAP]_Pákító", 1234);
```

itt a normál konstruktor fut le, mert nem egy másik `Hallgato` objektumot másolsz.

Ha heapen szeretnél másolatot készíteni, akkor így:

```cpp
Hallgato *h = new Hallgato("[HEAP]_Pákító", 1234);

// Másoló konstruktor meghívása
Hallgato *hMasolat = new Hallgato(*h);
```

Itt a `*h` dereferálja a pointert, tehát egy `Hallgato` objektumot kapunk, amiből a másoló konstruktor létrehozza az új objektumot.

A kimenet valami ilyesmi lesz:

```text
[HEAP]_Pákító felépítve
[HEAP]_Pákító másolata felépítve[másoló konstruktor]
```

Ne felejtsd el mindkettőt felszabadítani:

```cpp
delete hMasolat;
delete h;
```

Ha a függvényedet akarod meghívni heapen lévő objektummal, akkor nem ezt írod:

```cpp
fv(h);      // HIBA! h egy Hallgato*
```

hanem:

```cpp
fv(*h);     // OK
```

Ekkor a paraméter érték szerinti átadása miatt ismét lefut a másoló konstruktor:

```cpp
void fv(Hallgato masolat)
```

mert a `masolat` paraméterhez egy új `Hallgato` példány készül.

Összefoglalva:

```cpp
Hallgato *h = new Hallgato("[HEAP]_Pákító", 1234);

Hallgato *h2 = new Hallgato(*h); // heap -> heap másolat

fv(*h);                          // heap objektum átadása érték szerint

delete h2;
delete h;
```

Így ugyanaz a másoló konstruktor használódik, mint a stackes példánál. A C++ számára a másolás szempontjából nem számít, hogy az eredeti objektum stacken vagy heapen van.

Igen, a programod most már jól demonstrálja a másoló konstruktort stacken és heapen is. 👍

### 1. Miért fut le a másoló konstruktor automatikusan?

Amikor ezt írod:

```cpp
Hallgato *h2 = new Hallgato(*h);
```

a `*h` egy meglévő `Hallgato` objektumra hivatkozik. A fordító látja, hogy egy új `Hallgato`-t akarsz létrehozni egy másik `Hallgato` alapján, ezért automatikusan a másoló konstruktort hívja:

```cpp
Hallgato(const Hallgato &h)
```

Ugyanez történik itt is:

```cpp
fv(*h);
```

mert az `fv` paramétere:

```cpp
void fv(Hallgato masolat)
```

érték szerint kapja az argumentumot. Ahhoz, hogy a `masolat` nevű lokális objektum létrejöjjön, a C++ lemásolja a `*h` objektumot → másoló konstruktor fut le.

------

### 2. Miért fut le rögtön a destruktor az `fv(*h)` után?

Nézd meg:

```cpp
void fv(Hallgato masolat)
{
    std::cout <<"Az fv() függvényben\n";
}
```

A `masolat` egy lokális változó.

Lefutás:

```text
fv(*h)
  ↓
másoló konstruktor
  ↓
belép fv-be
  ↓
kiírja: Az fv() függvényben
  ↓
kilép fv-ből
  ↓
masolat megsemmisül
  ↓
destruktor
```

Ezért látod rögtön a destruktor üzenetét.

------

### 3. Mikor érdemes `delete`-elni?

Nálad most:

```cpp
std::cin.get();

delete h;
delete h2;
```

Ez teljesen jó.

A memória a program végéig megmarad, és csak az Enter után szabadul fel.

Alternatíva:

```cpp
delete h;
delete h2;

std::cin.get();
```

Ez is működik, de ilyenkor az objektumok már a várakozás előtt megsemmisülnek.

------

### 4. Mi történik, ha nem írsz `delete`-et?

```cpp
Hallgato *h = new Hallgato(...);
```

A memória foglalt marad a program végéig.

A modern operációs rendszerek a program befejezésekor visszaveszik ezt a memóriát, de C++ szempontból ez **memóriaszivárgásnak (memory leak)** számít.

Ezért a szabály:

```cpp
new  → delete
new[] → delete[]
```

------



```text
[stack]Prüntyi felépítve

Az fv() meghívása

[stack]Prüntyi másolata felépítve[másoló konstruktor]
Az fv() függvényben
[stack]Prüntyi másolata megsemmisítve

[HEAP]_Pákító felépítve

[HEAP]_Pákító másolata felépítve[másoló konstruktor]

[HEAP]_Pákító másolata felépítve[másoló konstruktor]
Az fv() függvényben
[HEAP]_Pákító másolata megsemmisítve

... Enter ...

[HEAP]_Pákító megsemmisítve
[HEAP]_Pákító másolata megsemmisítve
[stack]Prüntyi megsemmisítve
```

Jól látszik belőle, hogy a másoló konstruktor minden alkalommal lefut, amikor új objektumot kell létrehozni egy meglévőből.

#### full program

```cpp
//Másoló Konstruktor
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

class Hallgato
{
    public:
    //Hagyományos konstruktor
    Hallgato(const char *mNev = "névtelen", int kHazon = 0)
    :nev(mNev),azon(kHazon)
    {
        std::cout <<nev <<" félépítve" <<'\n';
    }
    //Másoló konstruktor
    Hallgato(const Hallgato &h)
    :nev(h.nev + " másolata"), azon(h.azon)
    {
        std::cout << nev << " felépítve[másoló kontruktor]"<<'\n';
    }
    //destruktor
    ~Hallgato()
    {
        std::cout << nev <<" megsemmísítve"<<'\n';
    }
protected:
    std::string nev;
    int azon;
};
//függvényünk
void fv(Hallgato masolat)
{
    std::cout <<"Az fv() függvényben " <<'\n';
}

int main(int argc, char** argv)
{
    //Stack objektumok
    Hallgato number1("[stack]Prüntyi", 1234);
    std::cout <<"Az fv() meghívása" <<'\n';
    fv(number1);

    //Heap objektumok
    Hallgato *h = new Hallgato("[HEAP]_Pákító", 1234);
    std::cout<<'\n';
    Hallgato *h2 = new Hallgato(*h);
    std::cout<<'\n';
    //vagy egyszerűbben
    fv(*h);//itt lefut a destruktor

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg kétszer egy entert...."<<std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();
    delete h;
    delete h2;

    return 0;
}
```

------

Amikor ezt írod:

```cpp
void fv(Hallgato masolat)
```

a `masolat` csak egy tetszőleges paraméternév. Lehetne bármi:

```cpp
void fv(Hallgato h)
```

vagy

```cpp
void fv(Hallgato kutya)
```

vagy

```cpp
void fv(Hallgato x)
```

mind ugyanazt jelenti.

A lényeg nem a név, hanem hogy **nem referencia** és **nem pointer**:

```cpp
void fv(Hallgato masolat)
```

Itt a paraméter típusa egyszerűen `Hallgato`, tehát a függvény saját példányt kap az objektumból. Ehhez másolni kell az átadott objektumot.

Példa:

```cpp
Hallgato number1("Pisti", 1234);

fv(number1);
```

A fordító ezt nagyjából így képzeli el:

```cpp
Hallgato masolat(number1); // másoló konstruktor

// fv törzse
std::cout << "Az fv() függvényben\n";

// fv vége
masolat.~Hallgato();
```

Ezért fut le a másoló konstruktor.

------

Ha nem akarod, hogy másolódjon, akkor referenciát használsz:

```cpp
void fv(const Hallgato& h)
{
    std::cout << "Az fv() függvényben\n";
}
```

Ekkor:

```cpp
fv(number1);
```

nem készül új objektum, nem fut le a másoló konstruktor, és a destruktor sem a függvény végén.

Összefoglalva:

```cpp
void fv(Hallgato h)
```

 érték szerinti átadás → másoló konstruktor

```cpp
void fv(Hallgato& h)
```

 referencia → nincs másolás

```cpp
void fv(const Hallgato& h)
```

referencia + nem módosítható → nincs másolás (ez a leggyakoribb forma)

Tehát a fordító nem a `masolat` névből tudja, hogy másolni kell, hanem abból, hogy a paraméter típusa egyszerűen `Hallgato`, nem pedig `Hallgato&` vagy `Hallgato*`.
