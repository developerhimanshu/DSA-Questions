/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>dp(m, vector<int>(m, 0));
        for(int j = 0; j<m; j++){
            dp[m-1][j]=triangle[m-1][j];
        }
        for(int i = m-2; i>=0; i--){
            for(int j = i; j>=0; j--){
                int btm = triangle[i][j]+dp[i+1][j];
                int diag = triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(btm, diag);
            }
        }
        return dp[0][0];
    }
};

int main()
{
    vector<vector<int>>triangle;
}
