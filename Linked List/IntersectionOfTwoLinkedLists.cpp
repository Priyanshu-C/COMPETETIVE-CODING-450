/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int len1=0;
        int len2=0;
        ListNode *temp=headA;
        while(temp)
        {
          temp=temp->next;
          len1++;
        }
        temp=headB;
        while(temp)
        {
          temp=temp->next;
          len2++;
        }
        if(len1>len2)
        {
          int c=len1-len2;
          while(c--)
          {
            headA=headA->next;
          }
        }
       else
        {
          int c=len2-len1;
          while(c--)
          {
            headB=headB->next;
          }
        }
        while(headA!=headB)
        {
          headA=headA->next;
          headB=headB->next;
        }
        return headA;
    }
};