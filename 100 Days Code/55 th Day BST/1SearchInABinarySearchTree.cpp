#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *search(Node *root, int key)
{
    if(root == NULL)
        return NULL;
    if(root->data == key)
    {
        return root;
    }
    else if(root->data <key)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}
int main()
{
    Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int x=16;
	
	if(search(root,x))
	    cout<<"Found";
	else
	    cout<<"Not Found";

    return 0;
}
