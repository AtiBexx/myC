#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>

int main(int argc, char* argv[]) {

    const char*str= "egyString";
    std::cout <<"A tömb értéke a következő: " << str << std::endl;

    std::cout <<"Az str kiírása tömbként: ";
    //írjuk ki a str-t tömbként
    //for(int i= 0; i< 9[str]; i++)
    for(int i= 0; i < strlen(str); i++) {
        std::cout << str[i];
    }
    std:: cout << std::endl;

    //most írjuk ki mutatóval
    std::cout <<"Az str kiírása mutatóval: ";
    const char* pStr = str;
    while(*pStr != '\0') {
        std::cout << *pStr;
        pStr++;
    }
    std:: cout << std::endl;
    
    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg az ENTER billentyú"<< std::endl;
    //std:cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //#include<limits>
    //std::cin.ignore(10, '\n');
    std::cin.get();
    return 0;
}