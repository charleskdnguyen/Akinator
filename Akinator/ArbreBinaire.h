#pragma once
#ifndef ARBREBINAIRE_H
#define ARBREBINAIRE_H

#include "NoeudBinaire.h"
#include <list>

class ArbreBinaire {

public:
	//Constructeur de l'arbre
	ArbreBinaire();

	ArbreBinaire(const ArbreBinaire& ab);

	//Destructeur de l'arbre
	~ArbreBinaire();

	//Operateur �gale de l'arbre
	const ArbreBinaire& operator=(const ArbreBinaire& ab);

	//Ins�rer une nouvelle question
	void insertionQuestionReponse(string question, string reponse);

	//si le prochain noeud existe
	bool questionReponseExiste();

	//on se place a la racine
	void demarrerJeu();

	//on r�pond oui
	void repondOui();

	//on r�pond non
	void repondNon();

	//le noeud a des fils
	bool questionValide();

	//le noeud a aucun fils
	bool reponseValide();

	//si le noeud a droite existe
	bool questionArbreDroiteInvalide();

	//On obtient la question a la racine
	NoeudBinaire* questionDemarrage();

	//pose la question ou la r�ponse
	const string poseQuestionReponse() const;

	//sauvegarde du fichier
	void sauvegarderFichier();

	//sauvegarde chaque noeud recursivement
	void sauvegarderRecursif(NoeudBinaire* n, ostream &fichier, 
		int niveau, string direction);

	//on set le nom du fichier
	void setNomFichier(string& nomFichier);

	//on r�cup�re le nom du fichier
	string& getNomFichier();

	//on construit l'arbre
	void construireArbre(list<list<string>>& listeQuestion);

	//fonction r�cursive pour construire l'arbre
	void construireRecursif(NoeudBinaire*& n, int niveau, string direction, 
		list<list<string>>& listeQuestion);


private:
	NoeudBinaire* racine;
	string nomFichier;
	mutable NoeudBinaire* curseur;
	void detruireRecursif(NoeudBinaire* n);
};


#endif