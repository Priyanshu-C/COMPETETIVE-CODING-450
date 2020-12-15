#include <bits/stdc++.h>
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode next) : val(x), next(next) {}
};

class Solution {
public:

    void reverseIter(ListNode* &start,int k)
    {
      ListNode *curr = start;
      ListNode *next = NULL;
      ListNode *prev = NULL;

      while(k--)
      {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
      }
      start=curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

      int len=0;
      ListNode *temp = head;
      while(temp!=NULL and temp->next!=NULL)
      {
        temp=temp->next;
        len++;
      }
      reverseIter(head,len);
      return head;



    }
};