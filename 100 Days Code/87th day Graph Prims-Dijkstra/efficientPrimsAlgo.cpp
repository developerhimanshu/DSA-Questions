#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<pair<int, int>>adj[], int u, int v, int wt) {
	adj[u].push_back({v, wt});
	adj[v].push_back({u, wt});
}
void primsAlgo(vector<pair<int, int>>adj[], int v, int s)
{
	int key[v];
	int parent[v];
	bool isMst[v];
	for (int i = 0; i < v ; i++)
		key[i] = INT_MAX, isMst[i] = false;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	key[s] = 0;
	parent[s] = -1;
	pq.push({s, 0});
	while (!pq.empty()) {
		int u = pq.top().first;  //This will give the result in O(log n)
		pq.pop();
		isMst[u] = true;
		for (auto it : adj[u])
		{
			int v = it.first;
			int weight = it.second;
			if (isMst[v] == false &&  weight < key[v]) {
				key[v] = weight, parent[v] = u;
				pq.push({v, key[v]});
			}
		}
	}
	for (int i = 1; i < v; i++)
		cout << parent[i] << "-" << i << "\n";
	cout << "The minimum cost of each edge will be" << "\n";
	for (int i = 0; i < v ; i++)
		cout << key[i] << " ";
}
int main()
{
	int v, n;
	cin >> v >> n;
	vector<pair<int, int>>adj[v];
	while (n--)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		addEdge(adj, u, v, wt);
	}
	primsAlgo(adj, v, 0);
	return 0;
}
