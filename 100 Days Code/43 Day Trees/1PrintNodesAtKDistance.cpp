 void printkthdist(TreeNode *root, int k)
    {
        if(root == NULL)
            return;
        if(k==0)
        {
            cout<<root->data<<" ";
            return;
        }
        else
        {
            printkthdist(root->left, k-1);
            printkthdist(root->right, k-1);
        }
    }
