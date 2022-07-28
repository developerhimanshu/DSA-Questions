#include <bits/stdc++.h>
using namespace std;

 int dp[1001][1001];
int lcs(int i, int j,string s1, string s2, string &s, int m, int n){
    if(dp[i][j]!=-1)return dp[i][j];
   if(i==m||j==n)return 0;
   if(s1[i]==s2[j]){
        s+=s1[i];
      return dp[i][j]=1+ lcs(i+1, j+1, s1, s2, s, m, n);
   }else{
     int val1 = lcs(i, j+1, s1, s2, s, m, n);
     int val2= lcs(i+1, j, s1, s2, s, m, n);
     return dp[i][j]= max(val1, val2);
   }
}
int main()
{
    int m, n;
    cin>>m>>n;
    string s1, s2, res;
    cin>>s1>>s2;
    res="";
    // vector<vector<int>>dp(s1.length(), vector<int>(s2.length(), -1));
    memset(dp, -1, sizeof(dp));
    lcs(0, 0, s1, s2, res, s1.length(), s2.length());
    cout<<res<<endl;
    return 0;
}
