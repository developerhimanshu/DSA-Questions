Node * RevInGroup(Node *head, int k)
{
    Node *curr = head, *prevfirst= NULL;
    bool firstPass = true;

    while(curr != NULL)
    {
        Node *first = curr, *prev = NULL;
        int count = 0;
        while(curr != NULL && count <k)
        {
            Node *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        if(firstPass){head = prev; firstPass = false;}
        else{prevfirst->next = prev;}
        prevfirst = first;
    }
    return head;
}
