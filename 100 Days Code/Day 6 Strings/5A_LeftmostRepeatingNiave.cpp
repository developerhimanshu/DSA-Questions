#include <bits/stdc++.h>
using namespace std;

int leftMostRepeating(string &str)
{
    for(int i=0; i<str.length(); i++)
    {
        for(int j=i+1; j<str.length(); j++)
        {
            if(str[j]==str[i])
                return i;
        }
    }
    return -1;
}
int main()
{
    string str="abcrdc";
    cout<<leftMostRepeating(str)<<endl;
    return 0;
}