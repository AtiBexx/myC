## VáltozóMéretek kiírása

```
#include <cstdio>
#include <cstdlib>
#include <iostream>

int main (int argc, char *argv[]) {

    bool b;
    char c;
    short s;
    int i;
    long l;
    long long ll;
    float f;
    double d;
    long double ld;

    //Kiírjuk a változók méretét bájtban
    std::cout << "a bool mérete: " << sizeof(b) << " byte\n";
    std::cout << "a char mérete: " << sizeof(c) << " byte\n";
    std::cout << "a short mérete: " << sizeof(s) << " byte\n";
    std::cout << "az int mérete: " << sizeof(i) << " byte\n";
    std::cout << "a long mérete: " << sizeof(l) << " byte\n";
    std::cout << "a long long mérete: " << sizeof(ll) << " byte\n";
    std::cout << "a float mérete: " << sizeof(f) << " byte\n";
    std::cout << "a double mérete: " << sizeof(d) << " byte\n";
    std::cout << "a long double mérete: " << sizeof(ld) << " byte\n";

    //kilépünk
    std::cout<<"A folytatáshoz kérlek nyomd meg az ENTER-t\n" << std::flush;
    std::cin.get();
    return 0;
}
```

vagy bit-ben

```
#include <cstdio>
#include <cstdlib>
#include <iostream>

int main (int argc, char *argv[]) {

    bool b;
    char c;
    short s;
    int i;
    long l;
    long long ll;
    float f;
    double d;
    long double ld;

    //Kiírjuk a változók méretét bájtban
    std::cout << "a bool mérete: " << sizeof(b) * 8<< " bit\n";
    std::cout << "a char mérete: " << sizeof(c) * 8 << " bit\n";
    std::cout << "a short mérete: " << sizeof(s)* 8 << " bit\n";
    std::cout << "az int mérete: " << sizeof(i) * 8 << " bit\n";
    std::cout << "a long mérete: " << sizeof(l) * 8 << " bit\n";
    std::cout << "a long long mérete: " << sizeof(ll) * 8 << " bit\n";
    std::cout << "a float mérete: " << sizeof(f) * 8 << " bit\n";
    std::cout << "a double mérete: " << sizeof(d) * 8 << " bit\n";
    std::cout << "a long double mérete: " << sizeof(ld) * 8 << " bit\n";

    //kilépünk
    std::cout<<"A folytatáshoz kérlek nyomd meg az ENTER-t\n" << std::flush;
    std::cin.get();
    return 0;
}
```

vagy simán expliciten :

```
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>

int main (int argc, char *argv[]) {


    //Kiírjuk a változók méretét bájtban
    std::cout << "a bool mérete: " << sizeof(bool) * CHAR_BIT << " bit\n";
    std::cout << "a char mérete: " << sizeof(char) * CHAR_BIT << " bit\n";
    std::cout << "a short mérete: " << sizeof(short) * CHAR_BIT << " bit\n";
    std::cout << "az int mérete: " << sizeof(int) * CHAR_BIT << " bit\n";
    std::cout << "a long mérete: " << sizeof(long) * CHAR_BIT << " bit\n";
    std::cout << "a long long mérete: " << sizeof(long long) * CHAR_BIT << " bit\n";
    std::cout << "a float mérete: " << sizeof(float) * CHAR_BIT << " bit\n";
    std::cout << "a double mérete: " << sizeof(double) * CHAR_BIT << " bit\n";
    std::cout << "a long double mérete: " << sizeof(long double) * CHAR_BIT << " bit\n";

    //kilépünk
    std::cout<<"A folytatáshoz kérlek nyomd meg az ENTER-t\n" << std::flush;
    std::cin.get();
    return 0;
}
```

```
#include <iostream>
#include <climits>

int main() {
    std::cout << "char: " << sizeof(char) << " byte, " 
              << sizeof(char) * CHAR_BIT << " bit\n";
    std::cout << "int: " << sizeof(int) << " byte, " 
              << sizeof(int) * CHAR_BIT << " bit\n";
    std::cout << "long double: " << sizeof(long double) 
              << " byte, " << sizeof(long double) * CHAR_BIT << " bit\n";
} //és így tovább akkor akimenet byte és bit lesz :) 
```

```
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>

int main (int argc, char *argv[]) {


    //Kiírjuk a változók méretét bájtban
    std::cout << "a bool mérete byte-ban: " << sizeof(bool) << " byte\n";
    std::cout << "a bool mérete bit-ben: " << sizeof(bool) * CHAR_BIT << " bit\n";
    std::cout << "a char mérete: " << sizeof(char) << " byte\n";
    std::cout << "a char mérete: " << sizeof(char) * CHAR_BIT << " bit\n";
    std::cout << "a short mérete: " << sizeof(short) << " byte\n";
    std::cout << "a short mérete: " << sizeof(short) * CHAR_BIT << " bit\n";
    std::cout << "az int mérete: " << sizeof(int) << " byte\n";
    std::cout << "az int mérete: " << sizeof(int) * CHAR_BIT << " bit\n";
    std::cout << "a long mérete: " << sizeof(long) << " byte\n";
    std::cout << "a long mérete: " << sizeof(long) * CHAR_BIT << " bit\n";
    std::cout << "a long long mérete: " << sizeof(long long) << " byte\n";
    std::cout << "a long long mérete: " << sizeof(long long) * CHAR_BIT << " bit\n";
    std::cout << "a float mérete: " << sizeof(float) << " byte\n";
    std::cout << "a float mérete: " << sizeof(float) * CHAR_BIT << " bit\n";
    std::cout << "a double mérete: " << sizeof(double) << " byte\n";
    std::cout << "a double mérete: " << sizeof(double) * CHAR_BIT << " bit\n";
    std::cout << "a long double mérete: " << sizeof(long double) << " byte\n";
    std::cout << "a long double mérete: " << sizeof(long double) * CHAR_BIT << " bit\n";

    //kilépünk
    std::cout<<"A folytatáshoz kérlek nyomd meg az ENTER-t\n" << std::flush;
    std::cin.get();
    return 0;
}
```

