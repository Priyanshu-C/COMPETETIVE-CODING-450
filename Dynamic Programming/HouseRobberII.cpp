class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int E = 0;
        int O = 0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(i%2==0)
            {
                E = max(E+nums[i],O);
            }
            else
            {
                O = max(O+nums[i],E);
            }
        }
        int res = max(E,O);
        E=0;
        O=0;
        for(int i=1;i<n;i++)
        {
            if(i%2==0)
            {
                E = max(E+nums[i],O);
            }
            else
            {
                O = max(O+nums[i],E);
            }
        }
        return max(E,max(O,res));
    }
};