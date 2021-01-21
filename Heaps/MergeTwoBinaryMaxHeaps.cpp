#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fo(i,n) for(i=0;i<n;i++)
#define fok(i,k,n) for(i=k;i<n;i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

void heapify(vector<int> &heap,int n,int i)
{
  int L = i * 2 + 1;
  int R = i * 2 + 2;
  //deb2(L,R);
  int curr = i;
  if(L<n and heap[L]>heap[curr])
  {
    curr = L;
  }
  if(R<n and heap[R]>heap[curr])
  {
    curr = R;
  }
  if(i!=curr)
  {
    swap(heap[curr],heap[i]);
    heapify(heap,n,curr);
  }
}


vector<int> mergeHeap(vector<int> &heap1,vector<int> &heap2,int n,int m)
{
  heap1.insert(heap1.end(),heap2.begin(),heap2.end());
  n = n + m;
  
  for(int i=n/2-1;i>=0;i--)
  {
    // deb(i);
    heapify(heap1,n,i);
  }
  return heap1;
}

int main() {
    FIN
    int i;
    int n,m;
    cin>>n>>m;
    vector<int> heap1(n);
    fo(i,n)
    cin>>heap1[i];

    vector<int> heap2(m);
    fo(i,m)
    cin>>heap2[i];
    for(int i:mergeHeap(heap1,heap2,n,m))
      cout<<i<<" "; 

    return 0;
}