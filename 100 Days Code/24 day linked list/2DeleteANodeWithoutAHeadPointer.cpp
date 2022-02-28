Node * delNode(Node *ptr)
{
  Node *temp =ptr->next;
  ptr->data = temp->data;
  ptr->next = temp->next;
  delete(temp);
}
