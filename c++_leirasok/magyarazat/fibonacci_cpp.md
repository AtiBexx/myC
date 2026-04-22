# Fibonacci Számok C++-ban

## Bevezetés

A Fibonacci-sorozat egy matematikai sorozat, ahol minden szám az előző két szám összege. A sorozat így kezdődik:

**0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...**

A definíció:
- F(0) = 0
- F(1) = 1
- F(n) = F(n-1) + F(n-2), ha n > 1

## C++ Implementációk

### 1. Rekurzív megoldás

Ez az intuitív megközelítés közvetlenül követi a matematikai definíciót:

```cpp
long long fibonacci_recursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}
```

**Előnyök:**
- Egyszerű és könnyen érthető
- Közvetlenül tükrözi a matematikai definíciót

**Hátrányok:**
- Exponenciális időbonyolultság: O(2^n)
- Rengeteg ismételt számítás történik

### 2. Memorizációs megoldás (Dinamikus programozás)

Ez a módszer elkerüli az ismételt számításokat egy tároló segítségével:

```cpp
#include <unordered_map>
std::unordered_map<int, long long> memo;

long long fibonacci_memoization(int n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    
    if (n <= 0) return memo[n] = 0;
    if (n == 1) return memo[n] = 1;
    
    return memo[n] = fibonacci_memoization(n - 1) + fibonacci_memoization(n - 2);
}
```

**Előnyök:**
- Lineáris időbonyolultság: O(n)
- Hatékonyabb, mint a tisztán rekurzív megoldás

**Hátrányok:**
- Lineáris térhasználat: O(n)
- Rekurzív hívási verem használata

### 3. Iteratív megoldás

Ez a legjobb teljesítményű megoldás:

```cpp
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
```

**Előnyök:**
- Lineáris időbonyolultság: O(n)
- Konstans térhasználat: O(1)
- Nincs rekurzív hívási verem

**Hátrányok:**
- Kicsit bonyolultabb megérteni, mint a rekurzív verzió

### 4. Mátrixos megoldás

A legfejlettebb módszer, logaritmikus időbonyolultsággal:

```cpp
void matrix_multiply(long long F[2][2], long long M[2][2]) {
    long long x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    long long y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    long long z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    long long w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
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
```

**Előnyök:**
- Logaritmikus időbonyolultság: O(log n)
- Kiváló nagy számokra

**Hátrányok:**
- Bonyolultabb implementáció
- Nehéz megérteni anélkül, hogy ismernénk a mátrixalgebra alapjait

## Teljes példaprogram

```cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_map>

using namespace std;

// ... (itt lennének a fenti függvények) ...

int main() {
    cout << "=== Fibonacci Számok Kiszámítása C++-ban ===" << endl;
    
    int n;
    cout << "Add meg, hogy hányadik Fibonacci számot szeretnéd kiszámolni: ";
    cin >> n;
    
    cout << "F(" << n << ") = " << fibonacci_iterative(n) << endl;
    
    return 0;
}
```

## Teljesítményösszehasonlítás

| Módszer | Időbonyolultság | Térhasználat | Legjobb használat |
|---------|----------------|--------------|-------------------|
| Rekurzív | O(2^n) | O(n) | Oktatási célokra |
| Memorizációs | O(n) | O(n) | Általános használatra |
| Iteratív | O(n) | O(1) | Legtöbb gyakorlati esetre |
| Mátrixos | O(log n) | O(log n) | Nagyon nagy számokra |

## Gyakorlati alkalmazások

A Fibonacci számok számos területen előfordulnak:

- **Matematikai modellezés**: Növényi spirálok, virágszirmok száma
- **Számítógép-tudomány**: Adatszerkezetek, algoritmusok elemzése
- **Pénzügy**: Technikai elemzés, Elliott-hullám elmélet
- **Mesterséges intelligencia**: Neurális hálózatok architektúrája

## Összefoglalás

A Fibonacci számok kiszámítására többféle módszer is létezik C++-ban, mindegyik saját előnyökkel és hátrányokkal. A választott módszer attól függ, hogy milyen méretű számokat kell kiszámolni és milyen erőforrások állnak rendelkezésre.

A legtöbb esetben az **iteratív megoldás** a legjobb választás, mivel hatékony és egyszerű implementálni.