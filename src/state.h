#pragma once
#include <string>
#include <vector>
#include <memory>

class state
{
private:
    std::string etat_;
    char transition_;
    int NbRecherches = 0;
    int nbTransition=0;
    
public:
    std::vector<std::unique_ptr<state>> listConnection;
    bool estFinal_;
    state(std::string, char,  bool);
    void print();
    state* ajouter(std::string, char, bool);
    void increment();
    state* getNextState(char);
    std::string getEtat();
    char getTransition();
    //int getNbTransition();
};
