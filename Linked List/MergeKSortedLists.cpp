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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue <int, vector<int>, greater<int> > pq;
        if(lists.size()==1)
            return lists[0];
        if(lists.size()==0)
            return NULL;
        
        
        for(auto i:lists){
            while(i!=NULL)
            {
                pq.push(i->val);
                i=i->next;
                }
        }
        if(pq.empty())
            return NULL;
        
        ListNode *head=new ListNode(pq.top()) ;
        pq.pop();
        ListNode *temp=head;
        while(!pq.empty())
        {
            ListNode *n=new ListNode(pq.top()) ;
            temp->next=n;
            temp=temp->next;
            pq.pop();
        }
        temp->next=NULL;
        return head;
    }
};