#pragma once
#include "state.h"
#include <iostream>
#include <vector>
#include <fstream>

/**
 * @brief Classe cree et gere les automates du jeu 
 * 
 */
class Jeu
{
private:
public:

    std::unique_ptr<state> stateStart =std::make_unique<state>(state(' ', " ", false));
    std::vector<state*> ListMotRecherche;

    void creerAutomate();
    void createState(std::string);
    void saisirMot();
    void updateNbWord();

    void afficherStatistique();

    void AjouterMotListe(state*);
    void updateTop();

};

