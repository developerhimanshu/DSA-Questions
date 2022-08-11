/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(m==0&&n==0)return grid[0][0];
        if(m<0||n<0)return 1e6;
        if(dp[m][n]!=-1)return dp[m][n];
        int left = grid[m][n]+solve(m, n-1, grid, dp);
        int top =   grid[m][n]+ solve(m-1, n, grid, dp);
        return dp[m][n]=min(left, top);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, dp);
    }
};

int main()
{
    vector<vector<int>>grids={{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution s;
    cout<<s.minPathSum(grids);


}
