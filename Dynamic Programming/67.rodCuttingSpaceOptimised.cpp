/*
Given a rod of length N inches and an array of prices, price[]. pricei denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
     int cutRod(int price[], int n) {
        vector<int>prev(n+1, 0);
        for(int tar=0; tar<=n; tar++){
            prev[tar] = tar*price[0]; 
        }
        
        for(int ind = 1; ind<n; ind++){
            for(int tar = 0; tar<=n; tar++){
                int notPick = prev[tar];
                int pick = INT_MIN;
                int rodLength = ind+1;
                if(tar>=rodLength)
                    pick = price[ind]+prev[tar-(rodLength)];
                prev[tar] = max(pick, notPick);
            }
        }
        return prev[n];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
