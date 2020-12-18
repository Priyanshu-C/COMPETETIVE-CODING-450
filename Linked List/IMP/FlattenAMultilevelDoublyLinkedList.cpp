/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if(!head or (!head->next and !head->child) )
            return head;
        
        Node *tempnext = head->next;
        
        if(head->child)
        {
            head->next = flatten(head->child);
            head->next->prev=head;
            
        }
        if(tempnext and !head->child)
        {
            head->next=flatten(tempnext);
            head->next->prev=head;
        }
        if(tempnext and head->child)
        {
            Node *temp=head->child;
            while(temp->next)
                    temp=temp->next;
            temp->next=flatten(tempnext);
            temp->next->prev=temp;
        }
            head->child=NULL;
            return head;
        
    }
};