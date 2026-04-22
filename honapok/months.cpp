#include<cstdio>
#include<cstdlib>
#include<iostream>
#include <sys/stat.h>
#include <limits>

//hónapok nevei
const char* const* honapok()
{  
static const char* const months[] = 
{
    "Érvénytelen",
    "Január",
     "Február",
      "Március",
    "Április",
     "Május", 
     "Június",
    "Július",
     "Augusztus",
      "Szeptember",
    "Október", 
    "November",
     "December"
};

return months;
}
// visszadjuk a hónapok neveit
const char* printingMonths(int nMonth)
{
    const char* const* getMonths = honapok();
    if (nMonth < 1 || nMonth >12)
    {
        return getMonths[0];
    }
    return getMonths[nMonth];
}

//prototypeDeclarations
const char* printingMonths(int nMonth);
const char* const* honapok();

//Main function
int main(int argc, char* argv[]) {

    //bekérjük a hónapokat
    std::cout <<"kérlek add meg a megjelenítendő hónap számát:\n";
    std::cout << "(A kilépéshez egy negatív számot adj meg kérlek!)\n";
          

    for(;;)
    {
        std::cout << "a hónap neve: ";
        int nMonth;
        std::cin >> nMonth;
        if (nMonth < 0)
        {
            break;
        }
        std::cout << printingMonths(nMonth) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "A program befejezéséhez kérlek nyomd meg az ENTERT......" << std::endl;
    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    std::cin.get();
    return EXIT_SUCCESS;
}