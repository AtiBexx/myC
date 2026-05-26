# Argumentumok

```
#include<cstdlib>
#include<cstdio>
#include<iostream>

int main(int argc, char* argv[])
{
    std::cout <<"Az argv[] argumentumai a következők: "<< std::endl;
    //std::cout <<"Az argv[] argumentumai a következők: "<< argv[0] << std::endl;
    //kiírjuk az argumentumokat
    for (int i = 0; i < argc; i++)
    {
        std::cout <<"\nAz Argumentumok = [" << i <<"] : " << argv[i] ;
    }
    
  /*  for (int i = 0; i < argc; i++)
{
    std::cout << "\nAz Argumentumok = [" << i << "] : " << *(argv + i);
} */
    std::cout <<"\n\nEnnyi argumentum van(Az argumentumok száma): "<< argc << std::endl;
    
    //kilépünk
    std::cout << "\nA program kilep." << std::endl;
    std::cout <<"A folytatáshoz kérlek nyomd meg az ENTERT." << std::endl;
    std:: cin.get();
    return 0;
}
```

**output**

```
argPrinting.exe Prüntyi Pákító Ati Nova a e cool learning
Az argv[] argumentumai a következők: 

Az Argumentumok = [0] : argPrinting.exe
Az Argumentumok = [1] : Prüntyi
Az Argumentumok = [2] : Pákító
Az Argumentumok = [3] : Ati
Az Argumentumok = [4] : Nova
Az Argumentumok = [5] : a
Az Argumentumok = [6] : e
Az Argumentumok = [7] : cool
Az Argumentumok = [8] : learning

Ennyi argumentum van(Az argumentumok száma): 9

A program kilep.
A folytatáshoz kérlek nyomd meg az ENTERT.
```

```
argPrinting.exe "Prüntyi Pákító" Ati
Az argv[] argumentumai a következők: 

Az Argumentumok = [0] : argPrinting.exe
Az Argumentumok = [1] : Prüntyi Pákító
Az Argumentumok = [2] : Ati

Ennyi argumentum van(Az argumentumok száma): 3

A program kilep.
A folytatáshoz kérlek nyomd meg az ENTERT.
```

a így indítod:

```
argPrinting.exe "Prüntyi Pákító" Ati
```

akkor a kimenet:

```
argv[1] = Prüntyi Pákító
argv[2] = Ati
```

mert az idézőjel **egy argumentummá teszi a szóközös szöveget**.

Kiadja a mappában lévő fájlokat pl így(ezt használjuk `*.*`)

```
E:\projects\vscode\arg_kiiras>argPrinting.exe *.*
Az argv[] argumentumai a következők:

Az Argumentumok = [0] : argPrinting.exe
Az Argumentumok = [1] : aprint.cpp
Az Argumentumok = [2] : aprint.exe
Az Argumentumok = [3] : argPrinting.cpp
Az Argumentumok = [4] : argPrinting.exe
Az Argumentumok = [5] : person.cpp
Az Argumentumok = [6] : tempCodeRunnerFile.cpp
Az Argumentumok = [7] : tempCodeRunnerFile.exe

Ennyi argumentum van(Az argumentumok száma): 8

A program kilep.
A folytatáshoz kérlek nyomd meg az ENTERT.

```

#### Argumentumok 2

```
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>

int main(int argc, char* argv[]) {

    std::string name;
    int age = 0;

    //kiírjuk az argumentomukat for ciklusal
    for(int i= 0; i < argc; i++)
    {
        std::string arg = argv[i];

        if (arg == "-name" && i + 1 < argc)
        {
            name = argv[i + 1];
            i++;
        }
        else if (arg == "-age" && i +1 <argc)
        {
            age = std::stoi(argv[i + 1]);
            i++;
        }
    }
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;

    return 0;

}
```

**output**

