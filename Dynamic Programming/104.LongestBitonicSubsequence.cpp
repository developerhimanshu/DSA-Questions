#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	
	//idea is to find longest increasing subsequence and longest decreasing subsequnce
	//Then for every point add the lis and lds and then sub them by 1 because there is 1 common element
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    int ans = 1;
	    vector<int>dp1(n, 1), dp2(n, 1);
	    
	    for(int i=0; i<n; i++){
	        for(int prev  = 0; prev<i; prev++){
	            if(nums[prev]<nums[i]){
	                if(dp1[i]<dp1[prev]+1)
	                    dp1[i] = dp1[prev]+1;
	            }
	        }
	    }
	    for(int i=n-1; i>=0; i--){
	        for(int prev  = n-1; prev>i; prev--){
	            if(nums[prev]<nums[i]){
	                if(dp2[i]<dp2[prev]+1)
	                    dp2[i] = dp2[prev]+1;
	            }
	        }
	    }
	  
	    for(int i = 0; i<n; i++){
	        ans = max(ans, dp1[i]+dp2[i]-1);
	    }
	    return ans;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}