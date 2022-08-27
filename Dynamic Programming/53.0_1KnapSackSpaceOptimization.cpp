//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.

    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // vector<int>curr(W+1, 0);
        vector<int>prev(W+1, 0);
        for(int i = wt[0]; i <=W; i++){
                prev[i]=val[0];
        }
        for(int ind = 1; ind<n; ind++){
            for(int wtg = W; wtg>=0; wtg--){
                int notPick = 0+prev[wtg];
                int pick = INT_MIN;
                if(wt[ind]<=wtg){
                    pick =val[ind] + prev[wtg-wt[ind]];
                }
                prev[wtg] = max(pick, notPick);
            }
        }
       return prev[W];
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends