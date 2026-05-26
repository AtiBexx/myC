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

**Exit_Parancsal** ->

```c++
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

**Tankönyvi példa:**

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

