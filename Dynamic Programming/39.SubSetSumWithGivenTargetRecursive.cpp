#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    if(k == 0)return true;
    if(n == 0)return (arr[n]==k);
    
    bool notPick = subsetSumToK(n-1, k, arr);
    bool pick = false;
    if(k>=arr[n])pick = subsetSumToK(n-1, k-arr[n], arr);
    
    return pick or notPick;
}

int main()
{

    return 0;
}