#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       
     
        vector<int>prev(amount+1, 0), curr(amount+1, 0);
        for(int i=0; i<amount+1; i++){
            if(i%coins[0]==0)prev[i]=i/coins[0];
            else
                prev[i] = INT_MAX;
        }
        for(int ind = 1; ind < coins.size(); ind++){
            for(int tar = 0; tar <=amount; tar++){
                long long notChoose = prev[tar];
                long long choose = 1e9;
                if(coins[ind]<=tar)
                    choose = 1+curr[tar-coins[ind]];
                curr[tar] = min(choose, notChoose);
            }
            prev = curr;
        }
      int ans =  prev[amount];
        if(ans>=1e9)return -1;
        return ans;
    }
};
int main()
{


    return 0;
}