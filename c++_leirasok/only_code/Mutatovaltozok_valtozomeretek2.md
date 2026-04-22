```
#include <cstdio>
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[]) {
    int kezdet;
    int n;
    long l;
    long long ll;
    float f;
    double d;
    char c;
    bool b;
    long double ld;

    //a kimenetet Hexadecimális módra állítjuk
    std::cout.setf(std::ios::hex);
    std::cout.unsetf(std::ios::dec);

    std::cout << "---" << &kezdet << std::endl;
    std::cout << "int memóriacíme: " << &n << std::endl;
    std::cout << "long memóriacíme: " << &l << std::endl;
    std::cout << "long long memóriacíme: " << &ll << std::endl;
    std::cout << "float memóriacíme: " << &f << std::endl;
    std::cout << "double memóriacíme: " << &d << std::endl;
    //Az std::cout specializálva van char* típusra,
    //  és nem címként, hanem C-stílusú nullával lezárt karakterláncként kezeli 
    // ezért megpróbálja kiírni a memóriában található karaktereket egymás után,
    //  amíg nullát nem talál.
    // static_cast<void*>(&c) -> ez kiírja a valódi memóriacímet
    std::cout << "char memóriacíme: " << static_cast<void*>(&c) << std::endl;
    std::cout << "bool memóriacíme: " << &b << std::endl;
    std::cout << "long double memóriacíme: " << &ld << std::endl;

    //kilépünk
    std::cout <<"Kérlek nyomj egy ENTERT a befejezéshez!" << std::endl;
    std::cin.get();
    return 0;
}
```

