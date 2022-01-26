/**
 * @file main.cpp
 * @author N. DELAHAIE, O. CESAT
 * @brief 
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * Nicolas et Oier certifions bien d'être les auteurs de ce document.
 * 
 */

#include "batnav.h"
#include "game-tools.h"
#include <iostream>
using namespace std;

int main(void)
{
    /* -------------------------------------------------------------------------- */
    /*                           D E C L A R A T I O N S                          */
    /* -------------------------------------------------------------------------- */

    bool grilleInvisible[TAILLE_GRILLE][TAILLE_GRILLE]; //Tableau contenant des booléens indiquant si un bateau se trouve sur une case ou non
    char grilleVisible[TAILLE_GRILLE][TAILLE_GRILLE];   //Tableau contenant les caractères présents et visibles dans la grille (' ', '.' ou 'O')
    unsigned short int compteurTentatives;              //Compteur du nombre de tentatives executées par le joueur
    unsigned short int nombreDeTouches;                 //Compteur du nombre de tentatives réussies, touchant un bateau
    unsigned short int colonneSaisie;                   //Colonne saisie par l'utilisateur sous forme de lettre puis traduite, comprise entre 0 et 8
    unsigned short int ligneSaisie;                     //ligne saisie par l'utilisateur puis traduite, comprise entre 0 et 8


    
    /* -------------------------------------------------------------------------- */
    /*                         I N I T I A L I S A T I O N                        */
    /* -------------------------------------------------------------------------- */
    
    remplissageTableauCaracteresVide(grilleVisible);
    remplissageTableauBooleensFaux(grilleInvisible);
    creationBateau(grilleInvisible);

    /* -------------------------------------------------------------------------- */
    /*                        J O U E R   L A   P A R T I E                       */
    /* -------------------------------------------------------------------------- */
    
    while (true)
    {   
        // Affichages d'entête
        afficherRegles();
        afficherCoordoneesBateau(grilleInvisible);
        afficherGrille(grilleVisible);

        //Bateau entièrement découvert
        if (nombreDeTouches == TAILLE_BATEAU)
        {
            cout << endl
                 << "B A T E A U   C O U L E  en " << compteurTentatives << " tirs" << endl;
            break;
        }

        //Saisie-Modification/Affichage
        if (saisieCoordonnees(compteurTentatives, colonneSaisie, ligneSaisie))
        {
            cout << endl
                 << "A B A N D O N   bateau touche " << nombreDeTouches << " fois sur " << compteurTentatives << endl;
            break;
        }
        else
        {
            modifGrille(grilleVisible, grilleInvisible, colonneSaisie, ligneSaisie, compteurTentatives, nombreDeTouches);
        }

        effacer();
    }
    
    return 0;
}