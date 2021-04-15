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

    void creerAutomate();
    void createState(std::string);
    void saisirMot();

};

