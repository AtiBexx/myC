# include <cstdio>
# include <cstdlib>
# include <iostream>
using namespace std;

class Tanulo 
{
    public:
    int feleviOraszam = 0;
    double tanulmanyiAtlag = 0;

    //Metódos/taggfüggvény
    double kurzusHozzadasa(int oraSzam, double osztalyzat)
    {return 0.0;}
};

void egyFv() 
{
// Deklarálunk egy 10 tanulóbol álló tömböt
    Tanulo t[10];
    //Az 5. hallgatóhoz 5 -ös tanulmányi átlagot rendelünk hozzá
    t[4].tanulmanyiAtlag = 5;  // (5 * 32 + 0)
    t[4].feleviOraszam = 32;

    //Hozzáadunk még egy kurzust az 5. hallgatóhoz ami nem sikerült neki 
    t[4].kurzusHozzadasa(3, 0.0); // (32 + 3)
    //uj tanulmanyi atlag kiszamitasa
    t[4].tanulmanyiAtlag = (t[4].tanulmanyiAtlag * t[4].feleviOraszam + t[4].kurzusHozzadasa(3, 0.0)) / (t[4].feleviOraszam + 3);
    // (5 * 32 + 0) / (32 + 3) = 160 / 35 ≈ 4.571
    cout << "A 5. hallgató tanulmanyi átlaga: " << t[4].tanulmanyiAtlag << endl;
}

int main(int argc, char* argv[])
{
    egyFv(); // meghivjuk a függvényünket
    cout << "A folytatáshoz nyomd meg az Entert..." << endl;
    cin.get();
    return EXIT_SUCCESS;
}