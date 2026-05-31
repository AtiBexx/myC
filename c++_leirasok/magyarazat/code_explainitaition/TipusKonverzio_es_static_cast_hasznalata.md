#### TípusKonverzió és static_cast<>() használata

```cpp
class hallgato
{
    public:
    //a következő"Névtelen" konstruktor nem használható
    //az int és a Hallgato közötti implicit konverziós útvonalként
    explicit Hallgato(int nHallgatoiAzon);
};
//Hallgato h = 1 továbbra se jó nem is lesz
Hallgato i(12345); //ez tivábbra is jü
```

Ez az `explicit` kulcsszó lényege.

Nézzük ezt:

```cpp
class Hallgato
{
public:
    explicit Hallgato(int nHallgatoiAzon);
};
```

A konstruktor egyetlen `int` paramétert vár. Normál esetben a C++ ezt **konverziós konstruktornak** tekinti.

### Explicit nélkül

```cpp
class Hallgato
{
public:
    Hallgato(int nHallgatoiAzon);
};
```

Ekkor ez működik:

```cpp
Hallgato h = 1;
```

A fordító ezt automatikusan átírja:

```cpp
Hallgato h(1);
```

Vagyis az `int`-ből automatikusan készít egy `Hallgato` objektumot.

------

### Explicit-tel

```cpp
class Hallgato
{
public:
    explicit Hallgato(int nHallgatoiAzon);
};
```

Ekkor ez már **tilos**:

```cpp
Hallgato h = 1;   // HIBA
```

mert az `explicit` megakadályozza az automatikus konverziót.

Viszont ez továbbra is jó:

```cpp
Hallgato h(1);
```

vagy

```cpp
Hallgato h{1};
```

mert itt te **kifejezetten** megmondod, hogy a konstruktort akarod meghívni.

------

Ezért írja a jegyzet:

```cpp
// Hallgato h = 1; továbbra sem jó
```

de

```cpp
Hallgato i(12345);
```

jó.

A különbség:

```cpp
Hallgato h = 1;     // implicit konverzió
```

vs.

```cpp
Hallgato h(1);      // explicit konstruktorhívás
```

Az `explicit` csak az elsőt tiltja.

Ez nagyon hasznos például ilyen hibák elkerülésére:

```cpp
void kiir(Hallgato h);

kiir(12345); // explicit nélkül működne
```

A fordító automatikusan létrehozna egy `Hallgato` objektumot az `12345` számból. Az `explicit` ezt megakadályozza, így csak ez lesz érvényes:

```cpp
kiir(Hallgato(12345));
```

vagy

```cpp
Hallgato h(12345);
kiir(h);
```

Így a kód egyértelműbb és kevesebb a véletlen konverzió.

Igen, pontosan ez történik. 👍

Ha a konstruktor **nem explicit**, akkor:

```cpp
class Hallgato
{
public:
    Hallgato(int azonosito);
};
```

és ezt írod:

```cpp
Hallgato h = 1;
```

akkor a fordító ezt úgy értelmezi, mintha ezt írtad volna:

```cpp
Hallgato h(1);
```

Vagy még pontosabban:

```cpp
Hallgato temp(1);
Hallgato h = temp;
```

(a fordító ezt általában optimalizálja, de a jelentése ez).

Ez az úgynevezett **implicit konverzió** (`int` → `Hallgato`).

------

### Hasonló példa a `std::string`-gel

```cpp
std::string s = "Hello";
```

Itt sem string objektumot adsz meg a jobb oldalon, hanem egy karakterláncot (`const char*`).

A fordító a háttérben meghívja a megfelelő konstruktort:

```cpp
std::string s("Hello");
```

------

### Miért lehet ez veszélyes?

Tegyük fel:

```cpp
class Hallgato
{
public:
    Hallgato(int azonosito);
};

void kiir(Hallgato h)
{
}
```

Ekkor ez is lefordul:

```cpp
kiir(12345);
```

mert a fordító automatikusan csinálja:

```cpp
kiir(Hallgato(12345));
```

Sokszor ez nem szándékos, ezért használjuk az `explicit` kulcsszót.

------

### Összefoglalás

**Explicit nélkül:**

```cpp
Hallgato h = 1;      // OK
```

A háttérben:

```cpp
Hallgato h(1);
```

**Explicit-tel:**

```cpp
explicit Hallgato(int);
```

akkor

```cpp
Hallgato h = 1;      // HIBA
Hallgato h(1);       // OK
Hallgato h{1};       // OK
```

Az `explicit` tehát azt mondja a fordítónak:

> „Ne alakíts át automatikusan más típusokat `Hallgato`-vá, csak akkor, ha ezt a programozó kifejezetten kéri.”

példa kód:

```cpp
//TypeConversion
//Szemlélteti az egyik típusról a másikra való
//történő implicit konverzióját
//C++ 2011 -es szabványtól
//használható az explicit kulcsszó ....

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Komplex
{
public:
    Komplex() : dValos(0.0), dImag(0.0)
    {
        std::cout <<"Az alapértelmezet konstruktor meghívása" <<'\n';
    }
    explicit Komplex(double _dValos) : dValos(_dValos),dImag(0.0)
    {
        std::cout <<"A valós konstruktor meghívása.... : "
        << dValos <<'\n';
    }
    Komplex(double _dValos, double _dImag): dValos(_dValos),
    dImag(_dImag)
    {
        std::cout <<"A komplex komnstruktor meghívása: "
        << ", "<< dImag <<'\n';
    }
    ~Komplex(){std::cout<<"Komplex megsemmisítése"<<'\n';}
protected:
    double dValos;
    double dImag;
};

int main(int argc, char** argv)
{
    Komplex k1, k2(1.0), k3(1.0, 1.0);

    k1 = Komplex(10.0);

    //A következő Objektumok vagy konverziók
    //akkor is müködnek ha az explicit nincs kikommentelve
    //itt azonal lefut a destruktor
    k1=(Komplex)20.0;
    k1= static_cast<Komplex>(30.0);

    //Implicit verziók
    //Ezek csak akkor müködnek ha az explicit ki van kommentelve
    /*k1=40.0;
    k1=50;*/
    std::cout<<"Heap verzió:"<<'\n';
    Komplex* k = new Komplex(100, 50);


    //kilépünk
    std::cout<<"A folytatáshoz kérlek kétszer nyomd meg az enter...." <<std::endl;
    //puffer delete bár itt nem kell de berakjuk a tanulás miatt
    //std::cin.ignore(1000, '\n');
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();//várunk az enterre(azaz egy bilentyűre)

    delete k;

    return EXIT_SUCCESS;
}

```

Ez a program nagyon jól szemlélteti az `explicit` hatását.

A kulcs ez a konstruktor:

```cpp
explicit Komplex(double _dValos)
    : dValos(_dValos), dImag(0.0)
{
}
```

Mivel `explicit`, a fordító **nem végezhet automatikus (`double` → `Komplex`) konverziót**.

------

### Ezek működnek

```cpp
k1 = Komplex(10.0);
```

Itt te magad hozol létre egy `Komplex` objektumot.

------

```cpp
k1 = (Komplex)20.0;
```

Ez egy C-stílusú cast.

A fordító ezt nagyjából így kezeli:

```cpp
k1 = Komplex(20.0);
```

------

```cpp
k1 = static_cast<Komplex>(30.0);
```

Ez a modern C++-os, típusbiztosabb változat.

A fordító itt is explicit módon meghívja a konstruktort.

------

### Ezek nem működnek `explicit` esetén

```cpp
k1 = 40.0;
```

A fordító ilyenkor szeretné ezt csinálni:

```cpp
k1 = Komplex(40.0);
```

de az `explicit` ezt megtiltja.

Ugyanez:

```cpp
k1 = 50;
```

Itt:

```cpp
50 -> double -> Komplex
```

lenne az implicit konverziós útvonal, de az `explicit` miatt nem engedélyezett.

------

### Mi történik a destruktorral?

Itt:

```cpp
k1 = Komplex(10.0);
```

létrejön egy ideiglenes objektum:

```cpp
Komplex(10.0)
```

amelyet hozzárendelsz `k1`-hez.

A sor végén az ideiglenes objektum megszűnik, ezért látod a destruktor futását.

Hasonlóan:

```cpp
k1 = (Komplex)20.0;
```

és

```cpp
k1 = static_cast<Komplex>(30.0);
```

esetén is.

------

### A heap-es rész

```cpp
Komplex* k = new Komplex(100, 50);
```

itt:

1. létrejön egy objektum a heapen,
2. a destruktora nem fut le automatikusan,
3. csak amikor ezt meghívod:

```cpp
delete k;
```

akkor fut le:

```cpp
~Komplex()
```

------

### Összefoglaló

| Kód                                | explicit nélkül | explicit-tel |
| ---------------------------------- | --------------- | ------------ |
| `Komplex k(10.0);`                 | ✔               | ✔            |
| `Komplex k = 10.0;`                | ✔               | ❌            |
| `k1 = 10.0;`                       | ✔               | ❌            |
| `k1 = Komplex(10.0);`              | ✔               | ✔            |
| `k1 = (Komplex)10.0;`              | ✔               | ✔            |
| `k1 = static_cast<Komplex>(10.0);` | ✔               | ✔            |

Az `explicit` tehát csak az **automatikus (implicit) konverziókat tiltja**, a kifejezett konstruktorhívásokat nem. Ezért működik továbbra is:

