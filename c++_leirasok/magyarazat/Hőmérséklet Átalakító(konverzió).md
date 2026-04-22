## Hőmérséklet Átalakító(konverzió)

Ha visual studioban dolgozol akkor **Create** majd **new project** és válaszuk a **console applications**-t.

![image-20260125164557498](E:\projects\Books\kepek\image-20260125164557498.png)

![image-20260125164631967](E:\projects\Books\kepek\image-20260125164631967.png)

A **project name**-hez a project nevét add meg.<br>

A **Location**-hoz ahova menteni akarod a projectet<br>

Képlet: $F = C \times \frac{9}{5} + 32$ <br>

az F a fahreinheit C celsius<br>

 x9 osztva 5 el +32 <br>

mondjuk 1 foknál 1*9= 9 1*5 =5 9/5 = 1.8 +32 = 33.8 F -> Fahreinheit<br>

Képletben:<br>

Behelyettesítve C=1C = 1C=1:<br>
$$
Behelyettesítve 
𝐶
=
1
C=1:

𝐹
=
1
×
9
5
+
32
F=1×
5
9
	​

+32
𝐹
=
9
5
+
32
F=
5
9
	​

+32
𝐹
=
1.8
+
32
F=1.8+32
𝐹
=
33.8
F=33.8
$$
A tényező a kódban a 9/5 lesz.....<br>

kód:

```
# include <iostream>
# include <cstdio>
#include<cstdlib>
#include<limits>

int main(int argc, char* argv[])
{
	// a változók deklarációja(declaring variables)
	// Szakmaibb nyelven típus definició (type definition)
	double celsius;

	//Most pedig bekérjük a számot (Now we ask for the number)
	std::cout << "Kérlek add meg a hőmérsékeletet Celsius fokban:";
	std::cin >> celsius; 
	
	//A konverzió elvégzése (Performing the conversion)
	// A Fahrenheit és Celsius közötti különbség (The difference between Fahrenheit and Celsius)
	double tenyezo = 9.0 / 5.0; // vagy 1.8 is lehetne (or it could be 1.8)

	//Átváltás Fahrenheit-re (Conversion to Fahrenheit)
	double fahrenheit = (celsius * tenyezo) + 32;
	
	//Eredmény kiírása (Outputting the result)
	std::cout << "A celsius fok amit beírtál"<< celsius << "\n";
	std::cout << "átváltva Fahrenheit-re: " << fahrenheit << " fok" << std::endl;

    //Várunk amíg a felhasználó megnyom egy gombot (We wait until the user presses a key)
	std::cout << "Nyomj meg egy gombot a kilépéshez...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//std::cin.ignore(10, '\n');
	std::cin.get();
	return 0;
}
```

**Fontos !**

`double tenyezo = 9.0 / 5.0;` ->**Ez tört szám azaz tizedes szám legyen**

**Ha nem tízedes szám akkor nem fogja átváltani tízedes azaz törtszámba**

```
std::cin >> celsius;
```

itt kérjük be a számot a `cin`-el**(std::cin)** és 

A `>>` operátor a *formázott beolvasást* végzi:

- **kihagyja a szóközöket, újsorokat, tabulátorokat**
- csak a következő „token”-t **(számot vagy szöveget)** olvassa be

```
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
```

Ez a kód addig törli a karakterek számát amíg egy új sorba nem ér ez a **pufferürítés** miatt kell amit majd ezen a példán keresztül be is mutatok miért kell.

Az az ez **a végtelenségig töröl**, **míg el nem éri a sor végét** (`'\n'`).(összes karaktert eldobja)

**De fontos kell hozzá** a `#include<limits>` könyvtár..!!!!

Következő ->

```
//std::cin.ignore(10, '\n');
```

Ez **maximum 10 karakterig töröl**, vagy **ha előbb talál `'\n'`-t**, akkor ott megáll.

Tehát ha a felhasználó 50 karaktert ír, akkor **csak az első 10-et törli**, a többi bent marad a pufferben.

**Miért kell ez?**

Példa:

```
std::cin >> celsius;
```

Ha a felhasználó beírja:

```
25<Enter> // és nyom egy entert
```

akkor a `25` beolvasódik, **de a `'\n'` bent marad** a pufferben.(azaz az enter lenyomása is bent marad)

Ez később gondot okozhat, például ha:

```
std::cin.get();
```

