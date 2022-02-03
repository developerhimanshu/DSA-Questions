#include <iostream>
#include <string>
using namespace std;

const int CHAR=256;

bool checkAnagram(string &s1, string &s2)  //  Time complexity=> O(lengthOfstring)
{
    if(s1.length()!=s2.length())return false;
    int count[CHAR]={0};

    for(int i=0; i<s1.length(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for(int i=0; i<CHAR; i++)
    {
        if(count[i]>0)
            return false;
    }
    return true;
}
int main()
{
    string s1="rat";
    string s2="tar";
    string s3="rap";
    cout<<checkAnagram(s1, s2)<<endl;
    cout<<checkAnagram(s1, s3)<<endl;
    return 0;
}