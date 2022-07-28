// In this problem we have to find the number of ways we can get the given sum from the set of coins and we can take as many coins as we want

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int sum, int n)
{
    int dp[sum + 1][n + 1];
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;
    for (int i=1; i<=sum; i++)
        dp[i][0]=0;
    for(int i=1;i<=sum; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            dp[i][j]=dp[i][j-1];
            if(coins[j-1]<=i){
                dp[i][j]+=dp[i-coins[j-1]][j];
            }
        }
    }
    return dp[sum][n];
}
int main()
{
    vector<int> coins = {1, 2, 3};
    int sum = 4;
    cout << coinChange(coins, sum, coins.size());

    return 0;
}
