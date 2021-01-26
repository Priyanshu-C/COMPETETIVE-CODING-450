#include <bits/stdc++.h> 
using namespace std; 

#define d(x) cout<<#x<<" "<<x<<endl;

bool isInside(int x, int y, int N) 
{ 
    if (x >= 1 && x <= N && y >= 1 && y <= N) 
        return true; 
    return false; 
} 
  

int minStepToReachTarget(vector<int> knightPos, vector<int> targetPos, int N) 
{ 
    vector<int> X = { 1 , 1 , -1 , -1 , 2 , 2, -2 , -2  };
    vector<int> Y = { 2 ,-2 , 2  ,  -2, 1 , -1, 1 , -1  }; 
    queue<pair<int,int>> Q;
    Q.push({knightPos[0],knightPos[1]});
    vector<vector<bool>> visited(N+1,vector<bool>(N+1,false));

    visited[knightPos[0]][knightPos[1]]=1;
    int count=0;
    while(!Q.empty())
    {
      //cout<<Q.front().first<<" "<<Q.front().second;
      int n = Q.size();
      d(n);
      count++;
      while(n--)
      {
        pair<int,int> pos = Q.front(); 
        Q.pop();
        for(int i=0;i<8;i++)
        {
          int x = pos.first + X[i];
          int y = pos.second + Y[i];
          if(isInside(x,y,N))
          {
            if(!visited[x][y])
            {
            visited[x][y]=1;
            Q.push({x,y});
            if(x==targetPos[0] and y==targetPos[1])
            return count;
            }
          }
        }
      }
    }
    return -1;
} 
  
// Driver code to test above methods 
int main() 
{ 
    int N = 30; 
    vector<int> knightPos = { 1, 1 }; 
    vector<int> targetPos = { 30, 30 }; 
    cout << minStepToReachTarget(knightPos, targetPos, N); 
    return 0; 
} 