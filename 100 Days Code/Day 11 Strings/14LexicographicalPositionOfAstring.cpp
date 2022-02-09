#include <bits/stdc++.h>
using namespace std;

const int CHAR=256;
int fact(int n)
{
    if(n==0)
        return 1;
    return n*fact(n-1);
}
int LexiPos(string &str)
{
    int n=str.length();
    int res=1;
    int count[CHAR]={0};
    int mul=fact(n);
    for(int i=0; i<n; i++)
    {
        count[str[i]]++;
    }
    for(int i=1; i<CHAR; i++)
    {
        count[i]+=count[i-1];
    }

    for(int i=0; i<n-1;i++)
    {
        mul=mul/(n-i);
        res+=count[str[i]-1]*mul;
        for(int j=str[i]; j<CHAR; j++)
            count[j]--;
    }
    return res;
}

int main()
{
    string str="Himanshu";
    string str1="bac";
    cout<<LexiPos(str)<<endl;
    cout<<LexiPos(str1)<<endl;
    return 0;
}