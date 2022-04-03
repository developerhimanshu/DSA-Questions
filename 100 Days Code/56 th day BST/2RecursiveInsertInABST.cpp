Node *insertion(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    else if (root->data > val)
        root->left = insertion(root->left, val);
    else
        root->right = insertion(root->right, val);
    return root;
}
