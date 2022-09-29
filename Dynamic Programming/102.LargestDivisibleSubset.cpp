/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>hash(n);
        for(int i=0; i<n ;i++)hash[i]=i;
        
        for(int i=0; i<n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i]%nums[j]==0&&1+dp[j]>dp[i])
                {   
                dp[i] = 1+dp[j];
                 hash[i] = j;  // We are storing the index in the hash
                }
            }
        }
        int lastInd = 0;
        int maxi = 1;
        for(int i = 0; i<n; i++){
            if(dp[i]>maxi){
                maxi = dp[i];
                lastInd = i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd){
            lastInd = hash[lastInd];
            ans.push_back(nums[lastInd]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{


    return 0;
}