#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class solution
{
public:
    vector<int> iterativePostorder(TreeNode *root)
    {
        vector<int> v;
        if(root == NULL)return v;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (curr != NULL || !stk.empty())
        {
            if (curr != NULL)
            {
                stk.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode *temp = stk.top()->right;
                if (temp == NULL)
                {
                    temp = stk.top();
                    stk.pop();
                    v.push_back(temp->data);
                    while(!stk.empty() &&temp ==stk.top()->right)
                    {
                        temp = stk.top();
                        stk.pop();
                        v.push_back(temp->data);
                    }
                }
                else
                    curr = temp;
            }
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
