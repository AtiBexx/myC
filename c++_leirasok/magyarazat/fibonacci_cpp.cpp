/*
 * Fibonacci számok kiszámítása C++ nyelven
 *
 * A Fibonacci sorozat az a számsorozat, ahol minden szám az előző két szám összege:
 * F(0) = 0
 * F(1) = 1
 * F(n) = F(n-1) + F(n-2), ha n > 1
 *
 * A sorozat első néhány eleme: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_map>

using namespace std;

// 1. REKURZÍV MEGOLDÁS (egyszerű, de hatékonyság szempontból nem optimális nagy számokra)
// Időbonyolultság: O(2^n) - exponenciális!
long long fibonacci_recursive(int n) {
    // Alapesetek
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    // Rekurzív hívások
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// 2. DINAMIKUS PROGRAMOZÁS (memorizációval) - hatékonyabb megoldás
// Időbonyolultság: O(n), Térbeli bonyolultság: O(n)
unordered_map<int, long long> memo;

long long fibonacci_memoization(int n) {
    // Ha már kiszámoltuk az n-edik Fibonacci számot, térjünk vissza vele
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    
    // Alapesetek
    if (n <= 0) {
        return memo[n] = 0;
    }
    if (n == 1) {
        return memo[n] = 1;
    }
    
    // Rekurzív hívások, de az eredményeket eltároljuk
    return memo[n] = fibonacci_memoization(n - 1) + fibonacci_memoization(n - 2);
}

// 3. ITERATÍV MEGOLDÁS (legjobb hatékonyságú megoldás)
// Időbonyolultság: O(n), Térbeli bonyolultság: O(1)
long long fibonacci_iterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    long long prev2 = 0;  // F(n-2)
    long long prev1 = 1;  // F(n-1)
    long long current;    // F(n)
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

// 4. MÁTRIX MEGOLDÁS (nagyon hatékony nagy számokra)
// Időbonyolultság: O(log n)
long long matrix_multiply(long long F[2][2], long long M[2][2]) {
    long long x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    long long y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    long long z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    long long w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
    
    return 0;
}

void matrix_power(long long F[2][2], int n) {
    if (n == 0 || n == 1) return;
    
    long long M[2][2] = {{1, 1}, {1, 0}};
    matrix_power(F, n / 2);
    matrix_multiply(F, F);
    
    if (n % 2 != 0) {
        matrix_multiply(F, M);
    }
}

long long fibonacci_matrix(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    long long F[2][2] = {{1, 1}, {1, 0}};
    matrix_power(F, n - 1);
    
    return F[0][0];
}

// 5. FIBONACCI SOROZAT KIIRATÁSA
void print_fibonacci_sequence(int count) {
    cout << "Fibonacci sorozat első " << count << " eleme:" << endl;
    for (int i = 0; i < count; i++) {
        cout << fibonacci_iterative(i);
        if (i < count - 1) cout << ", ";
    }
    cout << endl << endl;
}

// 6. IDŐMÉRÉSI SEGÉDFÜGGVÉNY
template<typename Func>
void measure_time(Func func, int n, const string& method_name) {
    auto start = chrono::high_resolution_clock::now();
    long long result = func(n);
    auto end = chrono::high_resolution_clock::now();
    
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << method_name << "(" << n << ") = " << result << endl;
    cout << "Futtatási idő: " << duration.count() << " mikromásodperc" << endl << endl;
}

int main() {
    cout << "=== Fibonacci Számok Kiszámítása C++-ban ===" << endl << endl;
    
    int n;
    cout << "Add meg, hogy hányadik Fibonacci számot szeretnéd kiszámolni: ";
    cin >> n;
    
    cout << endl;
    
    // Sorozat kiírása az n-edik számig
    if (n >= 0 && n <= 20) {  // Csak kisebb számokra, mert a rekurzív verzió lassú
        print_fibonacci_sequence(n + 1);
    }
    
    cout << "=== Különböző módszerek összehasonlítása ===" << endl;
    
    // Iteratív megoldás (ajánlott a legtöbb esetre)
    measure_time(fibonacci_iterative, n, "Iteratív");
    
    // Memorizációs megoldás
    memo.clear();  // Memo tábla ürítése
    measure_time(fibonacci_memoization, n, "Memorizációs");
    
    // Mátrixos megoldás (nagyon nagy számokra ajánlott)
    measure_time(fibonacci_matrix, n, "Mátrixos");
    
    // Rekurzív megoldás csak kis számokra (mert lassú)
    if (n <= 40) {
        measure_time(fibonacci_recursive, n, "Rekurzív");
    } else {
        cout << "Rekurzív megoldás kihagyva (túl lassú lenne)" << endl << endl;
    }
    
    // További példák különböző bemenetekre
    cout << "=== További példák ===" << endl;
    vector<int> examples = {0, 1, 2, 5, 10, 15, 20};
    
    for (int example : examples) {
        cout << "F(" << example << ") = " << fibonacci_iterative(example) << endl;
    }
    
    cout << endl << "Program vége." << endl;
    
    return 0;
}