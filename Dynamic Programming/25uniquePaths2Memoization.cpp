/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (m < 0 || n < 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (grid[m][n] == 1)
        return 0;
    if (m == 0 && n == 0 && grid[m][n] != 1)
        return 1;

    int top = solve(m - 1, n, grid, dp);
    int left = solve(m, n - 1, grid, dp);
    return dp[m][n] = left + top;
}
int uniquePathsWithObstacles(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m - 1, n - 1, grid, dp);
}
int main()
{
    int m, n;
    cin>>m>>n;
    vector<vector<int>>grids(m, vector<int>(n, 0));
    int p, q;
    cin>>p, q;
    grids[p-1][q-1]=1;
    cout<<uniquePathsWithObstacles(grids);
    return 0;
}
