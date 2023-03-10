#ifndef MOTTRIES_H
#define MOTTRIES_H
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <string>


class ListeMotsTries {
    protected:
    std::list<std::string> list;
    public:
    int numList = 0;
    using const_iterator = typename std::list<std::string>::const_iterator;
    ListeMotsTries();
    ~ListeMotsTries();

    int getNbMots() const;
    void ajouterMot(const std::string & inMot);
    void enleverMot(const std::string & outMot);
    const_iterator debut() const;
    const_iterator fin() const;
};

#endif