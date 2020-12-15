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
    ListNode *getIntersection(ListNode *headA, ListNode *headB) {
      if(!headA or !headB)
      return NULL;
      
      if(headA->val < headB->val)
      return getIntersection(headA->next,headB);

      
      if(headA->val > headB->val)
      return getIntersection(headA->next,headB);

      ListNode *temp = new ListNode(headA->val);
      temp->next = getIntersection(headA->next,headB->next);
      return temp;
    }
};