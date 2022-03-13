#include <bits/stdc++.h>
using namespace std;

struct MyDS{
    deque<int>dq;
    void insertmin(int x)
    {
        dq.push_front(x);
    }
    void insertmax(int x)
    {
        dq.push_back(x);
    }
    int getmin()
    {
        return dq.front();
    }
    int getmax()
    {
        return dq.back();
    }
    void extract_min()
    {
        dq.pop_front();
    }

    void extract_max()
    {
        dq.pop_back();
    }
};
int main()
{
    MyDS m;
    m.insertmin(10);
    m.insertmin(5);
    m.insertmin(2);
    m.insertmax(15);
    m.insertmax(25);
    m.insertmax(35);
    cout<<m.getmin()<<endl;
    cout<<m.getmax()<<endl;
    m.extract_min();
    m.extract_max();
    cout<<m.getmin()<<endl;
    cout<<m.getmax()<<endl;
    return 0;
}
