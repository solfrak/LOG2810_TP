#include <iostream>
#include <bits/stdc++.h>
#include <climits>
#include "Covid.h"
#include <vector>
#include "Dijkstra.h"
#define INFINITY 9999
using namespace std;

Covid t;
// std::vector<double> myDistance;

// void dijkstra(int n,int startnode, std::vector<std::vector<double>> G)
// {
	
// 	double cost[t.graph.size()][t.graph.size()];
// 	double distance[t.graph.size()];
// 	int pred[t.graph.size()];
// 	int visited[t.graph.size()],count;
// 	double mindistance;
// 	int nextnode,i,j;
	
// 	//pred[] stores the predecessor of each node
// 	//count gives the number of nodes seen so far
// 	//create the cost matrix
// 	for(i=0;i<n;i++)
// 		for(j=0;j<n;j++)
// 			if(G[i][j]==0)
// 				cost[i][j]=INFINITY;
// 			else
// 				cost[i][j]=G[i][j];
	
// 	//initialize pred[],distance[] and visited[]
// 	for(i=0;i<n;i++)
// 	{
// 		distance[i]=cost[startnode][i];
// 		pred[i]=startnode;
// 		visited[i]=0;
// 	}
	
// 	distance[startnode]=0.0;
// 	visited[startnode]=1;
// 	count=1;
	
// 	while(count<n-1)
// 	{
// 		mindistance=INFINITY;
		
// 		//nextnode gives the node at minimum distance
// 		for(i=0;i<n;i++)
// 			if(distance[i]<mindistance&&!visited[i])
// 			{
// 				mindistance=distance[i];
// 				nextnode=i;
// 			}
			
// 			//check if a better path exists through nextnode			
// 			visited[nextnode]=1;
// 			for(i=0;i<n;i++)
// 				if(!visited[i])
// 					if(mindistance+cost[nextnode][i]<distance[i])
// 					{
// 						distance[i]=mindistance+cost[nextnode][i];
// 						pred[i]=nextnode;
// 					}
// 		count++;
// 	}
// 	for(int i=0; i < t.graph.size(); i++){
// 		myDistance.push_back(distance[i]);
// 	}
// }

int main() 
{
	t.loadDoc();
	t.loadGraph();
	Dijkstra d;
	
	d.foundDistance(t.graph.size(), t.findIndexIndividu("Clorise"), t.graph);
	for(int i=0; i < d.myDistance.size(); i++){
		if(d.myDistance[i] <= 2 && t.getIndividus(i)->getIsInfected()){
			std::cout << "a été exposé"<< endl;
			break;
		}
	}
	cout << "n'a pas été exposé" << endl;
}
