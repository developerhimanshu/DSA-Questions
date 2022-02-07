#include <bits/stdc++.h>
using namespace std;

void PatternSrchDistinct(string &txt, string &ptrn)
{
    int n=txt.length(), m=ptrn.length();

    for(int i=0; i<=n-m;)
    {
        int j;
        for(j=0; j<m; j++)
        {
            if(ptrn[j]!=txt[i+j])
                break;
        }
        if(j==m)
            cout<<i<<" ";
        if(j==0)i++;
        else
            i=i+j;
    }

}
int main()
{
    string text="abacabcdads";
    string pattern="abcd";

    PatternSrchDistinct(text, pattern);

}
