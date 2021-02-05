
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

int productSubSeqCount(vector<int> &A,int k,int sum=1,int i=0)
{
   
  if(i==A.size())
  {
    if(sum<k)
    {deb2(sum,i);
      return 1;
    }
    else
    return 0;
  }
    return productSubSeqCount(A,k,sum*A[i],i+1) + productSubSeqCount(A,k,sum,i+1);
}

int main() {
   
   vector<int> A = {4, 8, 7, 2}; 
    // A.push_back(1); 
    // A.push_back(2); 
    // A.push_back(3); 
    // A.push_back(4); 
    int k = 50; 
    cout << productSubSeqCount(A, k)-1 << endl;

    return 0;
}