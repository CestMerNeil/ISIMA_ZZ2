#ifndef __SMS
#define __SMS

#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

class Reseau;
class SMS;
class MMS;
/**********************************************Media*/
class Media {
    public:
    std::string index;
    virtual std::string afficher() = 0;
    virtual ~Media(){}
};
class Image : public Media{
    std::string afficher() override{
        return "[[image]]";
    }

};
class Son : public Media{
    std::string afficher() override{
        return "[[son]]";
    }
};
class Video : public Media{
    std::string afficher() override{
        return "[[video]]";
    }
};
/**********************************************Telephone*/
class Telephone
{
private:
    std::string phoneNumber;
    Reseau *reseau;
    std::vector<SMS> msg;
    std::vector<MMS> mmsg;

public:
    Telephone() { reseau = 0; }
    Telephone(std::string num) { phoneNumber = num; }
    void setNumero(std::string number);
    void setReseau(Reseau *r) { reseau = r; }
    std::string getNumero() const;
    bool operator<(const Telephone &other) const { return phoneNumber < other.phoneNumber; }
    Reseau * getReseau() const;
    int getNbMessages() const { return msg.size(); }
    void textoter(std::string, std::string);
    void mmser(std::string, MMS mms);
};

/**********************************************Reseau*/

class Reseau
{
private:
    std::vector<Telephone> list;

public:
    Reseau() {}
    void ajouter(std::string);
    std::string lister() const;
    Telephone& trouveTel(std::string);
};

class MauvaisNumero : public std::invalid_argument
{
public:
    MauvaisNumero() : std::invalid_argument("mauvais numero") {}
};

/**********************************************SMS*/
class Message{
    public:
    Message() {}
    std::string exp;
    std::string dest;
    std::string date;
    int id;
    std::string text;
    static int cle;
    virtual std::string afficher() = 0;
    static int getCle() { return cle; }

    void setTexte(std::string text) { 
        std::string textOri = this->text;
        this->text = text;
        this->text += textOri;
    }
    std::string getTexte() const { return text; }
    int getId() { return id; }  
    virtual ~Message(){}
    std::string getDe() const{
        return exp;
    }
    std::string getA() const{
        return dest;
    }
};

class SMS : public Message {
    public:
    SMS(std::string exp, std::string dest, std::string date) {
        this->exp = exp;
        this->dest = dest;
        this->date = date;
        id = Message::getCle();
        cle += 1;
    }
    std::string afficher() override {return text;}
    virtual ~SMS();
    
};

/**********************************************MMS*/
class MMS : public Message {
    public:
    MMS(std::string a, std::string b, std::string c) {
        exp = a;
        dest = b;
        date = c;
    }

    void joindre(Media * media) {
        text += media->afficher();
    }
    std::string afficher() override { return text; }
};



#endif