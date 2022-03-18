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
        vector <int> iterativePostorder(TreeNode *root)
        {
            vector<int> v;
            stack<TreeNode *>stk1, stk2;
            stk1.push(root);
            while(!stk1.empty())
            {
                TreeNode *node = stk1.top();
                stk1.pop();
                stk2.push(node);
                if(node->left !=NULL)
                    stk1.push(node->left);
                if(node->right != NULL)
                    stk1.push(node->right);
            }
            while(!stk2.empty())
            {
                v.push_back(stk2.top()->data);
                stk2.pop();
            }
            return v;
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
   ans = s.iterativePostorder(root);
   for(auto x:ans)
   {
       cout<<x<<" ";
   }

    return 0;
}
