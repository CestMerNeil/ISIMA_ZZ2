#include "Chaine.hpp"
#include <cstring>
#include <sstream>

/****************** Constructors *********************/
Chaine::Chaine() {
    _capacite = -1;
    tab = nullptr;
}

Chaine::Chaine(char value) {
    _capacite = -1;
    tab = nullptr;
}

Chaine::Chaine(char * value) {
    tab = reinterpret_cast<const std::ostream *>(*value);
    _capacite = sizeof(value);
}

Chaine::Chaine(int capacite) {
    _capacite = capacite;
    tab = nullptr;
}

int Chaine::getCapacite() const {
    return _capacite;
}
/*
char * Chaine::c_str() const {
    //return tab;
}

void Chaine::afficher() {}

void Chaine::afficher(std::ostream ss) {
    ss = * tab;
}

*/


