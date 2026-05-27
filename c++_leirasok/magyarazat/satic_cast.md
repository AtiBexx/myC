A típuskonverzió azt jelenti:

> egy adatot átalakítasz másik adattípussá.

------

#  Egyszerű példa

C++

```cpp
double x = 5.8;
```

de te `int`-et akarsz:

```cpp
int y = x;
```

Itt történik konverzió:

```cpp
5.8 -> 5
```

------

#  Automatikus konverzió

```cpp
int x = 5;
double y = x;
```

 compiler automatikusan:

```cpp
5 -> 5.0
```

------

#  `static_cast`

A `static_cast` azt jelenti:

> „explicit módon alakítsd át erre a típusra”

------

# Példa

```cpp
double x = 5.8;

int y = static_cast<int>(x);
```

 eredmény:

```cpp
y = 5
```

------

#  Miért jó?

Mert egyértelműen látod:

```cpp
itt tudatos konverzió történik
```

------

#  Régi C-style cast

Régen:

```cpp
int y = (int)x;
```

Modern C++ inkább:

```cpp
int y = static_cast<int>(x);
```

------

#  Mire használják?

## float -> int

```cpp
int a = static_cast<int>(3.9);
```

------

## int -> float

```cpp
float b = static_cast<float>(5);
```

------

## char -> int (ASCII)

```cpp
char c = 'A';

int x = static_cast<int>(c);
```

👉 `65`

------

#  Pointer példa

```cpp
Base* b = new Derived;

Derived* d = static_cast<Derived*>(b);
```

👉 pointer típust alakítasz át.

------

#  Fontos

A `static_cast`:

- compile-time cast
- gyors
- nincs runtime ellenőrzés

------

#  Röviden

| dolog         | jelentés               |
| ------------- | ---------------------- |
| konverzió     | egyik típus → másik    |
| `static_cast` | explicit C++ konverzió |

------

#  Egyszerű példa fejben

```cpp
double -> int
```

olyan mint:

> „vágd le a tizedes részt” 

Nem, az első teljesen jó 
Sőt, ott nem is kell `static_cast`.

Ez:

```cpp
int x = 5;
double z = x;
```

teljesen helyes.

A compiler automatikusan konvertál:

```cpp
5 -> 5.0
```

Mert az `int -> double` biztonságos konverzió.

------

#  A te példádban hiba van

Ez:

```cpp
double z = static_cast<int> x
```

szintaktikailag hibás.

A helyes forma:

```cpp
double z = static_cast<double>(x);
```

------

# Mikor kell `static_cast`?

Amikor:

- explicit akarod jelezni
- veszélyesebb konverzió van
- pontosabb kontroll kell

------

#  Példa ahol hasznos

```cpp
double x = 5.8;

int y = static_cast<int>(x);
```

Itt:

```cpp
5.8 -> 5
```

adatvesztés történik.

Ezért jó, ha látszik a cast.

------

#  Egyszerű szabály

## Automatikus konverzió OK:

```cpp
int -> double
char -> int
```

------

## Explicit cast ajánlott:

```cpp
double -> int
pointer cast
```

------

#  Röviden

 Ez jó:

```cpp
int x = 5;
double z = x;
```

 Ez is jó:

```cpp
double z = static_cast<double>(x);
```

 Ez hibás:

```cpp
static_cast<int> x
```

mert kell:

```cpp
static_cast<int>(x)
```