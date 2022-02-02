#include <iostream>
#include <string>

using namespace std;

bool isPal(string str)
{
    string res;
    int n=str.length();
    for(int i=0; i<n; i++)
        res[i]=str[n-i-1];
    
    return res==str;
}

int main()
{
    string str="abba";
    cout<<isPal(str);

    return 0;
}