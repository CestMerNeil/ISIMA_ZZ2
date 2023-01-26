#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <iostream>
#include <fstream>

class Chaine  {
private:
    int _capacite;
    int *tab;
public:
    Chaine();
    int getCapacite();
    int c_str();
};

#endif
