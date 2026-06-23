```c++
#include <iostream>


long long fib(long long n)
{
    return n<=1 ? n : fib(n-2) + fib(n-1);
}

int main(int argc, char** argv)
{
    std::cout <<"Which are fibonacci number? ";
    long long n= 0;
    std::cin >> n;
    std::cout << "Fib(" << n <<")=" << fib(n) <<"\n";
}
```

int-el (a long long-al nem fog müködni nagyon ngy szám esetén)

```c++
#include <iostream>


int fib(int n)
{
    return n<=1 ? n : fib(n-2) + fib(n-1);
}

int main(int argc, char** argv)
{
    std::cout <<"Which are fibonacci number? ";
    int n= 0;
    std::cin >> n;
    std::cout << "Fib(" << n <<")=" << fib(n) <<"\n";
}
```



ez a verzió müködik

```cpp
#include <iostream>


long long fib(int n)
{
    if(n<= 1) return n;
    long long a= 0, b =1;

    for(int i = 2; i <= n; i++)
    {
        long long c = a + b;
        a=b;
        b=c;
    }
    return b;
}

int main(int argc, char** argv)
{
    std::cout <<"Which are fibonacci number? ";
    long long n= 0;
    std::cin >> n;
    std::cout << "Fib(" << n <<")=" << fib(n) <<"\n";
}
```

Igen, nagyon közel vagy a lényeghez — csak pontosítom kicsit, hogy tiszta legyen.

##  A Fibonacci-sor lényege

A Fibonacci-sor egy számsor, ahol:

- az első két szám adott:

```text
0, 1
```

- és **minden következő szám az előző kettő összege**

------

##  Szabály

```text
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)
```

------

##  Példa lépésről lépésre

```text
F(0) = 0
F(1) = 1
```

Innen:

```text
F(2) = 1 + 0 = 1
F(3) = 1 + 1 = 2
F(4) = 2 + 1 = 3
F(5) = 3 + 2 = 5
F(6) = 5 + 3 = 8
F(7) = 8 + 5 = 13
```

------

## Tehát amit kérdeztél:

> “mindig a 2 összeg eredményével nő?”

 Igen  **mindig az előző két szám összege adja a következőt**

De fontos pontosítás:

 nem “mindig +2”-vel nő
 hanem “az előző kettő összege” szabály szerint

------

##  Intuíció (miért érdekes?)

Ez a sor azért híres, mert sok helyen megjelenik:

- növények levelei
- csigaház spirál
- természetes minták
- algoritmusok

------

##  Egy mondatban

 A Fibonacci-sor: **olyan számsor, ahol minden elem az előző két elem összege**

------

Ha akarod, meg tudom mutatni:

- hogyan néz ki grafikusan 📈
- vagy miért nő ilyen gyorsan
- vagy hol használják a programozásban (spoiler: sok helyen)

### égtelenül nagy számok

Ha tényleg tetszőlegesen nagy Fibonacci-számokat akarsz, akkor **Big Integer** (nagy egész szám) kell.

Például:

- Boost `boost::multiprecision::cpp_int`
- GMP könyvtár

Példa Boosttal:

```cpp
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

cpp_int fib(int n)
{
    cpp_int a = 0, b = 1;

    for (int i = 0; i < n; i++)
    {
        cpp_int t = a + b;
        a = b;
        b = t;
    }

    return a;
}
```

