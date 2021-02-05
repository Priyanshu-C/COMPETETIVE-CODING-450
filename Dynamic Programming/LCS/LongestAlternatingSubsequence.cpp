#include <bits/stdc++.h>
using namespace std;

//Greedy is the way to go 
int AlternatingaMaxLength(vector<int> &ar)
{
  int n=ar.size();
  int inc=1;int dec = 1;
  for(int i=1;i<n;i++)
  {
    if(ar[i] > ar[i-1])
    {
      inc = dec+1;
    }
    else if(ar[i] < ar[i-1])
    {
     dec = inc+1;
     }
  }
  return max(dec,inc);
}

int main() {
  vector<int> x = {1,5,4};
  cout<<AlternatingaMaxLength(x);
}