#pragma once
#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

const int nmax = 20;
const int mmax = 20;
const int omax = 20 * 20;
const int c_infini = 9999;
const int K = 100000;

/*
 * @brief	Structure de graphe
 * @param	n			->	Nombre de pieces
 * @param	m			->	Nombre de machines
 * @param	p[][]		->	Machine pour le piece
 * @param	mach[][]	->	Temps de traitement pour le piece dans le machine
 **/
typedef struct t_instance {
	int n;
	int m;
	int p[nmax][mmax];
	int mach[nmax][mmax];
}t_instance;


/*
 * @brief	Structure de solution
 * @param	cout			->	Le temps qu'il a fallu pour arriver au sommet
 * @param	t[][]			->	
 * @param	pere[][][2]		->	Sommet pere
 * @param	vb[]			->	
 * @param	pere_etoile[]	->	Dernier sommet
 **/
typedef struct t_solution {
	int cout;
	int t[nmax][mmax];
	int pere[nmax][mmax][2];
	int vb[omax];
	int pere_etoile[2];
}t_solution;


void lire_fichier(t_instance& g, string file);
void bierwith(t_instance g, t_solution& s);
void evaluer(t_solution& s, t_instance g);
void verifier_vecteur(t_solution s, t_instance g);
void recherche_locale(t_solution& s, t_instance g, int n_max_iter);
int hashage(t_solution s, t_instance g);
void permut(t_solution& s, t_instance g);
void grasp(t_solution& s, t_instance g, int nb_iter, int nb_els, int nb_voisins);