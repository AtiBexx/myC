#include<cstdio>
#include<cstdlib>
#include<iostream>

//ptotótípusDeklaráció
void tombKiirasa(int Tomb[], int tombMerete);
void tombKiirasa2(int Tomb[], int tombMerete);

int main(int argc, char* argv[]) {

    int tomb[]= {4,3,2,1};
    tombKiirasa(tomb, 4);
    std::cout <<"\n"; //1 új sor
    std::cout <<"Második tömb:\n";
    tombKiirasa2(tomb, 4);


    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg az ENTER billentyú"<< std::endl;
    //std::cin.ignore(10, '\n');
    std::cin.get();
    return 0;
}

void tombKiirasa(int Tomb[], int tombMerete) {
    std::cout <<"A tömb értékei:\n";
 for (int i = 0; i < tombMerete; i++) {
    std::cout << i << ": " << Tomb[i] << "\n";  
 }
 std:: cout << std::endl;
}

void tombKiirasa2(int Tomb[], int tombMerete) {
    std::cout <<"A tömb értékei:\n";
    int* pTomb = Tomb;
 for (int i = 0; i < tombMerete; i++, pTomb++) {
    std::cout << i << ": " << *pTomb << "\n";  
 }
 std:: cout << std::endl;
}