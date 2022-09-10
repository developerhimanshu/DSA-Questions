//You are given two strings s1 and s2 you have to convert s1 to s2 in minimum possible operations
//The intuition behind solving this problem is LCS you have to find lcs(s1, s2), then you have to remove s1.length()-lcs(s1, s2)
//from s1 and add s2.length()-lcs(s1, s2) to s1

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lcs(string s1, string s2){
        int n = s1.length(), m = s2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            
        }
        return dp[n][m];
        
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        return (n+m- (2*lcs(word1, word2)));
    }
};

int main(){
    
    return 0;
}