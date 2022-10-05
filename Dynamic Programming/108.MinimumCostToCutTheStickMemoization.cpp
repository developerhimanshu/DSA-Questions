#include <bits/stdc++.h>
using namespace std;
class Solution {
public: 

    int fn(int i, int j, vector<int>&cuts,  vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini = 1e9;
        for(int ind = i; ind<=j;  ind++){
            int cost = cuts[j+1]-cuts[i-1]+fn(i, ind-1, cuts, dp)+fn(ind+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j]=mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(size+2, vector<int>(size+2, 0));
       
        return fn(1, size, cuts, dp); 
    }
};

int main(){

    return 0;
}