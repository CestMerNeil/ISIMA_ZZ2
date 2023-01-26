//
// Created by Ao XIE on 26/01/2023.
//

#include "Messages.hpp"

int main(int, char **){
    A a;
    B b;

    a.exec(99);
    b.exec(1001531);

    a.display();
    b.display();

    b.send(&a);

    a.display();
    b.display();

    a.send(&b);
    b.display();

    return 0;
}


