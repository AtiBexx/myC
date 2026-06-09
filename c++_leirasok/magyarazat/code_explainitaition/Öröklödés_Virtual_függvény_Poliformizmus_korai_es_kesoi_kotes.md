### Öröklődés és_VIRTUÁL_FÜGGVÉNY_

##### Korai kötés ->LATE BINDING

```cpp
// TúlterhelésFelüldefiniálás
// Azt szemlélteti ,amikor egy függvény
// fordítási időben van túlterhelve
// illetve futásidőben van felülbírálva

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
    public:
      // vedd ki a megjegyzésből az egyiket vagy a másikat
    // a következő két sor közül; az egyik korán köti a tandijKiszamitas()-t,
    // a másik pedig későn

    void tandijKiszamitas() //korán kötés
    //virtual void tandijKiszamitas() //késsői kötés
    {
        std:: cout << "Ez a hallgato::tandijKiszamitas" <<'\n';
    }
};
//öröklödés
class vegzosHallgato : public Hallgato
{
public:
    void tandijKiszamitas()
    {
        std::cout <<"Ez a vegzős hallgato::tandijKiszamitas" <<'\n';
    }
};
void fv(Hallgato &x)
{
    x.tandijKiszamitas(); // -> ez melyik tandijKiszamitas()?
}
//=====================
int main(int argc,char** argv)
{
    // átadunk egy alaposztályú objektumot a függvénynek
    //objektum
    //[stack]
    Hallgato h;
    fv(h);

    vegzosHallgato vh;
    fv(vh);

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg kétszer az ENTERT..."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return 0;
}

```

**OUTPUT:**

```cpp
Ez a hallgato::tandijKiszamitas
Ez a hallgato::tandijKiszamitas
A folytatáshoz kérlek nyomd meg kétszer az ENTERT...

```

##### Másik kód Késői kötés -> EARLY BINDING

--------------

```cpp
// TúlterhelésFelüldefiniálás
// Azt szemlélteti ,amikor egy függvény
// fordítási időben van túlterhelve
// illetve futásidőben van felülbírálva

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
    public:
      // vedd ki a megjegyzésből az egyiket vagy a másikat
    // a következő két sor közül; az egyik korán köti a tandijKiszamitas()-t,
    // a másik pedig későn

    //void tandijKiszamitas() //korán kötés
    virtual void tandijKiszamitas() //késsői kötés
    {
        std:: cout << "Ez a hallgato::tandijKiszamitas" <<'\n';
    }
};
//öröklödés
class vegzosHallgato : public Hallgato
{
public:
    void tandijKiszamitas()
    {
        std::cout <<"Ez a vegzős hallgato::tandijKiszamitas" <<'\n';
    }
};
void fv(Hallgato &x)
{
    x.tandijKiszamitas(); // -> ez melyik tandijKiszamitas()?
}
//=====================
int main(int argc,char** argv)
{
    // átadunk egy alaposztályú objektumot a függvénynek
    //objektum
    //[stack]
    Hallgato h;
    fv(h);

    vegzosHallgato vh;
    fv(vh);

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg kétszer az ENTERT..."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return 0;
}
```

**OUTPUT:**

```cpp
Ez a hallgato::tandijKiszamitas
Ez a vegzős hallgato::tandijKiszamitas
A folytatáshoz kérlek nyomd meg kétszer az ENTERT...

```



------

#### 1. Korai kötés vs késői kötés

##### Korai kötés (early binding)

- fordítási időben eldől, melyik függvény fut
- NINCS `virtual`

példád:

```cpp
void tandijKiszamitas()
```

a hívás:

- **gyorsabb**
- direkt hívás (assembly-ben fix cím)

------

##### Késői kötés (late binding / dynamic dispatch)

- futási időben dől el
- `virtual` kell

példában:

```cpp
virtual void tandijKiszamitas()
```

 ilyenkor:

- vtable (virtuális tábla)
- pointeren keresztül hívás

------

##  2. Melyik a gyorsabb?

### Korai kötés:

 gyorsabb
direkt hívás
nincs extra lookup

###  Késői kötés (virtual):

 picit lassabb
1 extra indirekció (vtable lookup)

------

####  De fontos igazság:

> a különbség **nagyon kicsi** (nanomásodperc szint)

A modern CPU-knál:

- cache-ben van a vtable
- branch prediction segít
- gyakran elhanyagolható

 tehát:

> 99%-ban nem ez lesz a bottleneck

------

####  3. Polimorfizmus melyikhez tartozik?

##### Polimorfizmus = késői kötés

```cpp
Hallgato &x
x.tandijKiszamitas();
```

ez:

 runtime polymorphism
virtual dispatch
 késői kötés

------

###  Két fajta polimorfizmus:

#### 1. Compile-time (korai kötés)

