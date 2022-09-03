/*
Given a rod of length N inches and an array of prices, price[]. pricei denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int f(int ind, int tar, int price[], vector<vector<int>>&dp){
        if(ind == 0)return tar*price[0];
        
        if(dp[ind-1][tar]!=-1)return dp[ind-1][tar];
        int notPick = f(ind-1, tar, price, dp);
        int pick = INT_MIN;
        if(tar>=ind)
            pick = price[ind-1]+f(ind, tar-(ind), price, dp);
        return dp[ind-1][tar] = max(pick, notPick);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return f(n, n, price, dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
