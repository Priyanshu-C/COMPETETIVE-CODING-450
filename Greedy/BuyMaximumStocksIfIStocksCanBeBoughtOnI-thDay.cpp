
#include <bits/stdc++.h> 
using namespace std; 
  

int buyMaximumProducts(int n, int k, vector<int> price) 
{ 
  vector<pair<int,int>> ar(n);
  for(int i=0;i<n;i++)
  ar[i] = {price[i],i+1};
  sort(ar.begin(),ar.end());
  int count = 0;
  for(int i=0;i<n;i++)
  {
    count+=min(ar[i].second,k/ar[i].first);
    k-=ar[i].first*min(ar[i].second,k/ar[i].first);
  }
  return count;
} 

int main() 
{ 
    vector<int> price = { 10, 7, 19 }; 
    int n = price.size();
    int k = 45; 
  
    cout << buyMaximumProducts(n, k, price) << endl; 
  
    return 0; 
} 