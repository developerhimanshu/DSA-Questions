/*
Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.
*/

#include <bits/stdc++.h>
using namespace std;



class Solution{
public:
    int f(int ind, int W, int val[], int wt[], vector<vector<int>>&dp){
        if(ind == 0){
            return int(W/wt[0])*val[0];   // suppose at 0th index it has the wt of 8 ans W left is 3 so still he has the chance to steal 2 items
        }
        
        if(dp[ind][W]!=-1)return dp[ind][W];
        int notPick = f(ind-1, W, val, wt, dp);
        int pick = INT_MIN;
        if(W>=wt[ind])
            pick = val[ind]+f(ind, W-wt[ind], val, wt, dp);
        
        return dp[ind][W] = max(notPick, pick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N, vector<int>(W+1, -1));
        return f(N-1, W, val, wt, dp);
        
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}