- function overloading
- operator overloading
- templates

 ez **nem virtual**

------

#### 2. Runtime (késői kötés)

- virtual functions
- inheritance
- pointer / reference base class

**ez az igazi OOP polimorfizmus**

------

#### 4. „A C is támogatja a korai kötést?”

 IGEN, de másképp

A C-ben:

- nincs OOP
- nincs virtual
- nincs polimorfizmus

De:

 minden függvényhívás **alapból early binding**
 a fordító fixen tudja a címet

------

### C vs C++ különbség:

| Nyelv | kötés típusa         | polimorfizmus |
| ----- | -------------------- | ------------- |
| C     | csak early binding   | nincs         |
| C++   | early + late binding | van           |

------

##### 5. A példa mit csinál?

```cpp
Hallgato h;
fv(h); // Hallgato::tandijKiszamitas()

vegzosHallgato vh;
fv(vh); // vegzosHallgato::tandijKiszamitas()
```

 mert:

- `Hallgato &x`
- virtual → runtime eldönti

------

#####  6. Egyszerű mentális modell

##### Korai binding:

> „már fordításkor tudom mit hívok”

##### Késői binding:

> „majd futáskor kiderül ki vagy”

------

#  Összefoglalás

- ✔ korai kötés = gyorsabb
- ✔ virtual = picit lassabb
- ✔ polimorfizmus = késői kötés
- ✔ C = csak korai kötés
- ✔ C++ = mindkettő

------

Jó kérdés — itt jön az a rész, ahol a “gyorsabb = jobb” gondolat már nem igaz 👍

A **futásidejű (virtual / late binding) polimorfizmust nem azért használják, mert gyors**, hanem mert **rugalmas**.

------

###  Mikor kell futásidejű (virtual) kötés?

###  Akkor, amikor NEM tudod előre a típust

Példák:

### 1. Játékok

```cpp
Enemy* e = getRandomEnemy();
e->attack();
```

Nem tudod fordításkor:

- skeleton lesz?
- zombie?
- boss?

futásidőben derül ki

------

### 2. Plugin / modul rendszer

```cpp
Shape* s = loadShapeFromFile();
s->draw();
```

Nem tudod:

- circle
- square
- triangle

 csak futáskor

------

### 3. Frameworkök / API-k

Pl. GUI rendszerek:

- Button
- TextBox
- Window

Mind ugyanazt az interfészt használja:

```cpp
widget->render();
```

------

### 4. Dependency injection / clean architecture

```cpp
Database* db = new MySQL();
db->connect();
```

Holnap lehet:

- PostgreSQL
- SQLite

kód nem változik

------

###  Miért nem mindig korai kötés?

Mert a korai kötés:

- fixálja a típust fordításkor
-  nem tudod kicserélni runtime

- nem rugalmas

------

### Egyszerű döntési szabály

### Használj korai kötést, ha:

 tudod a típust előre
 performance kritikus (pl. engine loop)
 nincs szükség változó viselkedésre

------

### Használj késői kötést (virtual), ha:

 többféle objektumot akarsz kezelni egységesen
 plugin / bővíthetőség kell
 runtime döntés szükséges

------

###  Fontos valóság (nagyon lényeges)

A modern C++ fordítók:

 sokszor **ki is optimalizálják a virtual-t**

- devirtualization
- inlining
- LTO

Tehát:

> virtual ≠ mindig lassú a gyakorlatban

------

###  Egy mondatban:

> Korai kötés = gyors, de merev
> Késői kötés = rugalmas, de picit komplex

------

###  A kódban:

```cpp
Hallgato& x
x.tandijKiszamitas();
```

 ez azért jó, mert:

- nem érdekel milyen típus
- csak az érdekel, hogy „tud tandíjat számolni”

------

Igen — **C-ben ezt “OOP-san” tényleg nem oldották meg nyelvi szinten**, de attól még *meg lehet csinálni kézzel*. Csak nincs hozzá beépített `virtual`, `class`, `inheritance`.

------

####  Rövid válasz:

 C-ben **nincs polimorfizmus nyelvi szinten**,
de **struct + function pointerekkel szimulálják**.

------

####  Hogyan csinálják C-ben?

####  1. “Objektum” = struct

```c
typedef struct {
    int type;
} Hallgato;
```

------

####  2. “Virtual function” = function pointer

```c
typedef struct {
    int type;
    void (*tandijKiszamitas)(void*);
} Hallgato;
```

------

#### 3. Külön implementációk

```c
void alapszintu_tandij(void* self) {
    printf("Alap hallgato\n");
}

void vegzos_tandij(void* self) {
    printf("Vegzos hallgato\n");
}
```

------

#### 4. “Objektum létrehozás”

