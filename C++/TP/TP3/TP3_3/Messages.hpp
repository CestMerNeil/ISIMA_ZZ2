//
// Created by Ao XIE on 26/01/2023.
//

#ifndef TP_MESSAGES_HPP
#define TP_MESSAGES_HPP

#include <iostream>
#include <string>

class A;
class B;

class A{
private:
    int _i;
public:
    void exec(int i);
    void send(B *b);
    void display();
};

class B{
private:
    int _j;
public:
    void exec(int j);
    void send(A *a);
    void display();
};

#endif //TP_MESSAGES_HPP
