#include "Contact.h"
#include <iostream>

/**
 * @brief Constructeur de la classe Contact
 * 
 * @param name1 Nom de la premiere personne
 * @param name2 Nom de la deuxieme personne
 * @param dist  Distance entre les deux personne
 */
Contact::Contact(Individu* name1, Individu* name2, float dist): name1_(name1), 
name2_(name2), distance_(dist){
}

/**
 * @brief Print le nom et la distance entre les personnes.
 * 
 */
void Contact::print(){
    std::cout << "(" << name1_->getName() <<", " << name2_->getName() << " (" << distance_ << "))\n";
    
}