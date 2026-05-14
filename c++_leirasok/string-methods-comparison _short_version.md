# String Metódusok Összehasonlítása

## Java String Metódusok

| Metódus | Leírás |
|---------|--------|
| `charAt(int index)` | Visszaadja a karaktert a megadott indexen |
| `codePointAt(int index)` | Visszaadja a karakter Unicode kódpontját a megadott indexen |
| `codePointBefore(int index)` | Visszaadja az index előtti karakter Unicode kódpontját |
| `codePointCount(int beginIndex, int endIndex)` | Visszaadja a Unicode kódpontok számát a megadott tartományban |
| `compareTo(String anotherString)` | Lexikografikusan összehasonlít két stringet |
| `compareToIgnoreCase(String str)` | Lexikografikusan összehasonlít két stringet, kis/nagybetű érzéketlenül |
| `concat(String str)` | Összefűzi a stringet a megadott stringgel |
| `contains(CharSequence s)` | Ellenőrzi, hogy tartalmazza-e a megadott karaktersorozatot |
| `contentEquals(CharSequence cs)` | Összehasonlítja a stringet egy karaktersorozattal |
| `contentEquals(StringBuffer sb)` | Összehasonlítja a stringet egy StringBuffer objektummal |
| `endsWith(String suffix)` | Ellenőrzi, hogy a string a megadott résszel végződik-e |
| `equals(Object anObject)` | Összehasonlítja a stringet egy másik objektummal |
| `equalsIgnoreCase(String anotherString)` | Összehasonlítja a stringeket kis/nagybetű érzéketlenül |
| `format(String format, Object... args)` | Formázott stringet ad vissza (statikus metódus) |
| `getBytes()` | Byte tömbbé konvertálja a stringet |
| `getBytes(Charset charset)` | Byte tömbbé konvertálja a stringet a megadott karakterkódolással |
| `getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin)` | Karaktereket másol a string egy részéből egy char tömbbe |
| `hashCode()` | Visszaadja a string hash kódját |
| `indexOf(int ch)` | Visszaadja az első előfordulás indexét |
| `indexOf(int ch, int fromIndex)` | Visszaadja az első előfordulás indexét a megadott indextől kezdve |
| `indexOf(String str)` | Visszaadja a substring első előfordulásának indexét |
| `indexOf(String str, int fromIndex)` | Visszaadja a substring első előfordulásának indexét a megadott indextől |
| `intern()` | Kanonikus reprezentációt ad vissza a string objektumról |
| `isEmpty()` | Ellenőrzi, hogy a string hossza 0-e |
| `join(CharSequence delimiter, CharSequence... elements)` | Összefűzi az elemeket a megadott elválasztóval (statikus) |
| `lastIndexOf(int ch)` | Visszaadja az utolsó előfordulás indexét |
| `lastIndexOf(int ch, int fromIndex)` | Visszaadja az utolsó előfordulás indexét visszafelé keresve |
| `lastIndexOf(String str)` | Visszaadja a substring utolsó előfordulásának indexét |
| `lastIndexOf(String str, int fromIndex)` | Visszaadja a substring utolsó előfordulásának indexét visszafelé keresve |
| `length()` | Visszaadja a string hosszát |
| `matches(String regex)` | Ellenőrzi, hogy a string illeszkedik-e a regex mintára |
| `offsetByCodePoints(int index, int codePointOffset)` | Visszaad egy indexet, ami el van tolva kódpontokkal |
| `regionMatches(int toffset, String other, int ooffset, int len)` | Két string régió egyezését teszteli |
| `regionMatches(boolean ignoreCase, int toffset, String other, int ooffset, int len)` | Két string régió egyezését teszteli opcionálisan kis/nagybetű érzéketlenül |
| `replace(char oldChar, char newChar)` | Lecseréli az összes előfordulását az egyik karakternek a másikra |
| `replace(CharSequence target, CharSequence replacement)` | Lecseréli az összes előfordulását egy részstringnek |
| `replaceAll(String regex, String replacement)` | Lecseréli az összes regex illeszkedést a megadott stringre |
| `replaceFirst(String regex, String replacement)` | Lecseréli az első regex illeszkedést |
| `split(String regex)` | Feldarabolja a stringet a regex minta mentén |
| `split(String regex, int limit)` | Feldarabolja a stringet a regex minta mentén maximális darabszámmal |
| `startsWith(String prefix)` | Ellenőrzi, hogy a string a megadott előtaggal kezdődik-e |
| `startsWith(String prefix, int toffset)` | Ellenőrzi, hogy a string egy adott pozíciótól a megadott előtaggal kezdődik-e |
| `subSequence(int beginIndex, int endIndex)` | Visszaad egy karaktersorozatot, ami ennek a sorozatnak egy része |
| `substring(int beginIndex)` | Visszaad egy új stringet, ami ennek a stringnek egy része |
| `substring(int beginIndex, int endIndex)` | Visszaad egy új stringet, ami a megadott intervallumban van |
| `toCharArray()` | Char tömbbé konvertálja a stringet |
| `toLowerCase()` | Kisbetűssé konvertálja az összes karaktert |
| `toLowerCase(Locale locale)` | Kisbetűssé konvertálja a megadott területi beállítás szerint |
| `toString()` | Visszaadja magát az objektumot |
| `toUpperCase()` | Nagybetűssé konvertálja az összes karaktert |
| `toUpperCase(Locale locale)` | Nagybetűssé konvertálja a megadott területi beállítás szerint |
| `trim()` | Eltávolítja a vezető és záró szóközöket |
| `valueOf(...)` | Különböző típusokat stringgé konvertál (statikus, több túlterhelés) |

