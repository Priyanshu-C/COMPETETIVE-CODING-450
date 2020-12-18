
Node* reverseDLL(Node * head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        curr->prev=next;
        prev=curr;
        curr=next;
    }
    return prev;
    //Your code here
}
