/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<double>>dp(m+1, vector<double>(n+1));
        for(int i = 0; i<=m; i++)
            dp[i][0] = 1;
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return (int)dp[m][n];
    }
};

int main()
{

    return 0;
}