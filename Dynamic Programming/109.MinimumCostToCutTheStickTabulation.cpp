#include <bits/stdc++.h>
using namespace std;
class Solution {
public: 


   int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(size+2, vector<int>(size+2, 0));
       
        for(int i = size; i>=1; i--){
            for(int j = 1; j<= size; j++){
                if(i>j)continue;  //Base Case
                int mini = 1e9;
                for(int ind = i; ind<=j;  ind++){
                    int cost = cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][size];
    }
};

int main(){

    return 0;
}