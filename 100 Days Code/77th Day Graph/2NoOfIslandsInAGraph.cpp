//In this problem you are given disconnected graph now you have to find number of connected components in that graph
// Like there are are three disconnected points in a graph so number of connected components in that graph will be 3
#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[], int v, int s, bool visited[])
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        // cout << u << " ";
        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
int connectedComponents(vector<int> adj[], int v)
{
    int count=0;
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            BFS(adj, v, i, visited);
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
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);

    cout << "Number of connteced components in the graph are: " << endl;
    cout<<connectedComponents(adj, V);



    return 0;
}
