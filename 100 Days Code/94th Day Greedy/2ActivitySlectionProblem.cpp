#include <bits/stdc++.h>
using namespace std;
static bool cmp(pair<int, int>a, pair<int, int>b){
    return (a.second<b.second);
}
int maxActivities(vector<pair<int, int>>activities, int n){
    sort(activities.begin(), activities.end(), cmp);
    int prev = 0;
    int res = 1;
    for(int curr = 1; curr <n; curr++){
        if(activities[curr].first>activities[prev].second){
            res++;
            prev = curr;
        }
    }
    return res;
}
int main()
{
    vector<pair<int, int>>arr = {make_pair(2,2), make_pair(1,2)};

	int n = 2;

	cout<<maxActivities(arr, n); 
    return 0;
}
