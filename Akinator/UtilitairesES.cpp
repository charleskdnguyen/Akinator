#include "UtilitairesES.h"
#include <iostream>


int lireEntier(const string& message, int limiteInferieure, 
	int limiteSuperieure)
{
	int nombre = 0;
	bool valide = false;
	while (!valide)
	{
		cout << message << ": ";
		cin >> nombre;
		if (cin.fail())
		{
			cerr << "Vous devez entrer une valeur réelle !!" << endl;
		}
		else if (nombre >= limiteInferieure && nombre <= limiteSuperieure)
		{
			valide = true;
		}
		else
		{
			cerr << "Vous devez entrer une valeur entre " << limiteInferieure << " "
				<< "et " << limiteSuperieure << "." << endl;
		}
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}
	return nombre;
}


float lireReel(const string& message, float limiteInferieure, float limiteSuperieure)
{
	float nombre = 0;
	bool valide = false;
	while (!valide)
	{
		cout << message << ":";
		cin >> nombre;
		if (cin.fail())
		{
			cerr << "Vous devez entrer une valeur entière !!" << endl;
		}
		else if (nombre >= limiteInferieure && nombre <= limiteSuperieure)
		{
			valide = true;
		}
		else
		{
			cerr << "Vous devez entrer une valeur entre " << limiteInferieure << " "
				<< "et " << limiteSuperieure << "." << endl;
		}
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}
	return nombre;
}