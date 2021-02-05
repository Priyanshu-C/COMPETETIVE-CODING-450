class Solution
{
	public:
		int editDistance(string S1,string S2) {

          int n=S1.size();
          int m=S2.size();
          vector<vector<int>> DP(n+1,vector<int>(m+1,0));
          for(int i=0;i<=n;i++)
          DP[i][0]=i;
          for(int j=0;j<=m;j++)
          DP[0][j]=j;
         // debmat(DP);
          for(int i=1;i<=n;i++)
          {
            for(int j=1;j<=m;j++)
            {
              if(S1[i-1]==S2[j-1])
              DP[i][j]=DP[i-1][j-1];
              else
              DP[i][j]=min(DP[i-1][j],min(DP[i][j-1],DP[i-1][j-1]))+1;
            }
            //debmat(DP);
          }
          return DP[n][m];
        }
};