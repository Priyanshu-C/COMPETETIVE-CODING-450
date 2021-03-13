class Solution {
public:
    #define d(x) cout<<#x<<" "<<x<<endl;
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> outIn(n);
        for(auto i:edges)
        {
            outIn[i[1]]++;
        }
          
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(outIn[i]==0)
            {
                res.push_back(i);
            }
            if(count == n)
                return res;
        }
        
        return res;
    }
};