---

## Kotlin String Metódusok

*A Kotlin tartalmazza az összes Java String metódust, plusz kiterjesztéseket:*

| Metódus | Leírás |
|---------|--------|
| **Java metódusok** | *Összes fenti Java metódus elérhető* |
| `isBlank()` | Ellenőrzi, hogy a string üres-e vagy csak whitespace karaktereket tartalmaz |
| `isNotBlank()` | Ellenőrzi, hogy a string nem üres és nem csak whitespace karaktereket tartalmaz |
| `isEmpty()` | Ellenőrzi, hogy a string hossza 0-e |
| `isNotEmpty()` | Ellenőrzi, hogy a string hossza nem 0 |
| `orEmpty()` | Visszaadja a stringet, vagy üres stringet, ha null |
| `capitalize()` | Nagybetűsíti az első karaktert (deprecated, használd `replaceFirstChar`) |
| `decapitalize()` | Kisbetűsíti az első karaktert (deprecated, használd `replaceFirstChar`) |
| `drop(n: Int)` | Visszaad egy stringet az első n karakter eltávolításával |
| `dropLast(n: Int)` | Visszaad egy stringet az utolsó n karakter eltávolításával |
| `dropWhile(predicate)` | Eltávolítja a karaktereket az elejéről amíg a feltétel igaz |
| `dropLastWhile(predicate)` | Eltávolítja a karaktereket a végéről amíg a feltétel igaz |
| `filter(predicate)` | Visszaad egy stringet csak azokkal a karakterekkel, amik megfelelnek a feltételnek |
| `filterNot(predicate)` | Visszaad egy stringet azokkal a karakterekkel, amik nem felelnek meg a feltételnek |
| `findAnyOf(strings: Collection<String>)` | Megkeresi az első előfordulását bármely stringnek a kollekcióból |
| `findLastAnyOf(strings: Collection<String>)` | Megkeresi az utolsó előfordulását bármely stringnek a kollekcióból |
| `forEach(action)` | Végrehajt egy műveletet minden karakteren |
| `lines()` | Sorokra bontja a stringet |
| `padEnd(length: Int, padChar: Char)` | Kitölti a stringet jobbról a megadott karakterrel a megadott hosszig |
| `padStart(length: Int, padChar: Char)` | Kitölti a stringet balról a megadott karakterrel a megadott hosszig |
| `removePrefix(prefix: String)` | Eltávolítja az előtagot, ha a string vele kezdődik |
| `removeSuffix(suffix: String)` | Eltávolítja az utótagot, ha a string vele végződik |
| `removeRange(startIndex: Int, endIndex: Int)` | Eltávolítja a karaktereket a megadott tartományból |
| `removeSurrounding(delimiter: String)` | Eltávolítja az előtagot és utótagot |
| `repeat(n: Int)` | Megismétli a stringet n-szer |
| `replace(oldValue: String, newValue: String, ignoreCase: Boolean)` | Lecseréli az előfordulásokat opcionálisan case-insensitive módon |
| `replaceFirst(oldValue: String, newValue: String, ignoreCase: Boolean)` | Lecseréli az első előfordulást |
| `reversed()` | Megfordítja a stringet |
| `slice(indices)` | Visszaad egy részstringet a megadott indexekkel |
| `split(delimiters: Array<String>)` | Feldarabolja a stringet több elválasztó alapján |
| `splitToSequence(delimiters)` | Feldarabolja a stringet sequence-re |
| `substringAfter(delimiter: String)` | Visszaadja a részstringet az első elválasztó után |
| `substringAfterLast(delimiter: String)` | Visszaadja a részstringet az utolsó elválasztó után |
| `substringBefore(delimiter: String)` | Visszaadja a részstringet az első elválasztó előtt |
| `substringBeforeLast(delimiter: String)` | Visszaadja a részstringet az utolsó elválasztó előtt |
| `take(n: Int)` | Visszaad egy stringet az első n karakterrel |
| `takeLast(n: Int)` | Visszaad egy stringet az utolsó n karakterrel |
| `takeWhile(predicate)` | Karaktereket vesz az elejéről amíg a feltétel igaz |
| `takeLastWhile(predicate)` | Karaktereket vesz a végéről amíg a feltétel igaz |
| `toBooleanStrict()` | String-et konvertál Boolean-ra strict módon |
| `toByteOrNull()` | String-et próbálja konvertálni Byte-ra, null-t ad vissza hiba esetén |
| `toDoubleOrNull()` | String-et próbálja konvertálni Double-ra, null-t ad vissza hiba esetén |
| `toIntOrNull()` | String-et próbálja konvertálni Int-re, null-t ad vissza hiba esetén |
| `toFloatOrNull()` | String-et próbálja konvertálni Float-ra, null-t ad vissza hiba esetén |
| `toLongOrNull()` | String-et próbálja konvertálni Long-ra, null-t ad vissza hiba esetén |
| `toShortOrNull()` | String-et próbálja konvertálni Short-ra, null-t ad vissza hiba esetén |
| `trimIndent()` | Eltávolítja a közös minimális behúzást minden sorból |
| `trimMargin(marginPrefix: String)` | Eltávolítja a margót minden sorból |
| `windowed(size: Int, step: Int)` | Csúszó ablakokat készít a stringből |
| `zipWithNext()` | Párokat készít szomszédos karakterekből |

