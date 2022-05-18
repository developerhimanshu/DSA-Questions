#include <bits/stdc++.h>
using namespace std;


void shortestPath(vector<int>adj[], int s, int v, int dist[])
{

    bool visited[v];
    for(int i=0; i<v; i++)
        visited[i]=false;
    queue<int>q;
    visited[s]=true;
    q.push(s);
    dist[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:adj[u])
        {
            if(visited[v]==false)
            {
                dist[v]=dist[u]+1;
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
void addEdge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int v=4;
    vector<int>adj[v];
    addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,0,2); 
	addEdge(adj,1,3);
    int dist[v];
    for(int i=0; i<v; i++)
    {
        dist[i]=INT_MAX;
    }
    shortestPath(adj, 0, v, dist);
    for(int i=0; i<v; i++)
        cout<<dist[i]<<" ";
    return 0;
}
