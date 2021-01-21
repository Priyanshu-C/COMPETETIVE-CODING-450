// Keep adding k lists [0] value in heap with keeping high 
// Now basically top of heap will be the lowerst values and inserting number will be either be a high or not 
// Maintain the range and give back the ranghe 


class Solution {
public:
    #define ppi pair<int,int>;
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> pos(k,0);
        priority_queue<ppi,vector<ppi>,greater<ppi>> PQ;
        int high = INT_MIN;
        
        for(int i=0;i<k;i++)
        {
            PQ.push({nums[i][0],i});
            high = max(high,nums[i][0]);
        }
        
        pair<int,int> rangeValues = {PQ.top().first,high};
        int range = rangeValues.second - rangeValues.first;
        
        
        while(1)
        {
            pair<int,int> top = PQ.top();
            PQ.pop();
            
            int arrayNumber = top.second;
            pos[arrayNumber]++;
            int nextIndex = pos[arrayNumber];
            
            if(nextIndex == nums[arrayNumber].size())
            {
                vector<int> res;
                res.push_back(rangeValues.first);
                res.push_back(rangeValues.second);
                return res;
            }
            high = max(high,nums[arrayNumber][pos[arrayNumber]]);
            
            PQ.push({nums[arrayNumber][pos[arrayNumber]],arrayNumber});
            
            pair<int,int> rangeInit = {PQ.top().first,high};
            
            if(range > rangeInit.second - rangeInit.first )
            {
                range = rangeInit.second - rangeInit.first;
                rangeValues = rangeInit;
            }
            
        }
        vector<int> res;
        res.push_back(rangeValues.first);
        res.push_back(rangeValues.second);
        return res;
    }
};