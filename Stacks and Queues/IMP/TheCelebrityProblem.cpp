#include <bits/stdc++.h> 
using namespace std; 
  
#define N 8 
  

bool MATRIX[N][N] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}}; 
  
bool knows(int a, int b) 
{ 
    return MATRIX[a][b]; 
} 
  
 
int findCelebrity(int n) 
{ 
   stack<int> S;
   for(int i=0;i<n;i++)
   {
     S.push(i);
   }

    while(S.size()>1)
    {
      int A = S.top(); S.pop();
      int B = S.top(); S.pop();
      if(knows(A,B))
      {
        S.push(B);
      }
      else
      { 
        S.push(A);
      }
    }
    int C=S.top();
    for(int i=0;i<n;i++)
    {
      if(C!=i)
      if(knows(C,i) or !knows(i,C))
      return -1;
    }
  return C;
} 
  
// Driver code 
int main() 
{ 
    int n = 4; 
    int id = findCelebrity(n); 
    id == -1 ? cout << "No celebrity" : 
               cout << "Celebrity ID " << id; 
    return 0; 
} 