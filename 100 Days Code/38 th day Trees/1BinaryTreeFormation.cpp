#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *right;
    Node *left;
    Node(int d)
    {
        data =d;
        left = right = NULL;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->right = new Node(4);
    root->right->left = new Node(25); 
    return 0;
}
