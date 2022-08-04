/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, and all the houses are in the circular manner the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int notPick = 0 + prev;
            int curi = max(pick, notPick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    int rob(vector<int> &nums)
    {
        vector<int> temp1, temp2;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        int ans1 = solve(temp1);
        int ans2 = solve(temp2);
        return max(ans1, ans2);
    }
};

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    Solution s;
    cout << s.rob(nums);
    return 0;
}
