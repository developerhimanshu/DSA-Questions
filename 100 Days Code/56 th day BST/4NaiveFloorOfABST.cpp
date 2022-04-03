/* Method 1: By returning the integer
=> This will take O(h) time.
*/

int floorOfABST(Node *root, int key)
{
    int result = 0;
    while(root!=NULL)
    {
        if(root->data < key)
        {
            result=max(result, root->data);
        }
        if(root->data < key)
        {
            root = root->right;
        }
        else if(root->data >key)
            root = root->left;
    }
    return result;
}
