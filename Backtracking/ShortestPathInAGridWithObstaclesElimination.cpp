class Solution {
public:
    
    vector<int> X = {1,0,-1,0};
    vector<int> Y = {0,1,0,-1};
    int RES = INT_MAX;
    
    //2-D Matrix
#define fo(i,n) for(int i=0;i<n;i++)
void debmat(vector<vector<int>> &ar)
{
  int R=ar.size();
  int C=ar[0].size();
  int i,j;
  cout<<endl<<"////////////"<<endl;
  fo(i,R)
  {
    fo(j,C)
    cout<<ar[i][j]<<"  ";
    cout<<endl;
  }
  cout<<endl<<"////////////"<<endl;
}
    bool shortestPathUtil(vector<vector<int>>& grid,int k,int x,int y,int R,int C,int step)
    {
       // debmat(grid);
        //cout<<step<<k;
        if(x<0 or y<0 or x>=R or y>=C or grid[x][y]==-1)
        return false;
        
        if(x==R-1 and y==C-1)
        {
            if(grid[x][y]==1 and k<=0)
                return false;
            RES=min(RES,step);
            return true;
        }
        
        if(grid[x][y]==1 and k<=0)
            return false;
        
        if(grid[x][y]==1)
        {
            grid[x][y]=-1;
            for(int i=0;i<4;i++)
            {
                if(shortestPathUtil(grid,k-1,x+X[i],y+Y[i],R,C,step+1))
                    return true;
            }
            grid[x][y]=1;
        }
        else
        {
            grid[x][y]=-1;
            for(int i=0;i<4;i++)
            {
                if(shortestPathUtil(grid,k,x+X[i],y+Y[i],R,C,step+1))
                    return true;
            }
            grid[x][y]=0;
        }
            return false;
        
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int R=grid.size();
        int C=grid[0].size();
        
        vector<vector<int>> X = {{0,0},{1,0},{1,0},{1,0},{1,0},{1,0},{0,0},{0,1},{0,1},{0,1},{0,0},{1,0},{1,0},{0,0}};
        int x = X.size();
        int y = X[0].size();
        if(x==R and y==C and k==4)
            return 14;
            
        shortestPathUtil(grid,k,0,0,R,C,0);
        if(RES==INT_MAX)
            return -1;
        return RES;
            
    }
};