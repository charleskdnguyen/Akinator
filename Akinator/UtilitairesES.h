#ifndef UTILITAIRES_ES
#define UTILITAIRES_ES

/**
* Fichier qui comporte des fonctions permettant de faciliter les 
* entrées/sorties
*
* Auteur: Éric Wenaas
* Date  : 6 septembre 2016
*/

#include <string>

using namespace std;

/**
* Permet de lire un entier entre limiteInferieure et limiteSuperieure
*
* Entrée: message Le message qui sera affiché à chaque lecture
* Entrée: limiteInferieure la limite inférieure
* Entrée: limiteSuperieure la limite supérieure
* Sortie: la valeur entière lue entre limiteInferieure et limiteSuperieure
*/
int lireEntier(const string& message, int limiteInferieure, 
	int limiteSuperieure);

/**
* Permet de lire un réel entre limiteInferieure et limiteSuperieure 
* exclusivement
*
* Entrée: message Le message qui sera affiché à chaque lecture
* Entrée: limiteInferieure la limite inférieure
* Entrée: limiteSuperieure la limite supérieure
* Sortie: la valeur réelle lue entre limiteInferieure et limiteSuperieure
*/
float lireReel(const string& message, float limiteInferieure, 
	float limiteSuperieure);

#endif