#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert> //assert() -hez kell
#include <limits>

typedef unsigned long long int Number; //a typedefel a rövidítéseket tudunk megadni

//prottype declartions
unsigned long long factorial(Number n);

int main(int argc, char* argv[]) 
{
    std::cout << "====FAKTORIÁLIS SZÁMÍTÓ====\n";
    std::cout <<"Fordítva: " <<__DATE__ <<" " <<__TIME__ <<"\n" <<std::endl;

    Number n;
    std::cout << "Kérlek adj meg egy pozítiv számot: ";
    std::cin >> n;
    assert(n > 0); //ha negatív a program leáll
    unsigned long long result = factorial(n);
    std::cout << n << "! = " << result << std::endl;

    std::cout << "A kilépéshez használd az ENTER-t" <<std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
  
}
//Faktoriális függvény
unsigned long long factorial(Number n)
{
unsigned long long fact = 1;
for (int i = 1; i <= n; i++)
{
    fact *= i;
}
return fact;
}