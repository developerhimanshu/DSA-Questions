/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+2, vector<int>(2, 0));
        for(int ind = prices.size()-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                if(buy){
                    dp[ind][buy] = max(-prices[ind]+dp[ind+1][0], dp[ind+1][1]);
                }
                else
                    dp[ind][buy] = max(prices[ind]+dp[ind+2][1], dp[ind+1][0]);
            }
        }
        return dp[0][1];
    }
};