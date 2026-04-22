#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>

int main(int argc, char* argv[]) {

    std::string name;
    int age = 0;

    //kiírjuk az argumentomukat for ciklusal
    for(int i= 0; i < argc; i++)
    {
        std::string arg = argv[i];

        if (arg == "-name" && i + 1 < argc)
        {
            name = argv[i + 1];
            i++;
        }
        else if (arg == "-age" && i +1 <argc)
        {
            age = std::stoi(argv[i + 1]);
            i++;
        }
    }
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;

    return 0;

}