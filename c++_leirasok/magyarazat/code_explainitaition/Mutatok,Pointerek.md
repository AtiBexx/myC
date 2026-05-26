```
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

void fv (int* mvaltozo);
void fv2 (int* mvaltozo);
void fvKilometer(const int* kmValtozo);
void stack(double* stackVar);
void fv4 (double* dvalt);
void fv (int* mvaltozo) {
     *mvaltozo = 5;
}
void fv2 (int* mvaltozo) {
    *mvaltozo += 10;
}
void fvKilometer(const int* kmValtozo) {
    std::cout << "Érték: " << *kmValtozo << std::endl;
}
void stack(double* stackVar) {
    *stackVar = 3.14;
}
void fv4 (double &dvalt) {
     dvalt = 6.28;
}

int main (int argc, char* argv[]) {
    int nvaltozo = 1;
    fv(&nvaltozo);
    std::cout << nvaltozo << std::endl;
    fv2(&nvaltozo);
    std::cout << nvaltozo << std::endl;
    nvaltozo -= 5;
    std::cout << nvaltozo << std::endl;

    int kilometerTotal = 100;
    fvKilometer(&kilometerTotal);
    std::cout << std::flush;

    //halommemória
    double* ptr = new double;
    stack(ptr);
    std::cout <<"A pointer edménye:"<< *ptr << std::endl;
    delete ptr; //törölkjuk a pointeredményt
    ptr = 0; //pointer nullázása
    //ez után soha nem szabad a törölt memóriát ujraolvasni
    //ptr = nullptr; //pointer nullázása
    // std::cout <<"A pointer edménye újra: "<< *ptr << std::endl;
    double n2valtozo = 1;
    fv4(n2valtozo);
    std::cout <<"n2valtozo eredménye: " << n2valtozo << std::endl;
    //klépünk 
    std::cout << "Kérlek nyomj egy ENTERT a befejezéshez!" << std::endl;
    //std:: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}
```

