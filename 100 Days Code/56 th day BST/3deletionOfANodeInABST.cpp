Node *inorderSuccessor(Node *root)
{
    root = root->right;
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
        return root;
    if (root->data > val)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = inorderSuccessor( root);
            root->data = temp ->data;
            root->right = deleteNode(root->right, temp->data);  // Because we will delete the inorder successor and it all be in the right.
        }
    }
    return root;
}
