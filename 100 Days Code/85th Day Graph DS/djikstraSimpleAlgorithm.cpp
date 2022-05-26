#include <bits/stdc++.h>
#define v 4
using namespace std;

vector<int> djikstraShortestPath(int graph[v][v], int src)
{
    vector<int>dist(v, INT_MAX);
    dist[src]=0;
    vector<bool>fin(v, false);
    for(int count=0; count<v-1; count++)
    {
        int u = -1;
        for(int i=0; i<v; i++)
        {
            if(fin[i]==false && (u==-1||dist[i]<dist[u]))
                u=i;
        }
        fin[u]=true;
        for(int x=0; x<v; x++)
        {
            if(graph[u][x]!=0 && fin[x]==false)
            {
                dist[x]=min(dist[x], dist[u]+graph[u][x]);
            }
        }
    }
    return dist;
}

int main() 
{ 
	int graph[v][v] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },}; 

	for(int x: djikstraShortestPath(graph, 0)){
	    cout<<x<<" ";
	} 

	return 0; 
} 
