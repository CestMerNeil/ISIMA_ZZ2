#include "Fil_Rouge.hpp"

Rectangle::Rectangle(int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}
Cercle::Cercle(int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}
Cercle::Cercle(int cx, int cy, int rayon)
{
    this->cx = cx;
    this->cy = cy;
    this->rayon = rayon;
}

std::string Rectangle::toString(){
    std::string output = "RECTANGLE";
    output += " ";
    output += std::to_string(x);
    output += " ";
    output += std::to_string(y);
    output += " ";
    output += std::to_string(w);
    output += " ";
    output += std::to_string(h);
    return  output;
}

std::string Cercle::toString(){
    std::string output = "CERCLE";
    output += " ";
    output += std::to_string(x);
    output += " ";
    output += std::to_string(y);
    output += " ";
    output += std::to_string(w);
    output += " ";
    output += std::to_string(h);
    return  output;
}

int main(int, char **){
    Rectangle r1(10, 20, 30, 40);
    std::cout << r1.toString() << std::endl;
    Cercle c(20, 30, 40, 50);
    std::cout << c.toString() << std::endl;

    return 0;
}