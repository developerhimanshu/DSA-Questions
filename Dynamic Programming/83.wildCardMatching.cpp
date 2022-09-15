#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    bool solveMem(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        //base case
        if(i<0 && j<0) 
            return true;
        if(i>=0 && j<0)  
            return false;

        if(i<0 && j>=0){  
            for( int k=0 ; k<=j; k++){
                if(p[k] != '*')
                    return false;
            }
            return true;
        }

        if(dp[i][j] != -1 )
            return dp[i][j];


        //match
        if( s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solveMem(s,p,i-1,j-1,dp);

        else if(p[j] == '*')  
            return dp[i][j] = (solveMem(s,p,i-1,j,dp) || solveMem(s,p,i,j-1,dp));

        else //no match
            return false;

    }
    */

    bool isMatch(string s, string p) {
        int m= s.length(), n = p.length();
        vector<vector<bool>>dp(n+1, vector<bool>(m+1, -1));
        dp[0][0] = true;
        for(int j = 1; j<=m; j++)dp[0][j]=false;
        for(int i = 1; i<=n; i++){
            bool fl = true;
            for(int x = 1; x<=i; x++){
                if(p[x-1]!='*')fl=false;
            }
            dp[i][0]=fl;
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(p[i-1]==s[j-1]||p[i-1]=='?')dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='*')dp[i][j]=dp[i-1][j] | dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};

int main(){
    
}