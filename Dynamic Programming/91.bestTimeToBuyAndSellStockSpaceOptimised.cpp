#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>>after(2, vector<int>(3, 0));
        vector<vector<int>>cur(2, vector<int>(3, 0));

      
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int cap = 1; cap < 3; cap++)
                {
                    if (buy == 1)
                    {
                        cur[buy][cap] = max(-prices[ind] + after[0][cap], after[1][cap]);
                    }
                    else
                    {
                        cur[buy][cap] = max(prices[ind] + after[1][cap - 1], after[0][cap]);
                    }
                }
                after = cur;
            }
        }

        return after[1][2];
    }
};
int main()
{

    return 0;
}