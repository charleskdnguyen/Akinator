#include "NoeudBinaire.h"

NoeudBinaire::NoeudBinaire() :
	gauche(0),
	droite(0)
{

}

NoeudBinaire::~NoeudBinaire() {

}

const string NoeudBinaire::getElement() const {
	return questionReponse;
}

const NoeudBinaire* NoeudBinaire::getGauche() const {
	return gauche;
}

NoeudBinaire* NoeudBinaire::getGauche() {
	return gauche;
}

const NoeudBinaire* NoeudBinaire::getDroite() const {
	return droite;
}

NoeudBinaire* NoeudBinaire::getDroite() {
	return droite;
}

void NoeudBinaire::setElement(string element) {
	this->questionReponse = element;
}

void NoeudBinaire::setGauche(NoeudBinaire* gauche) {
	this->gauche = gauche;
}

void NoeudBinaire::setDroite(NoeudBinaire* droite) {
	this->droite = droite;
}
