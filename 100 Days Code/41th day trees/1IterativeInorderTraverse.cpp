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
    vector<int> inorder(TreeNode *root)
    {
        vector<int>traverse;
        if(root == NULL)return traverse;
        stack <TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* Node = st.top();
            st.pop();
            traverse.push_back(Node->data);
            if(Node->right != NULL)
            {
                st.push(Node->right);
            }
            if(Node->left != NULL)
            {
                st.push(Node->left);
            }
        }
        return traverse;
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
   vector <int>ans;
   ans = s.inorder(root);
   for(auto x:ans)
   {
       cout<<x<<" ";
   }
}
