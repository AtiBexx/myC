//AdatfolyamKimenet
//egyszerű írás egy fájlba
//
#include <fstream>

int main(int agrc, char** argv)
{
    std::ofstream nevem("nevem.txt");
    nevem << "Atti_c" <<'\n'
    << "test" << std::endl;


    return 0;
}
/*
#include <fstream>

int main(int argc, char** argv)
{
    std::ofstream nevem("nevem.txt");

    nevem << "Atti_c" << '\n';
    nevem << "test" << std::endl;

    return 0;
}
*/
