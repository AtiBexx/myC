// Tömb létrehozzás példa
//Amely egy konstruktort hív meg
//egy objektumból álló tömbön
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
//#include <limits>

class Hallgato
{
public:
    Hallgato()
    {
        std::cout << "A Hallgato fellépítése" <<"\n";
    }
};
int main(int argc , char** argv)
{
    std::cout << "5 hallgato objektum létrehozása " <<std::endl;
    Hallgato h[5];

    //kilépünk várakozással
    //std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cout <<"A folytatáshoz kérlek nyomd meg az Entert..."<<"\n"<<std::flush;
    std::cin.get();
    return 0;
}
