/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
       ListNode *prev;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head, int k,int &maxlen) {
        
        if(maxlen==0)
        {
            return head;
        }
      int count =0;   
      ListNode *curr = head;
      ListNode *prev=NULL;
      ListNode *next=NULL;
      while(count<k and curr!=NULL)
      {
        next=curr->next;
        curr->next=prev;
        curr->prev=next;
        prev=curr;
        curr=next;
        count++;
        maxlen--;
      }
      if(next!=NULL)
      {
        head->next= reverseKGroup(next,k);
        head->next->prev= head;
      }
      
      return prev;
    }
        
    ListNode* reverseKGroup(ListNode* head, int k) {
        
      ListNode *temp = head;
        int len=0;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        len = k*(len/k);
     return reverse(head,k,len);
    }
};