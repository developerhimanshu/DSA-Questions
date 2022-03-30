void serialize(Node *root, vector<int>&v)
{
    if(root==NULL)
    {
        v.push_back(-1);
        return ;
    }
    v.push_back(root->data);
    serialize(root->left, v);
    serialize(root->right, v);
}

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);    
    }
} 

// Deserialze :- Covert an array to a binary tree
Node* deserialize(vector<int>&v, int &idx)
{
    if(idx == v.size())return NULL;
    int val = v[idx];
    idx ++;
    if(val==-1)
        return NULL;
    Node *root = new Node (val);
    root->left = deserialize(v, idx);
    root->right = deserialize(v, idx);
    return root;
}
