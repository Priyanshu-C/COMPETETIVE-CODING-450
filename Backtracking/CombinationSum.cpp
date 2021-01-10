class Solution {
public:
    #define d(x) cout<<#x<<" "<<x<<endl;
    
    void combinationSumUtil(vector<int>& candidates, vector<vector<int>> &RES,int len,int target,vector<int>& ar,int start)
    {
        //d(target);
        if(target<0)
            return;
        if(target==0)
        {
            RES.push_back(ar);
            return;
        }
        for(int i=start;i<len and target >= candidates[i];i++)
        {
            ar.push_back(candidates[i]);
            combinationSumUtil(candidates,RES, len,target-candidates[i],ar,i);
            ar.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     sort(candidates.begin(),candidates.end());
     int len = candidates.size();   
     vector<vector<int>> RES;
     vector<int> ar;
     combinationSumUtil(candidates,RES, len,target,ar,0);
        return RES;
    }
};