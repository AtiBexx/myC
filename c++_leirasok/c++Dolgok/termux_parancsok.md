# Termux Túlélőkészlet: A legfontosabb parancsok

Ez a jegyzet tartalmazza az összes olyan parancsot, amire szükséged lesz a Termuxban való fejlesztéshez, fájlkezeléshez és rendszerkarbantartáshoz.

---

## 1. Rendszer és Csomagkezelés (A szoftverek lelke)
- `pkg update && pkg upgrade` : A rendszer és az összes telepített program frissítése. **(Érdemes hetente futtatni!)**
- `pkg install <név>` : Új eszköz telepítése (pl. `pkg install clang`, `pkg install make`).
- `pkg uninstall <név>` : Program törlése.
- `pkg search <név>` : Keresés az elérhető programok között.
- `pkg list-installed` : Kilistázza az összes már telepített csomagot.
- `termux-setup-storage` : **Kritikus!** Engedélyt kér a telefon tárhelyéhez. E nélkül nem látod a képeidet vagy letöltéseidet.

---

## 2. Fájlkezelés és Navigáció (Mozgás a terminálban)
- `pwd` : Megmutatja az aktuális mappa teljes útvonalát (Print Working Directory).
- `ls` : Kilistázza a mappa tartalmát.
- `ls -la` : Minden fájlt mutat (a rejtett `.dotfile`-okat is) mérettel és dátummal.
- `cd <mappa>` : Belépés egy mappába.
- `cd ..` : Visszalépés a szülőmappába.
- `cd ~` : Ugrás a "home" mappába (kezdőpont).
- `mkdir <név>` : Új mappa létrehozása.
- `touch <fájlnév>` : Új üres fájl létrehozása.
- `rm <fájl>` : Fájl törlése.
- `rm -rf <mappa>` : Mappa törlése minden tartalmával együtt (nagyon óvatosan!).
- `cp <forrás> <cél>` : Másolás.
- `mv <forrás> <cél>` : Áthelyezés vagy átnevezés.
- `cat <fájl>` : A fájl tartalmának kiírása a képernyőre.

---

## 3. C++ Fejlesztői Eszközök
- `clang++ <fájl>.cpp -o <név>` : C++ kód fordítása.
- `make` : Automatizált fordítás a Makefile alapján.
- `./<név>` : A lefordított program elindítása.
- `gdb <név>` : Hibakereső (Debugger) indítása.
- `cmake .` : Fordítási szabályok generálása modern projektekhez.

---

## 4. Termux-API (Android funkciók elérése)
*Ehhez telepíteni kell a `pkg install termux-api` csomagot és a Google Play-ből a Termux:API appot!*
- `termux-vibrate -d 500` : Megrezegteti a telefont (500 ms).
- `termux-battery-status` : Megmutatja az akku állapotát, hőmérsékletét.
- `termux-clipboard-get` : Kiolvassa a vágólapot (Ctrl+V).
- `termux-clipboard-set <szöveg>` : Szöveget másol a vágólapra (Ctrl+C).
- `termux-toast <üzenet>` : Kis úszó értesítést dob fel a kijelzőn.
- `termux-tts-speak <szöveg>` : Felolvassa a szöveget (Android hangján).

---

## 5. Hálózat és Folyamatok
- `ifconfig` vagy `ip a` : Megmutatja a telefonod IP címét.
- `ping <cím>` : Ellenőrzi az internetkapcsolatot (pl. `ping google.com`).
- `top` : Mutatja a futó folyamatokat (mennyi RAM-ot/CPU-t esznek). Kilépés: `q`.
- `ps` : Aktuális folyamatok listája.
- `kill <PID>` : Egy beragadt program leállítása a folyamatazonosítója (PID) alapján.

---

## 6. Szuper Tippek (Gyorsító billentyűk)
- **Hangerő Fel + Q** : Megmutatja az extra billentyűzet-sort (ESC, TAB, CTRL, stb.).
- **TAB** : Automatikus kiegészítés (elkezded gépelni a fájlnevet, nyomsz egy TAB-ot, és befejezi helyetted).
- **Hangerő Fel + W, A, S, D** : Kurzor mozgatása (felfelé, balra, lefelé, jobbra).
- **Hangerő Le + C** : A futó program azonnali leállítása (Cancel).
- **Hangerő Fel + L** : Képernyő letakarítása (Clear).

---

## 7. Takarítás és Kilépés
- `clear` : Képernyő törlése.
- `history` : Az összes korábban beírt parancs listája.
- `exit` : Kilépés a Termuxból.

**Gemmi tanácsa:** Ha az Acode-ban írod a kódot, a `termux-setup-storage` után a `/sdcard` mappán keresztül tudod a legkönnyebben cserélni a fájlokat a Termux és a grafikus felület között! 🚀📱✨
