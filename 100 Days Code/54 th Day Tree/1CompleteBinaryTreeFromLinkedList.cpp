void convert(Node *head, TreeNode *&root) {
    // Your code here
    if(head==NULL)
    {
        root==NULL;
        return;
    }
    queue<TreeNode*>q;
    root = new TreeNode(head->data);
    q.push(root);
    head = head->next;
    while(head !=NULL)
    {
        TreeNode* parent = q.front();
        q.pop();
        
        TreeNode *left_child = NULL, *right_child=NULL;
        left_child = new TreeNode(head->data);
        q.push(left_child);
        head = head ->next;
        if(head)
        {
            right_child = new TreeNode(head->data);
            q.push(right_child);
            head = head->next;
        }
        parent->left = left_child;
        parent->right = right_child;
    }
}
