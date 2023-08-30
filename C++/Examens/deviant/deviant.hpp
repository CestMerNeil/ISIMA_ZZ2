#ifndef __deviant_hpp__
#define __deviant_hpp__

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
// completer la liste suivant vos besoins

enum class TYPE { PERSONNE, DEVIANT };

class Personne {
    private:
    std::string nom;
    std::string prenom;

    public:
    Personne();
    Personne(std::string nom);
    std::string getNom() const;
    void setNom(std::string);
};


class Individu {
    private:
    static int container;
    int id;

    public:
    Individu();
    static int getCompteur();
    void afficher(std::ostream& ) const;
};

class Hello{
    private:
    std::string message;

    public:
    Hello();
    Hello(std::string);
    std::string getMessage() const;
    void setMessage(std::string);
};

class Bonjour{
    public:
    Bonjour();
    std::string direBonjour() const;
};


// Utiliser une des versions de Cite
// #define CITE Cite::getCite()
// extern Cite CITE;



#endif
