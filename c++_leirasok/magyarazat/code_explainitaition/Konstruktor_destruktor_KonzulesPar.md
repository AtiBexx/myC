```
// A tagok megsemmisítése
//Ez a program  fellépít és megsemmisit néhány adattagot
//
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

class Kurzus
{
public:
    //Jump9
    Kurzus() {cout <<"[HEAP]A Kurzus létrehozása....\n";} //Jump4
    ~Kurzus() {cout <<"[HEAP]A Kurzus megsemmisítése\n";}
};
class Hallgato
{
public:
    //Jump1
    Hallgato() {cout <<"[STACK]A Hallgató létrehozzása....."<<"\n";} //Jump7
    ~Hallgato() {cout <<"[STACK]A Hallgató megsemmisítése...." <<"\n";}
};
class Oktato
{
public:
    Oktato()
    {
        //Jump8
        cout <<"[STACK]Az Oktató létrehozása és a[HEAP] Kurzus létrehozzáse heapen..." <<"\n";// Jump3
        // HEAP
        mK = new Kurzus;
    }
    ~Oktato()
    {
        cout <<"[STACK]Az Oktató megsemmisítése" <<"\n";
        cout <<"[HEAP]Az Oktató megsemmisítése" <<"\n";
        // HEAP TŐRLÉSE
        delete mK;
    }
protected:
     // pointer a HEAP objektumra
    Kurzus* mK;
    //Itt adjuk át a Kurzust az mK pointernek
};

class KonzulensPar
{
public:
    //Jump10
    KonzulensPar() {cout << "[STACK]A KonzulensPar létrehozzása/fellépítése" << "\n";} //Jump5
    ~KonzulensPar() {cout <<"[STACK]A KonzulensPar megsemmisítése..." <<"\n";}
protected:
    //itt hivatkozunk az objektumokra de itt stacken
     // STACK
    Hallgato hallgato; // STACK Jump2
    Oktato oktato;  // STACK (de belül HEAP-et is használ)
};

KonzulensPar* fv()
{
    cout <<"A KonzulensPar objektum létrehozása az fv() függvényben..."<< "\n";// jump1
     // STACK
    KonzulensPar kp;
    cout <<"A KonzulensPar lefoglalasa a halommemóriából" << "\n"; //Jump6
    // HEAP
    KonzulensPar* mKP = new KonzulensPar;

    cout << "Visszatérés return-el az fv() függvényből " <<"\n";//Jump10
    return mKP;
}

int main(int argc, char** argv)
{
    //meghivjuk az fv() függvényt
    //majd visszaadjuk a halomemóriába
    //a konzulensPar objektumot

     // HEAP pointer kap vissza fv()-ből
    KonzulensPar* mKPVisszaHelyezett = fv();
    cout << "Visszahelyezük a KonzulensPar-t a halomemóriába azaz töröljük..."<<"\n";

    // HEAP törlés
    delete mKPVisszaHelyezett;
    cout << "Most már nincs memória szivárgás" <<"\n";

    //kilépünk
    cout <<"A kilépéshez kérlek nyomd meg 2-szer az ENTERT..." << endl;
    cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    cin.get();

    return EXIT_SUCCESS;
}
```

