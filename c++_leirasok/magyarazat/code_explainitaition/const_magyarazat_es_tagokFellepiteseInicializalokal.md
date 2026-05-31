## const_magyarazat_es_tagokFellepiteseInicializalokal

```cpp
// TagokFelépítéseInicializálókkal
// Ez a program bemutatja mi történik egy inicializálóval
// rendelkező adattag fellépítésekor

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class HallgatoiAzonosito
{
public:
    HallgatoiAzonosito(int azonosito): ertek(azonosito)
    {
        std::cout << "azonositó: " << ertek <<'\n';
    }
protected:
    int ertek;
};
int kovHallgatoiAzonosito = 1000;

class Hallgato
{
public:
    //const = constant (állandó)
    Hallgato(const char* mNev, int kHAzonosito)
        : nev(mNev), azonosito(kHAzonosito)
    {
        std::cout << "A következő hallgató fellépítése: "
                  << mNev <<'\n';
    }
    Hallgato(const char* mNev): nev(mNev)
    {
        std::cout << "A következő hallgató felépítése: " << mNev <<'\n';
    }
protected:
    std::string nev;
    HallgatoiAzonosito azonosito = kovHallgatoiAzonosito++;
};

int main(int argc, char** argv)
{
    //Stack memory (VEREM)
    Hallgato h1("Ati", 12345);
    Hallgato h2("Prüntyi");
    Hallgato h3("Pákító");
    //Heap memory (HALOM)
    Hallgato* hH = new Hallgato("NOVA");
    Hallgato*hH2 = new Hallgato("GEMINI");
    Hallgato* hH3 = new Hallgato("CLAUDE",5);

    delete hH, hH2, hH3;

    //kilépünk
    std::cout << "A folytatáshoz kérlek kétszer nyomd meg az ENTERT..." << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return EXIT_SUCCESS;
}
```

Igen, van ilyen, és a két forma **ugyanazt jelenti**.

## 1. `const char*` és `char const*`

Ez a kettő ekvivalens:

```cpp
const char* mNev;
char const* mNev;
```

Mindkettő azt jelenti:

> "mutató egy konstans char-ra"

Tehát:

```cpp
char const* szoveg = "Hello";

// HIBA
szoveg[0] = 'J';
```

A karaktereket nem módosíthatod.

Viszont a mutató maga átállítható:

```cpp
char const* szoveg = "Hello";
szoveg = "World";   // OK
```

------

## 2. Miért kétféle írásmód?

A `const` mindig a BAL OLDALI dologra vonatkozik.

Ha nincs bal oldalon semmi, akkor a jobb oldalira.

Ezért:

```cpp
const char
```

ugyanaz mint

```cpp
char const
```

Mindkettő:

```text
konstans char
```

------

## 3. Mutatóknál érdekesebb

### konstans adat

```cpp
char const* p;
```

vagy

```cpp
const char* p;
```

Jelentése:

```text
p -> konstans char
```

A karakter nem változhat.

------

### konstans mutató

```cpp
char* const p;
```

Jelentése:

```text
konstans mutató -> char
```

Itt a mutató nem mozgatható:

```cpp
char a = 'A';
char b = 'B';

char* const p = &a;

// HIBA
p = &b;
```

De az adat módosítható:

```cpp
*p = 'Z';
```

------

### mindkettő konstans

```cpp
char const* const p;
```

Jelentése:

```text
konstans mutató -> konstans char
```

Sem a mutató, sem az adat nem változhat.

------

## 4. `const double` és `double const`

Szintén ugyanaz.

```cpp
const double pi = 3.14;
```

=

```cpp
double const pi = 3.14;
```

Mindkettő:

```text
konstans double
```

Példa:

```cpp
double const pi = 3.14;

// HIBA
pi = 5.0;
```

------

## Miért szeretik sokan a `T const` stílust?

Néhány C++ programozó ezt írja:

```cpp
char const* p;
double const pi;
std::string const nev;
```

mert mindig ugyanaz a szabály:

> a `const` a bal oldalán álló dolgot teszi konstanssá

Például:

```cpp
char const* const p;
```

szinte "olvasható":

