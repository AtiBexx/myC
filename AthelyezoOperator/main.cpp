//Áthelyező operátor
//-PÉLDAPROGRAM
//Szemlélteti az áthelyező Operátort
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cstring>


class EnTarolom
{
public:
EnTarolom(int nS, const char* pS) : nMeret(nS)
{
    mSztring = new char[nMeret];
    //strcpy(cel, forras); azaz Másol
    strcpy(mSztring, pS);
}
//Desktruktor
~EnTarolom()
{
    delete[] mSztring;
    mSztring = nullptr;
}
//Másoló konstruktor
EnTarolom(const EnTarolom &s)
{
    masolas(*this, s);
}
EnTarolom& operator=(EnTarolom& s)
{
    //önEllenőrzés
    if(this==&s) return *this;

    delete[] mSztring;
    masolas(*this, s);

    return *this;
}
//áthelyező konstruktor
EnTarolom(EnTarolom&& s)
{
    athelyezes(*this, s);
}
EnTarolom& operator=(EnTarolom&& s)
{
    //önEllenőrzés
    if(this==&s) return *this;

    delete[] mSztring;
    athelyezes(*this, s);

    return *this;
}

protected:
    static void athelyezes(EnTarolom& cel, EnTarolom& forras)
    {
        std::cout<< forras.mSztring << " áthelyezése: " << '\n';
        cel.nMeret = forras.nMeret;
        cel.mSztring = forras.mSztring;

        forras.nMeret = 0;
        forras.mSztring = nullptr;
    }
    static void masolas(EnTarolom& cel,const EnTarolom& forras)
    {
        std::cout<< forras.mSztring << " másolása: " << '\n';
        delete[] cel.mSztring;
        cel.nMeret = forras.nMeret;
        cel.mSztring = forras.mSztring;

        cel.mSztring = new char[cel.nMeret];
        strncpy(cel.mSztring, forras.mSztring, cel.nMeret);
    }
    int nMeret;
    char* mSztring;
};
EnTarolom fv(int n, const char* mSztring)
{
    EnTarolom b(n, mSztring);
    return b;
}
int main(int argc, char** argv)
{
    //stack
    EnTarolom et(100, "Eredeti");
    et = fv(100, "Létrehozva az fv()-ben");
    //kilépünk
    std::cout<<"A folytatáshoz kérlek nyomd meg az ENTERT...... Kétszer"<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();
    return 0;
}
