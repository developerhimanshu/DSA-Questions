class solution{
    public:
    int preIndex=0;
    Node *cTree(int in[], int pre[], int is, int ie)
    {
        if(is>ie)
            return NULL;
        Node *root = new Node(pre[preIndex++]);

        int InIndex;
        for(int i=is; i<=ie; i++)
        {
            if(in[i]==root->data)
            {
                InIndex = i;
                break;
            }
        }

        root->left = cTree(in, pre, is, InIndex-1);
        root->right = cTree(in, pre, InIndex+1, ie);
        return root;
    }

    void inorder(Node *root)
    {
        if(root == NULL)
            return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};
