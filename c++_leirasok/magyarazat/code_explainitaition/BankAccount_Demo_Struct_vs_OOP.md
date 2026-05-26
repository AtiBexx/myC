# Struct vs OOP

**main.cpp**

```
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <limits>
#include "class_test.h"

//PrototypeDeclarations
//ez nem szükséges mert már a h fájlban deklaráltuk őket
double inPayment(savingsAccount& account, double amount);
double befizetes(double egyenleg, double osszeg);


int main (int argc, char* argv[]) {

MegtakaritasiSzamla szamlam;
szamlam.szamlaSzam = 123456;
szamlam.egyenleg = 1000.0;

savingsAccount savAcc;
savAcc.accountNumber = 123456;
savAcc.balance = 1000.0;

double userInput;

std::cout << "Kérlek add meg a számlaszámodat és az egyenlegedet:" << std::endl;
std::cin >> szamlam.szamlaSzam ;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

std::cin >> szamlam.egyenleg ; 
//Itt nem adjuk hozzá az egyenleghez a befizetett osszeget
//Hanem új egyenleget adunk hozzá
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

std::cout << "A számlaszámod: " << szamlam.szamlaSzam << std::endl;
std::cout << "Az egyenleged: " << szamlam.egyenleg << std::endl;

std::cout << "\nOOP befizetés mérés..." << std::endl;
    measureTime([&]() {
        szamlam.befizetes(500); // példa befizetés
    });



std::cout << "A következő struct-os változathaoz kérlek nyomj egy entert !" << std::endl;
std::cin.get();

std::cout << "Please enter your account number and balance:" << std::endl;
std::cin >> savAcc.accountNumber ;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

std::cin >> userInput ;
//Hozzáadjuk a befizetett osszeget a számla egyenlegéhez
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
if(savAcc.balance > 0) savAcc.balance += userInput;


std::cout << "Your account number: " << savAcc.accountNumber << std::endl;
std::cout << "Your balance: " << savAcc.balance << std::endl;

std::cout << "\nStruct befizetés mérés..." << std::endl;
    measureTime([&]() {
        inPayment(savAcc, (500)); // példa befizetés
    });

return 0;

}
```

**class_test.h**

```
#ifndef CLASS_TEST_H

#define  CLASS_TEST_H

//vagy #pragma once 
// de akkor nem kell #ifndef #define és #endif -se

#include <iostream>
#include <chrono>

template<typename Func>
void measureTime(Func f) {
    auto start = std::chrono::high_resolution_clock::now();
    f(); // lefut a számítás
    auto end = std::chrono::high_resolution_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "A számítás ideje: " << diff.count() << " ms" << std::endl;
}
//Savings Account
class MegtakaritasiSzamla
{
    public:
    unsigned szamlaSzam;
    double egyenleg;

    // Mivel osztályban deklaráltuk a befizetes fuggvenyt-> 
    // ezt nevezük tagfüggvénynek / Memeber function-nak
    double befizetes (double osszeg) {
        egyenleg += osszeg;
        return egyenleg;
    }
};

//a struct-nál nem kell a public /private /protected keresztneveket megadni
//Itt is lehet taggfüggvényként írni a befizetes függvényt de csak C++-ban
// C-ben nem C-ben úgyanígy funkcionális programozásban kell leírni mint a példa itt is
// mutatja a befizetes függvényt.
struct savingsAccount {
    unsigned accountNumber;
    double balance; 
};
inline double inPayment(savingsAccount& account, double amount) {
    account.balance += amount;
    return account.balance;
    
}


#endif // !CLASS_TEST_H
//Az inline azt mondja a fordítónak
//“Ha lehet, ne hozz létre külön függvényhívást, hanem 
// helyettesítsd be a függvény törzsét a hívás helyére.
//Miért jobb ez a kis függvényeknél?
//Nincs függvényhívás overhead.....(PárMásodperces Milliszekundum)
//nem kötelező, a fordító maga is inline-olhat, 
// de az explicit jelzés → biztosabb eredmény kis függvényeknél

/*
Amikor a befizetes függvényt az osztályon belül deklarálod és használod, 
OOP-ről beszélünk: az osztály tagja a függvény (tagfüggvény / member function)
, és az objektum állapotát (egyenleg) módosítja. 
Ez a példány-specifikus viselkedés jellemző az objektum-orientált programozásra.
Ha ugyanezt a befizetes függvényt osztályon kívül írnád, mondjuk így:
*/
/* Funkcionális programozás */
/*class MegtakaritasiSzamla
{
    public:
    unsigned szamlaSzam;
    double egyenleg;
};
double befizetes(double egyenleg, double osszeg) {
    egyenleg += osszeg;
    return egyenleg;
}
    */
/*
akkor ez funkcionális / procedurális stílus lenne, 
mert nem kapcsolódik objektumhoz, nincs tagfüggvény, 
és nem használja az osztály példányát a belső állapot kezelésére. 
Itt csak adatot adsz át paraméterként, és a 
függvény visszaadja a módosított értéket.
*/
```

