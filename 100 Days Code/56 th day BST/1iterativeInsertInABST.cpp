Node *insertion(Node *root, int val)
{
    Node *temp = new Node(val);
    Node *parent = NULL;
    Node *curr = root;
    while(curr != NULL)
    {
        parent = curr;
        if(curr->data > val)
            curr = curr->left;
        else if(curr->data<val)
            curr = curr->right;
        else
            return root;
    }
    if(parent == NULL)
        return temp;
    if(parent->data >val)
    {
        parent ->left = temp;
    }
    else
        parent->right = temp;
    return root;
}
