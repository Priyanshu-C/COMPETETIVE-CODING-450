#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000

class Stack
{
  private:
  vector<int> ar;
  int top;
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
    ar[++top]=val;
    return true;
  }
  int pop()
  {
    if(top==-1)
    return false;
    
    return ar[top--];
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
};

int main()
{
Stack s;
s.push(4);
s.push(4);
s.push(4);
s.pop();
cout<<s.peek();
}