//This algorithm find the given pattern in a string using the concept of Lps array in O(m+n) time

#include <bits/stdc++.h>
using namespace std;

void fillLPS(string &str, int lps[])
{
    int n=str.length(), len=0;
    lps[0]=0;
    int i=1;
    while(i<n)
    {
        if(str[i]==str[len])
        {len++; lps[i]=len; i++; }
        else{
            if(len==0)
            {lps[i]=0; i++;}
            else
            {
                len=lps[len-1];
            }
        }
    }
}

void KmpPatternfind(string &str, string &ptrn)
{
    int m=str.length();
    int n=ptrn.length();
    int lps[m];
    fillLPS(ptrn, lps);
    int i=0, j=0;
    while(i<m)
    {
        if(str[i]==ptrn[j]){i++, j++;}
        if(j==n){cout<<(i-n)<<" "; j=lps[j-1];}
        else if(i<m && ptrn[j]!=str[i])
        {
            if(j==0){i++;}
            else{j=lps[j-1];} //This step will make j the previous lps element
        }
    }
}
int main()
{
    string str="abacabacab";
    string ptrn="aba";
    KmpPatternfind(str, ptrn);
    return 0;
}