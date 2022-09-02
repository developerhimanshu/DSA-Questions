/*
Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N, vector<int>(W+1, 0));
        for(int i=0; i<W+1; i++){
            dp[0][i] = ((int)(i/wt[0])) * val[0];
        }
        
        for(int ind = 1; ind < N; ind++){
            for(int w = 0; w<W+1; w++){
                int notPick = dp[ind-1][w];
                int pick = INT_MIN;
                if(w>=wt[ind])
                    pick = val[ind]+dp[ind][w-wt[ind]];
                
                dp[ind][w] = max(notPick, pick);
            }
        }
        return dp[N-1][W];
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