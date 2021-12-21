#include <iostream>
#include <vector>
using namespace std;

class maxi{
    public:
        int maxsum(vector<int>nums)
        {
            int maxending, res;
            maxending=res=nums[0];
            for(int i=1; i<nums.size(); i++)
            {
                maxending=max(maxending+nums[i], nums[i]);
                res=max(res, maxending);
            }
            return res;
        }
};
int main()
{
    maxi m1;
    vector<int>num={-2,1,-3,4,-1,2,1,-5,4};
    cout<<m1.maxsum(num);


}