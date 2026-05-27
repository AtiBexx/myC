// Konstruktor példa ami konstruktort hív meg
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

class Student
{
public:
    Student()
    {
        std::cout <<"The structure of the student" <<"\n";
        semestersHours = 2;
        academicAvarage = 3.0;
    }
    int getSemestersHours()
    {
        return semestersHours;
    }
    double getAcademicAvarage()
    {
        return academicAvarage;
    }

protected:
    int semestersHours;
    double academicAvarage;
};

int main(int argc, char** argv)
{
    std::cout << "New Student object create" << "\n";
    Student s;
    std::cout <<"[STACK]valueOne:"<<s.getSemestersHours() <<"\n[STACK]valueTwo: " <<s.getAcademicAvarage()<< "\n\n";

    std::cout <<"New Object create in heap memory"<<"\n";
    Student* mS = new Student();
    std::cout <<"[HEAP]valueOne:"<< mS->getSemestersHours() <<"\n[HEAP]valueTwo: " <<mS->getAcademicAvarage()<< "\n";
    std::cout <<"Deleting Pointer..."<<"\n";
    delete mS;
    std::cout<<'\n';
    //Exiting
    std::cout<<"Please press Enter twice to countinue..."<< std::endl;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}
