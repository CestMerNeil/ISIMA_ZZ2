#include "sms.hpp"

Telephone::Telephone(void){};

Telephone::Telephone(std::string numero){
    this->numero = numero;
}

void Telephone::setNumero(std::string num){
    numero = num;
}

std::string Telephone::getNumero() const{
    return numero;
}

Reseau::Reseau(void){};

std::string Reseau::lister(void){
    return list;
}

void Reseau::ajouter(std::string ajouter){
    list += ajouter;
    list += "\n";
}

Message::afficher(){

}

Message::Message(std::string sender, std::string receiver, std::string date){
    this->sender = sender;
    this->receiver = receiver;
    this->date = date;
    ID += 1;
}

int Message::getCle(){
    return cle;
}
int Message::getId(){
    return id;
}

void SMS::setTexte(std::string message){
    this->msg = message;
}

std::string SMS::getTexte(void){
    return msg;
}

std::string SMS::afficher(void){
    return msg;
}