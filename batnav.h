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

#include <iostream>
using namespace std;

const unsigned short int TAILLE_GRILLE = 9;
const unsigned short int TAILLE_BATEAU = 4;

const unsigned short int A_ASCII = 65;
const unsigned short int I_ASCII = 73;
const unsigned short int AROBASE_ASCII = 64;

const unsigned short int UN_ASCII = 49;
const unsigned short int NEUF_ASCII = 57;

/* ----------------------------------- A F F I C H A G E S ----------------------------------- */
/**
 * @brief Affiche les règles du jeu
 * 
 */
void afficherRegles();
/**
 * @brief Affiche les coordonnées des 4 emplacements du bateau
 * 
 * @param grille Grille à parcourir dans ce sous-programme 
 */
void afficherCoordoneesBateau(const bool grille[][TAILLE_GRILLE]);
/**
 * 
 * @brief Affiche un tableau carré de caractères de tailleTab
 * 
 * @param grille tableau de caractères, constituée de ‘.’, ‘O’ et d'espaces.
 */
void afficherGrille(char grille[][TAILLE_GRILLE]);
/**
 * @brief Affiche une ligne de tableau de nombreCases
 * 
 * @param nombreCases Nombre d’espacements de la forme +---+
 */
void afficherLigne(unsigned int nombreCases);

/* ----------------------------- I N I T T I A L I S A T I O N S ----------------------------- */
/**
 * @brief Remplit le tableau de tailleTab d'espaces
 * 
 * @param tab tableau de caractère à initialiser
 */
void remplissageTableauCaracteresVide(char tab[][TAILLE_GRILLE]);
/**
 * @brief Remplit le tableau de tailleTab de booléens faux
 * 
 * @param tab tableau de booléens à initialiser
 */
void remplissageTableauBooleensFaux(bool tab[][TAILLE_GRILLE]);
/**
 * @brief Place un bateau aléatoirement dans la grille
 * 
 * @param grille grille contenant le bateau
 */
void creationBateau(bool grille[][TAILLE_GRILLE]);

/* -------------------------------- I N T E R R A C T I O N S -------------------------------- */
/**
 * @brief Saisie des coordonnées sous forme "A5" et renvoit la ligne et la colonne associés. Renvoit faux si le joueur abandonne (a entré @@)
 * 
 * @param tentatives Nombre de tentatives(tirs) effectués par l’utilisateur
 * @param colonneNumero Colonne saisie par l’utilisateur
 * @param ligne Ligne saisie par l’utilisateur
 * @return true 
 * @return false 
 */
bool saisieCoordonnees(unsigned short int &tentatives, unsigned short int &colonneNumero, unsigned short int &ligne);

/* ---------------------------------- C O N T R O L E U R S ---------------------------------- */
/**
 * @brief indique si le caratère saisit est une lettre 
 * 
 * @param car Caractère à vérifier
 * @return true 
 * @return false 
 */
bool estUneLettre(char car);
/**
 * @brief indique si le caratère saisit est un nombre
 * 
 * @param car Caractère à vérifier
 * @return true 
 * @return false 
 */
bool estUnNombre(char car);
/**
 * @brief indique si les deux premières lettre contiennent @@
 * 
 * @param saisie Saisie du joueur stockée dans cette variable avant la traduction 
 * @return true 
 * @return false 
 */
bool veutAbandonner(string saisie);

/* ---------------------------------- C O N V E R T I S S E U R S ---------------------------------- */
/**
 * @brief traduit un caractère sous forme ASCII en une nombre correspondant aux coordonnées
 * 
 * @param car Caractère à traduire
 * @return int 
 */
int asciiVersCoordonee(char car);
/**
 * @brief convertie des coordonées entières en coordonées ascii Ascii
 * 
 * @param nombre //Nombre à transformer en caractère Ascii
 * @return string 
 */
string coordonneesVersAscii(int ligne, int colonne);

/* --------------------------------- M O D I F I C A T E U R S-------------------------------- */
/**
 * @brief Modifie la grille pour rajouter un "." ou un "O" en fonction de la ligne et colonne de la case saisie et envoit un message
 * 
 * @param grilleAffiche Grille visible par l’utilisateur
 * @param grilleCache Grille contenant le bateau
 * @param colonne Colonne ciblée par l’utilisateur
 * @param ligne Ligne ciblée par l’utilisateur
 * @param compteurTir Compteur de tir effectué par l’utilisateur
 * @param compteurTouche Nombre de fois où l’utilisateur a touché le bateau
 */
void modifGrille(char grilleAffiche[][TAILLE_GRILLE], bool grilleCache[][TAILLE_GRILLE], unsigned short int colonne, unsigned short int ligne, unsigned short int &compteurTir, unsigned short int &compteurTouche);


#endif