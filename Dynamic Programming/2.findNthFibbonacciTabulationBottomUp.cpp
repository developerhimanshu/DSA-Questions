#include <bits/stdc++.h>
using namespace std;
long long findNthFibonacci(int number)
{
    // Your Code Here
    long long dp[number + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= number; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[number];
}

int main()
{
    int number;
    cin >> number;
    cout << findNthFibonacci(number);
    return 0;
}
