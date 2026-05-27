------

#  1. `static`

A `static` egy kulcsszó, több jelentése is van C/C++-ban.

C++

------

#  A) Lokális static változó

```cpp
void test()
{
    static int x = 0;

    x++;

    std::cout << x << '\n';
}
```

Ha többször hívod:

```cpp
1
2
3
```

 mert a `static` lokális változó:

- nem törlődik függvény végén
- megőrzi értékét

------

#  B) Static class tag

```cpp
class Test
{
public:
    static int count;
};
```

 ez:

- nem objektumhoz tartozik
- hanem az egész classhoz

------

#  C) File scope static (C-ben is)

```cpp
static int x;
```

👉 csak abban a `.cpp` fájlban látható.

------

#  2. `static_cast`

Ez már egy típuskonverzió.

```cpp
float x = 5.7f;

int y = static_cast<int>(x);
```

 `y = 5`

------

#  Miért jobb mint a sima cast?

Régi C-style:

```cpp
int y = (int)x;
```

Modern C++:

```cpp
int y = static_cast<int>(x);
```

Mert:

- olvashatóbb
- biztonságosabb
- compiler jobban ellenőrzi

------

#  Mire használják gyakran?

## integer → float

```cpp
float a = static_cast<float>(x);
```

## base ↔ derived pointer

```cpp
Derived* d = static_cast<Derived*>(basePtr);
```

------

#  Fontos

A `static_cast`:

- NEM RTTI check
- NEM runtime safety

Arra ott van:

```cpp
dynamic_cast
```

------

#  Röviden

| dolog         | mire való                           |
| ------------- | ----------------------------------- |
| `static`      | tárolás / élettartam / osztályszint |
| `static_cast` | típuskonverzió                      |

------

#  Egyszerű megjegyzés

## `static`

 „meddig él / kihez tartozik”

## `static_cast`

 „alakítsd át másik típussá”