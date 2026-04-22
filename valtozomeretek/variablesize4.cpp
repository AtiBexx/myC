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