/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//https://www.youtube.com/watch?v=xbpUHSKoALg
//Watch to claarify 
// basically create a copy of nodes in between them, and use them

void debNode(Node *temp)
{   cout<<"///////////////////"<<endl;
    while(temp)
    {   
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl<<"///////////////////"<<endl;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp = head;
        Node *next;
        Node *copy;
        Node *copyI;
        
        while(temp)
        {
            next=temp->next;
            Node *LOL = new Node(temp->val);
            temp->next=LOL;
            LOL->next=next;
            
            temp=next;
        }
        debNode(head);
        
        temp=head;
        while(temp)
        {
            if(temp->random)
            temp->next->random = temp->random->next;
            temp=temp->next->next;
        }
        
        temp=head;
        Node *Phead = new Node(0);
        copyI = Phead;
        
        while(temp)
        {
            next=temp->next->next;
            copy = temp->next;
            copyI->next = copy;
            copyI = copy;
            
            temp->next= next;
            temp = next;
            
        }
        return Phead->next;
        
    }
};