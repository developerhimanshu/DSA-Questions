#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n)
{
    vector<int> dp(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
                temp[j] = 1;
            else
            {
                temp[j] = temp[j - 1] + dp[j];
            }
        }
        dp = temp;
    }
    return dp[n - 1];
}

int main()
{
    int m, n;
    cout<<"Enter the row number and column number of the grid";
    cin>>m>>n;
    cout<<"The no of Unique paths are:";
    cout<<uniquePaths(m , n);
    return 0;
}
