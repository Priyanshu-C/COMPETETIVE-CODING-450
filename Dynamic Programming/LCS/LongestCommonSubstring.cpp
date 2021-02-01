#include <bits/stdc++.h>
using namespace std;

// TOP-DOWN 

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


int LCSubstring(string x,string y,int n,int m)
{

  vector<vector<int>> DP(n+1,vector<int> (m+1,0));
  int mmax = 0;

  for(int i=1;i<=n;i++)
  {
     for(int j=1;j<=m;j++)
    {
      if(x[i-1]==y[j-1])
      {
        DP[i][j] = 1 + DP[i-1][j-1];
        mmax = max(DP[i][j],mmax);
      }
      else
      {

        DP[i][j] = 0;
      }
    }
  }
  return mmax;
}

int main() {
  string x = "abdcefgg";
  string y = "abfgefgg";
  cout<<LCSubstring(x,y,x.size(),y.size());
}