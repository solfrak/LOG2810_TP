#pragma once
#include <string>
#include <vector>
#include <memory>

/**
 * @brief Classe qui gere les states
 * 
 */
class state
{
private:
    char transition_;
    
public:
    
    std::string etat_;
    bool estFinal_;
    int NbRecherches = 0;

    int nbWord = 0;
    bool estTop10 = false;

    std::vector<std::unique_ptr<state>> listConnection;
    state(char, std::string,  bool);
    void print();
    state* ajouter(char, std::string, bool);
    void increment();
    state* getNextState(char);
    std::string getEtat();
    char getTransition();
    int updateNbWord();

    void printStat();
};
