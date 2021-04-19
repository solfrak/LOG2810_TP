#include "state.h"
#include <iostream>


state::state(std::string etat, char transition, bool estFinal) : etat_(etat), transition_(transition), estFinal_(estFinal)
{
}

void state::print()
{
    if(this->estFinal_){
        std::cout << this->getEtat() << std::endl;
    }
    else{
        for(auto& it : listConnection){
            it->print();
        }
    }
}

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

std::string state::getEtat(){
    return etat_;
}

void state::increment()
{
    NbRecherches++;
}

state* state::getNextState(char c)
{
  
    for(int i=0; i < listConnection.size(); i++){
        state* test = listConnection.at(i).get();
        if(test->getTransition() == c){
            return test;
        }
    }
    return nullptr;
}

char state::getTransition(){
    return transition_;
}

state* state::ajouter(std::string etat, char c, bool bb){
    listConnection.push_back(std::make_unique<state>(etat,c,bb));
    return listConnection.back().get();
}


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

