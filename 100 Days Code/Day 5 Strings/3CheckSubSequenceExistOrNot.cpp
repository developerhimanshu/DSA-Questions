#include <bits/stdc++.h>

using namespace std;

bool checkSubsequence(string &s1, string &s2)
{
    int i=0, j=0;
    while(i!=s1.length() && j!=s2.length())
    {
        if(s1[i]==s2[j])
        {
            i++, j++;
        }
        else
            i++;
    }
    return j==s2.length();
}
int main()
{
    string s1="abcd";
    string s2="cd";
    string s3="da";
    cout<<checkSubsequence(s1, s2)<<endl;
    cout<<checkSubsequence(s1, s3)<<endl;
    return 0;
}