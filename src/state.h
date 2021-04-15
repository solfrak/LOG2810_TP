#pragma once
#include <string>
#include <vector>
#include <memory>

class state
{
private:
    char transition_;
    
public:
    
    std::string etat_;
    int NbRecherches = 0;
    int nbWord = 0;
    bool estTop10 = false;
    std::vector<std::unique_ptr<state>> listConnection;
    bool estFinal_;
    state(std::string, char,  bool);
    void print();
    state* ajouter(std::string, char, bool);
    void increment();
    state* getNextState(char);
    std::string getEtat();
    char getTransition();
    int updateNbWord();

    void getTop(std::vector<state*>);
};
