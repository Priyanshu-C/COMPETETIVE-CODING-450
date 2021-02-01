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

int LongestIncreasingSubsequence(vector<int> &x,int n)
{

  vector<int> DP(n+1,1);
  int maxn=INT_MIN;  
  for(int i=1;i<=n;i++)
  {
    int j=0;
     while(j<i)
     {
      if(x[j]<x[i] and DP[j]>=DP[i])
      {
        DP[i]=DP[j]+1;
        maxn=max(maxn,DP[i]);
      }
      j++;
     }
  }

  return maxn;
}

int main() {
  vector<int> x = {10,9,2,5,3,7,101,18};
  cout<<LongestIncreasingSubsequence(x,x.size());
}