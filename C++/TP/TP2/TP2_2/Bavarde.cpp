#include <iostream>

class Bavarde {
    int x;

    public:
    void setX(int xInput);
    int getX();
    
    Bavarde(void);
    Bavarde(int x);
} bizarre(1);  

Bavarde globale(2);

void fonction(Bavarde b) {
  std::cout << "code de la fonction";
}

void Bavarde::setX(int xInput){
  x = xInput;
}

int Bavarde::getX(){
  return x;
}

Bavarde::Bavarde(void){};
Bavarde::Bavarde(int x){
    x = x;
}
Bavarde::~Bavarde() {
  std::cout << "Tais-toi " << std::endl;
}  


int main(int, char **) {
  Bavarde b1(3);
  Bavarde b2(4);
  Bavarde * p = new Bavarde(5);
  // fonction(b1);
  
  return 0;
}
