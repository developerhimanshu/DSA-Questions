#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
    int fn(int ind, bool buy, int cap, vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(cap==0)return 0;
        if(ind==prices.size())return 0;
        if(dp[ind][buy][cap] != -1)return dp[ind][buy][cap];
        int profit;

        if(buy){
            profit =  max(-prices[ind]+fn(ind+1, 0, cap, prices, dp),  fn(ind+1, 1, cap, prices, dp));
        }else{
            profit = max(prices[ind]+fn(ind+1, 1, cap-1, prices, dp), fn(ind+1, 0, cap, prices, dp));
        }
        return dp[ind][buy][cap] = profit;
    }

    */
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int ind = 0; ind <= n; ind++)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                dp[ind][buy][0] = 0;
            }
        }

        for (int buy = 0; buy < 2; buy++)
        {
            for (int cap = 0; cap < 3; cap++)
            {
                dp[n][buy][cap] = 0;
            }
        }
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int cap = 1; cap < 3; cap++)
                {
                    if (buy == 1)
                    {
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind + 1][1][cap]);
                    }
                    else
                    {
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};
int main()
{

    return 0;
}