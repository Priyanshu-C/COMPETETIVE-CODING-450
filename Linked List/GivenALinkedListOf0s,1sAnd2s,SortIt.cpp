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
    ListNode* sortList(ListNode* head) {
        
        if(!head or !head->next)
            return head;
        
        int A0=0,A1=0,A2=0;
        ListNode *temp = head;
        while(temp)
        {
            switch(temp->val)
            {
                    case 0:{A0++;break;}
                    case 1:{A1++;break;}
                    case 2:{A2++;break;}
            }
            temp=temp->next;
        }
        cout<<A0<<A1<<A2;
        temp = head;
        while(A0--)
        {
            temp->val=0;
            temp=temp->next;
        }
        
        while(A1--)
        {
            temp->val=1;
            temp=temp->next;
        }
        
        while(A2--)
        {
            temp->val=2;
            temp=temp->next;
        }
        return head;
    }
};