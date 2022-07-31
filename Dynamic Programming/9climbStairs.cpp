/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/

//  This problem is the variation of fibbonacci
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int n, vector<int> &dp)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        int x = solve(n, dp);
        return x;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.climbStairs(n) << endl;
    return 0;
}
