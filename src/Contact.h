#pragma once
#include <string>
#include "Individu.h"

/**
 * @brief Classe qui enregistre les contactes entre les personnes
 * 
 */
class Contact
{
private:
public:
    Contact(Individu*, Individu*, float);
    void print();
    
    Individu* name1_, * name2_;
    float distance_;
};

