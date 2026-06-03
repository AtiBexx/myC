Igen, a C szinte a procedurális programozás mintapéldája.

# C

A C alapvetően:

- procedurális
- strukturált
- alacsony szintű rendszerszintű nyelv

Példa:

```c
#include <stdio.h>

void koszon()
{
    printf("Hello\n");
}

int main()
{
    koszon();
}
```

A C-ben nincs:

- osztály (`class`)
- öröklődés
- polimorfizmus
- konstruktor
- destruktor

Ezért a C-t nem tekintjük objektumorientált nyelvnek.

A gondolkodásmód általában:

```text
adatok
+
függvények
```

külön vannak.

------

# C++

A C++ többparadigmás:

- procedurális
- objektumorientált
- generikus
- részben funkcionális

Például ugyanabban a programban lehet:

```cpp
void fv()
{
}
```

és

```cpp
class Hallgato
{
};
```

és

```cpp
template<typename T>
```

és

```cpp
[](int x){ return x * 2; }
```

------

# Rust

A Rust szintén többparadigmás nyelv, de más filozófiával.

Támogat:

- procedurális programozást
- generikus programozást
- funkcionális programozási elemeket
- adatközpontú (data-oriented) szemléletet

Viszont a klasszikus OOP-t csak részben.

------

## Rust procedurális része

```rust
fn koszon()
{
    println!("Hello");
}

fn main()
{
    koszon();
}
```

Ez teljesen procedurális.

------

## Rust struktúrák

Rustban nincs `class`.

Helyette:

```rust
struct Hallgato
{
    nev: String,
    azon: i32,
}
```

------

## Metódusok

```rust
impl Hallgato
{
    fn kiir(&self)
    {
        println!("{}", self.nev);
    }
}
```

Ez hasonlít a C++ osztályokra.

------

## Mi hiányzik a klasszikus OOP-ból?

Rustban nincs hagyományos öröklődés:

C++:

```cpp
class Ember
{
};

class Hallgato : public Ember
{
};
```

Rust:

```rust
struct Ember
{
}

struct Hallgato
{
}
```

Nincs ilyen öröklési lánc.

A Rust fejlesztői szándékosan kihagyták.

------

## Rust nagyon funkcionális

Gyakoriak az ilyenek:

```rust
let szamok = vec![1,2,3,4];

let uj: Vec<i32> =
    szamok.iter()
          .map(|x| x * 2)
          .collect();
```

Ez sokkal közelebb áll a funkcionális programozáshoz, mint a tipikus C++.

------

# Egyszerű besorolás

| Nyelv   | Procedurális | OOP         | Generikus | Funkcionális |
| ------- | ------------ | ----------- | --------- | ------------ |
| C       | Nagyon erős  | Nincs       | Nincs     | Nincs        |
| C++     | Erős         | Erős        | Erős      | Közepes      |
| Rust    | Erős         | Részleges   | Erős      | Erős         |
| Java    | Közepes      | Nagyon erős | Közepes   | Közepes      |
| Haskell | Nem jellemző | Nincs       | Erős      | Nagyon erős  |

Ha egy mondatban kellene összefoglalni:

- **C**: procedurális rendszernyelv.
- **C++**: többparadigmás rendszernyelv.
- **Rust**: modern többparadigmás rendszernyelv, amely a procedurális, generikus és funkcionális szemléletet részesíti előnyben a klasszikus OOP helyett.