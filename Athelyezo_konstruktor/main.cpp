// C++ 2011 től kezdve a programozó
//létrehozhat egy "ÁTHELYEZŐ"
//erőforrásokat áthelyező konstruktort
//amely az erőforrásokat 'NEM MÁSOLJA'
//hanem a célforráshoz helyezi át.
//formátuma : X::X(X&&)
//pl: Tanulo(Tanulo &&t);
// -----példa program------
//
//========ÁTHEYLEZŐ KONSTRUKTOR=======
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Szemely
{
public:
    Szemely(const char *mN)
    {
        mNev = new std::string(mN);
        std::cout <<*mNev <<" felépítése" <<'\n';
    }
    //másolunk
    Szemely(const Szemely &sz)
    {
        std::cout <<*sz.mNev <<" másolása" <<'\n';
        mNev = new std::string(" másolata");
        *mNev += *sz.mNev;
    }
    //Áthelyező konstruktor
    Szemely(Szemely &&sz)
    {
        std::cout <<*sz.mNev <<" áthelyezése" <<'\n';
        mNev = sz.mNev;
        sz.mNev = nullptr;
    }
    //Destruktor
    ~Szemely()
    {
        if(mNev)
        {
            std::cout<< *mNev <<" megsemmisítése" <<'\n';
            delete mNev;
        }
        else
        {
            std::cout <<" Null értékű objektum megsemmisítése" << '\n';
        }
    }

protected:
    std::string* mNev;
};
//függvényeink
Szemely fv2(Szemely sz)
{
    std::cout << " Belépés az fv2-be"<<'\n';
    return sz;
}
Szemely fv1(const char* mNev)
{
    std::cout <<" Belépés az fv1-be" <<'\n';
                Szemely temp(mNev);
                return fv2(temp);

                //Itt memóriaSzivárgás történik.
              //return fv2(*new Szemely(mNev));
}

int main(int argc, char** argv)
{
    //stack
    Szemely t(fv1("Anonime"));
    //heap
    Szemely *SzT = new Szemely(fv1("Anonimus"));

    delete SzT;
    //kilépünk
    std::cout <<"A kilépéshez kérlek nyomd meg kétszer az entert...."<<std::endl;

    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
                    std::cin.get();

                    return 0;
}

