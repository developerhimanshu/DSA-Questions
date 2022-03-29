int countNodes(Node *root)
{
    if(root == NULL)
        return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
