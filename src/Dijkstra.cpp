#include "Dijkstra.h"
#ifndef INFINTIY
#define INFINITY 9999
#endif

/**
 * @brief Algorithme de Dijkstra
 * 
 * @param n Taille du vecteur (nombre d'individu)
 * @param startnode La personne par lequel l'algorithme commence
 * @param G Le vecteur contenant les personnes
 */
void Dijkstra::foundDistance(int n, int startnode, vector<vector<double>> G){
    double cost[n][n];
	double distance[n];
	
	int visited[n],count;
	double mindistance;
	int nextnode,i,j;
	
	/**	
	* Remplie la matrice de cout à partir du graph. Si la distance est 0, Cela veut dire qu'il n'y a pas de connection
	* donc la distance est INFINITY
	*/
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	/**
	 * Remplie le tableau de distance à partir du point de départ
	 * dans le graphe
	 */
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		visited[i]=0;
	}
	
	distance[startnode]=0.0;
	visited[startnode]=1;
	count=1;
	
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		
		//Trouve le noeud ayant la distance minimal
		for(i=0;i<n;i++){
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		}
				
		// Regarde si un meilleur chemin existe	à partir des noeuds déjà visité
		visited[nextnode]=1;
		for(i=0;i<n;i++){
			if(!visited[i])
				if(mindistance+cost[nextnode][i]<distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
				}
		}
		count++;
	}
	for(int i=0; i < n; i++){
		myDistance.push_back(distance[i]);
	}
}
