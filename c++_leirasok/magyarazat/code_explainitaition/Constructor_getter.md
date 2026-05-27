```
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

```

Ebben az esetben teljesen lehetne `private` is, sőt általában ez a jobb megoldás.

Mert most az adatokat csak gettereken keresztül éred el:

```cpp
getSemestersHours()
getAcademicAvarage()
```

Tehát nincs szükség arra, hogy leszármazott class közvetlenül hozzáférjen.

Így általában inkább:

```cpp
private:
    int semestersHours;
    double academicAvarage;
```

A `protected` akkor hasznos, ha öröklődésnél akarod használni a változókat közvetlenül.

Példa:

```cpp
class UniversityStudent : public Student
{
public:
    void test()
    {
        semestersHours = 5;
    }
};
```

Ez csak `protected` esetén működik.

A mostani kódod viszont már nagyon jó alap OOP szempontból:

- konstruktor 
- getter 
- stack objektum 
- heap objektum 
- `new` / `delete` 
- pointer használat 
- `->` operátor ✔

Egy apró modern C++ megjegyzés:

```cpp
Student* mS = new Student;
```

ma már gyakran inkább:

```cpp
Student* mS = new Student();
```

vagy modernebben smart pointer:

```cpp
std::unique_ptr<Student> mS = std::make_unique<Student>();
```

