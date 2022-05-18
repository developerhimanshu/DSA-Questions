#include <bits/stdc++.h>
using namespace std;

bool dfsRec(vector<int>adj[], int s, bool visited[], int parent)
{
    visited[s]=true;
    for(auto u:adj[s])
    {
        if(visited[u]==false){
            if(dfsRec(adj, u, visited, s)==true)
                return true;
        }
        else if(u!=parent)
        {
            return true;
        }
    }
    return false;
}

bool dfs(vector<int>adj[],int v){
    bool visited[v];
    for(int i=0; i<v; i++)
    {
        visited[i]=false;
    }

    for(int i=0; i<v; i++)
    {
        if(visited[i]==false)
        {
            if(dfsRec(adj, i, visited, -1)==true)
                return true;
        }
    }
    return false;
}

void addEdge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    	int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,4); 
	addEdge(adj,4,5); 
	addEdge(adj,1,3);
	addEdge(adj,2,3);

	if(dfs(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

    return 0;
}
