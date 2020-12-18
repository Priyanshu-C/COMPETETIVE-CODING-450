/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head or !head->next)
            return head;
        
        ListNode* temp = head;
        int count=0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        
        
        int ks;
        if(count<k)
         ks = count - k % count  ;
        else
         ks=count-k;
        
        cout<<"count "<<count<<endl;
        cout<<"ks "<<ks<<endl;
        
        temp = head;
        while(temp->next)
            temp=temp->next;
        
        
        temp->next = head;
        
        
        
        while(ks--)
        {
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        
        return head;
    }
};