```cpp
Komplex k2(1.0);
```

de nem működne:

```cpp
Komplex k2 = 1.0;
```

### Mi az a `static_cast`?

A `static_cast` egy C++-os típuskonverziós operátor.

Például:

```cpp
double d = 3.14;
int i = static_cast<int>(d);
```

Itt a `3.14` értékből `3` lesz.

A te példádban:

```cpp
k1 = static_cast<Komplex>(30.0);
```

a fordító ezt lényegében így értelmezi:

```cpp
k1 = Komplex(30.0);
```

Vagyis a `Komplex(double)` konstruktort hívja meg.

------

### Miért jobb, mint a C-stílusú cast?

Ez:

```cpp
k1 = (Komplex)30.0;
```

működik, de a C++ közösség általában a `static_cast`-ot preferálja, mert:

- egyértelműbb,
- könnyebb keresni a kódban,
- a fordító több ellenőrzést végez,
- látszik, hogy tudatos konverzió történik.

------

### Heap memória törlése csak a végén?

Ebben a programban:

```cpp
Komplex* k = new Komplex(100, 50);
```

és később:

```cpp
delete k;
```

a program végén teljesen rendben van.

A lényeg:

```cpp
new  -> foglalsz memóriát
delete -> felszabadítod
```

Amíg szükséged van az objektumra, addig ne töröld.

Amikor már nincs rá szükség, töröld.

------

### Mi történik, ha nem törlöd?

```cpp
Komplex* k = new Komplex(100, 50);

// nincs delete
```

Ekkor memória-szivárgás (*memory leak*) keletkezik.

A program végén az operációs rendszer ugyan visszaveszi a memóriát, de a destruktor nem fut le:

```cpp
~Komplex()
```

nem hívódik meg.

------

### Modern C++ megoldás

Ma általában nem ezt írjuk:

```cpp
Komplex* k = new Komplex(100, 50);
...
delete k;
```

hanem:

```cpp
#include <memory>

auto k = std::make_unique<Komplex>(100, 50);
```

Ekkor nem kell `delete`.

A program automatikusan meghívja a destruktort, amikor a mutató kikerül a hatókörből.

------

### A te példádban

Ez teljesen helyes:

```cpp
Komplex* k = new Komplex(100, 50);

/* használat */

delete k;
```

sőt oktatási célból kifejezetten jó, mert jól látszik:

1. konstruktor fut a `new`-nál,
2. destruktor fut a `delete`-nél.

Így könnyű megérteni a heap memória életciklusát.

Igen, a `static_cast` szó szerint **típuskonverziót** jelent, vagyis egy értéket az egyik típusból egy másik típusúként kezelünk vagy alakítunk át.

Például:

```cpp
double d = 3.14;
int i = static_cast<int>(d);
```

Itt a `double` típusú értékből egy `int` készül:

```text
3.14  →  3
```

------

### A te `Komplex` példádban

Van egy konstruktorod:

```cpp
explicit Komplex(double _dValos)
```

Ez azt mondja:

> "Tudok `double`-ből `Komplex` objektumot létrehozni."

Amikor ezt írod:

```cpp
static_cast<Komplex>(30.0)
```

akkor azt mondod a fordítónak:

> "Vedd a `30.0` double értéket, és alakítsd át `Komplex` objektummá."

A háttérben:

```cpp
Komplex(30.0)
```

jön létre.

------

### Miért kell ez, ha van konstruktor?

Mert nálad a konstruktor `explicit`:

```cpp
explicit Komplex(double _dValos)
```

Ez tiltja az automatikus konverziót:

```cpp
k1 = 30.0; // HIBA
```

Viszont a `static_cast` egy **kifejezett (explicit) kérés**:

```cpp
k1 = static_cast<Komplex>(30.0);
```

Itt te szólsz a fordítónak:

> "Igen, tudom mit csinálok, alakítsd át."

------

### Egy egyszerűbb példa

```cpp
char c = 'A';

int kod = static_cast<int>(c);
```

Eredmény:

```text
kod = 65
```

Mert az `'A'` ASCII kódja 65.

Itt a `char` típusból `int` típus lett.

------

### Összefoglalva

A

```cpp
static_cast<CelTipus>(ertek)
```

jelentése:

> "Készíts ebből az értékből egy `CelTipus` típusú értéket."

Példák:

```cpp
static_cast<int>(3.14)      // double -> int
static_cast<double>(5)      // int -> double
static_cast<Komplex>(30.0)  // double -> Komplex
```

A te programodban tehát a `static_cast<Komplex>(30.0)` nem csinál mást, mint meghívja a:

```cpp
Komplex(double)
```

konstruktort, és létrehoz egy ideiglenes `Komplex` objektumot a `30.0` értékből.