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

std::string state::getEtat(){
    return etat_;
}

void state::increment()
{
    NbRecherches++;
}

state* state::getNextState(char c)
{
    // for (auto it : listConnection)
    // {
    //     if(it->getTransition() == c){
    //         return it.get();
    //     }
    // }
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


// int state::getNbTransition(){
//     if(listConnection.size() == 0 && estFinal_){
//         return 0;
//     }
//     else{
//         int nb;
//         for(auto& it : listConnection){
//             nb += it->getNbTransition();
//         }
//         return nb;
//     }
// }