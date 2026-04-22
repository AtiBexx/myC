# For ciklus

**Pointerel**

```
#include <cstdio>
#include<cstdlib>
#include<iostream>

void arrayPrinting(int array[], int arraySize);

int main (int argc, char* argv[]) {

    int array[]= {4,3,2,1};
    arrayPrinting(array, 4 );

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg az ENTER billentyüt"<< std::endl;
    std::cin.get();
    return 0;

}

void arrayPrinting(int array[], int arraySize) {

    std::cout <<"A tömb értékei:\n";
    int* pArray = array;
    for (size_t i = 0; i < arraySize; i++, pArray++)
    {
      std::cout << i << ": " << *pArray << "\n";  
    }
    std:: cout << std::endl;
}
```

**nélküle**

```
#include <cstdio>
#include<cstdlib>
#include<iostream>

void arrayPrinting(int array[], int arraySize);

int main (int argc, char* argv[]) {

    int array[]= {4,3,2,1};
    arrayPrinting(array, 4 );

    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg az ENTER billentyüt"<< std::endl;
    std::cin.get();
    return 0;

}

void arrayPrinting(int array[], int arraySize) {

    std::cout <<"A tömb értékei:\n";
    //int* pArray = array;
    for (size_t i = 0; i < arraySize; i++)
    {
      std::cout << i << ": " << array[i] << "\n";  
    }
    std:: cout << std::endl;
}
```

`size_t` előjel nélküli, így nem lehet véletlenül negatív index.

Ha negatív értéket akarsz visszaadni akkor `int` vagy `long`/`long long`

Ez magyarul:

```
#include<cstdio>
#include<cstdlib>
#include<iostream>

//ptotótípusDeklaráció
void tombKiirasa(int Tomb[], int tombMerete);
void tombKiirasa2(int Tomb[], int tombMerete);

int main(int argc, char* argv[]) {

    int tomb[]= {4,3,2,1};
    tombKiirasa(tomb, 4);
    std::cout <<"\n"; //1 új sor
    std::cout <<"Második tömb:\n";
    tombKiirasa2(tomb, 4);


    //kilépünk
    std::cout <<"A folytatáshoz kérlek nyomd meg az ENTER billentyú"<< std::endl;
    //std::cin.ignore(10, '\n');
    std::cin.get();
    return 0;
}

void tombKiirasa(int Tomb[], int tombMerete) {
    std::cout <<"A tömb értékei:\n";
 for (int i = 0; i < tombMerete; i++) {
    std::cout << i << ": " << Tomb[i] << "\n";  
 }
 std:: cout << std::endl;
}

void tombKiirasa2(int Tomb[], int tombMerete) {
    std::cout <<"A tömb értékei:\n";
    int* pTomb = Tomb;
 for (int i = 0; i < tombMerete; i++, pTomb++) {
    std::cout << i << ": " << *pTomb << "\n";  
 }
 std:: cout << std::endl;
}
```



------

###  Mi az a memória?

A számítógép memóriája (RAM) **egy hatalmas sor kis rekeszből**, mindegyik rekesznek van **címe**:

```
Cím:   1000  1004  1008  1012
Érték:   4     3     2     1
```

- A fenti példában a `tomb[] = {4,3,2,1}` négy **egész számot** tárol.
- A **címek** (1000, 1004, …) megmutatják, hol van az adott szám a memóriában.

------

###  Mi történik a pointerrel?

- Egy **pointer** **magában egy szám**: az a cím, ahol az adat van.
- Például:

```cpp
int tomb[] = {4,3,2,1};
int* p = tomb;  // a p most a tömb első elemének címét tárolja
```

- `p` **nem az érték**, csak a cím: pl. `p = 1000` (memóriacímet mutat).
- Ha szeretnénk az értéket, **dereferáljuk**: `*p` → 4

```cpp
std::cout << p << "\n";   // 1000 (cím)
std::cout << *p << "\n";  // 4 (érték)
```

- Ha `p++` → a pointer a következő elem címére ugrik: 1004, és `*p` már 3-at mutat.

------

###  Miért lehet hasznos?

- Ha nem tudod előre a tömb hosszát vagy dinamikus tömböt használsz (`new`), **csak a címre tudsz hivatkozni**, nem a névre:

```cpp
int* tomb = new int[4]{4,3,2,1};
int* p = tomb;
while (p != tomb+4) {
    std::cout << *p << "\n";  // léptetjük a pointert
    p++;
}
```

- Itt **csak a pointerrel tudunk lépegetni**, indexelni nem feltétlenül.

------

###  Ha nem pointer

- Lokális tömbnél elég az `array[i]`:

```cpp
for (int i=0; i<4; i++)
    std::cout << tomb[i] << "\n";
```

- Itt a **fordító automatikusan kezeli**, hogy melyik memóriacímen van az `i`-edik elem.

------

 Röviden:

- **Pointer = cím**
- **Dereferálás (\*p) = cím által mutatott érték**
- **Indexelés (array[i]) = pointer + offset, automatikusan dereferálva**

------

