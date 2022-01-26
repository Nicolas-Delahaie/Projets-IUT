
/**
 * @file batNav.cpp
 * @author N. DELAHAIE et O. CESAT
 * @brief Module contenant les opérations pour jouer à la bataille navale. 
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

/* ----------------------------------- A F F I C H A G E S ----------------------------------- */
void afficherRegles()
{
    cout << "B A T A I L L E   N A V A L E " << endl;
    cout << "Le joueur doit couler un bateau de "<< TAILLE_BATEAU <<" cases " << endl
         << "(vertical ou horizontal ou diagonal)." << endl
         << endl;
}

void afficherCoordoneesBateau(const bool grille[][TAILLE_GRILLE])
{
    unsigned short int ligne;   //Ligne actuellement parcourue
    unsigned short int colonne; //Colonne actuellement parcourue
    string coordonnee;          //Variable où sera stockée le message des coordonnées à afficher

    cout << "Bateau =  ";

    //Parcourt chaque emplacement du tableau
    for (ligne = 0; ligne < TAILLE_GRILLE; ligne++)
    {
        for (colonne = 0; colonne < TAILLE_GRILLE; colonne++)
        {
            if (grille[ligne][colonne])

            {
                //Affiche la coordonnée
                coordonnee = coordonneesVersAscii(ligne, colonne);
                cout << "(" << coordonnee[0] << "," << coordonnee[1] << ")  ";
            }
        }
    }
}

void afficherGrille(char grille[][TAILLE_GRILLE])
{
    for (unsigned short int ligne = 0; ligne < TAILLE_GRILLE + 1; ligne++)
    {
        if (ligne == 0) //Affichage première ligne
        {
            afficherLigne(TAILLE_GRILLE+1);
            cout << "|   |";

            //Affichage des lettres de A à I
            for (unsigned int i = 0; i < TAILLE_GRILLE; i++)
            {
                cout << " " << char(A_ASCII + i) << " |";
            }
        }
        else //Affichage autres lignes
        {
            for (unsigned short int colonne = 0; colonne < TAILLE_GRILLE + 1; colonne++)
            {
                if (colonne == 0) //Affichage première colonne
                {
                    if (ligne < TAILLE_GRILLE+1)
                    {
                        cout << "| " << double(ligne) << " |";
                    }
                    else
                    {
                        cout << "| " << double(ligne) << "|";
                    }
                }
                else //Affichage autres colonnes
                {
                    cout << " " << grille[ligne - 1][colonne - 1] << " |";
                }
            }
        }
        afficherLigne(TAILLE_GRILLE+1);
    }
}

void afficherLigne(unsigned int nombreCases)
{
    cout << endl
         << "+";
    for (unsigned int i = 0; i < nombreCases; i++)
    {
        cout << "---+";
    }
    cout << endl;
}

/* ----------------------------- I N I T T I A L I S A T I O N S ----------------------------- */

void remplissageTableauCaracteresVide(char tab[][TAILLE_GRILLE])
{
    for (unsigned int ligne = 0; ligne < TAILLE_GRILLE; ligne++)
    {
        for (unsigned int colonne = 0; colonne < TAILLE_GRILLE; colonne++)
        {
            tab[ligne][colonne] = ' ';
        }
    }
}

void remplissageTableauBooleensFaux(bool tab[][TAILLE_GRILLE])
{
    for (unsigned int ligne = 0; ligne < TAILLE_GRILLE; ligne++)
    {
        for (unsigned int colonne = 0; colonne < TAILLE_GRILLE; colonne++)
        {
            tab[ligne][colonne] = false;
        }
    }
}

void creationBateau(bool grille[][TAILLE_GRILLE])
{
    unsigned short int colonneCaseAutresBateaux;    //Colonne d’une autre case de bateau
    unsigned short int ligneCaseAutresBateaux;      //Ligne d’une autre case de bateau

    unsigned short int colonnePremiereCaseBateau;   //Ligne de la premiere case du bateau
    unsigned short int lignePremiereCaseBateau;     //Colonne de la première case du bateau

    short int decalageHorizontal;   //Décalage horizontal de la 2e case compris entre -1 et 1
    short int decalageVertical;     //Décalage vertical de la 2e case compris entre -1 et 1


    short int xmin;                 //colonne de gauche de l’encadrement du 2e point
    short int xmax;                 //colonne de droite de l’encadrement du 2e point
    short int ymin;                 //ligne du bas de l’encadrement du 2e point
    short int ymax;                 //ligne du haut de l’encadrement du 2e point

    // -- Création premier point --
    lignePremiereCaseBateau = static_cast<unsigned short int>(random(0, TAILLE_GRILLE-1));
    colonnePremiereCaseBateau = static_cast<unsigned short int>(random(0, TAILLE_GRILLE-1));
    grille[lignePremiereCaseBateau][colonnePremiereCaseBateau] = true;

    // -- Création deuxième point --
    //Inititalisation encadrement
    ymin = static_cast<short int>(lignePremiereCaseBateau - 1);
    ymax = static_cast<short int>(lignePremiereCaseBateau + 1);
    xmin = static_cast<short int>(colonnePremiereCaseBateau - 1);
    xmax = static_cast<short int>(colonnePremiereCaseBateau + 1);

    //Reduction de l'encadrement en fonction de la proximité des bords
    if (lignePremiereCaseBateau < TAILLE_BATEAU-1)
    {
        ymin = lignePremiereCaseBateau;
    }
    else if (lignePremiereCaseBateau > TAILLE_GRILLE - TAILLE_BATEAU)
    {
        ymax = lignePremiereCaseBateau;
    }
    if (colonnePremiereCaseBateau < TAILLE_BATEAU-1)
    {
        xmin = colonnePremiereCaseBateau;
    }
    else if (colonnePremiereCaseBateau > TAILLE_GRILLE - TAILLE_BATEAU)
    {
        xmax = colonnePremiereCaseBateau;
    }

    // Selection aléatoire de la 2e case dans l'encadrement
    do
    {
        ligneCaseAutresBateaux = static_cast<unsigned short int>(random(ymin, ymax));
        colonneCaseAutresBateaux = static_cast<unsigned short int>(random(xmin, xmax));
    } while ((lignePremiereCaseBateau == ligneCaseAutresBateaux) && (colonnePremiereCaseBateau == colonneCaseAutresBateaux));



    
    // -- Calcul du décalage vertical et horizontal de la 2e case par rapport à la 1ere --
    decalageVertical = static_cast<short int>(ligneCaseAutresBateaux - lignePremiereCaseBateau);
    decalageHorizontal = static_cast<short int>(colonneCaseAutresBateaux - colonnePremiereCaseBateau);

    // -- Placement des 3 autres cases du bateau --
    for (unsigned short int bombe = 0; bombe < 3; bombe++)
    {
        grille[ligneCaseAutresBateaux][colonneCaseAutresBateaux] = true;
        ligneCaseAutresBateaux = static_cast<unsigned short int>(ligneCaseAutresBateaux + decalageVertical);
        colonneCaseAutresBateaux = static_cast<unsigned short int>(colonneCaseAutresBateaux + decalageHorizontal);
    }    
}

