# Macrók mi mire való?

# #define

**Konstans vagy macro definiálása**

```
#define PI 3.14
#define SQUARE(x) ((x)*(x))
```

Ez csak szövegcsere.

PI → 3.14

------

# #ifdef

**Ha létezik a definíció**

```
#define DEBUG

#ifdef DEBUG
printf("Debug mode");
#endif
```

Jelentése:

Ha DEBUG létezik → kód bekerül.

------

# #ifndef

**Ha NEM létezik a definíció**

```
#ifndef DEBUG
printf("Release mode");
#endif
```

Jelentése:

Ha DEBUG nincs → kód bekerül.

------

# #if

**Feltétel vizsgálat**

```
#define VERSION 2

#if VERSION == 2
printf("Version 2");
#endif
```

Ez számot vizsgál.

------

# #else

**Különben**

```
#ifdef DEBUG
printf("Debug");
#else
printf("Release");
#endif
```

------

# #endif

**Blokk lezárása**

Mindig kell:

```
#ifdef DEBUG

code

#endif
```

------

# Klasszikus példa (header guard):

```
#ifndef MYFILE_H
#define MYFILE_H

int square(int x);

#endif
```

Ez megakadályozza hogy többször include legyen.

------

# Egyszerű logika:

| Direktíva | Jelentés         |
| --------- | ---------------- |
| #define   | definíció        |
| #ifdef    | ha létezik       |
| #ifndef   | ha nem létezik   |
| #if       | ha feltétel igaz |
| #else     | különben         |
| #endif    | lezárás          |

------

# Így gondolkodj:

```
#ifdef DEBUG
```

= ha definiált

```
#ifndef DEBUG
```

= ha nincs definiálva

------

# Fontos:

Ez NEM C kód:

Ez preprocesszor.

Ez:

```
#ifdef DEBUG
```

nem ugyanaz mint:

```
if(DEBUG)
```

------

# Extra (amit kevesen tudnak):

Ez is létezik:

```
#elif
```

példa:

```
#if VERSION == 1
code
#elif VERSION == 2
code
#else
code
#endif
```