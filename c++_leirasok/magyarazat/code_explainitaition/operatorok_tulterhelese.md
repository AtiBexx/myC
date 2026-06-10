### Operátorok túlterhelése

----------

**A Belső Adattípusok mint pl int, double float és a különféle mutató típusok be vannak építve a nyelvbe de, a C++ ban ezek a belső operátorok melett további operátorokat is definiálhatunk az osztályokhoz.**

**EZT NEVEZZÜK OPERÁTOR TÚLTERHELÉSNEK....**

```cpp
//pl
a+b
//amit úgy is írhatnánk hogy,
operator+(a,b)//operator+(int, int)

```

Az operátorok függvényneveiben az adott operátor szimbóluma előtt az `operator`kulcsszó áll.

operátorok:

Rendben, ezt szépen tisztázzuk, mert itt több fogalom keveredik (operátor túlterhelés + másolás típusok).

------

####  1. Operátor túlterhelés C++-ban

Az operátor túlterhelés azt jelenti:

> saját osztályokra is definiálhatod, mit jelentsen az `+ - * ==` stb.

------

## Példa:

```cpp
class Szam {
public:
    int x;

    Szam(int v) : x(v) {}

    Szam operator+(const Szam& masik) {
        return Szam(x + masik.x);
    }
};
```

Használat:

```cpp
Szam a(2);
Szam b(3);

Szam c = a + b;   // ez: a.operator+(b)
```

------

####  2. Amit fontos megérteni

Ez:

```cpp
a + b
```

valójában ez:

```cpp
a.operator+(b)
```

------

#### 3. Másolás típusok C++-ban

Ez teljesen külön téma, de ide kapcsolódik.

------

####  1. Sekély másolás (shallow copy)

 csak a címek másolódnak

```cpp
A* p1 = new A();
A* p2 = p1;
```

 probléma:

- ugyanaz a memória
- dupla delete veszély

------

####  2. Mély másolás (deep copy)

 valódi új memória készül

```cpp
A* p2 = new A(*p1);
```

 minden adat külön másolat

------

####  3. Másoló konstruktor

```cpp
class A {
public:
    A(const A& masik) {
        // deep copy itt
    }
};
```

 akkor fut, amikor:

```cpp
A a2 = a1;
```

------

####  4. Értékadó operátor (=)

```cpp
A& operator=(const A& masik);
```

 akkor fut, amikor:

```cpp
a2 = a1;
```

------

####  Kulcs különbség

| eset    | mi történik        |
| ------- | ------------------ |
| A b = a | másoló konstruktor |
| b = a   | értékadó operátor  |

------

####  5. C++ operátorok listája

####  aritmetikai

- `+ - * / %`

####  növelés/csökkentés

- `++ --`

####  összehasonlítás

- `== != < > <= >=`

####  logikai

- `&& || !`

####  bitműveletek

- `& | ^ ~ << >>`

####  hozzárendelés

- `= += -= *= /= %= <<= >>= &= |= ^=`

####  memória / pointer

- `* & -> ->* []`

####  speciális

- `new delete`
- `,` (vessző operátor)
- `()` (function call operator)

------

####  6. Fontos szabály

**nem minden operátort lehet túlterhelni:**

 nem túlterhelhető:

- `::`
- `.`
- `?:`
- `sizeof`

### Ezek NEM túlterhelhető operátorok

------

####  `::` (scope resolution operator)

 „hatókör feloldás”

#### Mire jó?

- osztályon kívüli függvény definiálás
- namespace használat
- statikus tag elérése

#### Példa:

```
std::cout << "hello";
class A {
public:
    static int x;
};

int A::x = 10;
```

 itt a `::` azt mondja:

> “A osztályon belüli x”

------

####  `.` (member access operator)

 objektum tagjainak elérése

## Példa:

```
class A {
public:
    int x;
};

A a;
a.x = 5;
```

 itt:

- `a.x` = objektum mező elérése

------

####  miért nem túlterhelhető?

Mert:

