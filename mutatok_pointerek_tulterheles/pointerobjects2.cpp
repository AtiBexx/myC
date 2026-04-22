// Definiáljukn mutatókat
// és használjuk a Tanuló mutatóját

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Tanulo {
public:
  int felevioraszam = 0;
  double tanulmanyiAtlag = 0;
  // ha a double helyett voidot használsz nem tudsz értéket visszadni a
  // fuggvenyben doublet add vissza és oraSzamra int-et osztalyzatra doublet var
  double kurzusHozzadasa(int oraSzam, double osztalyzat);
};

int main(int argc, char *argv[]) {
  // létrehozuk a tanulo objektumot
  // Stack objektum
  Tanulo t;
  t.tanulmanyiAtlag = 3.0;

  // Most létrehozunk egy mH pointert(mutatót) ami egy tanuló objektumra mutat
  // Heap objektum
  Tanulo *mH = new Tanulo(); //átadjuk a tanuló objektumnak az mH pointert és Memóriát foglalunk a heap-en
  
  //mH = &t; //TILOS KIRAKNI AZ ÉRTÉKADÓ OPERÁTORT !!!! HA MEMÓRIÁT FOGLALUNK LE A NEW KULCSZÓVAL..... 

  //Most kiíratjuk az eredményt
  cout << "t.tanulmanyiAtlag: " << t.tanulmanyiAtlag <<"\n";
  cout << "mH->tanulmanyiAtlag: " << mH->tanulmanyiAtlag << endl;
  
  //Most feloldjuk az új eredményt azaz új értéket adunk neki
  //de figyeljünk a biztonságra
  if (mH != nullptr){
  (*mH).tanulmanyiAtlag = 4.5;
  }

  cout << "Az új t.tanulmanyiAtlag: " << t.tanulmanyiAtlag <<"\n"; // 3 marad
  cout << "Az újmH->tanulmanyiAtlag: " << mH->tanulmanyiAtlag << endl; //itt is az új eredmény lesz
    //vagy igy is lehet 
  
  if(mH != nullptr)  {mH->tanulmanyiAtlag = 5.0;} //   mH->tanulmanyiAtlag = 5.0;// A nyíl operátort csak azért használjuk mert olvashatóbb

  cout << "Az újabb t.tanulmanyiAtlag: " << t.tanulmanyiAtlag <<"\n"; // 3.-marad
  cout << "Az újabb mH->tanulmanyiAtlag: " << mH->tanulmanyiAtlag << endl; //itt is az új eredmény lesz

  //FONTOS!!!!
  // visszaAdjuk  azaz töröljük a hepon a memóriát és nullra állítjuk
  delete mH; 
  mH = nullptr;

  cout << "A folytatáshoz kérlek nyomd meg az Entert..." << endl;
  cin.get();//várunk az enterre
  return EXIT_SUCCESS;
}


