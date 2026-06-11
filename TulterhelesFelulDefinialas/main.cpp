// TúlterhelésFelüldefiniálás
// Azt szemlélteti ,amikor egy függvény
// fordítási időben van túlterhelve
// illetve futásidőben van felülbírálva

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Hallgato
{
    public:
      // vedd ki a megjegyzésből az egyiket vagy a másikat
    // a következő két sor közül; az egyik korán köti a tandijKiszamitas()-t,
    // a másik pedig későn

    //void tandijKiszamitas() //korán kötés
    virtual void tandijKiszamitas() //késsői kötés
    {
        std:: cout << "Ez a hallgato::tandijKiszamitas" <<'\n';
    }
};
//öröklödés
class vegzosHallgato : public Hallgato
{
public:
    void tandijKiszamitas()
    {
        std::cout <<"Ez a vegzős hallgato::tandijKiszamitas" <<'\n';
    }
};
void fv(Hallgato &x)
{
    x.tandijKiszamitas(); // -> ez melyik tandijKiszamitas()?
}
//=====================
int main(int argc,char** argv)
{
    // átadunk egy alaposztályú objektumot a függvénynek
    //objektum
    //[stack]
    Hallgato h;
    fv(h);

    vegzosHallgato vh;
    fv(vh);

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg kétszer az ENTERT..."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return 0;
}
