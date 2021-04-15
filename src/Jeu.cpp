#include "Jeu.h"
#include <cstring>
#include <algorithm>
void Jeu::creerAutomate()
{
    std::cout << "Entrer le nom du lexique\n";
    std::string nom = "Lexique.txt";
    std::cin >> nom;
    std::ifstream lexique;
    lexique.open(nom, std::ios::in);
    while (lexique.peek() != EOF)
    {
        std::string line;
        lexique >> line;
        createState(line);
    }

    stateStart.get()->updateNbWord();
}


void Jeu::createState(std::string word)
{
    char letter;
    state* currentState = stateStart.get();
    std::string etat = "";
    for (int i = 0; i < word.length(); i++)
    {
        letter = word[i];
        // if(letter < 0){
        //     i++;
        //     letter = word[i];
        // }
        if(i != word.length()-1)
        {
            if(currentState->getNextState(letter) != nullptr)
            {
                etat+=letter;
                currentState = currentState->getNextState(letter);
               // currentState = **currentState.getNextState(letter);
                
            }
            else
            {
                etat += letter;
                currentState =  currentState->ajouter(etat, letter, false);

            }
        }
        else{
            if(currentState->getNextState(letter) != nullptr)
            {
                currentState = currentState->getNextState(letter);
            }
            else
            {
                etat+= letter;
                currentState->ajouter(etat, letter, true);
                
            }
        }
        
    }
}

void Jeu::saisirMot(){
    bool motTrouv = false;
    state* currentState = stateStart.get();
    
    while(!motTrouv){
        std::cout << "Entrer une lettre\n";

        char input;
        std::cin >> input;
        currentState = currentState->getNextState(input);
        

        if(currentState->nbWord == 1){
            std::cout << "Le mot que vous chercez est: ";
            currentState->print();
            motTrouv = true;
            
            while(!currentState->estFinal_){
                currentState = currentState->listConnection.at(0).get();
            }
            currentState->increment();
            ajouteTop(currentState);
            updateTop();
            
            
        }
        else{
            currentState->print();
        }
    }
}


void Jeu::afficherStatistique(){
    
    std::cout << "\nLes 10 mots les plus recherche sont:\n";
    for(int i =0; i < myTop.size() && i < 10; i++){
        std::cout << myTop.at(i)->etat_ << std::endl;
    }
    
}

void Jeu::ajouteTop(state* s){
    for(auto& it : myTop){
        if(it->etat_ == s->etat_){
            return;
        }
    }
    myTop.push_back(s);
}

void Jeu::updateTop(){
    std::sort(myTop.begin(), myTop.end(), [](const auto* o1, const auto o2){
        return o1->NbRecherches > o2->NbRecherches;
    });
    for(int i =0; i < myTop.size(); i++){
        if(i < 10){
            myTop.at(i)->estTop10 = true;
        }
        else{
            myTop.at(i)->estTop10 = false;
        }
    }

}