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
#include <iostream>
#include <windows.h>
#include <random>
#include <chrono>
using namespace std;



void remplissageGrilleVide(char grille[][TAILLE_GRILLE], unsigned short int tailleGrille )
{
    for (unsigned int ligne = 0; ligne < tailleGrille ; ligne++)
    {
        for (unsigned int colonne = 0; colonne < tailleGrille ; colonne++)
        {
            grille[ligne][colonne] = ' ';
        }
    }
}

int random(int min, int max)
{
    std::default_random_engine generateur;
    std::uniform_int_distribution<int> distributionNombres;
    unsigned int tempsActuel = static_cast<unsigned int>(chrono::steady_clock::now().time_since_epoch().count());
    generateur.seed(tempsActuel);

    return ((distributionNombres(generateur) % (max - min + 1)) + min);
}

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
    cout << "Bateau 1 Ligne : " << lignePremiereCaseBateau << "  Colonne : " << colonnePremiereCaseBateau << endl;
    grille[lignePremiereCaseBateau][colonnePremiereCaseBateau] = 'X';


    // -- Analyse des directions possibles du bateau en fonction des bords --
    //Inititalisation zone de recherche
    ymin = static_cast<short int> (lignePremiereCaseBateau -1);
    ymax = static_cast<short int> (lignePremiereCaseBateau +1);
    xmin = static_cast<short int> (colonnePremiereCaseBateau -1);
    xmax = static_cast<short int> (colonnePremiereCaseBateau +1);

    //Reduction de zone de recherche en fonction de la proximité des bords
    if (lignePremiereCaseBateau < 3)      {ymin = 4;}
    else if (lignePremiereCaseBateau > 6) {ymax = 6;}
    if (colonnePremiereCaseBateau < 3)    {xmin = 4;}
    else if (lignePremiereCaseBateau > 6) {xmax = 6;}


    do
    {
        ligneCaseAutresBateaux = static_cast<unsigned short int> (random (ymin, ymax));
        colonneCaseAutresBateaux = static_cast<unsigned short int> (random(xmin, xmax));
    }
    while ((lignePremiereCaseBateau != ligneCaseAutresBateaux) && (colonnePremiereCaseBateau != colonneCaseAutresBateaux));

    decalageVertical = static_cast<short int> (lignePremiereCaseBateau - ligneCaseAutresBateaux);
    decalageHorizontal = static_cast<short int> (colonneCaseAutresBateaux - colonnePremiereCaseBateau);


    // -- Création des 3 autres cases du bateau --
    

    grille[ligneCaseAutresBateaux][colonneCaseAutresBateaux] = 'O';

}

void affichageBateau(char grille[][TAILLE_GRILLE]);

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

void saisieCoordonnees(unsigned int &ligneCase, unsigned &colonneCase);//OIER

void modifGrille(char grille[9][9], const unsigned int &ligneCase, const unsigned int &coolonneCase);//OIER
