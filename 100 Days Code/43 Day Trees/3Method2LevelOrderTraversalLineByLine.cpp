void levelOrderTraversal(TreeNode *root)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                cout<<curr->data<<" ";
                if(curr->left != NULL)q.push(curr->left);
                if(curr->right != NULL)q.push(curr->right);
            }
               cout<<"\n";
        }
    }
