## Debug macro:

Itt nem boolean a lényeg, hanem hogy **compile time ki-be kapcsolható legyen kód**.

Példa:

```
#define DEBUG 1

#if DEBUG
    printf("Debug info\n");
#endif
```

Vagy:

```
#ifdef DEBUG
    printf("Debug info\n");
#endif
```

Ha nincs DEBUG definiálva → a kód **nem is létezik a binaryben**.

Ez fontos:
 → nem runtime if
 → preprocesszor dönt

Ez történik:

```
if(DEBUG)
```

≠

```
#ifdef DEBUG
```

Az első runtime.
 A második compile time.

------

## Compile flags mire jók?

Példa:

Windows vs Linux:

```
#ifdef _WIN32
    printf("Windows\n");
#else
    printf("Linux\n");
#endif
```

Compiler automatikusan definiál:

- _WIN32
- **linux**
- **GNUC**

------

## Boolean rész:

Igen, sok macro 0 vagy 1:

```
#define FEATURE_ENABLED 1

#if FEATURE_ENABLED
    code
#endif
```

Ez preprocesszorban számként működik.

------

## A 4 leggyakoribb macro use:

### 1 Debug:

```
#ifdef DEBUG
printf("x = %d\n", x);
#endif
```

------

### 2 Feature toggle:

```
#define USE_FAST_MATH 1
```

------

### 3 Platform:

```
#ifdef _WIN32
#endif
```

------

### 4 Header guard:

```
#ifndef MYFILE_H
#define MYFILE_H

code

#endif
```

------

## Ami miatt igazán használják:

Ez a kedvenc:

```
#define LOG(x) printf("LOG: %s\n", x)
```

vagy:

```
#define LOG(x) std::cout << x << std::endl;
```

És debug buildben:

```
#define LOG(x) printf(x)
```

Release buildben:

```
#define LOG(x)
```

Ez **eltünteti a logot teljesen**.

Ez profi technika.

------

## Amit jól látsz:

Te már preprocesszor logikát kezded érteni. Ez már **low level programozás**.

------

## Egy nagyon fontos C interjú kérdés:

Mi a különbség:

```
#define SQUARE(x) x*x
```

és

```
inline int square(int x)
```