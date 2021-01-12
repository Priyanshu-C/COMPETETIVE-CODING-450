#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000

class Stack
{
  private:
  vector<int> ar;
  int top1;
  int top2;
  public:
  Stack()
    {
    top1=-1;
    top2=MAX;
    ar.resize(MAX);
    }
  bool push1(int val)
  {
    if(top1>=top2)
    return false;
    ar[++top1]=val;
    return true;
  }
  bool push2(int val)
  {
    if(top2<=top1)
    return false;
    ar[--top2]=val;
    return true;
  }
  int pop1()
  {
    if(top1==-1)
    return false;
    
    return ar[top1--];
  }
  int pop2()
  {
    if(top2==MAX)
    return false;
    
    return ar[top2++];
  }
  int peek1()
  {
    if(top1==-1)
    return false;
    return ar[top1];
  }
    int peek2()
  {
    if(top2==MAX)
    return false;
    return ar[top2];
  }
  bool isempty()
  {
    if(top1==-1 and top2==MAX)
    return true;
    return false;
  }
};

int main()
{
Stack s;
s.push1(4);
s.push2(4);
s.push1(4);
s.pop1();
cout<<s.peek1();
}