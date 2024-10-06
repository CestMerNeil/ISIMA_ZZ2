#pragma once

const int nmax = 211;
const int nmaxsucc = 211;
const int c_infini = 9999;

typedef struct t_graphe
{
	int n;
	int ns[nmax];
	float d[nmax][nmaxsucc];
	int s[nmax][nmaxsucc];

}t_graphe;

typedef struct t_sol {
	float valeur[nmax];
	int pere[nmax];
}t_sol;


void pluscourtchemin(t_sol & s, t_graphe g, int debut, int fin);
void bellman(t_sol& s, t_graphe g, int debut, int fin, int ordre[]);
void lire_fichier(t_graphe& g);
void pluslongchemin(t_sol& s, t_graphe g, int debut, int fin);