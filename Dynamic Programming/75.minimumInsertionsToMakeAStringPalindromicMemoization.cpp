/*
    Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fn(string &s1, string &s2,int ind1, int ind2, vector<vector<int>>&dp){
        if(ind1<0||ind2<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];   
        if(s1[ind1]==s2[ind2])return dp[ind1][ind2] = 1+fn(s1, s2, ind1-1, ind2-1, dp);
        return dp[ind1][ind2] = max(fn(s1, s2, ind1-1, ind2, dp), fn(s1, s2, ind1, ind2-1, dp));
    }
    int minInsertions(string s) {
        string str = s;
        reverse(str.begin(), str.end());
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int x = fn(s, str, n-1, n-1, dp);
        return n-x;
    }
};

int main()
{


    return 0;
}