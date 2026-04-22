#include <iostream>
#include <cassert>    // assert()-hez
using namespace std;

// ── Rekurzív faktoriális ──────────────────────────
long long faktorialis(int N) {
    assert(N >= 0);   // negatív szám esetén leállít

    if (N == 0 || N == 1)
        return 1;

    return N * faktorialis(N - 1);
}

// ── Iteratív faktoriális (ciklussal) ─────────────
long long faktorialis_iter(int N) {
    assert(N >= 0);

    long long eredmeny = 1;
    for (int i = 2; i <= N; ++i)
        eredmeny *= i;

    return eredmeny;
}

int main() {
    cout << "=== Faktoriális számító ===" << endl;
    cout << "Fordítva: " << __DATE__ << " " << __TIME__ << endl;
    cout << endl;

    // Táblázat 0!-tól 12!-ig
    cout << "N\t Rekurzív\t Iteratív" << endl;
    cout << "---\t----------\t---------" << endl;

    for (int i = 0; i <= 12; ++i) {
        cout << i << "!\t "
             << faktorialis(i)      << "\t\t "
             << faktorialis_iter(i) << endl;
    }

    cout << endl;

    // Egyedi bekérés a felhasználótól
    int szam;
    cout << "Adj meg egy számot (0-20): ";
    cin >> szam;
    cin.ignore();   // '\n' eltávolítása a bufferből

    if (szam < 0 || szam > 20) {
        cout << "Érvénytelen szám! (0-20 között kell lennie)" << endl;
    } else {
        cout << szam << "! = " << faktorialis(szam) << endl;
    }

    cout << endl;
    cout << "A kilépéshez kérlek nyomd meg az Entert..." << endl;
    cin.get();
    return EXIT_SUCCESS;
}