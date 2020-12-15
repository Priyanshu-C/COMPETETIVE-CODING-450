
#include <bits/stdc++.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head==NULL or head->next==NULL)
        return false;
        ListNode *Snext = head;
        ListNode *Fnext = head->next;

        while(Snext!=Fnext)
        {
        if(Fnext==NULL or Fnext->next==NULL)
            return false;
          Snext=Snext->next;
          Fnext=Fnext->next->next;
        }
        return true;
    }
};