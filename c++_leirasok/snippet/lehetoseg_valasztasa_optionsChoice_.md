```
int lehetoseg;
cout <<"Add meg az 1, 2, vagy a 3. lehetőség egyikét:";
cin >> lehetoseg;

switch(lehetoseg)
{
case 1:
//az első lehetőség
break;
case 2:
//a második lehetőség
break;
case 3:
//a harmadik lehetőség
break;

default:
cout << "Nem 1-et, 2-őt, vagy 3-at adtál meg\n";
}
```

Please select option 1, 2, or 3:

#### exit parancsal

```
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int lehetoseg;
    cout << "Add meg az 1, 2, vagy a 3. lehetőség egyikét: ";
    cin >> lehetoseg;

    switch(lehetoseg)
    {
        case 1:
            cout << "Első lehetőség\n";
            break;
        case 2:
            cout << "Második lehetőség\n";
            break;
        case 3:
            cout << "Harmadik lehetőség\n";
            break;
        default:
            cout << "Nem 1-et, 2-őt, vagy 3-at adtál meg\n";
            exit(0);   // kilép a programból
    }

    return 0;
}
```

#### getline + if / else if megoldás

```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string lehetoseg;

    cout << "Add meg az 1, 2, vagy a 3. lehetőséget: ";
    getline(cin, lehetoseg);

    if(lehetoseg == "1")
    {
        cout << "Első lehetőség\n";
    }
    else if(lehetoseg == "2")
    {
        cout << "Második lehetőség\n";
    }
    else if(lehetoseg == "3")
    {
        cout << "Harmadik lehetőség\n";
    }
    else
    {
        cout << "Hibás választás!\n";
        return 0;  // kulturált kilépés
    }

    return 0;
}
```

#### vagy

```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    int lehetoseg;

    cout << "Add meg az 1, 2 vagy 3 lehetőséget: ";
    getline(cin, input);

    try {
        lehetoseg = stoi(input);   // string → int konvertálás
    }
    catch(...) {
        cout << "Hibás bevitel!\n";
        return 0;
    }

    switch(lehetoseg)
    {
        case 1:
            cout << "Első lehetőség\n";
            break;
        case 2:
            cout << "Második lehetőség\n";
            break;
        case 3:
            cout << "Harmadik lehetőség\n";
            break;
        default:
            cout << "Nem 1, 2 vagy 3!\n";
    }

    return 0;
}
```

char használata

```
#include <iostream>
using namespace std;

int main()
{
    char valasz;

    cout << "Add meg az 1, 2 vagy 3 lehetőséget: ";
    cin >> valasz;

    switch(valasz)
    {
        case '1':
            cout << "Első lehetőség\n";
            break;
        case '2':
            cout << "Második lehetőség\n";
            break;
        case '3':
            cout << "Harmadik lehetőség\n";
            break;
        default:
            cout << "Hibás választás!\n";
    }

    return 0;
}
```

vagy

```
char valasz;

do {
    cout << "1, 2 vagy 3: ";
    cin >> valasz;
} while(valasz != '1' && valasz != '2' && valasz != '3');

switch(valasz)
{
    case '1': cout << "Első\n"; break;
    case '2': cout << "Második\n"; break;
    case '3': cout << "Harmadik\n"; break;
}
```

#### c-ben

```
#include <stdio.h>

int main() {
    int lehetoseg;

    printf("Add meg az 1, 2 vagy 3 lehetoseget: ");
    scanf("%d", &lehetoseg);

    switch(lehetoseg) {
        case 1:
            printf("Elso lehetoseg\n");
            break;

        case 2:
            printf("Masodik lehetoseg\n");
            break;

        case 3:
            printf("Harmadik lehetoseg\n");
            break;

        default:
            printf("Hibas adat!\n");
    }

    return 0;
}
```

vagy

```
#include <stdio.h>

int main() {
    int lehetoseg;

    while(1) {  // végtelen ciklus, amíg jó input nem jön
        printf("Add meg az 1, 2 vagy 3 lehetoseget: ");
        if(scanf("%d", &lehetoseg) != 1) {
            // Hibás input (pl. betű)
            printf("Hibás bevitel! Csak számot adj meg.\n");
            while(getchar() != '\n'); // buffer törlése
            continue;  // vissza a ciklus elejére
        }

        // if-else a választásra
        if(lehetoseg == 1) {
            printf("Első lehetőség\n");
            break;  // kilépünk a ciklusból
        } else if(lehetoseg == 2) {
            printf("Második lehetőség\n");
            break;
        } else if(lehetoseg == 3) {
            printf("Harmadik lehetőség\n");
            break;
        } else {
            printf("Hibás választás! Csak 1, 2 vagy 3 lehetőség.\n");
        }
    }

    return 0;
}
```

#### kotlin

```
fun main() {
    while(true) {
        print("Add meg az 1, 2 vagy 3 lehetőséget: ")
        val input = readLine()

        val lehetoseg = input?.toIntOrNull()  // szám konvertálása, ha nem szám → null

        if(lehetoseg == null) {
            println("Hibás bevitel! Csak számot adj meg.")
            continue
        }

        if(lehetoseg == 1) {
            println("Első lehetőség")
            break
        } else if(lehetoseg == 2) {
            println("Második lehetőség")
            break
        } else if(lehetoseg == 3) {
            println("Harmadik lehetőség")
            break
        } else {
            println("Hibás választás! Csak 1, 2 vagy 3 lehetőség.")
        }
    }
}
```

