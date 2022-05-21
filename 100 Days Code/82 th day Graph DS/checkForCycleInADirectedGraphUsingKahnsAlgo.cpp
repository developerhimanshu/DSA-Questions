#include <bits/stdc++.h>
using namespace std;

void checkForCycle(vector<int>adj[], int v)
{
    int indegree[v];
    for(int i=0; i<v; i++)
        indegree[i]=0;
    for(int u = 0; u<v; u++)
    {
        for(auto v:adj[u])
        {
            indegree[v]++;
        }
    }
    int count=0;
    queue<int>q;
    for(int i=0; i<v; i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto x:adj[u]){
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }
        count++;
    }
    if(count!=v){
        cout<<"The graph contains cycle"<<endl;
    }
    else
         cout<<"The graph doesn't contains cycle"<<endl;
}
void addEdge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
}
int main()
{
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,4, 1); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 1);  
    checkForCycle(adj, V);
    return 0;
}
