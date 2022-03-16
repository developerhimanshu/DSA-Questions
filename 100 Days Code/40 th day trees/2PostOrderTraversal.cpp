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

class Solution
{
private:
    void dfs(Node *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        dfs(root->left, v);
        dfs(root->right, v);
        v.push_back(root->data);
    }

public:
    vector<int> postorder(Node *root)
    {
        vector<int> v;
        dfs(root, v);
        return v;
    }
}; 
int main()
{
    Solution s;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->left->right->left = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    vector<int>v = s.postorder(root);
    cout<<"The postorder traversal of this solution is: "<<endl;
   for(int i=0; i<v.size(); i++)
   {
       cout<<v[i]<<" ";
   }
    return 0;
}
