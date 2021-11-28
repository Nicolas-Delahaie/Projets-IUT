/**
 * @file batNav.h
 * @author N. DELAHAIE et O. CESAT
 * @brief Entêtes du module batNav.cpp
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef BATNAV_H
#define BATNAV_H

const unsigned short int TAILLE_GRILLE = 9;

const unsigned short int A_ASCII = 65;
const unsigned short int I_ASCII = 73;

const unsigned short int AROBASE_ASCII = 64;

const unsigned short int UN_ASCII = 49;
const unsigned short int NEUF_ASCII = 57;


/**
 * @brief Affiche les règles du jeu
 * 
 */
void afficherRegles();

/**
 * @brief Remplit la grille d'espaces
 * 
 * @param grille 
 */
void remplissageGrilleVide(char grille[][TAILLE_GRILLE], unsigned short int tailleGrille);

/**
 * @brief Place un bateau aléatoirement dans la grille
 * 
 * @param grille 
 */
void creationBateau(char grille[][TAILLE_GRILLE]);

/**
 * @brief Affiche les coordonnées des 4 emplacements un bateau
 * 
 * @param grille 
 */
void afficherCoordoneesBateau(char grille[][TAILLE_GRILLE], unsigned short int TAILLE_GRILLE);

/**
 * 
 * @brief Affiche un tableau carré de caractères de tailleTab
 * 
 * @param tab 
 * @param LARGEUR 
 * @param LONGUEUR 
 */
void afficherTableauCarreDeCaracteres(char tab[][TAILLE_GRILLE], unsigned short int tailleTab);

/**
 * @brief Affiche une ligne de tableau de nombreCases
 * 
 * @param nombreCases 
 */
void afficherLigne(unsigned int nombreCases);

/**
 * @brief Saisie des coordonnées sous forme "A5" et renvoit la ligne et la colonne associés. Renvoit faux si le joueur abandonne (a entré @@)
 * 
 * @param tentatives 
 * @param colonneNumero 
 * @param ligne 
 * @return true 
 * @return false 
 */
bool saisieCoordonnees ( unsigned short int & tentatives, unsigned short int  & colonneNumero, unsigned short int & ligne);

/**
 * @brief Modifie la grille pour rajouter un "." ou un "O" en fonction de la ligne et colonne de la case saisie et envoit un message
 * 
 * @param grille 
 * @param ligneCase 
 * @param coolonneCase 
 */
void modifGrille ( char grilleAffiche [][TAILLE_GRILLE], char grilleCache [][TAILLE_GRILLE], unsigned short int colonne, unsigned short int ligne, unsigned short int & compteurTir, unsigned short int & compteurTouche);


#endif 