```c
Hallgato h;
h.type = 1;
h.tandijKiszamitas = alapszintu_tandij;
Hallgato vh;
vh.type = 2;
vh.tandijKiszamitas = vegzos_tandij;
```

------

####  5. Hívás

```c
h.tandijKiszamitas(&h);
vh.tandijKiszamitas(&vh);
```

 ez már majdnem ugyanaz, mint C++ virtual

------

####  Mi történik valójában?

## C++:

- compiler csinál vtable-t
- automatikus dispatch

## C:

- TE csinálod kézzel
- function pointer table vagy struct

------

####  C vs C++ különbség

| dolog        | C      | C++         |
| ------------ | ------ | ----------- |
| class        | ❌      | ✔           |
| inheritance  | ❌      | ✔           |
| virtual      | ❌      | ✔           |
| polymorphism | kézzel | automatikus |
| vtable       | kézzel | compiler    |

------

####  Valóság (nagyon fontos)

 A C++ virtual = **automatikus C-s hack**

Tehát:

> C-ben nincs “sehogy”
> csak “neked kell megírni”

------

#### Egyszerű gondolat

- C = alacsony szintű építőkockák
- C++ = ezekből összerakott OOP rendszer

------

####  Extra érdekesség

A C++ vtable:

 gyakorlatilag ugyanaz, mint amit C-ben kézzel csináltál
csak:

- automatikus
- optimalizált
- rejtett

------

####  Összefoglalás

-  **C-ben nincs beépített polimorfizmus**
- de function pointerekkel megoldható
- C++ ezt automatizálja virtual-lal
- a háttér elv ugyanaz

#### C verzió (polimorfizmus kézzel)

####  1. “Base struct + function pointer” (mint virtual)

```
#include <stdio.h>

typedef struct Hallgato Hallgato;

struct Hallgato {
    void (*tandijKiszamitas)(Hallgato* self);
};
```

 Ez a “virtual function” C-ben.

------

####  2. Alap implementáció

```
void alapszintu_tandij(Hallgato* self)
{
    printf("Ez a hallgato::tandijKiszamitas\n");
}
```

------

####  3. “Végzős hallgató” verzió

```
void vegzos_tandij(Hallgato* self)
{
    printf("Ez a vegzos hallgato::tandijKiszamitas\n");
}
```

------

####  4. “Objektum létrehozás”

```
Hallgato h;
h.tandijKiszamitas = alapszintu_tandij;

Hallgato vh;
vh.tandijKiszamitas = vegzos_tandij;
```

------

#### 5. Függvény (mint C++ fv(Hallgato &x))

```
void fv(Hallgato* x)
{
    x->tandijKiszamitas(x);
}
```

------

####  6. main

```
int main()
{
    Hallgato h;
    h.tandijKiszamitas = alapszintu_tandij;

    Hallgato vh;
    vh.tandijKiszamitas = vegzos_tandij;

    fv(&h);
    fv(&vh);

    return 0;
}
```

------

####  Mi történik itt?

#### C++ verzió:

```
virtual void tandijKiszamitas();
```

 compiler automatikusan:

- vtable
- dynamic dispatch

------

#### C verzió:

 TE csinálod:

- function pointer
- manuális dispatch

------

####  Fontos felismerés

Ez a C kód gyakorlatilag:

> ugyanaz a mechanizmus, mint a C++ virtual

csak:

- nincs automatizálva
- nincs inheritance kezelés
- nincs type safety

```c
//Itt a **teljes, tiszta C verzió**, function pointeres „polimorfizmussal”, és a végén **buffer-tisztítással + kétszeres ENTER-várással**:
//c id="c_full_polymorph"
#include <stdio.h>
#include <stdlib.h>

// "Osztály" elődeklaráció
typedef struct Hallgato Hallgato;

// struct (base class)
struct Hallgato {
    void (*tandijKiszamitas)(Hallgato* self);
};

// Alap implementáció
void alapszintu_tandij(Hallgato* self)
{
    printf("Ez a hallgato::tandijKiszamitas\n");
}

// Végzős implementáció
void vegzos_tandij(Hallgato* self)
{
    printf("Ez a vegzos hallgato::tandijKiszamitas\n");
}

// "Polimorf" hívás
void fv(Hallgato* x)
{
    x->tandijKiszamitas(x);
}

int main()
{
    // alap hallgató
    Hallgato h;
    h.tandijKiszamitas = alapszintu_tandij;

    // végzős hallgató
    Hallgato vh;
    vh.tandijKiszamitas = vegzos_tandij;

    fv(&h);
    fv(&vh);

    // kilépés előtti várakozás
    printf("A folytatáshoz kérlek nyomd meg kétszer az ENTERT...\n");

    int c;

    // 1. ENTER + maradék tisztítás
	while ((c = getchar()) != '\n' && c != EOF);

	// 2. ENTER
	while ((c = getchar()) != '\n' && c != EOF);

    return 0;
}


```

