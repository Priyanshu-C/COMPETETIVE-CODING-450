#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000

class Queue
{
  private:
  vector<int> ar;
  int front;
  int end;
  int capacity;
  public:
  Queue()
    {
    front=-1;
    end=-1;
    capacity=0;
    ar.resize(MAX);
    }
  bool enqueue(int val)
  {
    if(capacity==ar.size())
    return false;
    end = end+1 % MAX;
    ar[end]=val;capacity++;
    return true;
  }
  int dequeue()
  {
     if(capacity==0)
    return false;
    int val = ar[front];
    front = front + 1 % MAX;
    return val;
  }
  int start()
  {
    if(capacity==0)
    return -1;
    return ar[front];
  }
  int tail()
  {
    if(capacity==0)
    return -1;
    return ar[end];
  }
};

int main()
{
Queue s;
s.enqueue(4);
s.enqueue(4);
s.dequeue();
s.dequeue();
cout<<s.tail();
}