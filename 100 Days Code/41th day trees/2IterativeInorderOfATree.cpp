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
    vector<int> iterativeInorder(TreeNode *root)
    {
        vector<int>v;
        stack<TreeNode*>st;
        TreeNode *node = root;
        while(true)
        {
            if(node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty())break;
                node = st.top();
                st.pop();
                v.push_back(node->data);
                node = node->right;
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
   ans = s.iterativeInorder(root);
   for(auto x:ans)
   {
       cout<<x<<" ";
   }

    return 0;
}
