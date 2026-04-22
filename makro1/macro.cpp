#include <cstdio>
#include<cstdlib>
#include<iostream>

//Beágyazott függvény
// kommenteld ki az első makrót a második aktiválásához;

//#define SQUARE(x) x * x
//#ifndef SQUARE
//#define SQUARE(x) ((x) * (x))
#ifndef SQUARE
    inline int SQUARE(int x) {return x * x;}
#endif
//#endif

int main (int argc , char *argv[]) {
    int nSQUARE = SQUARE(2);
    std::cout <<"A négyzet eredménye: " << nSQUARE << std::endl;
    
    //itt van egy hiba ami megoldható ha zárójelet használsz
    std::cout << "A következő rossz eredmény'SQUARE(1 + 2)': " << SQUARE(1 + 2) << std::endl;

    //itt van egy olyan hiba ami nem oldható meg
    int i = 3;
    std::cout << "i = " << i << std::endl;
    nSQUARE = SQUARE(i++);
    std::cout << "A négyzet eredménye( 'SQUARE(i++)' ): " << nSQUARE << std::endl;
    std::cout <<"Most az i eredménye: " << i << std::endl;

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg az enter-t! " << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}