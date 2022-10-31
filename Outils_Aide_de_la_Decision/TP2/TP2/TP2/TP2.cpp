// TP2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Header.h"

int main()
{
    //srand(0);
    srand(time(NULL));
    t_instance g;
    t_solution s;
    t_solution best;
    lire_fichier(g, "D:/CodeGithub/ISIMA_ZZ2/Outils_Aide_de_la_Decision/TP2truela01.txt");
    printf("before\n");
    bierwith(g, s);
    verifier_vecteur(s, g);

    for (int i = 0; i < g.n * g.m; i++) {
        printf("%d ", s.vb[i]);
    }

    printf("\n");

    evaluer(s, g);

    for (int i = 1; i <= g.n; i++) {
        for (int j = 1; j <= g.m; j++) {
            printf("pere de [%d][%d] = [%d] [%d]\n", i, j, s.pere[i][j][0], s.pere[i][j][1]);
        }
    }

    printf("pere du dernier : %d %d\n", s.pere_etoile[0], s.pere_etoile[1]);
    printf("cout : %d\n", s.cout);

    printf("\n______________\n\n");

    recherche_locale(s, g, 2000);

    for (int i = 0; i < g.n * g.m; i++) {
        printf("%d ", s.vb[i]);
    }
    printf("\n");
    for (int i = 1; i <= g.n; i++) {
        for (int j = 1; j <= g.m; j++) {
            printf("pere de [%d][%d] = [%d] [%d]\n", i, j, s.pere[i][j][0], s.pere[i][j][1]);
        }
    }

    printf("pere du dernier : %d %d\n", s.pere_etoile[0], s.pere_etoile[1]);
    printf("cout : %d\n", s.cout);



    printf("\n_______GRASP_______\n\n");
    grasp(s, g, 100, 10, 10);

    for (int i = 0; i < g.n * g.m; i++) {
        printf("%d ", s.vb[i]);
    }
    printf("\n");
    for (int i = 1; i <= g.n; i++) {
        for (int j = 1; j <= g.m; j++) {
            printf("pere de [%d][%d] = [%d] [%d]\n", i, j, s.pere[i][j][0], s.pere[i][j][1]);
        }
    }

    printf("pere du dernier : %d %d\n", s.pere_etoile[0], s.pere_etoile[1]);
    printf("cout : %d\n", s.cout);


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
