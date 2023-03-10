#include "ListeMotsTries.hpp"

ListeMotsTries::ListeMotsTries(){}
ListeMotsTries::~ListeMotsTries(){}

int ListeMotsTries::getNbMots() const {
    return numList;
}

void ListeMotsTries::ajouterMot(const std::string & inMot) {
    ListeMotsTries::const_iterator i = list.begin();
    while((i != list.end()||(inMot < *i))){
        list.insert(i, inMot);
        i++;
    }
    numList += 1;

}

void ListeMotsTries::enleverMot(const std::string & outMot) {
    list.remove(outMot);
    numList -= 1;
}

ListeMotsTries::const_iterator ListeMotsTries::debut() const{
    return list.begin();
}

ListeMotsTries::const_iterator ListeMotsTries::fin() const {
    return list.end();
}

