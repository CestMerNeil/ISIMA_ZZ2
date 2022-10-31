#pragma once

const int nmax = 200;
const int mmax = 200;
const int omax = 200 * 200;
const int c_infini = 9999;

typedef struct t_instance {
	int n;
	int m;
	int p[nmax][mmax];
	int mach[nmax][mmax];
}t_instance;

typedef struct t_solution {
	int cout;
	int t[nmax][mmax];
	int pere[nmax];
	int vb[omax];
}t_solution;


void lire_fichier(t_instance& g, char* file);
