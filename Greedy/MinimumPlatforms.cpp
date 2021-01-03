#include <algorithm> 
#include <iostream> 
#include <bits/stdc++.h> 
  
using namespace std; 
 
int findPlatform(int arr[], int dep[], int n) 
{ 
  vector<pair<int,int>> ar(n);
  for(int i=0;i<n;i++)
  ar[i] = {arr[i],dep[i]};

  sort(ar.begin(),ar.end());
  int fc = 0;
  for(int i=0;i<n;i++)
  {
    int j=i+1;
    int c=1;
    while(j<n-1 and ar[j].first<ar[i].second)
    {
    c++;j++;
    }
    fc=max(c,fc);
  }
  return fc;
} 
  
int main() 
{ 
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n); 
    return 0; 
} 