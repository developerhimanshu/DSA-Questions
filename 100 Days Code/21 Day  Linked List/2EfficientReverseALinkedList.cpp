/*
=> This solution only takes one traversal
=> This solution doesn't takes any extra spaces
*/

Node *reverseLL(Node *head)
{
   if(head == NULL || head -> next == NULL)
        return head;
    Node *curr, *prev, *nex;
    prev = NULL;
    while(curr != NULL)       
    {
        nex = curr->next;
        curr->next = prev;
        prev  = curr;
        curr = nex;
    }
    return prev;
}
