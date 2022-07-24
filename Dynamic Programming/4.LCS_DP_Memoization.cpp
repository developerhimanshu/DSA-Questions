#include <bits/stdc++.h>
using namespace std;

 int dp[1001][1001];
    //Function to find the length of longest common subsequence in two strings.
    int rec(int i, int j, int n, int m, string s1, string s2) {
        if(i==n or j==m)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(s1[i]==s2[j])
        return dp[i][j] = 1 + rec(i+1,j+1,n,m,s1,s2);
        else {
            int choice1 = rec(i+1,j,n,m,s1,s2);
            int choice2 = rec(i,j+1,n,m,s1,s2);
            
            return dp[i][j] = max(choice1,choice2);
        }
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int n = s1.size();
        int m = s2.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,n,m,s1,s2);
    }
int main()
{


    return 0;
}
