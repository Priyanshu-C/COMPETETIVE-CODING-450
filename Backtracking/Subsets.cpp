class Solution {
public:

    void subsetsUtil(vector<int>& nums,vector<vector<int>> &ar,vector<int> test,int i)
    {
        if(i==nums.size())
            {
            ar.push_back(test);
            return;
            }
        
        test.push_back(nums[i]);
        subsetsUtil(nums,ar,test,i+1);
        test.pop_back();
        subsetsUtil(nums,ar,test,i+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> T;
        vector<vector<int>> ANS;
        subsetsUtil(nums,ANS,T,0);
        return ANS;
    
    }
};