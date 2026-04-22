## Az MSVC beállítása 1.... (Visual Studio környezet betöltése) 

**(vcvarsall.bat)**

**1) Indítsd el a sima CMD-t**

```bat
cmd
```

**2) Futtasd ezt:**

Ez a **kulcs**, ez állítja be a LIB/INCLUDE/PATH változókat.

```bat
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
```

Az útvonal nálad lehet más is, nálam pl a VS a `F:\intelij\vsCommunity\` alatt van.

Tehát nálam így néz ki így néz ki:

```bat
"F:\intelij\vsCommunity\VC\Auxiliary\Build\vcvarsall.bat" x64
```

A `vcvarsall.bat` lefuttatja a következőket:

- beállítja a `LIB` változót
- beállítja az `INCLUDE` változót
- beállítja a `PATH`-ot (link, cl, stb.)
- beállítja a Windows SDK elérési útjait

------

**Ellenőrzés**

Futtasd:

```bat
echo %LIB%
echo %INCLUDE%
where link
where cl
```

És Ha nem üres akkor jó, hogy nem üres.

------

**Most már a clang is működni fog**

```bat
clang test.c
```

------

**Ha azt akarod, hogy mindig így induljon a CMD**

Készíthetsz egy .bat fájlt, amit mindig futtatsz.

**pl. `devcmd.bat`**

```bat
@echo off
"F:\intelij\vsCommunity\VC\Auxiliary\Build\vcvarsall.bat" x64
cmd
```

Ezután mindig ezt indítod, és a sima CMD is **MSVC környezettel** indul.

------

**ha CMake-t is ezzel akarsz használni**

Ugyanebben a CMD-ben:

```bat
cmake -S . -B build -G Ninja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
cmake --build build
```

**Vagy a Következő megoldás még jobb......**

## Az MSVC beállítása 2 . (Környezeti változóval beállítva)

----------------------------------

**Elöször is létre kell hozni 2 db változót**

Az egyik az `INCLUDE` a másik a `LIB`

**Start menü->** `sysdm.cpl` /**vagy CMD-BEN** `rundll32 sysdm.cpl,EditEnvironmentVariables`

majd kattints a **környezeti változókra**(Speciális-> Környezeti változók)

![image-20260125071013386](E:\projects\Books\kepek\image-20260125071013386.png)

![image-20260125071202404](C:\Users\AtiBexx2\AppData\Roaming\Typora\typora-user-images\image-20260125071202404.png)



Majd felül a felhasználói változókhoz adod akkor csak nálad a te felhasználói neved alatt müködik ha pedig a Rendszerváltozókhoz akkor mindenkinél.(ez rád van bízva)

Kattints a az új és a Változó nevének add meg az `INCLUDE` -kifejezést.**(FORDÍTÁSHOZ)**

A változó értékeihez írd be a következőket.

[ **Alapjáraton ez a mappa itt van elvileg**

C:\Program Files (x86)\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\<verzió>\include]

**(Nálam ez így néz ki mert máshol van a visual studio a [mappákat ellenőrizd])**

- F:\intelij\vsCommunity\VC\Tools\MSVC\14.44.35207\include;
- C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\ucrt;
- C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\um;
- C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\shared

**Ügyelj Rá hogy ne hagyj szóközt közöttük mert nem fog müködni !!!!!.**

A következö pedig a` LIB` változó létrehozása.

Kattints a az új és a Változó nevének add meg az` LIB` -kifejezést.**(LINKELÉSHEZ)**

A változó értékeihez írd be a következőket.

[ **Alapjáraton ez a mappa itt van elvileg**

C:\Program Files (x86)\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\<verzió>\lib\x64]

**(Nálam ez így néz ki mert máshol van a visual studio a [mappákat ellenőrizd])**

- F:\intelij\vsCommunity\VC\Tools\MSVC\14.44.35207\lib\x64; 
- C:\Program Files (x86)\Windows Kits\10\Lib\10.0.26100.0\ucrt\x64;
- C:\Program Files (x86)\Windows Kits\10\Lib\10.0.26100.0\um\x64

Ellenőrzés cmd-ben.

`echo %INCLUDE%`

`echo %LIB%`

(Ha kiírja az értékeket akkor jó)

Még egy lépés a **Path** -ben is hozzá kell adni .....(**A Path** változóban)

![image-20260125090332852](E:\projects\Books\kepek\image-20260125090332852.png)

**(Nálam ez így néz ki mert máshol van a visual studio a [mappákat ellenőrizd])**

**Szerkesztés ->ÚJ majd oda  írd be ezeket de külön külön egyesével majd kattints az ok gombra.....**

- F:\intelij\vsCommunity\VC\Tools\MSVC\14.44.35207\bin\HostX64\x64
- C:\Program Files (x86)\Windows Kits\10\bin\10.0.26100.0\x64    ->rc.exe -hez

**Ellenőrzés CMD-ben:**

`where cl.exe`

`where rc.exe`

Ha kiadja az értékeket akkor jó.

**Következő ->**

Hozz létre egy fájlt pl:

**test.cpp**

```
#include <iostream>
int main() {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
```

Majd cmd-ben persze abban a mappában ahol a fájlt létrehoztad írd be `cl test.cpp` ha lefordítja jó.

később ellenőrzés `test.exe`

![image-20260125073857559](E:\projects\Books\kepek\image-20260125073857559.png)

## CODE::BLOCKSBAN 

![image-20260125075036657](E:\projects\Books\kepek\image-20260125075036657.png)

Kattints a Settings ->Complier -re.

![image-20260125075138374](E:\projects\Books\kepek\image-20260125075138374.png)

Majd a select Complier-nél válaszd valamelyik Visual Studio verziót.

![image-20260125075300767](E:\projects\Books\kepek\image-20260125075300767.png)

Kattints a **Copy** gombra majd írd be a kívánt nevet amit szeretnél Visual C++ 2022 **/vagy** MSVCComplier......

Amit létrehoztál kattints arra majd Keresd meg a Search directories és kattints rá.

A **Compiler**-hez add hozzá ezeket.

![image-20260125075717024](E:\projects\Books\kepek\image-20260125075717024.png)

[ **Alapjáraton ezek a mappá itt vannak elvileg**

C:\Program Files (x86)\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\<verzió>\include<br>

C:\Program Files (x86)\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\<verzió>\lib\x64]

**(Nálam ez így néz ki mert máshol van a visual studio a [mappákat ellenőrizd])**

- F:\intelij\vsCommunity\VC\Tools\MSVC\14.50.35717\include
- F:\intelij\vsCommunity\VC\Tools\MSVC\14.50.35717\lib\x64
- C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\ucrt
- C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\shared
- C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\um

**--Majd kattints a Linker-re.**

![image-20260125080135151](E:\projects\Books\kepek\image-20260125080135151.png)

Add hozzá ezeket.....

[ **Alapjáraton ez a mappa itt van elvileg**

C:\Program Files (x86)\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\<verzió>\lib\x64]

**(Nálam ez így néz ki mert máshol van a visual studio a [mappákat ellenőrizd])

- F:\intelij\vsCommunity\VC\Tools\MSVC\14.50.35717\lib\x64
- C:\Program Files (x86)\Windows Kits\10\Lib\10.0.26100.0\ucrt\x64
- C:\Program Files (x86)\Windows Kits\10\Lib\10.0.26100.0\um\x64

Következő kattints  a **ToolChain executables**-re.

![image-20260125080547216](E:\projects\Books\kepek\image-20260125080547216.png)

**A Compilier Installation Directoryhoz írd be a ** <br>

-- F:\intelij\vsCommunity\VC\Tools\MSVC\14.44.35207\bin\Hostx64\x64

(ez máshol alapesetben: **C:\Program Files (x86)\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\<verzió>\bin\Hostx64\x64 )**

Ez a mappa tartalmazza a **fordító binárisokat**:

- `cl.exe` --Linkeld be a  **C compiler** és C++ **Compiler**-hez.
- `link.exe`-- Linkeld be a **Linker for dynamic libs**-hez és a **Linker for static libs**-hez.
- `rc.exe`-- Ez máshol van(C:\Program Files (x86)\Windows Kits\10\bin\10.0.26100.0\x86) ezt is **add hozzá/linkeld be.**
- `nmake.exe` -- Linkeld be a **Make program**-hoz.

Majd az **additional Paths**-re kattintva add hozzá ezeket.

-- F:\intelij\vsCommunity\VC\Tools\MSVC\14.44.35207\bin\Hostx64\x64

(ez máshol alapesetben: **C:\Program Files (x86)\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\<verzió>\bin\Hostx64\x64** )



-- C:\Program Files (x86)\Windows Kits\10\bin\10.0.26100.0\x64

![image-20260125083129346](E:\projects\Books\kepek\image-20260125083129346.png)

Majd állítsd be a **Compiler settings** oldalon alul a **Runtime-nál a `/MTd`**-t legyen bepipálva.

![image-20260125083348162](E:\projects\Books\kepek\image-20260125083348162.png)

Ha kész Kattints az ok gombra beállíthatod a **Set as default** gombal hogy **alapértelmezet** legyen az **msvc-fordító** ha szükséges.

Gyors lista mi mit jelent.

**/MD és /MDd (DLL runtime)**

- A runtime **külön DLL-ben van** (`MSVCRT.dll` vagy `MSVCRTD.dll`)
- **kisebb exe**, de függ a DLL-től

**/MT és /MTd (Static runtime)**

- A runtime **belekerül az exe-be**
- **nagyobb exe**, de **önálló**
- Nem kell a DLL-re támaszkodnia

**Release:**<br>

**/MD** DLL runtime MSVCRT.dll Release ->**kisebb exe dll függöség** <br>

**/MT **Static runtime beépül az exe-be Release -> **nagyobb exe dll függöség nélkül**<br>

<del>**/ML** Multithreaded (régi, deprecated) statikus Release -> **nagyobb exe dll függöség nélkül** (Egyszállas)</del>

**Debug:**<br>

**/MDd** DLL runtime MSVCRTD.dll ->**kisebb exe dll függöség** <br>

**/MTd**Static runtime beépül az exe-be -> **nagyobb exe dll függöség nélkül**<br>

<del>**/MLd **Multithreaded Debug (régi) statikus Debug</del><br>

Gyors teszt:

![image-20260125084754376](E:\projects\Books\kepek\image-20260125084754376.png)



**File->New->Project**

![image-20260125084837032](E:\projects\Books\kepek\image-20260125084837032.png)

**-> Console Application** -> Go ->next -> c++ majd írd be a Project title-hez hogy Test.......

![image-20260125084938784](E:\projects\Books\kepek\image-20260125084938784.png)

**-> Next**

![image-20260125085224087](C:\Users\AtiBexx2\AppData\Roaming\Typora\typora-user-images\image-20260125085224087.png)

A complier-nél válaszd ki azt a nevet amit adtál az msvc fordítónak.

**->Finish**

Majd ->

A **main.cpp**-hez add hozzá:**(Ha nem lenne ott)**

```
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
```

![image-20260125085054721](C:\Users\AtiBexx2\AppData\Roaming\Typora\typora-user-images\image-20260125085054721.png)

Majd debug -ban és release-ban is teszteld müködik e.

És végül Kattints a **build and run** gombra......

![image-20260125085405024](E:\projects\Books\kepek\image-20260125085405024.png)

![image-20260125085430361](E:\projects\Books\kepek\image-20260125085430361.png)

Ha ez vár okés.

**CLIONBAN: ->** 

![image-20260125091052111](E:\projects\Books\kepek\image-20260125091052111.png)

![image-20260125091006252](E:\projects\Books\kepek\image-20260125091006252.png)

Ha a Clion Felajánjlja akkor + gomb visualStudio majd add meg a mappa helyét nálam az

**F:\intelij\vsCommunity** -nél van

(ez máshol alapesetben: **C:\Program Files (x86)\Microsoft Visual Studio\2022\Community**)

Ha nem ajánlja fel akkor a  File-> Settings és keresd meg a képen látható **Build,Execution,Deployment**-et és ott a **Toolchains**-re kattints rá.

![image-20260125091429695](E:\projects\Books\kepek\image-20260125091429695.png)