//Using 2 pointer we can easily do it

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int start=0,end=0;
        int len=INT_MAX;
        while(end<n)
        {
            sum+=nums[end++];
            while(sum>=s and start<end)
            {   
                len=min(len,end-start);
                sum-=nums[start++];
            }
        }
        if(len==INT_MAX)
            return 0;
        return len;
    }
};