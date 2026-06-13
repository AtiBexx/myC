# C++ Gyakorlatok – TODO lista

## 1. POINTER alapok
**Feladat:** Hozz létre egy int változót, egy pointert ami rá mutat,
írd ki a változó értékét a pointeren keresztül, majd változtasd meg
a pointer segítségével az értéket és írd ki újra.
```cpp
// SNIPPET:
int szam = 42;
int* p = &szam;
// ... te töltöd ki
```

---

## 2. POINTER tömbök (heap)
**Feladat:** Foglalj le `new`-val egy 5 elemű int tömböt,
töltsd fel 1-5-ig, írd ki az elemeket, majd szabadítsd fel `delete[]`-vel.
```cpp
// SNIPPET:
int* tomb = new int[5];
// ... te töltöd ki
```

---

## 3. POINTER függvénynek átadva
**Feladat:** Írj egy függvényt ami pointert kap paraméterként,
és megduplázza az értékét. Hívd meg és írd ki az eredményt.
```cpp
// SNIPPET:
void dupla(int* p) {
    // ... te töltöd ki
}
```

---

## 4. REFERENCIA (&) alapok
**Feladat:** Írj egy `csere` függvényt referenciával ami felcseréli
két int változó értékét. Csináld meg pointerrel is – figyeld meg a különbséget!
```cpp
// SNIPPET:
void csere(int& a, int& b) {
    // ... te töltöd ki
}
```

---

## 5. REFERENCIA – const &
**Feladat:** Írj egy függvényt ami `const std::string&` paramétert kap
és kiírja a hosszát és nagy betűsen a szöveget. Figyelj: nem módosíthatod!
```cpp
// SNIPPET:
void kiir(const std::string& s) {
    // ... te töltöd ki
}
```

---

## 6. ÉRTÉKMÁSOLÓ (Rule of Three)
**Feladat:** Írj egy `Doboz` osztályt ami egy `int*` tömböt tárol heap-en.
Valósítsd meg:
- Konstruktor (méret + feltöltés)
- Destruktor
- Másoló konstruktor
- Másoló `operator=`

Teszteld: másolj egy objektumot, változtasd meg az eredetit,
ellenőrizd hogy a másolat NEM változott!
```cpp
// SNIPPET:
class Doboz {
    int* adatok;
    int meret;
public:
    Doboz(int m) : meret(m) {
        adatok = new int[meret];
    }
    // ... destruktor, másoló konstruktor, operator= te töltöd ki
};
```

---

## 7. MOVE (Rule of Five) – Áthelyező konstruktor
**Feladat:** Bővítsd az előző `Doboz` osztályt:
- Move konstruktor (`&&`)
- Move `operator=`

Teszteld: hozz létre egy ideiglenes objektumot egy függvénnyel,
add vissza érték szerint, figyeld meg hogy move történik másolás helyett!
```cpp
// SNIPPET:
Doboz gyar(int meret) {
    Doboz b(meret);
    return b; // <- move fog történni!
}
```

---

## 8. ÖSSZEFOGLALÓ feladat
**Feladat:** Írj egy `Szoveg` osztályt ami `char*`-ot tárol (mint az EnTarolom),
de most egyedül, snippet nélkül. Valósítsd meg az összes 5 metódust.
Teszteld az összeset egy `main()`-ben.

---

## Fogalmak összefoglaló (ha elfelejtened)
| Név | Mit jelent |
|-----|-----------|
| Rule of Three | destruktor + másoló konstruktor + másoló operator= |
| Rule of Five | Rule of Three + move konstruktor + move operator= |
| `&` | referencia – létező változóra mutat |
| `&&` | rvalue referencia – ideiglenes értékre mutat (move) |
| `const &` | csak olvasható referencia |
| `new` / `delete` | heap foglalás / felszabadítás |
