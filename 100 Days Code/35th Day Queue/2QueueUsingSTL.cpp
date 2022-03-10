#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.size()<<endl;
    while(q.empty()== false)
    {
        cout<<q.front()<<" "<<q.back()<<endl;
        q.pop(); 
    }
    return 0;
}
