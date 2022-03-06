#include <bits/stdc++.h>
#define R 4
#define C 4
using namespace std;

int largestHistoArea(int arr[], int n)
{
     stack<int>s;
    int res = 0;
    int tp;
    int curr;
    for(int i=0; i<n; i++)
    {
        while(s.empty()==false && arr[i]<=arr[s.top()])
        {
            tp =s.top(); 
            s.pop();
            curr = arr[tp]*(s.empty()?i:(i-s.top()-1));
            res = max (curr, res);
        }
        s.push(i);
    }
    while(s.empty()==false)
    {
        tp = s.top(); s.pop();
        curr = arr[tp]*(s.empty()?n:(n-s.top()-1));
        res = max(curr, res);
    }
    return res;
}

int largestrectangle1s(int matrix[][C])
{
    int res = largestHistoArea(matrix[0], C);
    for(int i=1; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(matrix[i][j]==1)
                matrix[i][j]+=matrix[i-1][j];
        }
        res = max(res, largestHistoArea(matrix[i], C));
    }
    return res;
}
int main()
{
    int mat[][C] = { 
        { 0, 1, 1, 0 }, 
        { 1, 1, 1, 1 }, 
        { 1, 1, 1, 1 }, 
        { 1, 1, 0, 0 }, 
    }; 
  
    cout << "Area of maximum rectangle is " << largestrectangle1s(mat); 
  
    return 0;
}