---

## C++ std::string Metódusok

| Metódus | Leírás |
|---------|--------|
| `at(size_t pos)` | Visszaadja a karakter referenciáját a megadott pozíción (határellenőrzéssel) |
| `operator[]` | Visszaadja a karakter referenciáját a megadott pozíción (határellenőrzés nélkül) |
| `front()` | Visszaadja az első karakter referenciáját |
| `back()` | Visszaadja az utolsó karakter referenciáját |
| `data()` | Visszaadja a C-stílusú karakter tömb pointerét |
| `c_str()` | Visszaadja a null-terminált C-stílusú string pointert |
| `begin()` | Visszaadja az iterátort az elejére |
| `end()` | Visszaadja az iterátort a végére |
| `rbegin()` | Visszaadja a fordított iterátort az elejére |
| `rend()` | Visszaadja a fordított iterátort a végére |
| `cbegin()` | Visszaadja a konstans iterátort az elejére |
| `cend()` | Visszaadja a konstans iterátort a végére |
| `crbegin()` | Visszaadja a konstans fordított iterátort |
| `crend()` | Visszaadja a konstans fordított iterátort a végére |
| `empty()` | Ellenőrzi, hogy a string üres-e |
| `size()` | Visszaadja a karakterek számát |
| `length()` | Visszaadja a string hosszát (ugyanaz mint size) |
| `max_size()` | Visszaadja a maximális lehetséges karakterszámot |
| `reserve(size_t n)` | Előre lefoglalja a memóriát n karakternek |
| `capacity()` | Visszaadja a lefoglalt tárhely méretét |
| `shrink_to_fit()` | Csökkenti a memóriahasználatot a mérethez igazítva |
| `clear()` | Törli a string tartalmát |
| `insert(size_t pos, const string& str)` | Beszúr egy stringet a megadott pozícióra |
| `erase(size_t pos, size_t len)` | Töröl karaktereket a megadott pozíciótól |
| `push_back(char c)` | Hozzáfűz egy karaktert a végére |
| `pop_back()` | Eltávolítja az utolsó karaktert |
| `append(const string& str)` | Hozzáfűz egy stringet a végére |
| `operator+=` | Hozzáfűz egy stringet vagy karaktert |
| `compare(const string& str)` | Összehasonlít két stringet |
| `replace(size_t pos, size_t len, const string& str)` | Lecseréli a string egy részét |
| `substr(size_t pos, size_t len)` | Visszaad egy részstringet |
| `copy(char* s, size_t len, size_t pos)` | Másol karaktereket egy karakter tömbbe |
| `resize(size_t n)` | Átméretezi a stringet n karakterre |
| `swap(string& str)` | Kicseréli két string tartalmát |
| `find(const string& str, size_t pos)` | Megkeresi a substring első előfordulását |
| `rfind(const string& str, size_t pos)` | Megkeresi a substring utolsó előfordulását |
| `find_first_of(const string& str, size_t pos)` | Megkeresi az első olyan karaktert, ami a paraméterben van |
| `find_last_of(const string& str, size_t pos)` | Megkeresi az utolsó olyan karaktert, ami a paraméterben van |
| `find_first_not_of(const string& str, size_t pos)` | Megkeresi az első olyan karaktert, ami nincs a paraméterben |
| `find_last_not_of(const string& str, size_t pos)` | Megkeresi az utolsó olyan karaktert, ami nincs a paraméterben |
| `get_allocator()` | Visszaadja az allocator objektumot |

