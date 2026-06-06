# Terminál keresési parancsok — Windows & Linux

---

## 🪟 Windows (Command Prompt / CMD)

### `dir` — fájlok listázása
```
dir
```
Kilistázza az aktuális mappa tartalmát (fájlok + almappák).

```
dir /s /b *.html
```
- `/s` — **rekurzív**: almappákba is bemegy
- `/b` — **bare**: csak a teljes elérési utat írja ki, semmi más
- `*.html` — csak `.html` kiterjesztésű fájlokat keres

---

### `findstr` — szöveg keresése fájlokban vagy kimenetben
```
findstr "assembly" *.html
```
Az aktuális mappában lévő `.html` fájlokban keresi az "assembly" szót.

```
dir /s /b *.html | findstr /i "asm"
```
- `|` — **pipe**: az első parancs kimenetét átadja a másodiknak
- `/i` — **case-insensitive**: kis/nagybetű mindegy

**Kombinálva — fájl megtalálása tartalma alapján:**
```
dir /s /b *.html | findstr /i "asm\|book\|assembly"
```
Minden `.html` fájlt megkeres és szűri, amelynek az *elérési útjában* szerepel "asm", "book" vagy "assembly".

---

### `where` — program/fájl helyének megtalálása
```
where notepad
```
Megmutatja, hogy egy adott program hol van a rendszeren.

---

### PowerShell (modernebb, erősebb)
```powershell
Get-ChildItem -Recurse -Filter "*.html" | Select-String -Pattern "assembly"
```
- `Get-ChildItem -Recurse` — rekurzívan listáz minden fájlt
- `-Filter "*.html"` — csak `.html` fájlokat
- `Select-String -Pattern "assembly"` — amelyekben szerepel az "assembly" szó

```powershell
Get-ChildItem -Path C:\ -Recurse -Filter "*.html" -ErrorAction SilentlyContinue
```
Az egész C: meghajtón keres `.html` fájlokat, hibákat elnémítva.

---

## 🐧 Linux (Bash terminál)

### `find` — fájlok keresése név vagy típus alapján
```bash
find . -name "*.html"
```
- `.` — az aktuális mappától kezdve keres
- `-name "*.html"` — `.html` kiterjesztésű fájlok

```bash
find / -name "*.html" 2>/dev/null
```
- `/` — az egész fájlrendszerben keres (gyökértől)
- `2>/dev/null` — hibaüzeneteket eldobja (pl. "Permission denied")

```bash
find ~ -name "*asm*" -o -name "*book*"
```
- `~` — a saját home mappádban keres
- `-o` — **OR**: vagy ez, vagy az a névminta

---

### `grep` — szöveg keresése fájlokban
```bash
grep -r "assembly" .
```
- `-r` — **rekurzív**: almappákba is bemegy
- Megmutatja melyik fájlban és melyik sorban szerepel az "assembly"

```bash
grep -rl "assembly" .
```
- `-l` — csak a fájlneveket írja ki, nem a sorokat

```bash
grep -ri "bios\|nasm\|assembly" . --include="*.html"
```
- `-i` — kis/nagybetű mindegy
- `\|` — **OR**: többféle szóra keres egyszerre
- `--include="*.html"` — csak `.html` fájlokban keres

---

### `find` + `grep` kombinálva
```bash
find . -name "*.html" -exec grep -l "assembly" {} \;
```
Megkeresi az összes `.html` fájlt, majd megnézi melyikben van "assembly" szó — és csak azok nevét írja ki.

---

### `locate` — gyors keresés az adatbázisból
```bash
locate "*.html" | grep -i "asm"
```
- Sokkal **gyorsabb** mint a `find`, mert egy előre felépített adatbázisból keres
- Hátrány: nem mindig naprakész (frissítés: `sudo updatedb`)

---

## 📋 Összefoglaló táblázat

| Parancs | Rendszer | Mire való |
|---|---|---|
| `dir /s /b *.html` | Windows CMD | HTML fájlok keresése rekurzívan |
| `findstr /i "szó"` | Windows CMD | Szöveg keresése fájlokban |
| `Get-ChildItem -Recurse` | PowerShell | Fájlok keresése (modernebb) |
| `find . -name "*.html"` | Linux | Fájlok keresése névminta alapján |
| `grep -r "szöveg" .` | Linux | Szöveg keresése fájlokban rekurzívan |
| `locate "*.html"` | Linux | Gyors keresés (adatbázisból) |

---

> 💡 **Tipp:** Ha VS Code-ban dolgozol, a `Ctrl+Shift+F` globálisan keres az összes megnyitott mappában — sokszor gyorsabb mint a terminál.
