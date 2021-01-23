#include<bits/stdc++.h> 
using namespace std; 
  
void MaxHeapify(vector<int> &arr, int i, int n) 
{ 
    int L = i*2 +1;
    int R = i*2 +2;
    int largest = i;
    if(L<n and arr[L]>arr[largest])
    {
      largest = L;
    }
    if(R<n and arr[R]>arr[largest])
    {
      largest = R;
    }
    if(i!=largest)
    {
      swap(arr[i],arr[largest]);
      MaxHeapify(arr,largest,n);
    }
}
  

void convertMaxHeap(vector<int> &arr, int n) 
{ 

  for(int i=n-1;i>=0;i--)
    MaxHeapify(arr, i, n);

} 


void printArray(vector<int> arr, int size) 
{ 
    for (int i = 0; i < size; ++i) 
        printf("%d ", arr[i]); 
} 
  

int main() 
{ 
    // array representing Min Heap 
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9}; 
    int n = arr.size();
  
    printf("Min Heap array : "); 
    printArray(arr, n); 
  
    convertMaxHeap(arr, n); 
  
    printf("\nMax Heap array : "); 
    printArray(arr, n); 
  
    return 0; 
}