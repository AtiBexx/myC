Ez már a CPU belső hardvertervéhez tartozik.

A lényeg: **nem egy program írja be ezt a címet**, hanem a processzor áramkörei vannak úgy megtervezve, hogy resetkor automatikusan egy adott értéket töltsenek be bizonyos regiszterekbe.

### Mi történik resetkor?

A CPU-ban van egy reset áramkör.

Amikor a RESET jel aktív lesz:

- törlődnek bizonyos belső állapotok,
- néhány regiszter előre meghatározott értéket kap,
- a programszámláló (Program Counter, PC) vagy annak megfelelő regiszter fix értékre áll.

Egyszerűsítve:

```text
RESET
 ↓
PC = előre meghatározott cím
 ↓
utasítás olvasása
 ↓
végrehajtás
```

------

### Melyik regiszter?

Architektúrától függ.

Például egy egyszerű CPU-ban:

```text
PC (Program Counter)
```

vagy

```text
IP (Instruction Pointer)
```

tartja a következő végrehajtandó utasítás címét.

Az x86 processzorokban történelmileg a reset állapot például úgy van kialakítva, hogy a CPU egy meghatározott fizikai címről kezdjen futni.

A modern x86 processzoroknál ez kompatibilitási okokból ma is hasonló elven működik.

------

### De honnan kapja ezt az értéket?

A CPU chipen belül vannak logikai kapuk:

- tranzisztorok
- flip-flopok
- multiplexerek
- dekódolók

A reset logika gyakorlatilag ezt csinálja:

```text
ha RESET = 1
    PC <- 0xFFFF0
```

Ez nem szoftver.

Ez maga az elektronikai kapcsolás.

------

### Olyan, mint egy huzalozott szabály

Képzeld el:

```text
if(reset)
{
    program_counter = 0xFFFF0;
}
```

A valóságban ez nem C-kód.

Hanem tranzisztorok hálózata, amely fizikailag ezt az állapotot állítja elő.

------

### Miért pont ott van a BIOS?

A BIOS chipet a gép memóriatérképében úgy helyezték el, hogy azon a címen látszódjon, ahol a CPU reset után keresni fogja az első utasítást.

Például leegyszerűsítve:

```text
0x00000000 - RAM

...

0xFFFF0000 - BIOS ROM
```

A CPU odanéz:

```text
0xFFFF0
```

és máris a ROM-ból olvassa az első utasítást.

------

### Hogyan találták ezt ki?

Ez az úgynevezett bootstrap probléma.

Valaminek el kell indulnia magától.

Ezért a CPU tervezői azt mondják:

```text
Reset után mindig ugyanonnan indulunk.
```

Ez a hardverbe van építve.

Innen jön a "bootstrapping" szó is: a rendszer saját magát húzza fel egy minimális kezdőállapotból.

------

### A legmélyebb szinten mi történik?

A legelső órajel után:

```text
RESET megszűnik
↓
PC = fix érték
↓
címbuszra kikerül a cím
↓
ROM válaszol az utasítással
↓
utasításregiszterbe kerül
↓
dekódolás
↓
végrehajtás
↓
PC növekszik
↓
következő utasítás
```

Innentől a CPU már ugyanazt csinálja, mint amikor a saját programjaid futnak: olvas egy utasítást, dekódolja, végrehajtja. Az egyetlen különbség az, hogy az első címet nem egy program adja meg, hanem a processzor hardverének reset logikája.