# Faktoriális

A **faktoriális** egy matematikai művelet, ami egy számnál azt jelenti, hogy **az összes nála kisebb pozitív egész számmal összeszorzod.**

Jele:
**!**

### Példa:

```
5! = 5 × 4 × 3 × 2 × 1 = 120
4! = 4 × 3 × 2 × 1 = 24
3! = 3 × 2 × 1 = 6
```

### Speciális eset:

```
0! = 1
```

Ez definíció szerint 1.

------

# Negatív szám lehet?

**Normál faktoriálisnál: NEM.**

Mert:

```
(-3)! = ?
```

Nem tudod folytatni:

```
-3 × -4 × -5 ...
```

Ez matematikailag nincs definiálva az egyszerű faktoriálisnál.

------

# Pontos szabály:

A sima faktoriális csak:

**0,1,2,3,4... (nem negatív egész számokra)**

------

# Van kivétel (haladó matek):

Van egy függvény:

**Gamma függvény**

Ez kiterjeszti a faktoriálist törtekre:
pl:

```
(0.5)! létezik ott
```

De:
**negatív egész számokra ott sem.**

Ez már egyetemi matek.

------

# Programozásban ezért:

Ha faktoriálist írsz C++-ban:

Mindig ellenőrzöd:

```cpp
if(n < 0)
{
    std::cout << "Negativ szam nem lehet";
}
```

------

# Érdekesség:

Faktoriális gyorsan nő:

| n    | n!                        |
| ---- | ------------------------- |
| 5    | 120                       |
| 10   | 3 628 800                 |
| 15   | 1 307 674 368 000         |
| 20   | 2 432 902 008 176 640 000 |

Ezért C++-ban hamar overflow lesz.

------

# Röviden:

**Faktoriális = pozitív egész számok szorzata.
Negatív számra nincs értelmezve.**

------

1. **kód**

```
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert> //assert() -hez kell
#include <limits>

typedef unsigned long long int Number; //a typedefel a rövidítéseket tudunk megadni

//prottype declartions
unsigned long long factorial(Number n);

int main(int argc, char* argv[]) 
{
    std::cout << "====FAKTORIÁLIS SZÁMÍTÓ====\n";
    std::cout <<"Fordítva: " <<__DATE__ <<" " <<__TIME__ <<"\n" <<std::endl;

    Number n;
    std::cout << "Kérlek adj meg egy pozítiv számot: ";
    std::cin >> n;
    assert(n > 0); //ha negatív a program leáll
    unsigned long long result = factorial(n);
    std::cout << n << "! = " << result << std::endl;

    std::cout << "A kilépéshez használd az ENTER-t" <<std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
  
}
//Faktoriális függvény
unsigned long long factorial(Number n)
{
unsigned long long fact = 1;
for (int i = 1; i <= n; i++)
{
    fact *= i;
}
return fact;
}
```

**output**

```
Kérlek adj meg egy pozítiv számot: 2
2! = 2
A kilépéshez használd az ENTER-t


e:\projects\vscode\factoriál>factorial.exe
====FAKTORIÁLIS SZÁMÍTÓ====
Fordítva: Mar 16 2026 01:52:41

Kérlek adj meg egy pozítiv számot: 5
5! = 120
A kilépéshez használd az ENTER-t


e:\projects\vscode\factoriál>factorial.exe
====FAKTORIÁLIS SZÁMÍTÓ====
Fordítva: Mar 16 2026 01:52:41

Kérlek adj meg egy pozítiv számot: 3
3! = 6
A kilépéshez használd az ENTER-t


e:\projects\vscode\factoriál>factorial.exe
====FAKTORIÁLIS SZÁMÍTÓ====
Fordítva: Mar 16 2026 01:52:41

Kérlek adj meg egy pozítiv számot: -9
18446744073709551607! = 0
A kilépéshez használd az ENTER-t**
```

vagy