vagy másik `std::cin >>` következik.<br> most kikomentelem az `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');`

![image-20260125175215790](E:\projects\Books\kepek\image-20260125175215790.png)

nézzük mi történik.......

![image-20260125174906383](E:\projects\Books\kepek\image-20260125174906383.png)

Kilépet a projectből úgy mintha megnyomtad volna az entert a másik enter csak a fordító-nak a biztonsági kilépése ha **cmd**-ből használnád rögtön kiírná az eredményt és ki is lépne azonnal úgy hogy, az eredményt nem látnád.

![image-20260125175617119](E:\projects\Books\kepek\image-20260125175617119.png)

 Ha a másikat használod a `std::cin.ignore(10, '\n');`<br>

Írd be ezt a számot `4848484848481252511`................

Akkor ha nagyon nagy számot írsz be <br>

A `std::cin >> double`:

- megpróbálja beolvasni a számot
- **ameddig számjegyeket talál**
- és **amikor már nem fér bele a double-be**, akkor **nem fogja tovább olvasni** a maradékot, hanem **az marad a pufferben**.

Ezért történik az, hogy:

```
A celsius fok amit beírtál: 4.84848e+18
```

ami azt jelenti, hogy a `double` **túlcsordul** és tudományos jelölésbe megy.<br>

![image-20260125180112543](E:\projects\Books\kepek\image-20260125180112543.png)

```
//A konverzió elvégzése (Performing the conversion)
// A Fahrenheit és Celsius közötti különbség (The difference between Fahrenheit and Celsius)
long double tenyezo = 9.0 / 5.0; // vagy 1.8 is lehetne (or it could be 1.8)

//Átváltás Fahrenheit-re (Conversion to Fahrenheit)
long double fahrenheit = (celsius * tenyezo) + 32;
```

A long double nem sokat segít de nagyobb a tartománya ha átírod.

Ha kiszeded a `/n` et nem fog kilépni .....

**Snippet**

    //Várunk amíg a felhasználó megnyom egy gombot (We wait until the user presses a key)
    std::cout << "Nyomj meg egy gombot a kilépéshez...";
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.ignore(10 );
    
    std::cin.get();
    return 0;
    }
![image-20260125181107272](E:\projects\Books\kepek\image-20260125181107272.png)

megáll a Nyomj egy gombot a kilépés-nél

Ha **volt Enter** a bemenet végén, akkor az Enter karakter (azaz `'\n'`) **a pufferben maradt**, és ezért nem törölte ki a `std::cin.ignore(10)`.

Márpedig volt.

Itt amugy nem baj ha a pufferba marad pár karakter de majd lesz olyan példa ahol nagyon is az lesz a későbbiekben majd látni és tapasztalni fogod.

**Teljes kód:**

```
# include <iostream>
# include <cstdio>
#include<cstdlib>
#include<limits>

int main(int argc, char* argv[])
{
	// a változók deklarációja(declaring variables)
	// Szakmaibb nyelven típus definició (type definition)
	long double celsius;

	//Most pedig bekérjük a számot (Now we ask for the number)
	std::cout << "Kérlek add meg a hőmérsékeletet Celsius fokban:";
	std::cin >> celsius; 
	
	//A konverzió elvégzése (Performing the conversion)
	// A Fahrenheit és Celsius közötti különbség (The difference between Fahrenheit and Celsius)
	long double tenyezo = 9.0 / 5.0; // vagy 1.8 is lehetne (or it could be 1.8)

	//Átváltás Fahrenheit-re (Conversion to Fahrenheit)
	long double fahrenheit = (celsius * tenyezo) + 32;
	
	//Eredmény kiírása (Outputting the result)
	std::cout << "A celsius fok amit beírtál"<< celsius << "\n";
	std::cout << "átváltva Fahrenheit-re: " << fahrenheit << " fok" << std::endl;

    //Várunk amíg a felhasználó megnyom egy gombot (We wait until the user presses a key)
	std::cout << "Nyomj meg egy gombot a kilépéshez...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//std::cin.ignore(10,'\n' );

	std::cin.get();
	return 0;
}
```

A másik hiba:

Ha nem számot írsz be az **eredmény rossz lesz** szóval átírom egy kicsit robosztikusabbra a kódot.

Teljes javított kód:

