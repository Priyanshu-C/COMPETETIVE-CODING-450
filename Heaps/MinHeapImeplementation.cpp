#include <bits/stdc++.h>
using namespace std;

//Heapify is also known as PERCOLATE DOWN ALGORITHM

class MinHeap
{
  private:
  vector<int> ar;
  int capacity;
  int heap_size;

  ////// BASIC DECLARATION
  public:
  MinHeap(int cap)
  {
    capacity=cap;
    ar.resize(cap);
  }

  int parent(int i)
  {
    return (i-1)/2;
  }
  
  int left(int i)
  {
    return (i*2)+1;
  }

  int right(int i)
  {
    return (i*2)+2;
  }
  
  /////////


  void insert(int k)
  {
    if(heap_size==capacity)
    {
      cout<<"heap capacity reached!";
      return;
    }
    int i = heap_size++;
    ar[i]=k;
    while(i!=0 and ar[parent(i)]>ar[i])
    {
      swap(ar[parent(i)],ar[i]);
      i=parent(i);
    }
  }

  int extractMin()
  {
    if(heap_size==0)
    {
      cout<<"Empty Heap";
      return INT_MAX;
    }
    if(heap_size==1)
    {
      heap_size--;
      return ar[heap_size];
    }
    int val = ar[0];
    ar[0]=ar[heap_size-1];
    heap_size--;
    heapify(0);
    
    return val;
  }

  void heapify(int pos)
  {
    int l = left(pos);
    int r = right(pos);
    int sm = pos;
    if( l < heap_size and ar[l] < ar[pos])
    {
      sm = l;
    }
    if(r < heap_size and ar[r] < ar[sm])
    {
      sm = r;
    }
    if(sm!=pos)
    {
      swap(ar[pos],ar[sm]);
      heapify(sm);
    }
  }

  void deleteIndex(int i)
  {
    ar[i]=INT_MIN;
    while(i!=0 and ar[parent(i)] > ar[i] )
    {
      swap(ar[parent(i)],ar[i]);
      i = parent(i);
    }
    extractMin();
  }

};

int main() {
    MinHeap h(11); 
    h.insert(3); 
    h.insert(2); 
    h.deleteIndex(0); 
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45);
    cout<<h.extractMin();
}nt