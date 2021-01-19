//We need to do a bfs on the matrtix with the visited cells

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        queue<pair<int,int>> Q;
        vector<vector<bool>> visit(n,vector<bool>(m,false));
        vector<vector<int>> RES(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(matrix[i][j]==0)
                {
                    visit[i][j]=true;
                    Q.push({i,j});
                    RES[i][j]=0;
                }
        
        vector<int> X = {0 , 0 , 1 ,-1};
        vector<int> Y = {1 , -1, 0 , 0};
        
        
        while(!Q.empty())
        {
            for(int i=0;i<4;i++)
            {
                int x = Q.front().first+X[i];
                int y = Q.front().second+Y[i];
                if(x<n and y<m and x>=0 and y>=0 and visit[x][y]==false)
                {
                    RES[x][y]= RES[x-X[i]][y-Y[i]]+1;
                    visit[x][y]=true;
                    Q.push({x,y});
                }
                
            }
            Q.pop();
            
        }
        return RES;
    }
};