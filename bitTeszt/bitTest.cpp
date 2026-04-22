/*
 *BitTeszt
 *Ez a kód inicializál 2 változót ,és kiírja
 *~ , & | és a ^ müveleteket
 * George Boole igazságtáblája
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <limits>

int main(int argc, const char **argv)
{

    // a kimenet beállítása hexaDecimálisra
    // unsetf = kikakpcsolja a decimális kiírást
    // setf = bekapcsolja a hexadecimális kimenetet
    /* Régi C++ stílus
    std::cout.unsetf(std::cout.dec);
    std::cout.setf(std::cout.hex);
    */
    // ujabb stílus
    std::cout << std::dec;
    std::cout << std::hex;
    // Két argumentum iniciaéizálása
    int argc1 = 0x78ABCDEF;
    int argc2 = 0x12345678;

    // NOT operátor végrehajtása
    // Minden bitet megfordít
    // Ha 1, akkor 0, ha 0, akkor 1
    // pl 1101(13) lesz 0010  (2) decimálisan
    std::cout << " argc1 = 0x" << argc1 << std::endl;
    std::cout << "~argc1 = 0x" << ~argc1 << std::endl;
    std::cout << " argc2 = 0x" << argc2 << std::endl;
    std::cout << "~argc2 = 0x" << ~argc2 << std::endl;

    // kétoperandosú operátorok végrehajtása

    //& -AND és
    // Csak akkor 1 egy bit, ha MINDKETTŐ 1
    /*Igazságtábla:
    1 & 1 = 1
    1 & 0 = 0
    0 & 1 = 0
    0 & 0 = 0
     */
    std::cout << "0x" << argc1 << "\n"
              << "& 0x" << argc2 << "\n"
              << " ---------" << "\n"
              << "0x" << (argc1 & argc2) << "\n"
              << std::endl;

    //| -OR vagy
    // Elég ha az egyik 1
    /*Igazságtábla:
    1 | 1 = 1
    1 | 0 = 1
    0 | 1 = 1
    0 | 0 = 0
    */
    std::cout << "0x" << argc1 << "\n"
              << "| 0x" << argc2 << "\n"
              << " ---------" << "\n"
              << "0x" << (argc1 | argc2) << "\n"
              << std::endl;

    //^ — XOR (kizáró VAGY)
    // Csak akkor 1, ha KÜLÖNBÖZNEK
    // Az azonos bitek „kioltják” egymást
    /*
    Igazságtábla:
    1 ^ 1 = 0
    1 ^ 0 = 1
    0 ^ 1 = 1
    0 ^ 0 = 0
    */
    std::cout << "0x" << argc1 << "\n"
              << "^ 0x" << argc2 << "\n"
              << " ---------" << "\n"
              << "0x" << (argc1 ^ argc2) << "\n"
              << std::endl;

    std::cout << "A kilpéshez nyomd meg az Entert...." << std::endl;
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //  Mivel nem kértünk be adatot ezért semmi nem maradt a pufferben
    //  Nem kell üríteni a puffert mert akkor 2 db entert fog várni
    std::cin.get();
    return 0;
}