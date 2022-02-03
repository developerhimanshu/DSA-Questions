#include <bits/stdc++.h>
using namespace std;

bool SubSequence(string &s1, string &s2, int m, int n)
{
    if(n==0)
    {
        return true;
    }
    if(m==0)return false;

    if(s1[m-1]==s2[n-1])
        return SubSequence(s1, s2, m-1, n-1);
    else
        return SubSequence(s1, s2, m-1, n);

}
int main()
{
    string s1="abcd";
    string s2="bcd";
    string s3="cda";

    cout<<SubSequence(s1, s2, 4, 3)<<endl;
    cout<<SubSequence(s1, s3, 4, 3)<<endl;


    return 0;
}