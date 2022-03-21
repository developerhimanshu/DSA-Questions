  bool isChildrenSum(TreeNode *root)
    {
        if(root == NULL)
            return true;
        if(root->left == NULL && root->right == NULL)
            return true;
        int sum = 0;
        if(root->left != NULL)
        {
            sum+=root->left->data;
        }
        if(root->right != NULL)
        {
            sum += root->right->data;
        }
        return (sum==root->data && isChildrenSum(root->left) && isChildrenSum(root->right));
    }