```
e:\projects\vscode\arg_kiiras>cd "e:\projects\vscode\arg_kiiras\" && g++ person.cpp -o person && "e:\projects\vscode\arg_kiiras\"person
Name: 
Age: 0

e:\projects\vscode\arg_kiiras>person.exe -name Ati -age 37
Name: Ati
Age: 37

e:\projects\vscode\arg_kiiras>

----------------------------------------

e:\projects\vscode\arg_kiiras>person.exe -age 37 -name Ati
Name: Ati
Age: 37

e:\projects\vscode\arg_kiiras>
```

Felcserélve is müködik.....

#### Argumentumok 3 map-ben

```
#include <iostream>
#include <map>
#include <string>

int main(int argc, char* argv[])
{
    std::map<std::string, std::string> args;

    for (int i = 1; i < argc; i++)
    {
        std::string key = argv[i];

        if (i + 1 < argc)
        {
            args[key] = argv[i + 1];
            i++;
        }
    }

    std::cout << "Kapott parameterek:\n\n";

    for (auto& p : args)
    {
        std::cout << p.first << " = " << p.second << std::endl;
    }

    return 0;
}
```

**pl -name Ati -age 37 -city Budapest**

```
Kapott parameterek:

-name = Ati
-age = 36
-city = Budapest
```

# Egy extra profi trükk

Ha ezt írod:

```
std::cout << args["-name"];
```

akkor kiírja:

```
Ati
```

# 1️⃣ `argv` mi?

Az `argv` egy **tömb**, pontosabban:

```
char* argv[]
```

Ez azt jelenti:

**egy tömb, amely pointereket tartalmaz karakterláncokra.**

Egyszerűbben:

```
argv = szövegek tömbje
```

példa:

```
program.exe alma korte banan
```

akkor a memória így néz ki:

```
argv
 ↓
+-------+
| ptr0  | → "program.exe"
| ptr1  | → "alma"
| ptr2  | → "korte"
| ptr3  | → "banan"
+-------+
```

------

# argc mi?

Az `argc` azt jelenti:

```
argument count
```

tehát:

```
az argumentumok száma
```

példa:

```
program.exe alma korte banan
```

akkor:

```
argc = 4
```

mert:

```
argv[0] = program.exe
argv[1] = alma
argv[2] = korte
argv[3] = banan
```

------

# Fontos szabály

Az első elem **mindig a program neve**.

```
argv[0] = program neve
```

Ezért a valódi paraméterek általában:

```
argv[1] ... argv[argc-1]
```

------

# Ezért működik a ciklusod

```
for (int i = 0; i < argc; i++)
```

mert:

```
0 → program neve
1 → első paraméter
2 → második paraméter
...
```

------

# Miért pointer?

Az `argv` valójában:

```
char** argv
```

ugyanaz mint:

```
char* argv[]
```

Ezért:

```
argv[i]
```

ugyanaz mint:

```
*(argv + i)
```

Ez **pointer aritmetika**.

------

#  Röviden

| változó   | jelentés            |
| --------- | ------------------- |
| `argc`    | argumentumok száma  |
| `argv`    | argumentumok tömbje |
| `argv[0]` | program neve        |
| `argv[1]` | első paraméter      |

`argc` – Argument Count

`argv` – Argument Vector

A **vector itt nem C++ vector**, hanem matematikai értelemben **lista / tömb**.

```
char* argv[]
```

vagy ugyanaz pointerrel:

```
char** argv
```

## Az **argumentum** jelentése

Az **argumentum** egy **paraméter vagy adat**, amit egy programnak átadsz amikor elindítod.

- Az angol **argument** és a magyar **argumentum** szó a **latin `argumentum`** szóból származik.
- A latin `argumentum` jelentése eredetileg:

> **bizonyíték, érv, érvelés, indok**

- Tehát a szó **logikai, filozófiai kontextusból jön**:
   valami, amivel **alátámasztasz egy állítást**.

Például Cicero írásaiban:

```
"argumentum" = "bizonyíték a vita során"
```

------

## Hogyan került a programozásba?

- A számítógép-tudományban a **program indításakor átadott adatokat** nevezték **argumentumoknak**, mert azok “bizonyítékok”, adatok a programnak, amivel **eldönti, mit csináljon**.
- Az **`argc` = argument count** és **`argv` = argument vector** is innen kapta a nevét.