vagy

```
fun main() {
    print("Add meg az 1, 2 vagy 3 lehetőséget: ")
    val input = readLine()

    val lehetoseg = input?.toIntOrNull()

    if(lehetoseg == null) {
        println("Hibás bevitel! Csak számot adj meg.")
        return
    }

    when(lehetoseg) {
        1 -> println("Első lehetőség")
        2 -> println("Második lehetőség")
        3 -> println("Harmadik lehetőség")
        else -> println("Hibás választás! Csak 1, 2 vagy 3 lehetőség.")
    }
}
```

#### python

```
while True:
    input_str = input("Add meg az 1, 2 vagy 3 lehetőséget: ")

    if not input_str.isdigit():
        print("Hibás bevitel! Csak számot adj meg.")
        continue

    lehetoseg = int(input_str)

    if lehetoseg == 1:
        print("Első lehetőség")
        break
    elif lehetoseg == 2:
        print("Második lehetőség")
        break
    elif lehetoseg == 3:
        print("Harmadik lehetőség")
        break
    else:
        print("Hibás választás! Csak 1, 2 vagy 3 lehetőség.")
```

vagy

```
input_str = input("Add meg az 1, 2 vagy 3 lehetőséget: ")

if not input_str.isdigit():
    print("Hibás bevitel! Csak számot adj meg.")
    exit()

lehetoseg = int(input_str)

match lehetoseg:
    case 1:
        print("Első lehetőség")
    case 2:
        print("Második lehetőség")
    case 3:
        print("Harmadik lehetőség")
    case _:
        print("Hibás választás! Csak 1, 2 vagy 3 lehetőség.")
```

#### Java

```
import java.util.Scanner;

public class Valasztas {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int lehetoseg;

        while(true) {
            System.out.print("Add meg az 1, 2 vagy 3 lehetőséget: ");

            if(!sc.hasNextInt()) { // ellenőrzi, hogy szám-e
                System.out.println("Hibás bevitel! Csak számot adj meg.");
                sc.next(); // hibás input eltávolítása
                continue;
            }

            lehetoseg = sc.nextInt();

            if(lehetoseg == 1) {
                System.out.println("Első lehetőség");
                break;
            } else if(lehetoseg == 2) {
                System.out.println("Második lehetőség");
                break;
            } else if(lehetoseg == 3) {
                System.out.println("Harmadik lehetőség");
                break;
            } else {
                System.out.println("Hibás választás! Csak 1, 2 vagy 3 lehetőség.");
            }
        }

        sc.close();
    }
}
```

vagy

```
import java.util.Scanner;

public class SwitchExample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Add meg az 1, 2 vagy 3 lehetőséget: ");

        if(!sc.hasNextInt()) {
            System.out.println("Hibás bevitel! Csak számot adj meg.");
            sc.close();
            return;
        }

        int lehetoseg = sc.nextInt();

        switch(lehetoseg) {
            case 1:
                System.out.println("Első lehetőség");
                break;
            case 2:
                System.out.println("Második lehetőség");
                break;
            case 3:
                System.out.println("Harmadik lehetőség");
                break;
            default:
                System.out.println("Hibás választás! Csak 1, 2 vagy 3 lehetőség.");
        }

        sc.close();
    }
}
```

------

## Hogyan működik a switch a háttérben

Amikor C vagy C++ lefordítja a `switch`-et:

```c
switch(x) {
    case 1: ... break;
    case 2: ... break;
    case 3: ... break;
    default: ... break;
}
```

- A fordító **ugró táblát (jump table) készít** a `case` értékekből.
- Ez egy **memóriacímtábla**, ami megmondja, hogy **x = 2 esetén hova ugorjon** a kódban.
- Így **egyetlen memóriaolvasás és ugrás** elég a megfelelő ágra jutáshoz.

------

##  Hogyan működik az if-else

```c
if(x == 1) ...
else if(x == 2) ...
else if(x == 3) ...
else ...
```

- A program **egymás után végignézi a feltételeket**.
- Ha x = 3, előbb megnézi x == 1 (nem), x == 2 (nem), majd x == 3 (igen).
- Tehát **többszörös összehasonlítás** történik.
- Nagyon sok `case` esetén az if-else **lassabb**, mert lineárisan ellenőrzi mindet.

------

##  Mikor jelent ez különbséget?

- **Kevés case** → szinte ugyanaz a sebesség
- **Sok case (10+, 50+, 100)** → switch lehet **többször gyorsabb**, mert a jump table O(1), míg if-else O(n)

------

## Limitációk

- Switch csak **konstans, integrál típusú case-ekhez**
- Nem működik stringre vagy lebegőpontos számra
- Ha a case-ek “szakadnak” (pl. 1, 100, 1000), akkor a fordító gyakran **if-else láncot csinál** (ugró táblát nem lehet sűrűen építeni)

------

###  Összefoglalva

| Feature      | switch                 | if-else              |
| ------------ | ---------------------- | -------------------- |
| Futási idő   | O(1) jump table esetén | O(n)                 |
| Típus        | int, char, enum        | bármi, string is     |
| Olvashatóság | több case → tiszta     | sok if → hosszú      |
| Használat    | sok konstans esetén    | feltételes logikához |

------

