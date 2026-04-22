# Ha beragad a VSCODE

------

## 1️⃣ Developer: Reload Window

Ez gyakorlatilag **újraindítja az egész VSCode ablakot**, és újra betölti az összes extension-t.

- Nyomd: `Ctrl + Shift + P`
- Írd be: `Reload Window`
- Válaszd: **Developer: Reload Window**
- Enter

> Ha magyar VSCode-od van, lehet a neve: `Fejlesztő: Ablak újratöltése`, de ugyanazt csinálja.

------

## 2️⃣ Clangd: Restart Language Server

Ez csak a **clangd nyelvi szervert** indítja újra, ami IntelliSense-t szolgálja C/C++-ban.
Hasznos, ha header fájlok változnak, és a piros aláhúzás nem tűnik el.

- Nyomd: `Ctrl + Shift + P`
- Írd be: `Clangd: Restart`
- Válaszd: **Clangd: Restart Language Server**
- Enter

> Ez sokkal gyorsabb, mint teljes VSCode reload.

------

## 3️⃣ Compile / Build

Minden más trükk helyett: **ha a kód fordul, az a “valóság”**.

- Nyomd: `Ctrl + Shift + B` (ha build task van beállítva)
- Vagy manuálisan a terminálban:

```bash
g++ main.cpp overload.cpp -o program
./program
```

> Ha fordul, a kód jó. IntelliSense hibái csak vizuális jelzések.

------

### Extra tipp:

Ha gyakran tanulsz vagy kísérletezel:

- Clangd / clang-tidy lassít → kikapcsolható ideiglenesen
- VSCode → Settings → C/C++ → Code Analysis → clang-tidy OFF

------

Ha akarod, leírhatom neked **egyetlen workflow-t**, ami VSCode-ban a **leggyorsabb C++ tanulási környezet**:

- nem ragad be
- gyors a header update
- nem kell folyton reload.

