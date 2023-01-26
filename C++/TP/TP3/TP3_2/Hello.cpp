#include "Hello.hpp"

/************************** Mere ***************************/
Mere::Mere() {
    std::cout << "Bonjour, je suis mere." << std::endl;
}

Mere::Mere(std::string nom) {
    _nom = nom;
}

void Mere::setName(int name){
    _name = name;
}

std::string Mere::getName(){
    return _nom;
}

void Mere::afficher(){
    std::cout << _name << std::endl;
}

void Mere::setName(std::string nom) {
    _nom = nom;
}

int Mere::getComputer() {
    return _computer;
}

/************************** Fille ***************************/
Fille::Fille(std::string nom) {
    Mere::setName(nom);
}

void Fille::setAge(int age) {
    _age = age;
}

