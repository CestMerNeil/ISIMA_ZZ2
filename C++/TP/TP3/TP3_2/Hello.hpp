#ifndef _Class
#define _Class

#include <iostream>
#include <string>

class Mere{
protected:
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
protected:
    int _age;

public:
    void afficher();
    Fille();
    Fille(std::string nom);
    void setAge(int age);
};

#endif