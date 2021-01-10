//Simple backtracking

class Solution {
public:
    void uniquePathsUtil(int x,int y,vector<vector<int>> &M,int &res,int &m,int &n)
    {
        if(x<0 or y<0 or x>=m or y>=n or M[x][y]==1)
            return;
        if(x==m-1 and y==n-1)
            res++;
        
        M[x][y]=1;
        uniquePathsUtil(x+1,y,M,res,m,n);
        uniquePathsUtil(x,y+1,M,res,m,n);
        M[x][y]=-1;
        return;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> M(m,vector<int>(n,-1));
        int res=0;
        uniquePathsUtil(0,0,M,res,m,n);
        return res;
        
    }
};

//DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=1;
                else
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[m-1][n-1];
    }
};