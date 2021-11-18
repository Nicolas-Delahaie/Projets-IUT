/*
 Programme : Jeux du pendu
 But : Le programme execute le pendu d'un mot choisi à partir d'un theme saisi en lui donnant 7 tentatives de saisie.
 Date de dernière modification : 23/10/2021
 Auteur : O. CESAT et N. DELAHAIE
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cstring>
#include "game-tools.h"
using namespace std;

int main(void)
{

    //    ****************      D E C L A R A T I O N S      ***************
    //    T Y P E S
    Couleur couleurMessage; //Couleur du message en fonction du nombre de tentatives restantes

    //    V A R I A B L E S
    unsigned short int positionLettre;                         //Position de la lettre pour parcourir les mots
    unsigned short int themeSaisi;                             //Numero du theme saisi (1, 2 ou 3)
    unsigned short int tentativesRestantes;                    //Nombre de tentatives restantes au joueur. Le jeux s'arrete à 0
    unsigned short int tentativesJouees;                       //Nombre de tentatives jouees durant la partie.
    unsigned short int longueurMot;                            //Taille du mot choisi aleatoirement
    unsigned short int dernierEmplacementLibre;                //Dernier emplacement libre dans lettresSaisies
    const unsigned short int NOMBRE_CASES = 10;                //Taille de chaque categorie
    const unsigned short int NOMBRE_LETTRES_SAISISSABLES = 26; //Taille

    bool lettreTrouve;                                                                                                                                                                                                                                                                                                                                                          //Lettre trouvee
    bool motComplete;                                                                                                                                                                                                                                                                                                                                                           //Mot complete (plus aucun tiret dans motTiret)
    bool lettreDejaSaisie;                                                                                                                                                                                                                                                                                                                                                      //Lettre deja saisie precedemment
    char lettreSaisie;                                                                                                                                                                                                                                                                                                                                                          //Lettre saisie à chaque tentative
    char lettresSaisies[NOMBRE_LETTRES_SAISISSABLES];                                                                                                                                                                                                                                                                                                                           //Tableau regroupant l'ensemnle des lettres dejà
    string MOTS[3][NOMBRE_CASES] = {"russie", "afghanistan", "vietnam", "roumanie", "finlande", "irlande", "espagne", "portugal", "croatie", "france", "dalmau", "rousseau", "laplace", "larracoechea", "gastambide", "druon", "rustici", "harajon", "aniorte", "roose", "toyota", "mercedes", "renault", "citroen", "peugeot", "ferrari", "bugatti", "fiat", "isuzu", "seat"}; //Tableau de mots regroupés en 3 catégories ( pays, profeseur, marque )
    string motMystere;                                                                                                                                                                                                                                                                                                                                                          //Mot selectionné aleatoirement en fonction d'indice
    string motTiret;                                                                                                                                                                                                                                                                                                                                                            //Mot sous forme de tableau. Composé de tiret, il se transformera en motMystere au fur et à mesure de la partie . 25 car aucun mot depasse cette longueur

    //    D E B U T   D E   L A   P A R T I E
    cout << " * * J E U  D U  P E N D U * *" << endl
         << endl;

    // -- Saisie-Verif du theme --
    while (true)
    {
        cout << "Choisissez un theme :" << endl
             << "1- Pays" << endl
             << "2- Professeur" << endl
             << "3- Marque de voiture " << endl
             << "Votre choix : ";
        cin >> themeSaisi;
        if (1 <= themeSaisi && themeSaisi <= 3)
        {
            break;
        }
        cout << endl
             << "Numero de theme incorrecte. Recommencez" << endl
             << endl;
    }

    // -- initialisations --
    motMystere = MOTS[themeSaisi - 1][random(0, NOMBRE_CASES - 1)]; //valeur aléatoire entre 0 et 9
    motTiret = motMystere;
    longueurMot = static_cast<unsigned short int>(motMystere.size());
    tentativesRestantes = 7;
    dernierEmplacementLibre = 0;
    lettreTrouve = false;
    motComplete = false;

    // -- Complétion motTiret avec des tirets --
    for (positionLettre = 0; positionLettre < longueurMot; positionLettre++) // met des tirets à la place
    {
        motTiret[positionLettre] = '-';
    }

    // -- Effacement console --
    effacer();

    //  J O U E R  L A  P A R T I E
    while ((tentativesRestantes != 0) && (motComplete == false))
    {
        cout << " * * J E U  D U  P E N D U * *" << endl
             << endl;

        // -- Definition de la couleur --
        if (tentativesRestantes == 1)
        {
            couleurMessage = rouge;
        }
        else if (tentativesRestantes > 1 && tentativesRestantes <= 3)
        {
            couleurMessage = violet;
        }
        else
        {
            couleurMessage = vert;
        }

        
        // -- affichage-Saisie lettre --
        cout << "Mot a trouver : " << motTiret << endl
             << endl;
        afficherTexteEnCouleur("Nombre de coups restants : ", couleurMessage);
        afficherNombreEnCouleur(tentativesRestantes, couleurMessage, true);
        cout << "Proposition de lettre ? ";
        cin >> lettreSaisie;

        // -- Analyse si la lettre est présente ou non et remplit motTiret--
        lettreTrouve = false;
        for (positionLettre = 0; positionLettre < longueurMot; positionLettre++)
        {
            if (lettreSaisie == motMystere[positionLettre])
            {
                lettreTrouve = true;
                motTiret[positionLettre] = lettreSaisie;
            }
        }

        // -- Analyse si la lettre a deja ete saisie --
        lettreDejaSaisie = false;
        for (positionLettre = 0; positionLettre < dernierEmplacementLibre; positionLettre++)
        {
            if (lettreSaisie == lettresSaisies[positionLettre])
            {
                lettreDejaSaisie = true;
            }
        }

        // -- Ajoute la lettre saisie --
        if (lettreDejaSaisie == false)
        {
            lettresSaisies[dernierEmplacementLibre] = lettreSaisie;
            dernierEmplacementLibre++;
        }

        // -- Affiche la reponses a la saisie --
        if (lettreTrouve == false) //Lettre non présente
        {
            tentativesRestantes = static_cast<unsigned short int>(tentativesRestantes - 1);
            if (lettreDejaSaisie)
            {
                cout << "Lettre deja saisie, toujours NON presente   :D" << endl;
            }
            else
            {
                cout << "Lettre NON presente dans le mot   :'( " << endl;
            }
        }
        else //Lettre présente
        {
            if (lettreDejaSaisie)
            {
                cout << "Lettre deja saisie, toujours presente   :/" << endl;
            }
            else
            {
                cout << "Lettre presente dans le mot   :))" << endl;
            }

            //Regarde si toutes les lettres ont ete trouvees
            motComplete = true;
            for (positionLettre = 0; positionLettre < longueurMot; positionLettre++)
            {
                if (motTiret[positionLettre] == '-')
                {
                    motComplete = false;
                }
            }
        }
        Sleep(2500); // Attend 2.5 s
        effacer();
    }

    // F I N   D E   L A   P A R T I E
    if (motComplete == true)
    {
        tentativesJouees = static_cast<unsigned short int>(8 - tentativesRestantes);
        cout << endl
             << "Bravo vous gagnez la partie en utilisant " << tentativesJouees << " tentative(s) ! " << endl;
    }

    else if (motComplete == false)
    {
        cout << endl
             << "Zut, vous avez perdu la partie !" << endl;
    }
    cout << "Le mot etait : " << motMystere << endl;
    Sleep(8000);
    return 0;
}
