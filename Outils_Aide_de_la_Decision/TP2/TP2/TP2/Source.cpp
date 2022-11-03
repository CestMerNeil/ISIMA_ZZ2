using namespace std;
#include "Header.h"


int Ti[K] = { 0 };


/******************************************************************************************************************************
 * @fn		lire_fichier																				                      *
 *																												              *
 * @brief	Permet de lire une structure de graphe dans un fichier et de la stocker dans une instance donnee en parametre	  *              
 * @brief	Un fichier est sous la forme :									                                                  *
 * @brief	Nombre_de_pieces Nombre_de_machines							                                                      *
 * @brief	machine1 cout1 machine2 cout2 ...                                                                                 *
 * @brief	Chaque ligne correspond a une piece et decrit les operations successives avec leurs couts					      *
 *																															  *
 * @param	g		:	structure de graphe vide																			  *
 * @param	file	:	nom du fichier a ouvrir																				  *
 ******************************************************************************************************************************/
void lire_fichier(t_instance& g, string file) {
	ifstream infile(file);

	/* Si le fichier n'a pas pu etre ouvert */
	if (!infile.is_open())
	{
		cout << "Can not open the file \n" << endl;
		exit(-1);
	}
	else {
		infile >> g.n;
		infile >> g.m;

		/* For each piece */
		for (int piece = 1; piece <= g.n; piece++) {

			/* For each machine */
			for (int machine = 1; machine <= g.m; machine++) {
				infile >> g.mach[piece][machine];
				g.mach[piece][machine] ++;
				infile >> g.p[piece][machine];
			}
		}

	}

	infile.close();
}


/******************************************************************************************************************************
 * @fn		bierwith												                                                          *
 *																														      *
 * @brief	Genere un vecteur de bierwith aleatoirement dans le champ adapte de la structure passee en parametre	          *
 *																														      *
 * @param   g	:	structure du graphe considere																		      *
 * @param	s	:	structure de la solution dans laquelle stocker le vecteur												  *
 ******************************************************************************************************************************/
void bierwith(t_instance g, t_solution& s) {
	int np = g.n;
	int d[nmax][2];
	int random;
	int here = 0;

	//Initialisation
	for (int i = 0; i < np; i++) {
		d[i][0] = i + 1;
		d[i][1] = g.m;
	}

	/* Tant qu'il reste des operations a placer */
	while (np > 0) {
		random = rand() % np;
		s.vb[here] = d[random][0];
		d[random][1] --;

		/* Si on a place toutes les operations de la piece */
		if (d[random][1] < 1) {
			d[random][0] = d[np - 1][0];
			d[random][1] = d[np - 1][1];
			np--;
		}

		here++;
	}

}


/******************************************************************************************************************************
 * @fn		verifier_vecteur																								  *
 *																															  *
 * @brief	 Verifie que le vecteur de Bierwith de la solution passee en parametre est bien construite et termine l'execution *	 
 *			 si ce n'est pas le cas																							  *
 *																															  *
 * @param	g	:	structure du graphe utilise pour construire le vecteur													  *
 * @param	s	:	structure de solution ou est stocke le vecteur a verifier												  *
 ******************************************************************************************************************************/
void verifier_vecteur(t_solution s, t_instance g) {
	int count[nmax];
	int np = g.m * g.n;
	int i;

	memset(count, 0, sizeof(count));

	/* Pour chaque element du vecteur */
	for (i = 0; i < np; i++) {
		count[s.vb[i]] ++;

		/* S'il y a un trop grand nombre de fois une piece */
		if (count[s.vb[i]] > g.m) {
			exit(-1);
		}
	}

	/* Pour chaque piece */
	for (i = 1; i <= g.n; i++) {

		/* Si la piece apparait un trop petit
		   nombe de fois dans le vecteur      */
		if (count[i] < g.m) {
			exit(-1);
		}
	}
}



/******************************************************************************************************************************
 * @fn		evaluer																		                                      *
 *																														      *
 * @brief	Calcule les dates de debut de toutes les operations et indique leur pere dans les champs de la structure de		  *
 *			solution passee en parametre par rapport au graphe donne en parametre et d'un vecteur de Bierwith determine       *
 *			a l'avance																									      *
 *																															  *
 * @param	g	:	structure du graphe considere																			  *
 * @param	s	:	structure de la solution dans laquelle stocker les informations											  *
 ******************************************************************************************************************************/
