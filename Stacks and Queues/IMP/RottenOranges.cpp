class Solution {
private:
    vector<int> X = {0,1,0,-1};
    vector<int> Y = {1,0,-1,0};  
public:
    
    bool validPostion(int &x,int &y,int n,int m)
    {
        if(x>=n or x<0)
            return false;
        if(y>=m or y<0)
            return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        stack<pair<int,int>> oldRotten;
        stack<pair<int,int>> newRotten;
        int n=grid.size();
        int m=grid[0].size();
        int n0=0;
        
        if(n==1 and m==1)
        {
            if(grid[0][0]==0)
                return 0;
            else if(grid[0][0]==1)
                return -1;
            else
                return 0;
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    oldRotten.push({i,j});
                if(grid[i][j]==0)
                    n0++;
            }
        
        if(n0==m*n)
            return 0;
        
        int size=oldRotten.size();
        int totalRotten=size    ;
        int count=0;
        while(size!=0)
        {
        while(!oldRotten.empty())
        {
           
            pair<int,int> pos = oldRotten.top();
            oldRotten.pop();
            for(int i=0;i<4;i++)
            {
                int x =  pos.first+X[i];
                int y =  pos.second+Y[i];
                
                if(validPostion(x,y,n,m))
                {    
                    if(grid[x][y]==1)
                    {
                        
                        grid[x][y]=2;
                        newRotten.push({x,y});
                        totalRotten++;
                    }
                }
            }
        }
            size=newRotten.size();
            swap(newRotten,oldRotten);
            count++;
        }
        if(n*m-(n0+totalRotten)==0)
            return count-1;
        return -1;
    }
};