#include <bits/stdc++.h> 
using namespace std; 

int DP[100][100];
int MatrixChainOrder(int p[], int i, int j) 
{ 
    if(i==j)
    return 0;

    if(DP[i][j]!=-1)
    return DP[i][j];

    int m = INT_MAX;
    for(int k=i;k<j;k++)
    {
      int temp = MatrixChainOrder(p,i,k) + MatrixChainOrder(p,k+1,j) + p[i-1]*p[k]*p[j];
      m = min(m,temp); 
    }
    return DP[i][j] = m;
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
     memset(DP, -1, sizeof DP); 
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 1, n - 1); 
}