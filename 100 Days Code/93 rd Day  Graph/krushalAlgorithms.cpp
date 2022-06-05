#include <bits/stdc++.h>
using namespace std;

struct node {
	int u, v, wt;
	node(int first, int second, int weight) {
		u = first;
		v = second;
		wt = weight;
	}
};

bool comp(node n1, node n2) {
	return n1.wt < n2.wt;
}

int findPar(int node, vector<int>&parent) {
	if (node == parent[node]) // If the parent of the node is itself
		return node;
	return parent[node] = findPar(parent[node], parent);
}
void Union(int u, int v, vector<int>&parent, vector<int>&rank) {
	u = findPar(u, parent);
	v = findPar(v, parent);
	if (rank[u] < rank[v]) {
		parent[u] = v;
	}
	else if (rank[v] < rank[u]) {
		parent[v] = u;
	}
	else {
		parent[v] = u;
		rank[u]++;
	}
}

int main()
{
	int m, n;
	cin >> m >> n;
	vector<node>edges;
	while (m--) {
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back(node(u, v, wt));
		edges.push_back(node(v, u, wt));

	}
	sort(edges.begin(), edges.end(), comp);
	vector<int>parent(n);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	vector<int>rank(n, 0);

	int cost = 0;
	vector<pair<int, int>>mst;
	for (auto it : edges) {
		if (findPar(it.v, parent) != findPar(it.u, parent))
		{
			cost += it.wt;
			mst.push_back({it.u, it.v});
			Union(it.u, it.v, parent, rank);
		}
	}
	cout << cost << endl;
	for (auto it : mst) {
		cout << it.first << " -> " << it.second << endl;
	}
	return 0;
}
