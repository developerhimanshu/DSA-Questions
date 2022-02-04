#include <bits/stdc++.h>
using namespace std;

int lftmstRptngIdx(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        bool flag = true;
        for (int j = 0; j < str.length(); j++)
        {
            if (i != j && str[i] == str[j])
            {
                flag = false;
            }
        }
        if(flag==true)
            return i;
    }
    return -1;
}
int main()
{
    string str = "aadcda";
    cout << lftmstRptngIdx(str) << endl;
    return 0;
}