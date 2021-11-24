/**
 * @file batNav.cpp
 * @author N. DELAHAIE et O. CESAT
 * @brief Module contenant les opérations pour jouer à la bataille navale. 
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "batnav.h"
#include "game-tools.h"
#include <iostream>
#include <windows.h>
#include <random>
#include <chrono>
using namespace std;

void remplissageGrilleVide(char grille[][TAILLE_GRILLE], unsigned short int tailleGrille)
{
    for (unsigned int ligne = 0; ligne < tailleGrille ; ligne++)
    {
        for (unsigned int colonne = 0; colonne < tailleGrille ; colonne++)
        {
            grille[ligne][colonne] = ' ';
        }
    }
}

/*
char[TAILLE_GRILLE][TAILLE_GRILLE] creationGrilleVide()
{
    const unsigned short int TAILLE_GRILLE = 9;
    char grille[TAILLE_GRILLE][TAILLE_GRILLE];

    for (unsigned int ligne = 0; ligne < TAILLE_GRILLE ; ligne++)
    {
        for (unsigned int colonne = 0; colonne < TAILLE_GRILLE ; colonne++)
        {
            grille[ligne][colonne] = ' ';
        }
    }
    return grille;
}*/


void creationBateau(char grille[][TAILLE_GRILLE])
{
    short int decalageHorizontal;
    short int decalageVertical;

    unsigned short int colonneCaseAutresBateaux;
    unsigned short int ligneCaseAutresBateaux;

    unsigned short int lignePremiereCaseBateau;
    unsigned short int colonnePremiereCaseBateau;

    short int xmin;
    short int xmax;
    short int ymin;
    short int ymax;

    // -- Création premier point --
    lignePremiereCaseBateau = static_cast<unsigned short int> (random(0,8));
    colonnePremiereCaseBateau = static_cast<unsigned short int> (random(0,8));
    grille[lignePremiereCaseBateau][colonnePremiereCaseBateau] = 'O';


    // -- Analyse des directions possibles du bateau en fonction des bords --
    //Inititalisation zone de recherche
    ymin = static_cast<short int> (lignePremiereCaseBateau -1);
    ymax = static_cast<short int> (lignePremiereCaseBateau +1);
    xmin = static_cast<short int> (colonnePremiereCaseBateau -1);
    xmax = static_cast<short int> (colonnePremiereCaseBateau +1);

    //Reduction de zone de recherche en fonction de la proximité des bords
    if (lignePremiereCaseBateau < 3)        {ymin = lignePremiereCaseBateau;}
    else if (lignePremiereCaseBateau > 5)   {ymax = lignePremiereCaseBateau;}
    if (colonnePremiereCaseBateau < 3)      {xmin = colonnePremiereCaseBateau;}
    else if (colonnePremiereCaseBateau > 5) {xmax = colonnePremiereCaseBateau;}
    

    // -- Selection aléatoire de la direction --
    do
    {
        ligneCaseAutresBateaux = static_cast<unsigned short int> (random (ymin, ymax));
        colonneCaseAutresBateaux = static_cast<unsigned short int> (random(xmin, xmax));
    }
    while ((lignePremiereCaseBateau == ligneCaseAutresBateaux) && (colonnePremiereCaseBateau == colonneCaseAutresBateaux));
    decalageVertical = static_cast<short int> (ligneCaseAutresBateaux - lignePremiereCaseBateau);
    decalageHorizontal = static_cast<short int> (colonneCaseAutresBateaux - colonnePremiereCaseBateau);
    

    // -- Placement des 3 autres cases du bateau --    
    for (unsigned short int bombe = 0; bombe < 3 ; bombe++)
    {
        grille[ligneCaseAutresBateaux][colonneCaseAutresBateaux] = 'O';
        ligneCaseAutresBateaux += decalageVertical;
        colonneCaseAutresBateaux += decalageHorizontal;
    }

}

void afficherTableauCarreDeCharacteres(char tab[][TAILLE_GRILLE], unsigned short int tailleTab)
{
    for (unsigned short int ligne = 0 ; ligne <  tailleTab+1; ligne++)
    {
        if (ligne == 0) //Pour la première ligne
        {
            afficherLigne(10);
            cout << "|   |";
            for (unsigned int i = 0 ; i < tailleTab ; i++)
            {
                cout << " " << char(65+i) << " |";
            }
        }
        else
        {
            for (unsigned short int colonne = 0 ; colonne < tailleTab +1; colonne++)
            {
                if (colonne == 0) //Pour la première colonne
                {
                    if (ligne < 10) {cout << "| " << double(ligne) << " |";}
                    else            {cout << "| " << double(ligne) << "|" ;}
                }
                else 
                {
                    cout << " " <<  tab[ligne-1][colonne-1] << " |";
                }
            }
        }
        afficherLigne(10);
    }
}

void afficherLigne(unsigned int nombreCases) 
{
    cout << endl << "+";
    for (unsigned int i = 0; i < nombreCases; i++)
    {
        cout << "---+";
    }
    cout << endl;    
}

void affichageBateau(char grille[][TAILLE_GRILLE]);//OIER

void saisieCoordonnees(unsigned int &ligneCase, unsigned &colonneCase);//OIER

void modifGrille(char grille[9][9], const unsigned int &ligneCase, const unsigned int &coolonneCase);//OIER
