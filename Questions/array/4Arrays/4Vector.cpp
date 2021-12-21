#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> arr(10, 7);
    arr.push_back(16);
    for(int i=0; i<arr.size();i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}