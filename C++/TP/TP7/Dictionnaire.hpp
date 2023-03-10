#ifndef Dictionnaire_H
#define Dictionnaire_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>


class Dictionnaire {
    private:
    std::string _mot;
    int _numMots;
    public:
    Dictionnaire();
    ~Dictionnaire();

    void ajouterMot(const std::string & inMot);
    void retirerMot(const std::string & inMot);
    int getNbMots() const;
    std::string recherMots(const std::string & inMot);
};

class ListeMotsTries : public Dictionnaire {
    private:

    public:
    //void inserer(const const_iterator & inDebut, const const_iterator & inFin);
/*     const_iterator<T> debut() const;
    const_iterator fin() const;
 */
};

#endif