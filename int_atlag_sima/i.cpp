//
//  IntÁtlag - átlagol 3 számot egész számításokkal.
//             Először összeadja az egyes számokat 3-mal elosztva
//             másodszor pedig a három szám összegét
//             osztja 3-mal.
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int nArgSzama, char* mszArg[])
{
    int nErtek1;
    int nErtek2;
    int nErtek3;

    // megadunk három számot
    cout << "Ez a program három számot átlagol"
         << "egész számításokkal\n\n";
    cout << "Adj meg három egész számot:\n";

    cout << "n1 - ";
    cin  >> nErtek1;

    cout << "n2 - ";
    cin  >> nErtek2;

    cout << "n3 - ";
    cin  >> nErtek3;

    // először a három tört összege
    cout << "n1/3 + n2/3 + n3/3 = ";
    cout << nErtek1/3 + nErtek2/3 + nErtek3/3;
    cout << "\n";

    // most a három szám összegének törtrésze
    cout << "(n1 + n2 + n3)/3   = ";
    cout << (nErtek1 + nErtek2 + nErtek3) / 3;
    cout << "\n";

	// várakozás a program leállításával, amíg a felhasználó készen áll,
	// hogy a felhasználó láthassa a program eredményeit
	cout << "A folytatáshoz nyomd meg az Entert..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}
