#pragma once
#include <string>
#include "Individu.h"
class Contact
{
private:
public:
    Contact(Individu*, Individu*, float);
    void print();
    
    Individu* name1_, * name2_;
    float distance_;
};

