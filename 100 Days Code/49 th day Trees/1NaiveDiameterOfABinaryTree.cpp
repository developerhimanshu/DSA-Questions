int height(Node *root)
{
    if(root==NULL)  
        return 0;
    return max(height(root->left), height(root->right))+1;
}
int diameter(Node *root)
{
    if(root==NULL)return 0;
    int d1 = 1+height(root->left)+height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1, max(d2, d3));
}
