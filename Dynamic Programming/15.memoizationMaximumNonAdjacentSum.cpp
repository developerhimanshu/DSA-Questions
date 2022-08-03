// you are given and array you have to return the maximum adjacent sum in that array Note:- The elements shouldn't be adjacent

#include <bits/stdc++.h>
using namespace std;

int adjacentSum(vector<int>arr, int n, vector<int>&dp){
    if(n==0)return arr[n];
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];

    int pick = arr[n]+adjacentSum(arr, n-2, dp);//As we are picking non adjacant element as after picing an element we won't go to its adjacent instead we will go to its second next element
    int notPick = 0+adjacentSum(arr, n-1, dp);
    return dp[n]=max(pick, notPick);
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr={4, 1, 8, 9};
    vector<int>dp(n, -1);
    cout<<adjacentSum(arr, n-1, dp)<<endl;
    return 0;
}