> a nyelv alap szintaxis része, nem függvényhívás

------

####  `?:` (ternary operator)

 feltételes operátor

## Példa:

```
int x = (a > b) ? a : b;
```

 jelentése:

> ha a > b akkor a, különben b

------

#### Átírva:

```
if (a > b)
    x = a;
else
    x = b;
```

------

####  miért nem overloadolható?

Mert:

> nem függvény, hanem vezérlési struktúra

------

####  `sizeof`

 méret lekérdezése (byte-ban)

#### Példa:

```
int x;
std::cout << sizeof(x);
```

 pl:

- int = 4 byte (általában)

------

#### Objektumra is:

```
class A { int x; };
sizeof(A);
```

------

####  miért nem overloadolható?

Mert:

> compile-time operátor (fordításkor működik)

------

####  7. Egyszerű összefoglalás

- operátor túlterhelés = saját osztály + `+ - ==` stb
- másoló konstruktor = új objektum létrehozás
- értékadás operátor = meglévő objektum felülírása
- shallow = cím másolás
- deep = valódi adat másolás

------

####  Egy mondat:

> C++ operátor túlterhelés = saját osztályaidat úgy használhatod, mintha beépített típusok lennének



#### DEFINIÁLJUK FELÜL AZ ÉRTÉKADÓ OPERÁTORT

```cpp
//ÉrtékadóOperátorBemutató
// ez a program bemutatja az értékadó operátor használatát
// egy felhasználó által definiált osztályban
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
/*
-A DTomb egy dinamikus méretű tömbosztály, amellyel
- bemutatjuk az értékadó és a másoló konstruktor
- operátort.
*/
class DTomb
{
public:
 DTomb(int nTombHossza = 0) : nHossz(nTombHossza), mTomb(nullptr)
 {
     std::cout << "A DTomb létrehozása, hossz = " << nHossz <<'\n';
     if(nHossz > 0)
     {
         mTomb = new int[nHossz];
     }
 }
 DTomb(const DTomb& dt) : nHossz(0), mTomb(nullptr)
 {
     std::cout<<"A DTomb másolása, hossz = "
     << dt.nHossz <<'\n';
     dTombMasolas(dt);
 }
 ~DTomb()
 {
     dTombTorles();
 }
 //értékadó operátor
 DTomb& operator=(const DTomb& s)
 {
     std::cout << "A forrás hozzárendelése (hossz = " << s.nHossz <<") a célhoz (hossz = "
               << this->nHossz << ")" <<'\n';
               if(this != &s)
               {
               //töröljük a meglévő cuccokat
               dTombTorles();
               //Másolunk
               dTombMasolas(s);
               }
               //visszaadjuk a meglévő objektum értékét
               return* this;
 }
 //================
 int& operator[](int index)
 {
     return mTomb[index];
 }
 int meret() const
 {return nHossz;}
 //===============
 void megjelenites(std::ostream& ki)
 {
     if(nHossz > 0)
     {
         ki << mTomb[0];
         for(int i = 1; i < nHossz; i++)
         {
             ki << ", " << mTomb[i];
         }
     }
 }
//=================
protected:
    void dTombMasolas(const DTomb& dt);
    void dTombTorles();
    int nHossz;
    int* mTomb;
};
//dTombMasolas
// masolatot készítünk egy dinamikus int Tömbröl
void DTomb::dTombMasolas(const DTomb& forras)
{
    nHossz = forras.nHossz;
    mTomb = nullptr;
    if (nHossz > 0)
    {
        mTomb = new int[nHossz];
        for(int i = 0; i < nHossz; i++)
        {
            mTomb[i] = forras.mTomb[i];
        }
    }
}
//DTombTorles
//- felszabadytjuk a halomMermóriát
void DTomb::dTombTorles()
{
    nHossz = 0;
    delete[] mTomb;
    mTomb = nullptr;
}

int main(int argc, char** argv)
{
    //létrehozunk egy dinamikus tömböt és értéket adunk hozzá
    DTomb dt1(5);
    for (int i =0; i < dt1.meret(); i++)
    {
        //a felhasználó áltál definiált index operátoral
        //éri el a tömb tagjait
        dt1[i] = i;
    }
    std::cout <<"dt1= "; dt1.megjelenites(std::cout); std::cout <<std::endl;
    // most létrehozzuk ennek a dinamikus tömbnek a másolatát
    // a másoló konstruktorral; ez ugyanaz, mint a dt2(dt1)
    DTomb dt2 = dt1;
    dt2[2] = 20; // a másolatban módosítunk egy értéket
    std::cout <<"dt2= "; dt2.megjelenites(std::cout); std::cout <<std::endl;
    // felülírjuk a meglévő dt2-t az eredeti dt1-gyel
    dt2 = dt1;
    std::cout << "dt2= "; dt2.megjelenites(std::cout); std::cout << std::endl;


    //kilépünk
    std::cout <<"A kilépéshez kérlek nyomd meg 2-szer az entert..."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();
    return 0;
}

```



