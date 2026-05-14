Azonban a standard könyvtár egyes részeihez importálásra van szükség, mielőtt használhatnád őket a kódodban. Például, ha a standard könyvtár időmérési funkcióit szeretnéd használni, importálnod kell a `kotlin.time` csomagot. A fájlod elején add hozzá az `import` kulcsszót, majd a szükséges csomagot:

```
import kotlin.time.*
```

A csillag `*` egy helyettesítő karakter (wildcard), amely azt mondja a Kotlin-nak, hogy importáljon mindent a csomagon belül. A csillag `*` nem használható társosztályokkal. Ehelyett explicit módon kell deklarálnod a használni kívánt társosztály tagjait. Például:

```
import kotlin.time.Duration
import kotlin.time.Duration.Companion.hours
import kotlin.time.Duration.Companion.minutes

fun main() {
    val thirtyMinutes: Duration = 30.minutes
    val halfHour: Duration = 0.5.hours
    println(thirtyMinutes == halfHour) // true
}
```

Ez a példa:
- Importálja a `Duration` osztályt és a `hours` és `minutes` kiterjesztési tulajdonságokat a társosztályából.
- A `minutes` tulajdonságot használja 30 konvertálására 30 perces `Duration` objektummá.
- A `hours` tulajdonságot használja 0.5 konvertálására 30 perces `Duration` objektummá.
- Ellenőrzi, hogy mindkét időtartam egyenlő-e, és kiírja az eredményt.

## Keresés a saját fejlesztés előtt

Mielőtt úgy döntenél, hogy saját kódot írsz, ellenőrizd a standard könyvtárt, hogy megtalálod-e azt, amit keresel. Itt egy lista azokról a területekről, ahol a standard könyvtár már számos osztályt, függvényt és tulajdonságot biztosít számodra:

- Kollekciók
- Sorozatok
- Karakterlánc-manipuláció
- Időkezelés

További információkért a standard könyvtár tartalmáról fedezd fel az API referenciáját.

## Kotlin könyvtárak

A standard könyvtár sok gyakori használati esetet lefedi, de vannak olyanok is, amelyekkel nem foglalkozik. Szerencsére a Kotlin csapat és a közösség kifejlesztett számos könyvtárat a standard könyvtár kiegészítésére.

Például a `kotlinx-datetime` segít az idő kezelésében különböző platformokon. Hasznos könyvtárakat találhatsz a keresőplatformunkon. A használatukhoz extra lépéseket kell tenned, mint például függőség vagy plugin hozzáadása. Minden könyvtárhoz tartozik egy GitHub repository utasításokkal arról, hogyan vedd fel őket a Kotlin projektjeidbe. Miután hozzáadtad a könyvtárat, importálhatsz bármely csomagot belőle.

Itt egy példa a `kotlinx-datetime` csomag importálására az aktuális idő meghatározásához New Yorkban:

```
import kotlinx.datetime.*

fun main() {
    val now = Clock.System.now() // Aktuális időpont lekérése
    println("Current instant: $now")
    val zone = TimeZone.of("America/New_York")
    val localDateTime = now.toLocalDateTime(zone)
    println("Local date-time in NY: $localDateTime")
}
```

Ez a példa:
- Importálja a `kotlinx.datetime` csomagot.
- A `Clock.System.now()` függvényt használja egy `Instant` osztály példány létrehozásához, amely tartalmazza az aktuális időt, és az eredményt hozzárendeli a `now` változóhoz.
- Kiírja az aktuális időt.
- A `TimeZone.of()` függvényt használja New York időzónájának meghatározásához, és az eredményt hozzárendeli a `zone` változóhoz.
- Meghívja a `.toLocalDateTime()` függvényt az aktuális időt tartalmazó példányon, New York időzónával argumentumként.
- Hozzárendeli az eredményt a `localDateTime` változóhoz.
- Kiírja az időt, amelyet New York időzónájához igazított.

A példában használt függvények és osztályok részletesebb megismeréséhez lásd az API referenciát.

## API-k használatának engedélyezése

A könyvtárfejlesztők bizonyos API-kat megjelölhetnek úgy, hogy azok használatához engedélyezni kell őket a kódodban. Ezt általában akkor teszik, amikor egy API még fejlesztés alatt áll, és a jövőben változhat. Ha nem engedélyezed, figyelmeztetéseket vagy hibákat látsz, például:

```
This declaration needs opt-in. Its usage should be marked with '@...' or '@OptIn(...)'
```

Az engedélyezéshez írd le `@OptIn` majd zárójelek közé a osztály nevét, amely kategorizálja az API-t, utána kettő kettőspont `::` és `class`. Például a standard könyvtár `uintArrayOf()` függvénye a `@ExperimentalUnsignedTypes` alá tartozik, ahogy az API referenciában szerepel:

```
@ExperimentalUnsignedTypes
inline fun uintArrayOf(vararg elements: UInt): UIntArray
```

A kódodban az engedélyezés így néz ki:

```
@OptIn(ExperimentalUnsignedTypes::class)
```

Itt egy példa, amely engedélyezi a `uintArrayOf()` függvény használatát nem negatív egész számok tömbjének létrehozásához és egy elem módosításához:

```
@OptIn(ExperimentalUnsignedTypes::class)
fun main() {
    // Nem negatív egész számok tömbjének létrehozása
    val unsignedArray: UIntArray = uintArrayOf(1u, 2u, 3u, 4u, 5u)
    // Egy elem módosítása
    unsignedArray[2] = 42u
    println("Updated array: ${unsignedArray.joinToString()}") 
    // Updated array: 1, 2, 42, 4, 5
}
```

Ez a legegyszerűbb módja az engedélyezésnek, de vannak más módok is. További információ: Engedélyezési követelmények.

## Gyakorlás

### 1. feladat

Egy pénzügyi alkalmazást fejlesztesz, amely segít a felhasználóknak kiszámítani befektetéseik jövőbeli értékét. A kamatos kamat kiszámításának képlete:

Ahol:
- A az összegyűjtött pénz összege kamat után (tőke + kamat).
- P a tőkeösszeg (a kezdeti befektetés).
- r az éves kamatláb (decimális).
- n az évente elvégzett kamatszámítások száma.
- t az idő, amíg a pénzt befektetik (években).

Frissítsd a kódot:
1. Importáld a szükséges függvényeket a `kotlin.math` csomagból.
2. Add hozzá a `calculateCompoundInterest()` függvény törzsét, amely kiszámítja a végösszeget a kamatos kamat alkalmazása után.

```
// Write your code here || Írd ide a kódodat

fun calculateCompoundInterest(P: Double, r: Double, n: Int, t: Int): Double {
    // Write your code here || Írd ide a kódodat
}

fun main() {
    val principal = 1000.0
    val rate = 0.05
    val timesCompounded = 4
    val years = 5
    val amount = calculateCompoundInterest(principal, rate, timesCompounded, years)
    println("The accumulated amount is: $amount") 
    // The accumulated amount is: 1282.0372317085844
}
```

#### Megoldás
```
import kotlin.math.*

fun calculateCompoundInterest(P: Double, r: Double, n: Int, t: Int): Double {
    return P * (1 + r / n).pow(n * t)
}

fun main() {
    val principal = 1000.0
    val rate = 0.05
    val timesCompounded = 4
    val years = 5
    val amount = calculateCompoundInterest(principal, rate, timesCompounded, years)
    println("The accumulated amount is: $amount") 
    // The accumulated amount is: 1282.0372317085844
}
```

### 2. feladat

Meg szeretnéd mérni, hogy mennyi időt vesz igénybe több adatfeldolgozási feladat végrehajtása a programodban. Frissítsd a kódot a megfelelő import utasítások és függvények hozzáadásával a `kotlin.time` csomagból:

```
// Write your code here || Írd ide a kódodat

fun main() {
    val timeTaken = /* Write your code here */ {
        // Szimulál néhány adatfeldolgozást
        val data = List(1000) { it * 2 }
        val filteredData = data.filter { it % 3 == 0 }
        // Szimulálja a szűrt adatok feldolgozását
        val processedData = filteredData.map { it / 2 }
        println("Processed data")
    }
    println("Time taken: $timeTaken") // pl. 16 ms
}
```

#### Megoldás
```
import kotlin.time.measureTime

fun main() {
    val timeTaken = measureTime {
        // Szimulál néhány adatfeldolgozást
        val data = List(1000) { it * 2 }
        val filteredData = data.filter { it % 3 == 0 }
        // Szimulálja a szűrt adatok feldolgozását
        val processedData = filteredData.map { it / 2 }
        println("Processed data")
    }
    println("Time taken: $timeTaken") // pl. 16 ms
}
```

### 3. feladat

A standard könyvtárban egy új funkció érhető el a legújabb Kotlin kiadásban. Ki szeretnéd próbálni, de az engedélyezést igényel. A funkció az `@ExperimentalStdlibApi` alá tartozik. Hogyan kell kinéznie az engedélyezésnek a kódodban?

#### Megoldás
```
@OptIn(ExperimentalStdlibApi::class)
```

## Mi a következő?

Gratulálunk! Befejezted a középhaladó túrát! Következő lépésként fedezd fel oktatóanyagainkat a népszerű Kotlin alkalmazásokhoz:

- Hozz létre egy háttéralkalmazást Spring Boot-tal és Kotlin-nal
- Hozz létre egy többplatformos alkalmazást Androidra és iOS-re nulláról és:
  - Oszd meg az üzleti logikát, miközben a felhasználói felület megmarad natív
  - Oszd meg az üzleti logikát és a felhasználói felületet

## Kotlin szerveroldalra

A Kotlin kiváló választás szerveroldali alkalmazások fejlesztéséhez. Lehetővé teszi a tömör és kifejező kód írását miközben teljes kompatibilitást biztosít a meglévő Java-alapú technológiai veremmel, mindezt zökkenőmentes tanulási görbével:

- **Kifejezőkészség:** A Kotlin innovatív nyelvi funkciói, például a típusbiztos építők és delegált tulajdonságok támogatása, segít hatékony és könnyen használható absztrakciók építésében.
- **Méretezhetőség:** A Kotlin coroutinok támogatása segít olyan szerveroldali alkalmazások építésében, amelyek masszív számú ügyfélig skálázhatók mérsékelt hardverkövetelményekkel.
- **Interoperabilitás:** A Kotlin teljesen kompatibilis minden Java-alapú keretrendszerrel, így használhatod a megszokott technológiai vermed, miközben élvezheted a modern nyelv előnyeit.
- **Migráció:** A Kotlin támogatja a nagy kódbázisok fokozatos migrációját Javából Kotlinba. Elkezdheted az új kód írását Kotlinban, miközben a rendszer régebbi részeit Java nyelven tarthatod meg.
- **Eszköztámogatás:** Az általános IDE támogatáson túl a Kotlin framework-specifikus eszközöket kínál (például Spring és Ktor) az IntelliJ IDEA Ultimate pluginban.
- **Tanulási görbe:** Java fejlesztő számára a Kotlin elkezdése nagyon egyszerű. Az automatikus Java-to-Kotlin konverter, amely a Kotlin pluginban található, segít az első lépések megtételében. A Kotlin Koans sorozat interaktív gyakorlatokkal vezet végig a kulcsfontosságú nyelvi funkciókon.

## Keretrendszerek szerveroldali fejlesztéshez Kotlin-nal

Itt néhány példa a szerveroldali keretrendszerekre Kotlinhoz:

- **Spring** kihasználja a Kotlin nyelvi funkcióit tömörebb API-k kínálatához, kezdve az 5.0-s verziótól. Az online projektgenerátor lehetővé tesz egy új projekt gyors létrehozását Kotlin-ban.
- **Ktor** JetBrains által kifejlesztett keretrendszer webalkalmazások létrehozásához Kotlinban, amely kihasználja a coroutinokat nagy skálázhatóság érdekében, és könnyen használható és idiomatikus API-t kínál.
- **Quarkus** első osztályú támogatást nyújt Kotlin használatához. A keretrendszer nyílt forráskódú és a Red Hat karbantartja. Quarkust alapjaiban Kuberneteshez építették, és komplex teljes verem keretrendszert biztosít számos kiváló könyvtár felhasználásával.
- **Vert.x**, egy reaktív webalkalmazások építésére szolgáló keretrendszer a JVM-en, dedikált Kotlin támogatással rendelkezik, beleértve teljes dokumentációt.
- **kotlinx.html** egy DSL, amely segítségével HTML-t építhetsz webalkalmazásokban. Ez egy alternatíva a hagyományos sablonrendszerhez, mint a JSP és a FreeMarker.
- **Micronaut** egy modern JVM-alapú teljes verem keretrendszer moduláris, könnyen tesztelhető mikroszolgáltatások és serverless alkalmazások építéséhez. Sok hasznos beépített funkcióval rendelkezik.
- **http4k** egy kis méretű funkcionális eszköztár Kotlin HTTP alkalmazásokhoz, tisztán Kotlin-ban írva. A könyvtár a Twitter "Your Server as a Function" tanulmányán alapul, és mind a HTTP szervereket, mind a HTTP klienseket egyszerű Kotlin függvényként modellezi, amelyek egymással komponálhatók.

## Kotlin szerveroldali alkalmazások telepítése

A Kotlin alkalmazások telepíthetők bármely olyan szolgáltatónál, amelyek támogatják a Java Web alkalmazásokat, beleértve az Amazon Web Services-t, a Google Cloud Platform-ot és még sok mást. 

A Kotlin alkalmazások Heroku-ra való telepítéséhez követheted a hivatalos Heroku oktatóanyagát. 
Az AWS Labs egy mintaprojektet biztosít, amely bemutatja, hogyan használható a Kotlin AWS Lambda függvények írásához. 
A Google Cloud Platform sorozatos oktatóanyagokat kínál Kotlin alkalmazások telepítéséhez a GCP-re, mind Ktor és App Engine, mind Spring és App Engine esetén. 
Továbbá van egy interaktív kódlabor a Kotlin Spring alkalmazás telepítéséhez.

## Termékek, amelyek szerveroldalon használnak Kotlin-t

- **Corda** egy nyílt forráskódú elosztott nyilvántartó platform, amelyet nagy bankok támogatnak, és teljes egészében Kotlin-ban épült.
- **JetBrains Fiók**, a rendszer, amely felelős a JetBrains teljes licencelési és validációs folyamatért, 100%-ban Kotlin-ban íródott, és 2015 óta működik éles környezetben jelentősebb problémák nélkül.
- **Chess.com** egy weboldal, amely a sakkot és a világ százezreitól játékosait szolgálja. A Chess.com a Ktor-t használja a több HTTP kliens egyszerű konfigurálásához.

## Következő lépések

A nyelv mélyebb megismeréséhez fedezd fel a Kotlin dokumentációt ezen az oldalon és a Kotlin Koans-t. Fedezd fel, hogyan építsz aszinkron szerveralkalmazásokat a Ktor keretrendszerrel, amely a Kotlin coroutinokat használja. Nézz meg webinar-okat "Micronaut for microservices with Kotlin" címmel, és fedezd fel a részletes útmutatót, amely bemutatja, hogyan használhatod a Kotlin kiterjesztési függvényeket a Micronaut keretrendszerben. A http4k biztosít CLI-t teljes projekt létrehozásához, és egy starter repo-t egy teljes CD pipeline generálásához GitHub, Travis és Heroku használatával egyetlen bash parancs által.

Szeretnél Java-ról Kotlin-ra migrálni? Tanuld meg, hogyan hajts végre tipikus karakterlánc-manipulációs feladatokat Javában és Kotlinban.

## Kotlin Androidra

Az Android mobilfejlesztés Kotlin-first lett 2019-es Google I/O óta. Az Android fejlesztők több mint 50%-a Kotlin-t használ elsődleges nyelvként, míg csak 30% használja Javát fő nyelvként. A Kotlin elsődleges nyelvű fejlesztők 70%-a azt mondja, hogy a Kotlin produktívabbá teszi őket.

A Kotlin Android fejlesztéshez való használatával előnyöket élhetsz:

- **Kevesebb kód nagyobb olvashatósággal.** Kevesebb időt kell tölteni a kód írásával és mások kódjának megértésével.
- **Kevesebb gyakori hiba.** A Kotlin-nal készült alkalmazások 20%-kal kevesebb eséllyel omlanak össze a Google belső adatai szerint.
- **Kotlin támogatás a Jetpack könyvtárakban.** Jetpack Compose az Android ajánlott modern eszköze natív felhasználói felület építéséhez Kotlinban. KTX kiterjesztések hozzáadják a Kotlin nyelvi funkciókat, mint a coroutinokat, kiterjesztési függvényeket, lambda kifejezéseket és az elnevezett paramétereket a meglévő Android könyvtárakhoz.
- **Többplatformos fejlesztés támogatása.** A Kotlin Multiplatform lehetőséget biztosít nemcsak Androidra, hanem iOS-re, háttéralkalmazásokra és webalkalmazásokra is. Egyes Jetpack könyvtárak már többplatformosak. Compose Multiplatform, JetBrains deklaratív felhasználói felület keretrendszere Kotlin és Jetpack Compose alapján, lehetővé teszi a felhasználói felületek megosztását a platformok között – iOS, Android, desktop és web.
- **Érett nyelv és környezet.** A létrehozása óta 2011-ben a Kotlin folyamatosan fejlődött, nemcsak nyelvként hanem teljes környezetként is, robusztus eszköztámogatással. Jelenleg zökkenőmentesen be van építve az Android Studioba, és aktívan több vállalat használja Android alkalmazások fejlesztésére.
- **Interoperabilitás Javával.** Használhatsz Kotlin-t és Java programozási nyelvet az alkalmazásaidban anélkül, hogy teljes körűen Kotlin-ra kellene migrálnod a meglévő kódodat.
- **Könnyű tanulás.** A Kotlin nagyon könnyen tanulható, különösen a Java fejlesztők számára.
- **Nagy közösség.** A Kotlin-nak remek támogatása van, és sok hozzájárulás érkezik a világszerte növekvő közösségtől. A top thousand Android applikációk több mint 95%-a Kotlin-t használ. Sok startup és Fortune 500 vállalat már fejlesztett Android alkalmazást Kotlin-nal, tekintsd meg a listát a Google weboldalán Android fejlesztőknek.

A Kotlin Android fejlesztés megkezdéséhez olvasd el a Google dokumentációját az Android app fejlesztésről Kotlin-nal. A többplatformos mobilalkalmazások fejlesztéséhez lásd: Hozz létre egy alkalmazást megosztott logikával és natív UI-val.

## Kotlin/Wasm

A Kotlin/Wasm képes lefordítani a Kotlin kódodat WebAssembly (Wasm) formátumra. A Kotlin/Wasm segítségével olyan alkalmazásokat hozhatsz létre, amelyek különböző környezetekben és eszközökön futnak, amelyek támogatják a Wasm-ot és megfelelnek a Kotlin követelményeinek.

A Wasm egy bináris utasításformátum egy verem alapú virtuális gépszámára. Ez a formátum platformfüggetlen, mert saját virtuális gépén fut. A Wasm biztosítja a Kotlin és más nyelvek számára a fordítási célt. Használhatod a Kotlin/Wasm a különböző célkörnyezetekben, például böngészőkben webalkalmazások fejlesztéséhez Compose Multiplatformon keresztül, vagy böngészőn kívül önálló Wasm virtuális gépekben.

A böngészőn kívüli esetben a WebAssembly System Interface (WASI) biztosít hozzáférést a platform API-khoz, amelyeket szintén kihasználhatsz.

A Kotlin/Wasm-mal épített alkalmazások böngészőben való futtatásához a felhasználóinak olyan böngészőverzióra van szükségük, amely támogatja a WebAssembly garbage collection és legacy exception handling javaslatokat. A böngészőtámogatás állapotának ellenőrzéséhez lásd a WebAssembly roadmap-ot.

## Kotlin/Wasm és Compose Multiplatform

Kotlin segítségével lehetőséged van mobil és desktop felhasználói felületek (UI-k) újrafelhasználására webes projekteidben Compose Multiplatform és Kotlin/Wsam segítségével. A Compose Multiplatform egy deklaratív keretrendszer, amely Kotlin és Jetpack Compose alapján épít, lehetővé téve a felhasználói felület egyszeri implementálását és az összes célzott platformon történő megosztását.

Webplatformokhoz a Compose Multiplatform a Kotlin/Wasm-et használja fordítási célpontként. A Kotlin/Wasm és Compose Multiplatform segítségével épített alkalmazások egy wasm-js célpontot használnak, és böngészőkben futnak.

Fedezd fel online demónkat egy Compose Multiplatform és Kotlin/Wasm segítségével épített alkalmazásrol.

Ezen felül a Kotlin/Wasm esetében a legnépszerűbb Kotlin könyvtárakat azonnal használhatod. Mint más Kotlin és Multiplatform projekt esetén a build szkriptben megadhatod a függőségeket.

Szeretnéd kipróbálni? Kezdd el a Kotlin/Wasm-mal.

## Kotlin/Wasm és WASI

A Kotlin/Wasm a WebAssembly System Interface (WASI) segítségével működik a szerveroldali alkalmazásokban. A Kotlin/Wasm és WASI segítségével épített alkalmazások egy Wasm-WASI célpontot használnak, lehetővé téve a WASI API hívását és az alkalmazások böngészőn kívüli környezetben való futtatását. A Kotlin/Wasm a WASI-t használja a platformspecifikus részletek elvontabbá tételéhez, lehetővé téve ugyanazon Kotlin kód futtatását különböző platformokon. Ez kiterjeszti a Kotlin/Wasm elérhetőségét a webes alkalmazásokon túl anélkül, hogy egyedi kezelésre lenne szükség minden futtatókörnyezetre. A WASI biztonságos szabványos interfészt biztosít a WebAssembly-re lefordított Kotlin alkalmazások futtatására különböző környezetekben.

## Kotlin/Wasm teljesítmény

Bár a Kotlin/Wasm még Alphában van, a Compose Multiplatform, amely Kotlin/Wasm-on fut, már biztató teljesítményjellemzőket mutat. Láthatod, hogy végrehajtási sebessége meghaladja a JavaScript teljesítményét és közelít a JVM szintjéhez.

Rendszeresen futtatunk teljesítményméréseket Kotlin/Wasm-on, és ezek az eredmények a Google Chrome legújabb verziójában született tesztjeinkből származnak.

## Böngésző API támogatás

A Kotlin/Wasm standard könyvtár deklarációkat biztosít böngésző API-khoz, beleértve a DOM API-t. Ezeknek a deklarációknak köszönhetően közvetlenül használhatod a Kotlin API-t a különböző böngészőfunkciók elérésére és használatára. Például a Kotlin/Wasm alkalmazásaidban használhatsz DOM elemek manipulálását vagy fetch API-t anélkül, hogy ezeket a deklarációkat nulláról kellene definiálnod.

## Visszajelzés hagyása

### Kotlin/Wasm visszajelzés
- Slack: Szerezz Slack meghívót és adj visszajelzést közvetlenül a fejlesztőknek a #webassembly csatornán.
- Jelents be minden problémát a YouTrack-ban.

### Compose Multiplatform visszajelzés
- Slack: Adj visszajelzést a #compose-web nyilvános csatornán. 
- Jelents be minden problémát GitHub-on.

## További információk

Tudj meg többet a Kotlin/Wasm-ról ebben a YouTube lejátszási listában. Fedezd fel a Kotlin/Wasm példákat a GitHub repository-nkban.

## Kotlin/Native

A Kotlin/Native egy technológia, amely lehetővé teszi a Kotlin kód lefordítását natív bináris fájlokra, amelyek virtuális gép nélkül futnak. A Kotlin/Native tartalmaz egy LLVM-alapú backend-et a Kotlin fordítóhoz és a Kotlin standard könyvtár natív implementációját.

## Miért Kotlin/Native?

A Kotlin/Native elsősorban arra lett tervezve, hogy lehetővé tegye a fordítást olyan platformokra, ahol virtuális gépek nem kívánatosak vagy nem lehetségesek, például beágyazott eszközökön vagy iOS-en. Ideális olyan helyzetekben, amikor önálló programot szeretnél készíteni, amely nem igényel további futtatókörnyezetet vagy virtuális gépet. Könnyen beillesztheted a lefordított Kotlin kódot meglévő C, C++, Swift, Objective-C és egyéb nyelveken írt projektjeidbe. Használhatsz meglévő natív kódot, statikus vagy dinamikus C könyvtárakat, Swift/Objective-C keretrendszereket, grafikus motorokat és bármit más közvetlenül Kotlin-ből/Native-ből.

## Célplatformok

A Kotlin/Native támogatja a következő platformokat:
- Linux
- Windows (MinGW-n keresztül)
- Android NDK
- Apple célok macOS-hez, iOS-hez, tvOS-hez és watchOS-hez

Apple célok fordításához telepítened kell az Xcode-ot és annak parancssoros eszközeit. Lásd a támogatott célok teljes listáját.

## Interoperabilitás

A Kotlin/Native kétirányú interoperabilitást támogat a natív programozási nyelvekkel különböző operációs rendszereken. A fordító végrehajtható fájlokat tud létrehozni sok platformra, statikus vagy dinamikus C könyvtárakat és Swift/Objective-C keretrendszereket.

### Interoperabilitás C-vel

A Kotlin/Native interoperabilitást biztosít C-vel. Használhatsz meglévő C könyvtárakat közvetlenül Kotlin kódból. További információért végezd el a következő oktatóanyagokat:
- Hozz létre egy dinamikus könyvtárat C fejlécekkel C/C++ projektekből
- Tanuld meg, hogyan vannak a C típusok leképezve Kotlinra
- Hozz létre egy natív HTTP klienst C interop és libcurl használatával

### Interoperabilitás Swift/Objective-C-vel

A Kotlin/Native interoperabilitást biztosít Swift-cel Objective-C-n keresztül. Használhatsz Kotlin kódot közvetlenül Swift/Objective-C alkalmazásokból macOS-en és iOS-en. További információért végezd el a Kotlin/Native, mint Apple keretrendszer oktatóanyagot.

## Kód megosztása platformok között

A Kotlin/Native tartalmazza az előre elkészített platformkönyvtárak halmazát, amelyek segítenek Kotlin kód megosztásában a projektek között. POSIX, gzip, OpenGL, Metal, Foundation és számos más népszerű könyvtár és Apple keretrendszer előre importálva van és Kotlin/Native könyvtárakként szerepel a fordítócsomagban. A Kotlin/Native a Kotlin Multiplatform technológia része, amely segít a közös kód megosztásában több platform között, beleértve Androidot, iOS-t, JVM-t, webet és natív platformokat. A többplatformos könyvtárak biztosítják a szükséges API-kat a közös Kotlin kódhoz, és lehetővé teszik a projektek közös részeinek Kotlinban való megírását mind egy helyen.

## Memóriakezelő

A Kotlin/Native egy automatikus memóriakezelőt használ, amely hasonló a JVM-hez és Go-hoz. Saját nyomkövető szemétgyűjtővel rendelkezik, amely integrálva van a Swift/Objective-C ARC-vel. A memóriafogyasztást egy személyre szabott memóriafoglaló ellenőrzi. Optimalizálja a memóriahasználatot és segít megelőzni a memóriafoglalási hirtelen kiugrásokat.

## Kotlin/JavaScript

A Kotlin/JavaScript (Kotlin/JS) lehetővé teszi a Kotlin kódod, a Kotlin standard könyvtár és minden kompatibilis függőség JavaScript-re való transzpilálását. Így a Kotlin alkalmazásaid bármely JavaScript-et támogató környezetben futtathatók. Használd a Kotlin Multiplatform Gradle plugint (`kotlin.multiplatform`) a Kotlin projektjeid konfigurálásához és kezeléséhez, amelyek JavaScript-re céloznak egyetlen helyről. A Kotlin Multiplatform Gradle plugin hozzáférést biztosít olyan funkciókhoz, mint az alkalmazás csomagolásának vezérlése és JavaScript függőségek közvetlen hozzáadása az npm-ből. Az elérhető konfigurációs lehetőségek áttekintéséhez lásd: Kotlin/JS projekt beállítása. A Kotlin/JS jelenlegi implementációja az ES5 és ES2015 szabványokra céloz.

## Kotlin/JS használati esetek

Itt van néhány gyakori módja a Kotlin/JS használatának:

### Frontend és JVM backend közötti közös logika megosztása

Ha a backend-ed Kotlinban vagy más JVM-kompatibilis nyelven íródott, megoszthatod a közös kódot a webalkalmazásod és a backend között. Ez magában foglalja az adatátviteli objektumokat (DTO-k), validációs és hitelesítési szabályokat, REST API végpontok absztrakcióit és még sok mást.

### Android, iOS és web kliensek közötti közös logika megosztása

Megoszthatod az üzleti logikát a webes felület és a Android és iOS mobilalkalmazások között, miközben megtartod a natív felhasználói felületeket. Ez elkerüli az olyan közös funkcionalitások duplikálását, mint a REST API absztrakciók, felhasználói hitelesítés, űrlapvalidáció és domain modellek.

### Frontend webalkalmazások építése Kotlin/JS segítségével

Használj Kotlin-t hagyományos web frontendek fejlesztéséhez, miközben integrálódhatsz meglévő eszközökkel és könyvtárakkal:

- Ha ismerős az Android fejlesztés, webalkalmazásokat építhetsz Compose-alapú keretrendszerekkel, mint a Kobweb vagy Kilua.
- Építs teljesen típusbiztos React alkalmazásokat Kotlin/JS segítségével a JetBrains által biztosított közös JavaScript könyvtárak Kotlin wrappereivel.
- A Kotlin wrapperek (kotlin-wrappers) absztrakciókat és integrációkat kínálnak a React-hoz és más JavaScript keretrendszerekhez. Ezek a wrapperek támogatják a kiegészítő könyvtárakat is, mint a React Redux, React Router és styled-components.
- Használhatsz harmadik féltől származó React komponenseket és komponenskönyvtárakat a JavaScript ökoszisztéma interoperabilitásán keresztül.
- Használj Kotlin/JS keretrendszereket, amelyek integrálódnak a Kotlin ökoszisztémával, és támogatják a tömör és kifejező kódot.

### Többplatformos alkalmazások régebbi böngészők támogatásával

A Compose Multiplatform segítségével használhatsz Kotlin-t alkalmazások építéséhez és mobil és desktop felhasználói felületek újrafelhasználásához a webes projektjeidben. Bár a Kotlin/Wasm az elsődleges cél erre a célra, kiterjesztheted a támogatást a régebbi böngészőkre is a Kotlin/JS-re is célozással.

### Szerveroldali és serverless alkalmazások Kotlin/JS segítségével

A Kotlin/JS Node.js célpontja lehetővé teszi alkalmazások létrehozását szerveroldali vagy serverless környezetekhez JavaScript futtatókörnyezetben. Ez gyors indítást és alacsony memóriahasználatot kínál. A kotlinx-nodejs könyvtár típusbiztos hozzáférést biztosít a Node.js API-hoz Kotlin-ból.

A használati esetedtől függően a Kotlin/JS projektek használhatnak kompatibilis könyvtárakat a Kotlin ökoszisztémából és harmadik féltől származó könyvtárakat a JavaScript és TypeScript ökoszisztémákból. Harmadik féltől származó könyvtárak használatához létrehozhatsz saját típusbiztos wrappereket vagy használhatsz közösségi karbantartású wrappereket. Emellett használhatod a Kotlin/JS dinamikus típusát, amely lehetővé teszi a szigorú típusozás és könyvtári wrapperek kihagyását, a típusbiztonság árán.

A Kotlin/JS kompatibilis a leggyakoribb modulrendszerekkel: ESM, CommonJS, UMD és AMD. Ez lehetővé teszi a modulok előállítását és fogyasztását, valamint a JavaScript ökoszisztémába való strukturált integrációt.

## Oszd meg a használati eseteidet

A Kotlin/JS használati eseteinek listája nem teljes. Szabadon kísérletezhetsz különböző megközelítésekkel, és megtalálhatod a projektedhez legjobban illőt. Oszd meg a használati eseteidet, tapasztalataidat és kérdéseidet a Kotlin/JS közösséggel a Kotlin Slack #javascript csatornáján.

## Első lépések Kotlin/JS-sel

Fedezd fel az alapokat és az első lépéseket a Kotlin/JS-sel való munka megkezdéséhez:

- Ha új vagy a Kotlin-ban, kezdd az alap szintaxis áttekintésével és a Kotlin túra felfedezésével.
- Nézd meg a Kotlin/JS mintaprojektek listáját ihletért. Ezek a minták hasznos kódrészleteket és mintákat tartalmaznak, amelyek segíthetnek elindulni a projektjeiddel.
- Ha új vagy a Kotlin/JS-ben, kezdd a beállítási útmutatóval, mielőtt haladóbb témákba mennél bele:

### Kotlin/JS projekt beállítása
### Kotlin/JS mintaprojektek

A következő táblázat olyan mintaprojekteket sorol fel, amelyek különböző Kotlin/JS használati eseteket, architektúrákat és kód-megosztási stratégiákat mutatnak be:

| Projekt | Leírás |
|---------|--------|
| Petclinic közös kóddal Spring és Angular között | Bemutatja, hogyan lehet elkerülni a kódduplikációt vállalati alkalmazásokban az adatátviteli objektumok, validációs és hitelesítési szabályok, valamint REST API végpontok absztrakcióinak megosztásával. A kód meg van osztva egy Spring Boot backend és egy Angular frontend között. |
| Fullstack Conference CMS | Több kód-megosztási megközelítést mutat be, a legegyszerűbbtől az összes kódmegosztásig a Ktor, Jetpack Compose és Vue.js alkalmazások között. |
| Todo App egy Compose-alapú HTML Kobweb keretrendszeren | Bemutatja, hogyan lehet létrehozni egy teendőlista alkalmazást az Android fejlesztők számára ismerős megközelítés újrafelhasználásával. Egy a Kobweb keretrendszer által meghajtott kliens UI alkalmazást épít. |
| Egyszerű logikamegosztás Android, iOS és web között | Egy sablont tartalmaz projekt létrehozásához közös logikával Kotlinban, amelyet platform-natív UI alkalmazásokban használnak Androidon (Jetpack Compose), iOS-en (SwiftUI) és weben (React). |
| Teljes körű együttműködő teendőlista | Bemutatja, hogyan lehet létrehozni egy teendőlista alkalmazást együttműködéshez Kotlin Multiplatform használatával JS és JVM célokhoz. Ktor-t használ a backendhez, és Kotlin/JS-t React-tal a frontendhez. |

## Kotlin/JS keretrendszerek

A Kotlin/JS keretrendszerek leegyszerűsítik a webfejlesztést kész komponensek, útvonalválasztás, állapotkezelés és egyéb eszközök biztosításával modern webalkalmazások építéséhez. Nézd meg az elérhető Kotlin/JS keretrendszereket különböző szerzőktől.

## Csatlakozz a Kotlin/JS közösséghez

Csatlakozhatsz a hivatalos Kotlin Slack #javascript csatornájához, hogy beszélj a közösséggel és a Kotlin/JS csapattal.

## Mi a következő?

- Állíts be egy Kotlin/JS projektet
- Futtass Kotlin/JS projekteket
- Hibakeresés Kotlin/JS kódban
- Futtass teszteket Kotlin/JS-ben

## Kotlin adatelemzéshez

Az adatok felfedezése és elemzése olyan dolog, amelyet nem minden nap végzel el, de kulcsfontosságú készség szoftverfejlesztőként. Gondoljunk a szoftverfejlesztési feladatokra, ahol az adatelemzés kulcsfontosságú:

- Adatok elemzése kollekciókban hibakereséskor
- Memóriadump-ok vagy adatbázisok ásnivalója
- JSON fájlok fogadása nagy mennyiségű adattal REST API-k használatakor

A Kotlin Exploratív Adatelemzési (EDA) eszközeivel, mint a Kotlin notebook, Kotlin DataFrame és Kandy, rendelkezésedre áll egy gazdag eszköztár az analitikai készségeid fejlesztéséhez és különböző forgatókönyvek támogatásához:

- Töltsd be, transzformáld és vizualizáld az adatokat különböző formátumokban
- A Kotlin EDA eszközeivel olyan feladatokat hajthatsz végre, mint szűrés, rendezés és adataggregálás
- Eszközeink zökkenőmentesen olvashatnak adatokat különböző fájlformátumokból, beleértve a CSV, JSON és TXT-t
- A Kandy, mintázó eszközünk széles körű diagramokat hozhat létre az adathalmazból származó betekintésekhez

### Hatékony adatelemzés relációs adatbázisokban

A Kotlin DataFrame zökkenőmentesen integrálódik adatbázisokkal, és SQL-szerű lekérdezésekhez hasonló képességeket biztosít. Lekérheted, manipulálhatod és vizualizálhatod az adatokat közvetlenül különböző adatbázisokból.

### Valós idejű és dinamikus adathalmazok lekérése és elemzése web API-król

Az EDA eszközök rugalmassága lehetővé teszi külső API-k integrációját OpenAPI-szerű protokollokon keresztül. Ez a funkció segít adatok lekérésében webes API-król, majd az adatok tisztításában és transzformálásában az igényeid szerint.

### Szeretnéd kipróbálni a Kotlin adatelemzési eszközeit?

## Első lépések Kotlin Notebook-kal

A Kotlin adatelemzési eszközeink zökkenőmentesen kezelik az adataidat az elejétől a végéig. Könnyedén lekérheted az adataidat egyszerű fogd és vidd funkcionalitással a Kotlin Notebook-ban. Tisztítsd, transzformáld és vizualizáld csupán néhány sor kóddal. Emellett exportálhatod a kimeneti diagramokat néhány kattintással.

### Notebooks

A notebook interaktív szerkesztők, amelyek egyetlen környezetben integrálják a kódot, grafikákat és szöveget. Notebook használata során futtathatod a kódcellákat és azonnal láthatod a kimenetet. A Kotlin különböző notebook megoldásokat kínál, mint a Kotlin Notebook, Datalore és Kotlin-Jupyter Notebook, biztosítva kényelmes funkciókat az adatlekéréshez, transzformáláshoz, felfedezéshez, modellezéshez és egyebekhez. Ezek a Kotlin notebook megoldások a Kotlin Kernel-ünkre épülnek. Zökkenőmentesen megoszthatod a kódodat a Kotlin Notebook, Datalore és Kotlin-Jupyter Notebook között. Hozz létre projektet az egyik Kotlin notebookunkban, és folytasd a munkát egy másik notebookban kompatibilitási problémák nélkül. Hasznosítsd erőteljes Kotlin notebookjaink funkcióit és a Kotlin kódolás előnyeit.

A Kotlin integrálódik ezekbe a notebookba, hogy segítsen az adatok kezelésében és megoszd a kutatásaidat kollégáiddal, miközben építed az adattudományi és gépi tanulási készségeidet. Fedezd fel különböző Kotlin notebook megoldásaink funkcióit, és válaszd azt, amely legjobban illeszkedik a projekt igényeidhez.

### Kotlin Notebook

A Kotlin Notebook egy IntelliJ IDEA plugin, amely lehetővé teszi notebookok létrehozását Kotlinban. Biztosítja az IDE élményünket minden általános IDE funkcióval, valós idejű kódinformációkkal és projektintegrációval.

### Kotlin notebooks a Datalore-ban

A Datalore segítségével használhatod a Kotlin-t a böngészőben, további telepítés nélkül. Megoszthatod a notebookjaidat és futtathatod őket távolról, együttműködhetsz más Kotlin notebookokkal valós időben, intelligens kódolási segítséget kaphatsz a kód írása közben, és exportálhatod az eredményeket interaktív vagy statikus jelentéseken keresztül.

### Jupyter Notebook Kotlin Kernel-lel

A Jupyter Notebook egy nyílt forráskódú webalkalmazás, amely lehetővé teszi dokumentumok létrehozását és megosztását, amelyek kódot, vizualizációkat és Markdown szöveget tartalmaznak. A Kotlin-Jupyter egy nyílt forráskódú projekt, amely Kotlin támogatást hoz a Jupyter Notebook-hoz, hogy kihasználja a Kotlin erejét a Jupyter környezetben.

## Kotlin DataFrame

A Kotlin DataFrame könyvtár lehetővé teszi strukturált adatok manipulálását a Kotlin projektjeidben. Az adatlétrehozástól és tisztítástól kezdve a mély analízisig és funkciófejlesztésig, ez a könyvtár mindent lefed számodra. A Kotlin DataFrame könyvtárral dolgozhatsz különböző fájlformátumokkal, beleértve a CSV, JSON, XLS és XLSX. Ez a könyvtár is megkönnyíti az adatlekérési folyamatot az SQL adatbázisokhoz vagy API-khoz való kapcsolódás képességével.

## Kandy

A Kandy egy nyílt forráskódú Kotlin könyvtár, amely egy hatékony és rugalmas DSL-t biztosít különböző típusú diagramok ábrázolásához. Ez a könyvtár egy egyszerű, idiomatikus, olvasható és típusbiztos eszköz az adatok vizualizálásához. A Kandy zökkenőmentesen integrálódik Kotlin Notebook-kal, Datalore-mal és Kotlin-Jupyter Notebook-kal. Könnyen kombinálhatod a Kandy és Kotlin DataFrame könyvtárakat különböző adatkapcsolódó feladatok elvégzésére.

## Mi a következő?

- Első lépések Kotlin Notebook-kal
- Adatok lekérése és transzformálása a Kotlin DataFrame könyvtárral
- Adatok vizualizálása a Kandy könyvtárral
- Tudj meg többet a Kotlin és Java könyvtárakról adatelemzéshez

## Kotlin AI-meghajtott alkalmazásfejlesztéshez

A Kotlin modern és pragmatikus alapot biztosít AI-meghajtott alkalmazások építéséhez. Platformok között használható, jól integrálódik meglévő AI keretrendszerekkel, és támogatja az általános AI fejlesztési mintákat. Ez az oldal bemutatja, hogyan használják a Kotlin-t valós világbeli AI forgatókönyvekben a Kotlin-AI-példák gyűjteményéből származó működő példákkal.

## Kotlin AI-ügynök keretrendszer – Koog

A Koog egy Kotlin-alapú keretrendszer AI-ügynökök létrehozásához és futtatásához helyileg, külső szolgáltatások igénybevétele nélkül. A Koog a JetBrains innovatív, nyílt forráskódú ügynök-keretrendszere, amely lehetővé teszi fejlesztők számára AI-ügynökök építését a JVM ökoszisztémán belül. Tiszta Kotlin implementációt biztosít intelligens ügynökök építéséhez, amelyek interakcióba léphetnek eszközökkel, kezelhetnek összetett munkafolyamatokat, és kommunikálhatnak a felhasználókkal.

## További használati esetek

Számos más használati eset is létezik, ahol a Kotlin segíthet az AI fejlesztésben. A nyelvi modellek backend szolgáltatásokba való integrálásától az AI-meghajtott felhasználói felületek építéséig ezek a példák bemutatják a Kotlin sokoldalúságát különböző AI alkalmazásokban.

### Kibővített információ lekérés

Használj Kotlin-t kibővített információ lekérés (RAG) folyamatok építéséhez, amelyek nyelvi modelleket kapcsolnak össze külső forrásokkal, mint dokumentáció, vektor-tárolók vagy API-k. Például:

- springAI-demo: Egy Spring Boot alkalmazás, amely betölti a Kotlin standard könyvtár dokumentációit egy vektor-tárolóba, és támogatja a dokumentum-alapú kérdés-válaszolást.
- langchain4j-spring-boot: Egy minimális RAG példa a LangChain4j használatával.

### Ügynökalapú alkalmazások

Építs AI-ügynököket Kotlin-ban, amelyek gondolkodnak, terveznek és cselekszenek nyelvi modellek és eszközök használatával. Például:

- koog: Bemutatja, hogyan használható a Kotlin ügynök-keretrendszer Koog AI ügynökök építéséhez.
- langchain4j-spring-boot: Tartalmaz egy egyszerű, eszközöket használó ügynököt LangChain4j-vel építve.

### Gondolkodás láncolás késztetés

Implementálj strukturált késztetési technikákat, amelyek végigvezetik a nyelvi modelleket több lépcsős érvelésen. Például:

- LangChain4j_Overview.ipynb: Egy Kotlin Notebook, amely bemutatja a gondolat-láncolást és a strukturált kimenetet.

### LLM-ek backend szolgáltatásokban

Integrálj LLM-eket az üzleti logikába vagy REST API-kba Kotlin és Spring használatával. Például:

- spring-ai-examples: Besorolást, csevegést és összegzést tartalmazó példák.
- springAI-demo: Bemutatja az LLM válaszok teljes integrációját az alkalmazás logikával.

### Többplatformos felhasználói felületek AI-vel

Használj Compose Multiplatformot interaktív AI-meghajtott UI-k építéséhez Kotlin-ban. Például:

- mcp-demo: Egy asztali UI, amely Claude-hoz és OpenAI-hoz kapcsolódik, és válaszokat jelenít meg Compose Multiplatform használatával.

## Példák felfedezése

Felfedezheted és futtathatod a példákat a Kotlin-AI-példák gyűjteményéből. Minden projekt önellátó. Minden projektet referenciaként vagy sablonként használhatsz Kotlin-alapú AI alkalmazások építéséhez.

## Mi a következő?

- Végezd el a "Építs egy Kotlin alkalmazást, amely Spring AI-t használ dokumentumokkal történő kérdések megválaszolására Qdrantban tárolva" oktatóanyagot, hogy többet megtudj a Spring AI Kotlin-nal való használatáról IntelliJ IDEA-ban
- Csatlakozz a Kotlin közösséghez, hogy kapcsolatba lépj más fejlesztőkkel, akik AI alkalmazásokat építenek Kotlin-nal

## Kotlin versenyszoftver-fejlesztéshez

Ez az oktatóanyag versenyszoftver-fejlesztők számára készült, akik korábban nem használták a Kotlin-t, valamint Kotlin fejlesztők számára, akik korábban nem vettek részt versenyszoftver-fejlesztési eseményeken. Feltételezi a megfelelő programozási készségeket.

A versenyszoftver-fejlesztés egy elmetorna, ahol a versenyzők programokat írnak pontosan meghatározott algoritmikus problémák megoldására szigorú időkorlátokon belül. A problémák egyszerűektől az olyan összetettekig terjedhetnek, amelyek speciális algoritmusok, adatstruktúrák ismeretét és sok gyakorlást igényelnek.

Bár nem kifejezetten versenyszoftver-fejlesztésre lett tervezve, a Kotlin véletlenül is jól illeszkedik ehhez a domainhez, csökkentve a boilerplate kód mennyiségét, amelyet a fejlesztőnek írni és olvasni kell a kóddal való munka során. Ez majdnem olyan szintre csökkenti a mennyiséget, mint a dinamikusan típusozott szkriptnyelvek, miközben megtartja a statikusan típusozott nyelvek eszköztámogatását és teljesítményét.

Lásd: Első lépések Kotlin/JVM-mel a fejlesztési környezet beállításához.

Versenyszoftver-fejlesztés során általában egyetlen projektet hoznak létre, és minden probléma megoldását egyetlen forrásfájlban írják. 

## Egyszerű példa: Elérhető számok probléma

Nézzünk meg egy konkrét példát. A Codeforces Round 555 dátuma 2019. április 26-a volt, és 3. osztályú versenyként került megrendezésre, ami azt jelenti, hogy a problémák bármely fejlesztő számára kipróbálhatók voltak. Ezen a linken elolvashatod a problémákat.

A feladatsor legegyszerűbb problémája az A. Reachable Numbers probléma volt. Ez azt kérte, hogy implementáljunk egy egyszerű algoritmust, amelyet a probléma leírása tartalmazott.

Kezdjük a megoldást egy tetszőleges nevű Kotlin forrásfájl létrehozásával. Az A.kt jól működni fog.

Először implementálnod kell a probléma leírásában megadott függvényt:

Jelöljük az f(x) függvényt a következő módon: adjunk hozzá 1-et x-hez, majd amíg van legalább egy záró nulla az eredményül kapott számban, távolítsuk el ezt a nullát.

A Kotlin egy pragmatikus és nem dogmatikus nyelv, amely támogatja az imperatív és funkcionális programozási stílusokat anélkül, hogy a fejlesztőt az egyik felé tolja. Implementálhatod az f függvényt funkcionális stílusban, olyan Kotlin funkciókat használva, mint a farokrekurzió:

```
tailrec fun removeZeroes(x: Int): Int = if (x % 10 == 0) removeZeroes(x / 10) else x
fun f(x: Int) = removeZeroes(x + 1)
```

Alternatívaként írhatsz egy imperatív implementációt az f függvényre egy hagyományos while ciklus és változók használatával, amelyeket Kotlin-ban var-rel jelölnek:

```
fun f(x: Int): Int {
    var cur = x + 1
    while (cur % 10 == 0)
        cur /= 10
    return cur
}
```

A Kotlinban a típusok sok helyen opcionálisak az átfogó típus-inferencia miatt, de minden deklarációnak jól meghatározott statikus típusa van, amely a fordítás során ismert. Most már csak a main függvényt kell megírni, amely beolvassa a bemenetet és implementálja az algoritmus többi részét, amelyet a probléma leírása kér – kiszámítani a különböző egészek számát, amelyeket az f függvény ismételt alkalmazásával kapunk meg az n kezdő számból, amely a szabványos bemeneten adott.

Alapértelmezetten a Kotlin JVM-en fut, és közvetlen hozzáférést biztosít a gazdag és hatékony kollekciókönyvtárhoz általános célú kollekciókkal és adatstruktúrákkal, például dinamikusan méretezhető tömbökkel (ArrayList), hash-alapú térképekkel és halmazokkal (HashMap/HashSet), fa-alapú rendezett térképekkel és halmazokkal (TreeMap/TreeSet).

Egy egészeket tartalmazó hash-halmaz használatával a probléma egyszerű imperatív verziója így írható le:

### Kotlin 1.6.0 és újabb verziók

```
fun main() {
    var n = readln().toInt() // egész szám beolvasása a bemenetről
    val reached = HashSet<Int>() // változtatható hash halmaz
    while (reached.add(n)) 
        n = f(n) // f függvény iterálása
    println(reached.size) // válasz kiírása a kimenetre
}
```

Nincs szükség a hibásan formázott bemenet kezelésére versenyszoftver-fejlesztés során. A bemeneti formátum mindig pontosan meg van határozva versenyszoftver-fejlesztés során, és az aktuális bemenet nem térhet el a probléma leírásában szereplő bemeneti specifikációtól. Ezért használhatod a Kotlin `readln()` függvényét. Ez kijelenti, hogy a bemeneti karakterlánc jelen van, és kivételt dob ellenkező esetben. Hasonlóképpen, a `String.toInt()` függvény kivételt dob, ha a bemeneti karakterlánc nem egész szám.

### Korábbi verziók

```
fun main() {
    var n = readLine()!!.toInt() // egész szám beolvasása a bemenetről
    val reached = HashSet<Int>() // változtatható hash halmaz
    while (reached.add(n)) 
        n = f(n) // f függvény iterálása
    println(reached.size) // válasz kiírása a kimenetre
}
```

Vegyük észre a `readLine()` függvényhívás utáni Kotlin null-assertion operátor `!!` használatát. A Kotlin `readLine()` függvénye úgy van definiálva, hogy visszatérheti a nullable típus `String?`-t, és null-t ad vissza a bemenet végén, ami explicit módon arra kényszeríti a fejlesztőt, hogy kezelje a hiányzó bemenet esetét. Nincs szükség a hibásan formázott bemenet kezelésére versenyszoftver-fejlesztés során. A versenyszoftver-fejlesztés során a bemeneti formátum mindig pontosan meg van határozva, és az aktuális bemenet nem térhet el a probléma leírásában szereplő bemeneti specifikációtól. Ez az, amit a null-assertion operátor `!!` lényegében csinál – kijelenti, hogy a bemeneti karakterlánc jelen van, és kivételt dob ellenkező esetben. Hasonlóképpen, a `String.toInt()`.

Minden online versenyszoftver esemény lehetővé teszi előre írt kód használatát, így meghatározhatod a saját eszközkönyvtáradat, amely a versenyszoftver-fejlesztésre van optimalizálva, hogy az aktuális megoldási kódod könnyebben olvasható és írható legyen. Ezután használhatod ezt a kódot sablonként a megoldásaidhoz. Például definiálhatsz következő segédfüggvényeket a bemenetek olvasásához versenyszoftver-fejlesztés során:

## Kotlin 1.6.0 és újabb verziók
```
private fun readStr() = readln()        // karakterlánc sor
private fun readInt() = readStr().toInt() // egyszerű int
// hasonló más típusokhoz, amelyeket a megoldásokban használsz
```

## Korábbi verziók
```
private fun readStr() = readLine()!!     // karakterlánc sor
private fun readInt() = readStr().toInt() // egyszerű int
// hasonló más típusokhoz, amelyeket a megoldásokban használsz
```

Vegyük észre itt a `private` láthatósági módosító használatát. Bár a láthatósági módosító fogalma egyáltalán nem releváns versenyszoftver-fejlesztés során, lehetővé teszi több, ugyanazon sablon alapján készült megoldásfájl elhelyezését anélkül, hogy hiba történne az azonos csomagban lévő ütköző nyilvános deklarációk miatt.

## Funkcionális operátorok példa: Hosszú szám probléma

Összetettebb problémák esetén a Kotlin kiterjedt funkcionális műveleteinek könyvtára a kollekciókon hasznos a boilerplate minimalizálásában és a kód lineáris fentről lefelé és balról jobbra folyó adatátalakítási folyamatként való megírásában.

Például a B. Long Number probléma egyszerű mohó algoritmust alkalmaz az implementáláshoz, és ez a stílus így megírható egyetlen módosítható változó nélkül:

## Kotlin 1.6.0 és újabb verziók
```
fun main() {
    // bemenet olvasása
    val n = readln().toInt()
    val s = readln()
    val fl = readln().split(" ").map { it.toInt() }
    
    // helyi függvény definiálása
    fun f(c: Char) = '0' + fl[c - '1']
    
    // mohón megkeresi az első és utolsó indexeket
    val i = s.indexOfFirst { c -> f(c) > c }
        .takeIf { it >= 0 } ?: s.length
    val j = s.withIndex().indexOfFirst { (j, c) -> j > i && f(c) < c }
        .takeIf { it >= 0 } ?: s.length
    
    // válasz összeállítása és kiírása
    val ans = s.substring(0, i) + 
              s.substring(i, j).map { c -> f(c) }.joinToString("") + 
              s.substring(j)
    println(ans)
}
```

## Korábbi verziók
```
fun main() {
    // bemenet olvasása
    val n = readLine()!!.toInt()
    val s = readLine()!!
    val fl = readLine()!!.split(" ").map { it.toInt() }
    
    // helyi függvény definiálása
    fun f(c: Char) = '0' + fl[c - '1']
    
    // mohón megkeresi az első és utolsó indexeket
    val i = s.indexOfFirst { c -> f(c) > c }
        .takeIf { it >= 0 } ?: s.length
    val j = s.withIndex().indexOfFirst { (j, c) -> j > i && f(c) < c }
        .takeIf { it >= 0 } ?: s.length
    
    // válasz összeállítása és kiírása
    val ans = s.substring(0, i) + 
              s.substring(i, j).map { c -> f(c) }.joinToString("") + 
              s.substring(j)
    println(ans)
}
```

Ebben a sűrű kódban a kollekció-transzformációk mellett láthatunk hasznos Kotlin funkciókat, mint a helyi függvények és az elvis operátor `?:`, amely lehetővé tesz idiómák kifejezését, mint például "vedd az értéket, ha pozitív, különben használd a hosszat" tömör és olvasható kifejezésekkel, mint `.takeIf { it >= 0 } ?: s.length`. Ugyanakkor a Kotlin teljesen rendben van a további módosítható változók létrehozásával és ugyanez a kód imperatív stílusban való kifejezésével is.

A versenyszoftver-fejlesztési feladatok ehhez hasonló bemenetek olvasásának tömörebbé tételéhez az alábbi segéd bemenetolvasó függvények listája lehet hasznos:

## Kotlin 1.6.0 és újabb verziók
```
private fun readStr() = readln()                    // karakterlánc sor
private fun readInt() = readStr().toInt()           // egyszerű int
private fun readStrings() = readStr().split(" ")    // karakterláncok listája
private fun readInts() = readStrings().map { it.toInt() } // egészek listája
```

## Korábbi verziók
```
private fun readStr() = readLine()!!                // karakterlánc sor
private fun readInt() = readStr().toInt()           // egyszerű int
private fun readStrings() = readStr().split(" ")    // karakterláncok listája
private fun readInts() = readStrings().map { it.toInt() } // egészek listája
```

Ezekkel a segédfüggvényekkel a bemenet olvasására szolgáló kód egyszerűbbé válik, szorosan követve a probléma leírásában szereplő bemeneti specifikációt soronként:

```
// bemenet olvasása
val n = readInt()
val s = readStr()
val fl = readInts()
```

Vegyük észre, hogy a versenyszoftver-fejlesztés során szokás rövidebb változóneveket használni, mint az ipari programozási gyakorlatban, mivel a kódot egyszer kell megírni és utána nem kell karbantartani. Azonban ezek a nevek általában még mindig mnemonikusak – `a` tömbökre, `i`, `j` és mások indexekre, `r` és `c` sor- és oszlopszámokra táblázatokban, `x` és `y` koordinátákra, stb. Könnyebb megtartani ugyanazokat a neveket a bemeneti adatokhoz, mint amilyenek a probléma leírásában szerepelnek. Azonban az összetettebb problémák több kódot igényelnek, ami hosszabb, önmagát magyarázó változó- és függvénynév használatához vezet.

## További tippek és trükkök

A versenyszoftver-fejlesztési problémáknak gyakran ilyen bemenetük van:

```
A bemenet első sorában két egész szám szerepel n és k
```

A Kotlinban ez a sor tömören elemezhető a következő utasítással, egy destrukturáló deklarációt használva egészek listájából:

```
val (n, k) = readInts()
```

Meg lehet hívni a JVM `java.util.Scanner` osztályának használatát kevésbé strukturált bemeneti formátumok elemzésére. A Kotlin jól együttműködik a JVM könyvtárakkal, így azok használata természetesnek tűnik Kotlinban. Azonban vigyázz, hogy a `java.util.Scanner` rendkívül lassú. Olyan lassú, hogy valójában az 10⁵ vagy több egész szám elemzése vele nem fér bele egy tipikus 2 másodperces időlimitbe, amit egy egyszerű Kotlin `split(" ").map { it.toInt() }` kezelne.

A Kotlinban való kimenet írása általában egyszerű `println(...)` hívásokkal és a Kotlin karakterlánc sablonjainak használatával. Azonban figyelmet kell fordítani arra az esetre, amikor a kimenet 10⁵ sorrendű. Ennyi `println` hívás kiadása túl lassú, mivel a Kotlinban a kimenet automatikusan kiürül minden sor után. Egy gyorsabb módja sok sor kiírásának egy tömbből vagy listából a `joinToString()` függvény használata "\n" elválasztóval, így:

```
println(a.joinToString("\n")) // minden elem külön sorban
```

## Kotlin tanulása

A Kotlin könnyen tanulható, különösen azok számára, akik már ismerik a Java-t. A Kotlin alapvető szintaxisának rövid bevezetése szoftverfejlesztők számára közvetlenül megtalálható a weboldal referencia szekciójában, kezdve az alapvető szintaxistól. Az IDEA beépített Java-to-Kotlin konverterrel rendelkezik. Azok számára, akik ismerik a Java-t, használható a megfelelő Kotlin szintaktikai szerkezetek tanulására, de nem tökéletes, és még mindig érdemes megismerkedni a Kotlin-nal és megtanulni a Kotlin idiómákat.

## Újdonságok a Kotlin 2.2.20-ban

**Kiadva: 2025. szeptember 10.**

A Kotlin 2.2.20 kiadás elérhető, fontos változásokat hozva a webfejlesztéshez. A Kotlin/Wasm most már Beta szinten van, többek között javításokat a JavaScript interop-ban az kivételkezeléshez, npm függőségkezeléshez, beépített böngésző hibakeresési támogatáshoz, valamint egy új megosztott forráskészlethez js és wasmJs célokhoz.

Ezen felül itt van néhány főbb kiemelés:
- **Kotlin Multiplatform**: Swift export alapértelmezett elérhetősége, stabil keresztplatformos fordítás Kotlin könyvtárakhoz, és egy új megközelítés a közös függőségek deklarálására.
- **Nyelv**: Javított túlterhelési felbontás lambda kifejezések átadásakor suspend függvénytípusú túlterhelésekhez.
- **Kotlin/Native**: Támogatás a stack canary-khoz binárisokban és kisebb bináris méret kiadási binárisokhoz.
- **Kotlin/JS**: Hosszú értékek lefordítva JavaScript BigInt típusként.

## IDE támogatás

A Kotlin 2.2.20-at támogató Kotlin plugin be van csomagolva az IntelliJ IDEA és Android Studio legújabb verzióiba. A frissítéshez csak annyit kell tenned, hogy a build szkriptjeidben megváltoztatod a Kotlin verziót 2.2.20-ra. Lásd: Frissítés új kiadásra a részletekért.

## Nyelv

A Kotlin 2.2.20-ban kipróbálhatod a Kotlin 2.3.0-hoz tervezett közelgő nyelvi funkciókat, beleértve a javított túlterhelési felbontást lambda kifejezések suspend függvénytípusú túlterhelésekhez való átadásakor és a return utasítások támogatását kifejezés törzsekben kifejezetten visszatérési típusokkal.

Ez a kiadás továbbá javításokat tartalmaz a when kifejezések exhaustivitási ellenőrzéseiben, reified Throwable catch-ekben és Kotlin kontraktusokban.

## Javított túlterhelési felbontás lambda kifejezések suspend függvénytípusokhoz

Korábban egy függvény túlterhelése mind reguláris függvénytípussal, mind suspend függvénytípussal kétértelműségi hibát okozott lambda átadásakor. Megkerülhetted ezt a hibát egy explicit típuskényszerítéssel, de a fordító helytelenül "No cast needed" figyelmeztetést jelzett:

```
// Két túlterhelés definiálása
fun transform(block: () -> Int) {}
fun transform(block: suspend () -> Int) {}

fun test() {
    // Túlterhelési kétértelműségi hiba
    transform({ 42 })
    
    // Explicit kényszerítés használata, de a fordító helytelenül jelzi
    // "No cast needed" figyelmeztetést
    transform({ 42 } as () -> Int)
}
```

Ezzel a változással, amikor reguláris és suspend függvénytípusú túlterheléseket definiálsz, egy lambda explicit kényszerítés nélkül a reguláris túlterheléshez kerül feloldásra. Használd a `suspend` kulcsszót a suspend túlterheléshez való explicit felbontáshoz:

```
// transform(() -> Int) felbontás
transform({ 42 })

// transform(suspend () -> Int) felbontás
transform(suspend { 42 })
```

Ez a viselkedés alapértelmezett lesz a Kotlin 2.3.0-ban. Mostani teszteléshez állítsd be a nyelvi verziót 2.3-ra a következő fordító opcióval:

```
-language-version 2.3
```

Vagy konfiguráld a `build.gradle(.kts)` fájlban:

```
kotlin {
    compilerOptions {
        languageVersion.set(org.jetbrains.kotlin.gradle.dsl.KotlinVersion.KOTLIN_2_3)
    }
}
```

Örömmel fogadjuk visszajelzéseidet a issue trackerünkben, YouTrack.

## return utasítások támogatása kifejezés törzsekben kifejezetten visszatérési típusokkal

Korábban a `return` használata egy kifejezés törzsben fordítási hibát okozott, mert ez azt okozhatja, hogy a függvény visszatérési típusa Nothing-ként kerülne következtetésre.

```
fun example() = return 42 // Hiba: Visszatérések tiltottak kifejezés törzzsel rendelkező függvényökben
```

Ezzel a változással most már használhatod a `return`-t kifejezés törzsekben, amennyiben a visszatérési típus kifejezetten meg van adva:

```
// Visszatérési típus kifejezetten megadva
fun getDisplayNameOrDefault(userId: String?): String = 
    getDisplayName(userId ?: return "default")

// Hibás, mert nincs kifejezetten megadva a visszatérési típus
fun getDisplayNameOrDefault(userId: String?) = 
    getDisplayName(userId ?: return "default")
```

Hasonlóan, a return utasítások lambda kifejezésekben és beágyazott kifejezésekben korábban véletlenül lefordultak függvények kifejezés törzsekben. A Kotlin most támogatja ezeket az eseteket, amennyiben a visszatérési típus kifejezetten meg van adva. Az esetek kifejezetten megadott visszatérési típus nélkül elavulttá válnak a Kotlin 2.3.0-ban:

```
// A visszatérési típus nincs kifejezetten megadva, és a return utasítás lambda kifejezésen belül van
// ami elavulttá válik
fun returnInsideLambda() = run { 
    return 42 
}

// A visszatérési típus nincs kifejezetten megadva, és a return utasítás egy helyi változó inicializálójában van
// ami elavulttá válik
fun returnInsideIf() = when {
    else -> {
        val result = if (someCondition()) return "" else "value"
        result
    }
}
```

Ez a viselkedés alapértelmezett lesz a Kotlin 2.3.0-ban. Mostani teszteléshez állítsd be a nyelvi verziót 2.3-ra a következő fordító opcióval:

```
-language-version 2.3
```

Vagy konfiguráld a `build.gradle(.kts)` fájlban:

```
kotlin {
    compilerOptions {
        languageVersion.set(org.jetbrains.kotlin.gradle.dsl.KotlinVersion.KOTLIN_2_3)
    }
}
```

Örömmel fogadjuk visszajelzéseidet a issue trackerünkben, YouTrack.

## Adatfolyam-alapú exhaustivitási ellenőrzések when kifejezésekhez

A Kotlin 2.2.20 adatfolyam-alapú exhaustivitási ellenőrzéseket vezet be a when kifejezésekhez. Korábban a fordító ellenőrzései a when kifejezésre korlátozódtak, gyakran kényszerítve egy redundáns else ág hozzáadását. Ezzel a frissítéssel a fordító most nyomon követi az előző feltétel ellenőrzéseket és korai visszatéréseket, így eltávolíthatod a redundáns else ágakat.

Például a fordító most felismeri, hogy a függvény visszatér, amikor az if feltétel teljesül, így a when kifejezésnek csak a fennmaradó eseteket kell kezelnie:

```
enum class UserRole { ADMIN, MEMBER, GUEST }

fun getPermissionLevel(role: UserRole): Int {
    // Az Admin esetet kívül kezeli a when kifejezésen
    if (role == UserRole.ADMIN) return 99
    
    return when (role) {
        UserRole.MEMBER -> 10
        UserRole.GUEST -> 1
        // Már nem kell hozzáadni ezt az else ágat
        // else -> throw IllegalStateException()
    }
}
```

Ez a funkció **Kísérleti**. Az engedélyezéshez add hozzá a következő fordító opciót a `build.gradle(.kts)` fájlhoz:

```
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xdata-flow-based-exhaustiveness")
    }
}
```

## Reified típusok támogatása catch záradékokban

A Kotlin 2.2.20-ban a fordító most már lehetővé teszi reified generikus típusparaméterek használatát inline függvények catch záradékaiban. Íme egy példa:

```
inline fun <reified ExceptionType : Throwable> handleException(block: () -> Unit) {
    try {
        block()
        // Ez most már engedélyezett a változás után
    } catch (e: ExceptionType) {
        println("Caught specific exception: ${e::class.simpleName}")
    }
}

fun main() {
    // Megpróbál végrehajtani egy műveletet, amely IOException-t dobhat
    handleException<java.io.IOException> {
        throw java.io.IOException("File not found")
    }
    // Caught specific exception: IOException
}
```

Korábban a reified Throwable típus catch-elése inline függvényben hibát eredményezett. Ez a viselkedés alapértelmezett lesz a Kotlin 2.4.0-ban. A jelenlegi használathoz add hozzá a következő fordító opciót a `build.gradle(.kts)` fájlhoz:

```
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xallow-reified-type-in-catch")
    }
}
```

A Kotlin csapat hálás Iven Krall külső közreműködőnek a hozzájárulásért.

## Javított Kotlin kontraktusok

A Kotlin 2.2.20 számos javítást vezet be a Kotlin kontraktusokban, beleértve:
- Generikák támogatása kontraktus típus állításokban
- Kontraktusok támogatása tulajdonság hozzáférőkben és specifikus operátor függvényekben
- A `returnsNotNull()` függvény támogatása kontraktusokban mint mód a nem null érték visszatérés biztosítására amikor egy feltétel teljesül

Új `holdsIn` kulcsszó, lehetővé téve a feltételek igaznak feltételezését amikor lambdákba kerülnek

Ezek a javítások **Kísérleti**. Az engedélyezéshez továbbra is használnod kell az `@OptIn(ExperimentalContracts::class)` annotációt kontraktusok deklarálásakor. A `holdsIn` kulcsszó és a `returnsNotNull()` függvény szintén szükséges az `@OptIn(ExperimentalExtendedContracts::class)` annotáció. Ezeknek a javításoknak a használatához szintén hozzá kell adnod a leírt fordító opciókat minden szekcióban.

Örömmel fogadjuk visszajelzéseidet a issue trackerünkben.

## Generikák támogatása kontraktus típus állításokban

Most már írhatsz kontraktusokat, amelyek típus állításokat végeznek generikus típusokon:

```
import kotlin.contracts.*

sealed class Failure {
    class HttpError(val code: Int) : Failure()
    // Más hibatípusok beszúrása itt
}

sealed class Result<out T, out F : Failure> {
    class Success<T>(val data: T) : Result<T, Nothing>()
    class Failed<F : Failure>(val failure: F) : Result<Nothing, F>()
}

@OptIn(ExperimentalContracts::class)
// Kontraktus használata generikus típus állításra
fun <T, F : Failure> Result<T, F>.isHttpError(): Boolean {
    contract {
        returns(true) implies (this@isHttpError is Result.Failed<Failure.HttpError>)
    }
    return this is Result.Failed && this.failure is Failure.HttpError
}
```

Ebben a példában a kontraktus típus állítást végez a Result objektumon, lehetővé téve a fordító számára, hogy biztonságosan okos típuskényszerítést végezzen az assertált generikus típusra.

Ez a funkció **Kísérleti**. Az engedélyezéshez add hozzá a következő fordító opciót a `build.gradle(.kts)` fájlhoz:

```
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xallow-contracts-on-more-functions")
    }
}
```

## Kontraktusok támogatása tulajdonság hozzáférőkben és specifikus operátor függvényekben

Most már definiálhatsz kontraktusokat tulajdonság hozzáférőkben és specifikus operátor függvényekben. Ez lehetővé teszi kontraktusok használatát több típusú deklarációban, rugalmasabbá téve őket.

Például használhatsz kontraktust egy getterben az objektum fogadó okos típuskényszerítésének engedélyezésére:

```
import kotlin.contracts.*

val Any.isHelloString: Boolean
    get() {
        @OptIn(ExperimentalContracts::class)
        // Engedélyezi a fogadó String-re való okos típuskényszerítését amikor a getter true-t ad vissza
        contract {
            returns(true) implies (this@isHelloString is String)
        }
        return "hello" == this
    }

fun printIfHelloString(x: Any) {
    if (x.isHelloString) {
        // Kiírja a hosszt a fogadó String-re való okos típuskényszerítés után
        println(x.length) // 5
    }
}
```

Továbbá használhatsz kontraktusokat a következő operátor függvényekben:
- `invoke`
- `contains` 
- `rangeTo`, `rangeUntil`
- `componentN`
- `iterator`
- `unaryPlus`, `unaryMinus`, `not`
- `inc`, `dec`

Íme egy példa kontraktus használatára operátor függvényben egy változó inicializálásának biztosítására lambda kifejezésen belül:

```
import kotlin.contracts.*

class Runner {
    @OptIn(ExperimentalContracts::class)
    // Engedélyezi a lambda kifejezésen belüli változók inicializálását
    operator fun invoke(block: () -> Unit) {
        contract {
            callsInPlace(block, InvocationKind.EXACTLY_ONCE)
        }
        block()
    }
}

fun testOperator(runner: Runner) {
    val number: Int
    runner {
        number = 1
    }
    // Kiírja az értéket a kontraktus által garantált meghatározott inicializálás után
    println(number) // 1
}
```

Ez a funkció **Kísérleti**. Az engedélyezéshez add hozzá a következő fordító opciót a `build.gradle(.kts)` fájlhoz:

```
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xallow-contracts-on-more-functions")
    }
}
```

## A `returnsNotNull()` függvény támogatása kontraktusokban

A Kotlin 2.2.20 bevezeti a `returnsNotNull()` függvényt kontraktusokhoz. Használhatod ezt a függvényt annak biztosítására, hogy egy függvény nem null értéket adjon vissza amikor egy specifikus feltétel teljesül. Ez leegyszerűsíti a kódodat extra null ellenőrzések vagy többféle túlterhelés cseréje helyett egyetlen, tömör függvénnyel:

```
import kotlin.contracts.*

@OptIn(ExperimentalContracts::class, ExperimentalExtendedContracts::class)
fun decode(encoded: String?): String? {
    contract {
        // Garantál egy nem null visszatérési értéket amikor a bemenet nem null (encoded != null) implies (returnsNotNull())
    }
    if (encoded == null) return null
    return java.net.URLDecoder.decode(encoded, "UTF-8")
}

fun useDecodedValue(s: String?) {
    // Biztonságos hívást használ mivel a visszatérési érték lehet null
    decode(s)?.length
    
    if (s != null) {
        // A visszatérési érték nem nullként kezelhető az okos típuskényszerítés után
        decode(s).length
    }
}
```

Ebben a példában a `decode()` függvény kontraktusa lehetővé teszi a fordító számára az okos típuskényszerítést a visszatérési értékén amikor a bemenet nem null, eltávolítva az extra null ellenőrzések vagy többféle túlterhelés szükségességét.

Ez a funkció **Kísérleti**. Az engedélyezéshez add hozzá a következő fordító opciót a `build.gradle(.kts)` fájlhoz:

```
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xallow-condition-implies-returns-contracts")
    }
}
```

## Új `holdsIn` kulcsszó

A Kotlin 2.2.20 bevezeti az új `holdsIn` kulcsszót kontraktusokhoz. Használhatod egy boolean feltétel igazként feltételezésére egy specifikus lambda kifejezésen belül. Ez lehetővé teszi DSL-ek építését feltételes okos típuskényszerítéssel kontraktusok használatával.

Íme egy példa:

```
import kotlin.contracts.*

@OptIn(ExperimentalContracts::class, ExperimentalExtendedContracts::class)
fun <T> T.alsoIf(condition: Boolean, block: (T) -> Unit): T {
    contract {
        // Kijelenti, hogy a lambda legfeljebb egyszer fut le
        callsInPlace(block, InvocationKind.AT_MOST_ONCE)
        // Kijelenti, hogy a feltétel igaznak feltételezett lambda kifejezésen belül
        condition holdsIn block
    }
    if (condition) block(this)
    return this
}

fun useApplyIf(input: Any) {
    val result = listOf(1, 2, 3)
        .first()
        .alsoIf(input is Int) {
            // Az input paraméter Int típusúra kerül okos típuskényszerítéssel a lambda kifejezésen belül
            // Kiírja az input és az első lista elem összegét
            println(input + it) // 2
        }
        .toString()
}
```

Ez a funkció **Kísérleti**. Az engedélyezéshez add hozzá a következő fordító opciót a `build.gradle(.kts)` fájlhoz:

```
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xallow-holdsin-contract")
    }
}
```

## Kotlin/JVM: invokedynamic támogatás when kifejezésekkel

A Kotlin/JVM támogatja az `invokedynamic` használatát when kifejezésekkel kompatibilis JVM verziókon (.class fájlverzió 51 és újabb). Lásd a JVM nyelvi verziók támogatását a kompatibilitási útmutatóban.

Ez a JVM funkció lehetővé teszi komplex when kifejezések futtatását optimalizált módon, gyorsabb végrehajtással nagyobb bemenetek esetén.

Ennek az opcióknak a ki- és bekapcsolásához használj egy specifikus konfigurációt a Gradle-ben:

```
kotlin {
    jvmToolchain(11) // Biztosítja a kompatibilis JVM verziót
    
    compilerOptions {
        freeCompilerArgs.add("-Xuse-ir") // IR backend engedélyezése az invokedynamic támogatáshoz
    }
}
```

Bizonyosodj meg róla, hogy a JVM runtime verziód legalább Java 8 vagy újabb (bájtkód verzió 51+) támogatja az `invokedynamic` utasítást.

Fontos megjegyezni, hogy bár ez javíthatja a teljesítményt bizonyos forgatókönyvekben, olyan esetekben kisebb teljesítménycsökkenést is okozhat, ahol a JIT optimalizálás hatékonyságát csökkenti az extra JVM bájtkód hozzáadása.

A funkció használatakor figyelj a JVM verzió kompatibilitásra és teszteld teljes körűen az alkalmazásodat, hogy biztosítsd a várt viselkedést különböző környezetekben.

## Kotlin/JVM: invokedynamic támogatás when kifejezésekkel

A Kotlin 2.2.20-ban most már lefordíthatod a when kifejezéseket invokedynamic használatával. Korábban a több típusellenőrzést tartalmazó when kifejezések hosszú instanceof ellenőrzések láncává fordultak le a bájtkódban. Most invokedynamic-ot használhatsz when kifejezésekkel kisebb bájtkód generálásához, hasonlóan a Java switch utasítások által generált bájtkódhoz, amikor a következő feltételek teljesülnek:

- Minden feltétel kivéve az `else`-t `is` vagy null ellenőrzés.
- A kifejezés nem tartalmaz őrfeltételeket (`if`).
- A feltételek nem tartalmaznak olyan típusokat, amelyek nem ellenőrizhetők közvetlenül, mint például módosítható Kotlin kollekciók (`MutableList`) vagy függvénytípusok (`kotlin.Function1`, `kotlin.Function2`, stb.).
- Legalább két feltétel van az `else` kivételével.
- Minden ág ellenőrzi a when kifejezés ugyanazt a tárgyát.

Például:

```
open class Example
class A : Example()
class B : Example()
class C : Example()

fun test(e: Example) = when (e) {
    // invokedynamic használata SwitchBootstraps.typeSwitch segítségével
    is A -> 1
    is B -> 2
    is C -> 3
    else -> 0
}
```

Az új funkció engedélyezésével a when kifejezés ebben a példában egyetlen invokedynamic típuskapcsolóvá fordul le több instanceof ellenőrzés helyett.

A funkció engedélyezéséhez fordítsd a Kotlin kódodat JVM cél 21-es vagy újabb verzióval, és add hozzá a következő fordító opciót:

```
-Xwhen-expressions=indy
```

Vagy add hozzá a `compilerOptions {}` blokkhoz a `build.gradle(.kts)` fájlban:

```
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xwhen-expressions=indy")
    }
}
```

Ez a funkció **Kísérleti**. Örömmel fogadjuk visszajelzéseidet a issue trackerünkben, YouTrack.

## Kotlin Multiplatform

A Kotlin 2.2.20 jelentős változásokat vezet be a Kotlin Multiplatform számára: Swift export alapértelmezetten elérhető, új megosztott forráskészlet van, és kipróbálhatsz egy új megközelítést a közös függőségek kezelésére.

## Swift export alapértelmezetten elérhető

A Kotlin 2.2.20 kísérleti támogatást vezet be Swift exportáláshoz. Lehetővé teszi Kotlin források közvetlen exportálását és Kotlin kód idiomatikus hívását Swift-ből, kiküszöbölve az Objective-C fejlécek szükségességét. Ez jelentősen javítani fogja a többplatformos fejlesztést Apple célok számára.

Például, ha van egy Kotlin modulod felső szintű függvényekkel, a Swift export tiszta, modulspecifikus importokat tesz lehetővé, eltávolítva a zavaró Objective-C aláhúzásokat és mangled neveket.

A kulcsfunkciók:

- **Többmodulos támogatás**: Minden Kotlin modul külön Swift modulként kerül exportálásra, leegyszerűsítve a függvényhívásokat.
- **Csomagtámogatás**: A Kotlin csomagok kifejezetten megőrződnek az exportálás során, elkerülve az elnevezési ütközéseket a generált Swift kódban.
- **Típusálnév-aliaszok**: A Kotlin típusálnév-aliaszok exportálásra kerülnek és megőrződnek Swift-ben, javítva az olvashatóságot.
- **Fokozott nullázhatóság primitívekhez**: Az Objective-C interoperabilitással ellentétben, amely megkövetelte az olyan típusok becsomagolását mint `Int?` wrapper osztályokba mint `KotlinInt` a nullázhatóság megőrzése érdekében, a Swift export közvetlenül konvertálja a nullázhatósági információkat.
- **Túlterhelések**: Kotlin túlterhelt függvényeit Swift-ből egyértelműen hívhatod.
- **Lapított csomagstruktúra**: Kotlin csomagok Swift enum-okká alakíthatók, eltávolítva a csomagelőtagokat a generált Swift kódból.
- **Modulnév testreszabása**: Testreszabhatod az eredményül kapott Swift modulneveket a Kotlin projekt Gradle konfigurációjában.

## Swift export engedélyezése

A funkció jelenleg **Kísérleti** és csak olyan projekteken működik, amelyek közvetlen integrációt használnak az iOS keretrendszer Xcode projekthez való csatlakoztatásához. Ez a szabványos konfiguráció a Kotlin Multiplatform pluginnal létrehozott többplatformos projektek számára IntelliJ IDEA-ban vagy a webes varázsló segítségével.

A Swift export kipróbálásához konfiguráld az Xcode projektet:

1. Az Xcode-ban nyisd meg a projektbeállításokat.
2. A Build Phases fülön keresd meg a Run Script fázist az `embedAndSignAppleFrameworkForXcode` feladattal.
3. Állítsd be a szkriptet az `embedSwiftExportForXcode` feladatra a run script fázisban:

```bash
./gradlew :<Megosztott modul név>:embedSwiftExportForXcode
```

4. Építsd meg a projektet. A Swift modulok a build kimeneti könyvtárban kerülnek generálásra.

A funkció alapértelmezetten elérhető. Ha már engedélyezted korábbi kiadásokban, most már eltávolíthatod a `kotlin.experimental.swift-export.enabled` sort a `gradle.properties` fájlból.

Az idő megtakarítása érdekében klónozd nyilvános példánkat, amely már be van állítva Swift exporttal.

További információkért a Swift exportról lásd a dokumentációnkat.

## Visszajelzés

Tervezzük a Swift export támogatás kiterjesztését és fokozatos stabilizálását a jövőbeli Kotlin kiadásokban. A Kotlin 2.2.20 után a Kotlin és Swift közötti interoperabilitás javítására fogunk összpontosítani, különösen a coroutine-ok és flow-k körül.

A Swift export támogatása jelentős változás a Kotlin Multiplatform számára. Örömmel fogadjuk visszajelzéseidet:

- Lépj kapcsolatba a fejlesztőcsapattal közvetlenül a Kotlin Slack-en – szerezz meghívót és csatlakozz a #swift-export csatornához.
- Jelentsd be a Swift exporttal kapcsolatos problémáidat a YouTrack-ban.

## Megosztott forráskészlet js és wasmJs célokhoz

Korábban a Kotlin Multiplatform nem tartalmazott megosztott forráskészletet a JavaScript (js) és WebAssembly (wasmJs) webcéljaihoz alapértelmezetten. A js és wasmJs közötti kód megosztásához manuálisan kellett konfigurálni egy egyéni forráskészletet vagy kétszer kellett megírni a kódot, egy verziót js-re és egy másikat wasmJs-re.

Például:

```
// commonMain
expect suspend fun readCopiedText(): String

// jsMain
external interface Navigator {
    val clipboard: Clipboard
}

// Különböző interop JS-ben és Wasm-ben
external interface Clipboard {
    fun readText(): Promise<String>
}
external val navigator: Navigator

suspend fun readCopiedText(): String {
    // Különböző interop JS-ben és Wasm-ben
    return navigator.clipboard.readText().await()
}

// wasmJsMain
external interface Navigator {
    val clipboard: Clipboard
}
external interface Clipboard {
    fun readText(): Promise<JsString>
}
external val navigator: Navigator

suspend fun readCopiedText(): String {
    return navigator.clipboard.readText().await().toString()
}
```

Ettől a kiadástól kezdve a Kotlin Gradle plugin új megosztott forráskészletet ad a web számára (webMain és webTest alkotva) amikor az alapértelmezett hierarchia sablont használod. Ezzel a változással a web forráskészlet szülője lesz mind a js és wasmJs forráskészleteknek.

A frissített forráskészlet hierarchia így néz ki:

Új forráskészlet példája az alapértelmezett hierarchia sablon használatával webhez

Az új forráskészlet lehetővé teszi egy kód darab megírását mind a js és wasmJs célok számára. A megosztott kódodat a webMain-ben helyezheted el, és automatikusan működni fog mindkettő számára:

```
// commonMain
expect suspend fun readCopiedText(): String

// webMain
external interface Navigator {
    val clipboard: Clipboard
}
external interface Clipboard {
    fun readText(): Promise<JsString>
}
external val navigator: Navigator

actual suspend fun readCopiedText(): String {
    return navigator.clipboard.readText().await().toString()
}
```

Ez a frissítés leegyszerűsíti a kód megosztást a js és wasmJs célok között. Különösen hasznos két esetben:

- Ha könyvtárszerző vagy, és támogatást szeretnél adni mind a js és wasmJs céloknak, kód duplikálása nélkül.
- Ha Compose Multiplatform alkalmazásokat fejlesztasz webcélokra, lehetővé téve a keresztfordítást mind a js és wasmJs célok számára szélesebb böngészőkompatibilitás érdekében.

Ez a fallback mód miatt, amikor létrehozol egy weboldalt, az minden böngészőn működni fog alapból, mivel a modern böngészők wasmJs-t használnak, míg a régebbiek js-t.

A funkció kipróbálásához használd az alapértelmezett hierarchia sablont a `kotlin {}` blokkban a `build.gradle(.kts)` fájlban:

```
kotlin {
    js()
    wasmJs()
    // Engedélyezi az alapértelmezett forráskészlet hierarchiát, beleértve a webMain-t és webTest-et
    applyDefaultHierarchyTemplate()
}
```

Mielőtt használnád az alapértelmezett hierarchiát, gondosan fontold meg a potenciális ütközéseket, ha projektedben egyéni megosztott forráskészleted van vagy átnevezted a `js("web")` célt. Az ütközések feloldásához nevezd át az ütköző forráskészletet vagy célt, vagy ne használd az alapértelmezett hierarchiát.

## Stabil keresztplatformos fordítás Kotlin könyvtárakhoz

A Kotlin 2.2.20 befejez egy fontos ütemterv elemet, stabilizálva a keresztplatformos fordítást Kotlin könyvtárak számára. Most már bármely kiszolgálóról előállíthatsz .klib artefaktumokat Kotlin könyvtárak közzétételéhez. Ez jelentősen leegyszerűsíti a közzétételi folyamatot, különösen az Apple célok számára, amelyek korábban Mac gépet igényeltek.

A funkció alapértelmezetten elérhető. Ha már engedélyezted a keresztfordítást a `kotlin.native.enableKlibsCrossCompilation=true` beállítással, most már eltávolíthatod a `gradle.properties` fájlból.

Sajnos néhány korlátozás még mindig fennáll. Még mindig Mac gépet kell használnod, ha:

- A könyvtárad vagy bármely függő modulnak van cinterop függősége.
- A CocoaPods integráció be van állítva a projektben.
- Végleges binárisokat kell építeni vagy tesztelni Apple célokhoz.

További információkért a többplatformos könyvtárak közzétételéről lásd a dokumentációnkat.

## Új megközelítés a közös függőségek deklarálására

A többplatformos projektek Gradle-lel való beállításának leegyszerűsítése érdekében a Kotlin 2.2.20 most lehetővé teszi a közös függőségek deklarálását a `kotlin {}` blokkban egy felső szintű `dependencies {}` blokk használatával, amikor a projekt Gradle 8.8-as vagy újabb verziót használ. Ezek a függőségek úgy viselkednek, mintha a `commonMain` forráskészletben lettek volna deklarálva.

Ez a funkció hasonlóan működik a `dependencies` blokkhoz, amelyet Kotlin/JVM és csak Android projektekhez használsz, és most **Kísérleti** a Kotlin Multiplatformban.

A közös függőségek deklarálása projekt szinten csökkenti az ismétlődő konfigurációt a forráskészletek között és segít leegyszerűsíteni a build beállítást. Továbbra is hozzáadhatsz platformspecifikus függőségeket minden forráskészlethez szükség szerint.

A funkció kipróbálásához engedélyezd az `@OptIn(ExperimentalKotlinGradlePluginApi::class)` annotáció hozzáadásával a felső szintű `dependencies {}` blokk elé. Például:

```
kotlin {
    @OptIn(ExperimentalKotlinGradlePluginApi::class)
    dependencies {
        implementation("org.jetbrains.kotlinx:kotlinx-coroutines-core:1.10.2")
    }
}
```

Örömmel fogadjuk visszajelzéseidet erről a funkcióról a YouTrack-ban.

## Új diagnosztika a cél támogatásához a függőségekben

A Kotlin 2.2.20 előtt, ha egy függőség a build szkriptedben nem támogatta az összes forráskészlet által megkövetelt célt, a Gradle által termeltek hibaüzenetek nehezen érthetővé tették a problémát. A Kotlin 2.2.20 bevezet egy új diagnosztikát, amely egyértelműen mutatja meg, hogy mely célokat támogat minden függőség és melyeket nem.

Ez a diagnosztika alapértelmezetten engedélyezett. Ha valamilyen okból le kell tiltani, jelezd ezt megjegyzésben a YouTrack issue-ban.

A következő Gradle tulajdonságokat használhatod a diagnosztika letiltásához a `gradle.properties` fájlban:

| Tulajdonság                                              | Leírás                                                       |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| `kotlin.kmp.eagerUnresolvedDependenciesDiagnostic=false` | Csak a metaadat fordításokhoz és importokhoz futtatja a diagnosztikát |
| `kotlin.kmp.unresolvedDependenciesDiagnostic=false`      | Teljesen letiltja a diagnosztikát                            |

## Kotlin/Native

A Kotlin 2.2.20 javításokat hoz az Objective-C/Swift interoperabilitásban, hibakeresésben és új bináris opciókban.

## Támogatás stack canary-khoz binárisokban

A Kotlin 2.2.20-től kezdve a Kotlin támogatást nyújt a stack canary-khoz az eredményül kapott Kotlin/Native binárisokban. A stack védelem részeként ez a biztonsági funkció védelmet nyújt a stack smashing ellen, mérsékelve néhány gyakori alkalmazás sebezhetőséget.

Már elérhető Swift-ben és Objective-C-ben, most már támogatott Kotlin-ban is. A stack védelem implementációja Kotlin/Native-ben követi a Clang stack protector viselkedését.

A stack canary-k engedélyezéséhez add hozzá a következő bináris opciót a `gradle.properties` fájlhoz:

```
kotlin.native.binary.stackProtector=yes
```

A tulajdonság engedélyezi a funkciót minden Kotlin függvény számára, amely sebezhető a stack smashinggel szemben. Alternatív módok:

- `kotlin.native.binary.stackProtector=strong`, amely erősebb heurisztikát használ a stack smashinggel sebezhető függvényekhez.
- `kotlin.native.binary.stackProtector=all`, amely engedélyezi a stack protectorokat minden függvény számára.

Vegye figyelembe, hogy néhány esetben a stack védelem teljesítményköltséggel járhat.

## Kisebb bináris méret kiadási binárisokhoz

A Kotlin 2.2.20 bevezeti a `smallBinary` opciót, amely segíthet csökkenteni a kiadási binárisok méretét. Az új opció hatékonyan beállítja az `-Oz` értéket alapértelmezett optimalizációs argumentumként a fordító számára az LLVM fordítási fázis során.

A `smallBinary` opció engedélyezésével kisebbé teheted a kiadási binárisokat és javíthatod az építési időt. Azonban ez néhány esetben befolyásolhatja a futásidejű teljesítményt.

Az új funkció jelenleg **Kísérleti**. A projektben való kipróbáláshoz add hozzá a következő bináris opciót a `gradle.properties` fájlhoz:

```
kotlin.native.binary.smallBinary=true
```

A Kotlin csapat hálás Troels Lund segítségéért a funkció implementálásában.

## Javított hibakereső objektum összegzések

A Kotlin/Native most tisztább objektum összegzéseket generál a hibakereső eszközök számára, mint LLDB és GDB. Ez javítja a generált hibakeresési információk olvashatóságát és leegyszerűsíti a hibakeresési élményt.

Vegyünk példaként a következő objektumot:

```
class Point(val x: Int, val y: Int)
val point = Point(1, 2)
```

Korábban az ellenőrzés csak korlátozott információt mutatott, beleértve a mutatót az objektum memóriacíméhez:

```
(lldb) v point
(ObjHeader *) point = [x: ..., y: ...]
(lldb) v point->x
(int32_t *) x = 0x0000000100274048
```

A Kotlin 2.2.20-től a hibakereső már gazdagabb részleteket mutat, beleértve a tényleges értékeket:

```
(lldb) v point
(ObjHeader *) point = Point(x=1, y=2)
(lldb) v point->x
(int32_t) point->x = 1
```

A Kotlin csapat hálás Nikita Nazarov segítségéért a funkció implementálásában.

További információkért a Kotlin/Native hibakereséséről lásd a dokumentációt.

## Explicit nevek blokk típusokban Objective-C fejlécekhez

A Kotlin 2.2.20 bevezet egy opciót a Kotlin függvénytípusok paraméterneveinek explicit hozzáadására az Objective-C fejlécekhez, amelyeket a Kotlin/Native projektekből exportálnak.

A paraméternevek javítják az autocomplete javaslatokat az Xcode-ban és segítenek elkerülni a Clang figyelmeztetéseket.

Korábban a paraméternevek blokk típusokban el lettek hagyva a generált Objective-C fejlécekben. Ilyen esetekben az Xcode autocompletion javasolta a függvényhívásokat paraméternevek nélkül az Objective-C blokkban. A generált blokk Clang figyelmeztetéseket váltott ki.

Például a következő Kotlin kód esetén:

```
// Kotlin:
fun greetUser(block: (name: String) -> Unit) = block("John")
```

A generált Objective-C fejlécben nem volt paraméternév:

```
// Objective-C:
+ (void)greetUserBlock:(void (^)(NSString *))block attribute ((swift_name("greetUser(block:)")));
```

Így amikor az `greetUserBlock()` függvényt hívták Objective-C-ből az Xcode-ban, az IDE a következőt javasolta:

```
// Objective-C:
greetUserBlock:^(NSString *) {
    // ...
};
```

A hiányzó paraméternév (`NSString *`) a javaslatban Clang figyelmeztetéseket okozott.

Az új opcióval a Kotlin továbbítja a paraméterneveket a Kotlin függvénytípusokból az Objective-C blokk típusokba, így az Xcode használja őket a javaslatokban:

```
// Objective-C:
greetUserBlock:^(NSString *name) {
    // ...
};
```

Az explicit paraméternevek engedélyezéséhez add hozzá a következő bináris opciót a `gradle.properties` fájlhoz:

```
kotlin.native.binary.objcExportBlockExplicitParameterNames=true
```

A Kotlin csapat hálás Yijie Jiang-nek a funkció implementálásáért.

## A Kotlin/Native terjesztés méretének csökkentése

A Kotlin/Native terjesztés korábban két JAR fájlt tartalmazott a fordító kódjával:
- `konan/lib/kotlin-native.jar`
- `konan/lib/kotlin-native-compiler-embeddable.jar`

A Kotlin 2.2.20-től kezdve a `kotlin-native.jar` már nem kerül közzétételre. Az eltávolított JAR fájl az embeddable fordító örökölt verziója, amely már nem szükséges. Ez a változás jelentősen csökkenti a terjesztés méretét.

Ennek következtében a következő opciók már elavultak és eltávolításra kerültek:
- A `kotlin.native.useEmbeddableCompilerJar=false` Gradle tulajdonság. Ehelyett az embeddable fordító JAR fájl mindig használatban van Kotlin/Native projektekhez.
- A `KotlinCompilerPluginSupportPlugin.getPluginArtifactForNative()` függvény. Ehelyett a `getPluginArtifact()` függvény mindig használatban van.

További információkért lásd a YouTrack issue-t.

## KDocs exportálása Objective-C fejlécekbe alapértelmezetten

A KDoc kommentek most alapértelmezetten exportálásra kerülnek Objective-C fejlécek generálásakor a Kotlin/Native végleges binárisok fordítása során.

Korábban manuálisan kellett hozzáadni a `-Xexport-kdoc` opciót a build fájlhoz. Most automatikusan átadásra kerül a fordítási feladatokhoz.

Ez az opció beágyazza a KDoc kommenteket a klibsekbe és kinyeri a kommenteket a klibsekből Apple keretrendszerek előállításakor. Ennek eredményeként a kommentek osztályokon és metódusokon megjelennek az autocompletion során, például az Xcode-ban.

Letilthatod a KDoc kommentek exportálását a klibsekből az előállított Apple keretrendszerekbe a `binaries {}` blokkban a `build.gradle(.kts)` fájlban:

```
import org.jetbrains.kotlin.gradle.ExperimentalKotlinGradlePluginApi

kotlin {
    iosArm64 {
        binaries {
            framework {
                baseName = "sdk"
                @OptIn(ExperimentalKotlinGradlePluginApi::class)
                exportKdoc.set(false)
            }
        }
    }
}
```

További információkért lásd a dokumentációnkat.

## Az x86_64 Apple célok elavulttá nyilvánítása

Az Apple néhány éve már nem gyárt Intel chippeket használó eszközöket, és nemrég bejelentette, hogy a macOS Tahoe 26 lesz az utolsó operációs rendszer verzió, amely támogatja az Intel-alapú architektúrát.

Ez egyre nehezebbé teszi számunkra ezeknek a céloknak a megfelelő tesztelését a build ügynökeinken, különösen a jövőbeli Kotlin kiadásokban, ahol frissíteni fogjuk a támogatott Xcode verziót, amely a macOS 26-hoz tartozik.

A Kotlin 2.2.20-tól kezdve a `macosX64` és `iosX64` célok a támogatási szint 2-re kerülnek lefokozásra. Ez azt jelenti, hogy a cél rendszeresen tesztelve van CI-n fordításra, de előfordulhat, hogy nem automatikusan tesztelik a futtatást.

Tervezzük fokozatosan elavulttá tenni az összes x86_64 Apple célt, és végül eltávolítani a támogatást a Kotlin 2.2.20−2.4.0 kiadási ciklus során. Ez a következő célokat tartalmazza:

- `macosX64`
- `iosX64` 
- `tvosX64`
- `watchosX64`

További információkért a támogatási szintekről lásd a Kotlin/Native cél támogatást.

## Kotlin/Wasm

A Kotlin/Wasm most **Beta** szinten van, nagyobb stabilitást kínálva a szeparált npm függőségek, finomított kivételkezelés JavaScript interop-hoz, beépített böngésző hibakeresési támogatás és egyebek mellett.

## Szeparált npm függőségek

Korábban a Kotlin/Wasm projektjeidben az összes npm függőség együtt lett telepítve a projekt mappádba, beleértve mind a Kotlin eszközfüggőségeket, mind a saját függőségeidet. Ezeket a lock fájlokban (package-lock.json vagy yarn.lock) is együtt rögzítették.

Ennek eredményeként, amikor a Kotlin eszközfüggőségek frissültek, frissítened kellett a lock fájljaidat még akkor is, ha semmit sem adtál hozzá vagy változtattál.

A Kotlin 2.2.20-től kezdve a Kotlin eszköznpm függőségek a projekteden kívül kerülnek telepítésre. Most az eszközök és a felhasználói függőségek külön könyvtárakban vannak:

- **Eszközfüggőségek könyvtára**: `<kotlin-user-home>/kotlin-npm-tooling/<yarn|npm>/hash/node_modules`
- **Felhasználói függőségek könyvtára**: `build/wasm/node_modules`

Emellett a lock fájlok a projekt könyvtárában csak a felhasználó által meghatározott függőségeket tartalmazzák. Ez a javítás fókuszálttá teszi a lock fájljaidat csak a saját függőségeidre, segít tisztább projektet fenntartani, és csökkenti a felesleges fájlváltozásokat.

Ez a változás alapértelmezetten engedélyezett a `wasm-js` célhoz. A változás még nincs implementálva a `js` célhoz. Bár tervek vannak a jövőbeni kiadásokban való implementálásra, az npm függőségek viselkedése ugyanaz marad, mint korábban a `js` cél esetén a Kotlin 2.2.20-ban.

## Javított kivételkezelés Kotlin/Wasm és JavaScript interop-ban

Korábban a Kotlin nehezen értette meg a JavaScript-ben (JS) dobott kivételeket (hibákat), és Kotlin/Wasm kódra kerültek. Néhány esetben a probléma a fordított irányban is előfordult, amikor egy kivétel dobódott vagy áthaladt a Wasm kódon JS-re és becsomagolták WebAssembly.Exception-be részletek nélkül.

Ezek a Kotlin kivételkezelési problémák nehezítették a hibakeresést. A Kotlin 2.2.20-től kezdve a fejlesztői élmény a kivételekkel javul mindkét irányban:

- Amikor kivételek dobódnak JS-ből, több információt láthatsz Kotlin oldalon.
- Amikor egy ilyen kivétel visszakerül Kotlin-ból JS-re, már nem lesz becsomagolva WebAssembly-be.
- Amikor kivételek dobódnak Kotlin-ból, mostantól JS hibákként elkaphatók JS oldalon.

Az új kivételkezelés automatikusan működik a modern böngészőkben, amelyek támogatják a WebAssembly.JSTag tulajdonságot:
- Chrome 115+
- Firefox 129+
- Safari 18.4+

A régebbi böngészőkben a kivételkezelési viselkedés változatlan marad.

## Támogatás böngészőkben való hibakereséshez konfiguráció nélkül

Korábban a böngészők nem fértek hozzá automatikusan a Kotlin/Wasm projekt forrásaihoz, amelyek hibakereséshez szükségesek voltak. A Kotlin/Wasm alkalmazások böngészőben való hibakereséséhez manuálisan kellett konfigurálni a buildet a következő kódrészlet hozzáadásával a `build.gradle(.kts)` fájlhoz:

```
devServer = (devServer ?: KotlinWebpackConfig.DevServer()).apply {
    static = (static ?: mutableListOf()).apply {
        add(project.rootDir.path)
    }
}
```

A Kotlin 2.2.20-tól kezdve a modern böngészőkben való alkalmazáshibakeresés már alapból működik. Amikor Gradle fejlesztési feladatokat (*DevRun) futtatsz, a Kotlin automatikusan kiszolgálja a forrásfájlokat a böngészőnek, lehetővé téve töréspontok beállítását, változók ellenőrzését és lépésenkénti végrehajtást extra beállítás nélkül.

# Kotlin 2.2.20 változások és frissítések

## Hibakeresés egyszerűsítése

Ez a változás leegyszerűsíti a hibakeresést azzal, hogy eltávolítja a manuális konfiguráció szükségességét. A szükséges konfiguráció mostantól része a Kotlin Gradle pluginnek. Ha korábban ezt a beállítást hozzáadtad a `build.gradle(.kts)` fájlhoz, akkor el kell távolítanod, hogy elkerüld az ütközéseket.

A böngészőkben való hibakeresés mostantól alapértelmezetten engedélyezett minden Gradle *DevRun feladatra. Ezek a feladatok nemcsak az alkalmazást szolgálják ki, hanem a forrásfájlokat is, ezért csak helyi fejlesztéshez használd őket, és kerüld a futtatásukat olyan felhő- vagy éles környezetekben, ahol a források nyilvánosan elérhetővé válhatnak.

### Ismétlődő újratöltések kezelése hibakeresés során

A forrásfájlok alapértelmezett kiszolgálása ismétlődő újratöltéseket okozhat az alkalmazásban a böngészőben, mielőtt a Kotlin fordítás és csomagolás befejeződik. Megoldásként állítsd be a webpack konfigurációt, hogy figyelmen kívül hagyja a Kotlin forrásfájlokat, és tiltsd le a kiszolgált statikus fájlok figyelését. Adj hozzá egy `.js` fájlt a következő tartalommal a projekt gyökerében lévő `webpack.config.d` könyvtárhoz:

```
config.watchOptions = config.watchOptions || { ignored: ["**/*.kt", "**/node_modules"] }
if (config.devServer) {
    config.devServer.static = config.devServer.static.map(file => {
        if (typeof file === "string") {
            return { directory: file, watch: false, }
        } else {
            return file
        }
    })
}
```

## Üres `yarn.lock` fájlok megszűntetése

Korábban a Kotlin Gradle plugin (KGP) automatikusan létrehozott egy `yarn.lock` fájlt, amely tartalmazta az npm csomagok információit, amelyeket a Kotlin eszközlánc igényelt, valamint minden meglévő npm függőséget a projektből vagy használt könyvtárakból. Mostantól a KGP külön kezeli az eszközlánc függőségeit, és a projekt szintű `yarn.lock` fájl csak akkor kerül létrehozásra, ha a projektnek npm függőségei vannak. A KGP automatikusan létrehozza a `yarn.lock` fájlt, ha npm függőségek kerülnek hozzáadásra, és törli, ha azokat eltávolítják. Ez a változás tisztítja a projekt szerkezetét és megkönnyíti az npm függőségek nyomon követését.

### Nincs szükség további konfigurációra

Ez a viselkedés alapértelmezetten aktív, kivéve a Kotlin/Wasm projekteket, ahol a Kotlin 2.2.20-tól kezdve érhető el.

## Új fordítási hiba a teljesen minősített osztályneveknél

A Kotlin/Wasm esetén a fordító alapértelmezetten nem tárolja az osztályok teljesen minősített neveit (FQN) a generált binárisban. Ez az eljárás megakadályozza az alkalmazás méretének növekedését. Ennek eredményeként korábbi Kotlin verziókban a `KClass::qualifiedName` tulajdonság egy üres karakterláncot adott vissza az osztály minősített neve helyett.

A Kotlin 2.2.20-tól kezdve a fordító hibát jelez, ha használod a `KClass::qualifiedName` tulajdonságot Kotlin/Wasm projekteken, hacsak nem engedélyezed kifejezetten a minősített nevek funkciót. Ez a változás megakadályozza a váratlan üres karakterláncokat a `qualifiedName` tulajdonság meghívásakor, és fejlesztőbarátabb élményt nyújt a problémák fordítási időben való észlelésével.

Ez a diagnosztizálás alapértelmezetten engedélyezett, és a hibák automatikusan jelentésre kerülnek. A diagnosztika letiltásához és az FQN-ek Kotlin/Wasm-ben való tárolásához add hozzá a következő opciót a `build.gradle(.kts)` fájlhoz:

```
kotlin {
    wasmJs {
        ...
        compilerOptions {
            freeCompilerArgs.add("-Xwasm-kclass-fqn")
        }
    }
}
```

Ne feledd, hogy ennek az opciónak az engedélyezése növeli az alkalmazás méretét.

## Kotlin/JS

A Kotlin 2.2.20 támogatja a `BigInt` típus használatát a Kotlin `Long` típus reprezentálásához, lehetővé téve a `Long` típus használatát exportált deklarációkban. Ezenkívül ez a kiadás bevezet egy DSL függvényt a Node.js argumentumok tisztítására.

### A `BigInt` típus használata a Kotlin `Long` reprezentálásához

Az ES2020 szabvány előtt a JavaScript nem támogatta a 53 bitnél nagyobb pontos egész számok primitív típusát. Emiatt a Kotlin/JS a `Long` értékeket (amelyek 64 bitesek) két szám tulajdonságot tartalmazó JavaScript objektumként reprezentálta. Ez az egyéni implementáció bonyolultabbá tette a Kotlin és JavaScript közötti együttműködést.

A Kotlin 2.2.20-tól kezdve a Kotlin/JS a JavaScript beépített `BigInt` típusát használja a Kotlin `Long` értékek reprezentálásához, ha modern JavaScripthez (ES2020) fordítod a projektet. Ez a változás lehetővé teszi a `Long` típus exportálását JavaScriptbe, egy új funkció, amely szintén a Kotlin 2.2.20-ban jelent meg. Ennek eredményeként az együttműködés a Kotlin és JavaScript között egyszerűbbé válik.

Az engedélyezéshez add hozzá a következő fordító opciót a `build.gradle(.kts)` fájlhoz:

```
kotlin {
    js {
        ...
        compilerOptions {
            freeCompilerArgs.add("-Xes-long-as-bigint")
        }
    }
}
```

Ez a funkció Kísérleti. Örömmel fogadjuk a visszajelzéseidet a hibabejelentő rendszerünkben, YouTrack-ben.

### A `Long` típus használata exportált deklarációkban

A Kotlin/JS egyéni `Long` implementációja miatt korábban nehéz volt egyszerű módon együttműködni a Kotlin `Long` típusával JavaScriptből. Ennek eredményeként nem lehetett exportálni a `Long` típust használó Kotlin kódot JavaScriptbe. Ez a probléma minden olyan kódot érintett, amely a `Long` típust használta, például függvényparamétereket, osztálytulajdonságokat vagy konstruktorokat.

Most, hogy a Kotlin `Long` típus lefordítható JavaScript `BigInt` típusra, a Kotlin/JS támogatja a `Long` értékek exportálását JavaScriptbe, egyszerűbbé téve a Kotlin és JavaScript kód közötti együttműködést.

Az engedélyezéshez:

1. Engedélyezd a `Long` exportálását Kotlin/JS-ben a következő fordító opció hozzáadásával a `freeCompilerArgs` tulajdonsághoz a `build.gradle(.kts)` fájlban:

```
kotlin {
    js {
        ...
        compilerOptions {
            freeCompilerArgs.add("-XXLanguage:+JsAllowLongInExportedDeclarations")
        }
    }
}
```

2. Engedélyezd a `BigInt` típust. Lásd a használati utasítást a `BigInt` típus használatánál a Kotlin `Long` reprezentálásához.

### Új DSL függvény tisztább argumentumokhoz

Egy Kotlin/JS alkalmazás futtatásakor a Node.js-szel az argumentumok (args) tartalmazták:
- A végrehajtható Node elérési útját.
- A szkript elérési útját.
- A megadott parancssori argumentumokat.

Azonban az elvárt viselkedés az volt, hogy az argumentumok csak a parancssori argumentumokat tartalmazzák. Ennek eléréséhez manuálisan kellett kihagyni az első két argumentumot a `drop()` függvény használatával a `build.gradle(.kts)` fájlban vagy a Kotlin kódban:

```
fun main(args: Array<String>) {
    println(args.drop(2).joinToString(", "))
}
```

Ez a megoldás ismétlődő volt, hibás és nem működött jól platformok közötti kód megosztás esetén.

A Kotlin 2.2.20 bevezet egy új DSL függvényt, a `passCliArgumentsToMainFunction()` néven. Ennek segítségével csak a parancssori argumentumokat tartalmazza, a Node és a szkript elérési útjait pedig kihagyja:

```
fun main(args: Array<String>) {
    // Nincs szükség a drop() használatára, csak az egyéni argumentumokat tartalmazza
    println(args.joinToString(", "))
}
```

Ez a változás csökkenti a boilerplate kódot, megelőzi az argumentumok manuális kihagyásából adódó hibákat, és javítja a platformok közötti kompatibilitást.

Az engedélyezéshez add hozzá a következő DSL függvényt a `build.gradle(.kts)` fájlhoz:

```
kotlin {
    js {
        nodejs {
            passCliArgumentsToMainFunction()
        }
    }
}
```

## Gradle

A Kotlin 2.2.20 új fordítási teljesítménymutatókat vezet be a Kotlin/Native feladatokhoz a Gradle build jelentésekben, és minőségi fejlesztéseket hajt végre az inkrementális fordításban.

### Új fordítási teljesítménymutatók a Kotlin/Native feladatokhoz

A Kotlin 1.7.0 bevezette a build jelentéseket a fordító teljesítményének követéséhez. Azóta újabb metrikákat adtunk hozzá, hogy részletesebbé és hasznosabbá tegyük ezeket a jelentéseket a teljesítménnyel kapcsolatos problémák vizsgálata során.

A Kotlin 2.2.20 esetén a build jelentések most már tartalmazzák a Kotlin/Native feladatokhoz tartozó fordítási teljesítménymutatókat. A build jelentésekről és konfigurálásukról további információkért lásd a **build jelentések engedélyezése** részt.

### Az inkrementális fordítás fejlesztése Kotlin/JVM esetén (Előnézet)

A Kotlin 2.0.0 bevezette az új K2 fordítót egy optimalizált frontenddel. A Kotlin 2.2.20 a frontend használatával fejleszti a teljesítményt bizonyos összetett inkrementális fordítási forgatókönyvekben a Kotlin/JVM esetén.

Ezek a fejlesztések alapértelmezetten le vannak tiltva, míg stabilizáljuk a viselkedést. Az engedélyezéshez add hozzá a következő tulajdonságot a `gradle.properties` fájlhoz:

```
kotlin.incremental.jvm.fir=true
```

Jelenleg a kapt fordító plugin nem kompatibilis ezzel az új viselkedéssel. Dolgozunk azon, hogy támogatást adjunk egy jövőbeli Kotlin kiadásban. Örömmel fogadjuk a visszajelzéseidet a YouTrack hibabejelentő rendszerben.

### Az inkrementális fordítás észleli a beágyazott függvények lambdaiban történt változásokat

A Kotlin 2.2.20 előtt, ha az inkrementális fordítás engedélyezve volt, és megváltoztattad a logikát egy beágyazott függvény lambda kifejezésén belül, a fordító nem fordította újra a beágyazott függvény hívási helyeit más modulokban. Ennek eredménye az volt, hogy ezek a hívási helyek az előző verziót használták a lambda kifejezésből, ami váratlan viselkedést okozhatott.

A Kotlin 2.2.20 esetén a fordító most már felismeri a beágyazott függvények lambdaiban történt változásokat, és automatikusan újrafordítja a hívási helyeket.

## Maven

### A Kotlin daemon támogatása a `kotlin-maven-plugin`-ben

A Kotlin 2.2.20 tovább lép a Kotlin 2.2.0-ban bevezetett build eszköztárhoz kiadott fejlesztéssel, és hozzáadja a Kotlin daemon támogatását a `kotlin-maven-plugin` modulban. A Kotlin daemon használatakor a Kotlin fordító külön, izolált folyamatban fut, megakadályozva, hogy más Maven pluginok felülírják a rendszertulajdonságokat.

Egy példát láthatsz ebbe a [YouTrack problémában](https://youtrack.jetbrains.com/issue/KT-XXXX).

A Kotlin 2.2.20-tól kezdve a Kotlin daemon alapértelmezetten használatban van. Ha vissza szeretnél térni az előző viselkedésre, akkor a következő tulajdonságot kell megadnod a `pom.xml`-ben:

```
<properties>
    <kotlin.compiler.daemon>false</kotlin.compiler.daemon>
</properties>
```

A Kotlin 2.2.20 bevezet egy új `jvmArgs` tulajdonságot is, amellyel testreszabhatod az alapértelmezett JVM argumentumokat a Kotlin daemon számára. Például az `-Xmx` és `-Xms` opciók felülírásához add hozzá a következőt a `pom.xml` fájlhoz:

```
<properties>
    <kotlin.compiler.daemon.jvmArgs>Xmx1500m,Xms500m</kotlin.compiler.daemon.jvmArgs>
</properties>
```

## Új közös séma a Kotlin fordítási opciókhoz

A Kotlin 2.2.20 bevezet egy közös sémát minden fordítási opcióhoz, amely a `org.jetbrains.kotlin:kotlin-compiler-arguments-description` alatt érhető el. Ez az artifact tartalmazza a fordítási opciók kód reprezentációját és JSON megfelelőjét (nem JVM fogyasztók számára), leírásukat, valamint metaadatokat, például melyik verzióban kerültek bevezetésre vagy stabilizálásra.

Ez a séma segítségével generálhatsz egyéni nézetet az opciókról, vagy elemzed őket igény szerint.

## Kotlin alapkönyvtár (standard library)

Ez a kiadás új kísérleti funkciókat vezet be az alapkönyvtárban:
- tükrözési támogatás a Kotlin/JS-en belüli interfésztípusok azonosításához,
- frissítési funkciók a közös atomi típusokhoz,
- `copyOf()` túlterhelések tömbök átméretezéséhez.

### Interfésztípusok azonosítása tükrözéssel a Kotlin/JS-ben

A Kotlin 2.2.20 bevezeti az `Experimental KClass.isInterface` tulajdonságot a Kotlin/JS alapkönyvtárban. Ennek segítségével ellenőrizheted, hogy egy osztályhivatkozás Kotlin interfészt képvisel-e. Ez a Kotlin/JS-t közelebb viszi a Kotlin/JVM funkcionalitásához, ahol a `KClass.java.isInterface` tulajdonsággal ellenőrizheted, hogy egy osztály interfészt képvisel-e.

Az engedélyezéshez használd az `@OptIn(ExperimentalStdlibApi::class)` annotációt:

```
@OptIn(ExperimentalStdlibApi::class)
fun inspect(klass: KClass<*>) {
    // Igaz érték kerül kiírásra interfészek esetén
    println(klass.isInterface)
}
```

Örömmel fogadjuk a visszajelzéseidet a hibabejelentő rendszerünkben, YouTrack-ben.

### Frissítési funkciók közös atomi típusokhoz

A Kotlin 2.2.20 új kísérleti funkciókat vezet be a közös atomi típusok frissítéséhez és azok tömbbeli megfelelőinek elemeihez. Minden funkció atomi módon számol ki egy új értéket az egyik frissítési funkció segítségével, és lecseréli a jelenlegi értéket, a visszatérési érték attól függ, hogy melyik függvényt használod:

- `update()` és `updateAt()` új értéket állít be eredmény visszaadása nélkül.
- `fetchAndUpdate()` és `fetchAndUpdateAt()` új értéket állít be, és visszaadja a változás előtti értéket.
- `updateAndFetch()` és `updateAndFetchAt()` új értéket állít be, és visszaadja a változás utáni, frissített értéket.

Ezek a funkciók segítenek atomikus átalakításokat implementálni, amelyeket alapból nem támogat a rendszer, például szorzást vagy bitműveleteket.

Ez előtt a változással megnőtt egy közös atomi típus, és a korábbi érték kiolvasása egy hurokkal volt lehetséges a `compareAndSet()` függvény használatával.

Mint minden közös atomi API, ezek a funkciók Kísérletiek. Az engedélyezéshez használd az `@OptIn(ExperimentalAtomicApi::class)` annotációt.

Példa kód, amely különböző típusú frissítéseket végez, és az előző illetve frissített értéket adja vissza:

```
import kotlin.concurrent.atomics.*
import kotlin.random.Random

@OptIn(ExperimentalAtomicApi::class)
fun main() {
    val counter = AtomicLong(Random.nextLong())
    val minSetBitsThreshold = 20

    // Új érték beállítása eredmény visszaadása nélkül
    counter.update { if (it < 0xDECAF) 0xCACA0 else 0xC0FFEE }

    // Az aktuális érték lekérése, majd frissítése
    val previousValue = counter.fetchAndUpdate { 0x1CEDL.shl(Long.SIZE_BITS - it.countLeadingZeroBits()) or it }

    // Az érték frissítése, majd a frissített érték lekérése
    val current = counter.updateAndFetch {
        if (it.countOneBits() < minSetBitsThreshold) it.shl(20) or 0x15BADL else it
    }

    val hexFormat = HexFormat {
        upperCase = true
        number {
            removeLeadingZeros = true
        }
    }

    println("Previous value: ${previousValue.toHexString(hexFormat)}")
    println("Current value: ${current.toHexString(hexFormat)}")
    println("Expected status flag set: ${current and 0xBAD != 0xBADL}")
}
```

Örömmel fogadjuk a visszajelzéseidet a hibabejelentő rendszerünkben, YouTrack-ben.

### `copyOf()` túlterhelések támogatása tömbökhöz

A Kotlin 2.2.20 bevezet egy kísérleti túlterhelést a `copyOf()` függvényhez. Ez minden generikus típusú `Array<T>` és minden primitív tömbtípus esetén elérhető. Ezzel a funkcióval egy tömböt nagyobbra méretezhetsz, és az új elemeket egy inicializáló lambda segítségével töltheted fel. Ez segíthet csökkenteni az egyéni boilerplate kódot, és kijavítja a gyakori problémát, hogy egy generikus `Array<T>` átméretezése nullázható eredményt ad (Array<T?>).

Itt egy példa:

```
@OptIn(ExperimentalStdlibApi::class)
fun main() {
    val row1: Array<String> = arrayOf("one", "two")
    // A tömb átméretezése és az új elemek feltöltése a lambdával
    val row2: Array<String> = row1.copyOf(4) { "default" }
    println(row2.contentToString()) // [one, two, default, default]
}
```

Ez az API is Kísérleti. Az engedélyezéshez használd az `@OptIn(ExperimentalStdlibApi::class)` annotációt. Örömmel fogadjuk a visszajelzéseidet a hibabejelentő rendszerünkben.

## Compose fordító

Ez a kiadás minőségi fejlesztéseket hoz a Compose fordítóhoz, új figyelmeztetések hozzáadásával és a build metrikák kimenetének javításával, hogy könnyebben olvashatók legyenek.

### Nyelvi verzió korlátozások alapértelmezett paramétereknél

Ezzel a kiadással a Compose fordító hibát jelez, ha a fordításhoz megadott nyelvi verzió alacsonyabb, mint amit az absztrakt vagy nyitott összeállítható függvények alapértelmezett paramétereinek támogatásához szükséges. Az alapértelmezett paraméterek a Compose fordítóban támogatottak, a Kotlin 2.1.0-tól absztrakt függvények, a 2.2.0-tól pedig nyitott függvények esetén.

Amikor a Compose fordító újabb verzióját használod régebbi Kotlin nyelvi verziók esetén, a könyvtárfejlesztőknek figyelembe kell venniük, hogy az absztrakt vagy nyitott függvények alapértelmezett paraméterei továbbra is megjelenhetnek a nyilvános API-ban, még akkor is, ha a nyelvi verzió nem támogatja őket.

### Összeállítható cél figyelmeztetések a K2 fordítóhoz

Ez a kiadás figyelmeztetéseket ad a `@ComposableTarget` eltérésekről a K2 fordító használatakor. Például:

```
@Composable
fun App() {
    Box {
        // <-- `Box` egy `@UiComposable`
        Path(...) // <-- `Path` egy `@VectorComposable`
        ^^^^^^^^^ figyelmeztetés: vektor összeállító függvény hívása olyan helyen, ahol UI összeállító függvény van várva
    }
}
```

### Teljesen minősített nevek a build metrikákban

Az osztály- és függvénynevek most már teljesen minősítettek a build metrikákban, így könnyebb megkülönböztetni az azonos nevű, de különböző csomagokból származó deklarációkat.

Ezenkívül a build metrikák már nem tartalmaznak komplex kifejezések kiírását az alapértelmezett paraméterekből, így könnyebben olvashatók.

## Szakítások és elavultak

Ez a szakasz kiemeli a fontos szakításokat és elavultakat, amelyeket fontos megjegyezni:
- A kapt fordító plugin mostantól alapértelmezetten a K2 fordítót használja. Ennek eredményeként a kapt.use.k2 tulajdonság, amely szabályozza, hogy a plugin használja-e a K2 fordítót, elavult. Ha ezt a tulajdonságot hamisra állítod be a K2 fordító használatából való kizáráshoz, akkor a Gradle figyelmeztetést jelenít meg.

## Dokumentációs frissítések

A Kotlin dokumentáció számos észrevehető változáson esett át:
- Kotlin útiterv – Lásd a frissített listát a Kotlin nyelvi és ökoszisztéma fejlődésének prioritásairól.
- Tulajdonságok – Ismerd meg a Kotlinban lévő tulajdonságok számos használati módját.
- Feltételek és ciklusok – Ismerd meg, hogyan működnek a feltételek és a ciklusok a Kotlinban.
- Kotlin/JavaScript – Fedezd fel a Kotlin/JS felhasználási eseteit.
- Web fejlesztés – Ismerd meg a Gradle különböző web fejlesztés célú céljait.
- Kotlin daemon – Ismerd meg a Kotlin daemont és hogyan működik a build rendszerekkel és a Kotlin fordítóval.
- Korutin áttekintés – Ismerkedj meg a korutin fogalmakkal és kezdd meg a tanulásodat.
- Kotlin/Native bináris lehetőségek – Ismerd meg a Kotlin/Native bináris lehetőségeit és hogyan konfigurálhatod őket.
- Kotlin/Native hibakeresés – Fedezd fel a Kotlin/Native hibakeresésének különböző módjait.
- LLVM backend testreszabási tippek – Ismerd meg, hogyan használja a Kotlin/Native az LLVM-t és hogyan állíthatod be az optimalizálási folyamatokat.
- Ismerkedj meg az Exposed DAO API-val – Ismerd meg, hogyan használhatod az Exposed Data Access Object (DAO) API-ját adatok tárolásához és visszakereséséhez egy relációs adatbázisban.

Új oldalak az Exposed dokumentációban az R2DBC-ről:
- Adatbázisok használata
- ConnectionFactory használata
- Egyedi típusleképezés
- HTMX integráció – Ismerd meg, hogy a Ktor hogyan biztosít kísérleti, első osztályú támogatást az HTMX-hez.

## Hogyan frissíts a Kotlin 2.2.20-re

A Kotlin plugin elérhető a IntelliJ IDEA és az Android Studio csomagjában. A Kotlin új verziójára való frissítéshez egyszerűen változtasd meg a Kotlin verziót 2.2.20-ra a build szkriptjeidben.

## Újdonságok a Kotlin 2.2.0-ban

**Kiadás dátuma: 2025. június 23.**

A Kotlin 2.2.0 megérkezett! Íme a főbb kiemelések:
- Nyelv: új nyelvi funkciók előnézetben, beleértve a kontextusparamétereket.
- Számos korábban kísérleti funkcionalitás mostantól Stabil, például a védett feltételek, a nem helyi kilépések és folytatások, valamint a többdolláros interpoláció.
- Kotlin fordító: egységes kezelés a fordítási figyelmeztetések kezelésére.
- Kotlin/JVM: változások a felületi függvények alapértelmezett metódusgenerálásában.
- Kotlin/Native: LLVM 19 és új funkciók a memóriafogyasztás nyomon követéséhez és beállításához.
- Kotlin/Wasm: szeparált Wasm cél és a Binaryen projekt alapú konfigurálásának lehetősége.
- Kotlin/JS: javítás a `@JsPlainObject` interfészekhez generált `copy()` metódusban.
- Gradle: bináris kompatibilitás ellenőrzése a Kotlin Gradle pluginben.
- Alapkönyvtár: stabil Base64 és HexFormat API-k.
- Dokumentáció: a dokumentációs felmérés nyitva áll, és észrevehető fejlesztéseket eszközöltünk a Kotlin dokumentációban.

Megtekintés videón: [GIF](https://kotlinlang.org) vagy [videó megtekintése online](https://www.example.com).

## IDE támogatás

A Kotlin plugin, amely támogatja a 2.2.0 verziót, elérhető az IntelliJ IDEA és az Android Studio legújabb verzióiban. Nem kell frissítened a Kotlin plugin-t az IDE-ben. Mindössze annyit kell tenned, hogy megváltoztatod a Kotlin verziót a 2.2.0-re a build szkriptjeidben.

Qven: ```markdown
# Újdonságok a Kotlin 2.2.0-ban
## Lásd: [Frissítés új kiadásra](https://kotlinlang.org/docs/releases.html#update-to-a-new-release) részletesebb információkért.

## Nyelv

Ez a kiadás stabilizálja a **védett feltételeket**, a **nem helyi kilépést és folytatást**, valamint a **többdolláros interpolációt**. Továbbá számos funkciót, például a **kontextusparamétereket** és a **kontextusérzékeny feloldást**, előnézetként vezet be.

### Kontextusparaméterek előnézete

A kontextusparaméterek lehetővé teszik, hogy függvények és tulajdonságok függőségeket deklaráljanak, amelyek implicit módon elérhetők a környezetben. A kontextusparaméterekkel már nem kell manuálisan átadni az olyan értékeket (például szolgáltatásokat vagy függőségeket), amelyek megosztottak és ritkán változnak a függvényhívások során.

A kontextusparaméterek lecserélik a korábbi, kísérleti jellegű kontextusfogadókat. A kontextusfogadókról való áttéréshez használhatod az IntelliJ IDEA támogatását, amelyet bemutat a blogbejegyzés.

A fő különbség az, hogy a kontextusparaméterek nem fogadóként vannak bevezetve a függvény törzsében. Ennek eredményeként a kontextusparaméterek nevét kell használnod a tagok eléréséhez, míg a kontextusfogadók esetén a kontextus implicit módon elérhető.

A Kotlin kontextusparaméterei jelentős fejlődést jelentenek a függőségek kezelésében az egyszerűsített függőségi injektálás, javított DSL tervezés és hatókörrel rendelkező műveletek révén. További információkért lásd a funkció [KEEP](https://github.com/Kotlin/KEEP/blob/master/proposals/context-parameters.md) dokumentációját.

### Kontextusparaméterek deklarálása

Tulajdonságokhoz és függvényekhez kontextusparamétereket deklarálhatsz a `context` kulcsszó és a paraméterek listája segítségével, mindegyik `név: Típus` formátumban:

```
// UserService határozza meg a kontextusban szükséges függőséget
interface UserService {
    fun log(message: String)
    fun findUserById(id: Int): String
}

// Deklarál egy függvényt kontextusparaméterrel
context(users: UserService)
fun outputMessage(message: String) {
    // A kontextusból származó log használata
    users.log("Log: $message")
}

// Deklarál egy tulajdonságot kontextusparaméterrel
context(users: UserService)
val firstUser: String
    // A kontextusból származó findUserById használata
    get() = users.findUserById(1)
```

Használhatod `_` karaktert kontextusparaméter névként. Ebben az esetben a paraméter értéke elérhető a feloldáshoz, de nem érhető el név alapján a blokkon belül:

```
// "_" használata kontextusparaméter névként
context(_: UserService)
fun logWelcome() {
    // A megfelelő log függvény keresése a UserService-ből
    outputMessage("Welcome!")
}
```

### Kontextusparaméterek engedélyezése

A kontextusparaméterek engedélyezéséhez használd a következő fordítóopciót parancssorból:
```
-Xcontext-parameters
```

Vagy add hozzá a `compilerOptions {}` blokkhoz a Gradle build fájlban:
```
// build.gradle.kts
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xcontext-parameters")
    }
}
```

A `-Xcontext-receivers` és `-Xcontext-parameters` fordítóopciók egyszerre történő megadása hibát eredményez. Kérjük, vedd fel visszajelzésed a [YouTrack hibabejelentő rendszerben](https://kotl.in/issue).

Ez a funkció a jövőbeli Kotlin kiadásokban stabilizálódni és fejlődni fog. Örömmel fogadjuk a visszajelzéseidet a [YouTrack hibabejelentő rendszerben](https://kotl.in/issue).

### Kontextusérzékeny feloldás előnézete

A Kotlin 2.2.0 előnézetként bevezeti a kontextusérzékeny feloldás implementációját. Korábban meg kellett adni az enum bejegyzések vagy sealed osztálytagok teljes nevét, még akkor is, ha a típus kikövetkeztethető volt a kontextusból. Például:

```
enum class Problem {
    CONNECTION, AUTHENTICATION, DATABASE, UNKNOWN
}

fun message(problem: Problem): String = when (problem) {
    Problem.CONNECTION -> "connection"
    Problem.AUTHENTICATION -> "authentication"
    Problem.DATABASE -> "database"
    Problem.UNKNOWN -> "unknown"
}
```

Most, a kontextusérzékeny feloldással kihagyhatod a típusnevet olyan kontextusokban, ahol a várt típus ismert:

```
enum class Problem {
    CONNECTION, AUTHENTICATION, DATABASE, UNKNOWN
}

// Enum bejegyzések feloldása a probléma ismert típusa alapján
fun message(problem: Problem): String = when (problem) {
    CONNECTION -> "connection"
    AUTHENTICATION -> "authentication"
    DATABASE -> "database"
    UNKNOWN -> "unknown"
}
```

A fordító a kontextuális típusinformációkat használja a megfelelő tag feloldásához. Ez az információ tartalmazza többek között:
- A `when` kifejezés alanyát
- Az explicit visszatérési típust
- Egy deklarált változó típusát
- Típusellenőrzéseket (`is`) és típuskényszerítéseket (`as`)
- Egy sealed osztályhierarchia ismert típusát
- Egy paraméter deklarált típusát

A kontextusérzékeny feloldás nem vonatkozik függvényekre, paraméterekkel rendelkező tulajdonságokra vagy fogadókkal rendelkező kiterjesztéstartozásokra.

A kontextusérzékeny feloldás kipróbálásához használd a következő fordítóopciót parancssorból:
```
-Xcontext-sensitive-resolution
```

Vagy add hozzá a `compilerOptions {}` blokkhoz a Gradle build fájlban:
```
// build.gradle.kts
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xcontext-sensitive-resolution")
    }
}
```

Ez a funkció a jövőbeli Kotlin kiadásokban stabilizálódni és fejlődni fog. Örömmel fogadjuk a visszajelzéseidet a [YouTrack hibabejelentő rendszerben](https://kotl.in/issue).

### Új funkciók annotációk használati helyeinek céljaihoz

### `@all` metacél tulajdonságokhoz

A Kotlin lehetővé teszi annotációk adott deklarációs részekhez való csatolását, amelyeket használati hely céloknak neveznek. Azonban minden cél külön-külön annotálása bonyolult és hibás lehet:

```
data class User(
    val username: String,
    @param:Email // Konstruktor paraméter
    @field:Email // Támogató mező
    @get:Email // Getter metódus
    @property:Email // Kotlin tulajdonsághivatkozás
    val email: String,
) {
    @field:Email
    @get:Email
    @property:Email
    val secondaryEmail: String? = null
}
```

Az egyszerűsítés érdekében a Kotlin bevezeti az új `@all` metacélt tulajdonságokhoz. Ez a funkció azt mondja a fordítónak, hogy alkalmazza az annotációt a tulajdonság összes releváns részére. Használatakor a `@all` megpróbálja alkalmazni az annotációt:

- `param`: a konstruktor paraméterre, ha az elsődleges konstruktorban van deklarálva
- `property`: magára a Kotlin tulajdonságra
- `field`: a támogató mezőre, ha létezik
- `get`: a getter metódusra
- `setparam`: a setter metódus paraméterére, ha a tulajdonság `var`-ként van definiálva
- `RECORD_COMPONENT`: ha az osztály `@JvmRecord`, az annotáció a Java rekord komponensre vonatkozik

Ez a viselkedés utánozza a Java rekord komponensek annotációinak kezelését. A fordító csak a megadott tulajdonság céljaira alkalmazza az annotációt. Az alábbi példában az `@Email` annotáció az egyes tulajdonságok összes releváns céljára vonatkozik:

```
data class User(
    val username: String,
    // @Email alkalmazása param-ra, property-re, field-re,
    // get-re és setparam-re (ha var)
    @all:Email val email: String,
) {
    // @Email alkalmazása property-re, field-re és get-re
    // (nincs param, mert nem a konstruktorban van)
    @all:Email val secondaryEmail: String? = null
}
```

A `@all` metacélt bármilyen tulajdonsággal használhatod, mind az elsődleges konstruktoron belül, mind kívül. Azonban nem használhatod több annotáció esetén.

Az új funkció leegyszerűsíti a szintaxist, biztosítja a konzisztenciát és javítja a Java rekordokkal való együttműködést.

A `@all` metacél engedélyezéséhez használd a következő fordítóopciót parancssorból:
```
-Xannotation-target-all
```

Vagy add hozzá a `compilerOptions {}` blokkhoz a Gradle build fájlban:
```
// build.gradle.kts
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xannotation-target-all")
    }
}
```

Ez a funkció előnézetben van. Kérjük, jelentsd a problémákat a [YouTrack hibabejelentő rendszerben](https://kotl.in/issue).

További információk a `@all` metacélról: [KEEP javaslat](https://github.com/Kotlin/KEEP/blob/master/proposals/annotation-target-all.md).

### Új alapértelmezési szabályok annotációk használati helyeinek céljaihoz

A Kotlin 2.2.0 új alapértelmezési szabályokat vezet be az annotációk paraméterekre, mezőkre és tulajdonságokra történő propagálásához. Ahol korábban egy annotáció alapértelmezés szerint csak egy célra (`param`, `property` vagy `field`) volt alkalmazva, ott most az alapértelmezések jobban követik az annotációk elvárt viselkedését.

Ha több alkalmazható cél van, akkor egy vagy több cél kerül kiválasztásra a következők szerint:
- Ha a konstruktor paraméter cél (`param`) alkalmazható, akkor az lesz használva
- Ha a tulajdonság cél (`property`) alkalmazható, akkor az lesz használva
- Ha a mező cél (`field`) alkalmazható, miközben a tulajdonság cél nem, akkor a mező lesz használva
- Ha több cél van, és egyik sem (`param`, `property` vagy `field`) nem alkalmazható, akkor az annotáció hibát eredményez

A funkció engedélyezéséhez add hozzá a `compilerOptions {}` blokkhoz a Gradle build fájlban:
```
// build.gradle.kts
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xannotation-default-target=param-property")
    }
}
```

Vagy használd a parancssori argumentumot a fordítóhoz:
```
-Xannotation-default-target=param-property
```

Ha az régi viselkedést szeretnéd használni:
- Egy adott esetben definiáld a szükséges célt explicit módon, például `@param:Annotation` használatával az `@Annotation` helyett
- A teljes projekt esetén használd a következő zászlót a Gradle build fájlban:
```
// build.gradle.kts
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xannotation-default-target=first-only")
    }
}
```

Ez a funkció előnézetben van. Kérjük, jelentsd a problémákat a [YouTrack hibabejelentő rendszerben](https://kotl.in/issue).

További információk az új alapértelmezési szabályokról: [KEEP javaslat](https://github.com/Kotlin/KEEP/blob/master/proposals/annotation-default-targets.md).

### Beágyazott típusálnév (type alias) támogatás

Korábban csak a Kotlin fájl legfelső szintjén lehetett típusálnév deklarálni. Ez azt jelentette, hogy még a belső vagy domain-specifikus típusálnév-eket is az osztályon kívül kellett elhelyezni, ahol használták.

A 2.2.0-tól kezdve definiálhatsz típusálnév-eket más deklarációk belsejében, amennyiben nem ragadják meg a külső osztály típusparamétereit:

```
class Dijkstra {
    typealias VisitedNodes = Set<Node>
    private fun step(visited: VisitedNodes, ...) = ...
}
```

A beágyazott típusálnév-eknek vannak további korlátozásaik, például nem említhetik meg a típusparamétereket. A szabályok teljes listájáért lásd a dokumentációt.

A beágyazott típusálnév-ek tisztábbá és karbantarthatóbbá teszik a kódot a kapszulázás javításával, csomagszintű rendezetlenség csökkentésével és belső implementációk egyszerűsítésével.

### Beágyazott típusálnév-ek engedélyezése

A beágyazott típusálnév-ek engedélyezéséhez használd a következő fordítóopciót parancssorból:
```
-Xnested-type-aliases
```

Vagy add hozzá a `compilerOptions {}` blokkhoz a Gradle build fájlban:
```
// build.gradle.kts
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xnested-type-aliases")
    }
}
```

### Visszajelzés megosztása

A beágyazott típusálnév-ek jelenleg béta állapotban vannak. Kérjük, jelentsd a problémákat a [YouTrack hibabejelentő rendszerben](https://kotl.in/issue).

További információk a funkcióról: [KEEP javaslat](https://github.com/Kotlin/KEEP/blob/master/proposals/nested-type-aliases.md).

### Stabil funkciók: védett feltételek, nem helyi kilépés és folytatás, valamint többdolláros interpoláció

A Kotlin 2.1.0-ban több új nyelvi funkció is bevezetésre került előnézetként. Örömmel jelentjük be, hogy a következő nyelvi funkciók most már stabilak ebben a kiadásban:

- Védett feltételek `when` kifejezésben alany esetén
- Nem helyi kilépés és folytatás
- Többdolláros interpoláció: javított kezelés a `$` karakterre szövegliterálokban

Lásd a teljes listát a Kotlin nyelvi tervezési funkciókról és javaslatokról.

## Kotlin fordító: egységes fordítófigyelmeztetések kezelése

A Kotlin 2.2.0 bevezet egy új fordítóopciót, `-Xwarning-level`. Célja a Kotlin projektek fordítófigyelmeztetéseinek egységes kezelésének biztosítása.

Korábban csak általános modulszintű szabályokat lehetett alkalmazni, például az összes figyelmeztetés letiltását a `-nowarn` használatával, az összes figyelmeztetés hibává alakítását a `-Werror` használatával, vagy további fordítóellenőrzések engedélyezését a `-Wextra` használatával.

Az egyetlen lehetőség a specifikus figyelmeztetések módosítására a `-Xsuppress-warning` opció volt. Az új megoldással általános szabályokat felül lehet írni és specifikus diagnosztizálásokat kizárni konzisztens módon.

### Alkalmazás

Az új fordítóopció szintaxisa:
```
-Xwarning-level=DIAGNOSTIC_NAME:(error|warning|disabled)
```

- `error`: a megadott figyelmeztetést hibává emeli
- `warning`: figyelmeztetést bocsát ki, és alapértelmezetten engedélyezve van
- `disabled`: teljesen elnyomja a megadott figyelmeztetést a modul szintjén

Ne feledd, hogy csak a figyelmeztetések súlyossági szintjét tudod konfigurálni az új fordítóopcióval.

### Használati esetek

Az új megoldással jobban finomhangolható a figyelmeztetési jelentés a projektedben az általános szabályok és az egyedi szabályok kombinálásával. Válaszd ki a használati esetedet:

#### Figyelmeztetések elnyomása

| Parancs                                           | Leírás                                                   |
| ------------------------------------------------- | -------------------------------------------------------- |
| `-nowarn`                                         | Elfojta az összes figyelmeztetést a fordítás során       |
| `-Xwarning-level=DIAGNOSTIC_NAME:disabled`        | Csak a megadott figyelmeztetéseket fojtja el             |
| `-nowarn -Xwarning-level=DIAGNOSTIC_NAME:warning` | Elfojta az összes figyelmeztetést, kivéve a megadottakat |

#### Figyelmeztetések hibává emelése

| Parancs                                           | Leírás                                                       |
| ------------------------------------------------- | ------------------------------------------------------------ |
| `-Werror`                                         | Az összes figyelmeztetést hibává emeli                       |
| `-Xwarning-level=DIAGNOSTIC_NAME:error`           | Csak a megadott figyelmeztetéseket emeli hibává              |
| `-Werror -Xwarning-level=DIAGNOSTIC_NAME:warning` | Az összes figyelmeztetést hibává emeli, kivéve a megadottakat |

#### További fordítófigyelmeztetések engedélyezése

| Parancs                                            | Leírás                                                       |
| -------------------------------------------------- | ------------------------------------------------------------ |
| `-Wextra`                                          | Engedélyezi az összes további deklarációs, kifejezési és típusfordítási ellenőrzést, amely figyelmeztetést bocsát ki, ha igaz |
| `-Xwarning-level=DIAGNOSTIC_NAME:warning`          | Csak megadott további fordítóellenőrzéseket engedélyez       |
| `-Wextra -Xwarning-level=DIAGNOSTIC_NAME:disabled` | Engedélyezi az összes további ellenőrzést, kivéve a megadottakat |

### Figyelmeztetési listák

Ha sok figyelmeztetést szeretnél kizárni az általános szabályokból, listázhatod őket egy külön fájlban `@argfile` használatával.

### Visszajelzés

Az új fordítóopció még kísérleti. Kérjük, jelentsd a problémákat a [YouTrack hibabejelentő rendszerben](https://kotl.in/issue).

## Kotlin/JVM

A Kotlin 2.2.0 számos frissítést hoz a JVM-hez. A fordító most már támogatja a Java 24 bájtkódját és változásokat vezet be az interfészfüggvények alapértelmezett metódusgenerálásában. A kiadás továbbá leegyszerűsíti az annotációk használatát a Kotlin metaadatokban, javítja a Java együttműködést az inline értékosztályokkal és jobb támogatást nyújt a JVM rekordok annotálásához.

### Változások az interfészfüggvények alapértelmezett metódusgenerálásában

A Kotlin 2.2.0-tól kezdve az interfészekben deklarált függvények JVM alapértelmezett metódusokként kerülnek lefordításra, kivéve ha másképp van konfigurálva. Ez a változás befolyásolja a Kotlin interfészfüggvényeinek lefordítását bájtkódra az implementációkkal.

Ezt a viselkedést az új, stabil `-jvm-default` fordítóopció szabályozza, amely lecseréli az elavult `-Xjvm-default` opciót.

A `-jvm-default` opció viselkedését a következő értékekkel tudod szabályozni:

- `enable` (alapértelmezett): alapértelmezett implementációkat generál az interfészekben és hidatfunkciókat a leszármazott osztályokban és `DefaultImpls` osztályokban. Ezt a módot használd a régebbi Kotlin verziókkal való bináris kompatibilitás fenntartásához.
- `no-compatibility`: csak alapértelmezett implementációkat generál az interfészekben. Ez a mód kihagyja a kompatibilitási hidakat és `DefaultImpls` osztályokat, így új kódhoz alkalmas.
- `disable`: letiltja az alapértelmezett implementációkat az interfészekben. Csak hidatfunkciókat és `DefaultImpls` osztályokat generál, megegyezve a Kotlin 2.2.0 előtti viselkedéssel.

A `-jvm-default` fordítóopció konfigurálásához állítsd be a `jvmDefault` tulajdonságot a Gradle Kotlin DSL-ben:

```
// build.gradle.kts
kotlin {
    compilerOptions {
        jvmDefault = JvmDefaultMode.NO_COMPATIBILITY
    }
}
```

### Annotációk olvasásának és írásának támogatása Kotlin metaadatokban

Korábban annotációkat kellett olvasni a lefordított JVM osztályfájlokból visszatükrözés vagy bájtkódelemzés segítségével és kézzel kellett összevetni őket a metaadatbejegyzésekkel aláírások alapján. Ez a folyamat hibás volt, különösen túlterhelt függvények esetén.

Most, a Kotlin 2.2.0-ban a Kotlin Metadata JVM könyvtár támogatást vezet be a Kotlin metaadatokban tárolt annotációk olvasásához.

Ahhoz, hogy az annotációk elérhetők legyenek a metaadatokban a lefordított fájljaid számára, add hozzá a következő fordítóopciót:
```
-Xannotations-in-metadata
```
Vagy add hozzá a `compilerOptions {}` blokkhoz a Gradle build fájlban:
```
// build.gradle.kts
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xannotations-in-metadata")
    }
}
```

Ez az opció engedélyezve a Kotlin fordító az annotációkat a metaadatokba írja a JVM bájtkóddal együtt, így azok hozzáférhetők a `kotlin-metadata-jvm` könyvtár számára.

A könyvtár a következő API-kat biztosítja az annotációkhoz való hozzáféréshez:
- `KmClass.annotations`
- `KmFunction.annotations`
- `KmProperty.annotations`
- `KmConstructor.annotations`
- `KmPropertyAccessorAttributes.annotations`
- `KmValueParameter.annotations`
- `KmFunction.extensionReceiverAnnotations`
- `KmProperty.extensionReceiverAnnotations`
- `KmProperty.backingFieldAnnotations`
- `KmProperty.delegateFieldAnnotations`
- `KmEnumEntry.annotations`

Ezek az API-k kísérleti. Az engedélyezéshez használd a `@OptIn(ExperimentalAnnotationsInMetadata::class)` annotációt.

Példa annotációk olvasására Kotlin metaadatokból:

```
@file:OptIn(ExperimentalAnnotationsInMetadata::class)
import kotlin.metadata.ExperimentalAnnotationsInMetadata
import kotlin.metadata.jvm.KotlinClassMetadata

annotation class Label(val value: String)

@Label("Message class")
class Message

fun main() {
    val metadata = Message::class.java.getAnnotation(Metadata::class.java)
    val kmClass = (KotlinClassMetadata.readStrict(metadata) as KotlinClassMetadata.Class).kmClass
    println(kmClass.annotations) // [@Label(value = StringValue("Message class"))]
}
```

Ha használod a `kotlin-metadata-jvm` könyvtárat projektjeidben, javasoljuk a tesztelést és a kódod frissítését az annotációk támogatásához. Ellenkező esetben, amikor a metaadatokban lévő annotációk alapértelmezetten engedélyezve lesznek egy jövőbeli Kotlin verzióban, projektjeid érvénytelen vagy hiányos metaadatokat állíthatnak elő.

Ha bármilyen problémád van, kérjük, jelentsd a hibákat a [hibabejelentő rendszerben](https://kotl.in/issue).

### Javított Java együttműködés inline értékosztályokkal

A Kotlin 2.2.0 egy új kísérleti annotációt vezet be: `@JvmExposeBoxed`. Ez az annotáció megkönnyíti az inline értékosztályok Java-ból való fogyasztását.

Alapértelmezetten a Kotlin az inline értékosztályokat dobozolatlan reprezentációk használatával fordítja le, amelyek hatékonyabbak, de gyakran nehéz vagy akár lehetetlen is Java-ból használni.

Például:
```
@JvmInline
value class PositiveInt(val number: Int) {
    init {
        require(number >= 0)
    }
}
```

Ebben az esetben, mivel az osztály dobozolatlan, nincs konstruktor, amit Java tudna meghívni. Nincs semmilyen módja Java számára az `init` blokk kiváltására a `number` pozitív értékének biztosításához.

Amikor az osztályt `@JvmExposeBoxed` annotációval látod el, a Kotlin egy nyilvános konstruktort generál, amit Java közvetlenül meg tud hívni, biztosítva, hogy az `init` blokk is fusson.

A `@JvmExposeBoxed` annotációt osztályra, konstruktorra vagy függvényszinten alkalmazhatod, így finomhangolhatod, hogy mit tegyél elérhetővé Java számára.

Például az alábbi kódban a `.timesTwoBoxed()` kiterjesztési függvény nem érhető el Java-ból:

```
@JvmInline
value class MyInt(val value: Int)

fun MyInt.timesTwoBoxed(): MyInt = MyInt(this.value * 2)
```

Ahhoz, hogy lehetséges legyen a `MyInt` osztály példányának létrehozása és a `.timesTwoBoxed()` függvény Java kódból való meghívása, add hozzá a `@JvmExposeBoxed` annotációt mind az osztályhoz, mind a függvényhez:

```
@JvmExposeBoxed
@JvmInline
value class MyInt(val value: Int)

@JvmExposeBoxed
fun MyInt.timesTwoBoxed(): MyInt = MyInt(this.value * 2)
```

Ezekkel az annotációkkal a Kotlin fordító egy Java számára elérhető konstruktort generál a `MyInt` osztályhoz. Ezen felül generál egy túlterhelést a kiterjesztési függvény számára, amely az értékosztály dobozolt formáját használja.

Ennek eredményeként a következő Java kód sikeresen fut:

```
MyInt input = new MyInt(5);
MyInt output = ExampleKt.timesTwoBoxed(input);
```

Ha nem akarod annotálni az inline értékosztályok minden részét, amelyet elérhetővé szeretnél tenni, hatékonyan alkalmazhatod az annotációt egy egész modulra.

A viselkedés modulhoz való alkalmazásához fordítsd le a `-Xjvm-expose-boxed` opcióval.

Ez az opció fordítása ugyanazt a hatást gyakorol, mintha a modul minden deklarációja rendelkezne a `@JvmExposeBoxed` annotációval.

Az új annotáció nem változtatja meg, hogy Kotlin hogyan fordítja le vagy használja az értékosztályokat belsőleg, és minden meglévő lefordított kód érvényes marad.

Egyszerűen új képességeket ad a Java együttműködés javításához. Az értékosztályokat használó Kotlin kód teljesítménye nem változik.

# Kotlin 2.2.0 változások

## A @JvmExposeBoxed annotáció

A `@JvmExposeBoxed` annotáció hasznos könyvtárszerzők számára, akik dobozolt változatokat szeretnének elérhetővé tenni a tagfüggvényekből és dobozolt visszatérési típusokat kapni. Ez megszünteti annak szükségességét, hogy válasszunk egy inline értékosztály (hatékony, de csak Kotlinban használható) és egy adatosztály (Java-kompatibilis, de mindig dobozolt) között.

Részletesebb magyarázatért a `@JvmExposedBoxed` annotáció működéséről és a megoldott problémákról, lásd ezt a [KEEP javaslatot](https://github.com/Kotlin/KEEP/blob/master/proposals/jvm-expose-boxed.md).

## Javított támogatás a JVM rekordok annotálásához

A Kotlin a 1.5.0-s verziótól támogatja a JVM rekordokat. Most a Kotlin 2.2.0 javítja, hogyan kezeli a Kotlin az annotációkat a rekord komponenseken, különösen a Java `RECORD_COMPONENT` céljával kapcsolatban.

Először is, ha `RECORD_COMPONENT`-et szeretnél annotációs célnak használni, manuálisan kell hozzáadnod annotációkat Kotlinhoz (`@Target`) és Javához.

Ez azért van, mert a Kotlin `@Target` annotációja nem támogatja a `RECORD_COMPONENT`-et. Például:

```
@Target(AnnotationTarget.CLASS, AnnotationTarget.PROPERTY)
@java.lang.annotation.Target(ElementType.CLASS, ElementType.RECORD_COMPONENT)
annotation class exampleClass
```

Mindkét lista manuális karbantartása hibás lehet, ezért a Kotlin 2.2.0 fordítófigyelmeztetést vezet be, ha a Kotlin és Java célok nem egyeznek meg. Például, ha az `ElementType.CLASS` hiányzik a Java cél listából, a fordító ezt jelenti:

```
Incompatible annotation targets: Java target 'CLASS' missing, corresponding to Kotlin targets 'CLASS'.
```

Másodszor, a Kotlin viselkedése eltér a Javától a rekordokban történő annotációk propagálásában. Java-ban a rekord komponens annotációi automatikusan alkalmazódnak a támogató mezőre, getterre és konstruktor paraméterre. A Kotlin alapértelmezetten nem teszi ezt, de most már reprodukálhatod a viselkedést az `@all:` használati hely céllal. Például:

```
@JvmRecord
data class Person(val name: String, @all:Positive val age: Int)
```

Amikor `@JvmRecord`-ot használsz `@all:`-val, a Kotlin most:
- Propagálja az annotációt a tulajdonságra, támogató mezőre, konstruktor paraméterre és getterre
- Alkalmazza az annotációt a rekord komponensre is, ha az annotáció támogatja a Java `RECORD_COMPONENT`-et

## Kotlin/Native

A 2.2.0-tól kezdve a Kotlin/Native az LLVM 19-et használja. Ez a kiadás számos kísérleti funkciót is hoz, amelyek a memóriafelhasználás követésére és beállítására lettek tervezve.

### Objektumonkénti memóriafoglalás

A Kotlin/Native memóriafoglalója mostantól objektumonként tud memóriát lefoglalni. Bizonyos esetekben segíthet szigorú memóriakorlátok kielégítésében vagy csökkentheti az alkalmazás indítási memóriafelhasználását.

Az új funkció a `-Xallocator=std` fordítóopció lecserélésére lett tervezve, amely engedélyezte a rendszermemória-foglalót az alapértelmezett helyett. Mostantól letilthatod a pufferelést (az allokációk lapozását) anélkül, hogy memóriafoglalókat váltanál.

A funkció jelenleg Kísérleti. Az engedélyezéshez állítsd be a következő opciót a `gradle.properties` fájlban:

```
kotlin.native.binary.pagedAllocator=false
```

Kérjük, jelentsd a problémákat a hibabejelentő rendszerünkben.

### Latin-1 kódolású karakterláncok támogatása futásidőben

A Kotlin mostantól támogatja a Latin-1 kódolású karakterláncokat, hasonlóan a JVM-hez. Ez segíthet csökkenteni az alkalmazás bináris méretét és beállítani a memóriafelhasználást.

Alapértelmezetten a Kotlin karakterláncok UTF-16 kódolást használnak, ahol minden karakter két bájttal van reprezentálva. Néhány esetben ez azt eredményezi, hogy a karakterláncok kétszer akkora helyet foglalnak el a binárisban, mint a forráskódban, és egy egyszerű ASCII fájl olvasása kétszer annyi memóriát használ, mint a lemez tárolás.

Viszont a Latin-1 (ISO 8859-1) kódolás az első 256 Unicode karaktert egy bájttal reprezentálja. A Latin-1 támogatás engedélyezésével a karakterláncok Latin-1 kódolásban kerülnek tárolásra, amíg minden karakter a tartományon belül marad. Ellenkező esetben az alapértelmezett UTF-16 kódolás kerül alkalmazásra.

### Latin-1 támogatás engedélyezése

A funkció jelenleg Kísérleti. Az engedélyezéshez állítsd be a következő opciót a `gradle.properties` fájlban:

```
kotlin.native.binary.latin1Strings=true
```

### Ismert problémák

Amíg a funkció Kísérleti, a cinterop kiterjesztésfüggvények `String.pin`, `String.usePinned`, és `String.refTo` kevésbé hatékonyak lesznek. Minden hívásuk automatikus karakterlánc konverziót indíthat el UTF-16-ra.

A Kotlin csapat nagyon hálás kollégáinak a Google-nél és különösen Sonya Valchuknak a funkció megvalósításáért. A memóriafelhasználással kapcsolatos további információkért lásd a dokumentációt.

### Memóriafelhasználás követése Apple platformokon

A Kotlin 2.2.0-tól kezdve a Kotlin kóddal lefoglalt memória mostantól címkézett. Ez segíthet memóriaproblémák hibakeresésében Apple platformokon.

Amikor az alkalmazásod magas memóriafelhasználását vizsgálod, most már azonosíthatod, mennyi memóriát foglalt le a Kotlin kód. A Kotlin része egy azonosítóval van címkézve, és nyomon követhető olyan eszközökön keresztül, mint a VM Tracker az Xcode Instruments-ben.

Ez a funkció alapértelmezetten engedélyezett, de csak a Kotlin/Native alapértelmezett memóriafoglalóban érhető el, amikor az összes következő feltétel teljesül:
- Címkézés engedélyezve: A memóriát egy érvényes azonosítóval kell címkézni. Az Apple 240 és 255 közötti számokat javasol; az alapértelmezett érték 246. Ha beállítod a `kotlin.native.binary.mmapTag=0` Gradle tulajdonságot, a címkézés le van tiltva
- Allokáció mmap-pel: A foglalónak a mmap rendszerhívást kell használnia a fájlok memóriába történő leképezéséhez. Ha beállítod a `kotlin.native.binary.disableMmap=true` Gradle tulajdonságot, az alapértelmezett foglaló `malloc`-t használ `mmap` helyett
- Lapozás engedélyezve: Az allokációk lapozásának (pufferelés) engedélyezve kell lennie. Ha beállítod a `kotlin.native.binary.pagedAllocator=false` Gradle tulajdonságot, a memória objektumonként kerül lefoglalásra

A memóriafelhasználással kapcsolatos további információkért lásd a dokumentációt.

### LLVM frissítés 16-ról 19-re

A Kotlin 2.2.0-ban frissítettük az LLVM-et a 16-os verzióról a 19-esre. Az új verzió teljesítményjavításokat, hibajavításokat és biztonsági frissítéseket tartalmaz. Ez a frissítés nem befolyásolja a kódodat, de ha bármilyen problémába ütköznél, kérjük, jelentsd a hibabejelentő rendszerünket.

### Windows 7 cél elavult

A Kotlin 2.2.0-tól kezdve a minimálisan támogatott Windows verzió Windows 7-ről Windows 10-re lett emelve. Mivel a Microsoft 2025 januárjában befejezte a Windows 7 támogatását, úgy döntöttünk, hogy elavulttá tesszük ezt az örökölt célt.

További információkért lásd a Kotlin/Native cél támogatást.

## Kotlin/Wasm

Ez a kiadás elkülöníti a Wasm célhoz tartozó build infrastruktúrát a JavaScript céltól. Továbbá lehetőség van a Binaryen eszköz konfigurálására projekt vagy modul szinten.

### Wasm cél build infrastruktúra elkülönítve a JavaScript céltól

Korábban a `wasmJs` cél ugyanazt az infrastruktúrát osztotta meg, mint a `js` cél. Ennek eredményeként mindkét cél ugyanabban a könyvtárban (`build/js`) volt elhelyezve, és ugyanazokat az NPM feladatokat és konfigurációkat használta.

Mostantól a `wasmJs` cél saját infrastruktúrával rendelkezik, elkülönítve a `js` céltól. Ez lehetővé teszi a Wasm feladatok és típusok elkülönítését a JavaScripttől, független konfigurálás érdekében.

Továbbá a Wasm-hoz kapcsolódó projektfájlok és NPM függőségek mostantól külön `build/wasm` könyvtárban kerülnek tárolásra. Új NPM-kapcsolódó feladatok kerültek bevezetésre Wasm-hoz, miközben a meglévő JavaScript feladatok mostantól kizárólag a JavaScripthez vannak dedikálva:

#### Wasm feladatok | JavaScript feladatok

- `kotlinWasmNpmInstall` | `kotlinNpmInstall`
- `wasmRootPackageJson` | `rootPackageJson`

Hasonlóképpen új Wasm-specifikus deklarációk kerültek hozzáadásra:

#### Wasm deklarációk | JavaScript deklarációk

- `WasmNodeJsRootPlugin` | `NodeJsRootPlugin`
- `WasmNodeJsPlugin` | `NodeJsPlugin`
- `WasmYarnPlugin` | `YarnPlugin`
- `WasmNodeJsRootExtension` | `NodeJsRootExtension`
- `WasmNodeJsEnvSpec` | `NodeJsEnvSpec`
- `WasmYarnRootEnvSpec` | `YarnRootEnvSpec`

Mostantól a Wasm cél függetlenül dolgozhat a JavaScript céltól, ami leegyszerűsíti a konfigurációs folyamatot. Ez a változás alapértelmezetten engedélyezett és nem igényel további beállítást.

### Projekt szintű Binaryen konfiguráció

A Binaryen eszköz, amely Kotlin/Wasm-ben az éles build-ek optimalizálására szolgál, korábban egyszer lett konfigurálva a gyökérprojektben. Mostantól projekt vagy modul szinten is konfigurálható.

Ez a változás összhangban van a Gradle legjobb gyakorlataival, és jobb támogatást biztosít olyan funkciókhoz, mint a projekt izoláció, javítva a build teljesítményt és megbízhatóságot összetett build-eknél.

Továbbá mostantól különböző Binaryen verziókat is konfigurálhatsz különböző modulokhoz, ha szükséges.

Ez a funkció alapértelmezetten engedélyezett. Azonban ha egyéni konfigurációval rendelkezel a Binaryen eszközhöz, mostantól projekt szintenként kell alkalmaznod, nemcsak a gyökérprojektben.

## Kotlin/JS

Ez a kiadás javítja a `copy()` függvényt `@JsPlainObject` interfészekben, a típusálnév-eket `@JsModule` annotációval ellátott fájlokban és más Kotlin/JS funkciókat.

### Javítás a `copy()` függvényre `@JsPlainObject` interfészekben

A Kotlin/JS rendelkezik egy kísérleti `js-plain-objects` pluginnal, amely `copy()` függvényt vezetett be `@JsPlainObject` annotációval ellátott interfészekhez. A `copy()` függvény használható objektumok manipulálására. Azonban a `copy()` kezdeti implementációja nem volt kompatibilis az öröklődéssel, és ez problémákat okozott, amikor egy `@JsPlainObject` interfész más interfészeket örökölt.

Az egyszerű objektumok korlátozásainak elkerülése érdekében a `copy()` függvény az objektumról a kísérő objektumra került át:

```
@JsPlainObject
external interface User {
    val name: String
    val age: Int
}

fun main() {
    val user = User(name = "SomeUser", age = 21)
    // Ez a szintaxis már nem érvényes
    val copy = user.copy(age = 35)
    // Ez a helyes szintaxis
    val copy = User.copy(user, age = 35)
}
```

Ez a változás feloldja az öröklődési hierarchia ütközéseit és megszünteti az ambiguitást. Alapértelmezetten engedélyezve van a Kotlin 2.2.0-tól kezdve.

### Típusálnév támogatás `@JsModule` annotációval ellátott fájlokban

Korábban a JavaScript modulokból származó deklarációk importálásához `@JsModule` annotációval ellátott fájlok korlátozva voltak kizárólag külső deklarációkra. Ez azt jelentette, hogy nem lehetett típusálnév-eket deklarálni ilyen fájlokban.

A Kotlin 2.2.0-tól kezdve deklarálhatsz típusálnév-eket `@JsModule` annotációval ellátott fájlokban:

```
@file:JsModule("somepackage")
package somepackage

typealias SomeClass = Any
```

Ez a változás csökkenti a Kotlin/JS együttműködési korlátozásainak egy aspektusát, és további fejlesztések várhatók jövőbeli kiadásokban. A típusálnév támogatás `@JsModule`-ben alapértelmezetten engedélyezett.

### `@JsExport` támogatás multiplatform `expect` deklarációkban

Amikor a Kotlin Multiplatform projektekben a `expect`/`actual` mechanizmust dolgozod, nem volt lehetőség a `@JsExport` annotáció használatára a `expect` deklarációkhoz a közös kódban.

Ez a kiadás lehetővé teszi a `@JsExport` közvetlen alkalmazását `expect` deklarációkra:

```
// commonMain
// Korábban hibát okozott, de most helyesen működik
@JsExport
expect class WindowManager {
    fun close()
}

@JsExport
fun acceptWindowManager(manager: WindowManager) {
    ...
}

// jsMain
@JsExport
actual class WindowManager {
    fun close() {
        window.close()
    }
}
```

Meg kell annotálnod a megfelelő `actual` megvalósítást is `@JsExport` annotációval a JavaScript forráskészletben, és csak exportálható típusokat szabad használnia. Ez a javítás lehetővé teszi a `commonMain`-ben definiált megosztott kód helyes exportálását JavaScriptbe.

Mostantól elérhetővé teheted a multiplatform kódodat JavaScript fogyasztók számára anélkül, hogy kézi megoldásokat kellene használnod.

Ez a változás alapértelmezetten engedélyezett.

### `@JsExport` használata `Promise<Unit>` típussal

Korábban, amikor megpróbáltál `@JsExport` annotációval ellátott függvényt exportálni `Promise<Unit>` típussal visszatérési értékkel, a Kotlin fordító hibát generált. Míg a `Promise<Int>` típusú visszatérési értékek helyesen működtek, a `Promise<Unit>` használata "nem exportálható típus" figyelmeztetést váltott ki, még akkor is, ha helyesen képezte le TypeScript `Promise<void>` típusra.

Ez a korlátozás megszűnt. Most az alábbi kód hiba nélkül lefordul:

```
// Korábban helyesen működött
@JsExport
fun fooInt(): Promise<Int> = GlobalScope.promise {
    delay(100)
    return@promise 42
}

// Korábban hibát okozott, de most helyesen működik
@JsExport
fun fooUnit(): Promise<Unit> = GlobalScope.promise {
    delay(100)
}
```

Ez a változás megszüntet egy felesleges korlátozást a Kotlin/JS együttműködési modellben. Ez a javítás alapértelmezetten engedélyezett.

## Gradle

A Kotlin 2.2.0 teljes mértékben kompatibilis a Gradle 7.6.3-as verziótól a 8.14-es verzióig. Használhatsz Gradle verziókat egészen a legújabb Gradle kiadásig is. Ugyanakkor érdemes figyelembe venni, hogy ebben az esetben elavultsági figyelmeztetések jelenhetnek meg, és néhány új Gradle funkció nem biztos, hogy működni fog.

Ez a kiadás a Kotlin Gradle plugint számos diagnosztikai fejlesztéssel látta el. Bevezetett egy kísérleti integrációt a bináris kompatibilitás-ellenőrzéshez, megkönnyítve könyvtárak fejlesztését.

### Bináris kompatibilitás ellenőrzés a Kotlin Gradle pluginben

A könyvtári verziók közötti bináris kompatibilitás ellenőrzésének megkönnyítése érdekében kísérletezünk azzal, hogy a bináris kompatibilitás-ellenőrző funkcionalitását áthelyezzük a Kotlin Gradle pluginbe (KGP). Kísérletezhetsz vele játékprojektekben, de még nem javasoljuk gyártási környezetben való használatát. Az eredeti bináris kompatibilitás-ellenőrző a kísérleti fázis alatt továbbra is karban tartott.

A Kotlin könyvtárak kétféle bináris formátumot használhatnak: JVM osztályfájlokat vagy klib-eket. Mivel ezek a formátumok nem kompatibilisek egymással, a KGP külön kezeli őket.

A bináris kompatibilitás-ellenőrzési funkció beállításához add hozzá a következőt a `build.gradle.kts` fájlhoz a `kotlin{}` blokkban:

```
// build.gradle.kts
kotlin {
    @OptIn(org.jetbrains.kotlin.gradle.dsl.abi.ExperimentalAbiValidation::class)
    abiValidation {
        // Használd a set() függvényt a régebbi Gradle verziók kompatibilitásának biztosításához
        enabled.set(true)
    }
}
```

Ha a projektedben több modulban szeretnéd ellenőrizni a bináris kompatibilitást, konfiguráld a funkciót minden modulban külön. Minden modul saját egyéni konfigurációval rendelkezhet.

Az engedélyezés után futtasd a `checkLegacyAbi` Gradle feladatot a bináris kompatibilitási problémák ellenőrzéséhez. A feladatot futtathatod IntelliJ IDEA-ban vagy parancssorból a projekt könyvtárából:

```bash
./gradlew checkLegacyAbi
```

Ez a feladat egy UTF-8 szövegfájlként generál egy alkalmazás bináris interfész (ABI) kiírást az aktuális kódból. Ezután összehasonlítja az új kiírást az előző kiadásból származóval. Ha a feladat különbségeket talál, hibaként jelenti őket.

A hibák átnézése után, ha úgy döntesz, hogy a változások elfogadhatók, frissítheted a referenciaként szolgáló ABI kiírást az `updateLegacyAbi` Gradle feladat futtatásával.

#### Osztályok szűrése

A funkció lehetővé teszi az osztályok szűrését az ABI kiírásban. Kifejezetten név vagy névrészlet alapján tudod explicit módon tartalmazni vagy kizárni az osztályokat, vagy azokat az annotációkat (vagy az annotációk neveinek részeit) alapul véve, amelyekkel meg vannak jelölve.

Például ez a minta kizár minden osztályt a `com.company` csomagból:

```
// build.gradle.kts
kotlin {
    @OptIn(org.jetbrains.kotlin.gradle.dsl.abi.ExperimentalAbiValidation::class)
    abiValidation {
        filters.excluded.byNames.add("com.company.**")
    }
}
```

Fedezd fel a KGP API referenciát, hogy többet tudj meg a bináris kompatibilitás-ellenőrző konfigurálásáról.

#### Multiplatform korlátozások

Multiplatform projektekben, ha a géped nem támogatja az összes cél keresztkompilálását, a KGP megpróbálja kikövetkeztetni az ABI változásokat a nem támogatott céloknál más cél ABI kiírások alapján.

Ez a megközelítés segít elkerülni a hamis ellenőrzési hibákat, ha később olyan gépre váltasz, amely minden célt le tud fordítani.

Alapértelmezett viselkedést felülbírálhatod úgy, hogy a KGP ne következtessen ki ABI változásokat a nem támogatott céloknál, ha a következőt adod hozzá a `build.gradle.kts` fájlhoz:

```
// build.gradle.kts
kotlin {
    @OptIn(org.jetbrains.kotlin.gradle.dsl.abi.ExperimentalAbiValidation::class)
    abiValidation {
        klib {
            keepUnsupportedTargets = false
        }
    }
}
```

Azonban ha nem támogatott célod van a projektben, akkor a `checkLegacyAbi` feladat sikertelen lesz, mert a feladat nem tudja létrehozni az ABI kiírást. Ez a viselkedés akkor lehet kívánatos, ha fontosabb számodra, hogy az ellenőrzés meghiúsuljon, semmint hogy kimaradjon egy nem kompatibilis változás a más célból kikövetkeztetett ABI változások miatt.

### Rich output támogatás a konzolon a Kotlin Gradle plugin számára

A Kotlin 2.2.0-ban színes és más rich output támogatást vezettünk be a konzolon a Gradle build folyamat során, megkönnyítve az értelmezést és a diagnosztikák olvasását.

A rich output elérhető támogatott terminálemulátorokban Linuxon és macOS-en, és dolgozunk a Windows támogatás hozzáadásán.

#### Gradle konzol

Ez a funkció alapértelmezetten engedélyezett, de ha felül szeretnéd bírálni, add hozzá a következő Gradle tulajdonságot a `gradle.properties` fájlhoz:

```
org.gradle.console=plain
```

A tulajdonsággal és opcióival kapcsolatos további információkért lásd a Gradle dokumentációt a [napló formátum testreszabásáról](https://docs.gradle.org/current/userguide/command_line_interface.html#sec:command_line_customizing_log_format).

### Problems API integráció a KGP diagnosztikáiban

Korábban a Kotlin Gradle Plugin (KGP) csak sima szöveges kimenetként tudta jelenteni a figyelmeztetéseket és hibákat a konzolra vagy naplófájlokba.

A 2.2.0-tól kezdve a KGP bevezetett egy további jelentési mechanizmust: mostantól a Gradle Problems API-t használja, ami egy szabványosított módja a gazdag, strukturált problémainformációk jelentésének a build folyamat során.

A KGP diagnosztikái mostantól könnyebben olvashatók és konzisztensebben jelennek meg különböző interfészek között, mint például a Gradle CLI és az IntelliJ IDEA.

Ez az integráció alapértelmezetten engedélyezett, a Gradle 8.6 vagy újabb verzióitól kezdve. Mivel az API még mindig fejlődik, használj a lehető legújabb Gradle verziót, hogy élvezhesd a legújabb fejlesztéseket.

### KGP kompatibilitás a --warning-mode opcióval

A Kotlin Gradle Plugin (KGP) diagnosztikái fix súlyossági szintekkel jelentették a problémákat, ami azt jelentette, hogy a Gradle `--warning-mode` parancssori opciójának nem volt hatása arra, hogyan jelenítette meg a KGP a hibákat.

Mostantól a KGP diagnosztikái kompatibilisek a `--warning-mode` opcióval, több rugalmasságot biztosítva.

Például minden figyelmeztetést hibává alakíthatsz, vagy teljesen letilthatod a figyelmeztetéseket.

Ez a változás után a KGP diagnosztikái beállítják a kimenetet a kiválasztott figyelmeztetési mód alapján:
- Amikor beállítod `--warning-mode=fail`, a `Severity.Warning` diagnosztikái most `Severity.Error` szintre emelkednek
- Amikor beállítod `--warning-mode=none`, a `Severity.Warning` diagnosztikái nincsenek naplózva

Ez a viselkedés alapértelmezetten engedélyezett a 2.2.0-tól kezdve. A `--warning-mode` opció figyelmen kívül hagyásához állítsd be a következő Gradle tulajdonságot a `gradle.properties` fájlban:

```
kotlin.internal.diagnostics.ignoreWarningMode=true
```

### Új kísérleti build eszköz API

Különböző build rendszerekkel használhatod a Kotlin-t, mint például Gradle, Maven, Amper és mások. Azonban a Kotlin integrálása minden rendszerbe a teljes funkciókészlet támogatásához, mint például az inkrementális fordítás és a kompatibilitás a Kotlin fordító pluginokkal, démonokkal és Kotlin Multiplatformmal, jelentős erőfeszítést igényel.

A folyamat leegyszerűsítése érdekében a Kotlin 2.2.0 egy új kísérleti build eszköz API-t (BTA) vezet be.

A BTA egy univerzális API, amely absztrakciós rétegként működik a build rendszerek és a Kotlin fordító ökoszisztéma között. Ezzel a megközelítéssel minden build rendszer csak egyetlen BTA belépési pontot kell támogasson.

Jelenleg a BTA csak Kotlin/JVM-et támogat. A JetBrains Kotlin csapata már használja a Kotlin Gradle pluginban (KGP) és a `kotlin-maven-plugin`-ben.

A BTA-t kipróbálhatod ezeken a pluginokon keresztül, de maga az API még nem áll készen az általános használatra a saját build eszköz integrációidban.

Ha kíváncsi vagy a BTA javaslatra vagy visszajelzést szeretnél osztani, lásd ezt a [KEEP javaslatot](https://github.com/Kotlin/KEEP/blob/master/proposals/build-tools-api.md).

A BTA kipróbálásához:

#### KGP-ben

Add hozzá a következő tulajdonságot a `gradle.properties` fájlhoz:

```
kotlin.compiler.runViaBuildToolsApi=true
```

#### Maven-ben

Nem kell semmit csinálnod. Alapértelmezetten engedélyezett.



Qven: ```markdown
# Kotlin 2.2.0 változások

## Új kísérleti build eszköz API (folytatás)

A BTA jelenleg nincs közvetlen előnye a Maven plugin számára, de megalapoz egy gyorsabb új funkciók szállítását, mint például a Kotlin daemon támogatását és az inkrementális fordítás stabilizálását.

A KGP számára a BTA használata már a következő előnyöket nyújtja:
- Javított "folyamatban lévő" fordító végrehajtási stratégia
- Több rugalmasság a különböző fordító verziók konfigurálásában

### Javított "folyamatban lévő" fordító végrehajtási stratégia

A KGP három Kotlin fordító végrehajtási stratégiát támogat. Az "folyamatban lévő" stratégia, amely a fordítót a Gradle daemon folyamaton belül futtatja, korábban nem támogatta az inkrementális fordítást. Most a BTA használatával az "folyamatban lévő" stratégia már támogatja az inkrementális fordítást.

A használatához add hozzá a következő tulajdonságot a `gradle.properties` fájlhoz:

```
kotlin.compiler.execution.strategy=in-process
```

### Rugalmasság a különböző fordító verziók konfigurálásában

Néha érdemes lehet újabb Kotlin fordító verziót használni a kódodban miközben a KGP-t régebbi verzióra tartod – például új nyelvi funkciók kipróbálásához miközben még feldolgozod a build szkript elavultságokat. Vagy frissíteni szeretnéd a KGP verzióját de régebbi Kotlin fordító verziót szeretnél megtartani.

A BTA ezt lehetővé teszi. Így konfigurálhatod a `build.gradle.kts` fájlban:

```
// build.gradle.kts
import org.jetbrains.kotlin.buildtools.api.ExperimentalBuildToolsApi
import org.jetbrains.kotlin.gradle.ExperimentalKotlinGradlePluginApi

plugins {
    kotlin("jvm") version "2.2.0"
}

group = "org.jetbrains.example"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

kotlin {
    jvmToolchain(8)
    
    @OptIn(ExperimentalBuildToolsApi::class, ExperimentalKotlinGradlePluginApi::class)
    compilerVersion.set("2.1.21") // Különböző verzió, mint a 2.2.0
}
```

A BTA támogatja a KGP és Kotlin fordító verziók konfigurálását az előző három fő verzióval és egy következő fő verzióval. Tehát KGP 2.2.0 esetén a Kotlin fordító 2.1.x, 2.0.x és 1.9.25 verziók támogatottak. A KGP 2.2.0 kompatibilis a jövőbeli Kotlin fordító 2.2.x és 2.3.x verziókkal is.

Azonban tartsd észben, hogy különböző fordító verziók használata fordító pluginokkal együtt vezethet Kotlin fordító kivételekhez. A Kotlin csapat azt tervezi, hogy ezeket a problémákat jövőbeli kiadásokban orvosolja.

Próbáld ki a BTA-t ezekkel a pluginokkal és küldj nekünk visszajelzést a KGP és Maven plugin dedikált YouTrack jegyekben.

## Kotlin alapkönyvtár

A Kotlin 2.2.0-ban a Base64 API és a HexFormat API most már Stabil.

### Stabil Base64 kódolás és dekódolás

A Kotlin 1.8.20 bevezette a Base64 kódolás és dekódolás Kísérleti támogatását. A Kotlin 2.2.0-ban a Base64 API most már Stabil és négy kódolási sémát tartalmaz, az új Base64.Pem hozzáadva ebben a kiadásban:

- Base64.Default a standard Base64 kódolási sémát használja. A Base64.Default a Base64 osztály társobjektuma. Ennek eredményeként a függvényeit Base64.encode() és Base64.decode() helyett Base64.Default.encode() és Base64.Default.decode() hívhatod.
- Base64.UrlSafe az "URL és fájlnév biztonságos" kódolási sémát használja.
- Base64.Mime a MIME kódolási sémát használja, minden 76 karakter után sortörést szúr be kódolás közben és kihagyja az illegális karaktereket dekódolás közben.
- Base64.Pem adatokat kódol Base64.Mime szerint, de 64 karakteres sorkorlátozást alkalmaz.

A Base64 API használható bináris adatok Base64 karakterláncba kódolására és visszafejtésére bájtokká. Példa:

```
val foBytes = "fo".map { it.code.toByte() }.toByteArray()
Base64.Default.encode(foBytes) // "Zm8="
// Alternatívaként:
// Base64.encode(foBytes)

val foobarBytes = "foobar".map { it.code.toByte() }.toByteArray()
Base64.UrlSafe.encode(foobarBytes) // "Zm9vYmFy"

Base64.Default.decode("Zm8=") // foBytes
// Alternatívaként:
// Base64.decode("Zm8=")

Base64.UrlSafe.decode("Zm9vYmFy") // foobarBytes
```

JVM-en használd a .encodingWith() és .decodingWith() kiterjesztésfüggvényeket a Base64 kódoláshoz és dekódoláshoz bemeneti és kimeneti streamekkel:

```
import kotlin.io.encoding.*
import java.io.ByteArrayOutputStream

fun main() {
    val output = ByteArrayOutputStream()
    val base64Output = output.encodingWith(Base64.Default)
    base64Output.use { stream ->
        stream.write("Hello World!!".encodeToByteArray())
    }
    println(output.toString()) // SGVsbG8gV29ybGqhIq==
}
```

### Stabil hexadecimális elemzés és formázás a HexFormat API-val

A Kotlin 1.9.0-ban bevezetett HexFormat API most már Stabil. Használható numerikus értékek és hexadecimális karakterláncok közötti konverzióra. Például:

```
fun main() {
    println(93.toHexString()) //sampleEnd
}
```

További információkért lásd az új HexFormat osztályt hexadecimális formázáshoz és elemzéshez.

## Compose fordító

Ez a kiadás bevezeti a kompozíciós függvényreferenciák támogatását és változtatja több funkció alapértelmezett beállításait.

### @Composable függvényreferenciák támogatása

A Compose fordító támogatja a kompozíciós függvényreferenciák deklarálását és használatát a Kotlin 2.2.0 kiadástól kezdve:

```
val content: @Composable (String) -> Unit = ::Text

@Composable
fun App() {
    content("My App")
}
```

A kompozíciós függvényreferenciák kissé eltérően viselkednek a kompozíciós lambda objektumoktól futásidőben. Különösen a kompozíciós lambdák finomabb irányítást tesznek lehetővé az átugrás felett a ComposableLambda osztály kiterjesztésével. A függvényreferenciák a KCallable interfészt kell implementálják, így ugyanaz az optimalizáció nem alkalmazható rájuk.

### PausableComposition funkció alapértelmezetten engedélyezve

A PausableComposition funkció alapértelmezetten engedélyezve van a Kotlin 2.2.0-tól kezdve. Ez a jelző beállítja a Compose fordító kimenetét az újraindítható függvényekhez, lehetővé téve a futásidő számára az átugrási viselkedés kényszerítését és ezáltal hatékonyan szünetelteti a kompozíciót az egyes függvények átugrásával. Ez lehetővé teszi a nehéz kompozíciók felosztását keretek között, amit előtöltéshez használnak egy jövőbeli kiadásban.

A funkció letiltásához add hozzá a következőt a Gradle konfigurációhoz:

```
// build.gradle.kts
composeCompiler {
    featureFlag = setOf(ComposeFeatureFlag.PausableComposition.disabled())
}
```

### OptimizeNonSkippingGroups funkció alapértelmezetten engedélyezve

Az OptimizeNonSkippingGroups funkció alapértelmezetten engedélyezve van a Kotlin 2.2.0-tól kezdve. Ez az optimalizáció javítja a futásidejű teljesítményt az át nem ugró kompozíciós függvényekhez generált csoport hívások eltávolításával. Nem eredményezhet megfigyelhető viselkedésváltozást futásidőben. Ha problémákat tapasztalsz, érvényesítheted, hogy ez a változás okozza a problémát a funkció letiltásával. Kérjük, jelentsd a problémákat a Jetpack Compose hibabejelentő rendszerben.

Az OptimizeNonSkippingGroups jelző letiltásához add hozzá a következőt a Gradle konfigurációhoz:

```
composeCompiler {
    featureFlag = setOf(ComposeFeatureFlag.OptimizeNonSkippingGroups.disabled())
}
```

### Elavult funkciók

A StrongSkipping és IntrinsicRemember funkciók most már elavultak és egy jövőbeli kiadásban eltávolításra kerülnek. Ha bármilyen problémába ütközik ami miatt le kell tiltani ezeket a funkciókat, kérjük, jelentsd a Jetpack Compose hibabejelentő rendszerben.

## Szakítások és elavultak

Ez a szakasz kiemeli a fontos szakításokat és elavultakat, amelyeket érdemes megjegyezni. Lásd a Kompatibilitási útmutatót a kiadásban szereplő összes szakítás és elavult teljes áttekintéséhez.

A Kotlin 2.2.0-tól kezdve az Ant építőrendszer támogatása elavult. A Kotlin Ant támogatása már régóta nem aktív fejlesztés alatt áll, és nincs további karbantartási terv a viszonylag kis felhasználói bázis miatt. Az Ant támogatás eltávolításra kerül a 2.3.0-ban. Azonban a Kotlin továbbra is nyitva áll a hozzájárulásokra. Ha érdekel, hogy külső karbantartó lehess az Ant számára, hagyj megjegyzést a "jetbrains-team" láthatósági beállítással ebben a YouTrack problémában.

A Kotlin 2.2.0 megnöveli a kotlinOptions{} blokk elavultsági szintjét hibára. Használd a compilerOptions{} blokkot helyette. A build szkriptek frissítéséhez lásd a kotlinOptions{} compilerOptions{} áttelepítését.

A Kotlin szkriptelés továbbra is fontos része a Kotlin ökoszisztémának, de célzott használati esetekre koncentrálunk, mint például az egyéni szkriptelés, valamint a gradle.kts és main.kts szkriptek, jobb élmény érdekében. További információkért lásd a frissített blogbejegyzést.

Ennek eredményeként a Kotlin 2.2.0 elavulttá teszi a támogatást:

- REPL: A REPL kotlinc segítségével való további használatához engedélyezd a -Xrepl fordító opcióval.
- JSR-223: Mivel ez a JSR visszavonásra került, a JSR-223 implementáció továbbra is működik 1.9 nyelvi verzióval, de nem kerül át a K2 fordító használatára a jövőben.
- KotlinScriptMojo Maven plugin: Nem láttunk elég mozgalmat ezzel a pluginnel. Fordító figyelmeztetéseket fogsz látni, ha továbbra is használod.

A Kotlin 2.2.0-ban a setSource() függvény a KotlinCompileTool-ban most már lecseréli a konfigurált forrásokat a hozzáadásuk helyett. Ha forrásokat szeretnél hozzáadni a meglévők lecserélése nélkül, használd a source() függvényt.

A BaseKapt annotationProcessorOptionProviders típusa MutableList<Any>-ról MutableList<CommandLineArgumentProvider>-re változott. Ha a kódod jelenleg egy listát ad hozzá egyetlen elemként, használd az addAll() függvényt az add() függvény helyett.

A régi, örökölt Kotlin/JS backendben használt halott kód elimináció (DCE) eszköz elavultsága után a DCE-vel kapcsolatos fennmaradó DSL-ek most már eltávolításra kerültek a Kotlin Gradle pluginból:

- Az org.jetbrains.kotlin.gradle.dsl.KotlinJsDce interfész
- Az org.jetbrains.kotlin.gradle.targets.js.dsl.KotlinJsBrowserDsl.dceTask(body: Action<KotlinJsDce>) függvény
- Az org.jetbrains.kotlin.gradle.dsl.KotlinJsDceCompilerToolOptions interfész
- Az org.jetbrains.kotlin.gradle.dsl.KotlinJsDceOptions interfész

A jelenlegi JS IR fordító támogatja a DCE-t beépítve, és a @JsExport annotáció lehetővé teszi annak megadását, hogy mely Kotlin függvényeket és osztályokat tartsa meg a DCE során.

Az elavult kotlin-android-extensions plugin eltávolításra került a Kotlin 2.2.0-ban. Használd a kotlin-parcelize plugint a Parcelable implementáció generátorhoz és az Android Jetpack view kötéseit a szintetikus nézetekhez.

A kísérleti kotlinArtifacts API elavult a Kotlin 2.2.0-ban. Használd az aktuális DSL-t a Kotlin Gradle pluginban a végleges natív binárisok építéséhez. Ha ez nem elég az áttelepítéshez, hagyj megjegyzést ebben a YouTrack problémában.

A KotlinCompilation.source, amely a Kotlin 1.9.0-ban elavult, most már eltávolításra került a Kotlin Gradle pluginból.

A kísérleti közösítési módok paraméterei elavultak a Kotlin 2.2.0-ban. Töröld a közösítési gyorsítótárat az érvénytelen építési műtermékek törléséhez.

Az elavult konanVersion tulajdonság most már eltávolításra került a CInteropProcess feladatból. Használd a CInteropProcess.kotlinNativeVersion helyette.

Az elavult destinationDir tulajdonság használata most már hibát eredményez. Használd a CInteropProcess.destinationDirectory.set() helyette.

## Dokumentációs frissítések

Ez a kiadás észrevehető dokumentációs változásokat hoz, beleértve a Kotlin Multiplatform dokumentáció áttelepítését a KMP portálra. Ezen felül elindítottunk egy dokumentációs felmérést, új oldalakat és oktatóanyagokat hoztunk létre, és átdolgoztunk meglévőket.

### Kotlin dokumentációs felmérés

Őszinte visszajelzéseket keresünk a Kotlin dokumentáció javítása érdekében. A felmérés körülbelül 15 percet vesz igénybe, és a visszajelzésed segít alakítani a Kotlin dokumentumok jövőjét. Töltsd ki a felmérést itt.

### Új és átdolgozott oktatóanyagok

- Kotlin középhaladó túra – Emeld a Kotlin megértésedet a következő szintre. Tanuld meg, mikor használj kiterjesztésfüggvényeket, interfészeket, osztályokat és egyebeket.
- Készíts Kotlin alkalmazást Spring AI használatával – Tanuld meg, hogyan hozz létre Kotlin alkalmazást, amely kérdésekre válaszol OpenAI és vektoradatbázis használatával.
- Spring Boot projekt létrehozása Kotlin-nal – Tanuld meg, hogyan hozz létre Spring Boot projektet Gradle-lel az IntelliJ IDEA New Project varázslóján keresztül.
- Kotlin és C leképezés oktatóanyag sorozat – Tanuld meg, hogyan képeződnek le a különböző típusok és szerkezetek Kotlin és C között.
- Alkalmazás létrehozása C interop és libcurl használatával – Hozz létre egy egyszerű HTTP klienst, amely natívan fut a libcurl C könyvtár használatával.
- Kotlin Multiplatform könyvtár létrehozása – Tanuld meg, hogyan hozz létre és tegyél közzé multiplatform könyvtárat IntelliJ IDEA segítségével.
- Teljes verem alkalmazás építése Ktor és Kotlin Multiplatform használatával – Ez az oktatóanyag most IntelliJ IDEA-t használ a Fleet helyett, valamint Material 3-at és a Ktor és Kotlin legújabb verzióit.
- Helyi erőforrás-környezet kezelése a Compose Multiplatform alkalmazásban – Tanuld meg, hogyan kezeld az alkalmazás erőforrás-környezetét, mint például az alkalmazáson belüli téma és nyelv.

### Új és átdolgozott oldalak

- Kotlin AI áttekintés – Fedezd fel a Kotlin képességeit AI-alapú alkalmazások építéséhez.
- Dokka áttelepítési útmutató – Tanuld meg, hogyan telepíts át a Dokka Gradle plugin v2-es verziójára.
- Kotlin Metadata JVM könyvtár – Fedezz fel útmutatást a JVM-re fordított Kotlin osztályok metaadatainak olvasásához, módosításához és generálásához.
- CocoaPods integráció – Tanuld meg, hogyan állítsd be a környezetet, hogyan adj hozzá Pod függőségeket, vagy hogyan használj Kotlin projektet CocoaPod függőségként oktatóanyagok és mintaprojektek segítségével.

### Új oldalak a Compose Multiplatform számára az iOS stabil kiadás támogatásához:

- Navigáció és mélylinkelés különösen.
- Elrendezések megvalósítása Compose-ban.
- Karakterláncok honosítása és egyéb nemzetköziesítési oldalak, mint például az RTL nyelvek támogatása.
- Compose Hot Reload – Tanuld meg, hogyan használd a Compose Hot Reload-et az asztali céljaidhoz és hogyan add hozzá egy meglévő projekthez.

### Exposed migrációk

- Tanuld meg az Exposed által biztosított eszközöket az adatbázis séma változások kezeléséhez.

## Hogyan frissíts a Kotlin 2.2.0-ra

A Kotlin plugin elérhető csomagolt plugin formában az IntelliJ IDEA és Android Studio alkalmazásokban. A Kotlin új verzióra való frissítéséhez egyszerűen változtasd meg a Kotlin verziót a 2.2.0-ra a build szkriptjeidben.

## Újdonságok a Kotlin 2.1.20-ban

**Kiadás dátuma: 2025. március 20.**

A Kotlin 2.1.20 kiadás itt van! Főbb kiemelések:

### K2 fordító frissítések
- Frissítések az új kapt és Lombok pluginokhoz

### Kotlin Multiplatform
- Új DSL a Gradle Application plugin lecserélésére

### Kotlin/Native
- Xcode 16.3 támogatás és új beágyazási optimalizáció

### Kotlin/Wasm
- Alapértelmezett egyéni formázók, DWARF támogatás és áttelepítés a Provider API-hoz

### Gradle támogatás
- Kompatibilitás a Gradle izolált projektjeivel és egyéni kiadási változatokkal

### Alapkönyvtár
- Közös atomi típusok, javított UUID támogatás és új időkövetési funkcionalitás

### Compose fordító
- Laza korlátozások a @Composable függvényeknél és egyéb frissítések

### Dokumentáció
- Észrevehető fejlesztések a Kotlin dokumentációban

## IDE támogatás

A Kotlin 2.1.20-at támogató pluginok részei a legújabb IntelliJ IDEA-nak és Android Studio-nak. Nem kell frissítened a Kotlin plugin-t az IDE-ben. Mindössze annyit kell tenned, hogy megváltoztatod a Kotlin verziót a 2.1.20-ra a build szkriptjeidben. Részletekért lásd a Frissítés új kiadásra címet.

## Forráskódok letöltése OSGi támogatással rendelkező projektekben

A kotlin-osgi-bundle könyvtár összes függőségének forrásai most már beletartoznak a disztribúcióba. Ez lehetővé teszi az IntelliJ IDEA számára ezen források letöltését Kotlin szimbólumok dokumentációjának biztosításához és a hibakeresési élmény javításához.

## Kotlin K2 fordító

Folytatjuk a plugin támogatás fejlesztését az új Kotlin K2 fordítóhoz. Ez a kiadás frissítéseket hoz az új kapt és Lombok pluginokhoz.

### Új alapértelmezett kapt plugin

A Kotlin 2.1.20-tól kezdve a kapt fordító plugin K2 implementációja alapértelmezetten engedélyezett minden projekt számára. A JetBrains csapat elindította a kapt plugin új implementációját a K2 fordítóval a Kotlin 1.9.20-ban. Azóta tovább fejlesztettük a K2 kapt belső implementációját és hasonlóvá tettük a K1 verzió viselkedését, ugyanakkor jelentősen javítottuk a teljesítményét is.

Ha bármilyen problémába ütközhetsz a kapt használatakor a K2 fordítóval, ideiglenesen visszatérhetsz az előző plugin implementációhoz. Ehhez add hozzá a következő opciót a projekt gradle.properties fájljához:

```
kapt.use.k2=false
```

Kérjük, jelentsd a problémákat a hibabejelentő rendszerünkben.

### Lombok fordító plugin: @SuperBuilder támogatás és @Builder frissítések

A Kotlin Lombok fordító plugin most már támogatja a @SuperBuilder annotációt, megkönnyítve építők létrehozását osztályhierarchiákhoz. Korábban a Lombokot használó fejlesztőknek manuálisan kellett definiálniuk az építőket öröklődés esetén. A @SuperBuilder segítségével az építő automatikusan örökli a szülőosztály mezőit, lehetővé téve azok inicializálását objektum létrehozásakor.

Ezen felül ez a frissítés számos javítást és hibajavítást tartalmaz:

A @Builder annotáció most már működik konstruktorokon, rugalmasabb objektumkészítést lehetővé téve. Részletekért lásd a megfelelő YouTrack problémát.

A Kotlinban a Lombok kódgenerálással kapcsolatos számos probléma megoldásra került, javítva az általános kompatibilitást. Részletekért lásd a GitHub változásnaplót.

A @SuperBuilder annotációval kapcsolatos további információkért lásd a hivatalos Lombok dokumentációt.

## Kotlin Multiplatform: új DSL a Gradle Application plugin lecseréléséhez

A Gradle 8.7-től kezdve az Application plugin már nem kompatibilis a Kotlin Multiplatform Gradle pluginnal. A Kotlin 2.1.20 egy Kísérleti DSL-t vezet be hasonló funkcionalitás eléréséhez.

Az új executable {} blokk konfigurálja a végrehajtási feladatokat és Gradle disztribúciókat JVM céljainál. A build szkriptedben az executable {} blokk előtt add hozzá a következő @OptIn annotációt:

```
@OptIn(ExperimentalKotlinGradlePluginApi::class)
```

Például:

```
kotlin {
    jvm {
        @OptIn(ExperimentalKotlinGradlePluginApi::class)
        binaries {
            // Konfigurál egy "runJvm" nevű JavaExec feladatot és Gradle disztribúciót a "main" fordításhoz ebben a célban
            executable {
                mainClass.set("foo.MainKt")
            }
            // Konfigurál egy "runJvmAnother" nevű JavaExec feladatot és Gradle disztribúciót a "main" fordításhoz
            executable(KotlinCompilation.MAIN_COMPILATION_NAME, "another") {
                // Állíts be másik osztályt
                mainClass.set("foo.MainAnotherKt")
            }
            // Konfigurál egy "runJvmTest" nevű JavaExec feladatot és Gradle disztribúciót a "test" fordításhoz
            executable(KotlinCompilation.TEST_COMPILATION_NAME) {
                mainClass.set("foo.MainTestKt")
            }
            // Konfigurál egy "runJvmTestAnother" nevű JavaExec feladatot és Gradle disztribúciót a "test" fordításhoz
            executable(KotlinCompilation.TEST_COMPILATION_NAME, "another") {
                mainClass.set("foo.MainAnotherTestKt")
            }
        }
    }
}
```

Ebben a példában a Gradle Distribution plugin alkalmazva az első executable {} blokkon. Ha bármilyen problémába ütközhetsz, jelentsd a hibabejelentő rendszerünkben vagy értesíts minket a nyilvános Slack csatornánkon.

## Kotlin/Native

### Xcode 16.3 támogatás

A Kotlin 2.1.21-től kezdve a Kotlin/Native fordító támogatja az Xcode 16.3-at – az Xcode legújabb stabil verzióját. Nyugodtan frissítsd az Xcode-od és folytasd a munkádat Kotlin projektjeiden Apple operációs rendszerekhez.

A 2.1.21 kiadás szintén kijavítja a kapcsolódó cinterop problémát, amely fordítási hibákat okozott Kotlin Multiplatform projektjeinkben.

### Új beágyazási optimalizáció

A Kotlin 2.1.20 egy új beágyazási optimalizációs fázist vezet be, amely az aktuális kódgenerálási fázis előtt áll. Az új beágyazási fázis a Kotlin/Native fordítóban jobban teljesít, mint a szabványos LLVM beágyazó, és javítja a generált kód futásidejű teljesítményét.

Az új beágyazási fázis jelenleg Kísérleti. A kipróbálásához használd a következő fordító opciót:

```
-Xbinary=preCodegenInlineThreshold=40
```
Qven: ```markdown
# Kotlin 2.1.20 újdonságok

## Kísérleteink azt mutatják, hogy a küszöbérték 40 tokenre (a fordító által elemzett kódegységre) állítása ésszerű kompromisszumot biztosít a fordítás optimalizálásához. Benchmarkeink szerint ez összességében 9,5%-os teljesítményjavulást eredményez. Természetesen más értékeket is kipróbálhatsz. Ha megnövekedett bináris méretet vagy fordítási időt tapasztalsz, kérjük, jelentsd ezeket a problémákat a YouTrack segítségével.

## Kotlin/Wasm

Ez a kiadás javítja a Kotlin/Wasm hibakeresést és tulajdonságok használatát. Az egyéni formázók mostantól alapértelmezetten működnek a fejlesztési build-ekben, míg a DWARF hibakeresés lehetővé teszi a kód vizsgálatát. Ezen felül a Provider API leegyszerűsíti a tulajdonságok használatát Kotlin/Wasm és Kotlin/JS esetén.

### Egyéni formázók alapértelmezetten engedélyezve

Korábban manuálisan kellett konfigurálni az egyéni formázókat a webböngészőkben való hibakeresés javításához Kotlin/Wasm kód használatakor. Ebben a kiadásban az egyéni formázók alapértelmezetten engedélyezve vannak a fejlesztési build-ekben, így nincs szükség további Gradle konfigurációra.

A funkció használatához csak annyit kell tenned, hogy engedélyezed az egyéni formázókat a böngésződ fejlesztői eszközeiben:

Chrome DevTools esetén az egyéni formázók jelölőnégyzetét a Settings | Preferences | Console menüben találod:

Firefox DevTools esetén az egyéni formázók jelölőnégyzetét a Settings | Advanced settings menüben találod:

Ez a változás elsősorban a Kotlin/Wasm fejlesztési build-eket érinti. Ha speciális követelményeid vannak a termelési build-ekhez, akkor ennek megfelelően kell módosítani a Gradle konfigurációt. Ehhez add hozzá a következő fordító opciót a `wasmJs {}` blokkhoz:

```
// build.gradle.kts
kotlin {
    wasmJs {
        // ...
        compilerOptions {
            freeCompilerArgs.add("-Xwasm-debugger-custom-formatters")
        }
    }
}
```

### DWARF támogatás a Kotlin/Wasm kód hibakereséséhez

A Kotlin 2.1.20 bevezeti a DWARF (hibakeresés tetszőleges rekord formátummal) támogatását Kotlin/Wasm-ben. Ennek változtatásnak köszönhetően a Kotlin/Wasm fordító képes DWARF adatokat beágyazni a generált WebAssembly (Wasm) binárisba. Sok hibakereső és virtuális gép képes ezeket az adatokat olvasni a lefordított kódról betekintést nyújtani. A DWARF főként akkor hasznos a Kotlin/Wasm alkalmazások hibakereséséhez önálló Wasm virtuális gépek (VM-ek) belsejében. A funkció használatához a Wasm VM-nek és a hibakeresőnek is támogatnia kell a DWARF-ot. A DWARF támogatással lépésenként haladhatsz végig a Kotlin/Wasm alkalmazásokon, megvizsgálhatod a változókat és betekintést nyerhetsz a kódba. A funkció engedélyezéséhez használd a következő fordító opciót:

```
-Xwasm-generate-dwarf
```

### Áttelepítés a Provider API-hoz Kotlin/Wasm és Kotlin/JS tulajdonságokhoz

Korábban a Kotlin/Wasm és Kotlin/JS kiterjesztések tulajdonságai változtathatók voltak (`var`) és közvetlenül voltak hozzárendelve a build szkriptekben:

```
the<NodeJsExtension>().version = "2.0.0"
```

Mostantól a tulajdonságok a Provider API-n keresztül érhetők el, és az `.set()` függvény használatával kell értékeket rendelni:

```
the<NodeJsEnvSpec>().version.set("2.0.0")
```

A Provider API biztosítja, hogy az értékek lustán legyenek kiszámítva és megfelelően integrálódjanak a feladat függőségekkel, javítva a build teljesítményt. Ennek a változásnak köszönhetően a közvetlen tulajdonság hozzárendelések elavulttá váltak az *EnvSpec osztályok javára, mint például NodeJsEnvSpec és YarnRootEnvSpec. Ezen felül számos aliás feladat eltávolításra került a zavar elkerülése érdekében:

| Elavult feladat      | Csere                                                        |
| -------------------- | ------------------------------------------------------------ |
| wasmJsRun            | wasmJsBrowserDevelopmentRun                                  |
| wasmJsBrowserRun     | wasmJsBrowserDevelopmentRun                                  |
| wasmJsNodeRun        | wasmJsNodeDevelopmentRun                                     |
| wasmJsBrowserWebpack | wasmJsBrowserProductionWebpack vagy wasmJsBrowserDistribution |
| jsRun                | jsBrowserDevelopmentRun                                      |
| jsBrowserRun         | jsBrowserDevelopmentRun                                      |
| jsNodeRun            | jsNodeDevelopmentRun                                         |
| jsBrowserWebpack     | jsBrowserProductionWebpack vagy jsBrowserDistribution        |

Ha csak Kotlin/JS-t vagy Kotlin/Wasm-t használsz a build szkriptekben, akkor nincs szükség további teendőkre, mivel a Gradle automatikusan kezeli a hozzárendeléseket. Azonban ha egy plugin-t karbantartasz a Kotlin Gradle Plugin alapján, és a plugin nem alkalmazza a kotlin-dsl-t, akkor frissítened kell a tulajdonság hozzárendeléseket az `.set()` függvény használatára.

## Gradle

A Kotlin 2.1.20 teljes mértékben kompatibilis a Gradle 7.6.3-as verziótól a 8.11-es verzióig. Használhatsz Gradle verziókat egészen a legújabb Gradle kiadásig is. Ugyanakkor érdemes figyelembe venni, hogy ebben az esetben elavultsági figyelmeztetések jelenhetnek meg, és néhány új Gradle funkció nem biztos, hogy működni fog.

Ez a Kotlin verzió tartalmazza a Kotlin Gradle pluginok kompatibilitását a Gradle elszigetelt projektjeivel, valamint támogatja az egyéni Gradle kiadási változatokat.

### Kotlin Gradle pluginok kompatibilisek a Gradle elszigetelt projektjeivel

Ez a funkció jelenleg elő-alfa állapotban van a Gradle-ben. A JS és Wasm célok jelenleg nem támogatottak. Csak Gradle 8.10 vagy újabb verzióval használd, és kizárólag értékelési célokra.

A Kotlin 2.1.0 óta előnézetként elérhető a Gradle elszigetelt projektjeinek funkciója. Korábban konfigurálni kellett a Kotlin Gradle plugint, hogy a projekt kompatibilis legyen az elszigetelt projektek funkcióval, mielőtt kipróbálható lett volna. A Kotlin 2.1.20-ban ez a további lépés már nem szükséges. Mostantól az elszigetelt projektek funkció engedélyezéséhez csak a rendszertulajdonságot kell beállítani. A Gradle elszigetelt projektek funkciója támogatott a Kotlin Gradle pluginokban multiplatform projektek és csak JVM vagy Android célt tartalmazó projektek esetén is.

Konkrétan a multiplatform projektek esetén, ha problémákat tapasztalsz a Gradle build-del a frissítés után, akkor lemondhatsz az új Kotlin Gradle plugin viselkedésről a következő hozzáadásával:

```
kotlin.kmp.isolated-projects.support=disable
```

Azonban ha ezt a Gradle tulajdonságot használod a multiplatform projektben, akkor nem használhatod az elszigetelt projektek funkciót. Kérjük, oszd meg velünk tapasztalataidat erről a funkcióról a YouTrack-on.

### Egyéni Gradle kiadási változatok támogatása

A Kotlin 2.1.20 bevezeti az egyéni Gradle kiadási változatok támogatását. Ez a funkció elérhető multiplatform projektek és JVM célt megcélzó projektek számára. Ezzel a funkcióval nem módosíthatod a meglévő Gradle változatokat.

Ez a funkció Kísérleti. Az engedélyezéshez használd az `@OptIn(ExperimentalKotlinGradlePluginApi::class)` annotációt.

Az egyéni Gradle kiadási változat hozzáadásához hívd meg az `adhocSoftwareComponent()` függvényt, amely egy `AdhocComponentWithVariants` példányt ad vissza, amelyet konfigurálhatsz a Kotlin DSL-ben:

```
plugins {
    // Csak JVM és Multiplatform támogatott
    kotlin("jvm") // vagy kotlin("multiplatform")
}

kotlin {
    @OptIn(ExperimentalKotlinGradlePluginApi::class)
    publishing {
        // Egy AdhocSoftwareComponent példányt ad vissza
        adhocSoftwareComponent()
        // Alternatívaként konfigurálhatod az AdhocSoftwareComponent-ot a DSL blokkban a következőképpen
        adhocSoftwareComponent {
            // Add hozzá az egyéni változataidat az AdhocSoftwareComponent API használatával
        }
    }
}
```

A változatokkal kapcsolatos további információkért lásd a Gradle Egyéni kiadás testreszabási útmutatóját.

## Alapkönyvtár

Ez a kiadás új Kísérleti funkciókat hoz az alapkönyvtárba: közös atomi típusok, javított UUID támogatás és új időkövetési funkcionalitás.

### Közös atomi típusok

A Kotlin 2.1.20-ban bevezetjük a közös atomi típusokat az alapkönyvtár `kotlin.concurrent.atomics` csomagjában, lehetővé téve a szálbiztos műveletekhez szükséges megosztott, platformfüggetlen kód létrehozását. Ez leegyszerűsíti a Kotlin Multiplatform projektek fejlesztését az atomi függőséget igénylő logika duplikálásának eltávolításával a forráskészletek között.

A `kotlin.concurrent.atomics` csomag és tulajdonságai Kísérletiek. Az engedélyezéshez használd az `@OptIn(ExperimentalAtomicApi::class)` annotációt vagy a `-opt-in=kotlin.ExperimentalAtomicApi` fordító opciót.

Példa, amely bemutatja hogyan használhatod az `AtomicInt` típust biztonságosan több szálon feldolgozott elemek számolására:

```
// Importálja a szükséges könyvtárakat
import kotlin.concurrent.atomics.*
import kotlinx.coroutines.*

@OptIn(ExperimentalAtomicApi::class)
suspend fun main() {
    // Inicializálja az atomi számlálót a feldolgozott elemekhez
    var processedItems = AtomicInt(0)
    val totalItems = 100
    val items = List(totalItems) { "item$it" }
    
    // Szétválasztja az elemeket darabokra több korutin általi feldolgozáshoz
    val chunkSize = 20
    val itemChunks = items.chunked(chunkSize)
    
    coroutineScope {
        for (chunk in itemChunks) {
            launch {
                for (item in chunk) {
                    println("Processing $item in thread ${Thread.currentThread()}")
                    processedItems += 1 // Atomian növeli a számlálót
                }
            }
        }
    }
    
    // Kiírja a feldolgozott elemek teljes számát
    println("Total processed items: ${processedItems.load()}")
}
```

A Kotlin atomi típusok és a Java `java.util.concurrent.atomic` atomi típusok közötti zökkenőmentes együttműködés érdekében az API biztosítja az `.asJavaAtomic()` és `.asKotlinAtomic()` kiterjesztésfüggvényeket. JVM-en a Kotlin atomi típusok és a Java atomi típusok ugyanazok a típusok futásidőben, így a Java atomi típusokból Kotlin atomi típusokká és vissza történő átalakítás bármilyen felüljárás nélkül megvalósítható.

Példa, amely bemutatja hogyan működhetnek együtt a Kotlin és Java atomi típusok:

```
// Importálja a szükséges könyvtárakat
import kotlin.concurrent.atomics.*
import java.util.concurrent.atomic.*

@OptIn(ExperimentalAtomicApi::class)
fun main() {
    // Átalakítja a Kotlin AtomicInt típusát Java AtomicInteger típusra
    val kotlinAtomic = AtomicInt(42)
    val javaAtomic: AtomicInteger = kotlinAtomic.asJavaAtomic()
    println("Java atomic value: ${javaAtomic.get()}") // Java atomi érték: 42
    
    // Átalakítja a Java AtomicInteger típust vissza Kotlin AtomicInt típusra
    val kotlinAgain: AtomicInt = javaAtomic.asKotlinAtomic()
    println("Kotlin atomic value: ${kotlinAgain.load()}") // Kotlin atomi érték: 42
}
```

### Változások az UUID elemzésben, formázásban és összehasonlíthatóságban

A JetBrains csapat továbbra is javítja az alapkönyvtárban a 2.0.20-ban bevezetett UUID támogatást. Korábban a `parse()` függvény csak hexadecimális és kötőjellel formázott UUID-kat fogadott el. A Kotlin 2.1.20-tól kezdve a `parse()` függvényt használhatod mind a hexadecimális és kötőjellel, mind a sima hexadecimális (kötőjel nélküli) formátumokhoz is.

Ebben a kiadásban bevezettük a hexadecimális és kötőjellel formázott műveletekhez szükséges specifikus függvényeket is:

- `parseHexDash()` elemzi az UUID-kat hexadecimális és kötőjellel formátumból.
- `toHexDashString()` egy `Uuid` típust karakterlánccá alakít át hexadecimális és kötőjellel formátumban (tükrözve a `toString()` funkcionalitását).

Ezek a függvények hasonlóan működnek a korábban bevezetett `parseHex()` és `toHexString()` függvényekhez, amelyek a hexadecimális formátumhoz lettek bevezetve. Az elemzési és formázási funkcionalitás kifejezetten elnevezése javíthatja a kód világosságát és az általános UUID-kkal való élményt.

A Kotlinban az UUID-k mostantól Összehasonlíthatók. A Kotlin 2.1.20-tól kezdve közvetlenül összehasonlíthatod és rendezheted az `Uuid` típus értékeit. Ez lehetővé teszi a < és > operátorok használatát és azok standard könyvtár kiterjesztéseit, amelyek kizárólag az Összehasonlítható típusokhoz vagy azok gyűjteményeihez érhetők el (mint például `sorted()`), valamint lehetővé teszi az UUID-k átadását bármely függvénynek vagy API-nak, amely az Összehasonlítható interfészt igényli.

Ne feledd, hogy az alapkönyvtár UUID támogatása még mindig Kísérleti. Az engedélyezéshez használd az `@OptIn(ExperimentalUuidApi::class)` annotációt vagy a `-opt-in=kotlin.uuid.ExperimentalUuidApi` fordító opciót:

```
import kotlin.uuid.ExperimentalUuidApi
import kotlin.uuid.Uuid

@OptIn(ExperimentalUuidApi::class)
fun main() {
    // parse() elfogad egy UUID-t sima hexadecimális formátumban
    val uuid = Uuid.parse("550e8400e29b41d4a716446655440000")
    // Átalakítja hexadecimális és kötőjellel formátumba
    val hexDashFormat = uuid.toHexDashString()
    // Kiírja az UUID-t hexadecimális és kötőjellel formátumban
    println(hexDashFormat)
    // Kiírja az UUID-kat növekvő sorrendben
    println(
        listOf(
            uuid,
            Uuid.parse("780e8400e29b41d4a716446655440005"),
            Uuid.parse("5ab88400e29b41d4a716446655440076")
        ).sorted()
    )
}
```

### Új időkövetési funkcionalitás

A Kotlin 2.1.20-tól kezdve az alapkönyvtár képes egy időpontot reprezentálni. Ez a funkcionalitás korábban csak a kotlinx-datetime hivatalos Kotlin könyvtárban volt elérhető. A kotlinx.datetime.Clock interfész bekerült az alapkönyvtárba mint `kotlin.time.Clock` és a kotlinx.datetime.Instant osztály mint `kotlin.time.Instant`. Ezek a koncepciók természetesen illeszkednek az alapkönyvtár időcsomagjához, mivel csak az időpontokat érintik a bonyolultabb naptár és időzóna funkcionalitással szemben, amely a kotlinx-datetime-ben marad.

Az Instant és Clock hasznos, amikor pontos időkövetésre van szükség időzónákat vagy dátumokat figyelembe véve. Például használhatod őket események időbélyeggel történő naplózására, két időpont közötti időtartam mérésére és a jelenlegi időpont megszerzésére rendszerfolyamatokhoz.

Az egyéb nyelvekkel való együttműködés érdekében további konverter függvények érhetők el:

- `.toKotlinInstant()` egy időértéket `kotlin.time.Instant` példánnyá alakít
- `.toJavaInstant()` a `kotlin.time.Instant` értéket `java.time.Instant` értékké alakítja
- `Instant.toJSDate()` a `kotlin.time.Instant` értéket JS Date osztály példányává alakítja. Ez az átalakítás nem pontos; a JS ezredmásodperces pontossággal reprezentálja a dátumokat, míg a Kotlin nanomásodperces felbontást tesz lehetővé.

Az alapkönyvtár új időfunkciói még mindig Kísérletiek. Az engedélyezéshez használd az `@OptIn(ExperimentalTime::class)` annotációt:

```
import kotlin.time.*

@OptIn(ExperimentalTime::class)
fun main() {
    // Megkapja a jelenlegi időpontot
    val currentInstant = Clock.System.now()
    println("Current time: $currentInstant")
    
    // Megkeresi két időpont közötti különbséget
    val pastInstant = Instant.parse("2023-01-01T00:00:00Z")
    val duration = currentInstant - pastInstant
    println("Time elapsed since 2023-01-01: $duration")
}
```

Az implementációval kapcsolatos további információkért lásd ezt a [KEEP javaslatot](https://github.com/Kotlin/KEEP/blob/master/proposals/instants-as-kotlin-time.md).

## Compose fordító

A 2.1.20-ban a Compose fordító enyhíti az előző kiadásokban bevezetett @Composable függvényekre vonatkozó korlátozásokat. Ezen felül a Compose fordító Gradle plugin alapértelmezetten tartalmazza a forrásinformációkat, összehangolva a viselkedést minden platformon az Androiddal.

### Alapértelmezett értékkel rendelkező paraméterek támogatása nyitott @Composable függvényekben

A fordító korábban korlátozta az alapértelmezett értékkel rendelkező paramétereket a nyitott @Composable függvényekben a helytelen fordító kimenet miatt, amely futásidőben összeomlásokat eredményezett. Az alapvető probléma mostantól megoldódott, és az alapértelmezett értékkel rendelkező paraméterek teljes mértékben támogatottak a Kotlin 2.1.20 vagy újabb verzió használata esetén.

A Compose fordító támogatta az alapértelmezett értékkel rendelkező paramétereket a nyitott függvényekben az 1.5.8-as verzió előtt, így a támogatás projekt konfigurációtól függ:

- Ha egy nyitott összeállítható függvény a Kotlin 2.1.20 vagy újabb verzióval van lefordítva, a fordító helyes burkolókat generál az alapértelmezett értékkel rendelkező paraméterekhez. Ez magában foglalja az 1.5.8 előtti binárisokkal kompatibilis burkolókat is, ami azt jelenti, hogy az alsóbb szintű könyvtárak szintén képesek lesznek használni ezt a nyitott függvényt.
- Ha a nyitott összeállítható függvény a Kotlin 2.1.20 előtti verzióval van lefordítva, a Compose kompatibilitási módot használ, amely futásidőben összeomlásokat eredményezhet. A kompatibilitási mód használatakor a fordító figyelmeztetést bocsát ki a potenciális problémák kiemelésére.

### A végleges felülírt függvények újraindítása engedélyezett

A virtuális függvények (a nyitott és absztrakt felülírásai, beleértve az interfészeket) 2.1.0 kiadás óta kényszerítve lettek nem újraindíthatóvá. Ez a korlátozás mostantól enyhítve van azokra a függvényekre, amelyek végleges osztályok tagjai vagy maguk is véglegesek – ezek újraindulnak vagy átugrást szenvednek el a szokásos módon.

Egyes viselkedésváltozásokat tapasztalhatsz az érintett függvényekben a Kotlin 2.1.20-ra való frissítés után. Az előző verzió nem újraindítható logikájának kényszerítéséhez alkalmazd a `@NonRestartableComposable` annotációt a függvényre.

### ComposableSingletons eltávolítva a nyilvános API-ból

A ComposableSingletons egy olyan osztály, amelyet a Compose fordító hoz létre a @Composable lambdák optimalizálásakor. Azok a lambdák, amelyek nem ragadnak meg semmilyen paramétert, egyszer kerülnek létrehozásra és gyorsítótárazásra az osztály egy tulajdonságában, megtakarítva a futásidő alatt történő allokációkat. Az osztály internal láthatósággal kerül generálásra, és kizárólag a fordítási egységen belüli (általában egy fájlon belüli) lambdák optimalizálására szolgál. Azonban ez az optimalizáció az inline függvények törzsére is alkalmazva lett, ami azt eredményezte, hogy a szingletton lambda példányok kiszivárogtak a nyilvános API-ba. A probléma megoldása érdekében a 2.1.20-tól kezdve a @Composable lambdák többé nem optimalizálódnak szinglettonokká az inline függvények belsejében. Ugyanakkor a Compose fordító továbbra is generál szingletton osztályokat és lambdákat az inline függvények számára a korábbi modell szerint lefordított modulok bináris kompatibilitásának támogatása érdekében.

### Forrásinformáció alapértelmezetten tartalmazva

A Compose fordító Gradle plugin már alapértelmezetten tartalmazza a forrásinformációkat Androidon. A Kotlin 2.1.20-tól kezdve ez a funkció alapértelmezetten engedélyezve lesz minden platformon. Ne felejtsd el ellenőrizni, hogy ezt az opciót freeCompilerArgs segítségével állítod-e be. Ez a módszer a build sikertelenségét okozhatja, ha a pluginnal együtt használod, mivel egy opció kétszer kerül beállításra.

## Szakítások és elavultságok

A Kotlin Multiplatform összehangolása érdekében a jövőbeli Gradle változásokkal, a `withJava()` függvény fokozatosan kiiktatásra kerül. A Java forráskészletek mostantól alapértelmezetten létrejönnek. Ha a Java teszt fixture Gradle plugint használod, frissíts közvetlenül a Kotlin 2.1.21-re a kompatibilitási problémák elkerülése érdekében. A JetBrains csapat folytatja a `kotlin-android-extensions` plugin elavulttá tételét. Ha megpróbálod használni a projektben, most konfigurációs hibát kapsz, és egyetlen plugin kód sem lesz végrehajtva. A régi `kotlin.incremental.classpath.snapshot.enabled` tulajdonság eltávolításra került a Kotlin Gradle pluginból. A tulajdonság korábban lehetőséget biztosított az ABI pillanatkép beépített használatára a JVM-en. A plugin most más módszereket használ az észszerűtlen újrafordítások észlelésére és elkerülésére, így a tulajdonság elavulttá vált.

## Dokumentációs frissítések

A Kotlin dokumentáció számos észrevehető változást kapott:

### Átdolgozott és új oldalak

- Kotlin útiterv – lásd a frissített listát a Kotlin prioritásairól a nyelvi és ökoszisztéma fejlődés terén.
- Gradle legjobb gyakorlatok oldal – tanuld meg az alapvető legjobb gyakorlatokat a Gradle build-ek optimalizálásához és teljesítmény javításához.
- Compose Multiplatform és Jetpack Compose – áttekintés a két UI keretrendszer közötti kapcsolatról.
- Kotlin Multiplatform és Flutter – lásd a két népszerű keresztplatformos keretrendszer összehasonlítását.
- Együttműködés C-vel – fedezd fel a Kotlin C-vel való együttműködés részleteit.
- Számok – tanuld meg a különböző Kotlin típusokat a számok reprezentálásához.

### Új és frissített oktatóanyagok

- Könyvtárad közzététele a Maven Central-ba – tanuld meg, hogyan tedd közzé a KMP könyvtár műtermékeket a legnépszerűbb Maven tárolóban.
- Kotlin/Native dinamikus könyvtárként – hozz létre egy dinamikus Kotlin könyvtárat.
- Kotlin/Native Apple keretrendszerként – hozd létre a saját keretrendszered és használd a Kotlin/Native kódot Swift/Objective-C alkalmazásokban macOS-en és iOS-en.

## Hogyan frissíts a Kotlin 2.1.20-ra

Az IntelliJ IDEA 2023.3-tól és az Android Studio Iguana (2023.2.1) Canary 15-től kezdve a Kotlin plugin csomagolt plugin formában kerül terjesztésre az IDE-dbe. Ez azt jelenti, hogy többé nem telepítheted a plugin-t a JetBrains Marketplace-ről. Az új Kotlin verzióra való frissítéshez egyszerűen változtasd meg a Kotlin verziót a 2.1.20-ra a build szkriptjeidben.

## Újdonságok a Kotlin 2.1.0-ban

**Kiadás dátuma: 2024. november 27.**

A Kotlin 2.1.0 kiadás itt van! Főbb kiemelések:

Qven: Qven: ```markdown
# Kotlin 2.1.0 változások

## Új nyelvi funkciók előnézetben

- Védett feltételek `when` kifejezésekben alany esetén
- Nem helyi `break` és `continue`
- Több dolláros szöveg interpoláció

## K2 fordító frissítések

- Több rugalmasság a fordítóellenőrzések körül
- Javítások a `kapt` implementációban

## Kotlin Multiplatform

- Bevezetésre került az alapvető támogatás a Swift exportáláshoz
- Stabil Gradle DSL a fordító opciókhoz
- További fejlesztések

## Kotlin/Native

- Javított támogatás `iosArm64` és egyéb frissítések

## Kotlin/Wasm

- Több frissítés, beleértve az inkrementális fordítás támogatását

## Gradle támogatás

- Javított kompatibilitás a Gradle és Android Gradle plugin újabb verzióival
- Frissítések a Kotlin Gradle plugin API-ban

## Dokumentáció

- Jelentős fejlesztések a Kotlin dokumentációban

## IDE támogatás

A Kotlin 2.1.0-t támogató pluginok részei a legújabb IntelliJ IDEA-nak és Android Studio-nak. Nem kell frissítened a Kotlin plugin-t az IDE-ben. Mindössze annyit kell tenned, hogy megváltoztatod a Kotlin verziót a 2.1.0-ra a build szkriptjeidben. Részletekért lásd a Frissítés új Kotlin verzióra címet.

## Nyelv

A Kotlin 2.0.0 kiadás után, a K2 fordítóval, a JetBrains csapat a nyelv fejlesztésére koncentrál új funkciókkal. Ebben a kiadásban izgatottan jelentjük be számos új nyelvi tervezési fejlesztést. Ezek a funkciók előnézetben érhetők el, és örömmel fogadjuk visszajelzésedet:

- Védett feltételek `when` kifejezésekben alany esetén
- Nem helyi `break` és `continue`
- Több dolláros interpoláció: javított kezelés a `$` karakterre szövegliterálokban

Minden funkció támogatva van az IDE-ben a legújabb 2024.3-as IntelliJ IDEA verzióban, K2 mód engedélyezve. További információk az IntelliJ IDEA 2024.3 blogbejegyzésben.

Lásd a teljes listát a Kotlin nyelvi tervezési funkciókról és javaslatokról.

Ez a kiadás a következő nyelvi frissítéseket is tartalmazza:

- Támogatás opt-in követelményhez API-k kiterjesztéséhez
- Javított túlterhelés feloldás generikus típusokat használó függvények esetén
- Javított teljességi ellenőrzések `when` kifejezések esetén zárt osztályokhoz

## Védett feltételek `when` kifejezésekben alany esetén

Ez a funkció **Előnézetben** van, és opt-in szükséges (lásd részletek alább). Örömmel fogadjuk visszajelzésedet a YouTrack-ben.

A 2.1.0-tól kezdve használhatsz védett feltételeket `when` kifejezésekben vagy utasításokban alanyokkal. A védett feltételek lehetővé teszik több feltétel használatát a `when` kifejezés ágaihoz, így a komplex vezérlési folyamatokat kifejezőbbé és tömörebbé teszi, valamint lapítja a kódstruktúrát.

Az ágban való védett feltétel hozzáadásához helyezd el azt az elsődleges feltétel után, `if` segítségével elválasztva:

```
sealed interface Animal {
    data class Cat(val mouseHunter: Boolean) : Animal {
        fun feedCat() {}
    }
    data class Dog(val breed: String) : Animal {
        fun feedDog() {}
    }
}

fun feedAnimal(animal: Animal) {
    when (animal) {
        // Ág csak az elsődleges feltétellel. `feedDog()` hívása, amikor `animal` `Dog`
        is Animal.Dog -> animal.feedDog()
        // Ág az elsődleges és védett feltételekkel. `feedCat()` hívása, amikor `animal` `Cat` és nem `mouseHunter`
        is Animal.Cat if !animal.mouseHunter -> animal.feedCat()
        // "Unknown animal" kiírása, ha egyik fenti feltétel sem teljesül
        else -> println("Unknown animal")
    }
}
```

Egyetlen `when` kifejezésben kombinálhatsz ágakat védett feltételekkel és anélkül. A védett feltétellel rendelkező ágban lévő kód csak akkor fut le, ha mind az elsődleges, mind a védett feltétel igaz. Ha az elsődleges feltétel nem teljesül, a védett feltétel nem kerül kiértékelésre. Ezen felül a védett feltételek támogatják az `else if` szerkezetet.

A védett feltételek engedélyezéséhez használd a következő fordító opciót parancssorban:

```
kotlinc -Xwhen-guards main.kt
```

Vagy add hozzá a `compilerOptions {}` blokkhoz a Gradle build fájlban:

```
// build.gradle.kts
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xwhen-guards")
    }
}
```

## Nem helyi `break` és `continue`

Ez a funkció **Előnézetben** van, és opt-in szükséges (lásd részletek alább). Örömmel fogadjuk visszajelzésedet a YouTrack-ben.

A Kotlin 2.1.0 egy másik régóta várt funkció előnézetét vezeti be, a nem helyi `break` és `continue` használatának lehetőségét. Ez a funkció bővíti az eszköztárat, amelyet inline függvények hatókörében használhatsz, valamint csökkenti a boilerplate kódot a projektben.

Korábban csak nem helyi return használata volt lehetséges. Most a Kotlin támogatja a `break` és `continue` ugró kifejezések nem helyi alkalmazását is. Ez azt jelenti, hogy alkalmazhatod őket a lambda kifejezéseken belül, amelyeket paraméterként adtál át egy inline függvénynek, amely magába foglalja a ciklust:

```
fun processList(elements: List<Int>): Boolean {
    for (element in elements) {
        val variable = element.nullableMethod() ?: run {
            log.warning("Element is null or invalid, continuing...")
            continue
        }
        if (variable == 0) return true // Ha a variable 0, térjen vissza true értékkel
    }
    return false
}
```

A funkció kipróbálásához használd a `-Xnon-local-break-continue` fordító opciót parancssorban:

```
kotlinc -Xnon-local-break-continue main.kt
```

Vagy add hozzá a `compilerOptions {}` blokkhoz a Gradle build fájlban:

```
// build.gradle.kts
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xnon-local-break-continue")
    }
}
```

A funkció Stabilizálását tervezünk a jövőbeli Kotlin kiadásokban. Ha problémákat tapasztalsz a nem helyi `break` és `continue` használatakor, kérjük jelezd a hibabejelentő rendszerünkben.

## Több dolláros szöveg interpoláció

Ez a funkció **Előnézetben** van, és opt-in szükséges (lásd részletek alább). Örömmel fogadjuk visszajelzésedet a YouTrack-ben.

A Kotlin 2.1.0 bevezeti a több dolláros szöveg interpoláció támogatását, javítva a dollárjel (`$`) kezelését szövegliterálokban. Ez a funkció hasznos olyan környezetekben, ahol több dollárjel szükséges, például sablonmotorokban, JSON sémákban vagy más adatformátumokban.

A Kotlin szöveg interpoláció egyetlen dollárjelet használ. Azonban a szövegben szereplő literál dollárjel használata, amely gyakori pénzügyi adatokban és sablonrendszerekben, megoldást igényelt, például `${'$'}` használatát. A több dolláros interpolációs funkció engedélyezésével konfigurálhatod, hogy hány dollárjel váltson ki interpolációt, kevesebb dollárjellel szövegliterálként kezelve.

Példa JSON séma többsoros szöveg generálására helyőrzőkkel `$` használatával:

```
val KClass<*>.jsonSchema : String
    get() = $$"""
{
  "$$schema": "https://json-schema.org/draft/2020-12/schema",
  "$$id": "https://example.com/product.schema.json",
  "$$dynamicAnchor": "meta"
  "title": "$${simpleName ?: qualifiedName ?: "unknown"}",
  "type": "object"
}
"""
```

Ebben a példában a kezdeti `$$` azt jelenti, hogy két dollárjel (`$$`) szükséges az interpoláció kiváltásához. Ez megakadályozza, hogy `$schema`, `$id`, és `$dynamicAnchor` interpolációs jelzőként legyenek értelmezve. Ez a módszer különösen hasznos olyan rendszerekkel való munka során, amelyek dollárjeleket használnak helyőrző szintaxisban.

A funkció engedélyezéséhez használd a következő fordító opciót parancssorban:

```
kotlinc -Xmulti-dollar-interpolation main.kt
```

Alternatívaként frissítsd a `compilerOptions {}` blokkot a Gradle build fájlban:

```
// build.gradle.kts
kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xmulti-dollar-interpolation")
    }
}
```

Ha a kódod már használ szabványos szöveg interpolációt egyetlen dollárjellel, nem szükséges változtatás. Használhatod a `$$` jelet, amikor literál dollárjeleket szeretnél használni a szövegekben.

## Támogatás opt-in követelményhez API-k kiterjesztéséhez

A Kotlin 2.1.0 bevezeti a `@SubclassOptInRequired` annotációt, amely lehetővé teszi könyvtárszerzők számára az explicit opt-in követelményt, mielőtt a felhasználók implementálhatják a kísérleti interfészeket vagy kiterjeszthetik a kísérleti osztályokat.

Ez a funkció hasznos lehet, amikor egy könyvtár API elég stabil ahhoz, hogy használható legyen, de új absztrakt függvényekkel fejlődhet, így instabillá válik az öröklés szempontjából.

Az opt-in követelmény API elemhez való hozzáadásához használd a `@SubclassOptInRequired` annotációt egy hivatkozással az annotációs osztályra:

```
@RequiresOptIn(
    level = RequiresOptIn.Level.WARNING,
    message = "Interfaces in this library are experimental"
)
annotation class UnstableApi()

@SubclassOptInRequired(UnstableApi::class)
interface CoreLibraryApi
```

Ebben a példában a `CoreLibraryApi` interfész megköveteli a felhasználóktól az opt-in-t, mielőtt implementálhatják. A felhasználó az alábbi módon opt-in-olhat:

```
@OptIn(UnstableApi::class)
interface MyImplementation: CoreLibraryApi
```

Amikor a `@SubclassOptInRequired` annotációt használod az opt-in követelményhez, a követelmény nem terjed ki a belső vagy beágyazott osztályokra. Egy valós példát a `@SubclassOptInRequired` annotáció használatára az API-ban megtalálhatsz a kotlinx.coroutines könyvtár `SharedFlow` interfészében.

## Javított túlterhelés feloldás generikus típusokat használó függvények esetén

Korábban, ha több túlterhelésed volt egy függvényhez, ahol néhány értékparaméterei generikus típusúak voltak, míg mások függvénytípusok voltak ugyanabban a pozícióban, a feloldási viselkedés néha inkonzisztens lehetett. Ez különböző viselkedést eredményezett attól függően, hogy a túlterhelések tagfüggvények vagy kiterjesztésfüggvények voltak-e. Például:

```
class KeyValueStore<K, V> {
    fun store(key: K, value: V) {} // 1
    fun store(key: K, lazyValue: () -> V) {} // 2
}

fun <K, V> KeyValueStore<K, V>.storeExtension(key: K, value: V) {} // 1
fun <K, V> KeyValueStore<K, V>.storeExtension(key: K, lazyValue: () -> V) {} // 2

fun test(kvs: KeyValueStore<String, Int>) {
    // Tagfüggvények
    kvs.store("", 1) // Feloldódik 1-re
    kvs.store("") { 1 } // Feloldódik 2-re
    
    // Kiterjesztésfüggvények
    kvs.storeExtension("", 1) // Feloldódik 1-re
    kvs.storeExtension("") { 1 } // Nem oldódik fel
}
```

Ebben a példában a `KeyValueStore` osztálynak két túlterhelése van a `store()` függvényhez, ahol az egyik túlterhelés függvényparaméterekkel rendelkezik generikus típusokkal K és V, míg a másik lambda függvényt használ, amely generikus típusú V értéket ad vissza. Hasonlóképpen, két túlterhelés létezik a `storeExtension()` kiterjesztésfüggvény számára.

Amikor a `store()` függvényt lambda függvénnyel és anélkül hívták, a fordító sikeresen feloldotta a megfelelő túlterheléseket. Azonban amikor a `storeExtension()` kiterjesztésfüggvényt lambda függvénnyel hívták, a fordító nem oldotta fel a megfelelő túlterhelést, mert helytelenül mindkét túlterhelést alkalmazhatónak tartotta.

A probléma megoldására bevezettünk egy új heurisztikát, így a fordító el tud vetni egy lehetséges túlterhelést, amikor egy függvényparaméter generikus típusa nem tud elfogadni lambda függvényt egy másik argumentumból származó információ alapján. Ez a változás egységesíti a tagfüggvények és kiterjesztésfüggvények viselkedését, és alapértelmezetten engedélyezve van a Kotlin 2.1.0-ban.

## Javított teljességi ellenőrzések `when` kifejezések esetén zárt osztályokhoz

A Kotlin korábbi verzióiban a fordító `else` ágat követelt meg `when` kifejezéseknél típusparaméterek esetén zárt felső korlátokkal, még akkor is, amikor az összes eset a zárt osztályhierarchiában le volt fedve. Ez a viselkedés kezelve és javítva lett a Kotlin 2.1.0-ban, így a teljességi ellenőrzések hatékonyabbá váltak, lehetővé téve a redundáns `else` ágak eltávolítását, így a `when` kifejezések tisztábbak és intuitívabbak lettek.

Példa a változás bemutatására:

```
sealed class Result
object Error: Result()
class Success(val value: String): Result()

fun <T : Result> render(result: T) = when (result) {
    Error -> "Error!"
    is Success -> result.value // Nem szükséges else ág
}
```

## Kotlin K2 fordító

A Kotlin 2.1.0-val a K2 fordító most több rugalmasságot biztosít a fordítóellenőrzések és figyelmeztetések kezelésekor, valamint javított támogatást nyújt a kapt pluginhoz.

### Extra fordítóellenőrzések

A Kotlin 2.1.0 lehetővé tesz további ellenőrzéseket a K2 fordítóban. Ezek extra deklarációs, kifejezési és típusellenőrzések, amelyek általában nem kritikusak a fordításhoz, de hasznosak lehetnek bizonyos esetek validálásához:

| Ellenőrzés típusa                                   | Megjegyzés                                                   |
| --------------------------------------------------- | ------------------------------------------------------------ |
| REDUNDANT_NULLABLE                                  | Boolean?? használata Boolean? helyett                        |
| PLATFORM_CLASS_MAPPED_TO_KOTLIN                     | java.lang.String használata kotlin.String helyett            |
| ARRAY_EQUALITY_OPERATOR_CAN_BE_REPLACED_WITH_EQUALS | arrayOf("") == arrayOf("") használata arrayOf("").contentEquals(arrayOf("")) helyett |
| REDUNDANT_CALL_OF_CONVERSION_METHOD                 | 42.toInt() használata 42 helyett                             |
| USELESS_CALL_ON_NOT_NULL                            | "".orEmpty() használata "" helyett                           |
| REDUNDANT_SINGLE_EXPRESSION_STRING_TEMPLATE         | "$string" használata string helyett                          |
| UNUSED_ANONYMOUS_PARAMETER                          | Paraméter átadva a lambda kifejezésben, de soha nem használják |
| REDUNDANT_VISIBILITY_MODIFIER                       | public class Klass használata class Klass helyett            |
| REDUNDANT_MODALITY_MODIFIER                         | final class Klass használata class Klass helyett             |
| REDUNDANT_SETTER_PARAMETER_TYPE                     | set(value: Int) használata set(value) helyett                |
| CAN_BE_VAL                                          | var local = 0 definiálva, de soha nem rendelik hozzá újra, lehetne val local = 42 |
| ASSIGNED_VALUE_IS_NEVER_READ                        | val local = 42 definiálva, de soha nem használják később a kódban |
| UNUSED_VARIABLE                                     | val local = 0 definiálva, de soha nem használják a kódban    |
| REDUNDANT_RETURN_UNIT_TYPE                          | fun foo(): Unit {} használata fun foo() {} helyett           |
| UNREACHABLE_CODE                                    | Kódutasítás jelen van, de soha nem hajtható végre            |

Ha az ellenőrzés igaz, fordítófigyelmeztetést kapsz javaslattal a probléma javításához. Az extra ellenőrzések alapértelmezetten le vannak tiltva. Az engedélyezéshez használd a `-Wextra` fordító opciót parancssorban vagy add meg az `extraWarnings` beállítást a `compilerOptions {}` blokkban a Gradle build fájlban:

```
// build.gradle.kts
kotlin {
    compilerOptions {
        extraWarnings.set(true)
    }
}
```

További információk a fordító opciók definíciójáról és használatáról: Fordító opciók a Kotlin Gradle pluginban.

### Globális figyelmeztetés elnyomás

A 2.1.0-ban a Kotlin fordító kapott egy régóta kívánt funkciót – a figyelmeztetések globális elnyomásának lehetőségét. Mostantól elnyomhatsz specifikus figyelmeztetéseket az egész projektben a `-Xsuppress-warning=WARNING_NAME` szintaxis használatával parancssorban vagy a `freeCompilerArgs` attribútummal a build fájl `compilerOptions {}` blokkjában.

Például, ha extra fordítóellenőrzéseket engedélyeztél a projektben, de szeretnél elnyomni egyet közülük, használd:

```
// build.gradle.kts
kotlin {
    compilerOptions {
        extraWarnings.set(true)
        freeCompilerArgs.add("-Xsuppress-warning=CAN_BE_VAL")
    }
}
```

Ha szeretnél elnyomni egy figyelmeztetést, de nem tudod annak nevét, válaszd ki az elemet és kattints a villanykörte ikonra (vagy használd a Cmd + Enter/Alt + Enter billentyűket):

A figyelmeztetés neve megjelenik a szándékolt javaslatban.

Az új fordító opció jelenleg **Kísérleti**. Az alábbi részletek is fontosak:

- Hibaelnyomás nem engedélyezett
- Ha ismeretlen figyelmeztetés nevet adsz meg, a fordítás hibával zárul
- Több figyelmeztetést egyszerre is megadhatsz:

Parancssorban:
```
kotlinc -Xsuppress-warning=NOTHING_TO_INLINE -Xsuppress-warning=NO_TAIL_CALLS_FOUND main.kt
```

Build fájlban:
```
// build.gradle.kts
kotlin {
    compilerOptions {
        freeCompilerArgs.addAll(
            listOf(
                "-Xsuppress-warning=NOTHING_TO_INLINE",
                "-Xsuppress-warning=NO_TAIL_CALLS_FOUND"
            )
        )
    }
}
```

### Javított K2 kapt implementáció

A K2 fordító kapt pluginja (K2 kapt) **Alfában** van. Bármikor változhat. Örömmel fogadjuk visszajelzésedet a YouTrack-ben.

Jelenleg a kapt plugint használó projektek alapértelmezetten a K1 fordítóval működnek, támogatva a Kotlin 1.9-es verzióig terjedő verziókat. A Kotlin 1.9.20-ban elindítottunk egy kísérleti implementációt a kapt pluginról a K2 fordítóval (K2 kapt). Most javítottuk a K2 kapt belső implementációját, hogy enyhítsük a technikai és teljesítményproblémákat.

Míg az új K2 kapt implementáció nem vezet be új funkciókat, teljesítménye jelentősen javult az előző K2 kapt implementációhoz képest. Ezen felül a K2 kapt plugin viselkedése most sokkal közelebb került a K1 kapt viselkedéséhez.

Az új K2 kapt plugin implementáció használatához engedélyezd ugyanúgy, mint az előző K2 kapt plugint. Add hozzá a következő opciót a projekt `gradle.properties` fájljához:

```
kapt.use.k2=true
```

A következő kiadásokban a K2 kapt implementáció alapértelmezetten lesz engedélyezve a K1 kapt helyett, így manuálisan nem kell majd engedélyezni. Nagyon örülnénk a visszajelzésednek mielőtt az új implementáció stabilizálódna.

### Feloldás túlterhelés ütközések esetén előjel nélküli és nem primitív típusok között

Ez a kiadás kezeli a túlterhelés ütközések feloldásával kapcsolatos problémát, amely előfordulhatott korábbi verziókban, amikor függvények túlterhelve lettek előjel nélküli és nem primitív típusok esetén, mint például a következő példákban:

#### Túlterhelt kiterjesztésfüggvények

```
fun Any.doStuff() = "Any"
fun UByte.doStuff() = "UByte"

fun main() {
    val uByte: UByte = UByte.MIN_VALUE
    uByte.doStuff() // Túlterhelés feloldási ambiguitás a Kotlin 2.1.0 előtt
}
```

Korábbi verziókban az `uByte.doStuff()` hívás ambiguitást eredményezett, mert mind az `Any` és `UByte` kiterjesztések alkalmazhatók voltak.

#### Túlterhelt legfelső szintű függvények

```
fun doStuff(value: Any) = "Any"
fun doStuff(value: UByte) = "UByte"

fun main() {
    val uByte: UByte = UByte.MIN_VALUE
    doStuff(uByte) // Túlterhelés feloldási ambiguitás a Kotlin 2.1.0 előtt
}
```

Hasonlóképpen a `doStuff(uByte)` hívás ambiguitás volt, mert a fordító nem tudta eldönteni, hogy az `Any` vagy `UByte` verziót használja-e.

A 2.1.0-val a fordító most helyesen kezeli ezeket az eseteket, feloldva az ambiguitást a specifikusabb típus előnyben részesítésével, ebben az esetben `UByte`.

## Kotlin/JVM

A 2.1.0 verziótól kezdve a fordító képes osztályokat generálni, amelyek Java 23 bájtkódot tartalmaznak.

### JSpecify nullabilitás eltérés diagnosztizálás súlyosságának változása szigorúra

A Kotlin 2.1.0 kikényszeríti a nullabilitás annotációk szigorú kezelését az `org.jspecify.annotations` csomagból, javítva a típusbiztonságot a Java interoperabilitás szempontjából. Az alábbi nullabilitás annotációk érintettek:

- `org.jspecify.annotations.Nullable`
- `org.jspecify.annotations.NonNull`
- `org.jspecify.annotations.NullMarked`

A régi annotációk az `org.jspecify.nullness` csomagban (JSpecify 0.2 és korábbi)

A Kotlin 2.1.0-tól kezdve a nullabilitás eltérések figyelmeztetésekről hibákra változtak alapértelmezetten. Ez biztosítja, hogy annotációk, mint például `@NonNull` és `@Nullable` érvényesüljenek a típusellenőrzéseknél, megelőzve a váratlan nullabilitás problémákat futásidőben.

A `@NullMarked` annotáció szintén befolyásolja az összes tag nullabilitását a hatókörében, így a viselkedés kiszámíthatóbbá válik, amikor annotált Java kóddal dolgozol.

Példa az új alapértelmezett viselkedés bemutatására:

```
// Java
import *;
public class SomeJavaClass {
    @NonNull
    public String foo() {
        //...
    }
    
    @Nullable
    public String bar() {
        //...
    }
}

// Kotlin
fun test(sjc: SomeJavaClass) {
    // Hozzáfér egy nem null értékhez, ami engedélyezett
    sjc.foo().length
    
    // Hibát emel a szigorú alapértelmezett módban, mert az eredmény nullázható
    // A hiba elkerüléséhez használd a ?.length helyette
    sjc.bar().length
}
```

Manuálisan vezérelheted ezeknek az annotációknak a diagnosztizálásának súlyosságát. Ehhez használd az `-Xnullability-annotations` fordító opciót mód kiválasztásához:

- `ignore`: Figyelmen kívül hagyja a nullabilitás eltéréseket
- `warning`: Figyelmeztetéseket jelent a nullabilitás eltérésekről
- `strict`: Hibákat jelent a nullabilitás eltérésekről (alapértelmezett mód)

További információkért lásd a Nullabilitás annotációkat.

## Kotlin Multiplatform

A Kotlin 2.1.0 bevezeti az alapvető támogatást a Swift exportáláshoz és megkönnyíti a Kotlin Multiplatform könyvtárak közzétételét. Ezen felül a Gradle köré épülő fejlesztésekre koncentrál, stabilizálva az új DSL-t a fordító opciók konfigurálásához és előnézetet biztosítva az Elszigetelt Projektek funkcióhoz.

### Új Gradle DSL a fordító opciókhoz multiplatform projektekben előléptetve Stabilra

A Kotlin 2.0.0-ban bevezettünk egy új **Kísérleti** Gradle DSL-t a fordító opciók konfigurálásának egyszerűsítésére a multiplatform projektjeid között. A Kotlin 2.1.0-ban ez a DSL **Stabil** lett.

Az általános projekt konfigurációnak most három rétege van. A legmagasabb az extension szint, aztán a cél szint, és a legalacsonyabb a fordítási egység (amely általában egy fordítási feladat):

Qven: Qven: ```markdown
# Kotlin 2.1.0 folytatás

## Kotlin Multiplatform (folytatás)

### Fordító opciók szintjei a Gradle-ben

A Kotlin fordító opcióknak három konfigurációs szintje van:
1. **Extension szint** - a legmagasabb szint, minden célra érvényes
2. **Cél szint** - egy adott célra (pl. `iosX64()`) vonatkozik
3. **Fordítási egység szint** - a legalacsonyabb szint, például egy adott fordítási feladatra vonatkozik

További információkért lásd a [Fordító opciók](https://kotlinlang.org/docs/gradle-compiler-options.html) dokumentációt.

### Gradle elszigetelt projektek előnézete Kotlin Multiplatformban

Ez a funkció **Kísérleti** és jelenleg elő-alfa állapotban van a Gradle-ben. Csak Gradle 8.10 verzióval használd, és kizárólag értékelési célokra. A funkció bármikor eldobható vagy megváltozhat. Örömmel fogadjuk visszajelzésedet a YouTrack-ben. Opt-in szükséges (lásd részletek alább).

A Kotlin 2.1.0-ban előnézeted lehet a Gradle elszigetelt projektek funkcióját multiplatform projektjeidben. A Gradle elszigetelt projektek funkciója javítja a build teljesítményt az egyes Gradle projektek konfigurációjának "elszigetelésével" egymástól. Minden projekt build logikája korlátozva van más projektek változó állapotának közvetlen elérésében, lehetővé téve számukra a biztonságos párhuzamos futást.

A funkció támogatásához változtatásokat hajtottunk végre a Kotlin Gradle plugin modelljében, és érdeklődünk a tapasztalataidról ezen előnézeti fázis alatt.

Két módon engedélyezheted a Kotlin Gradle plugin új modelljét:

**1. lehetőség: Kompatibilitás tesztelése az elszigetelt projektek engedélyezése nélkül**

- A Kotlin Gradle plugin új modelljének kompatibilitásának ellenőrzéséhez az elszigetelt projektek funkció engedélyezése nélkül, add hozzá a következő Gradle tulajdonságot a projekt `gradle.properties` fájljához:

```
# gradle.properties
kotlin.kmp.isolated-projects.support=enable
```

**2. lehetőség: Tesztelés az elszigetelt projektek engedélyezésével**
- A Gradle elszigetelt projektek funkciójának engedélyezése automatikusan konfigurálja a Kotlin Gradle plugint az új modell használatára. Az elszigetelt projektek funkció engedélyezéséhez állítsd be a rendszertulajdonságot. Ebben az esetben nem kell hozzáadni a Gradle tulajdonságot a Kotlin Gradle pluginhoz a projektedben.

### Alapvető Swift export támogatás

Ez a funkció jelenleg a fejlesztés korai szakaszában van. Bármikor eldobható vagy megváltozhat. Opt-in szükséges (lásd részletek alább), és csak értékelési célokra használd. Örömmel fogadjuk visszajelzésedet a YouTrack-ben.

A 2.1.0 verzió az első lépés a Swift export támogatás felé a Kotlinban, lehetővé téve a Kotlin források közvetlen exportálását a Swift interfészbe Objective-C fejlécek használata nélkül. Ez megkönnyíti a multiplatform fejlesztést az Apple célokhoz.

A jelenlegi alapvető támogatás magában foglalja:
- Több Gradle modul exportálását Kotlinból közvetlenül Swiftbe
- Egyéni Swift modulnevek definiálását a `moduleName` tulajdonsággal
- Csomagstruktúra összecsukási szabályainak beállítását a `flattenPackage` tulajdonsággal

A következő build fájlt használhatod kiindulásként a Swift export beállításához:

```
// build.gradle.kts
kotlin {
    iosX64()
    iosArm64()
    iosSimulatorArm64()
    
    @OptIn(ExperimentalSwiftExportDsl::class)
    swiftExport {
        // Gyökér modulnév
        moduleName = "Shared"
        
        // Összecsukási szabály
        // Eltávolítja a csomag előtagot a generált Swift kódból
        flattenPackage = "com.example.sandbox"
        
        // Külső modulok exportálása
        export(project(":subproject")) {
            // Exportált modulnév
            moduleName = "Subproject"
            // Exportált függőség összecsukási szabálya
            flattenPackage = "com.subproject.library"
        }
    }
}
```

Klónozhatsz egy nyilvános mintát is, ahol a Swift export már be van állítva. A fordító automatikusan generálja az összes szükséges fájlt (beleértve a `swiftmodule` fájlokat, statikus `a` könyvtárat, fejléc és `modulemap` fájlokat) és átmásolja őket az alkalmazás build könyvtárába, amelyhez hozzáférhetsz az Xcode-ból.

### Swift export engedélyezése

Ne feledd, hogy a funkció jelenleg csak a fejlesztés korai szakaszában van. A Swift export jelenleg olyan projektekben működik, amelyek közvetlen integrációt használnak az iOS keretrendszer Xcode projekthez való csatlakoztatásához. Ez a standard konfiguráció a Kotlin Multiplatform projektekhez, amelyeket Android Studioban vagy a web varázsló segítségével hoztak létre.

A Swift export kipróbálásához a projektben:

1. Add hozzá a következő Gradle opciót a `gradle.properties` fájlhoz:

```
# gradle.properties
kotlin.experimental.swift-export.enabled=true
```

2. Az Xcode-ban nyisd meg a projekt beállításokat.

3. A Build Phases fülön keresd meg a Run Script fázist az `embedAndSignAppleFrameworkForXcode` feladattal.

4. Állítsd be a szkriptet, hogy az `embedSwiftExportForXcode` feladatot használja a run script fázisban:

```bash
./gradlew :<Shared module name>:embedSwiftExportForXcode
```

### Visszajelzés a Swift exportról

A jövőbeli Kotlin kiadásokban tervezzük a Swift export támogatás bővítését és stabilizálását. Kérjük, hagyj visszajelzést [ebben a YouTrack problémában](https://youtrack.jetbrains.com/issue/KT-XXXX).

### Kotlin könyvtárak közzététele bármely gépről

Ez a funkció jelenleg **Kísérleti**. Opt-in szükséges (lásd részletek alább), és csak értékelési célokra használd. Örömmel fogadjuk visszajelzésedet a YouTrack-ben.

A Kotlin fordító `.klib` műtermékeket hoz létre a Kotlin könyvtárak közzétételéhez. Korábban bármely gépről megkaphattad a szükséges műtermékeket, kivéve az Apple platform célokat, amelyek Mac gépet igényeltek. Ez korlátozást tett a Kotlin Multiplatform projektek számára, amelyek iOS, macOS, tvOS és watchOS célokat támogattak.

A Kotlin 2.1.0 eltávolítja ezt a korlátozást, támogatva a keresztfordítást. Most bármely gépen előállíthatod a `.klib` műtermékeket, ami jelentősen leegyszerűsíti a Kotlin és Kotlin Multiplatform könyvtárak közzétételének folyamatát.

### Könyvtárak közzététele bármely gépről - engedélyezés

A keresztfordítás kipróbálásához add hozzá a következő bináris opciót a `gradle.properties` fájlhoz:

```
# gradle.properties
kotlin.native.enableKlibsCrossCompilation=true
```

Ez a funkció jelenleg **Kísérleti** és bizonyos korlátozásokkal rendelkezik. Még mindig Mac gépet kell használnod, ha:

- A könyvtáradnak van `cinterop` függősége
- CocoaPods integrációd van beállítva a projektben
- Végleges binárisokat kell építeni vagy tesztelni az Apple célokhoz

### Visszajelzés a könyvtárak közzétételéről bármely gépről

A jövőbeli Kotlin kiadásokban tervezzük ennek a funkciónak a stabilizálását és a könyvtár közzététel további fejlesztését. Kérjük, hagyj visszajelzést a hibabejelentő rendszerünkben, YouTrack-ben.

További információkért lásd a [Multiplatform könyvtárak közzététele](https://kotlinlang.org/docs/multiplatform-publish-libraries.html) dokumentációt.

### Nem csomagolt klib támogatás

A Kotlin 2.1.0 lehetővé teszi a nem csomagolt `.klib` fájl műtermékek generálását. Ez lehetőséget ad a függőségek közvetlen konfigurálására a klib-ekre anélkül, hogy először kicsomagolnád őket. Ez a változás javíthatja a teljesítményt, csökkentve a fordítási és linkelési időt a Kotlin/Wasm, Kotlin/JS és Kotlin/Native projektekben.

Például a benchmark mutatja a teljes build idő körülbelül 3%-os javulását egy projektben 1 linkelési és 10 fordítási feladattal (a projekt egyetlen natív végrehajtható bináris építése 9 egyszerűsített projekttől függ).

Azonban a tényleges hatás a build időre attól függ, hogy hány alprojekt van és azok méreteitől.

### Projekt beállítása

Alapértelmezetten a Kotlin fordítási és linkelési feladatok mostantól úgy vannak konfigurálva, hogy az új nem csomagolt műtermékeket használják. Ha egyéni build logikát állítottál be a klib-ek feloldásához és az új kicsomagolatlan műtermékeket szeretnéd használni, akkor explicit módon meg kell adni a kívánt klib csomag feloldási változatot a Gradle build fájlban:

```
// build.gradle.kts
import org.jetbrains.kotlin.gradle.plugin.attributes.KlibPackaging

// ...
val resolvableConfiguration = configurations.resolvable("resolvable") {
    // Az új nem csomagolt konfigurációhoz:
    attributes.attribute(KlibPackaging.ATTRIBUTE, project.objects.named(KlibPackaging.NON_PACKED))
    
    // Az előző csomagolt konfigurációhoz:
    attributes.attribute(KlibPackaging.ATTRIBUTE, project.objects.named(KlibPackaging.PACKED))
}
```

A nem csomagolt `.klib` fájlok ugyanabban az elérési útban kerülnek generálásra a projekt build könyvtárában, mint korábban a csomagoltak. Ezután a csomagolt klib-ek a `build/libs` könyvtárban találhatók. Ha nincs megadva attribútum, akkor a csomagolt változat kerül felhasználásra.

Ellenőrizheted az elérhető attribútumok és változatok listáját a következő konzol parancs segítségével:

```bash
./gradlew outgoingVariants
```

Örömmel fogadjuk visszajelzésedet a YouTrack-ben erről a funkcióról.

### Régi android cél további elavulttá tétele

A Kotlin 2.1.0-ban az elavult figyelmeztetés az elavult android cél nevére hibára változott. Jelenleg azt javasoljuk, hogy az `androidTarget` opciót használd a Kotlin Multiplatform projektekben Android célokhoz.

Ez egy ideiglenes megoldás, amely szükséges ahhoz, hogy felszabadítsuk az `android` nevet a közelgő Android/KMP plugin számára a Google-től. További áttelepítési utasításokat biztosítunk, amikor az új plugin elérhető lesz.

Az új DSL a Google-től az előnyben részesített opció lesz az Android cél támogatásához a Kotlin Multiplatformban.

További információkért lásd a [Kotlin Multiplatform kompatibilitási útmutatót](https://kotlinlang.org/docs/compatibility-guide-21.html).

### Több azonos típusú cél deklarálásának támogatásának eldobása

A Kotlin 2.1.0 előtt több azonos típusú célt is deklarálhatsz a multiplatform projektjeidben. Azonban ez megnehezítette a célok megkülönböztetését és a megosztott forráskészletek hatékony támogatását.

A legtöbb esetben egy egyszerűbb beállítás, például különálló Gradle projektek használata jobban működik.

Részletes útmutatásért és példáért az áttelepítéshez lásd [Több hasonló cél deklarálása](https://kotlinlang.org/docs/compatibility-guide-21.html#multiple-targets-of-the-same-type) a Kotlin Multiplatform kompatibilitási útmutatóban.

A Kotlin 1.9.20 egy elavult figyelmeztetést váltott ki, ha több azonos típusú célt deklaráltál a multiplatform projektjeidben. A Kotlin 2.1.0-ban ez az elavult figyelmeztetés most már hiba minden célra, kivéve a Kotlin/JS célokat.

További információkért, hogy miért vannak mentesülve a Kotlin/JS célok, lásd [ezt a problémát a YouTrack-ben](https://youtrack.jetbrains.com/issue/KT-XXXX).

## Kotlin/Native

A Kotlin 2.1.0 frissítést hoz az `iosArm64` cél támogatásához, javított `cinterop` gyorsítótárazási folyamathoz és egyéb frissítésekhez.

### iosArm64 előléptetve Tier 1-re

Az `iosArm64` cél, amely kulcsfontosságú a Kotlin Multiplatform fejlesztéshez, Tier 1-re lett előléptetve. Ez a legmagasabb szintű támogatás a Kotlin/Native fordítóban. Ez azt jelenti, hogy a cél rendszeresen tesztelve van a CI folyamatban annak biztosítására, hogy képes legyen fordítani és futni. Emellett forrás és bináris kompatibilitást is biztosítunk a fordító kiadások között a cél számára.

További információkért lásd a [Kotlin/Native cél támogatás](https://kotlinlang.org/docs/native-target-support.html) dokumentációt.

### LLVM frissítés 11.1.0-ről 16.0.0-ra

A Kotlin 2.1.0-ban frissítettük az LLVM-et az 11.1.0 verzióról a 16.0.0-ra. Az új verzió hibajavításokat és biztonsági frissítéseket tartalmaz. Bizonyos esetekben fordító optimalizálásokat és gyorsabb fordítást is biztosít.

Ha Linux célok vannak a projektben, vedd figyelembe, hogy a Kotlin/Native fordító mostantól alapértelmezetten az `lld` linkert használja minden Linux célhoz. Ez a frissítés nem befolyásolja a kódodat, de ha bármilyen problémába ütköznél, kérjük jelezd a hibabejelentő rendszerünkben.

### Caching változások a cinterop-ban

A Kotlin 2.1.0-ban változtatásokat hajtunk végre a `cinterop` gyorsítótárazási folyamatában. Már nincs `CacheableTask` annotációtípusa. Az új ajánlott megközelítés a `cacheIf` kimenettípus használata a feladat eredményeinek gyorsítótárazásához. Ez megoldja azokat a problémákat, ahol az UP-TO-DATE ellenőrzések nem észlelték a fejlécfájlok változásait a definíciós fájlban megadottak szerint, megakadályozva a build rendszerét az újrafordításban.

### Mimalloc memória allokátor elavulttá tétele

A Kotlin 1.9.0-ban bevezettük az új memória allokátort, majd a Kotlin 1.9.20-ban engedélyeztük alapértelmezetten. Az új allokátor úgy lett tervezve, hogy hatékonyabbá tegye a szemétgyűjtést és javítsa a Kotlin/Native memória kezelő futásidejű teljesítményét. Az új memória allokátor lecserélte az előző alapértelmezett allokátort, a `mimalloc`-ot.

Most itt az ideje elavulttá tenni a `mimalloc`-ot a Kotlin/Native fordítóban. Most már eltávolíthatod a `-Xallocator=mimalloc` fordító opciót a build szkriptjeidből. Ha bármilyen problémába ütköznél, kérjük jelezd a hibabejelentő rendszerünkben.

További információkért a memória allokátorról és szemétgyűjtésről Kotlinban lásd a [Kotlin/Native memóriakezelés](https://kotlinlang.org/docs/native-memory-management.html) dokumentációt.

## Kotlin/Wasm

A Kotlin/Wasm több frissítést kapott az inkrementális fordítás támogatásával együtt.

### Inkrementális fordítás támogatás

Korábban, amikor változtattál valamit a Kotlin kódodban, a Kotlin/Wasm eszközláncnak újra kellett fordítania az egész kódbázist. A 2.1.0-tól kezdve az inkrementális fordítás támogatott a Wasm célokhoz.

Fejlesztési feladatokban a fordító mostantól csak az utolsó fordításhoz kapcsolódó változásokat érintő fájlokat fordítja újra, ami jelentősen csökkenti a fordítási időt.

Ez a változás jelenleg megkétszerezi a fordítási sebességet, és tervezzük további javítását a jövőbeli kiadásokban.

A jelenlegi beállításban a Wasm célok inkrementális fordítása alapértelmezetten le van tiltva. Az inkrementális fordítás engedélyezéséhez add hozzá a következő sort a projekt `local.properties` vagy `gradle.properties` fájljához:

```
# gradle.properties
kotlin.incremental.wasm=true
```

Próbáld ki a Kotlin/Wasm inkrementális fordítást és oszd meg velünk a visszajelzésedet. A betekintéseid segítenek ennek a funkciónak a stabilizálásában és alapértelmezett engedélyezésében.

### Böngésző API-k áthelyezve a kotlinx-browser önálló könyvtárba

Korábban a web API-k deklarációi és a kapcsolódó cél segédprogramok a Kotlin/Wasm alapkönyvtár részét képezték. Ebben a kiadásban az `org.w3c.*` deklarációk áthelyezésre kerültek a Kotlin/Wasm alapkönyvtárból az új `kotlinx-browser` könyvtárba.

Ez a könyvtár más webhez kapcsolódó csomagokat is tartalmaz, például `org.khronos.webgl`, `kotlin.dom`, és `kotlinx.browser`. Ez a szétválasztás modularitást biztosít, lehetővé téve a webhez kapcsolódó API-k független frissítését a Kotlin kiadási ciklusa kívül.

Ezen felül a Kotlin/Wasm alapkönyvtár mostantól csak azokat a deklarációkat tartalmazza, amelyek bármely JavaScript környezetben elérhetők.

A mozgatott csomagok deklarációinak használatához add hozzá a `kotlinx-browser` függőséget a projekt build konfigurációs fájljához:

```
// build.gradle.kts
val wasmJsMain by getting {
    dependencies {
        implementation("org.jetbrains.kotlinx:kotlinx-browser:0.3")
    }
}
```

### Javított hibakeresési élmény Kotlin/Wasm esetén

Korábban, amikor Kotlin/Wasm kódot debuggoltál webböngészőkben, alacsony szintű reprezentációt kaphattál a változó értékekről a hibakereső interfészben. Ez gyakran megnehezítette az alkalmazás aktuális állapotának követését.

A Kotlin/Wasm régi hibakereső

A felhasználói élmény javítása érdekében egyéni formázók kerültek hozzáadásra a változó nézetben. Az implementáció az egyéni formázók API-t használja, amely támogatott a főbb böngészőkben, mint például Firefox és Chromium-alapú böngészők.

Ezzel a változással most már felhasználóbarátabb és érthetőbb módon jelenítheted meg és keresheted meg a változó értékeket.

### Kotlin/Wasm javított hibakereső

Az új hibakeresési élmény kipróbálásához:

1. Add hozzá a következő fordító opciót a `wasmJs {}` fordító opciókhoz:

```
// build.gradle.kts
kotlin {
    wasmJs {
        // ...
        compilerOptions {
            freeCompilerArgs.add("-Xwasm-debugger-custom-formatters")
        }
    }
}
```

2. Engedélyezd az egyéni formázókat a böngésződben:

Chrome DevTools esetén ez elérhető a Settings | Preferences | Console menüpontban:

Firefox DevTools esetén ez elérhető a Settings | Advanced settings menüpontban:

### Kotlin/Wasm binárisok méretének csökkentése

A termelési build-ek által előállított Wasm binárisok mérete akár 30%-kal is csökkenthető, és némi teljesítményjavulást is láthatsz. Ennek oka, hogy a `--closed-world`, `--type-ssa`, és `--type-merging` Binaryen opciók mostantól biztonságosnak tekinthetők minden Kotlin/Wasm projekthez, és alapértelmezetten engedélyezve vannak.

### Javított JavaScript tömb interoperabilitás Kotlin/Wasm-ben

Míg a Kotlin/Wasm alapkönyvtár biztosítja a `JsArray<T>` típust a JavaScript tömbökhöz, korábban nem volt közvetlen módszer a `JsArray<T>` átalakítására a Kotlin natív `Array` vagy `List` típusokká. Ez az üres helyzet egyéni függvények létrehozását igényelte a tömb átalakításokhoz, bonyolítva a Kotlin és JavaScript kód közötti interoperabilitást.

Ez a kiadás egy adapter függvényt vezet be, amely automatikusan konvertálja a `JsArray<T>` típust `Array<T>` típuská és vissza, leegyszerűsítve a tömb műveleteket.

Példa generikus típusok közötti konverzióra:

Kotlin `List<T>` és `Array<T>` JavaScript `JsArray<T>` típusra:

```
val list: List<JsString> = listOf("Kotlin", "Wasm").map { it.toJsString() }
// Használja a .toJsArray() függvényt a List vagy Array JsArray-re konvertálásához
val jsArray: JsArray<JsString> = list.toJsArray()
// Használja a .toArray() és .toList() függvényeket visszakonvertálásra Kotlin típusokra
val kotlinArray: Array<JsString> = jsArray.toArray()
val kotlinList: List<JsString> = jsArray.toList()
```

Hasonló módszerek állnak rendelkezésre a típusos tömbök Kotlin megfelelőikre való konvertálásához (például `IntArray` és `Int32Array`).

Részletes információkért és implementációért lásd a [kotlinx-browser repository](https://github.com/Kotlin/kotlinx-browser)-t.

Példa típusos tömbök közötti konverzióra:

Kotlin `IntArray` JavaScript `Int32Array` típusra:

```
import org.khronos.webgl.*

// ...
val intArray: IntArray = intArrayOf(1, 2, 3)
// Használja a .toInt32Array() függvényt a Kotlin IntArray JavaScript Int32Array-re konvertálásához
val jsInt32Array: Int32Array = intArray.toInt32Array()
// Használja a .toIntArray() függvényt a JavaScript Int32Array visszakonvertálásához Kotlin IntArray-re
val kotlinIntArray: IntArray = jsInt32Array.toIntArray()
```

### JavaScript kivétel részletekhez való hozzáférés támogatása Kotlin/Wasm-ben

Korábban, amikor JavaScript kivétel történt Kotlin/Wasm-ben, a `JsException` típus csak általános üzenetet biztosított az eredeti JavaScript hibából származó részletek nélkül. A Kotlin 2.1.0-tól kezdve konfigurálhatod a `JsException` típust, hogy tartalmazza az eredeti hibaüzenetet és stack trace-t egy specifikus fordító opció engedélyezésével. Ez több kontextust biztosít a JavaScriptből származó problémák diagnosztizálásához.

Ez a viselkedés a WebAssembly.JSTag API-tól függ, amely csak bizonyos böngészőkben érhető el:

- Chrome: Támogatott a 115-ös verziótól
- Firefox: Támogatott a 129-es verziótól
- Safari: Még nem támogatott

A funkció engedélyezéséhez, amely alapértelmezetten le van tiltva, add hozzá a következő fordító opciót a `build.gradle.kts` fájlhoz:

```
// build.gradle.kts
kotlin {
    wasmJs {
        compilerOptions {
            freeCompilerArgs.add("-Xwasm-attach-js-exception")
        }
    }
}
```

Példa az új viselkedés bemutatására:

```
external object JSON {
    fun <T: JsAny> parse(json: String): T
}

fun main() {
    try {
        JSON.parse("an invalid JSON")
    } catch (e: JsException) {
        println("Thrown value is: ${e.thrownValue}") 
        // SyntaxError: Unexpected token 'a', "an invalid JSON" is not valid JSON
        println("Message: ${e.message}") 
        // Message: Unexpected token 'a', "an invalid JSON" is not valid JSON
        println("Stacktrace:") 
        // Stacktrace:
        // Kiírja a teljes JavaScript stack trace-t
        e.printStackTrace()
    }
}
```

Az `-Xwasm-attach-js-exception` opció engedélyezésével a `JsException` specifikus részleteket biztosít a JavaScript hibából. Az opció nélkül a `JsException` csak általános üzenetet tartalmaz, amely szerint kivétel dobódott JavaScript kód futtatása közben.

### Alapértelmezett exportálások elavulttá tétele

Az elnevezett exportálásokra való áttelepítés részeként korábban konzolra hibaüzenet került kiírásra, amikor alapértelmezett importot használtak a Kotlin/Wasm exportálásokhoz JavaScriptben. A 2.1.0-ban az alapértelmezett importok teljesen eltávolításra kerültek az elnevezett exportálások teljes támogatása érdekében.

Amikor JavaScript kódot írsz a Kotlin/Wasm célhoz, mostantól a megfelelő elnevezett importokat kell használnod az alapértelmezett importok helyett. Ez a változás az elnevezett exportálásokra való áttelepítés elavultsági ciklusának utolsó fázisa.

Qven: Qven: Qven: ```markdown
# Kotlin 2.1.0 változások (folytatás)

## Alapértelmezett exportálások elavulttá tétele (folytatás)

Verziók szerinti változások:
- **2.0.0 verzióban**: Figyelmeztető üzenet került kiírásra a konzolra, amely elmagyarázta, hogy az entitások alapértelmezett exportálása elavult
- **2.0.20 verzióban**: Hiba történt, amely a megfelelő elnevezett import használatát kérte
- **2.1.0 verzióban**: Az alapértelmezett importok használata teljesen eltávolításra került

## Alprojekt-specifikus Node.js beállítások

Konfigurálhatod a Node.js beállításokat a projektjeidhez a `NodeJsRootPlugin` osztály tulajdonságainak definiálásával a `rootProject` számára. A 2.1.0-ban ezeket a beállításokat minden alprojekthez konfigurálhatod egy új osztály, a `NodeJsPlugin` használatával.

Példa egy adott Node.js verzió beállítására egy alprojekt számára:

```
// build.gradle.kts
project.plugins.withType<org.jetbrains.kotlin.gradle.targets.js.nodejs.NodeJsPlugin> {
    project.the<org.jetbrains.kotlin.gradle.targets.js.nodejs.NodeJsEnvSpec>().version = "22.0.0"
}
```

Az új osztály használata az egész projekthez, add hozzá ugyanezt a kódot az `allprojects {}` blokkban:

```
// build.gradle.kts
allprojects {
    project.plugins.withType<org.jetbrains.kotlin.gradle.targets.js.nodejs.NodeJsPlugin> {
        project.the<org.jetbrains.kotlin.gradle.targets.js.nodejs.NodeJsEnvSpec>().version = "your Node.js version"
    }
}
```

Gradle konvenció pluginokat is használhatsz a beállítások alkalmazásához egy adott alprojektek halmazára.

## Kotlin/JS

### Nem azonosító karakterek támogatása tulajdonságokban

A Kotlin/JS korábban nem engedélyezte szóközöket tartalmazó nevek használatát tesztmetódusokhoz visszaapotok között. Hasonlóképpen nem volt lehetőség JavaScript objektum tulajdonságokhoz való hozzáférésre, amelyek olyan karaktereket tartalmaztak, amelyek nem engedélyezettek Kotlin azonosítókban, mint például kötőjelek vagy szóközök:

```
external interface Headers {
    var accept: String? // Érvénytelen Kotlin azonosító a kötőjel miatt
    var `content-length`: String?
}

val headers: Headers = TODO("value provided by a JS library")
val accept = headers.accept // Hibát okoz a kötőjel miatt a tulajdonságnévben
val length = headers.`content-length`
```

Ez a viselkedés eltért a JavaScript és TypeScript viselkedésétől, amelyek engedélyezték az ilyen tulajdonságokhoz való hozzáférést nem azonosító karakterek használatával. A Kotlin 2.1.0-tól kezdve ez a funkció alapértelmezetten engedélyezett.

A Kotlin/JS mostantól lehetővé teszi a visszaapotok (``) és a `@JsName` annotáció használatát JavaScript tulajdonságokhoz való hozzáféréshez, amelyek nem azonosító karaktereket tartalmaznak, valamint tesztmetódusok neveihez. Ezen felül használhatod a `@JsName` és `@JsQualifier` annotációkat a Kotlin tulajdonságnevek JavaScript megfelelőkhöz való leképezéséhez:

```
object Bar {
    val `property example`: String = "bar"
}

@JsQualifier("fooNamespace")
external object Foo {
    val `property example`: String
}

@JsExport
object Baz {
    val `property example`: String = "bar"
}

fun main() {
    // JavaScriptben ez Bar.property_example_HASH néven kerül lefordításra
    println(Bar.`property example`)
    
    // JavaScriptben ez fooNamespace["property example"] néven kerül lefordításra
    println(Foo.`property example`)
    
    // JavaScriptben ez Baz["property example"] néven kerül lefordításra
    println(Baz.`property example`)
}
```

### ES2015 nyíllambda függvények generálásának támogatása

A Kotlin 2.1.0-ban a Kotlin/JS bevezeti az ES2015 nyíllambda függvények generálásának támogatását, például `(a, b) => expression`, az anonim függvények helyett. A nyíllambda függvények használata csökkentheti a projekt csomagméretét, különösen a kísérleti `-Xir-generate-inline-anonymous-functions` mód használatakor. Ez szintén igazodik a modern JS-hez.

Ez a funkció alapértelmezetten engedélyezett ES2015 cél esetén. Alternatívaként engedélyezheted a `-Xes-arrow-functions` parancssori argumentum használatával.

További információk az ES2015-ről (ECMAScript 2015, ES6) a hivatalos dokumentációban.

## Gradle fejlesztések

A Kotlin 2.1.0 teljes mértékben kompatibilis a Gradle 7.6.3-as verziótól a 8.6-os verzióig. A 8.7-től 8.10-ig terjedő Gradle verziók is támogatottak, egy kivétellel. Ha a Kotlin Multiplatform Gradle plugint használod, akkor elavult figyelmeztetéseket láthatsz a multiplatform projektjeidben, amelyek a `withJava()` függvényt hívják a JVM célban. Tervezzük a probléma mielőbbi javítását. További információkért lásd a kapcsolódó problémát a YouTrack-ben.

A legújabb Gradle kiadásokat is használhatod, de ebben az esetben tartsd szem előtt, hogy elavultsági figyelmeztetésekkel találkozhatsz, vagy néhány új Gradle funkció nem működik.

### Minimálisan támogatott AGP verzió 7.3.1-re emelve

A Kotlin 2.1.0-tól kezdve a minimálisan támogatott Android Gradle plugin verzió 7.3.1.

### Minimálisan támogatott Gradle verzió 7.6.3-ra emelve

A Kotlin 2.1.0-tól kezdve a minimálisan támogatott Gradle verzió 7.6.3.

## Új API a Kotlin Gradle plugin kiterjesztésekhez

A Kotlin 2.1.0 bevezet egy új API-t, amely megkönnyíti saját pluginok létrehozását a Kotlin Gradle plugin konfigurálásához. Ez a változás elavulttá teszi a `KotlinTopLevelExtension` és `KotlinTopLevelExtensionConfig` interfészeket, és bevezeti a következő interfészeket a plugin szerzők számára:

| Név                      | Leírás                                                       |
| ------------------------ | ------------------------------------------------------------ |
| `KotlinBaseExtension`    | Plugin DSL kiterjesztés típus a közös Kotlin JVM, Android és Multiplatform plugin opciók konfigurálásához az egész projekt számára: `org.jetbrains.kotlin.jvm`, `org.jetbrains.kotlin.android`, `org.jetbrains.kotlin.multiplatform` |
| `KotlinJvmExtension`     | Plugin DSL kiterjesztés típus a Kotlin JVM plugin opciók konfigurálásához az egész projekt számára |
| `KotlinAndroidExtension` | Plugin DSL kiterjesztés típus a Kotlin Android plugin opciók konfigurálásához az egész projekt számára |

Például, ha JVM és Android projektek számára szeretnél konfigurálni fordító opciókat, használd a `KotlinBaseExtension`-t:

```
// build.gradle.kts
configure<KotlinBaseExtension> {
    if (this is HasConfigurableKotlinCompilerOptions<*>) {
        with(compilerOptions) {
            if (this is KotlinJvmCompilerOptions) {
                jvmTarget.set(JvmTarget.JVM_17)
            }
        }
    }
}
```

Ez a JVM célt 17-re konfigurálja mind a JVM, mind az Android projekteknél. A fordító opciók JVM projektekhez való konfigurálásához használd a `KotlinJvmExtension`-t:

```
configure<KotlinJvmExtension> {
    compilerOptions {
        jvmTarget.set(JvmTarget.JVM_17)
    }
    target.mavenPublication {
        groupId = "com.example"
        artifactId = "example-project"
        version = "1.0-SNAPSHOT"
    }
}
```

Ez a példa szintén a JVM célt 17-re konfigurálja a JVM projektek számára. Ezen felül konfigurál egy Maven kiadványt a projekthez, így annak kimenete egy Maven tárolóba kerül közzétételre. A `KotlinAndroidExtension`-t pontosan ugyanígy használhatod.

## Fordító szimbólumok elrejtve a Kotlin Gradle plugin API-ból

Korábban a KGP tartalmazta az `org.jetbrains.kotlin:kotlin-compiler-embeddable` függőséget futásidejű függőségként, így a belső fordító szimbólumok elérhetők voltak a build szkript osztályútvonalban. Ezek a szimbólumok kizárólag belső használatra szántak voltak. A Kotlin 2.1.0-tól kezdve a KGP csomagol egy részhalmazát az `org.jetbrains.kotlin:kotlin-compiler-embeddable` osztályfájloknak a JAR fájljában, és fokozatosan eltávolítja őket. Ez a változás célja a kompatibilitási problémák megelőzése és a KGP karbantartás egyszerűsítése.

Ha a build logikád más részei, például pluginok mint a kotlinter, eltérő verziójú `org.jetbrains.kotlin:kotlin-compiler-embeddable` függőséget használnak, mint amit a KGP csomagol, ez ütközéseket és futásidejű kivételeket okozhat. Az ilyen problémák megelőzése érdekében a KGP most figyelmeztetést jelenít meg, ha az `org.jetbrains.kotlin:kotlin-compiler-embeddable` jelen van a build osztályútvonalban a KGP mellett.

Hosszú távú megoldásként, ha plugin szerzőként használod az `org.jetbrains.kotlin:kotlin-compiler-embeddable` osztályokat, javasoljuk azokat elszigetelt osztálybetöltőben futtatni. Például elérheted ezt a Gradle Workers API használatával osztálybetöltő vagy folyamat elszigeteléssel.

### A Gradle Workers API használata

Ez a példa bemutatja, hogyan használhatod biztonságosan a Kotlin fordítót egy Gradle plugin előállító projektben.

Először adj hozzá egy csak fordítási függőséget a build szkriptedben. Ez csak fordítási időben teszi elérhetővé a szimbólumot:

```
// build.gradle.kts
dependencies {
    compileOnly("org.jetbrains.kotlin:kotlin-compiler-embeddable:2.2.20")
}
```

Ezután definiálj egy Gradle munkaműveletet a Kotlin fordító verzió kiírásához:

```
import org.gradle.workers.WorkAction
import org.gradle.workers.WorkParameters
import org.jetbrains.kotlin.config.KotlinCompilerVersion

abstract class ActionUsingKotlinCompiler : WorkAction<WorkParameters.None> {
    override fun execute() {
        println("Kotlin compiler version: ${KotlinCompilerVersion.getVersion()}")
    }
}
```

Most hozz létre egy feladatot, amely elküldi ezt a műveletet a munkavégrehajtónak osztálybetöltő elszigetelés használatával:

```
import org.gradle.api.DefaultTask
import org.gradle.api.file.ConfigurableFileCollection
import org.gradle.api.tasks.Classpath
import org.gradle.api.tasks.TaskAction
import org.gradle.workers.WorkerExecutor
import javax.inject.Inject

abstract class TaskUsingKotlinCompiler: DefaultTask() {
    @get:Inject
    abstract val executor: WorkerExecutor
    
    @get:Classpath
    abstract val kotlinCompiler: ConfigurableFileCollection
    
    @TaskAction
    fun compile() {
        val workqueue = executor.classLoaderIsolation {
            classpath.from(kotlinCompiler)
        }
        workqueue.submit(ActionUsingKotlinCompiler::class.java) {}
    }
}
```

Végül konfiguráld a Kotlin fordító osztályútvonalat a Gradle pluginodban:

```
import org.gradle.api.Plugin
import org.gradle.api.Project

abstract class MyPlugin: Plugin<Project> {
    override fun apply(target: Project) {
        val myDependencyScope = target.configurations.create("myDependencyScope")
        target.dependencies.add(
            myDependencyScope.name, 
            "$KOTLIN_COMPILER_EMBEDDABLE:$KOTLIN_COMPILER_VERSION"
        )
        
        val myResolvableConfiguration = target.configurations.create("myResolvable") {
            extendsFrom(myDependencyScope)
        }
        
        target.tasks.register("myTask", TaskUsingKotlinCompiler::class.java) {
            kotlinCompiler.from(myResolvableConfiguration)
        }
    }
    
    companion object {
        const val KOTLIN_COMPILER_EMBEDDABLE = "org.jetbrains.kotlin:kotlin-compiler-embeddable"
        const val KOTLIN_COMPILER_VERSION = "2.2.20"
    }
}
```

## Compose fordító frissítések

### Több stabilitási konfigurációs fájl támogatása

A Compose fordító képes több stabilitási konfigurációs fájl értelmezésére, de a Compose Compiler Gradle plugin `stabilityConfigurationFile` opciója korábban csak egyetlen fájl megadását tette lehetővé. A Kotlin 2.1.0-ban ez a funkció átdolgozásra került, lehetővé téve több stabilitási konfigurációs fájl használatát egyetlen modulhoz:

- A `stabilityConfigurationFile` opció elavult
- Van egy új opció, `stabilityConfigurationFiles`, `ListProperty<RegularFile>` típussal

Így adj át több fájlt a Compose fordítónak az új opció használatával:

```
// build.gradle.kts
composeCompiler {
    stabilityConfigurationFiles.addAll(
        project.layout.projectDirectory.file("configuration-file1.conf"),
        project.layout.projectDirectory.file("configuration-file2.conf"),
    )
}
```

### Szüneteltethető kompozíció

A szüneteltethető kompozíció egy új **Kísérleti** funkció, amely megváltoztatja, hogyan generálja a fordító az átugorható függvényeket. Ezzel a funkcióval engedélyezve a kompozíció szünetelhet az átugrási pontokon futásidőben, lehetővé téve a hosszan futó kompozíciós folyamatok szétosztását több keretre.

A szüneteltethető kompozíciót lusta listákban és más teljesítményigényes komponensekben használják a tartalom előtöltésére, amely keretek ejtését okozhatja, ha blokkoló módon hajtódik végre.

A szüneteltethető kompozíció kipróbálásához add hozzá a következő funkció jelzőt a Compose fordító Gradle konfigurációjában:

```
// build.gradle.kts
composeCompiler {
    featureFlags = setOf(
        ComposeFeatureFlag.PausableComposition
    )
}
```

A futásidő támogatás ehhez a funkcióhoz az `androidx.compose.runtime` 1.8.0-alpha02 verziójában került hozzáadásra. A funkció jelzőnek nincs hatása régebbi futásidő verziókkal való használat esetén.

### Változások a nyitott és felülírt @Composable függvényekben

A virtuális (nyitott, absztrakt és felülírt) @Composable függvények többé nem újraindíthatók. A kódgenerálás az átugorható csoportok számára olyan hívásokat generált, amelyek nem működtek megfelelően az öröklődéssel, futásidejű összeomlásokat eredményezve. Ez azt jelenti, hogy a virtuális függvények nem kerülnek újraindításra vagy átugrásra: amikor az állapotuk érvénytelenné válik, a futásidő újra fogja komponálni a szülő összeállítható függvényüket.

Ha a kódod érzékeny a kompozíciókra, változásokat tapasztalhatsz a futásidejű viselkedésben.

### Teljesítményjavulások

A Compose fordító korábban létrehozta a modul IR teljes másolatát a @Composable típusok átalakításához. A csak a Compose-hoz nem kapcsolódó elemek másolásán kívül ez a viselkedés megnövelte a memóriafelhasználást, valamint bizonyos szélsőséges esetekben megszakította az alsóbb szintű fordító pluginokat. Ez a másolási művelet eltávolításra került, így potenciálisan gyorsabb fordítási idők érhetők el.

## Alapkönyvtár

### Változások az alapkönyvtár API-k elavultsági súlyosságában

A Kotlin 2.1.0-ban több alapkönyvtár API elavultsági súlyosságát emeljük figyelmeztetésről hibára. Ha a kódod ezekre az API-kra támaszkodik, frissítened kell azt a kompatibilitás biztosítása érdekében. A legfontosabb változások a következők:

- **Helyzetérzékeny kis- és nagybetű átalakító függvények Char és String típusokhoz elavultak**:
  - Az olyan függvények mint `Char.toLowerCase()`, `Char.toUpperCase()`, `String.toUpperCase()`, és `String.toLowerCase()` most elavultak, és használatuk hibát eredményez
  - Cserélje le őket helyzetérzéketlen függvény alternatívákkal vagy más kis- és nagybetű átalakító mechanizmusokkal
  - Ha továbbra is szeretné használni az alapértelmezett helyzetet, cserélje le az `String.toLowerCase()` hívásokat `String.lowercase(Locale.getDefault())` hívásokra, kifejezetten megadva a helyzetet
  - Helyzetérzéketlen átalakításhoz cserélje le őket `String.lowercase()` függvényre, amely alapértelmezetten az invariáns helyzetet használja

- **Kotlin/Native fagyasztási API elavult**:
  - A korábban `@FreezingIsDeprecated` annotációval megjelölt fagyasztással kapcsolatos deklarációk használata most hibát eredményez
  - Ez a változás tükrözi az örökölt memóriakezelőből való átmenetet a Kotlin/Native-ban, amely megkövetelte az objektumok fagyasztását a szálak közötti megosztáshoz
  - A fagyasztással kapcsolatos API-kból való áttelepítésről az új memóriamodellben lásd a Kotlin/Native áttelepítési útmutatót
  - További információkért lásd a fagyasztás elavultságáról szóló bejelentést

- **appendln() elavult az appendLine() javára**:
  - A `StringBuilder.appendln()` és `Appendable.appendln()` függvények most elavultak, és használatuk hibát eredményez
  - Cserélje le őket a `StringBuilder.appendLine()` vagy `Appendable.appendLine()` függvényekre
  - Az `appendln()` függvény elavult, mert a Kotlin/JVM-ben a `line.separator` rendszertulajdonságot használja, amelynek különböző alapértelmezett értéke van minden operációs rendszeren
  - A Kotlin/JVM-ben ez a tulajdonság alapértelmezetten `\r\n` (CR LF) Windows rendszereken és `\n` (LF) más rendszereken
  - Másrészt az `appendLine()` függvény következetesen `\n` (LF) karaktert használ soremelő karakterként, biztosítva a következetes viselkedést platformok között

Az érintett API-k teljes listájáért ebben a kiadásban lásd a [KT-71628 YouTrack problémát](https://youtrack.jetbrains.com/issue/KT-71628).

## Stabil fájlfabejáró kiterjesztések java.nio.file.Path számára

A Kotlin 1.7.20 bevezetett **Kísérleti** kiterjesztés függvényeket a `java.nio.file.Path` osztályhoz, amelyek lehetővé teszik egy fájlfán való végigmenni. A Kotlin 2.1.0-ban a következő fájlfabejáró kiterjesztések most **Stabilak**:

- `walk()` lustán bejárja a megadott elérési úton gyökerező fájlfát
- `fileVisitor()` lehetővé teszi egy `FileVisitor` külön létrehozását
- `FileVisitor` meghatározza a könyvtárakon és fájlokon végrehajtandó műveleteket a bejárás során
- `visitFileTree(fileVisitor: FileVisitor, ...)` bejár egy fájlfát, meghívja a megadott `FileVisitor`-t minden talált bejegyzésre, és a `java.nio.file.Files.walkFileTree()` függvényt használja belsőleg
- `visitFileTree(..., builderAction: FileVisitorBuilder.() -> Unit)` létrehoz egy `FileVisitor`-t a megadott `builderAction` segítségével, és meghívja a `visitFileTree(fileVisitor, ...)` függvényt
- `sealed interface FileVisitorBuilder` lehetővé teszi egy egyéni `FileVisitor` implementáció definiálását
- `enum class PathWalkOption` bejárási opciókat biztosít a `Path.walk()` függvény számára

Az alábbi példák bemutatják ezeknek a fájlbejáró API-knak a használatát egyéni `FileVisitor` viselkedések létrehozásához, amelyek lehetővé teszik specifikus műveletek definiálását fájlok és könyvtárak meglátogatásához. Például kifejezetten létrehozhatsz egy `FileVisitor`-t és később használhatod:

```
val cleanVisitor = fileVisitor {
    onPreVisitDirectory { directory, attributes ->
        // Helyőrző: Adj hozzá logikát a könyvtárak meglátogatásához
        FileVisitResult.CONTINUE
    }
    onVisitFile { file, attributes ->
        // Helyőrző: Adj hozzá logikát a fájlok meglátogatásához
        FileVisitResult.CONTINUE
    }
}

// Helyőrző: Adj hozzá logikát az általános beállításhoz a bejárás előtt
projectDirectory.visitFileTree(cleanVisitor)
```

Létrehozhatsz egy `FileVisitor`-t a `builderAction` segítségével és azonnal használhatod a bejáráshoz:

```
projectDirectory.visitFileTree {
    // Definiálja a builderAction-t:
    onPreVisitDirectory { directory, attributes ->
        // Néhány logika a könyvtárak meglátogatásához
        FileVisitResult.CONTINUE
    }
    onVisitFile { file, attributes ->
        // Néhány logika a fájlok meglátogatásához
        FileVisitResult.CONTINUE
    }
}
```

Ezen felül bejárhatod a megadott elérési úton gyökerező fájlfát a `walk()` függvénnyel:

```
fun traverseFileTree() {
    val cleanVisitor = fileVisitor {
        onPreVisitDirectory { directory, _ ->
            if (directory.name == "build") {
                directory.toFile().deleteRecursively()
                FileVisitResult.SKIP_SUBTREE
            } else {
                FileVisitResult.CONTINUE
            }
        }
        // Törli a .class kiterjesztésű fájlokat
        onVisitFile { file, _ ->
            if (file.extension == "class") {
                file.deleteExisting()
            }
            FileVisitResult.CONTINUE
        }
    }
    
    // Beállítja a gyökérkönyvtárat és fájlokat
    val rootDirectory = createTempDirectory("Project")
    
    // Létrehozza az src könyvtárat A.kt és A.class fájlokkal
    rootDirectory.resolve("src").let { srcDirectory ->
        srcDirectory.createDirectory()
        srcDirectory.resolve("A.kt").createFile()
        srcDirectory.resolve("A.class").createFile()
    }
    
    // Létrehozza a build könyvtárat egy Project.jar fájllal
    rootDirectory.resolve("build").let { buildDirectory ->
        buildDirectory.createDirectory()
        buildDirectory.resolve("Project.jar").createFile()
    }
    
    // Használja a walk() függvényt:
    val directoryStructure = rootDirectory.walk(PathWalkOption.INCLUDE_DIRECTORIES)
        .map { it.relativeTo(rootDirectory).toString() }
        .toList().sorted()
    println(directoryStructure) // "[, build, build/Project.jar, src, src/A.class, src/A.kt]"
    
    // Bejárja a fájlfát a cleanVisitor-rel, alkalmazva a rootDirectory.visitFileTree(cleanVisitor) takarítási szabályokat
    val directoryStructureAfterClean = rootDirectory.walk(PathWalkOption.INCLUDE_DIRECTORIES)
        .map { it.relativeTo(rootDirectory).toString() }
        .toList().sorted()
    println(directoryStructureAfterClean) // "[, src, src/A.kt]"
}
```

## Dokumentációs frissítések

A Kotlin dokumentáció számos észrevehető változást kapott:

### Nyelvi fogalmak

- **Javított Null biztonság oldal** – Tanulja meg, hogyan kezelje a null értékeket biztonságosan a kódjában
- **Javított Objektum deklarációk és kifejezések oldal** – Tanulja meg, hogyan definiáljon egy osztályt és hozzon létre egy példányt egy lépésben
- **Javított When kifejezések és utasítások szakasz** – Ismerje meg a when feltételes utasítást és annak használatát
- **Frissített Kotlin útiterv, Kotlin fejlődési elvek és Kotlin nyelvi funkciók és javaslatok oldalak** – Ismerje meg a Kotlin terveit, folyamatban lévő fejlesztéseit és vezérelveit

### Compose fordító

- **Compose fordító dokumentáció most a Fordítók és pluginok szekcióban található** – Ismerje meg a Compose fordítót, a fordító opciókat és az áttelepítés lépéseit

### API referenciák

- **Új Kotlin Gradle pluginok API referencia** – Fedezze fel az API referenciákat a Kotlin Gradle pluginhoz és a Compose fordító Gradle pluginhoz

### Multiplatform fejlesztés

# Kotlin 2.0.20 újdonságai és frissítések

## Új dokumentációs oldalak

- **Kotlin Multiplatform Library építése** – Megtudhatod, hogyan tervezd meg a Kotlin könyvtáraidat többplatformos környezetben.
- **Bevezetés a Kotlin Multiplatform világába** – Ismerd meg a kulcsfogalmakat, függőségeket, könyvtárakat és sok mást.
- **Kotlin Multiplatform áttekintés** – Fedezd fel a Kotlin Multiplatform alapjait és népszerű használati eseteit.
- **iOS integráció szekció** – Megtudhatod, hogyan építsd be a Kotlin Multiplatform közös modulját iOS aplikációdba.
- **Kotlin/Native Definition fájl** – Megtudhatod, hogyan hozz létre definition fájlt C és Objective-C könyvtárak használatához.
- **Első lépések WASI-val** – Megtudhatod, hogyan futtass egy egyszerű Kotlin/Wasm alkalmazást WASI segítségével különböző WebAssembly VM-eken.

## Fejlesztői eszközök

### Dokka migrációs útmutató  
A Dokka Gradle plugin v2-re való migráció lépéseiről itt olvashatsz bővebben.

### Kompatibilitási útmutató – Kotlin 2.1.0

A Kotlin 2.1.0 egy új funkciókat tartalmazó verzió, amely változásokat hozhat, melyek nem kompatibilisek a korábbi verziókban írt kóddal. A részletes változásokat megtalálod a [Compatibility Guide for Kotlin 2.1.0](link) dokumentumban.

#### Telepítés  
A Kotlin plugin mostantól a `bundled plugin` része az IntelliJ IDEA 2023.3-tól és az Android Studio Iguana (2023.2.1) Canary 15-től, így már nem telepíthető a JetBrains Marketplace-ről.

#### Következő lépések  
A Kotlin frissítéséhez egyszerűen változtasd meg a verziót a Gradle build szkriptjeidben: 
```
kotlin("jvm") version "2.1.0"
```

---

## Újdonságok a Kotlin 2.0.20-ban

**Megjelent:** 2024. augusztus 22.

Ez a kiadás jelentős teljesítményjavításokat és hibajavításokat tartalmaz a 2.0.0-hoz képest, különösen az új **K2 kompilátor** stabilizálása után.

### Főbb fejlesztések:

- A `data class copy()` függvény most már ugyanazt a láthatóságot örökli, mint a konstruktor
- A `source sets` statikus hozzáférései elérhetők multiplatform projektekben
- Kotlin/Native garbaze collectorában lehetőség van `concurrent marking` használatára
- Új helyen található az `@ExperimentalWasmDsl` annotáció a Kotlin/Wasm-ben
- Gradle 8.6–8.8 verziók támogatva
- Lehetőség van a JVM artifact-ok osztályfájlokban történő megosztására Gradle projektek között
- A Compose compiler frissítésre került
- UUID támogatás hozzáadva a közös `kotlin-stdlib` könyvtárhoz

### IDE támogatás

Az IntelliJ IDEA és Android Studio már tartalmazza a Kotlin plugin támogatást a 2.0.20-hoz, így nem szükséges külön telepíteni. Csak frissíteni kell a build szkriptben a Kotlin verziót.

---

## Nyelvi változások

### `data class copy()` láthatóság

#### Probléma:
A `data class` `copy()` metódusa jelenleg nem örökli a konstruktor láthatóságát.

#### Példa:
```
data class PositiveInteger private constructor(val number: Int) {
    companion object {
        fun create(number: Int): PositiveInteger? = if (number > 0) PositiveInteger(number) else null
    }
}

fun main() {
    val positiveNumber = PositiveInteger.create(42) ?: return
    val negativeNumber = positiveNumber.copy(number = -1) // Warning
}
```

#### Új funkciók:
- `@ConsistentCopyVisibility` – Új viselkedés engedélyezése.
- `@ExposedCopyVisibility` – Régi viselkedés megtartása, figyelmeztetések elnyomása.

#### Opció a teljes modulra:
```
-Xconsistent-data-class-copy-visibility
```

---

### Kontextus receptorok lecserélése

#### Változás:
- A `context receivers` (Experimental) elavult, a `context parameters` lesz a jövő.
- A két megközelítés nem lesz egyszerre támogatott.

#### Példa figyelmeztetésre:
```
class MyContext context(MyContext) // Warning
fun someFunction() { }
```

#### Migrációs lehetőségek:
- **Explicit paraméterek használata:**

```
// Korábban
context(ContextReceiverType) 
fun someFunction() { contextReceiverMember() }

// Most
fun someFunction(explicitContext: ContextReceiverType) { 
    explicitContext.contextReceiverMember() 
}
```

- **Extension tagfüggvények használata:**

```
// Korábban
context(ContextReceiverType)
fun contextReceiverMember() = TODO()

// Most
class ContextReceiverType {
    fun contextReceiverMember() = TODO()
}

fun ContextReceiverType.someFunction() {
    contextReceiverMember()
}
```

---

## Kotlin Multiplatform

A 2.0.20 javítja a forráskészlet kezelését multiplatform projektekben, valamint elavult néhány Gradle Java plugin támogatása a Gradle új változása miatt.

# Kotlin 2.0.20 Újdonságok és változások

## Forrás hozzáférések a Kotlin Multiplatform projektekben

### Típusos hozzáférések a `sourceSets` blokkban

A Kotlin 1.9.20 óta az alapértelmezett hierarchia sablon automatikusan alkalmazva van minden Kotlin Multiplatform projektben. Ezt követően a Kotlin Gradle plugin biztosított típusos hozzáféréseket az összes default hierarchiához tartozó source set számára.

A Kotlin 2.0.20 továbbfejleszti az IDE élményt, és most már statikus hozzáféréseket biztosít a `sourceSets {}` blokkban az összes default hierarchiából származó source set számára.

Példa:
```
kotlin {
    jvm()
    linuxX64()
    linuxArm64()
    mingwX64()

    sourceSets {
        commonMain.languageSettings {
            progressiveMode = true
        }
        jvmMain { }
        linuxX64Main { }
        linuxArm64Main { }
        // Figyelmeztetés: elérés forráskészlet regisztrálása nélkül
        iosX64Main { }
    }
}
```

### Elavult kompatibilitás a Gradle Java pluginokkal

A Kotlin Multiplatform Gradle plugin és a következő Gradle Java pluginok kombinálása elavult:

- Java
- Java Library
- Application

Ez a váltás az alábbi indokokból szükséges:

1. Fundamentális kompatibilitási problémák a Kotlin Multiplatform projektszerkezete és a Gradle Java ökoszisztéma között
2. A Gradle nem biztosít API-t a multiplatform komplexitás kezelésére
3. A workaround lehetőségek a Gradle 8.8-tól kezdve megszűntek

#### Megoldási javaslatok:

**Ha nincs szükség a Java pluginra:**

1. Távolítsd el, ha nem szükséges
2. Ellenőrizd, hogy csak egy feladathoz használod-e

**Ha mindenképp szükséges a használata:**

1. Hozz létre egy külön alprojektet
2. Alkalmazd a Java plugin-t ebben az alprojektben
3. Adj hozzá dependenciát a szülő projektben

Struktúra példa:
```
my-main-project/
├── build.gradle.kts
├── settings.gradle
└── subproject-A/
    ├── build.gradle.kts
    └── src/
        └── Main.java
```

Alprojekt `build.gradle.kts`:
```
plugins {
    id("application")
}

dependencies {
    implementation(project(":my-main-project"))
}
```

---

## Kotlin/Native fejlesztések

### Párhuzamos jelölés a garbage collectorban

#### Újdonság

Kísérleti párhuzamos jelölési támogatás érhető el a GC-ben, célja a GC szünetidő csökkentése UI alkalmazásokban.

**Engedélyezés:**

```
# gradle.properties
kotlin.native.binary.gc=cms
```

### Bitcode beágyazás eltávolítva

A bitcode beágyazás támogatása megszűnik, mivel:
- Xcode 14-ben elavult
- Xcode 15-ben teljesen eltávolítva

Elavult paraméterek:
- `embedBitcode` konfiguráció
- `-Xembed-bitcode`
- `-Xembed-bitcode-marker`

### GC teljesítmény monitorozás

A signposts eszköz most opt-in módon érhető el:
```
-Xbinary=enableSafepointSignposts=true
```

### Kotlin suspend függvények hívása nem-main szálról

A korábbi korlátozás megszűnik:
```
// Korábban csak main szálról lehetett hívni
// Most már bármely szálról meghívható
```

---

## Kotlin/Wasm változások

### Named exportsra történő átállás

**Változások a verziók szerint:**

- **2.0.0:** Figyelmeztetés default export használat esetén
- **2.0.20:** Hibaüzenet default export használat esetén
- **2.1.0:** Teljes eltávolítás

**Hibaüzenet:**
```
// Hibás használat
import module from "..." // Hiba
// Helyes használat
import { specificFunction } from "..."
```

### @ExperimentalWasmDsl új helye

**Régi hely:**
```
import org.jetbrains.kotlin.gradle.targets.js.dsl.ExperimentalWasmDsl
```

**Új hely:**
```
import org.jetbrains.kotlin.gradle.ExperimentalWasmDsl
```

---

## Kotlin/JS Experimental funkciók

### @JsStatic annotáció

Kotlin statikus tagok JavaScriptből való eléréséhez:

```
class C {
    companion object {
        @JsStatic 
        fun callStatic() {}
        
        fun callNonStatic() {}
    }
}
```

**JavaScript használat:**
```
C.callStatic(); // Működik
C.callNonStatic(); // Hiba
C.Companion.callStatic(); // Példány metódusként
C.Companion.callNonStatic(); // Csak így működik
```

### Kotlin kollekciók létrehozása JavaScriptből

**Kotlin oldal:**
```
@JsExport
fun consumeMutableMap(map: MutableMap<String, Int>)
```

**JavaScript oldal:**
```
import { consumeMutableMap } from "module"
import { KtMutableMap } from "module/kotlin-kotlin-stdlib"

consumeMutableMap(
    KtMutableMap.fromJsMap(new Map([["First", 1], ["Second", 2]]))
)
```

Támogatott típusok: `Set`, `Map`, `List` és mutábilis változataik.

---

## Gradle változások

### Kompatibilitás

- Támogatott: Gradle 6.8.3 - 8.6
- Részleges támogatás: Gradle 8.7 - 8.8 (JVM target `withJava()` figyelmeztetésekkel)

### Elavult inkrementális fordítás

A JVM history fájlokon alapuló inkrementális fordítás elavult, helyette az új megközelítés:

```
# Elavult
kotlin.incremental.useClasspathSnapshot
```

### JVM artifactok megosztása osztályfájlokként

**Experimental funkció - teljesítményjavulás Linux/macOS alatt:**

```
# gradle.properties
kotlin.jvm.addClassesVariant=true
```

**Windows teljesítmény probléma esetén:**
```
org.gradle.java.compile-classpath-packaging=true
```

---

## Egyéb fejlesztések

### Függőségek viselkedésének egységesítése

A `java-test-fixtures` pluginnal való kompatibilitás javítva, a hibás classpath duplikációk megszűntek.

### Fordítási feladatok automatikus függőségei

Automatikus függőségi hozzáadás fordítási artifactokhoz.

**Cirkuláris függőség esetén:**
```
archivesTaskOutputAsFriendModule=true
```

# Kotlin 2.0.20 Újdonságok - folytatás

## Gradle változások - folytatás

### Fordítási artifact függőségek

Alapértelmezetten a `archivesTaskOutputAsFriendModule` értéke `true`, de letiltható:

```
# gradle.properties
kotlin.build.archivesTaskOutputAsFriendModule=false
```

---

## Compose Compiler fejlesztések

### Elkerülve az indokolatlan újrarajzolások

A Kotlin 2.0.0-ban bevezetett probléma, ami nem megfelelő típusstabilitás következtében felesleges újrarajzolásokat okozott, javítva lett.

**Javasolt frissítés:**
- Compose alkalmazások: Kotlin 2.0.0 → 2.0.10 vagy újabb
- Függőségek: Frissítés az alkalmazással megegyező Compose compiler verzióra

### Új beállítási lehetőségek

A régi beállítások elavultak, új feature flag alapú rendszer került bevezetésre:

```
composeCompiler {
    featureFlags = setOf(
        ComposeFeatureFlag.IntrinsicRemember.disabled(),
        ComposeFeatureFlag.OptimizeNonSkippingGroups,
        ComposeFeatureFlag.StrongSkipping.disabled()
    )
}
```

**Elavult beállítások:**
- `enableIntrinsicRemember`
- `enableNonSkippingGroupOptimization` 
- `enableStrongSkippingMode`

### Erős átugrás mód (Strong skipping) alapértelmezetten aktív

Mostantól az instabil paraméterekkel rendelkező composables is átugorhatók. A lambdákat nem szükséges `remember`-rel becsomagolni.

### Composition trace marker alapértelmezetten aktív

Az Android Studio rendszer nyomkövetőjében kiolvashatók a composable függvények.

### Nem-átugorható csoport optimalizációk

**Experimental funkció** - letiltva alapértelmezetten:

```
composeCompiler {
    featureFlags = setOf(ComposeFeatureFlag.OptimizeNonSkippingGroups)
}
```

### Alapértelmezett paraméterek absztrakt composable függvényekben

```
abstract class Composables {
    @Composable
    abstract fun Composable(modifier: Modifier = Modifier)
}
```

---

## Standard könyvtár fejlesztések

### UUID támogatás (Experimental)

```
@OptIn(ExperimentalUuidApi::class)
fun main() {
    // Létrehozás
    val byteArray = byteArrayOf(
        0x55, 0x0E, 0x84.toByte(), 0x00, 0xE2.toByte(), 
        0x9B.toByte(), 0x41, 0xD4.toByte(), 0xA7.toByte(), 
        0x16, 0x44, 0x66, 0x55, 0x44, 0x00, 0x00
    )
    
    val uuid1 = Uuid.fromByteArray(byteArray)
    val uuid2 = Uuid.fromULongs(0x550E8400E29B41D4uL, 0xA716446655440000uL)
    val uuid3 = Uuid.parse("550e8400-e29b-41d4-a716-446655440000")
    
    println(uuid1) // 550e8400-e29b-41d4-a716-446655440000
    println(uuid1 == uuid2) // true
    println(uuid2 == uuid3) // true
    
    // Bit elérés
    val version = uuid1.toLongs { mostSignificantBits, _ -> 
        ((mostSignificantBits shr 12) and 0xF).toInt() 
    }
    println(version) // 4
    
    // Random UUID
    val randomUuid = Uuid.random()
    println(uuid1 == randomUuid) // false
}
```

**Java kompatibilitás:**
```
val kotlinUuid = Uuid.parseHex("550e8400e29b41d4a716446655440000")
val javaUuid = kotlinUuid.toJavaUuid()
val backToKotlin = javaUuid.toKotlinUuid()
```

### HexFormat minLength támogatás

```
@OptIn(ExperimentalStdlibApi::class)
fun main() {
    println(93.toHexString(HexFormat {
        number.minLength = 4
        number.removeLeadingZeros = true
    })) // "005d"
}
```

### Base64 dekóder változások

Alapértelmezetten most padding szükséges:

```
@OptIn(ExperimentalEncodingApi::class)
fun main() {
    val data = "fooba".toByteArray()
    
    // PRESENT padding (alapértelmezett)
    val base64Present = Base64.UrlSafe.withPadding(Base64.PaddingOption.PRESENT)
    val encodedDataPresent = base64Present.encode(data)
    println("Encoded with PRESENT padding: $encodedDataPresent") // Zm9vYmE=
    
    // ABSENT padding
    val base64Absent = Base64.UrlSafe.withPadding(Base64.PaddingOption.ABSENT)
    val encodedDataAbsent = base64Absent.encode(data)
    println("Encoded with ABSENT padding: $encodedDataAbsent") // Zm9vYmE
}
```

**Padding opciók:**

| Opció            | Kódoláskor         | Dekódoláskor              |
| ---------------- | ------------------ | ------------------------- |
| PRESENT          | Padding hozzáadása | Padding kötelező          |
| ABSENT           | Padding elhagyása  | Padding nem engedélyezett |
| PRESENT_OPTIONAL | Padding hozzáadása | Padding opcionális        |
| ABSENT_OPTIONAL  | Padding elhagyása  | Padding opcionális        |

---

## Dokumentáció fejlesztések

- Fejlesztett Standard input oldal
- K2 compiler migrációs útmutató
- Kivételek oldal fejlesztése
- JUnit tesztelési útmutató
- Swift/Objective-C interoperabilitás
- Swift package export beállítások

---

# Kotlin 2.0.0 Újdonságok

## Kotlin K2 Compiler stabilizálva

### Főbb fejlesztések

- **Teljesítményjavulások**
- Gyorsabb nyelvi funkció fejlesztés
- Platform unifikáció
- Jobb architektúra multiplatform projektekhez
- **Stabil** minden platformon: JVM, Native, Wasm, JS

### Tesztelés

- 10 millió sor kód fordítva tesztelésre
- 18,000 fejlesztő 80,000 projekt tesztelésében vett részt

### Limitációk (Gradle < 8.3 esetén)

- `buildSrc` forráskód fordítása
- Gradle plugin fordítás included buildben
- Gradle plugin függőségek építése

**Megoldás:**
```
kotlin {
    compilerOptions {
        languageVersion.set(org.jetbrains.kotlin.gradle.dsl.KotlinVersion.KOTLIN_1_9)
        apiVersion.set(org.jetbrains.kotlin.gradle.dsl.KotlinVersion.KOTLIN_1_9)
    }
}
```

---

## Smart Cast fejlesztések

### Javított viselkedések

1. **Lokális változók és scopeok**
2. **Logikai OR műveletek**
3. **Inline függvények**
4. **Függvény típusú propertyk**
5. **Kivételkezelés**
6. **Inkrementálás/dekrementálás operátorok**

#### Példa a lokális változó fejlesztésre:

```
class Cat {
    fun purr() {
        println("Purr purr")
    }
}

fun petAnimal(animal: Any) {
    val isCat = animal is Cat
    if (isCat) {
        // Kotlin 2.0.0: animal smart-cast Cat típusra
        animal.purr()
    }
}
```

### Logikai OR operátorok

```
fun processValue(value: Any) {
    if (value is String || value is Int) {
        // Smart cast a megfelelő típusokra mindkét ágon
    }
}
```

# Kotlin 2.0.0 Újdonságok - folytatás

## További Smart Cast fejlesztések

### Inline függvények kezelése

A K2 compiler most implicit `callsInPlace` kontraktusként kezeli az inline függvényeket:

```
interface Processor { 
    fun process() 
}

inline fun inlineAction(f: () -> Unit) = f()

fun nextProcessor(): Processor? = null

fun runProcessor(): Processor? {
    var processor: Processor? = null
    inlineAction {
        // Kotlin 2.0.0: a compiler tudja, hogy processor 
        // lokális változó és inlineAction inline függvény,
        // tehát nem szivároghat ki referencia
        if (processor != null) {
            processor.process() // Nem szükséges safe call
        }
        processor = nextProcessor()
    }
    return processor
}
```

### Függvény típusú propertyk

```
class Holder(val provider: (() -> Unit)?) {
    fun process() {
        if (provider != null) {
            provider() // Smart cast történik, nem kell ?.invoke()
        }
    }
}
```

### Kivételkezelés

```
fun testString() {
    var stringInput: String? = null
    stringInput = ""
    
    try {
        println(stringInput.length) // 0
        stringInput = null
        if (2 > 1) throw Exception()
        stringInput = ""
    } catch (exception: Exception) {
        // Kotlin 2.0.0: stringInput marad nullable
        println(stringInput?.length) // null
    }
}
```

### Inkrementálás/dekrementálás operátorok

```
interface Rho {
    operator fun inc(): Sigma = TODO()
}

interface Sigma : Rho {
    fun sigma() = Unit
}

interface Tau {
    fun tau() = Unit

fun main(input: Rho) {
    var unknownObject: Rho = input
    if (unknownObject is Tau) {
        ++unknownObject // unknownObject típusa Sigma-ra változik
        
        unknownObject.sigma() // Működik
        unknownObject.tau()    // Fordítási hiba: Unresolved reference
    }
}
```

---

## Kotlin Multiplatform fejlesztések

### Common és platform források szétválasztása

**Korábbi hiba:**
```
// Common code
fun foo(x: Any) = println("common foo")

// JVM platform code  
fun foo(x: Int) = println("platform foo")

// JavaScript platform code
// Nincs foo() overload

fun exampleFunction() {
    foo(42) // Különböző viselkedés különböző platformokon
}
```

**Kotlin 2.0.0 viselkedés:**
- Common kód nem fér hozzá platform kódhoz
- Konzisztens viselkedés minden platformon

### Várható és aktuális deklarációk láthatósága

Mostantól eltérő láthatósági szintek engedélyezettek:

```
expect internal class Attribute  // internal
actual class Attribute          // public (alapértelmezett, engedélyezett)

// Type alias esetén:
expect internal class Attribute
internal actual typealias Attribute = Expanded
class Expanded  // public, engedélyezett
```

### Fordító plugin támogatás

**Támogatott pluginok:**
- all-open
- AtomicFU
- jvm-abi-gen
- js-plain-objects
- kapt
- Lombok
- no-arg
- Parcelize
- SAM with receiver
- serialization
- Power-assert

**Compose és KSP:**
- Jetpack Compose compiler plugin 2.0.0
- Kotlin Symbol Processing (KSP) plugin KSP2-től

### Experimental Kotlin Power-assert plugin

```
plugins {
    kotlin("multiplatform") version "2.0.0"
    kotlin("plugin.power-assert") version "2.0.0"
}

powerAssert {
    functions = listOf("kotlin.assert", "kotlin.test.assertTrue")
}
```

---

## Kotlin K2 Compiler aktiválása

### Alapértelmezett aktiválás
Kotlin 2.0.0-tól automatikusan aktív, nincs szükség külön beállításra.

### IDE támogatás
Alapértelmezetten IntelliJ IDEA és Android Studio még a régi compilert használja IDE funkciókhoz.

**K2 mód engedélyezése:**
1. Settings | Languages & Frameworks | Kotlin
2. Enable K2 mode opció kiválasztása

---

## Kotlin/JVM fejlesztések

### Java 22 bytecode támogatás

### Lambda generálás invokedynamic használatával

**Újdonság:**
- invokedynamic lett az alapértelmezett lambda generálási mód
- Kisebb bináris méret
- JVM optimalizációk kihasználása

**Limitációk:**
1. invokedynamic lambda nem szerializálható
2. Experimental reflect() API nem támogatja
3. `.toString()` kevésbé olvasható eredményt ad

**Régi viselkedés megtartása:**
```
// Opció 1: @JvmSerializableLambda annotáció
val lambda = @JvmSerializableLambda { /* ... */ }

// Opció 2: Fordító opció
-Xlambdas=class
```

### kotlinx-metadata-jvm library stabilizálva

- Új név: `kotlin-metadata-jvm` (korábban `kotlinx-metadata-jvm`)
- Közös verziókezelés a Kotlin standard libraryval
- API bináris fájlok metaadatainak olvasásához és módosításához

---

## Kotlin/Native fejlesztések

### GC teljesítmény monitorozás

Apple platformokon Xcode Instruments segítségével monitorozható a GC teljesítmény signpostokkal.

### Objective-C metódus konfliktusok feloldása

### Fordító argumentumok naplózási szintjének változtatása

### Standard library és platform függőségek explicit hozzáadása

### Gradle konfigurációs cache hibák javítása

# Kotlin 2.0.0 Újdonságok - folytatás

## Kotlin/Native fejlesztések - folytatás

### Objective-C metódus konfliktusok feloldása

```
// Új annotáció a konfliktusok feloldására
@ObjCSignatureOverride
fun locationManager(locationManager: CLLocationManager, didEnterRegion region: CLRegion) {
    // ...
}

@ObjCSignatureOverride  
fun locationManager(locationManager: CLLocationManager, didExitRegion region: CLRegion) {
    // ...
}
```

### Fordító argumentumok naplózási szintje

A log szint `info`-ról `debug`-re változott a Gradle taskokban:
- `compile`
- `link` 
- `cinterop`

### Standard library és platform függőségek

Mostantól explicit módon szerepelnek a `compileDependencyFiles` paraméterben.

### Gradle konfigurációs cache hibák

Hamis pozitív hibák jelentkezhetnek bizonyos taskoknál:
- `NativeDistributionCommonizerTask`
- `KotlinNativeCompile`

---

## Kotlin/Wasm fejlesztések

### Teljesítményoptimalizálás Binaryen használatával

```
// Korábban manuális beállítás szükséges volt
// Most automatikusan alkalmazva production build esetén
```

### Named export támogatás

**Korábbi megközelítés:**
```
// JavaScript
import Module from "./index.mjs"
Module.add()
```

**Új megközelítés:**
```
// Kotlin
@JsExport
fun add(a: Int, b: Int) = a + b
```

```
// JavaScript
import { add } from "./index.mjs"
add(1, 2)
```

### Unsigned primitív típusok támogatása

```
@JsExport
fun processValue(value: UInt): ULong {
    return value.toULong() * 2u
}
```

### TypeScript deklarációs fájlok generálása

```
kotlin {
    wasmJs {
        binaries.executable()
        browser {
        }
        generateTypeScriptDefinitions()
    }
}
```

### JavaScript kivételek kezelése

```
try {
    // JavaScript kód hívása
} catch (e: JsException) {
    // JavaScript kivétel kezelése
} catch (e: Throwable) {
    // Általános kivétel kezelése
} finally {
    // Minden esetben végrehajtódik
}
```

### Új kivételkezelési javaslat

```
-Xwasm-use-new-exception-proposal
```

### withWasm() függvény szétválasztása

```
// Korábban
withWasm()

// Most
withWasmJs()
withWasmWasi()
```

---

## Kotlin/JS fejlesztések

### Új ES2015 kompilációs cél

```
kotlin {
    js {
        compilerOptions {
            target.set("es2015")
        }
    }
}
```

### Suspend függvények ES2015 generátorokként

**Experimental funkció:**
```
// Bundle méret csökkenés várható
```

### Main függvény argumentumok

```
kotlin {
    js {
        binary.executable()
        nodejs {
            passProcessArgvToMainFunction()
        }
    }
}
```

### Fájlonkénti kompiláció

```
kotlin {
    js(IR) {
        useEsModules()
        browser()
    }
}
```

```
# gradle.properties
kotlin.js.ir.output.granularity=per-file
```

### Kollekciók interoperabilitása

```
@JsExport
data class User(
    val name: String,
    val friends: List<User> = emptyList()
)

@JsExport
val me = User(
    name = "Me",
    friends = listOf(User(name = "Kodee"))
)
```

```
// JavaScript
import { User, me } from "my-module"

const allMyFriendNames = me.friends
    .asJsReadonlyArrayView()
    .map(x => x.name) // ['Kodee']
```

### createInstance() támogatás

```
// Korábban csak JVM-en elérhető
val instance = MyClass::class.createInstance()
```

### Type-safe JavaScript objektumok

```
import kotlinx.js.JsPlainObject

@JsPlainObject
external interface User {
    var name: String
    val age: Int
    val email: String?
}

fun main() {
    // Type-safe objektum létrehozása
    val user = User(name = "Name", age = 10)
    
    // Másolat készítése
    val copy = user.copy(age = 11, email = "some@user.com")
    
    println(JSON.stringify(user)) // { "name": "Name", "age": 10 }
    println(JSON.stringify(copy)) // { "name": "Name", "age": 11, "email": "some@user.com" }
}
```

### npm package manager támogatás

```
# gradle.properties
kotlin.js.yarn = false
```

### Kompilációs task változások

- `webpack` task most külön mappába generál
- `distributeResources` task eltávolítva
- `distribution` task `Copy` típusúra változott

### Legacy JAR artifactok megszűnése

A Kotlin disztribúció már nem tartalmazza a régi `.jar` kiterjesztésű Kotlin/JS artifactokat.

# Kotlin 2.0.0 Újdonságok - folytatás

## Gradle fejlesztések

### Új Gradle DSL a fordító beállításokhoz

**Experimental funkció:**
```
kotlin {
    compilerOptions {
        // Extension szintű beállítások
        allWarningsAsErrors.set(true)
    }
    
    jvm {
        compilerOptions {
            // Target szintű beállítások
            noJdk.set(true)
        }
    }
}
```

**Konfigurációs szintek:**
1. Extension szint (legmagasabb)
2. Target szint
3. Fordítási egység szint (legalacsonyabb)

### Új Compose compiler Gradle plugin

```
plugins {
    kotlin("plugin.compose") version "2.0.0"
}
```

### Új attribútum JVM és Android könyvtárak megkülönböztetésére

```
# gradle.properties - letiltás esetén
kotlin.publishJvmEnvironmentAttribute=false
```

### Javított CInteropProcess függőségkezelés

```
kotlin {
    macosArm64("native") {
        compilations.getByName("main") {
            cinterops {
                val cinterop by creating {
                    // Új property
                    definitionFile.set(project.file("def-file.def"))
                }
            }
        }
    }
}
```

### Láthatósági változások Gradle-ben

**Korábbi probléma:**
```
kotlin {
    jvm {
        // Hiba: sourceSets nem érhető el itt
        sourceSets.getByName("jvmMain").dependencies {
            // ...
        }
    }
}
```

**Helyes megközelítés:**
```
kotlin {
    sourceSets {
        named("jvmMain") {
            dependencies {
                implementation("...")
            }
        }
    }
}
```

### Új könyvtár a Kotlin adatokhoz

```
<project-root>/.kotlin  # Új hely
<project-root>/.gradle   # Régi hely (kompatibilitás miatt)
```

```
# gradle.properties
kotlin.project.persistent.dir=/custom/path
kotlin.project.persistent.dir.gradle.disableWrite=true
```

### Kotlin/Native compiler letöltés igény szerint

**Új viselkedés:**
- Csak akkor töltődik le, ha szükséges
- Csak a végrehajtási fázisban

```
# Visszatérés a régi viselkedéshez
kotlin.native.toolchain.enabled=false

# Maven Central használata letiltása
kotlin.native.distribution.downloadFromMaven=false
```

### Elavult fordító beállítási módok

**Elavult DSL-ek:**
- `kotlinOptions` a `KotlinCompile` interface-ben
- `kotlinOptions` a `KotlinCompilation` interface-ben
- `dceOptions` a `KotlinJsDce` interface-ben

### Minimális támogatott AGP verzió

Minimum: **7.1.3**

### Új Gradle property a legújabb nyelvi verzió kipróbálásához

```
# gradle.properties
kotlin.experimental.tryNext=true
```

### JSON kimeneti formátum build jelentésekhez

```
# gradle.properties
kotlin.build.report.output=json
kotlin.build.report.json.directory=my/directory/path
```

**Parancssoros használat:**
```
./gradlew assemble -Pkotlin.build.report.output=json -Pkotlin.build.report.json.directory="my/directory/path"
```

### Kapt konfigurációk öröklése

```
val commonAnnotationProcessors by configurations.creating

configurations.named("kapt") {
    extendsFrom(commonAnnotationProcessors)
}

dependencies {
    implementation("com.google.dagger:dagger:2.48.1")
    commonAnnotationProcessors("com.google.dagger:dagger-compiler:2.48.1")
}
```

### Elavult Gradle konvenciók eltávolítása

A Kotlin Gradle plugin már nem használ elavult Gradle 8.2+ konvenciókat.

---

## Standard könyvtár fejlesztések

### Stabil enum class values generikus függvény

### Stabil AutoCloseable interfész

### Közös védett tulajdonságok és függvények

```
// AbstractMutableList
protected open var modCount: Int
protected open fun removeRange(fromIndex: Int, toIndex: Int)

// String
fun toCharArray(destination: CharArray, destinationOffset: Int = 0)
```

# Kotlin 1.9.20 Újdonságok

## Stabilizált standard library funkciók

### Enum entries függvény

```
enum class RGB { 
    RED, GREEN, BLUE 
}

inline fun <reified T : Enum<T>> printAllValues() {
    print(enumEntries<T>().joinToString { it.name })
}

printAllValues<RGB>() // RED, GREEN, BLUE
```

### Stabil AutoCloseable interfész

```
interface XMLWriter {
    fun document(encoding: String, version: String, content: XMLWriter.() -> Unit)
    fun element(name: String, content: XMLWriter.() -> Unit)
    fun attribute(name: String, value: String)
    fun text(value: String)
    fun flushAndClose()
}

fun writeBooksTo(writer: XMLWriter) {
    val autoCloseable = AutoCloseable { writer.flushAndClose() }
    autoCloseable.use { 
        writer.document(encoding = "UTF-8", version = "1.0") {
            element("bookstore") {
                element("book") {
                    attribute("category", "fiction")
                    element("title") { text("Harry Potter and the Prisoner of Azkaban") }
                    // ... további elemek
                }
            }
        }
    }
}
```

### Közös védett tulajdonság és függvény

```
// AbstractMutableList.modCount elérhető common kódban
// AbstractMutableList.removeRange() felülírható common kódban

class CustomList<T> : AbstractMutableList<T>() {
    override val modCount: Int = 0
    
    override fun removeRange(fromIndex: Int, toIndex: Int) {
        // Egyedi implementáció
    }
}
```

### String.toCharArray(destination) függvény

```
fun main() {
    val myString = "Kotlin is awesome!"
    val destinationArray = CharArray(myString.length)
    
    // Karakterek átmásolása meglévő tömbbe
    myString.toCharArray(destinationArray)
    
    for (char in destinationArray) {
        print("$char ") // K o t l i n i s a w e s o m e !
    }
}
```

## Kotlin K2 Compiler fejlesztések

### K2 Beta minden platformon

- Teljes K2 compiler támogatás
- Teljesítményjavulások
- Platform unifikáció
- Jobb multiplatform architektúra

### K2 engedélyezése

**Gradle:**
```
kotlin {
    sourceSets.all {
        languageSettings {
            languageVersion = "2.0"
        }
    }
}
```

**Maven:**
```
<properties>
    <kotlin.compiler.languageVersion>2.0</kotlin.compiler.languageVersion>
</properties>
```

**IntelliJ IDEA:**
Settings | Build, Execution, Deployment | Compiler | Kotlin Compiler → Language Version: 2.0 (experimental)

## Kotlin/Wasm támogatás

### WASI API támogatás

### Új és átnevezett célok

## IDE támogatás

- IntelliJ IDEA 2023.1.x, 2023.2.x, 2023.x
- Android Studio Hedgehog (2023.1.1), Iguana (2023.2.1)

## Kotlin/JVM

Támogatás Java 21 bytecode-hoz

## Kotlin/Native fejlesztések

### Egyedi memória allokátor alapértelmezetten

```
# Visszatérés régi allokátorhoz
-Xallocator=mimalloc
-Xallocator=std
```

### Garbage collector fejlesztések

- **Teljes párhuzamos jelölés** - GC szünetidő csökkentése
- **Memória követés nagy darabokban** - jobb allokációs teljesítmény

### Klib artifactok inkrementális fordítása

```
# gradle.properties
kotlin.incremental.native=true
```

### Library linkage hibakezelés

```
kotlin {
    macosX64("native") {
        binaries.executable()
        compilations.configureEach {
            compilerOptions.configure {
                // Linkage hibák warningként
                freeCompilerArgs.add("-Xpartial-linkage-loglevel=WARNING")
                // Linkage warningok hibává emelése
                freeCompilerArgs.add("-Xpartial-linkage-loglevel=ERROR")
            }
        }
    }
}
```

### Companion object inicializálás

```
class Greeting {
    companion object {
        init {
            print("Hello, Kotlin!")
        }
    }
}

fun main() {
    val start = Greeting() // Kiírja: "Hello, Kotlin!"
}
```

### Cinterop deklarációk opt-in kötelezettség

```
// C és Objective-C könyvtárakhoz szükséges
@OptIn(ExperimentalForeignApi::class)
fun useCInteropFunction() {
    // ...
}
```

### Egyedi üzenetek linker hibákhoz

```
# .def fájlban
userSetupHint=Kérjük telepítse a szükséges C könyvtárakat
```

### Legacy memória manager eltávolítva

```
# Eltávolítandó a gradle.properties-ből
kotlin.native.binary.memoryModel=strict
```

### Cél támogatási szintek változása

**Tier 1 célok (macOS hosztokon):**
- macosX64
- macosArm64  
- iosSimulatorArm64
- iosX64

**Eltávolított célok:**
- iosArm32
- watchosX86
- wasm32
- mingwX86
- linuxMips32
- linuxMipsel32

### Kapt támogatás K2-vel (Experimental)

```
# gradle.properties
kotlin.experimental.tryK2=true
kapt.use.k2=true
```

# Kotlin Multiplatform 1.9.20 Újdonságok

## Kotlin Multiplatform stabilizálva

### Fontos mérföldkő
- **Stabil technológia** - kész gyártási környezetbe
- **Visszafelé kompatibilitás** garantált
- Egyes fejlett funkciók továbbra is Experimental státuszúak

## Alapértelmezett hierarchia sablon

### Automatikus forráskészlet létrehozás
```
kotlin {
    androidTarget()
    iosArm64()
    iosSimulatorArm64()
    // Az iosMain forráskészlet automatikusan létrejön
}
```

### Korábbi módszer (1.9.0 és korábbi)
```
kotlin {
    androidTarget()
    iosArm64()
    iosSimulatorArm64()
    
    sourceSets {
        val commonMain by getting
        val iosMain by creating {
            dependsOn(commonMain)
        }
        val iosArm64Main by getting {
            dependsOn(iosMain)
        }
        val iosSimulatorArm64Main by getting {
            dependsOn(iosMain)
        }
    }
}
```

### Forráskészlet kiegészítés
```
kotlin {
    jvm()
    macosArm64()
    iosArm64()
    iosSimulatorArm64()
    
    // Alapértelmezett hierarchia alkalmazása
    applyDefaultHierarchyTemplate()
    
    sourceSets {
        // További forráskészlet létrehozása
        val jvmAndMacos by creating {
            dependsOn(commonMain.get())
        }
        macosArm64Main.get().dependsOn(jvmAndMacos)
        jvmMain.get().dependsOn(jvmAndMacos)
    }
}
```

### Elutasítás a sablonból
```
# gradle.properties
kotlin.mpp.applyDefaultHierarchyTemplate=false
```

## Új projekt varázsló

### Kotlin Multiplatform web varázsló
- Első implementáció webes felületen
- Legnépszerűbb use case-ek támogatása
- Elosztott architektúra (egységes backend, különböző frontendek)

**Megjegyzés:** IntelliJ IDEA 1.9.20-tól kezdve már nem tartalmaz beépített Multiplatform projekt varázslót.

## Gradle konfigurációs cache teljes támogatása

### Támogatott komponensek
- Kotlin CocoaPods Gradle plugin
- Xcode build integrációs taskok (pl. `embedAndSignAppleFrameworkForXcode`)

```
// Korábban szükséges volt
kotlin.native.cacheKind=none

// Most már nem szükséges - eltávolítható a gradle.properties-ből
```

## Egyszerűbb standard library konfiguráció

### Korábbi módszer
```
kotlin {
    sourceSets {
        // Common forráskészlethez
        val commonMain by getting {
            dependencies {
                implementation("org.jetbrains.kotlin:kotlin-stdlib-common:1.9.10")
            }
        }
        // JVM forráskészlethez
        val jvmMain by getting {
            dependencies {
                implementation("org.jetbrains.kotlin:kotlin-stdlib:1.9.10")
            }
        }
        // JS forráskészlethez
        val jsMain by getting {
            dependencies {
                implementation("org.jetbrains.kotlin:kotlin-stdlib-js:1.9.10")
            }
        }
    }
}
```

### 1.9.20 új módszer
```
kotlin {
    sourceSets {
        commonMain {
            dependencies {
                implementation("org.jetbrains.kotlin:kotlin-stdlib:1.9.20")
            }
        }
    }
}
```

## Harmadik félnél cinterop könyvtárak támogatása

### Alapértelmezett támogatás
- Nincs szükség külön opt-in beállításra
- Pod könyvtárak elérhetők `iosMain` közös forráskészletből

## Kotlin/Native fordítási cache Compose Multiplatform projektekhez

### Korábbi workaround eltávolítva
```
# Törlendő a gradle.properties-ből
kotlin.native.cacheKind=none
```

## Kompatibilitási irányelvek

| Kotlin Multiplatform Gradle plugin | Gradle | AGP       | Xcode |
| ---------------------------------- | ------ | --------- | ----- |
| 1.9.20                             | 7.5+   | 7.4.2–8.2 | 15.0  |

**Ajánlott Xcode verzió:** 15.0

---

# Kotlin/Wasm 1.9.20

## Alpha szintű stabilitás elérve

### WebAssembly GC fázis 4 és végső opkódok támogatása

### Új célok
- `wasm-wasi` (új)
- `wasm-js` (korábbi `wasm` átnevezve)

```
kotlin {
    wasmWasi {
        // WASI specifikus konfiguráció
    }
    
    wasmJs {
        // JavaScript kompatibilis Wasm
    }
}
```

### WASI API támogatás standard libraryben

```
import kotlin.wasm.WasmImport

@WasmImport("wasi_snapshot_preview1", "clock_time_get")
private external fun wasiRawClockTimeGet(clockId: Int, precision: Long, resultPtr: Int): Int
```

### API fejlesztések
```
// Korábban
window.onload = {
    document.body?.sayHello()
    null // Visszatérési érték szükséges volt
}

// 1.9.20-tól
window.onload = {
    document.body?.sayHello()
    // Nincs szükség explicit null visszatérésre
}
```

**Megjegyzés:** JavaScript interoperabilitás nem elérhető `wasmWasi` célnál.

# Kotlin 1.9.20 Gradle és Standard Library fejlesztések

## Gradle fejlesztések

### Test fixture belső deklarációkhoz való hozzáférés

```
// 1.9.20-től a test fixtures hozzáférnek a main source set belső deklarációihoz
// Test forráskódok is látják a test fixtures belső deklarációit
```

### Új tulajdonság Konan könyvtárak elérési útjának konfigurálásához

```
# gradle.properties
kotlin.data.dir=/custom/path/to/konan
```

**Alternatív módszer:**
```
-Xkonan-data-dir=/custom/path/to/konan
```

### Új build report metrikák Kotlin/Native taskokhoz

**Példa build report kimenetre:**
```
Total time for Kotlin tasks: 20.81 s (93.1 % of all tasks time)
Time |% of Kotlin time|Task
15.24 s|73.2 % |:compileCommonMainKotlinMetadata
5.57 s |26.8 % |:compileNativeMainKotlinMetadata
```

## Standard Library fejlesztések

### Enum class values generikus függvény helyettesítése

```
enum class RGB { 
    RED, GREEN, BLUE 
}

@OptIn(ExperimentalStdlibApi::class)
inline fun <reified T : Enum<T>> printAllValues() {
    print(enumEntries<T>().joinToString { it.name })
}

printAllValues<RGB>() // RED, GREEN, BLUE
```

### Kotlin/Native standard library stabilizálva

**Főbb változások:**
- `Vector128` osztály áthelyezve: `kotlin.native` → `kotlinx.cinterop`
- `ExperimentalNativeApi` és `NativeRuntimeApi` annotációk: WARNING → ERROR szint
- Kotlin/Native kollekciók mostantól érzékelik az egyidejű módosításokat
- `printStackTrace()` most STDERR-re ír ki helyett STDOUT-ra

### Atomics API fejlesztések

```
@OptIn(ExperimentalStdlibApi::class)
fun atomicExample() {
    val intArray = AtomicIntArray(10)
    val longArray = AtomicLongArray(10)
    val objectArray = AtomicArray<String>(10)
}
```

**Elavult API-k:**
- `kotlin.native.concurrent` csomagban lévő Atomics API: WARNING → ERROR
- `kotlin.concurrent` csomagban lévő `AtomicInt` és `AtomicLong` függvények eltávolítva

## Dokumentáció fejlesztések

- JVM Metadata API referencia
- Időmérési útmutató
- Kollekciók fejezet fejlesztése a Kotlin útmutatóban
- Definitely non-nullable típusok
- Tömbök oldal fejlesztése
- Várható és aktuális deklarációk Kotlin Multiplatformban

---

# Kotlin 1.9.0 Újdonságok

## K2 Compiler fejlesztések

### JVM Beta státusz

### Kapt kompatibilitás K2-vel
```
# gradle.properties
kotlin.experimental.tryK2=true
```

### Gradle build reportok
```
##### 'kotlin.experimental.tryK2' results #####
:lib:compileKotlin: 2.0 language version
##### 100% (1/1) tasks have been compiled with Kotlin 2.0 #####
```

### K2 korlátozások (Gradle < 8.3)
- `buildSrc` forráskód fordítása
- Gradle plugin fordítás included buildsekben
- Gradle plugin függőségek építése

**Megoldás:**
```
kotlin {
    compilerOptions {
        languageVersion.set(org.jetbrains.kotlin.gradle.dsl.KotlinVersion.KOTLIN_1_9)
        apiVersion.set(org.jetbrains.kotlin.gradle.dsl.KotlinVersion.KOTLIN_1_9)
    }
}
```

## Nyelvi fejlesztések

### Stabil enum class entries tulajdonság

```
enum class Color(val colorName: String, val rgb: String) {
    RED("Red", "#FF0000"),
    ORANGE("Orange", "#FF7F00"),
    YELLOW("Yellow", "#FFFF00")
}

fun findByRgb(rgb: String): Color? = Color.entries.find { it.rgb == rgb }
```

### Stabil data objektumok

```
sealed interface ReadResult
data class Number(val number: Int) : ReadResult
data class Text(val text: String) : ReadResult
data object EndOfFile : ReadResult

fun main() {
    println(Number(7)) // Number(number=7)
    println(EndOfFile) // EndOfFile
}
```

### Másodlagos konstruktorok testtel inline value classokban

```
@JvmInline
value class Person(private val fullName: String) {
    init {
        check(fullName.isNotBlank()) { "Full name shouldn't be empty" }
    }
    
    constructor(name: String, lastName: String) : this("$name $lastName") {
        check(lastName.isNotBlank()) { "Last name shouldn't be empty" }
    }
}
```

## Kotlin/JVM

### JVM 20 bytecode támogatás

### JvmDefault annotáció elavult

## Kotlin/Native

### Egyedi memória allokátor előnézet

### Objective-C/Swift objektum deallokáció hook a fő szálon

### Konstans értékek elérése objektum inicializálás nélkül

### iOS szimulátor tesztek önálló mód konfigurálása

### Library linkage Kotlin/Native-ben

# Kotlin 1.9.0 Újdonságok - folytatás

## Kotlin/Native fejlesztések

### Egyedi memória allokátor előnézet

```
kotlin {
    macosX64("native") {
        binaries.executable()
        compilations.configureEach {
            compilerOptions.configure {
                freeCompilerArgs.add("-Xallocator=custom")
            }
        }
    }
}
```

### Objective-C/Swift objektum deallokációs hook a fő szálon

```
# Visszatérés a régi viselkedéshez
kotlin.native.binary.objcDisposeOnMain=false
```

### Konstans értékek elérése objektum inicializálás nélkül

```
object MyObject {
    init {
        println("side effect!")
    }
    const val y = 1
}

fun main() {
    println(MyObject.y) // Nincs inicializálás
    val x = MyObject   // Inicializálás történik
    println(x.y)
}
```

### iOS szimulátor tesztek önálló mód konfigurálása

```
tasks.withType<org.jetbrains.kotlin.gradle.targets.native.tasks.KotlinNativeSimulatorTest>().configureEach {
    standalone.set(false)
}
```

### Library linkage Kotlin/Native-ben

```
kotlin {
    macosX64("native") {
        binaries.executable()
        compilations.configureEach {
            compilerOptions.configure {
                // Linkage warningok elnyomása
                freeCompilerArgs.add("-Xpartial-linkage-loglevel=INFO")
                // Linkage warningok hibává emelése
                freeCompilerArgs.add("-Xpartial-linkage-loglevel=ERROR")
                // Funkció teljes letiltása
                freeCompilerArgs.add("-Xpartial-linkage=disable")
            }
        }
    }
}
```

### C interop implicit egész konverziók

```
tasks.withType<org.jetbrains.kotlin.gradle.tasks.KotlinNativeCompile>().configureEach {
    compilerOptions.freeCompilerArgs.addAll(
        "-XXLanguage:+ImplicitSignedToUnsignedIntegerConversion"
    )
}
```

## Kotlin Multiplatform fejlesztések

### Android cél támogatás változásai

```
// Korábban
kotlin {
    android()
}

// 1.9.0-tól
kotlin {
    androidTarget()
}
```

### Új Android forrás készlet elrendezés

**Előnyök:**
- Egyszerűsített típus szemantika
- Javított forráskönyvtár elrendezés
- Világos elnevezési séma Gradle konfigurációkhoz

### Gradle konfigurációs cache előnézet

**Támogatott:**
- Multiplatform könyvtárak

**Nem támogatott (még):**
- Xcode integrációs taskok
- Kotlin CocoaPods Gradle plugin

## Kotlin/Wasm fejlesztések

### Méret-optimalizálások

**Fejlesztés:** Több mint 10x kisebb kód lábnyom Kotlin 1.8.20-hoz képest

### JavaScript interoperabilitás frissítések

#### Dynamic típus korlátozása

```
// Korábban támogatott
val dynamicValue: dynamic = js("({})")

// 1.9.0-tól: elavult, helyette JsAny
val jsObject: JsAny = js("({})")
```

#### Nem-külső típusok korlátozása

**Támogatott típusok:**
- Primitívek (számok, Boolean, Char)
- String
- Függvény típusok

**Új típus:**
```
// JsReference - Kotlin/Wasm objektumok kezelésére
val reference: JsReference<MyClass> = createJsReference()
```

### Kotlin Playground támogatás

```
import kotlin.time.*
import kotlin.time.measureTime

fun main() {
    println("Hello from Kotlin/Wasm!")
    computeAck(3, 10)
}

tailrec fun ack(m: Int, n: Int): Int = when {
    m == 0 -> n + 1
    n == 0 -> ack(m - 1, 1)
    else -> ack(m - 1, ack(m, n - 1))
}

fun computeAck(m: Int, n: Int) {
    var res = 0
    val t = measureTime { res = ack(m, n) }
    println()
    println("ack($m, $n) = ${res}")
    println("duration: ${t.inWholeNanoseconds / 1e6} ms")
}
```

# Kotlin 1.9.0 Újdonságok - folytatás

## Kotlin/JS fejlesztések

### Régi Kotlin/JS compiler eltávolítva

### Kotlin/JS Gradle plugin elavult

```
// Korábban
plugins {
    kotlin("js") version "1.9.0"
}

// 1.9.0-tól
plugins {
    kotlin("multiplatform") version "1.9.0"
}

kotlin {
    js(IR) {
        browser()
    }
}
```

### External enum elavult

```
// Korábban
external enum class ExternalEnum {
    A, B
}

// 1.9.0-tól
external sealed class ExternalEnum {
    object A: ExternalEnum
    object B: ExternalEnum
}
```

### ES2015 osztályok és modulok Experimental támogatása

```
kotlin {
    js(IR) {
        useEsModules() // ES2015 modulok engedélyezése
        browser()
    }
}

tasks.withType<KotlinJsCompile>().configureEach {
    kotlinOptions {
        useEsClasses = true // ES2015 osztályok engedélyezése
    }
}
```

### JS produkciós disztribúció módosított elérési útja

**Új elérési út:**
```
build/dist/<targetName>/<binaryName>
```

**Példa:**
```
build/dist/js/productionExecutable  // Korábban: build/distributions
```

### org.w3c deklarációk külön függőségbe helyezve

## Gradle fejlesztések

### Eltávolított classpath property

### Új fordító beállítások

```
kotlin {
    compilerOptions {
        optIn.set(listOf("kotlin.RequiresOptIn"))
        progressiveMode.set(true)
    }
}
```

### Projekt szintű fordító beállítások Kotlin/JVM-hoz

```
kotlin {
    compilerOptions {
        jvmTarget.set(JVM.Target_11)
    }
}
```

### Kotlin/Native modul név beállítása

```
tasks.named<org.jetbrains.kotlin.gradle.tasks.KotlinNativeCompile>("compileKotlinLinuxX64") {
    compilerOptions {
        moduleName.set("my-module-name")
    }
}
```

### Különálló fordító pluginok hivatalos Kotlin könyvtárakhoz

**Új pluginok:**
- `kotlin-atomicfu-compiler-plugin`
- `kotlin-allopen-compiler-plugin`
- `kotlin-lombok-compiler-plugin`
- `kotlin-noarg-compiler-plugin`
- `kotlin-sam-with-receiver-compiler-plugin`
- `kotlinx-serialization-compiler-plugin`

### Minimum támogatott verzió emelése

**Minimum Android Gradle Plugin verzió:** 4.2.2

### Kapt nem okoz eager task létrehozást

```
// Custom konfiguráció esetén
tasks.named<KotlinJvmCompile>("compileKotlin") {
    // Egyedi konfiguráció
}

// Ugyanez szükséges a KaptGenerateStubs taskhoz is
tasks.named<KaptGenerateStubs>("kaptGenerateStubs") {
    // Ugyanaz az egyedi konfiguráció
}
```

### JVM cél validációs mód programmatikus konfigurálása

```
tasks.named<org.jetbrains.kotlin.gradle.tasks.KotlinJvmCompile>("compileKotlin") {
    jvmTargetValidationMode.set
    (org.jetbrains.kotlin.gradle.dsl.jvm.JvmTargetValidationMode.WARNING)
}
```

## Standard könyvtár fejlesztések

### Stabil ..< operátor nyitott tartományokhoz

```
// Korábban
for (number in 2 until 10) {
    if (number % 2 == 0) {
        print("$number ")
    }
}

// 1.9.0-tól
for (number in 2..<10) {
    if (number % 2 == 0) {
        print("$number ")
    }
}
```

### Stabil idő API

```
import kotlin.time.*
import kotlin.time.Duration.Companion.seconds

fun main() {
    // Idő mérése
    val timeSource = TimeSource.Monotonic
    val mark1 = timeSource.markNow()
    Thread.sleep(500)
    val mark2 = timeSource.markNow()
    
    val elapsed = mark2 - mark1
    println("Eltelt idő: $elapsed")
    
    // Timeout ellenőrzése
    val fiveSeconds = 5.seconds
    val deadline = mark1 + fiveSeconds
    println(deadline.hasPassedNow())
}
```

### HexFormat osztály

```
val hexFormat = HexFormat { 
    // Hexadecimális formázás beállítása
}
```

### @Volatile annotáció tágabb támogatása

### Regex capture group név alapján elérhető

```
val regex = Regex("(?<name>\\w+): (?<value>\\d+)")
val matchResult = regex.find("temperature: 25")
val name = matchResult?.groups?.get("name")?.value
val value = matchResult?.groups?.get("value")?.value
```

# Kotlin 1.9.0 Újdonságok - folytatás

## Kotlin/Native standard library áttekintés eredménye

### API változások

**Áthelyezett API-k:**
```
// Korábban elavult WARNING szinten
// IntelliJ IDEA automatikusan javasolja a helyettesítőt
```

**Stabilizált API-k:**
- Atomics API stabilizálva

**Experimental API-k:**
```
// kotlinx.cinterop most Experimental
@OptIn(ExperimentalForeignApi::class)
fun useCInterop() { /* ... */ }

@OptIn(BetaInteropApi::class)
fun useOtherInterop() { /* ... */ }
```

**Elavult API-k:**
- `Worker` osztály és kapcsolódó API-k
- `BitSet` osztály
- `kotlin.native.internal` csomag publikus API-jai

## Stabil @Volatile annotáció

```
// Korábban csak JVM-en működött
import kotlin.jvm.Volatile

// 1.9.0-tól stabil és multiplatform
import kotlin.concurrent.Volatile

class Counter {
    @Volatile
    private var count = 0
}
```

## Új közös függvény regex capture group eléréséhez

```
fun main() {
    val regex = """\b(?<city>[A-Za-z\s]+),\s(?<state>[A-Z]{2}):\s(?<areaCode>[0-9]{3})\b""".toRegex()
    val input = "Coordinates: Austin, TX: 123"
    val match = regex.find(input)!!
    
    println(match.groups["city"]?.value)    // Austin
    println(match.groups["state"]?.value)   // TX
    println(match.groups["areaCode"]?.value) // 123
}
```

## Új elérési út segédprogram szülő könyvtárak létrehozásához

```
sourcePath.copyToRecursively(
    destinationPath.createParentDirectories(),
    followLinks = false
)
```

## Új HexFormat osztály hexadecimális formázáshoz és elemzéshez

```
@OptIn(ExperimentalStdlibApi::class)
fun hexExample() {
    println(93.toHexString()) // "0000005d"
    
    val macAddress = "001b638445e6".hexToByteArray()
    
    // HexFormat builder használata kettősponttal elválasztva
    println(macAddress.toHexString(HexFormat {
        bytes.byteSeparator = ":"
    })) // "00:1b:63:84:45:e6"
    
    // HexFormat builder használata:
    // * Nagybetűs hexadecimális
    // * Bajtok párokba csoportosítva
    // * Pontokkal elválasztva
    val threeGroupFormat = HexFormat {
        upperCase = true
        bytes.bytesPerGroup = 2
        bytes.groupSeparator = "."
    }
    println(macAddress.toHexString(threeGroupFormat)) // "001B.6384.45E6"
    
    // Prefix használata hexadecimális elemzéshez
    println("0x3a".hexToInt(HexFormat {
        number.prefix = "0x"
    })) // "58"
}
```

## Dokumentáció frissítések

- Kotlin útmutató
- Android forrás készlet elrendezés
- Kotlin Multiplatform kompatibilitási útmutató
- Kotlin/Wasm dokumentáció

---

# Kotlin 1.8.20 Újdonságok

## K2 Compiler fejlesztések

### Új funkciók
- Serialization plugin előnézet
- JS IR compiler Alpha támogatás
- Kotlin 2.0 nyelvi verzió előnézet

### K2 engedélyezése
```
kotlin {
    sourceSets.all {
        languageSettings {
            languageVersion = "2.0"
        }
    }
}
```

## Nyelvi fejlesztések

### Modern és hatékony Enum class values helyettesítő

```
enum class Color(val colorName: String, val rgb: String) {
    RED("Red", "#FF0000"),
    ORANGE("Orange", "#FF7F00"),
    YELLOW("Yellow", "#FFFF00")
}

@OptIn(ExperimentalStdlibApi::class)
fun findByRgb(rgb: String): Color? = Color.entries.find { it.rgb == rgb }
```

### Data objektumok előnézet

```
package org.example
object MyObject
data object MyDataObject

fun main() {
    println(MyObject)      // org.example.MyObject@1f32e575
    println(MyDataObject) // MyDataObject
}

// Sealed hierarchiákban
sealed interface ReadResult
data class Number(val number: Int) : ReadResult
data class Text(val text: String) : ReadResult
data object EndOfFile : ReadResult

fun main() {
    println(Number(7)) // Number(number=7)
    println(EndOfFile) // EndOfFile
}
```

**Data objektum szemantika:**
```
data object MyDataObject {
    val x: Int = 3
}

// equals és hashCode konzisztens minden runtime példányra
// toString visszaadja az egyszerű nevet
```

### Másodlagos konstruktorok testtel inline osztályokban

```
@JvmInline
value class Person(private val fullName: String) {
    constructor(name: String, lastName: String) : this("$name $lastName") {
        // Testtel rendelkező másodlagos konstruktor
    }
}
```

## Gradle fejlesztések

### JVM inkrementális fordítás alapértelmezett

### Kotlin/Native célok frissítése

### Gradle kompozit build előnézet Kotlin Multiplatformban

### Javított hibakimenet Gradle hibákhoz Xcode-ben

## Standard könyvtár fejlesztések

### Experimental AutoCloseable interfész

```
@ExperimentalStdlibApi
interface AutoCloseable {
    fun close()
}
```

### Experimental Base64 kódolás

```
@OptIn(ExperimentalStdlibApi::class)
fun base64Example() {
    val encoded = "Hello World".encodeToByteArray().encodeBase64()
    val decoded = encoded.decodeBase64().decodeToString()
}
```

## IDE támogatás

- IntelliJ IDEA 2022.2.x, 2022.3.x, 2023.1.x
- Android Studio Flamingo (222)

Igen, a Groovy részeket is leírtam, ahol azok az eredeti anyagokban szerepeltek. Például:

1. **Kotlin/Native modul név beállítása Groovy-ban:**
```
tasks.named("compileKotlinLinuxX64", org.jetbrains.kotlin.gradle.tasks.KotlinNativeCompile.class) {
    compilerOptions {
        moduleName = "my-module-name"
    }
}
```

2. **K2 compiler engedélyezése Groovy-val:**
```
tasks .withType(org.jetbrains.kotlin.gradle.tasks.KotlinCompilationTask.class)
    .configureEach {
        compilerOptions.languageVersion = org.jetbrains.kotlin.gradle.dsl.KotlinVersion.KOTLIN_1_9
    }
```

3. **Data objects előnézet Groovy konfiguráció:**
```
tasks .withType(org.jetbrains.kotlin.gradle.tasks.KotlinCompilationTask.class)
    .configureEach {
        compilerOptions.languageVersion = org.jetbrains.kotlin.gradle.dsl.KotlinVersion.KOTLIN_1_9
    }
```

# Kotlin 1.8.20 Újdonságok - teljes fordítás

## Inline osztályok másodlagos konstruktorai testtel

```
@JvmInline
value class Person(private val fullName: String) {
    // Engedélyezve Kotlin 1.4.30 óta:
    init {
        check(fullName.isNotBlank()) {
            "Full name shouldn't be empty"
        }
    }
    
    // Előnézet elérhető Kotlin 1.8.20 óta:
    constructor(name: String, lastName: String) : this("$name $lastName") {
        check(lastName.isNotBlank()) {
            "Last name shouldn't be empty"
        }
    }
}
```

### Másodlagos konstruktorok engedélyezése testtel

```
// Kotlin
tasks.withType<org.jetbrains.kotlin.gradle.tasks.KotlinCompilationTask<*>>()
    .configureEach {
        compilerOptions.languageVersion
            .set(org.jetbrains.kotlin.gradle.dsl.KotlinVersion.KOTLIN_1_9)
    }

// Groovy
tasks.withType(org.jetbrains.kotlin.gradle.tasks.KotlinCompilationTask.class)
    .configureEach {
        compilerOptions.languageVersion = org.jetbrains.kotlin.gradle.dsl.KotlinVersion.KOTLIN_1_9
    }
```

## Új Kotlin/Wasm cél

### Kotlin/Wasm előnyök:
- Gyorsabb fordítás a wasm32 Kotlin/Native célhoz képest (nem használ LLVM-et)
- Könnyebb JS interoperabilitás és böngésző integráció a Wasm garbage collection köszönhetően
- Potenciálisan gyorsabb alkalmazás indulás Kotlin/JS és JavaScript-hez képest
- Javított futásidejű teljesítmény Kotlin/JS és JavaScript-hez képest

### Kotlin/Wasm engedélyezése

```
plugins {
    kotlin("multiplatform") version "1.8.20"
}

kotlin {
    wasm {
        binaries.executable()
        browser {
        }
    }
    
    sourceSets {
        val commonMain by getting
        val commonTest by getting {
            dependencies {
                implementation(kotlin("test"))
            }
        }
        val wasmMain by getting
        val wasmTest by getting
    }
}
```

### Böngésző beállítások:
**Chrome (verzió 110+):**
1. Menj ide: `chrome://flags/#enable-webassembly-garbage-collection`
2. Engedélyezd a WebAssembly Garbage Collection-t
3. Indítsd újra a böngészőt

**Firefox (verzió 109+):**
1. Menj ide: `about:config`
2. Engedélyezd: `javascript.options.wasm_function_references` és `javascript.options.wasm_gc`
3. Indítsd újra a böngészőt

## Kotlin/JVM fejlesztések

### Java szintetikus property referenciák előnézete

```
// Java kód
public class Person {
    private String name;
    private int age;
    
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    
    public String getName() {
        return name;
    }
    
    public int getAge() {
        return age;
    }
}
```

```
val persons = listOf(Person("Jack", 11), Person("Sofie", 12), Person("Peter", 11))

persons
    // Referencia létrehozása Java szintetikus propertyhez:
    .sortedBy(Person::age)
    // Java getter hívása Kotlin property szintaxis használatával:
    .forEach { person -> println(person.name) }
```

### JVM IR backend támogatás kapt stub generáló taskban

A `kapt.use.jvm.ir=true` beállítás már nem szükséges `gradle.properties` fájlban.

## Kotlin/Native fejlesztések

### Elavult célok (eltávolítás 1.9.20-ban):
- `iosArm32`
- `watchosX86`
- `wasm32`
- `mingwX86`
- `linuxArm32Hfp`
- `linuxMips32`
- `linuxMipsel32`

### Legacy memória menedzser elavult

### Objective-C header támogatás @import direktívákkal

```
kotlin {
    ios()
    cocoapods {
        summary = "CocoaPods test library"
        homepage = "https://github.com/JetBrains/kotlin"
        ios.deploymentTarget = "13.5"
        pod("PodName") {
            extraOpts = listOf("-compiler-option", "-fmodules")
        }
    }
}
```

### Link-only mód Cocoapods Gradle pluginban

```
cocoapods {
    summary = "CocoaPods test library"
    homepage = "https://github.com/JetBrains/kotlin"
    pod("Alamofire", linkOnly = true) {
        version = "5.7.0"
    }
}
```

### Objective-C kiterjesztések importálása osztály tagként UIKit-ben

### Fordító gyorsítótár menedzsment újraimplementálása

Visszatérés a régi viselkedéshez:
```
kotlin.native.cacheOrchestration=gradle
```

### useLibraries() elavult Cocoapods Gradle pluginban

## Kotlin Multiplatform fejlesztések

### Új megközelítés forrás készlet hierarchiához

```
@OptIn(ExperimentalKotlinGradlePluginApi::class)
kotlin {
    // Alapértelmezett cél hierarchia engedélyezése:
    targetHierarchy.default()
    android()
    iosArm64()
    iosSimulatorArm64()
}
```

### Gradle kompozit build előnézet támogatása

### Javított kimenet Gradle hibákhoz Xcode-ben

## IDE támogatás

- IntelliJ IDEA 2022.2.x, 2022.3.x, 2023.1.x
- Android Studio Flamingo (222)

---

# Kotlin 1.8.20 Újdonságok - folytatás

## Gradle kompozit build előnézet támogatás Kotlin Multiplatformban

```
# Előnézet engedélyezése
kotlin.mpp.import.enableKgpDependencyResolution=true
```

### Ismert problémák:
- Nincs Kotlin 1.8.20 plugin IntelliJ IDEA 2023.1 EAP-hez
- `rootProject.name` használata kompozit build-ekben problémát okozhat

## Javított kimenet Gradle hibákhoz Xcode-ben

```
# Új viselkedés alapértelmezett
kotlin.native.useXcodeMessageStyle=true
```

## Kotlin/JavaScript fejlesztések

### Dukat integráció eltávolítva Gradle pluginból

### Kotlin változó és függvény nevek source map-ben

```
tasks.withType<org.jetbrains.kotlin.gradle.tasks.Kotlin2JsCompile>().configureEach {
    compilerOptions.sourceMapNamesPolicy.set(
        org.jetbrains.kotlin.gradle.dsl.JsSourceMapNamesPolicy.SOURCE_MAP_NAMES_POLICY_FQ_NAMES
        // vagy SOURCE_MAP_NAMES_POLICY_NO
        // vagy SOURCE_MAP_NAMES_POLICY_SIMPLE_NAMES
    )
}
```

### TypeScript definíciós fájlok generálása

```
kotlin {
    js {
        binaries.executable()
        browser {
        }
        generateTypeScriptDefinitions()
    }
}
```

## Gradle fejlesztések

### Új Gradle plugin verzió igazítás

### Új JVM inkrementális fordítás alapértelmezetten

```
# Már nem szükséges
kotlin.incremental.useClasspathSnapshot=true
```

### Precíz backup fordítási task kimenetekhez

```
kotlin.compiler.preciseCompilationResultsBackup=true
```

### Lazy Kotlin/JVM task létrehozás minden Gradle verzióhoz

### Nem alapértelmezett hely compile task destinationDirectory

```
tasks.jar(type: Jar) {
    from sourceSets.main.outputs
    from sourceSets.main.kotlin.classesDirectories
}
```

### Opció kikapcsolni compiler argumentumok jelentését

```
kotlin.build.report.include_compiler_arguments=false
```

## Standard könyvtár fejlesztések

### AutoCloseable interfész támogatás

```
@OptIn(ExperimentalStdlibApi::class)
interface XMLWriter : AutoCloseable {
    fun document(encoding: String, version: String, content: XMLWriter.() -> Unit)
    fun element(name: String, content: XMLWriter.() -> Unit)
    fun attribute(name: String, value: String)
    fun text(value: String)
}

@OptIn(ExperimentalStdlibApi::class)
fun writeBooksTo(writer: XMLWriter) {
    writer.use { xml ->
        xml.document(encoding = "UTF-8", version = "1.0") {
            element("bookstore") {
                element("book") {
                    attribute("category", "fiction")
                    element("title") { text("Harry Potter and the Prisoner of Azkaban") }
                    element("author") { text("J. K. Rowling") }
                    element("year") { text("1999") }
                    element("price") { text("29.99") }
                }
            }
        }
    }
}
```

### Base64 kódolás és dekódolás

```
@OptIn(ExperimentalEncodingApi::class)
fun base64Example() {
    val foBytes = "fo".map { it.code.toByte() }.toByteArray()
    Base64.Default.encode(foBytes) // "Zm8="
    
    val foobarBytes = "foobar".map { it.code.toByte() }.toByteArray()
    Base64.UrlSafe.encode(foobarBytes) // "Zm9vYmFy"
    
    Base64.Default.decode("Zm8=") // foBytes
    Base64.UrlSafe.decode("Zm9vYmFy") // foobarBytes
}
```

### @Volatile támogatás Kotlin/Native-ben

```
@OptIn(ExperimentalStdlibApi::class)
class Counter {
    @Volatile
    private var count = 0
}
```

### Bug javítás stack overflow regex használatnál Kotlin/Native-ben

## Serialization frissítések

### K2 compiler Alpha támogatás

### Implicit serializer testreszabás tiltása companion object-en keresztül

```
// Korábban engedélyezett, de félreérthető
@Serializable
class Foo(val a: Int) {
    @Serializer(Foo::class)
    companion object {
        // Egyedi KSerializer<Foo> implementáció
    }
}

// 1.8.20-tól: compiler warning
// Javasolt megoldás:
@Serializable(with = FooSerializer::class)
class Foo(val a: Int)

object FooSerializer : KSerializer<Foo> {
    // Implementáció
}
```

---

# Kotlin 1.8.0 Újdonságok - teljes fordítás

## Kotlin/JS Serialization megoldás

```
// Egyértelmű megközelítés - custom serializer használata
@Serializable(with = Foo.Companion::class)
class Foo(val a: Int) {
    // Nem számít, használjuk-e @Serializer(Foo::class) vagy sem
    companion object : KSerializer<Foo> {
        // Egyedi KSerializer<Foo> implementáció
    }
}
```

## Dokumentáció frissítések
- Spring Boot és Kotlin használata
- Scope függvények
- CocoaPods integráció

## IDE támogatás
- IntelliJ IDEA 2021.3, 2022.1, 2022.2
- Android Studio Electric Eel (221), Flamingo (222)

## Kotlin/JVM fejlesztések

### JVM 19 bytecode támogatás

### Új compiler opciók:
```
// TYPE_USE és TYPE_PARAMETER célok kikapcsolása
-Xno-new-java-annotation-targets

// Optimalizálások kikapcsolása debugoláshoz
-Xdebug
```

### Lombok @Builder annotáció támogatás

### Régi backend eltávolítva
- `-Xuse-old-backend` opció eltávolítva
- `useOldBackend` Gradle opció eltávolítva

## Kotlin/Native fejlesztések

### Xcode 14.1 támogatás
- Új `watchosDeviceArm64` preset

### Javított Objective-C/Swift interoperabilitás

```
// @ObjCName - idiomatikus név Swift/Objective-C-ben
@ObjCName(swiftName = "MySwiftArray")
class MyKotlinArray {
    @ObjCName("index")
    fun indexOf(@ObjCName("of") element: String): Int = TODO()
}

// @HiddenFromObjC - Kotlin deklaráció elrejtése Objective-C-ből
@HiddenFromObjC
fun hiddenFunction() { }

// @ShouldRefineInSwift - Swift wrapperrel való helyettesítés
@ShouldRefineInSwift
fun refineInSwift() { }
```

### Dinamikus keretrendszerek alapértelmezett CocoaPods pluginban

```
kotlin {
    cocoapods {
        framework {
            baseName = "MyFramework"
            isStatic = false // Dinamikus alapértelmezetten
        }
    }
}
```

## Kotlin Multiplatform: Új Android forrás készlet elrendezés

### Kulcsfontosságú különbségek:

| Régi elrendezés    | Új elrendezés           |
| ------------------ | ----------------------- |
| androidMain        | androidMain             |
| androidTest        | androidUnitTest         |
| androidAndroidTest | androidInstrumentedTest |

### Forrás könyvtárak:

**Új elrendezés:**
- `src/androidMain/kotlin`
- `src/androidUnitTest/kotlin`
- `src/androidInstrumentedTest/kotlin`

### AndroidManifest.xml helye:
- `src/androidMain/AndroidManifest.xml`

### Android és közös tesztek kapcsolata:

```
kotlin {
    sourceSets {
        val commonTest by getting
        val androidInstrumentedTest by getting {
            dependsOn(commonTest) // Manuális deklarálás szükséges
        }
    }
}
```

### Android flavor támogatás:

```
kotlin {
    sourceSets.invokeWhenCreated("androidFreeDebug") {
        // ... 
    }
}
```

### Új elrendezés engedélyezése:

```
kotlin.mpp.androidSourceSetLayoutVersion=2
```

## Kotlin/JS fejlesztések

### Stabil JS IR compiler backend

### Új yarn.lock beállítások:

```
import org.jetbrains.kotlin.gradle.targets.js.yarn.YarnLockMismatchReport
import org.jetbrains.kotlin.gradle.targets.js.yarn.YarnRootExtension

rootProject.plugins.withType
(org.jetbrains.kotlin.gradle.targets.js.yarn.YarnPlugin::class.java) {
    rootProject.the<YarnRootExtension>().yarnLockMismatchReport = YarnLockMismatchReport.WARNING
    rootProject.the<YarnRootExtension>().reportNewYarnLock = false
    rootProject.the<YarnRootExtension>().yarnLockAutoReplace = false
}
```

### Böngésző teszt célok Gradle properties-ben:

```
kotlin.js.browser.karma.browsers=firefox,safari
```

### CSS támogatás új megközelítése:

```
// Régi megközelítés
browser {
    commonWebpackConfig {
        cssSupport.enabled = true
    }
}

// Új megközelítés
browser {
    commonWebpackConfig {
        cssSupport {
            enabled.set(true)
        }
    }
}
```

## Gradle fejlesztések

### Kotlin compiler opciók Gradle lazy properties-ként:

```
tasks.named("compileKotlin", org.jetbrains.kotlin.gradle.tasks.KotlinJvmCompile::class.java) {
    compilerOptions {
        useK2.set(true)
    }
}
```

---

# Kotlin 1.7.20 Újdonságok - teljes fordítás

## Gradle fejlesztések - folytatás

### JsModuleKind és JsSourceMapEmbedMode típusok

```
// Példa: compilerOptions használata típusos értékekkel
tasks.named("compileKotlin", org.jetbrains.kotlin.gradle.tasks.KotlinJvmCompile::class.java) {
    compilerOptions {
        jvmTarget.set(JvmTarget.JVM_11) // Típusos érték String helyett
    }
}

// Régi megközelítés:
kotlinOptions.jvmTarget = "11"
```

### Korlátozások:

```
# Warning letiltása kotlinOptions módosításakor
kotlin.options.suppressFreeCompilerArgsModificationWarning=true
```

### Kotlin daemon fallback stratégia letiltása:

```
# Daemon fallback stratégia letiltása
kotlin.daemon.useFallbackStrategy=false
```

```
// Task szintű beállítás (elsőbbséget élvez a Gradle property-nél)
tasks.withType<KotlinCompile>().configureEach {
    useDaemonFallbackStrategy.set(false)
}
```

### Új minimális támogatott verziók:
- Gradle: 6.8.3
- Android Gradle plugin: 4.1.3

### Kotlin stdlib verzió igazítás:

```
# Verzió igazítás letiltása
kotlin.stdlib.jdk.variants.version.alignment=false
```

```
// Kotlin BOM használata verzió igazításhoz
implementation(platform("org.jetbrains.kotlin:kotlin-bom:1.8.0"))
```

### JVM cél ellenőrzés:

```
# JVM cél kompatibilitás ellenőrzése hibaként
kotlin.jvm.target.validation.mode=error
```

### Kotlin Gradle plugin tranzitív függőségek feloldása:

```
dependencies {
    constraints {
        implementation("org.jetbrains.kotlin:kotlin-sam-with-receiver:1.8.0")
    }
}
```

### Elavult és eltávolított funkciók:
- `KotlinCompile.classpath` property - hiba szintre emelve
- `kapt.use.worker.api` property - eltávolítva
- `kotlin.compiler.execution.strategy` property - eltávolítva

## Standard könyvtár fejlesztések

### Frissített JVM compilation cél: 1.8

### cbrt() függvény stabilizálva:

```
import kotlin.math.*

fun main() {
    val num = 27
    val negNum = -num
    println("The cube root of ${num.toDouble()} is: " + cbrt(num.toDouble()))
    println("The cube root of ${negNum.toDouble()} is: " + cbrt(negNum.toDouble()))
}
```

### TimeUnit konverzió stabilizálva:

```
import kotlin.time.*

// Java-ból használathoz
fun wait(timeout: Long, unit: TimeUnit) {
    val duration: Duration = timeout.toDuration(unit.toDurationUnit())
    // ...
}
```

### Összehasonlítható és kivonható TimeMarks (Experimental):

```
@OptIn(ExperimentalTime::class)
fun main() {
    val timeSource = TimeSource.Monotonic
    val mark1 = timeSource.markNow()
    Thread.sleep(500) // 0.5 másodperc
    val mark2 = timeSource.markNow()
    
    // Új megközelítés 1.8.0-tól
    repeat(4) { n ->
        val mark3 = timeSource.markNow()
        val elapsed1 = mark3 - mark1
        val elapsed2 = mark3 - mark2
        println("Measurement ${n + 1}: elapsed1=$elapsed1, elapsed2=$elapsed2, diff=${elapsed1 - elapsed2}")
    }
    
    // TimeMarks összehasonlítása
    println(mark2 > mark1) // true, mivel mark2 később lett rögzítve
}
```

### Rekurzív könyvtár másolás és törlés (Experimental):

```
@OptIn(kotlin.io.path.ExperimentalPathApi::class)
fun fileOperations() {
    // Rekurzív másolás
    sourceRoot.copyToRecursively(destinationRoot, followLinks = false)
    
    // Rekurzív törlés
    directoryPath.deleteRecursively()
    
    // Hibakezelés másolásnál
    sourceRoot.copyToRecursively(destinationRoot, followLinks = false, onError = { source, target, exception ->
        logger.logError(exception, "Failed to copy $source to $target")
        OnErrorResult.TERMINATE
    })
    
    // Fájl felülírás
    sourcePath.copyToRecursively(destinationPath, followLinks = false, overwrite = true)
    
    // Egyedi másolási művelet
    sourceRoot.copyToRecursively(destinationRoot, followLinks = false) { source, target ->
        if (source.name.startsWith(".")) {
            CopyActionResult.SKIP_SUBTREE
        } else {
            source.copyToIgnoringExistingDirectory(target, followLinks = false)
            CopyActionResult.CONTINUE
        }
    }
}
```

### Java Optionals kiterjesztés függvények stabilizálva

### Javított kotlin-reflect teljesítmény

## Dokumentáció frissítések
- Gradle áttekintés
- Nullabilitás Java és Kotlin között
- Lincheck útmutató
- Új és frissített oktatóanyagok

## Kompatibilitási útmutató
Részletes lista az 1.8.0 verzió inkompatibilis változásairól.

---

# Kotlin 1.7.20 Újdonságok

## K2 Compiler plugin támogatás

### Támogatott pluginok:
- all-open
- no-arg
- SAM with receiver
- Lombok
- AtomicFU
- jvm-abi-gen

### K2 compiler engedélyezése:

```
// Kotlin
tasks.withType<KotlinCompile> {
    kotlinOptions.useK2 = true
}

// Groovy
compileKotlin {
    kotlinOptions.useK2 = true
}
```

Compiler opció: `-Xuse-k2`

**K2 compiler csak JVM projektekhez támogatott Alpha verzióban.**

---

# Kotlin 1.7.20 Újdonságok - folytatás

## Nyelvi fejlesztések

### ..< operátor nyílt tartományokhoz (Experimental)

```
@OptIn(ExperimentalStdlibApi::class)
fun rangeExample(value: Double) {
    when (value) {
        in 0.0..<0.25 -> // Első negyed
        in 0.25..<0.5 -> // Második negyed
        in 0.5..<0.75 -> // Harmadik negyed
        in 0.75..1.0 -> // Utolsó negyed (zárt tartomány)
    }
}

// Új OpenEndRange interfész
interface OpenEndRange<T : Comparable<T>> {
    val start: T
    val endExclusive: T
    operator fun contains(value: T): Boolean = value >= start && value < endExclusive
    fun isEmpty(): Boolean = start >= endExclusive
}

// rangeUntil operátorok
operator fun <T : Comparable<T>> T.rangeUntil(that: T): OpenEndRange<T> = OpenEndRangeImpl(this, that)
```

### Data object deklarációk (Experimental)

```
package org.example

object MyObject
data object MyDataObject

fun main() {
    println(MyObject) // org.example.MyObject@1f32e575
    println(MyDataObject) // MyDataObject
}

// Sealed class hierarchiákban ideális
sealed class ReadResult {
    data class Number(val value: Int) : ReadResult()
    data class Text(val value: String) : ReadResult()
    data object EndOfFile : ReadResult()
}

fun main() {
    println(ReadResult.Number(1)) // Number(value=1)
    println(ReadResult.Text("Foo")) // Text(value=Foo)
    println(ReadResult.EndOfFile) // EndOfFile
}
```

### Data object engedélyezése:

```
// Kotlin
tasks.withType<org.jetbrains.kotlin.gradle.tasks.KotlinCompile>().configureEach {
    kotlinOptions.languageVersion = "1.9"
}

// Groovy
compileKotlin {
    kotlinOptions.languageVersion = '1.9'
}
```

### Új builder típus inferencia korlátozások

```
// Probléma: típus kikövetkeztetés nem lehetséges lambda elemzés nélkül
fun test() {
    buildList { // HIBA: explicit típus szükséges
        this.add(Data())
        this.get(0).doSmth()
    }
}

// Javítás: explicit típus megadása
fun test() {
    buildList<Data> {
        this.add(Data())
        this.get(0).doSmth() // Most helyesen feloldódik
    }
}

// Több lambda esetén is szükséges explicit típus
fun main() {
    buildList<Int>( // Explicit típus szükséges
        first = {
            add(0)
        },
        second = {
            val i: Int = get(0)
            println(i)
        }
    )
}
```

## Kotlin/JVM fejlesztések

### Generikus inline osztályok (Experimental)

```
@JvmInline
value class UserId<T>(val value: T)

fun compute(s: UserId<String>) {} 
// Compiler generál: fun compute-<hashcode>(s: Any?)
```

Engedélyezés: `-language-version 1.8` compiler opció

### Optimalizált delegated property esetek

```
// Named object - $delegate mező elhagyva
object NamedObject {
    operator fun getValue(thisRef: Any?, property: KProperty<*>): String = ...
}
val s: String by NamedObject

// Final val property - $delegate mező elhagyva
val impl: ReadOnlyProperty<Any?, String> = ...
class A {
    val s: String by impl
}

// Constant expression, enum entry, this, vagy null - $delegate elhagyva
class A {
    operator fun getValue(thisRef: Any?, property: KProperty<*>) ...
    val s by this
}
```

### JVM IR backend támogatás kapt stub generálásban

```
# IR backend engedélyezése kapt-ban
kapt.use.jvm.ir=true
```

## Kotlin/Native fejlesztések

### Új alapértelmezett memória menedzser (Beta)

```
# Új memória menedzser alapértelmezett
# Eltávolítható: kotlin.native.binary.memoryModel=experimental

# Visszatérés a régi menedzserhez (nem ajánlott)
kotlin.native.binary.memoryModel=strict
```

### Freezing elavult

```
// Freezing elavult - ne használjuk hacsak nem szükséges
@OptIn(FreezingIsDeprecated::class)
fun legacyCode() {
    // freezing használata
}

// Gradle szintű elavult warning letiltása
kotlin {
    sourceSets.all {
        languageSettings.optIn("kotlin.native.FreezingIsDeprecated")
    }
}
```

### Kotlin suspend függvények hívása Swift/Objective-C-ből

```
# Thread korlátozás eltávolítása (óvatosan használjuk!)
kotlin.native.binary.objcExportSuspendFunctionLaunchThreadRestriction=none
```

### Info.plist testreszabás

```
kotlin {
    ios()
    binaries.framework {
        // Binary opciók
        binaryOption("bundleId", "com.example.myapp")
        binaryOption("bundleShortVersionString", "1.0.0")
        binaryOption("bundleVersion", "1")
        
        // Vagy compiler flag
        // -Xbinary=bundleId=com.example.myapp
    }
}
```

## Kotlin/JS fejlesztések

### Javított teljesítmény
- Klib generálás gyorsabb inkrementális és tiszta build-eknél
- .d.ts generálás javítva beágyazott objektumokhoz, sealed osztályokhoz

## Gradle fejlesztések

### Új JVM toolchain konfiguráció

```
kotlin {
    // Egyszerű konfiguráció
    jvmToolchain(17)
    
    // Részletes konfiguráció (régi módszer)
    jvmToolchain {
        languageVersion.set(JavaLanguageVersion.of(17))
    }
}

// Forráskönyvtárak konfigurálása
sourceSets {
    main {
        kotlin {
            java.setSrcDirs(listOf("src/java"))
            kotlin.setSrcDirs(listOf("src/kotlin"))
        }
    }
}
```

## Standard könyvtár fejlesztések

### Új fájlrendszer bejáró függvények (Experimental)

```
@OptIn(kotlin.io.path.ExperimentalPathApi::class)
fun fileSystemTraversal() {
    // FileVisitor létrehozása és használata
    val cleanVisitor = fileVisitor {
        onPreVisitDirectory { directory, attributes ->
            // Könyvtárak bejárásának logikája
            FileVisitResult.CONTINUE
        }
        onVisitFile { file, attributes ->
            // Fájlok bejárásának logikája
            FileVisitResult.CONTINUE
        }
    }
    projectDirectory.visitFileTree(cleanVisitor)
    
    // FileVisitor builderrel azonnali használatra
    projectDirectory.visitFileTree {
        onPreVisitDirectory { directory, attributes ->
            FileVisitResult.CONTINUE
        }
        onVisitFile { file, attributes ->
            FileVisitResult.CONTINUE
        }
    }
    
    // Fájlfa bejárása walk() függvénnyel
    projectDirectory.walk().forEach { path ->
        println(path)
    }
}
```

---

# Kotlin 1.7.0 Újdonságok - teljes fordítás

## Fájlrendszer bejáró függvények példa

```
@OptIn(kotlin.io.path.ExperimentalPathApi::class)
fun traverseFileTree() {
    val cleanVisitor = fileVisitor {
        onPreVisitDirectory { directory, _ ->
            if (directory.name == "build") {
                directory.toFile().deleteRecursively()
                FileVisitResult.SKIP_SUBTREE
            } else {
                FileVisitResult.CONTINUE
            }
        }
        onVisitFile { file, _ ->
            if (file.extension == "class") {
                file.deleteExisting()
            }
            FileVisitResult.CONTINUE
        }
    }
    
    val rootDirectory = createTempDirectory("Project")
    
    // Könyvtárstruktúra létrehozása és fájlok hozzáadása
    rootDirectory.resolve("src").let { srcDirectory ->
        srcDirectory.createDirectory()
        srcDirectory.resolve("A.kt").createFile()
        srcDirectory.resolve("A.class").createFile()
    }
    
    rootDirectory.resolve("build").let { buildDirectory ->
        buildDirectory.createDirectory()
        buildDirectory.resolve("Project.jar").createFile()
    }
    
    // walk() függvény használata
    val directoryStructure = rootDirectory.walk(PathWalkOption.INCLUDE_DIRECTORIES)
        .map { it.relativeTo(rootDirectory).toString() }
        .toList().sorted()
    
    rootDirectory.visitFileTree(cleanVisitor)
    
    val directoryStructureAfterClean = rootDirectory.walk(PathWalkOption.INCLUDE_DIRECTORIES)
        .map { it.relativeTo(rootDirectory).toString() }
        .toList().sorted()
}
```

## Dokumentáció frissítések
- Alaptípusok áttekintés
- IDE-k Kotlin fejlesztéshez
- Native és cross-platform app fejlesztés összehasonlítás
- Legjobb cross-platform keretrendszerek
- Új és frissített oktatóanyagok

## Kotlin 1.7.0 főbb újdonságok

### Új K2 compiler Alpha verzióban (csak JVM)

```
# K2 compiler engedélyezése
-Xuse-k2
```

Teljesítményjavulás:
- Kotlin: 2.2x gyorsabb
- YouTrack: 2.3x gyorsabb
- IntelliJ IDEA: 2.2x gyorsabb
- Space: 2.3x gyorsabb

### Nyelvi fejlesztések

#### Implementation by delegation inlined inline class értékre

```
interface Bar {
    fun foo() = "foo"
}

@JvmInline
value class BarWrapper(val bar: Bar): Bar by bar

fun main() {
    val bw = BarWrapper(object: Bar {})
    println(bw.foo())
}
```

#### Underscore operátor típus argumentumokhoz

```
abstract class SomeClass<T> {
    abstract fun execute(): T
}

class SomeImplementation : SomeClass<String>() {
    override fun execute(): String = "Test"
}

class OtherImplementation : SomeClass<Int>() {
    override fun execute(): Int = 42
}

object Runner {
    inline fun <reified S: SomeClass<T>, T> run(): T {
        return S::class.java.getDeclaredConstructor().newInstance().execute()
    }
}

fun main() {
    // T kikövetkeztetve String-ként
    val s = Runner.run<SomeImplementation, _>()
    assert(s == "Test")
    
    // T kikövetkeztetve Int-ként
    val n = Runner.run<OtherImplementation, _>()
    assert(n == 42)
}
```

#### Stabilizált builder inference

```
// Nincs szükség -Xenable-builder-inference opcióra
fun <T> buildList(builder: MutableList<T>.() -> Unit): List<T> {
    val list = mutableListOf<T>()
    list.builder()
    return list
}
```

#### Stabilizált opt-in követelmények

```
// Nincs szükség -opt-in=kotlin.RequiresOptIn-ra
@RequiresOptIn
annotation class MyExperimentalApi

@MyExperimentalApi
fun experimentalFunction() {}

@OptIn(MyExperimentalApi::class)
fun useExperimental() {
    experimentalFunction()
}
```

#### Stabilizált definitely non-nullable típusok

```
fun <T> elvisLike(x: T, y: T & Any): T & Any = x ?: y

fun main() {
    elvisLike<String>("", "").length // OK
    elvisLike<String>("", null).length // Hiba: 'null' nem lehet non-null típus értéke
    elvisLike<String?>(null, "").length // OK
    elvisLike<String?>(null, null).length // Hiba: 'null' nem lehet non-null típus értéke
}
```

## Kotlin/JVM fejlesztések

### Fordító teljesítmény optimalizálások
- Átlagosan 10% gyorsabb fordítás Kotlin 1.6.0-hoz képest

### Új compiler opció: -Xjdk-release

```
kotlinc -Xjdk-release=1.8 # Limitálja az API-t Java 1.8-ra
```

### Stabil callable references funkcionális interfész konstruktorokhoz

### JVM cél verzió 1.6 eltávolítva (alapértelmezett: 1.8)

## Kotlin/Native fejlesztések

### Új memória menedzser Alpha (jelentős teljesítményjavulás)

```
# Visszatérés a régi menedzserhez (ha szükséges)
kotlin.native.binary.memoryModel=experimental
```

### Egységesített compiler plugin ABI JVM és JS IR backendekkel

### Standalone Android executables támogatás

```
# Visszatérés a régi viselkedéshez
binaryOptions["androidProgramType"] = "nativeActivity"
```

### Swift async/await interop javítás (Void visszatérési érték)

### Objective-C hidakon keresztüli nem deklarált kivételek tiltva

### Javított CocoaPods integráció

### Kotlin/Native compiler letöltési URL testreszabása:

```
kotlin.native.distribution.baseDownloadUrl=https://example.com
```

## Kotlin/JS fejlesztések

### IR backend teljesítményjavulás
- Inkrementális fordítás jelentősen gyorsabb
- 20% kisebb végleges bundle méret néhány nagy projektnél
- Javított interfész típus ellenőrzés

### Tag nevek minifikálása IR használatakor

---

# Kotlin 1.7.0 Újdonságok - folytatás

## Kotlin/JS fejlesztések - folytatás

### Tag nevek minifikálása IR-ben

```
kotlin {
    js(IR) {
        compilations.all {
            compileKotlinTask.kotlinOptions.freeCompilerArgs += listOf("-Xir-minimized-member-names=false")
        }
    }
}
```

### Támogatás régebbi böngészők számára polyfill-ekkel (IR backend)

### Dinamikus JavaScript modul betöltés js kifejezésekkel

```
val myPackage = js("import('my-package')")
```

### Környezeti változók meghatározása JavaScript teszt futtatókhoz

```
kotlin {
    js {
        nodejs {
            testTask {
                environment("key", "value")
            }
        }
    }
}
```

## Standard könyvtár fejlesztések

### min() és max() függvények nem-null visszatérési értékkel

```
fun main() {
    val numbers = listOf<Int>()
    println(numbers.maxOrNull()) // "null"
    println(numbers.max()) // "Exception in... Collection is empty."
}

// Új függvények:
// min(), max(), minBy(), maxBy(), minWith(), maxWith() - nem-null visszatérés
```

### Reguláris kifejezés illeszkedés adott indexen

```
fun main() {
    val releaseText = "Kotlin 1.7.0 is on its way!"
    val versionRegex = "\\d[.]\\d[.]\\d+".toRegex()
    
    // matchesAt() - boolean eredmény
    println(versionRegex.matchesAt(releaseText, 0)) // "false"
    println(versionRegex.matchesAt(releaseText, 7)) // "true"
    
    // matchAt() - MatchResult vagy null
    println(versionRegex.matchAt(releaseText, 0)) // "null"
    println(versionRegex.matchAt(releaseText, 7)?.value) // "1.7.0"
}
```

### Elérés annotációkon keresztül reflektálással

```
@Repeatable 
annotation class Tag(val name: String)

@Tag("First Tag") 
@Tag("Second Tag")
fun taggedFunction() {
    println("I'm a tagged function!")
}

fun main() {
    val x = ::taggedFunction
    val foo = x as KAnnotatedElement
    println(foo.findAnnotations<Tag>()) // [@Tag(name=First Tag), @Tag(name=Second Tag)]
}
```

### Stabil deep recursive függvények

```
class Tree(val left: Tree?, val right: Tree?)

val calculateDepth = DeepRecursiveFunction<Tree?, Int> { t ->
    if (t == null) 0 
    else maxOf(
        callRecursive(t.left),
        callRecursive(t.right)
    ) + 1
}

fun main() {
    // 100,000 mélységű fa generálása
    val deepTree = generateSequence(Tree(null, null)) { prev -> Tree(prev, null) }
        .take(100_000).last()
    println(calculateDepth(deepTree)) // 100000
}
```

### Időmérés inline osztályokkal alapértelmezett időforrásból

```
@OptIn(ExperimentalTime::class)
fun main() {
    val mark = TimeSource.Monotonic.markNow() // Visszatérési érték inline osztály
    val elapsedDuration = mark.elapsedNow()
}
```

### Új experimental kiterjesztés függvények Java Optional-hez

```
@OptIn(ExperimentalStdlibApi::class)
fun optionalExamples() {
    val presentOptional = Optional.of("I'm here!")
    val absentOptional = Optional.empty<String>()
    
    // Érték lekérdezése
    println(presentOptional.getOrNull()) // "I'm here!"
    println(absentOptional.getOrNull()) // null
    println(absentOptional.getOrDefault("Nobody here!")) // "Nobody here!"
    println(absentOptional.getOrElse { 
        println("Optional was absent!") 
        "Default value!" 
    })
    
    // Konverziók
    println(presentOptional.toList() + "," + absentOptional.toList()) // ["I'm here!"], []
    println(presentOptional.toSet() + "," + absentOptional.toSet()) // ["I'm here!"], []
    
    // Kollekcióba való helyezés
    val myCollection = mutableListOf<String>()
    absentOptional.toCollection(myCollection) // []
    presentOptional.toCollection(myCollection) // ["I'm here!"]
    
    // Sorozattá konvertálás
    val list = listOf(presentOptional, absentOptional).flatMap { it.asSequence() }
    println(list) // ["I'm here!"]
}
```

### Támogatás nevesített rögzítő csoportokhoz JS és Native platformokon

```
// Nevesített rögzítő csoportok
fun main() {
    val regex = "\\b(?<city>[A-Za-z\\s]+),\\s(?<state>[A-Z]{2}):\\s(?<areaCode>[0-9]{3})\\b".toRegex()
    val input = "Coordinates: Austin, TX: 123"
    val match = regex.find(input)!!
    
    println(match.groups["city"]?.value) // "Austin" - név alapján
    println(match.groups[2]?.value) // "TX" - index alapján
}

// Nevesített visszahivatkozás
fun backRef() {
    val regex = "(?<title>\\w+), yes \\k<title>".toRegex()
    val match = regex.find("Do you copy? Sir, yes Sir!")!!
    println(match.value) // "Sir, yes Sir"
    println(match.groups["title"]?.value) // "Sir"
}

// Nevesített csoportok helyettesítő kifejezésekben
fun dateReplace() {
    val dateRegex = Regex("(?<dd>\\d{2})-(?<mm>\\d{2})-(?<yyyy>\\d{4})")
    val input = "Date of birth: 27-04-2022"
    
    // Név alapján
    println(dateRegex.replace(input, "\${yyyy}-\${mm}-\${dd}")) // "Date of birth: 2022-04-27"
    
    // Index alapján
    println(dateRegex.replace(input, "\$3-\$2-\$1")) // "Date of birth: 2022-04-27"
}
```

## Gradle fejlesztések

### Új megközelítés inkrementális fordításhoz (Experimental)

```
# Új inkrementális fordítás engedélyezése
kotlin.incremental.useClasspathSnapshot=true
```

### Build jelentések Kotlin compiler taskokhoz (Experimental)

```
# Build jelentések engedélyezése
kotlin.build.report.output=file
# vagy
kotlin.build.report.output=build_scan
# vagy
kotlin.build.report.output=http
# vagy kombináció
kotlin.build.report.output=file,build_scan
```

### Minimum támogatott verziók:
- Gradle: 6.7.1
- Android Gradle plugin: 3.6.4

### Gradle plugin variant támogatás

Variant típusok:
- `main` - Gradle 6.7.1–6.9.3
- `gradle70` - Gradle 7.0+

### Kotlin Gradle plugin API frissítések

```
// KotlinBasePlugin interfész használata
project.plugins.withType<org.jetbrains.kotlin.gradle.plugin.KotlinBasePlugin>() {
    // Konfigurációs művelet
}
```

---

# Kotlin 1.6.20 Újdonságok - teljes fordítás

## Kotlin Gradle plugin API frissítések - folytatás

### KotlinBasePlugin használata

```
project.plugins.withType<org.jetbrains.kotlin.gradle.plugin.KotlinBasePlugin>() {
    // Konfigurációs művelet bármely Kotlin plugin esetén
}
```

### SAM-with-receiver plugin elérhető a plugins DSL-en keresztül

```
plugins {
    id("org.jetbrains.kotlin.plugin.sam.with.receiver") version "$kotlin_version"
}
```

### Compile task változások

```
// Új megközelítés - DefaultTask-ből származik
kotlin {
    compilations.all {
        compileTaskProvider.configure {
            // libraries input használata a szükséges könyvtárakhoz
            libraries.setFrom(/* könyvtárak */)
        }
    }
}
```

### Annotation processor statisztikák kapt-ban

```
// build.gradle.kts
kapt {
    showProcessorStats = true
}
```

```
# gradle.properties
kapt.verbose=true
```

### Elavult rendszertulajdonság: kotlin.compiler.execution.strategy

```
# Régi tulajdonság helyett új Gradle property
kotlin.compiler.execution.strategy=out-of-process
```

## Eltávolított elavult opciók, metódusok és pluginok

### useExperimentalAnnotation metódus eltávolítva

```
// Régi megközelítés - ELTÁVOLÍTVA
// useExperimentalAnnotation("org.mylibrary.OptInAnnotation")

// Új megközelítés
sourceSets.all {
    languageSettings.optIn("org.mylibrary.OptInAnnotation")
}
```

### Eltávolított compiler opciók
- `kotlinOptions.jdkHome` - eltávolítva (használj Java toolchains-t)
- `noStdlib` compiler opció - eltávolítva

### Eltávolított pluginok
- `kotlin2js` - helyette `org.jetbrains.kotlin.js`
- `kotlin-dce-plugin` - DCE automatikus az új Kotlin/JS pluginnal
- `KotlinGradleSubplugin` osztály - helyette `KotlinCompilerPluginSupportPlugin`

### Eltávolított coroutines DSL opció és property
- `kotlin.experimental.coroutines` DSL opció
- `kotlin.coroutines` property

### Típuskényszerítés eltávolítva toolchain extension metódusból

```
// Korábbi megközelítés
kotlin {
    jvmToolchain {
        (this as JavaToolchainSpec).languageVersion.set(JavaLanguageVersion.of(11))
    }
}

// Új megközelítés - nincs szükség típuskényszerítésre
kotlin {
    jvmToolchain {
        languageVersion.set(JavaLanguageVersion.of(11))
    }
}
```

## Migráció Kotlin 1.7.0-ra

### Telepítés
- IntelliJ IDEA 2022.1 és Android Studio Chipmunk automatikusan javasolják
- Új parancssoros compiler letölthető GitHub-ról

## Nyelvi fejlesztések (Kotlin 1.6.20)

### Context receivers prototípus Kotlin/JVM-hez (Experimental)

```
// Engedélyezés: -Xcontext-receivers
interface LoggingContext {
    val log: Logger
}

context(LoggingContext)
fun startBusinessOperation() {
    log.info("Operation has started") // log elérhető implicit receiver-ként
}

fun test(loggingContext: LoggingContext) {
    with(loggingContext) {
        startBusinessOperation() // LoggingContext szükséges a scope-ban
    }
}
```

### Definitely non-nullable típusok (Beta)

```
// Engedélyezés: language version 1.7
fun <T> elvisLike(x: T, y: T & Any): T & Any = x ?: y

fun main() {
    elvisLike<String>("", "").length // OK
    elvisLike<String>("", null).length // Hiba: 'null' nem lehet non-null típus
    elvisLike<String?>(null, "").length // OK
    elvisLike<String?>(null, null).length // Hiba: 'null' nem lehet non-null típus
}
```

## Kotlin/JVM fejlesztések (1.6.20)

### Új @JvmDefaultWithCompatibility annotáció

```
@JvmDefaultWithCompatibility
interface MyInterface {
    fun defaultMethod() {
        // Default metódus JVM interface-ben
    }
}
```

Compiler opció: `-Xjvm-default=all`

### Párhuzamos fordítás támogatás (Experimental)

```
# Fordítás több szálon
-Xbackend-threads=4
# vagy minden CPU magra
-Xbackend-threads=0
```

### Callable references funkcionális interfész konstruktorokhoz (Experimental)

```
# Engedélyezés
-XXLanguage:+KotlinFunInterfaceConstructorReference
```

```
// Régi megközelítés
interface Printer {
    fun print()
}
fun Printer(block: () -> Unit): Printer = object : Printer {
    override fun print() = block()
}

// Új megközelítés - funkcionális interfész
fun interface Printer {
    fun print()
}

// Callable reference használata működik mindkét esetben
documentsStorage.addPrinter(::Printer)
```

## Kotlin/Native fejlesztések (1.6.20)

### Új memória menedzser fejlesztések
- Párhuzamos sweep fázis implementáció
- Annotation osztályok példányosítása

### Swift async/await interop
- Swift Void visszatérési érték KotlinUnit helyett

### Jobb stack trace-ek libbacktrace használatával

### Standalone Android executables támogatás

### Teljesítményjavulások és hibajavítások
- Hibakezelés javítva cinterop modulok importálásakor
- Xcode 13 könyvtárak támogatása

---

# Kotlin 1.6.20 Újdonságok - folytatás

## Kotlin/Native fejlesztések (1.6.20) - folytatás

### Új memória menedzser Alpha verzióban

```
# Új memória menedzser kipróbálása
kotlin.native.binary.memoryModel=experimental
```

### Párhuzamos sweep fázis az új memória menedzserben

```
# Párhuzamos garbage collector engedélyezése
-Xgc=cms
```

### Annotation osztályok példányosítása (Kotlin/Native támogatás)

### Swift async/await interop - Void visszatérési érték

```
# Gradle property Unit típusú suspend függvényekhez
kotlin.native.binary.unitSuspendFunctionObjCExport=proper
```

### Jobb stack trace-ek libbacktrace használatával (Experimental)

```
# Libbacktrace engedélyezése
kotlin.native.binary.sourceInfoType=libbacktrace
```

### Standalone Android executables támogatás

```
kotlin {
    androidNativeX64("android") {
        binaries {
            executable {
                // Standalone executable (Kotlin 1.7.0-ban alapértelmezett)
                binaryOptions["androidProgramType"] = "standalone"
                
                // Visszatérés a régi viselkedéshez
                // binaryOptions["androidProgramType"] = "nativeActivity"
            }
        }
    }
}
```

### Teljesítményjavulások
- 15% csökkenés végrehajtási időben
- 20% csökkenés kód méretben
- 26% csökkenés release bináris fordítási időben

### Javított hibakezelés cinterop modulok importálásakor

### Xcode 13 könyvtárak támogatása

## Kotlin Multiplatform fejlesztések (1.6.20)

### Hierarchikus struktúra alapértelmezett minden új multiplatform projektben

```
# Hierarchikus struktúra letiltása (ha szükséges)
kotlin.mpp.hierarchicalStructureSupport=false

# Eltávolítható régi beállítások (ha korábban be voltak állítva)
# kotlin.mpp.enableGranualrSourceSetsMetadata=true
# kotlin.native.enableDependencyPropagation=false
```

### iOS hierarchia példa:

```
commonMain
├── iosMain
│   ├── iosArm64Main
│   └── iosX64Main
└── androidMain
```

### Kotlin CocoaPods Gradle plugin fejlesztések

```
kotlin {
    cocoapods {
        version = "1.0"
        name = "MyCocoaPod"
        
        // Extra Podspec attribútumok
        extraSpecAttributes["social_media_url"] = "https://twitter.com/kotlin"
        extraSpecAttributes["vendored_frameworks"] = "CustomFramework.xcframework"
        extraSpecAttributes["libraries"] = "xml"
    }
}
```

### Új taskok XCFramework építésre és Podspec generálásra

## Kotlin/JS fejlesztések (1.6.20)

### Inkrementális fordítás fejlesztési binárisokhoz IR compilerrel

```
# Inkrementális fordítás engedélyezése
kotlin.incremental.js.ir=true
```

### Lassú inicializálás alapértelmezett top-level property-khez IR compilerrel

```
// Lassú inicializálás (alapértelmezett)
val a = run {
    val result = // intenzív számítások
    println(result)
    result
}

// Eager inicializálás (ha szükséges)
@EagerInitialization
val b = run {
    // azonnali inicializálás
}
```

### Különálló JS fájlok projekt modulokhoz alapértelmezetten IR compilerrel

```
# Régi opció (most már alapértelmezett)
-Xir-per-module=true
```

### Char osztály optimalizálás IR compilerben

### Export javítások (IR és régi backend is)

### @AfterTest garanciák aszinkron tesztekhez

---

# Kotlin 1.6.0 Újdonságok - teljes fordítás

## Kotlin/JS fejlesztések (1.6.20) - folytatás

### Külön JS fájlok projekt modulokhoz alapértelmezetten

```
# Egyetlen JS fájl generálása (kikapcsolja az alapértelmezett per-module módot)
kotlin.js.ir.output.granularity=whole-program

# Per-module mód (alapértelmezett)
kotlin.js.ir.output.granularity=per-module
```

### Char osztály optimalizálás
- Boxing nélküli kezelés (hasonlóan inline osztályokhoz)
- JavaScriptbe Number típusként exportálva

### Export és TypeScript deklaráció generálás javítások
- Interfészek és enumok exportálása
- @JsExport annotáció javításai
- TypeScript deklaráció (.d.ts) generálás javításai

### @AfterTest garanciák aszinkron tesztekhez

```
// Aszinkron teszt esetén @AfterTest helyesen működik
@Test
fun asyncTest(): Promise<Unit> {
    // Teszt logika
}

@AfterTest
fun cleanup() {
    // Mindig végrehajtódik, még aszinkron tesztek után is
}
```

## Biztonsági fejlesztések (1.6.20)

### Relatív útvonalak klib-ekben

```
// Gradle build script
tasks.withType(org.jetbrains.kotlin.gradle.dsl.KotlinCompile::class).configureEach {
    // $base a forrásfájlok alapútvonala
    kotlinOptions.freeCompilerArgs += "-Xklib-relative-path-base=$base"
}
```

### yarn.lock fájl megőrzése Kotlin/JS Gradle projektekben

```
// Testreszabás Gradle-ben
rootProject.plugins.withType<org.jetbrains.kotlin.gradle.targets.js.yarn.YarnPlugin> {
    rootProject.the<org.jetbrains.kotlin.gradle.targets.js.yarn.YarnRootExtension>().lockFileDirectory = 
        project.rootDir.resolve("my-kotlin-js-store")
    rootProject.the<org.jetbrains.kotlin.gradle.targets.js.yarn.YarnRootExtension>().lockFileName = 
        "my-yarn.lock"
}
```

### npm függőségek telepítése --ignore-scripts alapértelmezetten

```
// Lifecycle scriptek engedélyezése (ha szükséges)
rootProject.plugins.withType<org.jetbrains.kotlin.gradle.targets.js.yarn.YarnPlugin> {
    rootProject.the<org.jetbrains.kotlin.gradle.targets.js.yarn.YarnRootExtension>().ignoreScripts = false
}
```

## Gradle fejlesztések (1.6.20)

### Új tulajdonságok Kotlin compiler végrehajtási stratégia meghatározásához

```
# Gradle property használata
kotlin.compiler.execution.strategy=out-of-process
```

```
// Task szintű beállítás
import org.jetbrains.kotlin.gradle.tasks.KotlinCompilerExecutionStrategy

tasks.withType<KotlinCompile>().configureEach {
    compilerExecutionStrategy.set(KotlinCompilerExecutionStrategy.IN_PROCESS)
}
```

### Elavult build opciók:
- `kapt.use.worker.api` - figyelmeztetés, jövőbeli eltávolítás
- `kotlin.experimental.coroutines` DSL opció és `kotlin.coroutines` property - eltávolítva
- `kotlin.parallel.tasks.in.project` - eltávolítva

## Nyelvi fejlesztések (Kotlin 1.6.0)

### Stabil exhaustive when kifejezések enum, sealed és Boolean típusokra

```
sealed class Contact {
    data class PhoneCall(val number: String) : Contact()
    data class TextMessage(val number: String) : Contact()
}

// Hibás - nem exhaustive
fun Contact.messageCost(): Int = when(this) {
    is Contact.PhoneCall -> 42
    // Hiba: hiányzik TextMessage és else ág
}

// Javított változat
fun Contact.messageCost(): Int = when(this) {
    is Contact.PhoneCall -> 42
    is Contact.TextMessage -> 20
}
```

### Stabil suspending függvények szupertípusként

```
class MyClickAction : suspend () -> Unit {
    override suspend fun invoke() {
        // Implementáció
    }
}

fun launchOnClick(action: suspend () -> Unit) {}

// Használat
launchOnClick(MyClickAction())
```

### Stabil suspend konverziók

```
fun getSuspending(suspending: suspend () -> Unit) {}
fun suspending() {}
fun test(regular: () -> Unit) {
    getSuspending { }           // OK
    getSuspending(::suspending) // OK
    getSuspending(regular)      // OK - automatikus konverzió
}
```

### Stabil annotáció osztályok példányosítása

### Javított típus inferencia rekurzív generikus típusokhoz

```
// 1.6.0-tól működik típusparaméter nélkül
val container = PostgreSqlContainer(DockerImageName.parse("postgres:13-alpine"))
    .withDatabaseName("db")
    .withUsername("user")
    .withPassword("password")
    .withInitScript("sql/schema.sql")
```

### Builder inference javítások

```
# Builder inference engedélyezése
-Xenable-builder-inference
```

### Annotációk támogatása osztály típusparamétereken

```
@Target(AnnotationTarget.TYPE_PARAMETER)
annotation class BoxContent

class Box<@BoxContent T> {}
```

### Hosszabb API verzió támogatás (3 korábbi verzió + jelenlegi)

## Kotlin/JVM fejlesztések (1.6.0)

### JVM 17 bytecode támogatás

### Ismételhető annotációk (repeatable annotations)

```
// Kotlin repeatable annotáció
@Repeatable
annotation class Tag(val name: String)

// Java kompatibilitás
@JvmRepeatable(Tags::class)
annotation class Tag(val name: String)

annotation class Tags(val value: Array<Tag>)
```

### Optimalizált delegated property-k

```
class Box<T> {
    private var impl: T = ...
    var content: T by ::impl // Nincs $delegate mező generálva
}
```

Reflexió támogatás:
```
// Repeatable annotációk keresése
val annotations = element.findAnnotations<Tag>()
```

---

****

# Kotlin 1.6.0 Újdonságok - folytatás

## Kotlin/Native fejlesztések (1.6.0)

### Új memória menedzser előnézet (Experimental)

```
# Új memória menedzser engedélyezése
kotlin.native.binary.memoryModel=experimental
```

### Xcode 13 támogatás

### Windows targetek fordítása bármely hoszton

### LLVM és linker frissítések
- LLVM verzió frissítve 11.1.0-ra
- Függőség méret csökkent (~300 MB macOS-en az előző 1200 MB helyett)
- ncurses5 függőség eltávolítva

### Teljesítményjavulások
- Compiler cache-ek alapértelmezett linuxX64 és iosArm64 targetekre
- Tömb iteráció 12%-kal gyorsabb for ciklusokkal

### Egységesített compiler plugin ABI JVM és JS IR backendekkel

```
# Egységes plugin ABI engedélyezése
kotlin.native.useEmbeddableCompilerJar=true
```

### Részletes hibaüzenetek klib linkage hibáknál

### Újragondolt kezeletlen kivétel kezelés API

```
// Új függvény kezeletlen kivételek kezelésére
processUnhandledException(throwable: Throwable)

// Kivétel hook beállítása
setUnhandledExceptionHook { throwable ->
    // Kivétel feldolgozása
    // Program terminálása ha szükséges
    terminateWithUnhandledException()
}
```

## Kotlin/JS fejlesztések (1.6.0)

### Letöltés letiltása Node.js és Yarn esetén

```
// Yarn letöltés letiltása
rootProject.plugins.withType<org.jetbrains.kotlin.gradle.targets.js.yarn.YarnPlugin> {
    rootProject.the<org.jetbrains.kotlin.gradle.targets.js.yarn.YarnRootExtension>().download = false
}

// Node.js letöltés letiltása
rootProject.plugins.withType<org.jetbrains.kotlin.gradle.targets.js.nodejs.NodeJsRootPlugin> {
    rootProject.the<org.jetbrains.kotlin.gradle.targets.js.nodejs.NodeJsRootExtension>().download = false
}
```

## Kotlin Gradle plugin (1.6.0)

### Eltávolított/eltűnt funkciók:
- `KotlinGradleSubplugin` osztály - ERROR szintre emelve
- `kotlin.useFallbackCompilerSearch` build opció - eltávolítva
- `noReflect` és `includeRuntime` compiler opciók - eltávolítva
- `useIR` compiler opció - rejtett, jövőbeli eltávolítás

## Standard könyvtár fejlesztések (1.6.0)

### Új readline függvények (JVM és Native)

```
// Új függvények - csak JVM és Native
val line = readln()        // RuntimeException ha EOF
val lineOrNull = readlnOrNull() // null ha EOF

// Példa használat
println("What is your nickname?")
val nickname = readln()
println("Hello, $nickname!")

// EOF kezelés
fun main() {
    var sum = 0
    while (true) {
        val nextLine = readlnOrNull().takeUnless { it.isNullOrEmpty() } ?: break
        sum += nextLine.toInt()
    }
    println(sum)
}
```

### Stabil typeOf()

```
inline fun <reified T> renderType(): String {
    val type = typeOf<T>()
    return type.toString()
}

fun main() {
    val fromExplicitType = typeOf<Int>()
    val fromReifiedType = renderType<List<Int>>()
}
```

### Stabil collection builder-ek

```
fun main() {
    val x = listOf('b', 'c')
    val y = buildList {
        add('a')
        addAll(x)
        add('d')
    }
    println(y) // [a, b, c, d]
}
```

### Stabil Duration API

```
import kotlin.time.Duration.Companion.seconds

fun main() {
    val duration = 10000
    println("There are ${duration.seconds.inWholeMinutes} minutes in $duration seconds")
    // There are 166 minutes in 10000 seconds
}
```

### Regex felosztása sorozattá

```
fun main() {
    val colorsText = "green, red, brown&blue, orange, pink&green"
    val regex = "[,\\s]+".toRegex()
    
    val mixedColor = regex.splitToSequence(colorsText)
        .onEach { println(it) }
        .firstOrNull { it.contains('&') }
    
    println(mixedColor) // "brown&blue"
}
```

### Bit rotáció műveletek egészekre

```
fun main() {
    val number: Short = 0b10001
    println(number.rotateRight(2).toString(radix = 2)) // 100000000000100
    println(number.rotateLeft(2).toString(radix = 2))  // 1000100
}
```

### replace() és replaceFirst() változások JS-ben

```
fun main() {
    println(Regex("(.+)").replace("Kotlin", """\$ $1""")) // $ Kotlin
    println(Regex("(.+)").replaceFirst("1.6.0", """\\ $1""")) // \ 1.6.0
}
```

### Javítások meglévő API-khoz

```
// Comparable.compareTo infix formában
class WrappedText(val text: String) : Comparable<WrappedText> {
    override fun compareTo(other: WrappedText): Int = this.text compareTo other.text
}
```

### Elavultságok

```
// Elavult string függvények (JS-only)
// concat() -> használj plus()
// match() -> használj Regex.findAll()
// matches() -> használj Regex.matches()

// Elavult sort() függvények tömbökön
// Használj más standard library függvényeket
```

## Eszközök

### Kover - kód lefedettség eszköz Kotlin-hoz

```
plugins {
    id("org.jetbrains.kotlinx.kover") version "0.5.0"
}
```

## Coroutines 1.6.0-RC

### Újdonságok:
- Új Kotlin/Native memória menedzser támogatás
- Dispatcher views API bevezetése
- Java 6-ról Java 8-ra migráció
- Újragondolt kotlinx-coroutines-test API
- CopyableThreadContextElement bevezetése ThreadLocal változókhoz

---

