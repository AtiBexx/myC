# Kommentelési szokások C++, Java és Kotlin nyelvekben

## Áttekintés

A dokumentációs kommentek fontos szerepet játszanak a kód olvashatóságában és karbantarthatóságában. Mindhárom nyelv támogatja a dokumentáció írását, de a gyakorlatban eltérhet a használatuk.

---

## C++

### Szokásos kommentelési formák

- `//` – egy soros komment
- `/* ... */` – többsoros komment
- `/** ... */` – dokumentációs komment (Doxygen által felismerhető)

### Doxygen dokumentáció

A `/** ... */` formátumot a [Doxygen](https://www.doxygen.nl/) eszköz ismeri fel, és dokumentációt generál belőle (HTML, LaTeX, stb.).

Példa:
```cpp
/**
 * @brief Két szám összeadása
 * @param a Az első operandus
 * @param b A második operandus
 * @return Az a és b összege
 */
int add(int a, int b) {
    return a + b;
}
```

### Használat

- **Nem kötelező**, de ajánlott nagyobb projekteknél
- Doxygen nem része a nyelvnek, hanem külső eszköz
- C++ nem rendelkezik beépített dokumentációgeneráló eszközzel, mint Java a Javadoc-nál

---

## Java

### Dokumentációs komment

- `/** ... */` – dokumentációs komment
- A `javadoc` eszköz ebből generál dokumentációt

Példa:
```java
/**
 * Ez a függvény összead két egész számot.
 *
 * @param a az első szám
 * @param b a második szám
 * @return a két szám összege
 */
public int add(int a, int b) {
    return a + b;
}
```

---

## Kotlin

### Dokumentációs komment

- Hasonlóan működik, mint Java-ban
- `/** ... */` – dokumentációs komment
- Támogatja a Javadoc-szerű dokumentáció írását

Példa:
```kotlin
/**
 * Ez a függvény összead két egész számot.
 *
 * @param a az első szám
 * @param b a második szám
 * @return a két szám összege
 */
fun add(a: Int, b: Int): Int {
    return a + b
}
```

---

## Ajánlás C++ esetén

### Használjam Doxygent vagy sima kommentet?

Ez függ a projekt típusától és céljától:

- **Nagyobb projektek**: Doxygen használata javasolt, főleg ha dokumentációt is szeretnél generálni.
- **Kisebb projektek vagy tanulás**: Elég lehet a sima `//` vagy `/* */` komment is.
- **Csapatmunka**: Érdemes Doxygent használni, hogy a dokumentáció következetes és jól karbantartható legyen.

### Összefoglalás

| Nyelv | Dokumentációs komment | Eszköz |
|-------|------------------------|--------|
| C++   | `/** ... */`          | Doxygen (külső) |
| Java  | `/** ... */`          | Javadoc (beépített) |
| Kotlin| `/** ... */`          | Javadoc-szerű (támogatott) |

---

## Leggyakoribb Doxygen tag-ek

- `@brief` – rövid leírás
- `@param` – függvény paramétere
- `@return` – visszatérési érték leírása
- `@author` – szerző
- `@date` – dátum
- `@note` – megjegyzés
- `@warning` – figyelmeztetés
- `@see` – lásd még (hivatkozás más függvényre)
- `@todo` – teendők listázása
- `@code ... @endcode` – kódrészlet beszúrása dokumentációba

---

# Doxygen tag-ek Teljes Lista

- `@brief` – rövid leírás
- `@param` – függvény paramétere
- `@return` – visszatérési érték leírása
- `@author` – szerző
- `@date` – dátum
- `@note` – megjegyzés
- `@warning` – figyelmeztetés
- `@see` – lásd még (hivatkozás más függvényre)
- `@todo` – teendők listázása
- `@code ... @endcode` – kódrészlet beszúrása dokumentációba
- `@verbatim ... @endverbatim` – formázott szöveg (pl. pszeudokód)
- `@attention` – figyelemfelhívás
- `@since` – mikortól elérhető a funkció
- `@sa` – alternatíva a `@see` helyett
- `@retval` – visszatérési érték specifikus értékekhez
- `@pre` – előfeltétel
- `@post` – utófeltétel
- `@invariant` – invariáns állapot
- `@remark` – megjegyzés vagy kiegészítő információ
- `@par` – alcím vagy szakasz címe dokumentációban
- `@li` – lista elem (felsorolás)
- `@link ... @endlink` – belső hivatkozás más objektumra
- `@anchor` – horgony létrehozása dokumentáción belül
- `@copydoc` – más dokumentációból való másolás
- `@addtogroup` – csoportosítás alacsonyabb szinten
- `@page` – új dokumentációs oldal
- `@section` – szakasz címe
- `@subsection` – alcím
- `@subsubsection` – al-alcím
- `@image` – kép beszúrása dokumentációba (pl. `@image html image.png`)
- `@dotfile` – DOT fájl grafikonként történő megjelenítése
- `@htmlinclude` – HTML fájl beillesztése dokumentációba
- `@latexinclude` – LaTeX fájl beillesztése dokumentációba
------------



**kategóriákra bontva:**

------

## **1. Dokumentációs blokkok**

- `@file` – fájl dokumentálása
- `@brief` – rövid leírás
- `@details` – részletes leírás
- `@author` – szerző
- `@date` – dátum
- `@version` – verzió
- `@copyright` – szerzői jog
- `@mainpage` – főoldal
- `@page` – új dokumentációs oldal
- `@subpage` – aloldal
- `@section` – szakasz
- `@subsection` – alszakasz
- `@subsubsection` – al-alszakasz
- `@paragraph` – bekezdés

------

## **2. Kód elemek dokumentálása**

- `@class` – osztály
- `@struct` – struktúra
- `@union` – unió
- `@enum` – felsorolás
- `@fn` – függvény
- `@var` – változó
- `@def` – makró
- `@typedef` – típusdefiníció
- `@namespace` – névtér
- `@interface` – interfész
- `@protocol` – protokoll (Objective-C)
- `@category` – kategória (Objective-C)
- `@property` – tulajdonság (Objective-C)
- `@package` – csomag (Java)

------

## **3. Csoportosítás**

- `@defgroup` – csoport definiálása
- `@addtogroup` – meglévő csoporthoz adás
- `@ingroup` – elem csoportba sorolása
- `@weakgroup` – gyenge csoport (opcionális)
- `@name` – csoport elnevezése
- `@{` – csoport kezdete
- `@}` – csoport vége
- `@nosubgrouping` – alcsoportosítás tiltása

------

## **4. Paraméterek és visszatérési értékek**

- `@param` – paraméter dokumentálása
- `@param[in]` – bemeneti paraméter
- `@param[out]` – kimeneti paraméter
- `@param[in,out]` – kétirányú paraméter
- `@tparam` – template paraméter
- `@return` – visszatérési érték
- `@retval` – konkrét visszatérési érték
- `@result` – eredmény (alternatíva @return)

------

## **5. Kivételek és hibák**

- `@exception` – kivétel dokumentálása
- `@throw` – kivétel dobása (alternatíva)
- `@throws` – kivétel dobása (alternatíva)

------

## **6. Figyelmeztetések és megjegyzések**

- `@note` – megjegyzés
- `@warning` – figyelmeztetés
- `@attention` – figyelem
- `@remark` – megjegyzés
- `@todo` – tennivaló
- `@bug` – hiba
- `@test` – teszt
- `@deprecated` – elavult
- `@since` – mióta létezik
- `@pre` – előfeltétel
- `@post` – utófeltétel
- `@invariant` – invariáns feltétel

------

## **7. Példák és kódrészletek**

- `@code` – kódblokk kezdete
- `@endcode` – kódblokk vége
- `@verbatim` – szó szerinti szöveg
- `@endverbatim` – szó szerinti szöveg vége
- `@example` – példa fájl
- `@snippet` – kódrészlet fájlból
- `@dontinclude` – fájl kihagyása
- `@include` – fájl beillesztése
- `@includelineno` – fájl beillesztése sorszámokkal
- `@line` – egyetlen sor beillesztése
- `@skip` – sorok kihagyása
- `@skipline` – egy sor kihagyása
- `@until` – sorok beillesztése adott sorig

------

## **8. Hivatkozások és linkek**

- `@ref` – hivatkozás elemre
- `@see` – lásd még
- `@sa` – lásd még (alternatíva)
- `@link` – link kezdete
- `@endlink` – link vége
- `@cite` – bibliográfiai hivatkozás
- `@anchor` – horgony pont
- `@relatesalso` – kapcsolódó elem
- `@related` – kapcsolódó elem
- `@relates` – kapcsolódó elem

------

## **9. Láthatóság és hozzáférés**

- `@public` – publikus
- `@protected` – védett
- `@private` – privát
- `@static` – statikus
- `@internal` – belső dokumentáció
- `@endinternal` – belső dokumentáció vége

------

## **10. Öröklés és kapcsolatok**

- `@extends` – kiterjesztés
- `@implements` – implementáció
- `@memberof` – tagja egy osztálynak/névtérnek
- `@overload` – túlterhelés

------

## **11. Gráfok és diagramok**

- `@dot` – Graphviz dot gráf kezdete
- `@enddot` – dot gráf vége
- `@msc` – Message Sequence Chart
- `@endmsc` – MSC vége
- `@startuml` – PlantUML diagram (plugin)
- `@enduml` – PlantUML vége
- `@callgraph` – hívási gráf megjelenítése
- `@callergraph` – hívó gráf megjelenítése
- `@hidecallgraph` – hívási gráf elrejtése
- `@hidecallergraph` – hívó gráf elrejtése
- `@inheritancegraph` – öröklődési gráf
- `@hideinheritancegraph` – öröklődési gráf elrejtése
- `@collaborationgraph` – együttműködési gráf
- `@hideCollaborationgraph` – együttműködési gráf elrejtése
- `@directorygraph` – könyvtár gráf
- `@includegraph` – include gráf
- `@includedbygraph` – fordított include gráf

------

## **12. Formázás**

- `@a` – kurzív (argumentum)
- `@b` – félkövér
- `@c` – monospace (kód)
- `@e` – kurzív (emphasis)
- `@em` – kurzív
- `@p` – monospace (paraméter)
- `@n` – újsor
- `@li` – lista elem
- `@arg` – argumentum lista elem
- `@parblock` – paragrafus blokk kezdete
- `@endparblock` – paragrafus blokk vége
- `@verbatim` – formázatlan szöveg
- `@latexonly` – csak LaTeX kimenetben
- `@endlatexonly`
- `@htmlonly` – csak HTML kimenetben
- `@endhtmlonly`
- `@xmlonly` – csak XML kimenetben
- `@endxmlonly`
- `@manonly` – csak man kimenetben
- `@endmanonly`
- `@rtfonly` – csak RTF kimenetben
- `@endrtfonly`
- `@docbookonly` – csak DocBook kimenetben
- `@enddocbookonly`

------

## **13. Táblázatok**

- `@table` – táblázat kezdete
- `@endtable` – táblázat vége

------

## **14. Listák**

- `@li` – lista elem
- `@arg` – argumentum lista

------

## **15. Másolás és újrafelhasználás**

- `@copydoc` – teljes dokumentáció másolása
- `@copybrief` – rövid leírás másolása
- `@copydetails` – részletes leírás másolása

------

## **16. Feltételes dokumentáció**

- `@cond` – feltételes blokk kezdete
- `@endcond` – feltételes blokk vége
- `@if` – feltétel
- `@ifnot` – negált feltétel
- `@else` – különben
- `@elseif` – egyébként ha
- `@endif` – feltétel vége

------

## **17. Egyéb speciális parancsok**

- `@headerfile` – fejlécfájl dokumentálása
- `@addindex` – index hozzáadása
- `@printindex` – index nyomtatása (LaTeX)
- `@xrefitem` – egyedi kereszthivatkozás
- `@short` – rövid verzió
- `@showinitializer` – inicializáló megjelenítése
- `@hideinitializer` – inicializáló elrejtése
- `@tableofcontents` – tartalomjegyzék
- `@image` – kép beillesztése

------

