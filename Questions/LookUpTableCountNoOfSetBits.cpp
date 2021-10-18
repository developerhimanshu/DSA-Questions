#include <iostream>
using namespace std;
int table[256];
void initialize()
{
    for(int i=1; i<256; i++)
    {
        table[i]=(i&1)+table[i/2];
    }
}
int countSetBits(int n)
{
    return table[n&(0xff)]+table[(n>>8)&(0xff)]+table[(n>>16)&(0xff)]+table[(n>>24)];
    // int res=table[n&(0xff)];
    // res=res>>8;
    // res=res+table[n&0xff];
    // res=res>>8;
    // res=res+table[n&(0xff)];
    // res=res>>8;
    // res=res+table[n&(0xff)];
    // return res;
}
int main()
{
    initialize(); //  => Initializing the table
    int n;
    cin>>n;
   cout<< countSetBits(n);
          
return 0;
}
