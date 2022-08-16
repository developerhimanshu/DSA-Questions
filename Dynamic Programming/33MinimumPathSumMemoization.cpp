/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>&matrix, vector<vector<int>>&dp){
        if(j<0||j>=n)return 1e9;
        if(i==0)return matrix[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int s = matrix[i][j]+solve(i-1, j, n, matrix, dp);
        int ld = matrix[i][j]+solve(i-1, j-1, n, matrix, dp);
        int rd = matrix[i][j]+solve(i-1, j+1, n, matrix, dp);
        return dp[i][j]=min(s, min(ld, rd));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
        int mini = 1e9;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int j =0; j<matrix.size(); j++){
            mini = min(mini, solve(n-1, j, n, matrix, dp));
        }
        return mini;
    }
};

int main()
{

    return 0;
}