**vagy**

```c
printf("A folytatáshoz kérlek nyomd meg kétszer az ENTERT...\n");

getchar();
getchar();
```

###  Java: késői kötés

 Java-ban ez **default viselkedés**:

```
Animal a = new Dog();
a.sound();
```

 futáskor dől el, hogy:

- Animal?
- Dog?

------

####  Fontos különbség C++-hoz képest

#### C++:

```
virtual void sound();
```

 TE mondod meg, hogy késői kötés legyen

------

#### Java:

```
void sound();
```

 alapból késői kötés (instance metódusoknál)

------

####  Hogyan működik Java-ban?

 ugyanaz az elv, mint C++-ban:

- JVM runtime dönt
- objektum valódi típusa számít
- method dispatch (dinamikus hívás)

------

####  Mikor NINCS késői kötés Java-ban?

####  static metódus

```
static void test()
```

 ez:

- korai kötés (compile-time)
- nem polimorf

------

####  final metódus

```
final void test()
```

 nem felülírható → nincs polymorphism

------

####  private metódus

 szintén nem override-olható

 **mind Kotlinban, mind Pythonban van késői kötés**, csak ott is kicsit más a modell, mint C++-ban.

------

###  Kotlin

####  Alap:

 Kotlin is **Java JVM-en fut**, ezért örökli a Java viselkedést.

####  Késői kötés van (default):

```kotlin
open class Animal {
    open fun sound() {
        println("animal sound")
    }
}

class Dog : Animal() {
    override fun sound() {
        println("woof")
    }
}
val a: Animal = Dog()
a.sound()
```

 futáskor dől el → **Dog.sound()**

------

####  Fontos Kotlinban:

- `open` kell → hogy override lehessen
- `override` kell → hogy felülírd

------

####  Kotlin summary:

> instance method = late binding (alapból)

------

###  Python

####  Python még lazább

 Pythonban **minden method dispatch runtime-ban történik**

```python
class Animal:
    def sound(self):
        print("animal")

class Dog(Animal):
    def sound(self):
        print("woof")

a = Dog()
a.sound()
```

 mindig futásidőben dől el

------

####  Python mechanizmus:

- nincs compile-time binding
- attribute lookup runtime
- `__dict__` + method resolution order (MRO)

------

####  Python különlegesség

 Python nem is “klasszikus vtable”-t használ, hanem:

- MRO (Method Resolution Order)
- dinamikus lookup

------

####  Összehasonlítás

| nyelv  | késői kötés        |
| ------ | ------------------ |
| C      | nincs              |
| C++    | virtual-lal        |
| Java   | alapból            |
| Kotlin | Java miatt         |
| Python | teljesen dinamikus |

------

####  Legfontosabb különbség

## C++:

- explicit virtual
- vtable

## Java/Kotlin:

- JVM method table
- implicit

## Python:

- teljes runtime lookup
- nincs fix table ugyanúgy

------

####  Egyszerű gondolat:

> minél “magasabb szintű” a nyelv, annál inkább automatikus a késői kötés

------

####  Egy mondat:

- Kotlin = Java OOP (JVM virtual dispatch)
- Python = teljesen dinamikus runtime dispatch

------

##  Python

 szinte **nincs klasszikus korai kötés metódusokra**

##  Kotlin

 van **korai kötés + késői kötés is**, mint Javában

------

####  Kotlin – korai kötés

Kotlin JVM-en fut, ezért ugyanaz, mint Java:

####  NEM virtual:

#### 1. `static jelleg` (companion object)

```
class A {
    companion object {
        fun test() {
            println("hello")
        }
    }
}
```

 ez:

- compile-time binding
- nincs override
- korai kötés

------

#### 2. `final` függvények

```
open class A {
    fun test() { }
}
```

 mivel nem `open`:

- nem override-olható
- korai kötés

------

#### 3. top-level functions

```
fun test() {}
```

 teljesen compile-time hívás

------

####  Python – korai kötés?

Pythonban ez kicsit trükkös:

####  Klasszikus értelemben:

 nincs igazi korai kötés metódusokra

####  de vannak kivételek:

#### 1. Built-in functions

```
len("abc")
```

 ez:

- C-ben implementált
- fix binding
- “kvázi early binding”

------

#### 2. module import

```
import math
math.sqrt(4)
```

 import idején:

- modul fixálódik
- név feloldás részben előre történik

------

#### 3. constants / direct references

```
x = 10
y = x + 2
```

 itt már compile bytecode szinten fixált értékek lehetnek

------

####  De Python alapelve:

**minden attribute lookup runtime**

```
obj.method()
```

 ez mindig:

- futás közben keres
- dinamikus dispatch