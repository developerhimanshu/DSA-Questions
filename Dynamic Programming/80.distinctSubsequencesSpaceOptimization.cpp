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
        vector<double>prev(n+1);
        prev[0] = 1;
        for(int i = 1; i<=m; i++){
            for(int j = n; j>=1; j--){
                if(s[i-1]==t[j-1])
                    prev[j] = prev[j-1] + prev[j];
                else
                    prev[j] = prev[j];
            }
        }
        
        return (int)prev[n];
    }
};

int main()
{

    return 0;
}