#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int len = dp[n][m];
        int ind = len-1;
        string res = "";
        for(int i= 0; i<len; i++)res+='$';
        int i = n, j = m;
        while (i > 0 && j > 0){
            if (text1[i - 1] == text2[j - 1]){
                res[ind--] = text1[i - 1];
                i--;
                j--;
            }
            else{
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }
        return res;
    }
};
int main()
{
    string s1 = "bdgek", s2 = "abcde";
    Solution s;
    string res = s.longestCommonSubsequence(s1, s2);
    cout<<res;

    return 0;
}