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
    ListNode* reversed(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev = curr;
            curr=next;   
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode *fast = head;
        ListNode *slow = head;
        int len=1;
        while(fast and fast->next)
        {
            
            slow=slow->next;
            fast=fast->next->next;
        }

        slow = reversed(slow);
        fast = head;
        
        while(fast and slow)
        {
            if(fast->val!=slow->val)
                return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
        
            
    
    }
};