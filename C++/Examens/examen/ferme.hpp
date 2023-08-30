#ifndef ferme__hpp
#define ferme__hpp

#include <iostream>
#include <string>
#include <ostream>
#include <exception>

class Produit {
    private :
        std::string nom;

    public :
        Produit(std::string nom) : nom(nom) {}
        std::string getNom() const { return nom; }
        bool isEqual(Produit p) const { return nom == p.nom; }
        bool operator==(Produit p) const { return isEqual(p); }
        friend std::ostream& operator<<(std::ostream& os, const Produit& produit) 
        {
            os << produit.nom;
            return os;
        }

};

class PeutPasProduireException : public std::exception {
    public :
        virtual const char * what() const throw() {
            return "peut_pas_produire";
        }
};

#endif
