class Solution {
public:
    #define d(x) cout<<#x<<" "<<x<<endl;
    void dfs(vector<vector<char>>& grid,int i,int j)
    {   
        d(i);d(j);
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='x' or grid[i][j]=='0')
        return;
        if(grid[i][j]=='1')
        {   
            grid[i][j]='x';
            dfs(grid,i+1,j);
            dfs(grid,i,j+1);
            dfs(grid,i-1,j);
            dfs(grid,i,j-1);
          
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
    int x=grid.size();
    int y=grid[0].size();
        int c=0;
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(grid[i][j]=='1')
                {
                    c++;
                    dfs(grid,i,j);
                }
            }
        }
        return c;
        
    }
};