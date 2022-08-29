#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int ind, int tar, vector<int> &coins)
    {
        if (ind == 0)
        {
            if ((tar % coins[ind]) == 0)
                return tar / coins[ind];
            else
                return INT_MAX;
        }
        long long notChoose = f(ind - 1, tar, coins);
        long long choose = 1e9;
        if (coins[ind] <= tar)
            choose = 1 + f(ind, tar - coins[ind], coins);
        return min(choose, notChoose);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int ans = f(coins.size() - 1, amount, coins);
        if(ans>=1e9)return -1;
        return ans;
    }
};
int main()
{

    return 0;
}