
#include <bits/stdc++.h> 
using namespace std; 

int minimumCostOfBreaking(vector<int> &X, vector<int> &Y, int m, int n) 
{ 
  int RES=0;
  sort(X.begin(),X.end(),greater<int>());
  sort(Y.begin(),Y.end(),greater<int>());
  int V=1,H=0;

  int i=0,j=0;
  while(i<m and j<n)
  {
    if(X[i] > Y[j])
    {
      RES+=X[i]*V;
      H++;
      i++;
    }
    else
    {
      RES+=Y[j]*H;
      V++;
      j++;
    }

    int total = 0;
    while(i<m)
      total+=X[i++];
    RES+=total*V;

    while(j<n)
      total+=Y[j++];
    RES+=total*H;
    
    return RES;
  }



  return RES;
} 
  

int main() 
{ 
    int m = 6, n = 4; 
    vector<int> X = {2, 1, 3, 1, 4}; 
    vector<int> Y = {4, 1, 2}; 
    cout << minimumCostOfBreaking(X, Y, m-1, n-1); 
    return 0; 
} 