#### output

```cpp
A DTomb létrehozása, hossz = 5
dt1= 0, 1, 2, 3, 4
A DTomb másolása, hossz = 5
dt2= 0, 1, 20, 3, 4
A forrás hozzárendelése (hossz = 5) a célhoz (hossz = 5)
dt2=0, 1, 2, 3, 4
A kilépéshez kérlek nyomd meg 2-szer az entert...
```

Persze Ati. Ez a kód elsőre hosszúnak és ijesztőnek tűnik, de valójában néhány fontos C++ fogalmat mutat be egyszerre:

- konstruktor
- másoló konstruktor
- destruktor
- értékadó operátor
- operátor túlterhelés
- dinamikus memória
- deep copy

Menjünk végig rajta sorban.

------

# A DTomb osztály célja

Ez az osztály egy dinamikus méretű int tömböt valósít meg.

Ahelyett, hogy ezt írnánk:

```cpp
int tomb[5];
```

írhatjuk:

```cpp
DTomb dt(5);
```

A DTomb belül lefoglal egy int tömböt a heapen.

------

# Adattagok

```cpp
int nHossz;
int* mTomb;
```

## nHossz

A tömb méretét tárolja.

Például:

```cpp
DTomb dt(5);
```

után:

```cpp
nHossz = 5;
```

------

## mTomb

Mutató a dinamikusan foglalt tömbre.

Például:

```cpp
mTomb
```

mutathat egy ilyen memóriára:

```text
+---+---+---+---+---+
| 0 | 1 | 2 | 3 | 4 |
+---+---+---+---+---+
```

------

# Konstruktor

```cpp
DTomb(int nTombHossza = 0)
 : nHossz(nTombHossza), mTomb(nullptr)
```

Ez fut le objektum létrehozásakor.

Például:

```cpp
DTomb dt1(5);
```

------

Az inicializáló lista:

```cpp
:nHossz(nTombHossza), mTomb(nullptr)
```

ugyanaz mint:

```cpp
nHossz = nTombHossza;
mTomb = nullptr;
```

csak hatékonyabb.

------

Ezután:

```cpp
if(nHossz > 0)
{
    mTomb = new int[nHossz];
}
```

lefoglalja a memóriát.

Például:

```cpp
new int[5]
```

------

# Másoló konstruktor

```cpp
DTomb(const DTomb& dt)
```

Ez akkor fut le, amikor új objektum jön létre egy másikból.

Példa:

```cpp
DTomb dt2 = dt1;
```

------

A fordító ilyenkor meghívja:

```cpp
DTomb(const DTomb&)
```

------

Ezután:

```cpp
dTombMasolas(dt);
```

deep copy történik.

------

# Mi az a deep copy?

Ha van:

```cpp
dt1
```

és benne:

```text
mTomb ---> [0][1][2][3][4]
```

akkor a másolás után:

```text
dt1 ---> [0][1][2][3][4]

dt2 ---> [0][1][2][3][4]
```

külön memóriaterületre mutatnak.

