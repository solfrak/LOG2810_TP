#pragma once
#include "state.h"
#include <iostream>
#include <vector>
#include <fstream>


class Jeu
{
private:
public:

    std::unique_ptr<state> stateStart =std::make_unique<state>(state("", ' ', false));
    std::vector<state*> myTop;

    void creerAutomate();
    void createState(std::string);
    void saisirMot();
    void updateNbWord();

    void afficherStatistique();

    void ajouteTop(state*);
    void updateTop();

};

