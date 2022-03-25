int diameter = 0;

int height(Node*root)
{
    if(root==NULL)return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);
    diameter = max(diameter, (lh+rh+1));
    return 1+max(lh, rh);
}
