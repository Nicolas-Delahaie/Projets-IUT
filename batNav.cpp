/**
 * @file batNav.cpp
 * @author N. DELAHAIE et O. CESAT
 * @brief Module contenant les opérations pour jouer à la bataille navale. 
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*changes : 
    dans la saisie : changelent du if dans le if et séparation du message d'erreur 


*/
#include "batnav.h"
#include "game-tools.h"
#include <iostream>
using namespace std;


void afficherRegles()
{
    cout << "B A T A I L L E   N A V A L E " << endl;
    cout << "Le joueur doit couler un bateau de 4 cases " << endl
         << "(vertical ou horizontal ou diagonal)." << endl
         << endl;
}

void remplissageGrilleCaracteresVide(char grille[][TAILLE_GRILLE], unsigned short int tailleGrille)
{
    for (unsigned int ligne = 0; ligne < tailleGrille ; ligne++)
    {
        for (unsigned int colonne = 0; colonne < tailleGrille ; colonne++)
        {
            grille[ligne][colonne] = ' ';
        }
    }
}

void remplissageGrilleBooleensFaux(bool grille[][TAILLE_GRILLE], unsigned short int tailleGrille)
{
    for (unsigned int ligne = 0; ligne < tailleGrille ; ligne++)
    {
        for (unsigned int colonne = 0; colonne < tailleGrille ; colonne++)
        {
            grille[ligne][colonne] = false;
        }
    }
}

void creationBateau(bool grille[][TAILLE_GRILLE])
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
    grille[lignePremiereCaseBateau][colonnePremiereCaseBateau] = true;


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


    // -- Calcul du décalage vertical et horizontal de la 2e case par rapport à la 1ere --
    decalageVertical = static_cast<short int> (ligneCaseAutresBateaux - lignePremiereCaseBateau);
    decalageHorizontal = static_cast<short int> (colonneCaseAutresBateaux - colonnePremiereCaseBateau);
    

    // -- Placement des 3 autres cases du bateau --    
    for (unsigned short int bombe = 0; bombe < 3 ; bombe++)
    {
        grille[ligneCaseAutresBateaux][colonneCaseAutresBateaux] = true;
        ligneCaseAutresBateaux = static_cast<unsigned short int>(ligneCaseAutresBateaux + decalageVertical);
        colonneCaseAutresBateaux = static_cast<unsigned short int>(colonneCaseAutresBateaux + decalageHorizontal);
    }
}

void afficherCoordoneesBateau(bool grille[][TAILLE_GRILLE], unsigned short int TAILLE_GRILLE)
{
    unsigned short int ligne;
    unsigned short int colonne;

    cout << "Bateau =  ";

    //Parcourt chaque emplacement du tableau
    for (ligne = 0; ligne < TAILLE_GRILLE; ligne++)
    {
        for (colonne = 0; colonne < TAILLE_GRILLE; colonne++)
        {
            if (grille[ligne][colonne])
            {
                cout << "(" << char(colonne + 65) << "," << ligne + 1 << ")  ";
            }
        }
    }
}

void afficherTableauCarreDeCaracteres(char tab[][TAILLE_GRILLE], unsigned short int tailleTab)
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

bool saisieCoordonnees ( unsigned short int & tentatives, unsigned short int  & colonneCiblee, unsigned short int & ligneCiblee)
{
    char colonneLettre;
    char ligneLettre;
    

    while (true)
    {
        cout << "Votre tir numero " << tentatives + 1 << " (ex A3) ou abandonner (@@) ? ";
        
        cin >> colonneLettre;
        colonneCiblee = int(colonneLettre);

        cin >> ligneLettre;
        ligneCiblee = int(ligneLettre);

        //Si l'utilisateur saisie @@ pour abandonner
        if ((colonneCiblee == AROBASE_ASCII) && (ligneCiblee == AROBASE_ASCII))
        {
            return true;
        }

        //Saisies dans le bon intervalle
        else if ((colonneCiblee >= A_ASCII) && (colonneCiblee <= I_ASCII) && (ligneCiblee >= UN_ASCII) && (ligneCiblee <= NEUF_ASCII))
        {
            return false;
        }

        //Saisie en dehors du tableau
        else
        {
            if ((colonneCiblee < A_ASCII) || (colonneCiblee > I_ASCII))
            {
                cout << "Erreur de saisie de la colonne " << endl;
            }

            if ((ligneCiblee < UN_ASCII) || (ligneCiblee > NEUF_ASCII))
            {
                cout << "Erreur de saisie de la ligne " << endl;
            }
            cout << endl;
        }
    }
}

void modifGrille ( char grilleAffiche [][TAILLE_GRILLE], bool grilleCache [][TAILLE_GRILLE], unsigned short int colonne, unsigned short int ligne, unsigned short int & compteurTir, unsigned short int & compteurTouche)
{
    unsigned short int ligneTraduite;
    unsigned short int colonneTraduite;

    //Traduction des lignes et colonnes de char à int
    ligneTraduite = static_cast<unsigned short int>(ligne - UN_ASCII);
    colonneTraduite = static_cast<unsigned short int>(colonne - A_ASCII);

    //Si la case n'a pas été déjà découverte
    if ((grilleAffiche[ligneTraduite][colonneTraduite] != 'O') && (grilleAffiche[ligneTraduite][colonneTraduite] != '.'))
    {
        //Case contenant bateau
        if (grilleCache[ligneTraduite][colonneTraduite])
        {
            grilleAffiche[ligneTraduite][colonneTraduite] = 'O';
            compteurTouche++;
        }
        //Case vide
        else 
        {
            grilleAffiche[ligneTraduite][colonneTraduite] = '.';
        }
        compteurTir++;
    }
}
