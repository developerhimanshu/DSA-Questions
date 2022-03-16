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
    vector<vector<int>> levelorder(TreeNode *root)
    {
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false)
        {
            vector<int>level;
            int size = q.size();
            for(int i=0; i < size; i++)
            {
                TreeNode *Node = q.front();
                q.pop();
                if(Node->left != NULL)q.push(Node->left);
                if(Node->right != NULL)q.push(Node->right);
                level.push_back(Node->data);
            }
            ans.push_back(level);
        }
        return ans;
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
   vector<vector <int>>ans;
   ans = s.levelorder(root);
   cout<<"The level order traversal of this tree is\n";
   for(int i=0; i<ans.size(); i++)
   {
       for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
   }
}
