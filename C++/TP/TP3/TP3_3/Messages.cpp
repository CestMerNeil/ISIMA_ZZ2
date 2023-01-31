//
// Created by Ao XIE on 26/01/2023.
//

#include "Messages.hpp"

/***************** A ******************/
void A::send(B *b) {
    b->exec(_i);
}

void A::exec(int i) {
    _i = i;
}

void A::display() {
    std::cout << _i << std::endl;
}

/***************** B ******************/
void B::send(A *a) {
    a->exec(_j);
}

void B::exec(int j) {
    _j = j;
}

void B::display() {
    std::cout << _j << std::endl;
}