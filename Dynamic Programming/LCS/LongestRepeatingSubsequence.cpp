#include <bits/stdc++.h>
using namespace std;

// TOP-DOWN 


int LongestRepeatingSubsequence(string x,int n)
{
  string y = x;
  int m = n;
  vector<vector<int>> DP(n+1,vector<int> (m+1,0));
  
  for(int i=1;i<=n;i++)
  {
     for(int j=1;j<=m;j++)
    {
      if(x[i-1]==y[j-1] and i!=j)
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
  string x = "abcdef";
  string y = "abdef";
  cout<<LongestRepeatingSubsequence(x,x.size());
}