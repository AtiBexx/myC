Igen van 🙂 de attól függ **mit értesz nagyobb alatt**.

## 1. Beépített típusok (standard C++)

Ezek vannak:

| Típus              | Méret         | Max érték      |
| ------------------ | ------------- | -------------- |
| int                | 4 byte        | ~2 milliárd    |
| long               | 4 vagy 8 byte | platform függő |
| long long          | 8 byte        | **9.22×10¹⁸**  |
| unsigned long long | 8 byte        | **1.84×10¹⁹**  |

Ez a **legnagyobb standard integer típus**.

Tehát:

```text
unsigned long long  ← maximum built-in
```

## 2. Van nagyobb? Igen, de nem alapból.

### GCC extension:

Linuxon:

```cpp
__int128
unsigned __int128
```

Példa:

```cpp
__int128 x = 10000000000000000000;
```

De:

- Windows MSVC nem támogatja
- nem portable

## 3. Profi megoldás (amit matematikai programok használnak)

### Boost multiprecision (végtelen nagy szám):

```cpp
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

cpp_int x = 1;

for(int i=1;i<=100;i++){
    x *= i;
}

cout << x << endl;
```

Ez tud:

```text
100!
500!
1000!
10000!
```

## 4. Régi C módszer (nagyon érdekes 😄)

String alapú számolás:

```text
12345678901234567890
×                25
--------------------
308641972530864197250
```

Karakterenként számol.

Így csinálták:

- Turbo C
- DOS math tools
- régi scientific programok

## 5. Ami fontos:

Nem a típus a limit, hanem a **RAM**.

Példa:

```text
100!   → 158 digit
1000!  → 2568 digit
10000! → 35660 digit
```

## 6. Amit a legtöbb C++ tanuló nem tud:

A factorial gyorsan nő:

```text
20!  = 19 digit
50!  = 65 digit
100! = 158 digit
```

Ezért overflow gyorsan jön.

## 7. Ha tanulni akarsz (nagyon jó feladat)

Írhatunk **saját big integer factorialt** Boost nélkül.

Ez egy klasszikus C++ tanuló projekt:

vector + manual multiply:

```cpp
vector<int> digits;
```

Ez már kb **intermediate C++**.

## Ha akarod csinálhatunk egy igazi "végtelen faktoriális" programot 😄

Ami tud:

```text
fact 1000
fact 5000
fact 10000
```

És nem használ libraryt (nagyon jó pointer/vector gyakorlás).

Ez tipikusan az a feladat amitől hirtelen sokat fejlődik az ember C++-ban.