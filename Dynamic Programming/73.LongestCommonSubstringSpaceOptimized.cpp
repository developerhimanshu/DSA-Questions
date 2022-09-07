#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<int>prev(m+1, 0), cur(m+1, 0);
        int res = 0;
        for(int i=1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(S1[i-1]==S2[j-1]){
                    cur[j]=1+prev[j-1];
                    res = max(res, cur[j]);
                }
                else
                    cur[j]=0;
            }
            prev = cur;
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