void evaluer(t_solution& s, t_instance g) {
	int i, j, m, p, q;
	int mach, date;
	int np = g.n * g.m;
	int c[nmax];
	int pm[mmax][2];

	// Initialisation a 0 du tableau
	memset(s.t, 0, sizeof(s.t));
	memset(c, 0, sizeof(c));
	memset(pm, 0, sizeof(pm));
	memset(s.pere, -1, sizeof(s.pere));

	s.cout = 0;
	
	/* Pour toutes les operations */
	for (i = 0; i < np; i++) {
		j = s.vb[i];
		c[j] = c[j] + 1;

		/* Si ce n'est pas la premiere operation effectuee
		   pour la piece                                   */
		if (c[j] > 1) {
			m = s.t[j][c[j] - 1];

			/* Si le cout calcule est plus grand que la marque */
			if (m + g.p[j][c[j] - 1] > s.t[j][c[j]]) {
				s.t[j][c[j]] = m + g.p[j][c[j] - 1];
				s.pere[j][c[j]][0] = j;
				s.pere[j][c[j]][1] = c[j] - 1;
			}
		}

		mach = g.mach[j][c[j]];

		/* Si au moins une piece est passee sur la machine */
		if (pm[mach][0] != 0 || pm[mach][1] != 0) {
			p = pm[mach][0];
			q = pm[mach][1];
			date = s.t[p][q];

			/* Si la date calculee est plus grande que la date initiale */
			if (date + g.p[p][q] > s.t[j][c[j]]) {
				s.t[j][c[j]] = date + g.p[p][q];
				s.pere[j][c[j]][0] = p;
				s.pere[j][c[j]][1] = q;
			}
		}

		pm[mach][0] = j;
		pm[mach][1] = c[j];
	}

	/* Pour chaque piece, on traite la derniere operation */
	for (i = 1; i <= g.n; i++) {

		/* Si la date calculee finale calculee est plus grande
		   que celle sauvegardee                               */
		if (s.t[i][g.m] + g.p[i][g.m] > s.cout) {
			s.cout = s.t[i][g.m] + g.p[i][g.m];
			s.pere_etoile[0] = i;
			s.pere_etoile[1] = g.m;
		}
	}

}


/******************************************************************************************************************************
 * @fn		recherche_locale																								  *
 *																								                              *
 * @brief	Realise une amelioration de type descente a partir d'une premiere solution calculee grace au vecteur de Bierwith  *
 *			renseigne dans la structure de solution donne en parametre														  *
 *																															  *
 * @param	g			:	structure du graphe considere																	  *
 * @param	s			:	structure de la solution dans laquelle stocker les informations et contenant le premier vecteur   *
 *							de Bierwith																						  *
 * @param	max_iter	:	nombre max d'iteration			         													      *
 ******************************************************************************************************************************/
void recherche_locale(t_solution& s, t_instance g, int n_max_iter) {
	int        posi,
		       posj,
		       opi,
		       opj;
	int        indice,
		       piece,
		       machine;
	t_solution s_prime;
	int        stop = 0;
	int        c    = 0;
	int        i[2];
	int        j[2];

	i[0] = g.n + 1;
	i[1] = g.m + 1;
	j[0] = s.pere_etoile[0];
	j[1] = s.pere_etoile[1];

	evaluer(s, g);

	/* Boucle principale, executee autant de fois que precise en parametre */
	while (stop == 0) {

		/* Si les machines occupees par les operations sont differentes */
		if (i[1] != j[1]) {
			i[0] = j[0];
			i[1] = j[1];
			j[0] = s.pere[i[0]][i[1]][0];
			j[1] = s.pere[i[0]][i[1]][1];
		}

		else {
			posi = -1;
			posj = -1;
			opi = 0;
			opj = 0;
			indice = 0;

			/* Tant que l'on a pas trouve les position dans le vecteur
				des operation i et j */
			while (posj == -1 || posi == -1) {

				/* Si l'on a pas trouve la position de l'operation i et
					que le numero de piece correspond */
				if (posi == -1 && s.vb[indice] == i[0]) {
					opi++;

					/* Si l'operation decrite est la bonne */
					if (g.mach[i[0]][opi] == i[1]) {
						posi = indice;
					}
				}

				/* Si l'on a pas trouve la position de l'operation j et
					que le numero de piece correspond */
				else if (posj == -1 && s.vb[indice] == j[0]) {
					opj++;

					/* Si l'operation decrite est la bonne */
					if (g.mach[j[0]][opj] == j[1]) {
						posj = indice;
					}
				}

				indice++;
			}

			/* Copie du vecteur de bierwith initial */
			for (indice = 0; indice < g.n * g.m; indice++) {
				s_prime.vb[indice] = s.vb[indice];
			}

			s_prime.vb[posi] = s.vb[posj];
			s_prime.vb[posj] = s.vb[posi];
			
			evaluer(s_prime, g);

			/* Si la seconde solution a un cout plus eleve, on continue avec le premier vecteur*/
			if (s.cout <= s_prime.cout) {
				i[0] = j[0];
				i[1] = j[1];
				j[0] = s.pere[i[0]][i[1]][0];
				j[1] = s.pere[i[0]][i[1]][1];
			}

			else {
				s = s_prime;
				i[0] = g.n + 1;
				i[1] = g.m + 1;
				j[0] = s.pere_etoile[0];
				j[1] = s.pere_etoile[1];
			}
		}

		c++;

		/* Si on a atteint la solution optimale ou le nombre max d'iterations */
		if (i[0] == -1 || c >= n_max_iter) {
			stop = 1;
		}
	}

}


