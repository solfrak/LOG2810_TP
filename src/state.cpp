#include "state.h"

state::state(std::string etat, char transition, bool estFinal) : etat_(etat), transition_(transition), estFinal_(estFinal)
{

}

std::string state::print()
{
    // for (auto it : listConnection)
    // {
    //     if (!it->estFinal_)
    //     {
    //         return it->print();
    //     }
    //     else
    //     {
    //         return etat_; //ou etat
    //     }      
    // }
    for(int i=0; i < listConnection.size(); i++){
        state* test = listConnection.at(i).get();
    }
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

void state::ajouter(std::string etat, char c, bool bb){
    listConnection.push_back(std::make_unique<state>(etat,c,bb));
}