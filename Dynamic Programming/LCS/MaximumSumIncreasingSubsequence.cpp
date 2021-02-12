#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
const int mod = 1000000007;
//=======================

int MaximumSumIncreasingSubsequence(vector<int> &ar,int n)
{ 
  
  vector<int> DP(n,-1);
  DP[0]=ar[0];
  for(int i=1;i<n;i++)
  {
    int j=0;
    while(j<i)
    {
      if(ar[j]<ar[i])
      {
        DP[i]=max(ar[i]+DP[j],DP[i]);
      }
      j++;
    }
  }
  return DP[n-1];

}

int main() {

    int n = 3;
   
    vector<int> ar ={1, 2, 3} ; 
    // for(int i=0;i<n;i++)
    // cin>>ar[i];
    cout<<MaximumSumIncreasingSubsequence(ar,n);
    return 0;
}