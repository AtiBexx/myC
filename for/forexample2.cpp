#include <cstdio>
#include<cstdlib>
#include<iostream>

void arrayPrinting(int array[], int arraySize);

int main (int argc, char* argv[]) {

    int array[]= {4,3,2,1};
    arrayPrinting(array, 4 );

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg az ENTER billentyüt"<< std::endl;
    std::cin.get();
    return 0;

}

void arrayPrinting(int array[], int arraySize) {

    std::cout <<"A tömb értékei:\n";
    //int* pArray = array;
    for (size_t i = 0; i < arraySize; i++)
    {
      std::cout << i << ": " << array[i] << "\n";  
    }
    std:: cout << std::endl;
}