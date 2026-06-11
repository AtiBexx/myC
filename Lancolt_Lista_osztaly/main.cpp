//LáncoltListaOsztály osztálymetódusokkal
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

class NevAdathalmaz
{
    public:
    NevAdathalmaz(string &hivNev)
    :szNev(hivNev),mKovetkezo(nullptr) {}
    // önmaga hozzáadása a lista elejéhez
    void hozzaAdas()
    {
        this->mKovetkezo = mFej;
        mFej = this;
    }
    // lekérdező metódusok
    static NevAdathalmaz *elso() { return mFej; }
    NevAdathalmaz * kovetekezo() { return mKovetkezo; }
    const string &nev() { return szNev; }

    protected:
        string szNev;
        //A lista első és következő tagjának a hivatkozása
        static NevAdathalmaz *mFej;
        NevAdathalmaz *mKovetkezo;
};

//tárhelylefoglalása a fejmutatónak
NevAdathalmaz *NevAdathalmaz::mFej = nullptr;


NevAdathalmaz *adatokBeolvasasa()
{
    string nev;
    cout <<"Add meg a nevet:";
    cin >> nev;
    //
    if (nev == "stop")
    {
        return 0;
    }
    return new NevAdathalmaz(nev);
}

int main(int argc, char** argv)
{
    cout <<"A hallgatók nevének a beolvasása: " <<'\n';
    cout <<"A kilépéshez írd be hogy 'stop'...." <<'\n';

    //létrehozunk még egy NevAdathalmaz objektumot
    NevAdathalmaz* mNA;
    while(mNA = adatokBeolvasasa())
    {
        // hozzáadjuk a NevAdathalmaz objektumot a listához
        mNA->hozzaAdas();
    }

    // Az objektum megjelenitesehez vegogIteralunk
    // akkor állunk le a listával ha NULL
    cout << "\nBejegyzesek: " <<endl;
    for(NevAdathalmaz* mIter = NevAdathalmaz::elso();
    mIter;
    mIter = mIter->kovetekezo()
    )
    {
        //kiÍrjuk az aktuális bejegyzés nevét
        cout << mIter->nev() <<endl;
    }

    //kilépünk
    cout <<"A folytatáshoz kérlek nyomd meg kétszer az entert...."<< endl;

    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}
