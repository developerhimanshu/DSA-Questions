#include <iostream>

using namespace std;
void twoOddoccurence(int arr[], int n)
{   
    int XOR=0, res1=0, res2=0;
    for(int i=0; i<n; i++)
    {
        XOR=XOR^arr[i];
    }
    int rs=XOR&(~(XOR-1));  //For rightmost set bit
    for(int i=0; i<n; i++)
    {
        if((rs&arr[i])!=0)
        {
            res1=res1^arr[i];
        }
        else
        {
            res2=res2^arr[i];
        }
    }
    cout<<res1<<" "<<res2<<endl;
}
int main()
{
    	int arr[]= {3, 4, 3, 4, 5, 4, 4, 6, 7, 7}, n = 10;
	
    twoOddoccurence(arr, n);
    
    return 0;
}
