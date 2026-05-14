# Teljes String Függvények és Metódusok Összehasonlítása

## Java String Osztály - Minden Metódus

| Metódus | Visszatérési típus | Leírás |
|---------|-------------------|--------|
| `charAt(int index)` | char | Visszaadja a karaktert a megadott indexen |
| `chars()` | IntStream | IntStream-et ad vissza a karakterek int értékeiből (Java 8+) |
| `codePointAt(int index)` | int | Visszaadja a karakter Unicode kódpontját a megadott indexen |
| `codePointBefore(int index)` | int | Visszaadja az index előtti karakter Unicode kódpontját |
| `codePointCount(int beginIndex, int endIndex)` | int | Visszaadja a Unicode kódpontok számát a megadott tartományban |
| `codePoints()` | IntStream | IntStream-et ad vissza a kódpontokból (Java 8+) |
| `compareTo(String anotherString)` | int | Lexikografikusan összehasonlít két stringet |
| `compareToIgnoreCase(String str)` | int | Lexikografikusan összehasonlít két stringet, kis/nagybetű érzéketlenül |
| `concat(String str)` | String | Összefűzi a stringet a megadott stringgel |
| `contains(CharSequence s)` | boolean | Ellenőrzi, hogy tartalmazza-e a megadott karaktersorozatot |
| `contentEquals(CharSequence cs)` | boolean | Összehasonlítja a stringet egy karaktersorozattal |
| `contentEquals(StringBuffer sb)` | boolean | Összehasonlítja a stringet egy StringBuffer objektummal |
| `copyValueOf(char[] data)` | String | String-et ad vissza egy char tömbből (statikus) |
| `copyValueOf(char[] data, int offset, int count)` | String | String-et ad vissza egy char tömb részéből (statikus) |
| `describeConstable()` | Optional<String> | Konstans leíró objektumot ad vissza (Java 12+) |
| `endsWith(String suffix)` | boolean | Ellenőrzi, hogy a string a megadott résszel végződik-e |
| `equals(Object anObject)` | boolean | Összehasonlítja a stringet egy másik objektummal |
| `equalsIgnoreCase(String anotherString)` | boolean | Összehasonlítja a stringeket kis/nagybetű érzéketlenül |
| `format(String format, Object... args)` | String | Formázott stringet ad vissza (statikus metódus) |
| `format(Locale l, String format, Object... args)` | String | Formázott stringet ad vissza lokalizációval (statikus) |
| `formatted(Object... args)` | String | Formázza a stringet (Java 15+) |
| `getBytes()` | byte[] | Byte tömbbé konvertálja a stringet alapértelmezett kódolással |
| `getBytes(String charsetName)` | byte[] | Byte tömbbé konvertálja a megadott karakterkódolással |
| `getBytes(Charset charset)` | byte[] | Byte tömbbé konvertálja a megadott Charset-tel |
| `getBytes(int srcBegin, int srcEnd, byte[] dst, int dstBegin)` | void | Byte-okat másol (deprecated) |
| `getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin)` | void | Karaktereket másol a string egy részéből egy char tömbbe |
| `hashCode()` | int | Visszaadja a string hash kódját |
| `indent(int n)` | String | Minden sort behúz n szóközzel (Java 12+) |
| `indexOf(int ch)` | int | Visszaadja az első előfordulás indexét |
| `indexOf(int ch, int fromIndex)` | int | Visszaadja az első előfordulás indexét a megadott indextől kezdve |
| `indexOf(String str)` | int | Visszaadja a substring első előfordulásának indexét |
| `indexOf(String str, int fromIndex)` | int | Visszaadja a substring első előfordulásának indexét a megadott indextől |
| `intern()` | String | Kanonikus reprezentációt ad vissza a string objektumról |
| `isBlank()` | boolean | Ellenőrzi, hogy üres-e vagy csak whitespace-t tartalmaz (Java 11+) |
| `isEmpty()` | boolean | Ellenőrzi, hogy a string hossza 0-e |
| `join(CharSequence delimiter, CharSequence... elements)` | String | Összefűzi az elemeket a megadott elválasztóval (statikus) |
| `join(CharSequence delimiter, Iterable<? extends CharSequence> elements)` | String | Összefűzi az iterálható elemeket (statikus) |
| `lastIndexOf(int ch)` | int | Visszaadja az utolsó előfordulás indexét |
| `lastIndexOf(int ch, int fromIndex)` | int | Visszaadja az utolsó előfordulás indexét visszafelé keresve |
| `lastIndexOf(String str)` | int | Visszaadja a substring utolsó előfordulásának indexét |
| `lastIndexOf(String str, int fromIndex)` | int | Visszaadja a substring utolsó előfordulásának indexét visszafelé keresve |
| `length()` | int | Visszaadja a string hosszát |
| `lines()` | Stream<String> | Stream-et ad vissza a sorokból (Java 11+) |
| `matches(String regex)` | boolean | Ellenőrzi, hogy a string illeszkedik-e a regex mintára |
| `offsetByCodePoints(int index, int codePointOffset)` | int | Visszaad egy indexet, ami el van tolva kódpontokkal |
| `regionMatches(int toffset, String other, int ooffset, int len)` | boolean | Két string régió egyezését teszteli |
| `regionMatches(boolean ignoreCase, int toffset, String other, int ooffset, int len)` | boolean | Két string régió egyezését teszteli opcionálisan kis/nagybetű érzéketlenül |
| `repeat(int count)` | String | Megismétli a stringet count-szor (Java 11+) |
| `replace(char oldChar, char newChar)` | String | Lecseréli az összes előfordulását az egyik karakternek a másikra |
| `replace(CharSequence target, CharSequence replacement)` | String | Lecseréli az összes előfordulását egy részstringnek |
| `replaceAll(String regex, String replacement)` | String | Lecseréli az összes regex illeszkedést a megadott stringre |
| `replaceFirst(String regex, String replacement)` | String | Lecseréli az első regex illeszkedést |
| `resolveConstantDesc(MethodHandles.Lookup lookup)` | String | Konstans leírót old fel (Java 12+) |
| `split(String regex)` | String[] | Feldarabolja a stringet a regex minta mentén |
| `split(String regex, int limit)` | String[] | Feldarabolja a stringet a regex minta mentén maximális darabszámmal |
| `startsWith(String prefix)` | boolean | Ellenőrzi, hogy a string a megadott előtaggal kezdődik-e |
| `startsWith(String prefix, int toffset)` | boolean | Ellenőrzi, hogy a string egy adott pozíciótól a megadott előtaggal kezdődik-e |
| `strip()` | String | Eltávolítja a vezető és záró whitespace-t (Unicode-aware, Java 11+) |
| `stripIndent()` | String | Eltávolítja a közös behúzást (Java 13+) |
| `stripLeading()` | String | Eltávolítja a vezető whitespace-t (Java 11+) |
| `stripTrailing()` | String | Eltávolítja a záró whitespace-t (Java 11+) |
| `subSequence(int beginIndex, int endIndex)` | CharSequence | Visszaad egy karaktersorozatot, ami ennek a sorozatnak egy része |
| `substring(int beginIndex)` | String | Visszaad egy új stringet, ami ennek a stringnek egy része |
| `substring(int beginIndex, int endIndex)` | String | Visszaad egy új stringet, ami a megadott intervallumban van |
| `toCharArray()` | char[] | Char tömbbé konvertálja a stringet |
| `toLowerCase()` | String | Kisbetűssé konvertálja az összes karaktert |
| `toLowerCase(Locale locale)` | String | Kisbetűssé konvertálja a megadott területi beállítás szerint |
| `toString()` | String | Visszaadja magát az objektumot |
| `toUpperCase()` | String | Nagybetűssé konvertálja az összes karaktert |
| `toUpperCase(Locale locale)` | String | Nagybetűssé konvertálja a megadott területi beállítás szerint |
| `transform(Function<? super String,? extends R> f)` | R | Transzformációs függvényt alkalmaz (Java 12+) |
| `translateEscapes()` | String | Escape szekvenciákat fordít le (Java 15+) |
| `trim()` | String | Eltávolítja a vezető és záró szóközöket |
| `valueOf(boolean b)` | String | Boolean-t stringgé konvertál (statikus) |
| `valueOf(char c)` | String | Char-t stringgé konvertál (statikus) |
| `valueOf(char[] data)` | String | Char tömböt stringgé konvertál (statikus) |
| `valueOf(char[] data, int offset, int count)` | String | Char tömb részét stringgé konvertál (statikus) |
| `valueOf(double d)` | String | Double-t stringgé konvertál (statikus) |
| `valueOf(float f)` | String | Float-ot stringgé konvertál (statikus) |
| `valueOf(int i)` | String | Int-et stringgé konvertál (statikus) |
| `valueOf(long l)` | String | Long-ot stringgé konvertál (statikus) |
| `valueOf(Object obj)` | String | Objektumot stringgé konvertál (statikus) |

