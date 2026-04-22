// Megtakarítási számla -- Savings account
// Egy olyan osztályt hozzunk létre ami képes a befizetés megvalósítására
// Let's create a class that can handle the payment.

class megtakaritasiSzamla {
    public:

    double egyenleg;
    unsigned int szamlaszam;
    double befizetes(double osszeg) {
        egyenleg += osszeg;
        return osszeg;
    }
};

/*A Beágyazott megtakaritasiSzamla - egy olyan taggfüggvényt hívunk meg
 ami amegtakarítási számla osztályban van deklarálva és definiálva*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
 int main(int argc, char* argv[])
 {
    megtakaritasiSzamla szamla1;
    szamla1.egyenleg = 0;
    szamla1.szamlaszam = 123456789;

    std::cout << "10 egység befizetése a következő számlára: " << szamla1.szamlaszam << std::endl;
    szamla1.befizetes(10);
    std::cout << "Egyenleg: " << szamla1.egyenleg << std::endl;

    std::cout <<"A folytatáshoz kérlek nyomj egy Entert...." << std::endl;
    std::cin.get();
    return 0;

 }

 /*
 A helyben kifejtett függvény C++-ban azt jelenti, hogy a függvény definícióját és a deklarációját egyaránt ott adod meg, ahol használni szeretnéd, és gyakran inline (helyben beillesztett) optimalizációra gondolunk. Hivatalosan a C++-ban ezt az inline kulcsszóval lehet jelezni, de a modern fordítók sokszor automatikusan helyben kifejtik a rövid függvényeket.

Példa helyben kifejtett (inline) függvényre:
#include <iostream>
using namespace std;

inline int osszead(int a, int b) {
    return a + b;
}

int main() {
    cout << osszead(3, 5) << endl;  // Kiírja: 8
    return 0;
}

Magyarázat:

A inline kulcsszó azt mondja a fordítónak: „ha tudod, illeszd be a függvény kódját a hívás helyére ahelyett, hogy külön helyre menne a hívás.”
Ez gyorsabb lehet kis, gyakran használt függvényeknél, mert elkerüli a függvényhívással járó plusz utasításokat.
Helyben kifejtett függvényt általában header fájlokban (.h) szokás definiálni, hogy minden forrásfájl lássa.
Összefoglalva:
Rövid, egyszerű függvényeknél jó.
Csökkentheti a függvényhívás költségét.
A modern C++ fordítók gyakran automatikusan inline-olják a rövid függvényeket, még inline kulcsszó nélkül is.
 */
