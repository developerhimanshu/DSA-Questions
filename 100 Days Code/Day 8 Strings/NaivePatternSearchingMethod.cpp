#include <iostream>
#include <string>
using namespace std;

void PatternSearching(string &txt, string &ptrn)
{
    int n=txt.length(), m=ptrn.length();
    for(int i=0; i<=n-m; i++)
    {
        int j;
        for(j=0; j<m; j++)
        {
            if(ptrn[j]!=txt[i+j]) //That means it is not the pattern
                break;
        }
        if(j==m)
            cout<<i<<" ";   
    }
}
int main()
{
    string str="abacbaba";
    string ptrn="aba";
    PatternSearching(str, ptrn);
    return 0;
}
