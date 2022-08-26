#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9+7);

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>>dp(n, vector<int>(tar+1, 0));
    vector<int>prev(tar+1), curr(tar+1);
    if(num[0]==0)prev[0]=2;
    else prev[0] = 1;
    
    if(num[0]!=0 &&num[0]<=tar)prev[num[0]]  = 1;
    
    for(int i = 1; i<n; i++){
        for(int sum = 0; sum <= tar; sum++){
            int notTake = prev[sum];
            int take = 0;
            if(num[i]<=sum)take =prev[sum-num[i]];
            curr[sum]=(take+notTake)%mod;
        }
        prev = curr;
    }
    return prev[tar];
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(auto &x:arr)
        totalSum+=x;
    if(totalSum-d < 0 || (totalSum-d) %2)return 0;
    vector<vector<int>>dp(n, vector<int>(((totalSum-d)/2)+1, -1));
    return findWays(arr,(totalSum-d)/2);
}


int main()
{
    vector<int> arr = {0,0,1};
    int k=1;
                                 
     cout<<"The number of subsets found are " <<findWays(arr,k);
}