```
# include <iostream>
# include <cstdio>
#include<cstdlib>
#include<limits>

int main(int argc, char* argv[])
{
	for (;;) {
		// a változók deklarációja(declaring variables)
		// Szakmaibb nyelven típus definició (type definition)
		long double celsius;

		//Most pedig bekérjük a számot (Now we ask for the number)
		std::cout << "Kérlek add meg a hőmérsékeletet Celsius fokban:";
		std::cin >> celsius;

		//A konverzió elvégzése (Performing the conversion)
		// A Fahrenheit és Celsius közötti különbség (The difference between Fahrenheit and Celsius)
		long double tenyezo = 9.0 / 5.0; // vagy 1.8 is lehetne (or it could be 1.8)

		//Átváltás Fahrenheit-re (Conversion to Fahrenheit)
		long double fahrenheit = (celsius * tenyezo) + 32;

		//Eredmény kiírása (Outputting the result)
		if (!std::cin.fail()) {
			std::cout << "A celsius fok amit beírtál: " << celsius << "\n";
			std::cout << "átváltva Fahrenheit-re: " << fahrenheit << " fok" << std::endl;
			break;
		}
		else {
			std::cout << "Hiba: Nem érvényes számot adtál" << std::endl;
			std::cin.clear();// a hibajelzés törlése
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // a rossz bemenet eltávolítása a bemeneti pufferből
		}
	}
	

    //Várunk amíg a felhasználó megnyom egy gombot (We wait until the user presses a key)
	std::cout << "Nyomj meg egy gombot a kilépéshez...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//std::cin.ignore(10,'\n' );

	std::cin.get();
	return 0;
}
```

---------

```
for (;;) {} 
```

Beraktam az egészet egy végtelen for ciklusba `for(;;){}`  a párja a `break ;` amivel kilépünk ott van a for ciklusban <br>

```
//Eredmény kiírása (Outputting the result)
		if (!std::cin.fail()) {
			std::cout << "A celsius fok amit beírtál: " << celsius << "\n";
			std::cout << "átváltva Fahrenheit-re: " << fahrenheit << " fok" << std::endl;
			break;
		}
```

`if (!std::cin.fail())` -> elöször is a felkiáltójele `!` negálunk szóval az elentétje lesz a dolognak <br>

ez akkor lép be a ciklusba az állapota False a negálás miatt.

```
std::cin.get();
```

 ez egy karaktert vár/olvass be..........

**Nézük Argumentum megadásával**

Teljes kód:

```
# include <iostream>
# include <cstdio>
# include<cstdlib>
# include<limits>

int main(int argc, char* argv[])
{
	long double celsius;
	long double tenyezo;
	long double fahrenheit;

	if (argc > 1) {
		// Argumentum alapján próbáljuk olvasni a bemenetet
		std::string input = argv[1];
		char* endptr;
		celsius = std::strtold(input.c_str(), &endptr);

		// Ellenőrizzük, hogy sikerült-e számmá alakítani
		if (*endptr != '\0') {
			std::cout << "Hiba: Nem érvényes számot adtál meg." << std::endl;
			return 1;

		}
	}
	else { //Interaktív mód
		for (;;) {
			//Most pedig bekérjük a számot (Now we ask for the number)
			std::cout << "Kérlek add meg a hőmérsékeletet Celsius fokban:";
			std::cin >> celsius;


			//Eredmény kiírása (Outputting the result)
			if (!std::cin.fail()) {
				break;
			}
			else {
				std::cout << "Hiba: Nem érvényes számot adtál" << std::endl;
				std::cin.clear();// a hibajelzés törlése
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // a rossz bemenet eltávolítása a bemeneti pufferből
			}
		}
	}

	//A konverzió elvégzése (Performing the conversion)
	// A Fahrenheit és Celsius közötti különbség (The difference between Fahrenheit and Celsius)
	tenyezo = 9.0 / 5.0; // vagy 1.8 is lehetne (or it could be 1.8)

	//Átváltás Fahrenheit-re (Conversion to Fahrenheit)
	fahrenheit = (celsius * tenyezo) + 32;


	//Eredmény kiírása (Outputting the result)
	std::cout << "A celsius fok amit beírtál: " << celsius << "\n";
	std::cout << "átváltva Fahrenheit-re: " << fahrenheit << " fok" << std::endl;

	//Kilépés elött (Exit)
	//Várunk amíg a felhasználó megnyom egy gombot (We wait until the user presses a key)
	if (argc == 1) {

		std::cout << "Nyomj meg egy gombot a kilépéshez...";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//std::cin.ignore(10,'\n' );

		std::cin.get();
		return 0;
	}
}
```

