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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len=0;
        ListNode *temp = root;
        vector<ListNode*> ar(k);
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        temp = root;
        if(len<k)
        {
            for(int i=0;i<k;i++)
            {
                if(temp)
                {
                    ar[i]=new ListNode(temp->val);
                    ar[i]->next=NULL;
                    temp=temp->next;
                }
                else
                ar[i]=NULL;
            }
        }
        else
        {
            int con=len/k;
            int rem=len%k;
            int l=1;
            for(int i=0;i<k;i++)
            {
                
                if(rem>0)
                {
                    rem--;
                    l=1;
                }
                else
                    l=0;
                cout<<"con "<<con<<" len "<<len<<" k "<<k<<" rem "<<rem;
                ListNode *t = new ListNode(1);
                ListNode *start=t;
                
                for(int j=0;j<con+l;j++)
                {   
                    if(temp)
                    {
                        t->next=temp;
                        t=temp;
                        temp=temp->next;
                    }
                }
                t->next=NULL;
                ar[i]=start->next;
            }
        }
        return ar;
    }
};