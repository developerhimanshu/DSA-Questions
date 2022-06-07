//we are given an array of coins and an amount find minimum number of coins to get the amount

#include <bits/stdc++.h>
using namespace std;

int minimumCoins(int coins[], int n, int amount){
    sort(coins, coins+n);
    int res = 0;
    for(int i=n-1; i>=0; i--){
        if(coins[i]<=amount){
            int c = floor(amount/coins[i]);
            res = res +c;
            amount = amount - c*coins[i];
        }
        if(amount ==0)
            break;
        }
        return res;

}
int main()
{
    int coin[] = {5, 10, 2, 1}, n = 4, amount = 57;
      
      cout<<minimumCoins(coin, n, amount);
    return 0;
}
