#ifndef PILE_H
#define PILE_H

#include <iostream>

class Pile {
    private:
    int taille;
    int actu;
    int * info;

    public:
    Pile(int num);
    Pile();

    const int & top() const;
    void pop();
    void push( const int & element);
    bool empty() const;
    int size() const;
};

#endif