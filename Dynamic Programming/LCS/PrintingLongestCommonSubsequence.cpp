#include <bits/stdc++.h>
using namespace std;


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

// TOP-DOWN 

string LCSTD(string x,string y,int n,int m)
{

  vector<vector<int>> DP(n+1,vector<int> (m+1,0));
  
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

  debmat(DP);

  int i=n;
  int j=m;
  string ans = "";
  while(i!=0 and j!=0)
  {
    if(x[i-1]==y[j-1])
    {
      ans =  x[i-1] +  ans;
      i--;
      j--;
    }
    else
    j--;
   // cout<<i<<" "<<j<<endl;
  }
  return ans;
}

int main() {
  string x = "AGGTAB";
  string y = "GXTXAYB";
  cout<<LCSTD(x,y,x.size(),y.size());
}