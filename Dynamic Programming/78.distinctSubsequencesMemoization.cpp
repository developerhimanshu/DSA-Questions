/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fn(int i, int j, string s, string t, vector<vector<int>>dp){
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j])return dp[i][j] = fn(i-1, j-1, s, t, dp)+fn(i-1, j, s, t, dp);
        else return dp[i][j] = fn(i-1,  j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return fn(m-1, n-1, s, t, dp);
    }
};

int main()
{

    return 0;
}