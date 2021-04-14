#pragma once
#include <string>
#include <vector>
#include <memory>

class state
{
private:
    std::string etat_;
    char transition_;
    std::vector<std::unique_ptr<state>> listConnection;
    int NbRecherches = 0;
    
public:
    bool estFinal_;
    state(std::string, char,  bool);
    std::string print();
    void ajouter(std::string, char, bool);
    void increment();
    state* getNextState(char);
    char getTransition();
};