Ez nagyon fontos.

------

# Destruktor

```cpp
~DTomb()
```

Ez automatikusan lefut amikor az objektum megszűnik.

Például a main végén.

------

Meghívja:

```cpp
dTombTorles();
```

------

# dTombTorles

```cpp
delete[] mTomb;
```

felszabadítja a memóriát.

Ha ezt elfelejtenéd:

```cpp
new int[5];
```

memóriaszivárgás keletkezne.

------

# Operátor túlterhelés

Most jön a lényeg.

------

# Mi az az operator?

Normál esetben:

```cpp
a + b
```

A fordító ezt úgy értelmezi:

```cpp
operator+(a,b)
```

------

A C++ megengedi, hogy saját osztályokra is definiáld ezt.

Például:

```cpp
operator+
operator-
operator==
operator[]
operator=
```

------

# Az operator= jelentése

Ez:

```cpp
DTomb& operator=(const DTomb& s)
```

az értékadó operátor.

------

Amikor ezt írod:

```cpp
dt2 = dt1;
```

valójában:

```cpp
dt2.operator=(dt1);
```

hívódik meg.

------

Ezért mondjuk azt, hogy túlterheltük az = operátort.

------

# Mit csinál az operator= ?

Először:

```cpp
if(this != &s)
```

ellenőrzi:

```cpp
dt1 = dt1;
```

nem történik-e.

------

Ezután:

```cpp
dTombTorles();
```

kitörli a régi adatokat.

------

Majd:

```cpp
dTombMasolas(s);
```

lemásolja az új adatokat.

------

Végül:

```cpp
return *this;
```

------

# Mi az a this?

Minden objektum rendelkezik egy rejtett mutatóval:

```cpp
this
```

ami saját magára mutat.

------

Például:

```cpp
dt2.operator=(dt1);
```

esetén:

```cpp
this -> dt2
```

------

Tehát:

```cpp
return *this;
```

visszaadja a dt2 objektumot.

------

# Miért referencia?

```cpp
DTomb&
```

azért, hogy működjön például:

```cpp
a = b = c;
```

------

# operator[]

Ez:

```cpp
int& operator[](int index)
```

az index operátor.

------

Normál eset:

```cpp
tomb[3]
```

------

A fordító ezt látja:

```cpp
tomb.operator[](3)
```

------

Ezért működik:

```cpp
dt1[2] = 20;
```

------

Valójában:

```cpp
dt1.operator[](2) = 20;
```

------

# Miért int& ?

Nem ezt adja vissza:

```cpp
int
```

hanem:

```cpp
int&
```

------

Referencia kell ahhoz, hogy:

```cpp
dt1[2] = 20;
```

módosíthassa az elemet.

------

# dTombMasolas

Ez végzi a valódi másolást.

------

Először:

```cpp
nHossz = forras.nHossz;
```

------

Majd:

```cpp
mTomb = new int[nHossz];
```

------

Ezután:

```cpp
for(...)
{
    mTomb[i] = forras.mTomb[i];
}
```

egyenként lemásolja az elemeket.

------

# A main függvény

## Létrehozás

```cpp
DTomb dt1(5);
```

------

## Feltöltés

```cpp
for(...)
{
    dt1[i] = i;
}
```

------

A tömb tartalma:

```text
0,1,2,3,4
```

------

## Másoló konstruktor

```cpp
DTomb dt2 = dt1;
```

------

Lefut:

```cpp
DTomb(const DTomb&)
```

------

## Módosítás

```cpp
dt2[2] = 20;
```

------

Most:

```text
dt1: 0,1,2,3,4

dt2: 0,1,20,3,4
```

------

Ez bizonyítja, hogy deep copy történt.

------

## Értékadás

```cpp
dt2 = dt1;
```

------

Lefut:

```cpp
operator=
```

------

És dt2 ismét:

```text
0,1,2,3,4
```

lesz.

------

A program legfontosabb tanulsága:

A másoló konstruktor és az értékadó operátor nem ugyanaz.

