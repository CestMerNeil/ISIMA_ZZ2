// Fichier Point.cpp

#include <iostream>
#include "Point.hpp"

int Point::getX(){
    return x;
}

void Point::setX(int xInput){
    x = xInput;
}

int Point::getY(){
    return y;
}

void Point::setY(int yInput){
    y = yInput;
}

/*
void Point::deplaceDe(Point p){
    x = p.x;
    y = p.y;
}
*/

void Point::deplaceVer(Point p){
    x += p.x;
    y += p.y;
}

int Point::compte(){
    compteur = x + y;
}

Point::Point(void){};
Point::Point(int xInput, int yInput){
    x = xInput;
    y = yInput;
    compteur = x + y;
}

int main(int, char **)
{
    Point p1;
    Point p2(6, 8);
    Point * p3 = new Point(1, 2);
    p1.setX(5);
    p1.setY(9);
    //p2.deplaceDe(p1);
    std::cout << p1.getX() << std::endl;
    std::cout << p2.getX() << std::endl;

    return 0;
}