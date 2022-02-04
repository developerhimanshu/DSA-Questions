#include <bits/stdc++.h>
using namespace std;

const int CHAR=256;
int lftmostNonRptng(string &str)
{
    int fi[CHAR];
    fill(fi, fi+CHAR, -1);
    for(int i=0; i<str.length(); i++)
    {
        if(fi[str[i]]==-1)
        {
           fi[str[i]]=i; 
        }
        else
            fi[str[i]]=-2;
    }
    int res=INT_MAX;
    for(int i=0; i<CHAR; i++)
    {
        if(fi[i]>=0)
          res=min(res, fi[i]);
    }
    return (res==INT_MAX)?-1:res;
}

int main()
{
    string str = "aadcda";
    cout <<lftmostNonRptng(str) << endl;

    return 0;
}