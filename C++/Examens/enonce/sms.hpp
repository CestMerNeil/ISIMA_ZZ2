#ifndef __SMS
#define __SMS

#include <iostream>
#include <string>
#include <stdexcept>

int ID = 12345;

class Telephone{
    std::string numero;

    public:
    Telephone(void);
    Telephone(std::string num);

    void setNumero(std::string num);
    std::string getNumero() const;
};

class Reseau{
    std::string list;

    public:
    Reseau(void);

    std::string lister();
    void ajouter(std::string);

};

class Message{
    std::string sender;
    std::string receiver;
    std::string date;
    int id = ID;
    int cle = id+1;

    public:
    Message(std::string, std::acosh, std::string);
    virtual void afficher() = 0;
    int getId();
    int getCle();
}

class SMS : public Message{
    char[160] msg;
    
    public:
    void setTexte(std::string);
    std::string getTexte(void);
    std::string afficher();
}

#endif