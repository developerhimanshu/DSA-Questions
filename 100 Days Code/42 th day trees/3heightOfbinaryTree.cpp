#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left, *right;
    TreeNode(int d)
    {
        data = d;
        left = right = NULL;
    }
};

class solution{
    public:
        int height(TreeNode *node)
        {
            if(node == NULL)
                return 0;
            return max(height(node->left), height(node->right))+1;
        }
};

int main()
{
    solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);                     
    root->right = new TreeNode(3);                    
    root->left->left = new TreeNode(4);              
    root->left->right = new TreeNode(5);           
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    // root->left->left->right = new Node(7);
    root->left->right->left = new TreeNode(6);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);
    cout<<"Height of this binary tree is: ";
    cout<<s.height(root);
    return 0;
}
