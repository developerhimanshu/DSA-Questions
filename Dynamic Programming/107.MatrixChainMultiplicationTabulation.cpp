/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).


Example 1:

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

*/
#include <bits/stdc++.h>
using namespace std;



class Solution{
public:
   int matrixMultiplication(int N, int arr[])
    {
        
       int dp[N][N];
        for(int i = 1; i<N; i++){
            dp[i][i]=0;
        }
        for(int i = N-1; i>=1; i--){
            for(int j = i+1; j<N; j++){
                int mini = 1e9;
                for(int k = i; k<j; k++){
                    int steps = arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    mini = min(mini, steps);
                }
                dp[i][j]= mini;
            }
        }
        return dp[1][N-1];
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}