Probáld ki írd be a lefordított program nevét és nyomj egy szöközt majd írd mellé 2 

![image-20260126164902632](E:\projects\Books\kepek\image-20260126164902632.png) 

```
if (argc > 1) {}
```

Ez azt jelenti **ha több parancssori argumentum van megadva**

**Homerseklet_Konverzio.exe 25** az már több paracsori argumentum 

- **`argc`**: a parancssori argumentumok száma

- **`argv`**: maga az argumentumok tömbje

Ha nem adsz meg semmit csak a program nevét akkor:

- `argc = 1`

- `argv[0]` = "program.exe"

**Ha megadsz egy számot:**

program.exe `25`   azaz (**Homerseklet_Konverzio.exe 25**)

`argc` = 2

`argv[1]` = "25"

Ha az` argc` nagyobb mint egy” azt jelenti, hogy legalább egy argumentumot megadtál a program indításakor.

```
std::string input = argv[1];
```

- Az `argv[1]` egy **C-stílusú karaktertömb** (`char*`)

- Ezt **átalakítjuk** egy `std::string`-gé

```
celsius = std::strtold(input.c_str(), &endptr);
```

- átalakítás long double-re 

Az `std::strtold` egy **C/C++ beépített függvény**

```
std::string input = argv[1];
char* endptr;
celsius = std::strtold(input.c_str(), &endptr);
```

----------------

```
if (*endptr != '\0') {
    std::cout << "Hiba: Nem érvényes számot adtál meg." << std::endl;
    return 1;
}
```

Ha `endptr` nem a string végére mutat (`'\0'`), akkor **volt valami plusz karakter** a szám után → nem tiszta szám.

Ha csak pl sima `abc` adtál meg azaz nem számot akkor fogja kiírni hiba nem számot adtál meg

'\0' -> Ez a string **végjelzője** .<br>

miért `*endptr != '\0'`?<br>

Mert az `endptr` egy **pointer**, ami a bemenet azon részére mutat, <br>

ahol a szám konvertálás véget ért.<br>

Ha a bemeneted teljesen szám volt `"123"` a vége `'\0'` azaz Null Terminátor.<br>

ha volt extra karaktered pl `"123a"`  akkor az ami már nem egyenlő nullával....<br>

- memória számnál `'1' '2' '3' '\0'` <br>
- Ha volt extra karakter: `'1' '2' '3' 'a' '\0`'  -> a konvertálás az `a` előtt megáll<br>

**std::strtold** -> **C-stílusú karaktertömböt** (C-stringet) konvertál számmá.<br>

Az `std::strtold` így néz ki:<br>

```
long double strtold(const char* str, char** endptr);
```

- **`const char\*`** típusú bemenetet vár (C-string)

- nem `std::string`-et pl: `char szoveg[] = "123.45";`

`const char* `  Ez egy **C-stílusú string** 

A `return 1;` pedig  **hibakódot** jelent a `main()` függvényből való kilépéskor.

A számításokat ki kellett helyezni a for(;;) cikluson kívülre mert nem hajtódtak volna végre <br>

az argumentum megadása esetén.

```
//A konverzió elvégzése (Performing the conversion)
// A Fahrenheit és Celsius közötti különbség (The difference between Fahrenheit and Celsius)
tenyezo = 9.0 / 5.0; // vagy 1.8 is lehetne (or it could be 1.8)

//Átváltás Fahrenheit-re (Conversion to Fahrenheit)
fahrenheit = (celsius * tenyezo) + 32;

//Eredmény kiírása (Outputting the result)
std::cout << "A celsius fok amit beírtál: " << celsius << "\n";
std::cout << "átváltva Fahrenheit-re: " << fahrenheit << " fok" << std::endl;


```

```
if (argc == 1) {

std::cout << "Nyomj meg egy gombot a kilépéshez...";
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//std::cin.ignore(10,'\n' );

std::cin.get();
return 0;
```

`if (argc == 1) `-> azt jelenti ha az argumentumunk egy akkor kilép azaz a ciklus végrehajtódik.<br>

`==` egyenlő <br>

{**ÉS VÉGÜL AZ 'Exit' PARANCS HOZZÁADÁSA**}