/******************************************************************************************************************************
 * @fn		hashage																										      *
 *																															  *
 * @brief	Calcule le hash de la solution passee en parametre															      *
 *																															  *
 * @param	g	:	structure du graphe considere																			  *
 * @param	s	:	structure de la solution dont il faut calculer le hash									                  *
 * @return	res :	hash de la solution consideree																		      *
 ******************************************************************************************************************************/
int hashage(t_solution s, t_instance g) {
	int res = 0;
	
	/* Pour chaque piece */
	for (int i = 1; i < g.n; i++) {

		/* Pour chaque machine */
		for (int j = 1; j < g.m; j++) {
			res += (s.t[i][j]*s.t[i][j]) % 100000;
		}
	}

	return res % 100000;
}


/******************************************************************************************************************************
 * @fn		permut													 														  *
 *																															  *
 * @brief	Realise une permutation simple du vecteur de Bierwith donne dans la structure de solution donnee en parametre     *
 *																														      *
 * @param	g	:	structure du graphe considere																			  *
 * @param	s	:	structure de la solution ou faire la permutation												          *
 ******************************************************************************************************************************/
void permut(t_solution & s, t_instance g) {
	int save;
	int rand1 = rand() % (g.n * g.m);
	int rand2 = rand() % (g.n * g.m);

	/* Tant que la permutation ne change pas
	   le vecteur                            */
	while (s.vb[rand1] == s.vb[rand2]) {
		rand2 = rand() % (g.n * g.m);
	}

	save = s.vb[rand1];
	s.vb[rand1] = s.vb[rand2];
	s.vb[rand2] = save;
}


/******************************************************************************************************************************
 * @fn		grasp																			                                  *
 *																															  *
 * @brief	Fonction qui parcoure l'espace de maniere efficace pour trouver la solution optimale                             *
 *																														      *
 * @param	g			:	structure du graphe considere																	  *
 * @param	s			:	structure de la solution																		  *
 * @param	nb_iter		:	nombre max d'iteration																			  *
 * @param	nb_voisins	:	nombre de voisins a chercher																	  *
 * @param	nb_els		:	nombre max de recherche des voisins																  *
 ******************************************************************************************************************************/
void grasp(t_solution& s, t_instance g, int nb_iter, int nb_els, int nb_voisins) {
	t_solution best_voisin;
	int        voisins;
	int        iter;
	int        max_iter = nb_voisins * nb_voisins;
	t_solution sol_els;
	t_solution max;

	memset(Ti, 0, sizeof(Ti));
	max.cout = c_infini;

	/* Faire le meme traitement pour le nombre d'iterations voulues */
	for (int i = 0; i < nb_iter; i++) {

		/* Tant que l'on a deja visite la solution consideree */
		do {
			bierwith(g, s);
			verifier_vecteur(s, g);
			recherche_locale(s, g, 20000);
		} while (Ti[hashage(s, g)] == 1);

		Ti[hashage(s, g)] = 1;

		/* Visiter un espace voisin */
		for (int j = 0; j < nb_els; j++) {
			best_voisin = s;
			voisins = 0;
			iter = 0;

			/* Tant que l'on a pas trouve assez de voisins ou que l'on a 
			   depasse un nombre maximum d'essais et que l'on a au moins
			   un voisin                                                */
			while (voisins < nb_voisins && (iter < max_iter || voisins > 0)) {
				sol_els = s;
				permut(sol_els, g);
				recherche_locale(sol_els, g, 20000);

				/* Si on n'a pas deja visite cette solution */
				if (Ti[hashage(sol_els, g)] == 0) {
					Ti[hashage(sol_els, g)] = 1;
					
					/* Si la solution est meilleure que celle retenue jusque-la */
					if (best_voisin.cout > sol_els.cout) {
						best_voisin = sol_els;
					}

					voisins++;
				}

				iter++;
			}

			s = best_voisin;

			/* Si la solution est meilleure que toutes les autres
			   jusqu'a maintenant                                 */
			if (s.cout < max.cout) {
				max = s;
			}
		}
	}

	s = max;
	
}