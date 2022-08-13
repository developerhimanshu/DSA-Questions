/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp){
        if(i==m-1)return triangle[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int dwn = triangle[i][j]+solve(i+1, j, m, n, triangle, dp);
        int diag = triangle[i][j]+solve(i+1, j+1, m, n, triangle, dp);
        return dp[i][j]= min(dwn, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, triangle, dp);
    }
};

int main()
{
    vector<vector<int>>triangle;
}
