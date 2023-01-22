#ifndef __SMS
#define __SMS

#include <iostream>
#include <string>
#include <stdexcept>

int ID = 12345;

class Reseau{
    private:
    std::string list;

    public:
    Reseau(void);

    std::string lister() const;
    void ajouter(std::string);
    Telephone trouveTel(std::string numToFind) const;
};

class Telephone{
    private:
    std::string numero;
    

    public:
    Reseau *reseau; // For get the reseau right now.
    Telephone(void);
    Telephone(std::string num);

    void setNumero(std::string num);
    std::string getNumero() const;
};

class Message{
    std::string sender;
    std::string receiver;
    std::string date;
    int id = ID;
    int cle = id+1;

    public:
    Message(std::string, std::string, std::string);
    virtual std::string afficher() = 0;
    int getId();
    int getCle();
};

class SMS : public Message{
    char msg[160];
    
    public:
    void setTexte(std::string);
    std::string getTexte(void);
    std::string afficher();
};
*/
#endif