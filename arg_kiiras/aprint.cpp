#include<cstdio>
#include<cstdlib>
#include<iostream>

int main(int argc, char* argv[]) {

    //int x;
    //int* ptr = &x;
    int* ptr = new int;
    *ptr = 10;
    std:: cout << *ptr << std::endl;
    delete ptr;
    ptr = nullptr;

    return 0;
}