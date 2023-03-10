#include "Dictionnaire.hpp"

Dictionnaire::Dictionnaire() {
    _numMots = 0;
}
Dictionnaire::~Dictionnaire() {
    std::cout << "Bye Bye~ Dictionnaire." << std::endl;
}

void Dictionnaire::ajouterMot(const std::string & inMot){
    _mot += inMot;
    ++_numMots;
}

int Dictionnaire::getNbMots() const {
    return _numMots;
}