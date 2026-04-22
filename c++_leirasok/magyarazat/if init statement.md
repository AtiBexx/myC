## If init statement-- „if inicializáló utasítás”

A C++17 ben jött be röviden lehet váltózott deklarálni az if blokban 

pl...

```c++
#include <iostream>

using namespace std;

int main()
{
    int numb = 6;
    if (int val = 6; val == numb){
        cout <<"cool This process is IF" << endl;
    } else {
    cout << numb << endl;
    cout << "This processed is ELSE" << endl;
    }
    return 0;
}
```

A lényeg ....

`if (int val = 6; val == numb){` // inicializált val  igen az if blokban inicializáltuk a változótt 

A lényeg : <br>

`if`-ben lehet **változót deklarálni**, és utána használni a feltételben. Ez a **“if init statement”**.

if inicializálás utasításban..<br>

De c++ 17 alatt nem lehet ezt így használni akkor a helyes kód így lenne....

**Snippet:**

 ```c++
int numb = 6;
int val = 6; 
/* vagy egy sorban int numb = 6 , val = 6;*/
if (val == numb){
        cout <<"cool This process is IF" << endl;
    } else {
    cout << numb << endl;
    cout << "This processed is ELSE" << endl;
 ```

