#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

int isBST(Node *root, int min, int max)
{
    if(root == NULL)return true;

    return (root->data < max && root->data > min && isBST(root->left, min, root->data)&&isBST(root->right, root->data, max));
}

int main() {
	
	Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(1);  
    root->left->right = new Node(3);  
      
    if(isBST(root,INT_MIN,INT_MAX))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  
          
    return 0;  
	
}
