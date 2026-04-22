## Linkelés

**Statikus linkelés (static linking)**

- **NINCS külön DLL** futásidőben
- A szükséges kód **beleég a .exe-be**
- Egyetlen futtatható fájlod van

Előnyök:

- Nem hiányozhat DLL → “elindul bárhol”
- Verzióütközés nincs

Hátrányok:

- Nagyobb .exe
- Ha több program használja ugyanazt a libet → mindegyikben benne van külön



------

**Dinamikus linkelés (dynamic linking)**

- **DLL-ekre támaszkodik**
- A .exe csak „hivatkozik” rájuk
- Futáskor kell, hogy meglegyenek a DLL-ek

Előnyök:

- Kisebb .exe
- DLL frissíthető újrafordítás nélkül
- Memória megosztás több program között

Hátrányok:

- Hiányzó DLL → nem indul

Tipikus fájlok:

- **Windows**: `*.dll` + `*.lib` (import lib)
- **Linux**: `.so`
- **macOS**: `.dylib`

------

 **Gyors példa (MSVC / Code::Blocks vonalon)**

- `libcmt.lib` → **statikus CRT**
- `msvcrt.dll` → **dinamikus CRT**
- `/MT` → statikus runtime
- `/MD` → dinamikus runtime