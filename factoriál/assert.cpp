#include <iostream>
#include <cassert>
using namespace std;

// ── #error: fordítási időben dob hibát ───────────
#if !__cplusplus || !__STDC__
#error Ez egy szabvanyos C++ program.
#endif

// ── static_assert: fordítási idejű ellenőrzés ────
static_assert(sizeof(int) >= 4,
    "Az int legalább 4 bájt kell legyen!");

// ── assert: futási idejű ellenőrzés ─────────────
int osztás(int a, int b) {
    assert(b != 0);   // nullával nem osztunk
    return a / b;
}

int main() {
    cout << "Fájl: "    << __FILE__ << endl;
    cout << "Sor: "     << __LINE__ << endl;
    cout << "Dátum: "   << __DATE__ << endl;

    cout << "10 / 2 = " << osztás(10, 2) << endl;

    // osztás(10, 0);  // ← ha ezt aktiválod, assert leáll!

    cout << "A kilépéshez kérlek nyomd meg az Entert..."
         << endl;
    cin.get();
    return EXIT_SUCCESS;
}