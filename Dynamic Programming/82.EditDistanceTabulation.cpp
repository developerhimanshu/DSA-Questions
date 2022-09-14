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
   
    int minDistance(string word1, string word2) {
       int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        for(int j = 0; j<=m; j++)dp[0][j]=j;
        for(int i = 0; i<=n; i++)dp[i][0]=i;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(word1[i-1]==word2[j-1])dp[i][j] = dp[i-1][j-1];
                else{
                    int insert = 1+dp[i][j-1];
                    int del = 1+dp[i-1][j];
                    int replace = 1+dp[i-1][j-1];
                    dp[i][j] = min(insert, min(del, replace));
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{

    return 0;
}