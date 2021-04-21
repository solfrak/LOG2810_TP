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
    bool isInfected_;
    std::string name_;
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

