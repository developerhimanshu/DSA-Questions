#include<iostream>
#include <string>
#include <cmath>
using namespace std;
void powersetBitwise(string str)
{
    int n= str.length();
    int power=pow(2,n);
    for(int counter=0; counter <power; counter++)
    {
        for(int j=0; j<n; j++)
        {
            if((counter&(1<<j))!=0)
                cout<<str[j];
        }
        cout<<endl;
    }
}

int main()
{
    string str="abc";
    powersetBitwise(str);

    return 0;
}
