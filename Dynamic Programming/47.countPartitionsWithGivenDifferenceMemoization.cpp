/*
You are given an array ARR, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be 'S1' and 'S2'.

Given a difference 'D', count the number of partitions in which 'S1' is greater than or equal to 'S2' and the difference between 'S1' and 'S2' is equal to 'D'.

*/

#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);
int f(vector<int> &arr, int ind, int tar, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (tar == 0 && arr[0] == 0)
            return 2; // This thing is done to tackle if arr[i] = 0 suppose for the test case {0, 0, 1} tar = 1 then the total no of subsets with this target would be 4
        if (tar == 0 || arr[0] == tar)
            return 1;
        return 0;
    }
    if (dp[ind][tar] != -1)
        return dp[ind][tar];
    int notPick = f(arr, ind - 1, tar, dp);
    int pick = 0;
    if (arr[ind] <= tar)
        pick = f(arr, ind - 1, tar - arr[ind], dp);

    return dp[ind][tar] = (pick + notPick) % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int totalSum = 0;
    for (auto &x : arr)
        totalSum += x;
    if (totalSum - d < 0 || (totalSum - d) % 2)
        return 0;
    vector<vector<int>> dp(n, vector<int>(((totalSum - d) / 2) + 1, -1));
    return f(arr, n - 1, (totalSum - d) / 2, dp);
}

int main()
{
    vector<int> arr = {0, 0, 1};
    int k = 1;
    cout << "The number of subsets found are " << countPartitions(3, k, arr);
    return 0;
}