```cpp
DTomb dt2 = dt1;
```

→ másoló konstruktor

```cpp
dt2 = dt1;
```

→ operator=

Ez a példa pontosan ezt a különbséget mutatja be.

Szia! Szívesen elmagyarázom! Ez egy **dinamikus tömb osztály** (DTomb), ami bemutatja hogyan kell helyesen kezelni a memóriát C++-ban.

------

## Az osztály felépítése

### 🏗️ Mi az a DTomb?

Egy saját készítésű tömb, ahol a méret futásidőben dől el (nem fordításkor), és a memóriát a **heap-en** (halomban) tárolja.

------

## A konstruktorok és függvények

### 1️⃣ Alap konstruktor

```cpp
DTomb(int nTombHossza = 0) : nHossz(nTombHossza), mTomb(nullptr)
```

- Létrehoz egy tömböt adott mérettel
- Ha `nHossz > 0`, akkor `new int[nHossz]` — **lefoglalja a memóriát**
- Ha 0, akkor `nullptr` marad (üres tömb)

------

### 2️⃣ Másoló konstruktor

```cpp
DTomb(const DTomb& dt) : nHossz(0), mTomb(nullptr)
```

- Akkor hívódik meg, amikor **egy meglévőből csinálsz új példányt**:

```cpp
DTomb dt2 = dt1;  // ← itt hívódik meg
```

- Meghívja a `dTombMasolas()` segédfüggvényt
- **Miért kell ez?** Mert alapból csak a pointer másolódna át, nem az adat — akkor ketten mutatnának ugyanarra a memóriára → katasztrófa!

------

### 3️⃣ Destruktor

```cpp
~DTomb()
{
    dTombTorles();
}
```

- Automatikusan lefut, amikor a változó "kimegy a hatókörből"
- Felszabadítja a memóriát (`delete[]`)
- **Nélküle memory leak lenne!**

------

### 4️⃣ Értékadó operátor ← ez a program főszereplője

```cpp
DTomb& operator=(const DTomb& s)
```

- Akkor hívódik meg, amikor **egy már létező objektumra** adsz értéket:

```cpp
dt2 = dt1;  // ← itt hívódik meg (dt2 már létezett!)
```

A működése lépésről lépésre:

```
1. Ellenőrzi: dt2 = dt2 lenne? (önmagát adja magának?) → kihagyja
2. Törli dt2 régi adatait (dTombTorles)
3. Átmásolja dt1 adatait (dTombMasolas)
4. Visszaadja *this-t → ezért lehet láncolni: a = b = c
```

------

### 5️⃣ Index operátor

```cpp
int& operator[](int index)
```

- Ettől lehet így használni: `dt1[2] = 20`
- Referenciát ad vissza → **írni és olvasni is lehet** vele

------

## A két segédfüggvény

| Függvény         | Mit csinál                                                   |
| ---------------- | ------------------------------------------------------------ |
| `dTombMasolas()` | Új memóriát foglal, és **értékeket másol át** (mély másolat) |
| `dTombTorles()`  | `delete[]`-vel **felszabadítja** a memóriát, nulláz          |

------

## A main() folyamata

```
dt1 létrehozva (5 elem): [0, 1, 2, 3, 4]
         ↓
dt2 = dt1 másolattal (másoló konstruktor): [0, 1, 2, 3, 4]
         ↓
dt2[2] módosítva: [0, 1, 20, 3, 4]  ← dt1 nem változik!
         ↓
dt2 = dt1 (értékadó operátor): [0, 1, 2, 3, 4]
```

------

## Miért kell ennyi mindent megírni?

Ez az úgynevezett **"Rule of Three"** (Három szabálya) C++-ban:

> Ha az osztályodnak van **destruktora**, akkor szinte biztosan kell **másoló konstruktor** és **értékadó operátor** is — különben a pointer másolódik, nem az adat, és memóriahiba lesz.

![image-20260610045635259](E:\projects\cpp\c++_leirasok\magyarazat\image-20260610045635259.png)

