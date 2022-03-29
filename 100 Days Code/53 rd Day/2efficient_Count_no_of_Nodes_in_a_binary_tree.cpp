int countNodes(Node *root)  // 
{
    if(root==NULL)
        return 0;
    int lh=0, rh=0;
    Node *curr = root;
    while(curr!=NULL)
    {
        lh++;
        curr=curr->left;
    }
    curr = root;
    while(curr != NULL)
    {
        rh++;
        curr=curr->right;
    }
    if(lh == rh)
    {
        return pow(2, lh)-1;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}