---

## Kotlin String - Minden Metódus és Kiterjesztés

**Kotlin tartalmazza az összes fenti Java metódust, PLUSZ az alábbi kiterjesztéseket:**

| Metódus | Visszatérési típus | Leírás |
|---------|-------------------|--------|
| `all(predicate: (Char) -> Boolean)` | Boolean | Ellenőrzi, hogy minden karakter megfelel-e a feltételnek |
| `any()` | Boolean | Ellenőrzi, hogy van-e karakter a stringben |
| `any(predicate: (Char) -> Boolean)` | Boolean | Ellenőrzi, hogy van-e olyan karakter, ami megfelel a feltételnek |
| `asIterable()` | Iterable<Char> | Iterálható-ként adja vissza a stringet |
| `asSequence()` | Sequence<Char> | Sequence-ként adja vissza a stringet |
| `associate(transform)` | Map | Map-et készít a karakterekből transzformációval |
| `associateBy(keySelector)` | Map | Map-et készít kulcs szelektor alapján |
| `associateByTo(destination, keySelector)` | M | Map-et készít egy cél kollekcióba kulcs szelektor alapján |
| `associateTo(destination, transform)` | M | Map-et készít egy cél kollekcióba transzformációval |
| `associateWith(valueSelector)` | Map | Map-et készít érték szelektor alapján |
| `associateWithTo(destination, valueSelector)` | M | Map-et készít egy cél kollekcióba érték szelektor alapján |
| `chunked(size: Int)` | List<String> | A stringet darabokra bontja a megadott méretben |
| `chunked(size: Int, transform)` | List<R> | A stringet darabokra bontja és transzformál |
| `chunkedSequence(size: Int)` | Sequence<String> | A stringet darabokra bontja sequence-ként |
| `chunkedSequence(size: Int, transform)` | Sequence<R> | A stringet darabokra bontja és transzformál sequence-ként |
| `commonPrefixWith(other: CharSequence)` | String | Visszaadja a közös előtagot egy másik stringgel |
| `commonPrefixWith(other, ignoreCase)` | String | Visszaadja a közös előtagot case-insensitive módon |
| `commonSuffixWith(other: CharSequence)` | String | Visszaadja a közös utótagot egy másik stringgel |
| `commonSuffixWith(other, ignoreCase)` | String | Visszaadja a közös utótagot case-insensitive módon |
| `count()` | Int | Visszaadja a karakterek számát |
| `count(predicate)` | Int | Megszámolja a karaktereket, amik megfelelnek a feltételnek |
| `decapitalize()` | String | Kisbetűsíti az első karaktert (deprecated) |
| `decapitalize(locale)` | String | Kisbetűsíti az első karaktert lokalizációval (deprecated) |
| `decodeToString()` | String | ByteArray-ből dekódol stringet |
| `drop(n: Int)` | String | Visszaad egy stringet az első n karakter eltávolításával |
| `dropLast(n: Int)` | String | Visszaad egy stringet az utolsó n karakter eltávolításával |
| `dropLastWhile(predicate)` | String | Eltávolítja a karaktereket a végéről amíg a feltétel igaz |
| `dropWhile(predicate)` | String | Eltávolítja a karaktereket az elejéről amíg a feltétel igaz |
| `elementAt(index: Int)` | Char | Visszaadja a karaktert a megadott indexen |
| `elementAtOrElse(index, defaultValue)` | Char | Visszaadja a karaktert vagy az alapértelmezett értéket |
| `elementAtOrNull(index: Int)` | Char? | Visszaadja a karaktert vagy null-t |
| `encodeToByteArray()` | ByteArray | Enkódolja a stringet ByteArray-be |
| `endsWith(char: Char, ignoreCase)` | Boolean | Ellenőrzi, hogy a megadott karakterrel végződik-e |
| `endsWith(suffix: CharSequence, ignoreCase)` | Boolean | Ellenőrzi, hogy a megadott utótaggal végződik-e |
| `filter(predicate)` | String | Visszaad egy stringet csak azokkal a karakterekkel, amik megfelelnek a feltételnek |
| `filterIndexed(predicate)` | String | Szűr index alapján |
| `filterIndexedTo(destination, predicate)` | C | Szűr index alapján egy cél kollekcióba |
| `filterNot(predicate)` | String | Visszaad egy stringet azokkal a karakterekkel, amik nem felelnek meg a feltételnek |
| `filterNotTo(destination, predicate)` | C | Szűr negáltan egy cél kollekcióba |
| `filterTo(destination, predicate)` | C | Szűr egy cél kollekcióba |
| `find(predicate)` | Char? | Megkeresi az első karaktert, ami megfelel a feltételnek |
| `findAnyOf(strings: Collection<String>, startIndex, ignoreCase)` | Pair<Int, String>? | Megkeresi az első előfordulását bármely stringnek a kollekcióból |
| `findLast(predicate)` | Char? | Megkeresi az utolsó karaktert, ami megfelel a feltételnek |
| `findLastAnyOf(strings: Collection<String>, startIndex, ignoreCase)` | Pair<Int, String>? | Megkeresi az utolsó előfordulását bármely stringnek a kollekcióból |
| `first()` | Char | Visszaadja az első karaktert |
| `first(predicate)` | Char | Visszaadja az első karaktert, ami megfelel a feltételnek |
| `firstNotNullOf(transform)` | R | Transzformálja és visszaadja az első nem null értéket |
| `firstNotNullOfOrNull(transform)` | R? | Transzformálja és visszaadja az első nem null értéket vagy null-t |
| `firstOrNull()` | Char? | Visszaadja az első karaktert vagy null-t |
| `firstOrNull(predicate)` | Char? | Visszaadja az első karaktert, ami megfelel a feltételnek, vagy null-t |
| `flatMap(transform)` | List<R> | FlatMap transzformációt alkalmaz |
| `flatMapIndexed(transform)` | List<R> | FlatMap transzformációt alkalmaz index-szel |
| `flatMapIndexedTo(destination, transform)` | C | FlatMap transzformációt alkalmaz index-szel egy cél kollekcióba |
| `flatMapTo(destination, transform)` | C | FlatMap transzformációt alkalmaz egy cél kollekcióba |
| `fold(initial, operation)` | R | Fold műveletet alkalmaz kezdő értékkel |
| `foldIndexed(initial, operation)` | R | Fold műveletet alkalmaz kezdő értékkel és indexszel |
| `foldRight(initial, operation)` | R | Fold műveletet alkalmaz jobbról kezdő értékkel |
| `foldRightIndexed(initial, operation)` | R | Fold műveletet alkalmaz jobbról kezdő értékkel és indexszel |
| `forEach(action)` | Unit | Végrehajt egy műveletet minden karakteren |
| `forEachIndexed(action)` | Unit | Végrehajt egy műveletet minden karakteren indexszel |
| `getOrElse(index, defaultValue)` | Char | Visszaadja a karaktert vagy az alapértelmezett értéket |
| `getOrNull(index: Int)` | Char? | Visszaadja a karaktert vagy null-t |
| `groupBy(keySelector)` | Map<K, List<Char>> | Csoportosítja a karaktereket kulcs szelektor alapján |
| `groupBy(keySelector, valueTransform)` | Map<K, List<V>> | Csoportosítja a karaktereket kulcs és érték transzformációval |
| `groupByTo(destination, keySelector)` | M | Csoportosít egy cél map-be |
| `groupByTo(destination, keySelector, valueTransform)` | M | Csoportosít egy cél map-be érték transzformációval |
| `groupingBy(keySelector)` | Grouping<Char, K> | Grouping objektumot készít |
| `hasSurrogatePairAt(index: Int)` | Boolean | Ellenőrzi, hogy van-e surrogate pair a megadott indexen |
| `ifBlank(defaultValue)` | CharSequence | Visszaadja az alapértelmezett értéket, ha blank |
| `ifEmpty(defaultValue)` | CharSequence | Visszaadja az alapértelmezett értéket, ha üres |
| `indexOf(char: Char, startIndex, ignoreCase)` | Int | Megkeresi a karakter indexét |
| `indexOf(string: String, startIndex, ignoreCase)` | Int | Megkeresi a substring indexét |
| `indexOfAny(chars: CharArray, startIndex)` | Int | Megkeresi bármely karakter első előfordulását |
| `indexOfAny(strings: Collection<String>, startIndex, ignoreCase)` | Int | Megkeresi bármely string első előfordulását |
| `indexOfFirst(predicate)` | Int | Megkeresi az első karakter indexét, ami megfelel a feltételnek |
| `indexOfLast(predicate)` | Int | Megkeresi az utolsó karakter indexét, ami megfelel a feltételnek |
| `indices` | IntRange | Visszaadja az érvényes indexek tartományát (property) |
| `isBlank()` | Boolean | Ellenőrzi, hogy üres-e vagy csak whitespace karaktereket tartalmaz |
| `isEmpty()` | Boolean | Ellenőrzi, hogy a string hossza 0-e |
| `isNotBlank()` | Boolean | Ellenőrzi, hogy nem üres és nem csak whitespace karaktereket tartalmaz |
| `isNotEmpty()` | Boolean | Ellenőrzi, hogy a string hossza nem 0 |
| `isNullOrBlank()` | Boolean | Ellenőrzi, hogy null, üres vagy blank-e (extension a String?-hez) |
| `isNullOrEmpty()` | Boolean | Ellenőrzi, hogy null vagy üres-e (extension a String?-hez) |
| `last()` | Char | Visszaadja az utolsó karaktert |
| `last(predicate)` | Char | Visszaadja az utolsó karaktert, ami megfelel a feltételnek |
| `lastIndex` | Int | Visszaadja az utolsó karakter indexét (property) |
| `lastIndexOf(char: Char, startIndex, ignoreCase)` | Int | Megkeresi a karakter utolsó előfordulását |
| `lastIndexOf(string: String, startIndex, ignoreCase)` | Int | Megkeresi a substring utolsó előfordulását |
| `lastIndexOfAny(chars: CharArray, startIndex)` | Int | Megkeresi bármely karakter utolsó előfordulását |
| `lastIndexOfAny(strings: Collection<String>, startIndex, ignoreCase)` | Int | Megkeresi bármely string utolsó előfordulását |
| `lastOrNull()` | Char? | Visszaadja az utolsó karaktert vagy null-t |
| `lastOrNull(predicate)` | Char? | Visszaadja az utolsó karaktert, ami megfelel a feltételnek, vagy null-t |
| `lineSequence()` | Sequence<String> | Sorokra bontja a stringet sequence-ként |
| `lines()` | List<String> | Sorokra bontja a stringet |
| `lowercase()` | String | Kisbetűssé konvertálja (helyettesíti a toLowerCase-t) |
| `lowercase(locale: Locale)` | String | Kisbetűssé konvertálja lokalizációval |
| `map(transform)` | List<R> | Map transzformációt alkalmaz |
| `mapIndexed(transform)` | List<R> | Map transzformációt alkalmaz indexszel |
| `mapIndexedNotNull(transform)` | List<R> | Map transzformációt alkalmaz indexszel, null értékek kihagyásával |
| `mapIndexedNotNullTo(destination, transform)` | C | Map transzformációt alkalmaz indexszel egy cél kollekcióba, null értékek kihagyásával |
| `mapIndexedTo(destination, transform)` | C | Map transzformációt alkalmaz indexszel egy cél kollekcióba |
| `mapNotNull(transform)` | List<R> | Map transzformációt alkalmaz, null értékek kihagyásával |
| `mapNotNullTo(destination, transform)` | C | Map transzformációt alkalmaz egy cél kollekcióba, null értékek kihagyásával |
| `mapTo(destination, transform)` | C | Map transzformációt alkalmaz egy cél kollekcióba |
| `max()` | Char | Visszaadja a legnagyobb karaktert |
| `maxBy(selector)` | Char? | Visszaadja a legnagyobb karaktert szelektor alapján |
| `maxByOrNull(selector)` | Char? | Visszaadja a legnagyobb karaktert szelektor alapján vagy null-t |
| `maxOf(selector)` | R | Visszaadja a maximális értéket szelektor alapján |
| `maxOfOrNull(selector)` | R? | Visszaadja a maximális értéket szelektor alapján vagy null-t |
| `maxOfWith(comparator, selector)` | R | Visszaadja a maximális értéket komparátorral |
| `maxOfWithOrNull(comparator, selector)` | R? | Visszaadja a maximális értéket komparátorral vagy null-t |
| `maxOrNull()` | Char? | Visszaadja a legnagyobb karaktert vagy null-t |
| `maxWith(comparator)` | Char? | Visszaadja a legnagyobb karaktert komparátor alapján |
| `maxWithOrNull(comparator)` | Char? | Visszaadja a legnagyobb karaktert komparátor alapján vagy null-t |
| `min()` | Char | Visszaadja a legkisebb karaktert |
| `minBy(selector)` | Char? | Visszaadja a legkisebb karaktert szelektor alapján |
| `minByOrNull(selector)` | Char? | Visszaadja a legkisebb karaktert szelektor alapján vagy null-t |
| `minOf(selector)` | R | Visszaadja a minimális értéket szelektor alapján |
| `minOfOrNull(selector)` | R? | Visszaadja a minimális értéket szelektor alapján vagy null-t |
| `minOfWith(comparator, selector)` | R | Visszaadja a minimális értéket komparátorral |
| `minOfWithOrNull(comparator, selector)` | R? | Visszaadja a minimális értéket komparátorral vagy null-t |
| `minOrNull()` | Char? | Visszaadja a legkisebb karaktert vagy null-t |
| `minWith(comparator)` | Char? | Visszaadja a legkisebb karaktert komparátor alapján |
| `minWithOrNull(comparator)` | Char? | Visszaadja a legkisebb karaktert komparátor alapján vagy null-t |
| `none()` | Boolean | Ellenőrzi, hogy nincs karakter a stringben |
| `none(predicate)` | Boolean | Ellenőrzi, hogy nincs olyan karakter, ami megfelel a feltételnek |
| `onEach(action)` | String | Végrehajt egy műveletet minden karakteren és visszaadja a stringet |
| `onEachIndexed(action)` | String | Végrehajt egy műveletet minden karakteren indexszel |
| `orEmpty()` | String | Visszaadja a stringet, vagy üres stringet, ha null (extension a String?-hez) |
| `padEnd(length: Int, padChar: Char = ' ')` | String | Kitölti a stringet jobbról a megadott karakterrel a megadott hosszig |
| `padStart(length: Int, padChar: Char = ' ')` | String | Kitölti a stringet balról a megadott karakterrel a megadott hosszig |
| `partition(predicate)` | Pair<String, String> | Két részre bontja a stringet a feltétel alapján |
| `prependIndent(indent: String)` | String | Behúzást ad minden sor elejére |
| `random()` | Char | Visszaad egy véletlenszerű karaktert |
| `random(random: Random)` | Char | Visszaad egy véletlenszerű karaktert a megadott Random objektummal |
| `randomOrNull()` | Char? | Visszaad egy véletlenszerű karaktert vagy null-t |
| `randomOrNull(random: Random)` | Char? | Visszaad egy véletlenszerű karaktert vagy null-t a megadott Random objektummal |
| `reduce(operation)` | Char | Reduce műveletet alkalmaz |
| `reduceIndexed(operation)` | Char | Reduce műveletet alkalmaz indexszel |
| `reduceIndexedOrNull(operation)` | Char? | Reduce műveletet alkalmaz indexszel vagy null-t ad vissza |
| `reduceOrNull(operation)` | Char? | Reduce műveletet alkalmaz vagy null-t ad vissza |
| `reduceRight(operation)` | Char | Reduce műveletet alkalmaz jobbról |
| `reduceRightIndexed(operation)` | Char | Reduce műveletet alkalmaz jobbról indexszel |
| `reduceRightIndexedOrNull(operation)` | Char? | Reduce műveletet alkalmaz jobbról indexszel vagy null-t ad vissza |
| `reduceRightOrNull(operation)` | Char? | Reduce műveletet alkalmaz jobbról vagy null-t ad vissza |
| `regionMatches(thisOffset, other, otherOffset, length, ignoreCase)` | Boolean | Két string régió egyezését teszteli |
| `removePrefix(prefix: String)` | String | Eltávolítja az előtagot, ha a string vele kezdődik |
| `removeRange(startIndex: Int, endIndex: Int)` | String | Eltávolítja a karaktereket a megadott tartományból |
| `removeRange(range: IntRange)` | String | Eltávolítja a karaktereket a megadott tartományból |
| `removeSuffix(suffix: String)` | String | Eltávolítja az utótagot, ha a string vele végződik |
| `removeSurrounding(delimiter: String)` | String | Eltávolítja az előtagot és utótagot |
| `removeSurrounding(prefix: String, suffix: String)` | String | Eltávolítja a megadott előtagot és utótagot |
| `repeat(n: Int)` | String | Megismétli a stringet n-szer |
| `replace(oldChar: Char, newChar: Char, ignoreCase: Boolean = false)` | String | Lecseréli a karakter előfordulásokat |
| `replace(oldValue: String, newValue: String, ignoreCase: Boolean = false)` | String | Lecseréli a string előfordulásokat |
| `replaceAfter(delimiter: Char, replacement: String, missingDelimiterValue: String)` | String | Lecseréli az elválasztó utáni részt |
| `replaceAfter(delimiter: String, replacement: String, missingDelimiterValue: String)` | String | Lecseréli az elválasztó utáni részt |
| `replaceAfterLast(delimiter: Char, replacement: String, missingDelimiterValue: String)` | String | Lecseréli az utolsó elválasztó utáni részt |
| `replaceAfterLast(delimiter: String, replacement: String, missingDelimiterValue: String)` | String | Lecseréli az utolsó elválasztó utáni részt |
| `replaceBefore(delimiter: Char, replacement: String, missingDelimiterValue: String)` | String | Lecseréli az elválasztó előtti részt |
| `replaceBefore(delimiter: String, replacement: String, missingDelimiterValue: String)` | String | Lecseréli az elválasztó előtti részt |
| `replaceBeforeLast(delimiter: Char, replacement: String, missingDelimiterValue: String)` | String | Lecseréli az utolsó elválasztó előtti részt |
| `replaceBeforeLast(delimiter: String, replacement: String, missingDelimiterValue: String)` | String | Lecseréli az utolsó elválasztó előtti részt |
| `replaceFirst(oldChar: Char, newChar: Char, ignoreCase: Boolean)` | String | Lecseréli az első karakter előfordulást |
| `replaceFirst(oldValue: String, newValue: String, ignoreCase: Boolean)` | String | Lecseréli az első string előfordulást |
| `replaceFirstChar(transform)` | String | Transzformálja az első karaktert |
| `replaceIndent(newIndent: String)` | String | Lecseréli a behúzást minden sorban |
| `replaceIndentByMargin(newIndent: String, marginPrefix: String)` | String | Lecseréli a behúzást margó alapján |
| `replaceRange(startIndex: Int, endIndex: Int, replacement: CharSequence)` | String | Lecseréli a tartományt |
| `replaceRange(range: IntRange, replacement: CharSequence)` | String | Lecseréli a tartományt |
| `reversed()` | String | Megfordítja a stringet |
| `runningFold(initial, operation)` | List<R> | Running fold műveletet alkalmaz |
| `runningFoldIndexed(initial, operation)` | List<R> | Running fold műveletet alkalmaz indexszel |
| `runningReduce(operation)` | List<Char> | Running reduce műveletet alkalmaz |
| `runningReduceIndexed(operation)` | List<Char> | Running reduce műveletet alkalmaz indexszel |
| `scan(initial, operation)` | List<R> | Scan műveletet alkalmaz (alias runningFold-hoz) |
| `scanIndexed(initial, operation)` | List<R> | Scan műveletet alkalmaz indexszel |
| `single()` | Char | Visszaadja az egyetlen karaktert |
| `single(predicate)` | Char | Visszaadja az egyetlen karaktert, ami megfelel a feltételnek |
| `singleOrNull()` | Char? | Visszaadja az egyetlen karaktert vagy null-t |
| `singleOrNull(predicate)` | Char? | Visszaadja az egyetlen karaktert, ami megfelel a feltételnek, vagy null-t |
| `slice(indices: Iterable<Int>)` | String | Visszaad egy részstringet a megadott indexekkel |
| `slice(range: IntRange)` | String | Visszaad egy részstringet a megadott tartományból |
| `split(vararg delimiters: Char, ignoreCase, limit)` | List<String> | Feldarabolja a stringet több karakter elválasztó alapján |
| `split(vararg delimiters: String, ignoreCase, limit)` | List<String> | Feldarabolja a stringet több string elválasztó alapján |
| `split(regex: Regex, limit: Int)` | List<String> | Feldarabolja a stringet regex alapján |
| `splitToSequence(vararg delimiters: Char, ignoreCase, limit)` | Sequence<String> | Feldarabolja a stringet sequence-re karakterekkel |
| `splitToSequence(vararg delimiters: String, ignoreCase, limit)` | Sequence<String> | Feldarabolja a stringet sequence-re stringekkel |
| `splitToSequence(regex: Regex, limit: Int)` | Sequence<String> | Feldarabolja a stringet sequence-re regex-szel |
| `startsWith(char: Char, ignoreCase: Boolean)` | Boolean | Ellenőrzi, hogy a megadott karakterrel kezdődik-e |
| `startsWith(prefix: CharSequence, ignoreCase: Boolean)` | Boolean | Ellenőrzi, hogy a megadott előtaggal kezdődik-e |
| `startsWith(prefix: CharSequence, startIndex: Int, ignoreCase: Boolean)` | Boolean | Ellenőrzi, hogy a megadott pozíciótól az előtaggal kezdődik-e |
| `subSequence(startIndex: Int, endIndex: Int)` | CharSequence | Visszaad egy részsorozatot |
| `subSequence(range: IntRange)` | CharSequence | Visszaad egy részsorozatot tartományból |
| `substring(range: IntRange)` | String | Visszaad egy részstringet tartományból |
| `substringAfter(delimiter: Char, missingDelimiterValue: String)` | String | Visszaadja a részstringet az első elválasztó után |
| `substringAfter(delimiter: String, missingDelimiterValue: String)` | String | Visszaadja a részstringet az első elválasztó után |
| `substringAfterLast(delimiter: Char, missingDelimiterValue: String)` | String | Visszaadja a részstringet az utolsó elválasztó után |
| `substringAfterLast(delimiter: String, missingDelimiterValue: String)` | String | Visszaadja a részstringet az utolsó elválasztó után |
| `substringBefore(delimiter: Char, missingDelimiterValue: String)` | String | Visszaadja a részstringet az első elválasztó előtt |
| `substringBefore(delimiter: String, missingDelimiterValue: String)` | String | Visszaadja a részstringet az első elválasztó előtt |
| `substringBeforeLast(delimiter: Char, missingDelimiterValue: String)` | String | Visszaadja a részstringet az utolsó elválasztó előtt |
| `substringBeforeLast(delimiter: String, missingDelimiterValue: String)` | String | Visszaadja a részstringet az utolsó elválasztó előtt |
| `sumBy(selector)` | Int | Összegzi a karaktereket szelektor alapján (deprecated) |
| `sumByDouble(selector)` | Double | Összegzi a karaktereket double szelektor alapján (deprecated) |
| `sumOf(selector)` | Int/Long/Double` | Összegzi a karaktereket szelektor alapján |
| `take(n: Int)` | String | Visszaad egy stringet az első n karakterrel |
| `takeLast(n: Int)` | String | Visszaad egy stringet az utolsó n karakterrel |
| `takeLastWhile(predicate)` | String | Karaktereket vesz a végéről amíg a feltétel igaz |
| `takeWhile(predicate)` | String | Karaktereket vesz az elejéről amíg a feltétel igaz |
| `titlecase()` | String | Title case-re konvertálja (első karakter nagy) |
| `titlecase(locale: Locale)` | String | Title case-re konvertálja lokalizációval |
| `toBoolean()` | Boolean | String-et konvertál Boolean-ra |
| `toBooleanStrict()` | Boolean | String-et konvertál Boolean-ra strict módon |
| `toBooleanStrictOrNull()` | Boolean? | String-et konvertál Boolean-ra strict módon vagy null-t ad vissza |
| `toByte()` | Byte | String-et konvertál Byte-ra |
| `toByte(radix: Int)` | Byte | String-et konvertál Byte-ra a megadott számrendszerben |
| `toByteOrNull()` | Byte? | String-et próbálja konvertálni Byte-ra, null-t ad vissza hiba esetén |
| `toByteOrNull(radix: Int)` | Byte? | String-et próbálja konvertálni Byte-ra számrendszerrel |
| `toCharArray()` | CharArray | Char tömbbé konvertálja |
| `toCollection(destination)` | C | Karaktereket másol egy kollekcióba |
| `toDouble()` | Double | String-et konvertál Double-ra |
| `toDoubleOrNull()` | Double? | String-et próbálja konvertálni Double-ra, null-t ad vissza hiba esetén |
| `toFloat()` | Float | String-et konvertál Float-ra |
| `toFloatOrNull()` | Float? | String-et próbálja konvertálni Float-ra, null-t ad vissza hiba esetén |
| `toHashSet()` | HashSet<Char> | HashSet-té konvertálja a karaktereket |
| `toInt()` | Int | String-et konvertál Int-re |
| `toInt(radix: Int)` | Int | String-et konvertál Int-re a megadott számrendszerben |
| `toIntOrNull()` | Int? | String-et próbálja konvertálni Int-re, null-t ad vissza hiba esetén |
| `toIntOrNull(radix: Int)` | Int? | String-et próbálja konvertálni Int-re számrendszerrel |
| `toList()` | List<Char> | List-té konvertálja a karaktereket |
| `toLong()` | Long | String-et konvertál Long-ra |
| `toLong(radix: Int)` | Long | String-et konvertál Long-ra a megadott számrendszerben |
| `toLongOrNull()` | Long? | String-et próbálja konvertálni Long-ra, null-t ad vissza hiba esetén |
| `toLongOrNull(radix: Int)` | Long? | String-et próbálja konvertálni Long-ra számrendszerrel |
| `toMutableList()` | MutableList<Char> | MutableList-té konvertálja a karaktereket |
| `toMutableSet()` | MutableSet<Char> | MutableSet-té konvertálja a karaktereket |
| `toRegex()` | Regex | Regex objektummá konvertálja |
| `toRegex(option: RegexOption)` | Regex | Regex objektummá konvertálja opcióval |
| `toRegex(options: Set<RegexOption>)` | Regex | Regex objektummá konvertálja opciókkal |
| `toSet()` | Set<Char> | Set-té konvertálja a karaktereket |
| `toShort()` | Short | String-et konvertál Short-ra |
| `toShort(radix: Int)` | Short | String-et konvertál Short-ra a megadott számrendszerben |
| `toShortOrNull()` | Short? | String-et próbálja konvertálni Short-ra, null-t ad vissza hiba esetén |
| `toShortOrNull(radix: Int)` | Short? | String-et próbálja konvertálni Short-ra számrendszerrel |
| `toSortedSet()` | SortedSet<Char> | SortedSet-té konvertálja a karaktereket |
| `toSortedSet(comparator)` | SortedSet<Char> | SortedSet-té konvertálja a karaktereket komparátorral |
| `toUByte()` | UByte | String-et konvertál UByte-ra |
| `toUByte(radix: Int)` | UByte | String-et konvertál UByte-ra számrendszerrel |
| `toUByteOrNull()` | UByte? | String-et próbálja konvertálni UByte-ra |
| `toUByteOrNull(radix: Int)` | UByte? | String-et próbálja konvertálni UByte-ra számrendszerrel |
| `toUInt()` | UInt | String-et konvertál UInt-re |
| `toUInt(radix: Int)` | UInt | String-et konvertál UInt-re számrendszerrel |
| `toUIntOrNull()` | UInt? | String-et próbálja konvertálni UInt-re |
| `toUIntOrNull(radix: Int)` | UInt? | String-et próbálja konvertálni UInt-re számrendszerrel |
| `toULong()` | ULong | String-et konvertál ULong-ra |
| `toULong(radix: Int)` | ULong | String-et konvertál ULong-ra számrendszerrel |
| `toULongOrNull()` | ULong? | String-et próbálja konvertálni ULong-ra |
| `toULongOrNull(radix: Int)` | ULong? | String-et próbálja konvertálni ULong-ra számrendszerrel |
| `toUShort()` | UShort | String-et konvertál UShort-ra |
| `toUShort(radix: Int)` | UShort | String-et konvertál UShort-ra számrendszerrel |
| `toUShortOrNull()` | UShort? | String-et próbálja konvertálni UShort-ra |
| `toUShortOrNull(radix: Int)` | UShort? | String-et próbálja konvertálni UShort-ra számrendszerrel |
| `trim()` | String | Eltávolítja a vezető és záró whitespace-t |
| `trim(predicate)` | String | Eltávolítja a karaktereket mindkét oldalról a feltétel szerint |
| `trim(vararg chars: Char)` | String | Eltávolítja a megadott karaktereket mindkét oldalról |
| `trimEnd()` | String | Eltávolítja a záró whitespace-t |
| `trimEnd(predicate)` | String | Eltávolítja a karaktereket a végéről a feltétel szerint |
| `trimEnd(vararg chars: Char)` | String | Eltávolítja a megadott karaktereket a végéről |
| `trimIndent()` | String | Eltávolítja a közös minimális behúzást minden sorból |
| `trimMargin(marginPrefix: String = "|")` | String | Eltávolítja a margót minden sorból |
| `trimStart()` | String | Eltávolítja a vezető whitespace-t |
| `trimStart(predicate)` | String | Eltávolítja a karaktereket az elejéről a feltétel szerint |
| `trimStart(vararg chars: Char)` | String | Eltávolítja a megadott karaktereket az elejéről |
| `uppercase()` | String | Nagybetűssé konvertálja (helyettesíti a toUpperCase-t) |
| `uppercase(locale: Locale)` | String | Nagybetűssé konvertálja lokalizációval |
| `windowed(size: Int, step: Int = 1, partialWindows: Boolean = false)` | List<String> | Csúszó ablakokat készít a stringből |
| `windowed(size: Int, step: Int, partialWindows: Boolean, transform)` | List<R> | Csúszó ablakokat készít transzformációval |
| `windowedSequence(size: Int, step: Int, partialWindows: Boolean)` | Sequence<String> | Csúszó ablakokat készít sequence-ként |
| `windowedSequence(size: Int, step: Int, partialWindows: Boolean, transform)` | Sequence<R> | Csúszó ablakokat készít sequence-ként transzformációval |
| `withIndex()` | Iterable<IndexedValue<Char>> | Visszaad egy iterálhatót indexelt értékekkel |
| `zip(other: CharSequence)` | List<Pair<Char, Char>> | Párosítja a karaktereket egy másik stringgel |
| `zip(other: CharSequence, transform)` | List<R> | Párosítja a karaktereket egy másik stringgel transzformációval |
| `zipWithNext()` | List<Pair<Char, Char>> | Párokat készít szomszédos karakterekből |
| `zipWithNext(transform)` | List<R> | Párokat készít szomszédos karakterekből transzformációval |

---

## C++ std::string Osztály - Minden Metódus

| Metódus | Visszatérési típus | Leírás |
|---------|-------------------|--------|
| **Konstruktorok** |
| `string()` | | Üres string konstruktor |
| `string(const string& str)` | | Másoló konstruktor |
| `string(const string& str, size_t pos, size_t len)` | | Substring konstruktor |
| `string(const char* s)` | | C-string konstruktor |
| `string(const char* s, size_t n)` | | Buffer konstruktor |
| `string(size_t n, char c)` | | Fill konstruktor |
| `string(InputIterator first, InputIterator last)` | | Range konstruktor |
| `string(initializer_list<char> il)` | | Inicializáló lista konstruktor (C++11) |
| `string(string&& str)` | | Move konstruktor (C++11) |
| **Destruktor** |
| `~string()` | | Destruktor |
| **Elem hozzáférés** |
| `operator[](size_t pos)` | char& / const char& | Visszaadja a karakter referenciáját (határellenőrzés nélkül) |
| `at(size_t pos)` | char& / const char& | Visszaadja a karakter referenciáját (határellenőrzéssel) |
| `back()` | char& / const char& | Visszaadja az utolsó karakter referenciáját (C++11) |
| `front()` | char& / const char& | Visszaadja az első karakter referenciáját (C++11) |
| **Iterátorok** |
| `begin()` | iterator / const_iterator | Visszaadja az iterátort az elejére |
| `end()` | iterator / const_iterator | Visszaadja az iterátort a végére |
| `rbegin()` | reverse_iterator / const_reverse_iterator | Visszaadja a fordított iterátort |
| `rend()` | reverse_iterator / const_reverse_iterator | Visszaadja a fordított iterátort a végére |
| `cbegin()` | const_iterator | Visszaadja a konstans iterátort (C++11) |
| `cend()` | const_iterator | Visszaadja a konstans iterátort a végére (C++11) |
| `crbegin()` | const_reverse_iterator | Visszaadja a konstans fordított iterátort (C++11) |
| `crend()` | const_reverse_iterator | Visszaadja a konstans fordított iterátort a végére (C++11) |
| **Kapacitás** |
| `size()` | size_t | Visszaadja a karakterek számát |
| `length()` | size_t | Visszaadja a string hosszát (ugyanaz mint size) |
| `max_size()` | size_t | Visszaadja a maximális lehetséges karakterszámot |
| `resize(size_t n)` | void | Átméretezi a stringet n karakterre |
| `resize(size_t n, char c)` | void | Átméretezi a stringet n karakterre c-vel feltöltve |
| `capacity()` | size_t | Visszaadja a lefoglalt tárhely méretét |
| `reserve(size_t n = 0)` | void | Előre lefoglalja a memóriát n karakternek |
| `clear()` | void | Törli a string tartalmát |
| `empty()` | bool | Ellenőrzi, hogy a string üres-e |
| `shrink_to_fit()` | void | Csökkenti a memóriahasználatot (C++11) |
| **Elem műveletek** |
| `operator=(const string& str)` | string& | Másoló értékadás |
| `operator=(const char* s)` | string& | C-string értékadás |
| `operator=(char c)` | string& | Karakter értékadás |
| `operator=(initializer_list<char> il)` | string& | Inicializáló lista értékadás (C++11) |
| `operator=(string&& str)` | string& | Move értékadás (C++11) |
| **String műveletek** |
| `c_str()` | const char* | Visszaadja a null-terminált C-stílusú string pointert |
| `data()` | const char* / char* | Visszaadja a karakter tömb pointerét |
| `get_allocator()` | allocator_type | Visszaadja az allocator objektumot |
| `copy(char* s, size_t len, size_t pos = 0)` | size_t | Másol karaktereket egy karakter tömbbe |
| `find(const string& str, size_t pos = 0)` | size_t | Megkeresi a substring első előfordulását |
| `find(const char* s, size_t pos = 0)` | size_t | Megkeresi a C-string első előfordulását |
| `find(const char* s, size_t pos, size_t n)` | size_t | Megkeresi a buffer első előfordulását |
| `find(char c, size_t pos = 0)` | size_t | Megkeresi a karakter első előfordulását |
| `rfind(const string& str, size_t pos = npos)` | size_t | Megkeresi a substring utolsó előfordulását |
| `rfind(const char* s, size_t pos = npos)` | size_t | Megkeresi a C-string utolsó előfordulását |
| `rfind(const char* s, size_t pos, size_t n)` | size_t | Megkeresi a buffer utolsó előfordulását |
| `rfind(char c, size_t pos = npos)` | size_t | Megkeresi a karakter utolsó előfordulását |
| `find_first_of(const string& str, size_t pos = 0)` | size_t | Megkeresi az első olyan karaktert, ami a stringben van |
| `find_first_of(const char* s, size_t pos = 0)` | size_t | Megkeresi az első olyan karaktert, ami a C-stringben van |
| `find_first_of(const char* s, size_t pos, size_t n)` | size_t | Megkeresi az első olyan karaktert, ami a bufferben van |
| `find_first_of(char c, size_t pos = 0)` | size_t | Megkeresi az első olyan karaktert |
| `find_last_of(const string& str, size_t pos = npos)` | size_t | Megkeresi az utolsó olyan karaktert, ami a stringben van |
| `find_last_of(const char* s, size_t pos = npos)` | size_t | Megkeresi az utolsó olyan karaktert, ami a C-stringben van |
| `find_last_of(const char* s, size_t pos, size_t n)` | size_t | Megkeresi az utolsó olyan karaktert, ami a bufferben van |
| `find_last_of(char c, size_t pos = npos)` | size_t | Megkeresi az utolsó olyan karaktert |
| `find_first_not_of(const string& str, size_t pos = 0)` | size_t | Megkeresi az első olyan karaktert, ami nincs a stringben |
| `find_first_not_of(const char* s, size_t pos = 0)` | size_t | Megkeresi az első olyan karaktert, ami nincs a C-stringben |
| `find_first_not_of(const char* s, size_t pos, size_t n)` | size_t | Megkeresi az első olyan karaktert, ami nincs a bufferben |
| `find_first_not_of(char c, size_t pos = 0)` | size_t | Megkeresi az első olyan karaktert, ami nem c |
| `find_last_not_of(const string& str, size_t pos = npos)` | size_t | Megkeresi az utolsó olyan karaktert, ami nincs a stringben |
| `find_last_not_of(const char* s, size_t pos = npos)` | size_t | Megkeresi az utolsó olyan karaktert, ami nincs a C-stringben |
| `find_last_not_of(const char* s, size_t pos, size_t n)` | size_t | Megkeresi az utolsó olyan karaktert, ami nincs a bufferben |
| `find_last_not_of(char c, size_t pos = npos)` | size_t | Megkeresi az utolsó olyan karaktert, ami nem c |
| `substr(size_t pos = 0, size_t len = npos)` | string | Visszaad egy részstringet |
| `compare(const string& str)` | int | Összehasonlít két stringet |
| `compare(size_t pos, size_t len, const string& str)` | int | Összehasonlít részstringet |
| `compare(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen)` | int | Összehasonlít részstringeket |
| `compare(const char* s)` | int | Összehasonlít C-stringgel |
| `compare(size_t pos, size_t len, const char* s)` | int | Összehasonlít részstringet C-stringgel |
| `compare(size_t pos, size_t len, const char* s, size_t n)` | int | Összehasonlít részstringet bufferrel |
| **Módosítók** |
| `operator+=(const string& str)` | string& | Hozzáfűz egy stringet |
| `operator+=(const char* s)` | string& | Hozzáfűz egy C-stringet |
| `operator+=(char c)` | string& | Hozzáfűz egy karaktert |
| `operator+=(initializer_list<char> il)` | string& | Hozzáfűz inicializáló listát (C++11) |
| `append(const string& str)` | string& | Hozzáfűz egy stringet |
| `append(const string& str, size_t subpos, size_t sublen)` | string& | Hozzáfűz részstringet |
| `append(const char* s)` | string& | Hozzáfűz C-stringet |
| `append(const char* s, size_t n)` | string& | Hozzáfűz buffert |
| `append(size_t n, char c)` | string& | Hozzáfűz n darab c karaktert |
| `append(InputIterator first, InputIterator last)` | string& | Hozzáfűz range-et |
| `append(initializer_list<char> il)` | string& | Hozzáfűz inicializáló listát (C++11) |
| `push_back(char c)` | void | Hozzáfűz egy karaktert a végére |
| `assign(const string& str)` | string& | Értékül ad egy stringet |
| `assign(const string& str, size_t subpos, size_t sublen)` | string& | Értékül ad részstringet |
| `assign(const char* s)` | string& | Értékül ad C-stringet |
| `assign(const char* s, size_t n)` | string& | Értékül ad buffert |
| `assign(size_t n, char c)` | string& | Értékül ad n darab c karaktert |
| `assign(InputIterator first, InputIterator last)` | string& | Értékül ad range-et |
| `assign(initializer_list<char> il)` | string& | Értékül ad inicializáló listát (C++11) |
| `assign(string&& str)` | string& | Move assign (C++11) |
| `insert(size_t pos, const string& str)` | string& | Beszúr egy stringet a megadott pozícióra |
| `insert(size_t pos, const string& str, size_t subpos, size_t sublen)` | string& | Beszúr részstringet |
| `insert(size_t pos, const char* s)` | string& | Beszúr C-stringet |
| `insert(size_t pos, const char* s, size_t n)` | string& | Beszúr buffert |
| `insert(size_t pos, size_t n, char c)` | string& | Beszúr n darab c karaktert |
| `insert(const_iterator p, size_t n, char c)` | iterator | Beszúr n darab c karaktert iterátornál |
| `insert(const_iterator p, char c)` | iterator | Beszúr egy karaktert iterátornál |
| `insert(const_