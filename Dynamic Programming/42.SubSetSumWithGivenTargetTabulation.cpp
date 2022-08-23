#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool>prev(k+1, 0), curr(k+1, 0);
    prev[0] = curr[0] = true;
    for(int i = 0; i<n; i++){
        prev[0] = true;
    }
    if(arr[0] <= k){
        prev[arr[0]] = true;
    }
    
    for(int ind= 1; ind < n; ind++){
        for(int tar = 1; tar < k+1; tar++){
            bool notTake = prev[tar];
            bool take = false;
            if(arr[ind]<=tar)
                take = prev[tar-arr[ind]];
            curr[tar]=take|notTake;
        }
        prev = curr;
    }
    return prev[k];
}


int main()
{

    return 0;
}