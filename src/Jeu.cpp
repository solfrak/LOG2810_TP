#include "Jeu.h"

void Jeu::creerAutomate()
{
    std::cout << "Entrer le nom du lexique\n";
    std::string nom = "Lexique.txt";
    //std::cin >> nom;
    std::ifstream lexique;
    lexique.open(nom, std::ios::in);

    while (lexique.peek() != EOF)
    {
        std::string line;
        lexique >> line;
        createState(line);
    }
}

void Jeu::createState(std::string word)
{
    char letter;
    state* currentState = stateStart.get();
    for (int i = 0; i < word.length(); i++)
    {
        letter = word[i];
        if(i != word.length()-1)
        {
            if(currentState->getNextState(letter) != nullptr)
            {
                currentState = currentState->getNextState(letter);
               // currentState = **currentState.getNextState(letter);
                
            }
            else
            {
                std::string etat = "";
                for(int j = 0; j <= i; j++){
                    etat += word[j];
                }
                currentState->ajouter(etat, letter, false);
            }
        }
        else{
            if(currentState->getNextState(letter) != nullptr)
            {
                currentState = currentState->getNextState(letter);
            }
            else
            {
                std::string etat = "";
                for(int j = 0; j <= i; j++){
                    etat += word[j];
                }
                currentState->ajouter(etat, letter, true);
            }
        }
        
    }
}
