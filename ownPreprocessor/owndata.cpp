#include "owndata.h"
#include <cmath>

double own_sin (double x)
{
    return std::sin(x);
}

double own_cosin (double x)
{
    return std::cos(x);
}

double own_tan (double x)
{
    return std::tan(x);
}

/*
Mi a kapszulázás?
Egyszerűen:
Adatok + működés egy "dobozba" zárása, és elrejtése a külvilág elől.
Vagy még egyszerűbben:
Csak azt látod amit kell, a többi rejtve van.

private == Csak az osztály saját tagjai férhetnek hozzá.
protected == Olyan, mint a private, de a leszármazott osztályok is hozzáférhetnek. Külső kód nem látja, csak az öröklődő osztály.
public == Mindenki hozzáférhet az adott változóhoz/funkcióhoz bárhonnan.

Interface == MIT tudsz hívni
Encapsulation == MIT nem láthatsz
*/