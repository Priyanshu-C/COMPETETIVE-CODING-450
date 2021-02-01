#include <bits/stdc++.h>
using namespace std;

// TOP-DOWN 

int LongestPalindromicSubsequence(string x,string y,int n,int m)
{

  vector<vector<int>> DP(1001,vector<int> (1001,0));
  
  for(int i=1;i<=n;i++)
  {
     for(int j=1;j<=m;j++)
    {
      if(x[i-1]==y[j-1])
      {
        DP[i][j] = 1 + DP[i-1][j-1];
      }
      else
      {
        DP[i][j] = max(DP[i][j-1],DP[i-1][j]);
      }
    }
  }
  return DP[n][m];
}

int main() {
  string x = "bbbab";
  string y = x;
  reverse(x.begin(),x.end());
  cout<<LongestPalindromicSubsequence(x,y,x.size(),y.size());
}