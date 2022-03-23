 void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
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
        inorder(root->right);
    }

    TreeNode *bToDLL(TreeNode *root)
    {
        inorder(root);
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
