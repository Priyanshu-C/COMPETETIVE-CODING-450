#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
const int mod = 1000000007;
//=======================

int Longestsubsequence(vector<int> &ar,int n)
{ 
  
  vector<int> DP(n,1);
  for(int i=1;i<n;i++)
  {
    int j=0;
    while(j<i)
    {
      if(abs(ar[j]-ar[i])==1)
      {
        DP[i]=max(1+DP[j],DP[i]);
      }
      j++;
    }
  }
  return DP[n-1];

}

int main() {

    int n = 7;
   
    vector<int> ar ={10, 9, 4, 5, 4, 8, 6} ; 
    // for(int i=0;i<n;i++)
    // cin>>ar[i];
    cout<<Longestsubsequence(ar,n);
    return 0;
}