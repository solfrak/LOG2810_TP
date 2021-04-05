#include "Contact.h"
#include <iostream>

Contact::Contact(Individu* name1, Individu* name2, float dist): name1_(name1), 
name2_(name2), distance_(dist){
}

void Contact::print(){
    std::cout << "(" << name1_->getName() <<", " << name2_->getName() << " (" << distance_ << "))\n";
    
}