A `const` azt jelenti:

> „nem módosítható”

------

# Egyszerű példa

```cpp
const int x = 5;
```

Ezután:

```cpp
x = 10;
```

hiba lesz.

Mert a `const` védi a változót a módosítástól.

------

# A te példádban

```c
const char* mNev
```

ez azt jelenti:

> „egy karakterláncra mutató pointer,
> de a karaktereket nem módosíthatod”

------

# Mit véd itt?

Ez:

```c
mNev[0] = 'X';
```

❌ hiba lenne.

Mert a `const` azt mondja:

> csak olvasni lehet.

------

# Miért fontos stringeknél?

Amikor ezt írod:

```c
"Nova"
```

az egy string literal.

A literalok általában:

- read-only memóriában vannak
- nem szabad módosítani őket

Ezért:

```c
const char* nev = "Nova";
```

 helyes.

------

#  Régen sokan így írták

```c
char* nev = "Nova";
```

Ez veszélyesebb.

------

#  Pointer + const világ (nagyon fontos C/C++ téma)

## 1.

```c
const char* p;
```

 a karakter NEM módosítható
 pointer mozgatható

------

## 2.

```c
char* const p;
```

 pointer fix
 adat módosítható

------

## 3.

```c
const char* const p;
```

 semmi nem módosítható

------

#  A te eseted

```c
void hallgatoLetrehoz(struct Hallgato* h,
                      const char* mNev)
```

azt jelenti:

 a függvény csak olvassa a nevet
 nem írja át

Ez jó gyakorlat 