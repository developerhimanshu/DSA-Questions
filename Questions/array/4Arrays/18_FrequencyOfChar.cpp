#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int freq[26];
    for(int i=0; i<26; i++)
    {
        freq[i]=0;
    }
    for(int i=0;i<str.length(); i++)
    {
        freq[str[i]-'a']++;
    }
    for(int i=0; i<str.length(); i++)
    {
        if(freq[str[i]-'a']!=0)
        {
            cout<<str[i]<<" "<<freq[str[i]-'a']<<endl;
        }
        freq[str[i]-'a']=0;
    }
    return 0;
}