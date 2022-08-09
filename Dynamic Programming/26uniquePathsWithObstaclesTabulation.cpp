/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
*/

#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0 && grid[i][j] != 1)
            {
                dp[i][j] = 1;
                continue;
            }
            int top = 0, left = 0;
            if (grid[i][j] == 1)
                dp[i][j] = 0;
            else
            {
                if (i > 0)
                    top = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
            }
            dp[i][j] = top + left;
        }
    }
    return dp[m - 1][n - 1];
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grids(m, vector<int>(n, 0));
    int p, q;
    cin >> p, q;
    grids[p - 1][q - 1] = 1;
    cout << uniquePathsWithObstacles(grids);
    return 0;
}
