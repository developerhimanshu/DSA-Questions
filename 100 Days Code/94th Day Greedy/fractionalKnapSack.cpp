#include <bits/stdc++.h>
using namespace std;

bool mycmp(pair<int, int>a, pair<int, int>b) {   //This comparator is for sorting the pairs in the value/weight ratio
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
    int n;
    cin>>n;
    vector<pair<int, int>>arr;
    while(n--){
        int weight, value;
        cin>>weight>>value;
        arr.push_back(make_pair(weight,value));
    }

	int W = 50;

	cout << fKnapS(arr, W);


	return 0;
}
