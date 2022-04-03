int findCeil(struct Node* root, int input) {
    int result =-1;
    
    while(root != NULL)
    {
        if(root ->data == input)
        {
            return root -> data;
        }
        else if(root -> data > input)
        {
            result = root->data;
            root = root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return result;
}
