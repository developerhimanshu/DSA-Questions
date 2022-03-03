#include <bits/stdc++.h>
using namespace std;

struct kStacks
{
    int *arr, *next, *top;
    int cap, k;
    int freetop;
    kStacks(int k1, int c)
    {
        cap = c, k = k1;
        arr = new int[cap];
        top = new int[k];
        next = new int[cap];

        for (int i = 0; i < k; i++)
        {
            top[i] = -1;
        }
        freetop=0;
        for(int  i= 0; i<cap-1; i++)
        {
            next[i]=i+1;
        }
        next[cap-1]=-1;
    }
    bool isFull()   {  return (freetop == -1);  } 
  
    bool isEmpty(int sn)  {  return (top[sn] == -1); }
    bool push(int data, int stkno)
    {
        if (isFull()) 
        {
            cout<<"Stack Overfolow"<<endl;
            return 0;
        }
        else
        {
            int index = freetop;
            arr[index] = data;
            freetop = next[index];
            next[index] = top[stkno];
            top[stkno] = index;
            return 1;
        }
    }
    
    int pop(int stkno)
    {
        if (isEmpty(stkno)) 
        {
          cout<<"Stack Underflow"<<endl;
          return INT_MAX;
        }
       int index = top[stkno];
       stkno = next[index];
       next[index] = freetop;
       freetop = index;
       return arr[index];
    }
};

int main()
{  int k = 3, n = 10; 
    kStacks ks(k, n); 
  
    ks.push(15, 2); 
    ks.push(45, 2); 
   
    ks.push(17, 1); 
    ks.push(49, 1); 
    ks.push(39, 1); 
   
    ks.push(11, 0); 
    ks.push(9, 0); 
    ks.push(7, 0); 
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 
  
    return 0; 
}

