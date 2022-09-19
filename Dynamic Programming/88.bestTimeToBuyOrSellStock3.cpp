#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fn(int ind, bool buy, int k, vector<int> &prices)
    {
        if (k == 0)
            return 0;
        if (ind == prices.size())
            return 0;

        int profit;

        if (buy)
        {
            profit = max(-prices[ind] + fn(ind + 1, 0, k, prices), fn(ind + 1, 1, k, prices));
        }
        else
        {
            profit = max(prices[ind] + fn(ind + 1, 1, k - 1, prices), fn(ind + 1, 0, k, prices));
        }
        return profit;
    }
    int maxProfit(vector<int> &prices)
    {
        return fn(0, 1, 2, prices);
    }
};

int main()
{

    return 0;
}