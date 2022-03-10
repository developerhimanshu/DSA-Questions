#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x)
    {
            data = x; next = NULL;
    }
};

struct Queue
{
    Node *head, *rear; int size;
    Queue()
    {
        head = rear = NULL;
        size = 0;
    }
    bool isEmpty(){
        return  (head == NULL &&rear==NULL);
    }
    void enQueue(int x){
        Node *temp = new Node(x);
        if(isEmpty())
        {
            head = rear = temp;
            size++;
            return;
        }
        rear->next = temp;
        rear = temp;
        size++;
    }

    void deQueue()
    {
        if(head == NULL)return;
        Node *temp = head;
        head =head->next;
        if(head == NULL)
        {
            rear =NULL;
            size--;
        }
        delete(temp);
        size--;
    }
};
int main()
{
	Queue q; 
	q.enQueue(10); 
	q.enQueue(20); 
	q.deQueue(); 
	q.deQueue(); 
	q.enQueue(30); 
	q.enQueue(40); 
	q.enQueue(50); 
	q.deQueue(); 
	cout << "Queue Front : " << (q.head)->data << endl; 
	cout << "Queue Rear : " << (q.rear)->data; 
} 
