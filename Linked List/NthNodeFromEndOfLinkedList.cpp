/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n)
{
    if(!head)
    return -1;
    // int len=0;
    Node *temp = head;
    while(temp and n--)
    {
       // cout<<n;
        temp=temp->next;
    }
    
    Node *temp2 = head;
    if(!temp and n==0)
    return temp2->data;
    //cout<<len<<" ";
    if(temp)
    {
        while(temp)
        {
            temp=temp->next;
            temp2=temp2->next;
        }
        return temp2->data;
    }
    else
    return -1;
}