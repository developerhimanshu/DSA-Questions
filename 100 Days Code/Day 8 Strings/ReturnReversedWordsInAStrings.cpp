#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to reverse words in a given string.
   string reverseWords(string str)
   {
       string currWord="";
       string revword="";
       
       vector<string>words;
       for(int i=0; i<str.length(); i++)
       {
           if(str[i]=='.')
           {
                words.push_back(currWord);
                currWord="";
           }
           else
           {
               currWord+=str[i];
           }
        }
        words.push_back(currWord);//inserting last word
        for(int i=words.size()-1;i>=0; i--)
        {
            revword+=words[i];
            if(i!=0)
                revword+='.';
        }
        return revword;
       
   }
};
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
} 
