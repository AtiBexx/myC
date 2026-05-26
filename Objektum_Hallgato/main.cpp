// ObjektumMutató
//ObjMut - definiáljuk és használjuk a hallgató objektum mutatóját

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>

class Hallgato
{
public:
    int felevioraszam;
    double tanulmanyAtlag;

    double kurzusHozzaAdasa(int oraSzam, double osztalyzat);
};

int main(int argc, char** argv)
{
    //létrehozuk a hallgató objektumot
    Hallgato h;
    //beállítjuk a tanulmanyi átlagot
    h.tanulmanyAtlag = 3.0;
    //most létrehozzuk a mutatót ami a hallgató objektumra mutat
    Hallgato* mH;
    //Beállítjuk az Mh hogy a mi Hallgató objektumunkra mutasson
    //azaz átadjuk neki a mi h (hallgato) értékünket
    // pontosan átadjuk neki a h objektum memóriacímét ezáltal az értéket is.
    //ilyenkor nem adatot másolunk hanem a memóriacímünkre hivatkozunk
    mH = &h;

    // Most kiírjuk az értékeket
    std::cout <<"h.tanulmanyiAtlag: " <<h.tanulmanyAtlag <<"\n\n";

    // most kiírjuk mutatóval
    std::cout <<"mH* azaz mH->tanulmanyiAtlag: " <<mH->tanulmanyAtlag <<"\n\n";
    std::cout <<"Most létrehozzuk nem stacken hanem heapen ugyanezt"<<"\n";
    Hallgato* hH = new Hallgato;
    hH->tanulmanyAtlag = 3.3;

    std::cout <<"Heapen a tanulmányi átlag: "<< hH->tanulmanyAtlag <<"\n";
    delete hH;
    std::cout <<"És a végén töröljük delete hH;" << "\n\n";

    std::cout<<"Most pedig kiírjuk smart pointerel itt nem kell a new delete\n";
    auto hh = std::make_unique<Hallgato>();
    hh->tanulmanyAtlag = 3.4;
    std::cout<<"Smart pointerrel: " << hh->tanulmanyAtlag <<"\n";

    //kilépünk
    std::cout << "A folytatáshoz kérlek nyomd meg az Enter bilenytüt 2-szer..." << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}