Nagyon jó kérdés! Nézzük meg **vizuálisan** miért kell mind a három!

------

## Mi történik ha NINCS másoló konstruktor?

Az alapértelmezett másolás csak a **pointer címét** másolja át, nem az adatot:Most nézzük meg **konkrétan a kódban** mi miért kell:

------

## A "Rule of Three" — miért kell mind a három?

### A probléma: a pointer

A `DTomb`-nak van egy `int* mTomb` tagja — ez egy **pointer**, ami a heap memóriára mutat. Ez az, ami mindent bonyolulttá tesz.

Ha a C++ saját magától másolna egy ilyen objektumot, **csak a pointer számértékét másolná** (pl. `0xFF20`), nem az adatokat. Ezt látod a piros részben a diagramon.

------

### Destruktor — kötelező, ha `new`-t használsz

```cpp
~DTomb() { dTombTorles(); }  // delete[] mTomb
```

Ha foglaltál memóriát (`new`), valakinek fel kell szabadítani. Ez a destruktor feladata. Ha nincs → **memory leak**.

------

###  Másoló konstruktor — azért kell, mert van destruktor

```cpp
DTomb dt2 = dt1;  // ← ÚJ objektum jön létre
```

Ha nincs saját másoló konstruktorod:

- `dt2.mTomb` ugyanarra a memóriára mutat mint `dt1.mTomb`
- Amikor `dt2` megszűnik → destruktor lefut → törli a memóriát
- Amikor `dt1` is megszűnik → destruktor megint lefut → **ugyanazt a memóriát törli KÉTSZER** → program crash

------

###  Értékadó operátor — azért kell, mert van destruktor ÉS másoló konstruktor

```cpp
dt2 = dt1;  // ← dt2 MÁR LÉTEZETT, csak felülírjuk
```

Ha nincs saját értékadó operátorod, ugyanaz a pointer-probléma mint fentebb. De itt egy extra probléma is van: **dt2 régi memóriája soha nem szabadul fel** → memory leak.

Ezért az értékadó operátor 3 dolgot csinál:

```
1. Töröld a dt2 régi tartalmát  (delete[])
2. Másolj új memóriát            (new int[])
3. Másold át az értékeket        (for ciklus)
```

------

### Az ökölszabály egyszerűen

| Ha van...          | Kell még...        |
| ------------------ | ------------------ |
| `new` valahol      | destruktor         |
| destruktor         | másoló konstruktor |
| másoló konstruktor | értékadó operátor  |

Jó kérdés, de itt van egy kis félreértés! Nézzük meg pontosan **mikor kell** és **mikor nem kell** a Rule of Three.

------

## A te esetedben

```cpp
class ae {
public:
    ae(int a, int b) {
        eredmeny = a + b;  // csak számokat tárol, nem pointert!
    }
    ~ae() { }  // semmi heap memória → üres destruktor elég
    
    int eredmeny;
};

int main() {
    ae* ee = new ae(5, 2);
    // ee->eredmeny == 7
    delete ee;
    ee = nullptr;
}
```

**NEM kell** másoló konstruktor és értékadó operátor, mert:

------

## A döntő kérdés: van-e `new` az OSZTÁLYON BELÜL?

| Helyzet                                                     | Kell Rule of Three? |
| ----------------------------------------------------------- | ------------------- |
| `new`-t csak a `main`-ben használsz                         | ❌ Nem kell          |
| `new`-t az osztályon belül használsz (`mTomb = new int[n]`) | ✅ Kell!             |

------

## A különbség szemléletesen

###  Nem kell (a te eseted):

```cpp
class ae {
    int eredmeny;  // ← sima int, nem pointer
                   // az osztály NEM foglal heap memóriát
};

int main() {
    ae* ee = new ae(5, 2);  // ← itt van new, de ez az OBJEKTUMNAK foglal
    delete ee;               // ← ezt te kezeled, az osztály nem tudja
}
```

A `delete ee` **te** csinálod kézzel → az osztálynak semmi dolga.

