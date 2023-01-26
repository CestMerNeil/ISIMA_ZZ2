#include "tp3.hpp"

int main(int, char **) {

    /*
    const int TAILLE = 20;
    Bavarde   tab1[TAILLE];
    Bavarde * tab2 = new Bavarde[TAILLE];
    // Combien d'instances sont créées ?

    for (int i =0; i < TAILLE; ++i) {
        tab1[i].afficher();
        tab2[i].afficher();
    }

    // Combien d'instances sont détruites ?

    */

    Couple C(5, 7);
    Famille F;
    F.test[3].afficher();
    C.coupleA.afficher();

    Bavarde * mb = (Bavarde *)malloc(sizeof(Bavarde));
    mb->setX(50); 
    mb->afficher();

    
    return 0;
}
