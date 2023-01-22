#include "sms.hpp"

/************************* Telephone *****************************/
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

/************************* Reseau *****************************/
Reseau::Reseau(void){};

std::string Reseau::lister(void) const{
    return list;
}

void Reseau::ajouter(std::string ajouter){
    list += ajouter;
    list += "\n";
}

Telephone Reseau::trouveTel(std::string numToFind) const{
    return 
}


/************************* Message *****************************/

Message::Message(   std::string sender, 
                    std::string receiver, 
                    std::string date){
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
    msg = message;
}

std::string SMS::getTexte(void){
    return msg;
}

std::string SMS::afficher(void){
    return msg;
}

