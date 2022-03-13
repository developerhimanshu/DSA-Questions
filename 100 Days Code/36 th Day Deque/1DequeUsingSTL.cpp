#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int>dq={10, 15, 20};
    dq.push_front(5);
    dq.push_back(25);
    for(auto x: dq)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    cout<<dq.front()<<" "<<dq.back()<<endl;

    auto it = dq.begin();
    it++;
    dq.insert(it, 20);
    for(auto x: dq)
        cout<<x<<" ";
    cout<<"\n";
    return 0;
}
