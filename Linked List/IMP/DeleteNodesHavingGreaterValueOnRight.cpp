Node *reverse(Node *&head)
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
Node *compute(Node *head)
{
    head = reverse(head);
    Node *headRef=head;
    int maxTillNow = head->data;
    while(head->next)
    {
        // cout<<maxTillNow<<" for value "<<head->next->data<<endl;
        // cout<<endl;
        if(head->next->data<maxTillNow)
        {
            head->next=head->next->next;
        }
        else
        {
            maxTillNow=head->next->data;
            head=head->next;
        }
        
    }
    return reverse(headRef);
    
    
    
    // if(!head->next)
    // return head;
    
    // if(head->next->data>head->data)
    // head = compute(head->next);
    // else
    // head->next=compute(head->next);
    
    // return head;
}