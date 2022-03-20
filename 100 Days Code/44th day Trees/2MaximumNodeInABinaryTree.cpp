class solution{
    public:
    int getmax(TreeNode *node)
    {
        if(node == NULL)
            return INT_MIN;
        return max(node->data, max(getmax(node->left), getmax(node->right)));
    }
};
