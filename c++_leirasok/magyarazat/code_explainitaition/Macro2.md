# Makro 2 c++

| Makró (magyar)                  | Típus         | Mit ad vissza?                                               |
| :------------------------------ | :------------ | :----------------------------------------------------------- |
| `__FILE__` (__FÁJL__)           | `const char*` | A forrásfájl neve (pl. `"main.cpp"`)                         |
| `__LINE__` (__SOR__)            | `const int`   | Az aktuális sor száma a kódban                               |
| `__func__` (__függvény__)       | `const char*` | Az aktuális függvény neve (C++11 óta)                        |
| `__DATE__` (__DÁTUM__)          | `const char*` | Fordítás dátuma (pl. `"Mar 14 2026"`)                        |
| `__TIME__` (__IDŐ__)            | `const char*` | Fordítás időpontja (pl. `"13:45:02"`)                        |
| `__TIMESTAMP__` (__IDŐBÉLYEG__) | `const char*` | Fordítás dátuma + ideje együtt                               |
| `__STDC__`                      | `int`         | 1, ha a fordító megfelel a C++ szabványnak                   |
| `__cplusplus`                   | `int`         | 1, ha C++ fordítóprogram (nem C). Ezzel megkülönböztetheted a C és C++ kódot. |

Ezeket a makrókat a C++ **előre definiálja** – te nem hozod létre, a fordítóprogram töl ti ki automatikusan fordításkor. Az aláhúzásjelek (`__`) jelzik, hogy belső / fenntartott névről van szó.

me a 4 fül tartalma röviden:

**1. Belső makrók táblázat** — a könyvből az összes előre definiált konstans: `__FILE__`, `__LINE__`, `__func__`, `__DATE__`, `__TIME__`, `__TIMESTAMP__`, `__STDC__`, `__cplusplus` — mindegyiknek típusa és jelentése.

**2. Makró példakód** — egy kis program ami kiírja az összes belső makró értékét, pl. melyik fájlban, melyik sorban, mikor fordítottuk, milyen C++ szabvány.

**3. Faktoriális (teljes)** — **kétféle** megoldás egyszerre: rekurzív (önmagát hívja) + iteratív (for ciklussal). Táblázatot ír 0!-tól 12!-ig, aztán bekér egy számot a felhasználótól. `assert()` véd a negatív bemenettől.

**4. #error / assert / static_assert** — a könyvből a három hibakezelési módszer egy programban: fordítási idejű hiba, fordítási idejű feltétel, futási idejű feltétel.

**példa**:

```
#include <iostream>
#include <cstdlib>
#include <cstdio>

void info() {
    std::cout << "----- Fordítási információk -----" << std:: endl;
    std:: cout << "Fájl:     " << __FILE__ << std::endl;
    std::cout << "Sor:   " << __LINE__ << std::endl;
    std::cout << "Dátum:     " << __DATE__ << std::endl;
    std::cout << "Időpont:   " << __TIME__ << std::endl;
    std::cout << "Verzió:    " << __VERSION__ << std::endl;
    std::cout << "Függvény:     " << __func__ << std::endl;
    std::cout << "C++ verzió:    " << __cplusplus << std::endl;

}
//Prototypedeclaration
void info();

int main(int argc, char* argv[]) {
    info();
    std::cout << "----- Mainszöveg -----\n" << std::endl;
    std:: cout << "Most a " << __FILE__ << "   -fájl sorban vagyunk." << std::endl;
    std:: cout << "Most a " << __LINE__ << "   -'LINE' sorban vagyunk." << std::endl;
    std:: cout << "Most a " << __DATE__ << "   -DÁTUM sorban vagyunk." << std::endl;
    std:: cout << "Most az " << __TIME__ << "  -IDŐsorban vagyunk." << std::endl;
    std:: cout << "Most a " << __VERSION__ << "   -verzió sorban vagyunk." << std::endl;
    std:: cout << "Most a " << __func__ << "   -függvény sorban vagyunk." << std::endl;
    std:: cout << "Most a " << __cplusplus << "   -C++ verzió sorban vagyunk." << std::endl;

    std::cout <<"A folytatáshoz kérlek nyomd meg az enter-t! " << std::endl;
    std::cin.get();

    return EXIT_SUCCESS;
}
```

**output:**

```
----- Fordítási információk -----
Fájl:     macro2.cpp
Sor:   8
Dátum:     Mar 15 2026
Időpont:   23:20:32
Verzió:    15.1.0
Függvény:     info
C++ verzió:    201703
----- Mainszöveg -----

Most a  macro2.cpp   -fájl sorban vagyunk.
Most a 23   -'LINE' sorban vagyunk.
Most a Mar 15 2026   -DÁTUM sorban vagyunk.
Most az 23:20:32  -IDŐsorban vagyunk.
Most a 15.1.0   -verzió sorban vagyunk.
Most a main   -függvény sorban vagyunk.
Most a 201703   -C++ verzió sorban vagyunk.
A folytatáshoz kérlek nyomd meg az enter-t!
```

