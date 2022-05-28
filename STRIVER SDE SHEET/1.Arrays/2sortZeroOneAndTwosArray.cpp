class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        for(auto it:nums)
        {
            if(it==0)
                a++;
            else if(it==1)
                b++;
            else
                c++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i+1>=0 && i+1<=a)
            {
                nums[i]=0;
            }
            else if(i+1>=a && i+1<=a+b)
            {
                nums[i]=1;
            }
            else
            {
                nums[i]=2;
            }
        }
    }
};
