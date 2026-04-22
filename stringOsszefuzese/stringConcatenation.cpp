/**
Ez a program 2 Sztringet fűz össze.
*/

#include <cstring>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

//PrototypeDeclaration
void concatenation(char cCell[], const char cSource[]);
void stringPrinting();


void concatenation(char cCell[], const char cSource[]) {

    int cCellIndex = 0;
    //keressük meg az első string végét
    while (cCell[cCellIndex] ) {
        cCellIndex++;
    }

    //most füzzük hozzá a másodikat az elsőhöz
    int cSourceIndex = 0;
    while (cSource[cSourceIndex]) {
        cCell[cCellIndex] = cSource[cSourceIndex];
        cCellIndex++;
        cSourceIndex++;
    }

    cCell[cCellIndex] = '\0';
}

void stringPrinting() {
    //olvasuk be az első stringet
    char cCell[256];
    std:: cout << "Kérlek add meg az első stringet: ";
    std:: cin.getline(cCell, 256);

    //olvasuk be a masodik stringet
    char cSource[256];
    std:: cout << "Kérlek add meg a masodik stringet: ";
    std:: cin.getline(cSource, 256);


    //füzük össze az " - " elemet az elsővel
    concatenation(cCell, " - ");

    //most pedig füzük hozzá a masodikot az elsőhöz
    concatenation(cCell, cSource);

    //most pedig írjuk ki az eredményt
    std::cout << "Az eredmény: " << cCell << std::endl;
}
void stringPrintingArgs(char cCell[], char cSource[]) {
    
    concatenation(cCell, " - ");
    concatenation(cCell, cSource);
    std::cout << "Az eredmény: " << cCell << std::endl;
}


int main(int argc , char *argv[]) {


    if (argc > 2)
    {
        char cCell[256] = "";
        char cSource[256] = "";
        concatenation(cCell, argv[1]);
        concatenation(cSource, argv[2]);
        stringPrintingArgs(cCell, cSource);
        return 0;
    }

    stringPrinting();

    if (argc == 1)
    {
    std:: cout << "A folytatáshoz kérlek nyomd meg az entert!" << std::endl;
    std:: cin.get();
    return EXIT_SUCCESS; 
    }
    
}

    