```text
char const * const p
^^^^          ^
adat const    mutató const
```

Ezért sok veterán C++ fejlesztő a `T const` stílust preferálja.

------

A te konstruktorodban:

```cpp
Hallgato(const char* mNev)
```

a `const` azt jelenti, hogy a függvény **nem módosíthatja** a karakterlánc tartalmát.

Modern C++-ban viszont gyakran inkább ezt írják:

```cpp
Hallgato(const std::string& mNev)
```

vagy akár:

```cpp
Hallgato(std::string_view mNev)
```

mert ezek biztonságosabbak és rugalmasabbak a nyers `char*` használatánál.

Majdnem, de itt keveredik a **mutató** és az **objektum** fogalma.

Először is ezek a példák nem fordulnának le így:

```cpp
const std::string* p = "hello";
std::string* const p = "hello";
```

mert `"hello"` egy string literál, nem `std::string*`.

Vegyünk egy helyes példát:

```cpp
std::string s = "hello";
```

## 1. `const std::string* p = &s;`

Ugyanaz mint:

```cpp
std::string const* p = &s;
```

Jelentése:

```text
p -> konstans std::string
```

A mutató mozgatható:

```cpp
std::string t = "world";

p = &t;      // OK
```

De a stringet nem módosíthatod a mutatón keresztül:

```cpp
p->append("!");   // HIBA
(*p) = "abc";     // HIBA
```

------

## 2. `std::string* const p = &s;`

Jelentése:

```text
konstans mutató -> std::string
```

A mutató nem mozgatható:

```cpp
std::string t = "world";

p = &t;      // HIBA
```

Viszont a string módosítható:

```cpp
p->append("!");
(*p) = "abc";

std::cout << s;   // abc
```

------

## 3. `const std::string* const p = &s;`

Jelentése:

```text
konstans mutató -> konstans string
```

Sem a mutató nem mozgatható:

```cpp
p = &t;      // HIBA
```

Sem a string nem módosítható:

```cpp
p->append("!");   // HIBA
```

------

### Egyszerű memóriaábra

```cpp
std::string s = "hello";
std::string t = "world";
```

#### `const std::string* p`

```text
p ---> s

p átállhat t-re
s nem módosítható p-n keresztül
```

#### `std::string* const p`

```text
p ---> s

p nem állhat át t-re
s módosítható p-n keresztül
```

### Trükk az olvasáshoz

Nézd a `*` környékét:

```cpp
const std::string* p
```

A `const` a stringre vonatkozik.

```cpp
std::string* const p
```

A `const` a mutatóra vonatkozik.

```cpp
const std::string* const p
```

Mindkettő konstans.

Ez az egyik legfontosabb dolog a pointereknél C/C++-ban.

Pontosan. 👍

Amikor ezt írod:

```cpp
const char* nev;
```

vagy ugyanezt:

```cpp
char const* nev;
```

akkor:

- ✅ a mutató (`nev`) átállítható másik címre
- ❌ a mutatón keresztül a karakter nem módosítható

Példa:

```cpp
const char* nev = "Ati";

nev = "Peti";   // OK
```

A mutató most már egy másik szövegre mutat.

Viszont:

```cpp
nev[0] = 'X';   // HIBA
```

mert a `const` a `char`-ra vonatkozik.

------

Érdemes úgy olvasni:

```cpp
const char* nev;
```

↓

```text
nev egy mutató
      ↓
const char-ra
```

------

Ha ezt írod:

```cpp
char* const nev = p;
```

akkor fordítva:

- ❌ a mutató nem változhat
- ✅ a karakter módosítható

------

A mondatodban egy apró pontosítás:

> "a mutató módosítható, de a típus nem"

inkább így fogalmaznám:

> **a mutató módosítható, de az általa mutatott adat nem módosítható ezen a mutatón keresztül**

Mert a "típus" (`char`) természetesen nem változik meg; a kérdés az, hogy az adat módosítható-e.

Például:

```cpp
char tomb[] = "Ati";

const char* nev = tomb;
```

Itt a `tomb` valójában nem konstans, mégis:

```cpp
nev[0] = 'X';   // HIBA
```

