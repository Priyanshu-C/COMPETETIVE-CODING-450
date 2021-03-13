class Solution {
public:
    vector<vector<int>> res;
    void dfs(int target,int n,vector<vector<int>>& graph,vector<int> ans)
    {
        if(n==target)
        {
            ans.push_back(n);
            res.push_back(ans);
            return;
        }
        ans.push_back(n);
        for(int i:graph[n])
        {
            dfs(target,i,graph,ans);
        }
        ans.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> ans;
        dfs(graph.size()-1,0,graph,ans);
        return res;
    }
};