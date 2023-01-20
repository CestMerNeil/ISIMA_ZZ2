#ifndef _fil_rouge
#define _fil_rouge

#include <iostream>
#include <string>

class Rectangle{
    int x;
    int y;
    int w;
    int h;

    public:
    Rectangle(int x, int y, int w, int h);

    std::string toString();
};

class Cercle{
    int x;
    int y;
    int w;
    int h;

    int cx;
    int cy;
    int rayon;

    public:
    Cercle(int x, int y, int w, int h);
    Cercle(int cx, int cy, int rayon);

    std::string toString(); 
};

#endif