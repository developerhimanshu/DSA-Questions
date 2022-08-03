// you are given and array you have to return the maximum adjacent sum in that array Note:- The elements shouldn't be adjacent

#include <bits/stdc++.h>
using namespace std;

int adjacentSum(vector<int>arr, int n){
    vector<int>dp(n, 0);
	       int prev=arr[0];
           int prev2 = 0;
	       for(int i=1; i<n; i++){
	           int take = arr[i];
	           if(i>1)take+=prev2;
	           int notTake = prev;
	           int curri=max(take, notTake);
               prev2 = prev;
               prev = curri;
	       }
	       return prev;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr={4, 1, 8, 9};
    cout<<adjacentSum(arr, n)<<endl;
    return 0;
}
