#include <bits/stdc++.h>
using namespace std;

const int CHAR=256;

int leftMostRepeating(string &str)
{
    bool visited[CHAR];
    fill(visited, visited+CHAR, false);
    int res;
    for(int i=str.length(); i>=0; i--)
    {
        if(visited[str[i]])
            res=i;
        else
           visited[str[i]]=true;
    }
    return res;
}
int main()
{
    string str="abcrdc";
    cout<<leftMostRepeating(str)<<endl;

    return 0;
}