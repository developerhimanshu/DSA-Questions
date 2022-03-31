bool search(Node*root, int key)
{
    while(root != NULL)
    {
        if(root->data == key)
            return true;
        else if(root->data >key)
            root=root->left;
        else
            root = root->right;
    }
    return false;
}
