#include <iostream>
#include <stack>
using namespace std;


int main()
{
    stack<int>s;
    s.push(10);
    s.push(15);
    s.push(20);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    // The time complexity of all the operations of the stack is O(1) as they use another containers for their working therefore they are known as container adapter
    return 0;
}
