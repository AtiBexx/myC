#### Konstruktor Másolás Tiltása

Igen, ez egy régi és gyakran használt trükk volt C++98/C++03 idején.

Ha a másoló konstruktort a `protected` vagy `private` részbe teszed:

```cpp
class Szemely
{
public:
    Szemely(const char *mN);

protected:
    Szemely(const Szemely &szemely);
};
```

akkor a külső kód nem tudja meghívni:

```cpp
Szemely sz1("Pisti");
Szemely sz2(sz1);  // Hiba!
```

mert a másoló konstruktor nem elérhető.

------

Még szigorúbb a `private`:

```cpp
class Szemely
{
public:
    Szemely(const char *mN);

private:
    Szemely(const Szemely&);
};
```

Ilyenkor csak az osztály saját tagfüggvényei használhatják.

------

Modern C++-ban (C++11-től) inkább ezt írják:

```cpp
class Szemely
{
public:
    Szemely(const char *mN);

    Szemely(const Szemely&) = delete;
};
```

Ez egyértelműen kijelenti:

```text
Ezt az objektumot nem lehet másolni.
```

És a fordító szebb hibaüzenetet ad.

Példa:

```cpp
Szemely sz1("Pisti");
Szemely sz2(sz1);
```

hiba:

```text
use of deleted function 'Szemely::Szemely(const Szemely&)'
```

------

Viszont egy apróság:

Ha csak a másoló konstruktort zárod le, attól még lehetnek más másolási utak.

Például:

```cpp
Szemely a("Pisti");
Szemely b("Józsi");

b = a;
```

ehhez a másoló értékadó operátor (`operator=`) kell.

Ezért ha teljesen tiltani akarod a másolást, akkor általában mindkettőt tiltod:

```cpp
class Szemely
{
public:
    Szemely(const char *mN);

    Szemely(const Szemely&) = delete;
    Szemely& operator=(const Szemely&) = delete;
};
```

Ekkor sem

```cpp
Szemely b(a);
```

sem

```cpp
b = a;
```

nem fog működni.

**ha a másoló konstruktort `protected` vagy `private` részbe rakod, akkor a külső kód nem tud másolatot készíteni az objektumról.** **Modern C++-ban erre inkább a `= delete` megoldást használják.**