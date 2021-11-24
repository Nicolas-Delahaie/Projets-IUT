/**
 * @file main.cpp
 * @author N. DELAHAIE, O. CESAT
 * @brief 
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "batnav.h"
#include "game-tools.h"
using namespace std;


int main (void)
{

    //    ****************      D E C L A R A T I O N S      ***************
    //    T Y P E S 
    //    V A R I A B L E S  
    char grille[TAILLE_GRILLE][TAILLE_GRILLE];
    


    //    **************      I N I T I A L I S A T I O N      *************
    remplissageGrilleVide(grille, TAILLE_GRILLE);
    creationBateau(grille);


    cout << "B A T A I L L E       N A V A L E " << endl;
    cout << endl;
    cout << "Le joueur doit couler un bateau de 4 cases ( vertical ou horizontal ou diagonal )." << endl; 
    afficherTableauCarreDeCharacteres(grille, TAILLE_GRILLE);
    


    //    *************      J O U E R   L A   P A R T I E      ************

        
    return 0;
}





























