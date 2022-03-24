void printSpiral(Node *root)
{
    if (root == NULL) 
        return;  
    queue<Node *>q;
    stack<int>s;
    bool reverse = false;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if(reverse)
            {
                cout<<curr->data<<" ";
            }
            else
            {
                s.push(curr->data);
            }
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
        if(!reverse)
        {
            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        reverse = !reverse;
    }

}  
