#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

namespace Math 
{
    double log (double x) 
    { 
        return std::log(x);
    }
}

namespace systemLog
{
    void log (double x) 
    {
        std::cout << "Log value: " << x << std::endl;
    }
}
void test (double x)
{
    double dl = Math::log(x);
    systemLog::log(dl);
}

//prótotípus deklaráció
void test (double x);


int main(int argc, char* argv[]) 
{
    test(10);
    test(1);
    test(0.5);
    test(0.1);

    //exiting
    std::cout <<"A folytatáshoz kérlek nyomd meg az enter-t! " << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}