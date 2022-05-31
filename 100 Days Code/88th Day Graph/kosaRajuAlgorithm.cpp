// This algo is used to print the strongly connected components of a graph
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *adj;
    void fillOrder(int v, bool visited[], stack<int> &s);
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int v);
    void addEdge(int v, int w);
    void printSCCs();
    Graph getTranspose();

};

Graph::Graph(int v)
{
    this->v=v;
    adj = new list<int>[v];
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i = adj[v].begin(); i!=adj[v].end(); ++i){
        if(!visited[*i])
        {
            DFSUtil(*i, visited);
        }
    }
}

Graph Graph::getTranspose(){
    Graph g(v);
    for(int i = 0; i<v; i++)
    {
        list<int>::iterator it;
        for(it = adj[v].begin(); it!=adj[v].end(); ++it)
        {
            g.adj[*it].push_back(i);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::fillOrder(int v, bool visited[], stack<int>&s)
{
    visited[v]=true;
    list <int>::iterator i;
    for(i = adj[v].begin(); i!=adj[v].end() ;++i)
    {
        if(!visited[*i])
        {
            fillOrder(*i, visited, s);
        }
    }
    s.push(v);
}

void Graph::printSCCs()
{
    stack<int>s;
    bool *visited = new bool[v];
    for(int i = 0; i<v; i++)
    {
        visited[i]=false;
    }
    for(int i=0; i<v; i++)
        if(visited[i]==false)
            fillOrder(i, visited, s);
    Graph gr = getTranspose();
    for(int i=0; i<v; i++)
    {
        visited[i]=false;
    }
    while(s.empty()==false){
        int v = s.top();
        s.pop();
        if(visited[v]==false){
            gr.DFSUtil(v, visited);
            cout<<endl;
        }
    }
}
int main()
{
     
	Graph g(5); 
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 

	cout << "Following are strongly connected components in given graph \n"; 
	g.printSCCs(); 
    return 0;
}
