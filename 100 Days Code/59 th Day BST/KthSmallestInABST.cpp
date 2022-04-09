#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right  = NULL;
    }
};

void printKthSmallest(Node *root, int k, int &count)
{
    while(root!=NULL)
    {
        printKthSmallest(root->left, k);
        count++;
        if(count == k)
        {
            cout<<root->data;
            return;
        }
        printKthSmallest(root->right, k);
    }
}

int main()
{

    return 0;
}
