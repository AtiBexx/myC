#include <iostream>
#include <cassert>
using namespace std;

// ── Fordítási idejű ellenőrzések ─────────────────
#if !defined(__cplusplus)
#error Csak C++ fordítoval fordithato!
#endif
#if __cplusplus < 201103L
#error Legalabb C++11 szukseges!
#endif

static_assert(sizeof(int) == 4, "int = 4 bajt kell!");
static_assert(__cplusplus >= 201103L, "C++11+ kell!");

// ── Konstansok constexpr-rel ──────────────────────
constexpr int MAX_N = 20;
static_assert(MAX_N > 0, "MAX_N pozitiv legyen!");

// ── enum class a visszatérési státuszhoz ──────────
enum class Status { OK = 0, HIBA = 1 };

// ── Faktoriális assert-tel védve ──────────────────
long long faktorial(int N) {
    assert(N >= 0);
    assert(N <= MAX_N);
    if (N <= 1) return 1;
    return N * faktorial(N - 1);
}

// ── Debug log makró: FILE + LINE + func együtt ────
#define DLOG(msg) \
    cout << "[LOG][" << __func__ << "][" \
         << __FILE__ << ":" << __LINE__ << "] " \
         << msg << endl

int main() {
    cout << "╔══════════════════════════════════════╗" << endl;
    cout << "║  Összefoglaló C++ program            ║" << endl;
    cout << "║  Build: " << __DATE__ << " " << __TIME__ << "  ║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;
    cout << endl;

    // Belső makrók kiírása
    cout << "Fájl:      " << __FILE__    << endl;
    cout << "Függvény:  " << __func__    << endl;
    cout << "C++ verzió:" << __cplusplus << endl;
    cout << endl;

    DLOG("Program indul");

    // Faktoriális táblázat
    cout << "N\t N!" << endl;
    for (int i = 0; i <= 10; ++i)
        cout << i << "!\t= " << faktorial(i) << endl;

    cout << endl;
    int szam;
    cout << "Adj meg egy számot (0-20): ";
    cin >> szam; cin.ignore();

    if (szam < 0 || szam > MAX_N) {
        DLOG("Érvénytelen bemenet!");
        cout << "Hiba: 0 és 20 közé essen!" << endl;
    } else {
        cout << szam << "! = " << faktorial(szam) << endl;
        DLOG("Számítás kész");
    }

    cout << endl;
    cout << "A kilépéshez kérlek nyomd meg az Entert..." << endl;
    cin.get();
    return EXIT_SUCCESS;
}