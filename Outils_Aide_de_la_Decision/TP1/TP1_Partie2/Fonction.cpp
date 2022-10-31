#include <iostream>
#include "Header.h"

void PlusCourtChemin(Sommet& s, Graphe g, int debut, int fin)
{
	// Init
	for (int i = 1; i < numSommet; i++) {
		s.valeur[i] = c_infini;
		s.label[i] = 0;
	}
	s.valeur[debut] = 0;

	for (int i = debut; i <= fin; i++){
		for (int j = 1; j <= g.nombreEnfantSommet[i]; j++) {
			int new_val;
			new_val = s.valeur[i] + g.distanceEnfantSommet[i][j];
			if (s.label[i] == 0 && new_val < s.valeur[g.enfantSommet[i][j]]) {
				s.valeur[g.enfantSommet[i][j]] = new_val;
				s.pere[g.enfantSommet[i][j]] = i;
			}
		}
		s.label[i] = 1;
	}

	for (int i = debut; i <= fin; i++) {

		std::cout << " Sommet " << i << " Pere " << s.pere[i] << " Valeur " << s.valeur[i] << "\n";

	}
}