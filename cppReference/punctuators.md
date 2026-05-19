Íme a teljes szöveg magyar fordítással, megmaradva az eredeti angol verzióval és a szerkezettel, ahogy kérted.

------

[C++ language](https://cppreference.com/cpp/language) C++ nyelv

[Basic Concepts](https://cppreference.com/cpp/language/basic_concepts) Alapfogalmak

These are the punctuation symbols in C++. The meaning of each symbol is detailed in the linked pages. Ez a szakasz tartalmazza a C++ interpunkciós szimbólumait. Minden egyes szimbólum jelentése részletesen megtalálható a kapcsolódó oldalakon.

------

### Preprocessing operators

### Előprocesszor operátorok

Preprocessing operators are recognized by [preprocessors](https://cppreference.com/cpp/preprocessor). Az előprocesszor operátorokat az előprocesszor ismeri fel.

#### `#`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `%:`. (Alternatív írásmód: `%:`)

- Introduce a [preprocessing directive](https://cppreference.com/cpp/preprocessor). Előprocesszor direktíva bevezetése.
- The [preprocessing operator for stringification](https://cppreference.com/cpp/preprocessor/replace##_and_##_operators). A „szövecsesítési” (*stringification*) előprocesszor operátora.

#### `##`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `%:%:`. (Alternatív írásmód: `%:%:`)

- The [preprocessing operator for token pasting](https://cppreference.com/cpp/preprocessor/replace##_and_##_operators). A tokenek összefűzésére (*token pasting*) szolgáló előprocesszor operátora.

------

### Single-character operators and punctuators

### Egyetlen karakterből álló operátorok és interpunkciós jelek

#### `{` and `}`

Alternative spellings are `<%` and `%>` respectively. (Alternatív írásmódok: `<%` és `%>`)

- In a class definition, delimit the member specification. Osztálydefinícióban határjolja le a tagokat.

- In an enumeration definition, delimit the enumerator list. Enumeráció (típus) definíciójában határjolja le az enumerátorok listáját.

- Delimit a compound statement. The compound statement may be part of:

  Határjol egy összetett utasítást. Az összetett utasítás része lehet a következőnek:

  - a function definition (egy függvénydefiníciónak)
  - a try block (egy try blokknak)
  - a lambda expression (since C++11) (egy lambda kifejezésnek (C++11 óta))

- Part of the aggregate initialization (until C++11) / list-initialization (since C++11) syntax of an initializer. Egy inicializáló aggregált inicializálásának (C++11-ig) vagy lista-inicializálásának (C++11 óta) része.

- In a namespace definition, delimit the namespace body. Névtér (namespace) definícióban határjolja le a névtér testét.

- In a language linkage specification, delimit the declarations. Nyelvi kapcsolódási specifikációban határjolja le a deklarációkat.

- In a requires expression, delimit the requirements. Egy `requires` kifejezésben határjolja le a követelményeket.

- In a compound requirement, delimit the expression. Egy összetett követelményben határjolja le a kifejezést.

- In an export declaration, delimit the declarations (since C++20). Egy export deklarációban határjolja le a deklarációkat (C++20 óta).

#### `[` and `]`

Alternative spellings are `<:` and `:>` respectively. (Alternatív írásmódok: `<:` és `:>`)

- Subscript operator; part of `operator[]` in operator overloading. Indexelő operátor; az operátor túlterhelésnél az `operator[]` része.
- Part of array declarator in a declaration or a type-id (e.g. in a `new` expression). Tömb deklaráló része egy deklarációban vagy egy típus-azonosítóban (pl. egy `new` kifejezésben).
- Part of `new[]` operator in operator overloading (allocation function). Az `operator new[]` része az operátor túlterheléskor (allokációs függvény).
- Part of `delete[]` operator in `delete` expression and operator overloading (deallocation function). A `delete[]` operátor része egy `delete` kifejezésben vagy operátor túlterheléskor (deallokációs függvény).
- In a lambda expression, delimit the captures. Lambda kifejezésben határjolja le a capture-okat (elfogásokat).
- In an attribute specifier, delimit the attributes (since C++11). Attribút specifikátorban határjolja le az attribútokat (C++11 óta).
- In a structured binding declaration, delimit the identifier list (since C++17). Strukturált kötési (*structured binding*) deklarációban határjolja le az azonosítók listáját (C++17 óta).
- In a pack indexing, delimit converted constant expression representing an index (since C++26). Pack indexelésnél határjolja le az indexet reprezentáló konvertált konstans kifejezést (C++26 óta).

#### `(` and `)`

- In an expression, indicate grouping. Kifejezésben jelzi a csoportosítást.

- Function call operator; part of `operator()` in operator overloading. Függvényhívó operátor; az operátor túlterhelésnél az `operator()` része.

- In a function-style type cast, delimit the expression/initializers. Függvényszerű típuskonvertálásnál határjolja le a kifejezést/inicializálókat.

- In a `static_cast`, `const_cast`, `reinterpret_cast`, or `dynamic_cast`, delimit the expression. `static_cast`, `const_cast`, `reinterpret_cast` vagy `dynamic_cast` esetében határjolja le a kifejezést.

- Delimit the operand of the following operators: `typeid`, `sizeof`, `sizeof...`, `alignof`, `noexcept` (since C++11). A következő operátorok operandumát határjolja le: `typeid`, `sizeof`, `sizeof...`, `alignof`, `noexcept` (C++11 óta).

- In a placement new expression, delimit the placement arguments. Placement new kifejezésben határjolja le a placement argumentumokat.

- In a `new` expression, optionally delimit the type-id. `new` kifejezésben opcionálisan határjolja le a típus-azonosítót.

- In a `new` expression, delimit the initializers. `new` kifejezésben határjolja le az inicializálókat.

- In a C-style cast, delimit the type-id. C-stílusú típuskonvertálásnál határjolja le a típus-azonosítót.

- In a declaration or a type-id, indicate grouping. Deklarációban vagy típus-azonosítóban jelzi a csoportosítást.

- Delimit the parameter list in:

  Határjolja le a paraméterlistát a következőknél:

  - a function declarator (in a declaration or a type-id) (függvény deklaráló (deklarációban vagy típus-azonosítóban))
  - a lambda expression (since C++11) (lambda kifejezés (C++11 óta))
  - a user-defined deduction guide (since C++17) (felhasználói dedukciós útmutató (C++17 óta))
  - a requires expression (since C++20) (requires kifejezés (C++20 óta))

- Part of the direct-initialization syntax of an initializer. Egy inicializáló közvetlen inicializálási szintaxisának része.

- In an `asm` declaration, delimit the string literal. `asm` deklarációban határjolja le a karakterlánc literálisan.

- In a member initializer list, delimit the initializers to a base or member. Tag-inicializáló listában határjolja le a bázis- vagy tag-inicializálókat.

- Delimit the controlling clause of a selection statement or iteration statement, including: `if`, `switch`, `while`, `do-while`, `for`, range-based `for` (since C++11). Határjolja le a választási vagy iterációs utasítások vezérlő részét, többek között: `if`, `switch`, `while`, `do-while`, `for`, valamint a tartományalapú (`range-based`) `for` (C++11 óta).

- In a handler, delimit the parameter declaration. Kezelőben (*handler*) határjolja le a paraméter deklarációját.

- In a function-like macro definition, delimit the macro parameters. Függvényszerű makró definícióban határjolja le a makró paramétereit.

- In a function-like macro invocation, delimit the macro arguments or prevent commas from being interpreted as argument separators. Függvényszerű makró híváskor határjolja le a makró argumentumait, vagy megakadályozza, hogy a vesszőket argumentum-szeparátorként értelmezzék.

- Part of a defined, `__has_include` (since C++17), `__has_cpp_attribute` (since C++20) preprocessing operator. Részét képezi a meghatározott, `__has_include` (C++17 óta) vagy `__has_cpp_attribute` (C++20 óta) előprocesszor operátoroknak.

- In a `static_assert` declaration, delimit the operands (since C++11). `static_assert` deklarációban határjolja le az operandumokat (C++11 óta).

- Delimit the operand of the following specifiers: `decltype`, `noexcept`, `alignas`, `explicit` (since C++20). A következő specifikátorok operandumát határjolja le: `decltype`, `noexcept`, `alignas`, `explicit` (C++20 óta).

- In an attribute, delimit the attribute arguments (since C++11). Attribúmnál határjolja le az attribút argumentumokat (C++11 óta).

- Part of `decltype(auto)` specifier (since C++14). A `decltype(auto)` specifikátor része (C++14 óta).

- Delimit a fold expression (since C++17). Határjol egy fold kifejezést (C++17 óta).

- Part of `__VA_OPT__` replacement in a variadic macro definition (since C++20). Variábilis makró definícióban az `__VA_OPT__` helyettesítése része (C++20 óta).

#### `;`

Indicate the end of: Jelzi a következők végét:

- a statement (egy utasításnak)
- a declaration or member declaration (egy deklarációnak vagy tag-deklarációnak)
- a module declaration, import declaration, global module fragment introducer, or private module fragment introducer (egy modul deklarációnak, import deklarációnak, globális modul fragment bevezetőnek vagy privát modul fragment bevezetőnek)
- a requirement (since C++20) (egy követelménynek (C++20 óta))
- Separate the condition and statement of a `for` statement. Elválasztja a `for` utasítás feltételét és az utasítást.

#### `:`

- Part of conditional operator. A kondícionális (ternáres) operátor része.
- Part of label declaration. Címke (*label*) deklaráció része.
- In the base-clause of a class definition, introduce the base class. Osztálydefiníció bázis-részében vezeti be a bázisosztályt.
- Part of access specifier in member specification. A tag-specifikáció hozzáférési specifikátora része.
- In a bit-field member declaration, introduce the width. Bitmező tag-deklarációban vezeti be a szélességet.
- In a constructor definition, introduce the member initializer list. Konstruktornál vezeti be a tag-inicializáló listát.
- In a range-based `for` statement, separate the item-declaration and the range-initializer. Tartományalapú `for` utasításban választja el az elem-deklarációt a tartomány-inicializálótól.
- In the enum-base of an enumeration declaration, introduce the underlying type (since C++11). Enumeráció deklarációjának alap-típusa esetén vezeti be az alapul szolgáló típust (C++11 óta).
- In an attribute specifier, separate the attribute-namespace and the attribute-list (since C++17). Attribút specifikátorban választja el az attribút-névteret az attribút-listától (C++17 óta).
- In a module declaration or import declaration of module partition, introduce the module partition name (since C++20). Modul deklarációnál vagy modul partíció import deklarációjánál vezeti be a modul partíció nevét (C++20 óta).
- Part of a private module fragment introducer (`module :private;`) (since C++20). Privát modul fragment bevezető része (`module :private;`) (C++20 óta).

#### `?`

Part of conditional operator. A kondícionális (ternáres) operátor része.

#### `.`

- Member access operator. Tag-elérési operátor.
- In aggregate initialization, introduce a designator. Aggregált inicializálásnál vezeti be a megnevező (*designator*)-t.
- Part of module name or module partition name (since C++20). Modulnév vagy modul partíció név része (C++20 óta).

#### `~`

Alternative spelling is `compl`. (Alternatív írásmód: `compl`)

- Unary complement operator (a.k.a. bitwise not operator); part of `operator~` in operator overloading. Unáris kiegészítő operátor (más néven bitbisel négation); az operátor túlterhelésnél az `operator~` része.
- Part of an identifier expression to name a destructor or pseudo-destructor. A destruktor vagy pseudo-destruktor megnevezésének azonosító kifejezés része.

#### `!`

Alternative spelling is `not`. (Alternatív írásmód: `not`)

- Logical not operator; part of `operator!` in operator overloading. Logikai NEM operátor; az operátor túlterhelésnél az `operator!` része.
- Part of `consteval if` statement (since C++23). `consteval if` utasítás része (C++23 óta).

#### `+`

- Unary plus operator; part of `operator+` in operator overloading. Unáris plusz operátor; az operátor túlterhelésnél az `operator+` része.
- Binary plus operator; part of `operator+` in operator overloading. Bináris plusz operátor; az operátor túlterhelésnél az `operator+` része.

#### `-`

- Unary minus operator; part of `operator-` in operator overloading. Unáris mínusz operátor; az operátor túlterhelésnél az `operator-` része.
- Binary minus operator; part of `operator-` in operator overloading. Bináris mínusz operátor; az operátor túlterhelésnél az `operator-` része.

#### `*`

- Indirection operator; part of `operator*` in operator overloading. Indirekciós operátor; az operátor túlterhelésnél az `operator*` része.
- Multiplication operator; part of `operator*` in operator overloading. Szorzás operátor; az operátor túlterhelésnél az `operator*` része.
- Pointer operator or part of pointer-to-member operator in a declarator or in a type-id. Mutató operátor vagy tag-mutató operátor része egy deklarálóban vagy típus-azonosítóban.
- Part of `*this` in a lambda capture list, to capture the current object by copy (since C++17). Lambda capture listben a `*this` része, amely a jelenlegi objektumot másolással fogja el (C++17 óta).

#### `/`

Division operator; part of `operator/` in operator overloading. Osztás operátor; az operátor túlterhelésnél az `operator/` része.

#### `%`

Modulo operator; part of `operator%` in operator overloading. Modulo (maradék) operátor; az operátor túlterhelésnél az `operator%` része.

#### `^`

Alternative spelling is `xor`. (Alternatív írásmód: `xor`)

Bitwise xor operator; part of `operator^` in operator overloading. Bitbisel XOR operátor; az operátor túlterhelésnél az `operator^` része.

#### `&`

Alternative spelling is `bitand`. (Alternatív írásmód: `bitand`)

- Address-of operator; part of `operator&` in operator overloading. Cím-operátor; az operátor túlterhelésnél az `operator&` része.
- Bitwise and operator; part of `operator&` in operator overloading. Bitbisel AND operátor; az operátor túlterhelésnél az `operator&` része.
- Lvalue-reference operator in a declarator or in a type-id. Lvalue-referencia operátor egy deklarálóban vagy típus-azonosítóban.
- In a lambda capture, indicate by-reference capture. Lambda capture-ban jelzi a referenciによる elfogást.
- Ref-qualifier in member function declaration (since C++11). Referencia-kvalifikátor egy tagfüggvény deklarációban (C++11 óta).

#### `|`

Alternative spelling is `bitor`. (Alternatív írásmód: `bitor`)

Bitwise or operator; part of `operator|` in operator overloading. Bitbisel OR operátor; az operátor túlterhelésnél az `operator|` része.

#### `=`

- Simple assignment operator; part of `operator=` in operator overloading, which might be a special member function (copy assignment operator or move assignment operator (since C++11)). Egyszerű hozzárendelési operátor; az operátor túlterhelésnél az `operator=` része, amely lehet egy speciális tagfüggvény (másolási vagy mozgatási hozzárendelő operátor (C++11 óta)).
- Part of the copy-initialization and aggregate initialization (until C++11) / copy-list-initialization (since C++11) syntax of an initializer. Egy inicializáló másolási-inicializálásának és aggregált inicializálásának (C++11-ig) vagy másolási lista-inicializálásának (C++11 óta) szintaxisának része.
- In a function declaration, introduce a default argument. Függvény deklarációban vezeti be az alapértelmezett argumentumot.
- In a template parameter list, introduce a default template argument. Sablon (template) paraméterlistában vezeti be az alapértelmezett sablonargumentumot.
- In a namespace alias definition, separate the alias and the aliased namespace. Névtér alias definícióban választja el az aliast a hivatkozott névtértől.
- In an enum definition, introduce the value of enumerator. Enum definícióban vezeti be az enumerátor értékét.
- Part of pure-specifier in a pure virtual function declaration. Tiszta virtuális függvény deklarációjában a „tiszta” specifikátor része.
- Capture default in lambda capture, to indicate by-copy capture. Lambda capture alapértelmezése, amely a másolással történő elfogást jelzi.
- Part of defaulted definition (`=default;`) or deleted definition (`=delete;`) in function definition. Függvénydefinícióban az alapértelmezett (`=default;`) vagy törölt (`=delete;`) definíció része.
- In a type alias declaration, separate the alias and the aliased type (since C++11). Típus alias deklarációban választja el az aliast a hivatkozott típustól (C++11 óta).
- In a concept definition, separate the concept name and the constraint expression (since C++20). Koncepció definícióban választja el a koncepció nevét a korlátozó kifejezéstől (C++20 óta).

#### `<`

- Less-than operator; part of `operator<` in operator overloading. Kisebb mint operátor; az operátor túlterhelésnél az `operator<` része.

- In a `static_cast`, `const_cast`, `reinterpret_cast`, or `dynamic_cast`, introduce the type-id. `static_cast`, `const_cast`, `reinterpret_cast` vagy `dynamic_cast` esetében vezeti be a típus-azonosítót.

- Introduce a template argument list. Bevezeti a sablon-argumentum listát.

- Introduce a template parameter list in:

  Bevezeti a sablon-paraméter listát a következőkben:

  - a template declaration (egy sablon deklarációban)
  - a partial specialization (egy részleges specializációban)
  - a lambda expression (since C++20) (egy lambda kifejezésben (C++20 óta))

- Part of `template<>` in template specialization declaration. Sablon specializációs deklarációban a `template<>` része.

- Introduce a header name in:

  Bevezeti a fejléцnévben a következőkben:

  - a `#include` directive (egy `#include` direktívában)
  - a `__has_include` preprocessing expression (since C++17) (egy `__has_include` előprocesszor kifejezésben (C++17 óta))
  - an import declaration (since C++20) (egy import deklarációban (C++20 óta))

#### `>`

- Greater-than operator; part of `operator>` in operator overloading. Nagyobb mint operátor; az operátor túlterhelésnél az `operator>` része.

- In `static_cast`, `const_cast`, `reinterpret_cast`, or `dynamic_cast`, indicate the end of type-id. `static_cast`, `const_cast`, `reinterpret_cast` vagy `dynamic_cast` esetében jelzi a típus-azonosító végét.

- Indicate the end of a template argument list. Jelzi a sablon-argumentum lista végét.

- Indicate the end of a template parameter list in:

  Jelzi a sablon-paraméter lista végét a következőkben:

  - a template declaration (egy sablon deklarációban)
  - a partial specialization (egy részleges specializációban)
  - a lambda expression (since C++20) (egy lambda kifejezésben (C++20 óta))

- Part of `template<>` in template specialization declaration. Sablon specializációs deklarációban a `template<>` része.

- Indicate the end of a header name in:

  Jelzi a fejléccnév végét a következőkben:

  - a `#include` directive (egy `#include` direktívában)
  - a `__has_include` preprocessing expression (since C++17) (egy `__has_include` előprocesszor kifejezésben (C++17 óta))
  - an import declaration (since C++20) (egy import deklarációban (C++20 óta))

#### `,`

- Comma operator; part of `operator,` in operator overloading. Vessző operátor; az operátor túlterhelésnél az `operator,` része.

- List separator in:

  Lista szeparátor (elválasztó) a következőkben:

  - the declarator list in a declaration (egy deklaráció deklaráló listájában)
  - initializer list in initialization (inicializálásnál az inicializáló listában)
  - the placement argument list in a placement new (egy placement new placement argument listjében)
  - the argument list in a function call expression (egy függvényhívási kifejezés argumentum listájában)
  - the enumerator list in an enum declaration (egy enum deklaráció enumerátor listájában)
  - the base class list in a class declaration (egy osztály deklaráció bázisosztály listájában)
  - the member initializer list in a constructor definition (egy konstruktor definíció tag-inicializáló listájában)
  - a function parameter list (egy függvény paraméterlistájában)
  - a template parameter list (egy sablon paraméterlistájában)
  - a template argument list (egy sablon argumentum listájában)
  - a lambda capture list (egy lambda capture listában)
  - an attribute list (since C++11) (egy attribút listában (C++11 óta))
  - the declarator list in a `using`-declaration (egy `using` deklaráció deklaráló listájában)
  - the identifier list in a structured binding declaration (since C++17) (egy strukturált kötési deklaráció azonosító listájában (C++17 óta))
  - the argument list in a multi-argument subscript expression (since C++23) (egy több argumentumú indexelő kifejezés argumentum listájában (C++23 óta))
  - the macro parameter list in a function-like macro definition (egy függvényszerű makró definíció paraméter listájában)
  - the macro argument list in a function-like macro invocation, unless found between the parentheses of an argument (egy függvényszerű makró hívás argumentum listájában, hacsak nem egy argumentum zárójelei között található)

- In a `static_assert` declaration, separate the arguments (since C++11). `static_assert` deklarációban választja el az argumentumokat (C++11 óta).

------

### Multi-character operators and punctuators

### Több karakterből álló operátorok és interpunkciós jelek

#### `[:` and `:]` (since C++26)

Delimit a splice specifier. Határjol egy splice specifikátort (C++26 óta).

#### `^^` (since C++26)

Reflection operator. Reflekciós operátor (C++26 óta).

#### `...`

- In the parameter list of a function declarator or lambda expression (since C++11) or user-defined deduction guide (since C++17), signify a variadic function. Egy függvény deklaráló vagy lambda kifejezés (C++11 óta) vagy egy felhasználói dedukciós útmutató (C++17 óta) paraméterlistájában variábilis függvényt jelez.
- In a handler, signify catch-all handler. Kezelőben (*handler*) egy „mindenlehetőséget elfogó” (*catch-all*) kezelőt jelez.
- In a macro definition, signify a variadic macro. Makró definícióban egy variábilis makrót jelez.
- Indicate pack declaration and expansion (since C++11). A pack deklarációját és kibontását jelzi (C++11 óta).
- In pack indexing expression and specifier (since C++26). Pack indexelő kifejezésben és specifikátorban (C++26 óta).

#### `::`

Scope resolution operator in: Tartalommeg határozó (*scope resolution*) operátor a következőkben:

- a qualified name (egy kvalifikált névben)
- a pointer-to-member declaration (egy tag-mutató deklarációban)
- a `new` or `delete` expression, to indicate that only global allocation or deallocation functions are looked up (egy `new` vagy `delete` kifejezésben, jelzve, hogy csak a globális allokációs vagy deallokációs függvények legyenek keresve)
- In an attribute, indicate attribute scope (since C++11). Attribúmnál jelzi az attribút scope-ját (C++11 óta).
- Part of nested namespace definition (since C++17). Beágyazott névtér definíciója része (C++17 óta).

#### `.*`

Pointer-to-member access operator. Tag-mutató elérést biztosító operátor.

#### `->`

- Member access operator; part of `operator->` in operator overloading. Tag-elérési operátor; az operátor túlterhelésnél az `operator->` része.
- In a function declarator or lambda expression, introduce the trailing return type (since C++11). Függvény deklarálóban vagy lambda kifejezésben vezeti be a trailing return típust (C++11 óta).
- In a user-defined deduction guide, introduce the result type (since C++17). Felhasználói dedukciós útmutatóban vezeti be az eredmény típust (C++17 óta).
- In a compound requirement, introduce the return type requirement (since C++20). Összetett követelményben vezeti be a visszaadási típus követelményét (C++20 óta).

#### `->*`

Pointer-to-member access operator; part of `operator->*` in operator overloading. Tag-mutató elérést biztosító operátor; az operátor túlterhelésnél az `operator->*` része.

#### `+=`

Compound assignment operator; part of `operator+=` in operator overloading. Összecompound hozzárendelési operátor; az operátor túlterhelésnél az `operator+=` része.

#### `-=`

Compound assignment operator; part of `operator-=` in operator overloading. Összecompound hozzárendelési operátor; az operátor túlterhelésnél az `operator-=` része.

#### `*=`

Compound assignment operator; part of `operator*=` in operator overloading. Összecompound hozzárendelési operátor; az operátor túlterhelésnél az `operator*=` része.

#### `/=`

Compound assignment operator; part of `operator/=` in operator overloading. Összecompound hozzárendelési operátor; az operátor túlterhelésnél az `operator/=` része.

#### `%=`

Compound assignment operator; part of `operator%=` in operator overloading. Összecompound hozzárendelési operátor; az operátor túlterhelésnél az `operator%=` része.

#### `^=`

Alternative spelling is `xor_eq`. (Alternatív írásmód: `xor_eq`)

Compound assignment operator; part of `operator^=` in operator overloading. Összecompound hozzárendelési operátor; az operátor túlterhelésnél az `operator^=` része.

#### `&=`

Alternative spelling is `and_eq`. (Alternatív írásmód: `and_eq`)

Compound assignment operator; part of `operator&=` in operator overloading. Összecompound hozzárendelési operátor; az operátor túlterhelésnél az `operator&=` része.

#### `|=`

Alternative spelling is `or_eq`. (Alternatív írásmód: `or_eq`)

Compound assignment operator; part of `operator|=` in operator overloading. Összecompound hozzárendelési operátor; az operátor túlterhelésnél az `operator|=` része.

#### `==`

Equality operator; part of `operator==` in operator overloading. Egyenlőség operátora; az operátor túlterhelésnél az `operator==` része.

#### `!=`

Alternative spelling is `not_eq`. (Alternatív írásmód: `not_eq`)

Inequality operator; part of `operator!=` in operator overloading. Egyenlőtlenség operátora; az operátor túlterhelésnél az `operator!=` része.

#### `<=`

Less-than-or-equal-to operator; part of `operator<=` in operator overloading. „Kisebb vagy egyenlő” operátor; az operátor túlterhelésnél az `operator<=` része.

#### `>=`

Greater-than-or-equal-to operator; part of `operator>=` in operator overloading. „Nagyobb vagy egyenlő” operátor; az operátor túlterhelésnél az `operator>=` része.

#### `<=>`

Three-way comparison (spaceship) operator; part of `operator<=>` in operator overloading (since C++20). Háromirányú összehasonlító (űrhajó) operátor; az operátor túlterhelésnél az `operator<=>` része (C++20 óta).

#### `&&`

Alternative spelling is `and`. (Alternatív írásmód: `and`)

- Logical and operator; part of `operator&&` in operator overloading. Logikai ÉS operátor; az operátor túlterhelésnél az `operator&&` része.
- Rvalue-reference operator in a declarator or in a type-id. Rvalue-referencia operátor egy deklarálóban vagy típus-azonosítóban.
- Ref-qualifier in member function declaration (since C++11). Referencia-kvalifikátor egy tagfüggvény deklarációban (C++11 óta).

#### `||`

Alternative spelling is `or`. (Alternatív írásmód: `or`)

Logical or operator; part of `operator||` in operator overloading. Logikai VAGY operátor; az operátor túlterhelésnél az `operator||` része.

#### `<<`

Bitwise shift operator; part of `operator<<` in operator overloading (bitwise operator or stream insertion operator). Bitbisel tolási operátor; az operátor túlterhelésnél az `operator<<` része (bitbisel operátor vagy stream beillesztő operátor).

#### `>>`

Bitwise shift operator; part of `operator>>` in operator overloading (bitwise operator or stream extraction operator). Bitbisel tolási operátor; az operátor túlterhelésnél az `operator>>` része (bitbisel operátor vagy stream kinyérő operátor).

#### `<<=`

Compound assignment operator; part of `operator<<=` in operator overloading. Összetett hozzárendelési operátor; az operátor túlterhelésnél az `operator<<=` része.

#### `>>=`

Compound assignment operator; part of `operator>>=` in operator overloading. Összetett hozzárendelési operátor; az operátor túlterhelésnél az `operator>>=` része.

#### `++`

Increment operator; part of `operator++` in operator overloading. Inkrementációs operátor; az operátor túlterhelésnél az `operator++` része.

#### `--`

Decrement operator; part of `operator--` in operator overloading. Dekrementációs operátor; az operátor túlterhelésnél az `operator--` része.



#### Alternatív írásmód

Mindkét írásmód teljesen egyformánMacrophages hatással bír a C++ nyelvben. A `not_eq` egyszerűen a `!=` operátora úgynevezett alternatív írásmódja (alternative spelling).

### Mi a különbség?

1. `if (d != a)`: Ez a standard, leggyakrabban használt forma. Szinte minden programozó ezt használja, és ez a "norma".
2. `if (d not_eq a)`: Ez egy kulcsszó, amely pontosan ugyanazt csinálja. Ritkán látod a gyakorlatban, de nyelvtanilag teljesen helyes.

### Miért léteznek ezek az alternatív írásmódok?

Ezek azért kerültek be a nyelvbe, mert voltak olyan régi billentyűzetek (különösen nem angol nyelvű országokban), ahol a `!`, `<`, `>`, `&`, `|` jeleket nagyon nehéz volt elérni (vagy egyáltalán nem voltak a billentyűkön). Így lehetőséget kaptak a programozók, hogy szövegesen is leírják ezeket az operátorokat.

### Más hasonló példák, amiket szintén használhatsz:

A listában, amit korábban fordítottunk, szerepeltek mások is. Íme a leggyakoribb párjai:

| Szimbólum | Alternatív szöveges írásmód | Példa                                         |
| :-------- | :-------------------------- | :-------------------------------------------- |
| `&&`      | `and`                       | `if (a && b)` $\rightarrow$ `if (a and b)`    |
| `||`      | `or`                        | `if (a || b)` $\rightarrow$ `if (a or b)`     |
| `!`       | `not`                       | `if (!a)` $\rightarrow$ `if (not a)`          |
| `!=`      | `not_eq`                    | `if (a != b)` $\rightarrow$ `if (a not_eq b)` |
| `&=`      | `and_eq`                    | `a &= b;` $\rightarrow$ `a and_eq b;`         |
| `|=`      | `or_eq`                     | `a |= b;` $\rightarrow$ `a or_eq b;`          |
| `^=`      | `xor_eq`                    | `a ^= b;` $\rightarrow$ `a xor_eq b;`         |

Pro tipp: Bár a `not_eq`, `and`, `or` működnek, a legtöbb C++ fejlesztő a szimbólumokat (`!=`, `&&`, `||`) preferálja, mert így gyorsabban felismerhető a kód szerkezete. De ha nehezábban találod a billentyűket, vagy egyszerűbbnek érzed a szöveges formát, nyugodtan használhatod!