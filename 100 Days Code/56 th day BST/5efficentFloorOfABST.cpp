Node *floorOfABST(Node *root, int x)
{
    Node *result = NULL;
    while(root != NULL)
    {
        if(root->data == x)
            return root;
        else if(root->data > x)
            root = root->left;
        else{
            result = root;
            root = root->right;
        }
    }
    return result;
}
