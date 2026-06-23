Jó kérdések. Menjünk sorban.

## 1. Mit jelent ez?

```cpp
return n<=1 ? n : fib(n-2) + fib(n-1);
```

Ez a `? :` operátor (ternary operator).

Ugyanaz, mint:

```cpp
if (n <= 1)
    return n;
else
    return fib(n-2) + fib(n-1);
```

Magyarul:

- ha `n` 0 vagy 1 → add vissza magát
- különben számold ki a két előző Fibonacci-számot és add össze

Például:

```cpp
fib(4)
```

=

```text
fib(3) + fib(2)
```

=

```text
(fib(2)+fib(1)) + (fib(1)+fib(0))
```

=

```text
(1+1) + (1+0)
```

=

```text
3
```

------

## 2. Mi történik a ciklusos verzióban?

```cpp
long long a = 0;
long long b = 1;
```

Kezdetben:

```text
a = 0
b = 1
```

Ez a Fibonacci-sor első két eleme.

------

### Első kör

```cpp
long long c = a + b;
c = 0 + 1 = 1
```

Most:

```text
a = 0
b = 1
c = 1
```

------

```cpp
a = b;
a = 1
```

------

```cpp
b = c;
b = 1
```

Most:

```text
a = 1
b = 1
```

Ez már a következő két Fibonacci-szám.

------

### Második kör

```cpp
c = a + b;
c = 1 + 1 = 2
```

utána:

```text
a = 1
b = 2
```

------

### Harmadik kör

```text
c = 1 + 2 = 3
a = 2
b = 3
```

------

### Negyedik kör

```text
c = 2 + 3 = 5
a = 3
b = 5
```

Látod?

Mindig az utolsó két Fibonacci-számot tartjuk nyilván.

Ezért gyors.

------

## 3. Miért tűnik úgy, hogy a rekurzió "végtelent generál"?

Mert minden hívás kettőt csinál:

```cpp
fib(10)
```

hívja:

```cpp
fib(9)
fib(8)
```

A `fib(9)` hívja:

```cpp
fib(8)
fib(7)
```

A `fib(8)` hívja:

```cpp
fib(7)
fib(6)
```

stb.

Fa alakban:

```text
fib(5)
├─ fib(4)
│  ├─ fib(3)
│  └─ fib(2)
└─ fib(3)
   ├─ fib(2)
   └─ fib(1)
```

A `fib(3)` és `fib(2)` többször is kiszámolódik.

Ezért lassul be.

------

## 4. Használják a Fibonacci-sort népességnövekedésre?

Történelmileg igen.

A Fibonacci-sor eredetileg egy nyúltenyésztési feladatból származik, amelyet Leonardo Fibonacci írt le.

Az elképzelés:

- van egy nyúlpár
- minden hónapban szaporodik
- a kölykök később szintén szaporodnak

Ebből jött ki a Fibonacci-sor.

Viszont a valódi népességek nem így működnek.

Valódi népességeknél figyelembe kell venni:

- halálozást
- élelmiszerhiányt
- betegségeket
- migrációt

Ezért a demográfusok más modelleket használnak.

------

## 5. Használják a gazdaságban és a bankoknál?

Közvetlenül általában nem.

A gazdasági növekedést inkább ilyenekkel modellezik:

- kamatos kamat
- exponenciális növekedés
- statisztikai modellek
- idősorelemzés

Például egy bankbetét:

```text
1000 Ft
1100 Ft
1210 Ft
1331 Ft
...
```

Ez nem Fibonacci, hanem kamatos kamat.

------

## 6. Akkor miért hallani a Fibonacci-ról a tőzsdén?

Mert sok kereskedő használ úgynevezett Fibonacci-szinteket.

Ilyenek:

```text
23.6%
38.2%
50%
61.8%
78.6%
```

Különösen a:

```text
61.8%
```

az úgynevezett aranymetszéshez kapcsolódik.

Egyes kereskedők azt figyelik, hogy az árfolyam visszahúzódik-e ezekhez a szintekhez.

Viszont:

- sok trader használja
- sok trader nem hisz benne
- nem a bankrendszer alapja
- nem a gazdaság növekedésének hivatalos modellje

Tehát a Fibonacci nagyon fontos matematikai sorozat, de a modern gazdaságot és népességet nem ezzel számolják. Inkább oktatási, algoritmikus és bizonyos pénzügyi elemzési területeken találkozol vele.