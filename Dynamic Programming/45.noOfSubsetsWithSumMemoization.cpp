#include <bits/stdc++.h>
using namespace std;

int f(int ind, int tar, vector<int>&num,vector<vector<int>>&dp){
    if(tar==0)return 1;
    if(ind == 0){
        return num[ind]==tar;
    }
    if(dp[ind][tar]!=-1)return dp[ind][tar];
    int notPick = f(ind-1, tar, num, dp);
    int pick = 0;
    if(num[ind]<=tar)pick = f(ind-1, tar-num[ind], num, dp);
    return dp[ind][tar]=pick+notPick;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>>dp(n, vector<int>(tar+1, -1));
    return f(n-1, tar, num, dp);
}

int main()
{
    vector<int> arr = {1,2,2,3};
    int k=3;
                                 
    cout<<"The number of subsets found are " <<findWays(arr,k);

}