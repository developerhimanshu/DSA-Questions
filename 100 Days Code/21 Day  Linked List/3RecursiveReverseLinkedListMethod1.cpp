Node *reverseLL(Node *head)
{
   if(head == NULL || head -> next == NULL)
        return head;
    Node *restHead = reverseLL(head->next);
    Node *restTail = head->next;
    restTail->next = head;
    head->next = NULL;
    return restHead;
}
