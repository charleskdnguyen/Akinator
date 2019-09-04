#include "ArbreBinaire.h"
#include "NoeudBinaire.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

ArbreBinaire::ArbreBinaire() :
	racine(nullptr),
	curseur(nullptr)
{
}

ArbreBinaire::ArbreBinaire(const ArbreBinaire& ab) {
}

ArbreBinaire::~ArbreBinaire() {
	detruireRecursif(racine);
}

const ArbreBinaire& ArbreBinaire::operator=(const ArbreBinaire& ab) {
	detruireRecursif(racine);
	return *this;
}

void ArbreBinaire::insertionQuestionReponse(string question, string reponse) {
	
	//SI LA RACINE EST VIDE
	if (racine == nullptr) {
		//la premiere question
		NoeudBinaire* nouvelleQuestion = new NoeudBinaire();
		nouvelleQuestion->setElement(question);
		racine = nouvelleQuestion;

		//on set la reponse a gauche
		NoeudBinaire* nouvelleReponse = new NoeudBinaire();
		nouvelleReponse->setElement(reponse);

		//on lie la reponse a la racine
		nouvelleQuestion->setGauche(nouvelleReponse); 
		curseur = racine;
	}

	else if (curseur->getGauche() == nullptr) {
		
		NoeudBinaire* ancienReponse = new NoeudBinaire();
		NoeudBinaire* nouvelleReponse = new NoeudBinaire();

		//on stocke l'ancien reponse dans un noeud temporaire
		ancienReponse->setElement(curseur->getElement());
		//on lie l'ancien reponse au noeud pere
		
		nouvelleReponse->setElement(reponse);
		curseur->setGauche(nouvelleReponse);
		curseur->setElement(question);
		curseur->setDroite(ancienReponse);
	}
	else if (curseur->getDroite() == nullptr 
		&& curseur->getGauche() != nullptr) {

		NoeudBinaire* nouveauQuestion = new NoeudBinaire();
		NoeudBinaire* nouvelleReponse = new NoeudBinaire();

		nouvelleReponse->setElement(reponse);
		nouveauQuestion->setElement(question);

		curseur->setDroite(nouveauQuestion);
		nouveauQuestion->setGauche(nouvelleReponse);
	}
}

bool ArbreBinaire::questionArbreDroiteInvalide() {
	bool mauvaiseReponse = false;

	if (curseur->getDroite() == nullptr) {
		mauvaiseReponse = true;
	}
	return mauvaiseReponse;
}

bool ArbreBinaire::questionValide() {
	bool question = false;

	if (curseur->getGauche() != nullptr) {
		question = true;
	}
	return question;
}

bool ArbreBinaire::reponseValide() {
	bool reponse = false;

	if (curseur->getGauche() == nullptr) {
		reponse = true;
	}
	return reponse;
}

void ArbreBinaire::demarrerJeu() {
	curseur = racine;
}

void ArbreBinaire::repondOui() {
	curseur = curseur->getGauche();
}

void ArbreBinaire::repondNon() {
	curseur = curseur->getDroite();
}

const string ArbreBinaire::poseQuestionReponse() const {
	return curseur->getElement();
}

NoeudBinaire* ArbreBinaire::questionDemarrage() {
	return racine;
}

bool ArbreBinaire::questionReponseExiste() {
	return curseur != nullptr;
}

void ArbreBinaire::detruireRecursif(NoeudBinaire* n) {
	if (n != nullptr) {
		detruireRecursif(n->getGauche());
		detruireRecursif(n->getDroite());
		delete n;
	}
}

void ArbreBinaire::setNomFichier(string& nomFichier) {
	this->nomFichier = nomFichier;
}

string& ArbreBinaire::getNomFichier() {
	return nomFichier;
}

void ArbreBinaire::sauvegarderFichier() {
	ofstream fichier;
	fichier.open(nomFichier);

	if (fichier.is_open()) {
		sauvegarderRecursif(racine, fichier, 0, "R");
	}
	fichier.close();
}

void ArbreBinaire::sauvegarderRecursif(NoeudBinaire* n, ostream& fichier, 
	int niveau, string direction) {

	if (n != nullptr) {
		fichier << niveau << ' ' << direction << ' ' << n->getElement() << endl;
		if (n->getGauche() != nullptr) {
			sauvegarderRecursif(n->getGauche(), fichier, niveau + 1, "G");
		}
		if (n->getDroite() != nullptr) {
			sauvegarderRecursif(n->getDroite(), fichier, niveau + 1, "D");
		}
	}
}


void ArbreBinaire::construireArbre(list<list<string>>& listeQuestion) {
	construireRecursif(racine, 0, "R", listeQuestion);
}
//int niveau, string direction, string elem
void ArbreBinaire::construireRecursif(NoeudBinaire*& n, int niveau, 
	string direction, list<list<string>>& listeQuestion) {

		if (!listeQuestion.empty()) {
			if (niveau == stoi(listeQuestion.front().front())) {
				//pop le niveau
				listeQuestion.front().pop_front();

				if (direction == (listeQuestion.front().front())) {
					//pop la direction
					listeQuestion.front().pop_front();

					n = new NoeudBinaire();
					n->setElement(listeQuestion.front().front());
					//cout << n->getElement() << endl;
					listeQuestion.pop_front();

					construireRecursif(n->gauche, niveau + 1, 
						"G", listeQuestion);

					construireRecursif(n->droite, niveau + 1, 
						"D", listeQuestion);

				}

			}
		}
}