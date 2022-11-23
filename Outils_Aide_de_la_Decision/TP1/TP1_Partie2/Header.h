#pragma once
const int nmax = 50;
const int nmaxsucc = 10;
const int c_infini = 9999;
const int numSommet = 10;

typedef struct Graphe
{
	int n;
	int nombreEnfantSommet[numSommet];
	int distanceEnfantSommet[numSommet][numSommet];
	int enfantSommet[numSommet][numSommet];
}Graphe;

typedef struct Sommet
{
	int valeur[numSommet];
	int pere[numSommet];
	int label[numSommet];
}Sommet;

void PlusCourtChemin(Sommet& s, Graphe g, int debut, int fin);
