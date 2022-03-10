#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    queue<int> q1, q2;
    int curr_size;

public:
    Stack()
    {
        curr_size = 0;
    }

    void push(int x)
    {
        curr_size++;
        //Firstly push x in the empty queue 
        q2.push(x);

        //Then push all the elements in that queue
        while (q1.empty() == false)
        {
            q2.push(q1.front());
            q1.pop();
        }

        //Swap the names of the two queues
        queue<int> q;
        q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
        curr_size--;
    }

    int top()
    {
        if(q1.empty())
            return INT_MIN ;
        return q1.front();
    }

    int size()
    {
        return curr_size;
    }
};
int main()
{
	Stack s; 
	s.push(10); 
	s.push(5); 
	s.push(15); 
	s.push(20);

	cout << "current size: " << s.size() << endl; 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 

	cout << "current size: " <<  s.size() << endl; 
	return 0; 
} 
