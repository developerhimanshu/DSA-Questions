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
        vector<int>prev(n, 0);
        for(int j =0; j<matrix.size(); j++){
            prev[j]=matrix[0][j];
        }
        
        for(int  i =1; i<n; i++){
            vector<int>curr(n, 0);
            for(int j = 0; j<n; j++){
                int u = matrix[i][j]+prev[j];
                int ld = 1e9, rd = 1e9;
                if(j-1>=0)ld = matrix[i][j]+prev[j-1];
               if(j+1<n)rd = matrix[i][j]+prev[j+1];
                curr[j]=min(u, min(ld, rd));
            }
            prev = curr;
        }
        int mini = prev[0];
        for(int j  = 1;  j < n; j++){
            if(prev[j]<mini){
                mini = prev[j];
            }   
        }
        return mini;
    }
};

int main()
{

    return 0;
}
