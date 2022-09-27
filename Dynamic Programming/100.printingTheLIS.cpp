#include <bits/stdc++.h>
using namespace std;

  int lengthOfLIS(vector<int>&nums){
        int n = nums.size();
        int lastind = 0;
        vector<int>dp(n, 1);
        vector<int>hash(n);
        for(int i =0; i<n; i++)
            hash[i]=i;
        for(int i = 0; i<n; i++){
            for(int prev = 0; prev < i; prev ++){
                if(nums[prev]<nums[i] && 1+dp[prev] > dp[i]){
                    dp[i] =1+dp[prev];
                    hash[i]=prev;
                }
            }
        }
        int maxi = 1;
        for(int i = 0; i<n; i++){
            if(dp[i]>maxi){
                maxi = dp[i];
                lastind = i;
            }
        }
        
        vector<int>temp;
        temp.push_back(nums[lastind]);
        while(hash[lastind]!=lastind){
            lastind = hash[lastind];
            temp.push_back(nums[lastind]);
        }
        reverse(temp.begin(), temp.end());
        for(auto x:temp)
            cout<<x<<" ";
        cout<<'\n';
        return maxi;
    }

    int main()
    {

        return 0;
    }