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