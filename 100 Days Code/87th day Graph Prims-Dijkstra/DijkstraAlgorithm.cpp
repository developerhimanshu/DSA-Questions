#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>>adj[], int u, int v, int wt)
{
	adj[u].push_back({v, wt});
	adj[v].push_back({u, wt});
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>>adj[n+1];
	for(int i=0; i<m; i++)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		addEdge(adj, u, v, wt);
	}

	vector<int>dist(n+1, INT_MAX);  //1-indexed array to calculate the shortest path
	int s;
	cin >> s;
	dist[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;  // This is the priority queue of min-heap
	pq.push({0, s});
	while (!pq.empty()) {
		int dis = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		for (auto v : adj[prev])
		{
			int next = v.first;
			int nextDist = v.second;
			if (dist[next] > dis + nextDist) {
				dist[next] = dis + nextDist;
				pq.push({dist[next], next});
			}
		}
	}
	cout << "The distance from the source " << s << " to every vertex is: " << "\n";
	for (int i = 1; i <= n; i++)cout << dist[i] << " ";
	cout << "\n";
	return 0;
}
