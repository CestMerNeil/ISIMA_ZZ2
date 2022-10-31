using namespace std;
#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>


void lire_fichier(t_instance& g, char * file) {
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
		for (int piece = 0; piece < g.n; piece++) {

			/* For each machine */
			for (int machine = 0; machine < g.m; machine++) {
				infile >> g.mach[piece][machine];
				infile >> g.p[piece][machine];
			}
		}

	}

	infile.close();
}