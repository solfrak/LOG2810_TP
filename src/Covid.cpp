#include "Covid.h"
#include <iostream>
#include <fstream>

void Covid::loadDoc(){
    std::ifstream myfileIndividu;
    std::ifstream myfileContact;
    myfileIndividu.open("src/Individus.txt", std::ios::in);
    
    std::string line1;
    std::string line2;

    while(myfileIndividu.peek() != EOF){
        getline(myfileIndividu, line1, ',');
        getline(myfileIndividu, line2);
        bool isInfected = false;
        if(line2[0] == '1'){
            isInfected = true;
        }
    
        this->individus.push_back(std::make_unique<individue>(individue(line1, isInfected)));
    }
    myfileIndividu.close();

    myfileContact.open("src/Contacts.txt", std::ios::in);
    
    while(myfileContact.peek() != EOF){
        getline(myfileContact, line1, ' ');
        float dist;
        myfileContact >> dist;
        getline(myfileContact, line2);
        std::cout << dist << std::endl;
        
        this->contacts.push_back(std::make_unique<Contact>(Contact(line1, line2, dist)));
    }
    myfileContact.close();
}

individue* Covid::getIndividus(int index){
    return this->individus.at(index).get();
}

Contact* Covid::getContact(int index){
    return this->contacts.at(index).get();
}

void Covid::afficherGrapheExposition(){

}