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



std::cout << "A következő struct-os változathaoz kérlek nyomj egy entert....!" << std::endl;
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
std::cout << "A kilépéshez kérlek nyomj egy entert...." << std::endl;
std::cin.get();

return 0;

}