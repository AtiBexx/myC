#### TípusKonverzió

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