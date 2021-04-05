#pragma once
#include "Individu.h"
#include "Contact.h"
#include <vector>
#include <memory>
class Covid
{
private:
    Individu* findIndividu(std::string);
public:
    void loadDoc();
    std::vector<std::vector<double>> graph;
    std::vector<std::unique_ptr<Individu>> individus;
    std::vector<std::unique_ptr<Contact>> contacts;

    Individu* getIndividus(int index);
    Contact* getContact(int index);
    int findIndexIndividu(std::string name);
    void creerGrapheExposition();
    void afficherGrapheExposition();
    void loadGraph();
    // void IdentifierExposition();
    // void NotifierExposition();
};
