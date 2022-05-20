#include <bits/stdc++.h>
using namespace std;

void KahnsBFS(vector<int>adj[], int v,int indegree[])
{
/*  ==> Another method of making indegree
    vector<int> in_degree(V, 0); 
  
    for (int u = 0; u < V; u++) { 
        for (int x:adj[u]) 
            in_degree[x]++; 
    }
*/ 
    queue<int>q;
    for(int i=0; i<v; i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v:adj[u])
        {
           indegree[v]--;
           if(indegree[v]==0)
            q.push(v); 
        }
    }
}

void addEdge(vector<int>adj[], int u, int v, int indegree[])
{
    adj[u].push_back(v);
    indegree[v]++;
}
int main()
{
    int v=5;
    // cin>>v;
    int indegree[v];
    vector<int>adj[v];
    for(int i=0; i<v; i++)
    {
        indegree[i]=0;
    }
   	addEdge(adj,0, 2, indegree); 
    addEdge(adj,0, 3, indegree); 
    addEdge(adj,1, 3, indegree); 
    addEdge(adj,1, 4, indegree); 
    addEdge(adj,2, 3, indegree);  
    KahnsBFS(adj, v, indegree);
    return 0;
}
