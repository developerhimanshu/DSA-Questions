#include <iostream>

using namespace std;
int max_profit(int price[], int start, int end)
{
    int profit=0;
    if(end<=start)
        return 0;
    for(int i=start; i<end; i++)
    {
        for(int j=i+1; j<=end; j++)
        {
            if(price[j]>price[i])
            {
                int curr_profit=price[j]-price[i]+max_profit(price, start, i-1)+max_profit(price, j+1, end);


                profit=max(profit, curr_profit);
            }
        }
    }
    return profit;
}
int main()
{
    int price[]={5,6,3,7,1};
    cout<<max_profit(price, 0, 4);
    return 0;
}