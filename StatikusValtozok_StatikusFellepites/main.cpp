/*
A statikus változók olyan változók
amely egy függvény változói
de megőrzik az értéküket a függvény hívásai között.

A globális változók a függvényem kívül deklarált változók.
*/
//------------------------------------------------------
/*
A statikus Objektumok hasonlóak a helyi változókhoz
azt leszámítva hogy,, csak egyetlen egyszer épülnek fel.
*/
//======================================
// StatikusFelépítése
// Szemlélteti hogy a statikus objektum csak egyszer épül fel
//======================================
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class NemCsinalSemmit
{
public:
    NemCsinalSemmit(int kezdeti):nErtek(kezdeti)
    {
        std::cout <<"Nem csinálunk semmit érték(Stacken csak egyszer fut le):"<< kezdeti <<'\n';
    }
    //Destruktor ~ megsemmísítés
    ~NemCsinalSemmit()
    {
        std::cout <<"A Konstruktor megsemmisítése" <<'\n';
    }
protected:
    int nErtek;
};
void fv(int i)
{
    std::cout <<"Az fv() Függvénynek átadott érték: " << i <<'\n';
    static NemCsinalSemmit fv (i);
}

int main(int argc,char** argv)
{
    //stack
    fv(10);
    fv(20);
    fv(40);
    fv(50);
    std::cout<<'\n';
    std::cout <<"Heap->"<<'\n';
    //Heap *
    NemCsinalSemmit* fv1 = new NemCsinalSemmit(40);
    NemCsinalSemmit* fv2 = new NemCsinalSemmit(50);

    delete fv1;
    delete fv2;

    //kilépünk
    std::cout <<"Kérlek a folytatáshoz nyomd meg kétszer az ENTERT...."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return EXIT_SUCCESS;
}
