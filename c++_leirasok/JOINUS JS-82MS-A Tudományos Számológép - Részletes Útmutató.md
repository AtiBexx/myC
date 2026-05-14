# JOINUS JS-82MS-A Tudományos Számológép - Részletes Útmutató

## Alapvető Gombok

### Számok és Alapműveletek

- **0-9**: Számok bevitele
- **+, -, ×, ÷**: Alapműveletek (összeadás, kivonás, szorzás, osztás)
- **=**: Eredmény kiszámítása
- **AC** (All Clear): Mindent töröl, újrakezdés
- **DEL**: Utolsó karakter törlése
- **.** (pont): Tizedesvessző

### Előjel és Törtműveletek

- **(-)**: Negatív szám (előjel váltás)
- **a b/c**: Vegyes tört bevitele (pl. 2 1/3)
- **d/c**: Tört és decimális közötti váltás

### Hatványozás és Gyökök

- **x²**: Négyzetre emelés
- **x³**: Köbre emelés
- **x^y**: Tetszőleges hatványozás (x az y-adikon) - **EZ KELL A 2^6 SZÁMÍTÁSHOZ!**
- **√**: Négyzetgyök
- **∛**: Köbgyök
- **ⁿ√**: n-edik gyök

### Tudományos Funkciók

- **sin, cos, tan**: Szögfüggvények
- **sin⁻¹, cos⁻¹, tan⁻¹**: Inverz szögfüggvények (SHIFT + sin/cos/tan)
- **log**: 10-es alapú logaritmus
- **ln**: Természetes logaritmus (e alapú)
- **10^x**: 10 hatványa
- **e^x**: e hatványa
- **hyp**: Hiperbolikus függvények

### Speciális Gombok

- **SHIFT** (narancssárga): Második funkció aktiválása (a gombok feletti narancssárga szöveg)
- **ALPHA** (piros): Betűk és változók használata
- **MODE**: Üzemmód váltás
- **ENG**: Mérnöki (engineering) formátum
- **STO**: Érték tárolása memóriába
- **RCL**: Tárolt érték visszahívása
- **Pol(** és **Rec(**: Polár és derékszögű koordináták közötti váltás
- **Rnd**: Véletlen szám generálás
- **Ran#**: Véletlen szám (0 és 1 között)
- **DRG>**: Szögmértékegység váltás (DEG/RAD/GRAD)
- **Ans**: Előző eredmény

### Memória Gombok

- **M+**: Hozzáadás a memóriához
- **M-**: Kivonás a memóriából (DEL+M+)

### Statisztikai Gombok (Alsó rész)

- **DATA**: Adat bevitele statisztikai számításokhoz
- **Σ-SUM, Σ-VAR**: Összegzés, variancia számítások
- **π**: Pi konstans
- **EXP**: Exponenciális formátum (×10^n)

## BINÁRIS ÉS HEXADECIMÁLIS SZÁMÍTÁSOKHOZ

**FONTOS: Ez a számológép NEM rendelkezik beépített BIN/HEX/OCT móddal!**

### Amit TUDSZ csinálni:

#### 1. **Hatványozás (2^n számítások)**

```
Példa: 2^6 kiszámítása
- Nyomd meg: 2
- Nyomd meg: x^y (hatványozás gomb)
- Nyomd meg: 6
- Nyomd meg: =
- Eredmény: 64
```

#### 2. **Osztás 2-vel vagy 2 hatványaival**

```
Példa: 64 ÷ 2 = 32
- 64 ÷ 2 = (vagy 64 × 0.5 =)
```

#### 3. **Tárolás memóriába (A-F betűkhöz)**

```
Érték mentése "A" változóba:
- Írd be a számot (pl. 255)
- Nyomd meg: STO
- Nyomd meg: ALPHA
- Nyomd meg: ) gomb (ez az "A" ALPHA mód alatt)
- Kész! Az érték tárolva van

Visszahívás:
- Nyomd meg: RCL
- Nyomd meg: ALPHA  
- Nyomd meg: ) gomb (A betű)
- Megjelenik: 255
```

**ALPHA módban elérhető betűk:**

- **A**: ) gomb
- **B**: ( gomb
- **C**: DEG gomb
- **D**: hyp gomb
- **E**: sin gomb
- **F**: cos gomb
- **M**: M+ gomb
- **X**: SHIFT + ) gomb
- **Y**: SHIFT + ( gomb

### MIT NEM TUDSZ:

❌ **Nincs direkt BIN/HEX/OCT/DEC mód** ❌ **Nem tudsz közvetlenül bináris számokat beírni** (pl. 1010₂) ❌ **Nem tudsz hexadecimális számokat beírni** (pl. FF₁₆) ❌ **Nincs automatikus átváltás számrendszerek között**

### MEGOLDÁS Bináris/Hex Számításhoz:

**Manuálisan kell számolnod:**

#### Bináris → Decimális:

```
1010₂ átváltása:
= 1×2³ + 0×2² + 1×2¹ + 0×2⁰
= 1×8 + 0×4 + 1×2 + 0×1

Számológépen:
1 × 2 x^y 3 = → 8
+ 0 × 2 x^y 2 = → 0  
+ 1 × 2 x^y 1 = → 2
+ 0 × 2 x^y 0 = → 0
Össz = 10
```

#### Decimális → Bináris (osztásos módszer):

```
10 átváltása binárisba:
10 ÷ 2 = 5 maradék 0
5 ÷ 2 = 2 maradék 1
2 ÷ 2 = 1 maradék 0
1 ÷ 2 = 0 maradék 1

Eredmény (alulról felfelé): 1010₂
```

#### Hexadecimális számítás:

```
FF₁₆ → Decimális:
= F×16¹ + F×16⁰
= 15×16 + 15×1

Számológépen:
15 × 16 x^y 1 = → 240
+ 15 × 16 x^y 0 = → 15
Össz = 255
```

## PRAKTIKUS TIPPEK PROGRAMOZÓI SZÁMÍTÁSOKHOZ:

### 1. **2 hatványainak gyors kiszámítása:**

```
2^0 = 1
2^1 = 2
2^2 = 4
2^3 = 8
2^4 = 16
2^5 = 32
2^6 = 64
2^7 = 128
2^8 = 256

Használd: 2 x^y n =
```

### 2. **Bitek száma byte-okban:**

```
1 byte = 2^8 = 256 érték (0-255)
2 byte = 2^16 = 65536
4 byte = 2^32 = 4294967296

Számold: 2 x^y 8 = stb.
```

### 3. **Memória használata táblázathoz:**

```
Tárold el a gyakori értékeket:
255 → STO → ALPHA → ) (A-ba)
256 → STO → ALPHA → ( (B-be)
128 → STO → ALPHA → DEG (C-be)
```

## ÖSSZEFOGLALÁS:

✅ **Használható:** Hatványozás (2^n), osztás, szorzás, memória tárolás
 ✅ **Jó:** Decimális számítások, konverziók kézi számolással
 ❌ **Nem használható:** Direkt BIN/HEX/OCT bevitel és megjelenítés

**AJÁNLÁS:** Ha gyakran dolgozol bináris/hexadecimális számokkal, érdemes egy **programozói számológépet** venni (pl. Casio fx-991EX CLASSWIZ, vagy okostelefon app), amely rendelkezik BIN/HEX/OCT móddal.

Van még kérdésed valamelyik funkcióról? 😊