// TP1_Partie2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"

using namespace std;


int main()
{
    //std::cout << "Hello World!\n";
    /*
    ifstream infile("D:\\Cours\\Aide_de_la_decision\\TP1_DATA\\DLP_210.dat");

    string temp;
    if (!infile.is_open())
    {
        cout << "can not open the file \n" << endl;
        return -1;
    }
    while (getline(infile, temp))
    {
        cout << temp << "\n";
    }

    infile.close();
    return 0;
    */

    Graphe g;
    Sommet s{};

    g.nombreEnfantSommet[1] = 2;
    g.nombreEnfantSommet[2] = 2;
    g.nombreEnfantSommet[3] = 2;
    g.nombreEnfantSommet[4] = 1;
    g.nombreEnfantSommet[5] = 2;
    g.nombreEnfantSommet[6] = 1;
    g.nombreEnfantSommet[7] = 2;
    g.nombreEnfantSommet[8] = 1;
    g.nombreEnfantSommet[9] = 0;

    g.enfantSommet[1][1] = 4;
    g.enfantSommet[1][2] = 2;
    g.enfantSommet[2][1] = 3;
    g.enfantSommet[2][2] = 5;
    g.enfantSommet[3][1] = 8;
    g.enfantSommet[3][2] = 8;
    g.enfantSommet[4][1] = 6;
    g.enfantSommet[5][1] = 3;
    g.enfantSommet[5][2] = 8;
    g.enfantSommet[6][1] = 7;
    g.enfantSommet[7][1] = 9;
    g.enfantSommet[7][2] = 8;
    g.enfantSommet[8][1] = 9;

    g.distanceEnfantSommet[1][1] = 4;
    g.distanceEnfantSommet[1][2] = 10;
    g.distanceEnfantSommet[2][1] = 1;
    g.distanceEnfantSommet[2][2] = 2;
    g.distanceEnfantSommet[3][1] = 4;
    g.distanceEnfantSommet[3][2] = 2;
    g.distanceEnfantSommet[4][1] = 12;
    g.distanceEnfantSommet[5][1] = 9;
    g.distanceEnfantSommet[5][2] = 3;
    g.distanceEnfantSommet[6][1] = 5;
    g.distanceEnfantSommet[7][1] = 3;
    g.distanceEnfantSommet[7][2] = 3;
    g.distanceEnfantSommet[8][1] = 3;

    PlusCourtChemin(s, g, 2, 8);



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
