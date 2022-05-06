#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adjList[],int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void printGraph(vector<int>adjList[], int v)
{
    for(int i=0; i<v; i++)
    {
        cout<<i<<" : ";
        for(int x:adjList[i])
            cout<<x<<" ";
        cout<<"\n";
    }
}
int main()
{
    int V = 4; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    
    printGraph(adj, V); 
    return 0;
}
