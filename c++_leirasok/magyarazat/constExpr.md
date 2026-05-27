#  `constexpr`

C++

```cpp
constexpr int x = 5;
```

Ez azt jelenti:

> az érték már fordítási időben ismert és konstans

------

#  Különbség `const` és `constexpr` között

## `const`

```cpp
const int x = rand();
```

 lehet
mert csak azt mondja:

> „ne módosítsd”

De futáskor is kaphat értéket.

------

## `constexpr`

```cpp
constexpr int x = 5;
```

 fordításkor ismert kell legyen.

Ez már NEM lehet:

```cpp
constexpr int x = rand();
```

 mert `rand()` runtime.

------

#  Régi C világban

Régen sokszor:

```c
#define PI 3.14159
```

Ez preprocessor makró.

Nem valódi változó.

------

#  Modern ajánlás

C++-ban inkább:

```cpp
constexpr double PI = 3.14159;
```

------

#  Röviden

| kulcsszó    | jelentés                         |
| ----------- | -------------------------------- |
| `const`     | nem módosítható                  |
| `constexpr` | fordítási időben ismert konstans |
| `#define`   | preprocessor szövegcsere         |

------

#  Példa

```cpp
constexpr int size = 64;

int arr[size];
```

Ez működik, mert a compiler már előre tudja a méretet.