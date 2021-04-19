#include <iostream>
#include <bits/stdc++.h>
#include <climits>
#include "Covid.h"
#include <vector>
#include "Jeu.h"
#define INFINITY 9999
using namespace std;

//  void CreerGraphe(){
// 	 t.creerGrapheExposition;
//  }
//  void AfficherGraphe(){
// 	 t.afficherGrapheExposition;
//  }
//  AfficherNotification(){
// 	 t.
//  }





void MenuJeuInstructif()
{
	Jeu monjeu;
	bool menuJeu = true;
	while(menuJeu){
		char option;
		cout << "\n\n(a) Creer Automate.\n" << "(b) Saisir mot.\n" << "(c) Afficher statistique\n" << "(d) Quitter.\n";
		cin >> option;
		switch(option){
		case 'a':
			monjeu.creerAutomate();
			break;

		case 'b':
			monjeu.saisirMot();
			break;
			
		case 'c':
			monjeu.afficherStatistique();
			break;
		case 'd':
			menuJeu = false;
			break;
		
		default:
			cout << "Entre invalide!\n";
			break;
		}
	}
}


void MenuAlerteCovid()
{	
	Covid t;
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

				if(t.findIndexIndividu(nom) != -1){
					if(t.NotifierExposition(nom)){
						cout << "Vous avez ete exposer au cours des 14 derniers jours\n";
					}
					else {
						cout << "\nAucune exposition detectee\n";
					}
				}
				else{
					cout << "L'individu que vous recherchez ne se trouver pas dans notre base de données. Veuillez réessayer\n";
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

int main()
{
	char test = -61;
	char test2 = -81;
	std::cout << test << test2;
	while (true)
	{
		cout << "\n\nAppuyer sur:\n(a): Alerte COVID.\n(b): Jeu Intructif.\n(c): Quitter.\n";
		char input = 'b';
		cin >> input;

		switch (input)
		{
		case 'a':
			MenuAlerteCovid();
			break;

		case 'b':
			MenuJeuInstructif();
			break;

		case 'c':
			return 0;
			break;

		default:
			cout << "Entre invalide!\n";
			break;
		}
	}
}
