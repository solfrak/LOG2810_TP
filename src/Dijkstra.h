#pragma once

#include <vector>
using namespace std;

/**
 * @brief Classe de l'algorithme de dijkstra
 * 
 */
class Dijkstra
{
private:

public:
    vector<double> myDistance;
    
    void foundDistance(int n, int startnode, vector<vector<double>> G);
};


