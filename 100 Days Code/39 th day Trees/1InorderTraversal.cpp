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

void preorder(Node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Node *root = new Node(50);
    root->left = new Node(25);
    root->right = new Node(14);
    root->left->left = new Node(19);
    root->left->right = new Node(24); 
    root->right->left = new Node(21);
    root->right->right = new Node(26);
    root->left->left->right = new Node(7);
    root->left->right->left = new Node(12);
    root->right->right->left = new Node(42);
    root->right->right->right = new Node(31);
    cout<<"The preorder traversal of the given tree is:\n";
    preorder(root);
    return 0;
}
