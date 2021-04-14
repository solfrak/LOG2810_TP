#pragma once
#include <iostream>
#include <string>
#include "Covid.h"
#


using namespace std;

void MenuAlerteCovid(Covid t)
{	
	bool menuCovid = true;
	bool hasCreateExposition = false;
	while(menuCovid){
		char option;
		cout << "\n\n(a) Creer le graphe d’exposition.\n" << "(b) Afficher le graphe d’exposition.\n" << "(c) Afficher notification COVID\n" << "(d) Quitter.\n";
		cin >> option;

		switch (option)
		{
		case 'a':
			hasCreateExposition = t.creerGrapheExposition();
			break;

		case 'b':
			if(hasCreateExposition){
				t.afficherGrapheExposition();
			}
			else{
				cout << "Vous n'avez pas creer de graphe. Veuillez selectionner l'option (a) en premier\n";
			}
			break;
			
		case 'c':
			if(hasCreateExposition){
				cout << "Entrer le nom valide d'un indidu\n";
				std::string nom;
				cin >> nom;
				if(t.NotifierExposition(nom)){
					cout << "Vous avez ete exposer au cours des 14 derniers jours\n";
				}
				else {
					cout << "\nAucune exposition detectee\n";
				}
			}

			break;
		case 'd':
			menuCovid = false;
			break;
		
		default:
			cout << "Entre invalide!\n";
			break;
		}
	
	}
}