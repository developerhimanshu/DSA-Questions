#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        string str2="";
        int n = s.length();
        str2 = s;
        reverse(str2.begin(), str2.end());
        // vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        vector<int>prev(n+1, 0), cur(n+1, 0);
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1]==str2[j-1])
                    cur[j] = 1+prev[j-1];
                else
                    cur[j] = max(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        return prev[n];
    }
};

int main()
{
    return 0;
}