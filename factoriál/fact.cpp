#include<cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
    using namespace std;

    // PrototypeDeclaration
    void explanation(void); void exiting(int); void menu(void);
    unsigned long long factorial(unsigned long long);
    void factorialOutput(unsigned long long);

    int main(int argc, char *argv[]) {
      if (argc == 1) {
        menu();
      } else if(argc == 2) {
        unsigned long long n;
        stringstream ss(argv[1]);
        if (!(ss >> n)) {
            cout << "Hiba: nem ervenyes szamot adtal meg!" << endl;
            return 1;
        } else {
            cout << n << "! = " << factorial(n) << endl;
            return 0;
        }
      } else
      {
        cout << "Tul sok parameter!" << endl;
        cout << "Tul sok számot adtál meg csak egy számot adj meg!" << endl;
      }
    }

    void explanation(void) {
      cout << "Ez a program kiszámítja egy pozitív egész szám faktoriálisát."
           << endl;
      cout << "A kilépéshez használd az 'Exit' parancsot." << endl;
      cout << "A képernyő törléséhez pedig használd a 'cls' parancsot.\n"
           << endl;

      cout << "A menübe való visszalépéshez nyomd meg az ENTER-t." << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();
    } void exiting(int) {
      cout << "A Kilépeshez kérlek nyomd meg az enter-t......" << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();
      exit(0);
    } void factorialOutput() {
      for (;;) {
        string input;
        unsigned long long n;
        cout << "A kilépéshez használd az 'Exit' parancsot." << endl;
        cout << "A képernyő törléséhez pedig használd a 'cls' parancsot."
             << endl;
        cout << "Adj meg egy pozitiv egész számot: ";
        getline(cin, input);

        if (input == "exit" || input == "EXIT" || input == "Exit") {
          menu();
          return;
        } else if (input == "cls") {
          cout << "\x1B[2J\x1B[H";
          continue;
        }
        // ha nem szám
        long long temp;
        stringstream ss(input);
        if (!(ss >> temp) || temp < 0) {
          cout << "Nem számot adtál meg" << endl;
          cout << "Vagy ha igen akkor negatívat" << endl;
          cout << "Kérlek csak spozitiv egész számot adj meg !!!\n" << endl;
          continue; // újra a ciklus eleje
        } else {
          unsigned long long n = temp;
          cout << "A megadott szám kaktoriális értéke:" << endl;
          cout << n << "! = " << factorial(n) << endl;
        }
      }
    } unsigned long long factorial(unsigned long long n) {
      if (n > 20)
      {
        cerr << "Túlcsordulás 20-nál ne írj nagyobbat" << endl;
        cout << "Maximum 20-at adhatsz meg1!" << endl;
        //return 1;
        return EXIT_FAILURE;
      }  
      unsigned long long fact = 1;
      for (int i = 1; i <= n; i++) {
        fact *= i;
      }
      return fact;
    } void menu(void) {
      while (true) {
        int value;
        cout << "===== MENU =====" << endl;
        cout << "1 - Faktorialis szamitas" << endl;
        cout << "2 - Magyarazat" << endl;
        cout << "3 - Kilepes" << endl;

        cout << "választás: ";
        cin >> value;
        if (cin.fail())
        /*if (!(cin >> value))*/
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Nem számot adtál meg!" << endl;
          cout << "Kérlek add meg újra a megadott szamot 1-3-ig....." << endl;
          continue; // vissza a menübe
        }

        switch (value) {

        case 1:
          factorialOutput();
          break;

        case 2:
          explanation();
          break;

        case 3:
          exiting(0);
          break;

        default:
          if (value > 3 || value < 1) {
            cout << "A megadott szam nem megfelelo" << endl;
            cout << "Kérlek add meg újra a megadott szamot 1-3-ig....." << endl;
            continue; // újra a ciklus eleje
          }
        }
      }
    }