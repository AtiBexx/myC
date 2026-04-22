#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include <iostream>

int main (int argc, char* agrv[]) {

    wchar_t String1 [260];
    wchar_t String2 [260];

    std:: cout <<"Kérlek add meg az első szöveget az első stringhez: ";
    std:: wcin.getline (String1, 260);

    std:: cout <<"Kérlek add meg az második szöveget az második stringhez: ";
    std::wcin.getline (String2, 260);
    

    //most füzzük össze a 2-öt
    std:: wcsncat (String1, L" - ", 260);
    std:: wcsncat (String1, String2, 260);

    //most írjuk ki
    std:: wcout <<String1 <<std::endl;

    //kilépünk
    std::cout <<"Kérlek add meg az entert a kilépéshez...." <<std::endl;
    std::cin.get(); 
    return 0;
}