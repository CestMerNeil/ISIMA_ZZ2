/*
 * @author Ao XIE
 * @date 2023.02.08 
 */


#include "Pile.hpp"

Pile::Pile(int num){
    if(num<=0){
        throw std::invalid_argument("ERROR!!! In Pile.");
    }
    else {
        this->taille = num;
        this->actu = 0;
    }

}
Pile::Pile(){
    this->taille = 10;
    this->actu = 0;
}

const int & Pile::top() const {
    return info[actu-1];
}

void Pile::pop(){
    actu --;
}

void Pile::push(const int & element){
    info[actu] = element;
    actu ++;
}

bool Pile::empty() const {
    bool state = true;
    if (actu != 0) state = false;
    return state;
}

int Pile::size() const {
    return actu;
}