```
#include <iostream>
#include <cassert>    // assert()-hez
using namespace std;

// ── Rekurzív faktoriális ──────────────────────────
long long faktorialis(int N) {
    assert(N >= 0);   // negatív szám esetén leállít

    if (N == 0 || N == 1)
        return 1;

    return N * faktorialis(N - 1);
}

// ── Iteratív faktoriális (ciklussal) ─────────────
long long faktorialis_iter(int N) {
    assert(N >= 0);

    long long eredmeny = 1;
    for (int i = 2; i <= N; ++i)
        eredmeny *= i;

    return eredmeny;
}

int main() {
    cout << "=== Faktoriális számító ===" << endl;
    cout << "Fordítva: " << __DATE__ << " " << __TIME__ << endl;
    cout << endl;

    // Táblázat 0!-tól 12!-ig
    cout << "N\t Rekurzív\t Iteratív" << endl;
    cout << "---\t----------\t---------" << endl;

    for (int i = 0; i <= 12; ++i) {
        cout << i << "!\t "
             << faktorialis(i)      << "\t\t "
             << faktorialis_iter(i) << endl;
    }

    cout << endl;

    // Egyedi bekérés a felhasználótól
    int szam;
    cout << "Adj meg egy számot (0-20): ";
    cin >> szam;
    cin.ignore();   // '\n' eltávolítása a bufferből

    if (szam < 0 || szam > 20) {
        cout << "Érvénytelen szám! (0-20 között kell lennie)" << endl;
    } else {
        cout << szam << "! = " << faktorialis(szam) << endl;
    }

    cout << endl;
    cout << "A kilépéshez kérlek nyomd meg az Entert..." << endl;
    cin.get();
    return EXIT_SUCCESS;
}
```

vagy 

```
#include <iostream>
#include <cassert>
using namespace std;

// ── Fordítási idejű ellenőrzések ─────────────────
#if !defined(__cplusplus)
#error Csak C++ fordítoval fordithato!
#endif
#if __cplusplus < 201103L
#error Legalabb C++11 szukseges!
#endif

static_assert(sizeof(int) == 4, "int = 4 bajt kell!");
static_assert(__cplusplus >= 201103L, "C++11+ kell!");

// ── Konstansok constexpr-rel ──────────────────────
constexpr int MAX_N = 20;
static_assert(MAX_N > 0, "MAX_N pozitiv legyen!");

// ── enum class a visszatérési státuszhoz ──────────
enum class Status { OK = 0, HIBA = 1 };

// ── Faktoriális assert-tel védve ──────────────────
long long faktorial(int N) {
    assert(N >= 0);
    assert(N <= MAX_N);
    if (N <= 1) return 1;
    return N * faktorial(N - 1);
}

// ── Debug log makró: FILE + LINE + func együtt ────
#define DLOG(msg) \
    cout << "[LOG][" << __func__ << "][" \
         << __FILE__ << ":" << __LINE__ << "] " \
         << msg << endl

int main() {
    cout << "╔══════════════════════════════════════╗" << endl;
    cout << "║  Összefoglaló C++ program            ║" << endl;
    cout << "║  Build: " << __DATE__ << " " << __TIME__ << "  ║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;
    cout << endl;

    // Belső makrók kiírása
    cout << "Fájl:      " << __FILE__    << endl;
    cout << "Függvény:  " << __func__    << endl;
    cout << "C++ verzió:" << __cplusplus << endl;
    cout << endl;

    DLOG("Program indul");

    // Faktoriális táblázat
    cout << "N\t N!" << endl;
    for (int i = 0; i <= 10; ++i)
        cout << i << "!\t= " << faktorial(i) << endl;

    cout << endl;
    int szam;
    cout << "Adj meg egy számot (0-20): ";
    cin >> szam; cin.ignore();

    if (szam < 0 || szam > MAX_N) {
        DLOG("Érvénytelen bemenet!");
        cout << "Hiba: 0 és 20 közé essen!" << endl;
    } else {
        cout << szam << "! = " << faktorial(szam) << endl;
        DLOG("Számítás kész");
    }

    cout << endl;
    cout << "A kilépéshez kérlek nyomd meg az Entert..." << endl;
    cin.get();
    return EXIT_SUCCESS;
}
```







```
n!=n⋅(n−1)! a factoriális képlet
```

