Kezdjük a Fibonacci-val, mert az egyszerűbb.

## Miért `fib(n-1)` és `fib(n-2)`?

A Fibonacci definíciója:

```text
F(n) = F(n-1) + F(n-2)
```

Ez azt mondja:

> az n-edik Fibonacci-szám az előző kettő összege.

Például:

```text
F(6) = F(5) + F(4)
     = 5 + 3
     = 8
```

Ezért van a kódban:

```cpp
return fib(n-1) + fib(n-2);
```

A `-1` és `-2` nem véletlen számok, hanem az **előző két elem indexei**.

------

## Népességnövekedésre mit használnak?

Gyakran az exponenciális növekedés képletét:

```text
N(t) = N0 × (1 + r)^t
```

ahol:

- `N0` = kezdeti népesség
- `r` = növekedési ráta
- `t` = idő

Példa:

```text
1000 ember
évente 2% növekedés
```

10 év múlva:

```text
1000 × (1.02)^10 ≈ 1219
```

C++:

```cpp
#include <cmath>

double nepesseg(double kezdo, double rata, int ev)
{
    return kezdo * pow(1.0 + rata, ev);
}
```

------

## Ha a népesség csökken?

Ugyanaz a képlet, csak negatív ráta:

```text
N(t) = N0 × (1 - r)^t
```

Példa:

```text
1000 fő
évente 3% fogyás
1000 × (0.97)^10 ≈ 737
```

------

## Valódi népességmodellek

A valóságban nem nőhet örökké egy népesség.

Ezért használják a logisztikus modellt:

```text
P(t) = K / (1 + A·e^(-rt))
```

ahol:

- `K` = maximális eltartható népesség
- `r` = növekedési sebesség

Ez először gyorsan nő, aztán lassul.

------

## Gazdasági növekedés

GDP-nél gyakran egyszerű százalékos növekedést használnak:

```text
GDPjövő = GDPmost × (1 + r)^t
```

Példa:

```text
100 milliárd
évi 5%
100 × (1.05)^10
≈ 162.9 milliárd
```

------

## Bankok

Bankbetétnél a klasszikus képlet:

```text
A = P(1 + r/n)^(nt)
```

ahol:

- `P` = induló pénz
- `r` = éves kamat
- `n` = évente hányszor írják jóvá
- `t` = évek száma

Ez a kamatos kamat.

------

## Röviden

- Fibonacci: az előző **két elem összege**, ezért van `n-1` és `n-2`.
- Népességnövekedés: általában exponenciális vagy logisztikus modell.
- Gazdasági növekedés: többnyire százalékos (kamatos kamathoz hasonló) modellek.
- Bankok: kamatos kamat képlete.
- A Fibonacci-sorozatot általában **nem** használják hivatalos népesség- vagy GDP-előrejelzésekhez. Inkább matematikai és algoritmikai példa, illetve bizonyos pénzügyi elemzésekben jelenik meg.

Pontosan! 👍 Ez egy nagyon gyakori félreértés az elején.

Amikor ezt látod:

```cpp
fib(n-1) + fib(n-2)
```

akkor a `-1` és `-2` **nem a végeredményből vonódik ki**.

Hanem azt jelenti:

```cpp
fib(5)
```

számításakor hívd meg:

```cpp
fib(4) + fib(3)
```

Mert:

```text
n-1 = 5-1 = 4
n-2 = 5-2 = 3
```

Tehát a függvény paraméterét csökkentjük, hogy az előző Fibonacci-számokat kérjük le.

Példa:

```cpp
fib(6)
```

=

```cpp
fib(5) + fib(4)
```

=

```cpp
5 + 3
```

=

```cpp
8
```

A végén **összeadás történik**:

```cpp
fib(n-1) + fib(n-2)
```

A kivonás csak arra szolgál, hogy visszalépjünk a sorozat korábbi elemeihez.

Képzeld el a Fibonacci-sort indexekkel:

```text
Index:  0  1  2  3  4  5  6
Érték:  0  1  1  2  3  5  8
```

Ha a 6. elemet akarod:

```text
F(6) = F(5) + F(4)
     = 5 + 3
     = 8
```

Ezért kell az indexből (`n`) visszalépni 1-et és 2-t.

A rekurzió lényege itt az, hogy a függvény saját magát hívja egyre kisebb `n`-ekkel:

```text
fib(6)
→ fib(5) + fib(4)

fib(5)
→ fib(4) + fib(3)

fib(4)
→ fib(3) + fib(2)

...
```

és amikor eljut:

```cpp
fib(1)
fib(0)
```

értékekhez, akkor megáll, mert:

```cpp
if (n <= 1)
    return n;
```

Ezek az úgynevezett **alapesetek** (base case-ek), amelyek megakadályozzák a végtelen rekurziót.

Persze. Ezek egyszerű oktatási példák, hogy lásd a logikát.

## 1. Népességnövekedés

