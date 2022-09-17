/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>>dp(prices.size()+1, vector<int>(2, 0));
        vector<int>cur(2, 0), next(2, 0);
        for(int i = prices.size()-1; i>=0; i--){
            for(int j = 0; j<2; j++){
                int profit;
                if(j==1){
                    profit = max((-prices[i]+next[0]), 0+next[1]);
                }
                else
                    profit = max((prices[i]+next[1]), 0+next[0]);
                
                cur[j]=profit;
            }
            next = cur;
        }
        return cur[1]; 
    }
};

int main()
{

    return 0;
}