#include <bits/stdc++.h>
using namespace std;

long long findNthFibonacci(int number, long long int dp[])
{
    // Your Code Here
    if (dp[number] == 0)
    {
        long long res;
        if (number == 1 || number == 2)
        {
            res = number;
        }
        else
        {
            res = findNthFibonacci(number - 1, dp) + findNthFibonacci(number - 2, dp);
        }
        dp[number] = res;
    }
    return dp[number];
}


int main()
{
    long long dp[100]={0};
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    int number;
    cin>>number;
    cout<<findNthFibonacci(number, dp);
    return 0;
}
