#include <bits/stdc++.h> 
using namespace std;

void merge(vector<int> &ar,int l,int m,int r)
{
  
int j=m+1;
int i=l;

if(ar[m]<=ar[j])
return;

  while(i<=m and j<=r)
  {
    if(ar[i] <= ar[j])
      i++;
    else
    {
      int value = ar[j];
      int index = j;
      while(index!=i)
      {
        ar[index] = ar[index-1];
        index--;
      }
      ar[i]=value;

      i++;
      m++;
      j++;
    }
  }
}



void mergeSort(vector<int> &ar,int l,int r)
{
  if(l<r)
  {
    int m= l + (r-l)/2;
    mergeSort(ar,l,m);
    mergeSort(ar,m+1,r);
    merge(ar,l,m,r);
  }
}