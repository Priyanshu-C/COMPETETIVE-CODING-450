#include <bits/stdc++.h> 
using namespace std;

#define d(i,j) cout<<#i<<i<<" "<<#j<<" "<<j<<endl;

void debmat(vector<vector<int>> &ar)
{
  int R=ar.size();
  int C=ar[0].size();
  int i,j;
  cout<<endl<<"////////////"<<endl;
  for(int i=0;i<R;i++)
  {
    for(int j=0;j<C;j++)
    cout<<ar[i][j]<<"  ";
    cout<<endl;
  }
  cout<<endl<<"////////////"<<endl;
}

void solveMazeUtil(vector<vector<int>> &maze,int r,int c,int n,int m,vector<string> &S,string X)
{
//  debmat(maze);
if(r==n-1 and c==m-1 and maze[r][c]==1)
S.push_back(X);
if(r>=n or c>=m or c<0 or r<0 or maze[r][c]==0 or maze[r][c]==-1)
return;
maze[r][c]=-1;
solveMazeUtil(maze,r+1,c,n,m,S,X + "D");
solveMazeUtil(maze,r-1,c,n,m,S,X + "U");
solveMazeUtil(maze,r,c+1,n,m,S,X + "R");
solveMazeUtil(maze,r,c-1,n,m,S,X + "L");
maze[r][c]=1;
return;
}

vector<string> solveMaze(vector<vector<int>> &maze)
{
vector<string> S;
int n= maze.size();
int m = maze[0].size();
solveMazeUtil(maze,0,0,n,m,S,"");
return S;
}
 
// driver program to test above function 
int main() 
{ 
    vector<vector<int>> maze = { { 1, 0, 0, 0 }, { 1, 1, 0, 1 }, { 0, 1, 0, 0 }, { 1, 1, 1, 1 } }; 

    vector<string> S = solveMaze(maze); 
    for(string i:S)
    cout<<i<<" ";
    return 0; 
} 