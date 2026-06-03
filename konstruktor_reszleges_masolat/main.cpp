//Részleges Másolat
//Bájtonként részleges másolatot készít
//helytelen ha az osztály erőforrásokat tartalmaz

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Szemely
{
public:
    Szemely(const char *mN)
    {
        std::cout <<"Felépítés: " <<mN <<'\n';
        mNev= new std::string(mN);
    }
    //desktruktor
    ~Szemely()
    {
        std::cout<<"Megsemmisítés: " << mNev
        << " (" << *mNev << ")" <<'\n';
        *mNev = "Már megsemisített memória";
        //összeomlik ha törlünk memóriát
        //mert mind a 2 egy memóriacímre mutat
        //delete mNev;
    }
protected:
    std::string *mNev;
};
void fv()
{
    //létrehozunk egy uj objektumot
    Szemely sz1("LONG_NAME");
    //átmásoljuk a tartalmát az sz2-be
    Szemely sz2(sz1);
}
int main(int argc, char** argv)
{
    std::cout<<"Az fv() meghívása" <<'\n';
    fv();
    std::cout<<"vége újra a main függvényben"<<'\n';
    //kilépünk
    std::cout <<"A Kilépéshez kérlek nyomd meg kétszer az entert" << std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();

    return 0;
}
