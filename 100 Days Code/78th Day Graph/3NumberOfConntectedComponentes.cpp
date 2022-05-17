#include <bits/stdc++.h>
using namespace std;

void dfsRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    // cout << s << " ";
    for (int u : adj[s])
    {
        if (visited[u] == false)
            dfsRec(adj, u, visited);
    }
}
int conntectedComponents(vector<int> adj[], int v)
{
    int count = 0;
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dfsRec(adj, i, visited);
            count++;
        }
    }
    return count;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2);
	addEdge(adj,3,4);

	cout << "Number of connected components: "<< conntectedComponents(adj,V); 

	return 0; 
}
