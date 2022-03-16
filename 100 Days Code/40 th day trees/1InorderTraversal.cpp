#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

class Solution{
    private:
     void dfs(Node *root, vector<int> &v)
     {
         if(root == NULL)
            return;
        dfs(root->left, v);
        v.push_back(root->data);
        dfs(root->right, v);
     }

     public:
     vector<int> inorder(Node *root)
     {
         vector<int>v;
        dfs(root, v);
        return v;
     }
};
int main()
{

    Solution s;
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
    vector<int>v = s.inorder(root);
    cout<<"The preorder traversal of this solution is: "<<endl;
   for(int i=0; i<v.size(); i++)
   {
       cout<<v[i]<<" ";
   }
    return 0;
}