------

### Kell (a DTomb esete):

```cpp
class DTomb {
    int* mTomb;  // ← pointer!
    
    DTomb(int n) {
        mTomb = new int[n];  // ← az OSZTÁLY foglal heap memóriát
    }                        //   valakinek fel kell szabadítani!
};
```

Az osztály belül foglalt memóriát → az osztálynak kell takarítani → kell destruktor → kell mind a három.

------

## Egyszerű emlékeztető

> Ha az osztályodban van `int*` (vagy bármilyen pointer) **ÉS** az osztály maga csinálja a `new`-t → Rule of Three.
>
> Ha csak `int`, `double`, `string` stb. van → nem kell.

Rendben, megírjuk úgy hogy **az osztályon belül legyen pointer**, és akkor kell mind a három!Íme a teljes átírt példa, majd a diagram mutatja mi történik a memóriával:

```cpp
#include <iostream>

class ae {
public:

    // 1. Alap konstruktor — lefoglalja a memóriát
    ae(int a, int b) : pErtek(nullptr) {
        pErtek = new int(a + b);   // new → heap memória!
        std::cout << "Konstruktor: " << *pErtek << "\n";
    }

    // 2. Másoló konstruktor — mély másolat
    ae(const ae& masik) : pErtek(nullptr) {
        pErtek = new int(*masik.pErtek);  // ÚJ memória, átmásolt érték
        std::cout << "Másoló konstruktor: " << *pErtek << "\n";
    }

    // 3. Értékadó operátor — felülírás biztonságosan
    ae& operator=(const ae& masik) {
        std::cout << "Értékadó operátor\n";
        if (this != &masik) {
            delete pErtek;                    // régi memória törlése
            pErtek = new int(*masik.pErtek);  // új másolat
        }
        return *this;
    }

    // 4. Destruktor — felszabadítja a heap memóriát
    ~ae() {
        std::cout << "Destruktor: " << *pErtek << "\n";
        delete pErtek;
        pErtek = nullptr;
    }

    int ertek() const { return *pErtek; }

private:
    int* pErtek;   // ← ez a pointer teszi szükségessé a Rule of Three-t!
};

int main(int argc, char** argv) {
    ae* ee = new ae(5, 2);        // konstruktor → *pErtek = 7
    ae masolt = *ee;              // másoló konstruktor → saját memória
    ae harmadik(1, 1);            // konstruktor → *pErtek = 2
    harmadik = *ee;               // értékadó operátor → felülírja 7-re

    std::cout << ee->ertek()      << "\n";  // 7
    std::cout << masolt.ertek()   << "\n";  // 7
    std::cout << harmadik.ertek() << "\n";  // 7

    delete ee;
    ee = nullptr;
    return 0;
}
```

Most nézzük meg vizuálisan mi történik a memóriában:A lényeg nagyon röviden:

Az `ae` osztályban most `int* pErtek` van — egy pointer, ami a heap-re mutat. Ezért kell mind a három:

- a destruktor törli a `new int(...)` által foglalt memóriát, különben szivárog
- a másoló konstruktor új `new int(...)` memóriát foglal és átmásolja az értéket, különben két objektum ugyanarra a területre mutatna
- az értékadó operátor először `delete`-li a régi területet, majd szintén új `new int(...)` területre másolja az értéket, különben egyrészt szivárog a régi, másrészt megint pointer-ütközés lenne

A diagramon látható, hogy `ee`, `masolt` és `harmadik` mind más-más heap címre mutat (`0xB200`, `0xB300`, `0xB400`), tehát teljesen független egymástól. Ez pontosan az, amit a Rule of Three biztosít.

![image-20260610050531433](E:\projects\cpp\c++_leirasok\magyarazat\image-20260610050531433.png)

Pontosan jól látod! A `main`-ben **egyáltalán nincs** `new` és `delete` — és ez szándékos. Nézzük meg miért:

------

## A DTomb-ban a `main` tiszta és egyszerű

