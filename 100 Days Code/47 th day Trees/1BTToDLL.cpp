TreeNode *BinaryToDLL(TreeNode *root)
{
    if (root == NULL)
        return root;
    static TreeNode *prev = NULL;
    TreeNode *head = BinaryToDLL(root->left);
    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BinaryToDLL(root->right);
    return head;
}

void printlist(TreeNode *head)
{
    TreeNode *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}
