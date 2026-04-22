#ifndef OVERLOAD_H
#define OVERLOAD_H

class Tanulo
{
    private:
    double tanulmanyiAtlag = 0;
    
    public:
    double osztalyzat();    
    double osztalyzat(double ujTanulmanyAtlag);
};

class Osztalyozas 
{
    public:
    double osztalyzat(double atlag) const;
    const char* jegy(double ertek);
};



#endif