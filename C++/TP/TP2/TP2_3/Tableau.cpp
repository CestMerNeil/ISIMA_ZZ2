#include <iostream>

class Tableau
{
    int * tab;
    int taille;

    public:
    Tableau():tab(nullptr), taille(10)
    {
        tab = new int{taille};
    }
    void afficher();
};

void Tableau::afficher(){
    std::cout << "Taille" << std::endl;
    std::cout << taille * taille << std::endl;
}

int main(int, char**)
{
    Tableau t;
    t.afficher();
    return 0;
}