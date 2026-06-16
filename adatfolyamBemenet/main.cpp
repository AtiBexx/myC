#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <ostream>
#include <limits>
#include <string>

//std::ifstream &fajlMegnyitas()
  std::ifstream *fajlMegnyitas()
{
    //std::ifstream* mFajlAdatFolyam = 0;
    std::ifstream* mFajlAdatFolyam = nullptr;
    for(;;)
    {
        //megnyitjuk a fájl
        std::string sFajlNev;
        std::cout<<"Add meg az egész számokat tartalmazó fájl nevét: ";
        std::cin >> sFajlNev;

        //megnyitjuk a fájlt az olvasásra
        mFajlAdatFolyam = new std::ifstream(sFajlNev.c_str());

        if(mFajlAdatFolyam->good())
        {
            mFajlAdatFolyam->seekg(0);
            std:: cerr << sFajlNev <<" sikeresen megnyitva" << std::endl;
            break;
        }
        std::cerr << sFajlNev << " megnyitása nem sikerült..."<< std::endl;
        delete mFajlAdatFolyam;
        mFajlAdatFolyam = nullptr;
    }
    return mFajlAdatFolyam;
}
int main(int argc, char** argv)
{
    //Beolvasunk egy fájlAdatFolyamot
    //std::ifstream& fajlAdatFolyam = fajlMegnyitas();
     std::ifstream *fajlAdatFolyam = fajlMegnyitas();
    // amikor a fájlban már nincs több adat megállunk
    //while(!fajlAdatFolyam.eof())
     while( !fajlAdatFolyam->eof())
    {
        //Beolvassuk az értéket
        int nErtek = 0;
        *fajlAdatFolyam >> nErtek;

        //ha az olvasás nem sikerült megállunk
        //ha az adat nem int nem olvassuk
        //if(fajlAdatFolyam.fail())
        if(fajlAdatFolyam->fail())
        {
            break;
        }
        // kiírjuk a beolvasot értékeket
        std::cout << nErtek <<std::endl;
    }
    std::cout << "A FOLYTATÁSHOZ KÉRLEK NYOMD MEG AZ ENTERT..." << std::endl;
    delete fajlAdatFolyam;

    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}
