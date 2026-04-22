#include <iostream>
#include <cstdlib>
#include <cstdio>

void info() {
    std::cout << "----- Fordítási információk -----" << std:: endl;
    std:: cout << "Fájl:     " << __FILE__ << std::endl;
    std::cout << "Sor:   " << __LINE__ << std::endl;
    std::cout << "Dátum:     " << __DATE__ << std::endl;
    std::cout << "Időpont:   " << __TIME__ << std::endl;
    std::cout << "Verzió:    " << __VERSION__ << std::endl;
    std::cout << "Függvény:     " << __func__ << std::endl;
    std::cout << "C++ verzió:    " << __cplusplus << std::endl;
}
//Prototypedeclaration
void info();

int main(int argc, char* argv[]) {
    info();
    std::cout << "----- Mainszöveg -----\n" << std::endl;
    std:: cout << "Most a  " << __FILE__ << "   -fájl sorban vagyunk." << std::endl;
    std:: cout << "Most a " << __LINE__ << "   -'LINE' sorban vagyunk." << std::endl;
    std:: cout << "Most a " << __DATE__ << "   -DÁTUM sorban vagyunk." << std::endl;
    std:: cout << "Most az " << __TIME__ << "  -IDŐsorban vagyunk." << std::endl;
    std:: cout << "Most a " << __VERSION__ << "   -verzió sorban vagyunk." << std::endl;
    std:: cout << "Most a " << __func__ << "   -függvény sorban vagyunk." << std::endl;
    std:: cout << "Most a " << __cplusplus << "   -C++ verzió sorban vagyunk." << std::endl;

    std::cout <<"A folytatáshoz kérlek nyomd meg az enter-t! " << std::endl;
    std::cin.get();

    return EXIT_SUCCESS;
}