Teljes kód:

```
# include <iostream>
# include <cstdio>
# include<cstdlib>
# include<limits>
# include <string>

int main(int argc, char* argv[])
{
	long double celsius = 0.0;
	long double tenyezo = 9.0 / 5.0; // vagy 1.8 is lehetne (or it could be 1.8)
	long double fahrenheit = 0.0;
	//Bemenet olvasása (Reading input)
	std::string input;
	//std::getline(cin, input);
	

	if (argc > 1) {
		// Argumentum alapján próbáljuk olvasni a bemenetet
		std::string input = argv[1];
		char* endptr;
		celsius = std::strtold(input.c_str(), &endptr);

		// Ellenőrizzük, hogy sikerült-e számmá alakítani
		if (*endptr != '\0') {
			std::cout << "Hiba: Nem érvényes számot adtál meg." << std::endl;
			return 1;
		}
		// Számítás elvégzése az argumentum esetén is
		//Átváltás Fahrenheit-re (Conversion to Fahrenheit)
		fahrenheit = (celsius * tenyezo) + 32;

		//Eredmény kiírása (Outputting the result)
		std::cout << "A celsius fok amit beírtál: " << celsius << "\n";
		std::cout << "átváltva Fahrenheit-re: " << fahrenheit << " fok" << std::endl;
	}
	else { //Interaktív mód
		for (;;) {
			//Most pedig bekérjük a számot (Now we ask for the number)
			std::cout << "Kérlek add meg a hőmérsékeletet Celsius fokban\n";
			std::cout << "(A kilépéshez használd az 'exit' parancsot):";
			std::string input;
			std::getline(std::cin, input);

			char* endptr;
			long double temp_celsius = std::strtold(input.c_str(), &endptr);
			
			//Eredmény kiírása (Outputting the result)
			if (*endptr == '\0') {   
				celsius = temp_celsius;
				fahrenheit = (celsius * tenyezo) + 32;//Átváltás Fahrenheit-re (Conversion to Fahrenheit)
				std::cout << "A celsius fok amit beírtál: " << celsius << "\n";
				std::cout << "átváltva Fahrenheit-re: " << fahrenheit << " fok" << std::endl;
			}
			else if(input == "exit") {
				break;
			}
			else {
				std::cout << "Hiba: Nem számot adtál meg Kérlek számot adj meg..." << std::endl;
				//std::cin.clear();// a hibajelzés törlése
				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // a rossz bemenet eltávolítása a bemeneti pufferből
			}
		}
	}

	//Kilépés elött (Exit)
	//Várunk amíg a felhasználó megnyom egy gombot (We wait until the user presses a key)
	if (argc == 1) {

		std::cout << "Nyomd meg az ENTERT a kilépéshez...";
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//std::cin.ignore(10,'\n' );

		std::cin.get();
		return 0;
	}
}
```

![image-20260126201744260](E:\projects\Books\kepek\image-20260126201744260.png)

Argumentum megadása vstudioban....

![image-20260126201854735](E:\projects\Books\kepek\image-20260126201854735.png)

A solution explorerben a `Properties`Tulajdonságok majd a debugging és ott van a Command Arguments az oad beírt értéket tudod tesztelni...<br>

**Breakpoint beállítása a debbugoláshoz ->** 

![image-20260126202154204](E:\projects\Books\kepek\image-20260126202154204.png)

Beállítottam a `for(;;)`loop-nál a piros pötty jelzi....

![image-20260126202258908](C:\Users\AtiBexx2\AppData\Roaming\Typora\typora-user-images\image-20260126202258908.png)

 A **breakpoint** <br>

 egy "megállási pont" a kódban, ahol a **debuggolás** során a program futása megáll, hogy:

   - Megnézhesd, milyen értékek vannak a változókban
   - Láthasd, hogyan fut le a program lépésenként
   - Kideríthesd, hol van hiba, ha nem úgy működik, ahogy szeretnéd

Kattints a **windows local debbuger** vagy nyomd meg az **F5**-öt.

![image-20260126205057985](E:\projects\Books\kepek\image-20260126205057985.png)

![image-20260126205252449](E:\projects\Books\kepek\image-20260126205252449.png)

Ha tovább akarod a programot futtatni rá kell kattintanod a **Continue** gombra....

![image-20260126205350252](E:\projects\Books\kepek\image-20260126205350252.png)

