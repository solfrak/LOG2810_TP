#include "Covid.h"
#include <iostream>
#include <fstream>

bool Covid::loadDoc(std::string ind, std::string cont)
{
    std::ifstream myfileIndividu;
    std::ifstream myfileContact;
    myfileIndividu.open(ind, std::ios::in);

    std::string line1;
    std::string line2;
    int i = 0;
    if (!myfileIndividu.is_open()) return false;

    while (myfileIndividu.peek() != EOF)
    {
        getline(myfileIndividu, line1, ',');
        getline(myfileIndividu, line2);
        bool isInfected = false;
        if (line2[0] == '1')
        {
            isInfected = true;
        }

        this->individus.push_back(std::make_unique<Individu>(Individu(line1, isInfected, i++)));
    }
    myfileIndividu.close();

    myfileContact.open(cont, std::ios::in);
    if (!myfileContact.is_open()) return false;
    
        while (myfileContact.peek() != EOF)
        {
            myfileContact >> line1;
            float dist;
            myfileContact >> dist;
            myfileContact >> line2;

            this->contacts.push_back(std::make_unique<Contact>(Contact(findIndividu(line1), findIndividu(line2), dist)));
        }
    myfileContact.close();

    loadGraph();
    return true;
}

Individu *Covid::getIndividus(int index)
{
    return this->individus.at(index).get();
}

Contact *Covid::getContact(int index)
{
    return this->contacts.at(index).get();
}

void Covid::afficherGrapheExposition()
{
    for (auto &it : contacts)
    {
        it->print();
    }
}

void Covid::loadGraph()
{
    graph.resize(individus.size());
    for (auto &it : graph)
    {
        it.resize(individus.size());
    }
    //std::cout << graph.size() << '\n' << graph[0].size();
    for (int i = 0; i < individus.size(); i++)
    {
        for (int j = 0; j < individus.size(); j++)
        {
            graph[i][j] = 0;
        }
    }

    for (auto &it : contacts)
    {
        graph[it->name1_->getId()][it->name2_->getId()] = it->distance_;
        graph[it->name2_->getId()][it->name1_->getId()] = it->distance_;
    }
}

Individu *Covid::findIndividu(std::string name)
{
    for (auto& it : individus)
    {
        if (it->getName() == name)
        {
            return it.get();
        }
    }
    return nullptr;
}

int Covid::findIndexIndividu(std::string name)
{
    for (int i = 0; i < individus.size(); i++)
    {
        if (getIndividus(i)->getName() == name)
        {
            return i;
        }
    }
    return -1;
}

bool Covid::creerGrapheExposition()
{
    std::cout << "\nEntrez le nom du fichier d'individus\n";
    std::string ind;
    std::cin >> ind;

    std::cout << "\nEntrez le nom du fichier de contacts\n";
    std::string cont;
    std::cin >> cont;

   if( loadDoc(ind, cont)){
         std::cout << "\nLes fichiers ont bien ete lu.\n";
         return true;
         }

    else{
        std::cout << "\nLes fichiers n'ont pas pu etre lu. Veuillez-reessayer.\n";
        return false;
    }
}

bool Covid::NotifierExposition(std::string nom){
    return IdentifierExposition(nom);
}

bool Covid::IdentifierExposition(std::string nom){
    //partie Dijkstra
    d.foundDistance(graph.size(), findIndexIndividu(nom), graph);

    //Critère d'exposition
	for (int i = 0; i < d.myDistance.size(); i++)
	{
		if (d.myDistance[i] <= 2 && getIndividus(i)->getIsInfected())
		{
			return true;
		}
	}
	return false;
}