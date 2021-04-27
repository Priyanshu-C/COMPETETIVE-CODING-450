class Solution {
public:
    bool searchQ(int x,int y,vector<vector<int>>& queens)
    {
        for(int i=0;i<queens.size();i++)
        {
            if(x==queens[i][0] and y==queens[i][1])
                return true;
        }
        return false;
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int x = king[0];
        int y = king[1];   
        vector<vector<int>> res;
        for(int i=x;i>=0;i--)
        {
            if(searchQ(i,y,queens))
            {
                res.push_back({i,y});
                break;
            }
        }
        for(int i=x;i<8;i++)
        {
            if(searchQ(i,y,queens))
            {
                res.push_back({i,y});
                break;
            }
        }
         for(int i=y;i<8;i++)
        {
            if(searchQ(x,i,queens))
            {
                res.push_back({x,i});
                break;
            }
        }
         for(int i=y;i>=0;i--)
        {
            if(searchQ(x,i,queens))
            {
                res.push_back({x,i});
                break;
            }
        }
        //digonal
        for(int i=x,j=y;i<8 and j<8;i++,j++)
        {
            if(searchQ(i,j,queens))
            {
                res.push_back({i,j});
                break;
            }
        }
         for(int i=x,j=y;i<8 and j>=0;i++,j--)
        {
            if(searchQ(i,j,queens))
            {
                res.push_back({i,j});
                break;
            }
        }
         for(int i=x,j=y;i>=0 and j>=0;i--,j--)
        {
            if(searchQ(i,j,queens))
            {
                res.push_back({i,j});
                break;
            }
        }
         for(int i=x,j=y;i>=0 and j<8;i--,j++)
        {
            if(searchQ(i,j,queens))
            {
                res.push_back({i,j});
                break;
            }
        }
        return res;
    }
};