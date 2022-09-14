/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:

=> Insert a character
=> Delete a character
=> Replace a character
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fn(int i, int j, string s1, string s2,vector<vector<int>>&dp)
    {
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j] = fn(i-1, j-1, s1, s2, dp);
        else{
            int insert =1+fn(i, j-1, s1, s2, dp);
            int del = 1+fn(i-1, j, s1, s2, dp);
            int update = 1+fn(i-1, j-1, s1, s2, dp); 
            return dp[i][j] = min(insert, min(del, update));
            // return 1+min(fn(i, j-1, s1, s2), min(fn(i-1, j, s1, s2), fn(i-1, j-1, s1, s2)));
        }
    }
    int minDistance(string word1, string word2) {
       int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return fn(n-1, m-1, word1, word2, dp);
    }
};

int main()
{

    return 0;
}