# Fibonacci

**Fibonacci** teljes neve **Leonardo Pisano Bigollo** volt, és **1170 körül született Pisában, Olaszországban**.

- Őt hívták később egyszerűen **Fibonacci-nak**, ami a “filius Bonacci” rövidítése, azaz “Bonacci fia”.
- Matematikusként ismert a **középkori Európában**, és azért lett híres, mert bevezette **az indiai-arab számrendszert Európába**, ami a mai 0–9 számok alapja.

A legismertebb magyarázat a **nyúltenyésztés problémája** volt, amit **Fibonacci 1202-ben a „Liber Abaci” című könyvében** írt le:

- Képzelj el **egy nyúlpárt**, amely minden hónapban szaporodik:
  1. Hónap: 1 pár nyúl
  2. Hónap: még mindig 1 pár (mert még nem szaporodtak)
  3. Hónap: 2 pár (az első pár szaporodott)
  4. Hónap: 3 pár
  5. Hónap: 5 pár
  6. Hónap: 8 pár
- Így jön ki a sorozat: 1, 1, 2, 3, 5, 8 …

Tehát a Fibonacci-sorozat **eredetileg egy gyakorlati probléma modellezésére született**, hogy megmutassa, hogyan nő egy populáció hónapról hónapra, ha minden pár az előző hónapokban születettekből szaporodik.

-------------------

#### Sorozat

Első két szám: **0, 1**

Harmadik szám = előző kettő összege: **0 + 1 = 1** → sorozat: 0, 1, 1

Negyedik szám = előző kettő összege: **1 + 1 = 2** → sorozat: 0, 1, 1, 2

Ötödik szám = előző kettő összege: **1 + 2 = 3** → sorozat: 0, 1, 1, 2, 3

Hatodik szám = előző kettő összege: **2 + 3 = 5** → sorozat: 0, 1, 1, 2, 3, 5

Hetedik szám = előző kettő összege: **3 + 5 = 8** → sorozat: 0, 1, 1, 2, 3, 5, 8

1. 0 -> ez csak szám
2. 1 -> ez csak szám
3. 0+1 = 1 -> itt már összeadás az elözö 2 szám összege
4. 1+1 = 2 ->itt is
5. 1+2 = 3
6. 2+3 = 5
7. 3 + 5= 8
8. 5 + 8= 13 

Igen, Ati, teljesen értelek, és nagyon jó, hogy önállóan akarsz rájönni. 🙂
Lépésről lépésre elmagyarázom, mi a **lineáris** és mi a **rekurzív**, miért akarunk lineárisan gondolkodni, és miért nem mindig működik ez a Fibonacci-sorozatnál.

------

### Mi az a **lineáris**?

**Lineáris** azt jelenti, hogy **egyenletes, egyenes, előrehaladó, lépésről-lépésre történő folyamat**.

- A matematika és programozásban: ha minden lépés ugyanúgy nő vagy csökken, például **+1 minden lépésben**, az lineáris.
- Példa: 1, 2, 3, 4, 5 … minden szám **1-gyel nő**, ez lineáris növekedés.
- Zenében is használhatod ezt a hasonlatot: ha a hangfalad **lineárisan adja a hangot**, akkor minden frekvenciát egyenletesen kapsz, nincs kiugrás, egyenletes.

**Az agyad szeret lineárisan gondolkodni**, mert:

- egyszerű és kiszámítható
- könnyen átlátható
- megszoktad az iskolában (szorzás, összeadás, sorozatok egyszerűen)

Ezért próbáltad **a Fibonacci-számot úgy számolni, hogy a sorszámot szorozod valamilyen fix számmal**, mert ez a lineáris gondolkodás rövidítése.

------

### Mi az a **rekurzív**?

**Rekurzív** azt jelenti, hogy **valami önmagára hivatkozik**, az előző eredményekből számítjuk ki a következőt.

- A Fibonacci-sorozat rekurzív:
  [
  F(n) = F(n-1) + F(n-2)
  ]
  Ez azt jelenti: a **n-edik szám = az előző kettő összege**.
- Nem a sorszámtól függ, hanem az előző lépésekből építkezik.

Példa vizuálisan (sorozat kezdete 0,1):

- 0, 1 → kezdés
- 1 = 0+1
- 2 = 1+1
- 3 = 1+2
- 5 = 2+3
- 8 = 3+5
  Minden szám **az előző kettőből jön**, nem a sorszámtól.

------

### Miért akarunk lineárisan gondolkodni?

- Könnyebb az agynak: **egyenes, kiszámítható, rövidtávon működik**.
- A “rekurzív” gondolkodás **több lépésből építkezik**, és az agyadnak **többet kell visszamenőleg tartani**.
- Ezért próbáltad intuitíve “szorzással” megoldani, mert az **egyszerűbbnek tűnt**, gyorsabban tudod fejben csinálni.

------

### Miért nem mindig jó lineárisan gondolkodni?

- Mert a Fibonacci **nem lineáris**, minden szám **nem egyenesen nő**, hanem **az előző két szám összege szerint**, így a logika más:
  - Lineárisan: 1, 2, 3, 4, 5 …
  - Fibonacci: 1, 2, 3, 5, 8, 13 …
- Ha lineárisan gondolkodsz, **félrecsúszik a számolás**, ahogy nálad is történt.

------

###  Miért jó a rekurzív gondolkodás?

- Megtanulod **látni az előző lépéseket, összefüggéseket**
- Nem kell sorszámokat vagy szorzásokat kitalálni
- Könnyebben érted az olyan sorozatokat, mint Fibonacci, mert **logikusan építkezik**

------

