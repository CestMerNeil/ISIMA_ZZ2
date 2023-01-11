// Fichier Point.hpp
// Il manque les gardiens mais je vous laisse ajouter,
// c'est comme en C et le pragma once c'est nul.

#ifndef _Point
#define _Point

class Point{
    // par defaut, tout est prive dans une "class"
    int x;
    int y;
    int compteur;
    

    public:
    int getX();
    void setX(int xInput);
    int getY();
    void setY(int yInput);

    void deplaceDe(Point p);
    void deplaceVer(Point p);

    int compte();

    Point(void);
    Point(int xInput, int yInput);
};

#endif