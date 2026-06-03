Az áthelyező konstruktor (move constructor) az egyik legfontosabb újítás a C++11-ben.

A másoló konstruktor eddig ezt csinálta:

```cpp
Szemely sz2(sz1);
sz1 --> "LONG_NAME"
           |
           | másolás
           v
sz2 --> "LONG_NAME"
```

Új memóriát foglal és átmásolja az adatokat.

------

Az áthelyező konstruktor viszont ezt mondja:

```text
Ne másold le!
Vedd el az erőforrást a forrás objektumtól!
```

Például:

```cpp
Szemely sz2(std::move(sz1));
```

Ekkor:

```text
előtte:

sz1 --> "LONG_NAME"

utána:

sz1 --> nullptr

sz2 --> "LONG_NAME"
```

A pointer egyszerűen átkerül az új objektumba.

Nem történik:

- új memóriafoglalás
- karakterenkénti másolás

Ezért sokkal gyorsabb lehet.

------

Az alakja:

```cpp
Szemely(Szemely&& masik)
{
}
```

A dupla `&&` itt nem logikai ÉS.

Ez úgynevezett **rvalue referencia**.

Példa:

```cpp
Szemely(Szemely&& masik)
{
    mNev = masik.mNev;
    masik.mNev = nullptr;
}
```

Nagyon fontos a:

```cpp
masik.mNev = nullptr;
```

különben mindkét objektum ugyanarra a memóriára mutatna, és újra double delete lenne.

------

A destruktor ilyenkor általában:

```cpp
~Szemely()
{
    delete mNev;
}
```

mert:

```text
eredeti objektum:
mNev = nullptr

új objektum:
mNev = valódi cím
```

A `delete nullptr;` teljesen biztonságos C++-ban.

------

Amikor majd eljutsz idáig, három fontos fogalom lesz egymás mellett:

```cpp
Szemely(const Szemely& s);
```

Másoló konstruktor

```cpp
Szemely& operator=(const Szemely& s);
```

Másoló értékadás

```cpp
Szemely(Szemely&& s);
```

Áthelyező konstruktor

és később:

```cpp
Szemely& operator=(Szemely&& s);
```

Áthelyező értékadás

Ezek együtt alkotják a modern C++ egyik alapját. A te példád a nyers pointeres `std::string*`-gel kifejezetten jó lesz arra, hogy lásd a különbséget a másolás és az áthelyezés között, mert a memóriacímek változását is meg tudod majd figyelni.

```cpp
// C++ 2011 től kezdve a programozó
//létrehozhat egy "ÁTHELYEZŐ"
//erőforrásokat áthelyező konstruktort
//amely az erőforrásokat 'NEM MÁSOLJA'
//hanem a célforráshoz helyezi át.
//formátuma : X::X(X&&)
//pl: Tanulo(Tanulo &&t);
// -----példa program------
//
//========ÁTHEYLEZŐ KONSTRUKTOR=======
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Szemely
{
public:
    Szemely(const char *mN)
    {
        mNev = new std::string(mN);
        std::cout <<*mNev <<" felépítése" <<'\n';
    }
    //másolunk
    Szemely(const Szemely &sz)
    {
        std::cout <<*sz.mNev <<" másolása" <<'\n';
        mNev = new std::string(" másolata");
        *mNev += *sz.mNev;
    }
    //Áthelyező konstruktor
    Szemely(Szemely &&sz)
    {
        std::cout <<*sz.mNev <<" áthelyezése" <<'\n';
        mNev = sz.mNev;
        sz.mNev = nullptr;
    }
    //Destruktor
    ~Szemely()
    {
        if(mNev)
        {
            std::cout<< *mNev <<" megsemmisítése" <<'\n';
            delete mNev;
        }
        else
        {
            std::cout <<" Null értékű objektum megsemmisítése" << '\n';
        }
    }

protected:
    std::string* mNev;
};
//függvényeink
Szemely fv2(Szemely sz)
{
    std::cout << " Belépés az fv2-be"<<'\n';
    return sz;
}
Szemely fv1(const char* mNev)
{
    std::cout <<" Belépés az fv1-be" <<'\n';
                Szemely temp(mNev);
                return fv2(temp);

                //Itt memóriaSzivárgás történik.
              //return fv2(*new Szemely(mNev));
}

int main(int argc, char** argv)
{
    //stack
    Szemely t(fv1("Anonime"));
    //heap
    Szemely *SzT = new Szemely(fv1("Anonimus"));

    delete SzT;
    //kilépünk
    std::cout <<"A kilépéshez kérlek nyomd meg kétszer az entert...."<<std::endl;

    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
                    std::cin.get();

                    return 0;
}
```

Ez tényleg egy nehezebb példa, mert egyszerre mutatja be:

- konstruktor
- másoló konstruktor
- move konstruktor
- függvényparaméter másolása
- objektum visszaadása függvényből
- stack és heap objektumokat

Menjünk végig az első híváson:

```cpp
Szemely t(fv1("Anonime"));
```

------

# 1. Belépünk az fv1-be

```cpp
Szemely fv1(char* mNev)
{
    std::cout <<" Belépés az fv1-be" <<'\n';

    Szemely temp(mNev);

    return fv2(temp);
}
```

Kiírja:

```text
Belépés az fv1-be
```

------

# 2. Létrejön a temp objektum

```cpp
Szemely temp(mNev);
```

Meghívódik:

```cpp
Szemely(const char *mN)
```

Lefoglal egy stringet:

```text
temp
 |
 +-----> "Anonime"
```

Kiírja:

```text
Anonime felépítése
```

------

# 3. Meghívjuk az fv2-t

```cpp
fv2(temp);
```

Az fv2 paramétere:

