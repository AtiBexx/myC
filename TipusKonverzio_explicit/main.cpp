//TypeConversion
//Szemlélteti az egyik típusról a másikra való
//történő implicit konverzióját
//C++ 2011 -es szabványtól
//használható az explicit kulcsszó ....

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Komplex
{
public:
    Komplex() : dValos(0.0), dImag(0.0)
    {
        std::cout <<"Az alapértelmezet konstruktor meghívása" <<'\n';
    }
    explicit Komplex(double _dValos) : dValos(_dValos),dImag(0.0)
    {
        std::cout <<"A valós konstruktor meghívása.... : "
        << dValos <<'\n';
    }
    Komplex(double _dValos, double _dImag): dValos(_dValos),
    dImag(_dImag)
    {
        std::cout <<"A komplex komnstruktor meghívása: "
        << ", "<< dImag <<'\n';
    }
    ~Komplex(){std::cout<<"Komplex megsemmisítése"<<'\n';}
protected:
    double dValos;
    double dImag;
};

int main(int argc, char** argv)
{
    Komplex k1, k2(1.0), k3(1.0, 1.0);

    k1 = Komplex(10.0);

    //A következő Objektumok vagy konverziók
    //akkor is müködnek ha az explicit nincs kikommentelve
    //itt azonal lefut a destruktor
    k1=(Komplex)20.0;
    k1= static_cast<Komplex>(30.0);

    //Implicit verziók
    //Ezek csak akkor müködnek ha az explicit ki van kommentelve
    /*k1=40.0;
    k1=50;*/
    std::cout<<"Heap verzió:"<<'\n';
    Komplex* k = new Komplex(100, 50);


    //kilépünk
    std::cout<<"A folytatáshoz kérlek kétszer nyomd meg az enter...." <<std::endl;
    //puffer delete bár itt nem kell de berakjuk a tanulás miatt
    //std::cin.ignore(1000, '\n');
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();//várunk az enterre(azaz egy bilentyűre)

    delete k;

    return EXIT_SUCCESS;
}
