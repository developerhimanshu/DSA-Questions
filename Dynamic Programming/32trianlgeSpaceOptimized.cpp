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
        int n = triangle[m-1].size();
        vector<int>rear(n, 0);
        for(int j = 0; j<m; j++){
            rear[j]=triangle[m-1][j];
        }
        for(int i = m-2; i>=0; i--){
            vector<int>curr(n, 0);
            for(int j = i; j>=0; j--){
                int btm = triangle[i][j]+rear[j];
                int diag = triangle[i][j]+rear[j+1];
                curr[j]=min(btm, diag);
            }
            rear = curr;
        }
        return rear[0];
    }
};

int main()
{
    vector<vector<int>>triangle;
}
