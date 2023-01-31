#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <iostream>
#include <fstream>

class Chaine {
private:
    int _capacite;
    char *tab;
public:
    Chaine();
    explicit Chaine(int capacite);
    explicit Chaine(char value);
    explicit Chaine(char *value);
    [[nodiscard]] int getCapacite() const;
    [[nodiscard]] const char * c_str() const; // Question nodiscard->?
    void afficher();

    void afficher(std::ostream ss); // No idea!
};

#endif
