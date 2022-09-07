//The intuition same as the way we find LCSubsequnece in tabulation but here when the characters are not matching we just have to set the value as 0 and then we have to take the maximum on the dp[][] array

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        int res = 0;
        for(int i=1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    res = max(res, dp[i][j]);
                }
                else
                    dp[i][j]=0;
            }
        }
        return res;
    }
};



int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}