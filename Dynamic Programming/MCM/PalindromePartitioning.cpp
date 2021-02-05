#include <bits/stdc++.h> 
using namespace std; 

int DP[100][100];

bool isPalim(string &s,int i,int j)
{
  while(i<=j)
  {
    if(s[i++] != s[j--])
    return false;
  }
  return true;
}

int PalindromePartitioning(string &x, int i, int j) 
{ 
    if(i>=j)
    return 0;

    if(DP[i][j]!=-1)
    return DP[i][j];
    if(isPalim(x,i,j))
    return 0;

    // if(DP[i][j]!=-1)
    // return DP[i][j];
    int m = INT_MAX;
    for(int k=i;k<j;k++)
    {
      int temp = PalindromePartitioning(x,i,k) + PalindromePartitioning(x,k+1,j) + 1; 
      m = min(m,temp); 
    }
    return DP[i][j] = m;
} 
  
// Driver Code 
int main() 
{ 
    string x  = "aabbaaa";
    int n = x.size();
     memset(DP, -1, sizeof DP); 
    cout << "Minimum number of partitioning is "
         << PalindromePartitioning(x, 0, n - 1); 
}