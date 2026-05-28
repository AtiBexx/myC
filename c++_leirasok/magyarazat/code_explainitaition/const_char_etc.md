Igen 🙂

A `const` jelentése:

> nem módosítható

Például:

```cpp id="kl2w0q"
const int x = 5;
```

utána ez hibás:

```cpp id="r64lg8"
x = 10;
```

Mert `x` konstans.

---

Pointereknél kicsit trükkösebb:

```cpp id="2wv65t"
const char* szoveg
```

ez azt jelenti:

> a karaktereket nem módosíthatod

Tehát:

```cpp id="2q7v4r"
szoveg[0] = 'A';
```

HIBA.

De maga a pointer átállhat máshova:

```cpp id="o5rcy8"
szoveg = "Másik";
```

ez OK.

---

Van ilyen is:

```cpp id="85qy9l"
char* const szoveg
```

Itt fordítva:

* a pointer NEM változhat
* de a tartalom igen

És a legszigorúbb:

```cpp id="mpb7y8"
const char* const szoveg
```

se a pointer,
se a tartalom nem módosítható.
