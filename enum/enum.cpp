#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

constexpr int MAX_VAROS = 10;
enum class Megye 
{
    BP       = 0,
    Pest     = 1,
    BacsKisKun = 2
};
const char* megyeNev(Megye m)
{
    switch (m)
    {
    case Megye::BP:
        return "Budapest";
    case Megye::Pest:
        return "Pest";
    case Megye::BacsKisKun:
        return "Bács-Kiskun";
    }
}


int main(int argc, char* argv[])
{
    Megye valasztott = Megye::BP;
    cout << megyeNev(valasztott) << endl;
    
    cout << "Max varosok szama: " << MAX_VAROS << endl;

    cout <<"A kilépéshez nyomd meg az Entert......" << endl;
    cin.get();
    return 0;
}