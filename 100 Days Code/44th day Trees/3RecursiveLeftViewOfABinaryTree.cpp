class solution{
    public:
    int maxlevel=0;
    void printleft(TreeNode* root, int level){
    if(root == NULL)
        return;
    if(maxlevel<level)
    {
        cout<<root->data<<" ";
        maxlevel = level;
    }
    printleft(root->left, level+1);
    printleft(root->right, level+1);
    }
    void leftviewprint(TreeNode *root)
    {
        printleft(root, 1);
    }
};
