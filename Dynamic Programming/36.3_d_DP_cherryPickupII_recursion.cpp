#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i, int j1, int j2, int r, int c,  vector<vector<int>>& grid){
        if(j1<0||j2<0||j1>=c||j2>=c)
            return -1e8;
        
        if(i==r-1){
            if(j1==j2)return grid[i][j1];
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        
        //explore all the paths simultaneously
        int maxi = -1e8;
        for(int dj1 = -1; dj1<=1; dj1++){
            for(int dj2 = -1; dj2<=1; dj2++){
                int value = 0;
                if(j1==j2)value = grid[i][j1];
                else value = grid[i][j1]+grid[i][j2];
                value+=f(i+1, j1+dj1, j2+dj2, r, c, grid);
                maxi = max(maxi, value);
            }
        }
        return maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        return f(0, 0, c-1, r, c, grid);
    }
};
int main()
{

    return 0;
}