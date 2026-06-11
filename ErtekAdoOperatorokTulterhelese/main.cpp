//ÉrtékadóOperátorBemutató
// ez a program bemutatja az értékadó operátor használatát
// egy felhasználó által definiált osztályban
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
/*
-A DTomb egy dinamikus méretű tömbosztály, amellyel
- bemutatjuk az értékadó és a másoló konstruktor
- operátort.
*/
class DTomb
{
public:
 DTomb(int nTombHossza = 0) : nHossz(nTombHossza), mTomb(nullptr)
 {
     std::cout << "A DTomb létrehozása, hossz = " << nHossz <<'\n';
     if(nHossz > 0)
     {
         mTomb = new int[nHossz];
     }
 }
 DTomb(const DTomb& dt) : nHossz(0), mTomb(nullptr)
 {
     std::cout<<"A DTomb másolása, hossz = "
     << dt.nHossz <<'\n';
     dTombMasolas(dt);
 }
 ~DTomb()
 {
     dTombTorles();
 }
 //értékadó operátor
 DTomb& operator=(const DTomb& s)
 {
     std::cout << "A forrás hozzárendelése (hossz = " << s.nHossz <<") a célhoz (hossz = "
               << this->nHossz << ")" <<'\n';
               if(this != &s)
               {
               //töröljük a meglévő cuccokat
               dTombTorles();
               //Másolunk
               dTombMasolas(s);
               }
               //visszaadjuk a meglévő objektum értékét
               return* this;
 }
 //================
 int& operator[](int index)
 {
     return mTomb[index];
 }
 int meret() const
 {return nHossz;}
 //===============
 void megjelenites(std::ostream& ki)
 {
     if(nHossz > 0)
     {
         ki << mTomb[0];
         for(int i = 1; i < nHossz; i++)
         {
             ki << ", " << mTomb[i];
         }
     }
 }
//=================
protected:
    void dTombMasolas(const DTomb& dt);
    void dTombTorles();
    int nHossz;
    int* mTomb;
};
//dTombMasolas
// masolatot készítünk egy dinamikus int Tömbröl
void DTomb::dTombMasolas(const DTomb& forras)
{
    nHossz = forras.nHossz;
    mTomb = nullptr;
    if (nHossz > 0)
    {
        mTomb = new int[nHossz];
        for(int i = 0; i < nHossz; i++)
        {
            mTomb[i] = forras.mTomb[i];
        }
    }
}
//DTombTorles
//- felszabadytjuk a halomMermóriát
void DTomb::dTombTorles()
{
    nHossz = 0;
    delete[] mTomb;
    mTomb = nullptr;
}

int main(int argc, char** argv)
{
    //létrehozunk egy dinamikus tömböt és értéket adunk hozzá
    DTomb dt1(5);
    for (int i =0; i < dt1.meret(); i++)
    {
        //a felhasználó áltál definiált index operátoral
        //éri el a tömb tagjait
        dt1[i] = i;
    }
    std::cout <<"dt1= "; dt1.megjelenites(std::cout); std::cout <<std::endl;
    // most létrehozzuk ennek a dinamikus tömbnek a másolatát
    // a másoló konstruktorral; ez ugyanaz, mint a dt2(dt1)
    DTomb dt2 = dt1;
    dt2[2] = 20; // a másolatban módosítunk egy értéket
    std::cout <<"dt2= "; dt2.megjelenites(std::cout); std::cout <<std::endl;
    // felülírjuk a meglévő dt2-t az eredeti dt1-gyel
    dt2 = dt1;
    std::cout << "dt2= "; dt2.megjelenites(std::cout); std::cout << std::endl;


    //kilépünk
    std::cout <<"A kilépéshez kérlek nyomd meg 2-szer az entert..."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
    std::cin.get();
    return 0;
}
