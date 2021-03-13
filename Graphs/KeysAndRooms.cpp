class Solution {
public:
    void dfs(int n,vector<bool> &V,vector<vector<int>>& rooms)
    {
        V[n]=1;
        for(int i:rooms[n])
            if(!V[i])
                dfs(i,V,rooms);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> V(n,false);
        dfs(0,V,rooms);
        for(bool i:V)
            if(!i)
                return false;
        return true;
    }
};