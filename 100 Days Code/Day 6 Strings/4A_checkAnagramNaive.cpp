#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool checkAnagram(string &s1, string &s2)  // Time complexity => O(nlog(n))
{
    if(s1.length()!=s2.length())return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1==s2;

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