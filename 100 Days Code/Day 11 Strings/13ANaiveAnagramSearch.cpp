#include <bits/stdc++.h>
using namespace std;
const int CHAR=256;
bool areAnagram(string &ptrn, string &txt,int i)
{
    int count[CHAR]={0};
   for(int j=0; j<ptrn.length();j++)
   {
       count[ptrn[j]]++;
       count[txt[i+j]]--;
   }

   for(int j=0; j<CHAR; j++)
   {
       if(count[j]!=0)
        return false;
   }
   return true;
}

bool anaSearch(string &txt, string &ptrn)
{
   int n=txt.length(), m=ptrn.length();
   for(int i=0; i<n-m; i++) 
   {
       if(areAnagram(ptrn, txt, i))
            return true;
   }
   return false;
}

int main()
{
    string str="himanshu";
    string ptrn="manshi";
    cout<<anaSearch(str, ptrn)<<endl;

    return 0;
}