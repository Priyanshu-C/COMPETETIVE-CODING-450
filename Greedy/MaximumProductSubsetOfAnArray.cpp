#include <bits/stdc++.h>
using namespace std;
#define d(x) cout<<#x<<" "<<x<<endl;
int maxProductSubset(vector<int> &ar, int n)
{
  int Pprod=1;
  int Nprod=1;
  int lowIn = INT_MIN;
    for(int i:ar)
    {
      if(i>0)
      Pprod*=i;
      else if(i<0)
      {
        lowIn = max(lowIn,i);
        Nprod*=i;
      }
    }
    d(Pprod);
    d(Nprod);
    d(lowIn);
   
    if(Nprod<0)
      Nprod=Nprod/lowIn;
    return Pprod*Nprod;
}
 
int main()
{
    vector<int> ar = {  0, -1, 0, 4, 3  };
    int n = ar.size();
    cout << maxProductSubset(ar, n);
    return 0;
}