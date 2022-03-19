void levelOrderTraversal(TreeNode *root)
    {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL); // We are pushing NULL because we have to print the new line in it
        while(q.size()>1)
        {
            TreeNode *curr = q.front();
            q.pop();
            if(curr == NULL)
            {
                cout<<"\n";
                q.push(NULL);   
                continue;
            }
            cout<<curr->data<<" ";
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
