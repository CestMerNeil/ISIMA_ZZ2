using namespace std;
#include "Header.h"


void lire_fichier(t_instance& g, string file) {
	ifstream infile(file);

	if (!infile.is_open())
	{
		cout << "can not open the file \n" << endl;
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
				infile >> g.p[piece][machine];
			}
		}

	}

	infile.close();
}


void bierwith(t_instance g, t_solution& s) {
	printf("after\n");
	int np = g.n;
	int d[nmax][2];
	int random;
	int here = 0;

	//Initialisation
	for (int i = 0; i < np; i++) {
		d[i][0] = i + 1;
		d[i][1] = g.m;
	}

	while (np > 0) {
		random = rand() % np;
		s.vb[here] = d[random][0];
		d[random][1] --;

		if (d[random][1] < 1) {
			d[random][0] = d[np - 1][0];
			d[random][1] = d[np - 1][1];
			np--;
		}
		here++;
	}

}


void verifier_vecteur(t_solution s, t_instance g) {
	//faire un exit(-1) si pb, juste compter le nb des éléments
	int count[nmax];

	memset(count, 0, sizeof(count));

	for (int i = 0; i <= g.n; i++) {
		for (int j = 0; j <= g.m; j++) {

		}
	}
}



/* Fonction evaluer
*	m = cout calculé
*	c = compteur pour les opérations de chaque pièce
*	pm = quelle pièce est passée en dernier sur chaque machine
*/
void evaluer(t_solution& s, t_instance g) {
	int i, j, m, p, q;
	int mach, date;
	int np = g.n * g.m;
	int c[nmax];
	int pm[mmax][2];

	// Initialisation à 0 du tableau
	memset(s.t, 0, sizeof(s.t));
	memset(c, 0, sizeof(c));
	memset(pm, 0, sizeof(pm));
	memset(s.pere, -1, sizeof(s.pere));

	s.cout = 0;
	

	for (i = 0; i < np; i++) {
		j = s.vb[i];
		c[j] = c[j] + 1;

		if (c[j] > 1) {
			m = s.t[j][c[j] - 1];

			if (m + g.p[j][c[j] - 1] > s.t[j][c[j]]) {
				s.t[j][c[j]] = m + g.p[j][c[j] - 1];
				s.pere[j][c[j]][0] = j;
				s.pere[j][c[j]][1] = c[j] - 1;
			}
		}

		mach = g.mach[j][c[j]];
		if (pm[mach][0] != 0 || pm[mach][1] != 0) {
			p = pm[mach][0];
			q = pm[mach][1];
			date = s.t[p][q];

			if (date + g.p[p][q] > s.t[j][c[j]]) {
				s.t[j][c[j]] = date + g.p[p][q];
				s.pere[j][c[j]][0] = p;
				s.pere[j][c[j]][1] = q;
			}
		}

		pm[mach][0] = j;
		pm[mach][1] = c[j];
	}

	for (i = 1; i <= g.n; i++) {
		if (s.t[i][g.m] + g.p[i][g.m] > s.cout) {
			s.cout = s.t[i][g.m] + g.p[i][g.m];
			s.pere_etoile[0] = i;
			s.pere_etoile[1] = g.m;
		}
	}

}