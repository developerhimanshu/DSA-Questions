#include <bits/stdc++.h>
using namespace std;

bool mycmp(pair<int, int>a, pair<int, int>b) {
	double r1 = (double)a.second / a.first;
	double r2 = (double)b.second / b.first;
	return r1 > r2;
}
int fKnapS(vector<pair<int, int>>things, int weight) {
	sort(things.begin(), things.end(), mycmp);
	int curr_weight = weight;
	double res = 0.0;
	for (int i = 0; i < things.size(); i++) {
		if (things[i].first <= weight) {
			weight -= things[i].first;
			res += things[i].second;
		}
		else {
			res += ((double)weight / things[i].first) * (things[i].second);
			break;
		}
	}
	return res;
}
int main()
{
	vector<pair<int, int>>arr = {make_pair(30, 120), make_pair(20, 100), make_pair(10, 60)};

	int n = 3, W = 50;

	cout << fKnapS(arr, W);


	return 0;
}
