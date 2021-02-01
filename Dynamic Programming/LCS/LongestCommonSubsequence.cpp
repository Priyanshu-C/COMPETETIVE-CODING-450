#include <bits/stdc++.h>
using namespace std;


//RECURSIVE

int LCS(string x,string y,int n,int m)
{
  if(n==0 or m==0)
  return 0;
  if(x[n-1]==y[m-1])
  return LCS(x.substr(0,n-1),y.substr(0,m-1),n-1,m-1)+1;
  else
  {
    return max(LCS(x.substr(0,n-1),y,n-1,m) ,LCS(x,y.substr(0,m-1),n,m-1));
  }
}

#include <bits/stdc++.h>
using namespace std;


//RECURSIVE AND MEMOIZED

vector<vector<int>> DP(1001,vector<int> (1001,-1));
int LCSM(string x,string y,int n,int m)
{
  if(n==0 or m==0)
  return 0;

  if(DP[n][m]!=-1)
  return DP[n][m];

  if(x[n-1]==y[m-1])
  return DP[n][m]=LCS(x.substr(0,n-1),y.substr(0,m-1),n-1,m-1)+1;
  else
  {
    return DP[n][m] = max(LCS(x.substr(0,n-1),y,n-1,m) ,LCS(x,y.substr(0,m-1),n,m-1));
  }
}

// TOP-DOWN 


int LCSTD(string x,string y,int n,int m)
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
  string x = "abcdef";
  string y = "abdef";
  cout<<LCSTD(x,y,x.size(),y.size());
}