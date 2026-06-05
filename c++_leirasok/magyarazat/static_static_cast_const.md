#### static_static_cast_const

------

Szia Ati!

Ezek a C és C++ egyik legfontosabb kulcsszavai. Megpróbálom egyszerűen elmagyarázni.

# const

A `const` azt jelenti:

**"Ez az érték nem változhat."**

```cpp
const int x = 5;

x = 10; // HIBA
```

Az `x` létrehozás után már nem módosítható.

Használható C-ben és C++-ban is.

Példa:

```c
const float PI = 3.14159;
```

------

# static

A `static` jelentése attól függ, hogy hol használod.

## 1. Lokális változóban

Normál esetben a függvényből kilépve a változó törlődik.

```cpp
void test()
{
    int x = 0;
    x++;
    printf("%d\n", x);
}
```

Kimenet:

```
1
1
1
```

Minden híváskor újra létrejön.

------

Ha static:

```cpp
void test()
{
    static int x = 0;
    x++;
    printf("%d\n", x);
}
```

Kimenet:

```
1
2
3
```

A változó nem törlődik a függvény végén.

------

## 2. Globális változóban

```cpp
static int counter = 0;
```

Ilyenkor csak az adott `.c` vagy `.cpp` fájlból látható.

Más fájl nem fér hozzá.

------

## 3. Osztályban (C++)

```cpp
class Player
{
public:
    static int count;
};
```

A `count` nem az objektumé.

Minden objektum ugyanazt a változót használja.

```cpp
Player::count = 10;
```

------

# static_cast

Ez csak C++-ban létezik.

Típuskonverzióra használjuk.

Példa:

```cpp
int x = 5;

double y = static_cast<double>(x);
```

Eredmény:

```cpp
y = 5.0
```

------

Régi C-stílus:

```cpp
double y = (double)x;
```

Modern C++:

```cpp
double y = static_cast<double>(x);
```

------

Másik példa:

```cpp
double d = 3.9;

int x = static_cast<int>(d);
```

Eredmény:

```cpp
x = 3
```

A tizedes rész levágódik.

------

# const static

A kettő együtt is használható.

Jelentése:

**statikus és nem módosítható.**

Példa C++ osztályban:

```cpp
class Math
{
public:
    static const int MAX = 100;
};
```

A `MAX`:

- minden objektumnál ugyanaz
- nem változtatható

------

Példa függvényben:

```cpp
void test()
{
    static const int x = 5;

    // x = 10; HIBA
}
```

A változó:

- egyszer jön létre
- a program végéig él
- nem módosítható

------

Röviden:

| Kulcsszó       | Jelentés                                         |
| -------------- | ------------------------------------------------ |
| `const`        | Nem változhat                                    |
| `static`       | Megőrzi az értékét vagy közös példányt hoz létre |
| `static_cast`  | Biztonságosabb C++ típuskonverzió                |
| `static const` | Statikus és nem módosítható                      |

Egy mondatban:

- `const` = "csak olvasható"
- `static` = "nem törlődik el, vagy közös"
- `static_cast` = "alakítsd át másik típusra"
- `static const` = "közös és állandó"

Majdnem, de itt két külön dolog keveredik.

Ha van egy osztályod:

```cpp
class Hallgato
{
public:
    const char* nev;
};
```

akkor a `const char*` **nem azt jelenti, hogy a mutató nem változhat**, hanem azt, hogy a mutatott karakterek nem módosíthatók.

```cpp
Hallgato h;

h.nev = "Ati";     // OK
h.nev = "Nova";    // OK
```

Viszont:

```cpp
h.nev[0] = 'B';    // HIBA
```

mert a karakterek const-ok.

Ha azt akarod, hogy maga a mutató se változhasson:

```cpp
char* const nev;
```

vagy

```cpp
const char* const nev;
```

------

A `static const char*` egészen más:

```cpp
class Hallgato
{
public:
    static const char* nev;
};
```

Itt a `nev` nem az objektumé, hanem az osztályé.

Minden objektum ugyanazt használja:

```cpp
Hallgato a;
Hallgato b;

Hallgato::nev = "Ati";
```

Az `a` és `b` ugyanazt a `nev` változót látja.

------

A "csak egyszer fut le" nem a `static const` jelentése, hanem a **lokális static változóé**:

```cpp
void test()
{
    static const int x = 5;

    printf("%d\n", x);
}
```

Az `x` egyszer jön létre.

Ha a függvényt 100-szor meghívod:

```cpp
test();
test();
test();
```

a függvény mindháromszor lefut.

Csak az `x` inicializálása történik meg egyszer.

------

Példa:

```cpp
void test()
{
    static int x = 0;

    x++;

    printf("%d\n", x);
}
```

Kimenet:

```text
1
2
3
```

A függvény minden alkalommal lefutott, csak az `x` nem jött létre újra.

Tehát röviden:

```cpp
const char* nev;
```

→ a szöveg nem módosítható.

```cpp
static const char* nev;
```

→ egy közös mutató minden objektum számára.

```cpp
static int x;
```

egy függvényben
→ egyszer jön létre, de a függvény továbbra is minden híváskor lefut.

```cpp
const char* const nev;
```

→ sem a mutató, sem a szöveg nem változtatható.

**1. Általános melléknévként (jelentése: mozdulatlan, állandó)**
Nyugalmi állapotban lévő, egyensúlyban lévő vagy változatlan dolgokra használjuk. (Pl. *statikus állapot*, ami nem változik az idő múlásával). [[1](https://idegen-szavak.hu/statikus), [2](https://topszotar.hu/idegen-szavak/statikus), [3](https://www.citatum.hu/szotar/statikus)]

**2. Főnévként (építőmérnök / tartószerkezet-tervező)**
Olyan építőmérnök, aki az épületek és hidak tartószerkezeteinek (falak, gerendák, oszlopok, alapozás) stabilitását és teherbírását tervezi, számolja ki