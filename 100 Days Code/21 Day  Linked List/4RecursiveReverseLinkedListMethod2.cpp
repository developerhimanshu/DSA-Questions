Node *reverseLL(Node *curr, Node *prev)//We passed curr as head and perv as NULL
{
    if(curr == NULL)
    {
        return prev;
    }
    Node *nxt = curr->next;
    curr->next = prev;
    return  reverseLL(nxt, curr);
}
