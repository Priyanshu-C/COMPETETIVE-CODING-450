#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000

class Stack
{
  private:
  vector<int> ar;
  int top;
  int min;
  public:
  Stack()
    {
    top=-1;
    ar.resize(MAX);
    }
  bool push(int val)
  {
    if(top>MAX)
    return false;

    if(val>min)
    ar[++top]=val;
    else
    {
      ar[++top]=2*val-min;
      min=val;
    }
    return true;
  }
  int pop()
  {
    if(top==-1)
    return false;
    if(ar[top]>min)
    return ar[top--];
    else
    {
      int t = min;
      min = 2*min - ar[top--];
      return t;
    }
  }
  int peek()
  {
    if(top==-1)
    return false;
    return ar[top];
  }
  bool isempty()
  {
    if(top==-1)
    return true;
    return false;
  }
  int getmin()
  {
    return min;
  }
};

int main()
{
Stack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(-1);
s.pop();
cout<<s.getmin();
}