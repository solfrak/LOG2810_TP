#pragma once
#include "Individu.h"
#include "Contact.h"
#include <vector>
#include <memory>
#include "Dijkstra.h"

class Covid
{
private:
    Individu* findIndividu(std::string);
    Dijkstra d;
public:
    std::vector<std::vector<double>> graph;
    std::vector<std::unique_ptr<Individu>> individus;
    std::vector<std::unique_ptr<Contact>> contacts;

    Individu* getIndividus(int index);
    Contact* getContact(int index);
    int findIndexIndividu(std::string name);
    bool creerGrapheExposition();
    void afficherGrapheExposition();
    void loadGraph();
    bool loadDoc(std::string ind, std::string cont);
    bool IdentifierExposition(std::string);
    bool NotifierExposition(std::string);
};
