#include<bits/stdc++.h> 
using namespace std; 
  
const int MAX = 100; 


#define fo(i,n) for(int i=0;i<n;i++)
void debmat(vector<vector<int>> &ar)
{
  int R=ar.size();
  int C=ar[0].size();
  int i,row;
  cout<<endl<<"////////////"<<endl;
  fo(i,R)
  {
    fo(row,C)
    cout<<ar[i][row]<<"  ";
    cout<<endl;
  }
  cout<<endl<<"////////////"<<endl;
}

bool checkXY(int x,int y,int &n,int &m)
{
  if(x<0 or x>=m)
  return false;
  if(y<0 or y>=n)
  return false;
  return true;
}

int getMaxGold(int gold[][MAX], int m, int n) 
{
  vector<int> Y = {-1,0,1};
  vector<vector<int>> DP(m,vector<int>(n,0));
  for(int i=0;i<m;i++)
  {
    DP[i][n-1]=gold[i][n-1];
  }
    //debmat(DP);
  for(int col=m-2;col>=0;col--)
  {
    for(int row=0;row<n;row++)
    {
      for(int k=0;k<3;k++)
      {
        int y = row + Y[k];
        if(checkXY(y, col+1, n, m))
        {
          DP[row][col] = max(DP[row][col],gold[y][col+1]);
        }
      }
      DP[row][col] = DP[row][col] + gold[row][col];
      gold[row][col]=DP[row][col];
    }
  }
  //debmat(DP);
  int res = INT_MIN;
  for(int i=0;i<n;i++)
  {
    res = max(res,DP[i][0]);
  }
  return res;

}
  
// Driver Code 
int main() 
{ 
    int gold[MAX][MAX]= 
    { {1, 3, 1, 5}, 
        {2, 2, 4, 1}, 
        {5, 0, 2, 3}, 
        {0, 6, 1, 2} 
    }; 
    int m = 4, n = 4; 
    cout << getMaxGold(gold, m, n); 
    return 0; 
} 