#include <iostream>
using namespace std;

struct TwoStacks{
    int *arr, cap, top1, top2;
    TwoStacks(int x)
    {
        cap = x;
        top1 = -1;
        top2 = cap;
        arr = new int[cap];
    }

    void push1(int ele)
    {
        if(top1<top2-1)
        {
            top1++;
            arr[top1] = ele;
        }
    }
    void push2(int ele)
    {
        if(top1<top2-1)
        {
            top2--;
            arr[top2] = ele;
        }
    }
    int pop1(){
        if(top1>=0)
        {
            int ele = arr[top1];
            top1--;
            return ele;
        }
        else
            exit(1);
    }
    int pop2(){
        if(top2<cap)
        {
            int ele = arr[top2];
            top2++;
            return ele;
        }
        else
            exit(1);
    }

    int peek1()
    {
        return arr[top1];
    }
    int peek2()
    {
        return arr[top2];
    }
};
int main()
{
    TwoStacks t(6);
    t.push1(10);
    t.push1(20);
    t.push1(30);
    t.push2(40);
    t.push2(12);
    t.push2(15);
    cout<<t.peek1()<<endl;
    cout<<t.peek2()<<endl;
    t.pop1();
    t.pop2();
     cout<<t.peek1()<<endl;
    cout<<t.peek2()<<endl;


    return 0;
}