Tegyük fel:

- kezdeti népesség: 1000 fő
- éves növekedés: 2%
- 10 év

```cpp
#include <iostream>
#include <cmath>

int main()
{
    double kezdo = 1000;
    double rata = 0.02; // 2%
    int ev = 10;

    double nepesseg = kezdo * pow(1 + rata, ev);

    std::cout << "Nepesseg: " << nepesseg << '\n';
}
```

------

## 2. Népességcsökkenés

Például:

- 1000 fő
- évente 3%-kal fogy

```cpp
#include <iostream>
#include <cmath>

int main()
{
    double kezdo = 1000;
    double rata = 0.03; // 3%
    int ev = 10;

    double nepesseg = kezdo * pow(1 - rata, ev);

    std::cout << "Nepesseg: " << nepesseg << '\n';
}
```

------

## 3. Gazdasági növekedés (GDP)

Például:

- GDP = 100 milliárd
- évente 5% növekedés

```cpp
#include <iostream>
#include <cmath>

int main()
{
    double gdp = 100.0;
    double novekedes = 0.05;
    int ev = 10;

    double ujGDP = gdp * pow(1 + novekedes, ev);

    std::cout << "GDP: " << ujGDP << '\n';
}
```

------

## 4. Gazdasági visszaesés

Például:

- GDP = 100 milliárd
- évente 2% csökkenés

```cpp
#include <iostream>
#include <cmath>

int main()
{
    double gdp = 100.0;
    double csokkenes = 0.02;
    int ev = 10;

    double ujGDP = gdp * pow(1 - csokkenes, ev);

    std::cout << "GDP: " << ujGDP << '\n';
}
```

------

## 5. Ciklusos verzió (ez közelebb áll a programozói gondolkodáshoz)

Évente számoljuk ki:

```cpp
#include <iostream>

int main()
{
    double nepesseg = 1000;
    double rata = 0.02;

    for(int ev = 1; ev <= 10; ++ev)
    {
        nepesseg = nepesseg * (1 + rata);

        std::cout
            << ev
            << ". ev: "
            << nepesseg
            << '\n';
    }
}
```

Kimenet:

```text
1. ev: 1020
2. ev: 1040.4
3. ev: 1061.21
...
```

------

## Miért ezeket használják?

Mert a valóságban a népesség, a GDP és a bankbetétek általában **százalékosan változnak**.

Például:

```text
1000 → +2% → 1020
1020 → +2% → 1040.4
1040.4 → +2% → 1061.208
```

Ezért itt nem Fibonacci kell, hanem a kamatos kamathoz hasonló képlet:

```text
új_érték = régi_érték × (1 + ráta)
```

Ez a gazdaságban, demográfiában és pénzügyekben sokkal gyakoribb modell, mint a Fibonacci-sorozat.

Ha azt szeretnéd, hogy **csak a kezdő értéket add meg**, akkor valamilyen növekedési rátát fel kell tételezni. Például legyen automatikusan 2% évente népességnél és 3% GDP-nél.

## Népesség (csak a kezdő népességet adod meg)

```cpp
#include <iostream>

int main()
{
    double nepesseg;
    std::cout << "Kezdo nepesseg: ";
    std::cin >> nepesseg;

    const double rata = 0.02; // 2% novekedes

    for (int ev = 1; ev <= 10; ++ev)
    {
        nepesseg *= (1 + rata);

        std::cout
            << ev
            << ". ev: "
            << nepesseg
            << '\n';
    }
}
```

Példa:

```text
Kezdo nepesseg: 1000

1. ev: 1020
2. ev: 1040.4
3. ev: 1061.21
...
```

------

## Gazdaság / GDP (csak a kezdő GDP-t adod meg)

```cpp
#include <iostream>

int main()
{
    double gdp;
    std::cout << "Kezdo GDP: ";
    std::cin >> gdp;

    const double rata = 0.03; // 3% novekedes

    for (int ev = 1; ev <= 10; ++ev)
    {
        gdp *= (1 + rata);

        std::cout
            << ev
            << ". ev GDP: "
            << gdp
            << '\n';
    }
}
```

------

## Még jobb: a felhasználó adja meg a százalékot is

```cpp
#include <iostream>

int main()
{
    double ertek;
    double szazalek;
    int ev;

    std::cout << "Kezdo ertek: ";
    std::cin >> ertek;

    std::cout << "Eves valtozas (%): ";
    std::cin >> szazalek;

    std::cout << "Hany ev?: ";
    std::cin >> ev;

    double rata = szazalek / 100.0;

    for (int i = 1; i <= ev; ++i)
    {
        ertek *= (1 + rata);

        std::cout
            << i
            << ". ev: "
            << ertek
            << '\n';
    }
}
```

Itt:

- `2` → évi +2%
- `5` → évi +5%
- `-3` → évi -3% (csökkenés)

Tehát ugyanaz a program kezeli a növekedést és a csökkenést is.