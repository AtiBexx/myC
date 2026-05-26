// ObjektumHivÁtadás azaz egy objektum tartalmának módosítása
// egy függvényben, egy hivatkozás használatával....
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
public:
    int feleviOraSzam = 0;
    double tanulmanyiAtlag = 0.0;
};

//Hivatkozas
void egyFv(Hallgato& hivH)
{
    hivH.feleviOraSzam = 10;
    hivH.tanulmanyiAtlag = 3,0;

}

int main(int argc, char** argv)
{
    Hallgato h;
    h.tanulmanyiAtlag = 0.0;

    std::cout <<"A h.tanulmanyiAtlag értéke: " << h.tanulmanyiAtlag <<"\n";
    //átadjuk a meglévő objektum címét
    std::cout <<"Az egyFv(Hallgato*) meghívása" <<'\n';
    egyFv(h);
    std::cout <<"Visszatérés az egyFv(Hallgato*)  függvényből" <<"\n";
    // a h.tanulmanyiAtlag értéke most 3.0
    std::cout << "A h.tanulmanyiAtlag értéke = " << h.tanulmanyiAtlag << std::endl;

    //kilépünk
     std::cout << "A folytatáshoz kérlek nyomd meg az Entert..." << std::endl;
     std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
     std::cin.get();
     return 0;
}