/* -------------------------------- I N T E R R A C T I O N S -------------------------------- */
bool saisieCoordonnees(unsigned short int &tentatives, unsigned short int &ligne, unsigned short int &colonne)
{
    string saisieJoueur;    //Saisie du joueur stockée dans cette variable avant la traduction

    while (true)
    {
        cout << "Votre tir numero " << tentatives + 1 << " (ex A3) ou abandonner (@@) ? ";

        cin >> saisieJoueur;
        ligne = static_cast<unsigned short int>(asciiVersCoordonee(saisieJoueur[0]));
        colonne = static_cast<unsigned short int>(asciiVersCoordonee(saisieJoueur[1]));

        //Si l'utilisateur saisie @@ pour abandonner
        if (veutAbandonner(saisieJoueur))
        {
            return true;
        }

        //Saisies dans le bon intervalle
        else if (estUnNombre(saisieJoueur[1]) && estUneLettre(saisieJoueur[0]))
        {
            return false;
        }

        //Saisie en dehors du tableau
        else
        {
            if (!(estUneLettre(saisieJoueur[0])))
            {
                cout << "Erreur de saisie de la colonne " << endl;
            }

            if (!(estUnNombre(saisieJoueur[1])))
            {
                cout << "Erreur de saisie de la ligne " << endl;
            }
            cout << endl;
        }
    }
}

/* ---------------------------------- C O N T R O L E U R S ---------------------------------- */
bool estUnNombre(char car)
{
    int chiffre;    //Utilisé pour stocker le numéro ASCII de car

    // Conversion de car en entier
    chiffre = int(car);  

    // Verification grâce à la table ascii
    if (chiffre <= NEUF_ASCII && chiffre >= UN_ASCII)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool estUneLettre(char car)
{
    int chiffre;    //Variable utilisée pour stocker le caractère traduit

    // Conversion de car en entier
    chiffre = int(car);

    // Verification grâce à la table ascii
    if (chiffre <= I_ASCII && chiffre >= A_ASCII)
    {
        return true;
    }
    else
    {
       return false; 
    }
}

bool veutAbandonner(string saisie)
{
    if (saisie[0] == '@' && saisie[1] == '@')
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* ---------------------------------- C O N V E R T I S S E U R S ---------------------------------- */
int asciiVersCoordonee(char car)
{
    int chiffre;    //Variable utilisée pour stocker le caractère traduit

    // Initialise le chiffre en dehors de la tables ascii
    chiffre = 257; 

    //Convertit si c'est une lettre
    if (estUneLettre(car))
    {
        chiffre = (int(car) - A_ASCII);
        return chiffre;
    }

    //Convertit si c'est un nombre
    if (estUnNombre(car))
    {
        chiffre = (int(car) - UN_ASCII);
        return chiffre;
    }
    return chiffre;
}

string coordonneesVersAscii(int ligne, int colonne)
{
    string resultat;   //Variable utilisé pour stockée le résultat 

    //Initialisation de la chaîne de caractères
    resultat = "  ";

    //Convertion des entiers en caractères
    resultat[0] = char(colonne + A_ASCII);
    resultat[1] = char(static_cast<char>(ligne + UN_ASCII));
    return resultat;
}

/* --------------------------------- M O D I F I C A T E U R S-------------------------------- */

void modifGrille(char grilleAffichee[][TAILLE_GRILLE], bool grilleCachee[][TAILLE_GRILLE], unsigned short int colonne, unsigned short int ligne, unsigned short int &compteurTir, unsigned short int &compteurTouche)
{
    //Si la case n'a pas été déjà découverte
    if ((grilleAffichee[ligne][colonne] != 'O') && (grilleAffichee[ligne][colonne] != '.'))
    {
        //Case contenant bateau
        if (grilleCachee[ligne][colonne])
        {
            grilleAffichee[ligne][colonne] = 'O';
            compteurTouche++;
        }
        //Case vide
        else
        {
            grilleAffichee[ligne][colonne] = '.';
        }
        compteurTir++;
    }
}
