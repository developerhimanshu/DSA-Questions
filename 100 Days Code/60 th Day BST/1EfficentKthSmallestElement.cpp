#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int lcount;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        lcount =0;
        left = right = NULL;
    }
};

Node *insert(Node *root, int key)
{
    if(root == NULL)
        return new Node(key);
    if(key < root->data)
    {
       root->left = insert(root->left, key);
        root->lcount++;
    }
    else if(key > root->data)
        root->right = insert(root->right, key);
    return root;
}

Node *kthSmallest(Node *root , int k)
{
    if(root == NULL)
        return NULL;
    int count = root->lcount +1;
    if(count == k)
        return root;
    if(count > k)
        return kthSmallest(root->left, k);
        
    return kthSmallest(root->right, k-count);
}
int main()
{
    Node *root = NULL;
    int keys[]={ 20, 8, 22, 4, 12, 10, 14};

    for(int x: keys)
        root = insert(root, x);
    int k = 4;
    Node *res = kthSmallest(root, k);    
    
    if(res == NULL)
        cout<<"There are less than "<<k<<" nodes in the tree"<<endl;
    else 
        cout<<"k-th Smallest Element is: "<< res->data<<endl;
    return 0;
}
