#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ostream>
#include <Windows.h>
#include <list>
#include <clocale>
#include <iomanip>
#include "NoeudBinaire.h"
#include "UtilitairesES.h"
#include "ArbreBinaire.h"


using namespace std;
void afficherMenu();
int determinerChoix();
void nouvelleQuestion(ArbreBinaire& ab, list<list<string>>& listeQuestion);
void demanderQuestion(ArbreBinaire& ab, list<list<string>>& listeQuestion);
string aiQuestionne(ArbreBinaire& ab, list<list<string>>& listeQuestion);
void aiReponse(ArbreBinaire& ab, list<list<string>>& listeQuestion);
void ouvertureFichier(ArbreBinaire& ab, list<list<string>>& listeQuestion);

void main() {
	list<list<string>> listeQuestion;
	ArbreBinaire ab;
	int choix;
	bool quitter = false;

	//lit le fichier question.txt
	ouvertureFichier(ab, listeQuestion);

	//construit l'arbre à partir des questions et réponses dans le fichier
	ab.construireArbre(listeQuestion);

	setlocale(LC_ALL, "");

	//tant que le joueur ne quitte pas le jeu
	while (!quitter)
	{
		afficherMenu();
		choix = determinerChoix();
		switch (choix)
		{
		case 1:
			demanderQuestion(ab, listeQuestion);
			break;
		case 2:
			quitter = true;
			ab.sauvegarderFichier();
			//sauvegarde des données

			break;
		}
	}
	//sauvegarder et ecraser les données sur les equipes
	system("pause");
}

//affichage du menu
void afficherMenu() {
	cout << endl << "Veuillez choisir parmi les choix suivants:\n"
		<< "1) Jouer une nouvelle partie\n"
		<< "2) Quitter\n"
		<< endl;
}

//lecture de l'entré de l'utilisateur
int determinerChoix() {
	int choix = lireEntier("Entrez votre choix (entre 1 et 2)", 1, 2);
	return choix;
}

//on insert une nouvelle question et réponse
void nouvelleQuestion(ArbreBinaire& ab, list<list<string>>& listeQuestion) {

	string question;
	string reponse;

	//devrait mettre cin.ignore avec getline si la reponse est plus que 1 mots
	cin.ignore();
	cout << "Quel est la reponse? ";
	getline(cin, reponse);

	//cin.ignore();
	cout << "Comment puis-je la distinguer? ";
	getline(cin, question);

	ab.insertionQuestionReponse(question, reponse);
}

//démarrage du jeu
void demanderQuestion(ArbreBinaire& ab, list<list<string>>& listeQuestion) {

	ab.demarrerJeu();

	//si la racine est nulle
	if (ab.questionDemarrage() == nullptr) {
		cout << "Je ne sais pas" << endl;
		nouvelleQuestion(ab, listeQuestion);
	}
	else {

		string reponse;

		//tant qu'il y a une question ou une réponse
		while (ab.questionReponseExiste()) {

			//si le noeud est une reponse
			if (ab.reponseValide() == true) {
				aiReponse(ab, listeQuestion);
				break;
			}

			//si le noeud est une question
			if (ab.questionValide() == true) {
				reponse = aiQuestionne(ab, listeQuestion);
				if (reponse == "O") {
					ab.repondOui();
				}
				else if (reponse == "N") {
					if (ab.questionArbreDroiteInvalide()) {
						cout << "Je ne sais pas" << endl;
						nouvelleQuestion(ab, listeQuestion);
						ab.repondNon();
						break;
					}
					else {
						ab.repondNon();
					}
				}
			}
		}
	}
}

//on pose la question au joueur
string aiQuestionne(ArbreBinaire& ab, list<list<string>>& listeQuestion) {
	string reponse;
	do {
		cout << ab.poseQuestionReponse() << " (O/N): ";
		
		cin >> reponse; // oui ou non
	} while (!((reponse == "O") || (reponse == "N")));
	return reponse;
}

//si c'est une réponse, le AI donne la réponse
void aiReponse(ArbreBinaire& ab, list<list<string>>& listeQuestion) {
	string confirmation;
	cout << ab.poseQuestionReponse() << endl;
	cout << "Ai-je raison? (O/N): ";

	cin >> confirmation;
		//si le AI a raison
		if (confirmation == "O") {
			cout << "J'ai trouvé!!" << endl;
		}
		//si le AI a tort
		else if (confirmation == "N") {
			cout << "J'ai perdu.." << endl;;
			nouvelleQuestion(ab, listeQuestion);
		}
}

//ouverture du fichier pour lire les questions et réponses
void ouvertureFichier(ArbreBinaire& ab, list<list<string>>& listeQuestion) {
	string fichierTxt = "questions.txt";
	ifstream fichierQuestion(fichierTxt);
	ab.setNomFichier(fichierTxt);

	string chaineQuestion;
	string chaineDirection;
	string chaineNiveau;

	if (fichierQuestion.fail()) {
		cout << "L'ouverture n'a pas reussi." << endl;
		return;
	}

	while (!fichierQuestion.eof()) {

		list<string> ligne;
									 
		getline(fichierQuestion, chaineNiveau, ' ');

		//si la ligne est vide
		if (chaineNiveau.empty()) {
			break;
		}

		ligne.push_back(chaineNiveau);

		getline(fichierQuestion, chaineDirection, ' ');
		ligne.push_back(chaineDirection);

		getline(fichierQuestion, chaineQuestion);
		ligne.push_back(chaineQuestion);

		//on insert la liste qui contient les 3 éléments dans une liste general
		listeQuestion.push_back(ligne);
	}
	fichierQuestion.close();
}