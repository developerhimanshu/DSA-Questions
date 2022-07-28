//In this problem we have to find the number of ways we can get the given sum from the set of coins and we can take as many coins as we want

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>coins, int sum, int n){
    if(sum==0)return 1; //In this base case we've got the valid nums
    if(n==0)return 0; //In this base case we haven't got the valid nums

   int res = coinChange(coins, sum, n-1);
    if(sum>=coins[n-1]){
        res = res+coinChange(coins, sum-coins[n-1], n);
    }
    return res;
}
int main()
{
    vector<int>coins={1,2, 3};
    int sum = 4;
    cout<<coinChange(coins, sum, coins.size());


    return 0;
}
