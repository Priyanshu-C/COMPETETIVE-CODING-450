class Solution {
public:
    #define d(x) cout<<#x<<" "<<x<<endl;
    int findBallUtil(vector<vector<int>>& grid,int row,int col)
    {
        if(row==grid.size())
            return col;
        if(col==0 and grid[row][col]==-1)
            return -1;
        if(col==grid[0].size()-1 and grid[row][col]==1)
            return -1;
        if(grid[row][col]==1 and col+1<grid[0].size() and grid[row][col+1]==-1)
            return -1;
        if(grid[row][col]==-1 and  grid[row][col-1]==1)
            return -1;
        if(grid[row][col]==-1 and col+1<grid[0].size() and grid[row][col+1]==-1)
            return findBallUtil(grid,row+1,col-1);
        if(grid[row][col]==1 and col+1<grid[0].size() and grid[row][col+1]==1)
            return findBallUtil(grid,row+1,col+1);
        if(grid[row][col]==1 and  grid[row][col-1]==1)
            return findBallUtil(grid,row+1,col+1);
        if(grid[row][col]==-1 and grid[row][col-1]==-1)
            return findBallUtil(grid,row+1,col-1);
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> RES;
        int n = grid[0].size();
        for(int i=0;i<n;i++)
        {
            d(i);
            RES.push_back(findBallUtil(grid,0,i));
        }
        return RES;
    }
};


// [[1,1,1,-1,-1],
//  [1,1,1,-1,-1],
//  [-1,-1,-1,1,1],
//  [1,1,1,1,-1],
//  [-1,-1,-1,-1,-1]]