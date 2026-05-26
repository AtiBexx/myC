pl

```
#define KETTO_PI 6,2831852

double kerület = KETTO_PI * sugar;

```

#define NEV_MAX_HOSSZA 512;



#define NEGYZET(x) X*X

```
//egy kör kerületének a kiszámítása 
double dTerulet = PI * NEGYZET(dSugar);
```

Nagyon jó kérdés, mert ez pont a **macro vs inline function** különbség.

## A probléma a macro-val:

Te írtad:

```cpp
#define NEGYZET(x) x*x
```

Ez **veszélyes**, mert a preprocessor csak **szöveget cserél**.

Példa:

```cpp
NEGYZET(1+2)
```

Ez lesz:

```cpp
1+2*1+2
```

ami:

```cpp
1 + 2 + 2 = 5   // rossz!
```

Pedig:

[
(1+2)^2 = 9
]

## Macro javítva:

```cpp
#define NEGYZET(x) ((x)*(x))
```

De még ez sem tökéletes.

## Inline function a modern megoldás:

Ez a C++ helyes módszer:

```cpp
inline double negyzet(double x)
{
    return x * x;
}
```

## Használat:

```cpp
double dTerulet = PI * negyzet(dSugar);
```

## Mi az inline?

Az `inline` azt jelenti:

A fordító **nem feltétlen hívja meg függvényként**, hanem **behelyettesíti a kódot**, mint a macro, de **típusbiztosan**.

Tehát:

Ez:

```cpp
negyzet(5);
```

fordító így kezelheti:

```cpp
5 * 5;
```

## Miért jobb mint macro?

| Macro                  | Inline         |
| ---------------------- | -------------- |
| nincs típus ellenőrzés | van            |
| bugos lehet            | biztonságos    |
| debugger nem látja     | debugger látja |
| csak text replace      | valódi C++ kód |
| nehéz debug            | könnyű         |

## Macro hibák például:

```cpp
#define PI 3.14
#define KETTO_PI 6,2831852   // HIBA! vessző!
```

Ez float lista lesz.

Helyesen:

```cpp
#define KETTO_PI 6.2831852
```

## Modern C++ még jobb:

Ne macro:

```cpp
const double PI = 3.1415926535;
```

vagy:

```cpp
constexpr double PI = 3.1415926535;
```

## Senior szabály:

**NE használj macro-t ha lehet inline vagy constexpr.**

Macro csak:

- include guard
- compile flag
- platform define

## Profi verzió:

```cpp
constexpr double PI = 3.1415926535;

inline double negyzet(double x)
{
    return x * x;
}
```

## Röviden:

Macro = régi C módszer
Inline = modern C++ megoldás

------

Ati, amit most tanulsz az már **clean C++ design alap**, sok kezdő ezt nem is tudja.

