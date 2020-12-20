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

//Basically create 2 nodes each with alternate nodes and then finally join them to get the required list

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next)
            return head;
        
        ListNode *oddHead=head;
        ListNode *evenHead=head->next;
        ListNode *odd=head;
        ListNode *even=head->next;
        
        while(even and even->next)
        {
            odd->next=odd->next->next;
            even->next=even->next->next;
            even=even->next;
            odd=odd->next;
        }
        odd->next=evenHead;
        return head;
    }
};