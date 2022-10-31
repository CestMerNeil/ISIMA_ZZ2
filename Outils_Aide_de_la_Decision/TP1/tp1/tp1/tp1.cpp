// tp1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Header.h"

int main() {
    t_graphe g;
    t_sol s{};

    /*g.n = 9;
    g.ns[1] = 2;
    g.ns[2] = 2;
    g.ns[3] = 2;
    g.ns[4] = 1;
    g.ns[5] = 2;
    g.ns[6] = 1;
    g.ns[7] = 2;
    g.ns[8] = 1;
    g.ns[9] = 0;

    g.s[1][1] = 4;
    g.s[1][2] = 2;
    g.s[2][1] = 3;
    g.s[2][2] = 5;
    g.s[3][1] = 6;
    g.s[3][2] = 8;
    g.s[4][1] = 6;
    g.s[5][1] = 3;
    g.s[5][2] = 8;
    g.s[6][1] = 7;
    g.s[7][1] = 8;
    g.s[7][2] = 9;
    g.s[8][1] = 9;

    g.d[1][4] = 4;
    g.d[1][2] = 10;
    g.d[2][3] = 1;
    g.d[2][5] = 2;
    g.d[3][6] = 4;
    g.d[3][8] = 2;
    g.d[4][6] = 12;
    g.d[5][3] = 9;
    g.d[5][8] = 3;
    g.d[6][7] = 5;
    g.d[7][8] = 3;
    g.d[7][9] = 3;
    g.d[8][9] = 3;

    pluscourtchemin(s, g, 1, 9);
    for (int i = 1; i < 10; i++) {
        printf("Marque du sommet %d : %d\n", i, s.valeur[i]);
    }

    int ordre[10] = { 0,1,2,3,4,5,6,7,8,9 };
    bellman(s, g, 1, 9, ordre);
    for (int i = 1; i < 10; i++) {
        printf("Marque du sommet %d : %d\n", i, s.valeur[i]);

    }*/
    int ordre[211];
    int enfant = 210;
    lire_fichier(g);
    /*pluscourtchemin(s, g, 1, 210);
    for (int i = 1; i < g.n + 1; i++) {
        printf("Marque du sommet %d : %f\n", i, s.valeur[i]);

    }
    int enfant = 210;
    while (enfant > 1) {
        std::cout << enfant << " valeur " << s.valeur[enfant] << "\n";
        enfant = s.pere[enfant];
    }
    int ordre[211];
    for (int i = 0; i < 211; i++) {
        ordre[i] = i;
    }
    bellman(s, g, 1, 210, ordre);
    enfant = 210;
    while (enfant > 1) {
        std::cout << enfant << " valeur " << s.valeur[enfant] << "\n";
        enfant = s.pere[enfant];
    }*/
    ordre[0] = 0;
    ordre[1] = 1;
    ordre[210] = 210;
    for (int i = 2; i < 210; i++) {
        ordre[i] = 211 - i;
    }
    bellman(s, g, 1, 210, ordre);
    enfant = 210;
    while (enfant > 1) {
        std::cout << enfant << " valeur " << s.valeur[enfant] << "\n";
        enfant = s.pere[enfant];
    }

    //pluslongchemin(s, g, 1, 210);

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
