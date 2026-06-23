// Többszörös_öröklődés
// egy osztály több alaposztálytól is örökölhet
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Agy
{
public:
    Agy() {}
    void alvas()
    {
        std::cout << "Alvás" << '\n';
    }
    int suly;
};
class Kanape
{
public:
    Kanape() {}
    void TVnezes()
    {
        std::cout << "TV_Nézés" << '\n';
    }
    int suly;
};

//Kihuzhato kanapé ágy is egyben
class KihuzhatoKanape : public Agy, public Kanape
{
public:
    KihuzhatoKanape(){}
    void kihuzas()
    {
        std::cout << "Kihúzás" << '\n';
    }
};

int main(int argc, char** argv)
{
    KihuzhatoKanape kk;

    //tv nezes
    kk.TVnezes();
    //kihuzas
    kk.kihuzas();
    //alvás
    kk.alvas();

    std::cout <<'\n' <<'\n';
    std::cout << "on Heap" <<'\n';

    KihuzhatoKanape * k2 = new KihuzhatoKanape();
    k2->TVnezes();
    k2->alvas();
    k2->kihuzas();

    delete k2;
    k2 = nullptr;

    std::cout <<"A kilépéshez kérlek nyomd meg 2-szer az entert" << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return 0;
}