---

## Python str Metódusok

| Metódus | Leírás |
|---------|--------|
| `capitalize()` | Az első karaktert nagybetűssé, a többit kisbetűssé alakítja |
| `casefold()` | Kisbetűssé alakítja agresszív módon (Unicode-barát) |
| `center(width, fillchar)` | Középre igazítja a stringet a megadott szélességben |
| `count(sub, start, end)` | Megszámolja a substring előfordulásait |
| `encode(encoding, errors)` | Enkódolja a stringet byte objektummá |
| `endswith(suffix, start, end)` | Ellenőrzi, hogy a megadott utótaggal végződik-e |
| `expandtabs(tabsize)` | Tab karaktereket szóközökre cseréli |
| `find(sub, start, end)` | Megkeresi a substring első előfordulását, -1-et ad vissza ha nincs |
| `format(*args, **kwargs)` | Formázza a stringet |
| `format_map(mapping)` | Formázza a stringet mapping objektummal |
| `index(sub, start, end)` | Megkeresi a substring első előfordulását, hibát dob ha nincs |
| `isalnum()` | Ellenőrzi, hogy minden karakter alfanumerikus-e |
| `isalpha()` | Ellenőrzi, hogy minden karakter betű-e |
| `isascii()` | Ellenőrzi, hogy minden karakter ASCII-e |
| `isdecimal()` | Ellenőrzi, hogy minden karakter decimális számjegy-e |
| `isdigit()` | Ellenőrzi, hogy minden karakter számjegy-e |
| `isidentifier()` | Ellenőrzi, hogy érvényes Python azonosító-e |
| `islower()` | Ellenőrzi, hogy minden betű kisbetű-e |
| `isnumeric()` | Ellenőrzi, hogy minden karakter numerikus-e |
| `isprintable()` | Ellenőrzi, hogy minden karakter nyomtatható-e |
| `isspace()` | Ellenőrzi, hogy csak whitespace karaktereket tartalmaz-e |
| `istitle()` | Ellenőrzi, hogy title case formátumú-e |
| `isupper()` | Ellenőrzi, hogy minden betű nagybetű-e |
| `join(iterable)` | Összefűzi az iterálható elemeket a stringgel elválasztva |
| `ljust(width, fillchar)` | Balra igazítja a stringet a megadott szélességben |
| `lower()` | Kisbetűssé alakítja az összes karaktert |
| `lstrip(chars)` | Eltávolítja a megadott karaktereket a bal oldalról |
| `maketrans(x, y, z)` | Transzlációs táblát készít (statikus metódus) |
| `partition(sep)` | Három részre bontja a stringet az első elválasztónál |
| `removeprefix(prefix)` | Eltávolítja az előtagot ha létezik (Python 3.9+) |
| `removesuffix(suffix)` | Eltávolítja az utótagot ha létezik (Python 3.9+) |
| `replace(old, new, count)` | Lecseréli a substring előfordulásait |
| `rfind(sub, start, end)` | Megkeresi a substring utolsó előfordulását, -1-et ad vissza ha nincs |
| `rindex(sub, start, end)` | Megkeresi a substring utolsó előfordulását, hibát dob ha nincs |
| `rjust(width, fillchar)` | Jobbra igazítja a stringet a megadott szélességben |
| `rpartition(sep)` | Három részre bontja a stringet az utolsó elválasztónál |
| `rsplit(sep, maxsplit)` | Feldarabolja a stringet jobbról balra |
| `rstrip(chars)` | Eltávolítja a megadott karaktereket a jobb oldalról |
| `split(sep, maxsplit)` | Feldarabolja a stringet az elválasztó mentén |
| `splitlines(keepends)` | Sorokra bontja a stringet |
| `startswith(prefix, start, end)` | Ellenőrzi, hogy a megadott előtaggal kezdődik-e |
| `strip(chars)` | Eltávolítja a megadott karaktereket mindkét oldalról |
| `swapcase()` | Felcseréli a kis- és nagybetűket |
| `title()` | Title case formátumúvá alakítja (szavak első betűje nagy) |
| `translate(table)` | Transzlációs táblát alkalmaz a stringre |
| `upper()` | Nagybetűssé alakítja az összes karaktert |
| `zfill(width)` | Kitölti a stringet nullákkal balról a megadott szélességig |

