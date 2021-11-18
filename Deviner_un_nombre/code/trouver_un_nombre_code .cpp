/*
 Programme : Jeu deviner un nombre 
 But :  Ce jeu crée un nombre dans un interval saisi par l'utilisateur qu'il doit trouver en un nombre de tentatives rentré par celui-ci 
 Date de dernière modification : 29/09/2021
 Auteur : OIER CESAT et NICOLAS DELAHAIE
 Remarques : Ce code est fournit avec les extentions précisées dans le document joint. 
*/      


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main (void)
{
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  V A R I A B L E S  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

short int nombreTentatives;             // nombre de tentatvies saisi par l'utilisateur 
int nombreMystere;                      // nombre que l'utilisateur doit trouver    
short unsigned int  i;                  // tentative actuelle
int nombreSaisi;                        // nombre saisi par l'utilisateur lors de sa tentative
int borneInf;                           // borne inférieur pour le nombre mystère  
int borneSup;                           // borne supérieur pour le nombre mystère
bool erreur;                            // booléen servant à identifier un erreur 
bool nombreTrouve;                      // booléen servant à déterminer si le nombre est trouvé

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  T R A I T E M E N T S °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  I N I T I A L I S A T I O N  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
        
                // Saisir les donées
        cout << "Le jeux consiste a chercher un nombre en un nombre de tentatives limitees." << endl << "A chaque tentative, vous saurez si le nombre saisi est trop grand ou trop petit par rapport au nombre mystere." << endl << "Vous saisirez l'intervalle du nombre mystere."<< endl << "Bonne chance !" << endl << endl;
        //clavier >> saisir nombreTentatives >> nombreTentaives
        cout << "Saisissez le nombre de tentatives : ";
        cin >> nombreTentatives; 
        //clavier >> saisir borneInf >> borneInf
        cout << "Saisissez la borne inferieure : ";
        cin >> borneInf;
        //clavier >> saisir borneSup >> borneSup
        cout << "Saisissez la borne superieure : ";
        cin >> borneSup;
        
                // Creer le nombre mystere >> nombreMystere
        srand(time(NULL));
        nombreMystere = rand()%(borneSup-borneInf) + borneInf;;        // nombreMystere généré aléatoirement entre borneInf et borneSup


                // Initialisation des booléens >> nombreTrouve,erreur
        nombreTrouve=false;
        erreur=false;
   
         //°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  J O U E R  L A   P A R T I E  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

        // nombreTentatives,nombreMystere,borneInf,borneSup,i >> jouer la partie >> nombreTrouve,erreur

        if (nombreTentatives < 1 || borneInf > borneSup)        // vérification que les bornes soient cohérentes et que le nombre de tentatives soit supérieur à 1       
        {
                erreur = true;
        }

        for ( i = 1 ; i <= nombreTentatives ; i++)      // répétition de la boucle le nombre de tentatives saisies 
        {
                if ( erreur == false && nombreTrouve == false)
                {       
                        // i >> saisir un nombre >> nombreSaisi
                        cout << "Chercher entre "<< borneInf <<" et "<< borneSup << ". Tentative numero " << i << "/" << nombreTentatives << " ?";
                        cin >> nombreSaisi;

                        // borneInf,borneSup,nombreMystere,nombreSaisi,nombreTrouve >> analyse >> nombreTrouve,erreur
                        if (nombreSaisi == nombreMystere)                               // cas où nombreSaisi = nombreMystere
                        {
                                nombreTrouve = true;
                        }
                        else if (borneInf <= nombreSaisi && nombreSaisi < nombreMystere) // cas où borneInf < nombreSaisi < nombreMystere
                        {
                                cout << "Trop petit !" << endl;
                        }
                        else if (borneSup >= nombreSaisi && nombreSaisi > nombreMystere) // cas où nombreMystere < nombreSaisi < borneSup
                        {
                                cout << "Trop grand !" << endl;
                        }
                        else                                                            // cas d'erreur lorsque nombreSaisi < borneInf ou nombreSaisi > borneSup            
                        {
                                erreur = true;
                        }
                }
        }
        
        //°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  F i n a l i s e r   l a   p a r t i e  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° 

        // erreur,nombreTrouve >> Finaliser la partie 

        if (erreur == true)  // si une erreur est survenue lors du déroulement d'une partie 
        {       
                if (borneInf > borneSup) // erreur lors de la saisie des bornes 
                {
                        cout << "Erreur, les bornes sont inversees" << endl;
                }
                else if (nombreTentatives < 1) // erreur lors de la saisie du nombre de tentatives 
                {
                        cout << "Erreur, nombre de tentatives negatives" << endl;
                }
                else if (borneInf > nombreSaisi || nombreSaisi > borneSup ) // erreur lors de la saisie du nombre 
                {
                        cout << "Erreur, le nombre saisi n'est pas compris entre " << borneInf << " et " << borneSup << endl;
                }
        }

        else  // si il n'y a pas d'erreur 
        {                       
                switch (nombreTrouve)
                {
                case true:      // l'utilisateur trouve le nombre mystère 
                        cout << "Felicitation ! Vous avez trouve le nombre mystere" << endl;
                        break;
                        
                case false:     // l'utilisateur ne trouve pas la nombre mystère 
                        cout << "Bien essaye ! le nombre etait " << nombreMystere << endl;
                        break;
                }
                
        }
        
        
    return 0;
}