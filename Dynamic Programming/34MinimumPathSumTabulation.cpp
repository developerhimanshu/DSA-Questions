/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int j =0; j<matrix.size(); j++){
            dp[0][j]=matrix[0][j];
        }
        
        for(int  i =1; i<n; i++){
            for(int j = 0; j<n; j++){
                int u = matrix[i][j]+dp[i-1][j];
                int ld = 1e9, rd = 1e9;
                if(j-1>=0)ld = matrix[i][j]+dp[i-1][j-1];
               if(j+1<n)rd = matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(u, min(ld, rd));
            }
        }
        int mini = dp[n-1][0];
        for(int j  = 1;  j < n; j++){
            if(dp[n-1][j]<mini){
                mini = dp[n-1][j];
            }   
        }
        return mini;
    }
};

int main()
{

    return 0;
}
