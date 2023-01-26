#ifndef _Class
#define _Class

#include <iostream>
#include <string>

class Mere{
    private:
    int _name;
    int _computer;
    std::string _nom;

    public:
    Mere();
    Mere(std::string nom);
    void setName(int name);
    void setName(std::string nom);
    std::string getName();
    void afficher();
    int getComputer();
};

class Fille : public Mere{
private:
    int _age;

public:
    Fille(std::string nom);
    void setAge(int age);
};

#endif