![image-20260126205412622](E:\projects\Books\kepek\image-20260126205412622.png)

Már alul ki is írta miket használ a memóriacímet is kiírja...

Akár a kilépés folyamatát is tudod **debbugolni** mikor mit csinál a program...

Csak oda kell állítanod a **breakpoint**-ot és ennyi.





**Locals ablak**

   - A jelenlegi függvény scope-jában lévő változókat mutatja.
   - Minden lokális változó, amit a függvényben deklaráltál, itt jelenik meg.
   - Nem számít, hogy éppen melyik sor fut le, minden lokális változó szerepel.

  Példa:

```
 void fuggveny() {
     int a = 5;
    double b = 3.14;
    // breakpoint itt -> Locals: a = 5, b = 3.14
}
```



---

   **Autos ablak**

   - Csak azokat a változókat mutatja, amelyek a jelenlegi sorban szerepelnek.
   - A Visual Studio automatikusan kitalálja, hogy mely változók érdekesek a jelenlegi sorban.
   - Hasznos, ha csak az aktuális sorban szereplő változókat szeretnéd látni.

  Példa:

```
void fuggveny() {
      int a = 5;
     double b = 3.14;
    cout << a; // breakpoint itt -> Autos: csak a = 5 lesz benne
 }
```

Visszatérve a kódra....

`char* endptr;` - > itt az end pointernek adunk át értéket

```
std::string input;
std::getline(std::cin, input);
```

A `for(;;)` loop-ban /vagy hurokban hozzáadtuk az inputot és a `getline`-t 

`getline()` **elfogyasztja a sort és az Entert**

`cin >>` **nem fogyaszt Entert**

`getline()` után → **nem kell pufferürítés**

`cin >>` után, `getline()` előtt → **kell `ignore()`**

**A getline() előtt sose kérj be egy értéket csak utána !!!!**

```
for (;;) {
	//Most pedig bekérjük a számot (Now we ask for the number)
	std::cout << "Kérlek add meg a hőmérsékeletet Celsius fokban\n";
	std::cout << "(A kilépéshez használd az 'exit' parancsot):";
	std::string input;
	std::getline(std::cin, input);

char* endptr;
long double temp_celsius = std::strtold(input.c_str(), &endptr);

//Eredmény kiírása (Outputting the result)
if (*endptr == '\0') {
	celsius = temp_celsius;
	fahrenheit = (celsius * tenyezo) + 32;//Átváltás Fahrenheit-re (Conversion to Fahrenheit)
	std::cout << "A celsius fok amit beírtál: " << celsius << "\n";
	std::cout << "átváltva Fahrenheit-re: " << fahrenheit << " fok" << std::endl;
}
else if (input == "exit") {
	break;
}
else {
	std::cout << "Hiba: Nem számot adtál meg Kérlek számot adj meg..." << std::endl;
	//std::cin.clear();// a hibajelzés törlése
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // a rossz bemenet eltávolítása a bemeneti pufferből
```

```
long double temp_celsius = std::strtold(input.c_str(), &endptr);
```

itt kérjük be a temp_celsius _változó értékét amit  számmá konvertálunk_ 

```
char* endptr;
long double temp_celsius = std::strtold(input.c_str(), &endptr);
```

**`input.c_str()`**

- a `std::string input` → **C-stílusú stringgé** alakul
- típusa: `const char*`

 **`std::strtold(...)`**

- megpróbálja a string **elejétől** kezdve
- **`long double` számmá** alakítani

 **`temp_celsius`**

- megkapja az **átalakított számot**
- pl. `"12.5"` → `12.5`

 **`endptr`**

- arra a karakterre mutat, **ahol a konvertálás megállt**



```
else if (input == "exit") {
	break;
}
```

**ha input egyenlő exit-el kilépünk a ciklusból**

```
int main(int argc, char* argv[])
{
	long double celsius = 0.0;
	long double tenyezo = 9.0 / 5.0; // vagy 1.8 is lehetne (or it could be 1.8)
	long double fahrenheit = 0.0;
	//Bemenet olvasása (Reading input)
	std::string input;
```

Felül a `long double tenyezo` höz hozzá adtuk az értékeket. -> **`long double tenyezo = 9.0 / 5.0`;** <br>**`long double fahrenheit = 0.0;`** -> **inicializáltuk a váltózoinkat**

