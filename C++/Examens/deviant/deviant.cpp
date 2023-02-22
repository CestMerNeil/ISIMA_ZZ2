#include <algorithm>

#include "deviant.hpp"

Personne::Personne(std::string nom) {
    this->nom = nom;
}

Personne::Personne() {
    this->nom = "inconnu";
    this->prenom = "inconnu";
}

std::string Personne::getNom() const {
    return nom;
}

void Personne::setNom(std::string nom) {
    this->nom = nom;
}

Individu::Individu() {
    id = container;
    ++container;
}

int Individu::getCompteur() {
    return container;
}

void afficher(std::ostream& os) {
    
}


