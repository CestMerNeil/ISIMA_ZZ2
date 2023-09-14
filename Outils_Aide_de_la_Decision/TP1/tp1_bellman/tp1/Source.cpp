#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void pluscourtchemin(t_sol& s, t_graphe g, int debut, int fin) {

	//Init
	int t[999];
	int jmin;
	int valmin;
	int si;
	float val;
	for (int i = 0; i <= g.n; i++) {
		s.valeur[i] = c_infini;
		s.pere[i] = -1;
		t[i] = 0;
	}
	s.valeur[debut] = 0;
	for (int i = 1; i <= g.n; i++) {
		valmin = c_infini;
		jmin = 0;
		for (int j = 1; j <= g.n; j++) {
			//Recherche minimum
			if (t[j] == 0 && s.valeur[j] < valmin) {
				jmin = j;
				valmin = s.valeur[j];
			}
		}

		printf("_______________\nSommet considere : %d\n_______________\n", jmin);

		for (int k = 1; k <= g.ns[jmin]; k++){
			si = g.s[jmin][k];
			printf("Voisin considere : %d\n", si);
			val = s.valeur[jmin] + g.d[jmin][si];
			printf("%f(marque du pere) + %f(poids de l'arc) = %f < %f(marque du voisin) ? ", s.valeur[jmin], g.d[jmin][si], val, s.valeur[si]);
			if (val < s.valeur[si]) {
				printf("Oui, on change la marque\n");
				s.valeur[si] = val;
				s.pere[si] = jmin;
			}
			else {
				printf("Non, pas de changement\n");
			}
			printf("\n");
		}
		printf("\n");
		t[jmin] = 1;
	}
}


void bellman(t_sol& s, t_graphe g, int debut, int fin, int ordre[]) {
	int stop = 0;
	int jmin;
	int valmin;
	int si;
	float val;
	for (int i = 1; i <= g.n; i++) {
		s.valeur[i] = c_infini;
		s.pere[i] = -1;
	}
	s.valeur[debut] = 0;
	
	while (stop == 0) {
		stop = 1;
		for (int i = 1; i <= g.n; i++) {
			jmin = ordre[i];

			printf("_______________\nSommet considere : %d\n_______________\n", jmin);

			for (int k = 1; k <= g.ns[jmin]; k++) {
				si = g.s[jmin][k];
				printf("Voisin considere : %d\n", si);
				val = s.valeur[jmin] + g.d[jmin][si];
				printf("%f(marque du pere) + %f(poids de l'arc) = %f < %f(marque du voisin) ? ", s.valeur[jmin], g.d[jmin][si], val, s.valeur[si]);
				if (val < s.valeur[si]) {
					printf("Oui, on change la marque\n");
					s.valeur[si] = val;
					s.pere[si] = jmin;
					stop = 0;
				}
				else {
					printf("Non, pas de changement\n");
				}
				printf("\n");
			}
		}
	}
}


void lire_fichier(t_graphe& g) {
	ifstream infile("D:\\CodeGithub\\ISIMA_ZZ2\\Outils_Aide_de_la_Decision\\TP1\\TP1_DATA\\DLP_210.dat");

	string temp;
	int i;
	int ns = 1;
	int deb;
	int debprev = -1;
	int fin;
	float d;
	if (!infile.is_open())
	{
		cout << "can not open the file \n" << endl;
		exit(-1);
	}
	else {
		infile >> g.n;
		infile >> i;
		for (int j = 0; j < i; j++) {
			infile >> deb;
			infile >> fin;
			infile >> d;
			if (deb == debprev) {
				ns++;
			}
			else {
				if(debprev != -1) 
					g.ns[debprev] = ns;
				ns = 1;
			}
			g.d[deb][fin] = d;
			g.s[deb][ns] = fin;
			debprev = deb;
		}

	}


	infile.close();
}



void pluslongchemin(t_sol& s, t_graphe g, int debut, int fin) {

	//Init
	int t[999];
	int jmin;
	int valmin;
	int si;
	float val;
	for (int i = 0; i <= g.n; i++) {
		s.valeur[i] = 0;
		s.pere[i] = -1;
		t[i] = 0;
	}
	s.valeur[0] = -1;
	s.valeur[debut] = 0;
	for (int i = 1; i <= g.n; i++) {
		valmin = 0;
		jmin = 0;
		for (int j = 1; j <= g.n; j++) {
			//Recherche minimum
			if (t[j] == 0 && s.valeur[j] > valmin) {
				jmin = j;
				valmin = s.valeur[j];
			}
		}

		printf("_______________\nSommet considere : %d\n_______________\n", jmin);

		for (int k = 1; k <= g.ns[jmin]; k++) {
			si = g.s[jmin][k];
			printf("Voisin considere : %d\n", si);
			val = s.valeur[jmin] + g.d[jmin][si];
			printf("%f(marque du pere) + %f(poids de l'arc) = %f > %f(marque du voisin) ? ", s.valeur[jmin], g.d[jmin][si], val, s.valeur[si]);
			if (val > s.valeur[si]) {
				printf("Oui, on change la marque\n");
				s.valeur[si] = val;
				s.pere[si] = jmin;
			}
			else {
				printf("Non, pas de changement\n");
			}
			printf("\n");
		}
		printf("\n");
		t[jmin] = 1;
	}
}