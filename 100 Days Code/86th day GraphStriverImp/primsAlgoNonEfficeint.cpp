#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N = 5, M = 6;
	vector<pair<int, int>>adj[N];
	adj[0].push_back({1, 2});
	adj[0].push_back({3, 6});
	adj[1].push_back({0, 2});
	adj[1].push_back({2, 3});
	adj[1].push_back({3, 8});
	adj[1].push_back({4, 5});
	adj[2].push_back({1, 3});
	adj[2].push_back({4, 7});
	adj[3].push_back({0, 6});
	adj[3].push_back({1, 8});
	adj[4].push_back({1, 5});
	adj[4].push_back({2, 7});

	int parent[N];
	int key[N];
	bool mst[N];

	for (int i = 0; i < N; i++)
	{
		parent[i] = -1;
		key[i] = INT_MAX, mst[i] = false;
	}
	key[0] = 0;
	for (int count = 0; count < N - 1; count++)
	{
		int u; int mini = INT_MAX;
		for (int i = 0; i < N; i++)
		{
			if (mst[i] == false && key[i] < mini)
				mini = key[i], u = i;
		}
		mst[u] = true;
		for (auto it : adj[u])
		{
			int v = it.first;
			int weight = it.second;
			if (mst[v] == false && weight < key[v])
				parent[v] = u, key[v] = weight;
		}
	}
	cout << "The nodes of the graph are linked as: " << endl;
	for (int i = 1; i < N; i++)
		cout << parent[i] << " - " << i << " \n";
	cout << "The minimum spanning weight of the nodes of the graph are: " << endl;
	for (int i = 0; i < N; i++)
		cout << key[i] << " ";


	return 0;
}
