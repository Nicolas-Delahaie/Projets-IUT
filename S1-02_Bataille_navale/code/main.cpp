/**
 * @file main.cpp
 * @author N. DELAHAIE, O. CESAT
 * @brief 
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//Transformer le tableau invisible en booléen
//Empecher les doubles saisies (empecher compteur de tentatives d'incrementer)


#include <iostream>
#include "batnav.h"
#include "game-tools.h"
using namespace std;


int main (void)
{

    //    ****************      D E C L A R A T I O N S      ***************
    //    T Y P E S 
    //    V A R I A B L E S  
    char grilleInvisible[TAILLE_GRILLE][TAILLE_GRILLE];     //Tableau contenant des booléens indiquant si un bateau se trouve dessus
    char grilleVisible[TAILLE_GRILLE][TAILLE_GRILLE];       ///Tableau contenant les caractères présents et visibles dans la grille
    unsigned short int compteurTentatives;                  //Compteur du nombre de tentatives executées par le joueur
    unsigned short int nombreDeTouches;                     //Compteur du nombre de tentatives réussies, touchant un bateau
    unsigned short int colonneSaisie;                       //Colonne entre 0 et 9 saisie par l'utilisateur sous forme de lettre
    unsigned short int ligneSaisie;                         //Ligne entre 0 et 9 saisie par l'utilisateur
    bool joueurAbandonne;                                   //Booléen indiquant is l'utilisateur abandonne
    

    //    **************      I N I T I A L I S A T I O N      *************
    remplissageGrilleVide(grilleInvisible, TAILLE_GRILLE);
    remplissageGrilleVide(grilleVisible, TAILLE_GRILLE);
    creationBateau(grilleInvisible);
    
    

    //    *************      J O U E R   L A   P A R T I E      ************
    while (true)
    {
        afficherRegles();
        afficherCoordoneesBateau(grilleInvisible, TAILLE_GRILLE);
        afficherTableauCarreDeCaracteres(grilleVisible, TAILLE_GRILLE);

        if (nombreDeTouches == 4)
        {
            cout <<  endl << "B A T E A U   C O U L E  en " << compteurTentatives << " tirs" << endl; 
            break;
        }

        if (saisieCoordonnees(compteurTentatives, colonneSaisie, ligneSaisie))
        {
            cout << endl << "A B A N D O N   bateau touche " << nombreDeTouches << " fois sur " << compteurTentatives << endl;
            break;
        }

        modifGrille(grilleVisible, grilleInvisible, colonneSaisie, ligneSaisie, compteurTentatives, nombreDeTouches);        
        effacer();
    }
        
    return 0;
}





