```
	// Számítás elvégzése az argumentum esetén is
	//Átváltás Fahrenheit-re (Conversion to Fahrenheit)
	fahrenheit = (celsius * tenyezo) + 32;

	//Eredmény kiírása (Outputting the result)
	std::cout << "A celsius fok amit beírtál: " << celsius << "\n";
	std::cout << "átváltva Fahrenheit-re: " << fahrenheit << " fok" << std::endl;
}
```

És áthelyeztük az Argumentumhoz is a számítást és kiírást....

Nézzd át a kódot mi változott.....<br>

```
# include <iostream>
# include <cstdio>
# include<cstdlib>
# include<limits>
# include <string>

int main(int argc, char* argv[])
{
	long double celsius = 0.0;
	long double tenyezo = 9.0 / 5.0; // vagy 1.8 is lehetne (or it could be 1.8)
	long double fahrenheit = 0.0;
	//Bemenet olvasása (Reading input)
	std::string input;
	//std::getline(cin, input);


	if (argc > 1) {
		// Argumentum alapján próbáljuk olvasni a bemenetet
		std::string input = argv[1];
		char* endptr;
		celsius = std::strtold(input.c_str(), &endptr);

		// Ellenőrizzük, hogy sikerült-e számmá alakítani
		if (*endptr != '\0') {
			std::cout << "Hiba: Nem érvényes számot adtál meg." << std::endl;
			return 1;
		}
		// Számítás elvégzése az argumentum esetén is
		//Átváltás Fahrenheit-re (Conversion to Fahrenheit)
		fahrenheit = (celsius * tenyezo) + 32;

		//Eredmény kiírása (Outputting the result)
		std::cout << "A celsius fok amit beírtál: " << celsius << "\n";
		std::cout << "átváltva Fahrenheit-re: " << fahrenheit << " fok" << std::endl;
	}
	else { //Interaktív mód
		for (;;) {
			//Most pedig bekérjük a számot (Now we ask for the number)
			std::cout << "Kérlek add meg a hőmérsékeletet Celsius fokban\n";
			std::cout << "(A kilépéshez használd az 'exit' parancsot):";
			std::string input;
			std::getline(std::cin, input);

			char* endptr;
			long double temp_celsius = std::strtold(input.c_str(), &endptr);

			//Eredmény kiírása (Outputting the result)
			if (*endptr == '\0') {
				celsius = temp_celsius;
				fahrenheit = (celsius * tenyezo) + 32;//Átváltás Fahrenheit-re (Conversion to Fahrenheit)
				std::cout << "A celsius fok amit beírtál: " << celsius << "\n";
				std::cout << "átváltva Fahrenheit-re: " << fahrenheit << " fok" << std::endl;
			}
			else if (input == "exit") {
				break;
			}
			else {
				std::cout << "Hiba: Nem számot adtál meg Kérlek számot adj meg..." << std::endl;
				//std::cin.clear();// a hibajelzés törlése
				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // a rossz bemenet eltávolítása a bemeneti pufferből
			}
		}
	}

	//Kilépés elött (Exit)
	//Várunk amíg a felhasználó megnyom egy gombot (We wait until the user presses a key)
	if (argc == 1) {

		std::cout << "Nyomd meg az ENTERT a kilépéshez...";
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//std::cin.ignore(10,'\n' );

		std::cin.get();
		return 0;
	}
}
```



-----------------------EOF----------------------------------------------------------------------------------------



**Régi kód egy tankönyvi példa alapján:**

```
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(int nArgSzama, char* mszArg[])
{
	// a hőmérséklet megadása Celsius-fokban
	int celsius;
	cout << "Add meg a hőmérsékletet Celsius-fokban:";
	cin >> celsius;

	// A Celsius és Fahrenheit közötti konverziós
	// tényező kiszámítása
	int tenyezo;
	tenyezo = 212 - 32;

    // A konverziós tényező használata a Celsius-értékek
	// átváltásához Fahrenheitre
	int fahrenheit;
	fahrenheit = tenyezo * celsius/100 + 32;
	// az eredmények (majd egy sortörés) kiírása
	cout << "A Fahrenheit-érték:";
	cout << fahrenheit << endl;
	// várakozás a program leállításával, amíg a felhasználó készen áll,
	// hogy a felhasználó láthassa a program eredményeit
	cout << "A folytatáshoz nyomd meg az Entert..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}
```





