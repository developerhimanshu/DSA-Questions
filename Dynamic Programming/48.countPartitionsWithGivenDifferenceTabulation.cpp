/*
You are given an array ARR, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be 'S1' and 'S2'.

Given a difference 'D', count the number of partitions in which 'S1' is greater than or equal to 'S2' and the difference between 'S1' and 'S2' is equal to 'D'.

*/

#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    if (num[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = dp[i - 1][sum];
            int take = 0;
            if (num[i] <= sum)
                take = dp[i - 1][sum - num[i]];
            dp[i][sum] = (take + notTake) % mod;
        }
    }
    return dp[n - 1][tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (auto &x : arr)
        totalSum += x;
    if (totalSum - d < 0 || (totalSum - d) % 2)
        return 0;
    vector<vector<int>> dp(n, vector<int>(((totalSum - d) / 2) + 1, -1));
    return findWays(arr, (totalSum - d) / 2);
}

int main()
{
    vector<int> arr = {0, 0, 1};
    int k = 1;
    cout << "The number of subsets found are " << findWays(arr, k);
    return 0;
}