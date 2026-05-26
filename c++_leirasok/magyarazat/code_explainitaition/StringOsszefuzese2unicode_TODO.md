```
#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include <iostream>

int main (int argc, char* agrv[]) {

    wchar_t String1 [260];
    wchar_t String2 [260];

    std:: cout <<"Kérlek add meg az első szöveget az első stringhez: ";
    std:: wcin.getline (String1, 260);

    std:: cout <<"Kérlek add meg az második szöveget az második stringhez: ";
    std::wcin.getline (String2, 260);
    

    //most füzzük össze a 2-öt
    std:: wcsncat (String1, L" - ", 260);
    std:: wcsncat (String1, String2, 260);

    //most írjuk ki
    std:: wcout <<String1 <<std::endl;

    //kilépünk
    std::cout <<"Kérlek add meg az entert a kilépéshez...." <<std::endl;
    std::cin.get(); 
    return 0;
}
```

**meg tudtad volna csinálni `wcscat`-tel is**, csak ott még jobban kell figyelni a buffer méretre.

------

#  `wcscat` vs `wcsncat`

###  `wcscat`

- Mindent hozzáfűz a végéhez
- **NEM kér hossz paramétert**
- Veszélyesebb, ha nincs elég hely a tömbben

```cpp
wcscat(String1, L" - ");
wcscat(String1, String2);
```

Ez működik, **ha biztos vagy benne**, hogy:

```
wcslen(String1) + wcslen(L" - ") + wcslen(String2) < 260
```

Ha nem fér bele → buffer overflow 💥

------

###  `wcsncat`

- Megmondod, maximum hány karaktert fűzzön hozzá
- Biztonságosabb

------

#  Példa wcscat-tel

```cpp
wcscat(String1, L" - ");
wcscat(String1, String2);
```

------

#  Profi gondolkodás

Ha biztosra akarsz menni:

```
maxMéret = 259
maradék = maxMéret - wcslen(String1)
```

Ezért szoktuk inkább `wcsncat`-et használni.

------

#  Modern C++ verzió (nagyon egyszerű)

Ha `std::wstring`-et használsz:

```cpp
std::wstring s1, s2;
std::getline(std::wcin, s1);
std::getline(std::wcin, s2);

s1 += L" - ";
s1 += s2;

std::wcout << s1;
```

Semmi buffer, semmi overflow, semmi számolgatás

------

