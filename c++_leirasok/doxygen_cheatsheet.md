# 📚 Doxygen Cheatsheet – Nyelvtanuló App

---

## 📁 Mappastruktúra

```
E:/English/
│
├── src/                  ← itt van a forráskód (.cpp, .h)
│   ├── main.cpp
│   ├── Menu/
│   │   └── menu.h
│   ├── Translate/
│   │   └── translations.h
│   └── settings.h
│
├── docs/                 ← ide generálja a Doxygen a HTML dokumentációt
│                           (automatikusan létrehozza)
│
└── Doxyfile              ← a Doxygen konfigurációs fájl (ide tedd a gyökérbe)
```

---

## ⚙️ Parancsok

### 1. Doxyfile létrehozása (alapértelmezett sablon)
```bash
doxygen -g Doxyfile
```
> Ez létrehoz egy `Doxyfile` nevű fájlt az összes beállítással.
> Ezt kell majd szerkeszteni az alábbi beállításokkal.

---

### 2. Dokumentáció generálása
```bash
doxygen Doxyfile
```
> Beolvassa a `Doxyfile`-t és legenerálja a `docs/` mappába a HTML oldalt.

---

### 3. Ellenőrzés – mi változott a sablonhoz képest
```bash
doxygen -x Doxyfile
```
> Megmutatja csak azokat a sorokat amiket te változtattál meg.
> Hasznos ha nem emlékszel mit módosítottál.

---

## 🔧 Beállítások magyarázata

### 📌 Projekt alapadatok

| Beállítás | Értéked | Mit csinál |
|---|---|---|
| `PROJECT_NAME` | `"Nyelvtanulo App"` | Ez jelenik meg a dokumentáció tetején, a főoldalon |
| `OUTPUT_LANGUAGE` | `Hungarian` | A Doxygen által generált feliratok magyarul jelennek meg (pl. "Osztályok", "Fájlok") |
| `OUTPUT_DIRECTORY` | `docs` | Ide kerül a generált HTML – az `E:/English/docs/` mappába |

---

### 📂 Forrásfájlok

| Beállítás | Értéked | Mit csinál |
|---|---|---|
| `INPUT` | `E:/English/src` | Innen olvassa be a forrásfájlokat |
| `RECURSIVE` | `YES` | Az almappákat is végigkeresi (Menu/, Translate/, stb.) |
| `FILE_PATTERNS` | `*.h *.cpp` | Csak `.h` és `.cpp` fájlokat dolgoz fel, mást figyelmen kívül hagy |

---

### 🔍 Mit dokumentáljon

| Beállítás | Értéked | Mit csinál |
|---|---|---|
| `EXTRACT_ALL` | `YES` | Minden függvényt, osztályt, változót dokumentál – még akkor is ha nincs hozzá Doxygen komment |
| `EXTRACT_PRIVATE` | `YES` | A `private` osztálytagokat is belerakja a dokumentációba |
| `EXTRACT_STATIC` | `YES` | A `static` függvényeket és változókat is dokumentálja |

> 💡 Ha `EXTRACT_ALL = NO` lenne, csak azokat dokumentálná amikhez írtál `/** ... */` kommentet.

---

### 🖥️ Forráskód megjelenítés

| Beállítás | Értéked | Mit csinál |
|---|---|---|
| `SOURCE_BROWSER` | `YES` | A HTML dokumentációban böngészhető a forráskód – rákattintasz egy függvényre és látod a kódot |
| `INLINE_SOURCES` | `YES` | A függvény dokumentációs oldalán magát a forráskódot is megjeleníti |

---

### 🖼️ Képek

| Beállítás | Értéked | Mit csinál |
|---|---|---|
| `IMAGE_PATH` | `docs` | Ha a kommentekben képre hivatkozol (`@image html kep.png`), innen keresi a képfájlt |

---

### 📄 Kimenet formátuma

| Beállítás | Értéked | Mit csinál |
|---|---|---|
| `GENERATE_HTML` | `YES` | Generál HTML dokumentációt – ezt nyitod meg böngészőben |
| `GENERATE_LATEX` | `NO` | NEM generál LaTeX/PDF dokumentációt – nem kell most |

---

### 🔬 C optimalizálás

| Beállítás | Értéked | Mit csinál |
|---|---|---|
| `OPTIMIZE_OUTPUT_FOR_C` | `YES` | C stílusú kimenet – struct-ok, typedef-ek szebben jelennek meg. C++ projektnél elhagyható, de nem árt |

---

## 📝 A kész Doxyfile – csak a fontos sorok

```ini
PROJECT_NAME           = "Nyelvtanulo App"
OUTPUT_LANGUAGE        = Hungarian
OUTPUT_DIRECTORY       = docs

INPUT                  = E:/English/src
RECURSIVE              = YES
FILE_PATTERNS          = *.h *.cpp

EXTRACT_ALL            = YES
EXTRACT_PRIVATE        = YES
EXTRACT_STATIC         = YES

SOURCE_BROWSER         = YES
INLINE_SOURCES         = YES
IMAGE_PATH             = docs

GENERATE_HTML          = YES
GENERATE_LATEX         = NO

OPTIMIZE_OUTPUT_FOR_C  = YES
```

> 💡 A többi beállítást hagyd alapértelmezetten – a `doxygen -g Doxyfile` parancs generálja őket.

---

## 🚀 Teljes folyamat lépésről lépésre

```bash
# 1. Lépj be a projekt gyökérmappájába
cd E:/English

# 2. Generáld le az alap Doxyfile-t
doxygen -g Doxyfile

# 3. Szerkeszd meg a Doxyfile-t (nano, notepad++, CodeBlocks, bármi)
# – írd át a fenti beállításokat

# 4. Generáld le a dokumentációt
doxygen Doxyfile

# 5. Nyisd meg a böngészőben
# E:/English/docs/html/index.html
```

---

## 💡 Hasznos Doxygen komment példák

```cpp
/**
 * @brief Rövid leírás egy sorban
 *
 * @details
 * Hosszabb részletes leírás.
 * Több sorban is folytatható.
 *
 * @param input A bemeneti string amit ellenőrzünk
 * @param maxLength A maximális megengedett hossz
 * @return true  ha érvényes a bemenet
 * @return false ha érvénytelen
 */
bool validateName(const std::string& input, int maxLength);
```

```cpp
/// @brief Egysoros komment – rövid dolgokhoz elegendő
Language programUiLanguage = Language::HUNGARIAN;
```

```cpp
/**
 * @file main.cpp
 * @brief A fájl leírása – a fájl tetejére kerül
 */
```

---

## ⚠️ Gyakori hibák

| Hiba | Ok | Megoldás |
|---|---|---|
| `docs/` mappa nem jön létre | Nincs jogosultság vagy rossz az elérési út | Hozd létre kézzel: `mkdir docs` |
| Magyar karakterek rosszul jelennek meg | Kódolás probléma | A Doxyfile-ban: `DOXYFILE_ENCODING = UTF-8` |
| Nem találja a fájlokat | Rossz INPUT útvonal | Windows-on: `E:/English/src` (perjel, nem backslash) |
| Üres dokumentáció | `EXTRACT_ALL = NO` és nincs Doxygen komment | Állítsd `YES`-re vagy írj `/** */` kommenteket |

---

*Generálva: 2026 | Nyelvtanuló App – Doxygen dokumentáció útmutató*
