#ifndef OWNDATA_H
#define OWNDATA_H
//vagy c++17-óta pragma once 
double own_sin (double x);
double own_cosin (double x);
double own_tan (double x);

#endif // OWNDATA_H
/*
Interface == A program azon része amit más kód használhat.
Interfész = amit egy kód kifelé mutat magából.
Nem az hogyan működik,
hanem hogyan lehet használni.
*/

/*
#ifndef
Jelentése: “if not defined”, azaz „ha nincs definiálva”.
Azt ellenőrzi, hogy egy makró már létezik-e.
Ha még nincs definiálva, akkor a következő kódot engedi be.
header guard-ként használják, hogy egyszer csak legyen 
beolvasva a header fájl, még ha többször is includelnék.
*/

/*
#define
Jelentése: definiál egy makrót.
Itt azt mondjuk: „most már definiáltam az OWNDATA_H-t”.
így ha később valahol újra include-oljuk ezt a header-t, 
az #ifndef OWNDATA_H hamis lesz, és a kód nem kerül újra beolvasásra.
Ez megakadályozza a többszörös definíció miatti hibákat.
*/

/*
#endif az if/else-szerű direktívák “lezáró kulcsa” a C++ preprocessorban.
Minden #ifndef, #ifdef vagy #if blokkot le kell zárni #endif-tel.
Jelezze a fordítónak: „itt ér véget az ellenőrzés, mostantól újra normál kód következik”.
*/

/*
A #pragma once a C++-ban egy modern, egyszerűsített alternatívája a header guard-nek 
(#ifndef … #define … #endif)

#pragma once   // elég egyszer írni a fájl elejére

double own_sin(double x);
double own_cosin(double x);
double own_tan(double x);
*/