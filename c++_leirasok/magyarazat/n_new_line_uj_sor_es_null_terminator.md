Technikailag a `'\n'` egy picit egyszerűbb/gyorsabb lehet, mint a `"\n"`.

A különbség:

```cpp
'\n'
```

→ egyetlen `char`

míg:

```cpp
"\n"
```

→ C-string (`const char[2]`)
valójában:

```cpp
{ '\n', '\0' }
```

Tehát:

```cpp
std::cout << '\n';
```

kicsit direktebb.

Viszont a gyakorlatban a különbség szinte mérhetetlen normál programoknál.

Általában:

- egy karakter → `' '`
- szöveg → `" "`

Példák:

```cpp
std::cout << 'A';
std::cout << '\n';
```

és:

```cpp
std::cout << "Hello\n";
```

Ami viszont fontosabb teljesítményben:

```cpp
std::endl
```

lassabb lehet, mert:

```cpp
std::endl
```

nemcsak új sort ír, hanem flush-olja is a buffert.

Tehát:

```cpp
std::cout << '\n';
```

általában jobb, mint:

```cpp
std::cout << std::endl;
```

ha nem kell azonnali flush.

A te kódodban ez teljesen jó:

```cpp
std::cout << '\n';
```

Nagyon sok C++ fejlesztő ezt preferálja.

Pontosan ezért kisebb is.

Ez:

```cpp
'\n'
```

egy darab `char`.

Memóriában kb.:

```cpp
0x0A
```

Viszont ez:

```cpp
"\n"
```

C-string, tehát kell lezáró karakter:

```cpp
'\n', '\0'
```

vagy byte szinten:

```cpp
0x0A 0x00
```

Ezért:

```cpp
sizeof('\n')
```

nem ugyanaz mint:

```cpp
sizeof("\n")
```

Sőt:

```cpp
sizeof("\n")
```

2 lesz.

Mert:

- `\n`
- `\0`

A C-stringek mindig null-termináltak.

Ezért gyorsabb/egyszerűbb sokszor egyetlen karakterre:

```cpp
'\n'
```

mint:

```cpp
"\n"
```

mert ott nincs string kezelés.

A `'\0'` terminátor azért kell, mert a C és a régi C++ stringek nem tárolják külön a hosszúságukat.

Tehát a programnak valahonnan tudnia kell:

> „hol ér véget a szöveg?”

Erre szolgál a null terminátor:

```cpp
'\0'
```

ami értékben:

```cpp
0
```

Példa:

```cpp
char text[] = "Hello";
```

Memóriában valójában:

```cpp
'H' 'e' 'l' 'l' 'o' '\0'
```

A `std::cout`, `strlen`, `printf` stb. addig olvassa:

```cpp
H e l l o
```

amíg meg nem találja:

```cpp
'\0'
```

Ez jelzi:

> itt vége a stringnek.

Ha nem lenne terminátor:

```cpp
char text[] = {'H','e','l','l','o'};
```

akkor a program nem tudná hol a vége, és tovább olvasna a memóriában össze-vissza.

Ezért lehetnek ilyen hibák:

- garbage karakterek
- crash
- buffer overflow

Példa:

```cpp
char text[5] = {'H','e','l','l','o'};

std::cout << text;
```

Itt nincs `'\0'`, tehát undefined behavior.

Régi C stringek:

```cpp
char*
char[]
```

mind null-termináltak.

Modern C++ `std::string` már külön tárolja a méretet is, de kompatibilitás miatt ott is van terminátor sok implementációban.

  A `printf()` nagyon régi, már a C nyelv kezdetétől létezett, és ugyanúgy stringeket kapott.

Viszont azok a stringek ilyenek voltak:

```cpp
char text[] = "Hello";
```

vagy:

```cpp
char* text = "Hello";
```

Tehát a régi C-ben a „string” valójában csak:

- `char` tömb
- null terminátorral

Nem volt külön valódi string típus.

Példa régi C stílusban:

```cpp
#include <stdio.h>

int main()
{
    char text[] = "Hello";

    printf("%s\n", text);

    return 0;
}
```

A `%s` azt jelenti:

> olvass karaktereket addig amíg `'\0'` nincs.

A `std::cout` később jött a C++-ban.

Ez:

```cpp
std::cout << "Hello";
```

a háttérben ugyanúgy null-terminált stringet kap.

A `"Hello"` valójában:

```cpp
'H','e','l','l','o','\0'
```

Csak a C++ stream rendszer (`<<`) modernebb és típusbiztosabb.

Később jött a valódi C++ string osztály:

```cpp
std::string text = "Hello";
```

ami már:

- tárol méretet
- dinamikusan nő
- biztonságosabb
- kényelmesebb

De kompatibilitás miatt még mindig tud C-stringként működni:

```cpp
text.c_str()
```

ami visszaad egy null-terminált `char*`-t.

Azért nem kellett kézzel kiírni, mert a fordító automatikusan hozzáadja 

Ez:

```c
char text[] = "Hello";
```

valójában ezt jelenti a memóriában:

```c
char text[] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

A string literáloknál:

```c
"Hello"
```

a `'\0'` automatikusan bekerül a végére.

Ezért működik:

```c
printf("%s\n", text);
```

mert a `%s` megkeresi a lezáró nullát.

Viszont itt már nincs automatikus terminátor:

```c
char text[] = {'H', 'e', 'l', 'l', 'o'};
```

Itt NINCS `'\0'`.

Tehát:

```c
printf("%s\n", text);
```

→ undefined behavior lehet.

Ha kézzel írod a karaktertömböt, neked kell a terminátor:

```c
char text[] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

Ez már jó.