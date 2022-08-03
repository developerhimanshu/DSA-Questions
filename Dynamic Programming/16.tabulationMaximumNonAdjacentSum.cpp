// you are given and array you have to return the maximum adjacent sum in that array Note:- The elements shouldn't be adjacent

#include <bits/stdc++.h>
using namespace std;

int adjacentSum(vector<int>arr, int n){
    vector<int>dp(n, 0);
	       dp[0]=arr[0];
	       for(int i=1; i<n; i++){
	           int take = arr[i];
	           if(i>1)take+=dp[i-2];
	           int notTake = dp[i-1];
	           dp[i]=max(take, notTake);
	       }
	       return dp[n-1];
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr={4, 1, 8, 9};
    cout<<adjacentSum(arr, n)<<endl;
    return 0;
}
