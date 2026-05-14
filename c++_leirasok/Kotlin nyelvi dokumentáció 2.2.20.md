# Kotlin nyelvi dokumentáció 2.2.20

## Tartalomjegyzék

### Kotlin dokumentáció

#### Első lépések a Kotlinnal
- [Telepítsd a Kotlin-t](#)
- [Válaszd ki a Kotlin használati eseted](#)
- [Csatlakozz a Kotlin közösséghez](#)
- [Hiányzik valami?](#)

#### Üdvözöljük Kotlin ismerkedő túránkon!
- [Hello world](#)
- [Változók](#)
- [String sablonok](#)
- [Gyakorlás](#)
- [Következő lépés](#)

#### Alap típusok
- [Alap típusok](#)
- [Gyakorlás](#)
- [Következő lépés](#)

#### Kollekciók
- [Lista (`List`)](#)
- [Halmaz (`Set`)](#)
- [Térkép (`Map`)](#)
- [Gyakorlás](#)
- [Következő lépés](#)

#### Vezérlési szerkezetek
- [Feltételes kifejezések](#)
- [Feltételes kifejezések gyakorlása](#)
- [Tartományok (`Ranges`)](#)
- [Ciklusok](#)
- [Ciklusok gyakorlása](#)
- [Következő lépés](#)

#### Függvények
- [Függvények](#)
- [Elnevezett argumentumok](#)
- [Alapértelmezett paraméterértékek](#)
- [Függvények visszatérési érték nélkül](#)
- [Egysoros függvények](#)
- [Korai visszatérés függvényekben](#)
- [Függvények gyakorlása](#)
- [Lambda kifejezések](#)
- [Lambda kifejezések gyakorlása](#)
- [Következő lépés](#)

#### Osztályok
- [Osztályok](#)
- [Tulajdonságok](#)
- [Példány létrehozása](#)
- [Tulajdonságok elérése](#)
- [Tagfüggvények](#)
- [Adatosztályok](#)
- [Gyakorlás](#)
- [Következő lépés](#)

#### Null biztonság
- [Null biztonság](#)
- [Nullable típusok](#)
- [Null érték ellenőrzése](#)
- [Biztonságos hívások használata](#)
- [Elvis operátor használata](#)
- [Gyakorlás](#)
- [Mi a következő?](#)

#### Középhaladó: Extension függvények
- [Extension függvények](#)
- [Kiterjesztésorientált tervezés](#)
- [Gyakorlás](#)
- [Következő lépés](#)

#### Középhaladó: Scope függvények
- [Scope függvények](#)
- [Használati eset áttekintés](#)
- [Gyakorlás](#)
- [Következő lépés](#)

#### Középhaladó: Lambda kifejezések fogadóval
- [Lambda kifejezések fogadóval](#)
- [Gyakorlás](#)
- [Következő lépés](#)

#### Középhaladó: Osztályok és interfészek
- [Osztályöröklődés](#)
- [Interfészek](#)
- [Delegálás](#)
- [Gyakorlás](#)
- [Következő lépés](#)

#### Középhaladó: Objektumok
- [Objektum deklarációk](#)
- [Gyakorlás](#)
- [Következő lépés](#)

#### Középhaladó: Nyílt és speciális osztályok
- [Nyílt osztályok (`Open`)](#)
- [Speciális osztályok](#)
- [Gyakorlás](#)
- [Következő lépés](#)

#### Középhaladó: Tulajdonságok
- [Háttérmezők (`Backing fields`)](#)
- [Kiterjesztési tulajdonságok (`Extension properties`)](#)
- [Delegált tulajdonságok (`Delegated properties`)](#)
- [Gyakorlás](#)
- [Következő lépés](#)

#### Középhaladó: Null biztonság
- [Okos típuskényszerítések és biztonságos kényszerítések](#)
- [Null értékek és kollekciók](#)
- [Korai visszatérés és az Elvis operátor](#)
- [Gyakorlás](#)
- [Következő lépés](#)

#### Középhaladó: Könyvtárak és API-k
- [A standard könyvtár](#)
- [Kotlin könyvtárak](#)
- [API-k használatának engedélyezése (`Opt in`)](#)
- [Gyakorlás](#)
- [Mi a következő?](#)

### Kotlin szerveroldalra
- [Keretrendszerek szerveroldali fejlesztéshez Kotlinnal](#)
- [Kotlin szerveroldali alkalmazások telepítése](#)
- [Termékek, amelyek szerveroldalon használnak Kotlin-t](#)
- [Következő lépések](#)

### Kotlin Androidra
- [Kotlin/Wasm](#)
- [Kotlin/Wasm és Compose Multiplatform](#)
- [Kotlin/Wasm és WASI](#)
- [Kotlin/Wasm teljesítmény](#)
- [Böngésző API támogatás](#)
- [Visszajelzés küldése](#)
- [Tudj meg többet](#)

### Kotlin/Native
- [Miért Kotlin/Native?](#)
- [Célplatformok](#)
- [Interoperabilitás](#)
- [Kód megosztása platformok között](#)
- [Memóriakezelő](#)

### Kotlin/JavaScript
- [Használati esetek Kotlin/JS esetén](#)
- [Első lépések Kotlin/JS-sel](#)
- [Mintaprojektek Kotlin/JS-re](#)
- [Kotlin/JS keretrendszerek](#)
- [Csatlakozz a Kotlin/JS közösséghez](#)
- [Mi a következő?](#)

### Kotlin adatelemzéshez
- [Notebook-ok](#)
- [Kotlin DataFrame](#)
- [Kandy](#)
- [Mi a következő?](#)

### Kotlin AI-alapú alkalmazásfejlesztéshez
- [Kotlin AI ügynök keretrendszer – Koog](#)
- [További használati esetek](#)
- [Példák felfedezése](#)
- [Mi a következő?](#)

### Kotlin versenyszoftver-fejlesztéshez
- [Egyszerű példa: Reachable Numbers probléma](#)
- [Funkcionális operátorok példa: Long Number probléma](#)
- [További tippek és trükkök](#)

## Kotlin tanulása

### Újdonságok a Kotlin 2.2.20-ban
- [IDE támogatás](#)
- [Nyelv](#)
- [Kotlin/JVM: `invokedynamic` támogatás `when` kifejezésekkel](#)
- [Kotlin Multiplatform](#)
- [Kotlin/Native](#)
- [Kotlin/Wasm](#)
- [Kotlin/JS](#)
- [Gradle](#)
- [Maven: Kotlin daemon támogatás a `kotlin-maven-plugin`-ben](#)
- [Új közös séma a Kotlin fordító beállításokhoz](#)
- [Kotlin standard könyvtár](#)
- [Compose compiler](#)
- [Törésváltozások és elavultságok](#)
- [Dokumentációs frissítések](#)
- [Hogyan frissíts a Kotlin 2.2.20-ra](#)

### Újdonságok a Kotlin 2.2.0-ban
- [IDE támogatás](#)
- [Nyelv](#)
- [Kotlin compiler: egységesített figyelmeztetések kezelése](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin/Wasm](#)
- [Kotlin/JS](#)ł
- [Gradle](#)
- [Új kísérleti build eszköz API](#)

### Kotlin standard könyvtár
- [Compose compiler](#)
- [Törésváltozások és elavultságok](#)
- [Dokumentációs frissítések](#)
- [Hogyan frissíts a Kotlin 2.2.0-ra](#)

### Újdonságok a Kotlin 2.1.20-ban
- [IDE támogatás](#)
- [Kotlin K2 compiler](#)
- [Kotlin Multiplatform: új DSL a Gradle Application plugin cseréjére](#)
- [Kotlin/Native](#)
- [Kotlin/Wasm](#)
- [Gradle](#)
- [Standard könyvtár](#)
- [Compose compiler](#)
- [Törésváltozások és elavultságok](#)
- [Dokumentációs frissítések](#)
- [Hogyan frissíts a Kotlin 2.1.20-ra](#)

### Újdonságok a Kotlin 2.1.0-ban
- [IDE támogatás](#)
- [Nyelv](#)
- [Kotlin K2 compiler](#)
- [Kotlin/JVM](#)
- [Kotlin Multiplatform](#)
- [Kotlin/Native](#)
- [Kotlin/Wasm](#)
- [Kotlin/JS](#)
- [Gradle fejlesztések](#)
- [Compose compiler frissítések](#)
- [Standard könyvtár](#)
- [Dokumentációs frissítések](#)
- [Kompatibilitási útmutató a Kotlin 2.1.0-hoz](#)
- [Kotlin 2.1.0 telepítése](#)

### Újdonságok a Kotlin 2.0.20-ban
- [IDE támogatás](#)
- [Nyelv](#)
- [Kotlin Multiplatform](#)
- [Kotlin/Native](#)
- [Kotlin/Wasm](#)
- [Kotlin/JS](#)
- [Gradle](#)
- [Compose compiler](#)
- [Standard könyvtár](#)
- [Dokumentációs frissítések](#)
- [Kotlin 2.0.20 telepítése](#)

### Újdonságok a Kotlin 2.0.0-ban
- [IDE támogatás](#)
- [Kotlin K2 compiler](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin/Wasm](#)
- [Kotlin/JS](#)
- [Gradle fejlesztések](#)
- [Standard könyvtár](#)
- [Kotlin 2.0.0 telepítése](#)

### Újdonságok a Kotlin 1.9.20-ban
- [IDE támogatás](#)
- [Új Kotlin K2 compiler frissítések](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin Multiplatform](#)
- [Kotlin/Wasm](#)
- [Kotlin/JS](#)
- [Gradle](#)
- [Standard könyvtár](#)
- [Dokumentációs frissítések](#)
- [Kotlin 1.9.20 telepítése](#)

### Újdonságok a Kotlin 1.9.0-ban
- [IDE támogatás](#)
- [Új Kotlin K2 compiler frissítések](#)
- [Nyelv](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin Multiplatform](#)
- [Kotlin/Wasm](#)
- [Kotlin/JS](#)
- [Gradle](#)
- [Standard könyvtár](#)
- [Dokumentációs frissítések](#)
- [Kotlin 1.9.0 telepítése](#)
- [Kompatibilitási útmutató a Kotlin 1.9.0-hoz](#)

### Újdonságok a Kotlin 1.8.20-ban
- [IDE támogatás](#)
- [Új Kotlin K2 compiler frissítések](#)
- [Nyelv](#)
- [Új Kotlin/Wasm célplatform](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin Multiplatform](#)

### Kotlin/JavaScript
- [Gradle](#)
- [Standard könyvtár](#)
- [Serializáció frissítések](#)
- [Dokumentációs frissítések](#)
- [Kotlin 1.8.20 telepítése](#)

### Újdonságok a Kotlin 1.8.0-ban
- [IDE támogatás](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin Multiplatform: Új Android forrásfájl elrendezés](#)
- [Kotlin/JS](#)
- [Gradle](#)
- [Standard könyvtár](#)
- [Dokumentációs frissítések](#)
- [Kotlin 1.8.0 telepítése](#)
- [Kompatibilitási útmutató a Kotlin 1.8.0-hoz](#)

### Újdonságok a Kotlin 1.7.20-ban
- [Kotlin K2 compiler pluginok támogatása](#)
- [Nyelv](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin/JS](#)
- [Gradle](#)
- [Standard könyvtár](#)
- [Dokumentációs frissítések](#)
- [Kotlin 1.7.20 telepítése](#)

### Újdonságok a Kotlin 1.7.0-ban
- [Új Kotlin K2 compiler a JVM-hez (Alpha)](#)
- [Nyelv](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin/JS](#)
- [Standard könyvtár](#)
- [Gradle](#)
- [Migráció a Kotlin 1.7.0-ra](#)

### Újdonságok a Kotlin 1.6.20-ban
- [Nyelv](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin Multiplatform](#)
- [Kotlin/JS](#)
- [Biztonság](#)
- [Gradle](#)

### Újdonságok a Kotlin 1.6.0-ban
- [Nyelv](#)
- [Korábbi API verziók hosszabb támogatása](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin/JS](#)
- [Kotlin Gradle plugin](#)
- [Standard könyvtár](#)
- [Eszközök](#)
- [Coroutines 1.6.0-RC](#)
- [Migráció a Kotlin 1.6.0-ra](#)

### Újdonságok a Kotlin 1.5.30-ban
- [Nyelvi funkciók](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin Multiplatform](#)
- [Kotlin/JS](#)
- [Gradle](#)
- [Standard könyvtár](#)
- [Serializáció 1.3.0-RC](#)

### Újdonságok a Kotlin 1.5.20-ban
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin/JS](#)
- [Gradle](#)
- [Standard könyvtár](#)

### Újdonságok a Kotlin 1.5.0-ban
- [Nyelvi funkciók](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin/JS](#)
- [Kotlin Multiplatform](#)
- [Standard könyvtár](#)
- [kotlin-test könyvtár](#)
- [kotlinx könyvtárak](#)
- [Migráció a Kotlin 1.5.0-ra](#)

### Újdonságok a Kotlin 1.4.30-ban
- [Nyelvi funkciók](#)
- [Kotlin/JVM](#)
- [Kotlin/Native](#)
- [Kotlin/JS](#)
- [Gradle projekt fejlesztések](#)

### Standard könyvtár
- [Serializáció frissítések](#)

### Újdonságok a Kotlin 1.4.20-ban
- [Kotlin/JVM](#)
- [Kotlin/JS](#)
- [Kotlin/Native](#)
- [Kotlin Multiplatform](#)
- [Standard könyvtár](#)
- [Kotlin Android Extensions](#)

### Újdonságok a Kotlin 1.4.0-ban
- [Nyelvi funkciók és fejlesztések](#)
- [Új eszközök az IDE-ben](#)
- [Új fordító](#)
- [Kotlin/JVM](#)
- [Kotlin/JS](#)
- [Kotlin/Native](#)
- [Kotlin Multiplatform](#)
- [Gradle projekt fejlesztések](#)
- [Standard könyvtár](#)
- [Stabil JSON serializáció](#)
- [Szkriptelés és REPL](#)
- [Migráció a Kotlin 1.4.0-ra](#)

### Újdonságok a Kotlin 1.3-ban
- [Coroutine-ok kiadása](#)
- [Kotlin/Native](#)
- [Multiplatform projektek](#)
- [Kontraktusok (`Contracts`)](#)
- [Kifejezés változóba mentése `when` szerkezetben](#)
- [@JvmStatic és @JvmField interfészek társosztályainál](#)
- [Beágyazott deklarációk annotációs osztályokban](#)
- [Paraméter nélküli `main` függvény](#)
- [Függvények nagy aritással](#)
- [Progresszív mód](#)
- [Inline osztályok](#)
- [Előjel nélküli egészek](#)
- [@JvmDefault](#)
- [Standard könyvtár](#)
- [Eszközök](#)

### Újdonságok a Kotlin 1.2-ban
- [Tartalomjegyzék](#)
- [Multiplatform projektek (kísérleti)](#)
- [Egyéb nyelvi funkciók](#)
- [Standard könyvtár](#)
- [JVM backend](#)
- [JavaScript backend](#)
- [Eszközök](#)

### Újdonságok a Kotlin 1.1-ban
- [Tartalomjegyzék](#)
- [JavaScript](#)
- [Coroutine-ok (kísérleti)](#)
- [Egyéb nyelvi funkciók](#)
- [Standard könyvtár](#)
- [JVM Backend](#)
- [JavaScript backend](#)

### Kotlin roadmap
- [Főbb prioritások](#)
- [Kotlin roadmap részrendszerek szerint](#)

### Mi változott 2025 februárja óta
- [Kotlin nyelvi funkciók és javaslatok](#)
- [Kotlin evolúciós elvek](#)
- [Pragmatikus evolúció elvei](#)
- [Inkompatibilis változások](#)
- [Döntéshozatal](#)
- [Nyelv és eszköz kiadások](#)
- [Könyvtárak](#)
- [Fordító opciók](#)
- [Kompatibilitási eszközök](#)
- [Kotlin komponensek stabilitása](#)
- [Stabilitási szintek magyarázata](#)
- [GitHub jelvények Kotlin komponensekhez](#)
- [Alkomponensek stabilitása](#)
- [Kotlin komponensek jelenlegi stabilitása](#)
- [Nyelvi funkciók és tervezeti javaslatok](#)

### Kotlin kiadások
- [Frissítés új Kotlin verzióra](#)
- [IDE támogatás](#)
- [Kotlin kiadás kompatibilitás](#)
- [Kiadás részletei](#)

## Alap szintaxis
- [Csomagdefiníció és importálás](#)
- [Program belépési pontja](#)
- [Kiírás a standard kimenetre](#)
- [Beolvasás a standard bemenetről](#)
- [Függvények](#)
- [Változók](#)

### Osztályok és példányok létrehozása
### Megjegyzések
### String sablonok
### Feltételes kifejezések
### `for` ciklus
### `while` ciklus
### `when` kifejezés
### Tartományok (`Ranges`)
### Kollekciók
### Nullable értékek és null ellenőrzések
### Típusellenőrzések és automatikus típuskényszerítések

## Idiómák
- [DTO-k létrehozása (POJOs/POCOs)](#)
- [Alapértelmezett értékek függvény paraméterekhez](#)
- [Lista szűrése](#)
- [Elem jelenlétének ellenőrzése kollekcióban](#)
- [String interpoláció](#)
- [Standard bemenet biztonságos olvasása](#)
- [Példány ellenőrzések](#)
- [Csak olvasható lista](#)
- [Csak olvasható térkép](#)
- [Térkép elem elérése](#)
- [Térkép vagy párok listájának bejárása](#)
- [Tartomány bejárása](#)
- [Lusta (`lazy`) tulajdonság](#)
- [Extension függvények](#)
- [Singleton létrehozása](#)
- [Inline value osztályok használata típusbiztos értékekhez](#)
- [Absztrakt osztály példányosítása](#)
- [If-not-null rövidítés](#)
- [If-not-null-else rövidítés](#)
- [Kifejezés végrehajtása, ha null](#)
- [Lehetséges üres kollekció első eleme](#)
- [Végrehajtás, ha nem null](#)
- [Nullable érték leképezése, ha nem null](#)
- [Visszatérés `when` utasításban](#)
- [`try-catch` kifejezés](#)
- [`if` kifejezés](#)
- [Builder-stílusú használat egység (`Unit`) visszatérésű metódusoknál](#)
- [Egysoros függvények](#)
- [Több metódus hívása egy objektum példányon (`with`)](#)
- [Objektum tulajdonságainak konfigurálása (`apply`)](#)
- [Java 7 try-with-resources](#)
- [Generikus függvény, amely megköveteli a generikus típusinformációt](#)
- [Két változó felcserélése](#)
- [Kód megjelölése hiányosként (TODO)](#)

### Mi a következő?
## Kódolási konvenciók
- [Stílus konfigurálása az IDE-ben](#)
- [Forráskód szervezés](#)
- [Elnevezési szabályok](#)
- [Formázás](#)
- [Dokumentációs megjegyzések](#)
- [Redundáns szerkezetek elkerülése](#)
- [Nyelvi funkciók idiomatikus használata](#)
- [Könyvtárak kódolási konvenciói](#)

## Alaptípusok
### Számok
- [Egész típusok](#)
- [Lebegőpontos típusok](#)
- [Szám literálok](#)
- [Számok dobozolása és gyorsítótárazása a Java Virtuális Gépen](#)
- [Explicit szám konverziók](#)
- [Műveletek számokon](#)
- [Előjel nélküli egész típusok (`Unsigned`)](#)
- [Előjel nélküli tömbök és tartományok](#)
- [Előjel nélküli egészek literáljai](#)
- [Használati esetek](#)

### Logikai érték (`Boolean`)
### Karakterek (`Character`)
### Szövegek (`String`)
- [String literálok](#)
- [String sablonok](#)
- [String formázás](#)

### Tömbök (`Array`)
- [Mikor használjunk tömböket?](#)
- [Tömbök létrehozása](#)
- [Elemek elérése és módosítása](#)
- [Munka tömbökkel](#)
- [Primitív típusú tömbök](#)

### Mi a következő?
## Típusellenőrzések és típuskényszerítések
- [`is` és `!is` operátorok](#)
- [Okos típuskényszerítések (`Smart casts`)](#)

### „Nem biztonságos” típuskényszerítő operátor
### „Biztonságos” (nullable) típuskényszerítő operátor

## Feltételek és ciklusok
- [If kifejezés](#)
- [When kifejezések és utasítások](#)
- [For ciklusok](#)
- [While ciklusok](#)
- [Break és continue ciklusokban](#)

## Visszatérés és ugrások
- [Break és continue címkék](#)
- [Visszatérés címkéhez](#)

## Kivételek
- [Kivételek dobása](#)
- [Kivételek kezelése try-catch blokkokkal](#)
- [Egyéni kivételek létrehozása](#)
- [A Nothing típus](#)
- [Kivétel osztályok](#)
- [Veremkövetés (Stack trace)](#)
- [Kivétel interoperabilitás Java, Swift és Objective-C nyelvekkel](#)

## Csomagok és importálás
- [Alapértelmezett importálások](#)
- [Importálások](#)
- [Legfelső szintű deklarációk láthatósága](#)

## Osztályok
- [Konstruktorok](#)
- [Osztály példányok létrehozása](#)
- [Osztálytagok](#)
- [Öröklődés](#)
- [Absztrakt osztályok](#)
- [Társosztályok (Companion objects)](#)
- [Öröklődés](#)
- [Metódusok felülírása](#)
- [Tulajdonságok felülírása](#)
- [Származtatott osztály inicializálási sorrendje](#)
- [Szuperosztály implementációjának hívása](#)
- [Felülírási szabályok](#)

## Tulajdonságok
- [Tulajdonságok deklarálása](#)
- [Egyéni getterek és setterek](#)
- [Fordítási időben ismert konstansok](#)
- [Később inicializált tulajdonságok és változók](#)
- [Tulajdonságok felülírása](#)
- [Delegált tulajdonságok](#)

## Interfészek
- [Interfészek implementálása](#)
- [Tulajdonságok interfészekben](#)
- [Interfészek öröklődése](#)
- [Felülírási konfliktusok feloldása](#)
- [JVM alapértelmezett metódus generálás interfész függvényekhez](#)
- [Funkcionális (SAM) interfészek](#)
- [SAM konverziók](#)
- [Konstruktor függvényt tartalmazó interfész migrálása funkcionális interféssé](#)
- [Funkcionális interfészek vs. típusálnév-aliaszok](#)

## Láthatósági módosítók
- [Csomagok](#)
- [Osztálytagok](#)
- [Modulok](#)

## Kiterjesztések
- [Extension függvények](#)
- [A kiterjesztések statikus feloldása](#)
- [Nullable fogadó](#)
- [Extension tulajdonságok](#)
- [Társosztály (companion object) kiterjesztések](#)
- [Kiterjesztések hatóköre](#)
- [Kiterjesztések deklarálása tagként](#)
- [Megjegyzés a láthatóságról](#)

## Adatosztályok
- [Az osztály törzsében deklarált tulajdonságok](#)
- [Másolás](#)
- [Adatosztályok és destrukturáló deklarációk](#)
- [Standard adatosztályok](#)

## Sealed osztályok és interfészek
- [Sealed osztály vagy interfész deklarálása](#)
- [Öröklődés](#)
- [Sealed osztályok használata when kifejezéssel](#)
- [Használati forgatókönyvek](#)

## Generikák: in, out, where
- [Variancia](#)
- [Típusprojekciók](#)
- [Generikus függvények](#)
- [Generikus korlátozások](#)
- [Biztosan nem nullázható típusok](#)
- [Típus törlés](#)
- [Aláhúzás operátor típusargumentumokhoz](#)

### Beágyazott és belső osztályok
- [Belső osztályok](#)
- [Névtelen belső osztályok](#)

### Enum osztályok
- [Névtelen osztályok](#)
- [Interfészek implementálása enum osztályokban](#)
- [Munka az enum konstansokkal](#)

### Inline value osztályok
- [Tagok](#)
- [Öröklődés](#)
- [Reprezentáció](#)
- [Inline osztályok vs típusálnév-aliaszok](#)
- [Inline osztályok és delegálás](#)

### Objektum deklarációk és kifejezések
- [Objektum deklarációk](#)
- [Objektum kifejezések](#)
- [Viselkedésbeli különbség objektum deklarációk és kifejezések között](#)

### Delegálás
- [Interfész tag felülírása delegálással](#)

### Delegált tulajdonságok
- [Standard delegátok](#)
- [Delegálás másik tulajdonságra](#)
- [Tulajdonságok tárolása térképben](#)
- [Helyi delegált tulajdonságok](#)
- [Tulajdonság delegát követelmények](#)
- [Delegált tulajdonságok fordítási szabályai](#)
- [Delegát biztosítása](#)

### Típusálnév-aliaszok
- [Beágyazott típusálnév-aliaszok](#)

## Függvények
- [Függvény használat](#)
- [Függvény hatókör](#)
- [Generikus függvények](#)
- [Farkrekurzív függvények](#)

### Magasabbrendű függvények és lambdák
- [Magasabbrendű függvények](#)
- [Függvénytípusok](#)
- [Lambda kifejezések és névtelen függvények](#)

### Inline függvények
- [noinline](#)
- [Nem lokális ugrás kifejezések](#)
- [Reified típusparaméterek](#)
- [Inline tulajdonságok](#)
- [Korlátozások a publikus API inline függvényeire](#)

### Operátor túlterhelés
- [Unáris műveletek](#)
- [Bináris műveletek](#)
- [Infix hívások elnevezett függvényekre](#)

### Típusbiztos builder-ek
- [Hogyan működnek](#)
- [Hatáskör vezérlés: @DslMarker](#)
- [Builder-ek használata builder típusinferenciával](#)
- [Saját builder-ek írása](#)
- [Hogyan működik a builder inferencia](#)

### Kontextus paraméterek
- [Kontextus paraméterek feloldása](#)
- [Korlátozások](#)
- [Hogyan engedélyezzük a kontextus paramétereket](#)

## Null biztonság
- [Nullable és nem nullázható típusok](#)
- [Null ellenőrzés if feltétellel](#)
- [Biztonságos hívás operátor](#)
- [Elvis operátor](#)
- [Not-null kijelentés operátor](#)
- [Nullable fogadó](#)
- [Let függvény](#)
- [Biztonságos típuskényszerítések](#)
- [Nullable típusú kollekciók](#)

### Mi a következő?

## Egyenlőség
- [Strukturális egyenlőség](#)
- [Referencia szerinti egyenlőség](#)
- [Lebegőpontos számok egyenlősége](#)
- [Tömbök egyenlősége](#)

## This kifejezések
- [Minősített this](#)
- [Implicit this](#)

## Aszinkron programozási technikák
- [Szálkezelés](#)
- [Visszahívások (Callbacks)](#)
- [Futures, promises és egyebek](#)
- [Reaktív kiterjesztések](#)
- [Coroutine-ok](#)

## Coroutine-ok
- [Coroutine koncepciók](#)
- [Mi a következő?](#)

## Annotációk
- [Használat](#)
- [Konstruktorok](#)
- [Példányosítás](#)
- [Lambda kifejezések](#)
- [Annotáció használati hely célok](#)
- [Java annotációk](#)
- [Ismételhető annotációk](#)

## Destrukturáló deklarációk
- [Példa: két érték visszaadása függvényből](#)
- [Példa: destrukturáló deklarációk és térképek](#)
- [Aláhúzás használata nem használt változókhoz](#)
- [Destrukturálás lambda kifejezésekben](#)

## Reflektálás
- [JVM függőség](#)
- [Osztályreferenciák](#)
- [Hívható referenciák](#)

## Kotlin Notebook első lépések
- [Következő lépés](#)
- [Környezet beállítása](#)
- [Környezet beállítása](#)
- [Következő lépés](#)

## Az első Kotlin Notebook létrehozása
- [Üres projekt létrehozása](#)
- [Kotlin Notebook létrehozása](#)
- [Vázlat Kotlin Notebook létrehozása](#)
- [Következő lépés](#)

## Függőségek hozzáadása a Kotlin Notebook-hoz
- [Kotlin DataFrame és Kandy könyvtárak hozzáadása a Kotlin Notebook-hoz](#)
- [Mi a következő?](#)

## Kotlin Notebook megosztása
- [Mi a következő?](#)

## Kotlin Notebook által támogatott kimeneti formátumok
- [Szövegek](#)
- [HTML](#)
- [Képek](#)
- [Matematikai képletek és egyenletek](#)
- [Adatkeretek](#)
- [Diagramok](#)
- [Mi a következő?](#)

## Adatok lekérése fájlokból
- [Mielőtt elkezdesz](#)
- [Adatok lekérése fájlból](#)
- [Adatok megjelenítése](#)
- [Adatok finomítása](#)
- [DataFrame mentése](#)
- [Mi a következő?](#)

## Adatok lekérése webes forrásokból és API-król
- [Mielőtt elkezdesz](#)
- [Adatok lekérése API-ból](#)
- [Adatok tisztítása és finomítása](#)
- [Adatok elemzése Kotlin Notebook-ban](#)
- [Mi a következő?](#)

## Adatbázisokhoz való csatlakozás és adatok lekérése
- [Mielőtt elkezdesz](#)
- [Csatlakozás adatbázishoz](#)
- [Adatok lekérése és manipulálása](#)
- [Adatok elemzése Kotlin Notebook-ban](#)
- [Mi a következő?](#)

## Adatvizualizáció Kotlin Notebook-ban a Kandy segítségével
- [Mielőtt elkezdesz](#)
- [DataFrame létrehozása](#)
- [Vonalgrafikon létrehozása](#)
- [Pontdiagram létrehozása](#)
- [Oszlopdiagram létrehozása](#)
- [Mi a következő?](#)

## Kotlin és Java könyvtárak adatelemzéshez
- [Kotlin könyvtárak](#)
- [Java könyvtárak](#)

## Kotlin/JVM első lépések
- [Projekt létrehozása](#)
- [Alkalmazás létrehozása](#)
- [Alkalmazás futtatása](#)
- [Mi a következő?](#)

## Összehasonlítás Javával
- [Néhány Java probléma, amelyeket a Kotlin kezel](#)
- [Mit nyújt a Java, amit a Kotlin nem](#)
- [Mit nyújt a Kotlin, amit a Java nem](#)
- [Mi a következő?](#)

## Java hívása Kotlinból
- [Getterek és setterek](#)

### Java szintetikus tulajdonsághivatkozások
### Void visszatérési értékű metódusok
### Escape-elés Java azonosítókhoz, amelyek Kotlin kulcsszavak
### Null-biztonság és platform típusok
### Leképezett típusok
### Java generikák Kotlinban
### Java tömbök
### Java varargs
### Operátorok
### Ellenőrzött kivételek
### Objektum metódusok
### Öröklődés Java osztályokból
### Statikus tagok elérése
### Java reflektálás
### SAM konverziók
### JNI használata Kotlinnal
### Lombok által generált deklarációk használata Kotlinban

## Java hívása Kotlinból
- [Tulajdonságok](#)
- [Csomagszintű függvények](#)
- [Példányszintű mezők](#)
- [Statikus mezők](#)
- [Statikus metódusok](#)
- [Alapértelmezett metódusok interfészekben](#)
- [Láthatóság](#)
- [KClass](#)
- [Aláírásütközések kezelése @JvmName annotációval](#)
- [Túlterhelések generálása](#)
- [Ellenőrzött kivételek](#)
- [Null-biztonság](#)
- [Variáns generikák](#)
- [Inline value osztályok](#)

## Spring Boot és Kotlin első lépések
- [Következő lépés](#)
- [Csatlakozz a közösséghez](#)
- [Spring Boot projekt létrehozása Kotlinnal](#)
- [Mielőtt elkezdesz](#)
- [Spring Boot projekt létrehozása](#)
- [A projekt Gradle build fájljának vizsgálata](#)
- [A generált Spring Boot alkalmazás vizsgálata](#)
- [Controller létrehozása](#)
- [Alkalmazás futtatása](#)
- [Következő lépés](#)

## Adatosztály hozzáadása a Spring Boot projekthez
- [Alkalmazás frissítése](#)
- [Alkalmazás futtatása](#)
- [Következő lépés](#)

## Adatbázis-támogatás hozzáadása a Spring Boot projekthez
- [Adatbázis-támogatás hozzáadása](#)
- [MessageController osztály frissítése](#)
- [MessageService osztály frissítése](#)
- [Adatbázis konfigurálása](#)
- [Üzenetek hozzáadása adatbázishoz HTTP kérésen keresztül](#)
- [Üzenetek lekérése azonosító alapján](#)
- [Alkalmazás futtatása](#)
- [Következő lépés](#)

## Spring Data CrudRepository használata adatbázis eléréshez
- [Alkalmazás frissítése](#)
- [Alkalmazás futtatása](#)
- [Mi a következő?](#)

## Kotlin alkalmazás építése Spring AI-val dokumentumok alapján történő kérdések megválaszolásához
### Qdrant használata az oktatóanyaghoz
- [Projekt létrehozása](#)
- [Projekt konfiguráció frissítése](#)
- [Controller létrehozása dokumentumok betöltéséhez és kereséséhez](#)
- [AI chat végpont implementálása](#)

## Teszt kód JUnit használatával JVM-en – oktatóanyag
- [Függőségek hozzáadása](#)
- [Kód hozzáadása a teszteléshez](#)
- [Teszt létrehozása](#)
- [Teszt futtatása](#)
- [Mi a következő?](#)

## Java és Kotlin keverése egy projektben – oktatóanyag
- [Java forráskód hozzáadása meglévő Kotlin projekthez](#)
- [Kotlin forráskód hozzáadása meglévő Java projekthez](#)
- [Meglévő Java fájl konvertálása Kotlinra J2K segítségével](#)

## Java rekordok használata Kotlinban
- [Java rekordok használata Kotlin kódból](#)
- [Rekordok deklarálása Kotlinban](#)
- [Rekord komponensek annotálása Kotlinban](#)
- [Annotációk működtetése rekord komponensekkel](#)
- [További vita](#)

## Sztringek Javában és Kotlinban
- [Sztringek összefűzése](#)
- [Sztring építése](#)

### Sztring létrehozása kollekció elemeiből
### Alapértelmezett érték beállítása, ha a sztring üres
### Karakterek cseréje a sztring elején és végén
### Előfordulások cseréje
### Sztring szétválasztása
### Részsztring kivétele
### Többsoros sztringek használata
### Mi a következő?

## Kollekciók Javában és Kotlinban
- [Műveletek, amelyek megegyeznek Javában és Kotlinban](#)
- [Műveletek, amelyek kicsit eltérnek](#)
- [Műveletek, amelyek nem léteznek Java standard könyvtárában](#)
- [Módosíthatóság](#)
- [Kovariancia](#)
- [Tartományok és progressziók](#)
- [Összehasonlítás több szempont szerint](#)
- [Sorozatok](#)
- [Elemek eltávolítása listából](#)
- [Térkép bejárása](#)
- [Az első és utolsó elem lekérése lehetséges üres kollekcióból](#)
- [Halmaz létrehozása listából](#)
- [Elemek csoportosítása](#)
- [Elemek szűrése](#)
- [Kollekció transzformációs műveletek](#)
- [Mi a következő?](#)

## Nullázhatóság Javában és Kotlinban
- [Nullable típusok támogatása](#)
- [Platform típusok](#)
- [Biztosan nem nullázható típusok támogatása](#)
- [Függvényhívás eredményének ellenőrzése](#)
- [Alapértelmezett értékek null helyett](#)
- [Értéket vagy null-t visszaadó függvények](#)
- [Aggregáló műveletek](#)
- [Típusok biztonságos kényszerítése](#)
- [Mi a következő?](#)

## Standard bemenet
- [Olvasás standard bemenetről Java Scanner-rel](#)
- [Olvasás standard bemenetről readln() függvénnyel](#)

## Kotlin/Native első lépések
- [IDE-ben](#)
- [Gradle használatával](#)
- [Parancssoros fordító használatával](#)
- [Mi a következő?](#)

## Definíciós fájl
- [Definíciós fájl létrehozása és konfigurálása](#)
- [Tulajdonságok](#)
- [Kötések generálása parancssorból](#)
- [Mi a következő?](#)

## C és Objective-C könyvtárak importálásának stabilitása
- [Platform könyvtárak](#)
- [Harmadik féltől származó könyvtárak](#)
- [Natív könyvtártámogatás fejlődése](#)

## Interoperabilitás C-vel
- [Projekt beállítása](#)
- [Kötések](#)
- [Mi a következő?](#)

## C primitív adattípusok leképezése – oktatóanyag
- [Típusok C nyelvben](#)
- [C könyvtár létrehozása](#)
- [Kotlin/Native projekt létrehozása](#)
- [Generált Kotlin API-k vizsgálata C könyvtárhoz](#)
- [Kotlin kód frissítése](#)
- [Következő lépés](#)

## struct és union típusok leképezése C-ből – oktatóanyag
- [struct és union C típusok leképezése](#)
- [Generált Kotlin API-k vizsgálata C könyvtárhoz](#)
- [struct és union típusok használata Kotlinból](#)
- [Kotlin kód frissítése](#)
- [Következő lépés](#)

## Függvénymutatók leképezése C-ből – oktatóanyag
- [Függvénymutató típusok leképezése C-ből](#)
- [Generált Kotlin API-k vizsgálata C könyvtárhoz](#)
- [Kotlin függvény átadása C függvénymutatóként](#)
- [C függvénymutató használata Kotlinból](#)
- [Kotlin kód frissítése](#)
- [Következő lépés](#)

## Sztringek leképezése C-ből – oktatóanyag
- [Munka C sztringekkel](#)
- [Generált Kotlin API-k vizsgálata C könyvtárhoz](#)
- [Kotlin sztringek átadása C-nek](#)
- [C sztringek olvasása Kotlinban](#)
- [C sztring bájtok fogadása Kotlinból](#)
- [Kotlin kód frissítése](#)
- [Mi a következő?](#)

## Kotlin/Native dinamikus könyvtárként – oktatóanyag

## Kotlin könyvtár létrehozása
- [Generált fejlécfájl](#)
- [Generált fejlécek használata C-ből](#)
- [Projekt lefordítása és futtatása](#)
- [Mi a következő?](#)

## Alkalmazás létrehozása C interop és libcurl használatával – oktatóanyag
- [Mielőtt elkezdesz](#)
- [Definíciós fájl létrehozása](#)
- [Interoperabilitás hozzáadása a build folyamathoz](#)
- [Alkalmazás kódjának írása](#)
- [Alkalmazás lefordítása és futtatása](#)
- [Mi a következő?](#)

## Interoperabilitás Swift/Objective-C-vel
- [Swift/Objective-C könyvtárak importálása Kotlinba](#)
- [Kotlin használata Swift/Objective-C-ből](#)
- [Leképezések](#)
- [Típuskényszerítés leképzett típusok között](#)
- [Alosztályozás](#)
- [C funkciók](#)
- [Nem támogatott](#)

## Kotlin/Native Apple frameworkként – oktatóanyag
- [Kotlin könyvtár létrehozása](#)
- [Generált framework fejlécek](#)
- [Szemétgyűjtés és referenciaszámlálás](#)
- [Kód használata Objective-C-ből](#)
- [Kód használata Swift-ből](#)
- [Framework csatlakoztatása iOS projekthez](#)
- [Mi a következő?](#)

## Interoperabilitás Swifttel Swift export használatával
- [Swift export engedélyezése](#)
- [Jelenlegi korlátozások](#)
- [Leképezések](#)
- [Swift export fejlődése](#)

## Kotlin/Native könyvtárak
- [Kotlin fordító sajátosságok](#)
- [cinterop eszköz sajátosságok](#)
- [klib segédprogram](#)
- [Több példa](#)

## Haladó témák
- [Platform könyvtárak](#)
- [POSIX kötések](#)
- [Népszerű natív könyvtárak](#)
- [Mi a következő?](#)

## Kotlin/Native memóriakezelés
- [Szemétgyűjtő](#)
- [Memóriafelhasználás](#)
- [Egységtesztek a háttérben](#)
- [Mi a következő?](#)

## Integráció Swift/Objective-C ARC-vel
- [Szálak](#)
- [Szemétgyűjtés és életciklus](#)
- [Háttérállapot és App Extensions támogatása](#)
- [Mi a következő?](#)

## Migráció az új memóriakezelőre
- [Kotlin frissítése](#)
- [Függőségek frissítése](#)
- [Kód frissítése](#)
- [Mi a következő?](#)

## Kotlin/Native bináris opciók
- [Hogyan engedélyezzük](#)
- [Bináris opciók](#)
- [Mi a következő?](#)

## Kotlin/Native hibakeresés
- [Binárisok generálása hibakeresési információkkal](#)
- [Töréspontok beállítása](#)
- [Lépkedés használata](#)
- [Változók vizsgálata](#)
- [iOS alkalmazások hibakeresése](#)
- [Ismert problémák](#)

## Kotlin/Native célplatform támogatás
- [Tier 1](#)
- [Tier 2](#)
- [Tier 3](#)
- [Könyvtárfejlesztőknek](#)

## Tippek a fordítási idő javításához
- [Általános javaslatok](#)
- [Gradle konfiguráció](#)
- [Windows konfiguráció](#)
- [LLVM konfiguráció](#)
- [Tippek az LLVM backend testreszabásához](#)
- [Build napló vizsgálata](#)
- [LLVM optimalizációs lépések testreszabása](#)

## Licencfájlok a Kotlin/Native binárisokhoz

## Kotlin/Native GYIK
- [Hogyan futtassam a programomat?](#)
- [Mi a Kotlin/Native memóriakezelési modellje?](#)
- [Hogyan hozzak létre megosztott könyvtárat?](#)
- [Hogyan hozzak létre statikus könyvtárat vagy objektumfájlt?](#)
- [Hogyan futtassam a Kotlin/Native-ot vállalati proxy mögött?](#)
- [Hogyan adhatok meg egyéni Objective-C előtagot/nevet a Kotlin keretrendszeremhez?](#)
- [Hogyan nevezzem át az iOS keretrendszert?](#)
- [Hogyan engedélyezzem a bitcode-ot a Kotlin keretrendszeremhez?](#)
- [Hogyan hivatkozhatok biztonságosan objektumokra különböző coroutine-okból?](#)
- [Hogyan fordíthatom le a projektemet a Kotlin/Native nem kiadott verzióival?](#)

## Első lépések Kotlin/Wasm és Compose Multiplatformmal
- [Projekt létrehozása](#)
- [Alkalmazás futtatása](#)
- [Artefaktumok generálása](#)
- [Alkalmazás közzététele](#)
- [Mi a következő?](#)

## Első lépések Kotlin/Wasm és WASI-val
- [Mielőtt elkezdesz](#)
- [Alkalmazás futtatása](#)
- [Alkalmazás tesztelése](#)
- [Mi a következő?](#)

## Kotlin/Wasm kód hibakeresése
- [Mielőtt elkezdesz](#)
- [Hibakeresés IntelliJ IDEA-ban](#)
- [Hibakeresés böngészőben](#)
- [Visszajelzés küldése](#)
- [Mi a következő?](#)

## Interoperabilitás JavaScript-tel
- [JavaScript kód használata Kotlinban](#)
- [Kotlin kód használata JavaScriptben](#)
- [Típusmegfeleltetés](#)
- [Kivételkezelés](#)
- [Kotlin/Wasm és Kotlin/JS interoperabilitási különbségek](#)
- [Webes böngésző API-k](#)
- [Támogatott verziók és konfiguráció](#)
- [Böngészőverziók](#)
- [Wasm javaslatok támogatása](#)
- [Alapértelmezett import használata](#)
- [Lassú Kotlin/Wasm fordítás](#)
- [Diagnosztika teljesen minősített osztálynevekben](#)
- [Tömb túlindexelési hozzáférés és csapdák](#)
- [Kísérleti annotációk](#)
- [Újratöltések hibakeresés közben](#)

## Kotlin/JS projekt beállítása
- [Végrehajtási környezetek](#)
- [ES2015 funkciók támogatása](#)
- [Kimeneti granularitás konfigurálása](#)
- [TypeScript deklarációs fájlok (d.ts) generálása](#)
- [Függőségek](#)
- [run task](#)
- [test task](#)
- [webpack csomagolás](#)
- [CSS](#)
- [Node.js](#)
- [Yarn](#)
- [Elosztási célkönyvtár](#)
- [Modulnév](#)
- [package.json testreszabása](#)

## Kotlin/JS futtatása
- [Node.js cél futtatása](#)
- [Böngésző cél futtatása](#)
- [Fejlesztői szerver és folyamatos fordítás](#)

## Kotlin/JS kód hibakeresése
- [Hibakeresés böngészőben](#)
- [Hibakeresés az IDE-ben](#)
- [Hibakeresés Node.js-ben](#)
- [Mi a következő?](#)
- [Ha problémába ütközik](#)

## Tesztek futtatása Kotlin/JS-ben
- [Kotlin/JS keretrendszerek](#)
  - [Kobweb](#)
  - [Kilua](#)
  - [Kotlin React](#)
  - [KVision](#)
  - [fritz2](#)
  - [Doodle](#)

## Kotlin/JS fordító funkciók
- [Felső szintű tulajdonságok lusta inicializálása](#)
- [Inkrementális fordítás fejlesztési binárisokhoz](#)
- [Tagnevek minősítése éles környezetben](#)
- [Halott kód eliminálása](#)
- [JS egyszerű objektumok fordító plugin](#)
  - [Egyszerű JS objektumok](#)
  - [Plugin engedélyezése](#)
  - [Egyszerű objektum típus deklarálása](#)
  - [Egyszerű objektumok használata](#)
  - [Mi a következő?](#)

## Böngésző és DOM API
- [DOM-mal való interakció](#)
- [JavaScript kód használata Kotlinból](#)
- [Inline JavaScript](#)
- [external módosító](#)
- [Egyenlőség](#)
- [Dinamikus típus](#)
- [Függőségek használata npm-ből](#)
- [Kotlin kód használata JavaScriptből](#)
- [Deklarációk izolálása külön JavaScript objektumba egyszerű módban](#)
- [Csomagstruktúra](#)
- [Kotlin típusok JavaScriptben](#)
- [JavaScript modulok](#)
- [Böngésző célok](#)
- [JavaScript könyvtárak és Node.js fájlok](#)
- [@JsModule annotáció](#)

## Kotlin/JS reflektálás
- [Osztályhivatkozások](#)
- [KType és typeOf()](#)
- [KClass és createInstance()](#)
- [Példa](#)

## Típusbiztos HTML DSL
## Első lépések Kotlin egyéni szkripteléssel – oktatóanyag
- [Projekt struktúra](#)
- [Mielőtt elkezdesz](#)
- [Projekt létrehozása](#)
- [Szkriptmodulok hozzáadása](#)
- [Szkriptdefiníció létrehozása](#)
- [Szkripthoszt létrehozása](#)
- [Szkriptek futtatása](#)
- [Mi a következő?](#)

## Kollekciók áttekintése
- [Kollekciótípusok](#)
- [Kollekciók létrehozása](#)
  - [Elemekből való létrehozás](#)
  - [Kollekció-építő függvényekkel való létrehozás](#)
  - [Üres kollekciók](#)
  - [Listák inicializáló függvényei](#)
  - [Konkrét típus konstruktorai](#)
  - [Másolás](#)
  - [Függvények hívása más kollekciókon](#)

## Iterátorok
- [Lista iterátorok](#)
- [Módosítható iterátorok](#)

## Tartományok és progressziók
- [Tartományok](#)
- [Progressziók](#)

## Sorozatok
- [Létrehozás](#)
- [Sorozatműveletek](#)
- [Sorozatfeldolgozási példa](#)

## Kollekcióműveletek áttekintése
- [Kiterjesztési és tagfüggvények](#)
- [Gyakori műveletek](#)
- [Írási műveletek](#)

## Kollekció-transzformációs műveletek
- [Map](#)
- [Zip](#)
- [Associate](#)
- [Flatten](#)
- [String reprezentáció](#)

## Kollekciók szűrése
- [Szűrés predikátum alapján](#)
- [Partícionálás](#)
- [Predikátumok tesztelése](#)
- [Plusz és mínusz operátorok](#)

## Csoportosítás
## Kollekciórészek lekérése
- [Slice](#)
- [Take és drop](#)
- [Chunked](#)
- [Windowed](#)

## Egyetlen elem lekérése
- [Pozíció alapján](#)
- [Feltétel alapján](#)
- [Szelektorral](#)
- [Véletlen elem](#)

## Elemlétezés ellenőrzése
## Rendezés
- [Természetes sorrend](#)
- [Egyéni sorrendek](#)
- [Fordított sorrend](#)
- [Véletlen sorrend](#)

## Aggregáló műveletek
- [Fold és reduce](#)

## Kollekció írási műveletek
- [Elemek hozzáadása](#)
- [Elemek eltávolítása](#)
- [Elemek frissítése](#)

## Listára jellemző műveletek
- [Elemek lekérése index alapján](#)
- [Lista részeinek lekérése](#)
- [Elempozíciók meghatározása](#)
- [Lista írási műveletek](#)

## Halmazra jellemző műveletek
## Térképre jellemző műveletek
- [Kulcsok és értékek lekérése](#)
- [Szűrés](#)
- [Plusz és mínusz operátorok](#)
- [Térkép írási műveletek](#)

## Standard bemenet olvasása
- [Standard bemenet biztonságos kezelése](#)

## Opt-in követelmények
- [API-hoz való opt-in](#)
- [API használatához opt-in követelménye](#)
- [API kiterjesztéséhez opt-in követelménye](#)
- [Pre-stabil API-khoz opt-in követelmények](#)

## Hatókör függvények
- [Függvény kiválasztás](#)
- [Különbségek](#)
- [Függvények](#)
- [takeIf és takeUnless](#)

## Időmérés
- [Időtartam kiszámítása](#)
- [Idő mérése](#)
- [Időforrások](#)

## Coroutine útmutató
- [Tartalomjegyzék](#)
- [További hivatkozások](#)

## Coroutine alapok
- [Az első coroutine-od](#)
- [Függvény kibontási refaktorálás](#)
- [Hatókör építő](#)
- [Hatókör építő és konkurrencia](#)
- [Explicit job](#)
- [Coroutine-ok könnyűsúlyúak](#)

## Coroutine-ok és csatornák – oktatóanyag
- [Mielőtt elkezdesz](#)
- [Blokkoló kérések](#)
- [Visszahívások](#)
- [Felfüggesztő függvények](#)
- [Coroutine-ok](#)
- [Konkurrencia](#)
- [Strukturált konkurrencia](#)
- [Haladás megjelenítése](#)
- [Csatornák](#)
- [Tesztelés coroutine-ok](#)
- [Mi a következő?](#)

## Törlés és időkorlátok
- [Coroutine végrehajtás törlése](#)
- [A törlés együttműködő](#)
- [Számítási kód törlésképessé tétele](#)
- [Erőforrások lezárása finally blokkal](#)
- [Nem törlésképes blokk futtatása](#)
- [Időkorlát](#)
- [Aszinkron időkorlát és erőforrások](#)

## Felfüggesztő függvények összeállítása
- [Soros alapértelmezés szerint](#)
- [Párhuzamos async használatával](#)
- [Lusta indítású async](#)
- [Async-stílusú függvények](#)
- [Strukturált konkurrencia async-kel](#)

## Coroutine kontextus és diszpécser
- [Diszpécserek és szálak](#)
- [Korlátozatlan vs korlátozott diszpécser](#)
- [Coroutine-ok és szálak hibakeresése](#)
- [Ugrás szálak között](#)
- [Job a kontextusban](#)
- [Coroutine gyermekek](#)
- [Szülői felelősségek](#)
- [Coroutine-ok elnevezése hibakereséshez](#)
- [Kontextuselemek kombinálása](#)
- [Coroutine hatókör](#)

## Aszinkron folyam
- [Több érték reprezentálása](#)
- [Folyamok hidegek](#)
- [Folyamtörlés alapjai](#)
- [Folyamépítők](#)
- [Köztes folyamoperátorok](#)
- [Terminális folyamoperátorok](#)
- [Folyamok sorosak](#)
- [Folyamkontextus](#)
- [Pufferelés](#)
- [Több folyam összeállítása](#)
- [Folyamok lapítása](#)
- [Folyamkivételek](#)
- [Kivétel átlátszóság](#)
- [Folyambefejezés](#)
- [Imperatív vs deklaratív](#)
- [Folyam indítása](#)
- [Folyam és reaktív streamek](#)

## Csatornák
- [Csatorna alapok](#)
- [Csatornák lezárása és iterálás](#)
- [Csatornaproducer építése](#)
- [Pipeline-ok](#)
- [Prímszámok pipeline-nal](#)
- [Fan-out](#)
- [Fan-in](#)
- [Pufferelt csatornák](#)
- [Csatornák igazságosak](#)
- [Ticker csatornák](#)

## Coroutine kivételkezelés
- [Kivétel propagálás](#)
- [CoroutineExceptionHandler](#)
- [Törlés és kivételek](#)
- [Kivételek aggregálása](#)
- [Felügyelet](#)

## Megosztott módosítható állapot és konkurrencia
- [A probléma](#)
- [Volatile-ok nem segítenek](#)
- [Szálbiztos adatstruktúrák](#)
- [Szálkonfinement finomhangolású](#)
- [Szálkonfinement durván hangolású](#)
- [Kölcsönös kizárás](#)
- [Select kifejezés (kísérleti)](#)
- [Csatornákból való választás](#)
- [Lezárásnál való választás](#)
- [Küldésnél való választás](#)
- [Késleltetett értékek kiválasztása](#)
- [Késleltetett értékek csatornájának váltása](#)

## Coroutine-ok hibakeresése IntelliJ IDEA-val – oktatóanyag
- [Coroutine-ok létrehozása](#)
- [Coroutine-ok hibakeresése](#)

## Kotlin Flow hibakeresése IntelliJ IDEA-val – oktatóanyag
- [Kotlin flow létrehozása](#)
- [Coroutine hibakeresése](#)
- [Párhuzamosan futó coroutine hozzáadása](#)
- [Kotlin flow hibakeresése két coroutine-nal](#)

## Serializálás
- [Könyvtárak](#)
- [Formátumok](#)
- [Példa: JSON serializálás](#)
- [Mi a következő?](#)

## Kotlin Metadata JVM könyvtár
- [Könyvtár hozzáadása a projekthez](#)
- [Metaadatok olvasása és elemzése](#)
- [Metaadatok módosítása](#)
- [Metaadatok létrehozása nulláról](#)
- [Mi a következő?](#)

## Lincheck útmutató
- [Lincheck hozzáadása a projekthez](#)
- [Lincheck felfedezése](#)
- [További hivatkozások](#)

## Az első teszt írása Lincheck-kel
- [Projekt létrehozása](#)
- [Szükséges függőségek hozzáadása](#)
- [Konkurrens számláló írása és a teszt futtatása](#)
- [Érvénytelen végrehajtás nyomkövetése](#)
- [Java standard könyvtár tesztelése](#)
- [Következő lépés](#)
- [Lásd még](#)

## Stressztesztelés és modell-ellenőrzés
- [Stressztesztelés](#)
- [Modell-ellenőrzés](#)
- [Melyik tesztelési stratégia a jobb?](#)
- [Tesztelési stratégia konfigurálása](#)
- [Forgatókönyv minimalizálás](#)
- [Adatstruktúra állapotok naplózása](#)
- [Következő lépés](#)

## Művelet argumentumok
- [Következő lépés](#)

## Adatstruktúra korlátozások
- [Következő lépés](#)

## Haladási garanciák
- [Következő lépés](#)

## Szekvenciális specifikáció
## API hivatkozások

## Kulcsszavak és operátorok
- [Kemény kulcsszavak](#)
- [Lágy kulcsszavak](#)
- [Módosító kulcsszavak](#)
- [Speciális azonosítók](#)
- [Operátorok és speciális szimbólumok](#)

## Gradle
- [Mi a következő?](#)

## Első lépések Gradle-lel és Kotlin/JVM-mel
- [Projekt létrehozása](#)
- [Build szkript felfedezése](#)
- [Alkalmazás futtatása](#)
- [Mi a következő?](#)

## Gradle projekt konfigurálása
- [Plugin alkalmazása](#)
- [JVM célzása](#)
- [Több platform célzása](#)
- [Android célzása](#)
- [Web célzása](#)
- [Konfigurációs műveletek kiváltása a KotlinBasePlugin interfésszel](#)
- [Függőségek konfigurálása](#)
- [Tárolók deklarálása](#)
- [Mi a következő?](#)

## Gradle legjobb gyakorlatok
- [Szervezés](#)
- [Optimalizálás](#)

## Fordító opciók a Kotlin Gradle pluginben
- [Hogyan definiáljuk az opciókat](#)
- [JVM célzása](#)
- [JavaScript célzása](#)
- [Minden Kotlin fordítási feladat](#)
- [Minden fordító opció](#)
- [Mi a következő?](#)

## Fordítás és gyorsítótárak a Kotlin Gradle pluginben
- [Inkrementális fordítás](#)
- [Gradle build cache támogatás](#)
- [Gradle konfigurációs cache támogatás](#)
- [A Kotlin daemon és hogyan használjuk Gradle-lel](#)
- [Visszatérés az előző fordítóhoz](#)
- [Kotlin fordító végrehajtási stratégia meghatározása](#)
- [Kotlin fordító fallback stratégia](#)
- [A legújabb nyelvi verzió kipróbálása](#)
- [Építési jelentések](#)
- [Mi a következő?](#)

## Bináris kompatibilitás validálása a Kotlin Gradle pluginben
- [Hogyan engedélyezzük](#)
- [Bináris kompatibilitási problémák ellenőrzése](#)
- [Referencia ABI dump frissítése](#)
- [Szűrők konfigurálása](#)
- [Nem támogatott célokhoz következtetett változások megelőzése](#)
- [Gradle plugin variánsok támogatása](#)
- [Hibaelhárítás](#)
- [Mi a következő?](#)

## Maven
- [Plugin konfigurálása és engedélyezése](#)
- [Tárolók deklarálása](#)
- [Függőségek beállítása](#)
- [Csak Kotlin forráskód fordítása](#)
- [Kotlin és Java források fordítása](#)
- [Kotlin fordító végrehajtási stratégia konfigurálása](#)
- [Inkrementális fordítás engedélyezése](#)
- [Annotáció feldolgozás konfigurálása](#)
- [JAR fájl létrehozása](#)
- [Önellátó JAR fájl létrehozása](#)
- [Fordító opciók megadása](#)
- [BOM használata](#)
- [Dokumentáció generálása](#)
- [OSGi támogatás engedélyezése](#)

## Build eszközök API
- [Integráció Gradle-lel](#)
- [Integráció Maven-nel](#)
- [Kotlin daemon](#)
- [Kotlin daemon konfigurálása](#)

## Ant
- [Ant feladatok beszerzése](#)
- [JVM célzása csak Kotlin forrással](#)
- [JVM célzása csak Kotlin forrással és több gyökérrel](#)
- [JVM célzása Kotlin és Java forrással](#)
- [JavaScript célzása egyetlen forrásmappával](#)
- [JavaScript célzása Prefix, PostFix és sourcemap opciókkal](#)
- [JavaScript célzása egyetlen forrásmappával és metaInfo opcióval](#)
- [Hivatkozások](#)

## Bevezetés
- [Közösség](#)

## Első lépések Dokka-val
- [Gradle](#)
- [Dokka alkalmazása](#)
- [Dokumentáció generálása](#)
- [javadoc.jar létrehozása](#)
- [Konfigurációs példák](#)
- [Konfigurációs opciók](#)
- [Migrálás Dokka Gradle plugin v2-re](#)
- [Mielőtt elkezdesz](#)
- [Projekt migrálása](#)
- [Migráció véglegesítése](#)
- [Hibaelhárítás](#)
- [Mi a következő](#)

## Maven
- [Dokka alkalmazása](#)
- [Dokumentáció generálása](#)
- [javadoc.jar létrehozása](#)
- [Konfigurációs példa](#)
- [Konfigurációs opciók](#)

## CLI
- [Első lépések](#)
- [Dokumentáció generálása](#)
- [Parancssori opciók](#)
- [JSON konfiguráció](#)

## HTML
- [HTML dokumentáció generálása](#)
- [Konfiguráció](#)
- [Testreszabás](#)

## Markdown
- [GFM](#)
- [Jekyll](#)

## Javadoc
- [Javadoc dokumentáció generálása](#)

## Dokka pluginok
- [Dokka pluginok alkalmazása](#)
- [Dokka pluginok konfigurálása](#)
- [Jelentős pluginok](#)

## Modul dokumentáció
- [Fájlformátum](#)
- [Fájlok átadása Dokka-nak](#)

## IDE-k Kotlin fejlesztéshez
- [IntelliJ IDEA](#)
- [Android Studio](#)
- [Eclipse](#)
- [Kompatibilitás a Kotlin nyelvi verziókkal](#)
- [Egyéb IDE-k támogatása](#)
- [Mi a következő?](#)

## Migrálás Kotlin kódstílusra
- [Kotlin kódolási konvenciók és IntelliJ IDEA formázó](#)
- [Különbségek a "Kotlin kódolási konvenciók" és az "IntelliJ IDEA alapértelmezett kódstílus" között](#)
- [Migráció új kódstílusra vita](#)
- [Migráció új kódstílusra](#)
- [Régi kódstílus tárolása projektben](#)

## Kotlin Notebook
- [Adatelemzés és vizualizáció](#)
- [Prototípuskészítés](#)
- [Backend fejlesztés](#)
- [Kód dokumentáció](#)
- [Kód és kimenetek megosztása](#)
- [Mi a következő](#)

## Adatvizualizáció Lets-Plot for Kotlin-tal
- [Mielőtt elkezdesz](#)
- [Adatok előkészítése](#)
- [Szórási diagram létrehozása](#)
- [Dobozdiagram létrehozása](#)
- [2D sűrűségi diagram létrehozása](#)
- [Mi a következő](#)

## Kódrészletek futtatása
- [IDE: vázlatok és munkalapok](#)
- [Böngésző: Kotlin Playground](#)
- [Parancssor: ki shell](#)

## Kotlin és folyamatos integráció TeamCity-vel
- [Gradle, Maven és Ant](#)
- [IntelliJ IDEA Build Rendszer](#)
- [Egyéb CI szerverek](#)

## Kotlin kód dokumentálása: KDoc
- [KDoc szintaxis](#)
- [Inline jelölés](#)
- [Mi a következő?](#)

## Kotlin és OSGi
- [Maven](#)
- [Gradle](#)

## GYIK
## K2 fordító migrációs útmutató
- [Teljesítményjavulások](#)
- [Nyelvi funkció javulások](#)
- [Hogyan engedélyezzük a Kotlin K2 fordítót](#)
- [IDE támogatás](#)
- [Kotlin K2 fordító kipróbálása a Kotlin Playground-ben](#)
- [Hogyan térjünk vissza az előző fordítóhoz](#)
- [Változások](#)
- [Kompatibilitás a Kotlin kiadásokkal](#)
- [Kompatibilitás a Kotlin könyvtárakkal](#)
- [Fordító pluginok támogatása](#)
- [Visszajelzés megosztása az új K2 fordítóról](#)

## Kotlin parancssoros fordító
- [Fordító telepítése](#)
- [Alkalmazás létrehozása és futtatása](#)
- [Könyvtár fordítása](#)
- [REPL futtatása](#)
- [Szkriptek futtatása](#)

## Kotlin fordító opciók
- [Fordító opciók](#)
- [Séma a fordító opciókhoz](#)
- [Közös opciók](#)
- [Kotlin/JVM fordító opciók](#)
- [Kotlin/JS fordító opciók](#)
- [Kotlin/Native fordító opciók](#)

## All-open fordító plugin
- [Gradle](#)
- [Maven](#)
- [Spring támogatás](#)
- [Parancssoros fordító](#)

## No-arg fordító plugin
- [A Kotlin fájlban](#)
- [Gradle](#)
- [Maven](#)
- [JPA támogatás](#)
- [Parancssoros fordító](#)

## SAM-with-receiver fordító plugin
- [Gradle](#)
- [Maven](#)
- [Parancssoros fordító](#)

## kapt fordító plugin
- [Gradle-ben való használat](#)
- [Annotáció feldolgozó argumentumok](#)
- [Gradle build cache támogatás](#)
- [kapt-et használó build-ek sebességének javítása](#)
- [Fordítási elkerülés kapt esetén](#)
- [Inkrementális annotáció feldolgozás](#)
- [Annotáció feldolgozók öröklése a szuperkonfigurációkból](#)
- [Java fordító opciók](#)
- [Nem létező típus korrekció](#)
- [Maven-ben való használat](#)
- [IntelliJ build rendszerben való használat](#)
- [CLI-ben való használat](#)
- [Kotlin források generálása](#)
- [AP/Javac opciók kódolása](#)
- [Java fordító annotáció feldolgozóinak megtartása](#)

## Lombok fordító plugin
- [Támogatott annotációk](#)
- [Gradle](#)
- [Maven](#)
- [kapt-tel való használat](#)
- [Parancssoros fordító](#)

## Power-assert fordító plugin
- [Plugin alkalmazása](#)
- [Plugin konfigurálása](#)
- [Plugin használata](#)
- [Mi a következő](#)

## Compose fordító migrációs útmutató
- [Jetpack Compose projekt migrálása](#)
- [Mi a következő](#)

## Compose fordító opciók DSL
- [Funkcióflag-ek célja és használata](#)

## Kotlin Symbol Processing API
- [Áttekintés](#)
- [Hogyan néz a KSP a forrásfájlokat](#)
- [SymbolProcessorProvider: a belépési pont](#)
- [Erőforrások](#)
- [Támogatott könyvtárak](#)

## KSP gyorsindítás
- [Feldolgozó hozzáadása](#)
- [Saját feldolgozó létrehozása](#)
- [Saját feldolgozó használata projektben](#)
- [Opciók átadása feldolgozóknak](#)
- [IDE tudatása a generált kódról](#)
- [Miért KSP](#)
- [KSP megkönnyíti könnyűsúlyú fordító pluginok létrehozását](#)
- [Összehasonlítás kotlinc fordító pluginokkal](#)
- [Összehasonlítás reflektálással](#)
- [Összehasonlítás kapt-tal](#)
- [Korlátozások](#)

## KSP példák
- [Minden tagfüggvény lekérése](#)
- [Ellenőrzés, hogy egy osztály vagy függvény lokális-e](#)
- [Az aktuális osztály vagy interfész deklaráció megtalálása, amelyre a típusálnév mutat](#)
- [Elnyomott nevek gyűjtése egy fájlannotációban](#)

## Hogyan modellez a KSP Kotlin kódot
- [Típus és feloldás](#)
- [Java annotáció feldolgozás KSP hivatkozáshoz](#)
- [Program elemek](#)
- [Típusok](#)
- [Egyéb](#)
- [Részletek](#)

## Inkrementális feldolgozás
- [Aggregáló vs Izoláló](#)
- [1. példa](#)
- [2. példa](#)
- [Hogyan határozódik meg a fájl szennyezettsége](#)
- [Hibák bejelentése](#)
- [Többkörös feldolgozás](#)
- [Változások a feldolgozón](#)
- [Többkörös viselkedés](#)

## Haladó
- [KSP Kotlin Multiplatform-mal](#)
- [Fordítás és feldolgozás](#)
- [A ksp(...) konfiguráció elkerülése KSP 1.0.1+ verziónál](#)
- [KSP futtatása parancssorból](#)

## KSP GYIK
- [Miért KSP?](#)
- [Miért gyorsabb a KSP a kapt-nál?](#)
- [A KSP Kotlin-specifikus?](#)
- [Hogyan frissítsem a KSP-t?](#)
- [Használhatok újabb KSP implementációt régebbi Kotlin fordítóval?](#)
- [Milyen gyakran frissítitek a KSP-t?](#)
- [A Kotlin mellett vannak más verziókövetelmények a könyvtárakhoz?](#)
- [Mi a KSP jövőbeli útvonalterve?](#)

## Tanulási anyagok áttekintése
- [Kotlin Koans](#)
- [Kotlin hands-on](#)
  - [Reaktív Spring Boot alkalmazások építése Kotlin coroutine-okkal és RSocket-tel](#)
  - [Webalkalmazások építése React-tel és Kotlin/JS-sel](#)
  - [Webalkalmazások építése Spring Boot-tal és Kotlin-nal](#)
  - [HTTP API-k létrehozása Ktor-ral](#)
  - [WebSocket chat létrehozása Ktor-ral](#)
  - [Interaktív weboldal létrehozása Ktor-ral](#)
  - [Bevezetés Kotlin coroutine-okba és csatornákba](#)
  - [Bevezetés Kotlin/Native-be](#)
  - [Kotlin Multiplatform: hálózatkezelés és adattárolás](#)
  - [iOS és Android célzása Kotlin Multiplatformmal](#)

## Kotlin tippek
- [null + null Kotlinban](#)
- [Kollekciós elemek deduplikálása](#)
- [A suspend és inline rejtély](#)
- [Deklarációk "kicsomagolása" teljesen minősített névvel](#)
- [Return és throw az Elvis operátorral](#)
- [Destrukturáló deklarációk](#)
- [Operátorfüggvények nullable értékekkel](#)
- [Kód időzítése](#)
- [Ciklusok javítása](#)
- [Sztringek](#)
- [Több az Elvis operátorral](#)
- [Kotlin kollekciók](#)
- [Mi a következő?](#)

## Kotlin könyvek
## Advent of Code feladványok idiomatikus Kotlinban
- [Felkészülés Advent of Code-ra](#)
- [Advent of Code 2022](#)
- [Advent of Code 2021](#)
- [Advent of Code 2020](#)
- [Mi a következő?](#)

## Kotlin tanulása JetBrains Academy pluginnel
## Kotlin tanítása JetBrains Academy pluginnel
## Bevezetés könyvtárfejlesztők irányelveibe
- [Mi a következő](#)

## Mentális komplexitás minimalizálása áttekintés
- [Következő lépés](#)

## Egyszerűség
- [Explicit API mód használata](#)
- [Meglévő koncepciók újrahasznosítása](#)
- [Core API definiálása és építkezés rá](#)
- [Következő lépés](#)

## Olvashatóság
- [Explicit composable előnyben részesítése](#)
- [DSL-ek használata](#)
- [Kiterjesztési függvények és tulajdonságok használata](#)
- [Boolean típus használatának elkerülése argumentumként](#)
- [Numerikus típusok megfelelő használata](#)
- [Következő lépés](#)

## Konzisztencia
- [Paramétersorrend, elnevezés és használat megőrzése](#)
- [Objektumorientált tervezés használata adatokhoz és állapothoz](#)
- [Megfelelő hibakezelési mechanizmus kiválasztása](#)
- [Konvenciók és minőség fenntartása](#)
- [Következő lépés](#)

## Prediktibilitás
- [Az alapértelmezett helyes dolog megcsinálása](#)
- [Kiterjesztési lehetőségek biztosítása](#)
- [Nem kívánt és érvénytelen kiterjesztések megelőzése](#)
- [Módosítható állapot exposztálásának elkerülése](#)
- [Bemenetek és állapot validálása](#)
- [Következő lépés](#)

## Hibakereshetőség
- [toString metódus biztosítása állapottal rendelkező típusokhoz](#)
- [Kivételkezelési politika elfogadása és dokumentálása](#)
- [Következő lépés](#)

## Tesztelhetőség
- [Globális állapot és állapotfüggő felső szintű függvények elkerülése](#)
- [Mi a következő](#)

## Visszamenőleges kompatibilitási irányelvek könyvtárfejlesztőknek
- [Kompatibilitási típusok](#)
- [Bináris kompatibilitás validátor használata](#)
- [Visszatérési típusok explicit meghatározása](#)
- [Argumentumok hozzáadásának elkerülése meglévő API függvényekhez](#)
- [Visszatérési típusok szélesítésének vagy keskenyítésének elkerülése](#)
- [Adatosztályok használatának elkerülése az API-ban](#)
- [A PublishedApi annotáció használatának megfontolásai](#)
- [API-k pragmatikus fejlesztése](#)
- [A RequiresOptIn mechanizmus használata](#)
- [Mi a következő](#)

## Legjobb gyakorlatok könyvtárfejlesztőknek informatív dokumentáció létrehozásához
- [Átfogó dokumentáció biztosítása](#)
- [Felhasználói személyiségek létrehozása](#)
- [Dokumentálás példával, amikor csak lehetséges](#)
- [API alapos dokumentálása](#)
- [Lambda paraméterek dokumentálása](#)
- [Explicit hivatkozások használata dokumentációban](#)
- [Önellátóan működni, amikor csak lehetséges](#)
- [Egyszerű angol használata](#)
- [Mi a következő](#)

## Kotlin könyvtár építése multiplatformhoz
- [Elérés maximalizálása](#)
- [API-k tervezése közös kodból való használatra](#)
- [Konzisztens viselkedés biztosítása platformok között](#)
- [Tesztelés minden platformon](#)
- [Nem Kotlin felhasználók figyelembevétele](#)
- [Könyvtár népszerűsítése](#)

## Részvétel a Kotlin Early Access Preview-ban
- [Hogyan segíthet az EAP produktívabbá válni a Kotlinnal](#)
- [Építési részletek](#)
- [Build konfigurálása EAP-hoz](#)
- [Konfigurálás Gradle-ben](#)
- [Konfigurálás Maven-ben](#)
- [Ha problémába ütközik](#)

## GYIK
- [Mi az a Kotlin?](#)
- [Mi a jelenlegi Kotlin verzió?](#)
- [A Kotlin ingyenes?](#)
- [A Kotlin objektumorientált vagy funkcionális nyelv?](#)
- [Milyen előnyöket nyújt a Kotlin a Java programozási nyelvhez képest?](#)
- [A Kotlin kompatibilis a Java programozási nyelvvel?](#)
- [Mire használhatom a Kotlin-t?](#)
- [Használhatom a Kotlin-t Android fejlesztéshez?](#)
- [Használhatom a Kotlin-t szerveroldali fejlesztéshez?](#)
- [Használhatom a Kotlin-t webfejlesztéshez?](#)
- [Használhatom a Kotlin-t asztali fejlesztéshez?](#)
- [Használhatom a Kotlin-t natív fejlesztéshez?](#)
- [Mely IDE-k támogatják a Kotlin-t?](#)
- [Mely build eszközök támogatják a Kotlin-t?](#)
- [Mire fordul le a Kotlin?](#)
- [Mely JVM verziókat célozza a Kotlin?](#)
- [Nehéz a Kotlin?](#)
- [Mely cégek használják a Kotlin-t?](#)
- [Ki fejleszti a Kotlin-t?](#)
- [Hol tudok többet megtudni a Kotlin-ról?](#)
- [Vannak Kotlin könyvek?](#)
- [Vannak elérhető online kurzusok Kotlinhoz?](#)
- [Van Kotlin közösség?](#)
- [Vannak Kotlin események?](#)
- [Van Kotlin konferencia?](#)
- [A Kotlin elérhető a közösségi médiában?](#)
- [Vannak egyéb online Kotlin erőforrások?](#)
- [Hol szerezhetek HD Kotlin logót?](#)

## Kompatibilitási útmutató Kotlin 2.2-höz
- [Alapfogalmak](#)
- [Nyelv](#)
- [Standard könyvtár](#)
- [Eszközök](#)

## Kompatibilitási útmutató Kotlin 2.1-hez
- [Alapfogalmak](#)
- [Nyelv](#)
- [Standard könyvtár](#)
- [Eszközök](#)

## Kompatibilitási útmutató Kotlin 2.0-hoz
- [Alapfogalmak](#)
- [Nyelv](#)
- [Eszközök](#)

## Kompatibilitási útmutató Kotlin 1.9-hez
- [Alapfogalmak](#)
- [Nyelv](#)
- [Standard könyvtár](#)
- [Eszközök](#)

## Kompatibilitási útmutató Kotlin 1.8-hoz
- [Alapfogalmak](#)
- [Nyelv](#)
- [Standard könyvtár](#)
- [Eszközök](#)

## Kompatibilitási útmutató Kotlin 1.7.20-hoz
- [Alapfogalmak](#)
- [Nyelv](#)

## Kompatibilitási útmutató Kotlin 1.7-hez
- [Alapfogalmak](#)
- [Nyelv](#)
- [Standard könyvtár](#)
- [Eszközök](#)

## Kompatibilitási útmutató Kotlin 1.6-hoz
- [Alapfogalmak](#)
- [Nyelv](#)
- [Standard könyvtár](#)
- [Eszközök](#)

## Kompatibilitási útmutató Kotlin 1.5-höz
- [Alapfogalmak](#)
- [Nyelv és stdlib](#)
- [Eszközök](#)

## Kompatibilitási útmutató Kotlin 1.4-hez
- [Alapfogalmak](#)
- [Nyelv és stdlib](#)
- [Eszközök](#)

## Kompatibilitási útmutató Kotlin 1.3-hoz
- [Alapfogalmak](#)
- [Inkompatibilis változások](#)
- [Kompatibilitási módok](#)

## Google Summer of Code Kotlin-nal
- [GSoC 2025: projektötletek](#)
- [Korábbi GSoC projektek Kotlin-nal](#)
- [Google Summer of Code Kotlin-nal 2025](#)
- [Kotlin közreműködői irányelvek Google Summer of Code (GSoC) programhoz](#)
- [Projektötletek](#)
- [Google Summer of Code Kotlin-nal 2024](#)
- [Kotlin közreműködői irányelvek Google Summer of Code (GSoC) programhoz](#)
- [Projektötletek](#)
- [Google Summer of Code Kotlin-nal 2023](#)
- [Projektötletek](#)

## Biztonság
## Kotlin dokumentáció PDF formátumban

## Közreműködés
- [Részvétel az Early Access Preview programban](#)
- [Közreműködés a fordítóban és standard könyvtárban](#)
- [Közreműködés a Kotlin IDE pluginban](#)
- [Közreműködés más Kotlin könyvtárakban és eszközökben](#)
- [Közreműködés a dokumentációban](#)
- [Dokumentáció fordítása más nyelvekre](#)
- [Események és prezentációk tartása](#)

## KUG irányelvek
- [Hogyan működtess egy KUG-ot?](#)
- [KUG-ok támogatása JetBrains által](#)
- [JetBrains támogatás egyéb technológiai közösségeknek](#)

## Kotlin Night irányelvek
- [Eseményirányelvek](#)
- [Eseménykövetelmények](#)
- [JetBrains támogatás](#)

## Magatartási kódex és irányelvek a Kotlin Slack csatornához
- [Hogyan viselkedj](#)
- [Hogyan ne viselkedj](#)
- [Problémák bejelentése](#)
- [Alapvető használati irányelvek](#)
- [Moderátorok](#)

## Szerzői jog
## Kotlin márkajellemzők
- [Kotlin logó](#)
- [Kotlin mascut](#)
- [Kotlin User Group márkajellemzők](#)

# Kotlin dokumentáció

## Első lépések a Kotlinnal

A Kotlin egy modern, de már érett programozási nyelv, amelyet úgy terveztek, hogy a fejlesztők számára kellemesebb legyen a használata. Tömör, biztonságos, interoperabilis a Java és más nyelvek számára, és számos lehetőséget kínál a kód újrafelhasználására több platform között a produktív programozás érdekében.

A kezdéshez indítsd el a Kotlin bemutatóját! Ez a túra a Kotlin programozási nyelv alapjait tárgyalja, és teljes egészében a böngésződben végezhető el.

### [Indítsd el a Kotlin túrát](#)

## Kotlin telepítése

A Kotlin minden IntelliJ IDEA és Android Studio kiadásban benne van. Töltsd le és telepítsd az egyiket ezek közül a Kotlin használatának megkezdéséhez.

## Válaszd ki a Kotlin használati eseted

### Konzol

Itt megtanulod, hogyan fejlessz konzolalkalmazást és hogyan hozz létre egységteszteket Kotlinban.

1. Hozz létre egy alapszintű JVM alkalmazást az IntelliJ IDEA projektvarázslójával.  
2. Írd meg az első egységtesztedet.

### Backend

Itt megtanulod, hogyan fejlessz backend alkalmazást Kotlin szerveroldalon.

1. Hozd létre az első backend alkalmazásodat:  
   - Hozz létre egy RESTful webszolgáltatást Spring Boot-tal  
   - Hozz létre HTTP API-kat Ktor-al  

2. Tanuld meg, hogyan keveredhet a Kotlin és Java kód az alkalmazásodban.

### Cross-platform

Itt megtanulod, hogyan fejlessz cross-platform alkalmazást Kotlin Multiplatform használatával.

1. Állítsd be a környezetedet cross-platform fejlesztéshez.  
2. Hozd létre az első alkalmazásodat iOS-re és Androidra:  
   - Hozz létre egy cross-platform alkalmazást nulláról és:  
     - Oszd meg a üzleti logikát, miközben a felhasználói felület maradjon natív  
     - Oszd meg a üzleti logikát és a felhasználói felületet is  
     - Tedd működőképessé a meglévő Android alkalmazásodat iOS-en  
   - Hozz létre cross-platform alkalmazást Ktor és SQLdelight használatával  
3. Fedezz fel példaprojekteket.

### Android

A Kotlin Android fejlesztéshez való használatához olvasd el a [Google ajánlását a Kotlin Androiden való használatához](#).

### Adatfeldolgozás

Adatfolyamatok építésétől a gépi tanulási modellek produktivizálásáig a Kotlin kiváló választás az adatokkal való munkához és azok teljes kihasználásához.

1. Hozz létre és szerkessz notebookokat zökkenőmentesen az IDE-n belül:  
   - Első lépések Kotlin Notebookkal

2. Fedezd fel és kísérletezz az adataiddal:  
   - [DataFrame](#) – egy könyvtár az adatelemzéshez és -manipulációhoz.  
   - [Kandy](#) – egy rajzolóeszköz az adatvizualizációhoz.

3. Kövesd a [Kotlin for Data Analysis](https://twitter.com/KotlinForData) oldalt Twitteren.

## Csatlakozz a Kotlin közösséghez

Maradj naprakész a Kotlin ökoszisztéma legújabb frissítéseivel és oszd meg a tapasztalataidat.

Csatlakozz hozzánk itt:

- [Slack: kérj meghívót](#)
- [StackOverflow: iratkozz fel a "kotlin" címkére](#)
- Kövess minket a [YouTube](#), [Twitter](#), [Bluesky](#) és [Reddit](#) oldalainkon.
- [Iratkozz fel a Kotlin híreire](#)

Ha bármilyen nehézségbe ütköztél vagy problémád van, jelentsd be a [hibabejelentő rendszerünkben](#).

## Hiányzik valami?

Ha bármi hiányzik vagy zavaros ezen az oldalon, kérjük, ossz meg velünk visszajelzést.

---

## Üdvözöljük Kotlin ismerkedő túránkon!

Ezek a túrák teljes egészében böngészőben végezhetők el. Nincs szükség telepítésre.

Gyorsan tanuld meg a Kotlin programozási nyelv alapjait a túráinkon keresztül, amelyek elvezetnek a kezdőtől az középhaladó szintig.

Minden fejezet tartalmazza:

- Elméletet, amely bemutatja a nyelv kulcsfogalmait példákkal.
- Gyakorlatokat a megtanultak elsajátításának ellenőrzésére.
- Megoldásokat a hivatkozáshoz.

Kezdd az alapokkal: [Indítsd el a Kotlin alapozó túrát](#)

### Alapozó túra tartalma:
- Változók (`Variables`)
- Alap típusok (`Basic types`)
- Kollekciók (`Collections`)
- Vezérlési szerkezetek (`Control flow`)
- Függvények (`Functions`)
- Osztályok (`Classes`)
- Null biztonság (`Null safety`)

Ha készen állsz a Kotlin ismereteid következő szintre emelésére, vedd az [intermedier Kotlin túrát](#)

### Középhaladó túra tartalma:
- Extension függvények (`Extension functions`)
- Scope függvények (`Scope functions`)
- Lambda kifejezések fogadóval (`Lambda expressions with receiver`)
- Osztályok és interfészek (`Classes and interfaces`)
- Objektumok (`Objects`)
- Nyílt és speciális osztályok (`Open and special classes`)
- Tulajdonságok (`Properties`)
- Null biztonság (`Null safety`)
- Könyvtárak és API-k (`Libraries and APIs`)

## Hello world

Itt egy egyszerű program, amely kiírja a "Hello, world!" szöveget:

```
fun main() {
    println("Hello, world!") // Hello, world!
}
```

A Kotlin nyelvben:

- A `fun` kulcsszóval deklarálunk egy függvényt
- A `main()` függvény az a pont, ahol a programod elindul
- A függvény törzse kapcsos zárójelek `{}` közé írandó
- A `println()` és `print()` függvények kiírják paramétereiket a standard kimenetre

Egy függvény olyan utasítások halmaza, amely egy adott feladatot hajt végre. Miután létrehoztál egy függvényt, bárhányszor felhasználhatod, ha szükséged van az adott feladat elvégzésére, anélkül hogy újra meg kéne írnod az utasításokat. A függvényekről részletesebben későbbi fejezetekben lesz szó. Addig is minden példa a `main()` függvényt fogja használni.

## Változók

Minden programnak szüksége van adatok tárolására, és a változók ebben segítenek. Kotlin-ban a következőket deklarálhatod:

- Csak olvasható változókat `val` kulcsszóval
- Módosítható változókat `var` kulcsszóval

Egy csak olvasható változó értékét nem lehet megváltoztatni, miután értéket adtál neki. Értékadáshoz használd a `=` operátort. Például:

```
fun main() {
    val popcorn = 5     // There are 5 boxes of popcorn || 5 doboz pattogott kukorica van
    val hotdog = 7      // There are 7 hotdogs || 7 hotdog van
    var customers = 10  // There are 10 customers in the queue || 10 vásárló van a sorban

    // Some customers leave the queue || Néhány vásárló elhagyja a sort
    customers = 8

    println(customers)  // 8
}
```
## Változók

A változókat deklarálhatod a `main()` függvényen kívül is, a program elején. Az ilyen módon deklarált változókat legfelső szintű (top level) változóknak nevezzük. Mivel a `customers` egy módosítható változó, értéke újra hozzárendelhető a deklaráció után. Az összes változót csak olvashatóként (`val`) javasolt alapértelmezetten deklarálni. Csak akkor használj módosítható változókat (`var`), ha tényleg szükséged van rá. Így kevesebb eséllyel változtatsz meg véletlenül valamit, amit nem akartál megváltoztatni.

## String sablonok

Hasznos tudni, hogyan lehet kiírni a változók tartalmát a standard kimenetre. Ezt string sablonokkal teheted meg. A sablonkifejezések segítségével hozzáférhetsz a változókban és más objektumokban tárolt adatokhoz, és karakterlánccá alakíthatod őket. Egy string érték dupla idézőjelek közé írt karakterek sorozata `"` . A sablonkifejezések mindig dollárjellel `$` kezdődnek. Egy kódrészlet kiértékeléséhez a sablonkifejezésben, helyezd a kódot kapcsos zárójelek `{}` közé a dollárjel után `$`.

Például:

```
fun main() {
    val customers = 10
    println("There are $customers customers")        // There are 10 customers || 10 vásárló van
    println("There are ${customers + 1} customers")// There are 11 customers||11 vásárló van
}
```

További információért lásd: String sablonok.

Észreveheted, hogy a változókhoz nem lett típus deklarálva. A Kotlin magától kikövetkeztette a típust: `Int`. Ez a túra a különböző Kotlin alaptípusokat és azok deklarálását mutatja be a következő fejezetben.

## Gyakorlás

### Feladat
Egészítsd ki a kódot úgy, hogy a program a "Mary is 20 years old" szöveget írja ki a standard kimenetre:

```
fun main() {
    val name = "Mary"
    val age = 20
    // Write your code here || Írd ide a kódodat
}
```

### Megoldás
```
fun main() {
    val name = "Mary"
    val age = 20
    println("$name is $age years old") // Mary is 20 years old || Mary 20 éves
}
```

## Következő lépés

## Alaptípusok

A Kotlin minden változója és adatstruktúrája rendelkezik típussal. A típusok fontosak, mert megmondják a fordítónak, hogy mit tehetsz az adott változóval vagy adatstruktúrával. Más szóval, milyen függvényei és tulajdonságai vannak.

Az előző fejezetben a Kotlin ki tudta következtetni, hogy a `customers` típusa `Int`. A Kotlin típuskikövetkeztetési képességét típuskikövetkeztetésnek (type inference) nevezzük. A `customers` változóhoz egész értéket rendeltek. Ebből a Kotlin arra következtet, hogy a `customers` numerikus típusú `Int`. Ennek eredményeként a fordító tudja, hogy aritmetikai műveleteket hajthatsz végre a `customers` változón:

```
fun main() {
    var customers = 10 // Some customers leave the queue || Néhány vásárló elhagyja a sort
    customers = 8
    customers = customers + 3  // Example of addition: 11 || Példa összeadásra: 11
    customers += 7             // Example of addition: 18 || Példa összeadásra: 18
    customers -= 3             // Example of subtraction: 15 || Példa kivonásra: 15
    customers *= 2             // Example of multiplication: 30 || Példa szorzásra: 30
    customers /= 3             // Example of division: 10 || Példa osztásra: 10
    println(customers)         // 10
}
```

A `+=`, `-=`, `*=`, `/=`, és `%= ` operátorok kibővített értékadó operátorok. További információért lásd: Kibővített értékadások.

Összesen a Kotlin az alábbi alaptípusokkal rendelkezik:

| Kategória              | Alaptípusok                | Példakód                                                     |
| ---------------------- | -------------------------- | ------------------------------------------------------------ |
| Egészek                | Byte, Short, Int, Long     | `val year: Int = 2020`                                       |
| Előjel nélküli egészek | UByte, UShort, UInt, ULong | `val score: UInt = 100u`                                     |
| Lebegőpontos számok    | Float, Double              | `val currentTemp: Float = 24.5f`, `val price: Double = 19.99` |
| Logikai értékek        | Boolean                    | `val isEnabled: Boolean = true`                              |
| Karakterek             | Char                       | `val separator: Char = ','`                                  |
| Sztringek              | String                     | `val message: String = "Hello, world!"`                      |

További információ az alaptípusokról és tulajdonságaikról: Alaptípusok.

Ezzel a tudással deklarálhatsz változókat, és később inicializálhatod őket. A Kotlin ezt képes kezelni, amennyiben a változók inicializálva vannak az első olvasás előtt. Egy változó deklarálásához inicializálás nélkül, add meg a típusát `:` segítségével. Például:

```
fun main() {
    // Variable declared without initialization || Változó deklarálva inicializálás nélkül
    val d: Int
    // Variable initialized || Változó inicializálva
    d = 3
    // Variable explicitly typed and initialized || Változó explicit típusozva és inicializálva
    val e: String = "hello"
    // Variables can be read because they have been initialized || A változókat olvashatók, mert inicializálva lettek
    println(d)  // 3
    println(e)  // hello
}
```

Ha nem inicializálsz egy változót az olvasás előtt, hibát kapsz:

```
fun main() {
    // Variable declared without initialization || Változó deklarálva inicializálás nélkül
    val d: Int
    // Triggers an error || Hibát okoz
    println(d)  // Variable 'd' must be initialized || A 'd' változót inicializálni kell
}
```

Most, hogy tudod, hogyan kell deklarálni az alaptípusokat, itt az ideje megtanulni a kollekciókat.

## Gyakorlás

### Feladat
Explicit módon deklaráld az egyes változók helyes típusát:

```
fun main() {
    val a = 1000
    val b = "log message"
    val c = 3.14
    val d = 100_000_000_000_000
    val e = false
    val f = '\n'
}
```

### Megoldás
```
fun main() {
    val a: Int = 1000
    val b: String = "log message"
    val c: Double = 3.14
    val d: Long = 100_000_000_000_000
    val e: Boolean = false
    val f: Char = '\n'
}
```
## Következő lépés

## Kollekciók

A programozás során hasznos lehet az adatokat struktúrákba csoportosítani a későbbi feldolgozás érdekében. A Kotlin pontosan erre a célra biztosít kollekciókat.

A Kotlin a következő kollekciókat biztosítja az elemek csoportosításához:

| Kollekció típusa | Leírás |
|------------------|--------|
| Listák (Lists) | Az elemek rendezett gyűjteményei |
| Halmazok (Sets) | Az elemek egyedi, rendezetlen gyűjteményei |
| Térképek (Maps) | Kulcs-érték párok gyűjteményei, ahol a kulcsok egyediek és minden kulcs csak egy értékhez tartozik |

Minden kollekciótípus lehet módosítható vagy csak olvasható.

## Lista

A listák az elemeket a hozzáadás sorrendjében tárolják, és lehetővé teszik az ismétlődő elemeket.

- Egy csak olvasható lista (`List`) létrehozásához használd a `listOf()` függvényt.
- Egy módosítható lista (`MutableList`) létrehozásához használd a `mutableListOf()` függvényt.

A listák létrehozásakor a Kotlin ki tudja következtetni a tárolt elemek típusát. Az típus explicit deklarálásához add meg a típust szögletes zárójelek `<>` között a lista deklaráció után:

```
fun main() {
    // Read only list || Csak olvasható lista
    val readOnlyShapes = listOf("triangle", "square", "circle")
    println(readOnlyShapes) // [triangle, square, circle]
    
    // Mutable list with explicit type declaration || Módosítható lista explicit típusdeklarációval
    val shapes: MutableList<String> = mutableListOf("triangle", "square", "circle")
    println(shapes) // [triangle, square, circle]
}
```

A nem kívánt módosítások megelőzése érdekében létrehozhatsz egy csak olvasható nézetet egy módosítható listáról, ha hozzárendeled egy `List` típusú változóhoz:

```
val shapes: MutableList<String> = mutableListOf("triangle", "square", "circle")
val shapesLocked: List<String> = shapes
```

Ezt másnéven típuskényszerítésnek (casting) is nevezik.

A listák rendezettek, így egy elem eléréséhez használd az indexelt hozzáférés operátort `[]`:

```
fun main() {
    val readOnlyShapes = listOf("triangle", "square", "circle")
    println("The first item in the list is: ${readOnlyShapes[0]}") 
    // The first item in the list is: triangle || Az első elem a listában: triangle
}
```

A lista első vagy utolsó elemének lekéréséhez használd rendre a `.first()` és `.last()` függvényeket:

```
fun main() {
    val readOnlyShapes = listOf("triangle", "square", "circle")
    println("The first item in the list is: ${readOnlyShapes.first()}") 
    // The first item in the list is: triangle || Az első elem a listában: triangle
}
```

A `.first()` és `.last()` függvények példák kiterjesztési függvényekre (extension functions). Egy kiterjesztési függvény objektumon való meghívásához írd a függvény nevét az objektum után, egy ponttal `.` elválasztva. A kiterjesztési függvényekről részletesebben a középhaladó túrában lesz szó. Egyelőre csak azt kell tudnod, hogyan kell őket meghívni.

A listában lévő elemek számának lekéréséhez használd a `.count()` függvényt:

```
fun main() {
    val readOnlyShapes = listOf("triangle", "square", "circle")
    println("This list has ${readOnlyShapes.count()} items") 
    // This list has 3 items || Ennek a listának 3 eleme van
}
```

Annak ellenőrzéséhez, hogy egy elem szerepel-e a listában, használd az `in` operátort:

```
fun main() {
    val readOnlyShapes = listOf("triangle", "square", "circle")
    println("circle" in readOnlyShapes) // true
}
```

Elemek hozzáadásához vagy eltávolításához egy módosítható listából használd rendre az `.add()` és `.remove()` függvényeket:

```
fun main() {
    val shapes: MutableList<String> = mutableListOf("triangle", "square", "circle")
    // Add "pentagon" to the list || "pentagon" hozzáadása a listához
    shapes.add("pentagon")
    println(shapes) // [triangle, square, circle, pentagon]
    
    // Remove the first "pentagon" from the list || Az első "pentagon" eltávolítása a listából
    shapes.remove("pentagon")
    println(shapes) // [triangle, square, circle]
}
```

## Halmaz

Míg a listák rendezettek és ismétlődő elemeket is tárolhatnak, addig a halmazok rendezetlenek és csak egyedi elemeket tárolnak.

- Egy csak olvasható halmaz (`Set`) létrehozásához használd a `setOf()` függvényt.
- Egy módosítható halmaz (`MutableSet`) létrehozásához használd a `mutableSetOf()` függvényt.

A halmazok létrehozásakor a Kotlin ki tudja következtetni a tárolt elemek típusát. Az típus explicit deklarálásához add meg a típust szögletes zárójelek `<>` között a halmaz deklaráció után:

```
fun main() {
    // Read-only set || Csak olvasható halmaz
    val readOnlyFruit = setOf("apple", "banana", "cherry", "cherry")
    // Mutable set with explicit type declaration || Módosítható halmaz explicit típusdeklarációval
    val fruit: MutableSet<String> = mutableSetOf("apple", "banana", "cherry", "cherry")
    println(readOnlyFruit) // [apple, banana, cherry]
}
```

Az előző példából látható, hogy mivel a halmazok csak egyedi elemeket tartalmaznak, a második "cherry" elem eldobásra kerül.

A nem kívánt módosítások megelőzése érdekében létrehozhatsz egy csak olvasható nézetet egy módosítható halmazról, ha hozzárendeled egy `Set` típusú változóhoz:

```
val fruit: MutableSet<String> = mutableSetOf("apple", "banana", "cherry", "cherry")
val fruitLocked: Set<String> = fruit
```

Mivel a halmazok rendezetlenek, nem férhetsz hozzá egy adott indexen lévő elemhez. A halmazban lévő elemek számának lekéréséhez használd a `.count()` függvényt:

```
fun main() {
    val readOnlyFruit = setOf("apple", "banana", "cherry", "cherry")
    println("This set has ${readOnlyFruit.count()} items") 
    // This set has 3 items || Ennek a halmaznak 3 eleme van
}
```

Annak ellenőrzéséhez, hogy egy elem szerepel-e a halmazban, használd az `in` operátort:

```
fun main() {
    val readOnlyFruit = setOf("apple", "banana", "cherry", "cherry")
    println("banana" in readOnlyFruit) // true
}
```

Elemek hozzáadásához vagy eltávolításához egy módosítható halmazból használd rendre az `.add()` és `.remove()` függvényeket:

```
fun main() {
    val fruit: MutableSet<String> = mutableSetOf("apple", "banana", "cherry", "cherry")
    fruit.add("dragonfruit")  // Add "dragonfruit" to the set || "dragonfruit" hozzáadása a halmazhoz
    println(fruit) // [apple, banana, cherry, dragonfruit]
    
    fruit.remove("dragonfruit")  // Remove "dragonfruit" from the set || "dragonfruit" eltávolítása a halmazból
    println(fruit) // [apple, banana, cherry]
}
```
## Térkép

A térképek (maps) az elemeket kulcs-érték párokban tárolják. Az értéket a kulcs hivatkozásával érheted el. Elképzelhetsz egy térképet úgy, mint egy étlapot. Megtalálhatod az árat (érték), ha megtalálod azt az ételt (kulcs), amit enni szeretnél. A térképek hasznosak, ha indexelés nélkül szeretnél megkeresni egy értéket, mint a listák esetében. Minden kulcsnak egyedinek kell lennie egy térképen belül, hogy a Kotlin tudja, melyik értéket szeretnéd lekérni. Egy térkép azonban tartalmazhat több azonos értéket. 

- Egy csak olvasható térkép (`Map`) létrehozásához használd a `mapOf()` függvényt.
- Egy módosítható térkép (`MutableMap`) létrehozásához használd a `mutableMapOf()` függvényt.

A térképek létrehozásakor a Kotlin ki tudja következtetni a tárolt elemek típusát. Az típus explicit deklarálásához add meg a kulcsok és értékek típusát szögletes zárójelek `<>` között a térkép deklaráció után. Például: `MutableMap<String, Int>`. A kulcsok típusa `String`, az értékek típusa `Int`. A legegyszerűbb módja a térképek létrehozásának a `to` használata minden kulcs és a hozzá tartozó érték között:

```
fun main() {
    // Read-only map || Csak olvasható térkép
    val readOnlyJuiceMenu = mapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
    println(readOnlyJuiceMenu) // {apple=100, kiwi=190, orange=100}
    
    // Mutable map with explicit type declaration || Módosítható térkép explicit típusdeklarációval
    val juiceMenu: MutableMap<String, Int> = mutableMapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
    println(juiceMenu) // {apple=100, kiwi=190, orange=100}
}
```

A nem kívánt módosítások megelőzése érdekében létrehozhatsz egy csak olvasható nézetet egy módosítható térképről, ha hozzárendeled egy `Map` típusú változóhoz:

```
val juiceMenu: MutableMap<String, Int> = mutableMapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
val juiceMenuLocked: Map<String, Int> = juiceMenu
```

Egy térkép értékének eléréséhez használd az indexelt hozzáférés operátort `[]` a kulcsával:

```
fun main() {
    // Read-only map || Csak olvasható térkép
    val readOnlyJuiceMenu = mapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
    println("The value of apple juice is: ${readOnlyJuiceMenu["apple"]}") 
    // The value of apple juice is: 100 || Az almalevet értéke: 100
}
```

Ha olyan kulcs-érték párt próbálsz elérni, amely nem létezik a térképben, `null` értéket kapsz:

```
fun main() {
    // Read-only map || Csak olvasható térkép
    val readOnlyJuiceMenu = mapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
    println("The value of pineapple juice is: ${readOnlyJuiceMenu["pineapple"]}") 
    // The value of pineapple juice is: null || Az ananászlevet értéke: null
}
```

Ez a túra később elmagyarázza a `null` értékeket a Null biztonság fejezetben.

Az indexelt hozzáférés operátor `[]` használható elemek hozzáadására is egy módosítható térképhez:

```
fun main() {
    val juiceMenu: MutableMap<String, Int> = mutableMapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
    juiceMenu["coconut"] = 150  // Add key "coconut" with value 150 to the map || "coconut" kulcs hozzáadása 150 értékkel a térképhez
    println(juiceMenu) // {apple=100, kiwi=190, orange=100, coconut=150}
}
```

Elemek eltávolításához egy módosítható térképből használd a `.remove()` függvényt:

```
fun main() {
    val juiceMenu: MutableMap<String, Int> = mutableMapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
    juiceMenu.remove("orange")  // Remove key "orange" from the map || "orange" kulcs eltávolítása a térképből
    println(juiceMenu) // {apple=100, kiwi=190}
}
```

A térképben lévő elemek számának lekéréséhez használd a `.count()` függvényt:

```
fun main() {
    // Read-only map || Csak olvasható térkép
    val readOnlyJuiceMenu = mapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
    println("This map has ${readOnlyJuiceMenu.count()} key-value pairs") 
    // This map has 3 key-value pairs || Ennek a térképnek 3 kulcs-érték párja van
}
```

Annak ellenőrzéséhez, hogy egy adott kulcs szerepel-e már a térképben, használd a `.containsKey()` függvényt:

```
fun main() {
    val readOnlyJuiceMenu = mapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
    println(readOnlyJuiceMenu.containsKey("kiwi")) // true
}
```

Egy térkép kulcsainak vagy értékeinek gyűjteményének lekéréséhez használd rendre a `keys` és `values` tulajdonságokat:

```
fun main() {
    val readOnlyJuiceMenu = mapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
    println(readOnlyJuiceMenu.keys)   // [apple, kiwi, orange]
    println(readOnlyJuiceMenu.values) // [100, 190, 100]
}
```

A `keys` és `values` példák egy objektum tulajdonságaira. Egy objektum tulajdonságának eléréséhez írd a tulajdonság nevét az objektum után egy ponttal `.` elválasztva. A tulajdonságokról részletesebben az Osztályok fejezetben lesz szó. Ezen a ponton csak azt kell tudnod, hogyan kell elérni őket.

Annak ellenőrzéséhez, hogy egy kulcs vagy érték szerepel-e egy térképben, használd az `in` operátort:

```
fun main() {
    val readOnlyJuiceMenu = mapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
    println("orange" in readOnlyJuiceMenu.keys) // true
    // Alternatively, you don't need to use the keys property || Alternatívaként, nem kell használni a keys tulajdonságot
    println("orange" in readOnlyJuiceMenu)      // true
    println(200 in readOnlyJuiceMenu.values)     // false
}
```

További információért arról, mit tehetsz a kollekciókkal: Kollekciók.

Most, hogy tudod az alaptípusokat és hogyan kezelheted a kollekciókat, itt az ideje felfedezni a vezérlési szerkezeteket, amelyeket a programjaidban használhatsz.

## Gyakorlás

### Feladat 1
Van egy "zöld" számok listád és egy "piros" számok listád. Egészítsd ki a kódot, hogy kiírja, összesen hány szám van.

```
fun main() {
    val greenNumbers = listOf(1, 4, 23)
    val redNumbers = listOf(17, 2)
    // Write your code here || Írd ide a kódodat
}
```

### Megoldás
```
fun main() {
    val greenNumbers = listOf(1, 4, 23)
    val redNumbers = listOf(17, 2)
    val totalCount = greenNumbers.count() + redNumbers.count()
    println(totalCount) // 5
}
```

### Feladat 2
Van egy halmazod a szervered által támogatott protokollokról. Egy felhasználó kér egy adott protokollt. Egészítsd ki a programot, hogy ellenőrizd, a kért protokoll támogatott-e vagy sem (`isSupported` egy logikai érték kell legyen).

```
fun main() {
    val SUPPORTED = setOf("HTTP", "HTTPS", "FTP")
    val requested = "smtp"
    val isSupported = // Write your code here || Írd ide a kódodat
    println("Support for $requested: $isSupported") 
    // Support for smtp: false || Támogatás smtp esetén: false
}
```

**Tipp:** Győződj meg róla, hogy a kért protokollt nagybetűkkel ellenőrzöd. Használhatod az `.uppercase()` függvényt segítségül.

### Megoldás
```
fun main() {
    val SUPPORTED = setOf("HTTP", "HTTPS", "FTP")
    val requested = "smtp"
    val isSupported = requested.uppercase() in SUPPORTED
    println("Support for $requested: $isSupported") 
    // Support for smtp: false || Támogatás smtp esetén: false
}
```

### Feladat 3
Definiálj egy térképet, amely összekapcsolja az 1-től 3-ig terjedő egész számokat a megfelelő szóbeli alakjukkal. Használd ezt a térképet a megadott szám kiejtéséhez.

```
fun main() {
    val number2word = // Write your code here || Írd ide a kódodat
    val n = 2
    println("$n is spelt as '${/* Write your code here */}'") 
    // 2 is spelt as 'two' || 2 kiejtve mint 'kettő'
}
```

### Megoldás
```
fun main() {
    val number2word = mapOf(1 to "one", 2 to "two", 3 to "three")
    val n = 2
    println("$n is spelt as '${number2word[n]}'") 
    // 2 is spelt as 'two' || 2 kiejtve mint 'kettő'
}
```

## Következő lépés

## Vezérlési szerkezetek

### Vezérlési szerkezetek

Más programozási nyelvekhez hasonlóan a Kotlin is képes döntéseket hozni attól függően, hogy egy kódrészlet kiértékelése igaz-e. Az ilyen kódrészleteket feltételes kifejezéseknek nevezzük. A Kotlin képes ciklusokat is létrehozni és végigiterálni rajtuk.

### Feltételes kifejezések

A Kotlin az `if` és `when` utasításokat biztosítja a feltételes kifejezések ellenőrzésére. Ha választani kell az `if` és `when` között, javasoljuk a `when` használatát, mert:
- Kódod könnyebben olvashatóvá válik.
- Könnyebb egy másik ág hozzáadása.
- Kevesebb hibához vezet.

### If

Az `if` használatához add meg a feltételes kifejezést zárójelek `()` között, és a végrehajtandó műveletet kapcsos zárójelek `{}` között, ha az eredmény igaz:

```
fun main() {
    val d: Int
    val check = true
    if (check) {
        d = 1
    } else {
        d = 2
    }
    println(d) // 1
}
```

Nincs ternáris operátor (`condition ? then : else`) Kotlinban. Helyette az `if` kifejezésként használható. Ha minden ágban csak egy sornyi kód van, a kapcsos zárójelek `{}` opcionálisak:

```
fun main() {
    val a = 1
    val b = 2
    println(if (a > b) a else b) // Returns a value: 2 || Egy értéket ad vissza: 2
}
```
### When

Használd a `when` utasítást, amikor több ágú feltételes kifejezésed van. A `when` használatához:

- Tedd a kiértékelendő értéket zárójelek `()` közé.
- Helyezd el az ágakat kapcsos zárójelek `{}` közé.
- Használd a `->` jelet minden ágban a feltétel és a végrehajtandó művelet elválasztásához.

A `when` utasításként vagy kifejezésként is használható.

Egy utasítás nem ad vissza értéket, hanem műveleteket hajt végre. Itt egy példa a `when` utasításként való használatára:

```
fun main() {
    val obj = "Hello"
    when (obj) {
        // Checks whether obj equals to "1" || Ellenőrzi, hogy obj egyenlő-e "1"-gyel
        "1" -> println("One")
        // Checks whether obj equals to "Hello" || Ellenőrzi, hogy obj egyenlő-e "Hello"-val
        "Hello" -> println("Greeting")
        // Default statement || Alapértelmezett utasítás
        else -> println("Unknown")
    }
    // Greeting
}
```

Vegye figyelembe, hogy az összes ág feltétele sorban kerül ellenőrzésre, amíg egyikük sem teljesül. Ezért csak az első megfelelő ág hajtódik végre.

Egy kifejezés visszaad egy értéket, amelyet később felhasználhatsz a kódodban. Itt egy példa a `when` kifejezésként való használatára. A `when` kifejezés azonnal hozzárendelődik egy változóhoz, amelyet később használ a `println()` függvény:

```
fun main() {
    val obj = "Hello"
    val result = when (obj) {
        // If obj equals "1", sets result to "one" || Ha obj egyenlő "1"-gyel, result értéke "One"
        "1" -> "One"
        // If obj equals "Hello", sets result to "Greeting" || Ha obj egyenlő "Hello"-val, result értéke "Greeting"
        "Hello" -> "Greeting"
        // Sets result to "Unknown" if no previous condition is satisfied || Result értéke "Unknown", ha egyik előző feltétel sem teljesül
        else -> "Unknown"
    }
    println(result) // Greeting
}
```

Az eddigi `when` példák mindegyikének volt témája: `obj`. De a `when` használható témátlanul is. Ez a példa egy témátlan `when` kifejezést használ egy láncolatú logikai kifejezések ellenőrzésére:

```
fun main() {
    val trafficLightState = "Red" // This can be "Green", "Yellow", or "Red" || Ez lehet "Green", "Yellow", vagy "Red"
    val trafficAction = when {
        trafficLightState == "Green" -> "Go"
        trafficLightState == "Yellow" -> "Slow down"
        trafficLightState == "Red" -> "Stop"
        else -> "Malfunction"
    }
    println(trafficAction) // Stop
}
```

Azonban ugyanez a kód így is lehetne megírni, a `trafficLightState` használatával témaként:

```
fun main() {
    val trafficLightState = "Red" // This can be "Green", "Yellow", or "Red" || Ez lehet "Green", "Yellow", vagy "Red"
    val trafficAction = when (trafficLightState) {
        "Green" -> "Go"
        "Yellow" -> "Slow down"
        "Red" -> "Stop"
        else -> "Malfunction"
    }
    println(trafficAction) // Stop
}
```

A `when` használata témával könnyebbé teszi a kód olvasását és karbantartását. Ha témát használsz egy `when` kifejezéssel, segít a Kotlinnek ellenőrizni, hogy minden lehetséges eset le van-e fedve. Ellenkező esetben, ha nem használsz témát egy `when` kifejezéssel, meg kell adnod egy `else` ágat.

## Feltételes kifejezések gyakorlása

### Feladat 1

Hozz létre egy egyszerű játékot, ahol nyersz, ha két kockával dobva ugyanazt a számot kapod. Használd az `if` utasítást arra, hogy "You win :)" kerüljön ki, ha a kockák egyeznek, különben "You lose :(".

Ebben a feladatban importálsz egy csomagot, hogy használhasd a `Random.nextInt()` függvényt, amely egy véletlenszerű `Int` értéket ad.

**Tipp:** Használd az egyenlőség operátort (`==`) a kockadobások összehasonlításához.

```
import kotlin.random.Random

fun main() {
    val firstResult = Random.nextInt(6)
    val secondResult = Random.nextInt(6)
    // Write your code here || Írd ide a kódodat
}
```

### Megoldás
```
import kotlin.random.Random

fun main() {
    val firstResult = Random.nextInt(6)
    val secondResult = Random.nextInt(6)
    if (firstResult == secondResult)
        println("You win :)")
    else
        println("You lose :(")
}
```

### Feladat 2

Egy `when` kifejezés használatával frissítsd a következő programot úgy, hogy kiírja a megfelelő műveleteket, amikor a játékkonzol gombjainak neveit adod meg.

| Gomb  | Művelet                 |
| ----- | ----------------------- |
| A     | Yes                     |
| B     | No                      |
| X     | Menu                    |
| Y     | Nothing                 |
| Egyéb | There is no such button |

```
fun main() {
    val button = "A"
    println( // Write your code here || Írd ide a kódodat )
}
```

### Megoldás
```
fun main() {
    val button = "A"
    println(
        when (button) {
            "A" -> "Yes"
            "B" -> "No"
            "X" -> "Menu"
            "Y" -> "Nothing"
            else -> "There is no such button"
        }
    )
}
```

## Tartományok

Mielőtt a ciklusokról beszélnénk, hasznos tudni, hogyan kell tartományokat létrehozni, amelyeken a ciklusok végigiterálhatnak.

A Kotlinban a tartományok létrehozásának leggyakoribb módja a `..` operátor használata. Például `1..4` megegyezik a `1, 2, 3, 4` értékekkel.

Egy olyan tartomány deklarálásához, amely nem tartalmazza a végértéket, használd a `..<` operátort. Például `1..<4` megegyezik a `1, 2, 3` értékekkel.

Egy visszafelé haladó tartomány deklarálásához használd a `downTo` kulcsszót. Például `4 downTo 1` megegyezik a `4, 3, 2, 1` értékekkel.

Egy olyan tartomány deklarálásához, amely nem 1-es lépésközzel növekszik, használd a `step` kulcsszót és a kívánt növekmény értékét. Például `1..5 step 2` megegyezik a `1, 3, 5` értékekkel.

Ugyanez elvégezhető `Char` tartományokkal is:
- `'a'..'d'` megegyezik `'a', 'b', 'c', 'd'` értékekkel
- `'z' downTo 's' step 2` megegyezik `'z', 'x', 'v', 't'` értékekkel

## Ciklusok

A programozásban a két leggyakoribb ciklusszerkezet a `for` és `while`.

Használd a `for` ciklust egy értéktartományon való végigiteráláshoz és egy művelet végrehajtásához.

Használd a `while` ciklust egy művelet folytatásához, amíg egy adott feltétel nem teljesül.

### For

Az új tartománytudásod segítségével létrehozhatsz egy `for` ciklust, amely végigiterál a `1`-től `5`-ig terjedő számokon, és minden alkalommal kiírja a számot.

Helyezd az iterátort és a tartományt zárójelek `()` közé az `in` kulcsszóval. Add meg a végrehajtandó műveletet kapcsos zárójelek `{}` közé:

```
fun main() {
    for (number in 1..5) { // number is the iterator and 1..5 is the range || number az iterátor és 1..5 a tartomány
        print(number)
    }
    // 12345
}
```

A kollekciók is végigiterálhatók ciklusokkal:

```
fun main() {
    val cakes = listOf("carrot", "cheese", "chocolate")
    for (cake in cakes) {
        println("Yummy, it's a $cake cake!")
    }
    // Yummy, it's a carrot cake! || Jóízű, ez egy rétes torta!
    // Yummy, it's a cheese cake!  || Jóízű, ez egy sajttorta!
    // Yummy, it's a chocolate cake! || Jóízű, ez egy csokitorta!
}
```

### While

A `while` két módon használható:
- Egy kódblokk végrehajtása, amíg egy feltételes kifejezés igaz. (`while`)
- A kódblokk első végrehajtása, majd a feltételes kifejezés ellenőrzése. (`do-while`)

Az első esetben (`while`):
- Deklaráld a `while` ciklus folytatásának feltételét zárójelek `()` közé.
- Add meg a végrehajtandó műveletet kapcsos zárójelek `{}` közé.

A következő példák a növekmény operátort `++` használják a `cakesEaten` változó értékének növeléséhez.

```
fun main() {
    var cakesEaten = 0
    while (cakesEaten < 3) {
        println("Eat a cake") // Egy torta megkülönböztetése
        cakesEaten++
    }
    // Eat a cake
    // Eat a cake
    // Eat a cake
}
```

A második esetben (`do-while`):
- Deklaráld a `while` ciklus folytatásának feltételét zárójelek `()` közé.
- Definiáld a végrehajtandó műveletet kapcsos zárójelek `{}` közé a `do` kulcsszóval.

```
fun main() {
    var cakesEaten = 0
    var cakesBaked = 0
    while (cakesEaten < 3) {
        println("Eat a cake") // Egy torta megkülönböztetése
        cakesEaten++
    }
    do {
        println("Bake a cake") // Egy torta sütése
        cakesBaked++
    } while (cakesBaked < cakesEaten)
    // Eat a cake
    // Eat a cake
    // Eat a cake
    // Bake a cake
    // Bake a cake
    // Bake a cake
}
```

További információk és példák a feltételes kifejezésekről és ciklusokról: Feltételek és ciklusok.

Most, hogy ismered a Kotlin vezérlési szerkezeteinek alapjait, itt az ideje megtanulni, hogyan írj saját függvényeket.

## Ciklusok gyakorlása

### Feladat 1

Van egy programod, amely pizzadarabokat számol, amíg egy egész pizzát nem kapsz 8 darabbal. Refaktoráld ezt a programot két módon:
- Használj `while` ciklust.
- Használj `do-while` ciklust.

```
fun main() {
    var pizzaSlices = 0
    // Start refactoring here || Kezdj el refaktorálni itt
    pizzaSlices++
    println("There's only $pizzaSlices slice/s of pizza :(")
    pizzaSlices++
    println("There's only $pizzaSlices slice/s of pizza :(")
    pizzaSlices++
    println("There's only $pizzaSlices slice/s of pizza :(")
    pizzaSlices++
    println("There's only $pizzaSlices slice/s of pizza :(")
    pizzaSlices++
    println("There's only $pizzaSlices slice/s of pizza :(")
    pizzaSlices++
    println("There's only $pizzaSlices slice/s of pizza :(")
    pizzaSlices++
    println("There's only $pizzaSlices slice/s of pizza :(")
    pizzaSlices++
    // End refactoring here || Fejezz be a refaktorálást itt
    println("There are $pizzaSlices slices of pizza. Hooray! We have a whole pizza! :D")
}
```

### Megoldás - while ciklussal
```
fun main() {
    var pizzaSlices = 0
    while (pizzaSlices < 7) {
        pizzaSlices++
        println("There's only $pizzaSlices slice/s of pizza :(")
    }
    pizzaSlices++
    println("There are $pizzaSlices slices of pizza. Hooray! We have a whole pizza! :D")
}
```

### Megoldás - do-while ciklussal
```
fun main() {
    var pizzaSlices = 0
    pizzaSlices++
    do {
        println("There's only $pizzaSlices slice/s of pizza :(")
        pizzaSlices++
    } while (pizzaSlices < 8)
    println("There are $pizzaSlices slices of pizza. Hooray! We have a whole pizza! :D")
}
```

### Feladat 2

Írj egy programot, amely szimulálja a Fizz buzz játékot. A feladatod a számok kiírása 1-től 100-ig növekvő sorrendben, kicserélve minden hárommal osztható számot a "fizz" szóra, és minden öttel osztható számot a "buzz" szóra. Minden számot, amely osztható 3-mal és 5-tel is, cserélj le a "fizzbuzz" szóra.

```
​```kotlin
fun main() {
    // Write your code here || Írd ide a kódodat
}
```

### Megoldás
```
fun main() {
    for (number in 1..100) {
        println(
            when {
                number % 15 == 0 -> "fizzbuzz"
                number % 3 == 0 -> "fizz"
                number % 5 == 0 -> "buzz"
                else -> "$number"
            }
        )
    }
}
```

### Feladat 3

Van egy szavak listád. Használd a `for` és `if` utasításokat arra, hogy csak azokat a szavakat írd ki, amelyek az "l" betűvel kezdődnek.

**Tipp:** Használd a `.startsWith()` függvényt a `String` típushoz.

```
fun main() {
    val words = listOf("dinosaur", "limousine", "magazine", "language")
    // Write your code here || Írd ide a kódodat
}
```

### Megoldás
```
fun main() {
    val words = listOf("dinosaur", "limousine", "magazine", "language")
    for (w in words) {
        if (w.startsWith("l"))
            println(w)
    }
}
```

## Következő lépés

## Függvények

### Függvények

Saját függvényeket deklarálhatsz Kotlinban a `fun` kulcsszó használatával.

```
fun hello() {
    return println("Hello, world!") // Helló, világ!
}
```

```
fun main() {
    hello() // Hello, world!
}
```

A Kotlinban:
- A függvény paraméterek zárójelek `()` közé írandók.
- Minden paraméternek típussal kell rendelkeznie, és több paramétert vesszővel `,` kell elválasztani.
- A visszatérési típus a függvény zárójelei `()` után írandó, kettősponttal `:` elválasztva.
- A függvény törzse kapcsos zárójelek `{}` közé írandó.
- A `return` kulcsszó használatos a függvényből való kilépéshez vagy visszatéréshez.
- Ha egy függvény nem ad vissza semmi hasznosat, akkor a visszatérési típus és a `return` kulcsszó elhagyható. Erről többet megtudhatsz a Függvények visszatérés nélkül fejezetben.

A következő példában:
- `x` és `y` a függvény paraméterei.
- `x` és `y` típusa `Int`.
- A függvény visszatérési típusa `Int`.
- A függvény az `x` és `y` összegét adja vissza híváskor.

```
fun sum(x: Int, y: Int): Int {
    return x + y
}
```

```
fun main() {
    println(sum(1, 2)) // 3
}
```

A kódolási konvencióinkban javasoljuk, hogy a függvények nevét kisbetűvel kezdd és használj teve jelölést (camel case) aláhúzásjelek nélkül.

### Elnevezett argumentumok

A tömör kód érdekében a függvény hívásakor nem kell feltüntetni a paraméterneveket. Azonban a paraméternevek feltüntetése megkönnyíti a kód olvashatóságát. Ezt nevezzük elnevezett argumentumok használatának. Ha feltünteted a paraméterneveket, akkor tetszőleges sorrendben írhatod őket.

A következő példában string sablonokat `$` használunk a paraméterértékek eléréséhez, átalakításához karakterlánccá, majd ezek összefűzéséhez egy karakterláncba nyomtatáshoz.

```
fun printMessageWithPrefix(message: String, prefix: String) {
    println("[$prefix] $message")
}
```

```
fun main() {
    // Uses named arguments with swapped parameter order || Elnevezett argumentumok használata felcserélt paramétersorrenddel
    printMessageWithPrefix(prefix = "Log", message = "Hello") // [Log] Hello
}
```

### Alapértelmezett paraméterértékek

Megadhatsz alapértelmezett értékeket a függvényparaméteredhez. Minden paraméter, amelynek van alapértelmezett értéke, elhagyható a függvény hívásakor. Alapértelmezett érték deklarálásához használd a hozzárendelési operátort `=` a típus után:

```
fun printMessageWithPrefix(message: String, prefix: String = "Info") {
    println("[$prefix] $message")
}
```

```
fun main() {
    // Function called with both parameters || Függvény hívása mindkét paraméterrel
    printMessageWithPrefix("Hello", "Log") // [Log] Hello
    
    // Function called only with message parameter || Függvény hívása csak az üzenet paraméterrel
    printMessageWithPrefix("Hello") // [Info] Hello
    
    printMessageWithPrefix(prefix = "Log", message = "Hello") // [Log] Hello
}
```

Kihagyhatod azokat a paramétereket, amelyeknek alapértelmezett értékük van, nem kell mindegyiket elhagynod. Azonban az első kihagyott paraméter után az összes következő paramétert el kell nevezned.

### Függvények visszatérés nélkül

Ha a függvényed nem ad vissza hasznos értéket, akkor visszatérési típusa `Unit`. A `Unit` egy típus, amelynek csak egy értéke van – `Unit`. Nem kell explicit módon deklarálnod, hogy a függvény `Unit` értéket ad vissza. Ez azt jelenti, hogy nem kell használnod a `return` kulcsszót vagy deklarálni a visszatérési típust:

```
fun printMessage(message: String) {
    println(message) // `return Unit` or `return` is optional || `return Unit` vagy `return` opcionális
}
```

```
fun main() {
    printMessage("Hello") // Hello
}
```

### Egysoros függvények

A kódod tömörebbé tételéhez használhatsz egysoros függvényeket. Például a `sum()` függvény rövidíthető:

```
fun sum(x: Int, y: Int): Int {
    return x + y
}
```

```
fun main() {
    println(sum(1, 2)) // 3
}
```

Eltávolíthatod a kapcsos zárójeleket `{}` és deklarálhatod a függvénytörzset a hozzárendelési operátor `=` használatával. Amikor a hozzárendelési operátort `=` használod, a Kotlin típuskikövetkeztetést alkalmaz, így elhagyhatod a visszatérési típust is. A `sum()` függvény így egy soros lesz:

```
fun sum(x: Int, y: Int) = x + y
```

```
fun main() {
    println(sum(1, 2)) // 3
}
```

Azonban ha azt szeretnéd, hogy a kódodat más fejlesztők gyorsan megértsék, jó ötlet explicit módon definiálni a visszatérési típust, még akkor is, amikor a hozzárendelési operátort `=` használod. Ha kapcsos zárójeleket `{}` használsz a függvénytörzs deklarálásához, akkor meg kell adnod a visszatérési típust, kivéve ha az `Unit` típus.

### Korai visszatérés függvényekben

Ahhoz, hogy a függvényed kódját egy bizonyos ponton túl ne dolgozd fel tovább, használd a `return` kulcsszót. Ez a példa `if` utasítást használ a függvényből való korai visszatéréshez, ha a feltételes kifejezés igaznak bizonyul:

```
// A list of registered usernames || Regisztrált felhasználónevek listája
val registeredUsernames = mutableListOf("john_doe", "jane_smith")

// A list of registered emails || Regisztrált e-mailek listája
val registeredEmails = mutableListOf("john@example.com", "jane@example.com")

fun registerUser(username: String, email: String): String {
    // Early return if the username is already taken || Korai visszatérés, ha a felhasználónév már foglalt
    if (username in registeredUsernames) {
        return "Username already taken. Please choose a different username."
    }
    
    // Early return if the email is already registered || Korai visszatérés, ha az e-mail már regisztrálva van
    if (email in registeredEmails) {
        return "Email already registered. Please use a different email."
    }
    
    // Proceed with the registration if the username and email are not taken || Folytasd a regisztrációt, ha a felhasználónév és az e-mail nincs foglalva
    registeredUsernames.add(username)
    registeredEmails.add(email)
    return "User registered successfully: $username"
}
```

```
fun main() {
    println(registerUser("john_doe", "newjohn@example.com"))
    // Username already taken. Please choose a different username. || A felhasználónév már foglalt. Kérjük, válassz másikat.
    
    println(registerUser("new_user", "newuser@example.com"))
    // User registered successfully: new_user || A felhasználó sikeresen regisztrálva: new_user
}
```

## Függvények gyakorlása

### Feladat 1

Írj egy `circleArea` nevű függvényt, amely paraméterként egész számként egy kör sugarát kapja, és visszaadja ennek a körnek a területét.

Ebben a feladatban egy csomagot importálsz, hogy hozzáférj a pi értékéhez a `PI` segítségével.

```
import kotlin.math.PI
// Write your code here || Írd ide a kódodat

fun main() {
    println(circleArea(2))
}
```

### Megoldás
```
import kotlin.math.PI

fun circleArea(radius: Int): Double {
    return PI * radius * radius
}

fun main() {
    println(circleArea(2)) // 12.566370614359172
}
```

### Feladat 2

Írd át az előző feladat `circleArea` függvényét egysoros függvénnyé.

```
import kotlin.math.PI
// Write your code here || Írd ide a kódodat

fun main() {
    println(circleArea(2))
}
```

### Megoldás
```
import kotlin.math.PI

fun circleArea(radius: Int): Double = PI * radius * radius

fun main() {
    println(circleArea(2)) // 12.566370614359172
}
```

### Feladat 3

Van egy függvényed, amely egy órákban, percekben és másodpercekben megadott időintervallumot másodpercekre vált át. A legtöbb esetben csak egy vagy két függvényparamétert kell átadni, míg a többi 0. Javítsd a függvényt és a hívó kódot alapértelmezett paraméterértékek és elnevezett argumentumok használatával, hogy a kód könnyebben olvasható legyen.

```
fun intervalInSeconds(hours: Int, minutes: Int, seconds: Int) = ((hours * 60) + minutes) * 60 + seconds

fun main() {
    println(intervalInSeconds(1, 20, 15))
    println(intervalInSeconds(0, 1, 25))
    println(intervalInSeconds(2, 0, 0))
    println(intervalInSeconds(0, 10, 0))
    println(intervalInSeconds(1, 0, 1))
}
```

### Megoldás
```
fun intervalInSeconds(hours: Int = 0, minutes: Int = 0, seconds: Int = 0) = ((hours * 60) + minutes) * 60 + seconds

fun main() {
    println(intervalInSeconds(1, 20, 15))
    println(intervalInSeconds(minutes = 1, seconds = 25))
    println(intervalInSeconds(hours = 2))
    println(intervalInSeconds(minutes = 10))
    println(intervalInSeconds(hours = 1, seconds = 1))
}
```

## Lambda kifejezések

A Kotlin lehetővé teszi még tömörebb kódot írni függvényekhez lambda kifejezések használatával. Például a következő `uppercaseString()` függvény:

```
fun uppercaseString(text: String): String {
    return text.uppercase()
}
```

```
fun main() {
    println(uppercaseString("hello")) // HELLO
}
```

Lambda kifejezésként is írható:

```
fun main() {
    val upperCaseString = { text: String -> text.uppercase() }
    println(upperCaseString("hello")) // HELLO
}
```

A lambda kifejezések első ránézésre nehezen érthetők, ezért bontsuk le őket. A lambda kifejezések kapcsos zárójelek `{}` közé írandók. A lambda kifejezésen belül írd meg:
- A paramétereket, amelyeket `->` követ.
- A függvénytörzset `->` után.

Az előző példában:
- `text` a függvény paramétere.
- `text` típusa `String`.
- A függvény a `text` változón meghívott `.uppercase()` függvény eredményét adja vissza.
- Az egész lambda kifejezést a `upperCaseString` változóhoz rendeljük a hozzárendelési operátor `=` használatával.
- A lambda kifejezést a `upperCaseString` változó használatával függvényként hívjuk meg a "hello" karakterlánccal paraméterként.
- A `println()` függvény kiírja az eredményt.

Ha egy lambdát paraméterek nélkül deklarálsz, akkor nincs szükség `->` használatára. Például:

```
{ println("Log message") }
```

A lambda kifejezések számos módon használhatók:
- Lambda kifejezés átadása másik függvény paramétereként
- Lambda kifejezés visszaadása függvényből
- Lambda kifejezés önálló meghívása

Egy nagyszerű példa arra, mikor hasznos egy lambda kifejezést átadni függvénynek, a `.filter()` függvény használata kollekciókon:

```
fun main() {
    val numbers = listOf(1, -2, 3, -4, 5, -6)
    val positives = numbers.filter ({ x -> x > 0 })
    val isNegative = { x: Int -> x < 0 }
    val negatives = numbers.filter(isNegative)
    println(positives) // [1, 3, 5]
    println(negatives) // [-2, -4, -6]
}
```

A `.filter()` függvény egy lambda kifejezést fogad predikátumként, és ezt minden listaelemre alkalmazza. A függvény csak akkor tartja meg az elemet, ha a predikátum `true` értéket ad vissza:
- `{ x -> x > 0 }` `true` értéket ad vissza, ha az elem pozitív.
- `{ x -> x < 0 }` `true` értéket ad vissza, ha az elem negatív.

Ez a példa két módot mutat be lambda kifejezés függvénynek való átadására:
- Pozitív számok esetén a példa közvetlenül a lambda kifejezést adja hozzá a `.filter()` függvényhez.
- Negatív számok esetén a példa a lambda kifejezést az `isNegative` változóhoz rendeli. Ezután az `isNegative` változót használja függvényparaméterként a `.filter()` függvényben.

Ebben az esetben meg kell adni a lambda kifejezés függvényparamétereinek (x) típusát.

Ha a lambda kifejezés az egyetlen függvényparaméter, akkor elhagyhatod a függvény zárójeleit `()`:

```
val positives = numbers.filter { x -> x > 0 }
```

Ez egy példa lezáró lambda kifejezésre, amelyről részletesebben a fejezet végén lesz szó.

Egy másik jó példa a `.map()` függvény használata a kollekció elemeinek átalakításához:

```
fun main() {
    val numbers = listOf(1, -2, 3, -4, 5, -6)
    val doubled = numbers.map { x -> x * 2 }
    val isTripled = { x: Int -> x * 3 }
    val tripled = numbers.map(isTripled)
    println(doubled) // [2, -4, 6, -8, 10, -12]
    println(tripled) // [3, -6, 9, -12, 15, -18]
}
```

A `.map()` függvény egy lambda kifejezést fogad transzformációs függvényként:
- `{ x -> x * 2 }` minden listaelemet vesz, és visszaadja azt az elemet, amelyet 2-vel megszoroztak.
- `{ x -> x * 3 }` minden listaelemet vesz, és visszaadja azt az elemet, amelyet 3-mal megszoroztak.

## Függvénytípusok

Mielőtt egy lambda kifejezést visszaadhatsz függvényből, először meg kell értened a függvénytípusokat. Már megtanultad az alaptípusokat, de a függvényeknek maguknak is van típusuk. A Kotlin típuskikövetkeztetése ki tudja következtetni egy függvény típusát a paramétertípus alapján. De lehetnek olyan esetek, amikor explicit módon meg kell adnod a függvénytípust. A fordítónak szüksége van a függvénytípusra ahhoz, hogy tudja, mi engedélyezett és mi nem az adott függvény számára.

A függvénytípus szintaxisa:
- Minden paraméter típusa zárójelek `()` közé írandó és vesszővel `,` elválasztva.
- A visszatérési típus `->` után írandó.

Például: `(String) -> String` vagy `(Int, Int) -> Int`.

Így néz ki egy lambda kifejezés, ha az `upperCaseString()` függvénytípusa definiálva van:

```
val upperCaseString: (String) -> String = { text -> text.uppercase() }
```

```
fun main() {
    println(upperCaseString("hello")) // HELLO
}
```

Ha a lambda kifejezésednek nincs paramétere, akkor a zárójelek `()` üresek maradnak. Például: `() -> Unit`

A paraméter- és visszatérési típusokat vagy a lambda kifejezésben, vagy függvénytípusként kell deklarálnod. Ellenkező esetben a fordító nem fogja tudni, milyen típusú a lambda kifejezésed.

```
Például a következő nem működik:

val upperCaseString = { str -> str.uppercase() }
```

### Visszatérés függvényből

A lambda kifejezések visszaadhatók függvényből. Ahhoz, hogy a fordító értelmezze, milyen típusú a visszaadott lambda kifejezés, deklarálnod kell a függvénytípust.

A következő példában a `toSeconds()` függvény függvénytípusa `(Int) -> Int`, mert mindig egy olyan lambda kifejezést ad vissza, amely `Int` típusú paramétert fogad és `Int` értéket ad vissza.

Ez a példa egy `when` kifejezést használ annak meghatározására, hogy melyik lambda kifejezés kerül visszaadásra a `toSeconds()` hívásakor:

```
fun toSeconds(time: String): (Int) -> Int = when (time) {
    "hour" -> { value -> value * 60 * 60 }
    "minute" -> { value -> value * 60 }
    "second" -> { value -> value }
    else -> { value -> value }
}
```

```
fun main() {
    val timesInMinutes = listOf(2, 10, 15, 1)
    val min2sec = toSeconds("minute")
    val totalTimeInSeconds = timesInMinutes.map(min2sec).sum()
    println("Total time is $totalTimeInSeconds secs") // Total time is 1680 secs || Teljes idő: 1680 másodperc
}
```

### Külön meghívás

A lambda kifejezések önállóan is meghívhatók a kapcsos zárójelek `{}` után zárójelek `()` hozzáadásával és a paraméterek zárójelek közé helyezésével:

```
fun main() {
    println({ text: String -> text.uppercase() }("hello")) // HELLO
}
```

### Lezáró lambda kifejezések

Ahogy már láttad, ha egy lambda kifejezés az egyetlen függvényparaméter, akkor elhagyhatod a függvény zárójeleit `()`. Ha egy lambda kifejezés egy függvény utolsó paramétereként kerül átadásra, akkor a kifejezés a függvény zárójelein kívül írható.

Mindkét esetben ezt a szintaxist lezáró lambda kifejezésnek nevezik.

Például a `.fold()` függvény egy kezdeti értéket és egy műveletet fogad:

```
fun main() {
    // The initial value is zero. || A kezdeti érték nulla.
    // The operation sums the initial value with every item in the list cumulatively. || A művelet kumulatívan összeadja a kezdeti értéket a lista minden elemével.
    println(listOf(1, 2, 3).fold(0, { x, item -> x + item })) // 6
    
    // Alternatively, in the form of a trailing lambda || Alternatívaként, lezáró lambda formában
    println(listOf(1, 2, 3).fold(0) { x, item -> x + item }) // 6
}
```

További információ a lambda kifejezésekről: Lambda kifejezések és névtelen függvények.

A túra következő lépése az osztályok megismerése Kotlinban.

## Lambda kifejezések gyakorlása

### Feladat 1

Van egy webes szolgáltatás által támogatott műveletek listád, egy közös előtag minden kéréshez, és egy adott erőforrás azonosítója. Egy művelet címének kéréséhez az azonosítójú erőforráson keresztül: 5, a következő URL-t kell létrehoznod: `https://example.com/book-info/5/title`.

Használj lambda kifejezést URL-ek listájának létrehozásához a műveleti listából.

```
fun main() {
    val actions = listOf("title", "year", "author")
    val prefix = "https://example.com/book-info"
    val id = 5
    val urls = // Write your code here || Írd ide a kódodat
    println(urls)
}
```

### Megoldás
```
fun main() {
    val actions = listOf("title", "year", "author")
    val prefix = "https://example.com/book-info"
    val id = 5
    val urls = actions.map { action -> "$prefix/$id/$action" }
    println(urls)
}
```

### Feladat 2

Írj egy függvényt, amely egy `Int` értéket és egy műveletet fogad (egy `() -> Unit` típusú függvényt), majd megismétli ezt a műveletet a megadott számú alkalommal. Ezután használd ezt a függvényt "Hello" kiíratására 5 alkalommal.

```
fun repeatN(n: Int, action: () -> Unit) {
    // Write your code here || Írd ide a kódodat
}

fun main() {
    // Write your code here || Írd ide a kódodat
}
```

### Megoldás
```
fun repeatN(n: Int, action: () -> Unit) {
    for (i in 1..n) {
        action()
    }
}

fun main() {
    repeatN(5) { println("Hello") }
}
```

## Következő lépés

## Osztályok

### Osztályok

A Kotlin támogatja az objektumorientált programozást osztályokkal és objektumokkal. Az objektumok hasznosak az adatok tárolására a programodban. Az osztályok lehetővé teszik egy objektum jellemzőinek halmazának deklarálását. Amikor objektumokat hozol létre egy osztályból, időt és erőfeszítést spórolhatsz, mert nem kell minden alkalommal deklarálnod ezeket a jellemzőket.

Egy osztály deklarálásához használd a `class` kulcsszót:

```
class Customer
```

### Tulajdonságok

Egy osztály objektumának jellemzői tulajdonságokban deklarálhatók. Tulajdonságokat deklarálhatsz egy osztályhoz:
- Zárójelek `()` közé az osztály neve után.
```
class Contact(val id: Int, var email: String)
```

- Az osztálytörzsben, amely kapcsos zárójelek `{}` által definiált.
```
class Contact(val id: Int, var email: String) {
    val category: String = ""
}
```

Javasoljuk, hogy a tulajdonságokat csak olvashatóként (`val`) dekláld, kivéve ha az osztály példányának létrehozása után módosítani kell őket. Deklarálhatsz tulajdonságokat `val` vagy `var` nélkül a zárójelek között, de ezek a tulajdonságok nem lesznek elérhetők az osztálypéldány létrehozása után. A zárójelek `()` közé helyezett tartalmat osztályfejlécnek nevezzük.

Használhatsz záró vesszőt az osztálytulajdonságok deklarálásakor. Éppúgy, mint a függvényparamétereknél, az osztálytulajdonságoknak lehetnek alapértelmezett értékeik:

```
class Contact(val id: Int, var email: String = "example@gmail.com") {
    val category: String = "work"
}
```

### Példány létrehozása

Egy objektum létrehozásához egy osztályból deklarálnod kell egy osztálypéldányt egy konstruktor használatával. Alapértelmezés szerint a Kotlin automatikusan létrehoz egy konstruktort az osztályfejlécben deklarált paraméterekkel. Például:

```
class Contact(val id: Int, var email: String)

fun main() {
    val contact = Contact(1, "mary@gmail.com")
}
```

A példában:
- `Contact` egy osztály.
- `contact` a `Contact` osztály egy példánya.
- `id` és `email` tulajdonságok.
- `id` és `email` az alapértelmezett konstruktorral használatosak a `contact` létrehozásához.

A Kotlin osztályoknak lehet több konstruktoruk is, beleértve azokat is, amelyeket saját magad definiálsz. További információ a több konstruktor deklarálásáról: Konstruktorok.

### Tulajdonságok elérése

Egy példány tulajdonságának eléréséhez írd az osztálypéldány neve után a tulajdonság nevét ponttal `.` elválasztva:

```
class Contact(val id: Int, var email: String)

fun main() {
    val contact = Contact(1, "mary@gmail.com")
    // Prints the value of the property: email || Kiírja az email tulajdonság értékét
    println(contact.email) // mary@gmail.com
    
    // Updates the value of the property: email || Frissíti az email tulajdonság értékét
    contact.email = "jane@gmail.com"
    
    // Prints the new value of the property: email || Kiírja az email tulajdonság új értékét
    println(contact.email) // jane@gmail.com
}
```

Egy tulajdonság értékének karakterláncba való összefűzéséhez használhatsz string sablonokat (`$`). Például:

```
println("Their email address is: ${contact.email}")
```

### Tagfüggvények

Egy objektum jellemzőinek deklarálásán kívül az objektum viselkedését tagfüggvényekkel is meghatározhatod. Kotlinban a tagfüggvényeket az osztálytörzsben kell deklarálni. Egy tagfüggvény meghívásához írd az osztálypéldány neve után a függvény nevét ponttal `.` elválasztva.

Például:

```
class Contact(val id: Int, var email: String) {
    fun printId() {
        println(id)
    }
}

fun main() {
    val contact = Contact(1, "mary@gmail.com")
    // Calls member function printId() || Tagfüggvény printId() meghívása
    contact.printId() // 1
}
```

### Adatosztályok

A Kotlin rendelkezik adatosztályokkal, amelyek különösen hasznosak az adatok tárolására. Az adatosztályok ugyanolyan funkcionalitással rendelkeznek, mint a hagyományos osztályok, de automatikusan rendelkeznek további tagfüggvényekkel. Ezek a tagfüggvények lehetővé teszik az osztálypéldány könnyű olvasható formátumú kiírását, az osztálypéldányok összehasonlítását, másolását és még sok mást.

Mivel ezek a függvények automatikusan elérhetők, nem kell időt töltened ugyanazon boilerplate kód megírásával minden osztályodhoz.

Egy adatosztály deklarálásához használd a `data` kulcsszót:

```
data class User(val name: String, val id: Int)
```

Az adatosztályok leghasznosabb előredefiniált tagfüggvényei:

| Függvény             | Leírás                                                       |
| -------------------- | ------------------------------------------------------------ |
| `toString()`         | Kiír egy olvasható karakterláncot az osztálypéldányról és annak tulajdonságairól. |
| `equals()` vagy `==` | Összehasonlítja az osztálypéldányokat.                       |
| `copy()`             | Létrehoz egy osztálypéldányt egy másik másolásával, esetlegesen néhány eltérő tulajdonsággal. |

A következő szakaszokban példákat láthatsz az egyes függvények használatára:
- Kiírás karakterláncként
- Példányok összehasonlítása
- Példány másolása

### Kiírás karakterláncként

Egy osztálypéldány olvasható karakterláncának kiírásához explicit módon meghívhatod a `toString()` függvényt, vagy használhatsz kiíró függvényeket (`println()` és `print()`), amelyek automatikusan meghívják a `toString()` függvényt:

```
data class User(val name: String, val id: Int)

fun main() {
    val user = User("Alex", 1)
    // Automatically uses toString() function so that output is easy to read || Automatikusan használja a toString() függvényt, hogy a kimenet könnyen olvasható legyen
    println(user) // User(name=Alex, id=1)
}
```

Ez különösen hasznos hibakereséskor vagy naplók létrehozásakor.

### Példányok összehasonlítása

Adatosztály-példányok összehasonlításához használd az egyenlőség operátort `==`:

```
data class User(val name: String, val id: Int)

fun main() {
    val user = User("Alex", 1)
    val secondUser = User("Alex", 1)
    val thirdUser = User("Max", 2)
    
    // Compares user to second user || user összehasonlítása secondUser-rel
    println("user == secondUser: ${user == secondUser}") // user == secondUser: true
    
    // Compares user to third user || user összehasonlítása thirdUser-rel
    println("user == thirdUser: ${user == thirdUser}") // user == thirdUser: false
}
```

### Példány másolása

Egy adatosztály-példány pontos másolatának létrehozásához hívd meg a `copy()` függvényt a példányon. Egy adatosztály-példány másolatának létrehozásához néhány tulajdonság megváltoztatásával hívd meg a `copy()` függvényt a példányon, és add meg a helyettesítő értékeket a függvényparaméterekként.

Például:

```
data class User(val name: String, val id: Int)

fun main() {
    val user = User("Alex", 1)
    // Creates an exact copy of user || Pontos másolat létrehozása user-ről
    println(user.copy()) // User(name=Alex, id=1)
    
    // Creates a copy of user with name: "Max" || user másolatának létrehozása "Max" névvel
    println(user.copy("Max")) // User(name=Max, id=1)
    
    // Creates a copy of user with id: 3 || user másolatának létrehozása 3-as azonosítóval
    println(user.copy(id = 3)) // User(name=Alex, id=3)
}
```

Egy példány másolatának létrehozása biztonságosabb, mint az eredeti példány módosítása, mert az eredeti példánytól függő kódok nem érintettek a másolat és az azzal végzett műveletek által.

További információ az adatosztályokról: Adatosztályok.

A túra utolsó fejezete a Kotlin null biztonságáról szól.

## Gyakorlás

### Feladat 1

Definiálj egy `Employee` adatosztályt két tulajdonsággal: egy névhez és egy fizetéshez. Győződj meg róla, hogy a fizetés tulajdonság módosítható, különben nem kapsz bért emelést az év végén! A `main` függvény bemutatja, hogyan használhatod ezt az adatosztályt.

```
// Write your code here || Írd ide a kódodat

fun main() {
    val emp = Employee("Mary", 20)
    println(emp)
    emp.salary += 10
    println(emp)
}
```

### Megoldás
```
data class Employee(val name: String, var salary: Int)

fun main() {
    val emp = Employee("Mary", 20)
    println(emp)
    emp.salary += 10
    println(emp)
}
```

### Feladat 2

Deklaráld a további adatosztályokat, amelyek szükségesek a kód lefordításához.

```
data class Person(val name: Name, val address: Address, val ownsAPet: Boolean = true)
// Write your code here || Írd ide a kódodat
// data class Name(...)

fun main() {
    val person = Person(
        Name("John", "Smith"),
        Address("123 Fake Street", City("Springfield", "US")),
        ownsAPet = false
    )
}
```

### Megoldás
```
data class Person(val name: Name, val address: Address, val ownsAPet: Boolean = true)
data class Name(val first: String, val last: String)
data class Address(val street: String, val city: City)
data class City(val name: String, val countryCode: String)

fun main() {
    val person = Person(
        Name("John", "Smith"),
        Address("123 Fake Street", City("Springfield", "US")),
        ownsAPet = false
    )
}
```

### Feladat 3

A kódod teszteléséhez szükséged van egy generátorra, amely véletlenszerű alkalmazottakat tud létrehozni. Definiálj egy `RandomEmployeeGenerator` osztályt egy rögzített lehetséges nevek listájával (az osztálytörzsben). Konfiguráld az osztályt minimális és maximális fizetéssel (az osztályfejlécben). Az osztálytörzsben definiáld a `generateEmployee()` függvényt. Ismét a `main` függvény bemutatja, hogyan használhatod ezt az osztályt.

## Gyakorlás - RandomEmployeeGenerator (folytatás)

Ebben a feladatban egy `RandomEmployeeGenerator` osztályt hozunk létre, amely véletlenszerű alkalmazottakat generál. A példában a `kotlin.random.Random` csomagot használjuk a véletlenszám-generáláshoz.

**Tipp 1:** A listáknak van egy `.random()` kiterjesztési függvénye, amely egy véletlenszerű elemet ad vissza a listából.  
**Tipp 2:** A `Random.nextInt(from = ..., until = ...)` ad egy véletlenszerű `Int` számot a megadott határok között.

```
import kotlin.random.Random

data class Employee(val name: String, var salary: Int)

// Write your code here || Írd ide a kódodat
fun main() {
    val empGen = RandomEmployeeGenerator(10, 30)
    println(empGen.generateEmployee())
    println(empGen.generateEmployee())
    println(empGen.generateEmployee())
    empGen.minSalary = 50
    empGen.maxSalary = 100
    println(empGen.generateEmployee())
}
```

### Megoldás
```
import kotlin.random.Random

data class Employee(val name: String, var salary: Int)

class RandomEmployeeGenerator(var minSalary: Int, var maxSalary: Int) {
    val names = listOf("John", "Mary", "Ann", "Paul", "Jack", "Elizabeth")
    
    fun generateEmployee() = Employee(names.random(), Random.nextInt(from = minSalary, until = maxSalary))
}

fun main() {
    val empGen = RandomEmployeeGenerator(10, 30)
    println(empGen.generateEmployee())
    println(empGen.generateEmployee())
    println(empGen.generateEmployee())
    empGen.minSalary = 50
    empGen.maxSalary = 100
    println(empGen.generateEmployee())
}
```

## Következő lépés: Null biztonság

### Null biztonság

A Kotlinban lehetséges null értékek használata. A Kotlin null értékeket használ, amikor valami hiányzik vagy még nincs beállítva. Már láttál egy példát arra, amikor a Kotlin null értéket ad vissza a Kollekciók fejezetben, amikor egy olyan kulcs-érték párt próbáltál elérni, amelynek kulcsa nem létezik a térképben.

Bár hasznos a null értékek használata ilyen módon, problémákba ütközhetsz, ha a kódod nincs felkészítve a kezelésükre. Ahhoz, hogy megelőzzük a null értékekkel kapcsolatos problémákat a programjaidban, a Kotlinban van null biztonság.

A null biztonság a lehetséges problémákat a null értékekkel fordítási időben észleli, nem futási időben. A null biztonság olyan funkciók kombinációja, amelyek lehetővé teszik:

- Kifejezetten deklarálni, mikor engedélyezettek a null értékek a programodban.
- Null értékeket ellenőrizni.
- Biztonságos hívásokat használni olyan tulajdonságokhoz vagy függvényekhez, amelyek null értékeket tartalmazhatnak.
- Meghatározni a végrehajtandó műveleteket, ha null értékeket észlel.

### Nullable típusok

A Kotlin támogatja a nullable típusokat, amelyek lehetővé teszik annak lehetőségét, hogy a deklarált típusnak null értékei legyenek. Alapértelmezés szerint egy típus nem fogad el null értékeket. A nullable típusokat kifejezetten a `?` hozzáadásával a típusdeklaráció után deklaráljuk.

Például:

```
fun main() {
    // neverNull has String type || neverNull String típusú
    var neverNull: String = "This can't be null"
    // Throws a compiler error || Fordítási hibát okoz
    neverNull = null
    
    // nullable has nullable String type || nullable nullable String típusú
    var nullable: String? = "You can keep a null here"
    // This is OK || Ez rendben van
    nullable = null
    
    // By default, null values aren't accepted || Alapértelmezés szerint a null értékeket nem fogadja el
    var inferredNonNull = "The compiler assumes non-nullable"
    // Throws a compiler error || Fordítási hibát okoz
    inferredNonNull = null
    
    // notNull doesn't accept null values || notNull nem fogad el null értékeket
    fun strLength(notNull: String): Int {
        return notNull.length
    }
    
    println(strLength(neverNull)) // 18
    println(strLength(nullable))   // Throws a compiler error || Fordítási hibát okoz
}
```

A `length` a String osztály egy tulajdonsága, amely tartalmazza a karakterláncban lévő karakterek számát.

### Null értékek ellenőrzése

A null értékek jelenlétét feltételes kifejezéseken belül ellenőrizheted. A következő példában a `describeString()` függvény egy `if` utasítással ellenőrzi, hogy a `maybeString` nem null és hossza nagyobb-e nullánál:

```
fun describeString(maybeString: String?): String {
    if (maybeString != null && maybeString.length > 0) {
        return "String of length ${maybeString.length}"
    } else {
        return "Empty or null string"
    }
}

fun main() {
    val nullString: String? = null
    println(describeString(nullString)) // Empty or null string || Üres vagy null karakterlánc
}
```

### Biztonságos hívások

Ahhoz, hogy biztonságosan hozzáférj egy olyan objektum tulajdonságaihoz, amely null értéket tartalmazhat, használd a biztonságos hívás operátort `?.`. A biztonságos hívás operátor null értéket ad vissza, ha az objektum vagy az egyik elérni kívánt tulajdonsága null.

Ez hasznos, ha el akarod kerülni, hogy a null értékek jelenléte hibákat okozzon a kódodban.

A következő példában a `lengthString()` függvény egy biztonságos hívást használ annak visszaadására, hogy a karakterlánc hossza vagy null:

```
fun lengthString(maybeString: String?): Int? = maybeString?.length

fun main() {
    val nullString: String? = null
    println(lengthString(nullString)) // null
}
```

A biztonságos hívások láncolhatók, így ha egy objektum bármely tulajdonsága null értékű, akkor null érték kerül visszaadásra hiba dobása nélkül. Például:

```
person.company?.address?.country
```

A biztonságos hívás operátor használható kiterjesztési vagy tagfüggvények biztonságos hívására is. Ebben az esetben a függvény meghívása előtt null ellenőrzés történik. Ha az ellenőrzés null értéket észlel, akkor a hívás kihagyásra kerül és null érték kerül visszaadásra.

A következő példában a `nullString` null, ezért a `.uppercase()` meghívása kihagyásra kerül és null érték kerül visszaadásra:

```
fun main() {
    val nullString: String? = null
    println(nullString?.uppercase()) // null
}
```

### Elvis operátor

Megadhatsz alapértelmezett értéket, amelyet visszaad, ha null értéket észlel az Elvis operátor `?:` használatával.

Írd az Elvis operátor bal oldalára, hogy mit kell null értékre ellenőrizni. Írd az Elvis operátor jobb oldalára, hogy mit kell visszaadni, ha null értéket észlel.

A következő példában a `nullString` null, így a biztonságos hívás a hossz tulajdonság eléréséhez null értéket ad vissza. Ennek eredményeként az Elvis operátor 0-t ad vissza:

```
fun main() {
    val nullString: String? = null
    println(nullString?.length ?: 0) // 0
}
```

További információ a Kotlin null biztonságáról: Null biztonság.

## Gyakorlás

Van egy `employeeById` függvényed, amely hozzáférést biztosít egy vállalat alkalmazottainak adatbázisához. Sajnos ez a függvény az `Employee?` típusú értéket adja vissza, így az eredmény lehet null. A célod egy olyan függvény írása, amely visszaadja egy alkalmazott fizetését, ha meg van adva az azonosítója, vagy 0-t, ha az alkalmazott hiányzik az adatbázisból.

```
data class Employee (val name: String, var salary: Int)

fun employeeById(id: Int) = when(id) {
    1 -> Employee("Mary", 20)
    2 -> null
    3 -> Employee("John", 21)
    4 -> Employee("Ann", 23)
    else -> null
}

fun salaryById(id: Int) = // Write your code here || Írd ide a kódodat

fun main() {
    println((1..5).sumOf { id -> salaryById(id) })
}
```

### Megoldás
```
data class Employee (val name: String, var salary: Int)

fun employeeById(id: Int) = when(id) {
    1 -> Employee("Mary", 20)
    2 -> null
    3 -> Employee("John", 21)
    4 -> Employee("Ann", 23)
    else -> null
}

fun salaryById(id: Int) = employeeById(id)?.salary ?: 0

fun main() {
    println((1..5).sumOf { id -> salaryById(id) }) // 64
}
```

## Mi a következő?

Gratulálunk! Most, hogy befejezted a kezdő túrát, emeld a Kotlin ismereteidet a következő szintre középhaladó túránkkal:

### [Indítsd el a középhaladó Kotlin túrát](#)

## Középhaladó: Extension függvények

Ebben a fejezetben olyan speciális Kotlin függvényeket fogsz felfedezni, amelyek a kódodat tömörebbé és olvashatóbbá teszik. Megtanulod, hogyan segíthetnek hatékony tervezési minták használatával a projektjeidet a következő szintre emelni.

### Extension függvények

Szoftverfejlesztés során gyakran szükség van egy program viselkedésének módosítására anélkül, hogy megváltoztatnád az eredeti forráskódot. Például extra funkcionalitást szeretnél hozzáadni egy harmadik féltől származó könyvtár osztályához.

Ezt extension függvények hozzáadásával teheted meg az osztály kiterjesztéséhez. Az extension függvényeket ugyanúgy hívod meg, mint egy osztály tagfüggvényeit, pont `.` használatával.

Mielőtt bevezetnénk az extension függvények teljes szintaxisát, meg kell értened, mi az a receiver. A receiver az, amire a függvényt hívják. Más szóval, a receiver az, ahol vagy akivel az információ meg van osztva.

#### Példa küldőre és receiverre

Ebben a példában a `main()` függvény a `.first()` függvényt hívja meg egy lista első elemének visszaadásához. A `.first()` függvényt a `readOnlyShapes` változón hívják meg, így a `readOnlyShapes` változó a receiver.

Egy extension függvény létrehozásához írd az osztály nevét, amelyet ki szeretnél terjeszteni, majd egy `.` jelet és a függvény nevét. Folytasd a függvénydeklaráció többi részével, beleértve az argumentumait és visszatérési típusát.

Például:

```
fun String.bold(): String = "<b>$this</b>"

fun main() {
    // "hello" is the receiver || "hello" a receiver
    println("hello".bold()) // <b>hello</b>
}
```

Ebben a példában:
- A `String` a kiterjesztett osztály.
- A `bold` az extension függvény neve.
- A `.bold()` extension függvény visszatérési típusa `String`.
- A `"hello"`, egy `String` példány, mint receiver.
- A receiver a törzsben a `this` kulcsszóval érhető el.
- Egy string sablon (`$`) használatával érhető el a `this` értéke.
- A `.bold()` extension függvény egy karakterláncot vesz át, és visszaadja azt egy `<b>` HTML elemben a vastagított szöveghez.

### Kiterjesztés-orientált tervezés

Az extension függvényeket bárhol definiálhatod, amely lehetővé teszi a kiterjesztés-orientált tervezések létrehozását. Ezek a tervezések elkülönítik az alapfunkcionalitást a hasznos, de nem alapvető funkcióktól, így a kódodat könnyebb olvasni és karbantartani.

Egy jó példa erre a Ktor könyvtár `HttpClient` osztálya, amely segít hálózati kérések végrehajtásában. Funkcionalitásának alapja egyetlen `request()` függvény, amely minden HTTP kéréshez szükséges információt tartalmaz:

```
class HttpClient {
    fun request(method: String, url: String, headers: Map<String, String>): HttpResponse {
        // Network code || Hálózati kód
    }
}
```

Gyakorlatban a legnépszerűbb HTTP kérések a GET vagy POST kérések. Ésszerű a könyvtárnak rövidebb neveket biztosítani ezekhez a gyakori használati esetekhez. Azonban ezek nem igényelnek új hálózati kód írását, csak egy specifikus kérés hívását. Más szóval, tökéletes jelöltek különálló `.get()` és `.post()` extension függvényekként való definiálásra:

```
fun HttpClient.get(url: String): HttpResponse = request("GET", url, emptyMap())
fun HttpClient.post(url: String): HttpResponse = request("POST", url, emptyMap())
```

Ezek a `.get()` és `.post()` függvények a `request()` függvényt hívják meg a megfelelő HTTP metódussal, így neked nem kell. Ezek egyszerűsítik a kódodat és könnyebbé teszik a megértését:

```
class HttpClient {
    fun request(method: String, url: String, headers: Map<String, String>): HttpResponse {
        println("Requesting $method to $url with headers: $headers")
        return HttpResponse("Response from $url")
    }
}

fun HttpClient.get(url: String): HttpResponse = request("GET", url, emptyMap())

fun main() {
    val client = HttpClient()
    // Making a GET request using request() directly || GET kérés végrehajtása request() használatával közvetlenül
    val getResponseWithMember = client.request("GET", "https://example.com", emptyMap())
    // Making a GET request using the get() extension function || GET kérés végrehajtása a get() extension függvénnyel
    val getResponseWithExtension = client.get("https://example.com")
}
```

Ez a kiterjesztés-orientált megközelítés széles körben használt a Kotlin standard könyvtárában és más könyvtárakban. Például a `String` osztály sok extension függvénnyel rendelkezik, amelyek segítenek a karakterláncokkal való munkában.

További információ az extension függvényekről: Kiterjesztések.

## Gyakorlás

### Feladat 1

Írj egy `isPositive` nevű extension függvényt, amely egy egész számot vesz át és ellenőrzi, hogy pozitív-e.

```
fun Int.// Write your code here || Írd ide a kódodat

fun main() {
    println(1.isPositive()) // true
}
```

### Megoldás
```
fun Int.isPositive(): Boolean = this > 0

fun main() {
    println(1.isPositive()) // true
}
```

### Feladat 2

Írj egy `toLowercaseString` nevű extension függvényt, amely egy karakterláncot vesz át és visszaad egy kisbetűs verziót.

**Tipp:** Használd a `.lowercase()` függvényt a `String` típushoz.

```
fun // Write your code here || Írd ide a kódodat

fun main() {
    println("Hello World!".toLowercaseString()) // hello world!
}
```

### Megoldás
```
fun String.toLowercaseString(): String = this.lowercase()

fun main() {
    println("Hello World!".toLowercaseString()) // hello world!
}
```

## Következő lépés

## Középhaladó: Scope függvények

Ebben a fejezetben az extension függvények ismereteidre építve megtanulod a scope függvények használatát idiomatikus kód írásához.

### Scope függvények

A programozásban a scope az a terület, ahol a változó vagy objektum felismerhető. A leggyakrabban említett scope-ok a globális scope és a lokális scope:

- **Globális scope** – egy változó vagy objektum, amely bárhonnan elérhető a programban.
- **Lokális scope** – egy változó vagy objektum, amely csak azon a blokkon vagy függvényen belül érhető el, ahol definiálva van.

A Kotlinban vannak scope függvények is, amelyek lehetővé teszik egy ideiglenes scope létrehozását egy objektum körül, és némi kód végrehajtását.

A scope függvények a kódodat tömörebbé teszik, mert nem kell hivatkoznod az objektum nevére az ideiglenes scope-ban. A scope függvénytől függően az objektumhoz vagy a `this` kulcsszóval való hivatkozással, vagy `it` kulcsszóval argumentumként való használatával férhetsz hozzá.

A Kotlin összesen öt scope függvénnyel rendelkezik: `let`, `apply`, `run`, `also`, és `with`. Minden scope függvény egy lambda kifejezést vesz át, és visszaadja az objektumot vagy a lambda kifejezés eredményét.

Ebben a túrában mindegyik scope függvényt és használatukat elmagyarázzuk. Megnézheted Sebastian Aigner, Kotlin fejlesztői ügyvéd előadását a scope függvényekről: "Back to the Stdlib: Making the Most of Kotlin's Standard Library".

### Let

Használd a `let` scope függvényt, amikor null ellenőrzéseket szeretnél végrehajtani a kódodban, és később további műveleteket végezni a visszaadott objektummal.

Vegyük a következő példát:

```
fun sendNotification(recipientAddress: String): String {
    println("Yo $recipientAddress!")
    return "Notification sent!"
}

fun getNextAddress(): String {
    return "sebastian@jetbrains.com"
}

fun main() {
    val address: String? = getNextAddress()
    sendNotification(address)
}
```

A példa két függvényt tartalmaz:
- `sendNotification()`, amely egy `recipientAddress` függvényparaméterrel rendelkezik és karakterláncot ad vissza.
- `getNextAddress()`, amely nem rendelkezik függvényparaméterekkel és karakterláncot ad vissza.

A példa létrehoz egy `address` változót, amely nullable `String` típusú. Ez problémát okoz, amikor a `sendNotification()` függvényt hívod, mert ez a függvény nem várja, hogy az `address` null értékű lehet.

A fordító hibát jelez eredményként:
```
Argument type mismatch: actual type is 'String?', but 'String' was expected.
```

A kezdő túrából már tudod, hogy egy `if` feltétellel vagy az Elvis operátorral `?:` végezhetsz null ellenőrzést. De mi van, ha a visszaadott objektumot később szeretnéd használni a kódodban?

Ezt egy `if` feltétellel és egy `else` ággal is elérheted:

```
fun sendNotification(recipientAddress: String): String {
    println("Yo $recipientAddress!")
    return "Notification sent!"
}

fun getNextAddress(): String {
    return "sebastian@jetbrains.com"
}

fun main() {
    val address: String? = getNextAddress()
    val confirm = if(address != null) {
        sendNotification(address)
    } else {
        null
    }
}
```

Azonban egy tömörebb megközelítés a `let` scope függvény használata:

```
fun sendNotification(recipientAddress: String): String {
    println("Yo $recipientAddress!")
    return "Notification sent!"
}

fun getNextAddress(): String {
    return "sebastian@jetbrains.com"
}

fun main() {
    val address: String? = getNextAddress()
    val confirm = address?.let { sendNotification(it) }
}
```

A példa:
- Létrehozza az `address` és `confirm` változókat.
- Biztonságos hívást használ a `let` scope függvényhez az `address` változón.
- Létrehoz egy ideiglenes scope-ot a `let` scope függvényen belül.
- Átadja a `sendNotification()` függvényt lambda kifejezésként a `let` scope függvénybe.
- Az `address` változóra hivatkozik `it` segítségével az ideiglenes scope használatával.
- Hozzárendeli az eredményt a `confirm` változóhoz.

Ezzel a megközelítéssel a kódod kezelheti az `address` változó potenciális null értékét, és a `confirm` változót később is használhatod a kódodban.

### Apply

Használd az `apply` scope függvényt objektumok, például osztálypéldányok inicializálásához a létrehozás időpontjában, nem később a kódban. Ez a megközelítés könnyebbé teszi a kódod olvasását és kezelését.

Vegyük a következő példát:

```
class Client() {
    var token: String? = null
    fun connect() = println("connected!")
    fun authenticate() = println("authenticated!")
    fun getData(): String = "Mock data"
}

val client = Client()

fun main() {
    client.token = "asdf"
    client.connect()      // connected!
    client.authenticate()  // authenticated!
    client.getData()
}
```

A példa egy `Client` osztályt tartalmaz, amely egy `token` nevű tulajdonsággal és három tagfüggvénnyel rendelkezik: `connect()`, `authenticate()`, és `getData()`.

A példa létrehozza a `client` változót a `Client` osztály egy példányaként, mielőtt inicializálná annak `token` tulajdonságát és meghívná tagfüggvényeit a `main()` függvényben.

Bár ez a példa tömör, a valós világban eltarthat egy ideig, mire konfigurálni és használni tudod az osztálypéldányt (és annak tagfüggvényeit) a létrehozása után.

Azonban ha az `apply` scope függvényt használod, létrehozhatod, konfigurálhatod és használhatod a tagfüggvényeket az osztálypéldányon ugyanazon a helyen a kódban:

```
class Client() {
    var token: String? = null
    fun connect() = println("connected!")
    fun authenticate() = println("authenticated!")
    fun getData(): String = "Mock data"
}

val client = Client().apply {
    token = "asdf"
    connect()
    authenticate()
}

fun main() {
    client.getData()
    // connected!
    // authenticated!
}
```

A példa:
- Létrehozza a `client` változót a `Client` osztály egy példányaként.
- Használja az `apply` scope függvényt a `client` példányon.
- Létrehoz egy ideiglenes scope-ot az `apply` scope függvényen belül, így nem kell kifejezetten hivatkoznod a `client` példányra annak tulajdonságaihoz vagy függvényeihez való hozzáféréskor.
- Átad egy lambda kifejezést az `apply` scope függvénynek, amely frissíti a `token` tulajdonságot és meghívja a `connect()` és `authenticate()` függvényeket.
- Meghívja a `getData()` tagfüggvényt a `client` példányon a `main()` függvényben.

Ahogy látod, ez a stratégia kényelmes nagyobb kódrészletekkel való munka során.

### Run

Hasonlóan az `apply` függvényhez, a `run` scope függvényt használhatod egy objektum inicializálásához, de jobb a `run` használata egy objektum inicializálásához egy adott pillanatban a kódban és azonnali eredmény kiszámításához.

Folytassuk az előző példát az `apply` függvénynél, de ezúttal szeretnéd, hogy a `connect()` és `authenticate()` függvények csoportosítva legyenek, így minden kérésnél meghívódnak.

Például:

```
class Client() {
    var token: String? = null
    fun connect() = println("connected!")
    fun authenticate() = println("authenticated!")
    fun getData(): String = "Mock data"
}

val client: Client = Client().apply {
    token = "asdf"
}

fun main() {
    val result: String = client.run {
        connect()      // connected!
        authenticate()  // authenticated!
        getData()
    }
}
```

A példa:
- Létrehozza a `client` változót a `Client` osztály egy példányaként.
- Használja az `apply` scope függvényt a `client` példányon.
- Létrehoz egy ideiglenes scope-ot az `apply` scope függvényen belül, így nem kell kifejezetten hivatkoznod a `client` példányra annak tulajdonságaihoz vagy függvényeihez való hozzáféréskor.
- Átad egy lambda kifejezést az `apply` scope függvénynek, amely frissíti a `token` tulajdonságot.

A `main()` függvény:
- Létrehoz egy `result` változót `String` típussal.
- Használja a `run` scope függvényt a `client` példányon.

```
Létrehoz egy ideiglenes scope-ot a `run` scope függvényen belül, így nem kell kifejezetten hivatkoznod a `client` példányra annak tulajdonságaihoz vagy függvényeihez való hozzáféréskor.
- Átad egy lambda kifejezést a `run` scope függvénynek, amely meghívja a `connect()`, `authenticate()`, és `getData()` függvényeket.
- Hozzárendeli az eredményt a `result` változóhoz.

Most már használhatod a visszaadott eredményt később a kódodban.

### Also

Használd az `also` scope függvényt egy objektummal történő további művelet végrehajtásához, majd az objektum visszaadásához a további használathoz, például naplózás írásához.

Vegyük a következő példát:

​```kotlin
fun main() {
    val medals: List<String> = listOf("Gold", "Silver", "Bronze")
    val reversedLongUppercaseMedals: List<String> = medals
        .map { it.uppercase() }
        .filter { it.length > 4 }
        .reversed()
    println(reversedLongUppercaseMedals) // [BRONZE, SILVER]
}
```

A példa:
- Létrehozza a `medals` változót, amely karakterláncok listáját tartalmazza.
- Létrehozza a `reversedLongUpperCaseMedals` változót, amely `List<String>` típusú.
- Használja a `.map()` extension függvényt a `medals` változón.
- Átad egy lambda kifejezést a `.map()` függvénynek, amely a `medals` változóra hivatkozik az `it` kulcsszó segítségével, és meghívja rajta az `.uppercase()` extension függvényt.
- Használja a `.filter()` extension függvényt a `medals` változón.
- Átad egy lambda kifejezést predikátumként a `.filter()` függvénynek, amely a `medals` változóra hivatkozik az `it` kulcsszó segítségével, és ellenőrzi, hogy a listában lévő elem több mint 4 karakterből áll-e.
- Használja a `.reversed()` extension függvényt a `medals` változón.
- Hozzárendeli az eredményt a `reversedLongUpperCaseMedals` változóhoz.
- Kiírja a `reversedLongUpperCaseMedals` változóban található listát.

Hasznos lenne némi naplózást hozzáadni a függvényhívások közé, hogy lássuk, mi történik a `medals` változóval. Az `also` függvény ebben segít:

```
fun main() {
    val medals: List<String> = listOf("Gold", "Silver", "Bronze")
    val reversedLongUppercaseMedals: List<String> = medals
        .map { it.uppercase() }
        .also { println(it) } // [GOLD, SILVER, BRONZE]
        .filter { it.length > 4 }
        .also { println(it) } // [SILVER, BRONZE]
        .reversed()
    println(reversedLongUppercaseMedals) // [BRONZE, SILVER]
}
```

Most a példa:
- Használja az `also` scope függvényt a `medals` változón.
- Létrehoz egy ideiglenes scope-ot az `also` scope függvényen belül, így nem kell kifejezetten hivatkoznod a `medals` változóra, amikor függvényparaméterként használod.
- Átad egy lambda kifejezést az `also` scope függvénynek, amely meghívja a `println()` függvényt a `medals` változó használatával függvényparaméterként az `it` kulcsszó segítségével.

Mivel az `also` függvény visszaadja az objektumot, hasznos nemcsak naplózáshoz, hanem hibakereséshez, több művelet láncolásához és egyéb mellékhatás-műveletek végrehajtásához, amelyek nem befolyásolják a kódod fő folyamatát.

### With

A többi scope függvénnyel ellentétben a `with` nem extension függvény, így a szintaxis más. A receiver objektumot argumentumként adod át a `with` függvénynek. Használd a `with` scope függvényt, amikor több függvényt szeretnél meghívni egy objektumon.

Vegyük ezt a példát:

```
class Canvas {
    fun rect(x: Int, y: Int, w: Int, h: Int): Unit = println("$x, $y, $w, $h")
    fun circ(x: Int, y: Int, rad: Int): Unit = println("$x, $y, $rad")
    fun text(x: Int, y: Int, str: String): Unit = println("$x, $y, $str")
}

fun main() {
    val mainMonitorPrimaryBufferBackedCanvas = Canvas()
    mainMonitorPrimaryBufferBackedCanvas.text(10, 10, "Foo")
    mainMonitorPrimaryBufferBackedCanvas.rect(20, 30, 100, 50)
    mainMonitorPrimaryBufferBackedCanvas.circ(40, 60, 25)
    mainMonitorPrimaryBufferBackedCanvas.text(15, 45, "Hello")
    mainMonitorPrimaryBufferBackedCanvas.rect(70, 80, 150, 100)
    mainMonitorPrimaryBufferBackedCanvas.circ(90, 110, 40)
    mainMonitorPrimaryBufferBackedCanvas.text(35, 55, "World")
    mainMonitorPrimaryBufferBackedCanvas.rect(120, 140, 200, 75)
    mainMonitorPrimaryBufferBackedCanvas.circ(160, 180, 55)
    mainMonitorPrimaryBufferBackedCanvas.text(50, 70, "Kotlin")
}
```

A példa létrehoz egy `Canvas` osztályt, amely három tagfüggvénnyel rendelkezik: `rect()`, `circ()`, és `text()`. Minden tagfüggvény kiír egy állítást, amelyet a függvényparaméterekből épít fel.

A példa létrehozza a `mainMonitorPrimaryBufferBackedCanvas` változót a `Canvas` osztály egy példányaként, mielőtt meghívna egy sor tagfüggvényt a példányon különböző függvényparaméterekkel.

Láthatod, hogy ez a kód nehezen olvasható. Ha a `with` függvényt használod, a kód egyszerűsödik:

```
class Canvas {
    fun rect(x: Int, y: Int, w: Int, h: Int): Unit = println("$x, $y, $w, $h")
    fun circ(x: Int, y: Int, rad: Int): Unit = println("$x, $y, $rad")
    fun text(x: Int, y: Int, str: String): Unit = println("$x, $y, $str")
}

fun main() {
    val mainMonitorSecondaryBufferBackedCanvas = Canvas()
    with(mainMonitorSecondaryBufferBackedCanvas) {
        text(10, 10, "Foo")
        rect(20, 30, 100, 50)
        circ(40, 60, 25)
        text(15, 45, "Hello")
        rect(70, 80, 150, 100)
        circ(90, 110, 40)
        text(35, 55, "World")
        rect(120, 140, 200, 75)
        circ(160, 180, 55)
        text(50, 70, "Kotlin")
    }
}
```

Ez a példa:
- Használja a `with` scope függvényt a `mainMonitorSecondaryBufferBackedCanvas` példánnyal mint receiver.
- Létrehoz egy ideiglenes scope-ot a `with` scope függvényen belül, így nem kell kifejezetten hivatkoznod a `mainMonitorSecondaryBufferBackedCanvas` példányra annak tagfüggvényeinek meghívásakor.
- Átad egy lambda kifejezést a `with` scope függvénynek, amely meghív egy sor tagfüggvényt különböző függvényparaméterekkel.

Most, hogy ez a kód sokkal könnyebben olvasható, kevesebb eséllyel követsz el hibákat.

## Használati eset áttekintés

Ez a szakasz a Kotlinban elérhető különböző scope függvényeket és főbb használati eseteiket ismertette, hogy a kódod idiomatikusabbá váljon.

Ezt a táblázatot gyors referenciaként használhatod. Fontos megjegyezni, hogy nem szükséges teljes mértékben megértened, hogyan működnek ezek a függvények, hogy használhasd őket a kódodban.

| Függvény | Hozzáférés x-hez | Visszatérési érték | Használati eset                                              |
| -------- | ---------------- | ------------------ | ------------------------------------------------------------ |
| `let`    | `it`             | Lambda eredménye   | Null ellenőrzések végrehajtása a kódodban, majd további műveletek végrehajtása a visszaadott objektummal |
| `apply`  | `this`           | x                  | Objektumok inicializálása a létrehozás időpontjában          |
| `run`    | `this`           | Lambda eredménye   | Objektumok inicializálása a létrehozás időpontjában ÉS eredmény kiszámítása |
| `also`   | `it`             | x                  | További műveletek végrehajtása az objektum visszaadása előtt |
| `with`   | `this`           | Lambda eredménye   | Több függvény meghívása egy objektumon                       |

További információ a scope függvényekről: Scope függvények.

## Gyakorlás

### Feladat 1

Írd át a `.getPriceInEuros()` függvényt egy egysoros függvénnyé, amely biztonságos hívás operátorokat `?.` és a `let` scope függvényt használ.

**Tipp:** Használj biztonságos hívás operátorokat `?.` a `priceInDollars` tulajdonság biztonságos eléréséhez a `getProductInfo()` függvényből. Ezután használd a `let` scope függvényt a `priceInDollars` értékének euróra való átváltásához.

```
data class ProductInfo(val priceInDollars: Double?)

class Product {
    fun getProductInfo(): ProductInfo? {
        return ProductInfo(100.0)
    }
}

// Rewrite this function || Írd át ezt a függvényt
fun Product.getPriceInEuros(): Double? {
    val info = getProductInfo()
    if (info == null) return null
    val price = info.priceInDollars
    if (price == null) return null
    return convertToEuros(price)
}

fun convertToEuros(dollars: Double): Double {
    return dollars * 0.85
}

fun main() {
    val product = Product()
    val priceInEuros = product.getPriceInEuros()
    if (priceInEuros != null) {
        println("Price in Euros: €$priceInEuros") // Price in Euros: €85.0
    } else {
        println("Price information is not available.")
    }
}
```

### Megoldás
```
data class ProductInfo(val priceInDollars: Double?)

class Product {
    fun getProductInfo(): ProductInfo? {
        return ProductInfo(100.0)
    }
}

fun Product.getPriceInEuros() = getProductInfo()?.priceInDollars?.let { convertToEuros(it) }

fun convertToEuros(dollars: Double): Double {
    return dollars * 0.85
}

fun main() {
    val product = Product()
    val priceInEuros = product.getPriceInEuros()
    if (priceInEuros != null) {
        println("Price in Euros: €$priceInEuros") // Price in Euros: €85.0
    } else {
        println("Price information is not available.")
    }
}
```

### Feladat 2

Van egy `updateEmail()` függvényed, amely frissíti egy felhasználó e-mail címét. Használd az `apply` scope függvényt az e-mail cím frissítéséhez, majd az `also` scope függvényt egy naplóüzenet kiírásához: `Updating email for user with ID: ${it.id}.`

```
data class User(val id: Int, var email: String)

fun updateEmail(user: User, newEmail: String): User = // Write your code here || Írd ide a kódodat

fun main() {
    val user = User(1, "old_email@example.com")
    val updatedUser = updateEmail(user, "new_email@example.com")
    // Updating email for user with ID: 1
    println("Updated User: $updatedUser") // Updated User: User(id=1, email=new_email@example.com)
}
```

### Megoldás
```
data class User(val id: Int, var email: String)

fun updateEmail(user: User, newEmail: String): User = user.apply { 
    this.email = newEmail 
}.also { 
    println("Updating email for user with ID: ${it.id}") 
}

fun main() {
    val user = User(1, "old_email@example.com")
    val updatedUser = updateEmail(user, "new_email@example.com")
    // Updating email for user with ID: 1
    println("Updated User: $updatedUser") // Updated User: User(id=1, email=new_email@example.com)
}
```

## Következő lépés

## Középhaladó: Lambda kifejezések fogadóval

Ebben a fejezetben megtanulod, hogyan használj fogadókat egy másik függvénytípussal, a lambda kifejezésekkel, és hogyan segíthetnek domain-specifikus nyelv létrehozásában.

## Lambda kifejezések fogadóval

A kezdő túrán megtanultad, hogyan használj lambda kifejezéseket. A lambda kifejezéseknek lehet fogadójuk is. Ebben az esetben a lambda kifejezések hozzáférhetnek a fogadó bármely tagfüggvényéhez vagy tulajdonságához anélkül, hogy minden alkalommal kifejezetten meg kellene adni a fogadót.

Ezek nélkül a további hivatkozások nélkül a kódod könnyebben olvasható és karbantartható. A fogadóval rendelkező lambda kifejezéseket függvénnyelágként fogadóval is ismerik.

A fogadóval rendelkező lambda kifejezés szintaxisa más, amikor definiálod a függvénytípust. Először írd meg azt a fogadót, amelyet ki szeretnél terjeszteni. Ezután tegyél egy `.` jelet, majd fejezd be a függvénytípus-definíció többi részét.

Például:

```
MutableList<Int>.() -> Unit
```

Ez a függvénytípus a következőket tartalmazza:
- `MutableList<Int>` mint fogadó.
- Nincsenek függvényparaméterek a zárójelek `()` között.
- Nincs visszatérési érték: `Unit`.

Vegyük ezt a példát, amely alakzatokat rajzol egy vászonra:

```
class Canvas {
    fun drawCircle() = println(" Drawing a circle")
    fun drawSquare() = println(" Drawing a square")
}

// Lambda expression with receiver definition || Lambda kifejezés fogadóval definíció
fun render(block: Canvas.() -> Unit): Canvas {
    val canvas = Canvas()
    // Use the lambda expression with receiver || Használd a lambda kifejezést fogadóval
    canvas.block()
    return canvas
}

fun main() {
    render {
        drawCircle()  // Drawing a circle
        drawSquare()  // Drawing a square
    }
}
```

Ebben a példában:
- A `Canvas` osztálynak két függvénye van, amelyek szimulálják egy kör vagy négyzet rajzolását.
- A `render()` függvény egy `block` paramétert vesz át, és visszaadja a `Canvas` osztály egy példányát.
- A `block` paraméter egy fogadóval rendelkező lambda kifejezés, ahol a `Canvas` osztály a fogadó.
- A `render()` függvény létrehoz egy `Canvas` osztály példányát, és meghívja a `block()` lambda kifejezést a vászon példányon, fogadóként használva.
- A `main()` függvény meghívja a `render()` függvényt egy lambda kifejezéssel, amely átadásra kerül a `block` paraméternek.
- A `render()` függvényhez átadott lambda kifejezésen belül a program meghívja a `drawCircle()` és `drawSquare()` függvényeket a `Canvas` osztály egy példányán.
- Mivel a `drawCircle()` és `drawSquare()` függvényeket fogadóval rendelkező lambda kifejezésben hívják meg, közvetlenül hívhatók meg, mintha a `Canvas` osztályon belül lennének.

A fogadóval rendelkező lambda kifejezések hasznosak, amikor domain-specifikus nyelvet (DSL) szeretnél létrehozni. Mivel hozzáférhetsz a fogadó tagfüggvényeihez és tulajdonságaihoz anélkül, hogy kifejezetten hivatkoznál a fogadóra, a kódod egyszerűbbé válik.

A bemutatáshoz vegyünk egy példát, amely menüelemeket konfigurál. Kezdjük egy `MenuItem` osztállyal és egy `Menu` osztállyal, amely tartalmaz egy függvényt a menühöz való elemek hozzáadásához `item()` néven, valamint az összes menüelem listáját `items`:

```
class MenuItem(val name: String)

class Menu(val name: String) {
    val items = mutableListOf<MenuItem>()
    
    fun item(name: String) {
        items.add(MenuItem(name))
    }
}
```

Használjunk egy fogadóval rendelkező lambda kifejezést, amely függvényparaméterként kerül átadásra (`init`) a `menu()` függvénynek, amely menüt épít:

```
fun menu(name: String, init: Menu.() -> Unit): Menu {
    // Creates an instance of the Menu class || Létrehoz egy Menu osztály példányt
    val menu = Menu(name)
    // Calls the lambda expression with receiver init() on the class instance || Meghívja a lambda kifejezést fogadóval init() a osztálypéldányon
    menu.init()
    return menu
}
```

Most használhatod a DSL-t egy menü konfigurálásához, és létrehozhatsz egy `printMenu()` függvényt a menüstruktúra konzolra való kiírásához:

```
class MenuItem(val name: String)

class Menu(val name: String) {
    val items = mutableListOf<MenuItem>()
    
    fun item(name: String) {
        items.add(MenuItem(name))
    }
}

fun menu(name: String, init: Menu.() -> Unit): Menu {
    val menu = Menu(name)
    menu.init()
    return menu
}

fun printMenu(menu: Menu) {
    println("Menu: ${menu.name}")
    menu.items.forEach { println(" Item: ${it.name}") }
}

// Use the DSL || Használd a DSL-t
fun main() {
    // Create the menu || Hozd létre a menüt
    val mainMenu = menu("Main Menu") {
        // Add items to the menu || Adj hozzá elemeket a menühöz
        item("Home")
        item("Settings")
        item("Exit")
    }
    
    // Print the menu || Írd ki a menüt
    printMenu(mainMenu)
    // Menu: Main Menu
    // Item: Home
    // Item: Settings
    // Item: Exit
}
```

Ahogy látod, a fogadóval rendelkező lambda kifejezés használata nagymértékben egyszerűsíti a menü létrehozásához szükséges kódot.

A lambda kifejezések nemcsak beállításhoz és létrehozáshoz hasznosak, hanem konfigurációhoz is. Gyakran használják őket DSL-ek építéséhez API-khoz, UI keretrendszerekhez és konfigurációs építőkhöz, hogy egyszerűsített kódot állítsanak elő, lehetővé téve, hogy könnyebben összpontosíthass a mögöttes kódstruktúrára és logikára.

A Kotlin ökoszisztémájában sok példa van erre a tervezési mintára, például a standard könyvtár `buildList()` és `buildString()` függvényeiben.

A fogadóval rendelkező lambda kifejezések kombinálhatók a Kotlin típusbiztos építőivel, hogy olyan DSL-eket hozzanak létre, amelyek bármilyen típusproblémát fordítási időben észlelnek, nem futási időben.

További információért lásd: Típusbiztos építők.

## Gyakorlás

### Feladat 1

Van egy `fetchData()` függvényed, amely fogadóval rendelkező lambda kifejezést fogad. Frissítsd a lambda kifejezést az `append()` függvény használatával, hogy a kódod kimenete legyen: `Data received - Processed.`

```
fun fetchData(callback: StringBuilder.() -> Unit) {
    val builder = StringBuilder("Data received")
    builder.callback()
}

fun main() {
    fetchData {
        // Write your code here || Írd ide a kódodat
        // Data received - Processed
    }
}
```

### Megoldás
```
fun fetchData(callback: StringBuilder.() -> Unit) {
    val builder = StringBuilder("Data received")
    builder.callback()
}

fun main() {
    fetchData {
        append(" - Processed")
        println(this.toString()) // Data received - Processed
    }
}
```

### Feladat 2

Van egy `Button` osztályod és `ButtonEvent` valamint `Position` adatosztályaid. Írj kódot, amely elindítja a `Button` osztály `onEvent()` tagfüggvényét egy dupla kattintás esemény kiváltásához. A kódodnak ki kell írnia: `Double click!`

```
class Button {
    fun onEvent(action: ButtonEvent.() -> Unit) {
        // Simulate a double-click event (not a right-click) || Szimulál egy dupla kattintás eseményt (nem jobb kattintást)
        val event = ButtonEvent(isRightClick = false, amount = 2, position = Position(100, 200))
        event.action() // Trigger the event callback || Elindítja az esemény visszahívást
    }
}

data class ButtonEvent(
    val isRightClick: Boolean,
    val amount: Int,
    val position: Position
)

data class Position(
    val x: Int,
    val y: Int
)

fun main() {
    val button = Button()
    button.onEvent {
        // Write your code here || Írd ide a kódodat
        // Double click!
    }
}
```

### Megoldás
```
class Button {
    fun onEvent(action: ButtonEvent.() -> Unit) {
        // Simulate a double-click event (not a right-click) || Szimulál egy dupla kattintás eseményt (nem jobb kattintást)
        val event = ButtonEvent(isRightClick = false, amount = 2, position = Position(100, 200))
        event.action() // Trigger the event callback || Elindítja az esemény visszahívást
    }
}

data class ButtonEvent(
    val isRightClick: Boolean,
    val amount: Int,
    val position: Position
)

data class Position(
    val x: Int,
    val y: Int
)

fun main() {
    val button = Button()
    button.onEvent {
        if (!isRightClick && amount == 2) {
            println("Double click!") // Double click!
        }
    }
}
```

### Feladat 3

Írj egy függvényt, amely létrehoz egy egész számok listájának másolatát, ahol minden elem 1-gyel növekedett. Használd a megadott függvényvázlatot, amely kiterjeszti a `List<Int>` típust egy `incremented` függvénnyel.

```
fun List<Int>.incremented(): List<Int> {
    val originalList = this
    return buildList {
        // Write your code here || Írd ide a kódodat
    }
}

fun main() {
    val originalList = listOf(1, 2, 3)
    val newList = originalList.incremented()
    println(newList) // [2, 3, 4]
}
```

### Megoldás
```
fun List<Int>.incremented(): List<Int> {
    val originalList = this
    return buildList {
        for (n in originalList) add(n + 1)
    }
}

fun main() {
    val originalList = listOf(1, 2, 3)
    val newList = originalList.incremented()
    println(newList) // [2, 3, 4]
}
```

## Következő lépés

## Középhaladó: Osztályok és interfészek

A kezdő túrán megtanultad, hogyan használj osztályokat és adatosztályokat az adatok tárolására és a jellemzők gyűjteményének megosztására a kódodban. Végül hierarchiát szeretnél létrehozni a kódod hatékony megosztásához a projektjeidben. Ez a fejezet elmagyarázza a Kotlin által biztosított lehetőségeket a kód megosztására, és hogyan tehetik a kódodat biztonságosabbá és karbantarthatóbbá.

## Osztályöröklődés

Egy korábbi fejezetben lefedtük, hogyan használhatsz extension függvényeket osztályok kiterjesztésére az eredeti forráskód módosítása nélkül. De mi van, ha olyan összetett dolgon dolgozol, ahol az osztályok közötti kód megosztása hasznos lenne?

Ilyen esetekben használhatod az osztályöröklődést. Alapértelmezés szerint a Kotlin osztályok nem örökölhetők. A Kotlin így van kialakítva, hogy megelőzze a nem szándékolt öröklődést, és könnyebben karbantarthatóvá tegye az osztályokat.

A Kotlin osztályok csak egyszeres öröklődést támogatnak, ami azt jelenti, hogy egyszerre csak egy osztályból lehet örökölni. Ezt az osztályt szülőnek nevezzük. Egy osztály szülője egy másik osztályból örököl (a nagyszülő), így hierarchiát alkotva.

A Kotlin osztályhierarchiájának tetején van a közös szülőosztály: `Any`. Minden osztály végül az `Any` osztályból örököl:

Példa az osztályhierarchiára `Any` típussal

Az `Any` osztály automatikusan biztosítja a `toString()` függvényt tagfüggvényként. Ezért használhatod ezt az örökölt függvényt bármely osztályodban.

Például:

```
class Car(val make: String, val model: String, val numberOfDoors: Int)

fun main() {
    val car1 = Car("Toyota", "Corolla", 4)
    // Uses the .toString() function via string templates to print class properties || Használja a .toString() függvényt string sablonokon keresztül az osztálytulajdonságok kiírásához
    println("Car1: make=${car1.make}, model=${car1.model}, numberOfDoors=${car1.numberOfDoors}")
    // Car1: make=Toyota, model=Corolla, numberOfDoors=4
}
```

Ha öröklődést szeretnél használni a kód megosztásához az osztályok között, először fontold meg az absztrakt osztályok használatát.

## Absztrakt osztályok

Az absztrakt osztályok alapértelmezés szerint örökölhetők. Az absztrakt osztályok célja az, hogy tagokat biztosítsanak, amelyeket más osztályok örökölnek vagy implementálnak. Ennek eredményeként van konstruktoruk, de nem hozhatsz létre belőlük példányokat.

A gyermekosztályon belül a szülő tulajdonságainak és függvényeinek viselkedését az `override` kulcsszóval határozod meg. Így azt mondhatod, hogy a gyermekosztály "felülírja" a szülő tagjait.

Amikor meghatározod egy örökölt függvény vagy tulajdonság viselkedését, azt implementációnak nevezzük.

Az absztrakt osztályok tartalmazhatnak implementációval és anélkül függvényeket és tulajdonságokat is, amelyeket absztrakt függvényeknek és tulajdonságoknak nevezünk.

Egy absztrakt osztály létrehozásához használd az `abstract` kulcsszót:

```
abstract class Animal
```

Egy függvény vagy tulajdonság deklarálásához implementáció nélkül szintén az `abstract` kulcsszót használd:

```
abstract fun makeSound()
abstract val sound: String
```

Például, tegyük fel, hogy létre szeretnél hozni egy `Product` nevű absztrakt osztályt, amelyből gyermekosztályokat hozhatsz létre különböző termékkategóriák definiálásához:

```
abstract class Product(val name: String, var price: Double) {
    // Abstract property for the product category || Absztrakt tulajdonság a termékkategóriához
    abstract val category: String
    
    // A function that can be shared by all products || Egy függvény, amelyet minden termék megoszthat
    fun productInfo(): String {
        return "Product: $name, Category: $category, Price: $price"
    }
}
```

Az absztrakt osztályban:
- A konstruktornak két paramétere van a termék nevéhez és árához.
- Van egy absztrakt tulajdonság, amely tartalmazza a termékkategóriát karakterláncként.
- Van egy függvény, amely információkat nyomtat ki a termékről.

Hozzunk létre egy gyermekosztályt az elektronikához. Mielőtt definiálnád a kategória tulajdonság implementációját a gyermekosztályban, az `override` kulcsszót kell használnod:

```
class Electronic(name: String, price: Double, val warranty: Int) : Product(name, price) {
    override val category = "Electronic"
}
```

Az `Electronic` osztály:
- Az `Product` absztrakt osztályból örököl.
- További paramétere van a konstruktorban: `warranty`, amely az elektronikára jellemző.
- Felülírja a `category` tulajdonságot, hogy tartalmazza az "Electronic" karakterláncot.

Most így használhatod ezeket az osztályokat:

```
abstract class Product(val name: String, var price: Double) {
    // Abstract property for the product category || Absztrakt tulajdonság a termékkategóriához
    abstract val category: String
    
    // A function that can be shared by all products || Egy függvény, amelyet minden termék megoszthat
    fun productInfo(): String {
        return "Product: $name, Category: $category, Price: $price"
    }
}

class Electronic(name: String, price: Double, val warranty: Int) : Product(name, price) {
    override val category = "Electronic"
}

fun main() {
    // Creates an instance of the Electronic class || Létrehoz egy Electronic osztály példányt
    val laptop = Electronic(name = "Laptop", price = 1000.0, warranty = 2)
    println(laptop.productInfo()) // Product: Laptop, Category: Electronic, Price: 1000.0
}
```

Bár az absztrakt osztályok nagyszerűek a kód ilyen módon való megosztásához, korlátozottak, mert a Kotlin osztályok csak egyszeres öröklődést támogatnak. Ha több forrásból kell örökölnöd, fontold meg az interfészek használatát.

## Interfészek

Az interfészek hasonlók az osztályokhoz, de van néhány különbség:
- Nem hozhatsz létre interfészből példányt.
- Nincs konstruktoruk vagy fejlécük.
- Függvényeik és tulajdonságaik alapértelmezés szerint implicit módon örökölhetők.
- A Kotlinban azt mondjuk, hogy "nyitottak" (open).

Nem kell megjelölnöd a függvényeiket absztraktként, ha nem adsz nekik implementációt.

Hasonlóan az absztrakt osztályokhoz, az interfészek használatával függvények és tulajdonságok halmazát határozhatod meg, amelyeket az osztályok később örökölhetnek és implementálhatnak. Ez a megközelítés segít a felület által leírt absztrakcióra összpontosítani, nem pedig a konkrét implementációs részletekre.

Az interfészek használata a kódodat:
- Modulárisabbá teszi, mivel elkülöníti a különböző részeket, lehetővé téve számukra a független fejlődést.
- Könnyebben érthetővé teszi, mivel a kapcsolódó függvényeket egy kohéziós halmazba csoportosítja.
- Könnyebben tesztelhetővé teszi, mivel gyorsan lecserélheted az implementációt egy mock-ra teszteléshez.

Egy interfész deklarálásához használd az `interface` kulcsszót:

```
interface PaymentMethod
```

## Interfész implementáció

Az interfészek támogatják a többszörös öröklődést, így egy osztály egyszerre több interfészt is implementálhat. Először vegyük a forgatókönyvet, ahol egy osztály egy interfészt implementál. Egy osztály létrehozásához, amely implementál egy interfészt, adj hozzá egy kettőspontot az osztályfejléc után, majd az interfész nevét, amelyet implementálni szeretnél. Ne használj zárójeleket `()` az interfész neve után, mert az interfészeknek nincs konstruktoruk:

```
class CreditCardPayment : PaymentMethod
```

Például:

```
interface PaymentMethod {
    // Functions are inheritable by default || A függvények alapértelmezés szerint örökölhetők
    fun initiatePayment(amount: Double): String
}

class CreditCardPayment(val cardNumber: String, val cardHolderName: String, val expiryDate: String) : PaymentMethod {
    override fun initiatePayment(amount: Double): String {
        // Simulate processing payment with credit card || Szimulálja a fizetés feldolgozását hitelkártyával
        return "Payment of $$amount initiated using Credit Card ending in ${cardNumber.takeLast(4)}."
    }
}

fun main() {
    val paymentMethod = CreditCardPayment("1234 5678 9012 3456", "John Doe", "12/25")
    println(paymentMethod.initiatePayment(100.0)) // Payment of $100.0 initiated using Credit Card ending in 3456.
}
```

A példában:
- A `PaymentMethod` egy interfész, amelynek van egy `initiatePayment()` függvénye implementáció nélkül.
- A `CreditCardPayment` egy osztály, amely implementálja a `PaymentMethod` interfészt.
- A `CreditCardPayment` osztály felülírja az örökölt `initiatePayment()` függvényt.
- A `paymentMethod` a `CreditCardPayment` osztály egy példánya.
- Az örökölt `initiatePayment()` függvény meghívásra kerül a `paymentMethod` példányon 100.0 paraméterrel.

Egy osztály létrehozásához, amely több interfészt implementál, adj hozzá egy kettőspontot az osztályfejléc után, majd az interfészek nevét vesszővel elválasztva:

```
class CreditCardPayment : PaymentMethod, PaymentType
```

Például:

```
interface PaymentMethod {
    fun initiatePayment(amount: Double): String
}

interface PaymentType {
    val paymentType: String
}

class CreditCardPayment(val cardNumber: String, val cardHolderName: String, val expiryDate: String) : PaymentMethod, PaymentType {
    override fun initiatePayment(amount: Double): String {
        // Simulate processing payment with credit card || Szimulálja a fizetés feldolgozását hitelkártyával
        return "Payment of $$amount initiated using Credit Card ending in ${cardNumber.takeLast(4)}."
    }
    
    override val paymentType: String = "Credit Card"
}

fun main() {
    val paymentMethod = CreditCardPayment("1234 5678 9012 3456", "John Doe", "12/25")
    println(paymentMethod.initiatePayment(100.0)) // Payment of $100.0 initiated using Credit Card ending in 3456.
    println("Payment is by ${paymentMethod.paymentType}") // Payment is by Credit Card
}
```

A példában:
- A `PaymentMethod` egy interfész, amelynek van egy `initiatePayment()` függvénye implementáció nélkül.
- A `PaymentType` egy interfész, amelynek van egy `paymentType` tulajdonsága, amely nincs inicializálva.
- A `CreditCardPayment` egy osztály, amely implementálja a `PaymentMethod` és `PaymentType` interfészeket.
- A `CreditCardPayment` osztály felülírja az örökölt `initiatePayment()` függvényt és a `paymentType` tulajdonságot.
- A `paymentMethod` a `CreditCardPayment` osztály egy példánya.
- Az örökölt `initiatePayment()` függvény meghívásra kerül a `paymentMethod` példányon 100.0 paraméterrel.
- Az örökölt `paymentType` tulajdonság elérésre kerül a `paymentMethod` példányon.

További információ az interfészekről és interfészöröklődésről: Interfészek.

## Delegálás

Az interfészek hasznosak, de ha az interfészed sok függvényt tartalmaz, a gyermekosztályok végül sok boilerplate kóddal fognak rendelkezni. Ha csak egy osztály viselkedésének kis részét szeretnéd felülírni, sokat kell ismételned.

A boilerplate kód egy kódrészlet, amelyet újrahasznosítanak kis vagy semmilyen módosítással egy szoftverprojekt több részén.

Például, tegyük fel, hogy van egy `DrawingTool` nevű interfészed, amely számos függvényt és egy `color` nevű tulajdonságot tartalmaz:

```
interface DrawingTool {
    val color: String
    fun draw(shape: String)
    fun erase(area: String)
    fun getToolInfo(): String
}
```

Létrehozol egy `PenTool` nevű osztályt, amely implementálja a `DrawingTool` interfészt, és biztosít implementációkat az összes tagjához:

```
class PenTool : DrawingTool {
    override val color: String = "black"
    
    override fun draw(shape: String) {
        println("Drawing $shape using a pen in $color")
    }
    
    override fun erase(area: String) {
        println("Erasing $area with pen tool")
    }
    
    override fun getToolInfo(): String {
        return "PenTool(color=$color)"
    }
}
```

Létre szeretnél hozni egy olyan osztályt, mint a `PenTool`, ugyanazzal a viselkedéssel, de különböző színértékkel. Az egyik megközelítés egy új osztály létrehozása, amely egy `DrawingTool` interfészt implementáló objektumot vár paraméterként, például egy `PenTool` osztály példányt. Ezután az osztályon belül felülírhatod a `color` tulajdonságot. De ebben a forgatókönyvben hozzá kell adnod implementációkat a `DrawingTool` interfész minden tagjához:

```
interface DrawingTool {
    val color: String
    fun draw(shape: String)
    fun erase(area: String)
    fun getToolInfo(): String
}

class PenTool : DrawingTool {
    override val color: String = "black"
    
    override fun draw(shape: String) {
        println("Drawing $shape using a pen in $color")
    }
    
    override fun erase(area: String) {
        println("Erasing $area with pen tool")
    }
    
    override fun getToolInfo(): String {
        return "PenTool(color=$color)"
    }
}

class CanvasSession(val tool: DrawingTool) : DrawingTool {
    override val color: String = "blue"
    
    override fun draw(shape: String) {
        tool.draw(shape)
    }
    
    override fun erase(area: String) {
        tool.erase(area)
    }
    
    override fun getToolInfo(): String {
        return tool.getToolInfo()
    }
}

fun main() {
    val pen = PenTool()
    val session = CanvasSession(pen)
    println("Pen color: ${pen.color}") // Pen color: black
    println("Session color: ${session.color}") // Session color: blue
    session.draw("circle") // Drawing circle with pen in black
    session.erase("top-left corner") // Erasing top-left corner with pen tool
    println(session.getToolInfo()) // PenTool(color=black)
}
```

Láthatod, hogy ha sok tagfüggvényed van a `DrawingTool` interfészben, a `CanvasSession` osztályban lévő boilerplate kód mennyisége nagy lehet. Azonban van egy alternatíva. Kotlinban delegálhatod az interfészimplementációt egy osztálypéldányra a `by` kulcsszó használatával.

Például:

```
class CanvasSession(val tool: DrawingTool) : DrawingTool by tool
```

Itt a `tool` a `PenTool` osztálypéldány neve, ahol a tagfüggvények implementációi delegálva vannak. Most nem kell hozzáadnod implementációkat a `CanvasSession` osztály tagfüggvényeihez. A fordító ezt automatikusan megteszi számodra a `PenTool` osztályból. Ez megkímél a sok boilerplate kód írásától. Ehelyett csak azt a viselkedést kell hozzáadnod, amelyet meg szeretnél változtatni a gyermekosztályod számára.

Például, ha meg szeretnéd változtatni a `color` tulajdonság értékét:

```
interface DrawingTool {
    val color: String
    fun draw(shape: String)
    fun erase(area: String)
    fun getToolInfo(): String
}

class PenTool : DrawingTool {
    override val color: String = "black"
    
    override fun draw(shape: String) {
        println("Drawing $shape using a pen in $color")
    }
    
    override fun erase(area: String) {
        println("Erasing $area with pen tool")
    }
    
    override fun getToolInfo(): String {
        return "PenTool(color=$color)"
    }
}

class CanvasSession(val tool: DrawingTool) : DrawingTool by tool {
    // No boilerplate code! || Nincs boilerplate kód!
    override val color: String = "blue"
}

fun main() {
    val pen = PenTool()
    val session = CanvasSession(pen)
    println("Pen color: ${pen.color}") // Pen color: black
    println("Session color: ${session.color}") // Session color: blue
    session.draw("circle") // Drawing circle with pen in black
    session.erase("top-left corner") // Erasing top-left corner with pen tool
    println(session.getToolInfo()) // PenTool(color=black)
}
```

Ha szeretnéd, felülírhatod egy örökölt tagfüggvény viselkedését a `CanvasSession` osztályban, de most nem kell új sorokat hozzáadnod minden örökölt tagfüggvényhez.

További információ: Delegálás.

## Gyakorlás

### Feladat 1

Képzelj el, hogy egy okos otthon rendszert építesz. Egy okos otthonban általában különböző típusú eszközök vannak, amelyek mindegyike rendelkezik néhány alapvető funkcióval, de egyedi viselkedéssel is.

Az alábbi kódmintában egészítsd ki az `SmartDevice` nevű absztrakt osztályt, hogy a `SmartLight` gyermekosztály sikeresen lefordulhasson. Ezután hozz létre egy másik `SmartThermostat` nevű gyermekosztályt, amely az `SmartDevice` osztályból örököl, és implementálja a `turnOn()` és `turnOff()` függvényeket, amelyek kiírnak állításokat, amelyek leírják, hogy melyik termosztát fűt vagy ki van kapcsolva.

Végül adj hozzá egy másik `adjustTemperature()` nevű függvényt, amely bemenetként egy hőmérséklet-mérést fogad, és kiírja: `$name thermostat set to $temperature°C.`

**Tipp:** Az `SmartDevice` osztályban add hozzá a `turnOn()` és `turnOff()` függvényeket, hogy később felül tudjuk írni őket a `SmartThermostat` osztályban.

```
abstract class // Write your code here || Írd ide a kódodat

class SmartLight(name: String) : SmartDevice(name) {
    override fun turnOn() {
        println("$name is now ON.")
    }
    
    override fun turnOff() {
        println("$name is now OFF.")
    }
    
    fun adjustBrightness(level: Int) {
        println("Adjusting $name brightness to $level%.")
    }
}

class SmartThermostat // Write your code here || Írd ide a kódodat

fun main() {
    val livingRoomLight = SmartLight("Living Room Light")
    val bedroomThermostat = SmartThermostat("Bedroom Thermostat")
    
    livingRoomLight.turnOn() // Living Room Light is now ON.
    livingRoomLight.adjustBrightness(10) // Adjusting Living Room Light brightness to 10%.
    livingRoomLight.turnOff() // Living Room Light is now OFF.
    
    bedroomThermostat.turnOn() // Bedroom Thermostat thermostat is now heating.
    bedroomThermostat.adjustTemperature(5) // Bedroom Thermostat thermostat set to 5°C.
    bedroomThermostat.turnOff() // Bedroom Thermostat thermostat is now off.
}
```

### Megoldás
```
abstract class SmartDevice(val name: String) {
    abstract fun turnOn()
    abstract fun turnOff()
}

class SmartLight(name: String) : SmartDevice(name) {
    override fun turnOn() {
        println("$name is now ON.")
    }
    
    override fun turnOff() {
        println("$name is now OFF.")
    }
    
    fun adjustBrightness(level: Int) {
        println("Adjusting $name brightness to $level%.")
    }
}

class SmartThermostat(name: String) : SmartDevice(name) {
    override fun turnOn() {
        println("$name thermostat is now heating.")
    }
    
    override fun turnOff() {
        println("$name thermostat is now off.")
    }
    
    fun adjustTemperature(temperature: Int) {
        println("$name thermostat set to $temperature°C.")
    }
}

fun main() {
    val livingRoomLight = SmartLight("Living Room Light")
    val bedroomThermostat = SmartThermostat("Bedroom Thermostat")
    
    livingRoomLight.turnOn() // Living Room Light is now ON.
    livingRoomLight.adjustBrightness(10) // Adjusting Living Room Light brightness to 10%.
    livingRoomLight.turnOff() // Living Room Light is now OFF.
    
    bedroomThermostat.turnOn() // Bedroom Thermostat thermostat is now heating.
    bedroomThermostat.adjustTemperature(5) // Bedroom Thermostat thermostat set to 5°C.
    bedroomThermostat.turnOff() // Bedroom Thermostat thermostat is now off.
}
```

### Feladat 2

Hozz létre egy `Media` nevű interfészt, amelyet konkrét médiaosztályok, mint például `Audio`, `Video` vagy `Podcast` implementálásához használhatsz.

Az interfészednek tartalmaznia kell:
- Egy `title` nevű tulajdonságot a média címének megjelenítésére.
- Egy `play()` nevű függvényt a média lejátszásához.

Ezután hozz létre egy `Audio` nevű osztályt, amely implementálja a `Media` interfészt. Az `Audio` osztálynak használnia kell a `title` tulajdonságot a konstruktorában, valamint rendelkeznie kell egy további `composer` nevű tulajdonsággal, amely `String` típusú.

Az osztályban implementáld a `play()` függvényt úgy, hogy kiírja a következőt: `"Playing audio: $title, composed by $composer"`.

**Tipp:** Használhatod az `override` kulcsszót az osztályfejlécekben egy interfész tulajdonság implementálásához a konstruktorban.

```
interface // Write your code here || Írd ide a kódodat

class // Write your code here || Írd ide a kódodat

fun main() {
    val audio = Audio("Symphony No. 5", "Beethoven")
    audio.play() // Playing audio: Symphony No. 5, composed by Beethoven
}
```

### Megoldás
```
interface Media {
    val title: String
    fun play()
}

class Audio(override val title: String, val composer: String) : Media {
    override fun play() {
        println("Playing audio: $title, composed by $composer")
    }
}

fun main() {
    val audio = Audio("Symphony No. 5", "Beethoven")
    audio.play() // Playing audio: Symphony No. 5, composed by Beethoven
}
```

### Feladat 3

Egy e-kereskedelmi alkalmazás fizetésfeldolgozó rendszerét építed. Minden fizetési módnak képesnek kell lennie egy fizetés engedélyezésére és egy tranzakció feldolgozására. Egyes fizetéseknek képeseknek kell lenniük visszatérítések feldolgozására is.

1. A `Refundable` interfészben adj hozzá egy `refund()` nevű függvényt a visszatérítések feldolgozásához.
2. Az `PaymentMethod` absztrakt osztályban:
   - Adj hozzá egy `authorize()` nevű függvényt, amely egy összeget fogad és kiír egy üzenetet, amely tartalmazza az összeget.
   - Adj hozzá egy absztrakt `processPayment()` nevű függvényt, amely szintén egy összeget fogad.
3. Hozz létre egy `CreditCard` nevű osztályt, amely implementálja a `Refundable` interfészt és az `PaymentMethod` absztrakt osztályt. Ebben az osztályban adj hozzá implementációkat a `refund()` és `processPayment()` függvényekhez úgy, hogy kiírják a következő állításokat:
   - `"Refunding $amount to the credit card."`
   - `"Processing credit card payment of $amount."`

```
interface Refundable {
    // Write your code here || Írd ide a kódodat
}

abstract class PaymentMethod(val name: String) {
    // Write your code here || Írd ide a kódodat
}

class CreditCard // Write your code here || Írd ide a kódodat

fun main() {
    val visa = CreditCard("Visa")
    visa.authorize(100.0) // Authorizing payment of $100.0.
    visa.processPayment(100.0) // Processing credit card payment of $100.0.
    visa.refund(50.0) // Refunding $50.0 to the credit card.
}
```

### Megoldás
```
interface Refundable {
    fun refund(amount: Double)
}

abstract class PaymentMethod(val name: String) {
    fun authorize(amount: Double) {
        println("Authorizing payment of $$amount.")
    }
    
    abstract fun processPayment(amount: Double)
}

class CreditCard(name: String) : PaymentMethod(name), Refundable {
    override fun processPayment(amount: Double) {
        println("Processing credit card payment of $$amount.")
    }
    
    override fun refund(amount: Double) {
        println("Refunding $$amount to the credit card.")
    }
}

fun main() {
    val visa = CreditCard("Visa")
    visa.authorize(100.0) // Authorizing payment of $100.0.
    visa.processPayment(100.0) // Processing credit card payment of $100.0.
    visa.refund(50.0) // Refunding $50.0 to the credit card.
}
```
### Feladat 4

Van egy egyszerű üzenetküldő alkalmazásod, amely rendelkezik néhány alapvető funkcionalitással, de szeretnél hozzáadni néhány funkciót az okos üzenetekhez anélkül, hogy jelentősen duplikálnád a kódodat.

Az alábbi kódban definiálj egy `SmartMessenger` nevű osztályt, amely örököl a `Messenger` interfészből, de az implementációt egy `BasicMessenger` osztály példányára delegálja.

A `SmartMessenger` osztályban felülírd a `sendMessage()` függvényt az okos üzenetek küldéséhez. A függvénynek bemenetként el kell fogadnia egy üzenetet, és vissza kell adnia egy kiírt állítást: `"Sending a smart message: $message"`.

Ezenkívül hívd meg a `BasicMessenger` osztály `sendMessage()` függvényét, és az üzenet elé tegyél `[smart]` előtagot. Nem kell újraírnod a `receiveMessage()` függvényt a `SmartMessenger` osztályban.

```
interface Messenger {
    fun sendMessage(message: String)
    fun receiveMessage(): String
}

class BasicMessenger : Messenger {
    override fun sendMessage(message: String) {
        println("Sending message: $message")
    }
    
    override fun receiveMessage(): String {
        return "You've got a new message!"
    }
}

class SmartMessenger // Write your code here || Írd ide a kódodat

fun main() {
    val basicMessenger = BasicMessenger()
    val smartMessenger = SmartMessenger(basicMessenger)
    basicMessenger.sendMessage("Hello!") // Sending message: Hello!
    println(smartMessenger.receiveMessage()) // You've got a new message!
    smartMessenger.sendMessage("Hello from SmartMessenger!") 
    // Sending a smart message: Hello from SmartMessenger!
    // Sending message: [smart] Hello from SmartMessenger!
}
```

### Megoldás
```
interface Messenger {
    fun sendMessage(message: String)
    fun receiveMessage(): String
}

class BasicMessenger : Messenger {
    override fun sendMessage(message: String) {
        println("Sending message: $message")
    }
    
    override fun receiveMessage(): String {
        return "You've got a new message!"
    }
}

class SmartMessenger(val basicMessenger: BasicMessenger) : Messenger by basicMessenger {
    override fun sendMessage(message: String) {
        println("Sending a smart message: $message")
        basicMessenger.sendMessage("[smart] $message")
    }
}

fun main() {
    val basicMessenger = BasicMessenger()
    val smartMessenger = SmartMessenger(basicMessenger)
    basicMessenger.sendMessage("Hello!") // Sending message: Hello!
    println(smartMessenger.receiveMessage()) // You've got a new message!
    smartMessenger.sendMessage("Hello from SmartMessenger!") 
    // Sending a smart message: Hello from SmartMessenger!
    // Sending message: [smart] Hello from SmartMessenger!
}
```

## Következő lépés

## Középhaladó: Objektumok

## Középhaladó: Objektumok

Ebben a fejezetben bővíted az osztályokkal kapcsolatos ismereteidet az objektumdeklarációk felfedezésével. Ez a tudás segít a viselkedés hatékony kezelésében a projektjeidben.

## Objektumdeklarációk

A Kotlinban objektumdeklarációk segítségével deklarálhatsz egy osztályt egyetlen példánnyal. Egy értelemben egyszerre deklarálod az osztályt és létrehozod az egyetlen példányt.

Az objektumdeklarációk hasznosak, amikor létre szeretnél hozni egy osztályt, amelyet egyetlen referenciapontként használhatsz a programodban, vagy a viselkedés koordinálásához egy rendszeren belül.

Egy osztályt, amelynek csak egy példánya van, amely könnyen elérhető, szingletennek nevezünk. A Kotlin objektumok lusták, ami azt jelenti, hogy csak akkor jönnek létre, amikor hozzáférnek hozzájuk. A Kotlin azt is biztosítja, hogy minden objektum szálbiztos módon jön létre, így nem kell ezt manuálisan ellenőrizned.

Egy objektumdeklaráció létrehozásához használd az `object` kulcsszót:

```
object DoAuth {}
```

Az objektum neve után add meg bármely tulajdonságot vagy tagfüggvényt az objektumtörzsben, amelyet kapcsos zárójelek `{}` határoznak meg. Az objektumoknak nem lehetnek konstruktoraik, így nincsenek fejlécük, mint az osztályoknak.

Például, tegyük fel, hogy létre szeretnél hozni egy `DoAuth` nevű objektumot, amely felelős az authentikációért:

```
object DoAuth {
    fun takeParams(username: String, password: String) {
        println("input Auth parameters = $username:$password")
    }
}

fun main(){
    // Az objektum akkor jön létre, amikor a takeParams() függvényt meghívják
    DoAuth.takeParams("coding_ninja", "N1njaC0ding!") 
    // input Auth parameters = coding_ninja:N1njaC0ding!
}
```

Az objektumnak van egy `takeParams` nevű tagfüggvénye, amely felhasználónév és jelszó változókat fogad paraméterként, és kiír egy karakterláncot a konzolra. A `DoAuth` objektum csak akkor jön létre, amikor a függvényt először meghívják.

Az objektumok örökölhetnek osztályokból és interfészekből. Például:

```
interface Auth {
    fun takeParams(username: String, password: String)
}

object DoAuth : Auth {
    override fun takeParams(username: String, password: String) {
        println("input Auth parameters = $username:$password")
    }
}
```

## Adatobjektumok

Ahhoz, hogy könnyebb legyen kinyomtatni egy objektumdeklaráció tartalmát, a Kotlin rendelkezik adatobjektumokkal. Hasonlóan az adatosztályokhoz, amelyekről a kezdő túrán tanultál, az adatobjektumok automatikusan rendelkeznek további tagfüggvényekkel: `toString()` és `equals()`. 

Az adatosztályokkal ellentétben az adatobjektumok nem rendelkeznek automatikusan a `copy()` tagfüggvénnyel, mert csak egyetlen példányuk van, amelyet nem lehet másolni.

Egy adatobjektum létrehozásához használd ugyanazt a szintaxist, mint az objektumdeklarációk esetén, de előtagként add meg a `data` kulcsszót:

```
data object AppConfig {}
```

Például:

```
data object AppConfig {
    var appName: String = "My Application"
    var version: String = "1.0.0"
}

fun main() {
    println(AppConfig) // AppConfig
    println(AppConfig.appName) // My Application
}
```

További információ az adatobjektumokról: Adatobjektumok.

## Társosztályok (Companion objects)

A Kotlinban egy osztálynak lehet egy objektuma: egy társosztály. Egy osztályban csak egy társosztály lehet. A társosztály csak akkor jön létre, amikor az osztályra először hivatkoznak. A társosztályon belül deklarált bármely tulajdonság vagy függvény az összes osztálypéldány között megosztott.

Egy társosztály létrehozásához egy osztályon belül használd ugyanazt a szintaxist, mint az objektumdeklaráció esetén, de előtagként add meg a `companion` kulcsszót:

```
companion object Bonger {}
```

A társosztálynak nem kell nevet adni. Ha nem definiálsz egyet, az alapértelmezett a `Companion`. A társosztály bármely tulajdonságához vagy függvényéhez való hozzáféréshez hivatkozz az osztály nevére.

Például:

```
class BigBen {
    companion object Bonger {
        fun getBongs(nTimes: Int) {
            repeat(nTimes) {
                print("BONG ")
            }
        }
    }
}

fun main() {
    // A társosztály akkor jön létre, amikor az osztályra először hivatkoznak
    BigBen.getBongs(12) 
    // BONG BONG BONG BONG BONG BONG BONG BONG BONG BONG BONG BONG
}
```

Ez a példa létrehoz egy `BigBen` nevű osztályt, amely tartalmaz egy `Bonger` nevű társosztályt. A társosztálynak van egy `getBongs()` nevű tagfüggvénye, amely egy egész számot fogad, és ugyanannyiszor nyomtat ki "BONG"-ot a konzolra, mint az egész szám.

A `main()` függvényben a `getBongs()` függvényt az osztály nevére hivatkozva hívják meg. Ezen a ponton jön létre a társosztály. A `getBongs()` függvényt 12 paraméterrel hívják meg.

További információ: Társosztályok.

## Gyakorlás

### Feladat 1

Egy kávézó vezetésével bízol meg, és van egy rendszered az ügyfélrendelések nyomon követésére. Vedd figyelembe az alábbi kódot, és egészítsd ki a második adatobjektum deklarációját úgy, hogy a `main()` függvényben lévő következő kód sikeresen fusson:

```
interface Order {
    val orderId: String
    val customerName: String
    val orderTotal: Double
}

data object OrderOne: Order {
    override val orderId = "001"
    override val customerName = "Alice"
    override val orderTotal = 15.50
}

data object // Write your code here || Írd ide a kódodat

fun main() {
    // Az egyes adatobjektumok nevének kiírása
    println("Order name: $OrderOne") // Order name: OrderOne
    println("Order name: $OrderTwo") // Order name: OrderTwo
    
    // Annak ellenőrzése, hogy a rendelések azonosak-e
    println("Are the two orders identical? ${OrderOne == OrderTwo}") 
    // Are the two orders identical? false
    
    if (OrderOne == OrderTwo) {
        println("The orders are identical.")
    } else {
        println("The orders are unique.") // The orders are unique.
    }
    
    println("Do the orders have the same customer name? ${OrderOne.customerName == OrderTwo.customerName}") 
    // Do the orders have the same customer name? false
}
```

### Megoldás
```
interface Order {
    val orderId: String
    val customerName: String
    val orderTotal: Double
}

data object OrderOne: Order {
    override val orderId = "001"
    override val customerName = "Alice"
    override val orderTotal = 15.50
}

data object OrderTwo: Order {
    override val orderId = "002"
    override val customerName = "Bob"
    override val orderTotal = 12.75
}

fun main() {
    // Az egyes adatobjektumok nevének kiírása
    println("Order name: $OrderOne") // Order name: OrderOne
    println("Order name: $OrderTwo") // Order name: OrderTwo
    
    // Annak ellenőrzése, hogy a rendelések azonosak-e
    println("Are the two orders identical? ${OrderOne == OrderTwo}") 
    // Are the two orders identical? false
    
    if (OrderOne == OrderTwo) {
        println("The orders are identical.")
    } else {
        println("The orders are unique.") // The orders are unique.
    }
    
    println("Do the orders have the same customer name? ${OrderOne.customerName == OrderTwo.customerName}") 
    // Do the orders have the same customer name? false
}
```

### Feladat 2

Hozz létre egy objektumdeklarációt, amely örököl a `Vehicle` interfészből egyedi járműtípus létrehozásához: `FlyingSkateboard`. Implementáld a `name` tulajdonságot és a `move()` függvényt az objektumban úgy, hogy a `main()` függvényben lévő következő kód sikeresen fusson:

```
interface Vehicle {
    val name: String
    fun move(): String
}

object // Write your code here || Írd ide a kódodat

fun main() {
    println("${FlyingSkateboard.name}: ${FlyingSkateboard.move()}") 
    // Flying Skateboard: Glides through the air with a hover engine
    println("${FlyingSkateboard.name}: ${FlyingSkateboard.fly()}") 
    // Flying Skateboard: Woooooooo
}
```

### Megoldás
```
interface Vehicle {
    val name: String
    fun move(): String
}

object FlyingSkateboard : Vehicle {
    override val name = "Flying Skateboard"
    override fun move() = "Glides through the air with a hover engine"
    fun fly(): String = "Woooooooo"
}

fun main() {
    println("${FlyingSkateboard.name}: ${FlyingSkateboard.move()}") 
    // Flying Skateboard: Glides through the air with a hover engine
    println("${FlyingSkateboard.name}: ${FlyingSkateboard.fly()}") 
    // Flying Skateboard: Woooooooo
}
```

### Feladat 3

Van egy alkalmazásod, ahol hőmérsékleteket szeretnél rögzíteni. Az osztály maga tárolja az információkat Celsius-ban, de szeretnél egy könnyű módot biztosítani egy példány létrehozására Fahrenheit-ben is.

Egészítsd ki az adatosztályt úgy, hogy a `main()` függvényben lévő következő kód sikeresen fusson:

**Tipp:** Használj társosztályt.

```
data class Temperature(val celsius: Double) {
    val fahrenheit: Double = celsius * 9 / 5 + 32
    // Write your code here || Írd ide a kódodat
}

fun main() {
    val fahrenheit = 90.0
    val temp = Temperature.fromFahrenheit(fahrenheit)
    println("${temp.celsius}°C is $fahrenheit °F") 
    // 32.22222222222222°C is 90.0 °F
}
```

### Megoldás
```
data class Temperature(val celsius: Double) {
    val fahrenheit: Double = celsius * 9 / 5 + 32
    
    companion object {
        fun fromFahrenheit(fahrenheit: Double): Temperature = Temperature((fahrenheit - 32) * 5 / 9)
    }
}

fun main() {
    val fahrenheit = 90.0
    val temp = Temperature.fromFahrenheit(fahrenheit)
    println("${temp.celsius}°C is $fahrenheit °F") 
    // 32.22222222222222°C is 90.0 °F
}
```

## Következő lépés

## Középhaladó: Nyílt és speciális osztályok

## Középhaladó: Nyílt és speciális osztályok

Ebben a fejezetben megismered a nyílt osztályokat, hogyan működnek az interfészekkel, és a Kotlinban elérhető egyéb speciális típusú osztályokat.

## Nyílt osztályok

Ha nem tudsz interfészeket vagy absztrakt osztályokat használni, kifejezetten megteheted, hogy egy osztályt örökölhetővé teszel azzal, hogy nyíltnak deklarálod. Ehhez használd az `open` kulcsszót az osztálydeklaráció előtt:

```
open class Vehicle(val make: String, val model: String)
```

Egy másik osztályból örökölő osztály létrehozásához adj hozzá egy kettőspontot az osztályfejléc után, majd hívd meg a szülőosztály konstruktorát, amelyből örökölni szeretnél.

Ebben a példában a `Car` osztály örököl a `Vehicle` osztályból:

```
open class Vehicle(val make: String, val model: String)

class Car(make: String, model: String, val numberOfDoors: Int) : Vehicle(make, model)

fun main() {
    // A Car osztály egy példányának létrehozása
    val car = Car("Toyota", "Corolla", 4)
    // Az autó részleteinek kiírása
    println("Car Info: Make - ${car.make}, Model - ${car.model}, Number of doors - ${car.numberOfDoors}") 
    // Car Info: Make - Toyota, Model - Corolla, Number of doors - 4
}
```

Éppúgy, mint egy normál osztály példányának létrehozásakor, ha az osztály örököl egy szülőosztálytól, akkor inicializálnia kell a szülőosztály fejlécében deklarált összes paramétert.

Tehát a példában az `Car` osztály `car` példánya inicializálja a szülőosztály paramétereit: `make` és `model`.

### Örökölt viselkedés felülírása

Ha egy osztályból szeretnél örökölni, de meg szeretnéd változtatni néhány viselkedést, felülírhatod az örökölt viselkedést. Alapértelmezés szerint nem lehetséges felülírni egy szülőosztály tagfüggvényét vagy tulajdonságát.

Éppúgy, mint az absztrakt osztályok esetén, különleges kulcsszavakat kell használnod.

#### Tagfüggvények

Ahhoz, hogy egy szülőosztályban lévő függvény felülírható legyen, használd az `open` kulcsszót a deklaráció előtt a szülőosztályban:

```
open fun displayInfo() {}
```

Egy örökölt tagfüggvény felülírásához használd az `override` kulcsszót a függvénydeklaráció előtt a gyermekosztályban:

```
override fun displayInfo() {}
```

Például:

```
open class Vehicle(val make: String, val model: String) {
    open fun displayInfo() {
        println("Vehicle Info: Make - $make, Model - $model")
    }
}

class Car(make: String, model: String, val numberOfDoors: Int) : Vehicle(make, model) {
    override fun displayInfo() {
        println("Car Info: Make - $make, Model - $model, Number of Doors - $numberOfDoors")
    }
}

fun main() {
    val car1 = Car("Toyota", "Corolla", 4)
    val car2 = Car("Honda", "Civic", 2)
    // A felülírt displayInfo() függvény használata
    car1.displayInfo() 
    // Car Info: Make - Toyota, Model - Corolla, Number of Doors - 4
    car2.displayInfo() 
    // Car Info: Make - Honda, Model - Civic, Number of Doors - 2
}
```

Ez a példa:

- Létrehoz két `Car` osztály példányt, amelyek örökölnek a `Vehicle` osztályból: `car1` és `car2`.
- Felülírja a `displayInfo()` függvényt a `Car` osztályban, hogy kiírja az ajtók számát is.
- Meghívja a felülírt `displayInfo()` függvényt a `car1` és `car2` példányokon.

#### Tulajdonságok

A Kotlinban nem gyakori gyakorlat, hogy egy tulajdonságot örökléssel megnyitani az `open` kulcsszóval, majd később felülírni. A legtöbb esetben absztrakt osztályt vagy interfészt használsz, ahol a tulajdonságok alapértelmezés szerint örökölhetők.

A nyílt osztályokon belüli tulajdonságokhoz a gyermekosztály hozzáfér. Általában jobb közvetlenül hozzáférni hozzájuk, mint felülírni őket egy új tulajdonsággal.

Például, tegyük fel, hogy van egy `transmissionType` nevű tulajdonságod, amelyet később fel szeretnél írni. A tulajdonságok felülírásának szintaxisa pontosan ugyanaz, mint a tagfüggvények felülírásánál. Ezt teheted:

```
open class Vehicle(val make: String, val model: String) {
    open val transmissionType: String = "Manual"
}

class Car(make: String, model: String, val numberOfDoors: Int) : Vehicle(make, model) {
    override val transmissionType: String = "Automatic"
}
```

Azonban ez nem jó gyakorlat. Ehelyett hozzáadhatod a tulajdonságot az örökölhető osztály konstruktorához, és deklarálhatod az értékét, amikor létrehozod a `Car` gyermekosztályt:

```
open class Vehicle(val make: String, val model: String, val transmissionType: String = "Manual")

class Car(make: String, model: String, val numberOfDoors: Int) : Vehicle(make, model, "Automatic")
```

A tulajdonságok közvetlen elérése felülírás helyett egyszerűbbé és olvashatóbbá teszi a kódot. A tulajdonságok egyszeri deklarálásával a szülőosztályban és az értékeik konstruktoron keresztüli átadásával kiküszöböli a szükségtelen felülírások szükségességét a gyermekosztályokban.

További információ az osztályöröklődésről és az osztályviselkedés felülírásáról: Öröklődés.

### Nyílt osztályok és interfészek

Létrehozhatsz egy osztályt, amely örököl egy osztályt és implementál több interfészt is. Ebben az esetben először deklaráld a szülőosztályt a kettőspont után, mielőtt felsorolnád az interfészeket:

```
// Interfészek definiálása
interface EcoFriendly {
    val emissionLevel: String
}

interface ElectricVehicle {
    val batteryCapacity: Double
}

// Szülőosztály
open class Vehicle(val make: String, val model: String)

// Gyermekosztály
open class Car(make: String, model: String, val numberOfDoors: Int) : Vehicle(make, model)

// Új osztály, amely örököl a Car-ból és implementál két interfészt
class ElectricCar(
    make: String, 
    model: String, 
    numberOfDoors: Int, 
    val capacity: Double, 
    val emission: String
) : Car(make, model, numberOfDoors), EcoFriendly, ElectricVehicle {
    override val batteryCapacity: Double = capacity
    override val emissionLevel: String = emission
}
```

## Speciális osztályok

Az absztrakt, nyílt és adatosztályok mellett a Kotlin különleges típusú osztályokkal rendelkezik, amelyek különböző célokra lettek tervezve, például specifikus viselkedés korlátozására vagy a kis objektumok létrehozásának teljesítményhatásának csökkentésére.

### Sealed osztályok

Lehetnek olyan időpontok, amikor korlátozni szeretnéd az öröklődést. Ezt sealed osztályokkal teheted meg. A sealed osztályok egy speciális típusú absztrakt osztályok. Amikor deklarálod, hogy egy osztály sealed, akkor csak ugyanabban a csomagban hozhatsz létre gyermekosztályokat belőle. Nem lehetséges a sealed osztályból való öröklés ezen hatókörön kívül.

Egy csomag egy kapcsolódó osztályokból és függvényekből álló kódgűjtemény, általában egy könyvtáron belül. A Kotlin csomagokkal kapcsolatos további információkért lásd a Csomagok és importok fejezetet.

Egy sealed osztály létrehozásához használd a `sealed` kulcsszót:

```
sealed class Mammal
```

A sealed osztályok különösen hasznosak, amikor `when` kifejezéssel kombinálod őket. `when` kifejezés használatával meghatározhatod a viselkedést minden lehetséges gyermekosztályra.

Például:

```
sealed class Mammal(val name: String)

class Cat(val catName: String) : Mammal(catName)
class Human(val humanName: String, val job: String) : Mammal(humanName)

fun greetMammal(mammal: Mammal): String {
    when (mammal) {
        is Human -> return "Hello ${mammal.name}; You're working as a ${mammal.job}"
        is Cat -> return "Hello ${mammal.name}"
    }
}

fun main() {
    println(greetMammal(Cat("Snowy"))) // Hello Snowy
}
```

A példában:

- Van egy `Mammal` nevű sealed osztály, amelynek van egy `name` paramétere a konstruktorban.
- A `Cat` osztály örököl a `Mammal` sealed osztályból, és a saját konstruktorában a `catName` paramétert használja a `Mammal` osztály `name` paramétereként.
- A `Human` osztály örököl a `Mammal` sealed osztályból, és a saját konstruktorában a `humanName` paramétert használja a `Mammal` osztály `name` paramétereként. Emellett van egy `job` paramétere a konstruktorban.
- A `greetMammal()` függvény egy `Mammal` típusú argumentumot fogad, és egy karakterláncot ad vissza.
- A `greetMammal()` függvénytörzsben van egy `when` kifejezés, amely az `is` operátort használja annak ellenőrzésére, hogy milyen típusú az emlős, és eldönti, melyik műveletet hajtja végre.
- A `main()` függvény meghívja a `greetMammal()` függvényt a `Cat` osztály egy példányával és "Snowy" névparaméterrel.

Ez a túra részletesebben tárgyalja az `is` operátort a Null biztonság fejezetben.

A sealed osztályokkal és ajánlott használati eseteikkel kapcsolatos további információkért lásd: Sealed osztályok és interfészek.

### Enum osztályok

Az enum osztályok hasznosak, amikor véges számú különböző érték halmazát szeretnéd egy osztályban reprezentálni. Egy enum osztály tartalmaz enum konstansokat, amelyek maguk az enum osztály példányai.

Egy enum osztály létrehozásához használd az `enum` kulcsszót:

```
enum class State
```

Tegyük fel, hogy létre szeretnél hozni egy enum osztályt, amely tartalmazza egy folyamat különböző állapotait. Minden enum konstanst vesszővel `,` kell elválasztani:

```
enum class State {
    IDLE,
    RUNNING,
    FINISHED
}
```

A `State` enum osztálynak van enum konstansai: `IDLE`, `RUNNING` és `FINISHED`.

Egy enum konstans eléréséhez használd az osztálynevet, majd egy `.` jelet és az enum konstans nevét:

```
val state = State.RUNNING
```

Használhatod ezt az enum osztályt egy `when` kifejezéssel a végrehajtandó művelet meghatározásához az enum konstans értékétől függően:

```
enum class State {
    IDLE,
    RUNNING,
    FINISHED
}

fun main() {
    val state = State.RUNNING
    val message = when (state) {
        State.IDLE -> "It's idle"
        State.RUNNING -> "It's running"
        State.FINISHED -> "It's finished"
    }
    println(message) // It's running
}
```

Az enum osztályok rendelkezhetnek tulajdonságokkal és tagfüggvényekkel, éppúgy, mint a normál osztályok. Például, tegyük fel, hogy HTML-lel dolgozol, és létre szeretnél hozni egy enum osztályt, amely tartalmaz néhány színt. Szeretnéd, hogy minden színnek legyen egy tulajdonsága, nevezzük `rgb`-nek, amely tartalmazza az RGB értéküket hexadecimális formátumban.

Az enum konstansok létrehozásakor ezzel a tulajdonsággal kell inicializálnod:

```
enum class Color(val rgb: Int) {
    RED(0xFF0000),
    GREEN(0x00FF00),
    BLUE(0x0000FF),
    YELLOW(0xFFFF00)
}
```

A Kotlin a hexadecimálisokat egészként tárolja, így az `rgb` tulajdonság `Int` típusú, nem `String` típusú.

Egy tagfüggvény hozzáadásához az osztályhoz válaszd el az enum konstansoktól pontosvesszővel `;`:

```
enum class Color(val rgb: Int) {
    RED(0xFF0000),
    GREEN(0x00FF00),
    BLUE(0x0000FF),
    YELLOW(0xFFFF00);
    
    fun containsRed() = (this.rgb and 0xFF0000 != 0)
}

fun main() {
    val red = Color.RED
    // A containsRed() függvény meghívása az enum konstanson
    println(red.containsRed()) // true
    // A containsRed() függvény meghívása az enum konstansokon osztálynevek segítségével
    println(Color.BLUE.containsRed()) // false
    println(Color.YELLOW.containsRed()) // true
}
```

Ebben a példában a `containsRed()` tagfüggvény az enum konstans `rgb` tulajdonságának értékét éri el a `this` kulcsszó használatával, és ellenőrzi, hogy a hexadecimális érték tartalmazza-e az `FF` értéket az első bitekként, hogy logikai értéket adjon vissza.

További információ: Enum osztályok.

### Inline értékosztályok

Néha a kódodban szeretnél kis objektumokat létrehozni osztályokból, és csak rövid ideig használni őket. Ez a megközelítés teljesítményhatással járhat. Az inline értékosztályok egy speciális típusú osztály, amely elkerüli ezt a teljesítményhatást. Azonban csak értékeket tartalmazhatnak.

Egy inline értékosztály létrehozásához használd a `value` kulcsszót és a `@JvmInline` annotációt:

```
@JvmInline
value class Email
```

A `@JvmInline` annotáció utasítja a Kotlin-t, hogy optimalizálja a kódot a fordításkor. További információ: Annotációk.

Egy inline értékosztálynak egyetlen, az osztályfejlécben inicializált tulajdonsággal kell rendelkeznie. Tegyük fel, hogy létre szeretnél hozni egy osztályt, amely gyűjt egy e-mail címet:

```
// Az address tulajdonság inicializálva van az osztályfejlécben.
@JvmInline
value class Email(val address: String)

fun sendEmail(email: Email) {
    println("Sending email to ${email.address}")
}

fun main() {
    val myEmail = Email("example@example.com")
    sendEmail(myEmail) // Sending email to example@example.com
}
```

A példában:

- Az `Email` egy inline értékosztály, amelynek egy tulajdonsága van az osztályfejlécben: `address`.
- A `sendEmail()` függvény `Email` típusú objektumokat fogad, és kiír egy karakterláncot a standard kimenetre.
- A `main()` függvény:
  - Létrehoz egy `Email` osztály példányát `myEmail` néven.
  - Meghívja a `sendEmail()` függvényt a `myEmail` objektumon.

Az inline értékosztály használatával az osztály inline-olva lesz, és közvetlenül használhatod a kódodban objektum létrehozása nélkül. Ez jelentősen csökkentheti a memóriaigényt és javíthatja a kód futásidejű teljesítményét.

További információ az inline értékosztályokról: Inline értékosztályok.

## Gyakorlás

### Feladat 1

Egy szállítási szolgálatot vezetsz, és szükséged van a csomagok állapotának nyomon követésére. Hozz létre egy `DeliveryStatus` nevű sealed osztályt, amely adatosztályokat tartalmaz a következő állapotok reprezentálására: `Pending`, `InTransit`, `Delivered`, `Canceled`.

Egészítsd ki a `DeliveryStatus` osztálydeklarációt úgy, hogy a `main()` függvényben lévő kód sikeresen fusson:

```
sealed class // Write your code here || Írd ide a kódodat

fun printDeliveryStatus(status: DeliveryStatus) {
    when (status) {
        is DeliveryStatus.Pending -> {
            println("The package is pending pickup from ${status.sender}.")
        }
        is DeliveryStatus.InTransit -> {
            println("The package is in transit and expected to arrive by ${status.estimatedDeliveryDate}.")
        }
        is DeliveryStatus.Delivered -> {
            println("The package was delivered to ${status.recipient} on ${status.deliveryDate}.")
        }
        is DeliveryStatus.Canceled -> {
            println("The delivery was canceled due to: ${status.reason}.")
        }
    }
}

fun main() {
    val status1: DeliveryStatus = DeliveryStatus.Pending("Alice")
    val status2: DeliveryStatus = DeliveryStatus.InTransit("2024-11-20")
    val status3: DeliveryStatus = DeliveryStatus.Delivered("2024-11-18", "Bob")
    val status4: DeliveryStatus = DeliveryStatus.Canceled("Address not found")
    
    printDeliveryStatus(status1) // The package is pending pickup from Alice.
    printDeliveryStatus(status2) // The package is in transit and expected to arrive by 2024-11-20.
    printDeliveryStatus(status3) // The package was delivered to Bob on 2024-11-18.
    printDeliveryStatus(status4) // The delivery was canceled due to: Address not found.
}
```

### Megoldás
```
sealed class DeliveryStatus {
    data class Pending(val sender: String) : DeliveryStatus()
    data class InTransit(val estimatedDeliveryDate: String) : DeliveryStatus()
    data class Delivered(val deliveryDate: String, val recipient: String) : DeliveryStatus()
    data class Canceled(val reason: String) : DeliveryStatus()
}

fun printDeliveryStatus(status: DeliveryStatus) {
    when (status) {
        is DeliveryStatus.Pending -> {
            println("The package is pending pickup from ${status.sender}.")
        }
        is DeliveryStatus.InTransit -> {
            println("The package is in transit and expected to arrive by ${status.estimatedDeliveryDate}.")
        }
        is DeliveryStatus.Delivered -> {
            println("The package was delivered to ${status.recipient} on ${status.deliveryDate}.")
        }
        is DeliveryStatus.Canceled -> {
            println("The delivery was canceled due to: ${status.reason}.")
        }
    }
}

fun main() {
    val status1: DeliveryStatus = DeliveryStatus.Pending("Alice")
    val status2: DeliveryStatus = DeliveryStatus.InTransit("2024-11-20")
    val status3: DeliveryStatus = DeliveryStatus.Delivered("2024-11-18", "Bob")
    val status4: DeliveryStatus = DeliveryStatus.Canceled("Address not found")
    
    printDeliveryStatus(status1) // The package is pending pickup from Alice.
    printDeliveryStatus(status2) // The package is in transit and expected to arrive by 2024-11-20.
    printDeliveryStatus(status3) // The package was delivered to Bob on 2024-11-18.
    printDeliveryStatus(status4) // The delivery was canceled due to: Address not found.
}
```

### Feladat 2

A programodban képesnek kell lenned különböző állapotok és hibatípusok kezelésére. Van egy sealed osztályod, amely rögzíti a különböző állapotokat, amelyek adatosztályokban vagy objektumokban vannak deklarálva.

Egészítsd ki az alábbi kódot egy `Problem` nevű enum osztály létrehozásával, amely a különböző problématípusokat reprezentálja: `NETWORK`, `TIMEOUT` és `UNKNOWN`.

```
sealed class Status {
    data object Loading : Status()
    data class Error(val problem: Problem) : Status() {
        // Write your code here || Írd ide a kódodat
    }
    data class OK(val data: List<String>) : Status()
}

fun handleStatus(status: Status) {
    when (status) {
        is Status.Loading -> println("Loading...")
        is Status.OK -> println("Data received: ${status.data}")
        is Status.Error -> when (status.problem) {
            Status.Error.Problem.NETWORK -> println("Network issue")
            Status.Error.Problem.TIMEOUT -> println("Request timed out")
            Status.Error.Problem.UNKNOWN -> println("Unknown error occurred")
        }
    }
}

fun main() {
    val status1: Status = Status.Error(Status.Error.Problem.NETWORK)
    val status2: Status = Status.OK(listOf("Data1", "Data2"))
    
    handleStatus(status1) // Network issue
    handleStatus(status2) // Data received: [Data1, Data2]
}
```

### Megoldás
```
sealed class Status {
    data object Loading : Status()
    data class Error(val problem: Problem) : Status() {
        enum class Problem {
            NETWORK,
            TIMEOUT,
            UNKNOWN
        }
    }
    data class OK(val data: List<String>) : Status()
}

fun handleStatus(status: Status) {
    when (status) {
        is Status.Loading -> println("Loading...")
        is Status.OK -> println("Data received: ${status.data}")
        is Status.Error -> when (status.problem) {
            Status.Error.Problem.NETWORK -> println("Network issue")
            Status.Error.Problem.TIMEOUT -> println("Request timed out")
            Status.Error.Problem.UNKNOWN -> println("Unknown error occurred")
        }
    }
}

fun main() {
    val status1: Status = Status.Error(Status.Error.Problem.NETWORK)
    val status2: Status = Status.OK(listOf("Data1", "Data2"))
    
    handleStatus(status1) // Network issue
    handleStatus(status2) // Data received: [Data1, Data2]
}
```
## Következő lépés

## Középhaladó: Tulajdonságok

## Középhaladó: Tulajdonságok

A kezdő túrán megtanultad, hogyan használják a tulajdonságokat az osztálypéldányok jellemzőinek deklarálására és hogyan lehet hozzájuk férni. Ez a fejezet mélyebben ássa el, hogyan működnek a tulajdonságok a Kotlinban, és felfedezi azokat a más módszereket, amelyekkel a kódodban használhatod őket.

## Háttérmezők

A Kotlinban a tulajdonságoknak vannak alapértelmezett `get()` és `set()` függvényeik, amelyek tulajdonság-hozzáférőként ismertek, és kezelik az értékek lekérését és módosítását. Bár ezek az alapértelmezett függvények nem láthatók kifejezetten a kódban, a fordító automatikusan létrehozza őket a tulajdonság-hozzáférés kezelésére a háttérben.

Ezek a hozzáférők háttérmezőt használnak a tényleges tulajdonságérték tárolására. Háttérmezők akkor léteznek, ha a következők bármelyike igaz:

- Az alapértelmezett `get()` vagy `set()` függvényeket használod a tulajdonsághoz.
- A `field` kulcsszóval próbálod elérni a tulajdonság értékét a kódban.

A `get()` és `set()` függvényeket másnéven gettereknek és settereknek is nevezik.

Például ez a kód rendelkezik egy `category` tulajdonsággal, amelynek nincsenek egyéni `get()` vagy `set()` függvényei, ezért az alapértelmezett implementációkat használja:

```
class Contact(val id: Int, var email: String) {
    var category: String = ""
}
```

A háttérben ez egyenértékű az alábbi pszeudokóddal:

```
class Contact(val id: Int, var email: String) {
    var category: String = ""
        get() = field
        set(value) {
            field = value
        }
}
```

Ebben a példában:
- A `get()` függvény lekéri a tulajdonságértéket a mezőből: `""`.
- A `set()` függvény elfogad egy `value` paramétert, és hozzárendeli a mezőhöz, ahol a `value` értéke `""`.

A háttérmezőhöz való hozzáférés hasznos, amikor extra logikát szeretnél hozzáadni a `get()` vagy `set()` függvényeidhez anélkül, hogy végtelen ciklust okoznál.

Például van egy `Person` osztályod egy `name` tulajdonsággal:

```
class Person {
    var name: String = ""
}
```

Szeretnéd biztosítani, hogy a `name` tulajdonság első betűje nagybetűs legyen, ezért létrehozol egy egyéni `set()` függvényt, amely a `.replaceFirstChar()` és `.uppercase()` kiterjesztési függvényeket használja. Azonban ha közvetlenül hivatkozol a tulajdonságra a `set()` függvényedben, végtelen ciklust hozol létre, és `StackOverflowError`-t kapsz futási időben:

```
class Person {
    var name: String = ""
    set(value) {
        // Ez futási hibát okoz
        name = value.replaceFirstChar { firstChar ->
            firstChar.uppercase()
        }
    }
}

fun main() {
    val person = Person()
    person.name = "kodee"
    println(person.name)
    // Exception in thread "main" java.lang.StackOverflowError
}
```

Ennek javításához a `set()` függvényedben használhatod a háttérmezőt a `field` kulcsszóval való hivatkozás helyett:

```
class Person {
    var name: String = ""
    set(value) {
        field = value.replaceFirstChar { firstChar ->
            firstChar.uppercase()
        }
    }
}

fun main() {
    val person = Person()
    person.name = "kodee"
    println(person.name) // Kodee
}
```

A háttérmezők hasznosak akkor is, amikor naplózást szeretnél hozzáadni, értesítéseket küldeni, amikor egy tulajdonságérték megváltozik, vagy további logikát használni szeretnél, amely összehasonlítja a régi és új tulajdonságértékeket.

További információ: Háttérmezők.

## Kiterjesztési tulajdonságok

Éppúgy, mint a kiterjesztési függvények, léteznek kiterjesztési tulajdonságok is. A kiterjesztési tulajdonságok lehetővé teszik új tulajdonságok hozzáadását meglévő osztályokhoz anélkül, hogy módosítanád az eredeti forráskódot. Azonban a Kotlin kiterjesztési tulajdonságai nem rendelkeznek háttérmezőkkel. Ez azt jelenti, hogy a `get()` és `set()` függvényeket saját magadnak kell megírnod. Emellett a háttérmező hiánya azt is jelenti, hogy nem tudnak állapotot tárolni.

Egy kiterjesztési tulajdonság deklarálásához írd le azt az osztályt, amelyet ki szeretnél terjeszteni, majd egy `.` jelet, végül a tulajdonság nevét. Éppúgy, mint a normál osztálytulajdonságok esetén, deklarálnod kell a tulajdonság típusát. Például:

```
val String.lastChar: Char
```

A kiterjesztési tulajdonságok akkor a leghasznosabbak, amikor egy tulajdonságnak számított értéket szeretnél tárolni öröklés használata nélkül. A kiterjesztési tulajdonságokat úgy képzelheted el, mint egy olyan függvényt, amelynek csak egy paramétere van: a fogadó.

Például tegyük fel, hogy van egy `Person` nevű adatosztályod két tulajdonsággal: `firstName` és `lastName`.

```
data class Person(val firstName: String, val lastName: String)
```

Szeretnéd elérni a személy teljes nevét anélkül, hogy módosítanád a `Person` adatosztályt vagy örökölnél belőle. Ezt megteheted egy kiterjesztési tulajdonság létrehozásával egyedi `get()` függvénnyel:

```
data class Person(val firstName: String, val lastName: String)

// Kiterjesztési tulajdonság a teljes név lekéréséhez
val Person.fullName: String
    get() = "$firstName $lastName"

fun main() {
    val person = Person(firstName = "John", lastName = "Doe")
    // A kiterjesztési tulajdonság használata
    println(person.fullName) // John Doe
}
```

A kiterjesztési tulajdonságok nem írhatják felül az osztály meglévő tulajdonságait. Éppúgy, mint a kiterjesztési függvények esetén, a Kotlin standard könyvtár széles körben használja a kiterjesztési tulajdonságokat. Például lásd a `lastIndex` tulajdonságot egy `CharSequence` esetén.

## Delegált tulajdonságok

Már tanultad a delegálást az Osztályok és interfészek fejezetben. A tulajdonságokkal is használhatod a delegálást, hogy a tulajdonság-hozzáférőket egy másik objektumra delegáld. Ez akkor hasznos, ha összetettebb követelményeid vannak a tulajdonságok tárolására, mint amit egy egyszerű háttérmező képes kezelni, például értékek tárolása adatbázis táblában, böngésző munkamenetben vagy térképben.

A delegált tulajdonságok használata csökkenti a boilerplate kódot, mivel a tulajdonságok lekérésének és beállításának logikája csak abban az objektumban van, amelyre delegálsz. A szintaxis hasonló az osztálydelegáláshoz, de más szinten működik. Deklaráld a tulajdonságodat, majd a `by` kulcsszót és azt az objektumot, amelyre delegálni szeretnél. Például:

```
val displayName: String by Delegate
```

Itt a delegált `displayName` tulajdonság a `Delegate` objektumra hivatkozik a tulajdonság-hozzáférői szempontból. Minden objektumnak, amelyre delegálsz, rendelkeznie kell egy `getValue()` operátorfüggvénnyel, amelyet a Kotlin használ a delegált tulajdonság értékének lekérésére. Ha a tulajdonság módosítható, akkor rendelkeznie kell egy `setValue()` operátorfüggvénnyel is, amelyet a Kotlin használ az érték beállítására.

Alapértelmezés szerint a `getValue()` és `setValue()` függvények a következő szerkezettel rendelkeznek:

```
operator fun getValue(thisRef: Any?, property: KProperty<*>): String {}
operator fun setValue(thisRef: Any?, property: KProperty<*>, value: String) {}
```

Ezekben a függvényekben:
- Az `operator` kulcsszó megjelöli ezeket a függvényeket operátorfüggvényként, lehetővé téve a `get()` és `set()` függvények túlterhelését.
- A `thisRef` paraméter az objektumra hivatkozik, amely tartalmazza a delegált tulajdonságot.
- Alapértelmezés szerint a típus `Any?`, de szükség lehet konkrétabb típus deklarálására.
- A `property` paraméter a tulajdonságra hivatkozik, amelynek értékét elérjük vagy megváltoztatjuk.
- Ezt a paramétert arra használhatod, hogy információkat érj el, például a tulajdonság nevét vagy típusát.
- Alapértelmezés szerint a típus `KProperty<*>`, de használhatod az `Any?` típust is.
- Nem kell aggódnod a típus változtatása miatt a kódodban.
- A `getValue()` függvény alapértelmezés szerint `String` típussal tér vissza, de ezt igény szerint módosíthatod.
- A `setValue()` függvénynek van egy további `value` paramétere, amely az új értéket tárolja, amelyet a tulajdonsághoz rendelnek.

Tehát hogyan néz ki ez a gyakorlatban? Tegyük fel, hogy szeretnél egy számított tulajdonságot, például egy felhasználó megjelenített nevét, amelyet csak egyszer kell kiszámítani, mert a művelet drága, és az alkalmazásod érzékeny a teljesítményre. Használhatsz egy delegált tulajdonságot a megjelenített név gyorsítótárazására, így csak egyszer kell kiszámítani, de bármikor hozzáférhetsz anélkül, hogy teljesítményhatást okozna.

Először létre kell hoznod az objektumot, amelyre delegálni szeretnél. Ebben az esetben az objektum a `CachedStringDelegate` osztály egy példánya lesz:

```
class CachedStringDelegate {
    var cachedValue: String? = null
}
```

A `cachedValue` tulajdonság tartalmazza a gyorsítótárazott értéket. A `CachedStringDelegate` osztályon belül add hozzá a viselkedést, amelyet szeretnél a delegált tulajdonság `get()` függvényétől, a `getValue()` operátorfüggvény törzséhez:

```
class CachedStringDelegate {
    var cachedValue: String? = null
    
    operator fun getValue(thisRef: Any?, property: Any?): String {
        if (cachedValue == null) {
            cachedValue = "Default Value"
            println("Computed and cached: $cachedValue")
        } else {
            println("Accessed from cache: $cachedValue")
        }
        return cachedValue ?: "Unknown"
    }
}
```

A `getValue()` függvény ellenőrzi, hogy a `cachedValue` tulajdonság `null`-e. Ha igen, a függvény hozzárendeli az "Alapértelmezett értéket", és kiír egy karakterláncot naplózási célokra. Ha a `cachedValue` tulajdonság már ki lett számítva, a tulajdonság nem `null`. Ebben az esetben egy másik karakterlánc kerül kiírásra naplózási célokra. Végül a függvény az Elvis operátort használja a gyorsítótárazott érték vagy "Ismeretlen" visszaadására, ha az érték `null`.

Most delegálhatod a tulajdonságot, amelyet gyorsítótárazni szeretnél (`val displayName`), a `CachedStringDelegate` osztály egy példányára:

```
class CachedStringDelegate {
    var cachedValue: String? = null
    
    operator fun getValue(thisRef: User, property: Any?): String {
        if (cachedValue == null) {
            cachedValue = "${thisRef.firstName} ${thisRef.lastName}"
            println("Computed and cached: $cachedValue")
        } else {
            println("Accessed from cache: $cachedValue")
        }
        return cachedValue ?: "Unknown"
    }
}

class User(val firstName: String, val lastName: String) {
    val displayName: String by CachedStringDelegate()
}

fun main() {
    val user = User("John", "Doe")
    // Az első hozzáférés kiszámítja és gyorsítótárazza az értéket
    println(user.displayName) // Computed and cached: John Doe
                           // John Doe
    
    // A későbbi hozzáférések a gyorsítótárból nyerik ki az értéket
    println(user.displayName) // Accessed from cache: John Doe
                            // John Doe
}
```

Ez a példa:
- Létrehoz egy `User` osztályt, amelynek két tulajdonsága van a fejlécben, `firstName` és `lastName`, valamint egy tulajdonsága van az osztálytörzsben, `displayName`.
- Delegálja a `displayName` tulajdonságot a `CachedStringDelegate` osztály egy példányára.
- Létrehoz egy `User` osztály példányt `user` néven.
- Kiírja a `displayName` tulajdonság hozzáférésének eredményét a `user` példányon.

Vegye figyelembe, hogy a `getValue()` függvényben a `thisRef` paraméter típusa leszűkül `Any?` típusról az objektum típusára: `User`. Ez azért van így, hogy a fordító hozzáférhessen a `User` osztály `firstName` és `lastName` tulajdonságaihoz.

## Standard delegátok

A Kotlin standard könyvtár hasznos delegátokat biztosít számodra, így nem kell minden alkalommal sajátot létrehoznod. Ha az egyik delegátok közül használsz, nem kell meghatároznod a `getValue()` és `setValue()` függvényeket, mert a standard könyvtár automatikusan biztosítja őket.

## Lusta tulajdonságok

Egy tulajdonság inicializálásához csak akkor, amikor először hozzáférnek, használj lusta tulajdonságot. A standard könyvtár a `Lazy` interfészt biztosítja a delegáláshoz. A `Lazy` interfész egy példányának létrehozásához használd a `lazy()` függvényt egy lambdakifejezés biztosításával, amely akkor hajtódik végre, amikor a `get()` függvényt először hívják meg. A `get()` függvény további hívásai ugyanazt az eredményt adják vissza, amelyet az első hívás során kaptál.

A lusta tulajdonságok a végrehajtó lambdát a záró lambda szintaxis segítségével kapják meg. Például:

```
class Database {
    fun connect() {
        println("Connecting to the database...")
    }
    
    fun query(sql: String): List<String> {
        return listOf("Data1", "Data2", "Data3")
    }
}

val databaseConnection: Database by lazy {
    val db = Database()
    db.connect()
    db
}

fun fetchData() {
    val data = databaseConnection.query("SELECT * FROM data")
    println("Data: $data")
}

fun main() {
    // Az első hozzáférés inicializálja a databaseConnection-t
    fetchData() // Connecting to the database...
                // Data: [Data1, Data2, Data3]
    
    // A későbbi hozzáférések a meglévő kapcsolatot használják
    fetchData() // Data: [Data1, Data2, Data3]
}
```

Ebben a példában:
- Van egy `Database` osztály `connect()` és `query()` tagfüggvényekkel.
- A `connect()` függvény kiír egy karakterláncot a konzolra, a `query()` függvény pedig elfogad egy SQL lekérdezést és egy listát ad vissza.
- Van egy `databaseConnection` nevű tulajdonság, amely egy lusta tulajdonság.
- A `lazy()` funkcióhoz megadott lambda kifejezés:
  - Létrehoz egy `Database` osztály példányt.
  - Meghívja a `connect()` tagfüggvényt ezen a példányon (`db`).
  - Visszaadja a példányt.
- Van egy `fetchData()` függvény, amely:
  - Létrehoz egy SQL lekérdezést a `databaseConnection` tulajdonságon meghívott `query()` függvénnyel.
  - Hozzárendeli az SQL lekérdezést a `data` változóhoz.
  - Kiírja a `data` változót a konzolra.
- A `main()` függvény meghívja a `fetchData()` függvényt. Amikor először hívják, a lusta tulajdonság inicializálódik. A második alkalommal ugyanazt az eredményt kapjuk, mint az első hívásnál.

A lusta tulajdonságok nemcsak akkor hasznosak, amikor az inicializálás erőforrásigényes, hanem akkor is, amikor egy tulajdonságot előfordulhat, hogy nem használnak a kódban. Emellett a lusta tulajdonságok alapértelmezés szerint szálbiztosak, ami különösen előnyös, ha párhuzamos környezetben dolgozol.

További információért lásd: Lusta tulajdonságok.

## Megfigyelhető tulajdonságok

Egy tulajdonság értékváltozásának figyeléséhez használj megfigyelhető tulajdonságot. Egy megfigyelhető tulajdonság akkor hasznos, amikor észre akarod venni a tulajdonságérték változását, és ennek ismeretében egy reakciót szeretnél kiváltani. A standard könyvtár biztosítja a `Delegates` objektumot a delegáláshoz. Egy megfigyelhető tulajdonság létrehozásához először importálnod kell a `kotlin.properties.Delegates.observable` osztályt. Ezután használd az `observable()` függvényt, és biztosíts egy lambdakifejezést, amely akkor hajtódik végre, amikor a tulajdonság megváltozik. Éppúgy, mint a lusta tulajdonságok esetén, a megfigyelhető tulajdonságok is a végrehajtó lambdát a záró lambda szintaxis segítségével kapják meg. Például:

```
import kotlin.properties.Delegates.observable

class Thermostat {
    var temperature: Double by observable(20.0) { _, old, new ->
        if (new > 25) {
            println("Warning: Temperature is too high! ($old°C -> $new°C)")
        } else {
            println("Temperature updated: $old°C -> $new°C")
        }
    }
}

fun main() {
    val thermostat = Thermostat()
    thermostat.temperature = 22.5 // Temperature updated: 20.0°C -> 22.5°C
    thermostat.temperature = 27.0 // Warning: Temperature is too high! (22.5°C -> 27.0°C)
}
```

Ebben a példában:
- Van egy `Thermostat` osztály, amely egy megfigyelhető tulajdonsággal rendelkezik: `temperature`.
- Az `observable()` függvény 20.0-t fogad paraméterként, és felhasználja a tulajdonság inicializálásához.
- Az `observable()` függvényhez megadott lambda kifejezés:
  - Három paraméterrel rendelkezik:
    - `_`, amely a tulajdonságra hivatkozik.
    - `old`, amely a tulajdonság régi értéke.
    - `new`, amely a tulajdonság új értéke.
  - Ellenőrzi, hogy az `new` paraméter nagyobb-e, mint 25, és az eredménytől függően kiír egy karakterláncot a konzolra.
- A `main()` függvény:
  - Létrehoz egy `Thermostat` osztály példányt `thermostat` néven.
  - Frissíti a példány `temperature` tulajdonságának értékét 22.5-re, amely egy hőmérsékletfrissítést kiíró nyomtatási utasítást vált ki.
  - Frissíti a példány `temperature` tulajdonságának értékét 27.0-re, amely figyelmeztetést kiíró nyomtatási utasítást vált ki.

A megfigyelhető tulajdonságok nemcsak naplózási és hibakeresési célokra hasznosak. Használhatod őket arra is, hogy például frissítsd a felhasználói felületet vagy további ellenőrzéseket hajts végre, például az adatok érvényességének ellenőrzésére. 

További információk: Megfigyelhető tulajdonságok.

## Gyakorlat

### 1. feladat

Egy könyvesboltban kezelsz egy raktárkészletrendszert. A raktárkészletet egy listában tárolják, ahol minden elem egy adott könyv mennyiségét jelöli. Például, `listOf(3, 0, 7, 12)` azt jelenti, hogy az üzletben 3 példány van az első könyvből, 0 a másodikból, 7 a harmadikból és 12 a negyedikből.

Írj egy `findOutOfStockBooks()` nevű függvényt, amely visszaadja azon könyvek indexeinek listáját, amelyekből elfogyott a készlet.

**Tipp 1:** Használd az `indices` kiterjesztési tulajdonságot a standard könyvtárból.
**Tipp 2:** Használhatod a `buildList()` függvényt listák létrehozására és kezelésére ahelyett, hogy manuálisan hoznál létre és adnál vissza egy módosítható listát. A `buildList()` függvény egy lambdát fogad el fogadóval, amelyről korábbi fejezetekben tanultál.

```
fun findOutOfStockBooks(inventory: List<Int>): List<Int> {
    // Write your code here || Írd ide a kódodat
}

fun main() {
    val inventory = listOf(3, 0, 7, 0, 5)
    println(findOutOfStockBooks(inventory)) // [1, 3]
}
```

#### Megoldás 1
```
fun findOutOfStockBooks(inventory: List<Int>): List<Int> {
    val outOfStockIndices = mutableListOf<Int>()
    for (index in inventory.indices) {
        if (inventory[index] == 0) {
            outOfStockIndices.add(index)
        }
    }
    return outOfStockIndices
}

fun main() {
    val inventory = listOf(3, 0, 7, 0, 5)
    println(findOutOfStockBooks(inventory)) // [1, 3]
}
```

#### Megoldás 2
```
fun findOutOfStockBooks(inventory: List<Int>): List<Int> = buildList {
    for (index in inventory.indices) {
        if (inventory[index] == 0) {
            add(index)
        }
    }
}

fun main() {
    val inventory = listOf(3, 0, 7, 0, 5)
    println(findOutOfStockBooks(inventory)) // [1, 3]
}
```

### 2. feladat

Van egy utazási alkalmazásod, amelynek meg kell jelenítenie a távolságokat kilométerben és mérföldben is. Hozz létre egy kiterjesztési tulajdonságot a `Double` típushoz `asMiles` néven, amely egy távolságot kilométerben mérföldre konvertál:

A kilométerek mérföldre konvertálásának képlete: `mérföld = kilométer * 0.621371`.

**Tipp:** Ne feledd, hogy a kiterjesztési tulajdonságokhoz egyedi `get()` függvényre van szükség.

```
val // Write your code here || Írd ide a kódodat

fun main() {
    val distanceKm = 5.0
    println("$distanceKm km is ${distanceKm.asMiles} miles") 
    // 5.0 km is 3.106855 miles
    val marathonDistance = 42.195
    println("$marathonDistance km is ${marathonDistance.asMiles} miles") 
    // 42.195 km is 26.218757 miles
}
```

#### Megoldás
```
val Double.asMiles: Double
    get() = this * 0.621371

fun main() {
    val distanceKm = 5.0
    println("$distanceKm km is ${distanceKm.asMiles} miles") 
    // 5.0 km is 3.106855 miles
    val marathonDistance = 42.195
    println("$marathonDistance km is ${marathonDistance.asMiles} miles") 
    // 42.195 km is 26.218757 miles
}
```

### 3. feladat

Van egy rendszerállapot-ellenőrző alkalmazásod, amely meghatározhatja egy felhőalapú rendszer állapotát. Azonban a két függvény, amelyeket futtatni lehet az állapotellenőrzéshez, teljesítményigényesek. Használj lusta tulajdonságokat az ellenőrzések inicializálásához, így a drága függvények csak akkor futnak le, amikor szükséges:

```
fun checkAppServer(): Boolean {
    println("Performing application server health check...")
    return true
}

fun checkDatabase(): Boolean {
    println("Performing database health check...")
    return false
}

fun main() {
    // Write your code here || Írd ide a kódodat
    when {
        isAppServerHealthy -> println("Application server is online and healthy")
        isDatabaseHealthy -> println("Database is healthy")
        else -> println("System is offline")
    }
    // Performing application server health check...
    // Application server is online and healthy
}
```

#### Megoldás
```
fun checkAppServer(): Boolean {
    println("Performing application server health check...")
    return true
}

fun checkDatabase(): Boolean {
    println("Performing database health check...")
    return false
}

fun main() {
    val isAppServerHealthy by lazy { checkAppServer() }
    val isDatabaseHealthy by lazy { checkDatabase() }
    
    when {
        isAppServerHealthy -> println("Application server is online and healthy")
        isDatabaseHealthy -> println("Database is healthy")
        else -> println("System is offline")
    }
    // Performing application server health check...
    // Application server is online and healthy
}
```

### 4. feladat

Egy egyszerű költségvetéskövető alkalmazást építesz. Az alkalmazásnak figyelnie kell a felhasználó hátralévő költségvetésének változásait, és értesítenie kell őt, amikor az egy bizonyos küszöb alá esik. Van egy `Budget` osztályod, amelyet egy `totalBudget` tulajdonsággal inicializálnak, amely a kezdeti költségvetési összeget tartalmazza. Az osztályon belül hozz létre egy `remainingBudget` nevű megfigyelhető tulajdonságot, amely kiírja:

- Egy figyelmeztetést, amikor az érték alacsonyabb, mint a kezdeti költségvetés 20%-a.
- Egy biztatást, amikor a költségvetés megnőtt az előző értékhez képest.

```
import kotlin.properties.Delegates.observable

class Budget(val totalBudget: Int) {
    var remainingBudget: Int // Write your code here || Írd ide a kódodat
}

fun main() {
    val myBudget = Budget(totalBudget = 1000)
    myBudget.remainingBudget = 800
    myBudget.remainingBudget = 150 
    // Warning: Your remaining budget (150) is below 20% of your total budget.
    myBudget.remainingBudget = 50  
    // Warning: Your remaining budget (50) is below 20% of your total budget.
    myBudget.remainingBudget = 300 
    // Good news: Your remaining budget increased to 300.
}
```

#### Megoldás
```
import kotlin.properties.Delegates.observable

class Budget(val totalBudget: Int) {
    var remainingBudget: Int by observable(totalBudget) { _, oldValue, newValue ->
        if (newValue < totalBudget * 0.2) {
            println("Warning: Your remaining budget ($newValue) is below 20% of your total budget.")
        } else if (newValue > oldValue) {
            println("Good news: Your remaining budget increased to $newValue.")
        }
    }
}

fun main() {
    val myBudget = Budget(totalBudget = 1000)
    myBudget.remainingBudget = 800
    myBudget.remainingBudget = 150 
    // Warning: Your remaining budget (150) is below 20% of your total budget.
    myBudget.remainingBudget = 50  
    // Warning: Your remaining budget (50) is below 20% of your total budget.
    myBudget.remainingBudget = 300 
    // Good news: Your remaining budget increased to 300.
}
```
## Következő lépés

## Középhaladó: Null biztonság

A kezdő túrán megtanultad, hogyan kezeljed a null értékeket a kódodban. Ez a fejezet a null biztonsági funkciók gyakori használati eseteit és azok maximális kihasználását tárgyalja.

## Okos típuskényszerítések és biztonságos kényszerítések

A Kotlin néha képes kikövetkeztetni a típust explicit deklaráció nélkül. Amikor azt mondod a Kotlin-nak, hogy egy változót vagy objektumot egy adott típusként kezeljen, ezt a folyamatot típuskényszerítésnek nevezzük. Amikor egy típus automatikusan kényszerítve van, például amikor kikövetkeztetett, ezt okos típuskényszerítésnek (smart casting) nevezzük.

## `is` és `!is` operátorok

Mielőtt felfedeznénk, hogyan működik a típuskényszerítés, nézzük meg, hogyan ellenőrizhetjük, hogy egy objektum rendelkezik-e bizonyos típussal. Ehhez használhatjuk az `is` és `!is` operátorokat `when` vagy `if` feltételes kifejezésekkel:

- `is` ellenőrzi, hogy az objektum rendelkezik-e a típussal, és logikai értéket ad vissza.
- `!is` ellenőrzi, hogy az objektum nem rendelkezik-e a típussal, és logikai értéket ad vissza.

Például:

```
fun printObjectType(obj: Any) {
    when (obj) {
        is Int -> println("It's an Integer with value $obj")
        !is Double -> println("It's NOT a Double")
        else -> println("Unknown type")
    }
}

fun main() {
    val myInt = 42
    val myDouble = 3.14
    val myList = listOf(1, 2, 3)
    
    // A típus Int
    printObjectType(myInt) // It's an Integer with value 42
    
    // A típus List, tehát NEM Double
    printObjectType(myList) // It's NOT a Double
    
    // A típus Double, tehát az else ág aktiválódik
    printObjectType(myDouble) // Unknown type
}
```

Már láttál egy példát a `when` feltételes kifejezés `is` és `!is` operátorokkal való használatára a "Nyílt és egyéb speciális osztályok" fejezetben.

## `as` és `as?` operátorok

Egy objektum explicit típuskényszerítéséhez bármely más típusra használd az `as` operátort. Ez magában foglalja a nullázható típusról annak nem nullázható párjára való kényszerítést is. Ha a kényszerítés nem lehetséges, a program futási időben összeomlik. Ezért hívják nem biztonságos kényszerítési operátornak.

```
fun main() {
    val a: String? = null
    val b = a as String // Futási hibát vált ki
    print(b)
}
```

Egy objektum explicit típuskényszerítéséhez nem nullázható típusra, de null érték visszaadásához hiba dobása helyett, használd az `as?` operátort. Mivel az `as?` operátor nem vált ki hibát sikertelenség esetén, biztonságos operátornak nevezik.

```
fun main() {
    val a: String? = null
    val b = a as? String // Null értéket ad vissza
    print(b) // null
}
```

Az `as?` operátort kombinálhatod az Elvis operátorral `?:`, hogy több kódsort egyre redukálj. Például a következő `calculateTotalStringLength()` függvény kiszámítja az összes karakterlánc teljes hosszát egy vegyes listában:

```
fun calculateTotalStringLength(items: List<Any>): Int {
    var totalLength = 0
    for (item in items) {
        totalLength += if (item is String) {
            item.length
        } else {
            0 // 0 hozzáadása nem karakterlánc elemekhez
        }
    }
    return totalLength
}
```

A példa:
- A `totalLength` változót számlálóként használja.
- Egy `for` ciklust használ a lista minden elemén való végiglépéshez.
- Egy `if` utasítást és az `is` operátort használ annak ellenőrzésére, hogy az aktuális elem karakterlánc-e:
  - Ha igen, a karakterlánc hosszát hozzáadja a számlálóhoz.
  - Ha nem, a számláló nem növekszik.
- Visszaadja a `totalLength` változó végleges értékét.

Ez a kód redukálható:

```
fun calculateTotalStringLength(items: List<Any>): Int {
    return items.sumOf { (it as? String)?.length ?: 0 }
}
```

A példa a `.sumOf()` kiterjesztési függvényt használja, és egy lambda kifejezést biztosít, amely:
- A lista minden elemére biztonságos kényszerítést hajt végre String típusra az `as?` használatával.
- Biztonságos hívást `?.` használ a `length` tulajdonság eléréséhez, ha a hívás nem ad vissza null értéket.
- Az Elvis operátort `?:` használja 0 visszaadásához, ha a biztonságos hívás null értéket ad vissza.

## Null értékek és kollekciók

A Kotlinban a kollekciókkal való munka gyakran magában foglalja a null értékek kezelését és a felesleges elemek kiszűrését. A Kotlin hasznos függvényekkel rendelkezik, amelyekkel tiszta, hatékony és null biztonságos kódot írhatsz listák, halmazok, térképek és egyéb típusú kollekciók kezelésekor.

A null értékek kiszűréséhez egy listából használd a `filterNotNull()` függvényt:

```
fun main() {
    val emails: List<String?> = listOf("alice@example.com", null, "bob@example.com", null, "carol@example.com")
    val validEmails = emails.filterNotNull()
    println(validEmails) // [alice@example.com, bob@example.com, carol@example.com]
}
```

Ha közvetlenül a lista létrehozásakor szeretnéd kiszűrni a null értékeket, használd a `listOfNotNull()` függvényt:

```
fun main() {
    val serverConfig = mapOf(
        "appConfig.json" to "App Configuration",
        "dbConfig.json" to "Database Configuration"
    )
    val requestedFile = "appConfig.json"
    val configFiles = listOfNotNull(serverConfig[requestedFile])
    println(configFiles) // [App Configuration]
}
```

Mindkét példában, ha minden elem null érték, üres listát ad vissza.

A Kotlin olyan függvényeket is biztosít, amelyekkel értékeket kereshetsz kollekciókban. Ha egy érték nem található, null értéket adnak vissza hiba kiváltása helyett:

- `maxOrNull()` megtalálja a legnagyobb értéket. Ha ilyen nem létezik, null értéket ad vissza.
- `minOrNull()` megtalálja a legkisebb értéket. Ha ilyen nem létezik, null értéket ad vissza.

Például:

```
fun main() {
    // Egy hét alatt rögzített hőmérsékletek
    val temperatures = listOf(15, 18, 21, 21, 19, 17, 16)
    
    // A hét legmagasabb hőmérsékletének megtalálása
    val maxTemperature = temperatures.maxOrNull()
    println("Highest temperature recorded: ${maxTemperature ?: "No data"}") 
    // Highest temperature recorded: 21
    
    // A hét legalacsonyabb hőmérsékletének megtalálása
    val minTemperature = temperatures.minOrNull()
    println("Lowest temperature recorded: ${minTemperature ?: "No data"}") 
    // Lowest temperature recorded: 15
}
```

Ez a példa az Elvis operátort `?:` használja egy nyomtatott utasítás visszaadásához, ha a függvények null értéket adnak vissza. A `maxOrNull()` és `minOrNull()` függvényeket null értékeket nem tartalmazó kollekciókhoz tervezték. Ellenkező esetben nem tudnád megmondani, hogy a függvény nem találta meg a kívánt értéket, vagy null értéket talált.

Használhatod a `singleOrNull()` függvényt egy lambda kifejezéssel egyetlen olyan elem megtalálásához, amely megfelel egy feltételnek. Ha ilyen elem nem létezik, vagy több elem is megfelel, a függvény null értéket ad vissza:

```
fun main() {
    // Egy hét alatt rögzített hőmérsékletek
    val temperatures = listOf(15, 18, 21, 21, 19, 17, 16)
    
    // Ellenőrzés, hogy pontosan egy nap volt-e 30 fokos
    val singleHotDay = temperatures.singleOrNull{ it == 30 }
    println("Single hot day with 30 degrees: ${singleHotDay ?: "None"}") 
    // Single hot day with 30 degrees: None
}
```

A `singleOrNull()` függvényt null értékeket nem tartalmazó kollekciókhoz tervezték. Egyes függvények lambda kifejezést használnak egy kollekció transzformálásához, és null értéket adnak vissza, ha nem tudják teljesíteni a céljukat.

Egy kollekció transzformálásához lambda kifejezéssel, és az első nem null érték visszaadásához használd a `firstNotNullOfOrNull()` függvényt. Ha ilyen érték nem létezik, a függvény null értéket ad vissza:

```
fun main() {
    data class User(val name: String?, val age: Int?)
    val users = listOf(
        User(null, 25),
        User("Alice", null),
        User("Bob", 30)
    )
    val firstNonNullName = users.firstNotNullOfOrNull { it.name }
    println(firstNonNullName) // Alice
}
```

Lambda kifejezés használatával minden kollekció elemet sorban feldolgozhatsz és halmozott értéket hozhatsz létre (vagy null értéket ad vissza, ha a kollekció üres), használd a `reduceOrNull()` függvényt:

```
fun main() {
    // Egy bevásárlókocsiban lévő tételek árai
    val itemPrices = listOf(20, 35, 15, 40, 10)
    
    // A teljes ár kiszámítása a reduceOrNull() függvénnyel
    val totalPrice = itemPrices.reduceOrNull { runningTotal, price ->
        runningTotal + price
    }
    println("Total price of items in the cart: ${totalPrice ?: "No items"}") 
    // Total price of items in the cart: 120
    
    val emptyCart = listOf<Int>()
    val emptyTotalPrice = emptyCart.reduceOrNull { runningTotal, price ->
        runningTotal + price
    }
    println("Total price of items in the empty cart: ${emptyTotalPrice ?: "No items"}") 
    // Total price of items in the empty cart: No items
}
```

Ez a példa szintén az Elvis operátort `?:` használja egy nyomtatott utasítás visszaadásához, ha a függvény null értéket ad vissza. A `reduceOrNull()` függvényt null értékeket nem tartalmazó kollekciókhoz tervezték.

Fedezd fel a Kotlin standard könyvtárát, hogy több olyan függvényt találj, amelyekkel biztonságosabbá teheted a kódodat.

## Korai visszatérés és az Elvis operátor

A kezdő túrán megtanultad, hogyan használj korai visszatérést, hogy megállítsd a függvény további feldolgozását egy bizonyos ponton túl. Használhatod az Elvis operátort `?:` egy korai visszatéréssel egy függvény előfeltételeinek ellenőrzéséhez. Ez a megközelítés remek módja a kód tömörítésének, mivel nem kell beágyazott ellenőrzéseket használni. A kód csökkentett összetettsége könnyebbé is teszi a karbantartást.

Például:

```
data class User(
    val id: Int,
    val name: String,
    // Barát felhasználók azonosítóinak listája
    val friends: List<Int>
)

// Függvény egy felhasználó barátjainak számának lekéréséhez
fun getNumberOfFriends(users: Map<Int, User>, userId: Int): Int {
    // A felhasználó lekérése, vagy -1 visszaadása, ha nem található
    val user = users[userId] ?: return -1
    // A barátok számának visszaadása
    return user.friends.size
}

fun main() {
    // Néhány minta felhasználó létrehozása
    val user1 = User(1, "Alice", listOf(2, 3))
    val user2 = User(2, "Bob", listOf(1))
    val user3 = User(3, "Charlie", listOf(1))
    
    // Felhasználók térképének létrehozása
    val users = mapOf(1 to user1, 2 to user2, 3 to user3)
    
    println(getNumberOfFriends(users, 1)) // 2
    println(getNumberOfFriends(users, 2)) // 1
    println(getNumberOfFriends(users, 4)) // -1
}
```

Ebben a példában:
- Van egy `User` adatosztály, amely tulajdonságokkal rendelkezik a felhasználó azonosítójához, nevéhez és barátainak listájához.
- A `getNumberOfFriends()` függvény:
  - Elfogad egy `User` példányok térképét és egy felhasználó azonosítót egész számként.
  - Eléri a `User` példányok térképének értékét a megadott felhasználó azonosítóval.
  - Az Elvis operátort használja a függvény korai visszatéréséhez -1 értékkel, ha a térkép értéke null.
  - Hozzárendeli a térképből megtalált értéket a `user` változóhoz.
  - Visszaadja a felhasználó barátainak számát a `size` tulajdonság használatával.
- A `main()` függvény:
  - Létrehoz három `User` példányt.
  - Létrehoz egy térképet ezekből a `User` példányokból, és hozzárendeli a `users` változóhoz.
  - Meghívja a `getNumberOfFriends()` függvényt a `users` változón 1 és 2 értékekkel, amely "Alice" két barátját és "Bob" egy barátját adja vissza.
  - Meghívja a `getNumberOfFriends()` függvényt a `users` változón 4 értékkel, amely korai visszatérést vált ki -1 értékkel.

Észreveheted, hogy a kód tömörebb lenne korai visszatérés nélkül. Azonban ehhez a megközelítéshez több biztonságos hívásra van szükség, mivel a `users[userId]` null értéket adhat vissza, így a kód nehezebben olvasható:

```
fun getNumberOfFriends(users: Map<Int, User>, userId: Int): Int {
    // A felhasználó lekérése, vagy -1 visszaadása, ha nem található
    return users[userId]?.friends?.size ?: -1
}
```

Bár ez a példa csak egy feltételt ellenőriz az Elvis operátorral, több ellenőrzést is hozzáadhatsz bármely kritikus hibautak lefedéséhez. Az Elvis operátorral történő korai visszatérés megakadályozza, hogy a program felesleges munkát végezzen, és biztonságosabbá teszi a kódodat a null érték vagy érvénytelen eset azonnali észlelésével.

További információ a `return` használatáról a kódodban: Visszatérés és ugrások.

## Gyakorlás

### 1. feladat

Egy alkalmazás értesítési rendszerét fejleszted, ahol a felhasználók engedélyezhetik vagy letilthatják a különböző típusú értesítéseket. Egészítsd ki a `getNotificationPreferences()` függvényt úgy, hogy:

1. A `validUser` változó az `as?` operátort használja annak ellenőrzésére, hogy a `user` a `User` osztály példánya-e. Ha nem, üres listát adjon vissza.
2. A `userName` változó az Elvis `?:` operátort használja annak biztosítására, hogy a felhasználó neve alapértelmezetten "Guest" legyen, ha null.
3. A végső visszatérési utasítás a `.takeIf()` függvényt használja az e-mail és SMS értesítési beállítások belefoglalásához csak akkor, ha engedélyezve vannak.
4. A `main()` függvény sikeresen fusson és a várt kimenetet nyomtassa ki.

A `takeIf()` függvény visszaadja az eredeti értéket, ha az adott feltétel igaz, különben null-t ad vissza. Például:

```
fun main() {
    // A felhasználó be van jelentkezve
    val userIsLoggedIn = true
    // A felhasználónak aktív munkamenete van
    val hasSession = true
    // Hozzáférést biztosít a műszerfalhoz, ha a felhasználó be van jelentkezve
    // és aktív munkamenettel rendelkezik
    val canAccessDashboard = userIsLoggedIn.takeIf { hasSession }
    println(canAccessDashboard ?: "Access denied") // true
}
```

```
data class User(val name: String?)

fun getNotificationPreferences(user: Any, emailEnabled: Boolean, smsEnabled: Boolean): List<String> {
    val validUser = // Write your code here || Írd ide a kódodat
    val userName = // Write your code here || Írd ide a kódodat
    return listOfNotNull( /* Write your code here */)
}

fun main() {
    val user1 = User("Alice")
    val user2 = User(null)
    val invalidUser = "NotAUser"
    println(getNotificationPreferences(user1, emailEnabled = true, smsEnabled = false)) 
    // [Email Notifications enabled for Alice]
    println(getNotificationPreferences(user2, emailEnabled = false, smsEnabled = true)) 
    // [SMS Notifications enabled for Guest]
    println(getNotificationPreferences(invalidUser, emailEnabled = true, smsEnabled = true)) 
    // []
}
```

#### Megoldás
```
data class User(val name: String?)

fun getNotificationPreferences(user: Any, emailEnabled: Boolean, smsEnabled: Boolean): List<String> {
    val validUser = user as? User ?: return emptyList()
    val userName = validUser.name ?: "Guest"
    return listOfNotNull(
        "Email Notifications enabled for $userName".takeIf { emailEnabled },
        "SMS Notifications enabled for $userName".takeIf { smsEnabled }
    )
}

fun main() {
    val user1 = User("Alice")
    val user2 = User(null)
    val invalidUser = "NotAUser"
    println(getNotificationPreferences(user1, emailEnabled = true, smsEnabled = false)) 
    // [Email Notifications enabled for Alice]
    println(getNotificationPreferences(user2, emailEnabled = false, smsEnabled = true)) 
    // [SMS Notifications enabled for Guest]
    println(getNotificationPreferences(invalidUser, emailEnabled = true, smsEnabled = true)) 
    // []
}
```

### 2. feladat

Egy előfizetés-alapú streaming szolgáltatáson dolgozol, ahol a felhasználók több előfizetéssel is rendelkezhetnek, de egyszerre csak egy lehet aktív. Egészítsd ki a `getActiveSubscription()` függvényt úgy, hogy a `singleOrNull()` függvényt egy predikátummal használja null érték visszaadásához, ha egynél több aktív előfizetés van:

```
data class Subscription(val name: String, val isActive: Boolean)

fun getActiveSubscription(subscriptions: List<Subscription>): Subscription? 
// Write your code here || Írd ide a kódodat

fun main() {
    val userWithPremiumPlan = listOf(
        Subscription("Basic Plan", false),
        Subscription("Premium Plan", true)
    )
    val userWithConflictingPlans = listOf(
        Subscription("Basic Plan", true),
        Subscription("Premium Plan", true)
    )
    println(getActiveSubscription(userWithPremiumPlan)) 
    // Subscription(name=Premium Plan, isActive=true)
    println(getActiveSubscription(userWithConflictingPlans)) 
    // null
}
```

#### Megoldás 1
```
data class Subscription(val name: String, val isActive: Boolean)

fun getActiveSubscription(subscriptions: List<Subscription>): Subscription? {
    return subscriptions.singleOrNull { subscription -> subscription.isActive }
}

fun main() {
    val userWithPremiumPlan = listOf(
        Subscription("Basic Plan", false),
        Subscription("Premium Plan", true)
    )
    val userWithConflictingPlans = listOf(
        Subscription("Basic Plan", true),
        Subscription("Premium Plan", true)
    )
    println(getActiveSubscription(userWithPremiumPlan)) 
    // Subscription(name=Premium Plan, isActive=true)
    println(getActiveSubscription(userWithConflictingPlans)) 
    // null
}
```

#### Megoldás 2
```
data class Subscription(val name: String, val isActive: Boolean)

fun getActiveSubscription(subscriptions: List<Subscription>): Subscription? = 
    subscriptions.singleOrNull { it.isActive }

fun main() {
    val userWithPremiumPlan = listOf(
        Subscription("Basic Plan", false),
        Subscription("Premium Plan", true)
    )
    val userWithConflictingPlans = listOf(
        Subscription("Basic Plan", true),
        Subscription("Premium Plan", true)
    )
    println(getActiveSubscription(userWithPremiumPlan)) 
    // Subscription(name=Premium Plan, isActive=true)
    println(getActiveSubscription(userWithConflictingPlans)) 
    // null
}
```

### 3. feladat

Egy közösségi média platformon dolgozol, ahol a felhasználóknak felhasználóneve és fiókállapotuk van. Meg szeretnéd tekinteni az aktuálisan aktív felhasználónevek listáját. Egészítsd ki a `getActiveUsernames()` függvényt úgy, hogy a `mapNotNull()` függvénynek legyen egy predikátuma, amely visszaadja a felhasználónevet, ha aktív, vagy null értéket, ha nem:

```
data class User(val username: String, val isActive: Boolean)

fun getActiveUsernames(users: List<User>): List<String> {
    return users.mapNotNull { /* Write your code here */ }
}

fun main() {
    val allUsers = listOf(
        User("alice123", true),
        User("bob_the_builder", false),
        User("charlie99", true)
    )
    println(getActiveUsernames(allUsers)) // [alice123, charlie99]
}
```

Éppúgy, mint az 1. feladatban, használhatod a `takeIf()` függvényt, amikor ellenőrzöd, hogy a felhasználó aktív-e.

#### Megoldás 1
```
data class User(val username: String, val isActive: Boolean)

fun getActiveUsernames(users: List<User>): List<String> {
    return users.mapNotNull { user ->
        if (user.isActive) user.username else null
    }
}

fun main() {
    val allUsers = listOf(
        User("alice123", true),
        User("bob_the_builder", false),
        User("charlie99", true)
    )
    println(getActiveUsernames(allUsers)) // [alice123, charlie99]
}
```

#### Megoldás 2
```
data class User(val username: String, val isActive: Boolean)

fun getActiveUsernames(users: List<User>): List<String> = 
    users.mapNotNull { user ->
        user.username.takeIf { user.isActive }
    }

fun main() {
    val allUsers = listOf(
        User("alice123", true),
        User("bob_the_builder", false),
        User("charlie99", true)
    )
    println(getActiveUsernames(allUsers)) // [alice123, charlie99]
}
```

### 4. feladat

Egy e-kereskedelmi platform készletkezelési rendszerén dolgozol. Egy eladás feldolgozása előtt ellenőrizned kell, hogy a kért termékmennyiség érvényes-e az elérhető készlet alapján. Egészítsd ki a `validateStock()` függvényt úgy, hogy korai visszatérést és az Elvis operátort használ (ahol alkalmazható) annak ellenőrzésére, hogy:

- A `requested` változó null-e.
- Az `available` változó null-e.
- A `requested` változó negatív érték-e.
- A `requested` változóban lévő mennyiség nagyobb-e, mint az `available` változóban.

Az összes fenti esetben a függvény korán vissza kell térjen -1 értékkel.

```
fun validateStock(requested: Int?, available: Int?): Int {
    // Write your code here || Írd ide a kódodat
}

fun main() {
    println(validateStock(5,10)) // 5
    println(validateStock(null,10)) // -1
    println(validateStock(-2,10)) // -1
}
```

#### Megoldás
```
fun validateStock(requested: Int?, available: Int?): Int {
    val validRequested = requested ?: return -1
    val validAvailable = available ?: return -1
    if (validRequested < 0) return -1
    if (validRequested > validAvailable) return -1
    return validRequested
}

fun main() {
    println(validateStock(5,10)) // 5
    println(validateStock(null,10)) // -1
    println(validateStock(-2,10)) // -1
}
```

## Következő lépés

## Középhaladó: Könyvtárak és API-k

Ahhoz, hogy a legtöbbet hozd ki a Kotlin-ból, használj meglévő könyvtárakat és API-kat, így több időd jut a kódolásra, és kevesebb időt kell az újra feltalálására fordítani. A könyvtárak újrafelhasználható kódot terjesztenek, amely leegyszerűsíti a gyakori feladatokat. A könyvtárakon belül vannak csomagok és objektumok, amelyek kapcsolódó osztályokat, függvényeket és segédprogramokat csoportosítanak. A könyvtárak API-kat (Application Programming Interfaces - Alkalmazásprogramozási Interfészek) tesznek elérhetővé függvények, osztályok vagy tulajdonságok halmazaként, amelyeket a fejlesztők használhatnak a kódjukban.

## Kotlin könyvtárak és API-k

Fedezzük fel, mi lehetséges a Kotlin-nal.

### A standard könyvtár

A Kotlin rendelkezik egy standard könyvtárral, amely alapvető típusokat, függvényeket, kollekciókat és segédprogramokat biztosít, hogy a kódod tömör és kifejező legyen. A standard könyvtár nagy része (minden a `kotlin` csomagban) azonnal elérhető bármely Kotlin fájlban anélkül, hogy explicit módon importálni kellene:

```
fun main() {
    val text = "emosewa si niltoK"
    // A reversed() függvény használata a standard könyvtárból
    val reversedText = text.reversed()
    // A print() függvény használata a standard könyvtárból
    print(reversedText) // Kotlin is awesome
}
```

Rendben, itt van a szöveged lefordítva magyarra, a kódokat és technikai részleteket meghagyva angolul, továbbá Markdown formátumba rendezve, ahol a címsorok `#`, `##`, kódblokkok ` ``` ... ``` `, és más formázások megfelelőek:

# További információk a változások naplójában

## Kotlin 1.6.0 migráció

Az IntelliJ IDEA és Android Studio automatikusan javasolni fogja a Kotlin plugin frissítését az 1.6.0 verzióra, amint elérhető. A meglévő projektek Kotlin 1.6.0-ra való migrálásához egyszerűen változtasd meg a Kotlin verziót 1.6.0-ra, majd importáld újra a Gradle vagy Maven projektet.  
👉 [Tudj meg többet a Kotlin 1.6.0 frissítéséről.](#)

Új projekt Kotlin 1.6.0 verzióval való indításához frissítsd a Kotlin plugint, majd használd a Projektvarázslót a `File | New | Project` menüpont alatt.

Az új parancssori fordító letölthető a [GitHub kiadási oldalról](#).

> ⚠️ A Kotlin 1.6.0 egy új funkciókat tartalmazó verzió, így előfordulhatnak olyan változások, amelyek nem kompatibilisek a korábbi verziókban írt kóddal. A részletes változásokért lásd a [Kotlin 1.6 kompatibilitási útmutatóját](#).

---

## Újdonságok a Kotlin 1.5.30-ban

**Megjelent:** 2021. augusztus 24.

A Kotlin 1.5.30 nyelvi frissítéseket, jövőbeli változások előnézeteit, platform- és eszközfejlesztések további javításait, valamint új standard library funkciókat kínál.

### Fontosabb fejlesztések:
- Nyelvi funkciók, mint például:
  - Kísérleti `sealed when` utasítások
  - Változások az opt-in követelmények használatában
- Natív támogatás az Apple Silicon chiphez
- Kotlin/JS IR backend elérte a béta szintet
- Fejlesztett Gradle plugin élmény

> 💡 A kiadásban lévő változásokról [itt olvashatsz bővebben](#), illetve [itt nézheted meg a videót](#).

---

## 414. Nyelvi funkciók

A Kotlin 1.5.30 a következőket nyújtja:
- A jövőbeli nyelvi változások előnézeteit
- Fejlesztéseket az opt-in követelmény mechanizmusban
- Típus-inferencia fejlesztése rekurzív generikus típusok esetén

### Exhaustive `when` utasítások `sealed` és `Boolean` típusok esetén

A `sealed` (exhaustive) `when` utasítások támogatása **kísérleti szinten** érhető el. Előfordulhat, hogy a későbbiekben el fog távolodni vagy változik.

Az opt-in használata kötelező (lásd alább) – csak értékelés céljából használd. Várjuk a visszajelzésed [YouTracken](#).

Egy kimerítő `when` utasítás tartalmazza:
- Az összes lehetséges típust/vagy értéket a vizsgált változóra
- Egy `else` ágat a fennmaradó esetek lefedésére

Tervezzük, hogy hamarosan tiltjuk a nem kimerítő `when` utasításokat annak érdekében, hogy egységes legyen a viselkedés a `when` kifejezésekkel.

A sima migráció érdekében a compiler beállítható arra, hogy figyelmeztessen a `sealed` class vagy `Boolean` esetén nem kimerítő `when` használatra. Ezek a figyelmeztetések alapértelmezés szerint megjelennek Kotlin 1.6-ban, majd hibává válnak.

```
sealed class Mode {
    object ON : Mode()
    object OFF : Mode()
}

fun main() {
    val x: Mode = Mode.ON
    when (x) {
        Mode.ON -> println("ON")
    } // FIGYELMEZTETÉS: a sealed típuson alapuló when utasítás nem kimerítő

    val y: Boolean = true
    when (y) {
        true -> println("true")
    } // FIGYELMEZTETÉS: a Boolean típuson alapuló when utasítás nem kimerítő
}
```

A funkció engedélyezéséhez használd a `languageVersion = "1.6"` beállítást:

**build.gradle.kts (Kotlin DSL)**
```
kotlin {
    sourceSets.all {
        languageSettings.apply {
            languageVersion = "1.6"
            // progressiveMode = true // hamarosan bekapcsolható
        }
    }
}
```

**build.gradle (Groovy DSL)**
```
kotlin {
    sourceSets.all {
        languageSettings {
            languageVersion = '1.6'
            // progressiveMode = true
        }
    }
}
```

---

## 415. Felfüggeszthető (`suspend`) függvények szupertípusként

Ez a funkció **kísérleti** jellegű – változhat vagy eltávolításra kerülhet.

A Kotlin 1.5.30 támogatja egy `suspend` függvény szupertípusként történő használatát néhány korlátozással.

```
class MyClass : suspend () -> Unit {
    override suspend fun invoke() {
        TODO()
    }
}
```

Engedélyezéshez használd a `-language-version 1.6` opciót.

---

## 416. Opt-in kötelezővé tétele az implicit kísérleti API-k használata esetén

A könyvtár készítője egy `@RequiresOptIn` annotációval jelölheti meg az API-t, amely figyelmezteti a felhasználókat az annak kísérleti jellegéről.

```
// Library code
@RequiresOptIn(message = "This API is experimental.")
@Retention(AnnotationRetention.BINARY)
@Target(AnnotationTarget.CLASS)
annotation class MyDateTime

@MyDateTime
class DateProvider

// Client code
fun createDateSource(): DateProvider { /* ... */ }

fun getDate(): Date {
    val dateSource = createDateSource() // Warning: experimental API usage
}
```

---

## 417. Javítások a rekurzív generikus típusok inferenciájában

A Kotlin 1.5.30 előtt nehéz volt a rekurzív generikus típusokon dolgozni, például:

```
val containerB = PostgreSqlContainer(DockerImageName.parse("postgres:13-alpine"))
    .withDatabaseName("db")
    .withUsername("user")
    .withPassword("password")
    .withInitScript("sql/schema.sql")
```

---

## 418. Builder inferencia korlátozások megszűnése

A Kotlin 1.5.30 eltávolítja a korábbi korlátozásokat a builder inferenciára.

Példa a beállítás aktiválására:

```
@kotlin.ExperimentalStdlibApi
val list = buildList {
    add("a")
    add("b")
    set(1, null)
    val x = get(1)
    if (x != null) removeAt(1)
}
```

Engedélyezéshez használd a `-Xunrestricted-builder-inference` vagy `-language-version 1.6` opciókat.

---

## Kotlin/JVM

### Annotation class példányosítása

A Kotlin 1.5.30 támogatja az annotációk példányosítását:

```
annotation class InfoMarker(val info: String)

fun main(args: Array<String>) {
    if (args.size != 0)
        processInfo(getAnnotationReflective(args))
    else
        processInfo(InfoMarker("default"))
}
```

> Engedélyezés: `languageVersion = "1.6"`

---

## Kotlin/Native

### Apple silicon támogatás

A Kotlin 1.5.30 támogatja natívan az Apple Silicon csipeket. Új célokat vezetett be:
- `macosArm64`
- `iosSimulatorArm64`
- `watchosSimulatorArm64`
- `tvosSimulatorArm64`

### Kotlin DSL a CocoaPods pluginhez

Javították a Gradle plugin DSL-t. Példa:

```
cocoapods {
    framework {
        baseName = "MyFramework"
        isStatic = false
        export(project(":anotherKMMModule"))
        embedBitcode(BITCODE)
    }
}
```

---

## Kotlin Multiplatform

### XCFrameworks támogatása

A Kotlin Multiplatform projektek most már XCFrameworks formátumban is exportálhatók.

### Custom cinterop könyvtárak támogatása

A `kotlin.mpp.enableCInteropCommonization=true` beállítással engedélyezhető saját C interop könyvtárak használata megosztott natív kódban.

Rendben, itt van a második szövegrész lefordítva magyarra, Markdown formátumban, a kódokat és technikai szakkifejezéseket meghagyva angolul:

```
# Kotlin Multiplatform – XCFramework támogatás

A Kotlin `XCFramework` segítségével több platformhoz is létrehozhatsz egyetlen keretrendszercsomagot.

## 421. XCFramework létrehozása

**build.gradle.kts (Kotlin DSL)**
​```kotlin
import org.jetbrains.kotlin.gradle.plugin.mpp.apple.XCFramework

plugins {
    kotlin("multiplatform")
}

kotlin {
    val xcf = XCFramework()
    ios {
        binaries.framework {
            baseName = "shared"
            xcf.add(this)
        }
    }
    watchos {
        binaries.framework {
            baseName = "shared"
            xcf.add(this)
        }
    }
    tvos {
        binaries.framework {
            baseName = "shared"
            xcf.add(this)
        }
    }
}
```

**build.gradle (Groovy DSL)**
```
import org.jetbrains.kotlin.gradle.plugin.mpp.apple.XCFrameworkConfig

plugins {
    id 'org.jetbrains.kotlin.multiplatform'
}

kotlin {
    def xcf = new XCFrameworkConfig(project)
    ios {
        binaries.framework {
            baseName = "shared"
            xcf.add(it)
        }
    }
    watchos {
        binaries.framework {
            baseName = "shared"
            xcf.add(it)
        }
    }
    tvos {
        binaries.framework {
            baseName = "shared"
            xcf.add(it)
        }
    }
}
```

### Új Gradle feladatok

Az XCFramework deklarálásakor az alábbi új feladatok lesznek regisztrálva:
- `assembleXCFramework`
- `assembleDebugXCFramework` (továbbá debug artifakt, amely tartalmazza a dSYMs-t)
- `assembleReleaseXCFramework`

> 💡 Bővebben az XCFrameworks-ről a [WWDC videón](#) olvashatsz.

---

## Új alapértelmezett publikációs beállítás Android célokhoz

A `maven-publish` Gradle plugin segítségével közzéteheted a Kotlin Multiplatform könyvtáradat Android célokhoz is.

A Kotlin 1.5.30 előtt minden publikált változat tartalmazta a build típus attribútumát, ami miatt csak azonos build típussal lehetett használni a könyvtárat.

### Új viselkedés:

- Ha minden változat ugyanazzal a build típussal rendelkezik, akkor ez az attribútum elhagyásra kerül.
- Ha a változatok különböző build típusokat tartalmaznak, akkor csak a `release` változatok nem tartalmazzák ezt az attribútumot.

➡️ **Ha a régi viselkedést szeretnéd megtartani**, add hozzá a `gradle.properties` fájlhoz:

```
kotlin.android.buildTypeAttribute.keep=true
```

---

# Kotlin/JS

## 1.5.30 újdonságok

### JS IR fordító béta szintre ért

A Kotlin/JS IR backend béta verzióra ért, korábban csak alfa volt. Ez javítja a kompatibilitást, és új eszközök, mint például a **Kotlin/JS Inspection Pack IDE plugin** is elérhető.

### Jobb hibakeresési élmény IR backend használatakor

A Kotlin 1.5.30 forrástérképek (source maps) generálását is támogatja, amelyek segítenek a böngészőben vagy IntelliJ IDEA Ultimate-ban való hibakeresésben. Teljes támogatás:
- Töréspontok (breakpoints)
- Léptetés
- Olvasható stack trace

> [További információ a Kotlin/JS hibakeresésről itt.](#)

---

# Gradle fejlesztések

## Java toolchains támogatása

A Kotlin Gradle plugin mostantól támogatja a Java toolchains-t (Gradle 6.7+). Ez lehetővé teszi:
- Különböző JDK-k használatát a build-hez
- A `jvmTarget` beállítást automatikusan

### Példa:

**build.gradle.kts**
```
kotlin {
    jvmToolchain {
        (this as JavaToolchainSpec).languageVersion.set(JavaLanguageVersion.of(11))
    }
}
```

**build.gradle**
```
kotlin {
    jvmToolchain {
        languageVersion.set(JavaLanguageVersion.of(11))
    }
}
```

ℹ️ Ha a `kotlin` extension-n keresztül állítod be a toolchain-t, akkor a Java feladatok is ezt fogják használni.

---

## Könnyebb Kotlin daemon JVM argumentumok beállítása

A Kotlin 1.5.30-ban egyszerűbben lehet JVM argumentumokat megadni a Kotlin daemon számára. A következő sorrend szerinti felülírás történik:

1. Ha nincs megadva semmi, az argumentumok öröklődnek a Gradle daemon-tól.
2. Használható a `kotlin.daemon.jvm.options` rendszerváltozó.
3. A `kotlin.daemon.jvmargs` beállítás `gradle.properties`-ben.
4. Beállítás a `kotlin` extension-ben.
5. Feladat-specifikus konfiguráció.

Példa:

**build.gradle.kts**
```
kotlin {
    kotlinDaemonJvmArgs = listOf("-Xmx486m", "-Xms256m", "-XX:+UseParallelGC")
}
```

**build.gradle**
```
kotlin {
    kotlinDaemonJvmArgs = ["-Xmx486m", "-Xms256m", "-XX:+UseParallelGC"]
}
```

---

# Standard library fejlesztések

## Duration API fejlesztések

A `Duration` API továbbfejlődött, például:

### A `Duration.toString()` kimenet változása

A kiírás mostantól egység szerinti komponensek kombinációjából áll:

| Példa hívás                         | Korábbi kimenet | Új kimenet |
| ----------------------------------- | --------------- | ---------- |
| `Duration.days(45).toString()`      | `45.0d`         | `45d`      |
| `Duration.minutes(1230).toString()` | `20.5h`         | `20h 30m`  |

**Negatív értékek:** `-12m`, vagy `-(1h 30m)` formátumban.

➡️ Kis időtartamok (1 másodpercnél kisebb) egyszerű számot és al-egységet használnak: `140.884ms`, `500us`, `24ns`.

🧪 Ez a funkció kísérleti jellegű.

---

### Duration érték feldolgozása szövegként

A Kotlin 1.5.30 új függvényeket vezet be:

- `Duration.parse()`
- `Duration.parseIsoString()`
- `Duration.parseOrNull()`
- `Duration.parseIsoStringOrNull()`

Példa:

```
println(Duration.parse("1h 30m")) // "1h 30m"
println(Duration.parseOrNull("hibás érték")) // null
```

---

# Regex fejlesztések

### Regex.matchAt() és Regex.matchesAt()

Az adott pozícióban pontos egyezést keres a szövegben.

```
val releaseText = "Kotlin 1.5.30 is released!"
val regex = "\\d[.]\\d[.]\\d+".toRegex()

println(regex.matchesAt(releaseText, 7)) // true
println(regex.matchAt(releaseText, 7)?.value) // "1.5.30"
```

### Regex.splitToSequence()

Lazy szétválasztás `Sequence`-be.

```
val colorsText = "green, red , brown&blue, orange, pink&green"
val regex = "[,\\s]+".toRegex()

val mixedColor = regex.splitToSequence(colorsText)
    .onEach { println(it) }
    .firstOrNull { it.contains('&') }

println(mixedColor) // "brown&blue"
```

---

# Serialization 1.3.0-RC

Az új változat az alábbi fejlesztéseket tartalmazza:

- Java IO streamek használata sorosításhoz
- Értékek alapértelmezett értékeinek szabályozása
- Null értékek kizárása sorosításból
- Egyéni osztályazonosítók a polimorf sorosításban

> 🔍 [További információk a változásokról itt.](#)

---

# Kotlin 1.5.20 Újdonságok

**Megjelent:** 2021. június 24.

### JVM platform fejlesztések:

- String konkatenáció `invokedynamic` használatával
- JSpecify nullabilitás annotációk támogatása
- Java Lombok metódusok hívása Kotlin és Java kódból álló modulokban

### Példa a JSpecify használatára:

```
// JavaClass.java
import org.jspecify.annotations.*;

@NullMarked
public class JavaClass {
    public String notNullableString() { return ""; }
    public @Nullable String nullableString() { return ""; }
}
```

```
// Test.kt
fun kotlinFun() = with(JavaClass()) {
    notNullableString().length // OK
    nullableString().length // Warning: receiver nullability mismatch
}
```

---

## Lombok plugin (kísérleti)

A Kotlin 1.5.20 kísérleti Lombok plugin-t vezetett be, amely lehetővé teszi Lombok annotációk használatát Java forrásokban.

Támogatott annotációk:
- `@Getter`, `@Setter`
- `@NoArgsConstructor`, `@RequiredArgsConstructor`, `@AllArgsConstructor`
- `@Data`, `@With`, `@Value`

🚫 A `@Builder` jelenleg nem támogatott, de ettől a YouTracken lehet szavazni.

---

## Kotlin/Native

### Újdonságok:

- KDoc exportálása Objective-C headerbe (kísérleti)
- Array.copyInto() teljesítményjavítás

### KDoc exportálása:

Engedélyezéshez add hozzá a `build.gradle.kts`-hez:

```
-Xexport-kdoc
```

Példa:
```
/**
 * Prints the sum of the arguments.
 * Properly handles the case when the sum doesn't fit in 32-bit integer.
 */
fun printSum(a: Int, b: Int) = println(a.toLong() + b)
```
Itt van a lefordított, formázott Markdown szöveg, ahol a kódokat és szakkifejezéseket meghagytam angolul:

# Kotlin/Native fejlesztések

## KDoc exportálása Objective-C headerbe

A Kotlin/Native mostantól támogatja a KDoc kommentek Objective-C headerbe való exportálását is.

**build.gradle.kts**
```
kotlin {
    targets.withType<org.jetbrains.kotlin.gradle.plugin.mpp.KotlinNativeTarget> {
        compilations.get("main").kotlinOptions.freeCompilerArgs += "-Xexport-kdoc"
    }
}
```

**build.gradle**
```
kotlin {
    targets.withType(org.jetbrains.kotlin.gradle.plugin.mpp.KotlinNativeTarget) {
        compilations.get("main").kotlinOptions.freeCompilerArgs += "-Xexport-kdoc"
    }
}
```

🧪 **Ez a funkció kísérleti.** Visszajelzést szívesen fogadunk [itt](#).

---

## Compiler hibajavítások

A Kotlin/Native compiler számos hibát javított a 1.5.20-ban. Fontos változás:

- Hibás UTF szürrogát párokat tartalmazó string konstansok értékei már nem vesznek el fordítás során.
- **Kompatibilitási megjegyzés**: Az új verzióval lefordított könyvtárak nem kompatibilisek régebbi compiler verziókkal.

---

## Array.copyInto() teljesítményjavítása

A `copyInto()` függvény sebessége jelentősen megnőtt, amikor ugyanazon tömböt használja forrásként és célként is – akár 20-szoros javulás is elérhető.

---

# Kotlin/JS 1.5.20

## Migrációs útmutató az IR backendhez

A Kotlin/JS IR backend felé való migráláshoz [itt található útmutató](#), amely segít az átállásban.

---

# Gradle fejlesztések (431.)

## Újdonságok:

### Kapt classloader caching (kísérleti)

A kapt-ban cach-elhetőek a classloader-ek. Ez felgyorsíthatja a Gradle futtatását.

```
# gradle.properties
kapt.classloaders.cache.size=5
kapt.include.compile.classpath=false
```

### `kotlin.parallel.tasks.in.project` elavult

A párhuzamos fordítás mostantól a Gradle `--parallel` flagjével irányítható, így a `kotlin.parallel.tasks.in.project` beállítás elavult.

---

# Standard library fejlesztések

## Char.digitToInt() – minden Unicode számjegy támogatott (Native és JS platformon)

```
val ten = '\u0661'.digitToInt() + '\u0039'.digitToInt() // 1 + 9
println(ten) // 10
```

## Char.isLowerCase()/isUpperCase() platformfüggetlenítve

Mostantól minden platformon ugyanúgy működik:

```
val circledLatinCapitalA = 'Ⓐ'
println(circledLatinCapitalA.isUpperCase()) // true
```

---

# Újdonságok a Kotlin 1.5.0-ban

**Megjelent:** 2021. május 5.

## Nyelvi fejlesztések

### JVM records támogatása

```
@JvmRecord
data class User(val name: String, val age: Int)
```

### Sealed interface-ek

```
sealed interface Polygon
class Rectangle : Polygon
class Triangle : Polygon

fun draw(polygon: Polygon) = when (polygon) {
    is Rectangle -> // ...
    is Triangle -> // ...
    // nincs szükség else-re
}
```

### Package-szintű sealed hierarchia

A sealed osztályok most már több fájlban is lehetnek, ugyanabban a csomagban.

### Inline class-ok

```
@JvmInline
value class Password(val s: String)
```

> ⚠️ A régi `inline` modifier elavult.

---

# Kotlin/JVM

## Stabil IR backend

Az IR backend mostantól alapértelmezett, és stabil.

**Régi backend használata (ha szükséges):**

**Gradle:**
```
tasks.withType<org.jetbrains.kotlin.gradle.dsl.KotlinJvmCompile> {
    kotlinOptions.useOldBackend = true
}
```

### Új alapértelmezett JVM cél: 1.8

### SAM adapterek és lambdák invokedynamic segítségével

Használja a `LambdaMetafactory.metafactory()` hívásokat a bonyolult wrapper osztályok helyett.

---

### Elavult: `@JvmDefault` és a régi `-Xjvm-default` módok

---

## Nullabilitás annotációk fejlesztése

Jobb kezelés:
- Típusargumentumokon
- `TYPE_USE` célú annotációkon

---

# Kotlin/Native

## Teljesítményjavítások

- Fordítási sebesség növekedés (akár 200% a tesztprojekteken)
- Cachelés támogatása: `linuxX64`, `iosArm64`

**gradle.properties**
```
kotlin.native.cacheKind.linuxX64=static
kotlin.native.cacheKind.iosArm64=static
```

### Tulajdonság-getterek inline-ba kerülnek
### `trimIndent()` kiértékelése fordítás közben
### Memóriavesztés-ellenőrző kikapcsolva

```
Platform.isMemoryLeakCheckerActive = true // ha szükséges
```

---

# Kotlin/JS

## Webpack 5 frissítés

A Kotlin/JS plugin mostantól a webpack 5-öt használja.

## Framework támogatás

Támogatott framework-ök:
- KVision
- fritz2
- doodle

---

# Kotlin Multiplatform

## Egyszerűbb tesztelési függőségek

Gradle automatikusan kezeli a platformspecifikus teszt könyvtárakat.

---

# Standard library frissítések (439.)

## Stabil unsigned típusok

- `UInt`, `ULong`, `UByte`, `UShort`
- Műveletek, tartományok – minden stabil

## Locale-független nagybetűsítés

Új API:

```
"Kotlin".uppercase() // helyett: toUpperCase()
"Kotlin".lowercase()
```

## Új Char kategória API

```
val category = 'A'.category
```

## Első nem null érték keresése

```
val result = list.firstNotNullOf { it.valueOrNull() }
```

## Szigorú `String?.toBoolean()`

```
"true".toBooleanStrict() // csak exact match-re működik
```

---

Itt van a lefordított és Markdown formázott szöveg, ahol a technikai kifejezéseket és kódokat meghagytam angolul:

# Kotlin 1.5.0 újdonságok és változások

## Stabil alternatívák a szövegkezelő függvényekhez (440.)

### String:

| Korábban | 1.5.0 alternatíva |
|----------|--------------------|
| `String.toUpperCase()` | `String.uppercase()` |
| `String.toLowerCase()` | `String.lowercase()` |
| `String.capitalize()` | `String.replaceFirstChar { it.uppercase() }` |
| `String.decapitalize()` | `String.replaceFirstChar { it.lowercase() }` |

### Char:

| Korábban | 1.5.0 alternatíva |
|----------|--------------------|
| `Char.toUpperCase()` | `Char.uppercaseChar(): Char` vagy `Char.uppercase(): String` |
| `Char.toLowerCase()` | `Char.lowercaseChar(): Char` vagy `Char.lowercase(): String` |
| `Char.toTitleCase()` | `Char.titlecaseChar(): Char` vagy `Char.titlecase(): String` |

> Kotlin/JVM esetén elérhetőek `uppercase()`, `lowercase()`, `titlecase()` függvények explicit `Locale` paraméterrel is.

A régi API-k elavultként lettek megjelölve, és később el lesznek távolítva.

---

## Stabil Char → egész konverziós API (441.)

### Új függvények:

- **Karakter kódjának lekérdezése / létrehozás:**
  ```
  fun Char(code: Int): Char
  fun Char(code: UShort): Char
  val Char.code: Int
  ```

- **Számjegy → érték:**
  ```
  fun Char.digitToInt(radix: Int): Int
  fun Char.digitToIntOrNull(radix: Int): Int?
  ```

- **Érték → karakter:**
  ```
  fun Int.digitToChar(radix: Int): Char
  ```

A régi API-k (például `Char.toInt()`, `Number.toChar()` stb.) elavultként lettek megjelölve.

---

## Stabil Path API (441.)

A `java.nio.file.Path` kiterjesztések mostantól stabilak:

```
val baseDir = Path("/base")
val subDir = baseDir / "subdirectory"

val kotlinFiles = Path("/home/user").listDirectoryEntries("*.kt")
```

---

## Padlásos osztás és modulus operátor

Új függvények moduláris aritmetikához:

- `a.floorDiv(b)`: lefelé kerekített osztás eredménye
- `a.mod(b)`: modulus (maradék), ami negatív számoknál is a `b` előjelével egyezik

```
fun main() {
    println("Floored division -5/3: ${(-5).floorDiv(3)}") // -2
    println("Modulus: ${(-5).mod(3)}") // 1
    println("Truncated division -5/3: ${-5 / 3}") // -1
    println("Remainder: ${-5 % 3}") // -2
}
```

---

## Duration API változások

A Duration API kísérleti jellegű – változhat a jövőben.

### Frissítések:
- A belső reprezentáció `Double` helyett mostantól `Long`
- Új API: `Duration.inWholeMinutes`, `Duration.seconds(10)` stb.

```
val duration = Duration.milliseconds(120000)
println("There are ${duration.inWholeSeconds} seconds in ${duration.inWholeMinutes} minutes")
```

---

## Új karakterkategória API (442.)

A karakterkategória ellenőrzés multiplatform kódban is elérhető:

```
val chars = listOf('a', '1', '+')
val (letterOrDigitList, notLetterOrDigitList) = chars.partition { it.isLetterOrDigit() }
```

Egyéb:
- `Char.isDefined()`, `Char.isISOControl()`
- `Char.category` és `CharCategory` enum

---

## Új kollekció-függvény: `firstNotNullOf()`

```
val data = listOf("Kotlin", "1.5")
println(data.firstNotNullOf(String::toDoubleOrNull)) // 1.5
println(data.firstNotNullOfOrNull(String::toIntOrNull)) // null
```

---

## Szigorú `toBoolean()` változatok

- `String.toBooleanStrict()` – csak `"true"` vagy `"false"`
- `String.toBooleanStrictOrNull()` – nem érvényes bemenet esetén `null`

```
println("true".toBooleanStrict()) // true
println("1".toBooleanStrictOrNull()) // null
```

---

# kotlin-test library (443.)

## Egyszerűbb tesztfüggőségek

A `commonTest` függőségekből Gradle automatikusan felismeri a platformspecifikus teszt keretrendszereket:

```
val commonTest by getting {
    dependencies {
        implementation(kotlin("test"))
    }
}
```

Ez beveszi:
- `kotlin-test-junit` JVM esetén
- `kotlin-test-js` Kotlin/JS esetén
- `kotlin-test-common` és `kotlin-test-annotations-common` közös kódhoz

JUnit 5/TestNG választása:

```
tasks {
    test {
        useJUnitPlatform() // vagy useTestNG()
    }
}
```

---

## Új assert függvények

### Típusellenőrzés:
```
val s: Any = "test"
assertIs<String>(s)
```

### Kollekció tartalom összehasonlítása:
```
assertContentEquals(expectedArray, actualArray)
```

### Float/Double összehasonlítás toleranciával:
```
assertEquals(0.0, x, tolerance)
```

### Tartalom vizsgálata:
```
assertContains(sampleList, sampleString)
assertContains(sampleString, "amp")
```

### Inline assert függvények:
```
assertTrue { deferred.await().contains("Kotlin") }
```

---

# kotlinx library-k

### kotlinx.coroutines 1.5.0-RC
- Új channels API
- Stabil reaktív integrációk
- Eltávolítva az experimental coroutines támogatás

### kotlinx.serialization 1.2.1
- JSON sorosítás teljesítményjavítás
- Több név támogatása JSON-ben
- `.proto` séma generálás (kísérleti)

### kotlinx-datetime 0.2.0
- `@Serializable` dátumobjektumok
- Egységesített `DateTimePeriod` és `DatePeriod` API

---

# Migráció Kotlin 1.5.0-re

Az IntelliJ IDEA és Android Studio automatikusan javasolja a Kotlin plugin frissítését.

Lépések:
1. Állítsd át a Kotlin verziót `1.5.0`-ra
2. Újraimportáld a Gradle/Maven projektet

---

# Kotlin 1.4.30 újdonságok

**Megjelent:** 2021. február 3.

## Nyelvi fejlesztések előnézete

A következő funkciókat lehet kipróbálni:

- JVM record támogatás (kísérleti)
- Sealed interface-ek
- Fejlesztett inline class-ok

### JVM Records (kísérleti)

```
@JvmRecord
data class User(val name: String, val age: Int)
```

Engedélyezéshez használd:
```
-Xjvm-enable-preview
-language-version 1.5
```

---

### Sealed interfészek (kísérleti)

```
sealed interface Polygon
class Rectangle : Polygon
class Triangle : Polygon

fun draw(polygon: Polygon) = when (polygon) {
    is Rectangle -> // ...
    is Triangle -> // ...
}
```

---

### Package-szintű sealed osztály hierarchia (kísérleti)

A `sealed` osztályok már nem kötelező, hogy egy fájlban legyenek.

---

### Fejlesztett inline class-ok (béta)

- Új szintaxis: `value class`
- `@JvmInline` szükséges JVM backenden
- `init` blokk támogatás

```
@JvmInline
value class Negative(val x: Int) {
    init {
        require(x < 0)
    }
}
```

---

🔗 Visszajelzést küldhetsz a [YouTrack](#) oldalon!

# Kotlin 1.4.30 újdonságok

## Inline class új mangling sémája

A Kotlin compiler a 1.4.30-tól új mangling sémát használ alapértelmezettként.

➡️ **Régi séma használata (kompatibilitásért):**

-Xuse-14-inline-classes-mangling-scheme



### Inline class-ok béta állapotba léptek

A `value class` / `inline class` béta szintre ért, és stabilizálódni fognak a jövőbeli verziókban.

✔️ **Kipróbáláshoz:**

-Xinline-classes vagy -language-version 1.5



🔗 [Részletes magyarázat a mangling működéséről itt](#).

---

## Kotlin/JVM

### JVM IR compiler backend béta

Az új backend béta állapotba ért – ez az utolsó lépés a stabilizálás előtt.

✅ Mostantól használhatod harmadik fél számára is, például könyvtárak készítéséhez.

🔧 **Engedélyezés Gradle-ben:**

```
tasks.withType(org.jetbrains.kotlin.gradle.dsl.KotlinJvmCompile::class) {
    kotlinOptions.useIR = true
}
```

**Maven-ben:**



```
<configuration>
  <args>
    <arg>-Xuse-ir</arg>
  </args>
</configuration>
```

------

## Kotlin/Native

### Teljesítményjavítások

Gyorsabb fordítás érhető el – például a sample projektben a framework rebuild ideje 9.5 → 4.5 másodpercre csökkent.

### watchOS 64 bites szimulátor

Az új `watchosX64` cél a 64 bites watchOS szimulátorhoz.

### Xcode 12.2 támogatás

A Xcode 12.2 új könyvtárai használhatóak Kotlin kódból.

------

## Kotlin/JS

### Lusta inicializálás (lazy) a top-level property-eknél (kísérleti)

Csökkenti az indítási időt – nem kell az összes változót előre inicializálni.

✅ **Használat:**



```
-Xir-property-lazy-initialization
```

------

## Gradle projekt fejlesztések

### Gradle configuration cache támogatás

Gyorsítja a buildelést azáltal, hogy újrahasználja a konfigurációkat.

------

## Standard library

### Locale-független szövegkezelés (kísérleti)

Új API a kis- és nagybetű átalakításhoz.

| Korábban         | 1.4.30 alternatíva                    |
| :--------------- | :------------------------------------ |
| `toUpperCase()`  | `uppercase()`                         |
| `toLowerCase()`  | `lowercase()`                         |
| `capitalize()`   | `replaceFirstChar { it.uppercase() }` |
| `decapitalize()` | `replaceFirstChar { it.lowercase() }` |

Példa:



```
println("Needs to be capitalized".uppercase()) // NEEDS TO BE CAPITALIZED
```

------

### Karakter → érték konverziók (kísérleti)

Korábban félreérthető volt a `Char.toInt()` függvény viselkedése.

✅ **Mostantól külön függvények:**



```
fun Char(code: Int): Char
val Char.code: Int
fun Char.digitToInt(radix: Int): Int
fun Int.digitToChar(radix: Int): Char
```

------

## Serialization frissítés

A `kotlinx.serialization 1.1.0-RC` új funkcionalitásokat is hoz:

### Inline osztályok sorosítása



```
@Serializable
inline class Color(val rgb: Int)
```

➡️ Szükséges: új IR compiler (1.4.30+)

### Előjel nélküli típusok sorosítása

Támogatott típusok:

- `UInt`, `ULong`, `UByte`, `UShort`

Példa:



```
@Serializable
class Counter(val counted: UByte, val description: String)

fun main() {
    val counted = 239.toUByte()
    println(Json.encodeToString(Counter(counted, "tries")))
}
```

------

# Kotlin 1.4.20 újdonságok

**Megjelent:** 2020. november 23.

------

## Kotlin/JVM

### Java 15 támogatás

A Kotlin/JVM célként támogatja a Java 15-öt.

### `invokedynamic` sztring összefűzés (kísérleti)

Javított teljesítmény a JVM 9+ verziónál.

✅ **Beállítások:**

- `indy-with-constants` – `makeConcatWithConstants()`
- `indy` – `makeConcat()`
- `inline` – klasszikus `StringBuilder.append()` módszer

➡️ Engedélyezés:



```
-Xstring-concat=indy-with-constants
```

------

## Kotlin/JS

### Gradle DSL fejlesztések

#### Egységes webpack konfiguráció



```
browser {
    commonWebpackConfig {
        cssSupport.enabled = true
    }
}
```

#### package.json testreszabása



```
kotlin {
    js(BOTH) {
        compilations["main"].packageJson {
            customField("hello", mapOf("one" to 1, "two" to 2))
        }
    }
}
```

#### Yarn függőségi felülírások (kísérleti)



```
rootProject.plugins.withType<YarnPlugin> {
    rootProject.the<YarnRootExtension>().apply {
        resolution("react", "16.0.0")
    }
}
```

------

### Új sablonok a projektvarázslóban

- **Browser Application** – egyszerű browseres Kotlin/JS projekt
- **React Application** – React + kotlin-wrappers
- **Node.js Application** – Node.js futtatókörnyezet

------

## Kotlin/Native

### Escape analysis (kísérleti)

A heap helyett stackre kerülhetnek bizonyos objektumok, ami gyorsabbá teszi a programot.

🔧 **Kiiktatás:**



```
-Xdisable-phases=EscapeAnalysis
```

### Objective-C kivételek kezelése (kísérleti)

A `ForeignException` típusba burkolja az `NSException`-öket, elkerülve a program összeomlását.

🔧 **Engedélyezés:**



```
pod("lib") {
    extraOpts = listOf("-Xforeign-exception-mode", "objc-wrap")
}
```

### CocoaPods plugin fejlesztések

- Jobb task végrehajtás – függőségek nem fordulnak újra feleslegesen
- Új DSL-elemek: git repo-ból, archive-ból, statikus lib-ből is hozzáadhatsz Podokat
- Testreszabható cinterop opciók

# Kotlin 1.4.20 újdonságok (folytatás)

## CocoaPods integráció – Xcode frissítések

### Frissített integráció az Xcode-dal

A Kotlin Podfile módosításokat igényel az Xcode megfelelő működéséhez:

- Ha a Kotlin Pod Git, HTTP vagy specRepo függőséggel rendelkezik, azt is meg kell adni a Podfile-ban.
- Egyéni spec repository használatakor a Podfile elején meg kell adni a specifikációk helyét.
- A hibák mostantól részletes leírással jelennek meg az IntelliJ IDEA-ban.

### Xcode 12 könyvtárak támogatása

A Xcode 12 új könyvtárai használhatóak Kotlin kódból.

---

## Kotlin Multiplatform

### Multiplatform könyvtárak publikációs struktúrája

A 1.4.20-tól nincs külön metaadat kiadvány – a metaadatokat a gyökércsomag tartalmazza, ami automatikusan a megfelelő platformspecifikus változatot tölti be.

📍 **Kompatibilitás:**
- A hierarchikus projektstruktúrával rendelkező projekteknek egyszerre kell frissülniük.
- A régi verziókkal közzétett könyvtárak nem kompatibilisek az új verziókkal.

---

## Standard library

### `java.nio.file.Path` kiterjesztések (kísérleti)

```
val baseDir = Path("/base")
val subDir = baseDir / "subdirectory"
val kotlinFiles = Path("/home/user").listDirectoryEntries("*.kt")
```

➡️ Használatához: `kotlin-stdlib-jdk7` modul szükséges, és opt-in szükséges: `@ExperimentalPathApi`.

### `String.replace()` teljesítményjavítás

Az új implementáció gyorsabb működést biztosít, különösen case-sensitive mód esetén.

------

## Kotlin Android Extensions – elavult komponensek

### Szintetikus nézetek elavulttá váltak

A Google Android Jetpack View Binding megoldást ajánlja, ezért a Kotlin plugin szintetikus nézetei elavulttá váltak.

### Új Parcelable plugin: `kotlin-parcelize`

A `@Parcelize` annotáció mostantól a `kotlinx.parcelize` csomagban található.

🔧 **Átállás:**



```
plugins {
    id("kotlin-parcelize")
}
```

------

# Kotlin 1.4.0 újdonságok

**Megjelent:** 2020. augusztus 17.

------

## Nyelvi fejlesztések

### SAM konverzió Kotlin interfészekre



```
fun interface IntPredicate {
    fun accept(i: Int): Boolean
}

val isEven = IntPredicate { it % 2 == 0 }
```

------

### Explicit API mód könyvtárfejlesztőknek



```
kotlin {
    explicitApi() // strict mód
    // vagy
    explicitApiWarning() // figyelmeztetés
}
```

------

### Keverhető névvel/név nélküli argumentumok



```
reformat("This is a String!", uppercaseFirstLetter = false, '-')
```

------

### Lezáró vesszőt támogatás



```
fun format(
    str: String,
    uppercaseFirstLetter: Boolean = true,
    wordSeparator: Char = ' ', // lezáró vessző
) { }
```

------

### Callable reference fejlesztések

- Paraméterek alapértelmezett értékének támogatása
- Unit-os függvényekhez való referencia
- Vararg paraméterekhez való adapter
- `suspend` konverzió callable reference esetén



```
fun call() {}
fun takeSuspend(f: suspend () -> Unit) {}

takeSuspend(::call) // 1.4-től működik
```

------

### `break` és `continue` `when` kifejezésen belül



```
for (x in xs) {
    when (x) {
        2 -> continue
        17 -> break
        else -> println(x)
    }
}
```

------

## Új IDE eszközök

### Új projektvarázsló

- Rugalmas sablonválasztás (multiplatform, JVM, JS stb.)
- Konfigurálható célok és modulok
- Build rendszer választása (Gradle, Maven, stb.)

### Coroutines Debugger

- Debug ablakban "Coroutines" fül
- Futó és felfüggesztett coroutine-ok állapotának nyomon követése
- Full dump letöltése a coroutine állapotáról

------

## Új fordító

### Teljesítmény és egységesség

- Új típus-inferencia algoritmus (alapértelmezett)
- Új IR backend-ek (JVM és JS)
- Egységesíti a platformok kódgenerálását

### Új típus-inferencia előnyei

✅ Több típus automatikusan kikövetkeztethető
✅ Smart castok lambda utolsó kifejezésére
✅ Callable reference-oknál is működik

Példa:



```
val rulesMap: Map<String, (String?) -> Boolean> = mapOf(
    "weak" to { it != null },
    "strong" to { it != null && "^[a-zA-Z0-9]+$".toRegex().matches(it) }
)
```

Smart cast lambda végén:



```
val result = run {
    var str = currentValue()
    if (str == null) {
        str = "test"
    }
    str // mostantól String típusú
}
```

Callable reference smart cast-tal:



```
sealed class Animal
class Cat : Animal() {
    fun meow() { println("meow") }
}

fun perform(animal: Animal) {
    val kFunction: KFunction<*> = when (animal) {
        is Cat -> animal::meow // smart cast
        else -> TODO()
    }
    kFunction.call()
}
```

# Kotlin 1.4.0 újdonságok (folytatás)

## Típus-inferencia további fejlesztések

### Delegált property-k jobb inferenciája

A következő korábban nem működött kód most már helyesen működik:

```
import kotlin.properties.Delegates

var prop: String? by Delegates.observable(null) { p, old, new ->
    println("$old → $new")
}
prop = "abc"
prop = "xyz"
```

### SAM konverzió Java interfészekre különböző argumentumokkal

Most már NATÚR módon lehet keverni lambda és objektum argumentumokat:



```
// Java
public class A {
    public static void foo(Runnable r1, Runnable r2) {}
}
```



```
// Kotlin
fun test(r1: Runnable) {
    A.foo(r1) {} // Működik a 1.4-ben
}
```

Java SAM interfészek használata Kotlinból:



```
import java.lang.Runnable

fun foo(r: Runnable) {}

fun test() {
    foo { } // OK
}
```

------

## Egységesített backend-ek és bővíthetőség

### Egységes IR alapú backend-ek

A Kotlin most már három platformot támogat egységes infrastruktúrával:

- Kotlin/JVM
- Kotlin/JS
- Kotlin/Native

Mindegyik mostantól IR alapú, ami lehetővé teszi:

- Funkciók egyszeri implementálását
- Optimalizációk automatikus alkalmazását minden platformon

🔧 **Új backend kipróbálása JVM-nél:**



```
kotlinOptions.useIR = true
```

Parancssorból:



```
-Xuse-ir
```

⚠️ **Megjegyzés:** A kódot csak akkor lehet használni, ha az új backenddel lett lefordítva.

------

### Új mód a default metódusok generálására



```
-Xjvm-default=all
```

Ez az összes Kotlin interfész metódust default Java metódussá alakítja.

------

### Egységesített kivételkezelés null ellenőrzéseknél

Mostantól minden futásidejű null ellenőrzés `java.lang.NullPointerException`-t dob:

✅ Érintett esetek:

- `!!` operátor
- Paraméter null ellenőrzések
- Platform típus ellenőrzések
- `as` operátor non-null típusokkal

❌ Nem érinti:

- `lateinit` null ellenőrzések
- `checkNotNull`, `requireNotNull` stb.

------

### Típus annotációk a JVM bytecode-ban

Type annotációk mostantól elérhetőek Java reflection segítségével:



```
@Target(AnnotationTarget.TYPE)
annotation class Foo

class A {
    fun foo(): @Foo String = "OK"
}
```

🔧 **Fordítási beállítások:**



```
-jvm-target=1.8
-Xemit-jvm-type-annotations
```

------

## Kotlin/JS fejlesztések

### Új Gradle DSL

- Executable fájlok konfigurálása: `binaries.executable()`
- CSS támogatás: `cssSupport`
- npm függőségek kezelése: `devNpm`, `peerNpm`, `optionalNpm`

### Új JS IR backend (alfa)

- Halott kód eltávolítás (kisebb méret)
- Jobb JavaScript és TypeScript együttműködés
- TypeScript definíciók generálása

🔧 **Aktiválás:**

`gradle.properties` fájlban:



```
kotlin.js.compiler=ir
```

Vagy Gradle-ben:



```
kotlin {
    js(IR) {
        binaries.executable()
    }
}
```

------

## Kotlin/Native fejlesztések

### Suspending függvények Swift és Objective-C-ben

Kotlin:



```
suspend fun queryData(id: Int): String = ...
```

Swift:



```
queryData(id: 17) { result, error in
    if let e = error {
        print("ERROR: \(e)")
    } else {
        print(result!)
    }
}
```

------

### Objective-C generikus támogatás alapértelmezettként

Korábban ez kísérleti volt – most már alapértelmezett.

🔧 **Visszatérés a régi módhoz:**



```
-Xno-objc-generics
```

------

### Kivételkezelés Swift-ben

A Kotlin kivételek most `@Throws` annotáció alapján lesznek `NSError`-ként kezelve.



```
@Throws(IOException::class)
fun riskyOperation() { ... }
```

------

### .dSYM fájlok generálása release buildnél

Alapértelmezetten engedélyezve van Darwin platformokon.

🔧 **Letiltás:**



```
-Xadd-light-debug=disable
```

------

### Teljesítményjavítások

- `mimalloc` memória allokátor (akár 2x gyorsabb néhány esetben)
- C interop könyvtárak gyorsabb fordítása (4x gyorsabb, 25-30% kisebb méret)
- GC optimalizációk
- HashMap és HashSet gyorsabb működése

------

### Egyszerűbb CocoaPods függőségkezelés

Mostantól IntelliJ IDEA-ból is kezelhető:

- Pod függőségek hozzáadása
- Projekt újraimportálása elég
- Nincs szükség Xcode váltásra minden alkalommal

------

## Kotlin Multiplatform (kísérleti)

### Hierarchikus projektstruktúra (alfa)

Új forrásstruktúra lehetővé teszi:

- Kód megosztás csak bizonyos platformok között
- Pl. iOS device és simulator közös kódja



```
kotlin {
    ios() // iosMain és iosTest source set-ek automatikusan
}
```

```
# Kotlin Multiplatform – Hierarchikus projektstruktúra

## Cél-interface szintű megosztás

### Előre definiált célokhoz (pl. `ios()`)

​```kotlin
kotlin {
    ios() // iosMain és iosTest automatikusan létrejön
}
```

### Egyéni célokhoz – manuális hierarchia



```
kotlin {
    sourceSets {
        val desktopMain by creating {
            dependsOn(commonMain)
        }
        val linuxX64Main by getting {
            dependsOn(desktopMain)
        }
        val mingwX64Main by getting {
            dependsOn(desktopMain)
        }
        val macosX64Main by getting {
            dependsOn(desktopMain)
        }
    }
}
```

Groovy DSL esetén:



```
kotlin {
    sourceSets {
        desktopMain {
            dependsOn(commonMain)
        }
        linuxX64Main {
            dependsOn(desktopMain)
        }
        mingwX64Main {
            dependsOn(desktopMain)
        }
        macosX64Main {
            dependsOn(desktopMain)
        }
    }
}
```

🔗 **Könyvtárak is támogatják**: egyes célokhoz közös API-k.

------

## Natív könyvtárak használata megosztott kódban

Platform-függő könyvtárak (mint Foundation, UIKit, POSIX) mostantól használhatók natív célok között megosztott forrásfájlokban.
🔧 **Automatikus** – nincs külön konfiguráció szükséges.

------

## Függőségek egyszeri deklarálása

Megosztott forrásban elég egyszer deklarálni:



```
kotlin {
    sourceSets {
        val commonMain by getting {
            dependencies {
                implementation("org.jetbrains.kotlinx:kotlinx-coroutines-core:1.10.2")
            }
        }
    }
}
```

🔧 **NE használj platform-szuffixeket** mint `-common`, `-native` – ezek elavultak.

➡️ Kivétel:

- `stdlib` – automatikusan hozzáadva
- `kotlin.test` – továbbra is `test-common`, `test-annotations-common`

Ha csak egy platformra kell függőség:



```
implementation("kotlinx-coroutines-core-jvm")
```

------

# Gradle projekt fejlesztések

## Stdlib függőség automatikusan

➡️ **Nem kell kézzel hozzáadni**

- A stdlib verziója megegyezik a Kotlin plugin verziójával
- Platformspecifikus változatok automatikusan választva

🔧 A JVM stdlib a `kotlinOptions.jvmTarget` alapján kerül kiválasztásra.

------

## Minimális Gradle verzió

| Projekt típus | Szükséges Gradle verzió |
| :------------ | :---------------------- |
| Multiplatform | 6.0+                    |
| Egyéb Kotlin  | 5.4+                    |

------

## `*.gradle.kts` fájlok támogatása IDE-ben

### Fejlesztések:

- Konfiguráció explicit betöltése (jobb teljesítmény)
  - Gradle < 6.0: **Load Configuration**
  - Gradle ≥ 6.0:
    - **Load Script Configurations** – csak script változások
    - **Load Gradle Changes** – teljes projekt újratöltés

🔧 **Init scriptekhez (`init.gradle.kts`)** régi mechanizmus szükséges – `Add to standalone scripts`.

### Hibajelentés javítva:

- Részletes hibák megjelennek a **Build** ablakban

------

# Standard library fejlesztések (476.)

## Kivételkezelés API közösítve

A következők mostantól minden platformon elérhetők:

- `Throwable.stackTraceToString()`
- `Throwable.printStackTrace()`
- `Throwable.addSuppressed()`, `Throwable.suppressedExceptions`
- `@Throws` annotáció

------

## Kollekciók – új függvények

### Újak:

- `setOfNotNull()` – csak nem-null elemek
- `shuffled()` – sequence-ekre is
- `onEachIndexed()`, `flatMapIndexed()`
- `randomOrNull()`, `reduceOrNull()`, `reduceIndexedOrNull()`
- `runningFold()`, `runningReduce()`, `scan()`
- `sumOf()` – összeg kiszámítása selector alapján
- `minOf()`, `maxOf()` – min/max kiválasztása selector alapján
- `flatMap()` új overloadok: `Iterable -> Sequence`, stb.
- `removeFirst()`, `removeLast()`, `*orNull()` változatok

------

### Tömbök:

- `shuffle()`
- `onEach()`
- `associateWith()`
- `reverse()`, `sortDescending()` – résztömbökre is
- `sort()`, `sortWith()` – megosztott forrásból

Konverziók:

- `ByteArray.decodeToString()`, `String.encodeToByteArray()`
- `CharArray.concatToString()`, `String.toCharArray()`

------

### `ArrayDeque` osztály

Dupla végű sor – O(1) beszúrás/eltávolítás mindkét végén:



```
val deque = ArrayDeque(listOf(1, 2, 3))
deque.addFirst(0)
deque.addLast(4)
println(deque) // [0, 1, 2, 3, 4]
```

------

## Sztringkezelés

### `StringBuilder` új függvények:

- `set()`, `setRange()`
- `deleteAt()`, `deleteRange()`
- `appendRange()`

### Új függvények:

- `Appendable.appendLine()`, `StringBuilder.appendLine()`

------

## Bitműveletek

- `countOneBits()`
- `countLeadingZeroBits()`
- `countTrailingZeroBits()`
- `takeHighestOneBit()`, `takeLowestOneBit()`
- `rotateLeft()`, `rotateRight()` *(kísérleti)*

------

## Delegált property fejlesztések

- Property delegálható másik property-re
- `PropertyDelegateProvider` interface
- `ReadWriteProperty` most már kiterjeszti `ReadOnlyProperty`-t
- Bytecode optimalizációk

------

## `KType` → Java `Type` konverzió



```
@OptIn(ExperimentalStdlibApi::class)
inline fun <reified T> accessReifiedTypeArg() {
    val kType = typeOf<T>()
    println("Java type: ${kType.javaType}")
}
```

------

## Proguard konfiguráció

A `kotlin-reflect.jar` tartalmazza a szükséges Proguard szabályokat – többé nem kell kézzel hozzáadni.

------

## API fejlesztések

### Null engedélyezett receiverrel:

- `toBoolean()` (sztringekre)
- `contentEquals()`, `contentHashCode()`, `contentToString()` (tömbökre)

### Konstansok:

- `NaN`, `NEGATIVE_INFINITY`, `POSITIVE_INFINITY` – annotációban használhatók
- `SIZE_BITS`, `SIZE_BYTES` új Double/Float értékek

------

## `module-info.java` leírók

A stdlib alapértelmezetten tartalmazza – kompatibilis `jlink` használatával.

------

## Elavultságok

### `Double` és `Float` – veszélyes konverziók:

- `toShort()` és `toByte()` elavult – használj kétlépcsős konverziót: `toDouble().toInt().toShort()`

### Lebegőpontos tömbök:

- `contains()`, `indexOf()`, `lastIndexOf()` elavult – IEEE 754 szabályok miatt

### Kollekciók:

- `min()` és `max()` → `minOrNull()`, `maxOrNull()` helyett

### Experimental coroutines:

- `kotlin.coroutines.experimental` eltávolítva
- Kompatibilitási modul érhető el: `kotlin-coroutines-experimental-compat.jar`

# Kotlin 1.4.0 újdonságok (folytatás)

## Stabil JSON sorosítás

A `kotlinx.serialization` 1.0.0-RC már stabilnak tekinthető – különösen a JSON sorosítás.

🔧 Kompatibilitás:
- Csak Kotlin 1.4.0 compilerrel működik
- Korábbi verziók nem kompatibilisek

📖 Dokumentáció: [Kotlin Serialization Guide](#)

---

## Scripting és REPL fejlesztések

### Újdonságok:
- Új függőségkezelő API
- Új REPL API (kísérleti)
- Gyorsítótárazott scriptek futtatása
- Módosított artifact nevek

🔧 Példák és útmutató: [Kotlin scripting példák](#)

---

### Új függőségkezelés

- Új artifactumok: `kotlin-scripting-dependencies`, `kotlin-scripting-dependencies-maven`
- Régi: `kotlin-script-util` – elavult

### Új REPL API

- Részét képezi a Kotlin Scripting API-nak
- Használatban a Kotlin Jupyter kernelben is

### Script gyorsítótár

- Ugyanazon scriptek gyorsabb futtatása
- `kotlin-main-kts` alapértelmezetten támogatja

### Artifact átnevezések

| Régi név | Új név |
|----------|--------|
| `kotlin-scripting-jsr223-embeddable` | `kotlin-scripting-jsr223` |
| `kotlin-scripting-jvm-host-embeddable` | `kotlin-scripting-jvm-host` |

➡️ Ezek mostantól alapértelmezetten a `kotlin-compiler-embeddable`-t használják.

---

## Migráció Kotlin 1.4.0-ra

### Lépések:

1. Állítsd a Kotlin verziót `1.4.0`-ra
2. Gradle/Maven projekt újraimportálása
3. IDE fogja kérni a migrációt

🔧 **Migrációs ellenőrzések**:
- Automatikusan javasolják a szükséges változtatásokat
- Súlyozott figyelmeztetések – döntsd el, melyeket fogad el

🔗 [Kompatibilitási útmutató itt](#)

---

# Kotlin 1.3 újdonságok

**Megjelent:** 2018. október 29.

---

## Coroutines stabilizálva!

🔧 Most már teljesen stabil az API és a nyelvi támogatás.

📝 Újdonságok:
- `suspend` függvényekre való callable reference
- Coroutines támogatás reflection API-ban

---

## Kotlin/Native fejlődések

🔧 Komplett átnézés és tökéletesítés.

---

## Multiplatform projektek

### Teljes átdolgozás:
- Egy modulban lehet közös és platformspecifikus kód
- Előre definiált platform konfigurációk
- Függőségek forrásonként külön
- Források megoszthatók tetszőleges platformkombinációk között
- Könyvtárak publikálása lehetséges

---

## Contracts (kísérleti)

A függvények viselkedésének leírása a compiler számára:

🔧 Két nagy típus:
- `returns() implies`: feltételezés logikája
- `callsInPlace`: függvény hívás pontos ideje

Példa:
```kotlin
fun require(condition: Boolean) {
    contract { returns() implies condition }
    if (!condition) throw IllegalArgumentException(...)
}

fun foo(s: String?) {
    require(s is String)
    println(s.length) // smart cast működik!
}
```

------

### Stdlib contracts – stabil

Például `isNullOrEmpty`:



```
fun bar(x: String?) {
    if (!x.isNullOrEmpty()) {
        println(x.length) // smart cast!
    }
}
```

------

### Egyéni contracts – kísérleti



```
fun String?.isNullOrEmpty(): Boolean {
    contract {
        returns(false) implies (this@isNullOrEmpty != null)
    }
    return this == null || isEmpty()
}
```

------

## `when` kifejezés változóban



```
fun Request.getBody() = when (val response = executeRequest()) {
    is Success -> response.body
    is HttpError -> throw HttpException(response.status)
}
```

➡️ `response` változó csak a `when` blokkon belül érhető el.

------

## `@JvmStatic` és `@JvmField` interface companionben



```
interface Foo {
    companion object {
        @JvmField val answer: Int = 42
        @JvmStatic fun sayHello() {
            println("Hello, world!")
        }
    }
}
```

Java-ban:



```
interface Foo {
    public static int answer = 42;
    public static void sayHello() { ... }
}
```

------

## Beágyazott deklarációk annotációkban



```
annotation class Foo {
    enum class Direction { UP, DOWN, LEFT, RIGHT }
    annotation class Bar
    companion object {
        fun foo(): Int = 42
    }
}
```

------

## Paraméter nélküli `main`



```
fun main() {
    println("Hello, world!")
}
```

------

## Nagyobb aritású függvények

Már 22+ paraméteres függvények is támogatottak:



```
fun trueEnterprise(block: (Any, Any, ..., Any) -> Any) {
    block(Any(), Any(), ..., Any())
}
```

------

## Progreszív mód

Fordító kapcsoló: `-progressive`

Előnyök:

- Kritikus hibák azonnali javítása
- Biztonságosabb kód
- Visszafelé kompatibilis

------

## Inline class-ok (alfa)



```
inline class Name(val s: String)

fun main() {
    val name = Name("Kotlin") // nincs konstruktorhívás
    println(name.s)
}
```

------

## Előjel nélküli típusok (béta)

Típusok:

- `UByte`: 0–255
- `UShort`: 0–65,535
- `UInt`: 0–4,294,967,295
- `ULong`: 0–2^64−1

Példa:



```
val uint = 42u
val ulong = 42uL
val ubyte: UByte = 255u

val int = uint.toInt()
val byte = ubyte.toByte()
```

------

## @JvmDefault annotáció (kísérleti)



```
interface Foo {
    @JvmDefault
    fun foo(): Int = 42
}
```

⛔ **Fontos**: bináris kompatibilitási kérdések!

------

## Standard library fejlesztések

### Multiplatform véletlenszám



```
val number = Random.nextInt(42) // [0, 42)
```

### `isNullOrEmpty` és `orEmpty`

Most már kollekciókra, map-ekre, tömbökre is:



```
val result = data.filter { ... }.ifEmpty { listOf("<no data>") }
```

### `copyInto` tömbök között



```
val target = source.copyInto(arrayOfNulls(6), 3, 3, 6)
```

### `associateWith`



```
val map = keys.associateWith { it.toString().repeat(5) }
```

### `ifEmpty`, `ifBlank`



```
val s = " \n"
println(s.ifBlank { "<blank>" })
```

### Sealed class-ok reflection-ben



```
val subtypes = MyClass::class.sealedSubclasses
```

### Egyéb kisebb javítások

- `Boolean` típusnak van `companion` objektuma
- `Any?.hashCode()` – null értékre 0-t ad
- `Char.MIN_VALUE`, `MAX_VALUE`
- Primitív típusokban `SIZE_BYTES`, `SIZE_BITS`

------

## IDE fejlesztések

### Kódformázás

- Ajánlott stílus támogatása
- Migrációs útmutató elérhető

------

## kotlinx.serialization

A sorosító könyvtár mostantól része a Kotlin disztribúciónak.

✅ Előnyök:

- Nem kell külön figyelni az IDE plugin verzióra
- Automatikusan kompatibilis

# Kotlin 1.3 → 1.2 újdonságok (folytatás)

## kotlinx.serialization (kísérleti)

Bár a 1.3-as kiadásban már része a Kotlin compiler disztribúciónak, még kísérleti állapotú.

---

## Scripting fejlesztések (kísérleti)

- Testreszabható scriptek: külső tulajdonságok, függőségek
- Futás közbeni értékelés (scratches)

🔧 További információ: [KEEP-75](#)

---

## Scratch fájlok támogatása

- `.kts` fájlok futtathatók és kiértékelhetők közvetlenül az IDE-ben

🔧 További információ: [Scratch dokumentáció](#)

---

# Kotlin 1.2 újdonságok

**Megjelent:** 2017. november 28.

---

## Multiplatform projektek (kísérleti)

Új funkció a kód újrafelhasználásra több platformon:
- JVM
- JavaScript
- (Native – később)

### Projektstruktúra három modultípusból áll:
1. **Közös** modul: platformfüggetlen kód
2. **Platformspecifikus** modul: platformfüggő implementációk
3. **Szokásos** modul: célplatformra optimalizálva

### Funkciók:
- `expect`/`actual` deklarációk a platformspecifikus API-khoz

Példa:

**Közös kód:**

```kotlin
expect fun hello(world: String): String

fun greet() {
    val greeting = hello("multiplatform world")
    println(greeting)
}

expect class URL(spec: String) {
    fun getHost(): String
    fun getPath(): String
}
```

**JVM kód:**



```
actual fun hello(world: String): String = "Hello, $world, on the JVM!"

actual typealias URL = java.net.URL
```

------

## Egyéb nyelvi fejlesztések

### Tömb literálok annotációkban



```
@CacheConfig(cacheNames = ["books", "default"])
```

------

### `lateinit` támogatás:

- Top-level property-kre
- Lokális változókra

Példa:



```
lateinit var third: Node<Int>
```

### Ellenőrzés: inicializálva van-e a `lateinit` változó



```
println(this::lateinitVar.isInitialized)
```

------

### Inline függvények alapértelmezett paraméterekkel



```
inline fun <E> Iterable<E>.strings(transform: (E) -> String = { it.toString() }) = map { transform(it) }
```

------

### Type cast információ használata típusinferenciában



```
val button = findViewById(R.id.button) as Button
```

------

### Smart cast fejlesztések



```
val firstChar = (s as? CharSequence)?.firstOrNull()
if (firstChar != null) return s.count { it == firstChar } // s automatikusan CharSequence
```

------

### `::foo` rövidítés

Helyett: `this::foo`
Most már: `::foo`

------

## Breaking changes

### Szigorúbb smart cast `try` blokk után

🔧 Régi viselkedéshez: `-Xlegacy-smart-cast-after-try`

------

## Elavultságok

🔧 Ezek a következő verzióban hibát fognak okozni:

- `data class`-ok `copy` metódus felülírása
- Beágyazott típusok `enum` elemekben
- Egyetlen névvel ellátott `vararg` argumentum
- `Throwable`-ből származó általános típusok belső osztályai
- Read-only property-k háttérváltozóinak módosítása

------

## Standard library

### Új felosztott csomagok

- `kotlin-stdlib-jdk7` és `kotlin-stdlib-jdk8` helyettesítik a régi `jre7`/`jre8` csomagokat

------

### Új függvények `Iterable`, `Sequence`, `CharSequence` típusokra

- `chunked`, `windowed`, `zipWithNext`

Példa:



```
val items = (1..9).map { it * it }
val slidingAvg = items.windowed(4) { it.average() }
```

------

### Listák kezelése

- `fill`, `replaceAll`, `shuffle` / `shuffled`

------

### Matematikai műveletek

`kotlin.math` csomag:

- `PI`, `E`
- Trigonometrikus: `cos`, `sin`, `tan`, `acos`, stb.
- Hiperbolikus: `cosh`, `sinh`, stb.
- Hatványozás, logaritmus
- Kerekítések
- Előjel, abszolút érték
- Max/Min
- Bináris műveletek

------

### `BigInteger` és `BigDecimal` támogatás

Új függvények:

- `toBigInteger()`, `toBigDecimal()`
- Operátorok: `+`, `-`, `/`, `*`, `%`, `and`, `or`, `xor`, `shl`, `shr`

------

### `Regex` szerializálható

------

### `Closeable.use` és `Throwable.addSuppressed`

Ha elérhető, a `use` hívás `addSuppressed`-et használ.

------

## JVM backend

### Konstruktor hívások normalizálása

🔧 Fordító kapcsoló: `-Xnormalize-constructor-calls=MODE`

Lehetőségek:

- `disable` (alapértelmezett)
- `enable`
- `preserve-class-initialization`

------

### Java default metódusok

Hiba a JVM 1.6 célra fordított `super` hívások esetén.

🔧 Most már csak JVM 8 cél engedélyezett.

------

### Breaking changes

- `x.equals(null)` null platform típuson most `NPE`-t dob
- Inline extension receiver null esetén is ellenőrizve van

🔧 Visszatérés a régi viselkedéshez:

- `-Xno-exception-on-explicit-equals-for-boxed-null`
- `-Xno-receiver-assertions`

------

## JavaScript backend

### TypedArrays alapértelmezetten engedélyezve

Kotlin primitív tömbök JS TypedArray-ként működnek.

------

## Fordító eszközök

### Figyelmeztetések hibaként kezelése



```
-Werror
```

Gradle-ben:



```
compileKotlin {
    kotlinOptions.allWarningsAsErrors = true
}
```

------

# Kotlin 1.1 újdonságok

**Megjelent:** 2016. február 15.

------

## JavaScript cél már nem kísérleti

- Teljes nyelvi támogatás
- Frontend integrációs eszközök

------

## Coroutines (kísérleti)

Aszinkron programozási minták:

- `async`/`await`
- `yield`

Példa:



```
fun asyncOverlay() = async(CommonPool) {
    val original = asyncLoadImage("original")
    val overlay = asyncLoadImage("overlay")
    applyOverlay(original.await(), overlay.await())
}

launch(UI) {
    val image = asyncOverlay().await()
    showImage(image)
}
```

🔧 További példa: `buildSequence` + `yield`



```
val seq = buildSequence {
    for (i in 1..5) {
        yield(i * i)
    }
    yieldAll(26..28)
}
```

⚠️ Kísérleti funkció – a visszafelé kompatibilitás nem garantált.

------

## Egyéb nyelvi fejlesztések

### Típus aliasok



```
 typealias NodeSet = Set<Network.Node>
```

# Kotlin 1.1 újdonságok (folytatás)

## Típus aliasok (Type aliases)

Új név definiálása meglévő típushoz – különösen hasznos gyűjtemények és függvénytípusok esetén.

```kotlin
typealias OscarWinners = Map<String, String>

fun countLaLaLand(oscarWinners: OscarWinners) = 
    oscarWinners.count { it.value.contains("La La Land") }

fun oscarWinners(): OscarWinners {
    return mapOf(
        "Best song" to "City of Stars (La La Land)",
        "Best picture" to "Moonlight"
    )
}
```

------

## Bound callable reference

Egy adott objektum példányhoz kötött tagfüggvény/referencia lekérdezése.



```
val numberRegex = "\\d+".toRegex()
val numbers = listOf("abc", "123", "456").filter(numberRegex::matches)
```

------

## Sealed és data class fejlesztések

### Sealed class-ok

Már nem kell beágyazva definiálni a leszármazottakat:



```
sealed class Expr
data class Const(val number: Double) : Expr()
data class Sum(val e1: Expr, val e2: Expr) : Expr()
object NotANumber : Expr()

fun eval(expr: Expr): Double = when (expr) {
    is Const -> expr.number
    is Sum -> eval(expr.e1) + eval(expr.e2)
    NotANumber -> Double.NaN
}
```

### Data class-ok

Most már származhatnak más osztályokból is.

------

## Destructuring lambdákban



```
val map = mapOf(1 to "one", 2 to "two")

// Új szintaxis
println(map.mapValues { (key, value) -> "$key -> $value!" })
```

------

## Aláhúzás (`_`) nem használt paraméterekhez



```
map.forEach { _, value -> println("$value!") }

val (_, status) = getResult()
```

------

## Aláhúzás szám literálokban (Java 8-szerint)



```
val oneMillion = 1_000_000
val hexBytes = 0xFF_EC_DE_5E
val bytes = 0b11010010_01101001_10010100_10010010
```

------

## Rövidebb property szintaxis

Getter típusa automatikusan következik:



```
data class Person(val name: String, val age: Int) {
    val isAdult get() = age >= 20 // Boolean típus kikövetkeztetve
}
```

------

## Inline property getter/setter



```
public val <T> List<T>.lastIndex: Int 
    inline get() = this.size - 1
```

------

## Lokális delegált property



```
val answer by lazy {
    println("Calculating...")
    42
}
```

------

## Delegált property kötés interceptelése



```
class ResourceLoader<T>(id: ResourceID<T>) {
    operator fun provideDelegate(thisRef: MyUI, prop: KProperty<*>): ReadOnlyProperty<MyUI, T> {
        checkProperty(thisRef, prop.name)
        // ...
    }
}
```

------

## Generikus enum értékek



```
enum class RGB { RED, GREEN, BLUE }

inline fun <reified T : Enum<T>> printAllValues() {
    print(enumValues<T>().joinToString { it.name })
}
```

------

## DSL scope korlátozás – `@DslMarker`



```
@DslMarker
annotation class HtmlTagMarker

@HtmlTagMarker
abstract class Tag

class Table : Tag()
class Tr : Tag()
class Td : Tag()
```

Most nem lehet például `tr` hívni `td`-n belül.

------

## `rem` operátor (mod helyett)

A `mod` elavult, helyette `rem`:



```
val remainder = a rem b
```

------

# Standard library újdonságok

## Szöveg → szám konverziók (hibabiztosan)



```
val port = System.getenv("PORT")?.toIntOrNull() ?: 80
```

Támogatott típusok:

- `toIntOrNull()`, `toDoubleOrNull()`, stb.

Radix paraméterrel:



```
val number = "1010".toInt(2) // Bináris szám
```

------

## `onEach()` függvény

Művelet végrehajtása minden elemen láncolható módon:



```
inputDir.walk()
    .filter { it.isFile && it.name.endsWith(".txt") }
    .onEach { println("Moving $it") }
    .forEach { moveFile(it, File(outputDir, it.name)) }
```

------

## `also()`, `takeIf()`, `takeUnless()`

### `also()`

Mint `apply`, de `it` referenciát használ:



```
val copy = block.also { it.content = this.content }
```

### `takeIf()`

Szűrés egy elemre – visszaadja, ha megfelel, egyébként null:



```
val index = input.indexOf("in").takeIf { it >= 0 } ?: error("Not found")
```

### `takeUnless()`

Ugyanaz, de invertált feltétellel:



```
val index = input.indexOf("in").takeUnless { it < 0 } ?: error("Not found")
```

------

## `groupingBy()`

Csoportosítás és aggregáció egy lépésben:



```
val frequencies = words.groupingBy { it.first() }.eachCount()
```

------

## Map másolások és módosítások

### Másolás:



```
val copy = map.toMap()
```

### Kulcs eltávolítása:



```
val newMap = map - "key"
```

Több kulcs:



```
val newMap = map - listOf("key1", "key2")
```

------

## `minOf()` és `maxOf()`



```
val minSize = minOf(list1.size, list2.size)
val longest = maxOf(list1, list2, compareBy { it.size })
```

------

## Lista létrehozás lambda segítségével



```
val squares = List(10) { index -> index * index }
val mutable = MutableList(10) { 0 }
```

------

## `Map.getValue()`

Kulcshoz tartozó érték lekérése vagy kivétel dobása:



```
val value = map.getValue("key")
```

Alapértelmezett érték esetén:



```
val mapWithDefault = map.withDefault { key -> key.length }
val value = mapWithDefault.getValue("key2")
```

------

## Absztrakt gyűjtemény osztályok

ReadOnly:

- `AbstractCollection`, `AbstractList`, `AbstractSet`, `AbstractMap`

Mutable:

- `AbstractMutableCollection`, stb.

------

## Tömbök manipulációja

Új függvények:

- `contentEquals()`, `contentDeepEquals()`
- `contentHashCode()`, `contentDeepHashCode()`
- `contentToString()`, `contentDeepToString()`

------

## JVM Backend

### Java 8 bytecode támogatás

Fordító opció:



```
-jvm-target 1.8
```

### Java 8 standard library

Használat:



```
<artifact>kotlin-stdlib-jre8</artifact>
```

### Paraméternevek a bytecode-ban

Fordító opció:



```
-java-parameters
```

------

### Constant inlining

A `const val` értékei be vannak illesztve a használati helyen.

------

### Mutable closure változók optimalizálása

Volatile mezők eltávolítva – jobb teljesítmény, de lehetséges versenyhelyzetek.

------

### `javax.script` támogatás



```
val engine = ScriptEngineManager().getEngineByExtension("kts")!!
engine.eval("val x = 3")
println(engine.eval("x + 2")) // 5
```

------

### `kotlin.reflect.full` csomág

Java 9 kompatibilitás miatt az extension függvények áthelyezve.

⚠️ Elavult: `kotlin.reflect` csomag – eltávolítás Kotlin 1.2-ben.

------

## JavaScript Backend

### Egységesített standard library

Nagyobb része a stdlib-nek mostantól elérhető JS-en is:

- `ArrayList`, `HashMap`, `StringBuilder`, stb.

JVM-en type alias, JS-en implementáció.

------

### Jobb kódgenerálás

Statisztikusan ellenőrizhető kód – jobb működés pl. minifier eszközökkel.

------

### `external` módosító

JS osztályok típusos elérése:



```
external class Node {
    val firstChild: Node
    fun appendChild(child: Node): Node
}
```

------

### Import javítások

Modul annotációk a pontosabb import érdekében:



```
@JsModule("some-lib")
external class SomeLib
```

Ha globálisan is elérhető:



```
@JsModule("lib")
@JsNonModule
external class LibGlobal
```

# JavaScript interop fejlesztések (folytatás)

## jQuery példa

```kotlin
external interface Jquery {
    fun toggle(duration: Int = definedExternally): Jquery
    fun click(handler: (Event) -> Unit): Jquery
}

@JsModule("jquery")
@JsNonModule
@JsName("$")
external fun jquery(selector: String): Jquery
```

Használat:



```
fun main(args: Array<String>) {
    jquery(".toggle-button").click {
        jquery(".toggle-panel").toggle(300)
    }
}
```

------

# Kotlin roadmap

**Utoljára módosítva:** 2025 augusztus
**Következő frissítés:** 2026 február

Üdvözöljük a Kotlin fejlesztési ütemtervén! Itt láthatja a JetBrains csapat főbb prioritásait.

## Főbb irányelvek

- **Nyelvfejlődés:** Pragmatikus és expresszív nyelv jellemzői – szemantikai fejlődés a szintaxis helyett
- **Multiplatform:** Modern multiplatform alkalmazások alapjai – iOS támogatás, web támogatás, IDE eszközök
- **Függetlenség:** Minden eszközt és célt támogatunk
- **Ökoszisztéma támogatás:** Egyszerűbbé tesszük a könyvtárak, eszközök és keretrendszerek fejlesztését/publikálását

------

## Ütemterv rendszerelemek szerint

### A jelenleg aktív területek

#### Nyelv

- Lásd a teljes listát: [Kotlin nyelvi funkciók és javaslatok](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
- YouTrack: [Következő nyelvi funkciók](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

#### Fordító

- Kotlin/Wasm: Prototípus többszálú támogatású thread használatára
- JSpecify támogatás véglegesítése
- K1 fordító elavulttá tétele
- Kotlin/Wasm (wasm-js) béta szintre emelése

#### Multiplatform

- Coroutines Swift támogatásban
- Kotlin/JS: Modern JavaScript-re fordítás
- Kotlin/JS: Export lehetőségek bővítése
- Kotlin/JS: Bevezető anyagok fejlesztése
- Concurrent Mark and Sweep (CMS) GC alapértelmezett engedélyezése
- Multiplatform könyvtárak új generációs formátuma
- Inline szemantika egységesítése minden célplatformon
- Klib artifactok inkrementális fordításának alapértelmezett engedélyezése

#### Eszközök

- Kotlin LSP és VS Code támogatás
- Kotlin + JPA élmény fejlesztése
- Kotlin JS/WASM támogatása Gradle project isolation-ben
- Kotlin Notebook: új használati esetek támogatása
- Kotlin/Wasm projektek fejlesztési élményének javítása IntelliJ IDEA-ban
- Import teljesítmény javítása
- IntelliJ IDEA K2 mód teljes kiadása
- Build Tools API tervezése
- Kotlin Ecosystem Plugin támogatás a Declarative Gradle számára
- Kotlin scripting és .gradle.kts élmény javítása

#### Ökoszisztéma

- KDoc gép által olvasható reprezentációjának implementálása
- Kotlin Notebook stabilizálása
- Kotlin DataFrame 1.0 kiadása
- Kandy 0.9 kiadása
- Nem használt visszatérési értékek figyelmeztetése
- Új multiplatform API a standard library számára: Unicode és codepoint támogatás
- kotlinx-io library stabilizálása
- Kotlin disztribúció UX javítása: kód lefedettség és bináris kompatibilitás validáció
- kotlinx-datetime béta szintre emelése
- Ktor: OpenAPI specifikáció támogatása Ktor kliens és szerver oldalon
- Ktor Adminisztráció és Megfigyelhetőség fejlesztése
- WebRTC kliens
- gRPC támogatás Ktor-ban generátor plugin-nel és tutorial-lal
- Kubernetes Generátor Plugin
- Dependency Injection használat egyszerűsítése
- HTTP/3 támogatás
- Exposed: 1.0.0 kiadás
- R2DBC támogatás

⚠️ Ez az ütemterv nem teljes lista, csak a legnagyobb projekteket tartalmazza. Nincs garancia konkrét funkciók vagy javítások konkrét verziókban való megjelenésére.

------

## 2025 február óta történt változások

### Elvégzett elemek

- Multiplatform: Swift Export első publikus kiadása
- Multiplatform: Kotlin Multiplatform függőségek projekt szinten történő deklarálásának támogatása
- Multiplatform: Klib keresztfordítás stabilizálása
- Multiplatform: Kotlin/JS: WasmJS és JS közös források támogatása Compose fallback esetén
- Eszközök: Kotlin build jelentések fejlesztése
- Eszközök: Stabil fordító argumentumok elérhetővé tétele Gradle DSL-ben
- Eszközök: Gradle project isolation támogatása
- Eszközök: Kotlin/Native toolchain integrációja Gradle-be
- Eszközök: Kotlin Notebook: Egyszerűbb hozzáférés és fejlesztett élmény
- Eszközök: Források támogatása XCFrameworks-ben
- Ökoszisztéma: Dokka HTML kimenet UI fejlesztése
- Ökoszisztéma: Backend alkalmazások projektstruktúrájának egyszerűsítése
- Ökoszisztéma: CLI generátor publikálása SNAP-ba
- Ökoszisztéma: Dependency Injection használat egyszerűsítése

### Új elemek az ütemtervhez

- Fordító: Kotlin/Wasm: Multithread támogatás prototípusa új thread javaslat alapján
- Multiplatform: Coroutines Swift export támogatása
- Multiplatform: Kotlin/JS: Modern JavaScript-re fordítás
- Multiplatform: Kotlin/JS: Export lehetőségek bővítése
- Multiplatform: Kotlin/JS: Bevezető anyagok fejlesztése
- Eszközök: Kotlin LSP és VS Code támogatás
- Eszközök: Kotlin + JPA élmény fejlesztése
- Eszközök: Kotlin JS/WASM támogatása Gradle project isolation-ben
- Eszközök: Kotlin Notebook: új használati esetek támogatása
- Ökoszisztéma: KDoc gép által olvasható reprezentáció implementálása
- Ökoszisztéma: Kotlin Notebook stabilizálása
- Ökoszisztéma: Kotlin DataFrame 1.0 kiadása
- Ökoszisztéma: Kandy 0.9 kiadása
- Ökoszisztéma: OpenAPI specifikáció támogatása Ktor kliens és szerver oldalon
- Ökoszisztéma: Ktor Adminisztráció és Megfigyelhetőség fejlesztése
- Ökoszisztéma: WebRTC kliens

### Eltávolított elemek

- Fordító: Kotlin/Wasm: wasm-wasi célváltozat WASI Preview 2-re váltása
- Fordító: Kotlin/Wasm: Component Model támogatás
- Ökoszisztéma: SNAP-ba való publikálás

Egyes elemek eltávolítva lettek az ütemtervből, de nem teljesen elvetve. Egyes esetekben az előző ütemtervek elemei egyesítve lettek az aktuálisakkal.

------

# Kotlin nyelvi funkciók és javaslatok

JetBrains a Kotlin nyelvet evolúciója során a Kotlin nyelvfejlődési elvek szerint fejleszti, pragmatikus design alapján.

A nyelvi funkció javaslatok Kotlin 1.7.0 verziótól kezdve listázva vannak. A nyelvi funkciók státuszainak magyarázata a Kotlin evolúciós elvek dokumentációban található meg.

## Minden funkció Explorációs és design fázisban

### Név alapú destruktúrázás

[KEEP proposal: name-based-destructuring.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
[YouTrack issue: KT-19627](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

### Immutabilitás támogatás

[KEEP notes: immutability](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
[YouTrack issue: KT-77734](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

### Fordítási idejű konstansok javítása

[KEEP proposal: improve-compile-time-constants.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
[YouTrack issue: KT-22505](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

### CoroutineContext mint kontextus paraméter

[KEEP proposal: CoroutineContext-context-parameter.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
[YouTrack issue: KT-15555](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

### Rich Errors: motiváció és érvelés

[KEEP proposal: rich-errors-motivation.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
[YouTrack issue: KT-68296](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

### Kotlin statikus és statikus extension funkcionalitás

[KEEP proposal: statics.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
[YouTrack issue: KT-11968](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

### Kollekció literálok

[KEEP proposal: collection-literals.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
[YouTrack issue: KT-43871](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

### Explicit backing fields

[KEEP proposal: explicit-backing-fields.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
[YouTrack issue: KT-14663](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

### Verzió overloading

[KEEP proposal: version-overloading.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

### Nem használt visszatérési érték ellenőrző

[KEEP proposal: unused-return-value-checker.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
[YouTrack issue: KT-12719](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

### KDoc ambiguitás hivatkozások egyszerűsítése

[KEEP proposal: streamline-KDoc-ambiguity-references.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
GitHub issues: dokka/#3451, dokka/#3179, dokka/#3334

### Extension hivatkozások feloldása KDoc-ban

[KEEP proposal: links-to-extensions.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
GitHub issue: dokka/#3555

## Előnézeti funkciók

### Adatfolyam-alapú exhaustiveness ellenőrzés

[KEEP proposal: dfa-exhaustiveness.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-8781
**Stabilitási szint:** Beta
**Elérhető:** 2.2.20 verziótól

### Kontextus paraméterek: kontextus-függő deklarációk támogatása

[KEEP proposal: context-parameters.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-14663
**Stabilitási szint:** Experimental
**Elérhető:** 2.2.0 verziótól

### Annotation use-site célok javítása tulajdonságoknál

[KEEP proposal: Improvements to annotation use-site targets on properties](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-19289
**Stabilitási szint:** Experimental
**Elérhető:** 2.2.0 verziótól

### Beágyazott (nem elkapó) típus aliasok

[KEEP proposal: Nested (non-capturing) type aliases](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-45285
**Stabilitási szint:** Beta
**Elérhető:** 2.2.0 verziótól

### Kontextus-érzékeny feloldás

[KEEP proposal: context-sensitive-resolution.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-16768
**Stabilitási szint:** Experimental
**Elérhető:** 2.2.0 verziótól

### Dobozolt inline érték osztályok JVM-en való kitétele

[KEEP proposal: jvm-expose-boxed.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-28135
**Stabilitási szint:** Experimental
**Elérhető:** 2.2.0 verziótól

### kotlin.time.Instant

[KEEP proposal: Instant and Clock](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
**Stabilitási szint:** Experimental
**Elérhető:** 2.1.0 verziótól

### Uuid

[KEEP proposal: uuid.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-31880
**Stabilitási szint:** Experimental
**Elérhető:** 2.0.20 verziótól

### Közös Atomi és Atomi Tömbök

[KEEP proposal: Common atomics](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-62423
**Stabilitási szint:** Experimental
**Elérhető:** 2.2.0 verziótól

### KMP Kotlin-to-Java direct actualization

[KEEP proposal: kmp-kotlin-to-java-direct-actualization.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-67202
**Stabilitási szint:** Experimental
**Elérhető:** 2.1.0 verziótól

## Stabil funkciók

### Őrfeltételek when-with-subject utasításban

[KEEP proposal: guards.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-13626
**Elérhető:** 2.2.0 verziótól

### Több dolláros interpoláció: a $ karakter jobb kezelése string literálokban

[KEEP proposal: dollar-escape.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-2425
**Elérhető:** 2.2.0 verziótól

### Nem-lokális break és continue

[KEEP proposal: break-continue-in-inline-lambdas.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-1436
**Elérhető:** 2.2.0 verziótól

### Stabilizált @SubclassOptInRequired

[KEEP proposal: subclass-opt-in-required.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-54617
**Elérhető:** 2.1.0 verziótól

### Enum.entries: Enum.values() teljesítmény-optimalizált helyettesítője

[KEEP proposal: enum-entries.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-48872
**Elérhető:** 2.0.0 verziótól

### Data objektumok

[KEEP proposal: data-objects.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-4107
**Elérhető:** 1.9.0 verziótól

### RangeUntil operátor ..<

[KEEP proposal: open-ended-ranges.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-15613
**Elérhető:** 1.7.20 verziótól

### Biztosan nem nulla típusok

[KEEP proposal: definitely-non-nullable-types.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-26245
**Elérhető:** 1.7.0 verziótól

## Visszavont funkciók

### Kontextus receiverek

[KEEP proposal: context-receivers.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-10468
Helyettesítve: context-parameters.md

### Java synthetikus property referenciák

[KEEP proposal: references-to-java-synthetic-properties.md](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)
YouTrack issue: KT-8575

------

# Kotlin evolúciós elvek

## Pragmatikus fejlődés elvei

**A nyelvdesign kőbe van vésve, de ez a kő viszonylag puha, és némi erőfeszítéssel később újraformálható.**
*Kotlin Design Team*

A Kotlin programozók pragmatikus eszközeként lett tervezve. Amikor a nyelvfejlődésről van szó, a pragmatizmus a következő elvekben nyilvánul meg:

- A nyelv modern marad az idő múlásával
- Folyamatos visszajelzési ciklus a felhasználókkal
- Új verziókra való frissítés könnyű és kényelmes legyen a felhasználók számára

### A nyelv modern tartása

Felismerjük, hogy a rendszerek az idő múlásával örökséget gyűjtenek. Ami egyszer korszerű technológia volt, az mára reménytelenül elavult lehet. A nyelvet fejlesztenünk kell, hogy releváns maradjon a felhasználók igényeihez és elvárásaihoz képest. Ez nemcsak új funkciók hozzáadását jelenti, hanem az elavulttá vált, már nem ajánlott gyártási használatú funkciók fokozatos eltávolítását is.

### Kényelmes frissítések

Az inkompatibilis változások, például a nyelvből való elemek eltávolítása, fájdalmas migrációt okozhatnak az egyik verzióról a másikra való frissítéskor, ha megfelelő gondosság nélkül hajtják végre. Mindig előre bejelentjük az ilyen változásokat, elavulttá tesszük a megfelelő elemeket, és biztosítunk automatizált migrációs eszközöket a változás előtt. A nyelv megváltozásakor szeretnénk, ha a világon a legtöbb kód már frissítve lenne, így ne okozna problémát az új verzióra való átállás.

### Visszajelzési ciklus

A deprekációs ciklusok végrehajtása jelentős erőfeszítést igényel, ezért minimalizálni szeretnénk a jövőben végrehajtandó inkompatibilis változások számát. A legjobb ítélőképességünk mellett úgy gondoljuk, hogy a dolgok kipróbálása a valós életben a legjobb módja egy design validálására. Mielőtt kőbe vésetnék ezt a dolgokat, szeretnénk, ha valódi csatamezőn kipróbáltak lennének. Ezért minden lehetőséget kihasználunk annak érdekében, hogy a terveink korai verziói elérhetők legyenek a nyelv éles verzióiban, de az egyik elő-stabil státuszban: Experimental, Alpha vagy Beta. Az ilyen funkciók nem stabilak, bármikor megváltozhatnak, és a felhasználók, akik tudatosan választják ezek használatát, ezt kifejezetten azért teszik, mert készek kezelni a jövőbeni migrációs problémákat. Ezek a felhasználók értékes visszajelzéseket adnak, amelyeket összegyűjtünk a design iterálásához és megerősítéséhez.

## Inkompatibilis változások

Ha egy verzióról a másikra frissítve egy kód, amely korábban működött, már nem működik, akkor az egy inkompatibilis változás a nyelvben (néha "breaking change"-ként is hivatkoznak rá). A "már nem működik" pontos jelentéséről viták lehetnek néhány esetben, de biztosan ide tartoznak a következők:

- Olyan kód, amely korábban sikeresen lefordult és futott, most hibát jelez (fordítási vagy linkelési időben). Ez tartalmazza a nyelvi konstrukciók eltávolítását és új korlátozások hozzáadását.
- Olyan kód, amely korábban normálisan futott, most kivételt dob.
- A kevésbé nyilvánvaló esetek, amelyek a "szürke területen" helyezkednek el, például sarokesetek eltérő kezelése, más típusú kivétel dobása, mint korábban, csak reflexión keresztül megfigyelhető viselkedés változása, dokumentálatlan vagy nem definiált viselkedés módosítása, bináris artefaktumok átnevezése és mások.

Néha az ilyen változások kritikusak és drámai módon befolyásolják a migrációs élményt, máskor jelentéktelenek. Példák, amik egyértelműen NEM inkompatibilis változások:

- Új figyelmeztetések hozzáadása.
- Új nyelvi konstrukciók engedélyezése vagy meglévő korlátozások enyhítése.
- Privát/belső API-k és más implementációs részletek változtatása.

# Kotlin evolúciós elvek (folytatás)

## Nyelv modernizálása és kényelmes frissítések

Az inkompatibilis változások néha szükségesek, de óvatosan kell bevezetni őket. Célunk, hogy a felhasználók időben értesüljenek a változásokról, hogy kényelmesen migrálhassák a kódjukat.

### Ideális migrációs munkafolyamat:

1. **Frissítés az A verzióra** (ahol a változás bejelentésre kerül)
2. **Figyelmeztetések megtekintése** az elkövetkező változásról
3. **Kód migrálása** az eszközök segítségével
4. **Frissítés a B verzióra** (ahol a változás ténylegesen bekövetkezik)
5. **Nincsenek problémák**

> Gyakorlatban néhány változás nem detektálható fordítási időben, így nem lehet figyelmeztetést adni, de legalább a kiadási jegyzetekben értesítjük a felhasználókat.

---

## Fordító hibák kezelése

Bár a fordító komplex szoftver, és hibákat tartalmazhat, a következő típusú hibák különbözőképpen kezelendők:

- **Fordítási hibák, spurious hibák**, vagy hibás kódgenerálás – könnyen javíthatók, mivel nem jelentenek inkompatibilis változást.
- **Helytelen kódgenerálás** (például hibák figyelmen kívül hagyása vagy rossz utasítások generálása) – ezek technikailag inkompatibilis változások, de fontos minél hamarabb kijavítani őket, hogy a rossz kódminták ne terjedjenek el.

Ez támogatja a **kényelmes frissítések elvét**, mivel kevesebb felhasználó érintett az ilyen típusú hibák miatt.

> Csak akkor alkalmazzuk ezt a megközelítést, ha a hibát hamar felfedezik a kiadás után.

---

## Döntéshozatal

A Kotlin fejlődését a **JetBrains** irányítja közösséggel és a **Kotlin Foundationnel** való együttműködés keretében. Minden nyelvi változást a **Lead Language Designer** (jelenleg Michail Zarečenskij) felügyel.

### A Language Committee feladata:
- Inkompatibilis változások jóváhagyása
- Döntések meghozatala, hogyan tegyen a migrációt a lehető legkönnyebbé
- A döntéseket a [Language Committee Guidelines](#) alapján hozza meg

---

## Kiadási ciklusok

### Stabil kiadások (pl. 2.0.0)
- Új nyelvi funkciókat tartalmaznak
- Jelentősebb változásokat vezetnek be

### Tooling kiadások (pl. 2.0.20)
- Eszközfejlesztések
- Teljesítménybeli és hibajavítások
- Kompatibilitás fenntartása

### EAP kiadások (Early Access Preview)
- Új funkciók előzetes kipróbálására
- Stabil fordító később elutasíthatja az EAP-ból származó binárisokat

---

## Pre-stabil szintű funkciók

A nyelvfejlesztés során nyíltan iterálunk olyan funkciókon, amelyek még **elő-stabil** szintűek.

- Ezek a funkciók bármikor **megváltozhatnak, eltávolíthatók** figyelmeztetés nélkül.
- A felhasználóknak szándékosan kell ezen funkciókat engedélyezniük kódban vagy konfigurációban.

### Funkció státuszok:

- **Exploration and design** – Funkció felvétele fontoló alatt
- **KEEP discussion** – Funkció dokumentálva, visszajelzés várva
- **In preview** – Funkció prototípusa elérhető, stabilizáció alatt
- **Stable** – Funkció része a nyelvnek, visszafelé kompatibilis
- **Revoked** – Funkció elvetve

---

# Könyvtárak és stabilitás

A nyelv csakis ökoszisztémájával együtt értelmezhető, így nagy hangsúlyt fektetünk a **könyvtárak evolúciójának** egyszerűsítésére.

### Cél:
Az új könyvtárverzió legyen **"drop-in replacement"** a régi helyett – akkor is, ha az alkalmazás nem lett újrafordítva.

### Nyelvi szabályok könyvtárfejlesztőknek:

- **Publikus API-k típusait explicit módon kell meghatározni**
- **Overload függvények hasonló funkciókat lássanak el**
- A `@Deprecated` és `@RequiresOptIn` annotációk használata segít a visszafelé kompatibilitásban
- **Belső API-k (`internal` névterek)** nem részei a publikus API-nak
- **`experimental` névterek** elő-stabil funkcionalitást tartalmaznak

---

## Kotlin Standard Library stabilitása

A standard library-t a nyelv evolúciós elvei szerint fejlesztjük. A **kontraktus-változásokat** ugyanazzal a szigorral kezeljük, mint a nyelv esetén.

---

## Fordító opciók stabilitása

A fordító által elfogadott parancssori opciók is nyilvános API-knak számítanak, és a következőképpen vannak kategorizálva:

- **Támogatott opciók (nélküli `-X` vagy `-XX` prefix)** – csak nyelvi kiadásokban adhatók hozzá, előtte el kell **avulttá tenni** őket
- **`-X` és `-XX` opciók** – kísérleti, bármikor változhatnak vagy eltávolíthatók

---

# Kompatibilitási eszközök

Ahogy az elavult funkciók eltávolításra kerülnek és hibák kijavításra, a forrásnyelv változik, és az el nem migrált kód **nem feltétlenül fordul** többé.

## Kompatibilitási opciók

A következő parancssori opciókkal megőrizhető a kompatibilitás:

- **`-language-version X.Y`**
- **`-api-version X.Y`**

Ezek lehetővé teszik, hogy az új verzió egy régi verzió viselkedését utánozza kompatibilitási célokból.

> A 3 korábbi nyelv- és API-verzió támogatott a legújabb stabil verzión felül.

### Progresszív mód
Aktívan karbantartott projektek előnyt élvezhetnek a legújabb hibajavításokból még a megszokott cikluson kívül is a `-progressive` opcióval.

---

## Bináris formátum evolúciója

A forráskód kézben is módosítható, de a bináris fájlok nehezebben migrálhatók – ezért a **bináris kompatibilitás különösen fontos**.

### Alapértelmezett protokoll (stabil kiadásoknál):

- **Bináris visszafelé kompatibilitás**: Újabb fordító el tudja olvasni a régi binárisokat
- **Régi fordítók elutasítják az új funkciókat használó binárisokat**
- **Előnyben részben előre kompatibilis**: Egy újabb verzióért nem garantált (pl. 1.9 olvashatja a 2.0 binárisait)

---

### Kotlin klib binárisok

A **klib binárisok** Kotlin 1.9.20 óta **Stabil** szintet értek el.

- **Visszafelé kompatibilitás**: 2.x fordító olvassa az 1.9.2x binárisokat
- **Előre kompatibilitás nem garantált**: 2.0.x nem biztos, hogy olvassa a 2.1.x binárisait
- **cinterop klib binárisok** még mindig **Beta**, nem garantált kompatibilitás

---

# Komponensek stabilitása

A Kotlin nyelv és eszköztár sok komponensből áll:
- Fordítók (JVM, JS, Native)
- Standard library
- Eszközök (IDE plugin, Gradle plugin, stb.)

### Stabilitási szintek:

#### ⚠️ **Experimental**
- „Csak próbaverziókban használja”
- Csak egy ötlet ki próbálása céljából

#### 🧪 **Alpha**
- „Használja saját felelősségére, migrációs problémák várhatók”

#### 🚧 **Beta**
- „Használható, igyekszünk minimalizálni a migrációs hibákat”
- Figyeljen a deprecations figyelmeztetésekre!

#### ✅ **Stable**
- „Használható akár a legkonzervatívabb környezetben is”

---

## GitHub badge-ek

A Kotlin GitHub projektjei két badge-et tartalmaznak:

- **Stabilitási szint** (Experimental, Alpha, Beta, Stable)
- **Támogatási szint** (JetBrains termékek szabványai szerint)

---

# Jelenlegi komponens-stabilitás

## Kotlin fordító

| Komponens        | Státusz | Elérhető verzió | Megjegyzés            |
|------------------|---------|------------------|------------------------|
| Kotlin/JVM       | Stable  | 1.0.0            |                        |
| Kotlin/Native    | Stable  | 1.9.0            |                        |
| Kotlin/JS        | Stable  | 1.3.0            |                        |
| Kotlin/Wasm      | Beta    | 2.2.20           |                        |

## Core plugin-ek

| Plugin              | Státusz | Verzió |
|---------------------|---------|--------|
| All-open            | Stable  | 1.3.0  |
| No-arg              | Stable  | 1.3.0  |
| Lombok              | Experimental | 1.5.20 |
| Power-assert        | Experimental | 2.0.0  |

## Könyvtárak

| Könyvtár             | Státusz | Verzió |
|----------------------|---------|--------|
| kotlin-stdlib (JVM) | Stable  | 1.0.0 |
| kotlinx-coroutines   | Stable  | 1.3.0 |
| kotlinx-serialization| Stable  | 1.0.0 |
| kotlinx-datetime     | Alpha   | 0.2.0 |
| kotlinx-io           | Alpha   | 0.2.0 |

## Multiplatform

| Komponens                             | Státusz | Verzió |
|--------------------------------------|---------|--------|
| Kotlin Multiplatform                 | Stable  | 1.9.20 |
| Kotlin Multiplatform Plugin (Android Studio) | Beta | 0.8.0 |

## Kotlin/Native

| Komponens                       | Státusz | Verzió |
|----------------------------------|---------|--------|
| Kotlin/Native Runtime           | Stable  | 1.9.20 |
| C/Objective-C interop           | Beta    | 1.3.0 |
| klib binárisok                  | Stable  | 1.9.20 |
| cinterop klib binárisok         | Beta    | 1.3.0 |

---

## Nyelvi eszközök

| Eszköz                   | Státusz | Elérhető verzió |
|--------------------------|---------|------------------|
| Scripting szintaxis      | Alpha   | 1.2.0 |
| Scripting IDE támogatás  | Beta    | IntelliJ IDEA 2023.1+ |
| CLI scripting            | Alpha   | 1.2.0 |

---

# Kotlin kiadási ciklus

### Nyelvi kiadások (2.x.0)
- Új nyelvi funkciók
- 6 havonta jelentkeznek

### Tooling kiadások (2.x.20)
- Eszközfejlesztések, hibajavítások
- Minden nyelvi kiadás után 3 hónappal

### Hibajavító kiadások (2.x.yz)
- Hibajavítások eszközkiadásokhoz
- Nincs fix időzítés

---

### Hírlevél és követés
Ha értesülni szeretne a Kotlin kiadásokról:
- [Kotlin hírlevél](#)
- Kövessen minket [X-en (@kotlin)](#)
- Engedélyezze a "Watch | Releases" beállítást a [Kotlin GitHub repojában](#)

---

## Frissítés új Kotlin verzióra

### Gradle (Kotlin DSL)

```
plugins {
    kotlin("jvm") version "2.2.20"
    // vagy multiplatform:
    // kotlin("multiplatform") version "2.2.20"
}
```

### Gradle (Groovy DSL)



```
plugins {
    id 'org.jetbrains.kotlin.jvm' version '2.2.20'
    // vagy multiplatform:
    // id 'org.jetbrains.kotlin.multiplatform' version '2.2.20'
}
```

# Kotlin frissítése és IDE támogatás (folytatás)

## Maven frissítés

### Kotlin verzió frissítése a `pom.xml` fájlban:

```xml
<properties>
    <kotlin.version>2.2.20</kotlin.version>
</properties>
```

**Alternatíva**: A `kotlin-maven-plugin` verziójának frissítése:



```
<plugins>
    <plugin>
        <groupId>org.jetbrains.kotlin</groupId>
        <artifactId>kotlin-maven-plugin</artifactId>
        <version>2.2.20</version>
    </plugin>
</plugins>
```

Ellenőrizze, hogy szükséges-e a `kotlinx` könyvtárak verzióit is frissíteni.

------

## IDE támogatás

Kotlin teljes támogatással rendelkezik az IntelliJ IDEA és Android Studio-ban a JetBrains által fejlesztett hivatalos Kotlin plugin segítségével.

### K2 mód IntelliJ IDEA-ban és Android Studio-ban

A K2 mód a K2 fordítót használja a jobb kódelemzés, kódkiegészítés és -kiemelés érdekében.

🔧 **IntelliJ IDEA 2025.1-től** alapértelmezetten engedélyezve van.

### K2 mód engedélyezése Android Studio-ban (2024.1-től):

1. Menjen a `Settings | Languages & Frameworks | Kotlin`
2. Válassza az `Enable K2 mode` opciót

🔗 További információ a [K2 mód blogbejegyzésben](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

------

## Kotlin kiadási kompatibilitás

🔗 Tudjon meg többet a következőkről:

- Kotlin kiadási típusok
- Kompatibilitás részletei

------

# Legutóbbi Kotlin kiadások

| Verzió | Dátum      | Újdonságok / Cél                                        |
| :----- | :--------- | :------------------------------------------------------ |
| 2.2.20 | 2025.09.10 | Webfejlesztési változások és javítások (Tooling)        |
| 2.2.10 | 2025.08.14 | Hibajavítások                                           |
| 2.2.0  | 2025.06.23 | Új nyelvi funkciók, kompatibilitás, teljesítmény        |
| 2.1.21 | 2025.05.13 | Hibajavítás                                             |
| 2.1.20 | 2025.03.20 | Kísérleti funkciók, teljesítményjavítások               |
| 2.1.10 | 2025.01.27 | Hibajavítás                                             |
| 2.1.0  | 2024.11.27 | Új nyelvi funkciók                                      |
| 2.0.21 | 2024.10.10 | Hibajavítás                                             |
| 2.0.20 | 2024.08.22 | Teljesítmény, Gradle 8.8 támogatás                      |
| 2.0.0  | 2024.05.21 | K2 fordító stabil kiadása                               |
| 1.9.25 | 2024.07.19 | Hibajavítás                                             |
| 1.9.20 | 2023.11.01 | K2 béta, Multiplatform stabil                           |
| 1.9.0  | 2023.07.06 | K2 fejlesztések, új range operátor (`..<`)              |
| 1.8.20 | 2023.04.03 | Kotlin/Wasm compiler backend                            |
| 1.8.0  | 2022.12.28 | Reflect teljesítmény, Native objektum interop javítás   |
| 1.7.20 | 2022.09.29 | Új nyelvi funkciók, Native memory manager béta          |
| 1.7.0  | 2022.06.09 | K2 Alpha JVM-re                                         |
| 1.6.20 | 2022.04.04 | Context receiverek prototípusa                          |
| 1.6.0  | 2021.11.16 | Új nyelvi funkciók, stdlib javítások                    |
| 1.5.30 | 2021.08.23 | Apple Silicon támogatás, native memory manager          |
| 1.5.0  | 2021.05.05 | JVM IR backend béta, sealed interface, inline class-ok  |
| 1.4.30 | 2021.02.03 | JVM 11+ támogatás                                       |
| 1.4.20 | 2020.11.23 | String interpolációs javítások, Multiplatform javítások |
| 1.4.0  | 2020.08.17 | Új típus inferencia, JVM IR backend                     |
| 1.3.70 | 2020.03.19 | Kotlin/Native performance javítás                       |
| 1.3.0  | 2018.10.29 | Coroutines stabil, Multiplatform javítás                |

🔗 További kiadások elérhetők a [GitHub release oldalon](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#)

🔧 **Early Access Preview (EAP)** kiadások elérhetők a fejlesztők számára kipróbálásra.

------

# Kotlin alap szintaxis – gyorstalpaló

Ez egy alap szintaxis gyűjtemény példákkal. Minden szekció végén link található a részletes dokumentációhoz.

🔗 Teljes Kotlin alapozó: [JetBrains Academy](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#free-kotlin-track)

------

## Csomagdefiníció és importálás

A csomagdefiníció a fájl elején lehet:



```
package my.demo
import kotlin.text.*
```

✨ Nem kötelező a könyvtárstruktúrának egyeznie a csomag nevével.

------

## Program belépési pont

A Kotlin alkalmazás belépési pontja a `main` függvény:



```
fun main() {
    println("Hello world!")
}

fun main(args: Array<String>) {
    println(args.contentToString())
}
```

------

## Standard kiírás



```
print("Hello ")      // Nem tesz sortörést
println("world!")    // Tesz sortörést
```

------

## Standard bemenet olvasása



```
println("Enter any word:")
val yourWord = readln() // Teljes sort olvas be
println("You entered: $yourWord")
```

------

## Függvények

### Két `Int` paraméterrel, `Int` visszatérési típussal:



```
fun sum(a: Int, b: Int): Int {
    return a + b
}
```

### Kifejezésként (`Unit` típus elhagyható):



```
fun sum(a: Int, b: Int) = a + b

fun printSum(a: Int, b: Int) {
    println("sum of $a and $b is ${a + b}")
}
```

------

## Változók

### `val` – immutable (csak egyszer értékelhető ki):



```
val x: Int = 5  // Egyértelmű típus
val y = 5       // Típus inferálva
```

### `var` – mutable:



```
var x = 5
x += 1  // Most x = 6
```

### Felső szintű változók:



```
val PI = 3.14
var x = 0

fun incrementX() {
    x += 1
}
```

------

## Osztályok és példányok létrehozása

### Egyszerű osztály:



```
class Shape
```

### Konstruktorral és tulajdonságokkal:



```
class Rectangle(val height: Double, val length: Double) {
    val perimeter = (height + length) * 2
}

fun main() {
    val rectangle = Rectangle(5.0, 2.0)
    println("Perimeter: ${rectangle.perimeter}")
}
```

### Öröklődés:



```
open class Shape
class Rectangle(val height: Double, val length: Double) : Shape()
```

------

## Kommentek

### Soron belüli és blokk komment:



```
// Egy soros
/*
Több soros
*/
```

### Beágyazott blokkok:



```
/* Start
   /* Nested */
   End */
```

------

## String sablonok (interpoláció)



```
var a = 1
val s1 = "a is $a"

a = 2
val s2 = "${s1.replace("is", "was")}, but now is $a"
```

------

## Feltételes kifejezések

### Klasszikus `if`:



```
fun maxOf(a: Int, b: Int): Int {
    if (a > b) {
        return a
    } else {
        return b
    }
}
```

### Kifejezésként:



```
fun maxOf(a: Int, b: Int) = if (a > b) a else b
```

------

## `for` ciklus



```
fun main() {
    val items = listOf("apple", "banana", "kiwifruit")
    for (item in items) {
        println(item)
    }
}
```

# Kotlin alap szintaxis – gyorstalpaló (folytatás)

## `while` ciklus

```kotlin
fun main() {
    val items = listOf("apple", "banana", "kiwifruit")
    var index = 0
    while (index < items.size) {
        println("item at $index is ${items[index]}")
        index++
    }
}
```

------

## `when` kifejezés



```
fun describe(obj: Any): String = when (obj) {
    1          -> "One"
    "Hello"    -> "Greeting"
    is Long    -> "Long"
    !is String -> "Not a string"
    else       -> "Unknown"
}

fun main() {
    println(describe(1))
    println(describe("Hello"))
    println(describe(1000L))
    println(describe(2))
    println(describe("other"))
}
```

------

## Tartományok (Ranges)

### Számot tartalmaz-e a tartomány:



```
val x = 10
val y = 9
if (x in 1..y+1) {
    println("fits in range")
}
```

### Tartományon kívül van-e:



```
val list = listOf("a", "b", "c")
if (-1 !in 0..list.lastIndex) {
    println("-1 is out of range")
}
if (list.size !in list.indices) {
    println("list size is out of valid list indices range, too")
}
```

### Tartomány bejárása:



```
for (x in 1..5) {
    print(x)
}
```

### Léptetéssel:



```
for (x in 1..10 step 2) {
    print(x)
}
println()
for (x in 9 downTo 0 step 3) {
    print(x)
}
```

------

## Kollekciók

### Bejárás:



```
val items = listOf("apple", "banana", "kiwifruit")
for (item in items) {
    println(item)
}
```

### Elemben keresés:



```
val items = setOf("apple", "banana", "kiwifruit")
when {
    "orange" in items -> println("juicy")
    "apple" in items -> println("apple is fine too")
}
```

### Szűrés és módosítás (lambda):



```
val fruits = listOf("banana", "avocado", "apple", "kiwifruit")
fruits
    .filter { it.startsWith("a") }
    .sortedBy { it }
    .map { it.uppercase() }
    .forEach { println(it) }
```

------

## Nullable értékek és null ellenőrzés

Egy referencia explicit módon nullable kell legyen, ha `null` is lehet az értéke. A nullable típusnevek végén `?` szerepel.



```
fun parseInt(str: String): Int? {
    return str.toIntOrNull()
}

fun printProduct(arg1: String, arg2: String) {
    val x = parseInt(arg1)
    val y = parseInt(arg2)

    if (x != null && y != null) {
        // Automatikus cast: x és y most már nem nullable
        println(x * y)
    } else {
        println("'$arg1' or '$arg2' is not a number")
    }
}
```

------

## Típusellenőrzés és automatikus cast



```
fun getStringLength(obj: Any): Int? {
    if (obj is String) {
        return obj.length // obj automatikusan String
    }
    return null
}

fun main() {
    println(getStringLength("Hello")) // 5
    println(getStringLength(123))     // null
}
```

------

# Kotlin idiómák

## DTO-k létrehozása (`data class`)



```
data class Customer(val name: String, val email: String)
```

Tartalmazza:

- getterek/setterek
- `equals()`, `hashCode()`, `toString()`
- `copy()`
- `componentN()` (destructuring)

------

## Függvényparaméterek alapértelmezett értékekkel



```
fun foo(a: Int = 0, b: String = "") { ... }
```

------

## Lista szűrése



```
val positives = list.filter { it > 0 }
```

------

## Elem meglétének ellenőrzése



```
if ("john@example.com" in emailsList) { ... }
if ("jane@example.com" !in emailsList) { ... }
```

------

## String interpoláció



```
println("Name $name")
```

------

## Bemenet olvasása biztonságosan



```
val input = readln().toIntOrNull() // null, ha nem szám
```

------

## Instance check



```
when (x) {
    is Foo -> ...
    is Bar -> ...
    else   -> ...
}
```

------

## ReadOnly lista és map



```
val list = listOf("a", "b", "c")
val map = mapOf("a" to 1, "b" to 2)
```

------

## Map bejárása



```
for ((k, v) in map) {
    println("$k -> $v")
}
```

------

## Tartományokon iterálás



```
for (i in 1..100) { ... }       // 100 is benne van
for (i in 1..<100) { ... }      // 100 nincs benne
for (i in 2..10 step 2) { ... }
for (i in 10 downTo 1) { ... }
```

------

## Extension függvény



```
fun String.spaceToCamelCase() { ... }

"Convert this to camelcase".spaceToCamelCase()
```

------

## Lazy tulajdonság



```
val p: String by lazy {
    // csak első hivatkozáskor számolódik ki
}
```

------

## Inline value class (type-safe wrapper)



```
@JvmInline
value class EmployeeId(private val id: String)

@JvmInline
value class CustomerId(private val id: String)
```

------

## Absztrakt osztály példányosítása (object)



```
abstract class MyAbstractClass {
    abstract fun doSomething()
    abstract fun sleep()
}

val myObject = object : MyAbstractClass() {
    override fun doSomething() { ... }
    override fun sleep() { ... }
}
```

------

## Ha nem null – shorthand



```
val files = File("Test").listFiles()
println(files?.size) // csak ha files nem null
```

------

## Ha nem null, akkor érték, egyébként alap



```
println(files?.size ?: "empty")

val filesSize = files?.size ?: run {
    val someSize = getSomeSize()
    someSize * 2
}
```

------

## Kifejezés végrehajtása, ha null



```
val email = values["email"] ?: throw IllegalStateException("Email is missing!")
```

------

## Első elem lekérése, ha üres akkor alap



```
val mainEmail = emails.firstOrNull() ?: ""
```

------

## Végrehajtás, ha nem null



```
value?.let {
    // csak akkor fut, ha value nem null
}
```

------

## Null mapelése alapra



```
val mapped = value?.let { transformValue(it) } ?: defaultValue
```

------

## `when` return-nel



```
fun transform(color: String): Int = when (color) {
    "Red"   -> 0
    "Green" -> 1
    "Blue"  -> 2
    else    -> throw IllegalArgumentException("Invalid color")
}
```

------

## `try-catch` mint kifejezés



```
val result = try {
    count()
} catch (e: ArithmeticException) {
    throw IllegalStateException(e)
}
```

------

## `if` mint kifejezés



```
val y = if (x == 1) {
    "one"
} else if (x == 2) {
    "two"
} else {
    "other"
}
```

------

## Builder stílusú metódushasználat (`Unit`-tel tér vissza)



```
fun arrayOfMinusOnes(size: Int): IntArray {
    return IntArray(size).apply { fill(-1) }
}
```

------

## Egysoros függvény



```
fun theAnswer() = 42
```

Ekvivalens:



```
fun theAnswer(): Int {
    return 42
}
```

------

## Több metódus hívása egy objektumon (`with`)



```
val myTurtle = Turtle()
with(myTurtle) {
    penDown()
    for (i in 1..4) {
        forward(100.0)
        turn(90.0)
    }
    penUp()
}
```

------

## Tulajdonságok konfigurálása (`apply`)



```
val myRectangle = Rectangle().apply {
    length = 4
    breadth = 5
    color = 0xFAFAFA
}
```

------

## Java 7 try-with-resources Kotlinban



```
val stream = Files.newInputStream(Paths.get("/some/file.txt"))
stream.buffered().reader().use { reader ->
    println(reader.readText())
}
```

------

## Általánosított függvény típusinformációval



```
inline fun <reified T: Any> Gson.fromJson(json: JsonElement): T =
    this.fromJson(json, T::class.java)
```

------

## Két változó felcserélése



```
var a = 1
var b = 2
a = b.also { b = a }
```

------

## Kód jelölése, mint "elkészületlen" (`TODO`)



```
fun calcTaxes(): BigDecimal = TODO("Waiting for feedback from accounting")
```

------

## Mi következik?

### Próbáld ki:

- [Advent of Code](https://openrouter.ai/chat?room=orc-1767124359-SMSp6mjPKPRiE20vVjp0#) feladványokat Kotlin idiómákkal
- Java ↔ Kotlin string műveletek összehasonlítása
- Java ↔ Kotlin kollekciók használata
- Java ↔ Kotlin null kezelés

------

# Kotlin kódolási konvenciók

## Stílus beállítása IDE-ben

### IntelliJ IDEA / Android Studio

1. Menjen: **Settings/Preferences | Editor | Code Style | Kotlin**
2. Kattintson: **Set from...**
3. Válassza: **Kotlin style guide**

### Stílus ellenőrzése

1. **Settings/Preferences | Editor | Inspections | General**
2. Engedélyezze: **Incorrect formatting inspection**

------

## Forráskód szervezés

### Mappastruktúra

**Tiszta Kotlin projekt:**
A package struktúra szerint, de közös gyökér nélkül.

Példa:



```
org.example.kotlin → gyökér alatt
org.example.kotlin.network.socket → network/socket mappában
```

**JVM esetén:**
Ugyanúgy, mint Java – osztály szerinti könyvtárstruktúra.

------

## Fájlnevek

Ha egy fájl **egyetlen osztályt vagy interface-t** tartalmaz:

- A neve egyezzen az osztállyal + `.kt`

Ha több osztály vagy csak felső szintű deklaráció:

- Használjon jelentéssel bíró, upper camel case nevet: `ProcessDeclarations.kt`

------

## Multiplatform projektek

Platformspecifikus fájlok utána kapjanak suffixet:



```
jvmMain/kotlin/Platform.jvm.kt
androidMain/kotlin/Platform.android.kt
iosMain/kotlin/Platform.ios.kt
```

Közös fájlok:



```
commonMain/kotlin/Platform.kt
```

### Miért fontos?

JVM korlátozás miatt – ne legyen file facade névütközés!

------

## Forrásfájl tartalma

Egy fájl tartalmazhat:

- Több osztályt
- Top-level függvényeket/property-ket

Ha szemantikailag összetartoznak → ugyanabban a fájlban.

------

## Osztály struktúra sorrendje

1. Tulajdonságok és inicializáló blokk
2. Másodlagos konstruktorok
3. Metódusok
4. Companion objektum

Nem:

- ABC sorrend
- Láthatóság szerinti csoportosítás

------

## Interface implementáció sorrendje

Ugyanolyan sorrendben, mint az interface-ben – kiegészítve privát metódusokkal.

------

## Overload metódusok

Mindig egymás után tegye a classban.

------

## Elnevezések

### Package nevek

- Mindig kisbetű
- Ne használjon `_`
- Példa: `org.example.project`

### Osztály és objektum nevek

- **UpperCamelCase**

### Függvény, tulajdonság, változó nevek

- **lowerCamelCase**

Kivétel: factory metódusok osztálynévvel azonos névvel:



```
interface Foo
class FooImpl : Foo

fun Foo(): Foo = FooImpl()
```

------

## Teszt metódusok

Több lehetőség:

- Szóközök: ``ensure everything works``
- Aláhúzás: `ensureEverythingWorks_onAndroid`



```
@Test
fun `ensure everything works`() { ... }

@Test
fun ensureEverythingWorks_onAndroid() { ... }
```

------

## Tulajdonságnevek

### Konstansok (immutable adatok)

**SCREAMING_SNAKE_CASE**:



```
const val MAX_COUNT = 8
val USER_NAME_FIELD = "UserName"
```

### Mutable/vagy viselkedéssel bíró tulajdonságok

**camelCase**:



```
var userName = ""
val userManager = UserManager()
```

# Kotlin elnevezési és formázási szabályok (folytatás)

## Tulajdonságnevek

### Mutable gyűjtemények

```kotlin
val mutableCollection: MutableSet<String> = HashSet()
```

### Singleton referenciák

Használhatják ugyanazt az elnevezési stílust, mint az objektumdeklarációk:



```
val PersonComparator: Comparator<Person> = /*...*/
```

### Enum konstansok

Két formátum is elfogadott:

- **SCREAMING_SNAKE_CASE**: `RED, GREEN`
- **UpperCamelCase**: `Red, Green`

Használat függvényében választható.

------

### Backing property-k nevei

Ha egy osztálynak két valamilyen szempontból azonos tulajdonsága van (egy nyilvános, egy privát), használjon aláhúzást a privát változó nevében:



```
class C {
    private val _elementList = mutableListOf<Element>()
    val elementList: List<Element>
        get() = _elementList
}
```

------

## Jó nevek választása

- **Osztály neve** általában főnevet vagy főnévi kifejezést tartalmaz:
  - Példa: `List`, `PersonReader`
- **Metódus neve** legyen ige vagy igeneves kifejezés:
  - Példa: `close`, `readPersons`
- A név utaljon arra is, hogy a metódus:
  - Módosítja-e az objektumot (`sort`) → *in-place*
  - Új objektumot ad-e vissza (`sorted`) → *másolat*
- Célszerű elkerülni a jelentés nélküli szavakat, mint:
  - `Manager`, `Wrapper`

------

### Betűszók használata

- **Kétbetűs betűszó** – mindkét betű nagy:
  - `IOStream`
- **Három+ betűs betűszó** – csak az első betű nagy:
  - `HttpInputStream`, `XmlFormatter`

------

# Formázás

## Behúzás

✅ **4 szóközt használjon**
❌ **Ne használjon tab karaktert**

------

## Kapcsos zárójelek



```
if (elements != null) {
    for (element in elements) {
        // ...
    }
}
```

------

## Vízszintes térközök

### Kétoldali operátorok körül



```
a + b       // jó
0..i        // kivétel: range operátor (nincs szóköz)
a++         // kivétel: egyoldalú operátor
```

### Kontrollstruktúrák után szóköz



```
if (x > 0) { ... }    // jó
for (i in 0..10) { ... }   // jó
```

### Ne tegyen szóközt...

- nyitó zárójel előtt:

  

  ```
  class A(val x: Int)     // jó
  fun foo(x: Int) { ... } // jó
  foo(1)                  // jó
  ```

- a `[`, `(` előtt, vagy `]`, `)` után

- `.` vagy `?.` körül:

  

  ```
  foo.bar().filter { it > 2 }.joinToString()
  ```

### `//` után szóköz



```
// Ez egy megjegyzés.
```

------

### Generikusok körül nincs szóköz



```
class Map<K, V> { ... }
```

------

### `::` körül nincs szóköz



```
Foo::class
String::length
```

------

### `?` típus után nincs szóköz



```
String?
```

------

### Általános elv: ne használjon vízszintes igazítást



```
val a = 1        // ne tegyen több szóközt a = köré
val longName = 2 // csak annyi szükséges, amennyi épp
```

------

## Kettőspont (`:`)

### Szóköz KELL előtte:



```
class Foo : IFoo
```

### Ne tegyen szóközt előtte, ha típusdeklaráció esetén:



```
val x: String = "..."
fun foo(a: Int): String { ... }
```

✅ **Mindig tegyen szóközt utána**

------

## Osztályfejlécek

### Rövid constructor → egy sorban:



```
class Person(id: Int, name: String)
```

### Hosszabb → minden paraméter külön sorban, záró `)` külön sor:



```
class Person(
    id: Int,
    name: String,
    surname: String
) : Human(id, name) {
    // ...
}
```

### Öröklődés + több interface:



```
class Person(
    id: Int,
    name: String,
    surname: String
) : Human(id, name),
    KotlinMaker {
    /*...*/
}
```

### Nagyon hosszú lista → új sor, behúzott sorok:



```
class MyFavouriteVeryLongClassHolder :
    MyLongHolder<MyFavouriteVeryLongClass>(),
    SomeOtherInterface,
    AndAnotherOne {
    
    fun foo() { /*...*/ }
}
```

------

## Módosítók sorrendje



```
public / protected / private / internal
expect / actual
final / open / abstract / sealed / const
external
override
lateinit
tailrec
vararg
suspend
inner
enum / annotation / fun
companion
inline / value
infix
operator
data
```

✅ Ha van annotáció → **mindig az módosítók előtt**



```
@Named("Foo") private val foo: Foo
```

------

## Annotációk

- Minden annotáció **új sorban**, azonos behúzással, mint az elem:



```
@Target(AnnotationTarget.PROPERTY)
annotation class JsonExclude
```

- Ha nincs paramétere → akár ugyanabban a sorban:



```
@JsonExclude @JvmField var x: String
```

------

## Fájl annotációk

A fájl komment után, package előtt, üres sorral elválasztva:



```
/** License, copyright and whatever */
@file:JvmName("FooBar")

package foo.bar
```

------

## Függvények

Ha a szignatúra nem fér el → sortörés paraméternél:



```
fun longMethodName(
    argument: ArgumentType = defaultValue,
    argument2: AnotherArgumentType,
): ReturnType {
    // body
}
```

✅ 4 szóköz behúzás függvényparamétereknél → konzisztencia

------

### Expression body

Ha rövid a kifejezés, egy sorban maradhat:



```
fun foo() = 1  // jó
```

Ha nem fér el a szignatúrával egy sorban:



```
fun f(x: String, y: String, z: String) =
    veryLongFunctionCallWithManyWords(andLongParametersToo(), x, y, z)
```

------

### Tulajdonságok

#### Rövid getter → egy sorban:



```
val isEmpty: Boolean get() = size == 0
```

#### Hosszabb → külön sorban:



```
val foo: String
    get() {
        // ...
    }
```

#### Hosszú inicializálás:



```
private val defaultCharset: Charset? =
    EncodingRegistry.getInstance().getDefaultCharsetForPropertiesFiles(file)
```

------

## Kontrollstruktúrák

### Több soros feltétel → mindig használjon kapcsos zárójeleket:



```
if (!component.isSyncing &&
    !hasAnyKotlinRuntimeInScope(module)
) {
    return createKotlinNotConfiguredPanel(module)
}
```

✅ `else`, `catch`, `finally` az előző `{` zárójel után ugyanabban a sorban:



```
if (condition) {
    // ...
} else {
    // ...
}
```

------

### `when` elágazások

Ha egy ág több soros → érdemes üres sorral elválasztani a többitől:



```
when (token) {
    is Token.ValueToken -> callback.visitValue(...)
    
    Token.LBRACE -> {
        // ...
    }
}
```

Rövid ágak lehetnek ugyanabban a sorban, kapcsos nélkül:



```
when (foo) {
    true -> bar()   // jó
    false -> { baz() } // rossz
}
```

------

### Metódushívások

#### Hosszú paraméterlista → soronként 1 paraméter:



```
drawSquare(
    x = 10,
    y = 10,
    width = 100,
    height = 100,
    fill = true
)
```

------

### Láncolt hívások

#### Új sorba a `.` vagy `?.`:



```
val anchor = owner
    ?.firstChild!!
    .siblings(forward = true)
    .dropWhile { it is PsiComment || it is PsiWhiteSpace }
```

------

## Lambda kifejezések



```
ints.forEach lit@{
    // ...
}
```

✅ Szóköz a `{`, `}` és `->` előtt/után:



```
list.filter { it > 10 }

appendCommaSeparated(properties) { prop ->
    val propertyValue = prop.get(obj)
    // ...
}
```

------

## Záró vessző (Trailing comma)

Engedélyezhető az IntelliJ-ben:
**Settings/Preferences > Editor > Code Style > Kotlin > Other > Use trailing comma**

Előnyei:

- Tisztább diff
- Könnyebb újrarendezés
- Egyszerűbb kódgenerálás



```
class Person(
    val firstName: String,
    val lastName: String,
    val age: Int, // trailing comma
)
```

------

## JavaDoc stílusú dokumentáció

### Több soros



```
/**
 * This is a documentation comment
 * on multiple lines.
 */
```

### Egy soros



```
/** This is a short documentation comment. */
```

#### Előnyben részesített stílus

- Ne használj `@param`, `@return` jelöléseket, ha a környezetből érthető
- Ha túl hosszú leírás szükséges → akkor használj



```
/**
 * Returns the absolute value of the given [number].
 */
fun abs(number: Int): Int { /*...*/ }
```

------

## Felesleges elemek elhagyása

### `Unit` típus elhagyható



```
fun foo() { ... }  // jó
```

### Pontosvessző elhagyható



```
println("hello world")  // jó
```

------

## String sablonok

### Egyszerű változó → kapcsos nélkül



```
println("$name has ${children.size} children")
```

------

## `$` karakter literálként → multi-dollar:



```
val schema = $$"""{
    "$$schema": "https://json-schema.org/draft/2020-12/schema",
    "title": "$${simpleName ?: qualifiedName ?: "unknown"}"
}"""
```

------

# Kotlin idiómák használata

## Immutable preferencia

- Mindig `val`-t használjon, ha nem változtatja az értéket
- Immutable gyűjtemények:



```
fun validateValue(actualValue: String, allowedValues: Set<String>) { ... }

val allowedValues = listOf("a", "b", "c") // jó
```

------

## Alapértelmezett paraméterek

✅ Általában jobbak, mint túlterhelés:



```
fun foo(a: String = "a") { ... }  // jó
```

------

## Type alias

Ha komplex típust sokszor használ:



```
typealias MouseClickHandler = (Any, MouseEvent) -> Unit
typealias PersonIndex = Map<String, Person>
```

------

## Lambda paraméterek

### Rövid, nem beágyazott lambda → `it` használata:



```
list.filter { it > 0 }
```

### Beágyazott lambdák → explicite deklarálandó:



```
files.forEach { file ->
    file.readLines().forEach { line ->
        println(line)
    }
}
```

------

## Visszatérés lambdából

✅ Ha elkerülhető, kerülje a `return@label` használatát

------

## Nevesített argumentumok

✅ Boolean vagy azonos primitív típusok esetén használja mindig:



```
drawSquare(x = 10, y = 10, width = 100, height = 100, fill = true)
```

------

## Elsődleges kifejezési alakok használata

✅ `if`, `when`, `try` mint kifejezéseket használjon:



```
return if (x) foo() else bar()

return when (x) {
    0 -> "zero"
    else -> "nonzero"
}
```

------

### `if` vs `when`

- **Két elágazás esetén** használj `if`-et:



```
if (x == null) ...
else ...
```

- **3+ elágazás esetén** használj `when`-t:



```
when (x) {
    1 -> ...
    2 -> ...
    else -> ...
}
```

------

### Guard feltételek `when`-ben

Zárójel használata több feltétel esetén:



```
when (status) {
    is Status.Ok if (status.info.isEmpty() || status.info.id == null) -> "no information"
}
```

------

### Nullable `Boolean`

✅ Ne döntse el csak a `value`-ra hivatkozva:



```
if (value == true) ...
if (value == false) ...
```

------

## Ciklusok és magasabbrendű függvények

### Előnyben: `map`, `filter`, `forEach` stb.



```
items.filter { it > 0 }.map { it * 2 }
```

✅ `forEach` helyett használjon hagyományos `for`-t, kivéve nullable esetekben

------

## Range ciklusok

✅ Legyen **nyitott végű** inkább:



```
for (i in 0..<n) { ... } // jó
for (i in 0..n - 1) { ... } // nem javasolt
```

# Kotlin alapvető típusok

Minden Kotlin-ban objektum – még a számok, karakterek és logikai értékek is tagfüggvényekkel és tulajdonságokkal rendelkeznek. Bár bizonyos típusok belsőleg primitívekként vannak reprezentálva (pl. számok, karakterek), felülről mindig osztályként viselkednek.

## Számok

### Egész számok (Integer)

Kotlin négy beépített egész típust biztosít különböző méretben és értéktartományban:

| Típus | Méret (bit) | Minimum érték        | Maximum érték         |
|------|-------------|----------------------|------------------------|
| Byte |     8       | -128                 | 127                    |
| Short|     16      | -32 768              | 32 767                 |
| Int  |     32      | -2 147 483 648       | 2 147 483 647          |
| Long |     64      | -9 223 372 036 854 775 808 | 9 223 372 036 854 775 807 |

Ezek mellett elérhetőek az **előjel nélküli egész típusok** is. Ezek külön szekcióban kerülnek bemutatásra.

#### Változó deklarálása

A típus kikövetkeztethető:

```
val one = 1           // Int
val threeBillion = 3000000000  // Long
val oneLong = 1L      // Long
val oneByte: Byte = 1 // Explicit Byte
```

### Lebegőpontos számok (Floating-point)

IEEE 754 szabványt követik:

| Típus  | Méret (bit) | Jelentékeny bitek | kitevő bitek | Pontosság (decimális) |
| :----- | :---------- | :---------------- | :----------- | :-------------------- |
| Float  | 32          | 24                | 8            | 6–7                   |
| Double | 64          | 53                | 11           | 15–16                 |

#### Példa:



```
val pi = 3.14           // Double
val eFloat = 2.718f     // Float
val oneDouble = 1.0      // Double

// Hiba:
// val x: Double = 1     → konverzió kell!
```

------

### Szám konverziók

Kotlinban **nincs implicit konverzió** számok között! Konverzióhoz explicit módon kell hívni:



```
val byte: Byte = 1
val intConvertedByte: Int = byte.toInt()
```

Konverziós függvények minden számra:

- `toByte()`
- `toShort()`
- `toInt()`
- `toLong()`
- `toFloat()`
- `toDouble()`

Automatikus műveleti konverzió történik, ha szükséges a kontextus alapján:



```
val l = 1L + 3   // Long + Int → Long
```

------

### Szám literálok

#### Egészek

- Decimális: `123`
- Long: `123L`
- Hexadecimális: `0xFF`
- Bináris: `0b000101`

### Lebegőpontos

- Double: `12.34`, `12.34e10`
- Float: `12.34f`

Olvashatóság: aláhúzás használható



```
val million = 1_000_000
val card = 1234_5678_9012_3456L
```

#### Előjel nélküli literálokhoz:

- `u`, `U` – automatikus unsigned típus
- `UL`, `uL` – unsigned long

------

### Boxolás a JVM-en

Java automatikusan boxolja a számokat ha kell – ez időnként meglepő viselkedést okozhat:

#### Kis számok cache-elése



```
val a: Int = 100
val boxedA: Int? = a
val anotherBoxedA: Int? = a
println(boxedA === anotherBoxedA)  // true
```

Nagy számoknál:



```
val b: Int = 10000
val boxedB: Int? = b
val anotherBoxedB: Int? = b
println(boxedB === anotherBoxedB)  // false
println(boxedB == anotherBoxedB)  // true
```

------

## Műveletek számokkal

### Alapműveletek



```
println(1 + 2)             // 3
println(5L / 2)            // 2 (egész osztás)
println(5.0 / 2)           // 2.5
```

### Bitműveletek (infix operátorok)

Csak `Int` és `Long` típusokhoz használhatók:

| Művelet      | Jelentés                   |
| :----------- | :------------------------- |
| `shl(bits)`  | Balra tolás                |
| `shr(bits)`  | Jobbra tolás (sign-extend) |
| `ushr(bits)` | Jobbra tolás (zero-fill)   |
| `and(bits)`  | Bitwise AND                |
| `or(bits)`   | Bitwise OR                 |
| `xor(bits)`  | Bitwise XOR                |
| `inv()`      | Bitwise NOT (invert)       |



```
val x = 1
val shifted = x shl 2   // 4
val andResult = x and 0x00FF  // 1
```

------

## Lebegőpontos számok összehasonlítása

Kotlin IEEE 754 standard szerint használja a szabványos összehasonlításokat:

- `==`, `!=`
- `<`, `>`, `<=`, `>=`
- `a..b` tartomány

Speciális értékek:



```
Double.NaN == Double.NaN     // false
listOf(Double.NaN) == listOf(Double.NaN) // true
0.0 == -0.0                  // true (IEEE)
listOf(0.0) == listOf(-0.0)  // false
```

Rendezés:



```
listOf(Double.NaN, Double.POSITIVE_INFINITY, 0.0, -0.0).sorted()
// [-0.0, 0.0, Infinity, NaN]
```

------

## Előjel nélküli egész típusok (Unsigned)

| Típus  | Méret | Minimum | Maximum                    |
| :----- | :---- | :------ | :------------------------- |
| UByte  | 8     | 0       | 255                        |
| UShort | 16    | 0       | 65 535                     |
| UInt   | 32    | 0       | 4 294 967 295              |
| ULong  | 64    | 0       | 18 446 744 073 709 551 615 |

------

### Felhasználási esetek

✅ Teljes bit-tartomány kihasználása (pl. 32 bites szín RGB formátum)



```
data class Color(val representation: UInt)
val yellow = Color(0xFFCC00CCu)
```

✅ Tömb inicializálása casting nélkül



```
val byteOrderMarkUtf8 = ubyteArrayOf(0xEFu, 0xBBu, 0xBFu)
```

✅ Native API-kkal való kompatibilitás

------

## Boolean (Logikai)

Két értéke van: `true` és `false`.

Támogatott operátorok:



```
val b1 = true  // Boolean
val b2 = false
val b3: Boolean = true

val result = b1 && b2 || !b3
```

------

## Karakterek (Char)

Karaktert `Char` típussal reprezentálunk. Mindig `'` jelek közé kell tenni.



```
val c = 'A'
val unicode = '\uFF00'
val newline = '\n'
```

Karakterek nem számok – nincs implicit konverzió, de külön operátorok állnak rendelkezésre:



```
val number = '9'.digitToInt()   // 9
val char = 9.digitToChar()       // '9'
```

------

## Szöveg (String)

Soron belüli (`"`) és többsoros (`"""`) szövegként is használható.



```
val str = "Hello"
val multiline = """
    Ez egy
    több soros
    szöveg.
""".trimIndent()
```

Tartomány közötti trimelés:



```
val margin = """
    |Ez egy
    |margint használó
    |szöveg.
""".trimMargin()
```

------

### String sablonok



```
val name = "Alice"
println("Hello, $name!")  // Hello, Alice!
println("Length: ${name.length}")  // Length: 5
```

------

## Tömbök (Array)

Minden elemtípushoz van tömb típus:

- `IntArray`, `DoubleArray`, `BooleanArray`, stb.
- `Array<T>` – generikus tömb

### Létrehozás:



```
val arr1 = arrayOf(1, 2, 3)
val arr2 = intArrayOf(1, 2, 3)
val arr3 = Array(5) { i -> i * i }  // [0, 1, 4, 9, 16]
```

------

### Előnyben részesített: sablonok vs konkatenáció

✅ Szöveg konstrukcióknál sablonokat használjunk:



```
val s = "Name: $name"  // jó
val s = "Name: " + name  // elkerülendő
```

------

### Függvények vs Tulajdonságok

Ha egy érték:

- nem dobhat kivételt
- olcsó a kiszámítása vagy gyorsítótárazott
- mindig ugyanazt adja

→ **használj tulajdonságot**

> Előnyben a kód olvashatóságának egyszerűsége

------

## Extension függvények

✅ Használd bátran! Minden függvény, ami elsősorban egy objektumon dolgozik, legyen extension függvény.

------

## Infix függvények

✅ Csak akkor használjuk, ha a két operandus szimmetrikus:

- Jó: `to`, `and`, `zip`
- Rossz: `add`



```
val pair = "key" to "value"
```

------

## Factory függvények

✅ Kerüljük, hogy a függvény neve megegyezzen az osztály nevével.

Jó példa:



```
class Point(val x: Double, val y: Double) {
    companion object {
        fun fromPolar(angle: Double, radius: Double) = Point(/*...*/)
    }
}
```

------

## Platform típusok

Ha egy Java osztály API-ból kapott érték, Kotlin nem tudja pontosan, hogy nullable-e, így platform típusként jelenik meg.

Ezek esetén:

✅ Mindig adjunk meg explicit Kotlin típust:



```
fun apiCall(): String = MyJavaApi.getProperty("name")
```

------

## Scope függvények

- `let`, `run`, `also`, `apply`, `with`

Használatuk célhoz igazítva. Leggyakoribbak:

### `apply`

Beállítás, leginkább property-k konfigurálására:



```
val rectangle = Rectangle().apply {
    length = 4
    width = 5
}
```

### `also`

Mellékhatás, például loggolás:



```
val result = getData().also { println("Got data: $it") }
```

### `let`

Null-safe művelet:



```
val length = str?.let { it.length }
```

------

## Kotlin könyvtárakhoz – API konvenciók

Ha könyvtárat írsz:

✅ Mindig adj meg:

- Tag függvény láthatóságot
- Visszatérési típust
- Dokumentációt (KDoc)

Ez biztosítja a visszafelé kompatibilitást.

# Kotlin alapvető típusok – folytatás

## Boolean

A `Boolean` típus kétféle értéket vehet fel: `true` és `false`.

```
val myTrue: Boolean = true
val myFalse: Boolean = false
val boolNull: Boolean? = null

println(myTrue || myFalse)  // true
println(myTrue && myFalse) // false
println(!myTrue)           // false
println(boolNull)          // null
```

### Lazy kiértékelés

- `||`: ha az első operandus `true`, a másodikat nem értékeli ki
- `&&`: ha az első operandus `false`, a másodikat nem értékeli ki

JVM: nullable boolean referenciák Java `Boolean` objektumba boxolódnak.

------

## Char (karakter)

A `Char` típus egy 16 bites Unicode karaktert reprezentál.



```
val aChar: Char = 'a'
println(aChar)
println('\n')  // Új sor
println('\uFF00') // Unicode karakter
```

### Speciális karakterek

Escape karakterek:

- `\t` – tabulátor
- `\b` – backspace
- `\n` – új sor
- `\r` – kocsi vissza
- `\'` – aposztróf
- `\"` – idézőjel
- `\\` – backslash
- `\$` – dollar jel

### Karakter átalakítás

Számjegy karaktert konvertálhatunk:



```
val digit = '9'.digitToInt() // 9
```

JVM: nullable karakterek Java `Character` objektumba boxolódnak.

------

## String (karaktersorozat)

A `String` típus Unicode karakterek sorozatát tárolja, UTF-16 kódolásban – kb. 2 bájt/karakter.

### Szöveg literálok

#### Szimpla idézőjeles szöveg (escaped string)



```
val str = "Hello\nworld"
```

Escape karakterek használhatók (`\n`, `\t`, stb.)

#### Többsoros szöveg



```
val text = """
    |Ez egy
    |több soros szöveg.
""".trimMargin()
```

Alapértelmezett margó karakter: `|`. Testreszabható:



```
val customMargin = """
    >Ez egy
    >margóval.
""".trimMargin(">")
```

------

### String sablonok (interpoláció)

#### Változók behelyettesítése



```
val name = "Anna"
println("Hello, $name!")  // Hello, Anna!
```

#### Kifejezés behelyettesítése



```
val s = "abc"
println("$s.length is ${s.length}")  // abc.length is 3
```

#### Dollar jel karakterként

Többdolláros interpoláció:



```
val schema = $$"""{"title": "$${simpleName ?: "unknown"}"}"""
```

Két `$` szükséges a sablon indításához. Egy szimpla `$` literálként szerepel.

------

### Szöveg összefűzés



```
val result = "abc" + 1        // "abc1"
val full = result + "def"     // "abc1def"
```

**Ajánlott:** sablonok vagy többsoros szövegek használata konkatenció helyett.

------

### String formázás (JVM-en)



```
val number = String.format("%07d", 31416)  // 0031416
val floatNum = String.format("%+.4f", 3.141592)  // +3.1416
val text = String.format("%S %S", "hello", "world")  // HELLO WORLD
```

Feltételek:

- `%d` – egész szám
- `%f` – lebegőpontos
- `%s` – string (nagybetűs: `%S` → nagybetűssé alakít)

------

## Tömbök (Arrays)

Adatszerkezet, amely rögzített számú azonos típusú értéket tárol.

### Mikor használjuk?

- Teljesítménykritikus vagy alacsonyszintű műveletek
- Egyéni adatszerkezetek készítése

Különbség a gyűjteményekkel szemben:

- Mérete fix
- Nem biztosítanak olvasható/írható gyűjteményeket
- Könnyebb őket hibásan használni

------

### Tömbök létrehozása

#### `arrayOf()` függvénnyel



```
val simpleArray = arrayOf(1, 2, 3)
```

#### `arrayOfNulls()` függvénnyel



```
val nullArray: Array<Int?> = arrayOfNulls(3)  // [null, null, null]
```

#### `emptyArray()` függvénnyel



```
var exampleArray = emptyArray<String>()
```

#### Konstruktorral:



```
val initArray = Array<Int>(3) { 0 }    // [0, 0, 0]
val squares = Array(5) { i -> i * i }   // [0, 1, 4, 9, 16]
```

------

### Tömbök bejárása



```
for (c in simpleArray) {
    println(c)
}
```

------

### Beágyazott tömbök (multidimensional)



```
val twoD = Array(2) { Array(2) { 0 } }  // [[0, 0], [0, 0]]
```

------

### Tömb elemek elérése és módosítása



```
simpleArray[0] = 10
twoDArray[0][0] = 2
```

Kotlinban a tömbök variánsok → `Array<String>` **nem** osztályozható `Array<Any>`-ként. Helyette: `Array<out Any>`.

------

## Tömbök használata

### Változó számú argumentum átadása függvénynek



```
fun printAllStrings(vararg strings: String) {
    for (s in strings) print(s)
}

val letters = arrayOf("c", "d")
printAllStrings("a", "b", *letters)  // abcd
```

Spread operátor (`*`) tömb elemeit egyesével adja át.

------

### Tömbök összehasonlítása



```
val a1 = arrayOf(1, 2, 3)
val a2 = arrayOf(1, 2, 3)

println(a1.contentEquals(a2))  // true
```

Nem használható `==` vagy `!=` a tartalomhoz!

Mély összehasonlítás beágyazott tömbökre:



```
a1.contentDeepEquals(a2)
```

------

### Tömbök transzformálása

#### Összegzés



```
val nums = arrayOf(1, 2, 3)
println(nums.sum())  // 6
```

#### Keverés



```
val arr = arrayOf(1, 2, 3)
arr.shuffle()  // pl. [3, 1, 2]
```

------

### Tömbök konvertálása gyűjteménnyé

#### Listává vagy halmazzá



```
val arr = arrayOf("a", "b", "c", "c")
println(arr.toSet())   // [a, b, c]
println(arr.toList())  // [a, b, c, c]
```

#### Map-pé

Csak `Pair<K,V>` tömb konvertálható `Map`-pé:



```
val pairs = arrayOf("apple" to 120, "banana" to 150)
println(pairs.toMap())  // {apple=120, banana=150}
```

------

## Primitív típusú tömbök

Ha primitív értékeket akarunk tárolni boxolás nélkül:

| Kotlin típus   | Java típus  |
| :------------- | :---------- |
| `BooleanArray` | `boolean[]` |
| `ByteArray`    | `byte[]`    |
| `CharArray`    | `char[]`    |
| `DoubleArray`  | `double[]`  |
| `FloatArray`   | `float[]`   |
| `IntArray`     | `int[]`     |
| `LongArray`    | `long[]`    |
| `ShortArray`   | `short[]`   |

Ezek nem öröklik az `Array` osztályt, de ugyanazokat a függvényeket tartalmazzák.

Konverzió primitívből objektumos tömbbe:



```
val intArray = intArrayOf(1, 2, 3)
val boxedArray = intArray.toTypedArray()  // Array<Int>
```

Objektumosból primitíves:



```
val anyArray = arrayOf(1, 2, 3)
val primitive = anyArray.toIntArray()
```

------

## Type checks és castok

Objektum típusának ellenőrzése futásidőben, vagy típuskonverzió.

### `is` és `!is` operátorok



```
if (obj is String) {
    println(obj.length)
}

if (obj !is String) {
    println("Not a string")
} else {
    println(obj.length)
}
```

### Smart cast

Ha egy változó típusát ellenőriztük, automatikusan castolódik:



```
fun getStringLength(obj: Any): Int? {
    if (obj is String) {
        return obj.length  // obj most String típusú
    }
    return null
}
```

------

### Safe cast (`as?`)

Ha a cast nem sikerül, `null` értéket ad:



```
val x: Any = "Hello"
val str = x as? String  // String vagy null
```

### Unsafe cast (`as`)

Ha nem kompatibilis típusra próbál castolni → kivételt dob:



```
val y: Any = "Hello"
val str = y as String  // Veszélyes!
```

⚠️ Használata kerülendő, inkább `as?` a biztonság érdekében.

# Kotlin – Smart castok és vezérlési szerkezetek

## Smart castok

A Kotlin automatikusan elvégzi a típusátalakítást, ha az kifejezetten biztonságos. Ez a **smart cast**.

### Példa

```
fun demo(x: Any) {
    if (x is String) {
        print(x.length)  // x automatikusan String-re castolva
    }
}
```

A **negatív ellenőrzés is működik**:



```
if (x !is String) return
print(x.length)  // x biztosan String típusú
```

### Működés más kontrollstruktúrákkal



```
when (x) {
    is Int -> print(x + 1)
    is String -> print(x.length + 1)
    is IntArray -> print(x.sum())
}
```

### Boolean típusú változók



```
class Cat {
    fun purr() { println("Purr purr") }
}

fun petAnimal(animal: Any) {
    val isCat = animal is Cat
    if (isCat) {
        animal.purr()
    }
}
```

------

## Logikai operátorok és smart cast



```
// x automatikusan String, ha a bal oldalon isString == true
if (x !is String || x.length == 0) return

// x biztosan String itt
if (x is String && x.length > 0) {
    print(x.length)
}
```

------

## Közös szülő típus (Union approximáció)

Ha `||` van használva:



```
interface Status
interface Postponed : Status
interface Declined : Status

fun signalCheck(signalStatus: Any) {
    if (signalStatus is Postponed || signalStatus is Declined) {
        signalStatus.signal()  // Status típusra castolva
    }
}
```

------

## Inline függvények és smart cast



```
interface Processor {
    fun process()
}

inline fun inlineAction(f: () -> Unit) = f()

fun nextProcessor(): Processor? = null

fun runProcessor(): Processor? {
    var processor: Processor? = null
    inlineAction {
        if (processor != null) {
            processor.process()  // Smart cast itt is működik
        }
        processor = nextProcessor()
    }
    return processor
}
```

------

## Kivételkezelés és smart cast



```
fun testString() {
    var stringInput: String? = null
    stringInput = ""

    try {
        println(stringInput.length)  // 0
        stringInput = null
        if (2 > 1) throw Exception()
    } catch (e: Exception) {
        println(stringInput?.length)  // null
    }
}
```

------

## Smart cast előfeltételek

A smart cast akkor működik, ha a compiler garantálja, hogy a változó **nem változik** az ellenőrzés és használat között.

### Használható esetek

| Változó típus       | Használható?                                |
| :------------------ | :------------------------------------------ |
| `val` helyi változó | ✅ Mindig                                    |
| `val` property      | ✅ Ha private/internal ugyanabban a modulban |
| `var` helyi változó | ✅ Ha nem módosul, nem kerül be lambda-ba    |
| `var` property      | ❌ Soha (más thread bármikor változtathatja) |

------

## „Unsafe” cast (`as`)

Nem nullable típusra castolás – **kivételt dob**, ha nem sikerül:



```
val x: String = y as String
```

Null érték esetén: `ClassCastException`

➡️ **Használata kerülendő**, kivéve ha biztos a típus.

------

## „Safe” cast (`as?`)

Biztonságos castolás – `null` értékkel tér vissza, ha nem sikerül:



```
val x: String? = y as? String
```

------

# Vezérlési szerkezetek

## `if` kifejezés



```
val heightAlice = 160
val heightBob = 175

var taller = if (heightAlice > heightBob) heightAlice else heightBob

// blokkként is:
val result = if (heightAlice > heightBob) {
    print("Alice")
    heightAlice
} else {
    print("Bob")
    heightBob
}
```

------

## `when` kifejezés

### Alapvető használat



```
val userRole = "Editor"
when (userRole) {
    "Viewer" -> print("Read-only access")
    "Editor" -> print("Can edit")
    else -> print("Unknown")
}
```

### Kifejezésként való használat



```
val result = when (x) {
    1 -> "x is one"
    2 -> "x is two"
    else -> "other"
}
```

------

### `when` feltételek típusai

#### Több feltétel egy ágban:



```
when (role) {
    "Admin", "Moderator" -> accessFull()
    else -> accessLimited()
}
```

#### Kifejezés kiértékelése:



```
when (enteredPin) {
    storedPin.toInt() -> println("Correct PIN")
    else -> println("Wrong PIN")
}
```

#### Tartományban vagy kollekcióban:



```
val x = 7
val validNumbers = setOf(15, 16, 17)

when (x) {
    in 1..10 -> print("x is in the range")
    in validNumbers -> print("x is valid")
    !in 10..20 -> print("x is outside the range")
    else -> print("none of the above")
}
```

------

### Típusellenőrzés és smart cast



```
fun hasPrefix(input: Any): Boolean = when (input) {
    is String -> input.startsWith("ID-")
    else -> false
}
```

------

### `when` feltétel nélkül



```
val message = when {
    localFileSize > remoteFileSize -> "Larger"
    localFileSize < remoteFileSize -> "Smaller"
    else -> "Same size"
}
```

------

### Változó rögzítése a `when` törzsében



```
val message = when (val input = readln()) {
    "yes" -> "Agreed"
    "no" -> "Denied"
    else -> "Unrecognized input: $input"
}
```

------

## Guard feltételek



```
sealed interface Animal {
    data class Cat(val mouseHunter: Boolean) : Animal
    data class Dog(val breed: String) : Animal
}

fun feedAnimal(animal: Animal) {
    when (animal) {
        is Animal.Dog -> feedDog()
        is Animal.Cat if !animal.mouseHunter -> feedCat()
        else -> println("Unknown")
    }
}
```

------

## `for` ciklus

### Kollekció bejárása



```
val items = listOf("apple", "banana")
for (item in items) {
    println(item)
}
```

### Tartományok



```
for (i in 1..5) print(i)        // 12345
for (i in 1..<5) print(i)       // 1234
for (i in 5 downTo 1) print(i)  // 54321
for (i in 1..10 step 2) print(i)  // 13579
```

### Indexelés



```
val items = arrayOf("a", "b", "c")

for (i in items.indices) {
    println("$i: ${items[i]}")
}

for ((index, value) in items.withIndex()) {
    println("$index: $value")
}
```

------

## Egyedi iterátor készítése



```
class Booklet(val totalPages: Int) : Iterable<Int> {
    override fun iterator(): Iterator<Int> {
        return object : Iterator<Int> {
            var current = 1
            override fun hasNext() = current <= totalPages
            override fun next() = current++
        }
    }
}

fun main() {
    val booklet = Booklet(3)
    for (page in booklet) {
        println("Reading page $page")
    }
}
```