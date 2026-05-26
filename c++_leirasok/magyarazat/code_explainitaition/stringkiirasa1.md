# String kiÍrása C++

```
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>

int main(int argc, char* argv[]) {

    const char*str= "egyString";
    std::cout <<"A tömb értéke a következő: " << str << std::endl;

    std::cout <<"Az str kiírása tömbként: ";
    //írjuk ki a str-t tömbként
    //for(int i= 0; i< 9[str]; i++)
    for(int i= 0; i < strlen(str); i++) {
        std::cout << str[i];
    }
    std:: cout << std::endl;

    //most írjuk ki mutatóval
    std::cout <<"Az str kiírása mutatóval: ";
    const char* pStr = str;
    while(*pStr != '\0') {
        std::cout << *pStr;
        pStr++;
    }
    std:: cout << std::endl;
    
    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg az ENTER billentyú"<< std::endl;
    //std:cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //#include<limits>
    //std::cin.ignore(10, '\n');
    std::cin.get();
    return 0;
}
```

### Mi történik, ha **nem írod oda**, hogy `!= '\0'`?(nem egyenlő 0 amíg nulla nem lesz azaz a vége)

Ha a ciklust így írod:

```
while(*pStr) {
    std::cout << *pStr;
    pStr++;
}
```

- Ez is ugyanúgy működik!
- Miért? A C/C++-ban az `*pStr` **igaz (true)**, ha nem 0, és **hamis (false)**, ha 0.
- A string vége `\0` (ami 0), így a ciklus **megáll**, amikor eléri a null karaktert.

Jó kérdés! Ha mutatóval kérsz be, **először memóriát kell foglalni** neki, különben nincs hova írni!

## A helyes módszer mutatóval:

```cpp
char* str = new char[100];  // ← először foglalj memóriát!
cin >> str;                  // ← most már van hova írni
cout << str;                 // ← kiírás
delete[] str;                // ← felszabadítás, fontos!
```

## Miért kell a `new`?

```cpp
char* str;        // ← csak egy mutató, "üres kulcs"
                  //    nem mutat sehova!

char* str = new char[100];  // ← most már "van szoba"
                             //    a mutató oda mutat
```

## Vizuálisan:

```
char* str;              str → ???  (sehova nem mutat)

char* str = new char[100];
                        str → [_][_][_][_]...[_]  (100 hely)
                               ↑
                             ide ír a cin
```

------

## Összefoglalva:

|                             | Memória van? | Biztonságos? |
| --------------------------- | ------------ | ------------ |
| `char* str`                 | ❌            | 💥 crash      |
| `char* str = new char[100]` | ✅            | ✅            |

