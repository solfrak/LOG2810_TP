#include "state.h"
#include <iostream>

/**
 * @brief Constructeur de la classe state
 * 
 * @param etat 
 * @param transition La lettre qui permet de passer a ce state
 * @param estFinal Si le state est le dernier du mot
 */
state::state(char transition, std::string etat, bool estFinal) : transition_(transition), etat_(etat), estFinal_(estFinal)
{
}

/**
 * @brief Imprime l'état du noeud de manière récursive (passe à travers tout les autres noeuds)
 * 
 */
void state::print()
{
    if(this->estFinal_ && this->listConnection.size() == 0){
        std::cout << this->getEtat() << std::endl;
    }
    else{
        if(this->estFinal_){
            std::cout << this->getEtat() << std::endl;
        }
        for(auto& it : listConnection){
            it->print();
        }
    }
}

/**
 * @brief Affiche le nombre de fois qu'un mot a ete recherche et s'il est dans le top 10
 * 
 */
void state::printStat()
{
    if(this->estFinal_){
        std::cout << this->getEtat() << "\n\tNombre de fois recherché: " << this->NbRecherches << "\n\tEst dans le top 10: " << this->estTop10 << std::endl << std::endl;
    }
    else{
        for(auto& it : listConnection){
            it->printStat();
        }
    }
}

/**
 * @brief Retourne l'etatt
 * 
 * @return std::string 
 */
std::string state::getEtat(){
    return etat_;
}

/**
 * @brief Incrémente le nombre de recherche pas 1
 * 
 */
void state::increment()
{
    NbRecherches++;
}

/**
 * @brief Retourne le prochain etat dans lequel on sera si l'on entre un certains character
 * 
 * @param c Le char rentré pour le mot recherché
 * @return state* Le prochain etat
 */
state* state::getNextState(char c)
{
  
    for(size_t i=0; i < listConnection.size(); i++){
        state* test = listConnection.at(i).get();
        if(test->getTransition() == c){
            return test;
        }
    }
    return nullptr;
}

/**
 * @brief Retourne la transition requise pour arriver à ce noeud
 * 
 * @return char 
 */
char state::getTransition(){
    return transition_;
}

/**
 * @brief Ajoute un nouvelle état à la liste de connection et retourne le nouveau noeud
 * 
 * @param c 
 * @param etat 
 * @param bb 
 * @return state* 
 */
state* state::ajouter(char c, std::string etat, bool bb){
    listConnection.push_back(std::make_unique<state>(c,etat,bb));
    return listConnection.back().get();
}

/**
 * @brief Calcule le nombre de mots possible à partir de ce noeud et retourne le nombre
 * 
 * @return int 
 */
int state::updateNbWord(){
    if(estFinal_){
        if(listConnection.size() == 0){
            nbWord +=1;
            return nbWord;
        }
        else{
            nbWord+=1;
        }

    }

    for(auto& it : listConnection){
        nbWord += it->updateNbWord();
    }
    return nbWord;
}

