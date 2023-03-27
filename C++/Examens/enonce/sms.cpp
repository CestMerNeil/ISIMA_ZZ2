#include "sms.hpp"
/**********************************************Telephone*/
void Telephone::setNumero(std::string numero)
{
    phoneNumber = numero;
}

std::string Telephone::getNumero() const
{
    return this->phoneNumber;
}

Reseau * Telephone::getReseau() const {
    return reseau;
}

void Telephone::textoter(std::string num, std::string text) {
    SMS newSMS(this->getNumero(), num, text);
    msg.push_back(newSMS);
}

/**********************************************Reseau*/

void Reseau::ajouter(std::string phone)
{
    Telephone newPhone(phone);
    newPhone.setReseau(this);
    list.push_back(newPhone);
    std::sort(list.begin(), list.end());
}

std::string Reseau::lister() const
{
    std::string backData;
    for (Telephone t : list)
    {
        backData += t.getNumero();
        backData += '\n';
    }
    return backData;
}

Telephone& Reseau::trouveTel(std::string num){
    for(Telephone t : list){
        if(t.getNumero() == num){
            return t;
        }
    }
    throw MauvaisNumero();
    //throw std::invalid_argument("mauvais numero");
}

/**********************************************SMS*/
int Message::cle = 0;
SMS::~SMS(){}