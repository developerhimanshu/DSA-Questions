  bool findPath(Node *root, vector<Node *>&v, int x)
    {
        if(root==NULL)
            return false;
        v.push_back(root);
        if(root->data == x)
            return true;
        if(findPath(root->left, v, x)||findPath(root->right, v, x))
            return true;
        
        v.pop_back();
        return false;
    }
    Node *lca(Node *root, int n1, int n2)
    {
        vector<Node*>path1, path2;

        if(findPath(root, path1, n1)==false || findPath(root, path2, n2)==false)
            return NULL;
        for(int i=0; i<path1.size()-1&&i<path2.size()-1; i++)
        {
            if(path1[i+1]!=path2[i+1])
                return path1[i];
        }
        return NULL;
    }
