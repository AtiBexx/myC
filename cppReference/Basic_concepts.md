# C++ 

### Basic Concepts

### Alapfogalmak

 

This section provides definitions for the specific terminology and the concepts used when describing the C++ programming language.

Ez a szakasz definiálja a specifikus terminológiát és azokat a koncepciókat, amelyeket a C++ programozási nyelv leírásakor alkalmazunk.

A C++ program is a sequence of text files (typically header and source files) that contain [declarations](https://cppreference.com/cpp/language/declarations). They undergo [translation](https://cppreference.com/cpp/language/translation_phases) to become an executable program, which is executed when the C++ implementation calls its [main function](https://cppreference.com/cpp/language/main_function).

Egy C++ program szöveges fájlok sorozata (általában fejlécek és forrásfájlok), amelyek deklarációkat tartalmaznak. Ezek egy fordítási folyamaton (*translation*) mennek keresztül, hogy végrehajtható programmá váljanak, amelyet a C++ implementáció a `main` függvény meghívásával futtat.

Certain words in a C++ program have special meaning, and these are known as [keywords](https://cppreference.com/cpp/keyword). Others can be used as [identifiers](https://cppreference.com/cpp/language/identifiers). [Comments](https://cppreference.com/cpp/comment) are ignored during translation. C++ programs also contain [literals](https://cppreference.com/cpp/language/expressions#Literals), the values of characters inside them are determined by [character sets and encodings](https://cppreference.com/cpp/language/charset). Certain characters in the program have to be represented with [escape sequences](https://cppreference.com/cpp/language/escape).

A C++ program bizonyos szavainak különleges jelentése van; ezeket kulcsszavaknak (*keywords*) nevezik. Más szavak azonosítóként (*identifiers*) használhatók. A megjegyzéseket a fordítás során figyelmen kívül hagyják. A C++ programok literálokat is tartalmaznak; ezekben szerepelő karakterek értékeit a karakterkészletek és a kódolások határozzák meg. A program bizonyos karaktereit menetvázolt szekvenciákkal (*escape sequences*) kell reprezentálni.

The *entities* of a C++ program are values, [objects](https://cppreference.com/cpp/language/objects), [references](https://cppreference.com/cpp/language/reference), [structured bindings](https://cppreference.com/cpp/language/structured_binding)(since C++17), [result bindings](https://cppreference.com/cpp/language/function#Postcondition_assertions)(since C++26), [functions](https://cppreference.com/cpp/language/functions), [enumerators](https://cppreference.com/cpp/language/enum), [types](https://cppreference.com/cpp/language/type), class members, [templates](https://cppreference.com/cpp/language/templates), [template specializations](https://cppreference.com/cpp/language/template_specialization), [packs](https://cppreference.com/cpp/language/pack)(since C++11), and [namespaces](https://cppreference.com/cpp/language/namespace). Preprocessor [macros](https://cppreference.com/cpp/preprocessor/replace) are not C++ entities.

A C++ program entitásai: az értékek, objektumok, referenciák, strukturált kötések (*structured bindings*, C++17-től), eredmény-kötések (*result bindings*, C++26-tól), függvények, enumerátorok, típusok, osztálytagok, sablonok, sablon-speciálisítások, csomagok (*packs*, C++11-től) és névterek. Az előprocesszor makrók nem C++ entitások.

[Declarations](https://cppreference.com/cpp/language/declarations) may introduce entities, associate them with [names](https://cppreference.com/cpp/language/name) and define their properties. The declarations that define all properties required to use an entity are [definitions](https://cppreference.com/cpp/language/definition). A program must contain only one definition of any non-inline function or variable that is [odr-used](https://cppreference.com/cpp/language/definition#ODR-use).

A deklarációk bevezethetnek entitásokat, hozzárendelhetnek hozzájuk neveket és meghatározhatják tulajdonságaikat. Azok a deklarációk, amelyek egy entitás használatához szükséges *minden* tulajdonságot meghatározzák, definícióknak nevezhetők. Egy programnak csak egyetlen definíciója lehet bármely nem-inline függvénynek vagy változónak, amely *odr-used* (azaz az ODR-szabály szerint használt).

Definitions of functions usually include sequences of [statements](https://cppreference.com/cpp/language/statements), some of which include [expressions](https://cppreference.com/cpp/language/expressions), which specify the computations to be performed by the program.

A függvénydefiníciók általában utasítások sorozatait tartalmazzák, amelyek egy része kifejezésekből áll; ezek határozzák meg a program által végrehajlandó számításokat.

Names encountered in a program are associated with the declarations that introduced them using [name lookup](https://cppreference.com/cpp/language/lookup). Each name is only valid within a part of the program called its [scope](https://cppreference.com/cpp/language/scope). Some names have [linkage](https://cppreference.com/cpp/language/storage_duration) which makes them refer to the same entities when they appear in different scopes or translation units.

A programban előforduló nevek a névkeresés (*name lookup*) révén kapcsolódnak hozzá azokat bevezető deklarációkhoz. Minden név csak a program egy meghatározott részén érvényes, amelyet a név hatókörének (*scope*) nevezünk. Egyes nevek rendelkeznek kapcsolattal (*linkage*), amely lehetővé teszi, hogy különböző hatókörökben vagy fordításegységekben megjelenve ugyanazokat az entitásokat hivatkozzanak.

Each object, reference, function, expression in C++ is associated with a [type](https://cppreference.com/cpp/language/type), which may be [fundamental](https://cppreference.com/cpp/language/types), compound, or [user-defined](https://cppreference.com/cpp/language/classes), complete or [incomplete](https://cppreference.com/cpp/language/incomplete_type), etc.

A C++ minden objektuma, referenciája, függvénye és kifejezése egy típushoz kötött, amely alapvető (*fundamental*), összetett (*compound*) vagy felhasználó által definiált lehet, illetve teljes vagy nem teljes stb.

Declared objects and declared references that are not [non-static data members](https://cppreference.com/cpp/language/data_members) are *variables* ﻿.

A deklarált objektumok és deklarált referenciák, amelyek nem statikus adattagok, változóknak számítanak.