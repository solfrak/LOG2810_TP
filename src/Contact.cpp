#include "Contact.h"
#include <iostream>

Contact::Contact(std::string name1, std::string name2, float dist): name1_(name1), 
name2_(name2), distance_(dist){
}

void Contact::print(){
    std::cout << "(" << name1_ <<", " << name2_ << " (" << distance_ << "))\n";
    
}