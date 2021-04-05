#include "Covid.h"
#include <iostream>
#include <fstream>

void Covid::loadDoc(){
    std::ifstream myfileIndividu;
    std::ifstream myfileContact;
    myfileIndividu.open("src/Individus.txt", std::ios::in);
    
    std::string line1;
    std::string line2;
    int i=0;
    bool test = myfileIndividu.is_open();
    while(myfileIndividu.peek() != EOF){
        getline(myfileIndividu, line1, ',');
        getline(myfileIndividu, line2);
        bool isInfected = false;
        if(line2[0] == '1'){
            isInfected = true;
        }
    
        this->individus.push_back(std::make_unique<Individu>(Individu(line1, isInfected, i++)));
    }
    myfileIndividu.close();

    myfileContact.open("src/Contacts.txt", std::ios::in);
    
    while(myfileContact.peek() != EOF){
        myfileContact >> line1;
        float dist;
        myfileContact >> dist;
        myfileContact >> line2;

        this->contacts.push_back(std::make_unique<Contact>(Contact(findIndividu(line1), findIndividu(line2), dist)));
    }
    myfileContact.close();

    loadGraph();
}

Individu* Covid::getIndividus(int index){
    return this->individus.at(index).get();
}

Contact* Covid::getContact(int index){
    return this->contacts.at(index).get();
}

void Covid::afficherGrapheExposition(){
    for(auto& it: contacts){
        it->print();
    }
}

void Covid::loadGraph(){
    graph.resize(individus.size());
    for(auto& it: graph){
        it.resize(individus.size());
    }
    //std::cout << graph.size() << '\n' << graph[0].size();
    for(int i=0; i < individus.size(); i++){
        for(int j = 0; j < individus.size(); j++){
            graph[i][j] = 0;
        }
    }

    for(auto& it : contacts){
        graph[it->name1_->getId()][it->name2_->getId()] = it->distance_;
        graph[it->name2_->getId()][it->name1_->getId()] = it->distance_;
    }

}

Individu* Covid::findIndividu(std::string name){
    for(auto& it : individus){
        if(it->getName() == name){
            return it.get();
        }
    }
    return nullptr;
}

int Covid::findIndexIndividu(std::string name){
    for(int i=0; i < individus.size(); i++){
        if(getIndividus(i)->getName() == name){
            return i;
        }
    }
    return -1;
}