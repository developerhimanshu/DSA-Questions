#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, 0));
        for(int i=0; i<amount+1; i++){
            if(i%coins[0]==0)dp[0][i]=i/coins[0];
            else
                dp[0][i] = INT_MAX;
        }
        for(int ind = 1; ind < coins.size(); ind++){
            for(int tar = 0; tar <=amount; tar++){
                long long notChoose = dp[ind-1][tar];
                long long choose = 1e9;
                if(coins[ind]<=tar)
                    choose = 1+dp[ind][tar-coins[ind]];
                dp[ind][tar] = min(choose, notChoose);
            }
        }
      int ans =  dp[coins.size()-1][amount];
        if(ans>=1e9)return -1;
        return ans;
    }
};

int main()
{


    return 0;
}