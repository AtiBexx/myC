Nem 🙂
Ez hibás lenne:

```cpp
char** str = "valami";
```

mert:

```cpp
"valami"
```

típusa:

```cpp
const char*
```

NEM `char**`.

------

Nézzük külön:

## 1. Ez egy C-string

```cpp
const char* str = "valami";
```

vagy régebbi stílusban:

```cpp
char* str = "valami";
```

(de ez modern C++-ban rossz/veszélyes)

------

## 2. Ez karaktertömb

```cpp
char str[] = "valami";
```

Itt valódi tömb jön létre:

```text
v a l a m i \0
```

Ez módosítható:

```cpp
str[0] = 'K';
```

------

## 3. Ez pointertömb

```cpp
char* str[]
```

jelentése:

```cpp
char* str[] = {"egy", "ketto"};
```

Tehát:

- tömb
- amiben char pointerek vannak

Kb:

```text
str[0] ---> "egy"
str[1] ---> "ketto"
```

------

## 4. Mi a `char**`?

Az:

> pointer egy `char*` pointerre

Példa:

```cpp
char* szoveg = nullptr;
char** ptr = &szoveg;
```

Ez már dupla pointer.

Gyakori:

- `argv`
- dinamikus stringtömbök
- C API-k

Például:

```cpp
int main(int argc, char** argv)
```

Itt:

- `argv`
  → pointer pointerre
  → sok stringet tartalmaz.

Kb:

```text
argv[0] -> "program"
argv[1] -> "file.txt"
```

Majdnem 🙂
De itt keveredik a `char[]` és a `char*[]`.

Ez:

```cpp
char* str[]
```

NEM karaktertömb,
hanem pointertömb.

Te most karaktertömböt akarsz:

```cpp
char str[] = {'v','a','l','a','m','i','\0'};
```

Igen, ide kell a null terminátor:

```cpp
'\0'
```

mert a C-string végét ez jelzi.

Ez teljesen jó.

------

Viszont ez:

```cpp
char* str[]
```

inkább ilyen:

```cpp
char* str[] = {"egy", "ketto"};
```

vagy:

```cpp
const char* str[] = {"egy", "ketto"};
```

Ez stringek tömbje.

------

A `main`-ben:

```cpp
char** argv
```

az gyakorlatilag ugyanaz mint:

```cpp
char* argv[]
```

mert tömb paraméter átadáskor pointerré alakul.

Tehát:

```cpp
int main(int argc, char** argv)
```

≈

```cpp
int main(int argc, char* argv[])
```

ugyanaz 

Pontosan 🙂
Ez:

```cpp
char** tomb = {"Egy", "Kettő"};
```

nem jó.

Mert:

- jobb oldalon egy TÖMB van
- bal oldalon meg egy sima dupla pointer.

Helyesen:

```cpp
const char* tomb[] = {"Egy", "Kettő"};
```

vagy:

```cpp
char* tomb[] = {"Egy", "Kettő"};
```

(de modern C++-ban inkább `const char*`)

------

Mi történik itt?

```cpp
const char* tomb[]
```

jelentése:

> tömb, amiben `const char*` pointerek vannak.

Kb:

```text
tomb[0] ---> "Egy"
tomb[1] ---> "Kettő"
```

------

A `char**` más.

Az általában így jön létre:

```cpp
const char* tomb[] = {"Egy", "Kettő"};

const char** ptr = tomb;
```

Itt:

- `tomb` egy pointertömb
- `ptr` pedig az első elemre mutató dupla pointer.

Ezért működik a `argv` is:

```cpp
char** argv
```

mert valójában egy string-pointer tömb első elemére mutat.

Nagyon jó kérdés 🙂
Itt a függvényparaméterek miatt nincs `=`.

Ez:

```cpp
int main(int argc, char** argv)
```

nem változó inicializálás,
hanem függvényparaméter-lista.

Olyan mint:

```cpp
void valami(int x)
```

Itt sem írunk:

```cpp
int x = ...
```

mert a paraméter értékét a függvényhívás adja át.

------

## Mit jelent az `argc`?

Az `argc` rövidítés:

```text
argument count
```

vagyis:

> argumentumok száma

------

## Mit jelent az `argv`?

```text
argument vector
```

Ez:

> argumentumokat tartalmazó tömb/pointerlista

------

Példa:

Terminálban:

```bash
./program alma korte dio
```

akkor:

```cpp
argc == 4
```

mert:

1. program neve
2. alma
3. korte
4. dio

------

Az `argv` így néz ki:

```text
argv[0] -> "./program"
argv[1] -> "alma"
argv[2] -> "korte"
argv[3] -> "dio"
```

Ezért dupla pointer:

```cpp
char** argv
```

mert:

- `argv` → pointer
- ami `char*` pointerekre mutat
- azok pedig stringekre mutatnak

------

Ez ugyanaz mint:

```cpp
char* argv[]
```

csak pointeres formában írva.

------

Tehát itt a rendszer „tölti fel” az adatokat:

```cpp
int main(int argc, char** argv)
```

nem neked kell `=`-t írni 🙂