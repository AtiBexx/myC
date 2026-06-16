// FájlMásolás
//Biztonsági másolatot készít egy fájlról
//
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <string>
#include <iostream>
int main(int argc, char** argv)
{
//minden átadot fájlnál megismételjük a folyamatot
    for (int n = 1; n < argc; n++)
    {
        // létrehozunk egy fájlnevet és egy biztonsági nevet
        std::string szForras(argv[n]);
        std::string szCel = szForras + ".bMasolat";
        //most megnyitjuk a fájlt olvasásra a célt pedig írásra
        std::ifstream bemenet(szForras.c_str(),
                              std::ios_base::in|std::ios_base::binary);
        std::ofstream kimenet(szCel.c_str(),
                              std::ios_base::out|std::ios_base::binary|std::ios_base::trunc);
        if(bemenet.good() && kimenet.good())
        {
            std::cout << szForras << "Biztonsági Mentése..." <<"...";
            //addig olvassuk be a 4 kb blokokat amíg el nem érjük a fájl végét EOF
            while(!bemenet.eof() && bemenet.good())
            {
                char puffer[4096];
                bemenet.read(puffer, 4096);
                kimenet.write(puffer,bemenet.gcount());
            }
            std::cout <<"kész"<<std::endl;

        }
        else
        {
            std::cerr <<szForras<< " "<<"másolása nem sikerült...." <<std::endl;
        }
    }
    //kilépünk
    std::cout <<"A Folytatáshoz nyomd meg az ENTER kétszer...." <<std::flush<<'\n';
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();


    return 0;
}
