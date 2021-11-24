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
void affichageBateau(char grille[][TAILLE_GRILLE]);

/**
 * 
 * @brief Affiche un tableau carré de caractères de tailleTab
 * 
 * @param tab 
 * @param LARGEUR 
 * @param LONGUEUR 
 */
void afficherTableauCarreDeCharacteres(char tab[][TAILLE_GRILLE], unsigned short int tailleTab);

/**
 * @brief Affiche une ligne de tableau de nombreCases
 * 
 * @param nombreCases 
 */
void afficherLigne(unsigned int nombreCases); //OIER

/**
 * @brief Saisie des coordonnées sous forme "A5" et renvoit une ligne et uen colonne
 * 
 * @param ligne 
 * @param colonne 
 */
void saisieCoordonnees(unsigned int &ligneCase, unsigned &colonneCase);//OIER

/**
 * @brief Modifie la grille pour rajouter un "." ou un "O" en fonction de la ligne et colonne de la case saisie et envoit un message
 * 
 * @param grille 
 * @param ligneCase 
 * @param coolonneCase 
 */
void modifGrille(char grille[TAILLE_GRILLE][TAILLE_GRILLE], const unsigned int &ligneCase, const unsigned int &coolonneCase);//OIER


#endif 
