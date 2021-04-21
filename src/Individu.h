#pragma once
#include <string>
#include <vector>

/**
 * @brief Classe qui enregistre les individus et leur status
 * 
 */
class Individu
{
private:
    std::string name_;
    bool isInfected_;
    int id_;
public:
    Individu(std::string, bool, int);
    
    std::string getName(){
        return name_;
    }
    bool getIsInfected(){
        return isInfected_;
    }
    int getId(){
        return id_;
    }
};