```cpp
int main() {
    DTomb dt1(5);      // ← sima stack változó, nem new!
    DTomb dt2 = dt1;   // ← másoló konstruktor, nem new!
    dt2 = dt1;         // ← értékadó operátor, nem new!
}
// ← itt automatikusan lefutnak a destruktorok!
```

Nincs egyetlen `new`, `delete`, pointer a `main`-ben. Mégis heap memória van használatban — csak **az osztályon belül**, rejtve.

------

## Hol van akkor a `new` és `delete`?

```cpp
// Az OSZTÁLYON BELÜL — rejtve a felhasználó elől:

DTomb(int n) {
    mTomb = new int[n];   // ← itt foglal az osztály
}

~DTomb() {
    delete[] mTomb;       // ← itt szabadít fel az osztály
}
```

Ez az egész lényege — ezt hívják **egységbezárásnak (encapsulation)**:

> A `main` nem tudja és nem is kell hogy tudja, hogy belül pointer és heap van. Az osztály elrejti a bonyolultságot, és maga kezeli a memóriát.

------

## Összehasonlítás

|                      | `ae` példád     | `DTomb`                  |
| -------------------- | --------------- | ------------------------ |
| `main`-ben `new`     | igen            | nem kell                 |
| Ki kezeli a memóriát | te, kézzel      | az osztály automatikusan |
| `main` bonyolultsága | több felelősség | tiszta, egyszerű         |

Rendben! Tehát ugyanaz mint a `DTomb` mintája — az osztály maga kezel mindent, a `main` tiszta marad:

```cpp
#include <iostream>

class ae {
public:

    // 1. Konstruktor — az osztály foglalja a memóriát
    ae(int a, int b) : pErtek(nullptr) {
        pErtek = new int(a + b);
        std::cout << "Konstruktor: " << *pErtek << "\n";
    }

    // 2. Másoló konstruktor — mély másolat
    ae(const ae& masik) : pErtek(nullptr) {
        pErtek = new int(*masik.pErtek);
        std::cout << "Másoló konstruktor: " << *pErtek << "\n";
    }

    // 3. Értékadó operátor
    ae& operator=(const ae& masik) {
        std::cout << "Értékadó operátor\n";
        if (this != &masik) {
            delete pErtek;
            pErtek = new int(*masik.pErtek);
        }
        return *this;
    }

    // 4. Destruktor — az osztály takarít
    ~ae() {
        std::cout << "Destruktor: " << *pErtek << "\n";
        delete pErtek;
        pErtek = nullptr;
    }

    int ertek() const { return *pErtek; }

protected:
    int* pErtek;   // ← rejtve, a main nem látja
};

int main(int argc, char** argv) {

    ae elso(5, 2);         // konstruktor — nem kell new!
    ae masolt = elso;      // másoló konstruktor — nem kell new!
    ae harmadik(10, 3);    // konstruktor
    harmadik = elso;       // értékadó operátor

    std::cout << elso.ertek()     << "\n";  // 7
    std::cout << masolt.ertek()   << "\n";  // 7
    std::cout << harmadik.ertek() << "\n";  // 7

}   // ← itt automatikusan lefutnak a destruktorok, nem kell delete!
```

A `main` teljesen tiszta — nincs benne `new`, `delete`, pointer. Pontosan mint a `DTomb`-nál. A kimenet így néz ki:

```
Konstruktor: 7
Másoló konstruktor: 7
Konstruktor: 13
Értékadó operátor
7
7
7
Destruktor: 7
Destruktor: 7
Destruktor: 7
```

A destruktorok a `main` végén automatikusan lefutnak fordított sorrendben — `harmadik`, `masolt`, `elso` — nem kell kézzel törölni semmit.

A lényeg amit ma megtanultál, egy mondatban:

> **Ha az osztályban van `new` → kell destruktor + másoló konstruktor + értékadó operátor. Ha nincs `new` → nem kell egyik sem.**

Ez az egész fejezet lényege. A könyv ezt 20 oldalon írja le, de valójában ennyi az egész.