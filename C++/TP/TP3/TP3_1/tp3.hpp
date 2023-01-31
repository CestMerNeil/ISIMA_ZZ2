#ifndef _tp3
#define _tp3

#include <iostream>
#include <cstdlib>

class Bavarde;
class Couple;

class Bavarde {
    int _x;

    public:
    void setX(int xInput);
    int getX();
    void afficher();
    
    Bavarde();
    Bavarde(int x);
    ~Bavarde();
};

class Couple {
    public:
    Bavarde coupleA;
    Bavarde coupleB;
    Couple(int a, int b);
};

class Famille {
    public:
    Bavarde test[10];
};

#endif