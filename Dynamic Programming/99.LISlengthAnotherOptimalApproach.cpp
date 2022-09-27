    int lengthOfLIS(vector<int>&nums){
        int n = nums.size();
        vector<int>dp(n, 1);
        for(int i = 0; i<n; i++){
            for(int prev = 0; prev < i; prev ++){
                if(nums[prev]<nums[i]){
                    dp[i] = max(1+dp[prev], dp[i]);
                }
            }
        }
        int maxi = INT_MIN;
        for(auto x:dp){
            maxi = max(maxi, x);
        }
        return maxi;
    }