---

## Összefoglaló táblázat - Főbb műveletek összehasonlítása

| Művelet | Java | Kotlin | C++ | Python |
|---------|------|--------|-----|--------|
| **Hossz lekérdezése** | `length()` | `length` (property) | `length()` / `size()` | `len(str)` |
| **Üres-e** | `isEmpty()` | `isEmpty()` | `empty()` | `len(str) == 0` |
| **Karakter lekérése** | `charAt(i)` | `[i]` vagy `get(i)` | `[i]` vagy `at(i)` | `[i]` |
| **Substring** | `substring()` | `substring()` | `substr()` | `[start:end]` |
| **Tartalmaz-e** | `contains()` | `contains()` | `find() != npos` | `in` operátor |
| **Kezdődik-e** | `startsWith()` | `startsWith()` | `find() == 0` / `starts_with()` (C++20) | `startswith()` |
| **Végződik-e** | `endsWith()` | `endsWith()` | összehasonlítás / `ends_with()` (C++20) | `endswith()` |
| **Kisbetűs** | `toLowerCase()` | `lowercase()` | `std::transform + ::tolower` | `lower()` |
| **Nagybetűs** | `toUpperCase()` | `uppercase()` | `std::transform + ::toupper` | `upper()` |
| **Trim** | `trim()` | `trim()` | manuális / C++17 string_view | `strip()` |
| **Csere** | `replace()` | `replace()` | `replace()` | `replace()` |
| **Darabolás** | `split()` | `split()` | nincs beépített | `split()` |
| **Összefűzés** | `concat()` vagy `+` | `+` | `+` vagy `append()` | `+` vagy `join()` |
| **Keresés** | `indexOf()` | `indexOf()` | `find()` | `find()` vagy `index()` |

