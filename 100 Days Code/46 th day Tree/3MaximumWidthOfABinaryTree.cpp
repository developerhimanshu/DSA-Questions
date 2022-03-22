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
    int maxWidth(TreeNode *root)
    {
        if(root == NULL)return -1;
        queue<TreeNode*>q;
        q.push(root);
        int res = INT_MIN;
        while(!q.empty())
        {
            int count = q.size();
            res = max(res, count);
            for(int i = 0; i < count; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        return res;
    }
};
int main()
{
    solution s;
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
	root->right->left=new TreeNode(60);
    cout<<s.maxWidth(root)<<endl;
    return 0;
}
