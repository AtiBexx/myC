**VSCode-ban nincs alapból “Shift+F6” mint CLionban** (az a Refactor → Rename funkció a JetBrains IDE-kben). 

De van rá **megoldás**:

------

## 1️⃣ Beépített átnevezés VSCode-ban

- Windows/Linux: `F2`
- Mac: `fn + F2` vagy `Cmd + F2`

**Mit csinál?**

- Átnevez bármilyen változót, függvényt, osztályt
- Az IDE minden előfordulást próbál automatikusan frissíteni

------

## 2️⃣ LSP / C++ plugin

Ahhoz, hogy a `F2` **működjön C++-ban**, kell a **C/C++ Extension** (Microsoft) vagy **clangd**:

1. Telepítsd a **C/C++ (ms-vscode.cpptools)** kiegészítőt
2. VSCode felajánlja a `F2`-t a változók, függvények átnevezésére
3. Ha clangd-t használsz → sokkal pontosabb

------

## 3️⃣ Alternatívák

- **Ctrl+D** → jelöld ki a következő előfordulást és írj át mindet kézzel (nem IntelliSense-szerű, de gyors)
- **Ctrl+Shift+L** → minden előfordulás kijelölése

------

## 🔹 Összegzés

- **CLion Shift+F6 = VSCode F2** (ha a C++ extension fent van)
- Ha nincs extension → csak sima keresés/cserét tudsz (`Ctrl+F`, `Ctrl+H`)

------

