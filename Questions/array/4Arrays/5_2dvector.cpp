#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>>arr={
        {1,4,5},
        {45, 75,12,5},
        {9, 0, 4}
    };

    for(int i=0; i<arr.size(); i++)
    {
        for(int x: arr[i])
        {
            cout<<x<<",";
        }
        cout<<endl;
    }

    return 0;
}