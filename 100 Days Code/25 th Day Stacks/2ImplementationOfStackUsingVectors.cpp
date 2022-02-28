#include <iostream>
#include <vector>

using namespace std;

struct Mystack{
    vector<int>v;
    void push(int x)
    {
        v.push_back(x);
    }
    int pop()
    {
        int res = v.back();
        v.pop_back();
        return res;
    }
    int peek()
    {
        return v.back();
    }

    int size()
    {
        return v.size();
    }
    bool isEmpty()
    {
        return v.empty();
    }
};
int main()
{
    Mystack s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<"size of stack is: "<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}
