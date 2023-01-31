#include "tp3.hpp"
#include <iostream>

/********************* Bavarde **********************/
Bavarde globale(2);

void Bavarde::setX(int xInput){
  _x = xInput;
}

int Bavarde::getX(){
  return _x;
}

Bavarde::Bavarde(){
    _x = 0;
}

Bavarde::Bavarde(int x){
    _x = x;
}

void Bavarde::afficher(){
    std::cout << _x << std::endl;
}

Bavarde::~Bavarde() {
  std::cout << "Tais-toi " << _x << std::endl;
}


/********************* Couple **********************/
Couple::Couple(int a, int b){
  coupleA = a;
  coupleB = b;
}

/********************* Famille **********************/