```cpp
Szemely fv2(Szemely sz)
```

Figyeld:

```cpp
Szemely sz
```

nem referencia.

Ez azt jelenti, hogy másolni kell.

Meghívódik:

```cpp
Szemely(const Szemely &sz)
```

Létrejön egy új objektum:

```text
temp
 |
 +-----> "Anonime"

sz
 |
 +-----> " másolataAnonime"
```

Kiírja:

```text
Anonime másolása
```

------

# 4. Belépünk fv2-be

```cpp
std::cout << " Belépés az fv2-be";
```

Kiírja:

```text
Belépés az fv2-be
```

------

# 5. Visszatérés

```cpp
return sz;
```

Itt jön képbe a move konstruktor.

A fordító látja, hogy az fv2 véget ér.

A helyi változó:

```cpp
sz
```

hamarosan megszűnik.

Ezért ahelyett hogy másolna:

```cpp
Szemely(const Szemely&)
```

megpróbál áthelyezni:

```cpp
Szemely(Szemely&&)
```

------

# 6. Move konstruktor

```cpp
Szemely(Szemely &&sz)
{
    mNev = sz.mNev;
    sz.mNev = nullptr;
}
```

Előtte:

```text
sz
 |
 +-----> " másolataAnonime"
```

Utána:

```text
új objektum
 |
 +-----> " másolataAnonime"

sz
 |
 +-----> nullptr
```

Kiírja:

```text
másolataAnonime áthelyezése
```

------

# 7. fv2 vége

A helyi:

```cpp
sz
```

megsemmisül.

De:

```cpp
sz.mNev == nullptr
```

ezért:

```text
Null értékű objektum megsemmisítése
```

------

# 8. fv1 vége

A helyi:

```cpp
temp
```

megsemmisül.

Ő még birtokolja:

```text
"Anonime"
```

ezért:

```text
Anonime megsemmisítése
```

------

# 9. main-ben létrejön t

Most:

```cpp
Szemely t(...)
```

birtokolja:

```text
" másolataAnonime"
```

------

# Miért jó a move?

Másolás esetén:

```text
LONG_STRING
↓
új memória
↓
összes karakter másolása
```

Move esetén:

```text
pointer átadása
↓
régi pointer nullptr
```

Nagy objektumoknál ez óriási különbség.

------

# Ami a legfontosabb ebből a példából

A másoló konstruktor:

```cpp
Szemely(const Szemely&)
```

új erőforrást hoz létre.

```text
régi -----> "szöveg"

új  -----> "szöveg"
```

Az áthelyező konstruktor:

```cpp
Szemely(Szemely&&)
```

nem másol.

```text
régi -----> nullptr

új  -----> "szöveg"
```

A tulajdonjog egyszerűen átkerül az új objektumba. Ez a modern C++ move szemléletének lényege.

**OUTPUT**

```cpp
 Belépés az fv1-be
Anonime felépítése
Anonime másolása
 Belépés az fv2-be
 másolataAnonime áthelyezése
 Null értékű objektum megsemmisítése
Anonime megsemmisítése
 Belépés az fv1-be
Anonimus felépítése
Anonimus másolása
 Belépés az fv2-be
 másolataAnonimus áthelyezése
 Null értékű objektum megsemmisítése
Anonimus megsemmisítése
 másolataAnonimus megsemmisítése
A kilépéshez kérlek nyomd meg kétszer az entert....

```

Igen, a modern C++ nagyon sokat használja az áthelyezést (move), gyakran anélkül, hogy észrevennéd.

Például:

```cpp
std::string nev = "Pista";

std::vector<std::string> v;

v.push_back(std::move(nev));
```

Itt a string tartalma általában áthelyeződik a vektorba, nem másolódik.

------

De a másolásra továbbra is szükség van.

A kérdés az:

```text
Ugyanazt az adatot két helyen akarom használni?
```

Ha igen, akkor másolni kell.

Például:

```cpp
std::string a = "Hello";
std::string b = a;
```

Itt azt akarod, hogy:

```text
a = "Hello"
b = "Hello"
```

mindkettő külön létezzen.

Ez másolás.

------

Ha viszont az eredeti objektumra már nincs szükség:

```cpp
std::string a = "Hello";
std::string b = std::move(a);
```

akkor:

```text
a = üres / érvényes, de nem meghatározott állapot
b = "Hello"
```

Ilyenkor fölösleges másolni.

------

Képzeld el egy nagy fájl nevét vagy egy 100 MB-os adatblokkot.

Másolás:

```text
100 MB
↓
új 100 MB
↓
100 MB adat másolása
```

Move:

```text
pointer átadása
↓
kész
```

Ez sokkal gyorsabb.

------

A valóságban a legtöbb C++ programozó nem ír kézzel ilyen move konstruktort, mint a példádban, mert a standard könyvtár már megcsinálja helyettük.

Például:

```cpp
std::string
std::vector
std::unique_ptr
std::map
```

mind támogatják a move szemléletet.

------

A te példád inkább tanulási célú.

Valós projektekben ritkán látsz ilyet:

```cpp
std::string* mNev;
```

Inkább:

```cpp
std::string mNev;
```

vagy

```cpp
std::unique_ptr<std::string> mNev;
```

A fordító és a standard könyvtár ilyenkor sok move műveletet automatikusan elvégez.

------

Röviden:

- **Másolás**: amikor az eredeti és az új objektum is megmarad.
- **Move**: amikor az eredeti objektum erőforrását átadjuk az újnak.
- A modern C++ rengeteget használ move-ot teljesítmény miatt.
- A másolás viszont továbbra is szükséges, mert sokszor ugyanazt az adatot több objektumban is meg akarjuk tartani.