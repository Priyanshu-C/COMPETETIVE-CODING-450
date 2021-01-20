// DEQUE Insert the element at front when it is the max or empty or simply check if the rear is smaller than rear, keep poping the back. 

// If the element we are popping at the front of DQ we need to pop it out and check for others.

class Solution {
public:
    
    void debDQ(deque<int> DQ)
    {
        cout<<".........."<<endl;
        while(!DQ.empty())
        {
            cout<<DQ.front()<<" ";
            DQ.pop_front();
        }
        cout<<endl<<".........."<<endl;
    }
    
    vector<int> maxSlidingWindow(vector<int>& ar, int k) {
        deque<int> DQ;
        int n=ar.size();
        for(int i=0;i<k;i++)
        {
            while(!DQ.empty() and DQ.back()<ar[i])
                DQ.pop_back();
            if(DQ.empty())
                DQ.push_front(ar[i]);
            else DQ.push_back(ar[i]);
        }
        
        //debDQ(DQ);
        
        vector<int> RES;
        RES.push_back(DQ.front());
        for(int i=0,j=k;j<n;i++,j++)
        {
            if(ar[i]==DQ.front())
            {
                DQ.pop_front();
            }
            while(!DQ.empty() and ar[j]>DQ.back())
            {
                DQ.pop_back();
            }
            if(DQ.empty())
                DQ.push_front(ar[j]);
            else DQ.push_back(ar[j]);
            RES.push_back(DQ.front());
            //debDQ(DQ);
        }
        return RES;
    }
};