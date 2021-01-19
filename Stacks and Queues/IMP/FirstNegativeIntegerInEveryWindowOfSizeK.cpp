#include <bits/stdc++.h>

using namespace std;
 
void printFirstNegativeInteger(vector<int> &ar, int k, int n)
{
    int firstNegativeIndex=0;
    int firstNegativeNumber;
    for(int i=k-1;i<n;i++)
    {
      while(firstNegativeIndex<i and (ar[firstNegativeIndex]>0 or firstNegativeIndex <= i-k))
      firstNegativeIndex++;
      if(ar[firstNegativeIndex]<0)
      firstNegativeNumber=ar[firstNegativeIndex];
      else
      firstNegativeNumber=0;
      cout<<firstNegativeNumber<<" ";  
    }
}
 
// Driver code
int main()
{
     vector<int> arr= { 12, -1, -7, 8, -15, 30, 16, 28};
      int n = arr.size();
     int k = 3;
     printFirstNegativeInteger(arr, k, n);    
}