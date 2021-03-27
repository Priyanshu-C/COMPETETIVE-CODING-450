class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        int n = T.size();
        vector<int> res(n,0);
        if(n==1)
            return res;
        stack<pair<int,int>> S;
        S.push({T[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {
            while(!S.empty() and S.top().first<=T[i])
                S.pop();
            if(S.empty())
            {
                res[i]=0;
            }
            else
            {
                res[i] = S.top().second - i;
            }
              S.push({T[i],i});
        }
        return res;
        
    }
};