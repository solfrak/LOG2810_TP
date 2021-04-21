#include "Jeu.h"
#include <cstring>
#include <algorithm>

/**
 * @brief Cree les automates a partir d'un lexique
 * 
 */
void Jeu::creerAutomate()
{
    std::cout << "Entrer le nom du lexique\n";
    std::string nom = "Lexique.txt";
    std::cin >> nom;
    std::ifstream lexique;
    lexique.open(nom, std::ios::in);

    if(!lexique.is_open()){
        std::cout << "Une erreur est survenue dans la lecture du fichier. Veuillez réessayer.\n";
        return;
    }
    stateStart.get()->listConnection.clear();
    ListMotRecherche.clear();
    while (lexique.peek() != EOF)
    {
        std::string line;
        lexique >> line;
        createState(line);
    }

    stateStart.get()->updateNbWord();
    std::cout << "Le fichier a bien été lu\n";
}

/**
 * @brief Cree les etats de l'automate
 * 
 * @param word Mot dont les etats doivent etre cree
 */
void Jeu::createState(std::string word)
{
    char letter;
    state* currentState = stateStart.get();
    std::string etat = "";
    for (size_t i = 0; i < word.length(); i++)
    {
        letter = word[i];
        if(i != word.length()-1)
        {
            if(currentState->getNextState(letter) != nullptr)
            {
                etat+=letter;
                currentState = currentState->getNextState(letter);
            }
            else
            {
                etat += letter;
                currentState =  currentState->ajouter(letter, etat, false);

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
                currentState->ajouter(letter, etat, true);
                
            }
        }
        
    }
}

/**
 * @brief Methode affichant les prochains mot selon l'entree
 * 
 */
void Jeu::saisirMot(){
    bool motTrouv = false;
    state* currentState = stateStart.get();
    
    while(!motTrouv){
        std::cout << "Entrer une lettre\n";

        char input;
        std::cin >> input;
        currentState = currentState->getNextState(input);
        

        if(currentState->nbWord == 1){
            std::cout << "Le mot que vous cherchez est: ";
            currentState->print();
            motTrouv = true;
            
            while(!currentState->estFinal_){
                currentState = currentState->listConnection.at(0).get();
            }
            currentState->increment();
            AjouterMotListe(currentState);
            updateTop();
            
            
        }
        else{
            currentState->print();
        }
    }
}

/**
 * @brief affiche le top 10 des mots les plus utilisé
 * 
 */
void Jeu::afficherStatistique(){
    stateStart.get()->printStat();

    std::cout << "Les 10 mots les plus recherché sont:\n";
    for(int i =0; i < 10; i++){
        std::cout << ListMotRecherche[i]->etat_ << std::endl;
    }
}

/**
 * @brief Ajoute le mot rechercher par l'utilisateur dans la liste
 * 
 * @param s l'etat finale utilisé
 */
void Jeu::AjouterMotListe(state* s){
    for(auto& it : ListMotRecherche){
        if(it->etat_ == s->etat_){
            return;
        }
    }
    ListMotRecherche.push_back(s);
}

/**
 * @brief trie la liste par le nombre de fois qu'un mot a été cherché 
 *        et affecte true si l'index se situe dans le top 10
 * 
 */
void Jeu::updateTop(){
    std::sort(ListMotRecherche.begin(), ListMotRecherche.end(), [](const auto* o1, const auto o2){
        return o1->NbRecherches > o2->NbRecherches;
    });
    for(size_t i =0; i < ListMotRecherche.size(); i++){
        if(i < 10){
            ListMotRecherche.at(i)->estTop10 = true;
        }
        else{
            ListMotRecherche.at(i)->estTop10 = false;
        }
    }

}