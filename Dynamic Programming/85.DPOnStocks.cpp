// Best time to Buy and sell the stock so that you will get the maximum profit

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_ind = 0;
        int max_profit = 0;
        for(int i = 1; i<prices.size(); i++){
            if(prices[i]>prices[min_ind]){  // Whenever the price of item is greater then the price of the item you buy which is min_ind then update your profit
                max_profit = max(max_profit, (prices[i]-prices[min_ind]));
            }else{
                min_ind = i; // If you get minimal prices buy it
            }
        }
        return max_profit;
    }
};

int main(){

    return 0;
}