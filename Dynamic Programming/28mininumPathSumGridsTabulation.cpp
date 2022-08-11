/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i==0&&j==0)dp[i][j]=grid[0][0];
                else{
                int top = 1e6;
                int left = 1e6;
                if(i>0)top = grid[i][j]+dp[i-1][j];
                if(j>0)left = grid[i][j]+dp[i][j-1];
                dp[i][j]=min(top, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    vector<vector<int>>grids={{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution s;
    cout<<s.minPathSum(grids);


}