mert a `nev` mutató típusa `const char*`.

Viszont:

```cpp
tomb[0] = 'X';  // OK
```

mert maga a tömb nem konstans.

Ez egy fontos különbség: a `const` gyakran nem az objektumot teszi feltétlenül konstanssá, hanem azt szabályozza, hogy **ezen a referencián vagy mutatón keresztül mit szabad csinálni**.

Nagyon jó kérdés. Elsőre tényleg úgy tűnik, hogy:

> "Ha csak olvasni akarom a nevet, miért kell `const char*`?"

A válasz: **a függvény szerződést köt a hívóval**, hogy nem fogja módosítani az adatot.

Például:

```cpp
void kiir(const char* nev)
{
    std::cout << nev << '\n';
}
```

A `const` itt azt jelenti:

> "Ez a függvény csak olvasni fogja a szöveget."

Ha véletlenül ilyet írnál:

```cpp
void kiir(const char* nev)
{
    nev[0] = 'X';
}
```

a fordító hibát ad.

------

## Mi lenne `const` nélkül?

```cpp
void kiir(char* nev)
{
    nev[0] = 'X';
}
```

Most a függvény megváltoztathatja a hívó adatát:

```cpp
char nev[] = "Ati";

kiir(nev);

std::cout << nev;   // Xti
```

------

## String literálok miatt különösen fontos

Ez nagyon gyakori:

```cpp
const char* nev = "Ati";
```

A `"Ati"` string literál.

Ha megengedett lenne:

```cpp
char* nev = "Ati";
```

akkor valaki ezt írhatná:

```cpp
nev[0] = 'X';
```

A string literálok memóriája sok rendszeren írásvédett, így ez akár összeomláshoz (undefined behavior) vezethet.

Ezért a modern C++ gyakorlatilag minden string literált `const char[]`-ként kezel.

------

## A valódi haszon nagy projektekben

Képzeld el, hogy van egy függvény:

```cpp
void feldolgoz(const char* szoveg);
```

Már a függvény fejléce alapján tudod:

```text
✓ nem fogja módosítani
✓ biztonságos átadni neki
✓ csak olvasni akarja
```

Ha ezt látod:

```cpp
void feldolgoz(char* szoveg);
```

akkor nem tudod:

```text
? módosítja?
? átírja?
? törli?
```

------

Ezért mondják sokan:

> A `const` nem csak a fordítónak szól, hanem a programozónak is.

Dokumentálja a szándékot, és a fordító be is tartatja azt. Emiatt a C++-ban általában azt az elvet követik:

```text
Amit nem akarsz módosítani, jelöld const-nak.
```

Így kevesebb hibát lehet elkövetni.

Nem egészen. 😊

Nem a **fordító** akarja módosítani, hanem **te vagy egy másik programozó a kódban** módosíthatná véletlenül.

Például:

```cpp
void kiir(const char* nev)
{
    std::cout << nev << '\n';
}
```

A `const` azt mondja a fordítónak:

> "Ne engedd, hogy ezen a mutatón keresztül bárki módosítsa az adatot."

Ha később valaki ezt írja:

```cpp
void kiir(const char* nev)
{
    nev[0] = 'X';
}
```

akkor a fordító megállítja a hibát.

------

A fordító szerepe itt inkább a "rendőr":

```text
Programozó -> módosítani próbál
Fordító -> "nem, const!"
```

nem pedig az, hogy ő maga módosítaná az adatot.

------

A string literáloknál van még egy ok:

```cpp
const char* nev = "Ati";
```

A `"Ati"` gyakran a program egy csak olvasható memóriaterületén van.

Ha megengednénk:

```cpp
char* nev = "Ati";
nev[0] = 'X';
```

akkor a program akár össze is omolhatna.

Ezért a `const` egyszerre:

- dokumentálja a szándékot ("csak olvasom"),
- megakadályozza a véletlen módosítást,
- védi a csak olvasható memóriában lévő adatokat.

Szóval pontosabban:

> nem azért kell a `const`, mert a fordító módosítaná az adatot, hanem azért, hogy a fordító megakadályozza, hogy a program módosítsa azt.