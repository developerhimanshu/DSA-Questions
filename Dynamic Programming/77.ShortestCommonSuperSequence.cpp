#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        string ans = "";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        int i = n, j = m;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans += str1[i - 1];
                j--;
                i--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    ans += str1[i - 1];
                    i--;
                }
                else
                {
                    ans += str2[j - 1];
                    j--;
                }
            }
        }
        if (i != 0)
        {
            while (i > 0)
            {
                ans += str1[i - 1];
                i--;
            }
        }
        if (j != 0)
        {
            while (j > 0)
            {
                ans += str2[j - 1];
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}