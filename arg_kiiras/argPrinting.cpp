#include<cstdlib>
#include<cstdio>
#include<iostream>

int main(int argc, char* argv[])
{
    std::cout <<"Az argv[] argumentumai a következők: "<< std::endl;
    //std::cout <<"Az argv[] argumentumai a következők: "<< argv[0] << std::endl;
    //kiírjuk az argumentumokat
    for (int i = 0; i < argc; i++)
    {
        std::cout <<"\nAz Argumentumok = [" << i <<"] : " << argv[i] ;
    }
    
  /*  for (int i = 0; i < argc; i++)
{
    std::cout << "\nAz Argumentumok = [" << i << "] : " << *(argv + i);
} */
    std::cout <<"\n\nEnnyi argumentum van(Az argumentumok száma): "<< argc << std::endl;
    
    //kilépünk
    std::cout << "\nA program kilep." << std::endl;
    std::cout <<"A folytatáshoz kérlek nyomd meg az ENTERT." << std::endl;
    std:: cin.get();
    return 0;
}