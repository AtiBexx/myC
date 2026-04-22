## Clang Beállítása_CodeBlocks-ban

**Teljes setup: Clang + CMake + Ninja **

**1. Telepítsd a szükséges eszközöket:**

**Clang:**

Cmd-ben(Írd be).......

```bash
winget install LLVM.LLVM
```

**/vagy ha nem müködik akkor** https://releases.llvm.org/download.html **vagy**

[Release LLVM 21.1.0 · llvm/llvm-project](https://github.com/llvm/llvm-project/releases/tag/llvmorg-21.1.0)

![image-20260125103835413](E:\projects\Books\kepek\image-20260125103835413.png)

Ott válaszd ki a neked megfelelő verziót ha windows-t használsz akkor azt **installer/achive** verzió.

- Archive -tömörített**(zip/rar)**
- Installer - **setup-os installációs verzió**

ellenőrzés **CMD-ben**

`where clang`

vagy

`clang++ --version`

Ha kiírja a helyét akkor okés.<br>

![image-20260125124053322](E:\projects\Books\kepek\image-20260125124053322.png)

Ha a tömőrített verziót töltött le akkor hozzá kell adni a környezeti változóhoz Windows-on azt a mappát amit kicsomgoltál a **Path** változóhoz.

**CMake:**

Cmd-ben: (Ha nem müködik akkor le kell tölteni)

Írd be.......

```bash
winget install Kitware.CMake
```

Vagy: https://cmake.org/download/

![image-20260125104523670](E:\projects\Books\kepek\image-20260125104523670.png)

Itt is ugyanaz a felállás a **zip** a tömörített a **.msi** verzió az installációs setup-os verzió.

**FONTOS!!!! ugyanúgy ha a tömőrített verziót töltött le akkor hozzá kell adni a környezeti változóhoz Windows-on azt a mappát amit kicsomgoltál a `Path `változóhoz.**

Ellenőrzés cmd-ben:

`where cmake`

Ha kiírja a helyét akkor okés.<br>

**NINJA** ->

`winget install Ninja-build.Ninja`

Ha nem müködik akkor (**vagy más helyre szeretnéd rakni** )

[https://github.com/ninja-build/ninja/releases](https://github.com/ninja-build/ninja/releases)

![image-20260125105342759](E:\projects\Books\kepek\image-20260125105342759.png)

A win-arm -es verzio az mobil alkalmazásokhoz jó úgy .hogy windows-ra a **ninja-win.zip**

 -et kell letölteni.

![image-20260125110007735](E:\projects\Books\kepek\image-20260125110007735.png)

Ne felejtsd el hozzáadni a környezeti változók-hoz a **Path** változóhoz.

(De melyikhez gyors segítség!)

<dl>
    <dt>1.<b>Felhasználói (User) környezeti változók</b></dt>
    <dd>csak a jelenlegi felhasználóra vonatkozik a beállítás(Csak neked a te profilodban érhető el)</dd>
    <br>
    <dt><b>2.Rendszer (System / Global) környezeti változók[Rendszerváltozók]</b></dt>
    <dd>minden felhasználóra vonatkozik a beállítás(Mindenki számára elérhető globálisan)</dd>
</dl>

**A te döntésed hova adod hozzá....**

-------

**{Ha nem müködik a winget és te azzal szeretnéd megcsinálni.}**

<dl>
    <dt>Nyisd meg a <b>PowerShellt</b> adminként</dt>
    <dt>És írd be:</dt>
    <dd><code><strong>Invoke-WebRequest -Uri https://aka.ms/getwinget -OutFile winget.appxbundle
Add-AppxPackage .\winget.appxbundleInvoke-WebRequest -Uri https://aka.ms/getwinget -OutFile winget.appxbundle
Add-AppxPackage .\winget.appxbundle</strong></code></dd>
</dl>

Ez letölti és telepíti a winget-et.

**Ellenőrzés cmd-ben.**

`winget --version`

Ha nem müködik töltsd le az **AppStore installert**.

-------------

**Clang beállítása Code::Blockban**

**Állítsd be az LLVM Clang Compliere** <br>

(Át is másolhatod a copy gombal egy másik példányra ha akarod)

![image-20260125155907292](E:\projects\Books\kepek\image-20260125155907292.png)



Most állísd be a mappát ahol a `clang` található....<br>

![image-20260125160104852](E:\projects\Books\kepek\image-20260125160104852.png)



Add hozzá ha wiindowsra fejlesztesz ..... <br>**C complier `clang-cl.exe`**<br>

**C++ Complier `clang-cl.exe`**<br>

**Linker for dynamic libs:** **`clang-cl.exe`**

**Linker for static libs :`llvm-ar.exe` **<br>

![image-20260125160530389](E:\projects\Books\kepek\image-20260125160530389.png)

A complier settingsnél írd át a dolgokat....pl a **Have clang++ follow the C++17 ISO C++ language standard** -nál Kattints a **Modifly flagre** <br> írd át  `/std:c++17` a `-std:c++17 helyet`

![image-20260125160617867](E:\projects\Books\kepek\image-20260125160617867.png)

**Add hozzá a dynamikus linkelést ->**

![image-20260125160842627](E:\projects\Books\kepek\image-20260125160842627.png)

**kattints a New Flag-re ott a Category-nál ird be a Dinamic Linkinget majd ->** <br>

**name: Dinamic Linking_for Debug**  **linker flags:  /MD**

**ugyanúgy egy uj flag-ben name:  Dinamic Linking_for_Release<br> Category Dinamic Linking  linker flags  /MT** 





