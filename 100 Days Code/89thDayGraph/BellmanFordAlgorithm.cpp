#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N=6,m=7;
    vector<node> edges; 
	edges.push_back(node(0,1,5));
	edges.push_back(node(1,2,-2));
	edges.push_back(node(1,5,-3));
	edges.push_back(node(2,4,3));
	edges.push_back(node(3,2,6));
	edges.push_back(node(3,4,-2));
	edges.push_back(node(5,3,1));
    int src=0;
    int inf = 10000000; 
    vector<int> dist(N, inf); 
    dist[src] = 0; 
    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << -1; 
            fl = 1; 
            break; 
        }
    }
    
    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << dist[i]<<" ";
        }
    }
    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int src, dest, wt; 
};
struct Graph{
    int V, E;
    struct Edge* edge;
};

struct Graph * createGraph(int v, int e){
    struct Graph *graph = new Graph;
    graph->V= v;
    graph->E = e;
    graph->edge = new Edge[e];
    return graph;
};

void BellmanFord(Graph *graph, int src)
{
    int v = graph->V;
    int e = graph->E;
    vector<int>dist(v, INT_MAX);
    dist[src]=0;

    for(int i=1; i<=v-1; i++){
        for(int j =0; j<e; j++){
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].wt;
            if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
            {
                dist[v]=dist[u]+weight;
            }
        }
    } 
    for (int i = 0; i < e; i++) { 
		int u = graph->edge[i].src; 
		int v = graph->edge[i].dest; 
		int weight = graph->edge[i].wt; 
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 
			printf("Graph contains negative weight cycle"); 
			return; 
		} 
	}   
    

     printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < v; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
}
int main()
{

    	int V = 4;
	int E = 5; 
	struct Graph* graph = createGraph(V, E); 

	// add edge 0-1 (or A-B) 
	graph->edge[0].src = 0; 
	graph->edge[0].dest = 1; 
	graph->edge[0].wt = 1; 

	// add edge 0-2 (or A-C) 
	graph->edge[1].src = 0; 
	graph->edge[1].dest = 2; 
	graph->edge[1].wt = 4; 

	// add edge 1-2 (or B-C) 
	graph->edge[2].src = 1; 
	graph->edge[2].dest = 2; 
	graph->edge[2].wt = -3; 

	// add edge 1-3 (or B-D) 
	graph->edge[3].src = 1; 
	graph->edge[3].dest = 3; 
	graph->edge[3].wt = 2; 

	// add edge 2-3 (or C-D) 
	graph->edge[4].src = 2; 
	graph->edge[4].dest = 3; 
	graph->edge[4].wt = 3; 

	BellmanFord(graph, 0); 
    return 0;
}
*/
