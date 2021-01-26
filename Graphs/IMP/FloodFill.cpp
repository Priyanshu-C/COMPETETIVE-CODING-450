// Flood fill is easy by dfs simple, keep flodding for the required values; 

class Solution {
public:
    
    #define d(x) cout<<#x<<" "<<x<<endl;
    #define d2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
    bool validXY(int &x,int &y,int &R,int &C)
    {
        if(x>=0 and y>=0 and x<R and y<C)
            return true;
        return false;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int R = image.size();
        int C = image[0].size();
        
        vector<int> X = {0,0,-1,1};
        vector<int> Y = {-1,1,0,0};
        
        vector<vector<bool>> visited(R,vector<bool>(C,false));
        queue<pair<int,int>> Q;
        Q.push({sr,sc});
        int prevColor = image[sr][sc];
        visited[sr][sc]=1;
        image[sr][sc]=newColor;
        while(!Q.empty())
        {
            int n = Q.size();
            while(n--)
            {
                pair<int,int> pos = Q.front();
                Q.pop();
                for(int i=0;i<4;i++)
                {
                    int x = pos.first + X[i];
                    int y = pos.second + Y[i];
                    
                    if(validXY(x,y,R,C))
                    if(!visited[x][y] and image[x][y]==prevColor)
                    { 
                        image[x][y]=newColor;
                        visited[x][y]=1;
                        Q.push({x,y});
                    }
                }
            }
        }
        return image;
    }
};