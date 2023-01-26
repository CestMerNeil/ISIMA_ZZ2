#include "Chaine.hpp"
#include <cstring>

/****************** Chaine *********************/
Chaine::Chaine() {
    _capacite = -1;
    tab = nullptr;
}
int Chaine::getCapacite() {
    return _capacite;
}

int Chaine::c_str() {
    return *tab;
}