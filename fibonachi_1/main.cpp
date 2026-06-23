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
