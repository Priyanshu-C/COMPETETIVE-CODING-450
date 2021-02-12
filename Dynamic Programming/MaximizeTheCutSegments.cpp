#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
const int mod = 1000000007;
//=======================

int maximizeTheCutSegments(int n,int x,int y,int z)
{
  if(n==0)
  return 0;
  int Countx = INT_MIN;
  int County = INT_MIN;
  int Countz = INT_MIN;

  if(n>=x)
  {
    Countx = (1+maximizeTheCutSegments(n-x,x,y,z)); 
  }
  if(n>=y)
  {
    County = (1+maximizeTheCutSegments(n-y,x,y,z)); 
  }
  if(n>=z)
  {
    Countz = (1+maximizeTheCutSegments(n-z,x,y,z)); 
  }
  deb2(Countx,County);
  return max(max(Countx,County),Countz);
}

int main() {

    int n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<maximizeTheCutSegments(n,x,y,z);
    return 0;
}

// 5 3 3 2