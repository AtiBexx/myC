### A C programok alapvető fogalmai

A C nyelvre vonatkozó ezen rész ismertetése a C programozási nyelvhez használt kifejezések és fogalmak definícióját tartalmazza.

Egy C program szokásához híven sorozatban álló szövegfájlok (gyakran fejléc és forráskód fájlok) együttese, melyek benne kijelentéseket tartalmaznak. Ezek a fájlok fordítás alá kerülnek, hogy végül végrehajtható programot hozzanak létre, amikor az OS megnevezi a "main" függvényét a végrehajtás során (kivéve, ha az egybefonódott program a saját OS, vagy más összetett program, ettől abban az esetben az érkezési pont meg van határozva).

A C programhoz használt bizonyos szavak különleges értelemben vannak értelmezve, ezeket kifejezéseknek (keyword) nevezik. Mások lehetnek nevek (identifier), melyek a program különböző részeit, vagy részegységeit, például struktúrákat, uniókat, számlálókat, típusdefiníciókat, címkéket, vagy makrókat azonosítani, leképezni a programban való megjelenésük során.

Mind a név (amely nem makró), egyes hatókörbe van illesztve (scope), és egyik névterhez sem tartozik. Bizonyos név (identifier) függetlenül attól, hogy mely résznél szerepelnek, vagy más részeknél a forráskód megfogalmazása során egyedi entitásként jön számításba melyen a program kivitelezésekor változatlanul érvényesül.

A függvények definíciója során szintén sorjázik a kódok és kijelentések, ahol a végrehajtani kívánt számítások meg van határozva.

Az egyes nyilvántartási kifejezések és függvények az adott program részében megtalálhatók, és az adott nyelv által levezethető értéket az egyes elemhez rendelték.

#### Kommentek

/* komment */    (1)    
// komment    (2)    (a C99 óta)
1) Gyakran "C stílusú" vagy " több soros" kommentnek nevezik.
2) Gyakran "C++ stílusú" vagy "egy soros" kommentnek nevezik.
A jegyzeteket a fordítási fázis 3-ban eltávolítják a programból, és helyettük egy szóközt helyettesítik.

Stílus-C
A Stílus-C kommentek általában használatosak az aláírások vagy a kódrészletek nagy mennyiségű kommentálására. Azonban használhatók egyes sorok kommentálására is. Kódokat jegyzetelni kívánóképpen adjuk körbe a szöveget /* és */ karakterekkel. A fordító a /* és */ közötti kódot figyelmen kívül hagyja.

Három karakter kombináció, /*, a kód egy adott részének a kezdete. Ez a kombináció egy kódblokk kezdete, ami megjegyzetekben marad, amíg a */ karakterpáros nem érhető el. Ezzel a módszerrel írhatóak a dokumentálási blokkok is, /* és */ karakterekkel, de ez nem tartozik a programozási nyelvre.

Ha ez a kombináció egy karakter konstansban, egy karakterláncban vagy egy megjegyzetben nem szerepel, akkor a komment befejezését jelzi, azaz ha az utolsó * karakter van ekkor a kódblokk vége.
A Stílus-C kommentek nem lehetnek egyben.

C++-stílus
A C++-stílusú kommentek általában egy sort kommentálják. Általában azonban használhatóak egy soros kód kommentálására és több soros kódblokk kommentálására is. Továbbá, a C++-stílusú kommentekben lehet több vonalas kód is. Jegyzetelni kívánó kódokat a // karakterekkel kezdjük, a kód végén pedig egy új sor szintaxisát követve. A fordító a // és a következő új sor közötti kódot figyelmen kívül hagyja.

A kommentek, a karakter konstans, a karakterlánc vagy a komment kivételével, a // karaktereket a kód megjegyzésére használva a kompiler figyelmen kívül hagyja minden multibyte karaktert a // és a következő új sor karaktere között. A kommentek tartalma csak azért is figyelmen kívül hagyják a kompiler, mert ez egy új sor jellege miatt, milyen karakterek is tartoznak a kódokhoz, melyek a kommentet lezárják.

A C-stílusú kommenteket is lehet beágyazni egy C++-stílusú kommentbe, de ellenkezője, C++-stílusú komment beágyazása egy C-stílusú kommentbe azonban nem valósítható meg.

Ha C-stílusú kommentet beágyazunk a C++-stílusú kommentbe, akkor az C++-stílusú komment kódját nem fogják figyelmen kívül hagyni a kompiler:
// Jegyzetek kommentelve, azaz kommentelnek és elhagyják a kompiler.
// Az adott kommentek kódjait azután a kompiler nem figyelmen kívül hagyja a kompiler. /* Kommentek beágyaz