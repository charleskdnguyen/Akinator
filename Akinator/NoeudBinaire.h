#ifndef NOEUD_BINAIRE_H
#define NOEUD_BINAIRE_H
#include <iostream>

using namespace std;

class NoeudBinaire {

	friend class ArbreBinaire;

public:
	//constructeur du noeud
	NoeudBinaire();

	//destructeur du noeud
	~NoeudBinaire();

	//on récupère le contenu du noeud (réponse ou question)
	const string getElement() const;

	//on récupère le contenu du noeud gauche
	const NoeudBinaire* getGauche() const;

	//on récupère le contenu du noeud gauche
	NoeudBinaire* getGauche();

	//on récupère le contenu du noeud droite
	const NoeudBinaire* getDroite() const;

	//on récupère le contenu du noeud droite
	NoeudBinaire* getDroite();

	//on insert le contenu dans le noeud
	void setElement(string element);

	//on lie le noeud avec le noeud gauche
	void setGauche(NoeudBinaire* gauche);

	//on lie le noeud avec le noeud droit
	void setDroite(NoeudBinaire* droite);

private:
	NoeudBinaire* gauche;
	NoeudBinaire* droite;
	string questionReponse;
};

#endif