pl

```
void szorzasKettovel(int& m) //hivatkozási argumentum
{
m *=2 //pointer itt átadjuk az értéket
}

```

Az `&` a C++-ban **hivatkozást (reference) jelöl** a függvény argumentumánál. Nézzük részletesen, Ati:

```cpp
void szorzasKettovel(int& m) // hivatkozási argumentum
{
    m *= 2;
}
```

### Mit jelent ez?

1. **`int& m`**
   - Nem másolatot kapsz az `m` változóból, hanem **magára az eredeti változóra hivatkozol**.
   - Ha a függvényben megváltoztatod `m` értékét, **az eredeti változó is módosul** a függvényen kívül.
2. Példa:

```cpp
int x = 5;
szorzasKettovel(x);
std::cout << x << "\n"; // kiírja: 10
```

- Ha **nem** lett volna az `&`, tehát simán `int m`, akkor a függvényben csak egy **másolatot** módosítunk, és `x` értéke nem változik a main-ben.

------

### Hasonlítás pointerrel:

- Pointeres verzióval így néz ki:

```cpp
void szorzasKettovel(int* p)
{
    *p *= 2;  // a pointer által mutatott értéket változtatjuk
}

int x = 5;
szorzasKettovel(&x);
std::cout << x << "\n"; // kiírja: 10
```

- A **hivatkozás (`&`)** a C++-ban sokszor kényelmesebb, mert **nem kell dereferálni**, és a szintaxis tisztább:

```cpp
szorzasKettovel(x); // nincs szükség &-re a hívásnál
```

- Pointer esetén:

```cpp
szorzasKettovel(&x); // átadjuk a címét
```

### A neve az `&`-nek itt

- A **függvény argumentumában** az `&` a **hivatkozás (reference) deklarálása**, nem a bitwise AND operátor.
- Szóval a neve: **reference declarator** vagy egyszerűen **reference**.
- Például:

```cpp
int& m
```

→ azt jelenti, hogy `m` **hivatkozás** egy `int` változóra.

> Különbség: ugyanaz a jel az **& operátor** a kifejezésekben, pl. `&x` → "címoperátor", de a deklarációban `int& m` **hivatkozást jelent**.

------

###  Mit adunk át?

```cpp
void szorzasKettovel(int& m)
```

- Itt **nem a típusát adjuk át**, hanem **magát az értéket (a változó memóriáját)**.
- Pontosabban: a változó **azonosítóját**, vagy memóriacímet, de C++-ban ezt a **reference** koncepció kezeli, így nem kell `*`-ot dereferálni, mint pointernél.
- Amikor meghívod:

```cpp
int x = 5;
szorzasKettovel(x); // x "átadódik" referenciaként
```

→ a függvényen belül `m` **az x változóra hivatkozik**.

------

###  Mit lehet csinálni az `m`-mel?

```cpp
m *= 2; // jó, mert m az x-re hivatkozik
```

- **Nem lehet** `m *= cin >>`… ez **szintaxis hibás lenne**.
- `cin >> m` viszont működik, mert `m` valójában az `x`, tehát az `x`-et írhatod felül:

```cpp
std::cin >> m; // beolvasás, m (és x) értéke változik
```

- `m *= cin >> x;` → **nem értelmes**, mert `cin >> x` maga egy `istream&` értéket ad vissza, nem számot.

------

```
#include <iostream>
using namespace std;

// Érték szerint
void szorzasErtek(int n) {
    n *= 2; // csak a másolatot módosítjuk
}

// Referenciával
void szorzasReferencia(int& n) {
    n *= 2; // az eredeti változót módosítjuk
}

int main() {
    int a = 5;
    int b = 5;

    cout << "Eredeti a: " << a << ", b: " << b << endl;

    szorzasErtek(a);
    szorzasReferencia(b);

    cout << "Érték szerinti átadás után a: " << a << endl;
    cout << "Referencia szerinti átadás után b: " << b << endl;

    return 0;
}
```

 Magyarázat:

- `a` érték szerinti átadás: a függvény csak **másolatot** kap → az eredeti `a` nem változik.
- `b` referencia: a függvény **az eredeti változóra hivatkozik** → módosítás látszik a main-ben is.

Eredeti a: 5, b: 5
Érték szerinti átadás után a: 5
Referencia szerinti átadás után b: 10

másik példa

A **C++-ban** a `&` a **reference declarációs operátor**

```
void szorzasKettovel(int &m){
m *=2;
}
int n = 1;
szorzaskettovel(n);
std::cout << "n = " << n << endl;
```

#### C-ben

**Összehasonlítás C-ben (pointerrel):**

C-ben nincs reference, csak pointer. Ugyanezt így kellene csinálni C-ben:

```
#include <stdio.h>

void szorzasKettovel(int *m) {
    *m *= 2; // a pointer által mutatott értéket módosítjuk
}

int main() {
    int n = 1;
    szorzasKettovel(&n); // címét adjuk át
    printf("n = %d\n", n); // n = 2
}
```

- Itt `&n` a cím, `*m` a dereferálás → az eredeti változó módosítása.
- C++ reference (`int &m`) = C-ben a pointer `int* m` + dereferálás `*m`, de C++-ban **kényelmesebb**.

Szóval a `&` C++-ban **nem az “értékadó operátor”**, hanem **referencia deklarálására szolgál**.